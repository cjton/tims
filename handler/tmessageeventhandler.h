#ifndef TMESSAGEEVENTHANDLER_H
#define TMESSAGEEVENTHANDLER_H
#include <gloox/messageeventhandler.h>
using namespace gloox;
class TMessageEventHandler : public MessageEventHandler
{
public:
    TMessageEventHandler();
    virtual void handleMessageEvent(const JID &from, MessageEventType event);

};

#endif // TMESSAGEEVENTHANDLER_H
