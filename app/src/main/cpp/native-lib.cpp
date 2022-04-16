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
