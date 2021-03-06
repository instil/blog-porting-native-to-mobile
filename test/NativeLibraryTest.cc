#include <gtest/gtest.h>
#include "NativeLibrary.h"

TEST(NativeLibrary, HelloWorld) {
    HelloWorld();
}

TEST(NativeLibrary, AddFunction) {
    int result = AddFunction(2, 3);
    ASSERT_EQ(5, result);
}

TEST(NativeLibrary, PrintStructure) {
    struct Object object = {
        .a = 3,
        .message = "Hello World from Instil"
    };
    PrintStructure(&object);
}
