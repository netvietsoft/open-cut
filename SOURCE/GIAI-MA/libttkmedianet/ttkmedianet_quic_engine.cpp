// ============================================================================
// File: ttkmedianet_quic_engine.cpp
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// EN: Clean-room C++17 QUIC draft-29 / v1 transport, CUBIC & IACC congestion
//     control math, and QPACK static table (.rodata 0x07cff7..0x07d600).
// VI: Triển khai C++17 phòng sạch giao thức QUIC draft-29 / v1, toán học điều
//     khiển tắc nghẽn CUBIC & IACC, và bảng tĩnh QPACK (.rodata 0x07cff7..0x07d600).
// ============================================================================
#include "ttkmedianet_core.h"
#include <algorithm>
#include <cmath>

namespace TTKMediaNet {

// EN: Authentic QPACK static header names extracted from .rodata 0x07cff7..0x07d0f0
// VI: Danh sách trường header tĩnh QPACK trích xuất từ .rodata 0x07cff7..0x07d0f0
static const char* const kQpackStaticHeaders_07cff7[] = {
    ":authority",
    ":path",
    "age",
    "content-disposition",
    "content-length",
    "cookie",
    "date",
    "etag",
    "if-modified-since",
    "if-none-match",
    "last-modified",
    "link",
    "location",
    "referer",
    "set-cookie",
    ":method",
    ":scheme",
    ":status",
    "accept",
    "accept-encoding",
    "accept-language",
    "accept-ranges",
    "access-control-allow-headers",
    "access-control-allow-origin",
    "cache-control",
    "content-encoding",
    "content-type",
    "range",
    "strict-transport-security",
    "vary",
    "x-content-type-options",
    "x-xss-protection",
    "alt-svc",
    "authorization",
    "early-data",
    "expect-ct",
    "forwarded",
    "if-range",
    "purpose",
    "server",
    "timing-allow-origin",
    "upgrade-insecure-requests",
    "user-agent",
    "x-forwarded-for",
    "x-frame-options"
};

const char* LookupQpackStaticHeaderField(uint32_t index) noexcept {
    constexpr uint32_t kCount = static_cast<uint32_t>(sizeof(kQpackStaticHeaders_07cff7) / sizeof(kQpackStaticHeaders_07cff7[0]));
    if (index >= kCount) {
        return "";
    }
    return kQpackStaticHeaders_07cff7[index];
}

// EN: CUBIC congestion window growth formula (RFC 8312 / QUIC cubic @ .rodata 0x07cad4):
//     W_cubic(t) = C * (t - K)^3 + W_max, where C = 0.4, beta = 0.7
// VI: Công thức tăng cửa sổ tắc nghẽn CUBIC (RFC 8312 / QUIC cubic @ .rodata 0x07cad4):
//     W_cubic(t) = C * (t - K)^3 + W_max, với C = 0.4, beta = 0.7
uint32_t ComputeCubicCwnd(uint32_t origin_cwnd, uint64_t elapsed_ms, uint32_t rtt_min_ms, uint32_t max_udp_payload) noexcept {
    const uint32_t mss = std::max(1200u, max_udp_payload);
    const double w_max = static_cast<double>( std::max(origin_cwnd, 10u * mss) ) / static_cast<double>(mss);
    const double k_sec = std::cbrt(w_max * 0.3 / 0.4);
    const double t_sec = static_cast<double>(elapsed_ms + std::max(1u, rtt_min_ms)) / 1000.0;
    const double delta = t_sec - k_sec;
    const double w_cubic = 0.4 * (delta * delta * delta) + w_max;
    const double clamped_segments = std::clamp(w_cubic, 2.0, 65536.0);
    return static_cast<uint32_t>(clamped_segments * static_cast<double>(mss));
}

// EN: ByteDance IACC (Intelligent Adaptive Congestion Control @ .rodata 0x07c9e9..0x07ca44)
//     pacing rate formula combining `pacing_gain_percent` (0x07ca0c) and `smooth_iacc_percent` (0x07ca30).
// VI: Công thức tốc độ điều nhịp IACC của ByteDance (@ .rodata 0x07c9e9..0x07ca44)
//     kết hợp `pacing_gain_percent` (0x07ca0c) và `smooth_iacc_percent` (0x07ca30).
uint32_t ComputeIaccPacingRateBps(uint32_t cwnd_bytes, uint32_t srtt_us, uint32_t pacing_gain_percent, uint32_t smooth_iacc_percent) noexcept {
    if (srtt_us == 0u || cwnd_bytes == 0u) {
        return 0u;
    }
    const uint64_t base_bps = (static_cast<uint64_t>(cwnd_bytes) * 1000000ULL) / static_cast<uint64_t>(srtt_us);
    const uint64_t gained_bps = (base_bps * static_cast<uint64_t>(std::clamp(pacing_gain_percent, 50u, 300u))) / 100ULL;
    const uint64_t smoothed_bps = (gained_bps * static_cast<uint64_t>(std::clamp(smooth_iacc_percent, 10u, 100u))) / 100ULL;
    return static_cast<uint32_t>(std::min<uint64_t>(smoothed_bps, 0xFFFFFFFFULL));
}

} // namespace TTKMediaNet
