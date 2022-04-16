### OpenGL
##### OpenGLE视口代码的原理
    1. opengl 是一个状态机
    2. glClearColor不是一个动词，而是属于他的一个状态
    3. viewPort：视口。
    4. 左下角是(0,0)原点
    5. 彩色缓冲区，深度缓冲区，蒙版缓冲区

##### 使用NDK来写OpenGLES代码
    1. 导入头文件
    ```c
        #include <GLES2/gl2.h>
        #include<GLES2/gl2ext.h>
        #include<GLES2/gl2platform.h>
    ```
    2. cmake中导入so库
    ```
        find_library(
                gl2
                GLESv2
        )
        target_link_libraries( # Specifies the target library.
                learnogles

                # Links the target library to the log library
                # included in the NDK.
                ${log-lib}
                ${gl2})
    ```
##### NDK中增加LOG日志
    1. cmake中添加log库
    ```cmake
    find_library( # Sets the name of the path variable.
            log-lib

            # Specifies the name of the NDK library that
            # you want CMake to locate.
            log)
    target_link_libraries( # Specifies the target library.
            learnogles

            # Links the target library to the log library
            # included in the NDK.
            ${log-lib})
    ```
    2. 添加头文件
    ```c++
        #include<android/log.h>
    ```
    3. 代码中使用
    ```c++
        __android_log_print(ANDROID_LOG_DEBUG,TAG,"Init");
    ```