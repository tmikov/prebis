






















%union
{
  int ast;
  int str;
  int token;
  int sym;
  int typ;
  int dspecs;
}




%token <token> C_VOID C_CHAR C_SHORT C_INT C_LONG C_SIGNED C_UNSIGNED C_FLOAT C_DOUBLE 
%token <token> C__BOOL C__COMPLEX C__IMAGINARY 


%token C_EXT_INT 
%token C_EXT_FLOAT 



%token <token> C_CONST C_VOLATILE C_RESTRICT 



%token <token> C_EXTERN C_AUTO C_STATIC C_REGISTER C_TYPEDEF 

%token C_INLINE 



%token SWITCH 
%token STRUCT 
%token CONTINUE 
%token CASE 
%token SIZEOF 
%token DEFAULT 
%token ELSE 
%token WHILE 
%token DO 
%token ENUM 
%token GOTO 
%token BREAK 
%token IF 
%token FOR 
%token UNION 
%token RETURN 

%token <str> IDENT 
%token <sym> TYPENAME 

%token <ast> NUMBER 
%token <ast> F_NUMBER 
%token STRING_CONST 
%token LSTRING_CONST 



%token LOG_OR LOG_AND INC DEC PTR ELLIPSIS 



%token ASSIGN 
%token EQCOMPARE 
%token ARITHCOMPARE 
%token SHIFT 


%token DECLSPEC 


%token ATTR 



%token TYPEOF LABEL ALIGNOF GCC_ATTRIBUTE 


%left IF 
%left ELSE 






%expect 4 

%type<ast> constant %type<str> any_identifier %type<ast> primary_expression %type<ast> expression %type<ast> postfix_expression %type<ast> assignment_expression %type<ast> unary_expression %type<ast> cast_expression %type<ast> multiplicative_expression %type<ast> additive_expression %type<ast> shift_expression %type<ast> relational_expression %type<ast> equality_expression %type<ast> and_expression %type<ast> exclusive_or_expression %type<ast> inclusive_or_expression %type<ast> logical_and_expression %type<ast> logical_or_expression %type<ast> conditional_expression %type<ast> expression1 %type<ast> constant_expression1 %type<ast> constant_expression %type<typ> GenType_declaration_specifiers %type<dspecs> declaration_specifiers %type<dspecs> storage_class_specifier %type<dspecs> declaration_specifiers_opt %type<dspecs> function_specifier %type<dspecs> type_qualifier %type<dspecs> type_specifier %type<dspecs> declaration_specifiers1 %type<dspecs> typedef_name %type<dspecs> declaration_specifiers2 %type<token> sclass %type<dspecs> declspec %type<dspecs> declspec_list_opt %type<token> typespec %type<dspecs> extended_int_specifier %type<dspecs> struct_or_union_specifier %type<dspecs> enum_specifier %type<typ> GenType_specifier_qualifier_list %type<dspecs> specifier_qualifier_list %type<dspecs> specifier_qualifier_list1 %type<dspecs> specifier_qualifier_list2 %type<token> qual %type<typ> pointer_opt %type<typ> type_qualifier_list_opt %type<dspecs> type_qualifier_list %type<typ> left_bra_CopyType %type<typ> qual_pointer %type<typ> pointer %% 

start: 
translation_unit { @1 }
| 
;









comma_opt: 

| ',' 
;








constant: 
NUMBER 
| F_NUMBER 



;

string_literal: 
STRING_CONST 
| LSTRING_CONST 
| string_literal STRING_CONST 
| string_literal LSTRING_CONST 
;




























identifier: 
IDENT {TODO;}
;

any_identifier: 
TYPENAME { $$ = $1->id.strName }
| IDENT 
;







primary_expression: 
identifier {TODO;}
| constant 
| string_literal {TODO;}
| '(' expression ')' { $$ = $2; }

| '(' compound_statement ')' {TODO;}
;


postfix_expression: 
primary_expression 
| postfix_expression '[' expression ']' {TODO;}
| postfix_expression '(' argument_expression_list_opt ')' {TODO;}
| postfix_expression '.' any_identifier {TODO;}
| postfix_expression PTR any_identifier {TODO;}
| postfix_expression INC {TODO;}
| postfix_expression DEC {TODO;}
| '(' type_name ')' '{' initializer_list comma_opt '}' {TODO;}
;

argument_expression_list: 
assignment_expression {TODO;}
| argument_expression_list ',' assignment_expression {TODO;}
;

argument_expression_list_opt: 

| argument_expression_list 
;


unary_expression: 
postfix_expression 
| INC unary_expression {TODO;}
| DEC unary_expression {TODO;}
| unary_operator cast_expression {TODO;}
| SIZEOF unary_expression {TODO;}
| SIZEOF '(' type_name ')' {TODO;}


| ALIGNOF unary_expression {TODO;}
| ALIGNOF '(' type_name ')' {TODO;}
| LOG_AND any_identifier {TODO;}
;

unary_operator: 
'&' | '*' | '+' | '-' | '~' | '!' 
;



cast_expression: 
unary_expression 
| '(' type_name ')' cast_expression {TODO;}
;


multiplicative_expression: 
cast_expression 
| multiplicative_expression '*' cast_expression {$$ = Expr_mul( &@1, $1, $3 )}
| multiplicative_expression '/' cast_expression {TODO;}
| multiplicative_expression '%' cast_expression {TODO;}
;


additive_expression: 
multiplicative_expression 
| additive_expression '+' multiplicative_expression {TODO;}
| additive_expression '-' multiplicative_expression {TODO;}
;


shift_expression: 
additive_expression 
| shift_expression SHIFT additive_expression {TODO;}
;


relational_expression: 
shift_expression 
| relational_expression ARITHCOMPARE shift_expression {TODO;}
;


equality_expression: 
relational_expression 
| equality_expression EQCOMPARE relational_expression {TODO;}
;


and_expression: 
equality_expression 
| and_expression '&' equality_expression {$$ = Expr_binAnd( &@2, $1, $3 )}
;


exclusive_or_expression: 
and_expression 
| exclusive_or_expression '^' and_expression {$$ = Expr_binXor( &@2, $1, $3 )}
;


inclusive_or_expression: 
exclusive_or_expression 
| inclusive_or_expression '|' exclusive_or_expression {$$ = Expr_binOr( &@2, $1, $3 )}
;


logical_and_expression: 
inclusive_or_expression 
| logical_and_expression LOG_AND inclusive_or_expression {TODO;}
;


logical_or_expression: 
logical_and_expression 
| logical_or_expression LOG_OR logical_and_expression {TODO;}
;


conditional_expression: 
logical_or_expression 

| logical_or_expression '?' expression_opt ':' conditional_expression {TODO;}
;


assignment_expression: 
conditional_expression 
| unary_expression assignment_operator assignment_expression {TODO;}
;

assignment_expression_opt: 

| assignment_expression {TODO;DumpAst( $1 );}
;

assignment_operator: 
ASSIGN | '=' 
;


expression1: 
assignment_expression 
| expression1 ',' assignment_expression {TODO;}
;

expression: 
expression1 { DumpAst( $1 ) }
;

expression_opt: 

| expression {TODO;}
;


constant_expression1: 
conditional_expression 
;

constant_expression: 
constant_expression1 { DumpAst( $1 ) }
;


































declaration: 
GenType_declaration_specifiers init_declarator_list_opt ';' {TODO}
;

GenType_declaration_specifiers: 
declaration_specifiers { $$ = DSpecs_GenType( $1 ) }
;














declaration_specifiers: 
storage_class_specifier declaration_specifiers_opt { $$ = DSpecs_Add( $1, $2 ) }
| function_specifier declaration_specifiers_opt { $$ = DSpecs_Add( $1,      $2 ) }
| type_qualifier declaration_specifiers_opt { $$ = DSpecs_Add( $1,          $2 ) }

| type_specifier declaration_specifiers1 { $$ = DSpecs_Add( $1,          $2 ) }
| typedef_name declaration_specifiers2 { $$ = DSpecs_Add( $1,            $2 ) }
;

declaration_specifiers_opt: 
{ $$ = NULL }
| declaration_specifiers 
;

declaration_specifiers1: 
{ $$ = NULL }
| storage_class_specifier declaration_specifiers1 { $$ = DSpecs_Add( $1, $2 ) }
| function_specifier declaration_specifiers1 { $$ = DSpecs_Add( $1,      $2 ) }
| type_qualifier declaration_specifiers1 { $$ = DSpecs_Add( $1,          $2 ) }
| type_specifier declaration_specifiers1 { $$ = DSpecs_Add( $1,          $2 ) }
;

declaration_specifiers2: 
{ $$ = NULL }
| storage_class_specifier declaration_specifiers2 { $$ = DSpecs_Add( $1, $2 ) }
| function_specifier declaration_specifiers2 { $$ = DSpecs_Add( $1,      $2 ) }
| type_qualifier declaration_specifiers2 { $$ = DSpecs_Add( $1,          $2 ) }
;

init_declarator_list: 
init_declarator 
| init_declarator_list ',' {$<typ>$=$<typ>0} init_declarator 
;

init_declarator_list_opt: 

| init_declarator_list 
;

init_declarator: 
declarator 
| declarator '=' initializer 
;


storage_class_specifier: 
sclass { $$ = New_DSpecs( $1 ) }

| declspec 
;

sclass: 

C_TYPEDEF 
| C_EXTERN 
| C_STATIC 
| C_AUTO 
| C_REGISTER 
;







declspec: 
DECLSPEC '(' any_identifier ')' {TODO}
;

declspec_list_opt: 
{ $$ = NULL }
| declspec_list_opt declspec {TODO}
;














type_specifier: 
typespec { $$ = New_DSpecs( $1 ) }
| extended_int_specifier 
| struct_or_union_specifier 
| enum_specifier 


| TYPEOF '(' expression ')' {TODO}
| TYPEOF '(' type_name ')' {TODO}
;

typespec: 
C_VOID 
| C_CHAR 
| C_SHORT 
| C_INT 
| C_LONG 
| C_SIGNED 
| C_UNSIGNED 
| C_FLOAT 
| C_DOUBLE 
| C__BOOL 
| C__COMPLEX 
| C__IMAGINARY 
;


extended_int_specifier: 
C_EXT_INT '(' NUMBER ')' {TODO}
;



struct_or_union_specifier: 
struct_or_union declspec_list_opt any_identifier '{' struct_declaration_list '}' {TODO}
| struct_or_union declspec_list_opt '{' struct_declaration_list '}' {TODO}
| struct_or_union declspec_list_opt any_identifier {TODO}
;

struct_or_union: 
STRUCT 
| UNION 
;

struct_declaration_list: 
struct_declaration 
| struct_declaration_list struct_declaration 
;

struct_declaration: 
GenType_specifier_qualifier_list struct_declarator_list ';' {TODO}
;

GenType_specifier_qualifier_list: 
specifier_qualifier_list { $$ = DSpecs_GenType( $1 ) }
;








specifier_qualifier_list: 
type_qualifier specifier_qualifier_list { $$ = DSpecs_Add( $1, $2 ) }
| type_qualifier 
| type_specifier specifier_qualifier_list1 { $$ = DSpecs_Add( $1, $2 ) }
| typedef_name specifier_qualifier_list2 { $$ = DSpecs_Add( $1,   $2 ) }
;

specifier_qualifier_list1: 
{ $$ = NULL }
| type_qualifier specifier_qualifier_list1 { $$ = DSpecs_Add( $1, $2 ) }
| type_specifier specifier_qualifier_list1 { $$ = DSpecs_Add( $1, $2 ) }
;

specifier_qualifier_list2: 
{ $$ = NULL }
| type_qualifier specifier_qualifier_list2 { $$ = DSpecs_Add( $1, $2 ) }
;

struct_declarator_list: 
struct_declarator 
| struct_declarator_list ',' {$<typ>$=$<typ>0} struct_declarator 
;

struct_declarator: 
declarator 
| declarator ':' constant_expression 
| ':' constant_expression 
;


enum_specifier: 
ENUM any_identifier '{' enumerator_list comma_opt '}' {TODO}
| ENUM '{' enumerator_list comma_opt '}' {TODO}
| ENUM any_identifier {TODO}
;

enumerator_list: 
enumerator 
| enumerator_list ',' enumerator 
;

enumerator: 
enumeration_constant 
| enumeration_constant '=' constant_expression 
;

enumeration_constant: 
any_identifier {TODO}
;


type_qualifier: 
qual { $$ = New_DSpecs( $1 ) }






| ATTR '(' any_identifier ')' {TODO}
;

qual: 
C_CONST 
| C_RESTRICT 
| C_VOLATILE 
;



function_specifier: 
C_INLINE {TODO}
;



declarator: 
pointer_opt direct_declarator {TODO}
;

direct_declarator_tail: 
'[' type_qualifier_list_opt assignment_expression_opt ']' 
| '[' C_STATIC type_qualifier_list_opt assignment_expression ']' 
| '[' type_qualifier_list C_STATIC assignment_expression ']' 
| '[' type_qualifier_list_opt '*' ']' 
| '(' parameter_type_list ')' 
| '(' identifier_list_opt ')' 
;






















left_bra_CopyType: 
'(' { $$ = $<typ>0 }
;

direct_declarator: 
any_identifier {TODO}
| left_bra_CopyType declarator ')' {TODO}
| direct_declarator direct_declarator_tail 
;







declarator1: 
pointer_opt direct_declarator1 {TODO}
;

direct_declarator1: 
any_identifier {TODO}
| left_bra_CopyType declarator2 ')' {TODO}
| direct_declarator1 direct_declarator_tail 
;

declarator2: 
pointer_opt direct_declarator2 {TODO}
;

direct_declarator2: 
identifier 
| left_bra_CopyType declarator2 ')' {TODO}
| direct_declarator2 direct_declarator_tail 
;







qual_pointer: 
'*' type_qualifier_list_opt 
{ 
        $2->tnode = New_TTypeNode( TYPE_POINTER ); 
        $2->tnode->of = $<typ>0;
        $$ = $2;
      }
;

pointer: 
qual_pointer 
| pointer qual_pointer { $$ = $2 }
;

pointer_opt: 
{ $$ = $<typ>0 }
| pointer 
;

type_qualifier_list: 
type_qualifier 
| type_qualifier_list type_qualifier { $$ = DSpecs_Add( $1, $2 ) }
;

type_qualifier_list_opt: 
{ $$ = DSpecs_GenQual( NULL ) }
| type_qualifier_list { $$ = DSpecs_GenQual( $1 ) }
;




forward_parameter_decl: 

;









parameter_type_list: 
forward_parameter_decl parameter_list 
| forward_parameter_decl parameter_list ',' ELLIPSIS 
;

parameter_type_list_opt: 

| parameter_type_list 
;

parameter_list: 
parameter_declaration 
| parameter_list ',' parameter_declaration 
;

parameter_declaration: 
GenType_declaration_specifiers declarator1 {TODO}
| GenType_declaration_specifiers abstract_declarator {TODO}
| GenType_declaration_specifiers {TODO}
;










identifier_list: 
identifier 
| identifier_list ',' any_identifier 
;

identifier_list_opt: 

| identifier_list 
;


type_name: 
GenType_specifier_qualifier_list abstract_declarator {TODO}
| GenType_specifier_qualifier_list {TODO}
;

abstract_declarator: 
pointer {TODO}
| pointer_opt direct_abstract_declarator {TODO}
;

direct_abstract_declarator: 
left_bra_CopyType abstract_declarator ')' {TODO}
| direct_abstract_declarator '[' assignment_expression_opt ']' 
| '[' assignment_expression_opt ']' 
| direct_abstract_declarator '[' '*' ']' 
| '[' '*' ']' 
| direct_abstract_declarator '(' parameter_type_list_opt ')' 
| '(' parameter_type_list_opt ')' 

;


typedef_name: 
TYPENAME {TODO1("Save the typedef itself"); /*$$ = New_DSpecs( $1 );*/}
;


initializer: 
assignment_expression {TODO;}
| '{' initializer_list comma_opt '}' 
;

initializer_list: 
designation_opt initializer 
| initializer_list ',' designation_opt initializer 
;

designation: 
designator_list '=' 
;

designation_opt: 

| designation 
;

designator_list: 
designator 
| designator_list designator 
;

designator: 
'[' constant_expression ']' 
| '.' any_identifier 


| '[' constant_expression ELLIPSIS constant_expression ']' 

;








statement: 
labeled_statement 
| compound_statement 
| expression_statement 
| selection_statement 
| iteration_statement 
| jump_statement 
;


labeled_statement: 
any_identifier ':' statement {TODO}
| CASE constant_expression ':' statement 
| DEFAULT ':' statement 


| CASE constant_expression ELLIPSIS constant_expression ':' statement 
;


compound_statement: 
'{' declare_labels_list_opt block_item_list_opt '}' 
;



declare_labels_list: 
declare_labels ';' 
| declare_labels_list declare_labels ';' 
;

declare_labels_list_opt: 

| declare_labels_list 
;

declare_labels: 
LABEL any_identifier 
| declare_labels ',' any_identifier 
;

block_item_list: 
block_item 
| block_item_list block_item 
;

block_item_list_opt: 

| block_item_list 
;

block_item: 
declaration 
| statement 
;


expression_statement: 
expression_opt ';' 
;


selection_statement: 
IF '(' expression ')' statement %prec IF 
| IF '(' expression ')' statement ELSE statement %prec ELSE 
| SWITCH '(' expression ')' statement 
;


iteration_statement: 
WHILE '(' expression ')' statement 
| DO statement WHILE '(' expression ')' ';' 
| FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement 
| FOR '(' declaration expression_opt ';' expression_opt ')' statement 
;


jump_statement: 
GOTO any_identifier ';' 

| GOTO '*' cast_expression ';' 

| CONTINUE ';' 
| BREAK ';' 
| RETURN expression_opt ';' 
;








translation_unit: 
external_declaration 
| translation_unit external_declaration 
;

external_declaration: 
function_definition 
| declaration 


| ';' 
;


function_definition: 
GenType_declaration_specifiers declarator 
declaration_list_opt compound_statement {TODO}
;

declaration_list: 
declaration 
| declaration_list declaration 
;

declaration_list_opt: 

| declaration_list 
;

%%

static const char * yytypstrs[] =
{
  "YYST_AST",
  "YYST_STR",
  "YYST_TOKEN",
  "YYST_SYM",
  "YYST_TYP",
  "YYST_DSPECS",
  0
};

static const char * yytoktyp_str[][2] =
{
  { "C_VOID", "YYST_TOKEN" },
  { "C_CHAR", "YYST_TOKEN" },
  { "C_SHORT", "YYST_TOKEN" },
  { "C_INT", "YYST_TOKEN" },
  { "C_LONG", "YYST_TOKEN" },
  { "C_SIGNED", "YYST_TOKEN" },
  { "C_UNSIGNED", "YYST_TOKEN" },
  { "C_FLOAT", "YYST_TOKEN" },
  { "C_DOUBLE", "YYST_TOKEN" },
  { "C__BOOL", "YYST_TOKEN" },
  { "C__COMPLEX", "YYST_TOKEN" },
  { "C__IMAGINARY", "YYST_TOKEN" },
  { "C_CONST", "YYST_TOKEN" },
  { "C_VOLATILE", "YYST_TOKEN" },
  { "C_RESTRICT", "YYST_TOKEN" },
  { "C_EXTERN", "YYST_TOKEN" },
  { "C_AUTO", "YYST_TOKEN" },
  { "C_STATIC", "YYST_TOKEN" },
  { "C_REGISTER", "YYST_TOKEN" },
  { "C_TYPEDEF", "YYST_TOKEN" },
  { "IDENT", "YYST_STR" },
  { "TYPENAME", "YYST_SYM" },
  { "NUMBER", "YYST_AST" },
  { "F_NUMBER", "YYST_AST" },
  { "constant", "YYST_AST" },
  { "any_identifier", "YYST_STR" },
  { "primary_expression", "YYST_AST" },
  { "expression", "YYST_AST" },
  { "postfix_expression", "YYST_AST" },
  { "assignment_expression", "YYST_AST" },
  { "unary_expression", "YYST_AST" },
  { "cast_expression", "YYST_AST" },
  { "multiplicative_expression", "YYST_AST" },
  { "additive_expression", "YYST_AST" },
  { "shift_expression", "YYST_AST" },
  { "relational_expression", "YYST_AST" },
  { "equality_expression", "YYST_AST" },
  { "and_expression", "YYST_AST" },
  { "exclusive_or_expression", "YYST_AST" },
  { "inclusive_or_expression", "YYST_AST" },
  { "logical_and_expression", "YYST_AST" },
  { "logical_or_expression", "YYST_AST" },
  { "conditional_expression", "YYST_AST" },
  { "expression1", "YYST_AST" },
  { "constant_expression1", "YYST_AST" },
  { "constant_expression", "YYST_AST" },
  { "GenType_declaration_specifiers", "YYST_TYP" },
  { "declaration_specifiers", "YYST_DSPECS" },
  { "storage_class_specifier", "YYST_DSPECS" },
  { "declaration_specifiers_opt", "YYST_DSPECS" },
  { "function_specifier", "YYST_DSPECS" },
  { "type_qualifier", "YYST_DSPECS" },
  { "type_specifier", "YYST_DSPECS" },
  { "declaration_specifiers1", "YYST_DSPECS" },
  { "typedef_name", "YYST_DSPECS" },
  { "declaration_specifiers2", "YYST_DSPECS" },
  { "sclass", "YYST_TOKEN" },
  { "declspec", "YYST_DSPECS" },
  { "declspec_list_opt", "YYST_DSPECS" },
  { "typespec", "YYST_TOKEN" },
  { "extended_int_specifier", "YYST_DSPECS" },
  { "struct_or_union_specifier", "YYST_DSPECS" },
  { "enum_specifier", "YYST_DSPECS" },
  { "GenType_specifier_qualifier_list", "YYST_TYP" },
  { "specifier_qualifier_list", "YYST_DSPECS" },
  { "specifier_qualifier_list1", "YYST_DSPECS" },
  { "specifier_qualifier_list2", "YYST_DSPECS" },
  { "qual", "YYST_TOKEN" },
  { "pointer_opt", "YYST_TYP" },
  { "type_qualifier_list_opt", "YYST_TYP" },
  { "type_qualifier_list", "YYST_DSPECS" },
  { "left_bra_CopyType", "YYST_TYP" },
  { "qual_pointer", "YYST_TYP" },
  { "pointer", "YYST_TYP" },
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

    if (yytoktyp_str[sym][0] == 0)
      printf( "0" );
    else
      printf( "%s", yytoktyp_str[sym][1] );
  }

  printf( "\n};\n" );
}

int main ( void )
{
  yygen_typdefs();
  yygen_toktyp();
  return 0;
}


