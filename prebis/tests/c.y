%{
#include "precomp.h"
#include "cfe_priv.h"

#include "c.tab.inc" // automatically generated definitions

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

static void yy_mark ( unsigned typ, const YYSTYPE * pval );

// Use this to fix bison type errors when we *really* don't have a result
// from a production.
#define NO_RESULT  ((void)0)

static TDeclSpecs * DSPECS_COMBINE ( TDeclSpecs * a, TDeclSpecs ** pb );
static TQualNode * DSPECS_GENQUAL ( TDeclSpecs ** pds );

%}

%union 
{
  STRING       str;
  TSymbol      * sym;
  TQualNode    * typ;
  CORD         cord;
  TAst         * ast;
  TDeclSpecs   * dspecs;
  int          token;
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

%type<ast> constant %type<str> any_identifier %type<ast> primary_expression expression postfix_expression assignment_expression unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression expression1 constant_expression1 constant_expression %type<dspecs> GenType_declaration_specifiers declaration_specifiers storage_class_specifier declaration_specifiers_opt function_specifier type_qualifier type_specifier declaration_specifiers1 typedef_name declaration_specifiers2 %type<token> sclass %type<dspecs> declspec declspec_list_opt %type<token> typespec %type<dspecs> extended_int_specifier struct_or_union_specifier enum_specifier GenType_specifier_qualifier_list specifier_qualifier_list specifier_qualifier_list1 specifier_qualifier_list2 %type<token> qual %type<dspecs> pointer_opt direct_declarator direct_declarator_tail %type<typ> type_qualifier_list_opt %type<dspecs> type_qualifier_list left_bra_CopyDSpecs direct_declarator1 direct_declarator2 qual_pointer pointer %% 

start: 
translation_unit { @1 }
| 
;







garbage_collect: 
{
      // Is it time to collect ?
      // In debug builds we always perform a full collection to make sure
      // there isn't a marking bug.
      //
#ifdef _DEBUG
      if (GcCollectStart( true )) 
#else
      if (GcCollectStart( false )) 
#endif
      {
        YY_MARK_STACK();   // mark the contents of the parser stack
        Cfe_GcMarkRoots(); // mark all C front-end data

        GcCollectEnd();
      }
    }
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
GenType_declaration_specifiers 
init_declarator_list_opt ';' 
{NO_RESULT}
;

GenType_declaration_specifiers: 
declaration_specifiers { $$ = DSpecs_GenType( $1 ) }
;














declaration_specifiers: 
storage_class_specifier declaration_specifiers_opt { $$ = DSPECS_COMBINE( $1, &$2 ) }
| function_specifier declaration_specifiers_opt { $$ = DSPECS_COMBINE( $1,      &$2 ) }
| type_qualifier declaration_specifiers_opt { $$ = DSPECS_COMBINE( $1,          &$2 ) }

| type_specifier declaration_specifiers1 { $$ = DSPECS_COMBINE( $1,          &$2 ) }
| typedef_name declaration_specifiers2 { $$ = DSPECS_COMBINE( $1,            &$2 ) }
;

declaration_specifiers_opt: 
{ $$ = NULL }
| declaration_specifiers 
;

declaration_specifiers1: 
{ $$ = NULL }
| storage_class_specifier declaration_specifiers1 { $$ = DSPECS_COMBINE( $1, &$2 ) }
| function_specifier declaration_specifiers1 { $$ = DSPECS_COMBINE( $1,      &$2 ) }
| type_qualifier declaration_specifiers1 { $$ = DSPECS_COMBINE( $1,          &$2 ) }
| type_specifier declaration_specifiers1 { $$ = DSPECS_COMBINE( $1,          &$2 ) }
;

declaration_specifiers2: 
{ $$ = NULL }
| storage_class_specifier declaration_specifiers2 { $$ = DSPECS_COMBINE( $1, &$2 ) }
| function_specifier declaration_specifiers2 { $$ = DSPECS_COMBINE( $1,      &$2 ) }
| type_qualifier declaration_specifiers2 { $$ = DSPECS_COMBINE( $1,          &$2 ) }
;

init_declarator_list: 
init_declarator 
| init_declarator_list ',' {$<dspecs>$=$<dspecs>0} init_declarator 
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
type_qualifier specifier_qualifier_list { $$ = DSPECS_COMBINE( $1, &$2 ) }
| type_qualifier 
| type_specifier specifier_qualifier_list1 { $$ = DSPECS_COMBINE( $1, &$2 ) }
| typedef_name specifier_qualifier_list2 { $$ = DSPECS_COMBINE( $1,   &$2 ) }
;

specifier_qualifier_list1: 
{ $$ = NULL }
| type_qualifier specifier_qualifier_list1 { $$ = DSPECS_COMBINE( $1, &$2 ) }
| type_specifier specifier_qualifier_list1 { $$ = DSPECS_COMBINE( $1, &$2 ) }
;

specifier_qualifier_list2: 
{ $$ = NULL }
| type_qualifier specifier_qualifier_list2 { $$ = DSPECS_COMBINE( $1, &$2 ) }
;

struct_declarator_list: 
struct_declarator 
| struct_declarator_list ',' {$<dspecs>$=$<dspecs>0} struct_declarator 
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
pointer_opt direct_declarator 
{
        Declare( $2 );
      }
;

direct_declarator_tail: 
'[' type_qualifier_list_opt assignment_expression_opt ']' 
{
        TTypeNode * tnode = New_TTypeNode( TYPE_ARRAY );
        tnode->of = $<dspecs>0->type;
        tnode->u.arrayLen = $3;

        $$ = DSpecs_SetType( $<dspecs>0, $2, tnode );
      }
| '[' C_STATIC type_qualifier_list_opt assignment_expression ']' 
| '[' type_qualifier_list C_STATIC assignment_expression ']' 
| '[' type_qualifier_list_opt '*' ']' 
| '(' parameter_type_list ')' 
| '(' identifier_list_opt ')' 
;






















left_bra_CopyDSpecs: 
'(' { $$ = $<dspecs>0 }
;

direct_declarator: 
any_identifier 
{ 
        $$ = DSpecs_SetIdent( $1 );
      }
| left_bra_CopyDSpecs declarator ')' 
{
        $$ = $2;
      }
| direct_declarator direct_declarator_tail 
{ 
        $$ = $2;
      }
;







declarator1: 
pointer_opt direct_declarator1 
{
        Declare( $2 );
      }
;

direct_declarator1: 
any_identifier 
{ 
        $$ = DSpecs_SetIdent( $1 );
      }
| left_bra_CopyDSpecs declarator2 ')' 
{
        $$ = $2;
      }
| direct_declarator1 direct_declarator_tail 
{ 
        $$ = $2;
      }
;

declarator2: 
pointer_opt direct_declarator2 
{
        Declare( $2 );
      }
;

direct_declarator2: 
identifier 
{ 
        $$ = DSpecs_SetIdent( $1 );
      }
| left_bra_CopyDSpecs declarator2 ')' 
{
        $$ = $2;
      }
| direct_declarator2 direct_declarator_tail 
{ 
        $$ = $2;
      }
;







qual_pointer: 
'*' type_qualifier_list_opt 
{ 
        TTypeNode * tnode = New_TTypeNode( TYPE_POINTER );
        tnode->of = $<dspecs>0->type;

        $$ = DSpecs_SetType( $<dspecs>0, $2, tnode );
      }
;

pointer: 
qual_pointer 
| pointer qual_pointer { $$ = $2 }
;

pointer_opt: 
{ $$ = $<dspecs>0 }
| pointer 
;

type_qualifier_list: 
type_qualifier 
| type_qualifier_list type_qualifier { $$ = DSPECS_COMBINE( $1, &$2 ) }
;

type_qualifier_list_opt: 
{ $$ = DSpecs_GenQual( NULL ) }
| type_qualifier_list { $$ = DSPECS_GENQUAL( &$1 ) }
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
left_bra_CopyDSpecs abstract_declarator ')' {TODO}
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
garbage_collect 
| translation_unit external_declaration 
garbage_collect 
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

// DSpecs manipulation routines, with explicitly freeing the no-longer used 
// argument to conserve memory. 
// Note: we need to zero the parser stack location that holds the 
// freed value.

//--------------------------------------------------------------------------
// Name         DSPECS_COMBINE 
//
// 
//--------------------------------------------------------------------------
static TDeclSpecs * DSPECS_COMBINE ( TDeclSpecs * a, TDeclSpecs ** pb )
{
  TDeclSpecs * res = DSpecs_Add( a, *pb );
  GC_DELETE( *pb );
  return res;
};

//--------------------------------------------------------------------------
// Name         DSPECS_GENQUAL 
//
// 
//--------------------------------------------------------------------------
static TQualNode * DSPECS_GENQUAL ( TDeclSpecs ** pds )
{
  TQualNode * res = DSpecs_GenQual( *pds );
  GC_DELETE( *pds );
  return res;
}

//--------------------------------------------------------------------------
// Name         yy_mark 
//
// Mark the contents of a semantic stack entry (YYSTYPE).
//
// _typ_ identifies the type of the entry, corresponing to a member
// of the declared %union. The possible values of _typ_ (YYST_xxx) are 
// generated automatically by PREBIS and are defined in c.tab.inc
//--------------------------------------------------------------------------
static void yy_mark ( unsigned typ, const YYSTYPE * pval )
{
  switch (typ)
  {
  case YYST_AST:
    GC_MARK( pval->ast ); break;

  case YYST_STR:
    GC_MARK( pval->str ); break;

  case YYST_TOKEN:
    break;

  case YYST_SYM:
    GC_MARK( pval->sym ); break;

  case YYST_TYP:
    GC_MARK( pval->typ ); break;

  case YYST_DSPECS:
    GC_MARK( pval->dspecs ); break;

  default:
    ASSERT( 0 );
  }
}


#ifndef TEST_YYPARSE

void yyerror ( char * err )
{
  CompilerError( "%s", err );
};

#else

void yyerror ( char * err )
{
  printf( "\n\n **** error: %s\n\n", err );
};

int yylex ( void )
{
  int res;
  char buf[32];
  for(;;)
  {
    printf( "Enter code:" );
    gets( buf );

    if (isdigit(buf[0]))
    {
      if (sscanf( buf, "%d", &res ) != 1)
        printf( "Error! Try again.\n" );
      else
        return res;
    }
    else
    if (isalpha( buf[0] ))
    {
      int i;
      for ( i = 0; yytname[i] != NULL; ++i )
      {
        if (_stricmp( buf, yytname[i] ) == 0)
          return i + 255;
      }
      printf( "Undefined token! Try again.\n" );
    }
    else
      return buf[0];
  }
};

int main ( int argc, char ** argv )
{
#if YYDEBUG
  yydebug = argc == 2;
#endif 
  yyparse();

  return 0;
};
#endif // TEST_YYPARSE

