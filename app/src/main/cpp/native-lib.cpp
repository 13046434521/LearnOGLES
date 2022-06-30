#include "base.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_jtl_learnogles_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

int main(){
    printf("你好:%d",123);
}

int JNI_OnLoad(JavaVM* javaVm,void* arg){
    __android_log_print(ANDROID_LOG_DEBUG, "LOG_TAG","%s",(char*)"JNI_OnLoad");

    return JNI_VERSION_1_6;
}