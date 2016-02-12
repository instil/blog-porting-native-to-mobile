// -*-c++-*-
#ifndef __NATIVE_LIBRARY_H__
#define __NATIVE_LIBRARY_H__

#ifdef __cplusplus
extern "C" {
#endif

    struct Object {
        int a;
        char message[128];
    };

    extern void HelloWorld();

    extern int AddFunction(int, int);

    extern void PrintStructure(const struct Object * const);

#ifdef __cplusplus
};
#endif

#endif // __NATIVE_LIBRARY_H__
