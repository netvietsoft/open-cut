// ======================================================================
// RECONSTRUCTED C++ PREDEMUX MONITOR HEADER: libttdemux.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: AVPredemuxMonitor (Pre-buffering Performance & Hit Tracking)
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#pragma once

#include "ttdemux_types.h"
#include <mutex>

namespace com::ss::ttm::demuxer {

// ======================================================================
// EN: AVPredemuxMonitor Class
// VN: Lớp AVPredemuxMonitor (Giám sát bộ nhớ đệm nạp trước và tỷ lệ trúng predemux)
// ======================================================================
class AVPredemuxMonitor : public com::ss::vcbkit::BaseRef {
private:
    // Internal state matching disassembly at 0x88fc - 0x8aa0
    com::ss::vcbkit::Mutex m_monitor_mutex;
    bool m_predemux_enabled{true};          // +0x0c
    int32_t m_hit_status{0};                // +0x38: Hit status (0=NotUsed, 1=Hit, 2=Miss, 3=Pending)
    int64_t m_predemux_bytes{0};            // +0x40: Pre-buffered byte count
    int64_t m_hit_timestamp_ms{0};          // +0x48: Timestamp when predemux was consumed
    int32_t m_open_count{0};                // +0x50: Number of open requests
    bool m_predemux_finished{false};        // +0x54: Flag indicating predemux task completed

public:
    AVPredemuxMonitor();
    virtual ~AVPredemuxMonitor() override;

    // Mangled: _ZN3com2ss3ttm7demuxer17AVPredemuxMonitor14notifyDemuxMsgENS3_11DemuxStatusENS3_11DemuxActionE (0x88fc - 220 bytes)
    // EN: Process demuxer lifecycle message and track predemux cache hits
    // VN: Xử lý thông điệp vòng đời demuxer và theo dõi tỷ lệ trúng cache predemux
    void notifyDemuxMsg(DemuxStatus status, DemuxAction action);

    // Mangled: _ZN3com2ss3ttm7demuxer17AVPredemuxMonitor14notifyPredemuxEb (0x89d8 - 104 bytes)
    // EN: Notify completion or failure of background predemux task
    // VN: Thông báo hoàn tất hoặc thất bại của tác vụ nạp trước ngầm
    void notifyPredemux(bool success);

    // Mangled: _ZN3com2ss3ttm7demuxer17AVPredemuxMonitor20getPredemuxHitStatusEv (0x8a40 - 96 bytes)
    // EN: Return hit status enum (PREDEMUX_HIT, PREDEMUX_MISS, etc.)
    // VN: Trả về trạng thái trúng đệm nạp trước
    PredemuxHitStatus getPredemuxHitStatus() const noexcept;

    // Helper metrics queries
    inline bool isPredemuxEnabled() const noexcept { return m_predemux_enabled; }
    inline int64_t getPredemuxBytes() const noexcept { return m_predemux_bytes; }
};

} // namespace com::ss::ttm::demuxer
