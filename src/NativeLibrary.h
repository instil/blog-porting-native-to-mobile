// -*-c++-*-
#ifndef __NATIVE_LIBRARY_H__
#define __NATIVE_LIBRARY_H__

#ifdef __cplusplus
extern "C" {
#endif

    struct NativeObject {
        int a;
        char message[128];
    };

    extern void Native_HelloWorld();

    extern int Native_AddFunction(int, int);

    extern void Native_PrintStructure(const struct NativeObject * const);

#ifdef __cplusplus
};
#endif

#endif // __NATIVE_LIBRARY_H__
