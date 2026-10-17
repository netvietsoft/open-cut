/**
 * @file buffer_pgl_mremap.cpp
 * @brief ByteDance Pangle / OpenVK GeckoX MReMapBuffer Native Implementation.
 *        Hiện thực mã nguồn C++ tái ánh xạ mremap cho Pangle OpenVK GeckoX.
 */

#include "buffer_pgl_mremap.h"
#include <cstdlib>
#include <cerrno>

namespace nextai {
namespace opencut {
namespace buffer_pgl {

PglMReMapBufferEngine::PglMReMapBufferEngine()
    : m_address(nullptr), m_size(0) {}

PglMReMapBufferEngine::PglMReMapBufferEngine(void* initialAddress, size_t initialSize)
    : m_address(initialAddress), m_size(initialSize) {}

PglMReMapBufferEngine::~PglMReMapBufferEngine() {
    release();
}

bool PglMReMapBufferEngine::resize(size_t newSize, std::string& outError) {
    if (newSize == 0) {
        outError = ErrorStrings::LENGTH_ILLEGAL;
        return false;
    }
    if (!m_address || m_address == MAP_FAILED) {
        outError = "Invalid base address for mremap";
        return false;
    }

#if defined(__ANDROID__) || defined(__linux__)
    void* newAddr = ::mremap(m_address, m_size, newSize, MREMAP_MAYMOVE);
    if (newAddr == MAP_FAILED) {
        outError = ErrorStrings::MREMAP_FAILED;
#ifdef __ANDROID__
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_PGL_BUFFER_TAG, "%s", ErrorStrings::MREMAP_FAILED);
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

void PglMReMapBufferEngine::release() {
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

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

using namespace nextai::opencut::buffer_pgl;

extern "C" {

JNIEXPORT jlong JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MReMapBuffer_nMReMap(
    JNIEnv* env,
    jobject thiz,
    jlong oldAddress,
    jlong oldSize,
    jlong newSize
) {
    if (!env) return 0;

#if defined(__ANDROID__) || defined(__linux__)
    void* newAddr = ::mremap(
        reinterpret_cast<void*>(oldAddress),
        static_cast<size_t>(oldSize),
        static_cast<size_t>(newSize),
        MREMAP_MAYMOVE
    );

    if (newAddr == MAP_FAILED) {
#ifdef __ANDROID__
        __android_log_print(ANDROID_LOG_DEBUG, GECKOX_PGL_BUFFER_TAG, "%s", ErrorStrings::MREMAP_FAILED);
#endif
        throwIOException(env, ErrorStrings::MREMAP_FAILED);
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
