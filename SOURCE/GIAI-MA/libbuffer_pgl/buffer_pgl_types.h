/**
 * @file buffer_pgl_types.h
 * @brief ByteDance Pangle / OpenVK GeckoX Native Buffer Subsystem - Common Definitions & ABI.
 *        Hệ thống bộ đệm nguyên sinh Pangle OpenVK GeckoX - Định nghĩa chung & ABI.
 *
 * Target: libbuffer_pgl.so (ARM64-v8a).
 * Package: com.bykv.vk.openvk.preload.geckox.buffer.impl
 */

#ifndef GECKOX_BUFFER_PGL_TYPES_H
#define GECKOX_BUFFER_PGL_TYPES_H

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
#include <sys/mman.h>
#include <android/log.h>
#else
typedef int8_t jbyte;
typedef int32_t jint;
typedef int64_t jlong;
typedef uint8_t jboolean;
typedef void* jobject;
typedef void* jstring;
typedef void* jclass;
typedef void* jbyteArray;
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
#ifndef O_TRUNC
#define O_TRUNC 01000
#endif
#ifndef O_CLOEXEC
#define O_CLOEXEC 02000000
#endif

#ifndef PROT_READ
#define PROT_READ 0x1
#endif
#ifndef PROT_WRITE
#define PROT_WRITE 0x2
#endif
#ifndef MAP_SHARED
#define MAP_SHARED 0x01
#endif
#ifndef MAP_FAILED
#define MAP_FAILED ((void*)-1)
#endif
#ifndef MS_SYNC
#define MS_SYNC 0x0004
#endif
#ifndef MREMAP_MAYMOVE
#define MREMAP_MAYMOVE 1
#endif

#ifndef SEEK_SET
#define SEEK_SET 0
#endif
#ifndef SEEK_END
#define SEEK_END 2
#endif

struct JNINativeInterface_Pgl {
    void* reserved0;
    void* reserved1;
    void* reserved2;
    void* reserved3;
    jint (*GetVersion)(void*);
    jclass (*DefineClass)(void*, const char*, jobject, const jbyte*, jsize);
    jclass (*FindClass)(void*, const char*); // 0x30
    void* fromReflectedMethod;
    void* fromReflectedField;
    void* toReflectedMethod;
    void* getSuperclass;
    void* isAssignableFrom;
    void* toReflectedField;
    jint (*Throw)(void*, jthrowable);
    jint (*ThrowNew)(void*, jclass, const char*); // 0x70
    void* padding_to_0x548[154];
    const char* (*GetStringUTFChars)(void*, jstring, jboolean*); // 0x548
    void (*ReleaseStringUTFChars)(void*, jstring, const char*); // 0x550
    void* padding_to_0x640[29];
    void (*GetByteArrayRegion)(void*, jbyteArray, jsize, jsize, jbyte*); // 0x640
    void* padding_to_0x680[7];
    void (*SetByteArrayRegion)(void*, jbyteArray, jsize, jsize, const jbyte*); // 0x680
};
typedef const struct JNINativeInterface_Pgl* JNIEnv;
#endif

namespace nextai {
namespace opencut {
namespace buffer_pgl {

constexpr const char* GECKOX_PGL_BUFFER_TAG = "Buffer";
constexpr const char* JAVA_IOEXCEPTION_CLASS = "java/io/IOException";

namespace ErrorStrings {
    constexpr const char* INCONSISTENT_FILE_LENGTH = "inconsistent file length";
    constexpr const char* FILE_LENGTHS_INCONSISTENT= "File lengths are inconsistent";
    constexpr const char* MMAP_FAILED_FMT          = "mmap failed, %s";
    constexpr const char* MAP_FAILED_STR           = "map failed";
    constexpr const char* LENGTH_ILLEGAL           = "length illegal";
    constexpr const char* SEEK_FAILED              = "seek failed";
    constexpr const char* NATIVE_CALLOC_FAILED     = "native calloc failed";
    constexpr const char* READ_FULL_FAILED         = "read full failed";
    constexpr const char* CLOSE_FAILED             = "close failed";
    constexpr const char* CLOSE_FILE_FAILED        = "close file failed";
    constexpr const char* MREMAP_FAILED            = "mremap failed";
}

long readFull(int fd, void* buf, long count);
void throwIOException(JNIEnv* env, const char* message);
void throwIOExceptionWithErrno(JNIEnv* env, int errNum);

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_PGL_TYPES_H
