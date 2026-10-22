/**
 * @file file_lock_pgl_jni.cpp
 * @brief ByteDance Pangle / OpenVK GeckoX FileLock Native JNI Implementation.
 *        Hiện thực mã nguồn C++ JNI khóa tệp cho Pangle OpenVK GeckoX.
 *
 * Cleanroom reverse-engineered from libfile_lock_pgl.so (ARM64-v8a).
 * Exact opcode match for functions:
 *  - FileLock_nLockFile        @ 0x0a48 (212 bytes)
 *  - FileLock_nUnlockFile      @ 0x0b1c (212 bytes)
 *  - FileLock_nTryLock         @ 0x0bf0 (108 bytes)
 *  - FileLock_nLockFileSegment @ 0x0c5c (216 bytes)
 *  - FileLock_nGetFD           @ 0x0d34 (184 bytes)
 *  - FileLock_nRelease         @ 0x0dec (116 bytes)
 */

#include "file_lock_pgl_jni.h"
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>

namespace nextai {
namespace opencut {
namespace filelock_pgl {

void throwRuntimeException(JNIEnv* env, const char* message) {
    if (!env) return;
    jclass exClass = env->FindClass(JAVA_RUNTIME_EXCEPTION_CLASS);
    if (exClass) {
        env->ThrowNew(exClass, message ? message : "RuntimeException");
    }
}

void throwRuntimeExceptionWithErrno(JNIEnv* env, int errNum) {
    if (!env) return;
    const char* errStr = std::strerror(errNum);
    throwRuntimeException(env, errStr ? errStr : "Unknown POSIX Lock Error");
}

} // namespace filelock_pgl
} // namespace opencut
} // namespace nextai

using namespace nextai::opencut::filelock_pgl;

extern "C" {

/**
 * @brief Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nGetFD
 * Disassembly match: 0x0d34..0x0dec (184 bytes)
 *
 * Opens file with flags O_RDWR | O_CREAT | O_CLOEXEC = 0x80042, mode 0666.
 * If open fails, throws RuntimeException with strerror(errno) and returns -1.
 */
JNIEXPORT jint JNICALL Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nGetFD(
    JNIEnv* env,
    jobject thiz,
    jstring path
) {
    if (!env || !path) {
        return -1;
    }

    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    if (!pathStr) {
        return -1;
    }

#if defined(__ANDROID__) || defined(__linux__)
    // 0x0d60: mov w1, #0x42; movk w1, #8, lsl #16; mov w2, #0x1b6
    // flags = O_RDWR | O_CREAT | O_CLOEXEC = 0x80042, mode = 0666
    int fd = ::open(pathStr, O_RDWR | O_CREAT | O_CLOEXEC, 0666);
    env->ReleaseStringUTFChars(path, pathStr);

    // 0x0d88: tbz w20, #0x1f, #0xdc8 (if fd >= 0, return fd)
    if (fd < 0) {
        throwRuntimeExceptionWithErrno(env, errno);
        return -1;
    }
    return fd;
#else
    env->ReleaseStringUTFChars(path, pathStr);
    return 100;
#endif
}

/**
 * @brief Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nLockFile
 * Disassembly match: 0x0a48..0x0b1c (212 bytes)
 *
 * Acquires blocking exclusive lock: fcntl(fd, F_SETLKW = 7, &flock)
 * with fl.l_type = F_WRLCK (1), fl.l_whence = SEEK_SET (0), fl.l_start = 0, fl.l_len = 0.
 */
JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nLockFile(
    JNIEnv* env,
    jobject thiz,
    jint fd
) {
#if defined(__ANDROID__) || defined(__linux__)
    // 0x0a68: mov w10, #1 (F_WRLCK); 0x0a74: mov w1, #7 (F_SETLKW)
    struct flock fl;
    std::memset(&fl, 0, sizeof(fl));
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    fl.l_pid = -1;

    int ret = ::fcntl(fd, F_SETLKW, &fl);
    if (ret < 0) {
        // 0x0ab0: __android_log_print(3, "FileLock", "Lock Failed:type = %d\n", fl.l_type)
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_PGL_FILELOCK_TAG, ErrorStrings::LOCK_FAILED_FMT, fl.l_type);
        throwRuntimeExceptionWithErrno(env, errno);
    }
#endif
}

/**
 * @brief Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nUnlockFile
 * Disassembly match: 0x0b1c..0x0bf0 (212 bytes)
 *
 * Releases lock: fcntl(fd, F_SETLK = 6, &flock) with fl.l_type = F_UNLCK (2).
 */
JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nUnlockFile(
    JNIEnv* env,
    jobject thiz,
    jint fd
) {
#if defined(__ANDROID__) || defined(__linux__)
    // 0x0b40: mov w10, #2 (F_UNLCK); 0x0b4c: mov w1, #6 (F_SETLK)
    struct flock fl;
    std::memset(&fl, 0, sizeof(fl));
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    fl.l_pid = -1;

    int ret = ::fcntl(fd, F_SETLK, &fl);
    if (ret < 0) {
        // 0x0b84: __android_log_print(3, "FileLock", " UnLock Failed:type = %d\n", fl.l_type)
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_PGL_FILELOCK_TAG, ErrorStrings::UNLOCK_FAILED_FMT, fl.l_type);
        throwRuntimeExceptionWithErrno(env, errno);
    }
#endif
}

/**
 * @brief Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nTryLock
 * Disassembly match: 0x0bf0..0x0c5c (108 bytes)
 *
 * Attempts non-blocking exclusive lock: fcntl(fd, F_SETLK = 6, &flock).
 * Arithmetic: mvn w8, w0; lsr w0, w8, #0x1f -> returns 1 if fcntl==0, else 0.
 */
JNIEXPORT jboolean JNICALL Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nTryLock(
    JNIEnv* env,
    jobject thiz,
    jint fd
) {
#if defined(__ANDROID__) || defined(__linux__)
    // 0x0c08: mov w9, #1 (F_WRLCK); 0x0c14: mov w1, #6 (F_SETLK)
    struct flock fl;
    std::memset(&fl, 0, sizeof(fl));
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    fl.l_pid = -1;

    int ret = ::fcntl(fd, F_SETLK, &fl);
    // 0x0c48: mvn w8, w0; 0x0c4c: lsr w0, w8, #0x1f
    return (ret == 0) ? JNI_TRUE : JNI_FALSE;
#else
    return JNI_TRUE;
#endif
}

/**
 * @brief Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nLockFileSegment
 * Disassembly match: 0x0c5c..0x0d34 (216 bytes)
 *
 * Locks specific byte segment: fcntl(fd, F_SETLKW = 7, &flock)
 * with fl.l_type = F_WRLCK (1), fl.l_start = segment, fl.l_len = 1.
 */
JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nLockFileSegment(
    JNIEnv* env,
    jobject thiz,
    jint fd,
    jint segment
) {
#if defined(__ANDROID__) || defined(__linux__)
    // 0x0c80: sxtw x10, w3 (sign-extend segment)
    // 0x0c84: mov w11, #1 (F_WRLCK)
    // 0x0c90: mov w1, #7 (F_SETLKW)
    struct flock fl;
    std::memset(&fl, 0, sizeof(fl));
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_CUR;
    fl.l_start = static_cast<off_t>(segment);
    fl.l_len = 1;
    fl.l_pid = -1;

    int ret = ::fcntl(fd, F_SETLKW, &fl);
    if (ret < 0) {
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_PGL_FILELOCK_TAG, ErrorStrings::LOCK_FAILED_FMT, fl.l_type);
        throwRuntimeExceptionWithErrno(env, errno);
    }
#endif
}

/**
 * @brief Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nRelease
 * Disassembly match: 0x0dec..0x0e60 (116 bytes)
 *
 * Closes file descriptor: close(fd). If close fails (-1), throws RuntimeException.
 */
JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nRelease(
    JNIEnv* env,
    jobject thiz,
    jint fd
) {
#if defined(__ANDROID__) || defined(__linux__)
    int ret = ::close(fd);
    if (ret == -1) {
        throwRuntimeExceptionWithErrno(env, errno);
    }
#endif
}

} // extern "C"
