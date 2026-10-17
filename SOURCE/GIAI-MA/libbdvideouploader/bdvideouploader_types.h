/**
 * @file bdvideouploader_types.h
 * @brief ByteDance Video Uploader - Core ABI Definitions, Data Structures & Parameters.
 *        Định nghĩa giao diện nhị phân ABI, cấu trúc dữ liệu và tham số của libbdvideouploader.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary proof).
 */

#ifndef BDVIDEOUPLOADER_TYPES_H
#define BDVIDEOUPLOADER_TYPES_H

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <mutex>
#include <functional>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief Binary Magic Constants & Limits
 *        Các hằng số nhị phân và giới hạn hệ thống
 */
constexpr uint32_t BD_DISK_RESUME_MAGIC = 0x4244524D; // "BDRM" (ByteDance Resume Magic)
constexpr uint32_t BD_DEFAULT_SLICE_SIZE = 524288;     // 512 KB per slice
constexpr uint32_t BD_MAX_SLICE_SIZE     = 10485760;   // 10 MB maximum slice
constexpr int32_t  BD_DEFAULT_RETRY_COUNT = 3;         // 3 retry attempts
constexpr int32_t  BD_DEFAULT_TIMEOUT_MS  = 30000;     // 30 seconds connection timeout
constexpr int32_t  BD_MAX_CONCURRENT_TASKS = 16;       // 16 parallel upload tasks

/**
 * @brief Upload Protocol Modes
 *        Các chế độ giao thức truyền tải tải lên
 */
enum class BDUploadProtocol : int32_t {
    HTTP_1_1 = 0,    // Standard HTTP/1.1
    HTTP_2   = 1,    // HTTP/2 multiplexing
    QUIC     = 2,    // Cronet / xQUIC RFC 9000
    AUTO     = 3     // Auto fallback (HTTP/2 -> QUIC)
};

/**
 * @brief Parameter Keys for _setIntValue and _getIntValue (0x0125a8)
 *        Mã khóa tham số cho phương thức _setIntValue
 */
enum class BDUploaderIntKey : int32_t {
    SLICE_SIZE             = 1,
    SOCKET_TIMEOUT_MS      = 2,
    CONNECT_TIMEOUT_MS     = 3,
    MAX_RETRY_COUNT        = 4,
    ENABLE_HTTPS           = 5,
    ENABLE_QUIC            = 6,
    UPLOAD_MODE            = 7,
    PROCESS_TYPE           = 8,
    ENABLE_DISK_RESUME     = 9,
    TCP_OPEN_TIMEOUT_MS    = 10,
    TRAN_TIMEOUT_MS        = 11,
    ROUTER_TYPE            = 12,
    HEADER_X_STORAGE_MODE  = 13,
    IS_USE_EXTERN_NET      = 14,
    SCENES_TAG             = 15
};

/**
 * @brief Parameter Keys for _setStringValue and _getStringValue (0x011ff4)
 *        Mã khóa chuỗi tham số cho phương thức _setStringValue
 */
enum class BDUploaderStrKey : int32_t {
    VIDEO_HOST             = 5,
    AUTH_KEY               = 16,
    SESSION_TOKEN          = 75,
    ACCESS_KEY_ID          = 85,
    SECRET_ACCESS_KEY      = 301,
    TRACE_ID               = 453,
    FILE_PATH              = 454,
    DISK_RESUME_DIR        = 455,
    DNS_CUSTOM_SERVERS     = 456,
    SCENES_TAG_STRING      = 457
};

/**
 * @brief Upload Task State Machine
 *        Máy trạng thái chu trình tải lên
 */
enum class BDUploadState : int32_t {
    IDLE       = 0,
    PREPARING  = 1,
    UPLOADING  = 2,
    PAUSED     = 3,
    COMPLETED  = 4,
    FAILED     = 5,
    CANCELED   = 6
};

/**
 * @brief Slice Range & Checksum Tracking
 *        Thông tin phân đoạn lát cắt tải lên
 */
struct BDSliceInfo {
    int32_t  sliceIndex;
    int64_t  offset;
    size_t   size;
    bool     isUploaded;
    uint32_t crc32;
    std::string etag;

    BDSliceInfo()
        : sliceIndex(0), offset(0), size(0), isUploaded(false), crc32(0) {}
    BDSliceInfo(int32_t idx, int64_t off, size_t sz)
        : sliceIndex(idx), offset(off), size(sz), isUploaded(false), crc32(0) {}
};

/**
 * @brief Disk Resume Record Structure (Magic 0x4244524D)
 *        Bản ghi lưu trữ trên đĩa để tiếp tục tải lên khi bị gián đoạn
 */
struct BDDiskResumeRecord {
    uint32_t magic;          // BD_DISK_RESUME_MAGIC (0x4244524D)
    int32_t  version;        // Resume record format version (1)
    char     fileHash[64];   // SHA-256 hash of original file
    int64_t  fileSize;       // Total size of original file
    int64_t  uploadedBytes;  // Successfully transferred bytes
    int32_t  totalSlices;    // Total slices count
    int32_t  completedSlices;// Count of uploaded slices
    int64_t  timestamp;      // Last update epoch millisecond
};

/**
 * @brief Network Speed Probe Metric
 *        Chỉ số đo kiểm tốc độ mạng
 */
struct BDNetworkSpeedMetric {
    std::string host;
    int64_t     rttMs;
    int64_t     throughputBps;
    float       weight;
    bool        isExpired;
    int64_t     createTime;
};

/**
 * @brief AWS / TOS Authentication Credentials
 *        Thông tin chứng thực AWS S3 / ByteDance TOS
 */
struct BDAuthCredentials {
    std::string accessKeyId;
    std::string secretAccessKey;
    std::string sessionToken;
    std::string region;
    std::string service;
    std::string authKey;
};

/**
 * @brief Task Callback Listener Interface
 *        Giao diện hàm gọi lại thông báo tiến trình và kết quả
 */
class IBDUploadListener {
public:
    virtual ~IBDUploadListener() = default;
    virtual void onProgress(int64_t uploadedBytes, int64_t totalBytes) = 0;
    virtual void onSliceComplete(int32_t sliceIndex, const std::string& etag) = 0;
    virtual void onComplete(const std::string& fileKey, const std::string& extra) = 0;
    virtual void onError(int32_t errorCode, const std::string& errorMsg) = 0;
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_TYPES_H
