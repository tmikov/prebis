typedef struct TActTok TActTok;
typedef struct TToken  TToken;
typedef struct TRule   TRule;
typedef struct TProd   TProd;
typedef struct TSymbol TSymbol;

#define TSTRING_DATA_DEFINED
typedef TSymbol TStringData;

#include "ulib\h\strings.h"
#include "ulib\h\cord.h"
#include "ulib\h\debug.h"

typedef TSymbol TIdent;
#include "idtab.h"

#include "pre.tab.h"

// scan.l
//
extern FILE *yyin;
extern int yylineno;
extern char * yytext;
void ScannerInit ( void );

// pre.y
//

void FatalError ( const char * err, ... );
void Error ( const char * err, ... );
void Warning ( const char * err, ... );
void ErrorLine ( int line, const char * err, ... );
void WarningLine ( int line, const char * err, ... );

int yyparse ( void );

//
// Data structures
//

typedef enum
{
  AC_CORD = 0,
  AC_SYM,
  AC_REF_INDEX,     // reference to an item by index. e.g. $2
  AC_LOC_SYM,
  AC_LOC_REF_INDEX, // reference to an item by index. e.g. @2
} ActCode_t;

struct TActTok
{
  ActCode_t code;
  TActTok * pNext, * pLast;

  STRING  refType; // type of $<type>N

  union
  {
    CORD    text;      // AC_STR
    TSymbol * sym;     // AC_IDENT
    int     refIndex;  // 
  };
};

struct TToken
{
  int      code;
  int      line, 
           lastLine;
  TToken * pNext, 
         * pLast;
  STRING   str;
  int      tokindex;
  int      actualIndex;

  union
  {
    TSymbol * sym;    // TERM, NONTERM, IDENT
    int       index;
    TActTok * act;    // ACTION2
    CORD      cord;   // C_SECTION END_SECTION
  };
};

struct TRule
{
  int sepLine; // line of the '|' or ':'

  TRule * nextRule;

  TToken * start;
};

struct TProd
{
  TRule     * firstRule;
  TIdentTab * idtab;      // list of local identifiers
  TListRoot   params;     // list of TSymbol
  int         paramCount;
  int         semiLine;   // line of the ';'
};

typedef enum SymClass_t
{
  SC_NONTERM,
  SC_TERM,
  SC_PARAM,
  SC_TYPE      // used only in TypesTab.
} SymClass_t;

struct TSymbol
{
  TListEntry link;
  STRING name;
  STRING type;

  SymClass_t sc;
  bool   bTyped;
  bool   bDefined;

  TProd * prod;
  int     index;     // parameter index, starting from 1

  STRING  desc;      // description
};

TToken  * New_TToken ( int code );
TProd   * New_TProd ( void );
TSymbol * New_TSymbol ( STRING name );
TSymbol * New_TypeSymbol ( STRING name );
TRule   * New_TRule ( TToken * list );

void Prebis_MarkRoots ( void );
void TActTok_GcMark ( const TActTok * act );
void TToken_GcMark ( const TToken * tok );
void TRule_GcMark ( const TRule * rule );
void TProd_GcMark ( const TProd * prod );
void TSymbol_GcMark ( const TSymbol * sym );

TStringData * StringData ( STRING str );
TSymbol     * GetSymbol ( STRING str );

int CurNTFindLocal ( STRING name, TSymbol ** ppSym, int * pSrcIndex );

extern const char * szFileName;
extern bool  bGenPass1;

extern TListRoot Symbols;
extern STRING ErrorName;
extern TSymbol * CurNT;
extern TRule * CurRule;
extern TIdentTab * TypesTab;

extern int CurTokIndex;
extern int ErrorCount;


// gen.c
//

void Gen ( TToken * tok );
