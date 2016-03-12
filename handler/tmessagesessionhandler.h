#ifndef TMESSAGESESSIONHANDLER_H
#define TMESSAGESESSIONHANDLER_H

#include "gloox/messagesessionhandler.h"
#include "QHash"
#include <handler/tmessagehandler.h>
#include "handler/tmessageeventhandler.h"
#include <handler/tchatstatehandler.h>
#include <gloox/messageeventfilter.h>
#include <gloox/chatstatefilter.h>
using namespace gloox;
class TMessageSessionHandler:public MessageSessionHandler
{
public:
    TMessageSessionHandler();
    virtual void handleMessageSession(MessageSession *session);
    MessageSession* peekSessionList(QString jid);
    MessageEventFilter* peekMessageEventFilterList(QString jid);
    ChatStateFilter* peekChatStateFilterList(QString jid);
    void setChatState(QString jid,ChatStateType chatStateType);
    void raiseEvent(QString jid,MessageEventType messageEventType);
private:
    QHash<QString,MessageSession*> m_sessionList;
    QHash<QString,MessageEventFilter*> m_messageEventFilterList;
    QHash<QString,ChatStateFilter*> m_chatStateFilterList;
    QHash<QString,TMessageEventHandler*> m_messageEventHandlerList;
    QHash<QString,TChatStateHandler*> m_chatStateHandlerList;
    QHash<QString,TMessageHandler*> m_messageHandlerList;

};

#endif // TMESSAGESESSIONHANDLER_H
