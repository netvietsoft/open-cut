/**
 * @file buffer_pgl_mmap.h
 * @brief ByteDance Pangle / OpenVK GeckoX MMapBuffer Native Header.
 *        Hiện thực bộ đệm mmap cho Pangle OpenVK GeckoX.
 *
 * Target: libbuffer_pgl.so (ARM64-v8a).
 */

#ifndef GECKOX_BUFFER_PGL_MMAP_H
#define GECKOX_BUFFER_PGL_MMAP_H

#include "buffer_pgl_types.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nCreate(
    JNIEnv* env,
    jobject thiz,
    jstring path,
    jlong size
);

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nWrite(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
);

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nRead(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
);

JNIEXPORT jint JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nFlush(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong size
);

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nRelease(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong size
);

#ifdef __cplusplus
}
#endif

namespace nextai {
namespace opencut {
namespace buffer_pgl {

class PglMMapBufferEngine {
public:
    PglMMapBufferEngine();
    explicit PglMMapBufferEngine(const std::string& path, size_t size);
    ~PglMMapBufferEngine();

    bool openAndMap(const std::string& path, size_t size, std::string& outError);
    void closeAndUnmap();

    bool write(size_t offset, const uint8_t* src, size_t length);
    bool read(size_t offset, uint8_t* dst, size_t length) const;
    bool flush(bool async = false);

    uintptr_t getAddress() const { return reinterpret_cast<uintptr_t>(m_mappedAddress); }
    size_t getSize() const { return m_size; }
    bool isValid() const { return m_mappedAddress != nullptr && m_mappedAddress != MAP_FAILED; }

private:
    void* m_mappedAddress;
    size_t m_size;
    std::string m_filePath;
    mutable std::atomic<bool> m_isDirty;
};

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_PGL_MMAP_H
