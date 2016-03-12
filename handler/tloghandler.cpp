#include "tloghandler.h"
#include <qdebug.h>
TLogHandler::TLogHandler()
{

}

void TLogHandler::handleLog(LogLevel level, LogArea area, const std::string &message)
{
   qDebug()<< "level:" << level << " LogArea:" << area << \
              " message:" <<QString().fromStdString(message) << "########################";
}

