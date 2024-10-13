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

#include "box2d_common/logging.h"

#include "box2d_common/platform.h"

#if IS_PLATFORM_ANDROID
#include <android/log.h>
#endif // IS_PLATFORM_ANDROID

#include <cstdio> // for fprintf, stderr
#include <cstdarg> // for va_list, va_start, va_arg, va_end


#define TAG "logging"


void b2LogFatalV(const char *tag, const char *fmt, va_list args);
void b2LogErrorV(const char *tag, const char *fmt, va_list args);
void b2LogWarnV(const char *tag, const char *fmt, va_list args);
void b2LogInfoV(const char *tag, const char *fmt, va_list args);
void b2LogDebugV(const char *tag, const char *fmt, va_list args);
void b2LogTraceV(const char *tag, const char *fmt, va_list args);


void b2LogFatal(const char *tag, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    b2LogFatalV(tag, fmt, args);
    va_end(args);
}

void b2LogError(const char *tag, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    b2LogErrorV(tag, fmt, args);
    va_end(args);
}

void b2LogWarn(const char *tag, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    b2LogWarnV(tag, fmt, args);
    va_end(args);
}

void b2LogInfo(const char *tag, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    b2LogInfoV(tag, fmt, args);
    va_end(args);
}

void b2LogDebug(const char *tag, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    b2LogDebugV(tag, fmt, args);
    va_end(args);
}

void b2LogTrace(const char *tag, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    b2LogTraceV(tag, fmt, args);
    va_end(args);
}

void b2LogNull(const char *tag, const char *fmt, ...) {
    (void)tag;
    (void)fmt;
}


//
// define the various LogXXXV
//

#if IS_PLATFORM_ANDROID

void b2LogFatalV(const char *tag, const char *fmt, va_list args) {
    __android_log_vprint(ANDROID_LOG_FATAL, tag, fmt, args);
}

void b2LogErrorV(const char *tag, const char *fmt, va_list args) {
    __android_log_vprint(ANDROID_LOG_ERROR, tag, fmt, args);
}

void b2LogWarnV(const char *tag, const char *fmt, va_list args) {
    __android_log_vprint(ANDROID_LOG_WARN, tag, fmt, args);
}

void b2LogInfoV(const char *tag, const char *fmt, va_list args) {
    __android_log_vprint(ANDROID_LOG_INFO, tag, fmt, args);
}

void b2LogDebugV(const char *tag, const char *fmt, va_list args) {
    __android_log_vprint(ANDROID_LOG_DEBUG, tag, fmt, args);
}

void b2LogTraceV(const char *tag, const char *fmt, va_list args) {
    __android_log_vprint(ANDROID_LOG_VERBOSE, tag, fmt, args);
}

#else

void b2LogFatalV(const char *tag, const char *fmt, va_list args) {
    (void)tag;
    std::vfprintf(stderr, fmt, args);
    std::fflush(stderr);
}

void b2LogErrorV(const char *tag, const char *fmt, va_list args) {
    (void)tag;
    std::vfprintf(stderr, fmt, args);
    std::fflush(stderr);
}

void b2LogWarnV(const char *tag, const char *fmt, va_list args) {
    (void)tag;
    std::vfprintf(stderr, fmt, args);
    std::fflush(stderr);
}

void b2LogInfoV(const char *tag, const char *fmt, va_list args) {
    (void)tag;
    std::vfprintf(stderr, fmt, args);
    std::fflush(stderr);
}

void b2LogDebugV(const char *tag, const char *fmt, va_list args) {
    (void)tag;
    std::vfprintf(stderr, fmt, args);
    std::fflush(stderr);
}

void b2LogTraceV(const char *tag, const char *fmt, va_list args) {
    (void)tag;
    std::vfprintf(stderr, fmt, args);
    std::fflush(stderr);
}

#endif // IS_PLATFORM_ANDROID

void b2LogNullV(const char *tag, const char *fmt, va_list args) {
    (void)tag;
    (void)fmt;
    (void)args;
}


//
// default log level is INFO
//
LOG_decl b2LOGF_expanded = b2LogFatal;
LOG_decl b2LOGE_expanded = b2LogError;
LOG_decl b2LOGW_expanded = b2LogWarn;
LOG_decl b2LOGI_expanded = b2LogInfo;
LOG_decl b2LOGD_expanded = b2LogNull;
LOG_decl b2LOGT_expanded = b2LogNull;

LOG_declV b2LOGF_expandedV = b2LogFatalV;
LOG_declV b2LOGE_expandedV = b2LogErrorV;
LOG_declV b2LOGW_expandedV = b2LogWarnV;
LOG_declV b2LOGI_expandedV = b2LogInfoV;
LOG_declV b2LOGD_expandedV = b2LogNullV;
LOG_declV b2LOGT_expandedV = b2LogNullV;
















