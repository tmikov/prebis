#ifndef BISON_MAIN_PRE_TAB_H
# define BISON_MAIN_PRE_TAB_H

#ifndef YYSTYPE
typedef union 
{
  TToken * tok;
  TRule  * rule;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
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


extern YYSTYPE yylval;

#endif /* not BISON_MAIN_PRE_TAB_H */
