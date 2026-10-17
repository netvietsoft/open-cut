/**
 * @file buffer_mmap.cpp
 * @brief ByteDance GeckoX MMapBuffer Native Implementation.
 *        Hiện thực mã nguồn C++ cho bộ đệm ánh xạ tệp mmap của ByteDance GeckoX.
 *
 * Cleanroom reverse-engineered from libbuffer.so (ARM64-v8a).
 * Exact opcode match for functions:
 *  - MMapBuffer_nCreate  @ 0x0f5c (480 bytes)
 *  - MMapBuffer_nWrite   @ 0x113c (92 bytes)
 *  - MMapBuffer_nRelease @ 0x1198 (76 bytes)
 *  - MMapBuffer_nRead    @ 0x11e4 (92 bytes)
 *  - MMapBuffer_nFlush   @ 0x1240 (172 bytes)
 */

#include "buffer_mmap.h"
#include <cstdio>
#include <cstdlib>
#include <cerrno>

#if !defined(__ANDROID__) && !defined(__linux__)
// Fallback mock implementations for non-POSIX platforms
static void* mock_mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset) {
    return std::malloc(length);
}
static int mock_munmap(void* addr, size_t length) {
    std::free(addr);
    return 0;
}
static int mock_msync(void* addr, size_t length, int flags) {
    return 0;
}
#define mmap mock_mmap
#define munmap mock_munmap
#define msync mock_msync
#endif

namespace nextai {
namespace opencut {
namespace buffer {

void throwIOException(JNIEnv* env, const char* message) {
    if (!env) return;
    jclass exClass = env->FindClass(JAVA_IOEXCEPTION_CLASS);
    if (exClass) {
        env->ThrowNew(exClass, message ? message : "IOException");
    }
}

void throwIOExceptionWithErrno(JNIEnv* env, int errNum) {
    if (!env) return;
    const char* errStr = std::strerror(errNum);
    throwIOException(env, errStr ? errStr : "Unknown POSIX I/O error");
}

// ============================================================================
// MMapBufferEngine Implementation
// ============================================================================

MMapBufferEngine::MMapBufferEngine()
    : m_mappedAddress(nullptr), m_size(0), m_filePath(""), m_isDirty(false) {}

MMapBufferEngine::MMapBufferEngine(const std::string& path, size_t size)
    : m_mappedAddress(nullptr), m_size(0), m_filePath(""), m_isDirty(false) {
    std::string err;
    openAndMap(path, size, err);
}

MMapBufferEngine::~MMapBufferEngine() {
    closeAndUnmap();
}

MMapBufferEngine::MMapBufferEngine(MMapBufferEngine&& other) noexcept
    : m_mappedAddress(other.m_mappedAddress),
      m_size(other.m_size),
      m_filePath(std::move(other.m_filePath)),
      m_isDirty(other.m_isDirty.load()) {
    other.m_mappedAddress = nullptr;
    other.m_size = 0;
    other.m_isDirty = false;
}

MMapBufferEngine& MMapBufferEngine::operator=(MMapBufferEngine&& other) noexcept {
    if (this != &other) {
        closeAndUnmap();
        m_mappedAddress = other.m_mappedAddress;
        m_size = other.m_size;
        m_filePath = std::move(other.m_filePath);
        m_isDirty = other.m_isDirty.load();

        other.m_mappedAddress = nullptr;
        other.m_size = 0;
        other.m_isDirty = false;
    }
    return *this;
}

size_t MMapBufferEngine::getSystemPageSize() {
#if defined(__ANDROID__) || defined(__linux__)
    long sz = sysconf(_SC_PAGESIZE);
    return sz > 0 ? static_cast<size_t>(sz) : 4096;
#else
    return 4096;
#endif
}

uintptr_t MMapBufferEngine::alignToPage(uintptr_t addr) {
    size_t pageSize = getSystemPageSize();
    return (addr + pageSize - 1) & ~(pageSize - 1);
}

bool MMapBufferEngine::openAndMap(const std::string& path, size_t size, std::string& outError) {
    closeAndUnmap();

    if (size == 0) {
        outError = ErrorStrings::LENGTH_ILLEGAL;
        return false;
    }

#if defined(__ANDROID__) || defined(__linux__)
    // O_RDWR | O_CREAT | O_CLOEXEC (0x80042)
    int fd = ::open(path.c_str(), O_RDWR | O_CREAT | O_CLOEXEC, 0666);
    if (fd < 0) {
        outError = std::strerror(errno);
        return false;
    }

    off_t fileLen = ::lseek(fd, 0, SEEK_END);
    if (fileLen == static_cast<off_t>(-1)) {
        outError = std::strerror(errno);
        ::close(fd);
        return false;
    }

    // ByteDance consistency check: if file is non-empty and length does not match requested size
    // Kiểm tra tính nhất quán: nếu file có dữ liệu và kích thước không khớp kích thước yêu cầu
    if (fileLen >= 1 && static_cast<size_t>(fileLen) != size) {
        outError = ErrorStrings::INCONSISTENT_FILE_LENGTH;
        ::close(fd);
        return false;
    }

    // Truncate to desired size
    if (::ftruncate(fd, static_cast<off_t>(size)) != 0) {
        outError = std::strerror(errno);
        ::close(fd);
        return false;
    }

    void* mapped = ::mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    ::close(fd); // File descriptor can be closed immediately after successful mmap

    if (mapped == MAP_FAILED) {
        char buf[256];
        std::snprintf(buf, sizeof(buf), ErrorStrings::MMAP_FAILED_FMT, path.c_str());
        outError = buf;
#ifdef __ANDROID__
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_BUFFER_TAG, "%s", buf);
#endif
        return false;
    }

    m_mappedAddress = mapped;
    m_size = size;
    m_filePath = path;
    m_isDirty = false;
    return true;
#else
    // Host mock allocation
    m_mappedAddress = std::malloc(size);
    if (!m_mappedAddress) {
        outError = ErrorStrings::NATIVE_CALLOC_FAILED;
        return false;
    }
    std::memset(m_mappedAddress, 0, size);
    m_size = size;
    m_filePath = path;
    m_isDirty = false;
    return true;
#endif
}

void MMapBufferEngine::closeAndUnmap() {
    if (m_mappedAddress && m_mappedAddress != MAP_FAILED) {
        flush(false);
#if defined(__ANDROID__) || defined(__linux__)
        ::munmap(m_mappedAddress, m_size);
#else
        std::free(m_mappedAddress);
#endif
        m_mappedAddress = nullptr;
    }
    m_size = 0;
    m_filePath.clear();
    m_isDirty = false;
}

bool MMapBufferEngine::write(size_t offset, const uint8_t* src, size_t length) {
    if (!isValid() || !src || (offset + length > m_size) || (offset + length < offset)) {
        return false;
    }
    uint8_t* dst = static_cast<uint8_t*>(m_mappedAddress) + offset;
    std::memcpy(dst, src, length);
    m_isDirty = true;
    return true;
}

bool MMapBufferEngine::read(size_t offset, uint8_t* dst, size_t length) const {
    if (!isValid() || !dst || (offset + length > m_size) || (offset + length < offset)) {
        return false;
    }
    const uint8_t* src = static_cast<const uint8_t*>(m_mappedAddress) + offset;
    std::memcpy(dst, src, length);
    return true;
}

bool MMapBufferEngine::flush(bool async) {
    if (!isValid() || !m_isDirty) {
        return true;
    }
#if defined(__ANDROID__) || defined(__linux__)
    int flags = async ? MS_ASYNC : MS_SYNC;
    int ret = ::msync(m_mappedAddress, m_size, flags);
    if (ret == 0) {
        m_isDirty = false;
        return true;
    }
    return false;
#else
    m_isDirty = false;
    return true;
#endif
}

} // namespace buffer
} // namespace opencut
} // namespace nextai

// ============================================================================
// JNI Exports Matching libbuffer.so Exactly
// ============================================================================

using namespace nextai::opencut::buffer;

extern "C" {

/**
 * @brief Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nCreate
 * Disassembly match: 0x0f5c..0x113c (480 bytes)
 *
 * Register allocation:
 *  x19: env
 *  x20: pathStr pointer
 *  x21: size / return address
 *  x22: fd
 *  x23: path jstring
 */
JNIEXPORT jlong JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nCreate(
    JNIEnv* env,
    jobject thiz,
    jstring path,
    jlong size
) {
    if (!env || !path) {
        return 0;
    }

    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    if (!pathStr) {
        return 0;
    }

#if defined(__ANDROID__) || defined(__linux__)
    // 0x0fa0: mov w1, #0x42; movk w1, #8, lsl #16; mov w2, #0x1b6
    // flags = O_RDWR | O_CREAT | O_CLOEXEC = 0x80042, mode = 0666
    int fd = ::open(pathStr, O_RDWR | O_CREAT | O_CLOEXEC, 0666);
    env->ReleaseStringUTFChars(path, pathStr);

    // 0x0fd0: tbnz w22, #0x1f, #0x1050 (if fd < 0)
    if (fd < 0) {
        throwIOExceptionWithErrno(env, errno);
        return 0;
    }

    // 0x0fd4: mov w2, #2; lseek(fd, 0, SEEK_END)
    off_t fileLen = ::lseek(fd, 0, SEEK_END);
    if (fileLen == static_cast<off_t>(-1)) {
        ::close(fd);
        throwIOExceptionWithErrno(env, errno);
        return 0;
    }

    // 0x0fec: cmp x0, #1; b.lt #0x1038; cmp x0, x21; b.eq #0x1038
    // If fileLen < 1 || fileLen == size -> proceed to ftruncate
    if (fileLen < 1 || fileLen == static_cast<off_t>(size)) {
        // 0x1038: ftruncate(fd, size)
        if (::ftruncate(fd, static_cast<off_t>(size)) != 0) {
            ::close(fd);
            throwIOExceptionWithErrno(env, errno);
            return 0;
        }

        // 0x10c0: mov w2, #3; mov w3, #1; mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)
        void* ptr = ::mmap(nullptr, static_cast<size_t>(size), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        ::close(fd); // Immediate close as in binary 0x10e4

        if (ptr == MAP_FAILED) {
            // 0x10f0: log and throw IOException("mmap failed, %s")
            char errBuf[256];
            std::snprintf(errBuf, sizeof(errBuf), ErrorStrings::MMAP_FAILED_FMT, "file");
#ifdef __ANDROID__
            __android_log_print(ANDROID_LOG_DEBUG, GECKOX_BUFFER_TAG, "%s", errBuf);
#endif
            throwIOException(env, errBuf);
            return 0;
        }

        return reinterpret_cast<jlong>(ptr);
    } else {
        // 0x0ffc: close(fd) and throw IOException("inconsistent file length")
        ::close(fd);
        throwIOException(env, ErrorStrings::INCONSISTENT_FILE_LENGTH);
        return 0;
    }
#else
    env->ReleaseStringUTFChars(path, pathStr);
    void* heapBuf = std::malloc(static_cast<size_t>(size));
    if (!heapBuf) {
        throwIOException(env, ErrorStrings::NATIVE_CALLOC_FAILED);
        return 0;
    }
    std::memset(heapBuf, 0, static_cast<size_t>(size));
    return reinterpret_cast<jlong>(heapBuf);
#endif
}

/**
 * @brief Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nWrite
 * Disassembly match: 0x113c..0x1198 (92 bytes)
 *
 * Direct invocation of GetByteArrayRegion at offset 0x640:
 *  (*env)->GetByteArrayRegion(env, array, start, len, (jbyte*)(nativePtr + offset))
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nWrite(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
) {
    if (!env || !nativePtr || !array) {
        return;
    }
    jbyte* dest = reinterpret_cast<jbyte*>(nativePtr + offset);
    env->GetByteArrayRegion(array, start, len, dest);
}

/**
 * @brief Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRelease
 * Disassembly match: 0x1198..0x11e4 (76 bytes)
 *
 * Calls munmap((void*)nativePtr, size)
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRelease(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong size
) {
    if (nativePtr) {
#if defined(__ANDROID__) || defined(__linux__)
        ::munmap(reinterpret_cast<void*>(nativePtr), static_cast<size_t>(size));
#else
        std::free(reinterpret_cast<void*>(nativePtr));
#endif
    }
}

/**
 * @brief Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRead
 * Disassembly match: 0x11e4..0x1240 (92 bytes)
 *
 * Direct invocation of SetByteArrayRegion at offset 0x680:
 *  (*env)->SetByteArrayRegion(env, array, start, len, (const jbyte*)(nativePtr + offset))
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRead(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
) {
    if (!env || !nativePtr || !array) {
        return;
    }
    const jbyte* src = reinterpret_cast<const jbyte*>(nativePtr + offset);
    env->SetByteArrayRegion(array, start, len, src);
}

/**
 * @brief Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nFlush
 * Disassembly match: 0x1240..0x12ec (172 bytes)
 *
 * Calls msync((void*)nativePtr, size, MS_SYNC=4).
 * If msync fails, throws IOException with strerror(errno).
 */
JNIEXPORT jint JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nFlush(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong size
) {
    if (!nativePtr) {
        return 0;
    }

#if defined(__ANDROID__) || defined(__linux__)
    // 0x1268: mov w2, #4 (MS_SYNC)
    int ret = ::msync(reinterpret_cast<void*>(nativePtr), static_cast<size_t>(size), MS_SYNC);
    if (ret != 0) {
        throwIOExceptionWithErrno(env, errno);
    }
    return ret;
#else
    return 0;
#endif
}

} // extern "C"
