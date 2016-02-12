// -*-c++-*-
#ifndef __LOGGING_H__
#define __LOGGING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
    
// using __FILE__ returns the full file path which is too long in most cases.
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
    
#define printflike(s, e) __attribute__((format (printf, s, e)))

    typedef enum {
        INFO,
        DEBUG,
        ERROR
    } LOG_LEVEL;

    typedef void (*logging_callback)(LOG_LEVEL, const char *);
    
    extern void log(LOG_LEVEL, const char *, unsigned int, const char *, ...) printflike(4, 5);

    extern void set_logging_callback(logging_callback);

    extern void printf_backend(LOG_LEVEL, const char *);

#define info(...) log(INFO, __FILENAME__, __LINE__, __VA_ARGS__)
#define debug(...) log(DEBUG, __FILENAME__, __LINE__, __VA_ARGS__)
#define error(...) log(ERROR, __FILENAME__, __LINE__, __VA_ARGS__)

#ifdef __cplusplus
};
#endif

#endif //__LOGGING_H__
