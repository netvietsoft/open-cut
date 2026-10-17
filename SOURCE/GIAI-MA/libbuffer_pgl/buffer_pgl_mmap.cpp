/**
 * @file buffer_pgl_mmap.cpp
 * @brief ByteDance Pangle / OpenVK GeckoX MMapBuffer Native Implementation.
 *        Hiện thực mã nguồn C++ bộ đệm mmap cho Pangle OpenVK GeckoX.
 */

#include "buffer_pgl_mmap.h"
#include <cstdio>
#include <cstdlib>
#include <cerrno>

#if !defined(__ANDROID__) && !defined(__linux__)
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
namespace buffer_pgl {

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

PglMMapBufferEngine::PglMMapBufferEngine()
    : m_mappedAddress(nullptr), m_size(0), m_filePath(""), m_isDirty(false) {}

PglMMapBufferEngine::PglMMapBufferEngine(const std::string& path, size_t size)
    : m_mappedAddress(nullptr), m_size(0), m_filePath(""), m_isDirty(false) {
    std::string err;
    openAndMap(path, size, err);
}

PglMMapBufferEngine::~PglMMapBufferEngine() {
    closeAndUnmap();
}

bool PglMMapBufferEngine::openAndMap(const std::string& path, size_t size, std::string& outError) {
    closeAndUnmap();
    if (size == 0) {
        outError = ErrorStrings::LENGTH_ILLEGAL;
        return false;
    }

#if defined(__ANDROID__) || defined(__linux__)
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

    if (fileLen >= 1 && static_cast<size_t>(fileLen) != size) {
        outError = ErrorStrings::INCONSISTENT_FILE_LENGTH;
        ::close(fd);
        return false;
    }

    if (::ftruncate(fd, static_cast<off_t>(size)) != 0) {
        outError = std::strerror(errno);
        ::close(fd);
        return false;
    }

    void* mapped = ::mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    ::close(fd);

    if (mapped == MAP_FAILED) {
        char buf[256];
        std::snprintf(buf, sizeof(buf), ErrorStrings::MMAP_FAILED_FMT, path.c_str());
        outError = buf;
#ifdef __ANDROID__
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_PGL_BUFFER_TAG, "%s", buf);
#endif
        return false;
    }

    m_mappedAddress = mapped;
    m_size = size;
    m_filePath = path;
    m_isDirty = false;
    return true;
#else
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

void PglMMapBufferEngine::closeAndUnmap() {
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

bool PglMMapBufferEngine::write(size_t offset, const uint8_t* src, size_t length) {
    if (!isValid() || !src || (offset + length > m_size) || (offset + length < offset)) {
        return false;
    }
    uint8_t* dst = static_cast<uint8_t*>(m_mappedAddress) + offset;
    std::memcpy(dst, src, length);
    m_isDirty = true;
    return true;
}

bool PglMMapBufferEngine::read(size_t offset, uint8_t* dst, size_t length) const {
    if (!isValid() || !dst || (offset + length > m_size) || (offset + length < offset)) {
        return false;
    }
    const uint8_t* src = static_cast<const uint8_t*>(m_mappedAddress) + offset;
    std::memcpy(dst, src, length);
    return true;
}

bool PglMMapBufferEngine::flush(bool async) {
    if (!isValid() || !m_isDirty) return true;
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

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

using namespace nextai::opencut::buffer_pgl;

extern "C" {

JNIEXPORT jlong JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nCreate(
    JNIEnv* env,
    jobject thiz,
    jstring path,
    jlong size
) {
    if (!env || !path) return 0;
    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    if (!pathStr) return 0;

#if defined(__ANDROID__) || defined(__linux__)
    int fd = ::open(pathStr, O_RDWR | O_CREAT | O_CLOEXEC, 0666);
    env->ReleaseStringUTFChars(path, pathStr);

    if (fd < 0) {
        throwIOExceptionWithErrno(env, errno);
        return 0;
    }

    off_t fileLen = ::lseek(fd, 0, SEEK_END);
    if (fileLen == static_cast<off_t>(-1)) {
        ::close(fd);
        throwIOExceptionWithErrno(env, errno);
        return 0;
    }

    if (fileLen < 1 || fileLen == static_cast<off_t>(size)) {
        if (::ftruncate(fd, static_cast<off_t>(size)) != 0) {
            ::close(fd);
            throwIOExceptionWithErrno(env, errno);
            return 0;
        }

        void* ptr = ::mmap(nullptr, static_cast<size_t>(size), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        ::close(fd);

        if (ptr == MAP_FAILED) {
            char errBuf[256];
            std::snprintf(errBuf, sizeof(errBuf), ErrorStrings::MMAP_FAILED_FMT, "file");
#ifdef __ANDROID__
            __android_log_print(ANDROID_LOG_DEBUG, GECKOX_PGL_BUFFER_TAG, "%s", errBuf);
#endif
            throwIOException(env, errBuf);
            return 0;
        }

        return reinterpret_cast<jlong>(ptr);
    } else {
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

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nWrite(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
) {
    if (!env || !nativePtr || !array) return;
    jbyte* dest = reinterpret_cast<jbyte*>(nativePtr + offset);
    env->GetByteArrayRegion(array, start, len, dest);
}

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nRead(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
) {
    if (!env || !nativePtr || !array) return;
    const jbyte* src = reinterpret_cast<const jbyte*>(nativePtr + offset);
    env->SetByteArrayRegion(array, start, len, src);
}

JNIEXPORT jint JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nFlush(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong size
) {
    if (!nativePtr) return 0;
#if defined(__ANDROID__) || defined(__linux__)
    int ret = ::msync(reinterpret_cast<void*>(nativePtr), static_cast<size_t>(size), MS_SYNC);
    if (ret != 0) {
        throwIOExceptionWithErrno(env, errno);
    }
    return ret;
#else
    return 0;
#endif
}

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nRelease(
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

} // extern "C"
