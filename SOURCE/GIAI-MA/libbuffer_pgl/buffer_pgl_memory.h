/**
 * @file buffer_pgl_memory.h
 * @brief ByteDance Pangle / OpenVK GeckoX MemoryBuffer Native Header.
 *        Hiện thực bộ đệm heap cho Pangle OpenVK GeckoX.
 *
 * Target: libbuffer_pgl.so (ARM64-v8a).
 */

#ifndef GECKOX_BUFFER_PGL_MEMORY_H
#define GECKOX_BUFFER_PGL_MEMORY_H

#include "buffer_pgl_types.h"

#ifdef __cplusplus
extern "C" {
#endif

long _Z8readFulliPal(int fd, void* buf, long count);

JNIEXPORT jlong JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nCreate(
    JNIEnv* env,
    jobject thiz,
    jstring path,
    jlong size
);

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nWrite(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
);

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nRead(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
);

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nRelease(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr
);

JNIEXPORT void JNICALL Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nFlush(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jstring path,
    jlong size
);

#ifdef __cplusplus
}
#endif

namespace nextai {
namespace opencut {
namespace buffer_pgl {

class PglMemoryBufferEngine {
public:
    PglMemoryBufferEngine();
    explicit PglMemoryBufferEngine(size_t capacity);
    ~PglMemoryBufferEngine();

    bool allocate(size_t size);
    bool loadFromFile(const std::string& path, size_t requestedSize, std::string& outError);
    bool flushToFile(const std::string& path, size_t size, std::string& outError);
    void release();

    bool write(size_t offset, const uint8_t* src, size_t length);
    bool read(size_t offset, uint8_t* dst, size_t length) const;

    uintptr_t getAddress() const { return reinterpret_cast<uintptr_t>(m_buffer); }
    size_t getCapacity() const { return m_capacity; }
    bool isValid() const { return m_buffer != nullptr; }

private:
    uint8_t* m_buffer;
    size_t m_capacity;
    std::string m_path;
};

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_PGL_MEMORY_H
