#!/usr/bin/env bash
set -e

rm -rf _xcode
mkdir _xcode
pushd _xcode

cmake -DFOR_IOS=ON -G Xcode ../
# armv7
xcodebuild -project PortingTutorial.xcodeproj -target NativeLibrary -sdk iphoneos ARCHS='armv7' \
           -configuration Release clean build TARGET_BUILD_DIR='./_xcode/build-armv7' BUILT_PRODUCTS_DIR='./_xcode/build-armv7'
# armv7s
xcodebuild -project PortingTutorial.xcodeproj -target NativeLibrary -sdk iphoneos ARCHS='armv7s' \
           -configuration Release clean build TARGET_BUILD_DIR='./_xcode/build-armv7s' BUILT_PRODUCTS_DIR='./_xcode/build-armv7s'
# arm64
xcodebuild -project PortingTutorial.xcodeproj -target NativeLibrary -sdk iphoneos ARCHS='arm64' \
           -configuration Release clean build TARGET_BUILD_DIR='./_xcode/build-arm64' BUILT_PRODUCTS_DIR='./_xcode/build-arm64'
# i386
xcodebuild -project PortingTutorial.xcodeproj -target NativeLibrary -sdk iphonesimulator ARCHS='i386' \
           -configuration Release clean build TARGET_BUILD_DIR='./_xcode/build-i386' BUILT_PRODUCTS_DIR='./_xcode/build-i386'
# x86_64
xcodebuild -project PortingTutorial.xcodeproj -target NativeLibrary -sdk iphonesimulator ARCHS='x86_64' \
           -configuration Release clean build TARGET_BUILD_DIR='./_xcode/build-x86_64' BUILT_PRODUCTS_DIR='./_xcode/build-x86_64'
lipo -create \
     './build-armv7/libNativeLibrary.a' \
     './build-armv7s/libNativeLibrary.a' \
     './build-arm64/libNativeLibrary.a' \
     './build-i386/libNativeLibrary.a' \
     './build-x86_64/libNativeLibrary.a' \
     -output 'libNativeLibrary.a'
popd

# create library archive with headers.
echo "Creating library archive: libnative-library-ios.tar.gz..."

rm -rf libnative-library-ios libnative-library-ios.tar.gz
mkdir libnative-library-ios
mkdir libnative-library-ios/lib
mkdir libnative-library-ios/include

pushd src
for header in `find . -name "*.h"`; do
    cp $header "../libnative-library-ios/include/"
done
popd
cp -v _xcode/libNativeLibrary.a libnative-library-ios/lib

#  archive it
tar zcf libnative-library-ios.tar.gz libnative-library-ios/

echo "Done.."
