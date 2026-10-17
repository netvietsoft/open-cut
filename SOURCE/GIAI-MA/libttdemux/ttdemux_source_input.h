// ======================================================================
// RECONSTRUCTED C++ SOURCE INPUT HEADER: libttdemux.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: AVSourceInput (Unified Buffer Manager & Multi-Protocol Bridge)
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Implementation with Disassembly Match
// ======================================================================

#pragma once

#include "ttdemux_types.h"
#include "ttdemux_protocol.h"
#include <string>
#include <vector>
#include <memory>
#include <cstdarg>

namespace com::ss::ttm::demuxer {

// Forward declaration of FormatHolder
class FormatHolder;

// ======================================================================
// EN: AVSourceInput Class
// VN: Lớp AVSourceInput (Bộ điều phối nạp luồng, quản lý buffer và đa giao thức)
// ======================================================================
class AVSourceInput : public com::ss::vcbkit::BaseRef,
                      public AVSourceProtocolLisenter {
protected:
    // Memory layout precisely matching AArch64 disassembly offsets:
    // +0x10: Context holder reference / Tham chiếu context
    DemuxContextHolder* m_context_holder{nullptr};

    // +0x20: Synchronization mutex / Khóa tương hỗ luồng
    com::ss::vcbkit::Mutex m_mutex;

    // +0x28: Active protocol pointer / Giao thức đang hoạt động
    AVSourceProtocol* m_active_protocol{nullptr};

    // +0x30: Protocol list count / Số lượng giao thức đang nạp
    int64_t m_protocol_count{0};

    // +0x38: Current logical stream position / Vị trí luồng hiện tại
    int64_t m_current_pos{0};

    // +0x40: Cached total file size / Kích thước tệp đã lưu trong bộ đệm
    int64_t m_file_size{-1};

    // Internal list of instantiated protocols
    std::vector<AVSourceProtocol*> m_protocols;

    // Last error info & child object
    int32_t m_last_error_code{0};
    std::string m_last_error_msg;
    void* m_child_obj{nullptr};
    bool m_is_shutdown{false};
    bool m_auto_range_closed{false};

public:
    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInputC1EPNS2_18DemuxContextHolderE (0x66b8)
    explicit AVSourceInput(DemuxContextHolder* ctx = nullptr);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInputD1Ev (0x66f4, 0x68d8)
    virtual ~AVSourceInput() override;

    // Context & Format Lifecycle
    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput11openContextEP13AVInputFormatPP12AVDictionary (0x698c)
    int32_t openContext(AVInputFormat* fmt, AVDictionary** options);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput12allocContextEv (0x6a34)
    int32_t allocContext();

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput12closeContextEv (0x6a88)
    void closeContext();

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput12resetContextEv (0x6ac8)
    void resetContext();

    // Input & Protocol Management
    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8addInputEPKcllPP12AVDictionaryP15AVIOInterruptCBi (0x6ae0)
    int32_t addInput(const char* url, int64_t offset, int64_t size, AVDictionary** options, AVIOInterruptCB* cb, int32_t flags);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8addInputEPPNS2_16AVSourceProtocolE (0x7424)
    int32_t addInput(AVSourceProtocol** proto);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput13allocProtocolEPKcllPP12AVDictionaryP15AVIOInterruptCBi (0x6c54)
    AVSourceProtocol* allocProtocol(const char* url, int64_t offset, int64_t size, AVDictionary** options, AVIOInterruptCB* cb, int32_t flags);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput12openProtocolEPNS2_16AVSourceProtocolE (0x74e8)
    int32_t openProtocol(AVSourceProtocol* proto);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput15releaseProtocolEPPNS2_16AVSourceProtocolE (0x7500)
    void releaseProtocol(AVSourceProtocol** proto);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput9openInputEv (0x6d4c)
    int32_t openInput();

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput10closeInputEv (0x73a0)
    void closeInput();

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput11clearInputsEv (0x67a4)
    void clearInputs();

    // Core IO Operations (Bound to FFmpeg AVIO)
    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput4readEPhii (0x71f0)
    int32_t read(uint8_t* buf, int32_t size, int32_t flags = 0);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput4seekEli (0x6ef8)
    int64_t seek(int64_t offset, int32_t whence);

    // Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput11getFileSizeEv (0x6ea8)
    int64_t getFileSize() const noexcept;

    // Shutdown & State Control
    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8shutdownEi (0x737c)
    void shutdown(int32_t flag);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput10hasRequestEv (0x754c)
    bool hasRequest() const noexcept;

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput14closeAutoRangeEv (0x755c)
    void closeAutoRange();

    // Event & Error Callbacks
    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput10onFileSizeEl (0x6d3c)
    virtual void onFileSize(int64_t size) override;

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8onIoInfoEilPKc (0x6604)
    virtual void onIoInfo(int32_t type, int64_t code, const char* extra) override;

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput18ffio_info_callbackElilPKc (0x65f8)
    static void ffio_info_callback(int64_t opaque, int32_t type, int64_t code, const char* extra);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput15notifyErrorInfoEPKcz (0x6ddc)
    void notifyErrorInfo(const char* fmt, ...);

    // Property Accessors (ABI & Reflection)
    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput8setValueEiPKvm (0x75ac)
    void setValue(int32_t key, const void* val, size_t size);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput11setIntValueEii (0x75b4)
    void setIntValue(int32_t key, int32_t val);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput13setInt64ValueEim (0x75cc)
    void setInt64Value(int32_t key, uint64_t val);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput11setPtrValueEil (0x75d4)
    void setPtrValue(int32_t key, int64_t ptr);

    // Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput8getValueEiPvm (0x75dc)
    void getValue(int32_t key, void* out_val, size_t size) const;

    // Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput11getIntValueEii (0x75e4)
    int32_t getIntValue(int32_t key, int32_t default_val) const;

    // Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput13getInt64ValueEim (0x7600)
    int64_t getInt64Value(int32_t key, uint64_t default_val) const;

    // Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput11getPtrValueEi (0x7714)
    int64_t getPtrValue(int32_t key) const;

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput15getCStringValueEi (0x771c)
    const char* getCStringValue(int32_t key);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVSourceInput16getLastErrorCodeEv (0x7740)
    int32_t getLastErrorCode() const noexcept;

    // Mangled: _ZNK3com2ss3ttm7demuxer13AVSourceInput11getChildObjEv (0x7750)
    void* getChildObj() const noexcept;
};

} // namespace com::ss::ttm::demuxer
