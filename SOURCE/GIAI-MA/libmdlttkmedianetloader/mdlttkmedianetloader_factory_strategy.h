/**
 * @file mdlttkmedianetloader_factory_strategy.h
 * @brief Declarations of MDLTTKMediaNetDownloaderFactory, MDLTTKMediaNetStrategyFactory, MDLTTKMediaNetStrategy, and JNI Registration
 *        Khai báo các lớp MDLTTKMediaNetDownloaderFactory, MDLTTKMediaNetStrategyFactory, MDLTTKMediaNetStrategy và đăng ký JNI
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - MDLTTKMediaNetDownloaderFactory (0x00e13c..0x00eb4b, vtable @ 0x0176c8..0x017790, RTTI @ 0x017758):
 *   - Inherits MDLTTKMediaNetDownloaderFactoryBase (+0x00) and TTKMediaNet::TTKMediaNetMgr::Delegate (+0x08)
 *   - Singleton pointer @ 0x018000, mutex @ 0x018008, guard variable @ 0x018030
 * - MDLTTKMediaNetStrategyFactory (0x00eb4c..0x00ee97, vtable @ 0x0177e0..0x017800, RTTI @ 0x017898):
 *   - Singleton in .bss @ 0x018038..0x01807f (72 bytes), guard variable @ 0x018080
 *   - Reference-counted linked list of MDLTTKMediaNetStrategy instances keyed by strategy_id
 * - MDLTTKMediaNetStrategy (0x00ee98..0x01000b, vtable @ 0x017800..0x017888, RTTI @ 0x0178c0, size 0xa8 = 168 bytes):
 *   - Inherits MDLRangeRequestStrategy (+0x00) and MDLStrategy
 * - JNI_OnLoad (0x01008c..0x01028b) & JNI_OnUnload (0x01028c..0x0102bc)
 */

#ifndef NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_FACTORY_STRATEGY_H_
#define NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_FACTORY_STRATEGY_H_

#include "mdlttkmedianetloader_types.h"
#include "mdlttkmedianetloader_detect_downloader.h"
#include "mdlttkmedianetloader_downloader.h"

#include <jni.h>
#include <list>

namespace com {
namespace ss {
namespace ttmio {

// ============================================================================
// 1. MDLTTKMediaNetDownloaderFactory (0x00e13c..0x00eb4b)
//    Nhà máy khởi tạo và quản lý mạng MDLTTKMediaNetDownloaderFactory
// ============================================================================

/**
 * @brief Singleton factory managing TTKMediaNetMgr and QUIC detection (`0x00e13c..0x00eb4b`)
 *        Nhà máy đơn bản quản lý TTKMediaNetMgr và thăm dò QUIC (`0x00e13c..0x00eb4b`)
 *
 * Exact Binary Layout (0x30 = 48 bytes, allocated @ 0x00e5f4):
 * - +0x00: vptr MDLTTKMediaNetDownloaderFactoryBase (0x0176d8)
 * - +0x08: vptr TTKMediaNet::TTKMediaNetMgr::Delegate (0x017718)
 * - +0x10: TTKMediaNet::TTKMediaNetMgr* mNetworkMgr (created via CreateNetworkMgr() @ 0x00e27c)
 * - +0x18: std::shared_ptr<MDLTTKMediaNetDetectDownloader> mDetectDownloader (16 bytes, created @ 0x00e290)
 * - +0x28: uint8_t mIsInitialized (set to 1 @ 0x00e278, cleared to 0 @ 0x00e520)
 */
class MDLTTKMediaNetDownloaderFactory
    : public MDLTTKMediaNetDownloaderFactoryBase,
      public TTKMediaNet::TTKMediaNetMgr::Delegate {
public:
    /**
     * @brief Double-checked locking singleton accessor (0x00e5b8..0x00e67f)
     *        Phương thức truy cập đơn bản khóa kiểm tra kép (0x00e5b8..0x00e67f)
     */
    static MDLTTKMediaNetDownloaderFactory* getInstance();

    MDLTTKMediaNetDownloaderFactory();
    ~MDLTTKMediaNetDownloaderFactory() override;

    // MDLTTKMediaNetDownloaderFactoryBase overrides
    void init() override;                                                     // 0x00e260..0x00e31f
    void uninit() override;                                                   // 0x00e50c..0x00e5b7
    void startQuicDetect(const char* host) override;                          // 0x00e680..0x00e70f
    bool preconnectUrl(const char* url) override;                             // 0x00e710..0x00e7df
    TTKMediaNet::TTKMediaNetMgr* getNetworkMgr() override;                    // 0x00e7e0..0x00e7e7
    void updateAltSvcInfo(const char* host, const char* alt_svc) override;    // 0x00e7e8..0x00e8b7
    bool isHostSupportQuic(const char* host) override;                        // 0x00e8b8..0x00e96b

    // TTKMediaNet::TTKMediaNetMgr::Delegate overrides
    void OnAltSvcUpdated(const char* host, const char* alt_svc) override;
    bool IsHostSupportQuic(const char* host) override;
    int32_t OnCustomVerify(void* ssl, void* cert_chain, const char* host, int32_t port) override; // 0x00e96c..0x00e983
    void OnNetLog(const char* log_msg) override;                              // 0x00e984..0x00e98b

    // Additional virtual methods in vtable (0x00e98c..0x00e9bb)
    void onEvent(int32_t event_id);                                           // 0x00e98c..0x00e9b3
    bool isInitialized() const;                                               // 0x00e9b4..0x00e9b8

private:
    void configureNetworkMgr();                                               // 0x00e320..0x00e50b

private:
    TTKMediaNet::TTKMediaNetMgr* mNetworkMgr_{nullptr};                       // +0x10
    std::shared_ptr<MDLTTKMediaNetDetectDownloader> mDetectDownloader_;       // +0x18
    uint8_t mIsInitialized_{0};                                               // +0x28
};

// ============================================================================
// 2. MDLTTKMediaNetStrategy (0x00ee98..0x01000b)
//    Chiến lược điều phối giao thức và dải byte MDLTTKMediaNetStrategy
// ============================================================================

/**
 * @brief Protocol selection, QUIC racing, and link quality strategy (`0x00ee98..0x01000b`)
 *        Chiến lược lựa chọn giao thức, đua tốc độ QUIC và đánh giá chất lượng liên kết (`0x00ee98..0x01000b`)
 *
 * Exact Binary Layout (0xa8 = 168 bytes, allocated @ 0x00ecc0):
 * - +0x00: vptr MDLRangeRequestStrategy (0x017810)
 * - +0x10: void* mTaskContext (set via vtable +0x30 @ 0x00ffe0)
 * - +0x28: MDLStrategy* mParentStrategy / mCallbackTarget (invoked with keys 0x21=33 @ 0x00fafc, 0x22=34 @ 0x00f1f4)
 * - +0x30: int32_t mLastDownloaderId (-1 @ 0x00ecd8, updated from "downloader_id" @ 0x00ff5c)
 * - +0x34: int32_t mPrevDownloaderId (-1 @ 0x00ecd8, copied from +0x30 @ 0x00ffb0)
 * - +0x38: int32_t mLastErrCode (0 @ 0x00ecec, updated from "err_code" @ 0x00f980)
 * - +0x3c: uint8_t mIsRegisteredListener (0 @ 0x00ecf0, set to 1 @ 0x00ef3c)
 * - +0x40: std::string mCurrentHost (24 bytes, updated from "host" @ 0x00ff88..0x00ffa0)
 * - +0x58: std::string mFileKey (24 bytes, updated from "file_key" @ 0x00f41c..0x00f42c)
 * - +0x70: int64_t mStartOff (-1 @ 0x00ed0c, updated from "start_off" @ 0x00f5bc)
 * - +0x78: int64_t mReqStartTime (0 @ 0x00ed0c, updated from "start-time" @ 0x00f4b4..0x00f51c)
 * - +0x80: int64_t mHttpOpenEndTime (-1 @ 0x00ed00, updated from "httpopen_end_time" @ 0x00f68c)
 * - +0x88: int32_t mReqProtoType (-1 @ 0x00ed00, 1=HTTP/1.1, 2=QUIC)
 * - +0x8c: int32_t mQuicFailCount (-1 @ 0x00ed00, copied from task config +0x268 @ 0x00f428)
 * - +0x90: int32_t mTaskType (-1 @ 0x00ed04, copied from task config +0x08 @ 0x00f434)
 * - +0x94: int32_t mPreloadType (0 @ 0x00ed04, copied from task config +0x178 @ 0x00f43c)
 * - +0x98: int64_t mSessionId (0 @ 0x00ed04, updated from "session" @ 0x00efa8..0x00efb4)
 * - +0xa0: int32_t mBtagItemVal (0 @ 0x00ecf4, parsed via getItemFromBtag(host, 4) @ 0x00fb4c..0x00fb68)
 */
class MDLTTKMediaNetStrategy : public MDLRangeRequestStrategy {
public:
    MDLTTKMediaNetStrategy();
    ~MDLTTKMediaNetStrategy() override;                                       // 0x00ee98..0x00ef1f

    void onParameterUpdated() override;                                       // 0x00ef20..0x00ef4b
    int32_t onEvent(int32_t event_type, MDLMessage* msg) override;            // 0x00ef4c..0x00f25b
    void handleError(int32_t event_type, MDLMessage* msg) override;           // 0x00f25c..0x00fa87
    void updateTaskConfig(MDLMessage* msg) override;                          // 0x00ff40..0x00ffc3

private:
    int32_t evaluateProtocolAndConfigureTask(MDLMessage* msg);                // 0x00ef70..0x00f25b
    void extractTaskConfigFields(MDLMessage* msg);                            // 0x00f3d8..0x00f44f
    void handleRequestStartTime(MDLMessage* msg);                             // 0x00f450..0x00f533
    void handleRequestStartOffset(MDLMessage* msg);                           // 0x00f534..0x00f617
    void handleHttpOpenEndTime(MDLMessage* msg);                              // 0x00f618..0x00f6a3
    void handleRequestCompletionMetrics(MDLMessage* msg);                     // 0x00f6a4..0x00f8cb
    void handleAltSvcUpdateEvent(MDLMessage* msg);                            // 0x00f8cc..0x00f943
    void handleErrorEvent(MDLMessage* msg);                                   // 0x00f944..0x00fa87
    bool checkPreviousDownloaderQuicBroken();                                 // 0x00fa88..0x00fb2f
    bool checkBtagAllowsQuic(const std::string& host);                        // 0x00fb30..0x00fb97
    bool checkLowerProtoAllowsQuic() const;                                   // 0x00fb98..0x00fbd3
    bool evaluateQuicRaceDecision();                                          // 0x00fbd4..0x00fc7b
    bool evaluateLinkQualityDecision();                                       // 0x00fc7c..0x00fcfc
    void checkAndRefreshQuicRaceWindow();                                     // 0x00fd00..0x00fd77
    bool isQuicFailCountAcceptable();                                         // 0x00fd78..0x00fdfb
    int64_t queryHistoricalBandwidth() const;                                 // 0x00fdfc..0x00ff3f

private:
    void* mTaskContext_{nullptr};                                             // +0x10
    MDLStrategy* mParentStrategy_{nullptr};                                   // +0x28
    int32_t mLastDownloaderId_{-1};                                           // +0x30
    int32_t mPrevDownloaderId_{-1};                                           // +0x34
    int32_t mLastErrCode_{0};                                                 // +0x38
    uint8_t mIsRegisteredListener_{0};                                        // +0x3c
    std::string mCurrentHost_;                                                // +0x40
    std::string mFileKey_;                                                    // +0x58
    int64_t mStartOff_{-1};                                                   // +0x70
    int64_t mReqStartTime_{0};                                                // +0x78
    int64_t mHttpOpenEndTime_{-1};                                            // +0x80
    int32_t mReqProtoType_{-1};                                               // +0x88
    int32_t mQuicFailCount_{-1};                                              // +0x8c
    int32_t mTaskType_{-1};                                                   // +0x90
    int32_t mPreloadType_{0};                                                 // +0x94
    int64_t mSessionId_{0};                                                   // +0x98
    int32_t mBtagItemVal_{0};                                                 // +0xa0
};

// ============================================================================
// 3. MDLTTKMediaNetStrategyFactory (0x00eb4c..0x00ee97)
//    Nhà máy quản lý vòng đời chiến lược MDLTTKMediaNetStrategyFactory
// ============================================================================

/**
 * @brief Reference-counted strategy factory singleton (`0x00eb4c..0x00ee97`)
 *        Nhà máy đơn bản quản lý chiến lược có đếm tham chiếu (`0x00eb4c..0x00ee97`)
 *
 * Node Layout allocated @ 0x00ecb0 (0x10 = 16 bytes):
 * - +0x00: MDLTTKMediaNetStrategy* strategy_ptr
 * - +0x08: int32_t strategy_id
 * - +0x0c: int32_t ref_count
 */
class MDLTTKMediaNetStrategyFactory {
public:
    struct StrategyEntry {
        MDLTTKMediaNetStrategy* strategy{nullptr}; // +0x00
        int32_t strategy_id{0};                    // +0x08
        int32_t ref_count{0};                      // +0x0c
    };

    static MDLTTKMediaNetStrategyFactory* getInstance();                      // 0x00eb4c..0x00ebf3
    static MDLStrategy* create(int32_t strategy_id);                          // 0x00ee40..0x00ee6b
    static void destroy(MDLStrategy* strategy);                               // 0x00ee6c..0x00ee97

    MDLTTKMediaNetStrategyFactory();
    virtual ~MDLTTKMediaNetStrategyFactory();                                 // 0x00ebf4..0x00ec5b

    virtual MDLStrategy* acquireStrategy(int32_t strategy_id);                // 0x00ec5c..0x00ed6b
    virtual void releaseStrategy(MDLStrategy* strategy);                      // 0x00ed6c..0x00ee3f

private:
    std::mutex mMutex_;                                                       // +0x08
    std::list<StrategyEntry*> mEntries_;                                      // +0x30
};

} // namespace ttmio
} // namespace ss
} // namespace com

extern "C" {
/**
 * @brief Exported JNI entry point at 0x01008c (512 bytes) and JNI_OnUnload at 0x01028c (48 bytes)
 *        Điểm nhập JNI xuất khẩu tại 0x01008c (512 byte) và JNI_OnUnload tại 0x01028c (48 byte)
 */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);
void JNI_OnUnload(JavaVM* vm, void* reserved);
}

#endif // NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_FACTORY_STRATEGY_H_
