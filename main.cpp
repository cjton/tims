#include <QCoreApplication>
#include "commodule.h"
#include <qdebug.h>
#include <QThread>
#include <windows.h>
int main(int argc, char *argv[])
{
    qDebug() << "TIMS is starting!";
    QCoreApplication a(argc, argv);
    ComModule com;
    if(com.loginServer("tj@192.168.3.222","111111")){
        com.startMessagePump();
    }
    QString jid ="zn@raspberrypi";
    QString msg;
    QTextStream in(stdin);
    while(true){
        qDebug()<<"Please input a Message:";
        in >>msg;
        com.sendMsg(jid,msg);
        Sleep(1000);
        com.sendChatState(jid,ChatStateComposing);
        Sleep(1000);
        com.sendChatState(jid,ChatStateInactive);
        com.sendEvent(jid,MessageEventComposing);
    }
    a.exec();
}

