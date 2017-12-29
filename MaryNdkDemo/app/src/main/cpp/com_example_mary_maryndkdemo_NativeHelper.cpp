//
// Created by mary on 2017/12/26.
//

#include <jni.h>
#include <android/log.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_mary_maryndkdemo_NativeHelper_getAppKey(JNIEnv *env, jclass type) {

    // TODO
    //测试代码, 没有任何意义
    char *app_key = "5465465416948";

    return env->NewStringUTF(app_key);
}

JNIEXPORT void JNICALL
Java_com_example_mary_maryndkdemo_NativeHelper_printLog(JNIEnv *env, jclass type, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    //TODO: 显示Android 的日志
    // 调用Android的代码
    // 代码需要调用系统的日志库, 这个库已经在 CMakeList.txt添加了e,因此可以直接调用
    const char *tag = "NativeHelper";
    //jstring -> char*
    jboolean *b = JNI_FALSE;
    const char *txt = env->GetStringUTFChars(str_, b);
    //打印log日志
    __android_log_write(ANDROID_LOG_DEBUG, tag, txt);
    //释放string
    env->ReleaseStringUTFChars(str_, str);
}
