/**
 * @file buffer_pgl_mremap.h
 * @brief ByteDance Pangle / OpenVK GeckoX MReMapBuffer Native Header.
 *        Hiện thực bộ đệm tái ánh xạ mremap cho Pangle OpenVK GeckoX.
 *
 * Target: libbuffer_pgl.so (ARM64-v8a).
 */

#ifndef GECKOX_BUFFER_PGL_MREMAP_H
#define GECKOX_BUFFER_PGL_MREMAP_H

#include "buffer_pgl_types.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MReMapBuffer_nMReMap(
    JNIEnv* env,
    jobject thiz,
    jlong oldAddress,
    jlong oldSize,
    jlong newSize
);

#ifdef __cplusplus
}
#endif

namespace nextai {
namespace opencut {
namespace buffer_pgl {

class PglMReMapBufferEngine {
public:
    PglMReMapBufferEngine();
    explicit PglMReMapBufferEngine(void* initialAddress, size_t initialSize);
    ~PglMReMapBufferEngine();

    bool resize(size_t newSize, std::string& outError);
    uintptr_t getAddress() const { return reinterpret_cast<uintptr_t>(m_address); }
    size_t getSize() const { return m_size; }
    bool isValid() const { return m_address != nullptr && m_address != MAP_FAILED; }
    void release();

private:
    void* m_address;
    size_t m_size;
};

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_PGL_MREMAP_H
