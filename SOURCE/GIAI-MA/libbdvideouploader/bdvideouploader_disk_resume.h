/**
 * @file bdvideouploader_disk_resume.h
 * @brief ByteDance Video Uploader - Interrupted Upload Disk Resume Subsystem.
 *        Phân hệ lưu vết và phục hồi điểm truyền gián đoạn trên ổ đĩa.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDVIDEOUPLOADER_DISK_RESUME_H
#define BDVIDEOUPLOADER_DISK_RESUME_H

#include "bdvideouploader_types.h"
#include <string>
#include <vector>
#include <mutex>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief Disk Resume Record Serializer & Recovery Engine
 *        Bộ tuần tự hóa và phục hồi tiến trình tải lên từ bộ nhớ đĩa
 */
class BDDiskResume {
public:
    BDDiskResume(const std::string& resumeDir = "");

    void setResumeDirectory(const std::string& dir);

    /**
     * @brief Save progress checkpoint to binary record
     *        Lưu điểm kiểm tra tiến độ vào bản ghi nhị phân (Magic 0x4244524D)
     */
    bool saveCheckpoint(
        const std::string& fileKey,
        const std::string& fileHash,
        int64_t fileSize,
        int64_t uploadedBytes,
        int32_t totalSlices,
        int32_t completedSlices,
        const std::vector<uint8_t>& completedBitmask
    );

    /**
     * @brief Load and validate resume record
     *        Đọc và xác thực tính hợp lệ của bản ghi tiếp tục
     */
    bool loadCheckpoint(
        const std::string& fileKey,
        const std::string& expectedFileHash,
        int64_t expectedFileSize,
        BDDiskResumeRecord& outRecord,
        std::vector<uint8_t>& outCompletedBitmask
    );

    /**
     * @brief Clear checkpoint when upload succeeds
     *        Xóa bỏ bản ghi tiếp tục khi quá trình tải lên hoàn tất
     */
    bool clearCheckpoint(const std::string& fileKey);

private:
    std::string getRecordFilePath(const std::string& fileKey) const;

    std::string mResumeDir;
    mutable std::mutex mMutex;
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_DISK_RESUME_H
