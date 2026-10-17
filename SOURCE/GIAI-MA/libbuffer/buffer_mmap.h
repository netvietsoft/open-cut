/**
 * @file buffer_mmap.h
 * @brief ByteDance GeckoX MMapBuffer Native Implementation Header.
 *        Hiện thực bộ đệm ánh xạ tệp mmap hiệu năng cao ByteDance GeckoX.
 *
 * Target: libbuffer.so (ARM64-v8a).
 * Matches functions:
 *  - Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nCreate (0x0f5c, 480B)
 *  - Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nWrite  (0x113c, 92B)
 *  - Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRelease(0x1198, 76B)
 *  - Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRead   (0x11e4, 92B)
 *  - Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nFlush  (0x1240, 172B)
 */

#ifndef GECKOX_BUFFER_MMAP_H
#define GECKOX_BUFFER_MMAP_H

#include "buffer_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Native factory creating mmap-backed file buffer
 *        Hàm native khởi tạo bộ đệm ánh xạ mmap từ đường dẫn tệp
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MMapBuffer instance / Đối tượng Java MMapBuffer
 * @param path File path string / Chuỗi đường dẫn tệp
 * @param size Target capacity in bytes / Kích thước mong đợi theo byte
 * @return Mapped virtual address (or 0 on failure) / Địa chỉ ảo được map (hoặc 0 nếu lỗi)
 */
JNIEXPORT jlong JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nCreate(
    JNIEnv* env,
    jobject thiz,
    jstring path,
    jlong size
);

/**
 * @brief Write bytes from Java byte[] array into mmap buffer
 *        Ghi mảng byte từ tầng Java vào bộ đệm mmap nguyên sinh
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MMapBuffer instance / Đối tượng Java MMapBuffer
 * @param nativePtr Base virtual address of mmap / Địa chỉ ảo gốc của mmap
 * @param offset Byte offset within mmap buffer / Độ dời byte trong mmap buffer
 * @param array Source Java byte array / Mảng byte nguồn Java
 * @param start Start offset in Java byte array / Vị trí bắt đầu trong mảng Java
 * @param len Number of bytes to transfer / Số lượng byte cần sao chép
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nWrite(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
);

/**
 * @brief Read bytes from mmap buffer into Java byte[] array
 *        Đọc dữ liệu từ bộ đệm mmap nguyên sinh vào mảng byte Java
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MMapBuffer instance / Đối tượng Java MMapBuffer
 * @param nativePtr Base virtual address of mmap / Địa chỉ ảo gốc của mmap
 * @param offset Byte offset within mmap buffer / Độ dời byte trong mmap buffer
 * @param array Destination Java byte array / Mảng byte đích Java
 * @param start Start offset in Java byte array / Vị trí bắt đầu trong mảng Java
 * @param len Number of bytes to transfer / Số lượng byte cần sao chép
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRead(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
);

/**
 * @brief Synchronize dirty mmap pages to disk storage (msync)
 *        Đồng bộ các trang bộ nhớ dirty của mmap xuống đĩa cứng vật lý
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MMapBuffer instance / Đối tượng Java MMapBuffer
 * @param nativePtr Base virtual address of mmap / Địa chỉ ảo gốc của mmap
 * @param size Buffer capacity in bytes / Kích thước bộ đệm theo byte
 * @return 0 on success, or -1 on failure / 0 nếu thành công, -1 nếu thất bại
 */
JNIEXPORT jint JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nFlush(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong size
);

/**
 * @brief Unmap and release virtual memory mapping (munmap)
 *        Hủy ánh xạ và giải phóng bộ nhớ ảo của mmap
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MMapBuffer instance / Đối tượng Java MMapBuffer
 * @param nativePtr Base virtual address of mmap / Địa chỉ ảo gốc của mmap
 * @param size Buffer capacity in bytes / Kích thước bộ đệm theo byte
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRelease(
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
namespace buffer {

/**
 * @brief C++ RAII Wrapper for GeckoX MMap Buffer
 *        Lớp bọc C++ RAII quản lý vòng đời bộ đệm mmap của GeckoX
 */
class MMapBufferEngine {
public:
    MMapBufferEngine();
    explicit MMapBufferEngine(const std::string& path, size_t size);
    ~MMapBufferEngine();

    // Non-copyable, movable
    MMapBufferEngine(const MMapBufferEngine&) = delete;
    MMapBufferEngine& operator=(const MMapBufferEngine&) = delete;
    MMapBufferEngine(MMapBufferEngine&& other) noexcept;
    MMapBufferEngine& operator=(MMapBufferEngine&& other) noexcept;

    bool openAndMap(const std::string& path, size_t size, std::string& outError);
    void closeAndUnmap();

    bool write(size_t offset, const uint8_t* src, size_t length);
    bool read(size_t offset, uint8_t* dst, size_t length) const;
    bool flush(bool async = false);

    uintptr_t getAddress() const { return reinterpret_cast<uintptr_t>(m_mappedAddress); }
    size_t getSize() const { return m_size; }
    const std::string& getPath() const { return m_filePath; }
    bool isValid() const { return m_mappedAddress != nullptr && m_mappedAddress != MAP_FAILED; }

    static size_t getSystemPageSize();
    static uintptr_t alignToPage(uintptr_t addr);

private:
    void* m_mappedAddress;
    size_t m_size;
    std::string m_filePath;
    mutable std::atomic<bool> m_isDirty;
};

} // namespace buffer
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_MMAP_H
