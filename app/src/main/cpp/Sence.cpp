//
// Created by Administrator on 2022/4/16.
//

#include "Sence.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_jtl_learnogles_MainActivity_getTest(JNIEnv *env, jobject thiz) {
    // TODO: implement getTest()

    return 200;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_Init (JNIEnv *env, jobject thiz){
    glClearColor(0.1,0.3,0.8,1.0);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_OnViewPortChange(JNIEnv *env, jobject thiz,jint width,jint height){
    glViewport(0,0,width,height);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_Render(JNIEnv *env, jobject thiz){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}