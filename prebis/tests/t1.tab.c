/* Bison-generated parse tables, made from t1.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

#line 1 "t1.y"
#include <stdio.h>
#line 2 "t1.y"
#ifndef YYSTYPE
typedef union
{
  int val;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		8
#define	YYFLAG		-32768
#define	YYNTBASE	6

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 256 ? yytranslate[x] : 9)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     4,     5,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1
};
static const short yyprhs[] =
{
       0,     0,     4,     6
};
static const short yyrhs[] =
{
       3,     7,     8,     0,     4,     0,     5,     0
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,    11,    12,    14
};
#endif

#define YYNTOKENS 6
#define YYNNTS 3
#define YYNRULES 3
#define YYNSTATES 9
#define YYMAXUTOK 256

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "'a'", "'b'", "'c'", "prog", "prog1", 
  "prog2", 0
};
/* YYTOKNUM[YYLEX] -- Index in YYTNAME corresponding to YYLEX. */
static const short yytoknum[] =
{
       0,   256,     2,    97,    98,    99,    -1
};
/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,     6,     7,     8
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     3,     1,     1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       0,     0,     2,     0,     3,     1,     0,     0,     0
};

static const short yydefgoto[] =
{
       6,     3,     5
};

static const short yypact[] =
{
      -3,    -2,-32768,    -4,-32768,-32768,     3,     4,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768
};


#define	YYLAST		4


static const short yytable[] =
{
       1,     4,     2,     7,     8
};

static const short yycheck[] =
{
       3,     5,     4,     0,     0
};
#line 16 "t1.y"


static const char * yytypstrs[] =
{
  "YYST_VAL",
  0
};

static const char * yytoktyp_str[][3] =
{
  { "'a'", "this is a", "YYST_VAL" },
  { "prog", "program", "YYST_VAL" },
  { "prog1", "program1", 0 },
  { "prog2", 0, 0 },
  { "'b'", 0, 0 },
  { "'c'", 0, 0 },
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


