#ifndef TCHATSTATEHANDLER_H
#define TCHATSTATEHANDLER_H
#include <gloox/chatstatehandler.h>
using namespace gloox;
class TChatStateHandler : public ChatStateHandler
{
public:
    TChatStateHandler();
    virtual void handleChatState(const JID &from, ChatStateType state);
};

#endif // TCHATSTATEHANDLER_H
