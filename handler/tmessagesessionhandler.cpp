#include "tmessagesessionhandler.h"
#include <QDebug>
#include <handler/tmessagehandler.h>
#include <iterator>
TMessageSessionHandler::TMessageSessionHandler()
{

}

void TMessageSessionHandler::handleMessageSession(MessageSession *session)
{
   QString _jid = QString::fromStdString(session->target().bare());
   m_sessionList.insert(_jid,session);
   TMessageHandler *_messageHandler = new TMessageHandler;
   session->registerMessageHandler(_messageHandler);
   m_messageHandlerList.insert(_jid,_messageHandler);

   MessageEventFilter *_messageEventFilter = new MessageEventFilter(session);
   TMessageEventHandler *_messageEventHandler = new TMessageEventHandler;
   _messageEventFilter->registerMessageEventHandler(_messageEventHandler);
   m_messageEventFilterList.insert(_jid,_messageEventFilter);
   m_messageEventHandlerList.insert(_jid,_messageEventHandler);

   ChatStateFilter* _chatStateFilter = new ChatStateFilter(session);
   TChatStateHandler* _chatStateHandler = new TChatStateHandler;
   _chatStateFilter->registerChatStateHandler(_chatStateHandler);
   m_chatStateFilterList.insert(_jid,_chatStateFilter);
   m_chatStateHandlerList.insert(_jid,_chatStateHandler);
}

MessageSession* TMessageSessionHandler::peekSessionList(QString jid)
{
   QHash<QString,MessageSession*>::const_iterator _i = m_sessionList.find(jid);
   if(_i == m_sessionList.end())
     return NULL;
   return _i.value();
}

MessageEventFilter* TMessageSessionHandler::peekMessageEventFilterList(QString jid){
   QHash<QString,MessageEventFilter*>::const_iterator _i = m_messageEventFilterList.find(jid);
   if(_i == m_messageEventFilterList.end())
       return NULL;
   return _i.value();
}

ChatStateFilter* TMessageSessionHandler::peekChatStateFilterList(QString jid)
{
    QHash<QString,ChatStateFilter*>::const_iterator _i = m_chatStateFilterList.find(jid);
    if(_i == m_chatStateFilterList.end())
        return NULL;
    return _i.value();
}

void TMessageSessionHandler::setChatState(QString jid,ChatStateType chatStateType)
{

    ChatStateFilter* _chatStateFilter = peekChatStateFilterList(jid);
    if(_chatStateFilter != NULL){
        _chatStateFilter->setChatState(chatStateType);
    }else{
        qDebug()<<"chatStateFilter is not found!";
    }
}

void TMessageSessionHandler::raiseEvent(QString jid,MessageEventType messageEventType)
{
    MessageEventFilter* _messageEventFilter = peekMessageEventFilterList(jid);
    if(_messageEventFilter != NULL){
        _messageEventFilter->raiseMessageEvent(messageEventType);
    }else{
        qDebug()<<"messageEventFilter is not found!";
    }
}
