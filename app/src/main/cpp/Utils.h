# pragma once
#include "base.h"
struct Vertice{
    float mPosition[4];// x,y,z,w
};
// 读取Asset内的文件
unsigned char* loadFileContent(char * filePath,int& fileSize);

// 获取两次之间的时间差
float getFrameTime();
