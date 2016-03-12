#include "tconnectionlistener.h"
#include "QDebug"
#include "commodule.h"
#include "gloox/rostermanager.h"
TConnectListener::TConnectListener(ComModule *comModule)
{
    this->comModule = comModule;
}


void TConnectListener::onConnect()
{
   qDebug() << "Connection is established now!";
}

void TConnectListener::onDisconnect(ConnectionError e)
{
    qDebug() << "Connection is break now!";
}

bool TConnectListener::onTLSConnect(const CertInfo &info)
{

}
