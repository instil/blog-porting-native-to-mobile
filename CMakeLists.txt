cmake_minimum_required (VERSION 2.6.3)
project (PortingTutorial)

# default library type
set(LIBRARY_TYPE STATIC)

option(FOR_IOS "Enable iOS specific extensions" OFF)
if(FOR_IOS)
  add_definitions(-D__IS_IOS__)
  set(LIBRARY_TYPE STATIC)
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
  set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "8.0")
  set(CMAKE_XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "8.0")
  set(CMAKE_XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "NO")
endif()

option(FOR_ANDROID "Enable Android specific extensions" OFF)
if(FOR_ANDROID)
  add_definitions(-D__IS_ANDROID__)
  set(LIBRARY_TYPE SHARED)
endif()

option(BUILD_JAR "Build jni wrapper jar" OFF)
if(BUILD_JAR)
  find_package(Java REQUIRED)
  include(UseJava)
  set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.6" "-target" "1.6")
endif()

option(BUILD_JNI_WRAPPER "Build JNI Wrapper" OFF)

Set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

option(DEBUG_SYMBOLS "Turn on Debug Symbols" OFF)
if(DEBUG_SYMBOLS)
  Set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

include_directories("${PROJECT_BINARY_DIR}/src")

include_directories(src)
add_subdirectory(src)

option(UNIT_TESTS "Enable unit-tests" OFF)
if(UNIT_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory (test)
endif()
