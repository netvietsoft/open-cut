/**
 * @file mdlttkmedianetloader_types.h
 * @brief Core ABI Structures, Constants, and External VCN/AVMDL/TTKMediaNet Interfaces for libmdlttkmedianetloader.so
 *        Các cấu trúc ABI cốt lõi, Hằng số và Giao diện ngoại vi VCN/AVMDL/TTKMediaNet cho libmdlttkmedianetloader.so
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - File size / Dung lượng: 83,560 bytes (20 ELF64 sections)
 * - Build Info / Thông tin Build: "Apr 10 2025" "05:13:12" ("2.1.227.25") @ 0x010f78..0x010f95
 * - Source Files / Tệp mã nguồn gốc:
 *   1. MDLTTKMediaNetDetectDownloader.cpp
 *   2. MDLTTKMediaNetDownloader.cpp
 *   3. MDLTTKMediaNetDownloaderFactory.cpp (@ 0x010bc6)
 *   4. MDLTTKMediaNetStrategy.cpp (@ 0x010dee)
 *   5. MDLTTKMediaNetJniBase.cpp (@ 0x010f25)
 * - Exported Symbol / Ký hiệu xuất (.dynsym[124]):
 *   - JNI_OnLoad (0x01008c, size 512 bytes)
 */

#ifndef NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_TYPES_H_
#define NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_TYPES_H_

#include <atomic>
#include <cstdint>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

namespace TTKMediaNet {

/**
 * @brief Preconnect parameter block passed to TTKMediaNetMgr::Preconnect (0x0061f8..0x0062cb)
 *        Khối tham số kết nối trước (Preconnect) truyền vào TTKMediaNetMgr::Preconnect (0x0061f8..0x0062cb)
 *
 * Stack Layout in executeQuicPreconnect (sp + 0x08, 56 bytes):
 * - +0x00: std::string host (24 bytes)
 * - +0x18: int32_t protocol_type (1 = QUIC, movi v0.2s, #1 @ 0x00626c)
 * - +0x1c: int32_t enable_flag (1)
 * - +0x20: std::string ip (24 bytes)
 * - +0x38: int32_t reserved (0)
 */
struct TTKMediaNetPreconnectParam {
    std::string host;           // +0x00 (24B)
    int32_t protocol_type{1};   // +0x18 (4B)
    int32_t enable_flag{1};     // +0x1c (4B)
    std::string ip;             // +0x20 (24B)
    int32_t reserved{0};        // +0x38 (4B)
};

/**
 * @brief HTTP response header and status container passed to TTKMediaNetTask::Delegate::OnResponse (0x007820)
 *        Cấu trúc chứa mã trạng thái và tiêu đề phản hồi HTTP truyền vào TTKMediaNetTask::Delegate::OnResponse (0x007820)
 *
 * Binary Layout:
 * - +0x00: int32_t status_code (ldr w8, [x1] @ 0x007840)
 * - +0x08..0x20: status_line / metadata
 * - +0x28: std::map<std::string, std::string> headers (red-black tree begin @ +0x28, end sentinel @ +0x30)
 */
struct TTKMediaNetResponseInfo {
    int32_t status_code{0};
    int32_t http_version{0};
    uint64_t reserved_08{0};
    uint64_t reserved_10{0};
    std::map<std::string, std::string> headers;
};

/**
 * @brief Request parameter structure passed to TTKMediaNetMgr::CreateAndStartTask (0x0095e8..0x0096ec)
 *        Cấu trúc tham số yêu cầu truyền vào TTKMediaNetMgr::CreateAndStartTask (0x0095e8..0x0096ec)
 *
 * Stack Layout in sendHttpRequest (sp + 0x130, size 0xa8 = 168 bytes):
 * - +0x00 (sp+0x130): int32_t is_quic (1 if mReqProtoType == 2, else 0 @ 0x00962c..0x009634)
 * - +0x08 (sp+0x138): int64_t range_start (mHttpContext->mRangeStart @ 0x009638)
 * - +0x10 (sp+0x140): int64_t range_end (mHttpContext->mRangeEnd or -1 @ 0x009640)
 * - +0x18 (sp+0x148): int64_t reserved_neg1 (-1)
 * - +0x20 (sp+0x150): int32_t flags (0)
 * - +0x24 (sp+0x154): int32_t open_timeout_ms (mOpenTimeoutSec * 1000 @ 0x00965c)
 * - +0x28 (sp+0x158): int32_t rw_timeout_ms (mRwTimeoutSec * 1000 @ 0x009668)
 * - +0x2c (sp+0x15c): int32_t total_timeout_ms (mRwTimeoutSec * 1000 @ 0x00966c)
 * - +0x30 (sp+0x160): std::string lower_proto_str (from this + 0x100 @ 0x009674)
 * - +0x48 (sp+0x178): std::string url (from current request URL @ 0x009694)
 * - +0x60 (sp+0x190): std::string ip_list (comma-joined IP list @ 0x0096a0)
 * - +0x78 (sp+0x1a8): int32_t priority (-1 @ 0x0095fc)
 * - +0x80 (sp+0x1b0): std::string method ("GET" @ 0x0096b4)
 * - +0x98 (sp+0x1c8): std::map<std::string, std::string> custom_headers (copied @ 0x0096c8)
 */
struct TTKMediaNetRequestParam {
    int32_t is_quic{0};                                  // +0x00
    int32_t padding_04{0};                               // +0x04
    int64_t range_start{-1};                             // +0x08
    int64_t range_end{-1};                               // +0x10
    int64_t reserved_18{-1};                             // +0x18
    int32_t flags{0};                                    // +0x20
    int32_t open_timeout_ms{5000};                       // +0x24
    int32_t rw_timeout_ms{5000};                         // +0x28
    int32_t total_timeout_ms{5000};                      // +0x2c
    std::string lower_proto_str;                         // +0x30
    std::string url;                                     // +0x48
    std::string ip_list;                                 // +0x60
    int32_t priority{-1};                                // +0x78
    int32_t padding_7c{0};                               // +0x7c
    std::string method{"GET"};                           // +0x80
    std::map<std::string, std::string> custom_headers;   // +0x98
};

/**
 * @brief Delegate interface for TTKMediaNetTask callbacks (RTTI @ 0x010531, vtable in MDLTTKMediaNetDownloader @ 0x016fa0)
 *        Giao diện Delegate cho các callback của TTKMediaNetTask (RTTI @ 0x010531, vtable tại 0x016fa0)
 */
class TTKMediaNetTask {
public:
    class Delegate {
    public:
        virtual ~Delegate() = default;
        virtual void OnResponse(const TTKMediaNetResponseInfo* response) = 0;
        virtual void OnReadAvailable(int32_t available_bytes) = 0;
        virtual void OnRedirect() {}
        virtual void OnCompleted() = 0;
        virtual void OnFailed(int32_t err_code) = 0;
        virtual void OnCanceled() = 0;
        virtual void OnTimeout(int32_t timeout_code, int64_t value) = 0;
    };

    virtual ~TTKMediaNetTask() = default;
    virtual int32_t ReadData(uint8_t* buffer, int32_t max_len) = 0;
};

/**
 * @brief Delegate & Manager interface for TTKMediaNetMgr (RTTI @ 0x010cc2, vtable in Factory @ 0x017708)
 *        Giao diện Delegate & Manager cho TTKMediaNetMgr (RTTI @ 0x010cc2, vtable trong Factory @ 0x017708)
 */
class TTKMediaNetMgr {
public:
    class Delegate {
    public:
        virtual ~Delegate() = default;
        virtual void OnAltSvcUpdated(const char* host, const char* alt_svc) = 0;
        virtual bool IsHostSupportQuic(const char* host) = 0;
        virtual int32_t OnCustomVerify(void* ssl, void* cert_chain, const char* host, int32_t port) = 0;
        virtual void OnNetLog(const char* log_msg) {}
    };

    virtual ~TTKMediaNetMgr() = default;
    virtual int32_t RegisterDelegate(std::shared_ptr<Delegate> delegate) = 0;
    virtual int32_t StopNetworkMgr() = 0;
    virtual TTKMediaNetTask* CreateTask() = 0;
    virtual int32_t CancelTask(TTKMediaNetTask* task) = 0;
    virtual int32_t Preconnect(const TTKMediaNetPreconnectParam* param) = 0;
    virtual bool PreconnectUrl(const std::string& host, int32_t port, int32_t flag) = 0;
    virtual void UpdateAltSvc(const std::string& host, const std::string& alt_svc) = 0;
    virtual bool IsQuicSupported(const std::string& host, int32_t flag) = 0;
    virtual void SetConfigString(uint32_t key, const std::string& val) = 0;
    virtual void NotifyEvent(uint32_t event_id, int64_t arg) = 0;
};

} // namespace TTKMediaNet

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

/**
 * @brief VCN HTTP Context structure mirrored from libvcn.so offsets accessed in MDLTTKMediaNetDownloader
 *        Cấu trúc VCNHttpContext phản chiếu từ các offset của libvcn.so được truy cập trong MDLTTKMediaNetDownloader
 *
 * Accessed Offsets in Disassembly:
 * - +0x20a4: int32_t status_code (str w8, [x9, #0x20a4] @ 0x007850)
 * - +0x20a8: int64_t chunked_eof_flag (str xzr, [x8, #0x20a8] @ 0x007ad0)
 * - +0x20b0: int64_t req_start_offset (str x8, [x21, #0x20b0] @ 0x0087f4)
 * - +0x20b8: int64_t req_end_offset (str x8, [x21, #0x20b8] @ 0x008810)
 * - +0x20c0: int64_t content_length (str x0, [x8, #0x20c0] @ 0x007abc)
 * - +0x27b8: char* custom_header_str (ldr x8, [x21, #0x27b8] @ 0x008828)
 * - +0x2a98: int32_t req_proto_type (str w2, [x8, #0x2a98] @ 0x0069b0)
 * - +0x2aa8: int32_t lower_proto_type (str w8, [x21, #0x2aa8] @ 0x008818)
 */
struct VCNHttpContext {
    uint8_t padding_0000[0x20a4]{};
    int32_t status_code{0};           // +0x20a4
    int64_t chunked_eof_flag{0};      // +0x20a8
    int64_t req_start_offset{0};      // +0x20b0
    int64_t req_end_offset{0};        // +0x20b8
    int64_t content_length{0};        // +0x20c0
    uint8_t padding_20c8[0x6f0]{};
    char* custom_header_str{nullptr}; // +0x27b8
    uint8_t padding_27c0[0x2d8]{};
    int32_t req_proto_type{0};        // +0x2a98
    uint8_t padding_2a9c[0x0c]{};
    int32_t lower_proto_type{0};      // +0x2aa8
};

VCNHttpContext* createHttpContext();
void releaseHttpContext(VCNHttpContext** ctx);
void httpParserParseContentRange(VCNHttpContext* ctx, const char* content_range_val);

} // namespace vcn
} // namespace mediakit

namespace ttmio {

// Forward declarations / Khai báo trước
class MDLTTKMediaNetDownloaderFactory;

/**
 * @brief Request Protocol Type Enumeration (used in MDLLinkQualityManager & Strategy)
 *        Kiểu liệt kê giao thức yêu cầu mạng (dùng trong MDLLinkQualityManager & Strategy)
 */
enum class ReqProtoType : int32_t {
    kProtoUnknown = -1,
    kProtoHttp1x  = 1,
    kProtoQuic    = 2,
    kProtoHttp2   = 3
};

/**
 * @brief DNS Resolution Listener Interface (RTTI @ 0x010423)
 *        Giao diện lắng nghe phân giải DNS (RTTI @ 0x010423)
 */
class MIODnsResolveListener {
public:
    virtual ~MIODnsResolveListener() = default;
    virtual void onResolve(std::string host, std::string ip_list, int32_t dns_type, int32_t err_code, int32_t ttl) = 0;
};

/**
 * @brief Base Listener Interface for MIO events (RTTI @ 0x01050f)
 *        Giao diện lắng nghe sự kiện MIO cơ sở (RTTI @ 0x01050f)
 */
class MIOListener {
public:
    virtual ~MIOListener() = default;
};

/**
 * @brief MIO Value wrapper for event notifications (0x55a0, 0x55c0, 0x58e0, 0x5270)
 *        Lớp bao bọc giá trị MIOValue cho thông báo sự kiện (0x55a0, 0x55c0, 0x58e0, 0x5270)
 */
class MIOValue {
public:
    explicit MIOValue(int32_t v) : int_val_(v), type_(1) {}
    explicit MIOValue(int64_t v) : int_val_(v), type_(2) {}
    explicit MIOValue(const char* s) : str_val_(s ? s : ""), type_(3) {}
    ~MIOValue() = default;

    int64_t int_val() const { return int_val_; }
    const std::string& str_val() const { return str_val_; }
    int32_t type() const { return type_; }

private:
    int64_t int_val_{0};
    std::string str_val_;
    int32_t type_{0};
};

/**
 * @brief IoListener interface receiving status updates and errors from downloader (offsets +0x10..+0x38)
 *        Giao diện MIOIoListener nhận cập nhật trạng thái và lỗi từ bộ tải (offset +0x10..+0x38)
 */
class MIOIoListener {
public:
    virtual ~MIOIoListener() = default;
    virtual void onTaskValUpdate(std::weak_ptr<void> sender, int32_t key, const MIOValue& val) = 0; // vtable +0x10
    virtual void onDataReady(std::weak_ptr<void> sender) = 0;                                       // vtable +0x18
    virtual void onRedirect(std::weak_ptr<void> sender, const char* new_url) {}                     // vtable +0x20
    virtual void onError(std::weak_ptr<void> sender, int32_t err_code, int64_t offset, const std::string& msg) = 0; // vtable +0x28
    virtual void onComplete(std::weak_ptr<void> sender, int32_t code, int64_t extra) = 0;           // vtable +0x30
    virtual void onClosed(std::weak_ptr<void> sender) = 0;                                          // vtable +0x38
};

/**
 * @brief Base VOD Network Adapter class (RTTI @ 0x0170b0, imported from libavmdlbase.so)
 *        Lớp cơ sở MIOVodNetAdapter (RTTI @ 0x0170b0, nhập từ libavmdlbase.so)
 */
class MIOVodNetAdapter {
public:
    explicit MIOVodNetAdapter(uint64_t adapter_id = 0) : adapter_id_(adapter_id) {}
    virtual ~MIOVodNetAdapter() = default;

    virtual void setStringValue(int32_t key, const char* val) = 0;
    virtual void setIntValue(int32_t key, int64_t val) = 0;
    virtual void setObjectValue(int32_t key, void* obj) = 0;
    virtual void setListener(std::weak_ptr<MIOIoListener> listener) { io_listener_ = listener; }
    virtual const char* getStringValue(int32_t key) { return nullptr; }
    virtual int64_t getIntValue(int32_t key) { return 0; }
    virtual int32_t getBoolValue(int32_t key) { return 0; }
    virtual int32_t open(int64_t offset, int64_t size) = 0;
    virtual int32_t read(uint8_t* buf, int64_t size, int64_t* total_size) = 0;
    virtual int32_t read(uint8_t* buf, int32_t size, int64_t offset) { return 0; }
    virtual int32_t write(uint8_t* buf, int32_t size) { return 0; }
    virtual int32_t close() = 0;
    virtual bool isDataAvailable() { return false; }

protected:
    uint64_t adapter_id_{0};
    std::weak_ptr<MIOIoListener> io_listener_;
};

/**
 * @brief Ring Buffer structure for HTTP/QUIC payload buffering (0x5690, 0x7298..0x72f4, 0x7c78..0x7c8c)
 *        Cấu trúc bộ đệm vòng MDLRingBuffer để lưu trữ luồng dữ liệu HTTP/QUIC
 */
class MDLRingBuffer {
public:
    MDLRingBuffer(size_t capacity, size_t block_size)
        : capacity_(capacity), block_size_(block_size), buffer_(capacity, 0) {}
    virtual ~MDLRingBuffer() = default;

    virtual int64_t getTotalSize() const { return total_size_; }                 // vtable +0x10
    virtual int64_t getWriteOffset() const { return write_offset_; }             // vtable +0x18
    virtual int32_t getFreeSize() const {                                        // vtable +0x20
        return static_cast<int32_t>(capacity_ - (write_offset_ - read_offset_));
    }
    virtual int64_t write(const uint8_t* data, int64_t len) {                    // vtable +0x40
        if (!data || len <= 0) return 0;
        write_offset_ += len;
        return len;
    }
    virtual void setReadOffset(int64_t offset) {                                 // vtable +0x68
        read_offset_ = offset;
        write_offset_ = offset;
    }
    virtual void reset() {                                                       // vtable +0x70
        read_offset_ = 0;
        write_offset_ = 0;
    }
    virtual int32_t read(uint8_t* dst, int32_t max_len) {                        // vtable +0x90
        int64_t avail = write_offset_ - read_offset_;
        if (avail <= 0) return 0;
        int32_t to_read = (avail < max_len) ? static_cast<int32_t>(avail) : max_len;
        read_offset_ += to_read;
        return to_read;
    }

private:
    size_t capacity_{0};
    size_t block_size_{0};
    int64_t total_size_{0};
    int64_t read_offset_{0};
    int64_t write_offset_{0};
    std::vector<uint8_t> buffer_;
};

/**
 * @brief Message dictionary used between Strategy and Downloader (0x5390, 0x5280, 0x5330, 0x53d0, 0x55d0, 0x5730)
 *        Từ điển thông điệp MDLMessage dùng giữa Strategy và Downloader
 */
class MDLMessage {
public:
    MDLMessage() = default;
    ~MDLMessage() = default;

    void setInt32(const char* key, int32_t val) {
        if (key) int_map_[key] = val;
    }
    void setInt64(const char* key, int64_t val) {
        if (key) long_map_[key] = val;
    }
    void setString(const char* key, const std::string& val) {
        if (key) str_map_[key] = val;
    }
    bool findIntValue(const char* key, int32_t& out) const {
        if (!key) return false;
        auto it = int_map_.find(key);
        if (it != int_map_.end()) {
            out = it->second;
            return true;
        }
        return false;
    }
    bool findLongValue(const char* key, int64_t& out) const {
        if (!key) return false;
        auto it = long_map_.find(key);
        if (it != long_map_.end()) {
            out = it->second;
            return true;
        }
        return false;
    }
    bool findCStringValue(const char* key, char*& out) const {
        if (!key) return false;
        auto it = str_map_.find(key);
        if (it != str_map_.end()) {
            out = strdup(it->second.c_str());
            return true;
        }
        return false;
    }
    bool isMember(const char* key) const {
        if (!key) return false;
        return int_map_.count(key) > 0 || long_map_.count(key) > 0 || str_map_.count(key) > 0;
    }

private:
    std::map<std::string, int32_t> int_map_;
    std::map<std::string, int64_t> long_map_;
    std::map<std::string, std::string> str_map_;
};

/**
 * @brief Base Range Request Strategy interface (RTTI @ 0x010edf, vtable @ 0x017800)
 *        Giao diện chiến lược yêu cầu dải byte MDLRangeRequestStrategy (RTTI @ 0x010edf, vtable @ 0x017800)
 */
class MDLStrategy {
public:
    virtual ~MDLStrategy() = default;
    virtual void onParameterUpdated() = 0;
    virtual int32_t onEvent(int32_t event_type, MDLMessage* msg) = 0;
    virtual void handleError(int32_t event_type, MDLMessage* msg) = 0;
    virtual void updateTaskConfig(MDLMessage* msg) = 0;
};

class MDLRangeRequestStrategy : public MDLStrategy {
public:
    ~MDLRangeRequestStrategy() override = default;
};

/**
 * @brief Base Downloader Factory interface (RTTI @ 0x010c8d)
 *        Giao diện nhà máy bộ tải cơ sở MDLTTKMediaNetDownloaderFactoryBase (RTTI @ 0x010c8d)
 */
class MDLTTKMediaNetDownloaderFactoryBase {
public:
    virtual ~MDLTTKMediaNetDownloaderFactoryBase() = default;
    virtual void init() = 0;
    virtual void uninit() = 0;
    virtual void startQuicDetect(const char* host) = 0;
    virtual bool preconnectUrl(const char* url) = 0;
    virtual TTKMediaNet::TTKMediaNetMgr* getNetworkMgr() = 0;
    virtual void updateAltSvcInfo(const char* host, const char* alt_svc) = 0;
    virtual bool isHostSupportQuic(const char* host) = 0;
};

/**
 * @brief Configuration Center mirror with exact field offsets from disassembly
 *         Trung tâm cấu hình MDLConfigCenter phản chiếu chính xác các offset từ mã máy
 */
struct MDLConfigCenter {
    int32_t mLowerProtoType{0};         // +0x120 (ldr w0, [x0, #0x120] @ 0x00acf8)
    int32_t mUseRingBufferPool{1};      // +0x22c (ldr w8, [x0, #0x22c] @ 0x006414)
    int32_t mRingBufferSize{256};       // +0x238 (ldr w8, [x0, #0x238] @ 0x0076d4)
    int32_t mMultiIpEnable{1};          // +0x430 (ldr w8, [x22, #0x430] @ 0x009054)
    int32_t mEnableQuicHeader{1};       // +0x438 (ldr w8, [x22, #0x438] @ 0x0090f4)
    int32_t mEnableQuicPreconn{1};      // +0x43c (ldr w8, [x21, #0x43c] @ 0x00f0e8)
    int32_t mQuicPreconnSync{0};        // +0x444 (ldr w8, [x21, #0x444] @ 0x00f0f4)
    int32_t mQuicCheckLowerProto{1};    // +0x44c (ldr w8, [x0, #0x44c] @ 0x00fba8)
    int32_t mEnableQuicRace{1};         // +0x454 (ldr w8, [x21, #0x454] @ 0x00f144)
    int32_t mEnableLinkQuality{1};      // +0x458 (ldr w8, [x21, #0x458] @ 0x00f15c)
    int32_t mQuicMaxFailCount{3};       // +0x474 (ldr w8, [x20, #0x474] @ 0x00fda8)
    int32_t mHttp1xMinSpeedThreshold{0};// +0x478 (ldrsw x8, [x20, #0x478] @ 0x00fdd0)
    int32_t mRequireValidMetrics{0};    // +0x480 (ldr w8, [x21, #0x480] @ 0x00f174)
    int32_t mEnableRaceSpeedUpdate{1};  // +0x488 (ldr w8, [x0, #0x488] @ 0x00f314)
    int32_t mEnableResetRaceOnErr{1};   // +0x48c (ldr w8, [x20, #0x48c] @ 0x00fa64)
    int32_t mRaceIntervalMin{1};        // +0x490 (ldr w8, [x0, #0x490] @ 0x00fd28, multiplied by 60000 = 0xea60)
    void*   mDnsLooper{nullptr};        // +0x5d0 (ldr x20, [x0, #0x5d0] @ 0x008930)
    int32_t mUseWeakCallback{1};        // +0x62c (ldr w8, [x0, #0x62c] @ 0x009c9c)
    int32_t mEnableDnsParser{1};        // +0x640 (ldr w8, [x0, #0x640] @ 0x005998)
    int32_t mCheckMediatorError{1};     // +0x6cc (ldr w8, [x0, #0x6cc] @ 0x00f9f8)
    int32_t mUseSharedDnsParser{1};     // +0x6f4 (ldr w8, [x0, #0x6f4] @ 0x0059a0)

    std::string getStrValue(int32_t key) const {
        if (key == 0x4a) return "quic_params";
        if (key == 0xb0) return "net_extras";
        return "";
    }
};

/**
 * @brief QUIC State Manager singleton mirror (`MDLQuicStateManager` @ 0x5430)
 *        Trình quản lý trạng thái QUIC đơn bản (`MDLQuicStateManager` @ 0x5430)
 */
class MDLQuicStateManager {
public:
    static MDLQuicStateManager* getInstance() {
        static MDLQuicStateManager instance;
        return &instance;
    }

    std::mutex& getMutex() { return mutex_; }               // offset +0x88 (0x00f484) & +0xb0 (0x00e69c)
    int64_t getLastRaceTime() const { return last_race_ts_; } // offset +0x80 (0x00fd10)

    bool quicConnecting() const { return quic_connecting_; }
    void setQuicConnecting(bool v) { quic_connecting_ = v; }
    void setNewQuicConnectStart() { last_connect_ts_ = 1; }
    void updateQuicPreconnStatus(bool ok) { preconn_ok_ = ok; }
    void markQuicBroken(const char* host) {
        if (host) broken_hosts_[host] = true;
    }
    bool isQuicBroken(const char* host) const {
        if (!host) return false;
        auto it = broken_hosts_.find(host);
        return it != broken_hosts_.end() && it->second;
    }
    bool isQuicEverSucceed() const { return ever_succeed_; }
    bool isRacingInProgress() const { return racing_in_progress_; }
    void setRacingInProgress(bool v) { racing_in_progress_ = v; }
    bool isQuicRacedSucceed() const { return quic_raced_succeed_; }
    void updateSpeedRacingStatus(bool v) { quic_raced_succeed_ = v; }
    void resetQuicRacingStatus() {
        racing_in_progress_ = false;
        quic_raced_succeed_ = false;
    }
    int32_t quicRacingNums() const { return quic_racing_nums_; }
    int32_t http1xRacingNums() const { return http1x_racing_nums_; }
    void addToQuicRacingList(int64_t session_id) { ++quic_racing_nums_; }
    void addToHttp1xRacingList(int64_t session_id) { ++http1x_racing_nums_; }
    void updateSpeed(const MDLMessage& msg) {}

private:
    std::mutex mutex_;
    int64_t last_race_ts_{0};
    int64_t last_connect_ts_{0};
    bool quic_connecting_{false};
    bool preconn_ok_{true};
    bool ever_succeed_{true};
    bool racing_in_progress_{false};
    bool quic_raced_succeed_{true};
    int32_t quic_racing_nums_{0};
    int32_t http1x_racing_nums_{0};
    std::map<std::string, bool> broken_hosts_;
};

int64_t getCurrentTime();
int32_t ff_convertStatusCodeToMdlErr(int32_t http_status, bool is_open);
std::string safeString(const char* s);
int32_t getItemFromBtag(const std::string& btag, int32_t index);

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_TYPES_H_
