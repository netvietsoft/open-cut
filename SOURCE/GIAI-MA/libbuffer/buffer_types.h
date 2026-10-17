/**
 * @file buffer_types.h
 * @brief ByteDance GeckoX High-Performance Native Buffer Subsystem - Common Definitions & ABI.
 *        Hệ thống bộ đệm nguyên sinh hiệu năng cao ByteDance GeckoX - Định nghĩa chung & ABI.
 *
 * Reconstructed Cleanroom Header for libbuffer.so / Tái dựng cleanroom cho libbuffer.so.
 * Target: ARM64-v8a (Android NDK ABI).
 * Package: com.bytedance.geckox.buffer.impl
 */

#ifndef GECKOX_BUFFER_TYPES_H
#define GECKOX_BUFFER_TYPES_H

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <string>
#include <memory>
#include <atomic>
#include <vector>
#include <system_error>

#if defined(__ANDROID__) || defined(__linux__)
#include <jni.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <android/log.h>
#else
// Mock declarations for non-Android host verification and unit testing
// Khai báo giả lập phục vụ kiểm thử và xác minh trên môi trường host
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

// Forward declaration of mock JNI native environment
struct JNINativeInterface_;
typedef const struct JNINativeInterface_* JNIEnv;

struct JNINativeInterface_ {
    void* reserved0;
    void* reserved1;
    void* reserved2;
    void* reserved3;
    jint (*GetVersion)(JNIEnv*);
    jclass (*DefineClass)(JNIEnv*, const char*, jobject, const jbyte*, jsize);
    jclass (*FindClass)(JNIEnv*, const char*); // Offset 0x30 (index 6)
    void* fromReflectedMethod;
    void* fromReflectedField;
    void* toReflectedMethod;
    void* getSuperclass;
    void* isAssignableFrom;
    void* toReflectedField;
    jint (*Throw)(JNIEnv*, jthrowable);
    jint (*ThrowNew)(JNIEnv*, jclass, const char*); // Offset 0x70 (index 14)
    // ... padding to offset 0x548 ...
    void* padding_to_0x548[154];
    const char* (*GetStringUTFChars)(JNIEnv*, jstring, jboolean*); // Offset 0x548 (index 169)
    void (*ReleaseStringUTFChars)(JNIEnv*, jstring, const char*); // Offset 0x550 (index 170)
    // ... padding to offset 0x640 ...
    void* padding_to_0x640[29];
    void (*GetByteArrayRegion)(JNIEnv*, jbyteArray, jsize, jsize, jbyte*); // Offset 0x640 (index 200)
    // ... padding to offset 0x680 ...
    void* padding_to_0x680[7];
    void (*SetByteArrayRegion)(JNIEnv*, jbyteArray, jsize, jsize, const jbyte*); // Offset 0x680 (index 208)
};
#endif

namespace nextai {
namespace opencut {
namespace buffer {

/**
 * @brief GeckoX Log Tag
 *        Nhãn log chuẩn của GeckoX Buffer
 */
constexpr const char* GECKOX_BUFFER_TAG = "Buffer";

/**
 * @brief Standard Java IOException class path
 *        Đường dẫn lớp ngoại lệ IOException chuẩn trong Java runtime
 */
constexpr const char* JAVA_IOEXCEPTION_CLASS = "java/io/IOException";

/**
 * @brief Error messages embedded in libbuffer.so .rodata
 *        Các chuỗi thông báo lỗi lưu trong phân vùng .rodata của libbuffer.so
 */
namespace ErrorStrings {
    constexpr const char* INCONSISTENT_FILE_LENGTH = "inconsistent file length";
    constexpr const char* MMAP_FAILED_FMT          = "mmap failed, %s";
    constexpr const char* LENGTH_ILLEGAL           = "length illegal";
    constexpr const char* SEEK_FAILED              = "seek failed";
    constexpr const char* NATIVE_CALLOC_FAILED     = "native calloc failed";
    constexpr const char* READ_FULL_FAILED         = "read full failed";
    constexpr const char* CLOSE_FAILED             = "close failed";
    constexpr const char* CLOSE_FILE_FAILED        = "close file failed";
    constexpr const char* MREMAP_FAILED            = "mremap failed";
}

/**
 * @brief Buffer Type Enumeration
 *        Phân loại kiểu bộ đệm (Memory mapped vs RAM heap)
 */
enum class BufferType : uint32_t {
    MMAP = 0,    ///< POSIX mmap shared file buffer / Bộ đệm mmap chia sẻ tập tin
    MEMORY = 1   ///< Heap allocated memory buffer / Bộ đệm bộ nhớ heap calloc
};

/**
 * @brief Runtime Buffer Descriptor Structure
 *        Cấu trúc bộ mô tả bộ đệm runtime quản lý con trỏ và dung lượng
 */
struct BufferDescriptor {
    BufferType type;           ///< Buffer type / Kiểu bộ đệm
    uintptr_t nativePtr;       ///< Virtual address / Địa chỉ ảo (mmap or heap)
    size_t size;               ///< Buffer size in bytes / Kích thước bộ đệm theo byte
    std::string filePath;      ///< Associated backing file path / Đường dẫn tập tin sao lưu
    int backingFd;             ///< File descriptor (-1 if closed) / File descriptor
    bool isDirty;              ///< Dirty modification flag / Cờ dữ liệu bị sửa đổi
    std::atomic<bool> isValid; ///< Validity flag / Cờ trạng thái hợp lệ

    BufferDescriptor()
        : type(BufferType::MEMORY), nativePtr(0), size(0), backingFd(-1), isDirty(false), isValid(false) {}

    BufferDescriptor(BufferType t, uintptr_t ptr, size_t sz, const std::string& path)
        : type(t), nativePtr(ptr), size(sz), filePath(path), backingFd(-1), isDirty(false), isValid(true) {}
};

/**
 * @brief Read full helper declaration
 *        Hàm trợ giúp đọc đầy đủ số byte từ file descriptor vào bộ đệm
 *
 * @param fd File descriptor to read from / File descriptor đọc dữ liệu
 * @param buf Destination buffer pointer / Con trỏ bộ đệm đích
 * @param count Number of bytes to read / Số byte cần đọc
 * @return Number of bytes actually read / Số byte thực tế đã đọc thành công
 */
long readFull(int fd, void* buf, long count);

/**
 * @brief Helper to throw Java IOException
 *        Hàm ném ngoại lệ java/io/IOException lên tầng Java
 */
void throwIOException(JNIEnv* env, const char* message);

/**
 * @brief Helper to throw Java IOException with errno string
 *        Hàm ném ngoại lệ java/io/IOException kèm strerror(errno)
 */
void throwIOExceptionWithErrno(JNIEnv* env, int errNum);

} // namespace buffer
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_TYPES_H
