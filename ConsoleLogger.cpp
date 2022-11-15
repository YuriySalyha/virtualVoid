#pragma warning(disable : 4996)
#include "ConsoleLogger.h"
#include "DateTime.h"
#include "List.h"

void ConsoleLogger::Log(const char* value)
{
    DateTime data = DateTime::now(true);
    char* stringDate = new char[128];
    strcpy(stringDate, "[");
    stringDate = strcat(stringDate, data.toString(true));
    stringDate = strcat(stringDate, "] - ");
    value = strcat(stringDate, value);
    logs.add(value);
    
}

char* ConsoleLogger::ToString()
{
    //StatickLogger::logger.Log("ToString");
    int lenght = logs.len();
    char* output = new char[256];
    if (lenght > 0) {
        strcpy(output, logs[0]);
    }
    else
    {
        strcpy(output, "");
        return output;
    }
    output = strcat(output, "\n");
    for (int i = 0; i < lenght; i++)
    {
        output = strcat(output, logs[i]);
        output = strcat(output, "\n");
    }
    return output;
}

const char* ConsoleLogger::GetStackTrace()
{
    const char* output;
    int lenght = logs.len();
    for (int i = 0; i < lenght; i++)
    {

    }
}