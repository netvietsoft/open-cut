/**
 * @file buffer_memory.h
 * @brief ByteDance GeckoX MemoryBuffer Native Implementation Header.
 *        Hiện thực bộ đệm vùng nhớ RAM heap của ByteDance GeckoX.
 *
 * Target: libbuffer.so (ARM64-v8a).
 * Matches functions:
 *  - readFull               @ 0x15f4 (172 bytes, _Z8readFulliPal)
 *  - MemoryBuffer_nCreate   @ 0x12ec (776 bytes)
 *  - MemoryBuffer_nWrite    @ 0x16a0 (92 bytes)
 *  - MemoryBuffer_nRead     @ 0x16fc (92 bytes)
 *  - MemoryBuffer_nRelease  @ 0x1758 (72 bytes)
 *  - MemoryBuffer_nFlush    @ 0x17a0 (336 bytes)
 */

#ifndef GECKOX_BUFFER_MEMORY_H
#define GECKOX_BUFFER_MEMORY_H

#include "buffer_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Fully read count bytes into buffer, handling EINTR signals and chunked reads
 *        Đọc toàn bộ số byte count vào bộ đệm, xử lý tín hiệu ngắt EINTR và đọc phân đoạn
 *
 * Exported symbol: _Z8readFulliPal
 * Opcode match: 0x15f4..0x16a0 (172 bytes)
 *
 * @param fd File descriptor to read from / File descriptor cần đọc
 * @param buf Destination buffer / Con trỏ vùng nhớ đích
 * @param count Requested byte count / Số byte mong muốn đọc
 * @return Bytes actually read / Số lượng byte thực tế đã đọc
 */
long _Z8readFulliPal(int fd, void* buf, long count);

/**
 * @brief Native factory allocating heap memory buffer and reading backing file contents
 *        Hàm native cấp phát bộ nhớ heap và đọc toàn bộ nội dung tệp sao lưu
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MemoryBuffer instance / Đối tượng Java MemoryBuffer
 * @param path Backing file path / Đường dẫn tập tin sao lưu
 * @param size Target buffer size / Kích thước bộ đệm mong muốn
 * @return Heap pointer address (or 0 on error) / Địa chỉ vùng nhớ heap (hoặc 0 nếu lỗi)
 */
JNIEXPORT jlong JNICALL Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nCreate(
    JNIEnv* env,
    jobject thiz,
    jstring path,
    jlong size
);

/**
 * @brief Copy bytes from Java byte[] array into heap memory buffer
 *        Sao chép mảng byte từ Java vào vùng nhớ heap nguyên sinh
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MemoryBuffer instance / Đối tượng Java MemoryBuffer
 * @param nativePtr Base heap address / Địa chỉ vùng nhớ heap gốc
 * @param offset Byte offset in heap buffer / Độ dời byte trong bộ đệm heap
 * @param array Source Java byte array / Mảng byte nguồn Java
 * @param start Start offset in Java array / Vị trí bắt đầu trong mảng Java
 * @param len Number of bytes to copy / Số byte cần sao chép
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nWrite(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
);

/**
 * @brief Copy bytes from heap memory buffer into Java byte[] array
 *        Sao chép dữ liệu từ vùng nhớ heap nguyên sinh vào mảng byte Java
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MemoryBuffer instance / Đối tượng Java MemoryBuffer
 * @param nativePtr Base heap address / Địa chỉ vùng nhớ heap gốc
 * @param offset Byte offset in heap buffer / Độ dời byte trong bộ đệm heap
 * @param array Destination Java byte array / Mảng byte đích Java
 * @param start Start offset in Java array / Vị trí bắt đầu trong mảng Java
 * @param len Number of bytes to copy / Số byte cần sao chép
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nRead(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr,
    jlong offset,
    jbyteArray array,
    jint start,
    jint len
);

/**
 * @brief Release heap memory buffer (calls free)
 *        Giải phóng vùng nhớ heap nguyên sinh (gọi free)
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MemoryBuffer instance / Đối tượng Java MemoryBuffer
 * @param nativePtr Base heap address to free / Địa chỉ vùng nhớ heap cần giải phóng
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nRelease(
    JNIEnv* env,
    jobject thiz,
    jlong nativePtr
);

/**
 * @brief Flush heap memory buffer contents to backing file (atomic write + close)
 *        Ghi xả nội dung từ vùng nhớ heap ra tập tin sao lưu trên đĩa (ghi nguyên tử + đóng tệp)
 *
 * @param env JNI environment pointer / Con trỏ môi trường JNI
 * @param thiz Java MemoryBuffer instance / Đối tượng Java MemoryBuffer
 * @param nativePtr Base heap address / Địa chỉ vùng nhớ heap
 * @param path Destination file path / Đường dẫn tập tin đích
 * @param size Number of bytes to write / Số byte cần ghi ra tệp
 */
JNIEXPORT void JNICALL Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nFlush(
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
namespace buffer {

/**
 * @brief C++ RAII Wrapper for GeckoX Memory Buffer
 *        Lớp bọc C++ RAII quản lý bộ đệm heap của GeckoX
 */
class MemoryBufferEngine {
public:
    MemoryBufferEngine();
    explicit MemoryBufferEngine(size_t capacity);
    ~MemoryBufferEngine();

    // Movable, non-copyable
    MemoryBufferEngine(const MemoryBufferEngine&) = delete;
    MemoryBufferEngine& operator=(const MemoryBufferEngine&) = delete;
    MemoryBufferEngine(MemoryBufferEngine&& other) noexcept;
    MemoryBufferEngine& operator=(MemoryBufferEngine&& other) noexcept;

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

} // namespace buffer
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_MEMORY_H
