#ifndef TMESSAGEHANDLER_H
#define TMESSAGEHANDLER_H

#include "gloox/messagehandler.h"
using namespace gloox;
class TMessageHandler: public MessageHandler
{
public:
    TMessageHandler();
    virtual void handleMessage( const Message& msg, MessageSession* session = 0 );
};

#endif // TMESSAGEHANDLER_H
