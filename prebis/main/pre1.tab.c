/* Bison-generated parse tables, made from main/pre1.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

#line 1 "main/pre1.y"
#include <stdio.h>
#line 30 "main/pre1.y"
#ifndef YYSTYPE
typedef union
{
  int tok;
  int rule;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		90
#define	YYFLAG		-32768
#define	YYNTBASE	33

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 278 ? yytranslate[x] : 69)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    32,     2,     2,     2,
      28,    29,     2,     2,    31,     2,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    26,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24
};
static const short yyprhs[] =
{
       0,     0,     6,     7,    10,    14,    17,    20,    23,    25,
      27,    29,    31,    33,    35,    36,    40,    43,    45,    47,
      49,    50,    52,    53,    56,    61,    62,    69,    70,    75,
      76,    79,    81,    82,    83,    88,    91,    93,    94,    99,
     103,   105,   109,   110,   113,   114,   116,   118,   121,   123,
     126,   128,   130,   133,   135,   139,   141,   145,   148,   152,
     154,   155,   157
};
static const short yyrhs[] =
{
      43,    34,    16,    44,    17,     0,     0,    34,    35,     0,
      37,    67,    38,     0,    12,    36,     0,    14,    21,     0,
       3,     4,     0,     6,     0,     7,     0,     8,     0,    10,
       0,    11,     0,    40,     0,     0,    38,    39,    40,     0,
      41,    49,     0,    42,     0,    18,     0,    20,     0,     0,
       5,     0,     0,    44,    45,     0,    46,    25,    56,    26,
       0,     0,    11,    68,    50,    51,    47,    49,     0,     0,
      50,    51,    48,    49,     0,     0,    30,    19,     0,    18,
       0,     0,     0,    28,    52,    53,    29,     0,    28,    29,
       0,    55,     0,     0,    53,    31,    54,    55,     0,    32,
      68,    18,     0,    57,     0,    57,    27,    56,     0,     0,
      58,    59,     0,     0,    60,     0,    61,     0,    60,    61,
       0,    62,     0,    13,    41,     0,    36,     0,    63,     0,
      63,    64,     0,    41,     0,    28,    65,    29,     0,    66,
       0,    65,    31,    66,     0,    32,    18,     0,    32,    67,
      21,     0,    36,     0,     0,    68,     0,    22,     0
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,    76,    81,    83,    86,    89,    90,    93,    97,    97,
      97,    97,    97,    99,   101,   101,   105,   110,   115,   117,
     120,   122,   125,   127,   130,   135,   135,   138,   138,   141,
     143,   147,   153,   155,   155,   156,   159,   161,   161,   164,
     170,   172,   176,   176,   181,   183,   186,   188,   191,   194,
     203,   205,   206,   210,   217,   221,   223,   226,   230,   232,
     235,   237,   240
};
#endif

#define YYNTOKENS 33
#define YYNNTS 36
#define YYNRULES 62
#define YYNSTATES 91
#define YYMAXUTOK 278

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "ACTION1", "ACTION2", "C_SECTION", "LEFT", 
  "NONASSOC", "RIGHT", "START", "TOKEN", "TYPE", "UNION", "PREC", 
  "EXPECT", "OTHER", "SECTION", "END_SECTION", "IDENT", "C_STRING", 
  "CHAR", "NUMBER", "SEMTYPE", "TERM", "NONTERM", "':'", "';'", "'|'", 
  "'('", "')'", "'/'", "','", "'$'", "grammar", "decl_list", "decl", 
  "action", "any_decl", "decl_ident_list", "@1", "decl_ident_or_char", 
  "ident_or_char", "id_or_char", "c_section_opt", "prod_list", "prod", 
  "prod_head", "@2", "@3", "description_opt", "prod_ident", 
  "params_decl_opt", "@4", "param_decl_list", "@5", "param_decl", 
  "alt_list", "rule", "@6", "sym_list_opt", "sym_list", "symbol_invoke", 
  "symbol", "sym_ident", "call", "arg_list", "arg", "opt_sem_type", 
  "sem_type", 0
};
/* YYTOKNUM[YYLEX] -- Index in YYTNAME corresponding to YYLEX. */
static const short yytoknum[] =
{
       0,   256,     2,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,    58,    59,   124,    40,    41,
      47,    44,    36,    -1
};
/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    33,    34,    34,    35,    35,    35,    36,    37,    37,
      37,    37,    37,    38,    39,    38,    40,    41,    42,    42,
      43,    43,    44,    44,    45,    47,    46,    48,    46,    49,
      49,    50,    51,    52,    51,    51,    53,    54,    53,    55,
      56,    56,    58,    57,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    64,    65,    65,    66,    66,    66,
      67,    67,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     5,     0,     2,     3,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     0,     3,     2,     1,     1,     1,
       0,     1,     0,     2,     4,     0,     6,     0,     4,     0,
       2,     1,     0,     0,     4,     2,     1,     0,     4,     3,
       1,     3,     0,     2,     0,     1,     1,     2,     1,     2,
       1,     1,     2,     1,     3,     1,     3,     2,     3,     1,
       0,     1,     1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
      20,    21,     2,     0,     8,     9,    10,    11,    12,     0,
       0,    22,     3,    60,     0,     5,     6,     0,    62,     0,
      61,     7,     0,     1,    31,    23,     0,    32,    18,    19,
       4,    13,    29,    17,     0,    42,    33,    27,     0,     0,
      16,    32,     0,    40,    44,    35,     0,    29,    15,    30,
      25,    24,    42,     0,    50,    53,    43,    45,    46,    48,
      51,     0,     0,    36,    28,    29,    41,    49,    47,     0,
      52,     0,    34,    37,    26,    60,    59,     0,    55,    39,
       0,    57,     0,    54,     0,    38,    58,    56,     0,     0,
       0
};

static const short yydefgoto[] =
{
      88,     3,    12,    54,    13,    30,    38,    31,    32,    33,
       2,    17,    25,    26,    65,    47,    40,    27,    37,    46,
      62,    80,    63,    42,    43,    44,    56,    57,    58,    59,
      60,    70,    77,    78,    19,    20
};

static const short yypact[] =
{
      25,-32768,-32768,     0,-32768,-32768,-32768,-32768,-32768,     6,
      15,-32768,-32768,    16,    33,-32768,-32768,     7,-32768,     8,
  -32768,-32768,    16,-32768,-32768,-32768,    14,    13,-32768,-32768,
       9,-32768,    12,-32768,    26,-32768,    17,-32768,     8,    24,
  -32768,    13,    19,    20,     2,-32768,    18,    12,-32768,-32768,
  -32768,-32768,-32768,     8,-32768,-32768,-32768,     2,-32768,-32768,
      21,    16,     3,-32768,-32768,    12,-32768,-32768,-32768,    -1,
  -32768,    30,-32768,-32768,-32768,     1,-32768,     4,-32768,-32768,
      18,-32768,    31,-32768,    -1,-32768,-32768,-32768,    51,    53,
  -32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,    -9,-32768,-32768,-32768,    23,   -40,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,   -44,    22,    27,-32768,
  -32768,-32768,   -26,     5,-32768,-32768,-32768,-32768,    -2,-32768,
  -32768,-32768,-32768,   -25,   -17,   -21
};


#define	YYLAST		75


static const short yytable[] =
{
      15,    34,    14,    64,    55,    14,     4,     5,     6,    14,
       7,     8,     9,    67,    10,    53,    11,    55,    22,    81,
      28,    74,    29,    18,    23,    24,    28,   -14,    29,   -14,
       1,    75,    72,    83,    73,    84,    16,    21,    18,    35,
      71,    36,    39,    49,    24,    51,    45,    52,    79,    69,
      61,    89,    86,    90,    85,    68,    41,    66,    82,    87,
      76,    48,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,    76
};

static const short yycheck[] =
{
       9,    22,     3,    47,    44,     3,     6,     7,     8,     3,
      10,    11,    12,    53,    14,    13,    16,    57,    11,    18,
      18,    65,    20,    22,    17,    18,    18,    18,    20,    20,
       5,    32,    29,    29,    31,    31,    21,     4,    22,    25,
      61,    28,    30,    19,    18,    26,    29,    27,    18,    28,
      32,     0,    21,     0,    80,    57,    34,    52,    75,    84,
      69,    38,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    84
};
#line 245 "main/pre1.y"


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
#include "prebis_1.inc"

