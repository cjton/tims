#include "tmessageeventhandler.h"
#include <QDebug>
TMessageEventHandler::TMessageEventHandler()
{

}
void TMessageEventHandler::handleMessageEvent(const JID &from, MessageEventType event)
{

    qDebug()<<"MessageEventType:  "<< event;
}
