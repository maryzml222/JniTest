package com.example.mary.maryndkdemo;

/**
 * Created by mary on 2017/12/26.
 */

public class NativeHelper {
    static {
        // 加载C代码库, 库的名称, 必须是CMakeLists.txt中指定的名称
        System.loadLibrary("native-lib");
    }

    //获取C中隐藏的AppKey
    public static native String getAppKey();
    //在C中打印log
    public static native void printLog(String str);
}
