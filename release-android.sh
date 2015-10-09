#!/usr/bin/env bash
set -e

: ${ANDROID_NDK:?"Need to set the ANDROID_NDK path envrioment variable"}

ARCHS=("armeabi-v7a"
       "armeabi" \
       "arm64-v8a" \
       "x86" \
       "x86_64")

pushd src
echo "Generating swig jni wrapper"
rm -f jni/*.java
rm -f jni/interface_wrap.*
swig -c++ -java -cppext cpp -package co.instil.nativelibrary.android -Wall jni/interface.i
popd

# Build JNI Bindings Jar
rm -rf _android_bindings
mkdir _android_bindings
pushd _android_bindings
cmake -DBUILD_JAR=ON ../
make VERBOSE=1
popd

# Build JNI Native libs
for arch in "${ARCHS[@]}"; do
    rm -rf "_android_$arch"
    mkdir "_android_$arch"
    pushd "_android_$arch"
    
    echo "Building for [$arch]"
    echo

    cmake -DFOR_ANDROID=ON \
          -DBUILD_JNI_WRAPPER=ON \
	  -DCMAKE_TOOLCHAIN_FILE=../android-cmake/android.toolchain.cmake \
	  -DCMAKE_BUILD_TYPE=Release \
          -DANDROID_STL=gnustl_static \
          -DANDROID_NATIVE_API_LEVEL=android-17 \
	  -DANDROID_ABI="$arch" \
	  ../
    make -j2 VERBOSE=1
    
    popd
done

echo "Creating library archive: libnative-library-android.tar.gz..."

rm -rf libnative-library-android libnative-library-android.tar.gz
mkdir libnative-library-android
mkdir -p libnative-library-android/lib

cp -v _android_bindings/src/NativeLibrary.jar libnative-library-android/
for arch in "${ARCHS[@]}"; do
    mkdir libnative-library-android/lib/$arch
    cp -v "_android_$arch/src/libNativeLibrary.so" "libnative-library-android/lib/$arch/"
done

tar zcf libnative-library-android.tar.gz libnative-library-android

echo "Done.."
