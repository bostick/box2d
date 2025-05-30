// Copyright (C) 2025 by Brenton Bostick
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial
// portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once


//
// there is an outside chance these macros are already defined
//
#if defined(PLATFORM_ANDROID) || defined(PLATFORM_IOS) || defined(PLATFORM_MACOS) || defined(PLATFORM_WINDOWS) || defined(PLATFORM_LINUX)
#error Platform macros already defined (PLATFORM_ANDROID, PLATFORM_IOS, PLATFORM_MACOS, PLATFORM_WINDOWS, \
    PLATFORM_LINUX).
#endif // defined(PLATFORM_ANDROID) || defined(PLATFORM_IOS) || defined(PLATFORM_MACOS) || defined(PLATFORM_WINDOWS) || defined(PLATFORM_LINUX)


// keep 0 undefined
#define PLATFORM_ANDROID 1
#define PLATFORM_IOS 2
#define PLATFORM_MACOS 3
#define PLATFORM_WINDOWS 4
#define PLATFORM_LINUX 5


#if defined(__ANDROID__)

//
// https://android.googlesource.com/platform/bionic/+/HEAD/docs/defines.md
//

#define IS_PLATFORM_ANDROID 1
#define PLATFORM PLATFORM_ANDROID
#define PLATFORM_STRING "android"

#elif __APPLE__

#include "TargetConditionals.h"

#if TARGET_OS_IOS

#define IS_PLATFORM_IOS 1
#define PLATFORM PLATFORM_IOS
#define PLATFORM_STRING "ios"

#elif TARGET_OS_OSX

#define IS_PLATFORM_MACOS 1
#define PLATFORM PLATFORM_MACOS
#define PLATFORM_STRING "macos"

#else // TARGET_OS_IOS
#error Unknown Apple platform
#endif // TARGET_OS_IOS

#elif defined(_WIN32)

#define IS_PLATFORM_WINDOWS 1
#define PLATFORM PLATFORM_WINDOWS
#define PLATFORM_STRING "windows"

#elif defined(__linux__)

#define IS_PLATFORM_LINUX 1
#define PLATFORM PLATFORM_LINUX
#define PLATFORM_STRING "linux"

#else
#error Unknown platform
#endif // defined(__ANDROID__)
















