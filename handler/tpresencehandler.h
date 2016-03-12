#ifndef TPRESENCEHANDLER_H
#define TPRESENCEHANDLER_H

#include "gloox/presencehandler.h"
using namespace gloox;
class TPresenceHandler :public PresenceHandler
{
public:
    TPresenceHandler();
    void handlePresence(const Presence &presence);
};

#endif // TPRESENCEHANDLER_H
