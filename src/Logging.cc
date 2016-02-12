#include "Logging.h"

#include <cstdio>
#include <cstdlib>
#include <cstdarg>

static logging_callback __logging_callback;

void set_logging_callback(logging_callback cb)
{
    __logging_callback = cb;
}

void printf_backend(LOG_LEVEL level, const char * message)
{
    switch (level) {
    case INFO:
        printf("%s: %s\n", "INFO", message);
        break;

    case DEBUG:
        printf("%s: %s\n", "DEBUG", message);
        break;

    case ERROR:
        printf("%s: %s\n", "ERROR", message);
        break;
    }
}

void log(LOG_LEVEL level, const char * file, unsigned int line, const char * fmt, ...)
{   
/*
  Don't do this in production use streams or something to avoid overflow.
  This illustrates the idea.
*/   
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    char buf[512];
    memset(buf, 0, sizeof(buf));
    snprintf(buf, sizeof(buf), "%s:%i -> %s", file, line, buffer);
    
    // notify the delegate/callback
    if (__logging_callback != NULL) {
        __logging_callback(level, buf);
    } else {
        printf_backend(level, buf);
    }
}

