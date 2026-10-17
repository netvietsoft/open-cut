/**
 * @file avmdlbase_ringbuffer.h
 * @brief ByteDance Mobile Download Base - Circular RingBuffer Streaming Cache.
 *        Bộ đệm vòng tròn luân chuyển dữ liệu video streaming trong libavmdlbase.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef AVMDLBASE_RINGBUFFER_H
#define AVMDLBASE_RINGBUFFER_H

#include "avmdlbase_types.h"
#include <vector>
#include <mutex>
#include <cstdint>
#include <cstddef>

namespace com {
namespace ss {
namespace ttmio {

/**
 * @brief MIORingBuffer: Thread-safe circular buffer for high-throughput media streams.
 *        Bộ đệm vòng tròn an toàn đa luồng khớp nhị phân offset 0x050544 (524 bytes).
 */
class MIORingBuffer {
public:
    explicit MIORingBuffer(size_t capacity = 1048576); // Default 1 MB
    ~MIORingBuffer() = default;

    /**
     * @brief Writes data into circular ring buffer.
     *        Ghi dữ liệu vào bộ đệm vòng tròn.
     */
    size_t write(const uint8_t* data, size_t length);

    /**
     * @brief Reads data out of circular ring buffer into destination array.
     *        Đọc dữ liệu ra mảng đích.
     */
    size_t read(uint8_t* outBuf, size_t maxLen);

    /**
     * @brief Reads data directly into MIODataWriter without intermediate copies.
     *        Hàm đọc trực tiếp qua DataWriter khớp opcode 0x050544 (524 bytes).
     */
    size_t readBy(MIODataWriter* writer);

    /**
     * @brief Returns currently available readable bytes.
     *        Số lượng byte hiện có sẵn để đọc.
     */
    size_t getAvailableData() const noexcept;

    /**
     * @brief Returns currently available writable space.
     *        Dung lượng còn trống để ghi tiếp.
     */
    size_t getAvailableSpace() const noexcept;

    /**
     * @brief Clears and resets read/write pointers.
     *        Xóa sạch bộ đệm và tái lập vị trí đọc/ghi.
     */
    void clear() noexcept;

private:
    std::vector<uint8_t> mBuffer;
    size_t               mCapacity;
    size_t               mReadPos = 0;
    size_t               mWritePos = 0;
    size_t               mCount = 0;
    mutable std::mutex   mMutex;
};

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // AVMDLBASE_RINGBUFFER_H
