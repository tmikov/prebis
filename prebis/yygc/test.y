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
{} 
;

decl_list: 
{} 
| decl_list decl {} 
;

decl: 
any_decl opt_sem_type decl_ident_list 
{} 
| UNION action {} 
| EXPECT NUMBER {} 
;

action: 
ACTION1 ACTION2 {} 
;

any_decl: LEFT | NONASSOC | RIGHT | TOKEN | TYPE ;

decl_ident_list: 
decl_ident_or_char 
| decl_ident_list { return "YYST_TOK"; } decl_ident_or_char 
{} 
;

decl_ident_or_char: 
ident_or_char description_opt 
{} 
;

ident_or_char: 
id_or_char 
{} 
;

id_or_char: 
IDENT {} 
| CHAR {} 
;

c_section_opt: 
{} 
| C_SECTION 
;

prod_list: 
{} 
| prod_list prod {} 
;

prod: 
prod_head ':' alt_list ';' 
{} 
;

prod_head: 
TYPE sem_type prod_ident params_decl_opt { return "YYST_TOK"; } description_opt 
{} 
| prod_ident params_decl_opt { return "YYST_TOK"; } description_opt 
;

description_opt: 

| '/' C_STRING 
{} 
;

prod_ident: 
IDENT 
{} 
;


params_decl_opt: 

| '(' { return "YYST_TOK"; } param_decl_list ')' 
| '(' ')' {} 
;

param_decl_list: 
param_decl 
| param_decl_list ',' { return "YYST_TOK"; } param_decl 
;

param_decl: 
'$' sem_type IDENT 
{} 
;


alt_list: 
rule 
| rule '|' alt_list 
{} 
;

rule: 
{} 
sym_list_opt {} 
;

sym_list_opt: 

| sym_list 
;

sym_list: 
symbol_invoke {} 
| sym_list symbol_invoke {} 
;

symbol_invoke: 
symbol 

| PREC ident_or_char {} 
;







symbol: 
action {} 
| sym_ident 
| sym_ident call 
{} 
;

sym_ident: 
ident_or_char 
{} 
;



call: 
'(' arg_list ')' {} 
;

arg_list: 
arg 
| arg_list ',' arg {} 
;

arg: 
'$' IDENT 
{} 

| '$' opt_sem_type NUMBER 
{} 
| action {} 
;

opt_sem_type: 
{} 
| sem_type 
;

sem_type: 
SEMTYPE 
{} 
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
}


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


int latok[YYNSTATES]; // token or nonterminal shifted on stack before entering   
                      // a state

const char * getruletype ( int rule )
{
  switch (rule)
  {
#include YYACT
  }

  return 0;
}

const char * getsymtype ( int sym )
{
  int i;
  const char * typ;

  // First try to locate the symbol in the type table
  //
  for ( i = 0; yytoktyp_str[i][0] != 0; ++i )
  {
    if (strcmp( yytoktyp_str[i][0], yytname[sym] ) == 0)
      return yytoktyp_str[i][2];
  }

  // It is probably an internal symbol for an in-rule action. If the 
  // action was generated by PREBIS, it must have inserted code to return
  // its type.
  //
  // Reverse lookup in the rule->symbol table to determine the rule number.
  //
  for ( i = 0; i < sizeof(yyr1)/sizeof(yyr1[0]); ++i )
  {
    if (yyr1[i] == sym)
    {
      if (0 != (typ = getruletype( i )) )
        return typ;
    }
  }

  return 0;
}

void setlatok ( int state, int tok )
{
  if (latok[state] >= 0 && latok[state] != tok)
  {
    fprintf( stderr, "Conflict in state %d!!!\n", state );
    abort();
  }
  else
    latok[state] = tok;
}


void yygen_statetyp ( void )
{
  int state;

  // Clear the lookahead array
  //
  for ( state = 0; state < YYNSTATES; ++state )
    latok[state] = -1;

  // Iterate through the transition table for each state
  //
  for ( state = 0; state < YYNSTATES; ++state )
  {
    int tok1, ntsym, newstate;

    // Try every possible (translated) token
    //

    for ( tok1 = 0; tok1 < YYNTOKENS; ++tok1 )
    {
      int yyn;

      yyn = yypact[state] + tok1;
      if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != tok1)
      {
      }  
      else 
      {
        int action = yytable[yyn];

        if (action > 0) // a shift to a new state -> record the token!
        {
          newstate = action;

          setlatok( newstate, tok1 );
        }
      }
    }

    // Try every possible non-terminal
    //

    for ( ntsym = YYNTBASE; ntsym < YYNTBASE + YYNNTS; ++ntsym )
    {
      int t;

      t = yypgoto[ntsym - YYNTBASE] + state;
      if (t >= 0 && t <= YYLAST && yycheck[t] == state)
        newstate = yytable[t];
      else
        newstate = yydefgoto[ntsym - YYNTBASE];

      setlatok( newstate, ntsym );
    }
  }

  printf( "\n\n" );
  printf( "#ifndef YYSTATETYP_DEFINED\n" );
  printf( "#define YYSTATETYP_DEFINED\n\n" );
  printf( "static const unsigned char yystatetyp[] =\n{\n" );
  printf( "  0,\n" );

  // Generate the table (excluding state 0)
  //
  for ( state = 1; state < YYNSTATES; ++state )
  {
    const char * typ;
    int tok1;

    if (latok[state] < 0)
    {
      fprintf( stderr, "Error: state %d has no lookahead!\n", state ); 
      abort();
    }

    tok1 = latok[state];

    if (0 == (typ = getsymtype( tok1 )) )
    {
      fprintf( stderr, "Warning: state %d (%s) has no type\n", state, yytname[tok1] ); 
      typ = "0";
    }

    printf( "  %s,", typ );
    printf( " \t/* %3d:%s */", state, yytname[tok1] );
    printf( "\n" );
  }
  printf( "};\n" );
  printf( "\n#endif\n\n" );
}

int main ( void )
{
  yygen_typdefs();
  yygen_toktyp();
  yygen_tokdesc();
  yygen_statetyp();
  return 0;
}


