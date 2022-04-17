//
// Created by Administrator on 2022/4/16.
//

#include "Sence.h"
#include "Utils.h"

AAssetManager *aAssetManager = nullptr;

unsigned char *loadFileContent(char *filePath, int &fileSize) {
    unsigned char *content = nullptr;
    AAsset *aAsset = AAssetManager_open(aAssetManager, filePath, AASSET_MODE_UNKNOWN);
    if (aAsset != nullptr) {
        fileSize = AAsset_getLength(aAsset);
        content = new unsigned char[fileSize + 1];
        AAsset_read(aAsset, content, fileSize);
        *(content + fileSize) = 0;
        AAsset_close(aAsset);
    }
    return content;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_Init(JNIEnv *env, jobject thiz) {
    glClearColor(0.1, 0.3, 0.8, 1.0);
    int size = 0;
    unsigned char *text = loadFileContent("text.txt", size);


    // 顶点坐标
    Vertice vertice[3];
    vertice[0].mPosition[0] = 0.0f,
    vertice[0].mPosition[1] = 0.5f,
    vertice[0].mPosition[2] = -2.0f,
    vertice[0].mPosition[3] = 1.0f,

    vertice[1].mPosition[0] = -0.5f,
    vertice[1].mPosition[1] = -0.5f,
    vertice[1].mPosition[2] = -2.0f,
    vertice[1].mPosition[3] = 1.0f,

    vertice[2].mPosition[0] = 0.5f,
    vertice[2].mPosition[1] = -0.5f,
    vertice[2].mPosition[2] = -2.0f,
    vertice[2].mPosition[3] = 1.0f;

    GLuint  vbo ;
    glGenBuffers(1,&vbo);// 生成一个vbo缓冲区
    glBindBuffer(GL_ARRAY_BUFFER,vbo);//将GL_ARRAY_BUFFER卡槽设置指向vbo
    // 在显存中开辟空间
    glBufferData(GL_ARRAY_BUFFER,sizeof (Vertice)*3, nullptr,GL_STATIC_DRAW);//  GL_STATIC_DRAW:静态不会改变
    // 设置数据到显存
    glBufferSubData(GL_ARRAY_BUFFER,0,sizeof (Vertice)*3,vertice);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)*3,vertice,GL_STATIC_DRAW); // 直接在显存中开辟内存+设置数据
    // 等价于：
    //1. glBufferData(GL_ARRAY_BUFFER,sizeof (Vertice)*3, nullptr,GL_STATIC_DRAW);//  GL_STATIC_DRAW:静态不会改变
    //2. glBufferSubData(GL_ARRAY_BUFFER,0,sizeof (Vertice)*3,vertice);
    // 将GL_ARRAY_BUFFER卡槽 设置指向0
    glBindBuffer(GL_ARRAY_BUFFER,0);




    __android_log_print(ANDROID_LOG_DEBUG, TAG, "Init:%s", text);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_OnViewPortChange(JNIEnv *env, jobject thiz, jint width,
                                                      jint height) {
    glViewport(0, 0, width, height);
    __android_log_print(ANDROID_LOG_DEBUG, TAG, "OnViewPortChange:%d,%d", width, height);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_OpenGLHelper_Render(JNIEnv *env, jobject thiz) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    __android_log_print(ANDROID_LOG_DEBUG, TAG, "Render:%f", getFrameTime());

}
extern "C"
JNIEXPORT void JNICALL
Java_com_jtl_learnogles_MainActivity_initAssetManager(JNIEnv *env, jobject thiz,
                                                      jobject asset_manager) {
    aAssetManager = AAssetManager_fromJava(env, asset_manager);
}