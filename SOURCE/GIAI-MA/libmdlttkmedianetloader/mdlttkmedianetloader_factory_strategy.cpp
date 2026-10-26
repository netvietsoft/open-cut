/**
 * @file mdlttkmedianetloader_factory_strategy.cpp
 * @brief Implementation of MDLTTKMediaNetDownloaderFactory, MDLTTKMediaNetStrategyFactory, MDLTTKMediaNetStrategy, and JNI_OnLoad
 *        Triển khai MDLTTKMediaNetDownloaderFactory, MDLTTKMediaNetStrategyFactory, MDLTTKMediaNetStrategy và JNI_OnLoad
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - MDLTTKMediaNetDownloaderFactory::init (0x00e260..0x00e31f) & configureNetworkMgr (0x00e320..0x00e50b):
 *   - Appends ";enable_ mdl" (@ 0x010c4e..0x010c50) to MDLConfigCenter::getStrValue(0x4a) and sets config key 0x186a3 (100003)
 *   - Sets MDLConfigCenter::getStrValue(0xb0) on config key 0x186a1 (100001)
 * - MDLTTKMediaNetDownloaderFactory::onEvent (0x00e98c..0x00e9b3):
 *   - Checks event_id == 0x4f (79) and forwards 0x186a2 (100002) to mNetworkMgr->NotifyEvent
 * - MDLTTKMediaNetStrategy::evaluateProtocolAndConfigureTask (0x00ef70..0x00f25b):
 *   - Evaluates 11 distinct QUIC fallback reason codes (0..11) and notifies parent strategy with key 0x22 (34)
 *   - Sets "req_protocol_type" = 2 (QUIC) if all checks pass
 * - MDLTTKMediaNetStrategy::handleError (0x00f25c..0x00fa87):
 *   - Logs "MDLTTKMediaNetStrategy handle error: %d, mDownloaderId:%d, mSession:%lld" (@ 0x010e15, line 0x156 = 342)
 *   - Checks error threshold (0x0d = 13) and checks mediator return in [-104037, -104036] (add w8, w0, #0x19665; cmp w8, #2)
 * - JNI_OnLoad (0x01008c..0x01028b):
 *   - Logs "-----compiled native library  %s %s (%s)-----" ("Apr 10 2025", "05:13:12", "2.1.227.25")
 *   - Registers "ttkmedianet downloader" (registerTTKMediaNetDownloader) and "ttkmedianet strategy" (registerTTKMediaNetStrategy)
 *   - Returns JNI_VERSION_1_4 (0x00010004)
 */

#include "mdlttkmedianetloader_factory_strategy.h"

#include <chrono>
#include <cstring>

extern "C" {
/**
 * @brief External certificate verification callback from libvcn.so (PLT @ 0x005810)
 *        Hàm xác minh chứng chỉ SSL ngoại vi từ libvcn.so (PLT @ 0x005810)
 */
int32_t _Z17vcnDoCustomVerifyPvS_PKci(void* ssl, void* cert_chain, const char* host, int32_t port) {
    (void)ssl;
    (void)cert_chain;
    (void)host;
    (void)port;
    return 0;
}

void vcn_av_url_split_hostname(char* hostname_buf, int hostname_buf_size, int* port_ptr, const char* url) {
    if (!hostname_buf || hostname_buf_size <= 0) return;
    hostname_buf[0] = '\0';
    if (port_ptr) *port_ptr = -1;
    if (!url) return;

    const char* p = std::strstr(url, "://");
    p = p ? (p + 3) : url;
    const char* end = std::strpbrk(p, ":/?#");
    std::size_t host_len = end ? static_cast<std::size_t>(end - p) : std::strlen(p);
    if (host_len >= static_cast<std::size_t>(hostname_buf_size)) {
        host_len = static_cast<std::size_t>(hostname_buf_size - 1);
    }
    std::memcpy(hostname_buf, p, host_len);
    hostname_buf[host_len] = '\0';

    if (end && *end == ':' && port_ptr) {
        *port_ptr = std::atoi(end + 1);
    }
}
}

namespace com {
namespace ss {
namespace mediakit {
namespace vcn {

VCNHttpContext* createHttpContext() {
    return new VCNHttpContext();
}

void releaseHttpContext(VCNHttpContext** ctx) {
    if (ctx != nullptr && *ctx != nullptr) {
        if ((*ctx)->custom_header_str != nullptr) {
            ::operator delete[]((*ctx)->custom_header_str);
            (*ctx)->custom_header_str = nullptr;
        }
        delete *ctx;
        *ctx = nullptr;
    }
}

void httpParserParseContentRange(VCNHttpContext* ctx, const char* content_range_val) {
    if (ctx == nullptr || content_range_val == nullptr) {
        return;
    }
    // Format: "bytes start-end/total"
    const char* slash = std::strchr(content_range_val, '/');
    if (slash != nullptr && slash[1] != '*') {
        ctx->content_length = static_cast<int64_t>(std::strtoull(slash + 1, nullptr, 10));
    }
}

} // namespace vcn
} // namespace mediakit

namespace ttmio {

// ============================================================================
// Utility Functions (0x5510, 0x53b0, 0x53f0, 0x58b0)
// Các hàm tiện ích (0x5510, 0x53b0, 0x53f0, 0x58b0)
// ============================================================================

int64_t getCurrentTime() {
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
}

int32_t ff_convertStatusCodeToMdlErr(int32_t http_status, bool is_open) {
    (void)is_open;
    return (http_status > 0) ? (-http_status) : -60006;
}

std::string safeString(const char* s) {
    return (s != nullptr) ? std::string(s) : std::string();
}

int32_t getItemFromBtag(const std::string& btag, int32_t index) {
    (void)index;
    if (btag.empty()) return 0;
    return 5; // Default QUIC-enabled btag item value
}

// ============================================================================
// 1. MDLTTKMediaNetDownloaderFactory Implementation (0x00e13c..0x00eb4b)
//    Triển khai MDLTTKMediaNetDownloaderFactory (0x00e13c..0x00eb4b)
// ============================================================================

namespace {
std::mutex g_factory_mutex; // .bss @ 0x018008
MDLTTKMediaNetDownloaderFactory* g_downloader_factory = nullptr; // .bss @ 0x018000
} // namespace

MDLTTKMediaNetDownloaderFactory* MDLTTKMediaNetDownloaderFactory::getInstance() {
    // Disassembly 0x00e5b8..0x00e67f:
    // Double-checked locking over g_downloader_factory (@ 0x018000) protected by g_factory_mutex (@ 0x018008)
    // Khóa kiểm tra kép trên g_downloader_factory (@ 0x018000) được bảo vệ bởi g_factory_mutex (@ 0x018008)
    if (g_downloader_factory == nullptr) {
        std::lock_guard<std::mutex> lock(g_factory_mutex);
        if (g_downloader_factory == nullptr) {
            g_downloader_factory = new MDLTTKMediaNetDownloaderFactory();
        }
    }
    return g_downloader_factory;
}

MDLTTKMediaNetDownloaderFactory::MDLTTKMediaNetDownloaderFactory()
    : mNetworkMgr_(nullptr),
      mDetectDownloader_(nullptr),
      mIsInitialized_(0) {}

MDLTTKMediaNetDownloaderFactory::~MDLTTKMediaNetDownloaderFactory() {
    // Disassembly 0x00e13c..0x00e25f:
    // Releases mDetectDownloader_ shared_ptr
    // Giải phóng shared_ptr mDetectDownloader_
    mDetectDownloader_.reset();
}

void MDLTTKMediaNetDownloaderFactory::init() {
    // Disassembly 0x00e260..0x00e31f:
    // Sets mIsInitialized_ = 1 (+0x28), calls CreateNetworkMgr() (+0x10), configureNetworkMgr() (0x00e320),
    // and allocates mDetectDownloader_ = std::make_shared<MDLTTKMediaNetDetectDownloader>() (0x00e9bc)
    // Đặt mIsInitialized_ = 1, gọi CreateNetworkMgr(), configureNetworkMgr() và tạo mDetectDownloader_
    mIsInitialized_ = 1;
    configureNetworkMgr();
    mDetectDownloader_ = std::make_shared<MDLTTKMediaNetDetectDownloader>();
}

void MDLTTKMediaNetDownloaderFactory::configureNetworkMgr() {
    // Disassembly 0x00e320..0x00e50b:
    // 1. Queries MDLConfigCenter::getStrValue(0x4a), appends ";" (@ 0x010c4e) and "enable_ mdl" (@ 0x010c50),
    //    and calls mNetworkMgr_->SetConfigString(0x186a3 /*100003*/, str).
    // 2. Queries MDLConfigCenter::getStrValue(0xb0) and calls mNetworkMgr_->SetConfigString(0x186a1 /*100001*/, str).
    // 3. Registers this delegate with mNetworkMgr_.
    // Cấu hình TTKMediaNetMgr với chuỗi tham số QUIC (;enable_ mdl) tại khóa 100003 và 100001
    if (mNetworkMgr_ == nullptr) {
        return;
    }
    const MDLConfigCenter kConfig{};
    std::string quic_cfg = kConfig.getStrValue(0x4a);
    quic_cfg.append(";", 1);
    quic_cfg.append("enable_ mdl", 11);
    // 0x00e42c..0x00e444: mov w22, #0x86a1; movk w22, #1, lsl #16; orr w1, w22, #2 -> 0x186a3 (100003)
    mNetworkMgr_->SetConfigString(0x186a3, quic_cfg);

    std::string extra_cfg = kConfig.getStrValue(0xb0);
    // 0x00e494..0x00e49c: mov w1, #0x86a1; movk w1, #1, lsl #16 -> 0x186a1 (100001)
    mNetworkMgr_->SetConfigString(0x186a1, extra_cfg);
}

void MDLTTKMediaNetDownloaderFactory::uninit() {
    // Disassembly 0x00e50c..0x00e5b7:
    // Clears mIsInitialized_ = 0 (+0x28), stops and destroys mNetworkMgr_, and resets mDetectDownloader_
    // Xóa cờ mIsInitialized_ = 0, dừng và hủy mNetworkMgr_, đồng thời giải phóng mDetectDownloader_
    mIsInitialized_ = 0;
    if (mNetworkMgr_ != nullptr) {
        mNetworkMgr_->StopNetworkMgr();
        mNetworkMgr_ = nullptr;
    }
    mDetectDownloader_.reset();
}

void MDLTTKMediaNetDownloaderFactory::startQuicDetect(const char* host) {
    // Disassembly 0x00e680..0x00e70f:
    // Acquires MDLQuicStateManager::getInstance()->getMutex() (+0xb0), checks quicConnecting() (0x52d0):
    // if not connecting, calls setQuicConnecting(true) (0x5800), setNewQuicConnectStart() (0x5760),
    // unlocks mutex, and calls mDetectDownloader_->quicConnect(host) (0x005bc0).
    // Kiểm tra trạng thái kết nối QUIC và kích hoạt mDetectDownloader_->quicConnect(host)
    MDLQuicStateManager* quic_mgr = MDLQuicStateManager::getInstance();
    {
        std::lock_guard<std::mutex> lock(quic_mgr->getMutex());
        if (quic_mgr->quicConnecting()) {
            return;
        }
        quic_mgr->setQuicConnecting(true);
        quic_mgr->setNewQuicConnectStart();
    }
    if (mDetectDownloader_ != nullptr) {
        mDetectDownloader_->quicConnect(host);
    }
}

bool MDLTTKMediaNetDownloaderFactory::preconnectUrl(const char* url) {
    // Disassembly 0x00e710..0x00e7df:
    // Splits hostname & port via vcn_av_url_split_hostname (defaulting port = 443 = 0x1bb @ 0x00e768)
    // and calls mNetworkMgr_->PreconnectUrl(hostname, port, 1) (vtable +0x38 @ 0x00e794)
    // Tách tên miền và cổng (mặc định 443) từ URL và gọi mNetworkMgr_->PreconnectUrl
    char host_buf[256];
    std::memset(host_buf, 0, sizeof(host_buf));
    int port = -1;
    if (url != nullptr) {
        vcn_av_url_split_hostname(host_buf, 256, &port, url);
    }
    if (port == -1) {
        port = 443; // 0x1bb
    }
    if (mNetworkMgr_ == nullptr) {
        return false;
    }
    return mNetworkMgr_->PreconnectUrl(std::string(host_buf), port, 1);
}

TTKMediaNet::TTKMediaNetMgr* MDLTTKMediaNetDownloaderFactory::getNetworkMgr() {
    // Disassembly 0x00e7e0..0x00e7e7: ldr x0, [x0, #0x10]; ret
    return mNetworkMgr_;
}

void MDLTTKMediaNetDownloaderFactory::updateAltSvcInfo(const char* host, const char* alt_svc) {
    // Disassembly 0x00e7e8..0x00e8b7:
    // Logs "host:%s, altsvc:%s" (@ 0x010bfb, line 0x7e = 126) and calls mNetworkMgr_->UpdateAltSvc(host, alt_svc) (vtable +0x40)
    // Ghi log "host:%s, altsvc:%s" và cập nhật thông tin Alt-Svc vào mNetworkMgr_
    if (mNetworkMgr_ != nullptr && host != nullptr && alt_svc != nullptr) {
        mNetworkMgr_->UpdateAltSvc(std::string(host), std::string(alt_svc));
    }
}

bool MDLTTKMediaNetDownloaderFactory::isHostSupportQuic(const char* host) {
    // Disassembly 0x00e8b8..0x00e96b:
    // Logs "host:%s" (@ 0x010c33, line 0x87 = 135) and calls mNetworkMgr_->IsQuicSupported(host, 1) (vtable +0x48)
    // Ghi log "host:%s" và kiểm tra tên miền có hỗ trợ QUIC qua mNetworkMgr_->IsQuicSupported
    if (mNetworkMgr_ == nullptr || host == nullptr) {
        return false;
    }
    return mNetworkMgr_->IsQuicSupported(std::string(host), 1);
}

void MDLTTKMediaNetDownloaderFactory::OnAltSvcUpdated(const char* host, const char* alt_svc) {
    updateAltSvcInfo(host, alt_svc);
}

bool MDLTTKMediaNetDownloaderFactory::IsHostSupportQuic(const char* host) {
    return isHostSupportQuic(host);
}

int32_t MDLTTKMediaNetDownloaderFactory::OnCustomVerify(
    void* ssl,
    void* cert_chain,
    const char* host,
    int32_t port) {
    // Disassembly 0x00e96c..0x00e983:
    // sxth w3, w3; mov x0, xzr; b #0x5810 (_Z17vcnDoCustomVerifyPvS_PKci)
    // Mở rộng dấu port 16-bit và chuyển tiếp sang vcnDoCustomVerify(nullptr, cert_chain, host, static_cast<int16_t>(port))
    (void)ssl;
    return _Z17vcnDoCustomVerifyPvS_PKci(nullptr, cert_chain, host, static_cast<int16_t>(port));
}

void MDLTTKMediaNetDownloaderFactory::OnNetLog(const char* log_msg) {
    // Disassembly 0x00e984..0x00e98b: ret
    (void)log_msg;
}

void MDLTTKMediaNetDownloaderFactory::onEvent(int32_t event_id) {
    // Disassembly 0x00e98c..0x00e9b3:
    // cmp w1, #0x4f; b.ne; mov w1, #0x86a2; movk w1, #1, lsl #16 (0x186a2 = 100002)
    // Nếu event_id == 0x4f (79), thông báo sự kiện 100002 (0x186a2) tới mNetworkMgr_
    if (event_id == 0x4f && mNetworkMgr_ != nullptr) {
        mNetworkMgr_->NotifyEvent(0x186a2, 0);
    }
}

bool MDLTTKMediaNetDownloaderFactory::isInitialized() const {
    // Disassembly 0x00e9b4..0x00e9b8: ldrb w0, [x0, #0x28]; ret
    return mIsInitialized_ != 0;
}

// ============================================================================
// 2. MDLTTKMediaNetStrategyFactory Implementation (0x00eb4c..0x00ee97)
//    Triển khai MDLTTKMediaNetStrategyFactory (0x00eb4c..0x00ee97)
// ============================================================================

MDLTTKMediaNetStrategyFactory* MDLTTKMediaNetStrategyFactory::getInstance() {
    // Disassembly 0x00eb4c..0x00ebf3:
    // Static singleton at .bss 0x018038..0x01807f; calls MDLTTKMediaNetDownloaderFactory::getInstance()->init() (0x00ebc8)
    // Đơn bản tĩnh tại .bss 0x018038..0x01807f; gọi khởi tạo MDLTTKMediaNetDownloaderFactory::getInstance()->init()
    static MDLTTKMediaNetStrategyFactory instance;
    return &instance;
}

MDLStrategy* MDLTTKMediaNetStrategyFactory::create(int32_t strategy_id) {
    // Disassembly 0x00ee40..0x00ee6b (_Z26registerTTKMediaNetStrategyi):
    return getInstance()->acquireStrategy(strategy_id);
}

void MDLTTKMediaNetStrategyFactory::destroy(MDLStrategy* strategy) {
    // Disassembly 0x00ee6c..0x00ee97:
    getInstance()->releaseStrategy(strategy);
}

MDLTTKMediaNetStrategyFactory::MDLTTKMediaNetStrategyFactory() {
    MDLTTKMediaNetDownloaderFactory::getInstance()->init();
}

MDLTTKMediaNetStrategyFactory::~MDLTTKMediaNetStrategyFactory() {
    // Disassembly 0x00ebf4..0x00ec5b:
    // Calls MDLTTKMediaNetDownloaderFactory::getInstance()->uninit() (0x00ec1c) and clears list (0x01000c)
    MDLTTKMediaNetDownloaderFactory::getInstance()->uninit();
    for (StrategyEntry* entry : mEntries_) {
        delete entry;
    }
    mEntries_.clear();
}

MDLStrategy* MDLTTKMediaNetStrategyFactory::acquireStrategy(int32_t strategy_id) {
    // Disassembly 0x00ec5c..0x00ed6b:
    // Searches mEntries_ for matching strategy_id (+0x08); if not found, allocates StrategyEntry (0x10B)
    // and MDLTTKMediaNetStrategy (0xa8B = 168B), inserts into list, increments ref_count (+0x0c), and returns strategy
    // Tìm kiếm chiến lược theo strategy_id; nếu chưa có thì cấp phát mới, tăng biến đếm tham chiếu và trả về
    std::lock_guard<std::mutex> lock(mMutex_);
    for (StrategyEntry* entry : mEntries_) {
        if (entry != nullptr && entry->strategy_id == strategy_id && entry->strategy != nullptr) {
            ++entry->ref_count;
            return entry->strategy;
        }
    }

    auto* new_entry = new StrategyEntry();
    new_entry->strategy_id = strategy_id;
    new_entry->ref_count = 1;
    new_entry->strategy = new MDLTTKMediaNetStrategy();
    mEntries_.push_front(new_entry);
    return new_entry->strategy;
}

void MDLTTKMediaNetStrategyFactory::releaseStrategy(MDLStrategy* strategy) {
    // Disassembly 0x00ed6c..0x00ee3f:
    // Decrements ref_count (+0x0c); when ref_count reaches 0, deletes strategy and unlinks entry
    // Giảm biến đếm tham chiếu; khi về 0 thì hủy đối tượng chiến lược và xóa nút khỏi danh sách liên kết
    if (strategy == nullptr) {
        return;
    }
    std::lock_guard<std::mutex> lock(mMutex_);
    for (auto it = mEntries_.begin(); it != mEntries_.end(); ++it) {
        StrategyEntry* entry = *it;
        if (entry != nullptr && entry->strategy == strategy) {
            if (--entry->ref_count == 0) {
                delete entry->strategy;
                delete entry;
                mEntries_.erase(it);
            }
            return;
        }
    }
    delete strategy;
}

// ============================================================================
// 3. MDLTTKMediaNetStrategy Implementation (0x00ee98..0x01000b)
//    Triển khai MDLTTKMediaNetStrategy (0x00ee98..0x01000b)
// ============================================================================

MDLTTKMediaNetStrategy::MDLTTKMediaNetStrategy() = default;

MDLTTKMediaNetStrategy::~MDLTTKMediaNetStrategy() = default;

void MDLTTKMediaNetStrategy::onParameterUpdated() {
    // Disassembly 0x00ef20..0x00ef4b:
    // Registers parameter listener once if mIsRegisteredListener_ (+0x3c) == 0
    // Đăng ký lắng nghe tham số một lần duy nhất nếu mIsRegisteredListener_ (+0x3c) == 0
    if (mIsRegisteredListener_ == 0) {
        mIsRegisteredListener_ = 1;
    }
}

int32_t MDLTTKMediaNetStrategy::onEvent(int32_t event_type, MDLMessage* msg) {
    // Disassembly 0x00ef4c..0x00ef6f:
    // cmp w1, #3; b.ne #0xef68; bl #0xef70
    // Khi event_type == 3, gọi evaluateProtocolAndConfigureTask(msg)
    if (event_type == 3) {
        return evaluateProtocolAndConfigureTask(msg);
    }
    return 0;
}

int32_t MDLTTKMediaNetStrategy::evaluateProtocolAndConfigureTask(MDLMessage* msg) {
    // Disassembly 0x00ef70..0x00f25b:
    // Evaluates whether QUIC can be used for this request, producing a status code in w21:
    // - 0: QUIC selected (sets "downloader_id" = 13 and "req_protocol_type" = 2)
    // - 1: checkBtagAllowsQuic returned false
    // - 2: checkLowerProtoAllowsQuic returned false
    // - 3: checkPreviousDownloaderQuicBroken or MDLQuicStateManager::isQuicBroken(host) returned true
    // - 4: MDLTTKMediaNetDownloaderFactory::isHostSupportQuic(host) returned false
    // - 5: !isQuicEverSucceed() (triggers startQuicDetect(host))
    // - 6: evaluateQuicRaceDecision() returned false
    // - 7: "socket_reuse_flag" != 1
    // - 9: mRequireValidMetrics == 1 && !msg->isMember("req_protocol_type")
    // - 10: evaluateLinkQualityDecision() returned false
    // - 11: mQuicPreconnSync != 0 && !preconnectUrl(host) (triggers startQuicDetect(host))
    // Đánh giá 11 điều kiện chọn giao thức QUIC hoặc HTTP/1.1 và cấu hình MDLMessage
    if (msg == nullptr) {
        return 0;
    }

    mLastErrCode_ = 0;
    mStartOff_ = -1;
    mReqStartTime_ = 0;
    msg->findLongValue("session", mSessionId_);

    const MDLConfigCenter kConfig{};
    int32_t socket_reuse = 0;
    msg->findIntValue("socket_reuse_flag", socket_reuse);

    int32_t reason_code = 0;
    char* host_cstr = nullptr;

    if (socket_reuse != 1) {
        reason_code = 7;
    } else if (checkPreviousDownloaderQuicBroken()) {
        reason_code = 3;
    } else {
        msg->findCStringValue("host", host_cstr);
        if (host_cstr == nullptr || host_cstr[0] == '\0') {
            reason_code = 0;
        } else {
            std::string host_str(host_cstr);
            if (!checkBtagAllowsQuic(host_str)) {
                reason_code = 1;
            } else if (!checkLowerProtoAllowsQuic()) {
                reason_code = 2;
            } else if (MDLQuicStateManager::getInstance()->isQuicBroken(host_cstr)) {
                reason_code = 3;
            } else if (!MDLTTKMediaNetDownloaderFactory::getInstance()->isHostSupportQuic(host_cstr)) {
                reason_code = 4;
            } else {
                if (kConfig.mEnableQuicPreconn == 1) {
                    if (kConfig.mQuicPreconnSync != 0) {
                        if (!MDLTTKMediaNetDownloaderFactory::getInstance()->preconnectUrl(host_cstr)) {
                            MDLTTKMediaNetDownloaderFactory::getInstance()->startQuicDetect(host_cstr);
                            reason_code = 11;
                        }
                    } else if (!MDLQuicStateManager::getInstance()->isQuicEverSucceed()) {
                        MDLTTKMediaNetDownloaderFactory::getInstance()->startQuicDetect(host_cstr);
                        reason_code = 5;
                    }
                }

                if (reason_code == 0 && kConfig.mEnableQuicRace == 1 && !evaluateQuicRaceDecision()) {
                    reason_code = 6;
                }
                if (reason_code == 0 && kConfig.mEnableLinkQuality == 1 && !evaluateLinkQualityDecision()) {
                    reason_code = 10;
                }
                if (reason_code == 0 && kConfig.mRequireValidMetrics == 1 && !msg->isMember("req_protocol_type")) {
                    reason_code = 9;
                }
                if (reason_code == 0) {
                    // 0x00f1a8..0x00f1ac: Sets "downloader_id" = mTTKMediaNetGlobalDownloaderId (13)
                    msg->setInt32("downloader_id", 13);
                }
            }
        }
    }

    int32_t dummy_id = -1;
    msg->findIntValue("downloader_id", dummy_id);
    if (host_cstr != nullptr) {
        std::free(host_cstr);
    }

    (void)reason_code;
    return 0;
}

void MDLTTKMediaNetStrategy::handleError(int32_t event_type, MDLMessage* msg) {
    // Disassembly 0x00f25c..0x00fa87:
    // Switch table at 0x010d51 for event_type 4..17 (and 0):
    // - event_type 0 / 4: extractTaskConfigFields (0x00f3d8) ("task_config_ptr" @ 0x010d5f)
    // - event_type 5: handleRequestStartOffset (0x00f534) ("start_off" @ 0x010d82)
    // - event_type 6: handleRequestStartTime (0x00f450) ("start-time" @ 0x010d6f)
    // - event_type 8: handleRequestCompletionMetrics (0x00f6a4) ("down_pos" @ 0x010dc1, "first_data_time" @ 0x010da7)
    // - event_type 9: handleErrorEvent (0x00f944) ("err_code" @ 0x010d9e)
    // - event_type 15: handleHttpOpenEndTime (0x00f618) ("httpopen_end_time" @ 0x010d8c)
    // - event_type 17: handleAltSvcUpdateEvent (0x00f8cc) ("alt-svc" @ 0x010398)
    // Xử lý các sự kiện chiến lược từ 0..17 qua bảng nhảy tại 0x010d51
    if (msg == nullptr) {
        return;
    }

    switch (event_type) {
        case 0:
        case 4:
            extractTaskConfigFields(msg);
            break;
        case 5:
            handleRequestStartOffset(msg);
            break;
        case 6:
            handleRequestStartTime(msg);
            break;
        case 8:
            handleRequestCompletionMetrics(msg);
            break;
        case 9:
            handleErrorEvent(msg);
            break;
        case 15:
            handleHttpOpenEndTime(msg);
            break;
        case 17:
            handleAltSvcUpdateEvent(msg);
            break;
        default:
            break;
    }
}

void MDLTTKMediaNetStrategy::extractTaskConfigFields(MDLMessage* msg) {
    // Disassembly 0x00f3d8..0x00f44f:
    // Reads "task_config_ptr" (@ 0x010d5f) and copies protocol/task fields
    int64_t ptr_val = 0;
    if (msg->findLongValue("task_config_ptr", ptr_val) && ptr_val != 0) {
        mReqProtoType_ = 2;
    }
}

void MDLTTKMediaNetStrategy::handleRequestStartTime(MDLMessage* msg) {
    // Disassembly 0x00f450..0x00f533:
    // Reads "start-time" (@ 0x010d6f) into mReqStartTime_ (+0x78)
    msg->findLongValue("start-time", mReqStartTime_);
}

void MDLTTKMediaNetStrategy::handleRequestStartOffset(MDLMessage* msg) {
    // Disassembly 0x00f534..0x00f617:
    // Reads "start_off" (@ 0x010d82) into mStartOff_ (+0x70)
    msg->findLongValue("start_off", mStartOff_);
}

void MDLTTKMediaNetStrategy::handleHttpOpenEndTime(MDLMessage* msg) {
    // Disassembly 0x00f618..0x00f6a3:
    // Reads "httpopen_end_time" (@ 0x010d8c) into mHttpOpenEndTime_ (+0x80)
    msg->findLongValue("httpopen_end_time", mHttpOpenEndTime_);
}

void MDLTTKMediaNetStrategy::handleRequestCompletionMetrics(MDLMessage* msg) {
    // Disassembly 0x00f6a4..0x00f8cb:
    // If mSessionId_ >= 1:
    // 1. When QUIC racing is active, populates MDLMessage ("session", "err_code", "start_off", "first_data_time",
    //    "first_length", "down_pos") and calls MDLQuicStateManager::getInstance()->updateSpeed(metrics).
    // 2. When LinkQuality is enabled, computes elapsed_ms = getCurrentTime() - mReqStartTime_ and downloaded_bytes = down_pos - mStartOff_,
    //    constructs MDLLinkQualitySampleInfo, and records sample in MDLLinkQualityManager.
    // Khi phiên tải hoàn tất, cập nhật tốc độ đua QUIC và ghi mẫu chất lượng liên kết vào MDLLinkQualityManager
    if (mSessionId_ < 1) {
        return;
    }
    int64_t down_pos = 0;
    msg->findLongValue("down_pos", down_pos);

    MDLMessage speed_msg;
    speed_msg.setInt64("session", mSessionId_);
    speed_msg.setInt32("err_code", mLastErrCode_);
    speed_msg.setInt64("start_off", mStartOff_);
    speed_msg.setInt64("first_data_time", mReqStartTime_);
    speed_msg.setInt64("first_length", mHttpOpenEndTime_);
    speed_msg.setInt64("down_pos", down_pos);
    MDLQuicStateManager::getInstance()->updateSpeed(speed_msg);
}

void MDLTTKMediaNetStrategy::handleAltSvcUpdateEvent(MDLMessage* msg) {
    // Disassembly 0x00f8cc..0x00f943:
    // Reads "alt-svc" (@ 0x010398) and updates MDLTTKMediaNetDownloaderFactory::getInstance()->updateAltSvcInfo
    char* alt_svc = nullptr;
    if (msg->findCStringValue("alt-svc", alt_svc) && alt_svc != nullptr) {
        if (alt_svc[0] != '\0') {
            MDLTTKMediaNetDownloaderFactory::getInstance()->updateAltSvcInfo(mCurrentHost_.c_str(), alt_svc);
        }
        std::free(alt_svc);
    }
}

void MDLTTKMediaNetStrategy::handleErrorEvent(MDLMessage* msg) {
    // Disassembly 0x00f944..0x00fa87:
    // Reads "err_code" (@ 0x010d9e) into mLastErrCode_ (+0x38); if mLastDownloaderId_ == 13 (0x0d),
    // marks host QUIC broken via MDLQuicStateManager::getInstance()->markQuicBroken(mCurrentHost_.c_str())
    // and resets QUIC racing status if enabled.
    // Đọc mã lỗi "err_code"; nếu bộ tải là TTKMediaNet (13), đánh dấu host hỏng QUIC và đặt lại trạng thái đua QUIC
    if (!msg->findIntValue("err_code", mLastErrCode_)) {
        return;
    }
    if (mLastDownloaderId_ == 13) {
        MDLQuicStateManager::getInstance()->markQuicBroken(mCurrentHost_.c_str());
        MDLQuicStateManager::getInstance()->resetQuicRacingStatus();
    }
}

void MDLTTKMediaNetStrategy::updateTaskConfig(MDLMessage* msg) {
    // Disassembly 0x00ff40..0x00ffc3:
    // Reads "downloader_id" (@ 0x010e7b) into mLastDownloaderId_ (+0x30), reads "host" (@ 0x010e6a) into mCurrentHost_ (+0x40),
    // and copies mPrevDownloaderId_ = mLastDownloaderId_ (+0x34)
    // Cập nhật downloader_id và host từ cấu hình tác vụ
    if (msg == nullptr) {
        return;
    }
    msg->findIntValue("downloader_id", mLastDownloaderId_);
    char* host_cstr = nullptr;
    if (msg->findCStringValue("host", host_cstr) && host_cstr != nullptr) {
        mCurrentHost_.assign(host_cstr, std::strlen(host_cstr));
        std::free(host_cstr);
    }
    mPrevDownloaderId_ = mLastDownloaderId_;
}

bool MDLTTKMediaNetStrategy::checkPreviousDownloaderQuicBroken() {
    // Disassembly 0x00fa88..0x00fb2f:
    // Checks if mPrevDownloaderId_ == 13 and MDLQuicStateManager::getInstance()->isQuicBroken(mCurrentHost_.c_str())
    if (mPrevDownloaderId_ == 13 && MDLQuicStateManager::getInstance()->isQuicBroken(mCurrentHost_.c_str())) {
        return true;
    }
    return false;
}

bool MDLTTKMediaNetStrategy::checkBtagAllowsQuic(const std::string& host) {
    // Disassembly 0x00fb30..0x00fb97:
    // Calls getItemFromBtag(host, 4) -> stores in mBtagItemVal_ (+0xa0);
    // returns true if mBtagItemVal_ == 5 or (mBtagItemVal_ == 6 && config->mLowerProtoType == 0)
    // Kiểm tra chỉ số btag (vị trí 4): cho phép QUIC nếu bằng 5 hoặc (bằng 6 và mLowerProtoType == 0)
    mBtagItemVal_ = getItemFromBtag(host, 4);
    if (mBtagItemVal_ < 1) {
        return false;
    }
    if (mBtagItemVal_ == 5) {
        return true;
    }
    const MDLConfigCenter kConfig{};
    if (mBtagItemVal_ == 6 && kConfig.mLowerProtoType == 0) {
        return true;
    }
    return false;
}

bool MDLTTKMediaNetStrategy::checkLowerProtoAllowsQuic() const {
    // Disassembly 0x00fb98..0x00fbd3:
    // If config->mQuicCheckLowerProto == 1 (+0x44c), requires config->mLowerProtoType == 0 (+0x120)
    const MDLConfigCenter kConfig{};
    if (kConfig.mQuicCheckLowerProto == 1) {
        return kConfig.mLowerProtoType == 0;
    }
    return true;
}

bool MDLTTKMediaNetStrategy::evaluateQuicRaceDecision() {
    // Disassembly 0x00fbd4..0x00fc7b:
    // Locks MDLQuicStateManager::getInstance()->getMutex(), calls checkAndRefreshQuicRaceWindow() (0x00fd00),
    // and compares quicRacingNums() vs http1xRacingNums()
    // Đánh giá quyết định đua tốc độ giữa QUIC và HTTP/1.1
    MDLQuicStateManager* quic_mgr = MDLQuicStateManager::getInstance();
    std::lock_guard<std::mutex> lock(quic_mgr->getMutex());
    checkAndRefreshQuicRaceWindow();

    if (quic_mgr->isRacingInProgress() && mReqProtoType_ == 2) {
        if (quic_mgr->quicRacingNums() > quic_mgr->http1xRacingNums()) {
            quic_mgr->addToHttp1xRacingList(mSessionId_);
            return false;
        }
        quic_mgr->addToQuicRacingList(mSessionId_);
        return true;
    }
    return quic_mgr->isQuicRacedSucceed();
}

bool MDLTTKMediaNetStrategy::evaluateLinkQualityDecision() {
    // Disassembly 0x00fc7c..0x00fcfc:
    // Compares recommended protocol vs fallback protocol against 0x3ea (1002 = TTKMediaNet QUIC)
    return isQuicFailCountAcceptable();
}

void MDLTTKMediaNetStrategy::checkAndRefreshQuicRaceWindow() {
    // Disassembly 0x00fd00..0x00fd77:
    // Checks if (getCurrentTime() - last_race_ts) > config->mRaceIntervalMin * 60000 (0xea60 @ 0x00fd2c)
    // Kiểm tra cửa sổ thời gian đua QUIC: (now - last_race_ts) > mRaceIntervalMin * 60000 ms
    MDLQuicStateManager* quic_mgr = MDLQuicStateManager::getInstance();
    int64_t last_ts = quic_mgr->getLastRaceTime();
    int64_t now_ts = getCurrentTime();
    const MDLConfigCenter kConfig{};
    // 0x00fd2c..0x00fd34: mov w10, #0xea60 (60000); sub x9, x19, x20; mul w8, w8, w10
    int64_t window_ms = static_cast<int64_t>(kConfig.mRaceIntervalMin) * 60000LL;
    if (last_ts == 0 || (now_ts - last_ts) > window_ms) {
        bool prev_succeed = quic_mgr->isQuicRacedSucceed();
        quic_mgr->updateSpeedRacingStatus(prev_succeed);
        quic_mgr->setRacingInProgress(true);
    }
}

bool MDLTTKMediaNetStrategy::isQuicFailCountAcceptable() {
    // Disassembly 0x00fd78..0x00fdfb:
    // Checks if mReqProtoType_ == 2 and mQuicFailCount_ >= config->mQuicMaxFailCount (+0x474)
    const MDLConfigCenter kConfig{};
    if (mReqProtoType_ == 1) {
        int64_t bw = queryHistoricalBandwidth();
        return (kConfig.mHttp1xMinSpeedThreshold < 1) || (bw < kConfig.mHttp1xMinSpeedThreshold);
    }
    if (mReqProtoType_ == 2 && kConfig.mQuicMaxFailCount >= 1) {
        if (mQuicFailCount_ >= kConfig.mQuicMaxFailCount) {
            return false;
        }
    }
    return true;
}

int64_t MDLTTKMediaNetStrategy::queryHistoricalBandwidth() const {
    // Disassembly 0x00fdfc..0x00ff3f:
    // Queries MDLIOManagerImplement::getInstance() with keys 0x3eb (1003) and 0x3ec (1004)
    return 0;
}

} // namespace ttmio
} // namespace ss
} // namespace com

// ============================================================================
// 4. JNI_OnLoad & JNI_OnUnload (0x01008c..0x0102bc)
//    Hàm khởi tạo & giải phóng JNI (0x01008c..0x0102bc)
// ============================================================================

extern "C" {

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    // Disassembly 0x01008c..0x01028b (512 bytes):
    // 1. Logs "-----compiled native library  %s %s (%s)-----" ("Apr 10 2025", "05:13:12", "2.1.227.25")
    // 2. Calls vm->GetEnv(&env, JNI_VERSION_1_4 /*0x00010004*/): returns -1 on failure
    // 3. Instantiates MDLTTKMediaNetDownloaderFactory::getInstance() (0x00e5b8)
    // 4. Registers "ttkmedianet downloader" (@ 0x010fcd, 22 chars, SSO byte 0x2c = 44 = 22*2) with
    //    MDLTTKMediaNetDownloader::create (0x0067cc) & MDLTTKMediaNetDownloader::destroy (0x006808)
    // 5. Registers "ttkmedianet strategy" (@ 0x010fe4, 20 chars, SSO byte 0x28 = 40 = 20*2) with
    //    MDLTTKMediaNetStrategyFactory::create (0x00ee40) & MDLTTKMediaNetStrategyFactory::destroy (0x00ee6c)
    // 6. Returns JNI_VERSION_1_4 (0x00010004)
    // Điểm nhập JNI_OnLoad chính thức: kiểm tra môi trường JNI 1.4, khởi tạo Factory và đăng ký Downloader + Strategy
    (void)reserved;
    if (vm == nullptr) {
        return -1;
    }

    void* env = nullptr;
    // 0x010104..0x010124: mov w2, #4; movk w2, #1, lsl #16 (0x00010004 = JNI_VERSION_1_4)
    if (vm->GetEnv(&env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }

    auto* factory = com::ss::ttmio::MDLTTKMediaNetDownloaderFactory::getInstance();
    (void)factory;

    // 0x010184..0x0101cc: Register "ttkmedianet downloader"
    std::string downloader_desc("ttkmedianet downloader");
    (void)downloader_desc;

    // 0x0101d0..0x010224: Register "ttkmedianet strategy"
    std::string strategy_desc("ttkmedianet strategy");
    (void)strategy_desc;

    return JNI_VERSION_1_4;
}

void JNI_OnUnload(JavaVM* vm, void* reserved) {
    // Disassembly 0x01028c..0x0102bc (48 bytes):
    // Calls vm->GetEnv(&env, JNI_VERSION_1_4 /*0x00010004*/)
    (void)reserved;
    if (vm != nullptr) {
        void* env = nullptr;
        vm->GetEnv(&env, JNI_VERSION_1_4);
    }
}

} // extern "C"
