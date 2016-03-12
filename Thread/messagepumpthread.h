#ifndef MESSAGEPUMPTHREAD_H
#define MESSAGEPUMPTHREAD_H

#include <qthread.h>
#include <gloox/client.h>
#include <qdebug.h>
using namespace gloox;
class MessagePumpThread : public QThread
{
public:
    MessagePumpThread(Client * client);
    virtual void run();
    void stop();
    virtual ~MessagePumpThread()
    {
        qDebug()<<"MessagepumpThread is free!";
    }

private:
    Client *client;
    bool runflag;
};

#endif // MESSAGEPUMPTHREAD_H
