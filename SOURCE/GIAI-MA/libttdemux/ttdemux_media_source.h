// ======================================================================
// RECONSTRUCTED C++ MEDIA SOURCE HEADER: libttdemux.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: AVMediaSource & AVMediaSourceHelper (High-level Demuxer Pipeline)
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#pragma once

#include "ttdemux_types.h"
#include "ttdemux_source_input.h"
#include "ttdemux_format_holder.h"
#include "ttdemux_predemux_monitor.h"
#include <functional>
#include <memory>
#include <string>

namespace com::ss::ttm::demuxer {

// Callback type for format configuration matching disassembly at 0x63f0
using OpenFormatCallback = std::function<void(AVFormatContext*, AVInputFormat**, AVDictionary**)>;

// ======================================================================
// EN: AVMediaSource Class
// VN: Lớp AVMediaSource (Đầu vào phương tiện truyền thông cấp cao)
// ======================================================================
class AVMediaSource : public com::ss::vcbkit::BaseRef {
private:
    // Size = 0xe0 (224 bytes) matching disassembly opcode 0x6394
    DemuxContextHolder* m_context_holder{nullptr};
    com::ss::vcbkit::RefPtr<AVSourceInput> m_source_input;
    std::unique_ptr<FormatHolder> m_format_holder;
    std::shared_ptr<AVPredemuxMonitor> m_predemux_monitor;
    std::string m_media_url;
    bool m_is_open{false};
    bool m_stream_info_found{false};
    com::ss::vcbkit::Mutex m_media_mutex;

public:
    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSourceC1EPNS2_18DemuxContextHolderE (0x62b0)
    explicit AVMediaSource(DemuxContextHolder* ctx = nullptr);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSourceD1Ev (0x6568)
    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSourceD0Ev (0x630c)
    virtual ~AVMediaSource() override;

    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSource17createMediaSourceERNS0_6vcbkit6RefPtrIS3_EEPNS2_18DemuxContextHolderE (0x6354 - 156 bytes)
    // EN: Factory method allocating 224-byte AVMediaSource and wrapping in RefPtr
    // VN: Phương thức nhà máy cấp phát AVMediaSource 224-byte và đóng gói trong RefPtr
    static int32_t createMediaSource(com::ss::vcbkit::RefPtr<AVMediaSource>& out_source, DemuxContextHolder* ctx);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSource15openInputFormatEPKcNSt6__ndk18functionIFvP15AVFormatContextPP13AVInputFormatPP12AVDictionaryEEEP15AVIOInterruptCBii (0x63f0 - 264 bytes)
    // EN: Open input container format, attach custom IO buffer and prepare demuxing
    // VN: Mở định dạng container đầu vào, gắn bộ đệm IO tùy biến và chuẩn bị giải mã
    int32_t openInputFormat(const char* url,
                           OpenFormatCallback format_cb,
                           AVIOInterruptCB* interrupt_cb,
                           int32_t open_flags,
                           int32_t probe_size);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSource14findStreamInfoEv (0x64f8)
    // EN: Analyze stream headers and populate audio/video codec parameters
    // VN: Phân tích header luồng và nạp thông số codec âm thanh/hình ảnh
    int32_t findStreamInfo();

    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSource18getPredemuxMonitorERNSt6__ndk18weak_ptrINS2_17AVPredemuxMonitorEEE (0x6500)
    // EN: Retrieve weak reference to predemux monitor
    // VN: Lấy tham chiếu yếu đến bộ giám sát predemux
    void getPredemuxMonitor(std::weak_ptr<AVPredemuxMonitor>& out_monitor);

    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSource16closeInputFormatEv (0x6508)
    // EN: Close active format and release native demuxer resources
    // VN: Đóng format đang mở và giải phóng tài nguyên demuxer
    void closeInputFormat();

    // Mangled: _ZNK3com2ss3ttm7demuxer13AVMediaSource10getContextEv (0x6510)
    // EN: Query underlying AVFormatContext pointer
    // VN: Truy vấn con trỏ AVFormatContext nền tảng
    AVFormatContext* getContext() const noexcept;

    // Mangled: _ZN3com2ss3ttm7demuxer13AVMediaSource8shutdownEi (0x6518)
    // EN: Abort any pending network IO and shutdown demuxer pipeline
    // VN: Hủy mọi tác vụ IO mạng đang chờ và ngắt pipeline demuxer
    void shutdown(int32_t flag);

    // Read packet from stream
    int32_t readPacket(uint8_t* buf, int32_t size);

    // Seek to stream timestamp or byte offset
    int64_t seek(int64_t offset, int32_t whence);
};

// ======================================================================
// EN: AVMediaSourceHelper Utility Wrapper Class
// VN: Lớp tiện ích bọc ngoài AVMediaSourceHelper
// ======================================================================
class AVMediaSourceHelper {
public:
    // Mangled: _ZN3com2ss3ttm7demuxer19AVMediaSourceHelper16closeInputFormatERNS0_6vcbkit6RefPtrINS2_13AVMediaSourceEEE (0x6520)
    static void closeInputFormat(com::ss::vcbkit::RefPtr<AVMediaSource>& source);

    // Mangled: _ZN3com2ss3ttm7demuxer19AVMediaSourceHelper10getContextERNS0_6vcbkit6RefPtrINS2_13AVMediaSourceEEE (0x6538)
    static AVFormatContext* getContext(com::ss::vcbkit::RefPtr<AVMediaSource>& source);

    // Mangled: _ZN3com2ss3ttm7demuxer19AVMediaSourceHelper8shutdownERNS0_6vcbkit6RefPtrINS2_13AVMediaSourceEEEi (0x6550)
    static void shutdown(com::ss::vcbkit::RefPtr<AVMediaSource>& source, int32_t flag);
};

} // namespace com::ss::ttm::demuxer
