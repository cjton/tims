#include "tpresencehandler.h"
#include <QDebug>
TPresenceHandler::TPresenceHandler()
{

}

void TPresenceHandler::handlePresence(const Presence &presence)
{
    qDebug() << "presence:" << presence.subtype()<< QString::fromStdString(presence.from().bare());

}

