/* A Bison parser, made from main/pre.yp
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	ACTION1	257
# define	ACTION2	258
# define	C_SECTION	259
# define	LEFT	260
# define	NONASSOC	261
# define	RIGHT	262
# define	START	263
# define	TOKEN	264
# define	TYPE	265
# define	UNION	266
# define	PREC	267
# define	EXPECT	268
# define	OTHER	269
# define	SECTION	270
# define	END_SECTION	271
# define	IDENT	272
# define	C_STRING	273
# define	CHAR	274
# define	NUMBER	275
# define	SEMTYPE	276
# define	TERM	277
# define	NONTERM	278

#line 1 "main/pre.yp"

#include "precomp.h"
#include "prebis.h"

#define YYINITDEPTH 50

#define YYDEBUG 1

#if YYDEBUG
#  define YYERROR_VERBOSE 1
#endif
#define YYSTDERR          stdout

// In order to prevent usage of last_line & last_column, we declare this to be
// empty
#define YYLLOC_DEFAULT(Current, Rhs, N) 

void yyerror ( char * err );
int yylex ( void );
void yy_mark ( unsigned typ, const YYSTYPE * pval );

static TToken * Chain ( TToken * a, TToken * b );

#include "pre.tab.inc"

#define RET1


#line 30 "main/pre.yp"
#ifndef YYSTYPE
typedef union 
{
  TToken * tok;
  TRule  * rule;
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
       0,    76,    96,    98,   101,   119,   120,   123,   127,   127,
     127,   127,   127,   129,   131,   131,   135,   158,   169,   171,
     179,   181,   184,   186,   189,   199,   199,   214,   214,   217,
     219,   230,   263,   265,   265,   266,   269,   271,   271,   274,
     303,   305,   313,   313,   321,   323,   326,   328,   331,   334,
     343,   345,   346,   358,   376,   380,   382,   385,   404,   414,
     417,   419,   422
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
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "main/bison.simple.c"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
         || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))      \
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))                         \
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)              \
      do                                        \
        {                                       \
          register YYSIZE_T yyi;                \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (To)[yyi] = (From)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)                                        \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack, Stack, yysize);                          \
        Stack = &yyptr->Stack;                                          \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;   \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY && yylen == 1)                          \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      yychar1 = YYTRANSLATE (yychar);                           \
      YYPOPSTACK;                                               \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror ("syntax error: cannot back up");                 \
      YYERROR;                                                  \
    }                                                           \
while (0)

#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)        \
   Current.last_line   = Rhs[N].last_line;      \
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX                yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX                yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX                yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX                yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX                  yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 315 "main/bison.simple.c"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES                       \
/* The lookahead symbol.  */                            \
int yychar;                                             \
                                                        \
/* The semantic value of the lookahead symbol. */       \
YYSTYPE yylval;                                         \
                                                        \
/* Number of parse errors so far.  */                   \
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES                      \
YY_DECL_NON_LSP_VARIABLES                       \
                                                \
/* Location data for the lookahead symbol.  */  \
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES                      \
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */


// extern void yy_mark ( unsigned typ, const YYSTYPE * pval );

//--------------------------------------------------------------------------
// Name         yy_mark_stack
//
// 
//--------------------------------------------------------------------------
static void  yy_mark_stack ( 
    const short   * yyss,    // state stack
    const YYSTYPE * yyvs,    // semantic value stack
    unsigned        depth,   // depth of the stack (yyssp - yyss + 1)
    int             yychar,
    const YYSTYPE * pyylval

  )
{
  unsigned typ;

  // Mark the current character
  //
  if (0 != (typ = yytoktyp[YYTRANSLATE( yychar )]) )
    yy_mark( typ, pyylval );

  // Mark the stack
  //
  for ( ; depth-- > 0; ++yyss, ++yyvs )
  {
    if (0 != (typ = yystatetyp[*yyss]) )
      yy_mark( typ, yyvs );
  }
};

#define YY_MARK_STACK()  yy_mark_stack( yyss, yyvs, yyssp - yyss + 1, yychar, &yylval )

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;             /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack. Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        short *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
        YYLTYPE *yyls1 = yyls;
        /* This used to be a conditional around just the two extra args,
           but that might be undefined if yyoverflow is a macro.  */
        yyoverflow ("parser stack overflow",
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyls = yyls1;
# else
        yyoverflow ("parser stack overflow",
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
# endif
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
        goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
        yystacksize = YYMAXDEPTH;

      {
        short *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyoverflowlab;
        YYSTACK_RELOCATE (yyss);
        YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
        YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)              /* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;           /* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
        which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
        {
          YYFPRINTF (stderr, "Next token is %d (%s",
                     yychar, yytname[yychar1]);
          /* Give the individual parser a way to print the precise
             meaning of a token, for further debugging info.  */
# ifdef YYPRINT
          YYPRINT (stderr, yychar, yylval);
# endif
          YYFPRINTF (stderr, ")\n");
        }
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
              yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
                 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
        YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 1:
#line 78 "main/pre.yp"
{
      yyval.tok = Chain( yyvsp[-4].tok, Chain( yyvsp[-3].tok, Chain( yyvsp[-2].tok, Chain( yyvsp[-1].tok, yyvsp[0].tok ) ) ) );

      TRACE1( "Strings_count = %u\n", Strings_Count );
      Strings_GcUnpin();
      if (GcCollectStart( false ))
      {
        YY_MARK_STACK();
        GC_MARK( yyval.tok );
        Prebis_MarkRoots();
        GcCollectEnd();
      }

      Gen( yyval.tok );
      printf( "\n" );
    ;
    break;}
case 2:
#line 97 "main/pre.yp"
{ yyval.tok = NULL ;
    break;}
case 3:
#line 98 "main/pre.yp"
{ yyval.tok = Chain( yyvsp[-1].tok, yyvsp[0].tok ) ;
    break;}
case 4:
#line 103 "main/pre.yp"
{
        TToken * tok;

        // Declare terminals
        //
        for ( tok = yyvsp[0].tok; tok != NULL; tok = tok->pNext )
        {
          TSymbol * sym = tok->sym;

          // if it is not declared with "%type", it is a terminal symbol
          if (sym->sc == 0 && yyvsp[-2].tok->code != TYPE)
            sym->sc = SC_TERM;
        }

        yyval.tok = Chain( yyvsp[-2].tok, Chain( yyvsp[-1].tok, yyvsp[0].tok ) );
      ;
    break;}
case 5:
#line 119 "main/pre.yp"
{ yyval.tok = Chain( yyvsp[-1].tok, yyvsp[0].tok ) ;
    break;}
case 6:
#line 120 "main/pre.yp"
{ yyval.tok = Chain( yyvsp[-1].tok, yyvsp[0].tok ) ;
    break;}
case 7:
#line 124 "main/pre.yp"
{ yyval.tok = yyvsp[0].tok ;
    break;}
case 14:
#line 131 "main/pre.yp"
{yyval.tok=yyvsp[-1].tok;
    break;}
case 15:
#line 132 "main/pre.yp"
{ yyval.tok = Chain( yyvsp[-2].tok, yyvsp[0].tok ) ;
    break;}
case 16:
#line 137 "main/pre.yp"
{
      TSymbol * sym = yyvsp[-1].tok->sym;

      // Set the type
      if (yyvsp[-2].tok != NULL)
      {
        if (sym->type != NULL)
        {
          if (sym->type != yyvsp[-2].tok->str)
          {
            Error( "Redefining the type of terminal '%s' from %s to %s", 
                    C_STR(sym->name), C_STR(sym->type), C_STR(yyvsp[-2].tok->str) );
          }
        }
        sym->type = yyvsp[-2].tok->str;
      }
      
      RET1;
    ;
    break;}
case 17:
#line 160 "main/pre.yp"
{
      // Add the symbol to the symbol list
      //
      if (yyvsp[0].tok->sym->link.Flink == NULL)
        INSERT_TAIL_LIST( &Symbols, &yyvsp[0].tok->sym->link );
      RET1;
    ;
    break;}
case 18:
#line 170 "main/pre.yp"
{ yyvsp[0].tok->sym = GetSymbol( yyvsp[0].tok->str ); RET1 ;
    break;}
case 19:
#line 171 "main/pre.yp"
{ 
                  yyvsp[0].tok->sym = GetSymbol( yyvsp[0].tok->str ); 
                  if (yyvsp[0].tok->sym->sc == 0)        // characters are always terminals
                    yyvsp[0].tok->sym->sc = SC_TERM;
                   RET1 
                ;
    break;}
case 20:
#line 180 "main/pre.yp"
{ yyval.tok = NULL ;
    break;}
case 22:
#line 185 "main/pre.yp"
{ yyval.tok = NULL ;
    break;}
case 23:
#line 186 "main/pre.yp"
{ yyval.tok = Chain( yyvsp[-1].tok, yyvsp[0].tok ) ;
    break;}
case 24:
#line 191 "main/pre.yp"
{
        yyvsp[-1].rule->sepLine = yyvsp[-2].tok->line;
        yyvsp[-3].tok->sym->prod->firstRule = yyvsp[-1].rule;
        yyvsp[-3].tok->sym->prod->semiLine = yyvsp[0].tok->line;
        RET1;
      ;
    break;}
case 25:
#line 200 "main/pre.yp"
{yyval.tok=yyvsp[-1].tok;
    break;}
case 26:
#line 201 "main/pre.yp"
{
        TSymbol * sym = yyvsp[-3].tok->sym;

        if (sym->type != NULL)
        {
          Error( "Redefining the type of typed non-terminal '%s' from %s to %s",
                 C_STR(sym->name), C_STR(sym->type), C_STR(yyvsp[-4].tok->str) );
        }
        sym->type = yyvsp[-4].tok->str;
        sym->bTyped = true;

        yyval.tok = yyvsp[-3].tok;
      ;
    break;}
case 27:
#line 214 "main/pre.yp"
{yyval.tok=yyvsp[-1].tok;
    break;}
case 30:
#line 220 "main/pre.yp"
{ 
      ASSERT( yyvsp[-2].tok->sym );

      if (yyvsp[-2].tok->sym->desc != NULL)
        Warning( "Overiding the description of symbol '%s'", C_STR(yyvsp[-2].tok->sym->name) );

      yyvsp[-2].tok->sym->desc = yyvsp[0].tok->str;
    ;
    break;}
case 31:
#line 232 "main/pre.yp"
{
        TSymbol * sym = GetSymbol( yyvsp[0].tok->str );

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
        yyvsp[0].tok->sym = sym;

        CurNT = sym;

        RET1;
      ;
    break;}
case 33:
#line 265 "main/pre.yp"
{yyval.tok=yyvsp[-1].tok;
    break;}
case 35:
#line 266 "main/pre.yp"
{;
    break;}
case 37:
#line 271 "main/pre.yp"
{yyval.tok=yyvsp[-2].tok;
    break;}
case 39:
#line 276 "main/pre.yp"
{
        TSymbol * nonterm = yyvsp[-3].tok->sym;
        TProd * prod = nonterm->prod;
        TSymbol * param;

        if (prod->idtab == NULL)
          prod->idtab = New_IdentTab();

        if (IdentTab_Find( prod->idtab, yyvsp[0].tok->str, NULL ) != NULL)
        {
          Error( "Redefinition of parameter '%s'", C_STR(yyvsp[0].tok->str) );

          // error recovery
          param = New_TSymbol( ErrorName );
        }
        else
          param = New_TSymbol( yyvsp[0].tok->str );

        param->type = yyvsp[-1].tok->str;
        param->sc = SC_PARAM;
        IdentTab_Insert( prod->idtab, param, NULL );
        INSERT_TAIL_LIST( &prod->params, &param->link );
        param->index = ++prod->paramCount;
      ;
    break;}
case 41:
#line 306 "main/pre.yp"
{
        yyvsp[0].rule->sepLine = yyvsp[-1].tok->line;
        yyvsp[-2].rule->nextRule = yyvsp[0].rule;
        RET1;
      ;
    break;}
case 42:
#line 314 "main/pre.yp"
{ 
      CurTokIndex = 0; 
      CurRule = New_TRule( NULL );
    ;
    break;}
case 43:
#line 318 "main/pre.yp"
{ yyval.rule = CurRule ;
    break;}
case 46:
#line 327 "main/pre.yp"
{ CurRule->start = yyvsp[0].tok; ;
    break;}
case 47:
#line 328 "main/pre.yp"
{ Chain( CurRule->start, yyvsp[0].tok ); ;
    break;}
case 49:
#line 334 "main/pre.yp"
{ yyval.tok = Chain( yyvsp[-1].tok, yyvsp[0].tok ) ;
    break;}
case 50:
#line 344 "main/pre.yp"
{ yyvsp[0].tok->tokindex = ++CurTokIndex; RET1 ;
    break;}
case 52:
#line 347 "main/pre.yp"
{ 
        if (yyvsp[-1].tok->code == TERM)
        {
          Error( "Invoking a terminal (%s) with arguments", C_STR(yyvsp[-1].tok->str) );
          RET1;
        }
        else
          yyval.tok = Chain( yyvsp[-1].tok, yyvsp[0].tok ) 
      ;
    break;}
case 53:
#line 360 "main/pre.yp"
{ 
        TSymbol * sym = yyvsp[0].tok->sym;

        if (sym->sc == SC_TERM)
          yyvsp[0].tok->code = TERM;
        else
          yyvsp[0].tok->code = NONTERM;
        yyvsp[0].tok->sym = sym;
        yyvsp[0].tok->tokindex = ++CurTokIndex;

        RET1;
      ;
    break;}
case 54:
#line 377 "main/pre.yp"
{ yyval.tok = Chain( yyvsp[-2].tok, Chain( yyvsp[-1].tok, yyvsp[0].tok ) ) ;
    break;}
case 56:
#line 382 "main/pre.yp"
{ yyval.tok = Chain( yyvsp[-2].tok, yyvsp[0].tok ) ;
    break;}
case 57:
#line 387 "main/pre.yp"
{
        TSymbol * local;
        int       refIndex;
        int       kind      = CurNTFindLocal( yyvsp[0].tok->str, &local, &refIndex );

        if (kind == 1)
          yyvsp[0].tok->sym = local;
        else
        if (kind == 2)
        {
          yyvsp[0].tok->code = NUMBER;
          yyvsp[0].tok->index = refIndex;
        }
  
        yyval.tok = yyvsp[0].tok;
      ;
    break;}
case 58:
#line 405 "main/pre.yp"
{
        int number = atoi( C_STR(yyvsp[0].tok->str) );

        Warning( "Usage of $N is deprecated" );

        yyvsp[0].tok->index = number;

        yyval.tok = Chain( yyvsp[0].tok, yyvsp[-1].tok );
      ;
    break;}
case 59:
#line 414 "main/pre.yp"
{ Error( "Action arguments are not yet supported" ) ;
    break;}
case 60:
#line 418 "main/pre.yp"
{ yyval.tok = NULL ;
    break;}
case 62:
#line 424 "main/pre.yp"
{
      if (!IdentTab_Find( TypesTab, yyvsp[0].tok->str, NULL ))
      {
        TSymbol * typeSym = New_TypeSymbol( yyvsp[0].tok->str );
        IdentTab_Insert( TypesTab, typeSym, NULL );
      }
      RET1;
    ;
    break;}
}

#line 740 "main/bison.simple.c"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
        YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
#define YYTDESC(x)  (yytokdesc[x] ? yytokdesc[x] : yytname[x])
//#define YYTDESC(x)  yytname[x]
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
        {
          YYSIZE_T yysize = 0;
          char *yymsg;
          int yyx, yycount;

          yycount = 0;
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  */
          for (yyx = yyn < 0 ? -yyn : 0;
               yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
            if (yycheck[yyx + yyn] == yyx)
              yysize += yystrlen (YYTDESC(yyx)) + 15, yycount++;
          yysize += yystrlen ("parse error, unexpected ") + 1;
          yysize += yystrlen (YYTDESC(YYTRANSLATE (yychar)));
          yymsg = (char *) YYSTACK_ALLOC (yysize);
          if (yymsg != 0)
            {
              char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
              yyp = yystpcpy (yyp, YYTDESC(YYTRANSLATE (yychar)));

              if (yycount < 5)
                {
                  yycount = 0;
                  for (yyx = yyn < 0 ? -yyn : 0;
                       yyx < (int) (sizeof (yytname) / sizeof (char *));
                       yyx++)
                    if (yycheck[yyx + yyn] == yyx)
                      {
                        const char *yyq = ! yycount ? ", expecting " : " or ";
                        yyp = yystpcpy (yyp, yyq);
                        yyp = yystpcpy (yyp, YYTDESC(yyx));
                        yycount++;
                      }
                }
              yyerror (yymsg);
              YYSTACK_FREE (yymsg);
            }
          else
            yyerror ("parse error; also virtual memory exhausted");
        }
      else
#endif /* defined (YYERROR_VERBOSE) */
        yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
        YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
                  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
        YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
        goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 435 "main/pre.yp"


//--------------------------------------------------------------------------
// Name         yy_mark 
//
// 
//--------------------------------------------------------------------------
void yy_mark ( unsigned typ, const YYSTYPE * pval )
{
  switch (typ)
  {
  case YYST_TOK:
    GC_MARK( pval->tok );
    break;

  case YYST_RULE:
    GC_MARK( pval->rule );
    break;

  default:
    ASSERT( 0 );
  }
};

//--------------------------------------------------------------------------
// Name         Chain 
//
// 
//--------------------------------------------------------------------------
static TToken * Chain ( TToken * a, TToken * b )
{
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;

  a->pLast->pNext = b;
  a->pLast = b->pLast;

  return a;
};

//--------------------------------------------------------------------------
// Name         PrintMessage 
//
// 
//--------------------------------------------------------------------------
static void PrintMessage ( int line, const char * msg, const char * fmt, va_list ap )
{
  fprintf( stderr, "%s(%d) : %s : ", szFileName, line, msg );
  vfprintf( stderr, fmt, ap );
  fprintf( stderr, "\n" );
};


//--------------------------------------------------------------------------
// Name         FatalError 
//
// 
//--------------------------------------------------------------------------
void FatalError ( const char * err, ... )
{
  va_list ap;
  va_start( ap, err );

  ++ErrorCount;
  PrintMessage( yylineno, "fatal error", err, ap );

  va_end( ap );

  exit( EXIT_FAILURE );
};

//--------------------------------------------------------------------------
// Name         Error 
//
// 
//--------------------------------------------------------------------------
void Error ( const char * err, ... )
{
  va_list ap;
  va_start( ap, err );

  ++ErrorCount;
  PrintMessage( yylineno, "error", err, ap );

  va_end( ap );
};

//--------------------------------------------------------------------------
// Name         Warning 
//
// 
//--------------------------------------------------------------------------
void Warning ( const char * err, ... )
{
  va_list ap;
  va_start( ap, err );

  PrintMessage( yylineno, "warning", err, ap );

  va_end( ap );
};

//--------------------------------------------------------------------------
// Name         ErrorLine 
//
// 
//--------------------------------------------------------------------------
void ErrorLine ( int line, const char * err, ... )
{
  va_list ap;
  va_start( ap, err );

  ++ErrorCount;
  PrintMessage( line, "error", err, ap );

  va_end( ap );
};

//--------------------------------------------------------------------------
// Name         WarningLine
//
// 
//--------------------------------------------------------------------------
void WarningLine ( int line, const char * err, ... )
{
  va_list ap;
  va_start( ap, err );

  PrintMessage( line, "warning", err, ap );

  va_end( ap );
};

//--------------------------------------------------------------------------
// Name         yyerror 
//
// 
//--------------------------------------------------------------------------
void yyerror ( char * err )
{
  Error( "%s at '%s'", err, yytext );
};


