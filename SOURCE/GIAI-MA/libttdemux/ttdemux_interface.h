// ======================================================================
// RECONSTRUCTED C++ MASTER INTERFACE: libttdemux.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Target Architecture: AArch64 / Android arm64-v8a
// Namespace: NextAI::OpenCut::ttdemux & com::ss::ttm::demuxer
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Public API & Engine Bridge
// ======================================================================

#pragma once

#include "ttdemux_types.h"
#include "ttdemux_protocol.h"
#include "ttdemux_source_input.h"
#include "ttdemux_format_holder.h"
#include "ttdemux_predemux_monitor.h"
#include "ttdemux_media_source.h"
#include <string>
#include <memory>
#include <vector>

namespace NextAI::OpenCut::ttdemux {

// Using underlying ByteDance TTPlayer demuxer types
using DemuxStatus = com::ss::ttm::demuxer::DemuxStatus;
using DemuxAction = com::ss::ttm::demuxer::DemuxAction;
using PredemuxHitStatus = com::ss::ttm::demuxer::PredemuxHitStatus;
using DemuxConfig = com::ss::ttm::demuxer::DemuxConfig;
using DemuxMetrics = com::ss::ttm::demuxer::DemuxMetrics;
using DemuxContextHolder = com::ss::ttm::demuxer::DemuxContextHolder;
using AVSourceInput = com::ss::ttm::demuxer::AVSourceInput;
using FormatHolder = com::ss::ttm::demuxer::FormatHolder;
using SourceInputHelper = com::ss::ttm::demuxer::SourceInputHelper;
using AVPredemuxMonitor = com::ss::ttm::demuxer::AVPredemuxMonitor;
using AVMediaSource = com::ss::ttm::demuxer::AVMediaSource;
using AVMediaSourceHelper = com::ss::ttm::demuxer::AVMediaSourceHelper;

// ======================================================================
// EN: TtdemuxEngine (High-Level Cleanroom Demuxing Engine)
// VN: Lớp TtdemuxEngine (Động cơ Demux cấp cao chuẩn Cleanroom cho NextAI OpenCut)
// ======================================================================
class TtdemuxEngine {
private:
    com::ss::vcbkit::RefPtr<DemuxContextHolder> m_context;
    com::ss::vcbkit::RefPtr<AVMediaSource> m_media_source;
    bool m_is_initialized{false};

public:
    TtdemuxEngine();
    virtual ~TtdemuxEngine();

    // EN: Initialize engine with custom buffer size and retry limits
    // VN: Khởi tạo động cơ với kích thước đệm và giới hạn thử lại tùy biến
    bool initialize(int32_t buffer_size = 32768, int32_t max_retry = 3);

    // EN: Open media stream from URL (supports http, https, file, mdl://)
    // VN: Mở luồng đa phương tiện từ URL (hỗ trợ http, https, file, mdl://)
    int32_t openStream(const char* url, int32_t probe_size = 32768);

    // EN: Read raw packet/chunk from media container
    // VN: Đọc gói tin/dải byte thô từ container đa phương tiện
    int32_t readPacket(uint8_t* buffer, int32_t size);

    // EN: Seek to target offset or timestamp
    // VN: Nhảy đến vị trí byte hoặc mốc thời gian mục tiêu
    int64_t seek(int64_t offset, int32_t whence);

    // EN: Query total file size
    // VN: Truy vấn tổng kích thước tệp
    int64_t getFileSize() const noexcept;

    // EN: Query current predemux cache hit status
    // VN: Truy vấn trạng thái trúng đệm nạp trước (Predemux Hit Status)
    PredemuxHitStatus getPredemuxHitStatus() const noexcept;

    // EN: Query network performance metrics
    // VN: Truy vấn các chỉ số hiệu năng mạng (DNS, Connect, Throughput)
    DemuxMetrics getMetrics() const noexcept;

    // EN: Close active media stream and release resources
    // VN: Đóng luồng media đang phát và giải phóng tài nguyên
    void closeStream();

    // EN: Check whether a URL scheme is supported
    // VN: Kiểm tra xem lược đồ URL có được hỗ trợ hay không
    static bool isSchemeSupported(const char* url);

    // EN: Run self-test verification suite
    // VN: Chạy bộ kiểm thử tự kiểm tra nội bộ
    static bool runSelfTest();
};

} // namespace NextAI::OpenCut::ttdemux
