#include "tchatstatehandler.h"
#include <QDebug>
TChatStateHandler::TChatStateHandler()
{

}
void TChatStateHandler::handleChatState(const JID &from, ChatStateType state)
{

    qDebug() << "chatestatetype is :" << state;
}
