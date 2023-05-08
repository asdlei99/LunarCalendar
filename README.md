## LunarCalendar

Author: KangLin (kl222@126.com)

------------------------------------------------

[:cn: 中文](README_zh_CN.md)

- Project position: https://github.com/KangLin/LunarCalendar
- [Project home](https://kanglin.github.io/LunarCalendar/)

------------------------------------------------

- master
[![build](https://github.com/KangLin/LunarCalendar/actions/workflows/build.yml/badge.svg?branch=master)](https://github.com/KangLin/LunarCalendar/actions/workflows/build.yml)
[![Windows Build status](https://ci.appveyor.com/api/projects/status/p5vhmmbuql9fyfpl/branch/master?svg=true)](https://ci.appveyor.com/project/KangLin/lunarcalendar/branch/master)

- develop
[![build](https://github.com/KangLin/LunarCalendar/actions/workflows/build.yml/badge.svg?branch=develop)](https://github.com/KangLin/LunarCalendar/actions/workflows/build.yml)
[![Windows Build status](https://ci.appveyor.com/api/projects/status/p5vhmmbuql9fyfpl/branch/develop?svg=true)](https://ci.appveyor.com/project/KangLin/lunarcalendar/branch/develop)

[![GitHub stars](https://img.shields.io/github/stars/KangLin/LunarCalendar)](https://github.com/KangLin/LunarCalendar/stars)
[![Gitee stars](https://gitee.com/kl222/LunarCalendar/badge/star.svg?theme=dark)](https://gitee.com/kl222/LunarCalendar/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/KangLin/LunarCalendar)](https://github.com/KangLin/LunarCalendar/forks)
[![GitHub issues](https://img.shields.io/github/issues/KangLin/LunarCalendar)](https://github.com/KangLin/LunarCalendar/issues)
[![Current release](https://img.shields.io/github/release/KangLin/LunarCalendar)](https://github.com/KangLin/LunarCalendar/releases)
[![All releases downloads](https://img.shields.io/github/downloads/KangLin/LunarCalendar/total)](https://github.com/KangLin/LunarCalendar/releases)
[![Download LunarCalendar](https://img.shields.io/sourceforge/dt/lunarcalendar.svg)](https://sourceforge.net/projects/lunarcalendar/files/latest/download)

------------------------------------------------

### Table of Contents:
- [Features](#Features)
- [Download setup package](#Download-setup-package)
- [Donation](#Donation)
- [Screenshots](#Screenshots)
- [Compile](#Compile)
- [Other application use the library](#Other-application-use-the-library)
- [Contribution](#Contribution)
- [License Agreement](#License-Agreement)
    - [The third-party libraries](#The-third-party-libraries)

------------------------------------------------

### Features

The lunar calendar written by Qt. It provides:

- A lunar calendar library of Qt GUI, support QSS.
   + Solar calendar
   + Lunar calendar
   + Solar and Lunar holiday(include chinese holidays)
   + Solar and Lunar Day (eg birthday, wedding anniversary, etc.)
   + Month view
   + Week view
- Example
  + A simple calendar app. Used to illustrate how to use this lunar calendar library.
  + A complete application of this library [Calendar](https://github.com/KangLin/Calendar)
- Cross-platform, support multiple operating systems
   + [x] Windows
   + [x] Linux、Unix
   + [x] Android
   + [ ] Mac os
   + [ ] IOS

Mac os and IOS, I don't have the corresponding equipment,
please compile and test the students with the corresponding equipment.

### Donation

[![donation](https://gitee.com/kl222/RabbitCommon/raw/master/Src/Resource/image/Contribute.png "donation")](https://gitee.com/kl222/RabbitCommon/raw/master/Src/Resource/image/Contribute.png "donation")

### Screenshots
- Windows

![Screenshots](Docs/image/ScreenShot.PNG "Screenshots")
![Screenshots](Docs/image/ScreenShotQss.PNG "Screenshots")

- Android

![Android Screenshots](Docs/image/ScreenShotAndroid.PNG "Android Screenshots")

### [Download setup package](https://github.com/KangLin/LunarCalendar/releases/latest)

[LunarCalendar0.2.4_ubuntu.zip](https://github.com/KangLin/LunarCalendar/releases/download/develop/LunarCalendar0.2.4_ubuntu.zip)

[LunarCalendar_v0.2.4_macos_qt5.12.12_Debug.zip](https://github.com/KangLin/LunarCalendar/releases/download/develop/LunarCalendar_v0.2.4_macos_qt5.12.12_Debug.zip)
[LunarCalendar_v0.2.4_macos_qt5.12.12_Release.zip](https://github.com/KangLin/LunarCalendar/releases/download/develop/LunarCalendar_v0.2.4_macos_qt5.12.12_Release.zip)
[LunarCalendar_v0.2.4_macos_qt5.15.2_Debug.zip](https://github.com/KangLin/LunarCalendar/releases/download/develop/LunarCalendar_v0.2.4_macos_qt5.15.2_Debug.zip)
[LunarCalendar_v0.2.4_macos_qt5.15.2_Release.zip](https://github.com/KangLin/LunarCalendar/releases/download/develop/LunarCalendar_v0.2.4_macos_qt5.15.2_Release.zip)

### Compile

- Depend
  + [Qt (LGPL v2.1)](http://qt.io/)
  + [RabbitCommon](https://github.com/KangLin/RabbitCommon)

  ```
  git clone https://github.com/KangLin/RabbitCommon.git
  ```

- Create and enter the build directory

        git clone --recursive https://github.com/KangLin/LunarCalendar.git
        cd LunarCalendar
        mkdir build

- Use cmake
  - linux

        cd build
        cmake .. -DCMAKE_INSTALL_PREFIX=`pwd`/install \
             -DCMAKE_BUILD_TYPE=Release \
             -DQt5_DIR=${QT_ROOT}/lib/cmake/Qt5 \
             -DRabbitCommon_DIR=
        cmake --build . --config Release --target install
    
  - windows

        cd build
        cmake .. -DCMAKE_INSTALL_PREFIX=`pwd`/install ^
               -DCMAKE_BUILD_TYPE=Release ^
               -DQt5_DIR=${QT_ROOT}/lib/cmake/Qt5 ^
               -DRabbitCommon_DIR=
        cmake --build . --config Release --target install

  - Android
    - The host is linux
    
          cd build
          cmake .. -DCMAKE_BUILD_TYPE=Release \
                 -DCMAKE_INSTALL_PREFIX=`pwd`/android-build \
                 -DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK}/build/cmake/android.toolchain.cmake \
                 -DANDROID_ABI="armeabi-v7a with NEON" \
                 -DANDROID_PLATFORM=android-18 \
                 -DQt5_DIR= \
                 -DRabbitCommon_DIR= 
          cmake --build . --config Release --target install
          cmake --build . --target APK   
    
    - The host is windows
    
          cd build
          cmake .. -G"Unix Makefiles" ^
               -DCMAKE_BUILD_TYPE=Release ^
               -DCMAKE_INSTALL_PREFIX=`pwd`/android-build ^
               -DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK}/build/cmake/android.toolchain.cmake ^
               -DCMAKE_MAKE_PROGRAM=${ANDROID_NDK}/prebuilt/windows-x86_64/bin/make.exe ^
               -DANDROID_PLATFORM=android-18 ^
               -DANDROID_ABI=arm64-v8a ^
               -DANDROID_ARM_NEON=ON ^
               -DQt5_DIR= ^
               -DRabbitCommon_DIR= 
          cmake --build . --config Release --target install
          cmake --build . --target APK     

    - Parameter Description: https://developer.android.google.cn/ndk/guides/cmake
      + ANDROID_ABI: The following values can be taken:
         Goal ABI. If the target ABI is not specified, CMake uses armeabi-v7a by default.
         Valid ABI are:
        - armeabi：CPU with software floating point arithmetic based on ARMv5TE
        - armeabi-v7a：ARMv7-based device with hardware FPU instructions (VFP v3 D16)
        - armeabi-v7a with NEON：Same as armeabi-v7a, but with NEON floating point instructions enabled. This is equivalent to setting -DANDROID_ABI=armeabi-v7a and -DANDROID_ARM_NEON=ON.
        - arm64-v8a：ARMv8 AArch64 Instruction Set
        - x86：IA-32 Instruction Set
        - x86_64 - x86-64 Instruction Set
      + ANDROID_NDK <path> The path of installed ndk in host
      + ANDROID_PLATFORM: For a full list of platform names and corresponding Android system images, see the [Android NDK Native API] (https://developer.android.google.com/ndk/guides/stable_apis.html)
      + ANDROID_ARM_MODE
      + ANDROID_ARM_NEON
      + ANDROID_STL: Specifies the STL that CMake should use. 
        - c++_shared: The shared library variant of libc++.
        - c++_static: The static library variant of libc++.
        - none: No C++ standard library support.
        - system: The system STL
    
    - Install apk to devices
    
           adb install android-build-debug.apk 

- Note
    + windows
       If you build app. Qt does not provide openssl dynamic library for copyright reasons, so you must copy the dynamic library of openssl to the installation directory.
        - If it is 32, you can find the dynamic library of openssl (libeay32.dll, ssleay32.dll) in the Qt installer Tools\QtCreator\bin directory.
        - If it is 64-bit, you will need to download the binary installation package for openssl yourself.

    + linux

     ```
     sudo apt-get install libssl1.1
     ```

### Develop 
- Directory

```
  |-App                                        application source code
  |-Src                                        calendar library source code
     |- LunarCalendar.h                        calendar interface header file
         |- Resource
               |- database
                     |- chinese_holidays.sql   chinese holidays sql
```

### Other application use the library

- Direct use the library source code.
    + cmake
        - Submodule
            + add submodule:

                  git submodule add https://github.com/KangLin/LunarCalendar.git 3th_lib/LunarCalendar
                  git submodule update --init --recursive


            + Add follow code in CMakeLists.txt

                  add_subdirectory(3th_lib/LunarCalendar/Src)

        - No submodule
            + Download LunarCalendar source code from https://github.com/KangLin/LunarCalendar

                  git clone --recursive https://github.com/KangLin/LunarCalendar.git


            + Add follow code in CMakeLists.txt

                  set(LunarCalendar_DIR $ENV{LunarCalendar_DIR} CACHE PATH "Set LunarCalendar source code root directory.")
                  if(EXISTS ${LunarCalendar_DIR}/Src)
                      add_subdirectory(${LunarCalendar_DIR}/Src ${CMAKE_BINARY_DIR}/LunarCalendar)
                  else()
                      message("1. Please download LunarCalendar source code from https://github.com/KangLin/LunarCalendar")
                      message("   ag:")
                      message("       git clone https://github.com/KangLin/LunarCalendar.git")
                      message("2. Then set cmake value or environment variable LunarCalendar_DIR to download root directory.")
                      message("   ag:")
                      message(FATAL_ERROR "       cmake -DLunarCalendar_DIR= ")
                  endif()

            + Add libraries and include in CMakeLists.txt

                  SET(APP_LIBS ${PROJECT_NAME} ${QT_LIBRARIES})
                  if(TARGET LunarCalendar)
                      target_compile_definitions(${PROJECT_NAME}
                          PRIVATE -DLunarCalendar)
                      target_include_directories(${PROJECT_NAME}
                          PRIVATE "${LunarCalendar_DIR}/Src"
                          "${LunarCalendar_DIR}/Src/export")
                      set(APP_LIBS ${APP_LIBS} LunarCalendar)
                  endif()
                  target_link_libraries(${PROJECT_NAME} ${APP_LIBS})

- Use in library mode

    + cmake
        - Cmake parameter LunarCalendar_DIR specifies the installation root directory

                find_package(LunarCalendar)

        - Add libraries and include in CMakeLists.txt

                SET(APP_LIBS ${PROJECT_NAME} ${QT_LIBRARIES})
                if(LunarCalendar_FOUND)
                    target_compile_definitions(${PROJECT_NAME}
                                PRIVATE -DLunarCalendar)
                    target_include_directories(${PROJECT_NAME}
                                PRIVATE "${LunarCalendar_INCLUDE_DIRS}/Src"
                                        "${LunarCalendar_INCLUDE_DIRS}/Src/export")
                    set(APP_LIBS ${APP_LIBS} ${LunarCalendar_LIBRARIES})
                endif()
                target_link_libraries(${PROJECT_NAME} ${APP_LIBS})

- Load translator
    + Use library function

            CLunarCalendar::InitResource();

    + Customize

            QString szPre;
            #if defined(Q_OS_ANDROID) || _DEBUG
                szPre = ":/Translations";
            #else
                szPre = qApp->applicationDirPath() + QDir::separator() + ".." + QDir::separator() + "translations";
            #endif
            m_Translator.load(szPre + "/LunarCalendar_" + QLocale::system().name() + ".qm");
            qApp->installTranslator(&m_Translator);


### Contribution

- [Question](https://github.com/KangLin/LunarCalendar/issues)
- [Contributors](https://github.com/KangLin/LunarCalendar/graphs/contributors)

### [License Agreement](License.md "License.md")

Please follow the license agreement for the third-party libraries below and the license and thank the authors of the third-party libraries.

#### The third-party libraries

- [sxtwl_cpp](https://github.com/yuangu/sxtwl_cpp)

#### Other projects using this project

- [Calendar](https://github.com/KangLin/Calendar)
