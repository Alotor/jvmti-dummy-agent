#include <iostream>
#include "jni.h"
#include "jvmti.h"
#include "NativeObject.h"

extern "C" {
    jvmtiEnv *jvmti;

    JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *vm, char *options, void *reserved) {
        std::cout << "Loading..." << std::endl;
        vm->GetEnv((void **)&jvmti, JVMTI_VERSION);
        return JNI_OK;
    }

    JNIEXPORT void JNICALL Agent_OnUnload(JavaVM *vm) {
        std::cout << "Unload..." << std::endl;
    }

    JNIEXPORT void JNICALL Java_alotor_jvmti_NativeObject_helloFromC (JNIEnv *jniEnv, jobject obj){
        jvmtiError err;

        // jint runtime_version;
        // err = jvmti->GetVersionNumber(&runtime_version);
        // std::cout << "JVM TI Runtime Version: " << runtime_version << std::endl;

        jvmtiFrameInfo frames[5];
        jint count;
        jint framecount;

        err = jvmti->GetFrameCount(NULL, &framecount);
        err = jvmti->GetStackTrace(NULL, 0, 5, frames, &count);
        if (err == JVMTI_ERROR_NONE && count >= 1) {
           char *methodName;
           err = jvmti->GetMethodName(frames[0].method, &methodName, NULL, NULL);

           if (err == JVMTI_ERROR_NONE) {
               std::cout << "Executing method: " << methodName << std::endl;
               std::cout << "Frame count: " << framecount << std::endl;
           }
        }
    }
}
