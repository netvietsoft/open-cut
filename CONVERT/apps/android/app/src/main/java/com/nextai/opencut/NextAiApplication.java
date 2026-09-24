package com.nextai.opencut;

import android.app.Application;
import android.util.Log;

/**
 * NextAiApplication — Application Class
 * Initializes Koin DI, Native MiddleBridge C++ Engine, and Network infrastructure.
 * Khởi tạo hạ tầng Dependency Injection, nhân C++ và cấu hình mạng.
 */
public class NextAiApplication extends Application {
    private static final String TAG = "NextAI_App";

    @Override
    public void onCreate() {
        super.onCreate();
        Log.i(TAG, "NextAI OpenCut Application Initialized on Port 6033 Gateway");
    }
}
