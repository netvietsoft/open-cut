/**
 * @file file_lock_jni.h
 * @brief ByteDance GeckoX FileLock Native JNI Interface Header.
 *        Giao diện JNI native khóa tệp tin ByteDance GeckoX.
 */

#ifndef GECKOX_FILE_LOCK_JNI_H
#define GECKOX_FILE_LOCK_JNI_H

#include "file_lock_types.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_com_bytedance_geckox_utils_FileLock_nGetFD(
    JNIEnv* env,
    jobject thiz,
    jstring path
);

JNIEXPORT void JNICALL Java_com_bytedance_geckox_utils_FileLock_nLockFile(
    JNIEnv* env,
    jobject thiz,
    jint fd
);

JNIEXPORT void JNICALL Java_com_bytedance_geckox_utils_FileLock_nUnlockFile(
    JNIEnv* env,
    jobject thiz,
    jint fd
);

JNIEXPORT jboolean JNICALL Java_com_bytedance_geckox_utils_FileLock_nTryLock(
    JNIEnv* env,
    jobject thiz,
    jint fd
);

JNIEXPORT void JNICALL Java_com_bytedance_geckox_utils_FileLock_nLockFileSegment(
    JNIEnv* env,
    jobject thiz,
    jint fd,
    jint segment
);

JNIEXPORT void JNICALL Java_com_bytedance_geckox_utils_FileLock_nRelease(
    JNIEnv* env,
    jobject thiz,
    jint fd
);

#ifdef __cplusplus
}
#endif

#endif // GECKOX_FILE_LOCK_JNI_H
