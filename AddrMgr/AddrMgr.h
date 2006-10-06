/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski  <msend@o2.pl>
 *
 * released under GNU GPL v2 licence
 */

class TAddrMgr;
#ifndef ADDRMGR_H
#define ADDRMGR_H

#include <string>
#include "SmartPtr.h"
#include "Container.h"
#include "AddrClient.h"
#include "AddrIA.h"

#ifdef LIBXML2
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#define ADDRDB_DTD (xmlChar*)"AddrMgr.dtd"
#endif

class TAddrMgr
{
  public:
    friend ostream & operator<<(ostream & strum,TAddrMgr &x);
    TAddrMgr(string addrdb, bool loadfile = false);
    virtual ~TAddrMgr();
    
    //--- Client container ---
    void addClient(SmartPtr<TAddrClient> x);
    void firstClient();
    SmartPtr<TAddrClient> getClient();
    SmartPtr<TAddrClient> getClient(SmartPtr<TDUID> duid);
    int countClient();
    bool delClient(SmartPtr<TDUID> duid);

    // --- prefix related ---
    bool addPrefix(SmartPtr<TDUID> clntDuid , SmartPtr<TIPv6Addr> clntAddr,
		   int iface, unsigned long IAID, unsigned long T1, unsigned long T2, 
		   SmartPtr<TIPv6Addr> prefix, unsigned long pref, unsigned long valid,
		   int length, bool quiet);
    bool delPrefix(SmartPtr<TDUID> clntDuid,
		   unsigned long IAID, SmartPtr<TIPv6Addr> prefix,
		   bool quiet);
    bool prefixIsFree(SPtr<TIPv6Addr> prefix);

    //--- Time related methods ---
    unsigned long getT1Timeout();
    unsigned long getT2Timeout();
    unsigned long getPrefTimeout();
    unsigned long getValidTimeout();
    unsigned long getAddrCount(SmartPtr<TDUID> duid, int iface);
    
    // --- backup/restore ---
    void dbLoad();
    virtual void dump();
    bool isDone();

#ifdef LIBXML2
    xmlDocPtr xmlLoad(const char * filename);
    SmartPtr<TAddrAddr> parseAddrAddr(xmlDocPtr doc, xmlNodePtr xmlAddr, int depth);
    SmartPtr<TAddrIA> parseAddrIA(xmlDocPtr doc, xmlNodePtr xmlIA, int depth);
    SmartPtr<TAddrClient> parseAddrClient(xmlDocPtr doc, xmlNodePtr xmlClient, int depth);
    void parseAddrMgr(xmlDocPtr doc,int depth);
#endif

protected:
    virtual void print(ostream & out) = 0;

    bool IsDone;
    List(TAddrClient) ClntsLst;
    string XmlFile;
};

#endif
/*
 * $Id: AddrMgr.h,v 1.12 2006-10-06 00:30:17 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.11  2006-08-21 22:44:58  thomson
 * Cache support added.
 *
 * Revision 1.10  2006/03/05 21:39:19  thomson
 * TA support merged.
 *
 * Revision 1.9.2.1  2006/02/05 23:38:06  thomson
 * Devel branch with Temporary addresses support added.
 *
 * Revision 1.9  2004/12/07 00:45:41  thomson
 * Clnt managers creation unified and cleaned up.
 *
 * Revision 1.8  2004/06/17 23:53:54  thomson
 * Server Address Assignment rewritten.
 *
 * Revision 1.7  2004/06/04 19:03:46  thomson
 * Resolved warnings with signed/unisigned
 *
 * Revision 1.4  2004/04/11 18:04:53  thomson
 * LIBXML2 is now an optional feature
 *
 */
