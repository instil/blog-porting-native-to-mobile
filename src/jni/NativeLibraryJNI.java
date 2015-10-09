/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package co.instil.nativelibrary.android;

public class NativeLibraryJNI {

  static {
    try {
        System.loadLibrary("NativeLibrary");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("Native jni code library (libNativeLibrary.so) failed to load. \n" + e);
      System.exit(1);
    }
  }

  public final static native void NativeObject_a_set(long jarg1, NativeObject jarg1_, int jarg2);
  public final static native int NativeObject_a_get(long jarg1, NativeObject jarg1_);
  public final static native void NativeObject_message_set(long jarg1, NativeObject jarg1_, String jarg2);
  public final static native String NativeObject_message_get(long jarg1, NativeObject jarg1_);
  public final static native long new_NativeObject();
  public final static native void delete_NativeObject(long jarg1);
  public final static native void Native_HelloWorld();
  public final static native int Native_AddFunction(int jarg1, int jarg2);
  public final static native void Native_PrintStructure(long jarg1, NativeObject jarg1_);
}