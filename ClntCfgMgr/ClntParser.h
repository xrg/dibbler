#ifndef YY_ClntParser_h_included
#define YY_ClntParser_h_included
#define YY_USE_CLASS

#line 1 "../bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "../bison++/bison.h"
#line 3 "ClntParser.y"

#include <iostream>
#include <string>
#include <malloc.h>
#include "DHCPConst.h"
#include "SmartPtr.h"
#include "Container.h"
#include "ClntParser.h"
#include "ClntParsGlobalOpt.h"
#include "ClntCfgIface.h"
#include "ClntCfgAddr.h"
#include "ClntCfgIA.h"
#include "ClntCfgTA.h"
#include "ClntCfgPD.h"
#include "Logger.h"

    using namespace std;
    
#define YY_USE_CLASS
#define YY_ClntParser_MEMBERS  yyFlexLexer * lex;                                          \
/*List of options in scope stack,the most fresh is last in the list*/       \
TContainer<SmartPtr<TClntParsGlobalOpt> > ParserOptStack;                   \
/*List of parsed interfaces/IAs/Addresses, last */                          \
/*interface/IA/address is just being parsing or have been just parsed*/     \
TContainer<SmartPtr<TClntCfgIface> > ClntCfgIfaceLst;                       \
TContainer<SmartPtr<TClntCfgIA> >    ClntCfgIALst;                          \
TContainer<SmartPtr<TClntCfgTA> >    ClntCfgTALst;                          \
TContainer<SmartPtr<TClntCfgAddr> >  ClntCfgAddrLst;                        \
/*Pointer to list which should contain either rejected servers or */        \
/*preffered servers*/                                                       \
TContainer<SmartPtr<TStationID> > PresentStationLst;                        \
TContainer<SmartPtr<TIPv6Addr> > PresentAddrLst;                            \
TContainer<SmartPtr<string> > PresentStringLst;                             \
/*method check whether interface with id=ifaceNr has been */                \
/*already declared */                                                       \
bool CheckIsIface(int ifaceNr);                                             \
/* method check if interface with id=ifaceName has been already declared */ \
bool CheckIsIface(string ifaceName);                                        \
void StartIfaceDeclaration();                                               \
bool EndIfaceDeclaration();                                                 \
void EmptyIface();                                                          \
void StartIADeclaration(bool aggregation);                                  \
void EndIADeclaration();                                                    \
void EmptyIA();                                                             \
void EmptyAddr();                                                           \
bool iaidSet;                                                               \
unsigned int iaid;                                                          \
virtual ~ClntParser();
#define YY_ClntParser_CONSTRUCTOR_PARAM  yyFlexLexer * lex
#define YY_ClntParser_CONSTRUCTOR_CODE                                                     \
    this->lex = lex;                                                        \
    ParserOptStack.append(new TClntParsGlobalOpt());                        \
    ParserOptStack.getFirst()->setIAIDCnt(1);                               \
    ParserOptStack.getLast();

#line 66 "ClntParser.y"
typedef union    
{
    int ival;    
    char *strval;  
    struct SDuid  {      
        int length;    
        char* duid;  
    } duidval;  
    char addrval[16];  
} yy_ClntParser_stype;
#define YY_ClntParser_STYPE yy_ClntParser_stype

#line 21 "../bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_ClntParser_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_ClntParser_COMPATIBILITY 1
 #else
  #define  YY_ClntParser_COMPATIBILITY 0
 #endif
#endif

#if YY_ClntParser_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_ClntParser_LTYPE
   #define YY_ClntParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_ClntParser_STYPE
   #define YY_ClntParser_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_ClntParser_DEBUG
   #define  YY_ClntParser_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_ClntParser_USE_GOTO
  #define YY_ClntParser_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_ClntParser_USE_GOTO
 #define YY_ClntParser_USE_GOTO 0
#endif

#ifndef YY_ClntParser_PURE

 #line 65 "../bison++/bison.h"

#line 65 "../bison++/bison.h"
/* YY_ClntParser_PURE */
#endif


 #line 68 "../bison++/bison.h"

#line 68 "../bison++/bison.h"
/* prefix */

#ifndef YY_ClntParser_DEBUG

 #line 71 "../bison++/bison.h"

#line 71 "../bison++/bison.h"
/* YY_ClntParser_DEBUG */
#endif

#ifndef YY_ClntParser_LSP_NEEDED

 #line 75 "../bison++/bison.h"

#line 75 "../bison++/bison.h"
 /* YY_ClntParser_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_ClntParser_LSP_NEEDED
 #ifndef YY_ClntParser_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_ClntParser_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_ClntParser_STYPE
 #define YY_ClntParser_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_ClntParser_PARSE
 #define YY_ClntParser_PARSE yyparse
#endif

#ifndef YY_ClntParser_LEX
 #define YY_ClntParser_LEX yylex
#endif

#ifndef YY_ClntParser_LVAL
 #define YY_ClntParser_LVAL yylval
#endif

#ifndef YY_ClntParser_LLOC
 #define YY_ClntParser_LLOC yylloc
#endif

#ifndef YY_ClntParser_CHAR
 #define YY_ClntParser_CHAR yychar
#endif

#ifndef YY_ClntParser_NERRS
 #define YY_ClntParser_NERRS yynerrs
#endif

#ifndef YY_ClntParser_DEBUG_FLAG
 #define YY_ClntParser_DEBUG_FLAG yydebug
#endif

#ifndef YY_ClntParser_ERROR
 #define YY_ClntParser_ERROR yyerror
#endif

#ifndef YY_ClntParser_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_ClntParser_PARSE_PARAM
    #ifndef YY_ClntParser_PARSE_PARAM_DEF
     #define YY_ClntParser_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_ClntParser_PARSE_PARAM
  #define YY_ClntParser_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_ClntParser_PURE
  #ifndef yylval
   extern YY_ClntParser_STYPE YY_ClntParser_LVAL;
  #else
   #if yylval != YY_ClntParser_LVAL
    extern YY_ClntParser_STYPE YY_ClntParser_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "../bison++/bison.h"
#define	T1_	258
#define	T2_	259
#define	PREF_TIME_	260
#define	DNS_SERVER_	261
#define	VALID_TIME_	262
#define	UNICAST_	263
#define	NTP_SERVER_	264
#define	DOMAIN_	265
#define	TIME_ZONE_	266
#define	SIP_SERVER_	267
#define	SIP_DOMAIN_	268
#define	NIS_SERVER_	269
#define	NISP_SERVER_	270
#define	NIS_DOMAIN_	271
#define	NISP_DOMAIN_	272
#define	FQDN_	273
#define	LIFETIME_	274
#define	IFACE_	275
#define	NO_CONFIG_	276
#define	REJECT_SERVERS_	277
#define	PREFERRED_SERVERS_	278
#define	IA_	279
#define	TA_	280
#define	IAID_	281
#define	ADDRES_	282
#define	IPV6ADDR_	283
#define	WORKDIR_	284
#define	RAPID_COMMIT_	285
#define	STATELESS_	286
#define	OPTION_	287
#define	LOGNAME_	288
#define	LOGLEVEL_	289
#define	LOGMODE_	290
#define	STRING_	291
#define	HEXNUMBER_	292
#define	INTNUMBER_	293
#define	DUID_	294
#define	STRICT_RFC_NO_ROUTING_	295
#define	PD_	296


#line 169 "../bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_ClntParser_CLASS
  #define YY_ClntParser_CLASS ClntParser
 #endif

 #ifndef YY_ClntParser_INHERIT
  #define YY_ClntParser_INHERIT
 #endif

 #ifndef YY_ClntParser_MEMBERS
  #define YY_ClntParser_MEMBERS 
 #endif

 #ifndef YY_ClntParser_LEX_BODY
  #define YY_ClntParser_LEX_BODY  
 #endif

 #ifndef YY_ClntParser_ERROR_BODY
  #define YY_ClntParser_ERROR_BODY  
 #endif

 #ifndef YY_ClntParser_CONSTRUCTOR_PARAM
  #define YY_ClntParser_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_ClntParser_USE_CONST_TOKEN
  #define YY_ClntParser_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_ClntParser_USE_CONST_TOKEN != 0
  #ifndef YY_ClntParser_ENUM_TOKEN
   #define YY_ClntParser_ENUM_TOKEN yy_ClntParser_enum_token
  #endif
 #endif

class YY_ClntParser_CLASS YY_ClntParser_INHERIT
{
public: 
 #if YY_ClntParser_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "../bison++/bison.h"
static const int T1_;
static const int T2_;
static const int PREF_TIME_;
static const int DNS_SERVER_;
static const int VALID_TIME_;
static const int UNICAST_;
static const int NTP_SERVER_;
static const int DOMAIN_;
static const int TIME_ZONE_;
static const int SIP_SERVER_;
static const int SIP_DOMAIN_;
static const int NIS_SERVER_;
static const int NISP_SERVER_;
static const int NIS_DOMAIN_;
static const int NISP_DOMAIN_;
static const int FQDN_;
static const int LIFETIME_;
static const int IFACE_;
static const int NO_CONFIG_;
static const int REJECT_SERVERS_;
static const int PREFERRED_SERVERS_;
static const int IA_;
static const int TA_;
static const int IAID_;
static const int ADDRES_;
static const int IPV6ADDR_;
static const int WORKDIR_;
static const int RAPID_COMMIT_;
static const int STATELESS_;
static const int OPTION_;
static const int LOGNAME_;
static const int LOGLEVEL_;
static const int LOGMODE_;
static const int STRING_;
static const int HEXNUMBER_;
static const int INTNUMBER_;
static const int DUID_;
static const int STRICT_RFC_NO_ROUTING_;
static const int PD_;


#line 212 "../bison++/bison.h"
 /* decl const */
 #else
  enum YY_ClntParser_ENUM_TOKEN { YY_ClntParser_NULL_TOKEN=0
  
 #line 215 "../bison++/bison.h"
	,T1_=258
	,T2_=259
	,PREF_TIME_=260
	,DNS_SERVER_=261
	,VALID_TIME_=262
	,UNICAST_=263
	,NTP_SERVER_=264
	,DOMAIN_=265
	,TIME_ZONE_=266
	,SIP_SERVER_=267
	,SIP_DOMAIN_=268
	,NIS_SERVER_=269
	,NISP_SERVER_=270
	,NIS_DOMAIN_=271
	,NISP_DOMAIN_=272
	,FQDN_=273
	,LIFETIME_=274
	,IFACE_=275
	,NO_CONFIG_=276
	,REJECT_SERVERS_=277
	,PREFERRED_SERVERS_=278
	,IA_=279
	,TA_=280
	,IAID_=281
	,ADDRES_=282
	,IPV6ADDR_=283
	,WORKDIR_=284
	,RAPID_COMMIT_=285
	,STATELESS_=286
	,OPTION_=287
	,LOGNAME_=288
	,LOGLEVEL_=289
	,LOGMODE_=290
	,STRING_=291
	,HEXNUMBER_=292
	,INTNUMBER_=293
	,DUID_=294
	,STRICT_RFC_NO_ROUTING_=295
	,PD_=296


#line 215 "../bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_ClntParser_PARSE(YY_ClntParser_PARSE_PARAM);
 virtual void YY_ClntParser_ERROR(char *msg) YY_ClntParser_ERROR_BODY;
 #ifdef YY_ClntParser_PURE
  #ifdef YY_ClntParser_LSP_NEEDED
   virtual int  YY_ClntParser_LEX(YY_ClntParser_STYPE *YY_ClntParser_LVAL,YY_ClntParser_LTYPE *YY_ClntParser_LLOC) YY_ClntParser_LEX_BODY;
  #else
   virtual int  YY_ClntParser_LEX(YY_ClntParser_STYPE *YY_ClntParser_LVAL) YY_ClntParser_LEX_BODY;
  #endif
 #else
  virtual int YY_ClntParser_LEX() YY_ClntParser_LEX_BODY;
  YY_ClntParser_STYPE YY_ClntParser_LVAL;
  #ifdef YY_ClntParser_LSP_NEEDED
   YY_ClntParser_LTYPE YY_ClntParser_LLOC;
  #endif
  int YY_ClntParser_NERRS;
  int YY_ClntParser_CHAR;
 #endif
 #if YY_ClntParser_DEBUG != 0
  public:
   int YY_ClntParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_ClntParser_CLASS(YY_ClntParser_CONSTRUCTOR_PARAM);
public:
 YY_ClntParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_ClntParser_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_ClntParser_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_ClntParser_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_ClntParser_DEBUG 
   #define YYDEBUG YY_ClntParser_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "../bison++/bison.h"
#endif
