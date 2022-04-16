package com.jtl.learnogles;

import android.content.Context;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * @author：TianLong
 * @date：2022/4/16 0:49
 * @detail：
 */
public class LearnGLSurface extends GLSurfaceView implements GLSurfaceView.Renderer {
    public LearnGLSurface(Context context) {
        this(context,null);
    }

    public LearnGLSurface(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void init(){
        this.setEGLContextClientVersion(2);
        setRenderer(this);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
       OpenGLHelper.getInstance().Init();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        OpenGLHelper.getInstance().OnViewPortChange(width,height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        OpenGLHelper.getInstance().Render();
    }
}
