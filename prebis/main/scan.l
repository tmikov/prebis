%{    
#include "precomp.h"
#include "prebis.h"

static unsigned section;
int yylineno;
static STRING ActionStr; // just something to init the action strings with

static STRING StringFromCord ( CORD cord );
static int NewStringToken ( int code, STRING str, int line, int lastLine );
static int NewToken ( int code );

TActTok * New_TActTok ( void );
TActTok * ActTok_Append ( TActTok * a, TActTok * b );

#define CORD_APPEND   (cord = Cord_NewSegment( cord, yyleng+1, yytext ))
#define CORD_INIT     (cord = Cord_NewSegment( NULL, yyleng+1, yytext ))

#define TOK_ACT_INIT  (CORD_INIT, act = NULL)
#define TOK_ACT_NEW   (curAct = New_TActTok(), act = ActTok_Append( act, curAct ))
#define TOK_ACT_APPEND                           \
  do {                                           \
    if (cord != NULL)                            \
    {                                            \
      TOK_ACT_NEW;                               \
      curAct->text = cord;                       \
      cord = NULL;                               \
    }                                            \
  } while (0)

#define NL()          (++yylineno)
%}

%option noyywrap
%option nodefault
%option stack

/* C whitespace */
WS       [ \f\v\t]+

/* An identifier without universal characters */
SIMPLEID       ([[:alpha:]_][[:alnum:]_]*)

%x COMMENT LINE_COMMENT IN_C_SECTION IN_ACTION1 IN_ACTION2 IN_END_SECTION IN_C_STR IN_C_CHAR

%%
  unsigned startLine = 0;
  CORD     cord = NULL;
  unsigned level;
  TActTok * act, * curAct;

"/*"          startLine = yylineno; yy_push_state( COMMENT );
"//"          yy_push_state( LINE_COMMENT );

"%left"       return NewToken( LEFT ); 
"%nonassoc"   return NewToken( NONASSOC ); 
"%right"      return NewToken( RIGHT );
"%start"      return NewToken( START );
"%token"      return NewToken( TOKEN );
"%type"       return NewToken( TYPE );
"%union"      return NewToken( UNION );
"%prec"       return NewToken( PREC );
"%expect"     return NewToken( EXPECT );

"%"{SIMPLEID} return NewToken( OTHER );

"%{"          CORD_INIT; startLine = yylineno; BEGIN( IN_C_SECTION ); 

"%%"          {
                if (++section == 1)
                  return NewToken( SECTION );
                else
                {
                  CORD_INIT; startLine = yylineno; BEGIN( IN_END_SECTION ); 
                }
              }

"<"{SIMPLEID}">" return NewToken( SEMTYPE );
"<"{SIMPLEID} {
                Error("'>' expected after '%s'", yytext );
                return NewToken( SEMTYPE ); // TODO: must append the '>'
              }

{SIMPLEID}    return NewToken( IDENT );

"-"?[0-9]+    return NewToken( NUMBER );

'[^\n']'      return NewToken( CHAR );
'[^']         Error( "Unterminated character constant" ); return NewToken( CHAR );

\"            CORD_INIT; startLine = yylineno; yy_push_state( IN_C_STR );

"{"           yyless(0); BEGIN( IN_ACTION1 ); return ACTION1; /* see commens for ACTION1 and 2 in pre.y */

{WS}
\n            NL();

.             return NewToken( *yytext );

<COMMENT>{
        <<EOF>>         {
                          if (yy_top_state() == INITIAL) 
                            Error( "Comment started on line %u not closed", startLine ); 
                          else
                            Error( "Comment not closed" ); 
                          yyterminate();
                        }
        [^*\n]+         if (yy_top_state() != INITIAL) CORD_APPEND; /* eat anything that's not a '*' */
        "*"+[^*/\n]*    if (yy_top_state() != INITIAL) CORD_APPEND; /* eat up '*'s not followed by '/'s */
        \n              NL(); if (yy_top_state() != INITIAL) CORD_APPEND;
        "*"+"/"         if (yy_top_state() != INITIAL) CORD_APPEND; yy_pop_state();
}

<LINE_COMMENT>{
        <<EOF>>         yyterminate();
        \n              NL(); if (yy_top_state() != INITIAL) CORD_APPEND; yy_pop_state();
        .+              if (yy_top_state() != INITIAL) CORD_APPEND; 
}

<IN_C_STR>{
        <<EOF>>         Error("Unterminated string"); yyterminate();
        \n              {
                          Error("Unterminated string"); 
                          NL(); 
                          CORD_APPEND; 
                          yy_pop_state();
                          if (YYSTATE == INITIAL)
                            return NewStringToken( C_STRING, StringFromCord( cord ), startLine, yylineno );
                        }

        [^\n"\\]*\"     { // sequence without '\\' ending with '"'
                          CORD_APPEND; 
                          yy_pop_state(); 
                          if (YYSTATE == INITIAL)
                            return NewStringToken( C_STRING, StringFromCord( cord ), startLine, yylineno );
                        }

        [^\n"\\]+       CORD_APPEND;                 // sequence without '\\'

        \\\n            CORD_APPEND; // concatenated lines
        \\.?            CORD_APPEND; // escaped characters
}

<IN_C_CHAR>{
        <<EOF>>         Error("Unterminated character"); yyterminate();
        \n              Error("Unterminated character"); NL(); CORD_APPEND; yy_pop_state();

        [^\n'\\]*\'     CORD_APPEND; yy_pop_state(); // sequence without '\\' ending with '\''
        [^\n'\\]+       CORD_APPEND;                 // sequence without '\\'

        \\\n            CORD_APPEND; // concatenated lines
        \\.?            CORD_APPEND; // escaped characters
}

<IN_C_SECTION>{
        <<EOF>>         Error( "Unexpected EOF in section started on line %u", startLine ); yyterminate();

        \n              NL(); CORD_APPEND;
        \"              yy_push_state( IN_C_STR ); CORD_APPEND;
        '               yy_push_state( IN_C_CHAR ); CORD_APPEND;
        "/*"            yy_push_state( COMMENT ); CORD_APPEND;
        "//"            yy_push_state( LINE_COMMENT ); CORD_APPEND;
        "/"             CORD_APPEND;

        [^\n}/'"]*      CORD_APPEND;

        [^\n}/'"]*"}"   {
                          CORD_APPEND;
                          if (yyleng > 1 && yytext[yyleng - 2] == '%')
                          {
                            BEGIN(INITIAL);
                            NewStringToken( C_SECTION, ActionStr, startLine, yylineno );
                            yylval.tok->cord = cord;
                            return C_SECTION;
                          }
                        }
}

<IN_ACTION1>{
        "{"             TOK_ACT_INIT; startLine = yylineno; level = 1; BEGIN( IN_ACTION2 );
        .  |
        \n              ASSERT( 0 );
}

<IN_ACTION2>{
        <<EOF>>         Error( "Action started on line %u not closed", startLine ); yyterminate();

        \n              NL(); CORD_APPEND;
        \"              yy_push_state( IN_C_STR ); CORD_APPEND;
        '               yy_push_state( IN_C_CHAR ); CORD_APPEND;
        "/*"            yy_push_state( COMMENT ); CORD_APPEND;
        "//"            yy_push_state( LINE_COMMENT ); CORD_APPEND;
        "/"             CORD_APPEND;

        "{"             CORD_APPEND; ++level;
        "}"             {
                          CORD_APPEND; 
                          if (--level == 0)
                          {
                            BEGIN( INITIAL );
                            TOK_ACT_APPEND;
                            NewStringToken( ACTION2, ActionStr, startLine, yylineno );
                            yylval.tok->act = act;
                            return ACTION2;
                          }
                        }

        "@"{SIMPLEID}   {
                          if (CurNT == NULL)
                            yymore();
                          else
                          {
                            TSymbol * local;
                            int       refIndex;
                            int       kind = CurNTFindLocal( NewString( yytext + 1 ), &local, &refIndex );

                            if (kind != 0)
                            {
                              TOK_ACT_APPEND; // Append the text up to here
                              TOK_ACT_NEW;    // create a new action token for the ident

                              if (kind == 1)
                              {
                                curAct->code = AC_LOC_SYM;
                                curAct->sym = local;
                              }
                              else
                              {
                                curAct->code = AC_LOC_REF_INDEX;
                                curAct->refIndex = refIndex;
                              }
                            }
                          }
                        }

        "@"[0-9]+       {
                          if (CurNT == NULL)
                            yymore();
                          else
                          {
                            int index = atoi( &yytext[1] );
                            TOK_ACT_APPEND; // append the text up to here
                            TOK_ACT_NEW;    // create new action token for the ref

                            curAct->code = AC_LOC_REF_INDEX;
                            curAct->refIndex = index;
                            curAct->refType = NULL;
                          }
                        }

        "@"             CORD_APPEND;

        "$"{SIMPLEID}   {
                          if (CurNT == NULL)
                            yymore();
                          else
                          {
                            TSymbol * local;
                            int       refIndex;
                            int       kind = CurNTFindLocal( NewString( yytext + 1 ), &local, &refIndex );

                            if (kind != 0)
                            {
                              TOK_ACT_APPEND; // Append the text up to here
                              TOK_ACT_NEW;    // create a new action token for the ident

                              if (kind == 1)
                              {
                                curAct->code = AC_SYM;
                                curAct->sym = local;
                              }
                              else
                              {
                                curAct->code = AC_REF_INDEX;
                                curAct->refIndex = refIndex;
                              }
                            }
                          }
                        }
        "$"(<{SIMPLEID}>)?[0-9]+  {
                          if (CurNT == NULL)
                            yymore();
                          else
                          {
                            STRING type = NULL;
                            char * pNum; // start of the number
                            int index;

                            // If we have a type, extract it
                            //
                            if (yytext[1] == '<')
                            {
                              char saveCh;

                              pNum = strchr( yytext + 2, '>' ) + 1; // locate end of type
                              saveCh = *pNum;
                              *pNum = 0;

                              type = NewString( yytext + 1 );
                              *pNum = saveCh;
                            }
                            else
                              pNum = yytext + 1;
                            
                            index = atoi( pNum );  

                            Warning( "Usage of $N is deprecated" );

                            TOK_ACT_APPEND; // append the text up to here
                            TOK_ACT_NEW;    // create new action token for the ref

                            curAct->code = AC_REF_INDEX;
                            curAct->refIndex = index;
                            curAct->refType = type;
                          }
                        }
        "$"(<{SIMPLEID}>)?"$" {
                          CORD_APPEND;
                          if (yytext[1] == '<')
                            Warning( "$<type>$ is deprecated - prevents strict GC" );
                        }

        "$"            |
        "$"<           |
        "$"<{SIMPLEID} |
        "$"<{SIMPLEID}>   Error( "Invalid value reference '%s'", yytext ); CORD_APPEND;
                          
        [^\n}{/'"$@]*   CORD_APPEND;
}

<IN_END_SECTION>{
        <<EOF>>         { 
                          CORD_APPEND; 
                          BEGIN(INITIAL);
                          NewStringToken( END_SECTION, ActionStr, startLine, yylineno );
                          yylval.tok->cord = cord;
                          return END_SECTION;
                        }
        .*              CORD_APPEND;
        .*\n            NL(); CORD_APPEND;
}

%%

//--------------------------------------------------------------------------
// Name         New_TActTok 
//
// 
//--------------------------------------------------------------------------
TActTok * New_TActTok ( void )
{
  TActTok * res = GC_NEW(TActTok);
  res->pLast = res;
  return res;
};

//--------------------------------------------------------------------------
// Name         ActTok_Append 
//
// 
//--------------------------------------------------------------------------
TActTok * ActTok_Append ( TActTok * a, TActTok * b )
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
// Name         ScannerInit 
//
// 
//--------------------------------------------------------------------------
void ScannerInit ( void )
{
  section = 0;
  yylineno = 1;
  ActionStr = NewString( "{<<ACTION>>}" );
};

//--------------------------------------------------------------------------
// Name         NewStringToken 
//
// 
//--------------------------------------------------------------------------
static int NewStringToken ( int code, STRING str, int line, int lastLine )
{
  yylval.tok = New_TToken( code );
  yylval.tok->line = line;
  yylval.tok->lastLine = lastLine;
  yylval.tok->str = str;
  yylval.tok->pLast = yylval.tok;
  return code;
};

//--------------------------------------------------------------------------
// Name         NewToken
//
// 
//--------------------------------------------------------------------------
static int NewToken ( int code )
{
  return NewStringToken( code, NewString( yytext ), yylineno, yylineno );
};


//--------------------------------------------------------------------------
// Name         StringFromCord 
//
// 
//--------------------------------------------------------------------------
static STRING StringFromCord ( CORD cord )
{
  STRING res;

  if (cord == NULL)
  {
    res = NULL;
  }
  else
  // A little optimization. If teh cord has only one segment
  // we can use it directly instead of allocating a buffer
  //
  if (cord->pNext == NULL)
  {
    res = NewStringLen( (char *)cord->u.data, cord->segLen - 1 );
  }
  else
  {
    char * pszBuffer, * dest;

    // Don't forget to reserve for the 0
    dest = pszBuffer = GC_ARRAY_NEW_ATOMIC( char, cord->totalLen );
    do
    {
      memcpy( dest, cord->u.data, cord->segLen - 1 );
      dest += cord->segLen - 1;
      cord = cord->pNext;
    }
    while (cord != NULL);

    // no need to terminate the string fo NewStringLen

    res = NewStringLen( pszBuffer, dest - pszBuffer );

    // We don't really have to do this but just to signify that this buffer
    // is just temporary and will *never* be used again...
    GC_DELETE( pszBuffer ); 
  }

  return res;
};
