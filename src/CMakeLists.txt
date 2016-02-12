if(FOR_ANDROID)
  MESSAGE(STATUS "Will Build JNI Bindings: " ${BUILD_JNI_WRAPPER})
  if(BUILD_JNI_WRAPPER)
    set(JNI_SRCS
      ./jni/interface_wrap.cpp
      )
  endif()

  # this will cause crashes on android - swig generates old style pointer code for DIRECTORS
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing -Wunused-function")
else()
  set(JNI_SRCS)
endif()

MESSAGE(STATUS "Will Build JNI Jar archive: " ${BUILD_JAR})
if(BUILD_JAR)
  FILE(GLOB source "./jni/*.java")
  add_jar(NativeLibrary ${source})
endif()

if(BUILD_JAR STREQUAL OFF)
  add_library (NativeLibrary ${LIBRARY_TYPE}

    # Sources
    NativeLibrary.h
    NativeLibrary.cc
    Logging.h
    Logging.cc
    
    # Jni
    ${JNI_SRCS}  
  )

endif()
