/**
 * @file keva_types.h
 * @brief ByteDance Keva High-Performance Key-Value Storage Native Subsystem - Common Definitions & ABI.
 *        Hệ thống lưu trữ khóa-giá trị Keva hiệu năng cao ByteDance - Định nghĩa chung & ABI.
 *
 * Target: libkeva.so (ARM64-v8a).
 * Package: com.bytedance.keva.KevaImpl
 */

#ifndef GECKOX_KEVA_TYPES_H
#define GECKOX_KEVA_TYPES_H

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>
#include <memory>
#include <atomic>
#include <unordered_map>
#include <mutex>

#if defined(__ANDROID__) || defined(__linux__)
#include <jni.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <android/log.h>
#else
typedef int8_t jbyte;
typedef int32_t jint;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;
typedef uint8_t jboolean;
typedef void* jobject;
typedef void* jstring;
typedef void* jclass;
typedef void* jthrowable;
typedef void* jbyteArray;
typedef void* jobjectArray;
typedef int32_t jsize;

#define JNI_OK 0
#define JNI_ERR (-1)
#define JNI_TRUE 1
#define JNI_FALSE 0
#define JNI_VERSION_1_6 0x00010006

#define ANDROID_LOG_DEBUG 3
#define ANDROID_LOG_INFO  4
#define ANDROID_LOG_WARN  5
#define ANDROID_LOG_ERROR 6

struct JNINativeInterface_Keva {
    void* reserved0;
    void* reserved1;
    void* reserved2;
    void* reserved3;
    jint (*GetVersion)(void*);
    jclass (*DefineClass)(void*, const char*, jobject, const jbyte*, jsize);
    jclass (*FindClass)(void*, const char*);
    void* fromReflectedMethod;
    void* fromReflectedField;
    void* toReflectedMethod;
    void* getSuperclass;
    void* isAssignableFrom;
    void* toReflectedField;
    jint (*Throw)(void*, jthrowable);
    jint (*ThrowNew)(void*, jclass, const char*);
    void* padding_to_0x548[154];
    const char* (*GetStringUTFChars)(void*, jstring, jboolean*);
    void (*ReleaseStringUTFChars)(void*, jstring, const char*);
    jsize (*GetStringUTFLength)(void*, jstring);
    jbyteArray (*NewByteArray)(void*, jsize);
    jbyte* (*GetByteArrayElements)(void*, jbyteArray, jboolean*);
    void (*ReleaseByteArrayElements)(void*, jbyteArray, jbyte*, jint);
    void (*GetByteArrayRegion)(void*, jbyteArray, jsize, jsize, jbyte*);
    void (*SetByteArrayRegion)(void*, jbyteArray, jsize, jsize, const jbyte*);
    jsize (*GetArrayLength)(void*, jobject);
    jobjectArray (*NewObjectArray)(void*, jsize, jclass, jobject);
    jobject (*GetObjectArrayElement)(void*, jobjectArray, jsize);
    void (*SetObjectArrayElement)(void*, jobjectArray, jsize, jobject);
    jstring (*NewStringUTF)(void*, const char*);
    jint (*RegisterNatives)(void*, jclass, const void*, jint);
};
typedef const struct JNINativeInterface_Keva* JNIEnv;

struct JavaVM_Keva {
    void* functions;
    jint (*GetEnv)(void*, void**, jint);
};
typedef const struct JavaVM_Keva* JavaVM;
#endif

namespace nextai {
namespace opencut {
namespace keva {

constexpr const char* KEVA_TAG = "KEVA.NATIVE";
constexpr uint32_t KEVA_FILE_MAGIC = 0x4B455641;      ///< 'KEVA'
constexpr uint32_t KEVA_VERSION = 1;
constexpr size_t KEVA_DEFAULT_CHUNK_SIZE = 16;        ///< 16 bytes per chunk unit
constexpr size_t KEVA_INITIAL_FILE_SIZE = 64 * 1024;  ///< 64 KB initial mmap size

/**
 * @brief Keva Data Types enumeration
 *        Phân loại kiểu dữ liệu được Keva hỗ trợ
 */
enum KevaDataType : uint8_t {
    KEVA_TYPE_NULL         = 0,
    KEVA_TYPE_BOOL         = 1,
    KEVA_TYPE_INT          = 2,
    KEVA_TYPE_FLOAT        = 3,
    KEVA_TYPE_LONG         = 4,
    KEVA_TYPE_DOUBLE       = 5,
    KEVA_TYPE_STRING       = 6,
    KEVA_TYPE_BYTES        = 7,
    KEVA_TYPE_STRING_ARRAY = 8
};

/**
 * @brief Keva File Header Structure (Stored at offset 0 of mmap file)
 *        Tiêu đề tệp lưu trữ Keva (Nằm tại offset 0 của tệp mmap)
 */
#pragma pack(push, 1)
struct KevaFileHeader {
    uint32_t magic;             ///< 0x4B455641 ('KEVA')
    uint32_t version;           ///< Version 1
    uint32_t totalFileSize;     ///< Kích thước tệp hiện tại
    uint32_t chunkCount;        ///< Tổng số chunk quản lý
    uint32_t keyCount;          ///< Số lượng khóa hợp lệ
    uint32_t crc32;             ///< Mã kiểm tra toàn vẹn
    uint64_t sequenceNumber;    ///< Số thứ tự commit
    uint8_t  reserved[32];      ///< Dành riêng mở rộng
};

/**
 * @brief Keva Chunk Header Structure (Stored before each payload)
 *        Tiêu đề phân đoạn lưu trữ Keva
 */
struct KevaChunkHeader {
    uint16_t keyLength;         ///< Độ dài khóa UTF-8
    uint32_t valueLength;       ///< Độ dài giá trị (bytes)
    uint8_t  type;              ///< KevaDataType
    uint8_t  flags;             ///< Cờ chunk (0x01: Active, 0x02: Deleted)
    uint32_t crc32;             ///< Checksum dữ liệu payload
    uint64_t timestamp;         ///< Thời điểm ghi (microsecond)
};
#pragma pack(pop)

/**
 * @brief In-memory cache representation of a Keva Entry
 *        Bản ghi lưu trữ trong bộ nhớ đệm của một mục Keva
 */
struct KevaEntry {
    std::string key;
    KevaDataType type;
    int64_t intValue;
    double doubleValue;
    std::string stringValue;
    std::vector<uint8_t> bytesValue;
    std::vector<std::string> stringArrayValue;
    uint32_t chunkOffset;
    uint32_t chunkCount;
};

uint32_t calculateKevaCRC32(const uint8_t* data, size_t length);

} // namespace keva
} // namespace opencut
} // namespace nextai

#endif // GECKOX_KEVA_TYPES_H
