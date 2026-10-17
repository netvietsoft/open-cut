/**
 * @file bdvideouploader_disk_resume.cpp
 * @brief ByteDance Video Uploader - Interrupted Upload Disk Resume Implementations.
 *        Cài đặt chi tiết bộ tuần tự hóa bản ghi phục hồi tải lên bị ngắt quãng.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "bdvideouploader_disk_resume.h"
#include <fstream>
#include <chrono>
#include <cstring>

namespace com {
namespace ss {
namespace bduploader {

BDDiskResume::BDDiskResume(const std::string& resumeDir)
    : mResumeDir(resumeDir) {}

void BDDiskResume::setResumeDirectory(const std::string& dir) {
    std::lock_guard<std::mutex> lock(mMutex);
    mResumeDir = dir;
}

std::string BDDiskResume::getRecordFilePath(const std::string& fileKey) const {
    std::string prefix = mResumeDir.empty() ? "" : (mResumeDir + "/");
    return prefix + "bd_resume_" + fileKey + ".bin";
}

bool BDDiskResume::saveCheckpoint(
    const std::string& fileKey,
    const std::string& fileHash,
    int64_t fileSize,
    int64_t uploadedBytes,
    int32_t totalSlices,
    int32_t completedSlices,
    const std::vector<uint8_t>& completedBitmask
) {
    if (fileKey.empty()) return false;

    BDDiskResumeRecord record;
    record.magic = BD_DISK_RESUME_MAGIC; // 0x4244524D "BDRM"
    record.version = 1;
    std::memset(record.fileHash, 0, sizeof(record.fileHash));
    std::strncpy(record.fileHash, fileHash.c_str(), sizeof(record.fileHash) - 1);
    record.fileSize = fileSize;
    record.uploadedBytes = uploadedBytes;
    record.totalSlices = totalSlices;
    record.completedSlices = completedSlices;
    record.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();

    std::string path = getRecordFilePath(fileKey);
    std::lock_guard<std::mutex> lock(mMutex);
    std::ofstream ofs(path, std::ios::binary | std::ios::trunc);
    if (!ofs.is_open()) return false;

    ofs.write(reinterpret_cast<const char*>(&record), sizeof(record));
    uint32_t bitmaskSize = static_cast<uint32_t>(completedBitmask.size());
    ofs.write(reinterpret_cast<const char*>(&bitmaskSize), sizeof(bitmaskSize));
    if (bitmaskSize > 0) {
        ofs.write(reinterpret_cast<const char*>(completedBitmask.data()), bitmaskSize);
    }
    return ofs.good();
}

bool BDDiskResume::loadCheckpoint(
    const std::string& fileKey,
    const std::string& expectedFileHash,
    int64_t expectedFileSize,
    BDDiskResumeRecord& outRecord,
    std::vector<uint8_t>& outCompletedBitmask
) {
    if (fileKey.empty()) return false;

    std::string path = getRecordFilePath(fileKey);
    std::lock_guard<std::mutex> lock(mMutex);
    std::ifstream ifs(path, std::ios::binary);
    if (!ifs.is_open()) return false;

    ifs.read(reinterpret_cast<char*>(&outRecord), sizeof(outRecord));
    if (!ifs.good()) return false;

    // Validate Magic: 0x4244524D
    if (outRecord.magic != BD_DISK_RESUME_MAGIC) {
        return false;
    }

    // Validate File Consistency (Hash & Size)
    if (!expectedFileHash.empty() && std::strncmp(outRecord.fileHash, expectedFileHash.c_str(), sizeof(outRecord.fileHash)) != 0) {
        return false;
    }
    if (expectedFileSize > 0 && outRecord.fileSize != expectedFileSize) {
        return false;
    }

    uint32_t bitmaskSize = 0;
    ifs.read(reinterpret_cast<char*>(&bitmaskSize), sizeof(bitmaskSize));
    if (bitmaskSize > 0 && bitmaskSize < 1048576) { // Safety cap 1MB
        outCompletedBitmask.resize(bitmaskSize);
        ifs.read(reinterpret_cast<char*>(outCompletedBitmask.data()), bitmaskSize);
    }

    return true;
}

bool BDDiskResume::clearCheckpoint(const std::string& fileKey) {
    if (fileKey.empty()) return false;
    std::string path = getRecordFilePath(fileKey);
    std::lock_guard<std::mutex> lock(mMutex);
    return (std::remove(path.c_str()) == 0);
}

} // namespace bduploader
} // namespace ss
} // namespace com
