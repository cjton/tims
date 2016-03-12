#ifndef TLOGHANDLER_H
#define TLOGHANDLER_H
#include "gloox/loghandler.h"

using namespace gloox;
class TLogHandler : public LogHandler
{
public:
    TLogHandler();
    void handleLog(LogLevel level, LogArea area, const std::string &message);
};

#endif // TLOGHANDLER_H
