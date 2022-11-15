#ifndef ILogger_h
#define ILogger_h
#include "List.h"

class ILogger
{
public:
    List<const char*> logs;
    List<char*> stackTrace;
    virtual void Log(const char* value) = 0;
    virtual const char* GetStackTrace() = 0;
    virtual char* ToString() = 0;
};

#endif