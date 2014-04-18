#include <iostream>
#include "jni.h"
#include "jvmti.h"

JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *vm, char *options, void *reserved) {
    std::cout << "Loading..." << std::endl;
    return JNI_OK;
}

JNIEXPORT void JNICALL Agent_OnUnload(JavaVM *vm) {
    std::cout << "Unload..." << std::endl;
}
