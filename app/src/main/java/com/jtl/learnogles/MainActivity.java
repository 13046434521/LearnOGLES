package com.jtl.learnogles;

import android.content.res.AssetManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.jtl.learnogles.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'learnogles' library on application startup.
    static {
        System.loadLibrary("learnogles");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(""+stringFromJNI());

        initAssetManager(this.getAssets());
    }

    /**
     * A native method that is implemented by the 'learnogles' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native void initAssetManager(AssetManager assetManager);
}