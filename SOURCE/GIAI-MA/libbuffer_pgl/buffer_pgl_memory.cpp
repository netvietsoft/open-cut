/**
 * @file buffer_pgl_memory.cpp
 * @brief ByteDance Pangle / OpenVK GeckoX MemoryBuffer Native Implementation.
 *        Hiện thực mã nguồn C++ bộ đệm heap cho Pangle OpenVK GeckoX.
 */

#include "buffer_pgl_memory.h"
#include <cstdio>
#include <cstdlib>
#include <cerrno>

#if defined(__ANDROID__) || defined(__linux__)
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

namespace nextai {
namespace opencut {
namespace buffer_pgl {

long readFull(int fd, void* buf, long count) {
    return _Z8readFulliPal(fd, buf, count);
}

PglMemoryBufferEngine::PglMemoryBufferEngine()
    : m_buffer(nullptr), m_capacity(0), m_path("") {}

PglMemoryBufferEngine::PglMemoryBufferEngine(size_t capacity)
    : m_buffer(nullptr), m_capacity(0), m_path("") {
    allocate(capacity);
}

PglMemoryBufferEngine::~PglMemoryBufferEngine() {
    release();
}

bool PglMemoryBufferEngine::allocate(size_t size) {
    release();
    if (size == 0) return false;
    m_buffer = static_cast<uint8_t*>(std::calloc(1, size));
    if (!m_buffer) return false;
    m_capacity = size;
    return true;
}

bool PglMemoryBufferEngine::loadFromFile(const std::string& path, size_t requestedSize, std::string& outError) {
    release();
    if (static_cast<long>(requestedSize) < 0) {
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

    if (fileLen >= 1 && static_cast<size_t>(fileLen) != requestedSize) {
        outError = ErrorStrings::INCONSISTENT_FILE_LENGTH;
        ::close(fd);
        return false;
    }

    if (::ftruncate(fd, static_cast<off_t>(requestedSize)) != 0) {
        outError = std::strerror(errno);
        ::close(fd);
        return false;
    }

    if (::lseek(fd, 0, SEEK_SET) != 0) {
        outError = ErrorStrings::SEEK_FAILED;
        ::close(fd);
        return false;
    }

    uint8_t* mem = static_cast<uint8_t*>(std::calloc(1, requestedSize));
    if (!mem) {
        outError = ErrorStrings::NATIVE_CALLOC_FAILED;
        ::close(fd);
        return false;
    }

    if (fileLen > 0) {
        long readBytes = _Z8readFulliPal(fd, mem, fileLen);
        if (readBytes != fileLen) {
            std::free(mem);
            outError = ErrorStrings::READ_FULL_FAILED;
            ::close(fd);
            return false;
        }
    }

    if (::close(fd) != 0) {
        std::free(mem);
        outError = ErrorStrings::CLOSE_FAILED;
        return false;
    }

    m_buffer = mem;
    m_capacity = requestedSize;
    m_path = path;
    return true;
#else
    m_buffer = static_cast<uint8_t*>(std::calloc(1, requestedSize));
    if (!m_buffer) {
        outError = ErrorStrings::NATIVE_CALLOC_FAILED;
        return false;
    }
    m_capacity = requestedSize;
    m_path = path;
    return true;
#endif
}

bool PglMemoryBufferEngine::flushToFile(const std::string& path, size_t size, std::string& outError) {
    if (!isValid() || size > m_capacity) {
        outError = "Buffer invalid or size exceeds capacity";
        return false;
    }

#if defined(__ANDROID__) || defined(__linux__)
    int fd = ::open(path.c_str(), O_RDWR | O_CREAT | O_TRUNC | O_CLOEXEC, 0666);
    if (fd < 0) {
        outError = std::strerror(errno);
        return false;
    }

    ssize_t written = ::write(fd, m_buffer, size);
    int closeRet = ::close(fd);

    if (written != static_cast<ssize_t>(size)) {
        outError = std::strerror(errno);
        return false;
    }

    if (closeRet != 0) {
        outError = ErrorStrings::CLOSE_FILE_FAILED;
        return false;
    }

    return true;
#else
    return true;
#endif
}

void PglMemoryBufferEngine::release() {
    if (m_buffer) {
        std::free(m_buffer);
        m_buffer = nullptr;
    }
    m_capacity = 0;
    m_path.clear();
}

bool PglMemoryBufferEngine::write(size_t offset, const uint8_t* src, size_t length) {
    if (!isValid() || !src || (offset + length > m_capacity) || (offset + length < offset)) {
        return false;
    }
    std::memcpy(m_buffer + offset, src, length);
    return true;
}

bool PglMemoryBufferEngine::read(size_t offset, uint8_t* dst, size_t length) const {
    if (!isValid() || !dst || (offset + length > m_capacity) || (offset + length < offset)) {
        return false;
    }
    std::memcpy(dst, m_buffer + offset, length);
    return true;
}

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

using namespace nextai::opencut::buffer_pgl;

extern "C" {

long _Z8readFulliPal(int fd, void* buf, long count) {
    if (count <= 0 || !buf) return 0;
    long remaining = count;
    uint8_t* ptr = static_cast<uint8_t*>(buf);

    while (remaining > 0) {
#if defined(__ANDROID__) || defined(__linux__)
        ssize_t ret = ::read(fd, ptr, static_cast<size_t>(remaining));
        if (ret == -1) {
            if (errno == EINTR) continue;
            break;
        }
        if (ret == 0) break;
        remaining -= ret;
        ptr += ret;
#else
        break;
#endif
    }
    return count - remaining;
}

JNIEXPORT jlong JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nCreate(
    JNIEnv* env,
    jobject thiz,
    jstring path,
    jlong size
) {
    if (!env) return 0;
    if (size < 0) {
        throwIOException(env, ErrorStrings::LENGTH_ILLEGAL);
        return 0;
    }
    if (!path) return 0;

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

    if (fileLen >= 1 && fileLen != static_cast<off_t>(size)) {
        ::close(fd);
        throwIOException(env, ErrorStrings::INCONSISTENT_FILE_LENGTH);
        return 0;
    }

    if (::ftruncate(fd, static_cast<off_t>(size)) != 0) {
        ::close(fd);
        throwIOExceptionWithErrno(env, errno);
        return 0;
    }

    if (::lseek(fd, 0, SEEK_SET) != 0) {
        ::close(fd);
        throwIOException(env, ErrorStrings::SEEK_FAILED);
        return 0;
    }

    void* buf = std::calloc(1, static_cast<size_t>(size));
    if (!buf) {
        ::close(fd);
        throwIOException(env, ErrorStrings::NATIVE_CALLOC_FAILED);
        return 0;
    }

    if (fileLen > 0) {
        long readBytes = _Z8readFulliPal(fd, buf, fileLen);
        if (readBytes != fileLen) {
            ::close(fd);
            std::free(buf);
            throwIOException(env, ErrorStrings::READ_FULL_FAILED);
            return 0;
        }
    }

    int closeRet = ::close(fd);
    if (closeRet == -1) {
        std::free(buf);
        throwIOException(env, ErrorStrings::CLOSE_FAILED);
        return 0;
    }

    return reinterpret_cast<jlong>(buf);
#else
    env->ReleaseStringUTFChars(path, pathStr);
    void* buf = std::calloc(1, static_cast<size_t>(size));
    if (!buf) {
        throwIOException(env, ErrorStrings::NATIVE_CALLOC_FAILED);
        return 0;
    }
    return reinterpret_cast<jlong>(buf);
#endif
}

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nWrite(
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

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nRead(
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

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nRelease(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr
) {
    if (nativePtr) {
        std::free(reinterpret_cast<void*>(nativePtr));
    }
}

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nFlush(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jstring path,
    jlong size
) {
    if (!env || !nativePtr || !path) return;
    const char* pathStr = env->GetStringUTFChars(path, nullptr);
    if (!pathStr) return;

#if defined(__ANDROID__) || defined(__linux__)
    int fd = ::open(pathStr, O_RDWR | O_CREAT | O_TRUNC | O_CLOEXEC, 0666);
    env->ReleaseStringUTFChars(path, pathStr);

    if (fd < 0) {
        throwIOExceptionWithErrno(env, errno);
        return;
    }

    ssize_t written = ::write(fd, reinterpret_cast<const void*>(nativePtr), static_cast<size_t>(size));
    int closeRet = ::close(fd);

    if (written != static_cast<ssize_t>(size)) {
        throwIOExceptionWithErrno(env, errno);
        return;
    }

    if (closeRet == -1) {
        throwIOException(env, ErrorStrings::CLOSE_FILE_FAILED);
        return;
    }
#else
    env->ReleaseStringUTFChars(path, pathStr);
#endif
}

} // extern "C"
