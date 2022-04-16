package com.jtl.learnogles;

/**
 * @author：TianLong
 * @date：2022/4/16 11:18
 * @detail：
 */
public class OpenGLHelper {

    private OpenGLHelper(){}

    public static OpenGLHelper getInstance(){
        return OpenGLHelperHolder.OPEN_GL_HELPER;
    }

    private static class OpenGLHelperHolder {
        private static final OpenGLHelper OPEN_GL_HELPER = new OpenGLHelper();
    }

    public native void Init();

    public native void OnViewPortChange(int width,int height);

    public native void Render();

}
