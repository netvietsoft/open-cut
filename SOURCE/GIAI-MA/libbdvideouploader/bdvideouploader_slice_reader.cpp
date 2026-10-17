/**
 * @file bdvideouploader_slice_reader.cpp
 * @brief ByteDance Video Uploader - Slice Partitioning & Data Reader Implementations.
 *        Cài đặt chi tiết bộ đọc dữ liệu và giải thuật phân rã phân đoạn lát cắt.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "bdvideouploader_slice_reader.h"
#include <algorithm>
#include <cstring>

namespace com {
namespace ss {
namespace bduploader {

// ----------------------------------------------------------------------------
// BDFileReaderMemory Implementation
// ----------------------------------------------------------------------------
BDFileReaderMemory::BDFileReaderMemory(const uint8_t* data, size_t size)
    : mSize(static_cast<int64_t>(size)) {
    if (data && size > 0) {
        mBuffer.assign(data, data + size);
    }
}

BDFileReaderMemory::~BDFileReaderMemory() {
    close();
}

int64_t BDFileReaderMemory::getSize() const {
    std::lock_guard<std::mutex> lock(mMutex);
    return mSize;
}

int64_t BDFileReaderMemory::readSliceByOffsetAdv(int64_t offset, uint8_t* outBuf, size_t readSize) {
    if (!outBuf || readSize == 0 || offset < 0) {
        return -1;
    }

    std::lock_guard<std::mutex> lock(mMutex);
    if (offset >= mSize) {
        return 0; // EOF reached
    }

    size_t available = static_cast<size_t>(mSize - offset);
    size_t toCopy = std::min(readSize, available);
    std::memcpy(outBuf, mBuffer.data() + offset, toCopy);
    return static_cast<int64_t>(toCopy);
}

void BDFileReaderMemory::close() {
    std::lock_guard<std::mutex> lock(mMutex);
    mBuffer.clear();
    mBuffer.shrink_to_fit();
    mSize = 0;
}

// ----------------------------------------------------------------------------
// BDFileReaderExtern Implementation
// ----------------------------------------------------------------------------
BDFileReaderExtern::BDFileReaderExtern(int64_t totalSize, ExternalReadCallback callback)
    : mTotalSize(totalSize), mCallback(std::move(callback)), mIsClosed(false) {}

BDFileReaderExtern::~BDFileReaderExtern() {
    close();
}

int64_t BDFileReaderExtern::getSize() const {
    return mTotalSize;
}

int64_t BDFileReaderExtern::readSliceByOffsetAdv(int64_t offset, uint8_t* outBuf, size_t readSize) {
    if (!outBuf || readSize == 0 || offset < 0) {
        return -1;
    }

    std::lock_guard<std::mutex> lock(mMutex);
    if (mIsClosed || !mCallback) {
        return -1;
    }

    if (offset >= mTotalSize) {
        return 0; // EOF
    }

    return mCallback(offset, outBuf, readSize);
}

void BDFileReaderExtern::close() {
    std::lock_guard<std::mutex> lock(mMutex);
    mIsClosed = true;
    mCallback = nullptr;
}

// ----------------------------------------------------------------------------
// BDSliceManager Implementation & CRC32
// ----------------------------------------------------------------------------
BDSliceManager::BDSliceManager(int64_t fileSize, size_t sliceSize)
    : mFileSize(std::max<int64_t>(0, fileSize)),
      mSliceSize(sliceSize > 0 ? sliceSize : BD_DEFAULT_SLICE_SIZE),
      mTotalSlices(0) {
    if (mFileSize == 0) {
        mTotalSlices = 1;
        mSlices.emplace_back(0, 0, 0);
    } else {
        mTotalSlices = static_cast<int32_t>((mFileSize + mSliceSize - 1) / mSliceSize);
        mSlices.reserve(mTotalSlices);
        for (int32_t i = 0; i < mTotalSlices; ++i) {
            int64_t off = static_cast<int64_t>(i) * static_cast<int64_t>(mSliceSize);
            size_t sz = static_cast<size_t>(std::min<int64_t>(mSliceSize, mFileSize - off));
            mSlices.emplace_back(i, off, sz);
        }
    }
}

int32_t BDSliceManager::getTotalSlices() const {
    return mTotalSlices;
}

size_t BDSliceManager::getSliceSize() const {
    return mSliceSize;
}

int64_t BDSliceManager::getFileSize() const {
    return mFileSize;
}

BDSliceInfo BDSliceManager::getSliceInfo(int32_t index) const {
    std::lock_guard<std::mutex> lock(mMutex);
    if (index >= 0 && index < static_cast<int32_t>(mSlices.size())) {
        return mSlices[index];
    }
    return BDSliceInfo(-1, 0, 0);
}

bool BDSliceManager::markSliceCompleted(int32_t index, const std::string& etag, uint32_t crc32) {
    std::lock_guard<std::mutex> lock(mMutex);
    if (index >= 0 && index < static_cast<int32_t>(mSlices.size())) {
        mSlices[index].isUploaded = true;
        mSlices[index].etag = etag;
        mSlices[index].crc32 = crc32;
        return true;
    }
    return false;
}

bool BDSliceManager::isAllCompleted() const {
    std::lock_guard<std::mutex> lock(mMutex);
    for (const auto& s : mSlices) {
        if (!s.isUploaded) return false;
    }
    return true;
}

int64_t BDSliceManager::getUploadedBytes() const {
    std::lock_guard<std::mutex> lock(mMutex);
    int64_t sum = 0;
    for (const auto& s : mSlices) {
        if (s.isUploaded) {
            sum += static_cast<int64_t>(s.size);
        }
    }
    return sum;
}

// Standard IEEE 802.3 CRC32 implementation
uint32_t BDSliceManager::calculateCRC32(const uint8_t* data, size_t len) {
    if (!data || len == 0) return 0;

    static const uint32_t crc32_table[16] = {
        0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
        0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
        0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
        0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
    };

    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < len; ++i) {
        uint8_t byte = data[i];
        crc = (crc >> 4) ^ crc32_table[(crc ^ (byte & 0x0F)) & 0x0F];
        crc = (crc >> 4) ^ crc32_table[(crc ^ (byte >> 4)) & 0x0F];
    }
    return ~crc;
}

} // namespace bduploader
} // namespace ss
} // namespace com
