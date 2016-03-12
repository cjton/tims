#ifndef COMMODULE_H
#define COMMODULE_H

#include <QObject>
#include "gloox/client.h"
#include "Thread/messagepumpthread.h"
#include "listener/tconnectionlistener.h"
#include "listener/trosterlistener.h"
#include "handler/tmessagesessionhandler.h"
#include "handler/tpresencehandler.h"
#include "QList"
using namespace gloox;

class ComModule : public QObject
{
    Q_OBJECT
public:
    explicit ComModule(QObject *parent = 0);
    virtual ~ComModule();

    bool loginServer(std::string jidName, std::string pwd);
    void startMessagePump();
    void sendMsg(QString jid,QString msg);
    void sendEvent(QString jid,MessageEventType messageEventType);
    void sendChatState(QString jid,ChatStateType chatStateType);


public:

    Client *client;
    MessagePumpThread *messagePumpThread;
    TConnectListener connectListener;
    TMessageSessionHandler messageSessionHandler;
    TPresenceHandler presenceHandler;
    TRosterListener rosterListener;

};

#endif // COMMODULE_H
