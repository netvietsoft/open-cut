/**
 * @file mdlttkmedianetloader_downloader.h
 * @brief Declaration of com::ss::ttmio::MDLTTKMediaNetDownloader (0x006334..0x00a58b)
 *        Khai báo lớp com::ss::ttmio::MDLTTKMediaNetDownloader (0x006334..0x00a58b)
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - Multiple-Inheritance Vtable @ 0x016e00..0x017010 (RTTI @ 0x017098, Name "N3com2ss5ttmio24MDLTTKMediaNetDownloaderE" @ 0x0104a0):
 *   1. +0x00: com::ss::ttmio::MIOVodNetAdapter (primary vtable @ 0x016e10)
 *   2. +0x08: std::__ndk1::enable_shared_from_this<MDLTTKMediaNetDownloader> (__weak_this_ @ +0x08..+0x17)
 *   3. +0x10: com::ss::ttmio::MIOListener (secondary vtable @ 0x016f78)
 *   4. +0x18: TTKMediaNet::TTKMediaNetTask::Delegate (secondary vtable @ 0x016fa0)
 *   5. +0x20: com::ss::ttmio::MIODnsResolveListener (secondary vtable @ 0x016ff8)
 * - Object Allocation Size: 0x81d0 (33,232 bytes, allocated in MDLTTKMediaNetDownloader::create @ 0x00c164 -> mov w8, #0x81d0; movk w8, #0)
 *   including an inline 32,768-byte (0x8000) read bounce buffer at offset +0x188..+0x8187!
 */

#ifndef NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_DOWNLOADER_H_
#define NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_DOWNLOADER_H_

#include "mdlttkmedianetloader_types.h"

namespace com {
namespace ss {
namespace ttmio {

/**
 * @brief Event structures emitted to MDLObjectPcIoReq event handler (`0x007774..0x0077f8`, `0x007cd4..0x007d14`, `0x007d80..0x007de4`)
 *        Các cấu trúc sự kiện phát tới trình xử lý sự kiện MDLObjectPcIoReq
 */
struct MDLIoTaskEventCdnHeader {
    void* vptr{nullptr};           // +0x00 (vtable for MDLIoTaskEventCdnHeader @ 0x017f38 -> 0x017138)
    int32_t event_type{6};         // +0x08 (mov w8, #6 @ 0x00777c)
    int32_t padding_0c{0};         // +0x0c
    int64_t timestamp_ms{0};       // +0x10 (getCurrentTime() @ 0x007788)
    uint8_t is_handled{0};         // +0x18
    uint8_t padding_19[7]{};       // +0x19
    int64_t task_seq_id{-1};       // +0x20 (vtable +0xe8 on PcIoReq @ 0x0077c4)
    int64_t content_length{-1};    // +0x28 (mHttpContext->content_length @ 0x0077dc)
    int64_t req_start_offset{-1};  // +0x30 (mHttpContext->req_start_offset @ 0x0077e4)
    int64_t req_end_offset{-1};    // +0x38 (mHttpContext->req_end_offset @ 0x0077e4)
    uint64_t reserved_40{0};       // +0x40
};

struct MDLIoTaskEventSeqDataUpdate {
    void* vptr{nullptr};           // +0x00 (vtable for MDLIoTaskEventSeqDataUpdate @ 0x017f78 -> 0x0173e8)
    int32_t event_type{9};         // +0x08 (mov w8, #9 @ 0x007cd4)
    int32_t padding_0c{0};         // +0x0c
    int64_t timestamp_ms{0};       // +0x10 (getCurrentTime() @ 0x007cdc)
    uint16_t flags{0x0101};        // +0x18 (mov w8, #0x101 @ 0x007ce8)
    uint8_t padding_1a[6]{};       // +0x1a
    int64_t written_bytes{0};      // +0x20 (x20 @ 0x007d04)
    int64_t current_offset{0};     // +0x28 (mCurrentOffset @ 0x007d04)
};

struct MDLIoTaskEventCdnReqDone {
    void* vptr{nullptr};           // +0x00 (vtable for MDLIoTaskEventCdnReqDone @ 0x017f70 -> 0x017428)
    int32_t event_type{8};         // +0x08 (mov w8, #8 @ 0x007d88)
    int32_t padding_0c{0};         // +0x0c
    int64_t timestamp_ms{0};       // +0x10 (getCurrentTime() @ 0x007d94)
    uint8_t is_handled{0};         // +0x18
    uint8_t padding_19[7]{};       // +0x19
    int64_t task_seq_id{-1};       // +0x20 (vtable +0xe8 on PcIoReq @ 0x007dc0)
    void* pc_io_req_raw{nullptr};  // +0x28
};

/**
 * @brief Main TTKMediaNet VOD Downloader class (`com::ss::ttmio::MDLTTKMediaNetDownloader`)
 *        Lớp bộ tải VOD TTKMediaNet chính (`com::ss::ttmio::MDLTTKMediaNetDownloader`)
 *
 * Exact Binary Field Offsets Verified from Disassembly (0x006334..0x00a58b):
 * - +0x0000: vptr MIOVodNetAdapter
 * - +0x0010: vptr MIOListener
 * - +0x0018: vptr TTKMediaNet::TTKMediaNetTask::Delegate
 * - +0x0020: vptr MIODnsResolveListener
 * - +0x0028: std::weak_ptr<MDLTTKMediaNetDownloader> mSelfWeakPtr (16B)
 * - +0x0038: int32_t mState (0 = init, 1 = opened, 3 = closed @ 0x006b48, 0x006eac)
 * - +0x0040: mediakit::vcn::VCNHttpContext* mHttpContext (created via createHttpContext() @ 0x006404)
 * - +0x0048: void* mEventAdapter (allocated 0x30B with tag "medianet" @ 0x00643c..0x006468)
 * - +0x0050: void* mTimedEventQueue / mLocalDnsParser (allocated 0xa0B @ 0x006480 or 0x108B @ 0x008938)
 * - +0x0058: int32_t mDnsTaskId (stored @ 0x008be4)
 * - +0x0060: std::shared_ptr<void> mSharedDnsParser (16B, released @ 0x006610)
 * - +0x0070: void* mCustomDnsHandler (set via key 0x18 @ 0x00698c, invoked in onResolve @ 0x009c88)
 * - +0x0078: TTKMediaNet::TTKMediaNetTask* mMediaNetTask (created @ 0x0095e0, canceled in close @ 0x006ea0)
 * - +0x0080: char* mUrl (set via setStringValue key 0 @ 0x00688c)
 * - +0x0088: int64_t mReqOffset (set in open @ 0x006b98)
 * - +0x0090: int64_t mReqSize (set in open @ 0x006b98)
 * - +0x009c: int32_t mDownloaderId (initialized to mTTKMediaNetGlobalDownloaderId, set via key 1 @ 0x00696c)
 * - +0x00a0: char* mHostOrIpOverride (set via setStringValue key 1 @ 0x0068c4)
 * - +0x00a8: int32_t mMaxFailCount (set via setIntValue @ 0x006994)
 * - +0x00ac: int32_t mOpenTimeoutSec (set via setIntValue @ 0x00699c, multiplied by 1000 @ 0x00965c)
 * - +0x00b0: int32_t mRwTimeoutSec (set via setIntValue @ 0x0069a4, multiplied by 1000 @ 0x009668)
 * - +0x00b8: char* mCustomHeaders (set via setStringValue key 2 @ 0x0068fc)
 * - +0x00d0: int32_t mLowerProtoType (set via setIntValue key 0x14 @ 0x0069b8)
 * - +0x00f0: int32_t mAsyncDnsEventId (initialized to -1 @ 0x0063b8, set @ 0x008cc0)
 * - +0x00f8: int64_t mCurrentOffset (updated in open @ 0x006ba0 and onReadData @ 0x007c9c)
 * - +0x0100: std::string mLowerProtoStr (24B, set via setStringValue key 7 @ 0x006918)
 * - +0x0118: int32_t mQuicEnableFlag (set via setIntValue key 0x15 @ 0x0069c0)
 * - +0x011c: uint8_t mUseRingBufferPool (set from config->mUseRingBufferPool @ 0x006420)
 * - +0x0120: std::atomic<int32_t> mNeedTriggerRead (atomic ldar/stlr @ 0x00724c, 0x007270, 0x007330)
 * - +0x0124: std::atomic<uint8_t> mIsCompletedOrFailed (atomic ldarb/stlrb @ 0x007240, 0x007f88, 0x0080ac, 0x00816c)
 * - +0x0128: char* mResolvedIpList (heap C-string of resolved IPs @ 0x0089c8, 0x008a74, 0x008d8c)
 * - +0x0130: std::string mHostname (24B, extracted by extractHostname @ 0x00a4dc)
 * - +0x0148: std::mutex mListenerMutex (40B, locked around mIoListener access @ 0x006ab0, 0x006ba4)
 * - +0x0170: std::weak_ptr<MIOIoListener> mIoListener (24B: raw ptr +0x170, tag +0x178, control block +0x180)
 * - +0x0188: uint8_t mReadBounceBuffer[0x8000] (32,768B inline buffer passed to ReadData @ 0x007308, 0x007c48)
 * - +0x8188: MDLRingBuffer* mRingBuffer (created in OnResponse @ 0x0076f4 / 0x007724, recycled in dtor @ 0x006570)
 * - +0x8190: std::shared_ptr<void> mPcIoReq (16B, set via setObjectValue key 0x0f when type == 0x3e9 @ 0x006a00..0x006a54)
 * - +0x81a0: std::mutex mPcIoReqMutex (40B, locked around mPcIoReq & mIoEvHandler @ 0x006a0c, 0x00775c)
 * - +0x81c8: void* mIoEvHandler (acquired via MDLObjectPcIoReq::getIoEvHandler @ 0x006a2c, cleared in close @ 0x0070cc)
 */
class MDLTTKMediaNetDownloader
    : public MIOVodNetAdapter,
      public MIOListener,
      public TTKMediaNet::TTKMediaNetTask::Delegate,
      public MIODnsResolveListener {
public:
    /**
     * @brief Factory helper creating a shared_ptr-managed MDLTTKMediaNetDownloader (0x0067cc..0x006807 & 0x00c164)
     *        Hàm trợ giúp tạo đối tượng MDLTTKMediaNetDownloader được quản lý bởi shared_ptr (0x0067cc..0x006807 & 0x00c164)
     */
    static MIOVodNetAdapter* create();

    /**
     * @brief Factory destruction helper (0x006808..0x006818)
     *        Hàm trợ giúp hủy bộ tải (0x006808..0x006818)
     */
    static void destroy(MIOVodNetAdapter* downloader);

    /**
     * @brief Constructor (0x006334..0x0064ab)
     *        Hàm khởi tạo (0x006334..0x0064ab)
     */
    MDLTTKMediaNetDownloader();

    /**
     * @brief Destructor (0x0064ac..0x00662f, non-virtual thunks @ 0x006718..0x0067cb)
     *        Hàm hủy (0x0064ac..0x00662f, các thunk phi ảo @ 0x006718..0x0067cb)
     */
    ~MDLTTKMediaNetDownloader() override;

    // ========================================================================
    // MIOVodNetAdapter Overrides (0x00681c..0x007353)
    // Ghi đè các phương thức của MIOVodNetAdapter (0x00681c..0x007353)
    // ========================================================================
    void setStringValue(int32_t key, const char* val) override;              // 0x00681c..0x00693f
    void setIntValue(int32_t key, int64_t val) override;                     // 0x006940..0x0069c7
    void setObjectValue(int32_t key, void* obj) override;                    // 0x0069c8..0x006a9f
    void setListener(std::weak_ptr<MIOIoListener> listener) override;        // 0x006aa0..0x006adb
    const char* getStringValue(int32_t key) override;                        // 0x006adc..0x006ae3
    int32_t getBoolValue(int32_t key) override;                              // 0x006ae4..0x006aef
    int64_t getIntValue(int32_t key) override;                               // 0x006af0..0x006af7
    int32_t open(int64_t offset, int64_t size) override;                     // 0x006af8..0x006e6f
    int32_t close() override;                                                // 0x006e70..0x0070eb
    int32_t read(uint8_t* buf, int64_t size, int64_t* total_size) override;  // 0x0070ec..0x00727b

    // ========================================================================
    // TTKMediaNet::TTKMediaNetTask::Delegate Overrides (0x007354..0x0087d7)
    // Ghi đè các phương thức Delegate của TTKMediaNetTask (0x007354..0x0087d7)
    // ========================================================================
    void OnResponse(const TTKMediaNet::TTKMediaNetResponseInfo* response) override; // 0x007354..0x007c3b
    void OnReadAvailable(int32_t available_bytes) override;                         // 0x007c3c..0x00807f
    void OnRedirect() override;                                                     // 0x008080..0x008087
    void OnCompleted() override;                                                    // 0x008088..0x00813f
    void OnFailed(int32_t err_code) override;                                       // 0x008140..0x008367
    void OnCanceled() override;                                                     // 0x008368..0x00858b
    void OnTimeout(int32_t timeout_code, int64_t value) override;                   // 0x00858c..0x0087d7

    // ========================================================================
    // MIODnsResolveListener Override (0x009c18..0x00a22f)
    // Ghi đè phương thức MIODnsResolveListener (0x009c18..0x00a22f)
    // ========================================================================
    void onResolve(std::string host, std::string ip_list, int32_t dns_type, int32_t err_code, int32_t ttl) override;

private:
    // Internal helper methods matched 1:1 to binary subroutines
    // Các phương thức nội bộ khớp 1:1 với các hàm con trong nhị phân
    int32_t doOpen(int64_t offset, int64_t size);                            // 0x006b6c..0x006e6f
    void triggerAsyncRead();                                                 // 0x00727c..0x007343
    void parseResponseHeaders(const TTKMediaNet::TTKMediaNetResponseInfo* response); // 0x007820..0x007c33
    void processReadBuffer(uint8_t* data, int32_t len);                      // 0x007c54..0x00805f
    void initHttpContextRange();                                             // 0x0087d8..0x008877
    int32_t initDnsParser();                                                 // 0x008878..0x00897b
    int32_t checkHostIsIpLiteral();                                          // 0x00897c..0x008ab7
    void doDnsParseAndSendRequest();                                         // 0x008ab8..0x008d27
    int32_t onDnsParseCompleted(const std::string& host, const std::string& ip_list, int32_t dns_type); // 0x008d28..0x008fdb
    int32_t sendHttpRequest(const char* url);                                // 0x008fdc..0x009c17
    int32_t startRequestPipeline();                                          // 0x00a230..0x00a4db
    void extractHostname(const char* url);                                   // 0x00a4dc..0x00a58b
    std::string buildQuicHeaderValue();                                      // 0x00aa40..0x00ab63
    int32_t mapLowerProtoToQuicHeaderCode() const;                           // 0x00ace8..0x00ad4f

private:
    std::weak_ptr<MDLTTKMediaNetDownloader> mSelfWeakPtr_;                   // +0x0028
    int32_t mState_{0};                                                      // +0x0038
    mediakit::vcn::VCNHttpContext* mHttpContext_{nullptr};                   // +0x0040
    void* mEventAdapter_{nullptr};                                           // +0x0048 ("medianet")
    void* mTimedEventQueue_{nullptr};                                        // +0x0050
    int32_t mDnsTaskId_{0};                                                  // +0x0058
    std::shared_ptr<void> mSharedDnsParser_;                                 // +0x0060
    void* mCustomDnsHandler_{nullptr};                                       // +0x0070
    TTKMediaNet::TTKMediaNetTask* mMediaNetTask_{nullptr};                   // +0x0078
    char* mUrl_{nullptr};                                                    // +0x0080
    int64_t mReqOffset_{-1};                                                 // +0x0088
    int64_t mReqSize_{-1};                                                   // +0x0090
    int32_t mDownloaderId_{-1};                                              // +0x009c
    char* mHostOverride_{nullptr};                                           // +0x00a0
    int32_t mMaxFailCount_{-1};                                              // +0x00a8
    int32_t mOpenTimeoutSec_{-1};                                            // +0x00ac
    int32_t mRwTimeoutSec_{-1};                                              // +0x00b0
    char* mCustomHeaders_{nullptr};                                          // +0x00b8
    int32_t mLowerProtoType_{-1};                                            // +0x00d0
    int32_t mAsyncDnsEventId_{-1};                                           // +0x00f0
    int64_t mCurrentOffset_{0};                                              // +0x00f8
    std::string mLowerProtoStr_;                                             // +0x0100
    int32_t mQuicEnableFlag_{0};                                             // +0x0118
    uint8_t mUseRingBufferPool_{1};                                          // +0x011c
    std::atomic<int32_t> mNeedTriggerRead_{0};                               // +0x0120
    std::atomic<uint8_t> mIsCompletedOrFailed_{0};                           // +0x0124
    char* mResolvedIpList_{nullptr};                                         // +0x0128
    std::string mHostname_;                                                  // +0x0130
    std::mutex mListenerMutex_;                                              // +0x0148
    std::weak_ptr<MIOIoListener> mIoListener_;                               // +0x0170
    uint8_t mReadBounceBuffer_[0x8000]{};                                    // +0x0188 (32,768 bytes)
    MDLRingBuffer* mRingBuffer_{nullptr};                                    // +0x8188
    std::shared_ptr<void> mPcIoReq_;                                         // +0x8190
    std::mutex mPcIoReqMutex_;                                               // +0x81a0
    void* mIoEvHandler_{nullptr};                                            // +0x81c8
};

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_DOWNLOADER_H_
