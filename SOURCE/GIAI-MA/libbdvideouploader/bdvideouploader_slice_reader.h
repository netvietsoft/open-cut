/**
 * @file bdvideouploader_slice_reader.h
 * @brief ByteDance Video Uploader - Slice Partitioning & Data Reader Subsystem.
 *        Phân hệ phân mảnh lát cắt và đọc dữ liệu tệp tin đa tầng.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDVIDEOUPLOADER_SLICE_READER_H
#define BDVIDEOUPLOADER_SLICE_READER_H

#include "bdvideouploader_types.h"
#include <vector>
#include <string>
#include <memory>
#include <mutex>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief Abstract Data Reader Interface
 *        Giao diện trừu tượng nguồn đọc dữ liệu
 */
class IBDFileReader {
public:
    virtual ~IBDFileReader() = default;
    virtual int64_t getSize() const = 0;
    virtual int64_t readSliceByOffsetAdv(int64_t offset, uint8_t* outBuf, size_t readSize) = 0;
    virtual void close() = 0;
};

/**
 * @brief In-Memory Buffer Data Reader (BDFileReaderMemory)
 *        Bộ đọc dữ liệu từ vùng đệm RAM
 */
class BDFileReaderMemory : public IBDFileReader {
public:
    BDFileReaderMemory(const uint8_t* data, size_t size);
    ~BDFileReaderMemory() override;

    int64_t getSize() const override;
    int64_t readSliceByOffsetAdv(int64_t offset, uint8_t* outBuf, size_t readSize) override;
    void close() override;

private:
    std::vector<uint8_t> mBuffer;
    int64_t mSize;
    mutable std::mutex mMutex;
};

/**
 * @brief External Streaming / File Data Reader (BDFileReaderExtern)
 *        Bộ đọc dữ liệu từ tệp tin hoặc luồng ngoài
 */
class BDFileReaderExtern : public IBDFileReader {
public:
    using ExternalReadCallback = std::function<int64_t(int64_t offset, uint8_t* buf, size_t len)>;

    BDFileReaderExtern(int64_t totalSize, ExternalReadCallback callback);
    ~BDFileReaderExtern() override;

    int64_t getSize() const override;
    int64_t readSliceByOffsetAdv(int64_t offset, uint8_t* outBuf, size_t readSize) override;
    void close() override;

private:
    int64_t mTotalSize;
    ExternalReadCallback mCallback;
    mutable std::mutex mMutex;
    bool mIsClosed;
};

/**
 * @brief Slice Manager & Geometry Calculator
 *        Bộ điều phối phân bổ các lát cắt và kiểm tra tính toán hình học
 */
class BDSliceManager {
public:
    BDSliceManager(int64_t fileSize, size_t sliceSize);

    int32_t getTotalSlices() const;
    size_t getSliceSize() const;
    int64_t getFileSize() const;

    BDSliceInfo getSliceInfo(int32_t index) const;
    bool markSliceCompleted(int32_t index, const std::string& etag, uint32_t crc32);
    bool isAllCompleted() const;
    int64_t getUploadedBytes() const;

    static uint32_t calculateCRC32(const uint8_t* data, size_t len);

private:
    int64_t mFileSize;
    size_t  mSliceSize;
    int32_t mTotalSlices;
    std::vector<BDSliceInfo> mSlices;
    mutable std::mutex mMutex;
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_SLICE_READER_H
