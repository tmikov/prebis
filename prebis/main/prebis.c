#include "precomp.h"
#include "prebis.h"

const char * szFileName;
bool  bGenPass1 = false;

TListRoot Symbols;
STRING ErrorName;
TSymbol * CurNT;
TRule * CurRule;
TIdentTab * TypesTab;

int CurTokIndex;
int ErrorCount;

//--------------------------------------------------------------------------
// Name         Prebis_MarkRoots 
//
// 
//--------------------------------------------------------------------------
void Prebis_MarkRoots ( void )
{
  TListRoot_GcMark( &Symbols );
  GC_MARK( ErrorName );
  GC_MARK( CurNT );
  GC_MARK( CurRule );
  GC_MARK( TypesTab );
};

//--------------------------------------------------------------------------
// Name         New_TToken 
//
// 
//--------------------------------------------------------------------------
TToken * New_TToken ( int code )
{
  TToken * tok = GC_NEW( TToken );
  tok->code = code;
  return tok;
};

//--------------------------------------------------------------------------
// Name         New_TProd 
//
// 
//--------------------------------------------------------------------------
TProd * New_TProd ( void )
{
  TProd * prod = GC_NEW( TProd );
  INITIALIZE_LIST_HEAD( &prod->params );
  return prod;
};

//--------------------------------------------------------------------------
// Name         New_TSymbol
//
// 
//--------------------------------------------------------------------------
TSymbol * New_TSymbol ( STRING name )
{
  TSymbol * sym = GC_NEW( TSymbol );
  sym->name = name;
  return sym;
};

//--------------------------------------------------------------------------
// Name         New_TypeSymbol 
//
// Creates a TSymbol which holds a semantic type.
//   ->name is the type in the form '<type>'
//   ->type is the type in teh form 'type'
//--------------------------------------------------------------------------
TSymbol * New_TypeSymbol ( STRING name )
{
  TSymbol * sym = New_TSymbol( name );
  char * s, * e; 

  // extract the type name
  s = STRING_GET(name)->szString;
  if (*s == '<')
    ++s;
  for ( e = s; *e != 0 && *e != '>'; ++e );

  // zero terminate the string temporarily
  {
    char sav = *e;
    *e = 0;
    sym->type = NewString( s );
    *e = sav;
  }

  sym->sc = SC_TYPE;
  return sym;
};


//--------------------------------------------------------------------------
// Name         New_TRule 
//
// 
//--------------------------------------------------------------------------
TRule * New_TRule ( TToken * list )
{
  TRule * rule = GC_NEW( TRule );
  rule->start = list;
  return rule;
};

//--------------------------------------------------------------------------
// Name         GetSymbol 
//
// 
//--------------------------------------------------------------------------
TSymbol * GetSymbol ( STRING str )
{
  if (STRING_DATA(str) == NULL)
    STRING_SET_DATA(str, New_TSymbol(str));

  return STRING_DATA(str);
};

//--------------------------------------------------------------------------
// Name         CurNTFindLocal 
//
// 0 - not found
// 1 - local
// 2 - indexed invocation
//--------------------------------------------------------------------------
int CurNTFindLocal ( STRING name, TSymbol ** ppSym, int * pSrcIndex )
{
  TSymbol * local;
  TToken * tok;

  ASSERT( CurNT != NULL );
  ASSERT( CurNT->prod != NULL );
  ASSERT( CurRule != NULL );

  *ppSym = NULL;
  *pSrcIndex = INT_MIN;

  // Search the locals
  //
  if (NULL != (local = IdentTab_Find( CurNT->prod->idtab, name, NULL )) )
  {
    *ppSym = local;
    return 1;
  }

  // Search the rule
  //
  for ( tok = CurRule->start; tok != NULL; tok = tok->pNext )
  {
    if (tok->code == TERM || tok->code == NONTERM)
    {
      if (tok->sym->name == name)
      {
        *pSrcIndex = tok->tokindex;
        return 2;
      }
    }
  }

  Error( "Undefined local $%s", C_STR(name) );
  return 0;
};

//--------------------------------------------------------------------------
// Name         Init 
//
// 
//--------------------------------------------------------------------------
static void Init ( void )
{
  GcInit();
  Strings_Init();
  Strings_GcPin();
  ScannerInit(); 

  INITIALIZE_LIST_HEAD( &Symbols );
  ErrorName = NewString( "?error" );
  CurNT = NULL;
  CurRule = NULL;
  TypesTab = New_IdentTab();

  ErrorCount = 0;

  // Declare 'error' as a non-terminal
  {
    TSymbol * err = GetSymbol( NewString( "error" ) );
    err->sc = SC_NONTERM;
    err->bDefined = true;

    err->prod = New_TProd(); // just a dummy production, so later checks don't complain
  }
};


void TActTok_GcMark ( const TActTok * act )
{
  GC_MARK( act->pNext );
  //GC_MARK( act->pLast );
  GC_MARK( act->refType );

  switch (act->code)
  {
  case AC_CORD:      
    GC_MARK( act->text ); 
    break;

  case AC_SYM:  
  case AC_LOC_SYM:
    GC_MARK( act->sym ); break;

  case AC_REF_INDEX: 
  case AC_LOC_REF_INDEX: 
    break;

  default:           
    ASSERT( 0 );
  }
};

void TToken_GcMark ( const TToken * tok )
{
  GC_MARK( tok->pNext );
  //GC_MARK( tok->pLast );
  GC_MARK( tok->str );

  switch( tok->code )
  {
  case TERM: 
  case NONTERM: 
  case IDENT:     GC_MARK( tok->sym ); break;

  case ACTION2:   GC_MARK( tok->act ); break;

  case C_SECTION:
  case END_SECTION: GC_MARK( tok->cord ); break;
  }
};

void TRule_GcMark ( const TRule * rule )
{
  GC_MARK( rule->nextRule );
  GC_MARK( rule->start );
};

void TProd_GcMark ( const TProd * prod )
{
  GC_MARK( prod->firstRule );
  GC_MARK( prod->idtab );

  TListRoot_GcMark( &prod->params );
};

void TSymbol_GcMark ( const TSymbol * sym )
{
  GC_MARK( sym->name );
  GC_MARK( sym->type );
  GC_MARK( sym->prod );
  GC_MARK( sym->desc );
};

//--------------------------------------------------------------------------
// Name         main 
//
// 
//--------------------------------------------------------------------------
int main ( int argc, char ** argv )
{
  // Process command line options
  //

  // Skip the file name
  --argc;
  ++argv;

  // Iterate through the options
  //
  for ( ; argc > 0 && strchr( "-/", argv[0][0] ) != NULL; --argc, ++argv )
  {
    switch (tolower(argv[0][1]))
    {
    case 't':
      bGenPass1 = true;
      break;

    default:
      fprintf( stderr, "*** Unknown command line option: %s\n", argv[0] );
      exit( EXIT_FAILURE );
    }
  }

  if (argc > 1)
  {
    fprintf( stderr, "Fatal Error: Too many arguments\n" );
    exit( EXIT_FAILURE );
  }

  if (argc == 1)
  {
    szFileName = argv[0];

    if (NULL == (yyin = fopen( szFileName, "rt" )) )
    {
      perror( szFileName );
      exit( EXIT_FAILURE );
    }
  }
  else
    szFileName = "con:";

  Init();
/*  {
    extern int yydebug;
    yydebug = 1;
  }*/
  yyparse();

  if (yyin != stdin)
    fclose( yyin );

  return ErrorCount > 0 ? EXIT_FAILURE : EXIT_SUCCESS;
};
