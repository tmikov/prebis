%{#include <stdio.h>%}


























%union
{
  int tok;
  int rule;
}





%token ACTION1 
%token <tok> ACTION2 

%token <tok> 
C_SECTION 
LEFT 
NONASSOC 
RIGHT 
START 
TOKEN 
TYPE 
UNION 
PREC 
EXPECT 
OTHER 
SECTION 
END_SECTION 
IDENT 
C_STRING 
CHAR 
NUMBER 
SEMTYPE 



%token <tok> TERM 
%token <tok> NONTERM 

%token <tok> 
':' 
';' 
'|' 
'(' 
')' 

%type<tok> grammar c_section_opt decl_list prod_list decl any_decl opt_sem_type decl_ident_list action decl_ident_or_char ident_or_char id_or_char prod prod_head %type<rule> alt_list %type<tok> sem_type prod_ident %type<rule> rule %type<tok> symbol_invoke symbol sym_ident call arg_list arg %% 

grammar: 
c_section_opt decl_list SECTION prod_list END_SECTION 
{
      $$ = Chain( $1, Chain( $2, Chain( $3, Chain( $4, $5 ) ) ) );

      TRACE1( "Strings_count = %u\n", Strings_Count );
      Strings_Unpin();
      GcCollectStart();
        GC_MARK( $$ );
        Prebis_MarkRoots();
      GcCollectEnd();

      Gen( $$ );
      printf( "\n" );
    }
;

decl_list: 
{ $$ = NULL }
| decl_list decl { $$ = Chain( $1, $2 ) }
;

decl: 
any_decl opt_sem_type decl_ident_list 
{
        TToken * tok;

        // Declare terminals
        //
        for ( tok = $3; tok != NULL; tok = tok->pNext )
        {
          TSymbol * sym = tok->sym;

          // if it is not declared with "%type", it is a terminal symbol
          if (sym->sc == 0 && $1->code != TYPE)
            sym->sc = SC_TERM;
        }

        $$ = Chain( $1, Chain( $2, $3 ) );
      }
| UNION action { $$ = Chain( $1, $2 ) }
| EXPECT NUMBER { $$ = Chain( $1, $2 ) }
;

action: 
ACTION1 ACTION2 { $$ = $2 }
;

any_decl: LEFT | NONASSOC | RIGHT | TOKEN | TYPE ;

decl_ident_list: 
decl_ident_or_char 
| decl_ident_list {$<tok>$=$<tok>0} decl_ident_or_char 
{ $$ = Chain( $1, $3 ) }
;

decl_ident_or_char: 
ident_or_char description_opt 
{
      TSymbol * sym = $1->sym;

      // Set the type
      if ($<tok>0 != NULL)
      {
        if (sym->type != NULL)
        {
          if (sym->type != $<tok>0->str)
          {
            Error( "Redefining the type of terminal '%s' from %s to %s", 
                    C_STR(sym->name), C_STR(sym->type), C_STR($<tok>0->str) );
          }
        }
        sym->type = $<tok>0->str;
      }
      
      RET1;
    }
;

ident_or_char: 
id_or_char 
{
      // Add the symbol to the symbol list
      //
      if ($1->sym->link.Flink == NULL)
        INSERT_TAIL_LIST( &Symbols, &$1->sym->link );
      RET1;
    }
;

id_or_char: 
IDENT { $1->sym = GetSymbol( $1->str ); RET1 }
| CHAR { 
                  $1->sym = GetSymbol( $1->str ); 
                  if ($1->sym->sc == 0)        // characters are always terminals
                    $1->sym->sc = SC_TERM;
                   RET1 
                }
;

c_section_opt: 
{ $$ = NULL }
| C_SECTION 
;

prod_list: 
{ $$ = NULL }
| prod_list prod { $$ = Chain( $1, $2 ) }
;

prod: 
prod_head ':' alt_list ';' 
{
        $3->sepLine = $2->line;
        $1->sym->prod->firstRule = $3;
        $1->sym->prod->semiLine = $4->line;
        RET1;
      }
;

prod_head: 
TYPE sem_type prod_ident params_decl_opt {$<tok>$=$<tok>3} description_opt 
{
        TSymbol * sym = $3->sym;

        if (sym->type != NULL)
        {
          Error( "Redefining the type of typed non-terminal '%s' from %s to %s",
                 C_STR(sym->name), C_STR(sym->type), C_STR($2->str) );
        }
        sym->type = $2->str;
        sym->bTyped = true;

        $$ = $3;
      }
| prod_ident params_decl_opt {$<tok>$=$<tok>1} description_opt 
;

description_opt: 

| '/' C_STRING 
{ 
      ASSERT( $<tok>0->sym );

      if ($<tok>0->sym->desc != NULL)
        Warning( "Overiding the description of symbol '%s'", C_STR($<tok>0->sym->name) );

      $<tok>0->sym->desc = $2->str;
    }
;

prod_ident: 
IDENT 
{
        TSymbol * sym = GetSymbol( $1->str );

        if (sym->sc == SC_TERM)
        {
          Error( "'%s' is already declared as a terminal symbol", C_STR(sym->name) );

          // Perform some error recovery by creating a dummy symbol
          //
          sym = New_TSymbol( ErrorName );
        }

        // Add the symbol to the symbol list
        //
        if (sym->link.Flink == NULL)
          INSERT_TAIL_LIST( &Symbols, &sym->link );

        if (sym->prod == NULL)
          sym->prod = New_TProd();

        sym->sc = SC_NONTERM;
        sym->bDefined = true;
        $1->sym = sym;

        CurNT = sym;

        RET1;
      }
;


params_decl_opt: 

| '(' {$<tok>$=$<tok>0} param_decl_list ')' 
| '(' ')' {}
;

param_decl_list: 
param_decl 
| param_decl_list ',' {$<tok>$=$<tok>0} param_decl 
;

param_decl: 
'$' sem_type IDENT 
{
        TSymbol * nonterm = $<tok>0->sym;
        TProd * prod = nonterm->prod;
        TSymbol * param;

        if (prod->idtab == NULL)
          prod->idtab = New_IdentTab();

        if (IdentTab_Find( prod->idtab, $3->str, NULL ) != NULL)
        {
          Error( "Redefinition of parameter '%s'", C_STR($3->str) );

          // error recovery
          param = New_TSymbol( ErrorName );
        }
        else
          param = New_TSymbol( $3->str );

        param->type = $2->str;
        param->sc = SC_PARAM;
        IdentTab_Insert( prod->idtab, param, NULL );
        INSERT_TAIL_LIST( &prod->params, &param->link );
        param->index = ++prod->paramCount;
      }
;


alt_list: 
rule 
| rule '|' alt_list 
{
        $3->sepLine = $2->line;
        $1->nextRule = $3;
        RET1;
      }
;

rule: 
{ 
      CurTokIndex = 0; 
      CurRule = New_TRule( NULL );
    }
sym_list_opt { $$ = CurRule }
;

sym_list_opt: 

| sym_list 
;

sym_list: 
symbol_invoke { CurRule->start = $1; }
| sym_list symbol_invoke { Chain( CurRule->start, $2 ); }
;

symbol_invoke: 
symbol 

| PREC ident_or_char { $$ = Chain( $1, $2 ) }
;







symbol: 
action { $1->tokindex = ++CurTokIndex; RET1 }
| sym_ident 
| sym_ident call 
{ 
        if ($1->code == TERM)
        {
          Error( "Invoking a terminal (%s) with arguments", C_STR($1->str) );
          RET1;
        }
        else
          $$ = Chain( $1, $2 ) 
      }
;

sym_ident: 
ident_or_char 
{ 
        TSymbol * sym = $1->sym;

        if (sym->sc == SC_TERM)
          $1->code = TERM;
        else
          $1->code = NONTERM;
        $1->sym = sym;
        $1->tokindex = ++CurTokIndex;

        RET1;
      }
;



call: 
'(' arg_list ')' { $$ = Chain( $1, Chain( $2, $3 ) ) }
;

arg_list: 
arg 
| arg_list ',' arg { $$ = Chain( $1, $3 ) }
;

arg: 
'$' IDENT 
{
        TSymbol * local;
        int       refIndex;
        int       kind      = CurNTFindLocal( $2->str, &local, &refIndex );

        if (kind == 1)
          $2->sym = local;
        else
        if (kind == 2)
        {
          $2->code = NUMBER;
          $2->index = refIndex;
        }
  
        $$ = $2;
      }

| '$' opt_sem_type NUMBER 
{
        int number = atoi( C_STR($3->str) );

        Warning( "Usage of $N is deprecated" );

        $3->index = number;

        $$ = Chain( $3, $2 );
      }
| action { Error( "Action arguments are not yet supported" ) }
;

opt_sem_type: 
{ $$ = NULL }
| sem_type 
;

sem_type: 
SEMTYPE 
{
      if (!IdentTab_Find( TypesTab, $1->str, NULL ))
      {
        TSymbol * typeSym = New_TypeSymbol( $1->str );
        IdentTab_Insert( TypesTab, typeSym, NULL );
      }
      RET1;
    }
;

%%

static const char * yytypstrs[] =
{
  "YYST_TOK",
  "YYST_RULE",
  0
};

static const char * yytoktyp_str[][3] =
{
  { "ACTION1", "{ action }", 0 },
  { "ACTION2", "{ action }", "YYST_TOK" },
  { "C_SECTION", "%{ code section }", "YYST_TOK" },
  { "LEFT", "%left", "YYST_TOK" },
  { "NONASSOC", "%nonassoc", "YYST_TOK" },
  { "RIGHT", "%right", "YYST_TOK" },
  { "START", "%start", "YYST_TOK" },
  { "TOKEN", "%token", "YYST_TOK" },
  { "TYPE", "%type", "YYST_TOK" },
  { "UNION", "%union", "YYST_TOK" },
  { "PREC", "%prec", "YYST_TOK" },
  { "EXPECT", "%expect", "YYST_TOK" },
  { "OTHER", "%<<reserved>>", "YYST_TOK" },
  { "SECTION", "first '%%'", "YYST_TOK" },
  { "END_SECTION", "terminating '%%'", "YYST_TOK" },
  { "IDENT", "identifier", "YYST_TOK" },
  { "C_STRING", "\"string constant\"", "YYST_TOK" },
  { "CHAR", "'character constant'", "YYST_TOK" },
  { "NUMBER", "number", "YYST_TOK" },
  { "SEMTYPE", "<semantic type>", "YYST_TOK" },
  { "TERM", 0, "YYST_TOK" },
  { "NONTERM", 0, "YYST_TOK" },
  { "':'", ":", "YYST_TOK" },
  { "';'", ";", "YYST_TOK" },
  { "'|'", "|", "YYST_TOK" },
  { "'('", "(", "YYST_TOK" },
  { "')'", ")", "YYST_TOK" },
  { "grammar", 0, "YYST_TOK" },
  { "c_section_opt", 0, "YYST_TOK" },
  { "decl_list", 0, "YYST_TOK" },
  { "prod_list", 0, "YYST_TOK" },
  { "decl", 0, "YYST_TOK" },
  { "any_decl", 0, "YYST_TOK" },
  { "opt_sem_type", 0, "YYST_TOK" },
  { "decl_ident_list", 0, "YYST_TOK" },
  { "action", 0, "YYST_TOK" },
  { "decl_ident_or_char", 0, "YYST_TOK" },
  { "ident_or_char", 0, "YYST_TOK" },
  { "description_opt", 0, 0 },
  { "id_or_char", 0, "YYST_TOK" },
  { "prod", 0, "YYST_TOK" },
  { "prod_head", 0, "YYST_TOK" },
  { "alt_list", 0, "YYST_RULE" },
  { "sem_type", 0, "YYST_TOK" },
  { "prod_ident", 0, "YYST_TOK" },
  { "params_decl_opt", 0, 0 },
  { "'/'", 0, 0 },
  { "param_decl_list", 0, 0 },
  { "param_decl", 0, 0 },
  { "','", 0, 0 },
  { "'$'", 0, 0 },
  { "rule", 0, "YYST_RULE" },
  { "sym_list_opt", 0, 0 },
  { "sym_list", 0, 0 },
  { "symbol_invoke", 0, "YYST_TOK" },
  { "symbol", 0, "YYST_TOK" },
  { "sym_ident", 0, "YYST_TOK" },
  { "call", 0, "YYST_TOK" },
  { "arg_list", 0, "YYST_TOK" },
  { "arg", 0, "YYST_TOK" },
  { 0, 0 }
};

void yygen_typdefs ( void )
{
  int i;

  printf( "\n\n#ifndef %s\n\n", yytypstrs[0] );

  for ( i = 0; yytypstrs[i] != 0; ++i )
    printf( "#define %s  %u\n", yytypstrs[i], i + 1 );

  printf( "\n#endif\n\n" );
};

void yygen_toktyp ( void )
{
  int tok, sym;

  printf( "#ifndef YYTOKTYP_DEFINED\n" );
  printf( "#define YYTOKTYP_DEFINED\n\n" );

  printf( "static const unsigned char yytoktyp[] = \n{\n" );
  printf( "  0, 0, 0" );

  for ( tok = 3; yytname[tok] != 0; ++tok )
  {
    printf( ", " );
    if (tok % 5 == 0)
      printf( "\n  " );

    for ( sym = 0; yytoktyp_str[sym][0] != 0; ++sym )
      if (strcmp(yytoktyp_str[sym][0], yytname[tok]) == 0)
        break;

    if (yytoktyp_str[sym][2] == 0)
      printf( "0" );
    else
      printf( "%s", yytoktyp_str[sym][2] );
  }

  printf( "\n};\n" );

  printf( "\n#endif\n\n" );
}

void yyprint_str ( const char * s )
{
  printf( "\"" );
  for ( ;*s; ++s )
  {
    switch (*s)
    {
    case '"': 
    case '\\': printf( "\\" ); break;

    case '\n': printf( "\\n" ); continue;
    case '\t': printf( "\\t" ); continue;
    case '\v': printf( "\\v" ); continue;
    }

    printf( "%c", *s );
  }
  printf( "\"" );
};


void yygen_tokdesc ( void )
{
  int tok, sym;

  printf( "#ifndef YYTOKDESC_DEFINED\n" );
  printf( "#define YYTOKDESC_DEFINED\n\n" );

  printf( "static const char * const yytokdesc[] = \n{\n" );
  printf( "  0, 0, 0" );

  for ( tok = 3; yytname[tok] != 0; ++tok )
  {
    printf( ", " );
    if (tok % 5 == 0)
      printf( "\n  " );

    for ( sym = 0; yytoktyp_str[sym][0] != 0; ++sym )
      if (strcmp(yytoktyp_str[sym][0], yytname[tok]) == 0)
        break;

    if (yytoktyp_str[sym][1] == 0)
      printf( "0" );
    else
      yyprint_str( yytoktyp_str[sym][1] );
  }

  printf( "\n};\n" );

  printf( "\n#endif\n\n" );
}


int main ( void )
{
  yygen_typdefs();
  yygen_toktyp();
  yygen_tokdesc();
  return 0;
}


