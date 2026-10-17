/**
 * @file avmdlbase_types.h
 * @brief ByteDance Mobile Download Base Engine (libavmdlbase.so) - ABI Types, Enums & Structs.
 *        Kiểu dữ liệu ABI, hằng số cấu hình mạng và cấu trúc ngữ cảnh của libavmdlbase.so.
 *
 * Reconstructed Cleanroom Implementation based on CapCut AArch64 binary analysis.
 * Tái dựng sạch dựa trên phân tích nhị phân AArch64 của CapCut.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary proof).
 */

#ifndef AVMDLBASE_TYPES_H
#define AVMDLBASE_TYPES_H

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <atomic>
#include <mutex>

namespace com {
namespace ss {

// ============================================================================
// 1. NAMESPACE: com::ss::ttm::medialoader (Media Loader Engine)
// ============================================================================
namespace ttm {
namespace medialoader {

/**
 * @brief Configuration keys for AVMDLIOManager
 *        Các khóa cấu hình tham số cho Media Loader IO Manager
 */
enum class AVMDLIOManagerKey : int32_t {
    KeyCacheDir               = 1,
    KeyMaxCacheSize           = 2,
    KeyPreloadParallelNum     = 3,
    KeyConnectTimeoutMs       = 4,
    KeyReadTimeoutMs          = 5,
    KeyEnableH2               = 6,
    KeyEnableQuic             = 7,
    KeySocketSendBufferSize   = 8,
    KeySocketRecvBufferSize   = 9,
    KeyRingBufferSize         = 10,
    KeyMaxRetryCount          = 11,
    KeyDownloadSpeedLimit     = 12,
    KeyStrategyCenterConfig   = 13
};

/**
 * @brief Information metadata describing a media download / preload task.
 *        Cấu trúc siêu dữ liệu mô tả tác vụ tải / nạp trước media.
 *        Khớp kích thước và layout C++ trong libavmdlbase.so (0x02e44c, 0x02e708).
 */
struct AVMDLIOTaskInfo {
    std::string rawUrl;             /**< URL gốc của tệp đa phương tiện */
    std::string fileKey;            /**< Khóa nhận diện duy nhất của file cache */
    std::string localFilePath;      /**< Đường dẫn lưu trữ cục bộ */
    int64_t     offset = 0;         /**< Vị trí bắt đầu tải trong tệp (bytes) */
    int64_t     size = -1;          /**< Số byte cần tải (-1 là toàn bộ tệp) */
    int64_t     totalFileSize = 0;  /**< Tổng dung lượng tệp từ Content-Length */
    int64_t     downloadedBytes = 0;/**< Số byte đã nạp thành công */
    int32_t     priority = 0;       /**< Mức độ ưu tiên nạp trước */
    int32_t     taskState = 0;      /**< Trạng thái tác vụ (0: Init, 1: Running, 2: Done, 3: Error) */
    std::string mimeType;           /**< Định dạng MIME (video/mp4, audio/aac...) */
    std::map<std::string, std::string> customHeaders; /**< Tiêu đề HTTP tùy biến */

    AVMDLIOTaskInfo() = default;
    AVMDLIOTaskInfo(const AVMDLIOTaskInfo&) = default;
    AVMDLIOTaskInfo& operator=(const AVMDLIOTaskInfo&) = default;
};

/**
 * @brief Task listener callback interface
 *        Giao diện lắng nghe sự kiện tiến trình của tác vụ
 *        Vtable offset: 0x072c50 (kích thước 40 bytes)
 */
class AVMDLIOTaskListener {
public:
    virtual ~AVMDLIOTaskListener() = default;
    virtual void onTaskProgress(const AVMDLIOTaskInfo& info, int64_t currentBytes, int64_t totalBytes) = 0;
    virtual void onTaskCompleted(const AVMDLIOTaskInfo& info) = 0;
    virtual void onTaskFailed(const AVMDLIOTaskInfo& info, int32_t errorCode, const std::string& errorMsg) = 0;
};

/**
 * @brief Strategy Center listener for adaptive bandwidth regulation
 *        Giao diện trung tâm chiến lược điều phối băng thông tải media
 *        Vtable offset: 0x072cc0 (kích thước 72 bytes)
 */
class AVMDLStrategyCenterListener {
public:
    virtual ~AVMDLStrategyCenterListener() = default;
    virtual void onBandwidthSample(int64_t bytesTransferred, int64_t durationMs) = 0;
    virtual int32_t recommendPreloadSize(int64_t estimatedBitrate) = 0;
    virtual bool shouldPreloadNext(int64_t currentBufferMs) = 0;
};

/**
 * @brief Media Loader IO Task representation
 *        Vtable offset: 0x072bb8 (kích thước 136 bytes)
 */
class AVMDLIOTask {
public:
    virtual ~AVMDLIOTask() = default;
    virtual bool start() = 0;
    virtual void cancel() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual AVMDLIOTaskInfo getInfo() const = 0;
};

/**
 * @brief Media Loader IO Manager Pure Virtual Interface
 *        Giao diện điều phối IO Manager cốt lõi của libavmdlbase.so
 *        Vtable offset: 0x072b10 (152 bytes = 19 slots hàm ảo)
 */
class AVMDLIOManager {
public:
    virtual ~AVMDLIOManager() = default;

    virtual void notifyTaskInfo(AVMDLIOManagerKey key,
                               AVMDLIOTask* task,
                               AVMDLIOTaskInfo& info,
                               std::map<std::string, std::string>* extraMap,
                               int64_t paramLong,
                               char* paramChar) = 0;

    virtual std::string rewriteUri(const char* originUri, const char* fileKey) = 0;
    virtual int32_t convertToIOTaskInfo(const char* jsonStr, AVMDLIOTaskInfo** outInfo) = 0;
    virtual int32_t addTask(AVMDLIOTaskInfo& info, AVMDLIOTask* task) = 0;
    virtual int32_t removeTask(AVMDLIOTask* task) = 0;
    virtual AVMDLIOTask* getTask(AVMDLIOTaskInfo& info) = 0;
    virtual AVMDLIOTask* getPostTask(AVMDLIOTaskInfo& info) = 0;
    virtual int32_t releaseTask(AVMDLIOTask** task) = 0;
    virtual int64_t getInt64Value(AVMDLIOManagerKey key, const char* strKey, int64_t defaultValue) = 0;
    virtual int32_t getInfo(AVMDLIOManagerKey key, char* outBuf) = 0;
    virtual void setInt64Value(AVMDLIOManagerKey key, char* strKey, int64_t value) = 0;
    virtual void setStrategyCenter(AVMDLStrategyCenterListener* listener) = 0;
    virtual int32_t createAndStarPreloadTask(AVMDLIOTaskInfo& info, AVMDLIOTaskListener* listener) = 0;
    virtual int64_t getInt64ValueByStrStrInt(AVMDLIOManagerKey key, const char* k1, const char* k2, int64_t defVal) = 0;
    virtual int32_t prepareForIOTask(AVMDLIOTaskInfo& info) = 0;
};

/**
 * @brief Download context structure
 *        Ngữ cảnh điều khiển tác vụ tải dữ liệu
 */
struct AVMDLDownloadContext {
    uint32_t status = 0;
    int64_t  startTimeMs = 0;
    int64_t  endTimeMs = 0;
    int64_t  bytesRead = 0;

    void reset() noexcept {
        status = 0;
        startTimeMs = 0;
        endTimeMs = 0;
        bytesRead = 0;
    }
};

} // namespace medialoader
} // namespace ttm

// ============================================================================
// 2. NAMESPACE: com::ss::ttmio (TT Media IO Network Subsystem)
// ============================================================================
namespace ttmio {

/**
 * @brief Media IO Category
 *        Phân loại tác vụ mạng của Media IO
 */
enum class MIOCategory : int32_t {
    VideoPlay    = 1, /**< Phát video thời gian thực (Ưu tiên cao nhất) */
    VideoPreload = 2, /**< Nạp trước video trong luồng cuộn Feed */
    AudioStream  = 3, /**< Luồng âm thanh nhạc nền / Voiceover */
    ImageCover   = 4, /**< Nạp ảnh bìa và thumbnail */
    ModelWeight  = 5  /**< Tải trọng số mô hình trí tuệ nhân tạo AI */
};

/**
 * @brief Protocol types supported by TT Media IO
 *        Các giao thức mạng được hỗ trợ
 */
enum class MIOProtocolType : int32_t {
    HTTP_1_1 = 1,
    HTTP_2   = 2,
    HTTP_3_QUIC = 3
};

/**
 * @brief MIO Network Configuration parameters
 *        Thông số cấu hình mạng cho kết nối MIO
 */
struct MIOConfig {
    std::string host;
    int32_t     port = 443;
    bool        useTLS = true;
    bool        useQuic = false;
    int32_t     connectTimeoutMs = 5000;
    int32_t     readTimeoutMs = 10000;
    int32_t     socketSendBuf = 65536;
    int32_t     socketRecvBuf = 262144; // 256 KB
    std::string sniHost;
    std::vector<std::string> alpnProtocols = {"h2", "http/1.1"};
};

/**
 * @brief Common Configuration with printing capabilities
 *        Vtable offset: 0x076178 (kích thước 344 bytes)
 */
class MIOCommonConfig {
public:
    virtual ~MIOCommonConfig() = default;
    virtual std::string printConfig(std::string prefix) const;

    int32_t maxConcurrentConnections = 32;
    int32_t idleTimeoutSec = 60;
    int32_t retryLimit = 3;
    bool    enableTlsSessionReuse = true;
};

/**
 * @brief Parsed HTTP response information
 *        Thông tin phản hồi HTTP đã được phân tích cú pháp
 */
struct MIOHttpResponseInfo {
    int32_t     statusCode = 0;
    int64_t     contentLength = -1;
    int64_t     rangeStart = -1;
    int64_t     rangeEnd = -1;
    int64_t     rangeTotal = -1;
    bool        isChunked = false;
    bool        isPartialContent = false;
    std::string contentType;
    std::string server;
    std::string traceId;
    std::map<std::string, std::string> headers;
};

/**
 * @brief Property of a PlayTask
 *        Thuộc tính của tác vụ phát video streaming
 */
struct MIOPlayTaskProp {
    std::string url;
    std::string fileHash;
    int64_t     startOffset = 0;
    int64_t     preloadLength = 1048576; // 1 MB
    bool        isLiveStream = false;
};

/**
 * @brief Base connection listener
 *        Vtable offset: 0x075508 (16 bytes)
 */
class MIOConnListener {
public:
    virtual ~MIOConnListener() = default;
    virtual void onConnected() = 0;
    virtual void onDataReceived(const uint8_t* data, size_t length) = 0;
    virtual void onDisconnected(int32_t reason) = 0;
};

/**
 * @brief Abstract Data Writer interface for RingBuffer integration
 *        Giao diện ghi dữ liệu từ RingBuffer ra ngoài
 */
class MIODataWriter {
public:
    virtual ~MIODataWriter() = default;
    virtual size_t write(const uint8_t* data, size_t len) = 0;
};

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // AVMDLBASE_TYPES_H
