/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 or later licence
 *
 * $Id: Iface.h,v 1.5 2004-10-25 20:45:53 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 */

#ifndef IFACEIFACE_H
#define IFACEIFACE_H

#include "Portable.h"
#include "SmartPtr.h"
#include "Container.h"
#include "SocketIPv6.h"
#include "IPv6Addr.h"

/*
 * represents network interface 
 */
class TIfaceIface{
 public:
    friend ostream & operator <<(ostream & strum, TIfaceIface &x);

    TIfaceIface(char * name, int id, unsigned int flags, char* mac, 
                int maclen, char* llAddr, int llAddrCnt, int hwType);
    char * getName();
    int getID();

    // ---flags related---
    unsigned int getFlags();
    bool flagUp();
    bool flagRunning();
    bool flagMulticast();
    bool flagLoopback();

    // ---layer-2 related---
    int   getMacLen();
    char* getMac();
    int   getHardwareType();
    char* firstLLAddress();
    char* getLLAddress();

    // ---address related---
    bool addAddr(SmartPtr<TIPv6Addr> addr, long pref, long valid);
    bool delAddr(SmartPtr<TIPv6Addr> addr);
    bool updateAddr(SmartPtr<TIPv6Addr> addr, long pref, long valid);
    
    // ---socket related---
    bool addSocket(SmartPtr<TIPv6Addr> addr,int port, bool ifaceonly = true);
    bool addSocket(int port, bool ifaceonly = true); 
    bool delSocket(int id);
    void firstSocket();
    SmartPtr <TIfaceSocket> getSocketByFD(int fd);
    SmartPtr <TIfaceSocket> getSocket();
    int countSocket();

    ~TIfaceIface();

 protected:
    // ---interface data---
    char Name[MAX_IFNAME_LENGTH];
    int ID;
    unsigned int Flags;
    char* Mac;
    int Maclen;
    char* LLAddr;
    int LLAddrCnt;
    int HWType;

    // sockets
    TContainer< SmartPtr<TIfaceSocket> > SocketsLst;
    char*   PresLLAddr;
};

#endif
