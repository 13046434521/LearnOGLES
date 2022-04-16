//
// Created by Administrator on 2022/4/16.
//

#include "Sence.h"

AAssetManager * aAssetManager = nullptr;
unsigned char* loadFileContent(char * filePath,int& fileSize){
    unsigned char* content = nullptr;
    AAsset* aAsset = AAssetManager_open(aAssetManager,filePath,AASSET_MODE_UNKNOWN);
    if (aAsset!= nullptr){
        fileSize  = AAsset_getLength(aAsset);
        content = new unsigned char [fileSize+1];
        AAsset_read(aAsset,content,fileSize);
        *(content+fileSize) = 0;
        AAsset_close(aAsset);
    }
    return content;
}



extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_Init (JNIEnv *env, jobject thiz){
    glClearColor(0.1,0.3,0.8,1.0);
    int size = 0;
    unsigned char* text = loadFileContent("text.txt",size);


    __android_log_print(ANDROID_LOG_DEBUG,TAG,"Init:%s",text);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_OnViewPortChange(JNIEnv *env, jobject thiz,jint width,jint height){
    glViewport(0,0,width,height);
    __android_log_print(ANDROID_LOG_DEBUG,TAG,"OnViewPortChange:%d,%d",width,height);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_Render(JNIEnv *env, jobject thiz){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    __android_log_print(ANDROID_LOG_DEBUG,TAG,"Render");

}
extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_MainActivity_initAssetManager(JNIEnv *env, jobject thiz,
                                                      jobject asset_manager) {
    aAssetManager = AAssetManager_fromJava(env,asset_manager);
}