/*                                                                           
 * Dibbler - a portable DHCPv6                                               
 *                                                                           
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>                           
 *          Marek Senderski <msend@o2.pl>                                    
 *                                                                           
 * released under GNU GPL v2 or later licence                                
 *                                                                           
 * $Id: DHCPClient.cpp,v 1.12 2004-10-25 20:45:52 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.11  2004/09/07 15:37:44  thomson
 * Socket handling changes.
 *
 * Revision 1.10  2004/07/05 00:53:03  thomson
 * Various changes.
 *
 * Revision 1.7  2004/03/29 18:53:08  thomson
 * Author/Licence/cvs log/cvs version headers added.
 *                                                                           
 */

#include <iostream>
#include <stdlib.h>
#include "SmartPtr.h"
#include "DHCPClient.h"
#include "ClntTransMgr.h"
#include "IfaceMgr.h"
#include "ClntIfaceMgr.h"
#include "Logger.h"
#include "Portable.h"

volatile int serviceShutdown;

//static void foo() {
//    SmartPtr<TClntParsGlobalOpt> opt = new TClntParsGlobalOpt();
//}

TDHCPClient::TDHCPClient(string config)
{
    //foo();
    string oldconf = config+"-old";

    serviceShutdown = 0;
    srand(now());
    this->IsDone = false;

    IfaceMgr = new TClntIfaceMgr();
    if ( IfaceMgr->isDone() ) {
 	  Log(Crit) << "Fatal error during IfaceMgr init. Aborting." << LogEnd;
	  this->IsDone = true;
	  return;
    }

    IfaceMgr->dump(CLNTIFACEMGR_FILE);

    TransMgr = new TClntTransMgr(IfaceMgr, config);
    TransMgr->setThat(TransMgr);
}

void TDHCPClient::stop() {
    serviceShutdown = 1;

#ifdef WIN32
    // just to break select() in WIN32 systems
    std::clog << logger::logWarning << "Service shutdown: Sending SHUTDOWN packet on iface="
	      << TransMgr->getCtrlIface() << "/addr=" << TransMgr->getCtrlAddr() << logger::endl;
    int fd = sock_add("", TransMgr->getCtrlIface(),"::",0,true); 
    char buf = CONTROL_MSG;
    int cnt=sock_send(fd,TransMgr->getCtrlAddr(),&buf,1,DHCPCLIENT_PORT,TransMgr->getCtrlIface());
    sock_del(fd);
#endif
}


void TDHCPClient::run()
{
    SmartPtr<TMsg> msg;
    while ( !TransMgr->isDone() && (!this->isDone()) )
    {
	if (serviceShutdown)
	    TransMgr->shutdown();
	
	TransMgr->doDuties();
	
	unsigned int timeout = TransMgr->getTimeout();
	// FIXME: everything should be unsigned
	if (timeout == DHCPV6_INFINITY)
	    timeout = DHCPV6_INFINITY/2;
	if (timeout == 0)
	    timeout = 1;
	
        std::clog << logger::logNotice << "Sleeping for " 
		  << timeout << " seconds." << logger::endl;
        SmartPtr<TMsg> msg=IfaceMgr->select(timeout);
	
        if (msg) {
	    int iface = msg->getIface();
	    SmartPtr<TIfaceIface> ptrIface;
	    ptrIface = IfaceMgr->getIfaceByID(iface);
            Log(Notice) << "Received " << msg->getName() << " on " << ptrIface->getName() 
			<< "/" << iface	<< hex << ",TransID=0x" << msg->getTransID() 
			<< dec << ", " << msg->countOption() << " opts:";
            SmartPtr<TOpt> ptrOpt;
            msg->firstOption();
            while (ptrOpt = msg->getOption() )
                Log(Cont) << " " << ptrOpt->getOptType(); 
            Log(Cont) << logger::endl;
	    
            TransMgr->relayMsg(msg);
        }
    }
}

bool TDHCPClient::isDone() {
    return IsDone;
}

bool TDHCPClient::checkPrivileges() {
    // FIXME: check privileges
    return true;
}

TDHCPClient::~TDHCPClient()
{
}
