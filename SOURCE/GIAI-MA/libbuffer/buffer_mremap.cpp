/**
 * @file buffer_mremap.cpp
 * @brief ByteDance GeckoX MReMapBuffer Native Implementation.
 *        Hiện thực mã nguồn C++ tái ánh xạ mremap của ByteDance GeckoX.
 *
 * Cleanroom reverse-engineered from libbuffer.so (ARM64-v8a).
 * Exact opcode match for function:
 *  - MReMapBuffer_nMReMap @ 0x18f0..0x19a8 (184 bytes)
 */

#include "buffer_mremap.h"
#include <cstdlib>
#include <cerrno>

namespace nextai {
namespace opencut {
namespace buffer {

// ============================================================================
// MReMapBufferEngine Implementation
// ============================================================================

MReMapBufferEngine::MReMapBufferEngine()
    : m_address(nullptr), m_size(0) {}

MReMapBufferEngine::MReMapBufferEngine(void* initialAddress, size_t initialSize)
    : m_address(initialAddress), m_size(initialSize) {}

MReMapBufferEngine::~MReMapBufferEngine() {
    release();
}

MReMapBufferEngine::MReMapBufferEngine(MReMapBufferEngine&& other) noexcept
    : m_address(other.m_address), m_size(other.m_size) {
    other.m_address = nullptr;
    other.m_size = 0;
}

MReMapBufferEngine& MReMapBufferEngine::operator=(MReMapBufferEngine&& other) noexcept {
    if (this != &other) {
        release();
        m_address = other.m_address;
        m_size = other.m_size;
        other.m_address = nullptr;
        other.m_size = 0;
    }
    return *this;
}

bool MReMapBufferEngine::resize(size_t newSize, std::string& outError) {
    if (newSize == 0) {
        outError = ErrorStrings::LENGTH_ILLEGAL;
        return false;
    }

    if (!m_address || m_address == MAP_FAILED) {
        outError = "Invalid base address for mremap";
        return false;
    }

#if defined(__ANDROID__) || defined(__linux__)
    // Invoke POSIX mremap with MREMAP_MAYMOVE = 1 (flag 0x1)
    void* newAddr = ::mremap(m_address, m_size, newSize, MREMAP_MAYMOVE);
    if (newAddr == MAP_FAILED) {
        outError = ErrorStrings::MREMAP_FAILED;
#ifdef __ANDROID__
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_BUFFER_TAG, "%s", ErrorStrings::MREMAP_FAILED);
#endif
        return false;
    }
    m_address = newAddr;
    m_size = newSize;
    return true;
#else
    void* newAddr = std::realloc(m_address, newSize);
    if (!newAddr) {
        outError = ErrorStrings::MREMAP_FAILED;
        return false;
    }
    m_address = newAddr;
    m_size = newSize;
    return true;
#endif
}

void MReMapBufferEngine::release() {
    if (m_address && m_address != MAP_FAILED) {
#if defined(__ANDROID__) || defined(__linux__)
        ::munmap(m_address, m_size);
#else
        std::free(m_address);
#endif
        m_address = nullptr;
    }
    m_size = 0;
}

} // namespace buffer
} // namespace opencut
} // namespace nextai

// ============================================================================
// JNI Export Matching libbuffer.so Exactly
// ============================================================================

using namespace nextai::opencut::buffer;

extern "C" {

/**
 * @brief Java_com_bytedance_geckox_buffer_impl_MReMapBuffer_nMReMap
 * Disassembly match: 0x18f0..0x19a8 (184 bytes)
 *
 * Register allocation:
 *  x0: oldAddress -> mremap
 *  x1: oldSize    -> mremap
 *  x2: newSize    -> mremap
 *  w3: #1 (MREMAP_MAYMOVE)
 *  x19: env
 *  x20: error string pointer ("mremap failed")
 *  x21: thread pointer / canary
 */
JNIEXPORT jlong JNICALL Java_com_bytedance_geckox_buffer_impl_MReMapBuffer_nMReMap(
    JNIEnv* env,
    jobject thiz,
    jlong oldAddress,
    jlong oldSize,
    jlong newSize
) {
    if (!env) {
        return 0;
    }

#if defined(__ANDROID__) || defined(__linux__)
    // 0x1914: mov w3, #1 (MREMAP_MAYMOVE)
    // 0x1924: bl #0xe40 (CALL mremap)
    void* newAddr = ::mremap(
        reinterpret_cast<void*>(oldAddress),
        static_cast<size_t>(oldSize),
        static_cast<size_t>(newSize),
        MREMAP_MAYMOVE
    );

    // 0x1928: cmn x0, #1 (compare with MAP_FAILED == -1)
    if (newAddr == MAP_FAILED) {
        // 0x1940: mov w0, #3 (ANDROID_LOG_DEBUG)
        // 0x1948: bl #0xeb0 (CALL __android_log_print(3, "Buffer", "mremap failed"))
#ifdef __ANDROID__
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_BUFFER_TAG, "%s", ErrorStrings::MREMAP_FAILED);
#endif
        // 0x195c: FindClass("java/io/IOException")
        // 0x1974: ThrowNew(env, IOException, "mremap failed")
        throwIOException(env, ErrorStrings::MREMAP_FAILED);
        // 0x197c: mov w0, wzr (return 0)
        return 0;
    }

    return reinterpret_cast<jlong>(newAddr);
#else
    void* newAddr = std::realloc(reinterpret_cast<void*>(oldAddress), static_cast<size_t>(newSize));
    if (!newAddr) {
        throwIOException(env, ErrorStrings::MREMAP_FAILED);
        return 0;
    }
    return reinterpret_cast<jlong>(newAddr);
#endif
}

} // extern "C"
