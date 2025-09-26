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
typedef void (*LOG_decl)(const char *tag, const char *fmt);


#if __GNUC__ || __clang__

#define PRINTF_ATTRIBUTE

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

#ifdef __cplusplus
}
#endif // __cplusplus


#undef PRINTF_ATTRIBUTE


#define LOGE(fmt) \
    b2LOGE_expanded(TAG, fmt)

#define LOGW(fmt) \
    b2LOGW_expanded(TAG, fmt)

#define LOGI(fmt) \
    b2LOGI_expanded(TAG, fmt)

#define LOGD(fmt) \
    b2LOGD_expanded(TAG, fmt)

#define LOGT(fmt) \
    b2LOGT_expanded(TAG, fmt)
















