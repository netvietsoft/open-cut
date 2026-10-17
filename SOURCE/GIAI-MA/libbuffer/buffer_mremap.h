/**
 * @file buffer_mremap.h
 * @brief ByteDance GeckoX MReMapBuffer Native Implementation Header.
 *        Hiện thực bộ đệm tái ánh xạ mremap động của ByteDance GeckoX.
 *
 * Target: libbuffer.so (ARM64-v8a).
 * Matches function:
 *  - Java_com_bytedance_geckox_buffer_impl_MReMapBuffer_nMReMap @ 0x18f0 (184 bytes)
 */

#ifndef GECKOX_BUFFER_MREMAP_H
#define GECKOX_BUFFER_MREMAP_H

#include "buffer_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Native method to expand or shrink memory-mapped region using mremap(2)
 *        Hàm native mở rộng hoặc thu nhỏ vùng nhớ mmap sử dụng lệnh hệ thống mremap
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MReMapBuffer instance / Đối tượng Java MReMapBuffer
 * @param oldAddress Previous base virtual address / Địa chỉ ảo cũ của vùng nhớ
 * @param oldSize Previous buffer size in bytes / Kích thước cũ theo byte
 * @param newSize Requested new buffer size in bytes / Kích thước mới theo byte
 * @return New base virtual address (or 0 on failure) / Địa chỉ ảo mới (hoặc 0 nếu lỗi)
 */
JNIEXPORT jlong JNICALL Java_com_bytedance_geckox_buffer_impl_MReMapBuffer_nMReMap(
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
namespace buffer {

/**
 * @brief Dynamic MReMap Engine with virtual page realignment
 *        Động cơ tái ánh xạ mremap động với căn chỉnh trang bộ nhớ ảo
 */
class MReMapBufferEngine {
public:
    MReMapBufferEngine();
    explicit MReMapBufferEngine(void* initialAddress, size_t initialSize);
    ~MReMapBufferEngine();

    // Movable, non-copyable
    MReMapBufferEngine(const MReMapBufferEngine&) = delete;
    MReMapBufferEngine& operator=(const MReMapBufferEngine&) = delete;
    MReMapBufferEngine(MReMapBufferEngine&& other) noexcept;
    MReMapBufferEngine& operator=(MReMapBufferEngine&& other) noexcept;

    /**
     * @brief Resize buffer via mremap(MREMAP_MAYMOVE)
     *        Thay đổi kích thước bộ đệm thông qua lệnh mremap với cờ MREMAP_MAYMOVE
     */
    bool resize(size_t newSize, std::string& outError);

    uintptr_t getAddress() const { return reinterpret_cast<uintptr_t>(m_address); }
    size_t getSize() const { return m_size; }
    bool isValid() const { return m_address != nullptr && m_address != MAP_FAILED; }

    void release();

private:
    void* m_address;
    size_t m_size;
};

} // namespace buffer
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_MREMAP_H
