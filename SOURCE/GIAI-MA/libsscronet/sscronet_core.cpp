// ============================================================================
// Clean-Room C++17 Core Implementation for libsscronet.so (Target 122 / 169)
// Hiện thực hóa lõi C++17 sạch cho libsscronet.so (Mục tiêu 122 / 169)
// ============================================================================
#include "sscronet_core.h"
#include <cstdlib>
#include <algorithm>

extern "C" {

// Reconstructed from 0x1c9738..0x1c9740:
//   0x1c9738: D503245F  bti c
//   0x1c973c: 14044B9E  b   #0x2dc5b4 (operator delete)
void Cronet_DateTime_Destroy(void* obj) {
    std::free(obj);
}

// Reconstructed from 0x1ea6f4..0x1ea704:
//   0x1ea6f4: D503245F  bti c
//   0x1ea6f8: B4000040  cbz x0, #0x1ea700
//   0x1ea6fc: 1403C7AE  b   #0x2dc5b4
//   0x1ea700: D65F03C0  ret
void Cronet_AuthDelegate_Destroy(void* obj) {
    if (obj != nullptr) {
        std::free(obj);
    }
}

// Reconstructed from 0x1fac70..0x1fac7c (38 aliased *_SetClientContext exports):
//   0x1fac70: D503245F  bti c
//   0x1fac74: F9000401  str x1, [x0, #8]
//   0x1fac78: D65F03C0  ret
void Cronet_Engine_SetClientContext(void* obj, void* client_context) {
    if (!obj) return;
    static_cast<sscronet::CronetClientContextBase*>(obj)->client_context = client_context;
}

void Cronet_UrlRequest_SetClientContext(void* obj, void* client_context) {
    Cronet_Engine_SetClientContext(obj, client_context);
}

// Reconstructed from 0x267f10..0x267f80 (Cronet_Throttle_Create)
//   0x267f20: 52801100  mov w0, #0x88 (136 bytes)
//   0x267f6c: F900427F  str xzr, [x19, #0x80]
sscronet::CronetThrottleObject* Cronet_Throttle_Create() {
    auto* ptr = static_cast<sscronet::CronetThrottleObject*>(
        std::calloc(1, sizeof(sscronet::CronetThrottleObject)));
    if (ptr) {
        ptr->tail_ptr = nullptr;
    }
    return ptr;
}

// Reconstructed from 0x279dd0..0x279ec4 (Q_Eng_Create)
//   0x279de0: 52803800  mov w0, #0x1c0 (448 bytes)
//   0x279e1c: F8010E89  str x9, [x20, #0x10]! (x20 = x19 + 0x10)
//   0x279e30: 52802008  mov w8, #0x100; str w8, [x19, #0x60]
//   0x279e88: 52803E88  mov w8, #0x1f4; stp x8, x9, [x19, #0x118]
//   0x279ea4: 9A9403E0  csel x0, xzr, x20, eq (returns x19 + 0x10!)
void* Q_Eng_Create() {
    auto* raw = static_cast<sscronet::QEngObject*>(
        std::calloc(1, sizeof(sscronet::QEngObject)));
    if (!raw) return nullptr;
    raw->max_streams = 0x100;      // 256
    raw->idle_timeout_ms = 0x1F4;  // 500 ms
    return reinterpret_cast<uint8_t*>(raw) + 0x10;
}

// Reconstructed from 0x27caf4..0x27cba4 (Q_Conn_Create)
//   0x27cb04: 52802D00  mov w0, #0x168 (360 bytes)
//   0x27cb40: 12800008  mov w8, #-1; str w8, [x19, #0x80]
sscronet::QConnObject* Q_Conn_Create() {
    auto* ptr = static_cast<sscronet::QConnObject*>(
        std::calloc(1, sizeof(sscronet::QConnObject)));
    if (ptr) {
        ptr->socket_fd = -1;
    }
    return ptr;
}

// Reconstructed from 0x27f834..0x27f92c (Q_Stream_Create)
//   0x27f844: 52816C00  mov w0, #0xb60 (2,912 bytes)
//   0x27f898: 52802028  mov w8, #0x101; strh w8, [x19, #0xe0]
sscronet::QStreamObject* Q_Stream_Create() {
    auto* ptr = static_cast<sscronet::QStreamObject*>(
        std::calloc(1, sizeof(sscronet::QStreamObject)));
    if (ptr) {
        ptr->stream_flags = 0x0101;
    }
    return ptr;
}

// Reconstructed from 0x28a96c..0x28a9f4 (TTQuicHe_Engine_Create)
//   0x28a97c: 52801300  mov w0, #0x98 (152 bytes)
//   0x28a9a0: 52800034  mov w20, #1; strh w20, [x19, #0x40]
sscronet::TTQuicHeEngineObject* TTQuicHe_Engine_Create() {
    auto* ptr = static_cast<sscronet::TTQuicHeEngineObject*>(
        std::calloc(1, sizeof(sscronet::TTQuicHeEngineObject)));
    if (ptr) {
        ptr->version_flags = 1;
    }
    return ptr;
}

// Reconstructed from 0x28a9f8..0x28ab3c (TTQuicHe_HttpRequest_Create)
//   0x28aa08: 5281DD00  mov w0, #0xee8 (3,816 bytes)
sscronet::TTQuicHeHttpRequestObject* TTQuicHe_HttpRequest_Create() {
    return static_cast<sscronet::TTQuicHeHttpRequestObject*>(
        std::calloc(1, sizeof(sscronet::TTQuicHeHttpRequestObject)));
}

} // extern "C"

namespace sscronet {

// RFC 9002 Section 5.3 Smoothed RTT & RTTVAR EWMA Update:
//   adjusted_rtt = max(latest_rtt - ack_delay, min_rtt)
//   rttvar = (3/4) * rttvar + (1/4) * |srtt - adjusted_rtt|
//   srtt   = (7/8) * srtt   + (1/8) * adjusted_rtt
void UpdateQuicRttRFC9002(QuicRttAndCwndState& state, double latest_rtt_ms, double ack_delay_ms) noexcept {
    if (latest_rtt_ms <= 0.0) return;
    if (latest_rtt_ms < state.min_rtt_ms) {
        state.min_rtt_ms = latest_rtt_ms;
    }
    if (state.srtt_ms == 0.0) {
        state.srtt_ms = latest_rtt_ms;
        state.rttvar_ms = latest_rtt_ms * 0.5;
        return;
    }
    double adjusted = latest_rtt_ms;
    if (adjusted >= state.min_rtt_ms + ack_delay_ms) {
        adjusted -= ack_delay_ms;
    }
    double abs_err = std::fabs(state.srtt_ms - adjusted);
    state.rttvar_ms = 0.75 * state.rttvar_ms + 0.25 * abs_err;
    state.srtt_ms = 0.875 * state.srtt_ms + 0.125 * adjusted;
}

// BBR Pacing Rate Formula:
//   rate (bytes/sec) = pacing_gain * (cwnd_bytes / (min_rtt_ms / 1000.0))
uint64_t ComputeBbrPacingRateBytesPerSec(uint64_t cwnd_bytes, double min_rtt_ms, double pacing_gain) noexcept {
    if (min_rtt_ms <= 0.001 || pacing_gain <= 0.0) return 0ULL;
    double bw_bps = static_cast<double>(cwnd_bytes) * 1000.0 / min_rtt_ms;
    return static_cast<uint64_t>(bw_bps * pacing_gain);
}

} // namespace sscronet
