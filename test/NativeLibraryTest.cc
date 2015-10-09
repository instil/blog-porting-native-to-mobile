#include <gtest/gtest.h>
#include "NativeLibrary.h"

TEST(NativeLibrary, HelloWorld) {
    Native_HelloWorld();
}

TEST(NativeLibrary, AddFunction) {
    int result = Native_AddFunction(2, 3);
    ASSERT_EQ(5, result);
}

TEST(NativeLibrary, PrintStructure) {
    struct NativeObject object = { .a = 3, .message = "Hello World from Instil" };
    Native_PrintStructure(&object);
}
