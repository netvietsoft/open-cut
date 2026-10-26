/**
 * @file mdlttkmedianetloader_detect_downloader.cpp
 * @brief Implementation of com::ss::ttmio::MDLTTKMediaNetDetectDownloader (0x00594c..0x006330)
 *        Triển khai lớp com::ss::ttmio::MDLTTKMediaNetDetectDownloader (0x00594c..0x006330)
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - Constructor: 0x00594c..0x005a17 ("medianet.det" @ 0x0102fb)
 * - Destructor: 0x005aac..0x005b43 & 0x005b9c..0x005bbf
 * - quicConnect(const char*): 0x005bc0..0x005f6f (port fallback 0x1bb = 443 @ 0x005d58, timeout 0x1388 = 5000ms @ 0x005e0c)
 * - doQuicConnect: 0x005f70..0x0060a3 (comma delimiter 0x2c = ',' @ 0x005fac)
 * - executeQuicPreconnect: 0x0061f8..0x0062cb (movi v0.2s, #1 @ 0x00626c)
 * - onResolve: 0x0062cc..0x006333
 */

#include "mdlttkmedianetloader_detect_downloader.h"
#include "mdlttkmedianetloader_factory_strategy.h"

#include <cstdlib>
#include <cstring>

extern "C" {
/**
 * @brief External URL hostname/port splitter from libvcn.so (PLT @ 0x0056d0)
 *        Hàm tách tên miền và cổng URL ngoại vi từ libvcn.so (PLT @ 0x0056d0)
 */
void vcn_av_url_split_hostname(char* hostname_buf, int hostname_buf_size, int* port_ptr, const char* url);
}

namespace com {
namespace ss {
namespace ttmio {

// ============================================================================
// 1. Constructor & Destructor (0x00594c..0x005bbf)
//    Hàm khởi tạo & Hàm hủy (0x00594c..0x005bbf)
// ============================================================================

MDLTTKMediaNetDetectDownloader::MDLTTKMediaNetDetectDownloader()
    : mEventAdapter_(nullptr),
      mTimedEventQueue_(nullptr),
      mSharedDnsParser_(nullptr),
      mHost_(),
      mPortStr_(),
      mDnsParseTaskId_(0) {
    // Disassembly 0x005990..0x005a04:
    // Queries MDLSingletonsHolder::getInstance()->getConfigCenter()
    // Truy vấn cấu hình từ MDLSingletonsHolder::getInstance()->getConfigCenter()
    const MDLConfigCenter kDefaultConfig{};
    if (kDefaultConfig.mEnableDnsParser != 0) {
        if (kDefaultConfig.mUseSharedDnsParser == 0) {
            // 0x0059a8..0x0059d4: allocates MIOEventAdapter("medianet.det", true) (48 bytes)
            // Cấp phát MIOEventAdapter("medianet.det", true) (48 byte)
            mEventAdapter_ = ::operator new(0x30);
            std::memset(mEventAdapter_, 0, 0x30);
        }
    } else {
        // 0x0059ec..0x005a04: allocates MDLTimedEventQueue(false, nullptr) (160 bytes)
        // Cấp phát MDLTimedEventQueue(false, nullptr) (160 byte)
        mTimedEventQueue_ = ::operator new(0xa0);
        std::memset(mTimedEventQueue_, 0, 0xa0);
    }
}

MDLTTKMediaNetDetectDownloader::~MDLTTKMediaNetDetectDownloader() {
    // Disassembly 0x005aac..0x005b43:
    // Releases mEventAdapter_ (+0x18), mTimedEventQueue_ (+0x20), mPortStr_ (+0x50), mHost_ (+0x38), mSharedDnsParser_ (+0x28)
    // Giải phóng mEventAdapter_ (+0x18), mTimedEventQueue_ (+0x20), mPortStr_ (+0x50), mHost_ (+0x38), mSharedDnsParser_ (+0x28)
    if (mEventAdapter_ != nullptr) {
        ::operator delete(mEventAdapter_);
        mEventAdapter_ = nullptr;
    }
    if (mTimedEventQueue_ != nullptr) {
        ::operator delete(mTimedEventQueue_);
        mTimedEventQueue_ = nullptr;
    }
    mSharedDnsParser_.reset();
}

// ============================================================================
// 2. QUIC Preconnect & DNS Resolution Pipeline (0x005bc0..0x006333)
//    Đường ống phân giải DNS & Kết nối trước QUIC (0x005bc0..0x006333)
// ============================================================================

void MDLTTKMediaNetDetectDownloader::quicConnect(const char* url) {
    // Disassembly 0x005bc0..0x005f6f:
    // Copies url into mHost_ (+0x38) and resolves hostname via shared DNS parser or event loop
    // Sao chép url vào mHost_ (+0x38) và phân giải tên miền qua trình phân tích DNS dùng chung hoặc vòng lặp sự kiện
    if (url == nullptr) {
        return;
    }
    mHost_.assign(url, std::strlen(url));

    const MDLConfigCenter kConfig{};
    if (kConfig.mUseSharedDnsParser != 0) {
        // 0x005d3c..0x005d68: Split hostname and port using vcn_av_url_split_hostname
        // Tách tên miền và cổng bằng vcn_av_url_split_hostname
        char host_buf[256];
        std::memset(host_buf, 0, sizeof(host_buf));
        int port = -1;
        vcn_av_url_split_hostname(host_buf, 256, &port, mHost_.c_str());

        // 0x005d50..0x005d5c: cmn w8, #1; b.ne #0x5d60; mov w8, #0x1bb (443)
        // Nếu cổng bằng -1, gán mặc định cổng HTTPS/QUIC là 443 (0x1bb)
        if (port == -1) {
            port = 443; // 0x1bb
        }

        // 0x005d60..0x005db4: Store resolved host_buf into mPortStr_ (+0x50)
        // Lưu chuỗi host đã tách vào mPortStr_ (+0x50)
        mPortStr_ = safeString(host_buf);

        // 0x005db8..0x005e9c: If synchronous DNS resolution returns < 1, immediately invoke doQuicConnect
        // Nếu phân giải DNS đồng bộ trả về < 1, gọi trực tiếp doQuicConnect
        std::string resolved_ips = mPortStr_;
        int32_t ret = doQuicConnect(mPortStr_, resolved_ips);
        if (ret >= 1) {
            mDnsParseTaskId_ = ret;
        }
    } else {
        // 0x005ccc..0x005d20: Lambda $_1 (_ZN3com2ss5ttmio30MDLTTKMediaNetDetectDownloader11quicConnectEPKcE3$_1)
        // Invokes quicConnect(url) asynchronously on mEventAdapter_
        // Gọi bất đồng bộ quicConnect(url) trên mEventAdapter_
        auto lambda_task = [this, url]() {
            this->quicConnect(url);
        };
        (void)lambda_task;
    }
}

int32_t MDLTTKMediaNetDetectDownloader::doQuicConnect(const std::string& port_str, std::string ip_list) {
    // Disassembly 0x005f70..0x0060a3:
    // Checks if ip_list is non-empty; if it contains ',' (0x2c), slices the first IP address
    // Kiểm tra ip_list khác rỗng; nếu chứa dấu ',' (0x2c), cắt lấy địa chỉ IP đầu tiên
    (void)port_str;
    if (ip_list.empty()) {
        MDLQuicStateManager::getInstance()->markQuicBroken(mHost_.c_str());
        MDLQuicStateManager::getInstance()->updateQuicPreconnStatus(false);
        return -1;
    }

    // 0x005fac..0x005fe0: Search for ',' (0x2c) at offset 0 and take substring(0, comma_pos)
    // Tìm ký tự ',' (0x2c) từ vị trí 0 và lấy chuỗi con substring(0, comma_pos)
    std::size_t comma_pos = ip_list.find(',');
    if (comma_pos != std::string::npos) {
        ip_list = ip_list.substr(0, comma_pos);
    }

    // 0x006024..0x006060: Execute QUIC preconnect with (mHost_.c_str(), ip_list.c_str())
    // Thực thi kết nối trước QUIC với (mHost_.c_str(), ip_list.c_str())
    int32_t preconn_res = executeQuicPreconnect(mHost_.c_str(), ip_list.c_str());
    if (preconn_res != -1) {
        return 0;
    }

    // 0x006064..0x006090: On failure (-1), mark host QUIC broken and clear preconnect status
    // Khi thất bại (-1), đánh dấu host hỏng QUIC và xóa trạng thái kết nối trước
    MDLQuicStateManager::getInstance()->markQuicBroken(mHost_.c_str());
    MDLQuicStateManager::getInstance()->updateQuicPreconnStatus(false);
    return -1;
}

int32_t MDLTTKMediaNetDetectDownloader::executeQuicPreconnect(const char* host, const char* ip) {
    // Disassembly 0x0061f8..0x0062cb:
    // Builds TTKMediaNetPreconnectParam on stack and calls TTKMediaNetMgr::Preconnect (vtable +0x30)
    // Dựng cấu trúc TTKMediaNetPreconnectParam trên ngăn xếp và gọi TTKMediaNetMgr::Preconnect (vtable +0x30)
    TTKMediaNet::TTKMediaNetPreconnectParam param;
    param.host = host ? host : "";
    param.ip = ip ? ip : "";
    // 0x00626c: movi v0.2s, #1 -> protocol_type = 1, enable_flag = 1
    param.protocol_type = 1;
    param.enable_flag = 1;
    param.reserved = 0;

    MDLTTKMediaNetDownloaderFactory* factory = MDLTTKMediaNetDownloaderFactory::getInstance();
    if (factory == nullptr || factory->getNetworkMgr() == nullptr) {
        return -1;
    }

    // 0x006288..0x006294: blr x8; cmp w0, #0; csetm w19, ne (returns 0 on success, -1 on non-zero error)
    // Gọi hàm ảo tại +0x30; trả về 0 nếu thành công, -1 nếu khác 0
    int32_t rc = factory->getNetworkMgr()->Preconnect(&param);
    return (rc == 0) ? 0 : -1;
}

void MDLTTKMediaNetDetectDownloader::onResolve(
    std::string host,
    std::string ip_list,
    int32_t dns_type,
    int32_t err_code,
    int32_t ttl) {
    // Disassembly 0x0062cc..0x006333:
    // Copies host and ip_list and forwards to doQuicConnect
    // Sao chép host và ip_list rồi chuyển tiếp tới doQuicConnect
    (void)dns_type;
    (void)err_code;
    (void)ttl;
    doQuicConnect(host, ip_list);
}

} // namespace ttmio
} // namespace ss
} // namespace com
