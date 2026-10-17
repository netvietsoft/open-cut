// ======================================================================
// RECONSTRUCTED C++ PROTOCOL INTERFACE: libttdemux.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: AVSourceProtocol, AVSourceProtocolFF & Protocol Registry
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: Concrete Implementation with Disassembly Match
// ======================================================================

#pragma once

#include "ttdemux_types.h"
#include <string>
#include <vector>
#include <mutex>

namespace com::ss::ttm::demuxer {

// Forward declaration of AVSourceInput
class AVSourceInput;

// ======================================================================
// EN: AVSourceProtocolLisenter (Observer Interface for Protocol Events)
// VN: Giao diện lắng nghe sự kiện của AVSourceProtocol
// ======================================================================
class AVSourceProtocolLisenter {
public:
    virtual ~AVSourceProtocolLisenter() = default;

    // EN: Callback invoked when file size is resolved
    // VN: Callback kích hoạt khi xác định được kích thước tệp
    virtual void onFileSize(int64_t size) = 0;

    // EN: Callback invoked on IO progress / error info
    // VN: Callback kích hoạt khi có tiến trình IO hoặc thông tin lỗi
    virtual void onIoInfo(int32_t type, int64_t code, const char* extra) = 0;
};

// ======================================================================
// EN: Protocol Range Structure (addRequest & getRange)
// VN: Cấu trúc vùng byte yêu cầu (addRequest & getRange)
// ======================================================================
struct ProtocolRange {
    int64_t start_offset{0};
    int64_t end_offset{0};
    bool active{false};
};

// ======================================================================
// EN: AVSourceProtocol Base Class
// VN: Lớp cơ sở AVSourceProtocol (Quản lý kết nối, giao thức truyền dẫn)
// ======================================================================
class AVSourceProtocol : public com::ss::vcbkit::BaseRef {
protected:
    AVSourceInput* m_parent_input{nullptr};
    AVSourceProtocolLisenter* m_listener{nullptr};
    ProtocolRange m_current_range;
    std::string m_url;
    int64_t m_file_size{-1};
    int64_t m_current_offset{0};
    bool m_is_open{false};
    com::ss::vcbkit::Mutex m_protocol_mutex;

public:
    AVSourceProtocol();
    virtual ~AVSourceProtocol() override;

    // Mangled: _ZN3com2ss3ttm7demuxer16AVSourceProtocol11setListenerEPNS2_24AVSourceProtocolLisenterE (0x8700)
    void setListener(AVSourceProtocolLisenter* listener) noexcept;

    // Mangled: _ZN3com2ss3ttm7demuxer16AVSourceProtocol10addRequestEll (0x8708)
    virtual void addRequest(int64_t start_offset, int64_t end_offset);

    // Mangled: _ZN3com2ss3ttm7demuxer16AVSourceProtocol8getRangeERlS4_ (0x8714)
    virtual void getRange(int64_t& start_offset, int64_t& end_offset);

    // Pure virtual protocol operations matching vtable 0xf910 - 0xf9a0
    virtual int32_t open(const char* url, int64_t offset, int64_t size, AVDictionary** options, AVIOInterruptCB* cb, int32_t flags) = 0;
    virtual int32_t close() = 0;
    virtual int32_t read(uint8_t* buf, int32_t size, int32_t flags) = 0;
    virtual int64_t seek(int64_t offset, int32_t whence) = 0;
    virtual int64_t getFileSize() = 0;
    virtual bool isSeekable() const noexcept { return true; }

    inline const std::string& getUrl() const noexcept { return m_url; }
    inline bool isOpen() const noexcept { return m_is_open; }

    // Static registry methods
    // Mangled: _ZN3com2ss3ttm7demuxer16AVSourceProtocol16registerProtocolEPNS2_20AVSourceProtocolProbE (0x84c4)
    static int32_t registerProtocol(void* probe_struct);

    // Mangled: _ZN3com2ss3ttm7demuxer16AVSourceProtocol14createProtocolEPKcPNS2_13AVSourceInputE (0x857c)
    static AVSourceProtocol* createProtocol(const char* url, AVSourceInput* parent);
};

// ======================================================================
// EN: AVSourceProtocolFF (Standard FFmpeg AVIO Implementation)
// VN: Triển khai giao thức chuẩn FFmpeg AVIO (AVSourceProtocolFF)
// ======================================================================
class AVSourceProtocolFF : public AVSourceProtocol {
private:
    AVIOContext* m_avio_ctx{nullptr};
    int64_t m_download_offset{0};

public:
    AVSourceProtocolFF();
    virtual ~AVSourceProtocolFF() override;

    virtual int32_t open(const char* url, int64_t offset, int64_t size, AVDictionary** options, AVIOInterruptCB* cb, int32_t flags) override;
    virtual int32_t close() override;
    virtual int32_t read(uint8_t* buf, int32_t size, int32_t flags) override;
    virtual int64_t seek(int64_t offset, int32_t whence) override;
    virtual int64_t getFileSize() override;
};

// ======================================================================
// EN: Protocol Probe Struct for Factory Registration
// VN: Cấu trúc Probe dùng đăng ký nhà máy sản xuất giao thức
// ======================================================================
struct AVSourceProtocolProb {
    const char* scheme_name;
    int32_t (*probe_fn)(const char* url);
    AVSourceProtocol* (*create_fn)(const char* url, AVSourceInput* parent);
};

} // namespace com::ss::ttm::demuxer
