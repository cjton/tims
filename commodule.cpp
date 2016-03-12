#include "commodule.h"
#include "qdebug.h"
#include "gloox/disco.h"
#include "Thread/messagepumpthread.h"
#include "handler/tloghandler.h"
#include "gloox/chatstate.h"
#include "gloox/messageevent.h"
#include "gloox/rosteritem.h"
#include "gloox/rosterlistener.h"
#include "gloox/rostermanager.h"

ComModule::ComModule(QObject *parent) : QObject(parent),client(0),connectListener(this)
{
}

bool ComModule::loginServer(std::string jidName, std::string pwd)
{
    JID jid(jidName);
    client = new Client(jid,pwd);
    client->registerConnectionListener(&connectListener);
    client->registerMessageSessionHandler(&messageSessionHandler);
    client->registerPresenceHandler(&presenceHandler);
    client->rosterManager()->registerRosterListener(&rosterListener);
    client->disco()->setVersion("Client","bot");
    client->disco()->addFeature(XMLNS_CHAT_STATES);
    client->disco()->addFeature(XMLNS_X_EVENT);
    client->registerStanzaExtension(new ChatState(ChatStateComposing));
    client->registerStanzaExtension(new ChatState(ChatStateInactive));
    client->registerStanzaExtension(new MessageEvent(MessageEventComposing));
    client->setSASLMechanisms(SaslMechPlain);
    //client->logInstance().registerLogHandler( LogLevelDebug, LogAreaAll, new TLogHandler );
    if(!client->connect(false)){
        return false;
    }


    return true;
}
void ComModule::startMessagePump()
{
    messagePumpThread = new MessagePumpThread(client);
    messagePumpThread->start();
}

void ComModule::sendMsg(QString jid, QString msg)
{
    MessageSession *session = messageSessionHandler.peekSessionList(jid);
    if(session != NULL)
    {
        session->send(msg.toStdString());
        return ;
    }else{
        MessageSession *newSession = new MessageSession(client,JID(jid.toStdString()));
        messageSessionHandler.handleMessageSession(newSession);
        this->sendMsg(jid,msg);
    }

}
void ComModule::sendEvent(QString jid,MessageEventType messageEventType){
    messageSessionHandler.raiseEvent(jid,messageEventType);
}

void ComModule::sendChatState(QString jid,ChatStateType chatStateType){
    messageSessionHandler.setChatState(jid,chatStateType);
}



ComModule::~ComModule()
{
    messagePumpThread->stop();
    messagePumpThread->wait();

    delete(messagePumpThread);
    messagePumpThread = NULL;
    delete(client);
    client = NULL;
}
