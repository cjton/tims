#ifndef TCONNECTIONLISTENER_H
#define TCONNECTIONLISTENER_H

#include "gloox/connectionlistener.h"
class ComModule;
using namespace gloox;
class TConnectListener:public ConnectionListener
{
public:
    TConnectListener();
    TConnectListener(ComModule *comModule);
    virtual void onConnect();
    virtual bool onTLSConnect(const CertInfo &info);
    virtual void onDisconnect(ConnectionError e);
private:
    ComModule *comModule;
};

#endif // TCONNECTIONLISTENER_H
