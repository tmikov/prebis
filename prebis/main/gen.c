#include "precomp.h"
#include "prebis.h"

static int CurLine;
static int ActualTokIndex;
static TProd * CurNTProd;

//--------------------------------------------------------------------------
// Name         ValidateSymbols 
//
// Make sure all non-terminals are defined
//--------------------------------------------------------------------------
void ValidateSymbols ( void )
{
  TListEntry * entry;

  CLIST_FOR_EACH( &Symbols, entry )
  {
    TSymbol * sym = (TSymbol *)entry;

    if (sym->sc == SC_NONTERM && !sym->bDefined)
      Error( "Non-terminal '%s' is used but not defined", C_STR(sym->name) );
/*
    if (sym->type != NULL)
      fprintf( stderr, "TYPE %s : %s\n", C_STR(sym->name), C_STR(sym->type) );
*/
  }
};

//--------------------------------------------------------------------------
// Name         LinePos 
//
// 
//--------------------------------------------------------------------------
static void LinePos ( int pos )
{
  for ( ; CurLine < pos; ++CurLine )
    printf( "\n" );
};

//--------------------------------------------------------------------------
// Name         TokLinePos 
//
// 
//--------------------------------------------------------------------------
static void TokLinePos ( TToken * tok )
{
  LinePos( tok->line );
  CurLine = tok->lastLine;
};

//--------------------------------------------------------------------------
// Name         TokenByIndex
//
// 
//--------------------------------------------------------------------------
static TToken * TokenByIndex ( TRule * rule, int index, int upto )
{
  TToken * tok;

  if (index <= 0 || index >= upto)
  {
    ErrorLine( CurLine, "$%d is not accessible", index );
    return NULL;
  }

  for ( tok = rule->start; tok != NULL; tok = tok->pNext )
  {
    if (tok->tokindex == index)
    {
      ASSERT( tok->code == TERM || tok->code == NONTERM || tok->code == CHAR );
      return tok;
    }
  }

  ASSERT( 0 );
  return NULL;
};

//--------------------------------------------------------------------------
// Name         GenCord 
//
// 
//--------------------------------------------------------------------------
static void GenCord ( CORD seg )
{
  for ( ; seg != NULL; seg = seg->pNext )
    printf( "%s", seg->u.data );
};

//--------------------------------------------------------------------------
// Name         GenAction 
//
// 
//--------------------------------------------------------------------------
static void GenAction ( TToken * tok )
{
  TActTok * act;

  for ( act = tok->act; act != NULL; act = act->pNext )
  {
    switch (act->code)
    {
    case AC_SYM:
      {
        TSymbol * sym = act->sym;

        switch (sym->sc)
        {
        case SC_PARAM:
          printf( "$%s%d", C_STR(sym->type), sym->index - CurNT->prod->paramCount );
          break;

        default:
          Error( "Can't access %s from an action", C_STR(sym->name) );
          break;
        }
      }
      break;

    case AC_LOC_SYM:
      {
        TSymbol * sym = act->sym;

        switch (sym->sc)
        {
        case SC_PARAM:
          printf( "@%d", sym->index - CurNT->prod->paramCount );
          break;

        default:
          Error( "Can't access %s from an action", C_STR(sym->name) );
          break;
        }
      }
      break;

    case AC_REF_INDEX:
      {
        const char * szType;
        TToken * srctok;

        szType = act->refType != NULL ? C_STR(act->refType) : "";

        if (act->refIndex <= 0)
        {
          WarningLine( CurLine, "$N with N <= 0 used. Why not use parameters?" );
          printf( "$%s%d",  szType, act->refIndex );
        }
        else
        if (NULL != (srctok = TokenByIndex( CurRule, act->refIndex, ActualTokIndex )) )
          printf( "$%s%d",  szType, srctok->actualIndex );
      }
      break;

    case AC_LOC_REF_INDEX:
      {
        TToken * srctok;

        if (act->refIndex <= 0)
        {
          WarningLine( CurLine, "@N with N <= 0 used. Why not use parameters?" );
          printf( "@%d",  act->refIndex );
        }
        else
        if (NULL != (srctok = TokenByIndex( CurRule, act->refIndex, ActualTokIndex )) )
          printf( "@%d",  srctok->actualIndex );
      }
      break;

    default:
      ASSERT(act->code == AC_CORD);
      GenCord( act->text );
      break;
    }
  }
};

//--------------------------------------------------------------------------
// Name         GenDummyUnion_GenOneType 
//
// Function that is called for each type from GenDummyUnion.
// Generates on type.
//--------------------------------------------------------------------------
static bool GenDummyUnion_GenOneType ( void * ctx, TSymbol * sym )
{
  printf( "  int %s;\n", C_STR(sym->type) );
  ++CurLine;
  return true;
};

//--------------------------------------------------------------------------
// Name         GenDummyUnion 
//
// Generates a dummy union where all semantic types use din the grammer
// are defined as int.
//--------------------------------------------------------------------------
static void GenDummyUnion ( void )
{
  printf( "%%union\n{\n" );
  CurLine += 2;

  IdentTab_ForEach( TypesTab, NULL, GenDummyUnion_GenOneType );

  printf( "}\n" );
  ++CurLine;
};

//--------------------------------------------------------------------------
// Name         GenHeader 
//
// 
//--------------------------------------------------------------------------
static TToken * GenHeader ( TToken * tok )
{
  // in Gen_yytoktyp mode include <stdio.h>
  //
  if (bGenPass1)
  {
    printf( "%s\n", "%{#include <stdio.h>%}" );
    ++CurLine;
  }

  for ( ; tok != NULL; tok = tok->pNext )
  {
    LinePos( tok->line );

    switch (tok->code)
    {
    case C_SECTION:
      if (!bGenPass1)
        GenCord( tok->cord );
      else
        continue;
      break;

    case UNION:
      // if in Gen_yytoktyp mode, skip the %union definition and replace it with one  of
      // our own
      //
      if (bGenPass1 && tok->pNext != NULL && tok->pNext->code == ACTION2)
      {
        tok = tok->pNext; // skip the contents of the union
        GenDummyUnion();
        continue;
      }
      else
        goto default_case;
      break;

    case ACTION2:
      if (!bGenPass1)
        GenAction( tok );
      break;

    case SECTION:
      // Generate all non-terminal prototypes on the line
      // before the section delimiter and exit
      //
      {
        TListEntry * entry;
        STRING lastType = NULL;

        for ( entry = Symbols.Flink; !END_OF_LIST(&Symbols, entry ); entry = entry->Flink )
        {
          TSymbol * sym = (TSymbol *)entry;

          if (sym->bTyped)
          {
            if (sym->type != lastType)
            {
              printf( "%%type%s ", C_STR(sym->type) );
              lastType = sym->type;
            }

            printf( "%s ", C_STR(sym->name) );
          }
        }
      }
      // no break;

    default:
    default_case:
      printf( "%s ", C_STR( tok->str ) );
      break;
    }

    CurLine = tok->lastLine;

    if (tok->code == SECTION)
    {
      tok = tok->pNext;
      break;
    }
  }

  return tok;
};

//--------------------------------------------------------------------------
// Name         MatchArg
//
// Math the type and store the actual $index that must be used to access that
// arg.
//--------------------------------------------------------------------------
static TToken * MatchArg ( 
    TSymbol * dest, TSymbol * param, TToken * arg, bool * pbErr,
    int * pSrcIndex
  )
{
  STRING argtype = NULL;
  int line = arg->line;

  *pbErr = false;

  switch (arg->code)
  {
  case IDENT:
    if (arg->sym == NULL) // ignore errors detected during parse
      *pbErr = true;
    else
    {
      argtype = arg->sym->type;
      *pSrcIndex = arg->sym->index - CurNTProd->paramCount;
    }
    arg = arg->pNext;
    break;

  case NUMBER:
    {
      TToken * numtok;

      // Get pointers to the number&type and skip to next param
      //
      numtok = arg;
      arg = arg->pNext;
      if (arg->code == SEMTYPE)
      {
        argtype = arg->str;
        arg = arg->pNext;
      }

      // Locate the source token 
      //
      if (numtok->index > 0)
      {
        TToken * srctok;

        // This signifies a term in the rule
        //
        if (NULL == (srctok = TokenByIndex( CurRule, numtok->index, ActualTokIndex )) )
        {
          *pbErr = true;
          break;
        }

        if (srctok->code == TERM || srctok->code == NONTERM)
        {
          if (srctok->sym->type != NULL)
          {
            if (argtype != NULL) // do we already have a type
            {
              if (srctok->sym->type == argtype)
                WarningLine( line, "$%d already has a type", numtok->index );
              else
              {
                ErrorLine( line, "$%s%d type mismatch. Must be %s or empty", 
                           C_STR(argtype), numtok->index, C_STR(srctok->sym->type)
                         );
                *pbErr = true;
                break;
              }
            }
            else
              argtype = srctok->sym->type;
          }
        }

        *pSrcIndex = srctok->actualIndex;
      }
      else
      {
        // negative value or 0 signifies values on the stack before the current
        // rule. 
        //
        WarningLine( line, "$N with N <= 0 used. Why not use parameters?" );

        *pSrcIndex = numtok->index;
      }
                
      // We need type information
      //
      if (argtype == NULL)
      {
        ErrorLine( line, "Unknown type of $%d", numtok->index );
        *pbErr = true;
        break;
      }
    }
    break;

  default:
    ErrorLine( line, "Unexpected non-terminal argument" );
    *pbErr = true;
    arg = arg->pNext;
    break;
  }

  if (*pbErr == false && argtype != param->type) // match the type
  {
    ErrorLine( line, "Type mismatch, non-terminal '%s', parameter $%s%s, passed %s", 
               C_STR(dest->name), C_STR(param->type), C_STR(param->name),  
               C_STR(argtype) 
             );
    *pbErr = true;
  }

  return arg;
};

//--------------------------------------------------------------------------
// Name         PrintUpcaseType 
//
// Print the type name in upcase
//--------------------------------------------------------------------------
static void PrintUpcaseType ( const char * s )
{
  for ( ; *s; ++s )
    printf( "%c", toupper(*s) );
};

//--------------------------------------------------------------------------
// Name         PrintYYSTName 
//
// 
//--------------------------------------------------------------------------
static void PrintYYSTName ( const TSymbol * typeSym )
{
  printf( "\"YYST_" );
  PrintUpcaseType( C_STR(typeSym->type) );
  printf( "\"" );
};

//--------------------------------------------------------------------------
// Name         PushArgs 
//
// 
//--------------------------------------------------------------------------
static void PushArgs ( TProd * prod, int * argArray )
{
  TSymbol * param;
  int ofs;

  // Make sure we have parameters which to process
  //
  if (prod->paramCount == 0) 
    return; // nothing to do

  // Skip args that are already in the right place
  //
  param = (TSymbol *)prod->params.Flink;
  ofs = ActualTokIndex - *argArray + param->index - 1;
  if (ofs <= prod->paramCount) // we have a chance
  {
    ++argArray;
    param = (TSymbol *)param->link.Flink;
    while ( !END_OF_LIST( &prod->params, param ) )
    {
      if (ActualTokIndex - *argArray + param->index - 1 != ofs)
        break;

      ++argArray;
      param = (TSymbol *)param->link.Flink;
    }
  }

  // Push the rest
  //
  for ( ; !END_OF_LIST( &prod->params, param ); param = (TSymbol *)param->link.Flink )
  {
    ++ActualTokIndex;

    if (!bGenPass1)
      printf( "{$%s$=$%s%d} ", C_STR(param->type), C_STR(param->type),*argArray );
    else
    {
      TSymbol * typeSym;

      ASSERT( param->type != NULL );

      if (NULL != (typeSym = IdentTab_Find( TypesTab, param->type, NULL )) )
      {
        printf( "{ return " );
        PrintYYSTName( typeSym );
        printf( "; } " );
      }
      else
      {
        printf( "{} " );
      }
    }

    ++argArray;
  }
};

//--------------------------------------------------------------------------
// Name         MatchParams 
//
// 
//--------------------------------------------------------------------------
static TToken * MatchParams ( TToken * tok )
{
  TSymbol * dest = tok->sym;
  TProd   * prod;
  TToken  * arg;
  TSymbol * param;
  bool    bErr;

  int     * argArray;

  tok = tok->pNext; // skip the invocation

  ASSERT( dest != NULL );
  if (dest == NULL || (prod = dest->prod) == NULL)
  {
    ErrorLine( CurLine, "Invalid non-terminal invocation" );
    return tok;
  }

  // Allocate the argument array
  //
  if (NULL == (argArray = _alloca( sizeof(argArray[0]) * prod->paramCount )) )
    FatalError( "Out of memory" );

  // Get a pointer to the arguments or NULL
  //
  if (tok != NULL && tok->code == '(')
    arg = tok->pNext; // go to first arg
  else
    arg = NULL;

  // Get the first parameter
  //
  param = (TSymbol *)prod->params.Flink;

  // Iterate over the arguments
  //
  bErr = false;
  while (arg != NULL && arg->code != ')')
  {
    if (param == NULL) // we've reached params end, just locate the end of the arguments
    {
      arg = arg->pNext;
      continue;
    }

    // Check for too many arguments
    //
    if (END_OF_LIST( &prod->params, param ))
    {
      ErrorLine( CurLine, "Too many arguments supplied to non-terminal '%s'", C_STR(dest->name) );
      bErr = true;
      param = NULL; 
      arg = arg->pNext;
      continue;
    }

    // Match parameter types
    arg = MatchArg( dest, param, arg, &bErr, &argArray[param->index-1] );

    param = (TSymbol *)param->link.Flink;
  }

  // Check for too few arguments
  if (param != NULL && !END_OF_LIST( &prod->params, param ))
  {
    ErrorLine( CurLine, "Too few arguments supplied to non-terminal '%s'", C_STR(dest->name) );
    bErr = true;
  }

  // skip the ')'
  //
  if (arg != NULL)   
    tok = arg->pNext;

  // Generate the arguments
  if (!bErr)
    PushArgs( prod, argArray );

  return tok;
};

//--------------------------------------------------------------------------
// Name         GenRule 
//
// 
//--------------------------------------------------------------------------
static void GenRule ( char sep )
{
  TToken * tok;

  LinePos( CurRule->sepLine );
  printf( "%c ", sep );

  ActualTokIndex = 0;

  for ( tok = CurRule->start; tok != NULL; )
  {
    TToken * saveTok = tok;
    TokLinePos( tok );

    ++ActualTokIndex;

    switch (tok->code)
    {
    case NONTERM:
      tok = MatchParams( tok );
      saveTok->actualIndex = ActualTokIndex;
      printf( "%s ", C_STR( saveTok->str ) );
      break;

    case ACTION2:
      if (!bGenPass1)
        GenAction( tok );
      else
        printf( "{} " );

      saveTok->actualIndex = ActualTokIndex;
      tok = tok->pNext;
      break;

    default:
      printf( "%s ", C_STR( saveTok->str ) );
      saveTok->actualIndex = ActualTokIndex;
      tok = tok->pNext;
      break;
    }

  }
};

//--------------------------------------------------------------------------
// Name         GenNTBody 
//
// 
//--------------------------------------------------------------------------
static void GenNTBody ( TSymbol * nonterm )
{
  TProd * prod = nonterm->prod;
  char    sep = ':';

  ASSERT( prod != NULL );

  for ( CurRule = prod->firstRule; CurRule != NULL; CurRule = CurRule->nextRule )
  {
    GenRule( sep );
    sep = '|';
  }

  LinePos( nonterm->prod->semiLine );
  printf( ";" );
};


//--------------------------------------------------------------------------
// Name         GenProd 
//
// 
//--------------------------------------------------------------------------
static void GenProd ( TToken * tok )
{
  TSymbol * nonterm;
  TProd * prod;

  if (NULL == (nonterm = tok->sym) || NULL == (prod = nonterm->prod))
  {
    ErrorLine( tok->line, "Invalid production data" );
    return;
  }

  CurNT = nonterm;
  CurNTProd = prod;

  TokLinePos( tok );

#if 0
  // Generate a comment for the result type
  //
  if (nonterm->type != NULL)
    printf( "/*%%type%s*/ ", C_STR(nonterm->type) );
#endif
  printf( "%s", C_STR( nonterm->name ) );
  CurLine = tok->lastLine;

#if 0
  // Generate a comment with the parameters
  //
  if (!IS_LIST_EMPTY( &prod->params ))
  {
    TListEntry * entry;
    printf( " /*( " );
    for ( entry = prod->params.Flink; !END_OF_LIST(&prod->params, entry ); entry = entry->Flink )
    {
      TSymbol * sym = (TSymbol *)entry;

      if (sym->sc == SC_PARAM)
        printf( "$%s%s ", C_STR(sym->type), C_STR(sym->name) );
    }
    printf( ")*/ " );
  }
#endif

  GenNTBody( nonterm );
};

//--------------------------------------------------------------------------
// Name         GenBody 
//
// 
//--------------------------------------------------------------------------
static TToken * GenBody ( TToken * tok )
{
  for ( ; tok != NULL && tok->code != END_SECTION; tok = tok->pNext )
  {
    GenProd( tok );
  }

  return tok;
};

//--------------------------------------------------------------------------
// Name         GenEnd 
//
// 
//--------------------------------------------------------------------------
static void GenEnd ( TToken * tok )
{
  for ( ; tok != NULL; tok = tok->pNext )
  {
    TokLinePos( tok );
    if (tok->code == END_SECTION)
      GenCord( tok->cord );
    else
      printf( "%s ", C_STR( tok->str ) );
  }
};

//--------------------------------------------------------------------------
// Name         GenTypeDefines_GenOneType 
//
// 
//--------------------------------------------------------------------------
static bool GenTypeDefines_GenOneType ( void * ctx, TSymbol * sym )
{
  printf( "  \"YYST_" );
  PrintUpcaseType( C_STR(sym->type) );
  printf( "\",\n" );
  ++CurLine;

  return true;
};

//--------------------------------------------------------------------------
// Name         GenTypeDefines
//
// Generate an array of all semantic types constants
//--------------------------------------------------------------------------
static void GenTypeDefines ( void )
{
  printf( "static const char * yytypstrs[] =\n{\n" );
  CurLine += 2;

  IdentTab_ForEach( TypesTab, NULL, GenTypeDefines_GenOneType );

  printf( "  0\n};\n\n" );
  CurLine += 3;
};

//--------------------------------------------------------------------------
// Name         GenSymbolTypeArray
//
// Generate an array mapping symbols to types in the form :
// { "symbol", "type" }
//--------------------------------------------------------------------------
static void GenSymbolTypeArray ( void )
{
  TListEntry * entry;

  printf( "static const char * yytoktyp_str[][3] =\n{\n" );
  CurLine += 2;

  CLIST_FOR_EACH( &Symbols, entry )
  {
    TSymbol * sym = (TSymbol *)entry;
    TSymbol * typeSym;

    printf( "  { \"%s\", %s, ", C_STR(sym->name), sym->desc ? C_STR(sym->desc) : "0" );

    if (sym->type != NULL && NULL != (typeSym = IdentTab_Find( TypesTab, sym->type, NULL )) )
      PrintYYSTName( typeSym );
    else
      printf( "0" );

    printf( " },\n" );
    ++CurLine;
  }
  printf( "  { 0, 0 }\n};\n" );
  CurLine += 2;
};

//--------------------------------------------------------------------------
// Name         Gen_yygen_toktyp 
//
// 
//--------------------------------------------------------------------------
static void Gen_yygen_toktyp ( void )
{
  printf( "\n\n%%%%\n\n" );
  CurLine += 4;
  GenTypeDefines();
  GenSymbolTypeArray();

  printf( "#include \"prebis_1.inc\"\n" );
  ++CurLine;
};


//--------------------------------------------------------------------------
// Name         DoGen 
//
// 
//--------------------------------------------------------------------------
static void DoGen ( TToken * tok )
{
  CurNT = NULL;
  CurRule = NULL;

  CurLine = 1;

  tok = GenHeader( tok );
  tok = GenBody( tok );

  if (bGenPass1)
    Gen_yygen_toktyp();
  else
    GenEnd( tok );
};

//--------------------------------------------------------------------------
// Name         Gen 
//
// 
//--------------------------------------------------------------------------
void Gen ( TToken * tok )
{
  ValidateSymbols();

  DoGen( tok );
/*
  bGenPass1 = true;
  DoGen( tok );
*/
};


