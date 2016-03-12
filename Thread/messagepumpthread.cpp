#include "messagepumpthread.h"
#include "qdebug.h"
MessagePumpThread::MessagePumpThread(Client *client)
{
    this->client = client;
    runflag = true;
}

void MessagePumpThread::run()
{
    ConnectionError ce = ConnNoError;
    while ((ce == ConnNoError) && runflag) {
        ce = client->recv(1000);
    }
    if (runflag){
        qDebug()<< "Connection error:" << ce;
    }else
    {
        qDebug()<< "Connection finished normally!" << endl;
    }
}
void MessagePumpThread::stop()
{
    runflag = false;
}
