// ======================================================================
// RECONSTRUCTED C++ FORMAT HOLDER & IO HELPER: libttdemux.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: FormatHolder & SourceInputHelper (FFmpeg Context Lifecycle)
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#pragma once

#include "ttdemux_types.h"
#include "ttdemux_source_input.h"
#include <string>

namespace com::ss::ttm::demuxer {

// ======================================================================
// EN: FormatHolder Class
// VN: Lớp FormatHolder (Quản lý vòng đời AVFormatContext của FFmpeg)
// ======================================================================
class FormatHolder {
private:
    // +0x10: AVFormatContext pointer / Con trỏ ngữ cảnh FFmpeg
    AVFormatContext* m_format_context{nullptr};

public:
    FormatHolder();
    virtual ~FormatHolder();

    // Mangled: _ZN3com2ss3ttm7demuxer12FormatHolder5allocEv (0x777c)
    // EN: Allocate fresh AVFormatContext
    // VN: Cấp phát AVFormatContext mới
    int32_t alloc();

    // Mangled: _ZN3com2ss3ttm7demuxer12FormatHolder4openEPNS2_13AVSourceInputEP13AVInputFormatPP12AVDictionary (0x77a8)
    // EN: Bind custom AVIOContext and open media container
    // VN: Liên kết AVIOContext tùy biến và mở container media
    int32_t open(AVSourceInput* input, AVInputFormat* fmt, AVDictionary** options);

    // Mangled: _ZN3com2ss3ttm7demuxer12FormatHolder5closeEv (0x7898)
    // EN: Close format context and teardown custom IO
    // VN: Đóng format context và thu hồi IO tùy biến
    int32_t close();

    // Mangled: _ZNK3com2ss3ttm7demuxer12FormatHolder10getContextEv (0x78d8)
    // EN: Access underlying AVFormatContext pointer
    // VN: Truy cập con trỏ AVFormatContext nền tảng
    AVFormatContext* getContext() const noexcept;
};

// ======================================================================
// EN: SourceInputHelper Static Utility Class
// VN: Lớp tiện ích tĩnh SourceInputHelper (Quản lý IO và chỉ số kết nối)
// ======================================================================
class SourceInputHelper {
public:
    // Read thunk bound to FFmpeg AVIO (Disassembly 0x7978)
    static int readThunk(void* opaque, uint8_t* buf, int size);

    // Seek thunk bound to FFmpeg AVIO (Disassembly 0x7988)
    static int64_t seekThunk(void* opaque, int64_t offset, int whence);

    // Mangled: _ZN3com2ss3ttm7demuxer17SourceInputHelper13openIoContextEPP11AVIOContextPNS2_13AVSourceInputE (0x78e0 - 152 bytes)
    // EN: Allocate 272-byte TTIOContext and 32KB buffer, set callbacks, and init AVIO
    // VN: Phân bổ TTIOContext 272-byte và buffer 32KB, gắn callback và khởi tạo AVIO
    static int32_t openIoContext(AVIOContext** pb, AVSourceInput* input);

    // Mangled: _ZN3com2ss3ttm7demuxer17SourceInputHelper14closeIoContextEPP11AVIOContextb (0x7998 - 108 bytes)
    // EN: Release AVIO buffer and destroy TTIOContext
    // VN: Giải phóng vùng đệm AVIO và hủy TTIOContext
    static void closeIoContext(AVIOContext** pb, bool is_streamed);

    // Mangled: _ZN3com2ss3ttm7demuxer17SourceInputHelper18supportSourceInputEiPKc (0x7a04 - 60 bytes)
    // EN: Check if URL scheme is supported (specifically checks "mdl://")
    // VN: Kiểm tra lược đồ URL có được hỗ trợ (đặc biệt tiền tố "mdl://")
    static int32_t supportSourceInput(int32_t type, const char* url);

    // Mangled: _ZN3com2ss3ttm7demuxer17SourceInputHelper10getOptionsEP11AVIOContextiPPh (0x7a40)
    static int32_t getOptions(AVIOContext* ctx, int32_t opt_id, uint8_t** out_val);

    // Mangled: _ZN3com2ss3ttm7demuxer17SourceInputHelper13getIntOptionsEP11AVIOContextiPl (0x7a80)
    static int32_t getIntOptions(AVIOContext* ctx, int32_t opt_id, int64_t* out_val);

    // Mangled: _ZN3com2ss3ttm7demuxer17SourceInputHelper28parseAndUpdateConnectionInfoEPNS2_12DemuxMetricsEiPKc (0x7ac4 - 492 bytes)
    // EN: Parse comma-delimited stats string and pack bitfield (action << 16) | metric_id
    // VN: Tách chuỗi thống kê phân cách dấu phẩy và mã hóa bitfield (action << 16) | metric_id
    static void parseAndUpdateConnectionInfo(DemuxMetrics* metrics, int32_t action, const char* info_str);
};

} // namespace com::ss::ttm::demuxer
