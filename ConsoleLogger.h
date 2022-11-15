#ifndef ConsoleLogger_h
#define ConsoleLogger_h
#include "ILogger.h"

class ConsoleLogger : public ILogger
{
public:
    List<const char*>logs;
    void Log(const char* value);
    char* ToString();
    const char* GetStackTrace();
};

class StatickLogger
{
public:
    static ConsoleLogger logger;
};


#endif