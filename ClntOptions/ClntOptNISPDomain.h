/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 or later licence
 *
 * $Id: ClntOptNISPDomain.h,v 1.1 2004-10-25 20:45:53 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 *
 */

#ifndef CLNTOPTNISPDOMAIN_H
#define CLNTOPTNISPDOMAIN_H

#include "OptString.h"
#include "DUID.h"
#include "SmartPtr.h"

class TClntOptNISPDomain : public TOptString
{
 public:
    TClntOptNISPDomain(string domain, TMsg* parent);
    TClntOptNISPDomain(char *buf, int bufsize, TMsg* parent);
    bool doDuties();
    void setSrvDuid(SmartPtr<TDUID> duid);
private:
    SmartPtr<TDUID> SrvDUID;
};
#endif
