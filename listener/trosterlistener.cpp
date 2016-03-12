#include "trosterlistener.h"
#include <qdebug.h>

TRosterListener::TRosterListener()
{

}

void TRosterListener::handleItemAdded(const JID &jid)
{
    qDebug() << "RosterListener handleItemAdded: " << QString::fromStdString(jid.bare().c_str());
}

void TRosterListener::handleItemRemoved(const JID &jid)
{
    qDebug() << "RosterListener handleItemRemoved: " << QString::fromStdString(jid.bare().c_str());
}

void TRosterListener::handleItemSubscribed(const JID &jid)
{
    qDebug() << "RosterListener handleItemSubscribed: " << QString::fromStdString(jid.bare().c_str());
}

void TRosterListener::handleItemUnsubscribed(const JID &jid)
{
    qDebug() << "RosterListener handleItemUnsubscribed: " << QString::fromStdString(jid.bare().c_str());

}

void TRosterListener::handleItemUpdated(const JID &jid)
{
    qDebug() << "RosterListener handleItemUpdated: " << QString::fromStdString(jid.bare().c_str());

}

void TRosterListener::handleNonrosterPresence(const Presence &presence)
{

}

void TRosterListener::handleRoster(const Roster &roster)
{
    qDebug() << "begin handleRoster";
    QList<QString> *list =  beginRosterList(&roster);

    if(list != NULL){
        for(int i = 0; i < list->size(); i++){
            qDebug() << list->at(i);
        }
    }
    qDebug() << "end handleRoster";

    endRosterList(list);
}

void TRosterListener::handleRosterError(const IQ &iq)
{

}

void TRosterListener::handleRosterPresence(const RosterItem &item, const std::string &resource, Presence::PresenceType presence, const std::string &msg)
{

}


void TRosterListener::handleSelfPresence(const RosterItem &item, const std::string &resource, Presence::PresenceType presence, const std::string &msg)
{

}

bool TRosterListener::handleSubscriptionRequest(const JID &jid, const std::string &msg)
{

}

bool TRosterListener::handleUnsubscriptionRequest(const JID &jid, const std::string &msg)
{

}


QList<QString>* TRosterListener::beginRosterList(const Roster *roster){
    if(roster != NULL){
        Roster::const_iterator _it = roster->begin();
        QList<QString> *_rosterList = new QList<QString>();
        for(;_it != roster->end(); _it++){
            QString _strJid = QString::fromStdString((*_it).second->jidJID().bare());
            QString _strSubscribe = QString::number((*_it).second->subscription());
            _rosterList->insert(_rosterList->size(),_strJid + " " + _strSubscribe);
        }
        return _rosterList;
    }
    return NULL;
}

void TRosterListener::endRosterList(QList<QString> *rosterList)
{
    if (rosterList != NULL){
        delete rosterList;
    }

}

TRosterListener::~TRosterListener()
{

}
