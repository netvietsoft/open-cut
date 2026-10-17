/**
 * @file avmdlbase_ringbuffer.cpp
 * @brief ByteDance Mobile Download Base - Circular RingBuffer Implementations.
 *        Cài đặt chi tiết giải thuật bộ đệm vòng tròn luân chuyển dữ liệu media.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "avmdlbase_ringbuffer.h"
#include <cstring>
#include <algorithm>

namespace com {
namespace ss {
namespace ttmio {

MIORingBuffer::MIORingBuffer(size_t capacity)
    : mCapacity(capacity ? capacity : 1048576) {
    mBuffer.resize(mCapacity);
}

size_t MIORingBuffer::getAvailableData() const noexcept {
    std::lock_guard<std::mutex> lock(mMutex);
    return mCount;
}

size_t MIORingBuffer::getAvailableSpace() const noexcept {
    std::lock_guard<std::mutex> lock(mMutex);
    return mCapacity - mCount;
}

void MIORingBuffer::clear() noexcept {
    std::lock_guard<std::mutex> lock(mMutex);
    mReadPos = 0;
    mWritePos = 0;
    mCount = 0;
}

size_t MIORingBuffer::write(const uint8_t* data, size_t length) {
    if (!data || length == 0) return 0;
    std::lock_guard<std::mutex> lock(mMutex);

    size_t space = mCapacity - mCount;
    size_t toWrite = std::min(length, space);
    if (toWrite == 0) return 0;

    // First chunk up to end of buffer
    size_t chunk1 = std::min(toWrite, mCapacity - mWritePos);
    std::memcpy(mBuffer.data() + mWritePos, data, chunk1);

    // Second wrapped chunk at start of buffer
    size_t chunk2 = toWrite - chunk1;
    if (chunk2 > 0) {
        std::memcpy(mBuffer.data(), data + chunk1, chunk2);
    }

    mWritePos = (mWritePos + toWrite) % mCapacity;
    mCount += toWrite;
    return toWrite;
}

size_t MIORingBuffer::read(uint8_t* outBuf, size_t maxLen) {
    if (!outBuf || maxLen == 0) return 0;
    std::lock_guard<std::mutex> lock(mMutex);

    size_t toRead = std::min(maxLen, mCount);
    if (toRead == 0) return 0;

    size_t chunk1 = std::min(toRead, mCapacity - mReadPos);
    std::memcpy(outBuf, mBuffer.data() + mReadPos, chunk1);

    size_t chunk2 = toRead - chunk1;
    if (chunk2 > 0) {
        std::memcpy(outBuf + chunk1, mBuffer.data(), chunk2);
    }

    mReadPos = (mReadPos + toRead) % mCapacity;
    mCount -= toRead;
    return toRead;
}

/**
 * Opcode 0x050544 (524 bytes): _ZN3com2ss5ttmio13MIORingBuffer6readByEPNS1_13MIODataWriterE
 */
size_t MIORingBuffer::readBy(MIODataWriter* writer) {
    if (!writer) return 0;
    std::lock_guard<std::mutex> lock(mMutex);

    if (mCount == 0) return 0;

    size_t totalWritten = 0;
    size_t chunk1 = std::min(mCount, mCapacity - mReadPos);

    size_t w1 = writer->write(mBuffer.data() + mReadPos, chunk1);
    totalWritten += w1;
    mReadPos = (mReadPos + w1) % mCapacity;
    mCount -= w1;

    if (w1 == chunk1 && mCount > 0) {
        size_t chunk2 = std::min(mCount, mCapacity - mReadPos);
        size_t w2 = writer->write(mBuffer.data() + mReadPos, chunk2);
        totalWritten += w2;
        mReadPos = (mReadPos + w2) % mCapacity;
        mCount -= w2;
    }

    return totalWritten;
}

} // namespace ttmio
} // namespace ss
} // namespace com
