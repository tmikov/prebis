#define	YYFINAL		90
#define	YYFLAG		-32768
#define	YYNTBASE	33

#define YYNTOKENS 33
#define YYNNTS 36
#define YYNRULES 62
#define YYNSTATES 91
#define YYMAXUTOK 278

typedef short state_t;

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

#if YYDEBUG
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

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,    75,    92,    94,    97,   115,   116,   119,   123,   123,
     123,   123,   123,   125,   127,   127,   131,   154,   165,   167,
     175,   177,   180,   182,   185,   195,   195,   210,   210,   213,
     215,   226,   259,   261,   261,   262,   265,   267,   267,   270,
     299,   301,   309,   309,   317,   319,   322,   324,   327,   330,
     339,   341,   342,   354,   372,   376,   378,   381,   400,   410,
     413,   415,   418
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

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
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[YYNRULES+1] =
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
static const short yydefact[YYNSTATES] =
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

static const short yydefgoto[YYNNTS] =
{
      88,     3,    12,    54,    13,    30,    38,    31,    32,    33,
       2,    17,    25,    26,    65,    47,    40,    27,    37,    46,
      62,    80,    63,    42,    43,    44,    56,    57,    58,    59,
      60,    70,    77,    78,    19,    20
};

static const short yypact[YYNSTATES] =
{
      25,YYFLAG,YYFLAG,     0,YYFLAG,YYFLAG,YYFLAG,YYFLAG,YYFLAG,     6,
      15,YYFLAG,YYFLAG,    16,    33,YYFLAG,YYFLAG,     7,YYFLAG,     8,
  YYFLAG,YYFLAG,    16,YYFLAG,YYFLAG,YYFLAG,    14,    13,YYFLAG,YYFLAG,
       9,YYFLAG,    12,YYFLAG,    26,YYFLAG,    17,YYFLAG,     8,    24,
  YYFLAG,    13,    19,    20,     2,YYFLAG,    18,    12,YYFLAG,YYFLAG,
  YYFLAG,YYFLAG,YYFLAG,     8,YYFLAG,YYFLAG,YYFLAG,     2,YYFLAG,YYFLAG,
      21,    16,     3,YYFLAG,YYFLAG,    12,YYFLAG,YYFLAG,YYFLAG,    -1,
  YYFLAG,    30,YYFLAG,YYFLAG,YYFLAG,     1,YYFLAG,     4,YYFLAG,YYFLAG,
      18,YYFLAG,    31,YYFLAG,    -1,YYFLAG,YYFLAG,YYFLAG,    51,    53,
  YYFLAG
};

static const short yypgoto[YYNNTS] =
{
  YYFLAG,YYFLAG,YYFLAG,    -9,YYFLAG,YYFLAG,YYFLAG,    23,   -40,YYFLAG,
  YYFLAG,YYFLAG,YYFLAG,YYFLAG,YYFLAG,YYFLAG,   -44,    22,    27,YYFLAG,
  YYFLAG,YYFLAG,   -26,     5,YYFLAG,YYFLAG,YYFLAG,YYFLAG,    -2,YYFLAG,
  YYFLAG,YYFLAG,YYFLAG,   -25,   -17,   -21
};


#define	YYLAST		75


static const short yytable[YYLAST+1] =
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

static const short yycheck[YYLAST+1] =
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


#define YYTERROR        1
#define YYERRCODE       256


/* The lookahead symbol.  */                            \
int yychar;                                             \
                                                        \
/* The semantic value of the lookahead symbol. */       \
YYSTYPE yylval;                                         \
                                                        \
/* Number of parse errors so far.  */                   \
int yynerrs;
