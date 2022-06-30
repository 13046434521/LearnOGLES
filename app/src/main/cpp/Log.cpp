//
// Created by Administrator on 2022/4/24.
//

#include "Log.h"
void LOGV(const char* fmt, char *content) {
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, fmt, content);
}

void LOGW(const char* fmt, char *content) {
    __android_log_print(ANDROID_LOG_WARN, LOG_TAG, fmt, content);
}

void LOGD( const char* fmt, char *content) {
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, content);
}

void LOGE(const char* fmt, char *content) {
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt,content);
}
//void LOGV(const char* tag, const char* fmt, char *content) {
//    __android_log_print(ANDROID_LOG_VERBOSE, tag, fmt, content);
//}
//
//void LOGW(const char* tag, const char* fmt, char *content) {
//    __android_log_print(ANDROID_LOG_WARN, tag, fmt, content);
//}
//
//void LOGD(const char* tag, const char* fmt, char *content) {
//    __android_log_print(ANDROID_LOG_DEBUG, tag, fmt, content);
//}
//
//void LOGE(const char* tag, const char* fmt, char *content) {
//    __android_log_print(ANDROID_LOG_ERROR, tag, fmt,content);
//}