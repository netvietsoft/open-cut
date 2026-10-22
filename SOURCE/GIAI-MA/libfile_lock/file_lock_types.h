/**
 * @file file_lock_types.h
 * @brief ByteDance GeckoX FileLock Native Subsystem - Common Definitions & ABI.
 *        Hệ thống khóa tệp nguyên sinh ByteDance GeckoX - Định nghĩa chung & ABI.
 *
 * Target: libfile_lock.so (ARM64-v8a).
 * Package: com.bytedance.geckox.utils.FileLock
 */

#ifndef GECKOX_FILE_LOCK_TYPES_H
#define GECKOX_FILE_LOCK_TYPES_H

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <string>
#include <memory>
#include <atomic>
#include <vector>

#if defined(__ANDROID__) || defined(__linux__)
#include <jni.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <android/log.h>
#else
typedef int8_t jbyte;
typedef int32_t jint;
typedef int64_t jlong;
typedef uint8_t jboolean;
typedef void* jobject;
typedef void* jstring;
typedef void* jclass;
typedef void* jthrowable;
typedef int32_t jsize;

#define JNI_OK 0
#define JNI_ERR (-1)
#define JNI_TRUE 1
#define JNI_FALSE 0

#define ANDROID_LOG_DEBUG 3
#define ANDROID_LOG_INFO  4
#define ANDROID_LOG_WARN  5
#define ANDROID_LOG_ERROR 6

#ifndef O_RDWR
#define O_RDWR 02
#endif
#ifndef O_CREAT
#define O_CREAT 0100
#endif
#ifndef O_CLOEXEC
#define O_CLOEXEC 02000000
#endif

#ifndef F_RDLCK
#define F_RDLCK 0
#endif
#ifndef F_WRLCK
#define F_WRLCK 1
#endif
#ifndef F_UNLCK
#define F_UNLCK 2
#endif

#ifndef F_SETLK
#define F_SETLK 6
#endif
#ifndef F_SETLKW
#define F_SETLKW 7
#endif

#ifndef SEEK_SET
#define SEEK_SET 0
#endif
#ifndef SEEK_CUR
#define SEEK_CUR 1
#endif
#ifndef SEEK_END
#define SEEK_END 2
#endif

struct flock {
    short l_type;
    short l_whence;
    off_t l_start;
    off_t l_len;
    pid_t l_pid;
};

struct JNINativeInterface_FL {
    void* reserved0;
    void* reserved1;
    void* reserved2;
    void* reserved3;
    jint (*GetVersion)(void*);
    jclass (*DefineClass)(void*, const char*, jobject, const jbyte*, jsize);
    jclass (*FindClass)(void*, const char*); // Offset 0x30
    void* fromReflectedMethod;
    void* fromReflectedField;
    void* toReflectedMethod;
    void* getSuperclass;
    void* isAssignableFrom;
    void* toReflectedField;
    jint (*Throw)(void*, jthrowable);
    jint (*ThrowNew)(void*, jclass, const char*); // Offset 0x70
    void* padding_to_0x548[154];
    const char* (*GetStringUTFChars)(void*, jstring, jboolean*); // Offset 0x548
    void (*ReleaseStringUTFChars)(void*, jstring, const char*); // Offset 0x550
};
typedef const struct JNINativeInterface_FL* JNIEnv;
#endif

namespace nextai {
namespace opencut {
namespace filelock {

constexpr const char* GECKOX_FILELOCK_TAG = "FileLock";
constexpr const char* JAVA_RUNTIME_EXCEPTION_CLASS = "java/lang/RuntimeException";

namespace ErrorStrings {
    constexpr const char* LOCK_FAILED_FMT   = " Lock Failed:type = %d\n";
    constexpr const char* UNLOCK_FAILED_FMT = " UnLock Failed:type = %d\n";
}

enum class LockType : int {
    READ = 0,
    WRITE = 1,
    UNLOCK = 2
};

void throwRuntimeException(JNIEnv* env, const char* message);
void throwRuntimeExceptionWithErrno(JNIEnv* env, int errNum);

} // namespace filelock
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_TYPES_H
