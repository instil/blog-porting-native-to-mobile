#include "NativeLibrary.h"
#include "Logging.h"

#include <cstdio>

// ensure C linkage.
#ifdef __cplusplus
extern "C" {
#endif

void HelloWorld()
{
    info("Hello World");
}

int AddFunction(int a, int b)
{
    int result = a + b;
    debug("Adding %d + %d = %d", a, b, result);
    return result;
}

void PrintStructure(const struct Object * const object)
{
    info("Object->a = %d", object->a);
    info("Object->message = [%s]", object->message);
}

#ifdef __cplusplus
};
#endif
