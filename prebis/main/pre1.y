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
#include "prebis_1.inc"

