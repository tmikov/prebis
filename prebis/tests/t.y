%{#include <stdio.h>%}
%union
{
  int val;
}

%type<val> prog %% 

prog: 'a' prog1 prog2 { $$ = 0 };
prog1: 'b' ;
prog2: 'c' ;

%%

static const char * yytypstrs[] =
{
  "YYST_VAL",
  0
};

static const char * yytoktyp_str[][3] =
{
  { "prog", "program", "YYST_VAL" },
  { "'a'", 0, 0 },
  { "prog1", "program1", 0 },
  { "'b'", 0, 0 },
  { "prog2", 0, 0 },
  { "'c'", 0, 0 },
  { 0, 0, 0 }
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
      printf( "\"%s\"", yytoktyp_str[sym][1] );
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


