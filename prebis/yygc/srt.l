%{
#define YY_MAIN 1
//.*\..*\n           ECHO;
%}

%option nodefault
%option noyywrap

WS       [ \f\v\t]+

%%

^"state"{WS}.+\n        ECHO; 

[^ \f\v\t\n]+{WS}\.     printf("        %s\n",yytext);

.
\n

%%
