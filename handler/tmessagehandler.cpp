#include "tmessagehandler.h"
#include <QDebug>
#include <gloox/message.h>
#include <gloox/messagesession.h>
TMessageHandler::TMessageHandler()
{

}

void TMessageHandler::handleMessage(const Message &msg, MessageSession *session)
{
    if(msg.body()!=""){
        qDebug() <<  "Message is " << QString::fromStdString(msg.body());
    }
}
