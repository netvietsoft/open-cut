/**
 * @file mdlttkmedianetloader_detect_downloader.h
 * @brief Declaration of com::ss::ttmio::MDLTTKMediaNetDetectDownloader (0x00594c..0x006330)
 *        Khai báo lớp com::ss::ttmio::MDLTTKMediaNetDetectDownloader (0x00594c..0x006330)
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - Vtable: 0x016dd0..0x016e00 (RTTI @ 0x017030, Name "N3com2ss5ttmio30MDLTTKMediaNetDetectDownloaderE" @ 0x0103f3)
 * - Base Classes / Lớp cơ sở:
 *   1. com::ss::ttmio::MIODnsResolveListener (+0x00, RTTI @ 0x017010)
 *   2. std::__ndk1::enable_shared_from_this<MDLTTKMediaNetDetectDownloader> (+0x08, RTTI @ 0x017020)
 * - Async DNS Lambda:
 *   - _ZN3com2ss5ttmio30MDLTTKMediaNetDetectDownloader11quicConnectEPKcE3$_1 (RTTI @ 0x010754, vtable @ 0x017470)
 */

#ifndef NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_DETECT_DOWNLOADER_H_
#define NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_DETECT_DOWNLOADER_H_

#include "mdlttkmedianetloader_types.h"

namespace com {
namespace ss {
namespace ttmio {

/**
 * @brief Lightweight QUIC preconnect / reachability probe downloader for TTKMediaNet
 *        Bộ tải thăm dò khả năng kết nối trước (Preconnect) QUIC gọn nhẹ cho TTKMediaNet
 *
 * Exact Struct Layout (0x70 = 112 bytes, allocated @ 0x00e9cc inside 0x88-byte shared_ptr control block):
 * - +0x00: vptr (MIODnsResolveListener)
 * - +0x08: std::weak_ptr<MDLTTKMediaNetDetectDownloader> __weak_this_ (16 bytes)
 * - +0x18: MIOEventAdapter* mEventAdapter (allocated 0x30 bytes with tag "medianet.det" @ 0x0059a8..0x0059d4)
 * - +0x20: MDLTimedEventQueue* mTimedEventQueue (allocated 0xa0 bytes @ 0x0059ec..0x005a04)
 * - +0x28: std::shared_ptr<void> mSharedDnsParser (16 bytes, acquired via MIODNSParserManager::getInstance() @ 0x005c34)
 * - +0x38: std::string mHost (24 bytes, assigned in quicConnect @ 0x005be4..0x005c04)
 * - +0x50: std::string mPortStr (24 bytes, assigned in quicConnect @ 0x005d70..0x005db4)
 * - +0x68: int32_t mDnsParseTaskId (4 bytes, initialized to 0 @ 0x005988, updated @ 0x005e74)
 */
class MDLTTKMediaNetDetectDownloader
    : public MIODnsResolveListener,
      public std::enable_shared_from_this<MDLTTKMediaNetDetectDownloader> {
public:
    /**
     * @brief Constructor (0x00594c..0x005a17)
     *        Hàm khởi tạo (0x00594c..0x005a17)
     */
    MDLTTKMediaNetDetectDownloader();

    /**
     * @brief Destructor (0x005aac..0x005b43, deleting destructor @ 0x005b9c..0x005bbf)
     *        Hàm hủy (0x005aac..0x005b43, hàm hủy giải phóng bộ nhớ @ 0x005b9c..0x005bbf)
     */
    ~MDLTTKMediaNetDetectDownloader() override;

    /**
     * @brief Initiates DNS resolution and QUIC preconnect for the target host/URL (0x005bc0..0x005f6f)
     *        Khởi chạy phân giải DNS và kết nối trước QUIC cho máy chủ/URL đích (0x005bc0..0x005f6f)
     */
    void quicConnect(const char* url);

    /**
     * @brief Parses the first IP from comma-delimited ip_list and triggers QUIC preconnect (0x005f70..0x0060a3)
     *        Trích xuất IP đầu tiên từ danh sách cách nhau bởi dấu phẩy và kích hoạt QUIC preconnect (0x005f70..0x0060a3)
     */
    int32_t doQuicConnect(const std::string& port_str, std::string ip_list);

    /**
     * @brief Dispatches TTKMediaNetPreconnectParam to TTKMediaNetMgr::Preconnect (0x0061f8..0x0062cb)
     *        Gửi cấu trúc TTKMediaNetPreconnectParam tới TTKMediaNetMgr::Preconnect (0x0061f8..0x0062cb)
     */
    int32_t executeQuicPreconnect(const char* host, const char* ip);

    /**
     * @brief Callback invoked when asynchronous DNS resolution completes (0x0062cc..0x006333)
     *        Hàm gọi lại được kích hoạt khi phân giải DNS bất đồng bộ hoàn tất (0x0062cc..0x006333)
     */
    void onResolve(std::string host, std::string ip_list, int32_t dns_type, int32_t err_code, int32_t ttl) override;

private:
    void* mEventAdapter_{nullptr};             // +0x18 ("medianet.det")
    void* mTimedEventQueue_{nullptr};          // +0x20
    std::shared_ptr<void> mSharedDnsParser_;   // +0x28
    std::string mHost_;                        // +0x38
    std::string mPortStr_;                     // +0x50
    int32_t mDnsParseTaskId_{0};               // +0x68
};

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // NEXTAI_OPENCUT_MDLTTKMEDIANETLOADER_DETECT_DOWNLOADER_H_
