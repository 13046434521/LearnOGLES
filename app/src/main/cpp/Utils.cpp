
#include "Utils.h"


float getFrameTime(){
    static long long lastTime,currentTime;
    timeval timeval;
    gettimeofday(&timeval, nullptr);

    currentTime = timeval.tv_sec * 1000 + timeval.tv_usec/1000;

    float frameTime = lastTime==0?0:currentTime-lastTime;
    lastTime = currentTime;

    return (float )frameTime/1000.f;
}
