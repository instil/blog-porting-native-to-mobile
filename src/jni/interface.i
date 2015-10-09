%module NativeLibrary

%pragma(java) jniclasscode=%{
  static {
    try {
        System.loadLibrary("NativeLibrary");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("Native jni code library (libNativeLibrary.so) failed to load. \n" + e);
      System.exit(1);
    }
  }
%}

%{
#include "NativeLibrary.h"
%}

%include "NativeLibrary.h";
