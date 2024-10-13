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

//
// keep compilable with C and C++
//

#pragma once

#include "box2d_common/platform.h"

#include <stdarg.h> // for va_list


//
// there is an outside chance these macros are already defined
//
#if defined(LOGLEVEL_FATAL) || defined(LOGLEVEL_ERROR) || defined(LOGLEVEL_WARN) || defined(LOGLEVEL_INFO) || defined(LOGLEVEL_DEBUG) || defined(LOGLEVEL_TRACE)
#error Log level macros already defined (LOGLEVEL_FATAL, LOGLEVEL_ERROR, LOGLEVEL_WARN, LOGLEVEL_INFO, \
    LOGLEVEL_DEBUG, LOGLEVEL_TRACE), most likely from another logging framework. Remove previous logging framework.
#endif // defined(LOGLEVEL_FATAL) || defined(LOGLEVEL_ERROR) || defined(LOGLEVEL_WARN) || defined(LOGLEVEL_INFO) || defined(LOGLEVEL_DEBUG) || defined(LOGLEVEL_TRACE)


//
// arguments for SetLogLevel
//
// greater = more noise
//
#define LOGLEVEL_FATAL -1
#define LOGLEVEL_ERROR 0
#define LOGLEVEL_WARN 1
#define LOGLEVEL_INFO 2
#define LOGLEVEL_DEBUG 3
#define LOGLEVEL_TRACE 4


// var arg
typedef void (*LOG_decl)(const char *tag, const char *fmt, ...);

// va_list
typedef void (*LOG_declV)(const char *tag, const char *fmt, va_list args);


#if __GNUC__ || __clang__

//
// declare that LOGE_expanded et al take printf-style arguments
//
// https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#index-format-function-attribute
//

#define PRINTF_ATTRIBUTE __attribute__ ((format (printf, 2, 3)))

#else

#define PRINTF_ATTRIBUTE

#endif // __GNUC__ || __clang__


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// var arg

extern PRINTF_ATTRIBUTE LOG_decl b2LOGF_expanded;
extern PRINTF_ATTRIBUTE LOG_decl b2LOGE_expanded;
extern PRINTF_ATTRIBUTE LOG_decl b2LOGW_expanded;
extern PRINTF_ATTRIBUTE LOG_decl b2LOGI_expanded;
extern PRINTF_ATTRIBUTE LOG_decl b2LOGD_expanded;
extern PRINTF_ATTRIBUTE LOG_decl b2LOGT_expanded;

// va_list

//
// the va_list functions LOGE_expandedV et al can be called by code that already has a va_list
//

extern LOG_declV b2LOGF_expandedV;
extern LOG_declV b2LOGE_expandedV;
extern LOG_declV b2LOGW_expandedV;
extern LOG_declV b2LOGI_expandedV;
extern LOG_declV b2LOGD_expandedV;
extern LOG_declV b2LOGT_expandedV;

#ifdef __cplusplus
}
#endif // __cplusplus


#undef PRINTF_ATTRIBUTE


#if IS_PLATFORM_ANDROID

//
// LOGI() expands into LOGI_expanded(TAG, "")
//
// the old definition of:
// LOGI_expanded(TAG, fmt "" __VA_OPT__(,) __VA_ARGS__)
//
// meant that LOGI() expanded into LOGI_expanded(TAG, )
//
// and there is no easy way to get rid of the trailing comma.
//
// References such as:
// https://gcc.gnu.org/onlinedocs/cpp/Macro-Arguments.html
//
// explain "You can leave macro arguments empty"
//
// LOGI("%s", "foo") expands into LOGI_expanded(TAG, "%s" "" , "foo") -> LOGI_expanded(TAG, "%s", "foo")
//

#define COMMON_LOGGING_C ""

#else

//
// the "\n" in the below definitions serves 2 purposes:
// 1. allowing LOGI() to be expanded properly (the same purpose as "" above)
// 2. adding the trailing "\n" that is needed on non-Android platforms
//

#define COMMON_LOGGING_C "\n"

#endif // IS_PLATFORM_ANDROID

//
// do not call LOGF from top-level, use ABORT_expanded() directly
//
// #define LOGF(fmt, ...) LOGF_expanded(TAG, fmt COMMON_LOGGING_C __VA_OPT__(,) __VA_ARGS__)

#define LOGE(fmt, ...) \
    b2LOGE_expanded(TAG, fmt COMMON_LOGGING_C __VA_OPT__(,) __VA_ARGS__)

#define LOGW(fmt, ...) \
    b2LOGW_expanded(TAG, fmt COMMON_LOGGING_C __VA_OPT__(,) __VA_ARGS__)

#define LOGI(fmt, ...) \
    b2LOGI_expanded(TAG, fmt COMMON_LOGGING_C __VA_OPT__(,) __VA_ARGS__)

#define LOGD(fmt, ...) \
    b2LOGD_expanded(TAG, fmt COMMON_LOGGING_C __VA_OPT__(,) __VA_ARGS__)

#define LOGT(fmt, ...) \
    b2LOGT_expanded(TAG, fmt COMMON_LOGGING_C __VA_OPT__(,) __VA_ARGS__)
















