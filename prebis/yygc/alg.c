#define YYEMPTY         -2
#define YYEOF           0

/* The lookahead symbol.  */                            
int yychar;                                             
/* Lookahead token as an internal (translated) token number.  */
int yychar1 = 0;
                                                        
/* The semantic value of the lookahead symbol. */       
YYSTYPE yylval;                                         
                                                        
/* Number of parse errors so far.  */                   
int yynerrs;

state_t yystate; // cut state

YYSTYPE *ValueTop;
state_t *StateTop;

//--------------------------------------------------------------------------
// Name         yynextchar 
//
// Returns translated char
//--------------------------------------------------------------------------
int yynextchar ( void )
{
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
    yychar = YYEOF;           /* Don't call YYLEX any more */
    return 0; // EOF
  }
  else
    return YYTRANSLATE (yychar);
}

//--------------------------------------------------------------------------
// Name         yyreduce 
//
// 
//--------------------------------------------------------------------------
void yyreduce (  int rule )
{
  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen; 
  int rule; // rule to reduce with

  yylen = yyr2[rule];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = ValueTop[1-yylen];

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
                 rule, yyrline[rule]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[rule]; yyrhs[yyi] > 0; yyi++)
        YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[rule]]);
    }
#endif

  switch (rule) {...}

  ValueTop -= yylen;
  StateTop -= yylen;

  *++ValueTop = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  int ntsym = yyr1[rule];

  yystate = yypgoto[ntsym - YYNTBASE] + *StateTop;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *StateTop)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[ntsym - YYNTBASE];
}


int yyparse ( void )
{
  /* If reentrant, generate the variables here. */
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short yyssa[YYINITDEPTH];
  short *yyss = yyssa;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;


  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;             /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  StateTop = yyss;
  ValueTop = yyvs;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  StateTop++;

 yysetstate:
  *StateTop = yystate;

  if (StateTop >= yyss + yystacksize - 1)
  { resize stack  }

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

  if (yypact[yystate] == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */
  yychar1 = yynextchar();

  yyn = yypact[yystate] + yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  /* yytable[yyn] is what to do for this token type in this state.
     Negative => reduce, -yytable[yyn] is rule number.
     Positive => shift, yytable[yyn] is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yytable[yyn] == 0 || yytable[yyn] == YYFLAG)
    goto yyerrlab;
  else
  if (yytable[yyn] < 0)
  {
    rule = -yytable[yyn];
    goto yyreduce;
  }

  if (yytable[yyn] == YYFINAL)
    YYACCEPT;

  yystate = yytable[yyn];

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++ValueTop = yylval;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  rule = yydefact[yystate];
  if (rule == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  yyreduce( rule );

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
  if (StateTop == yyss)
    YYABORT;
  ValueTop--;
  yystate = *--StateTop;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != StateTop)
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

  *++ValueTop = yylval;
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
