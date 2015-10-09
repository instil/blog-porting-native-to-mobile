#include "NativeLibrary.h"

#include <cstdio>
#include <cstring>

// using __FILE__ returns the full file path which is too long in most cases.
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// ensure C linkage.
#ifdef __cplusplus
extern "C" {
#endif

void Native_HelloWorld()
{
    printf("[%s:%d] -> Hello World\n", __FILENAME__, __LINE__);
}

int Native_AddFunction(int a, int b)
{
    int result = a + b;
    printf("[%s:%d] -> Adding %d + %d = %d\n", __FILENAME__, __LINE__, a, b, result);
    return result;
}

void Native_PrintStructure(const struct NativeObject * const object)
{
    printf("[%s:%i] -> NativeObject->a = %d\n", __FILENAME__, __LINE__, object->a);
    printf("[%s:%i] -> NativeObject->message = [%s]\n", __FILENAME__, __LINE__, object->message);
}

#ifdef __cplusplus
};
#endif
