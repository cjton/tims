#ifndef TROSTERLISTENER_H
#define TROSTERLISTENER_H

#include "gloox/rosterlistener.h"
#include <QList>
using namespace gloox;
class TRosterListener :public RosterListener
{
public:
    TRosterListener();
    virtual 	~TRosterListener ();
    virtual void 	handleItemAdded (const JID &jid);
    virtual void 	handleItemSubscribed (const JID &jid);
    virtual void 	handleItemRemoved (const JID &jid);
    virtual void 	handleItemUpdated (const JID &jid);
    virtual void 	handleItemUnsubscribed (const JID &jid);
    virtual void 	handleRoster (const Roster &roster);
    virtual void 	handleRosterPresence (const RosterItem &item, const std::string &resource, Presence::PresenceType presence, const std::string &msg);
    virtual void 	handleSelfPresence (const RosterItem &item, const std::string &resource, Presence::PresenceType presence, const std::string &msg);
    virtual bool 	handleSubscriptionRequest (const JID &jid, const std::string &msg);
    virtual bool 	handleUnsubscriptionRequest (const JID &jid, const std::string &msg);
    virtual void 	handleNonrosterPresence (const Presence &presence);
    virtual void 	handleRosterError (const IQ &iq);

private:
    QList<QString>* beginRosterList(const Roster * roster);
    void endRosterList(QList<QString>* rosterList);
};

#endif // TROSTERLISTENER_H
