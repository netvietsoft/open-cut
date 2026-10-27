// ============================================================================
// Clean-Room C++17 Core Interfaces for libsscronet.so (Target 122 / 169)
// Giao diện lõi C++17 sạch cho libsscronet.so (Mục tiêu 122 / 169)
// ============================================================================
#pragma once

#include "sscronet_types.h"

extern "C" {

// JNI Entrypoint (0x1c74a8..0x1c78bc, 1,044 bytes)
int32_t JNI_OnLoad(void* vm, void* reserved);

// Consolidated Destroy & ClientContext Thunks (0x1c9738, 0x1ea6f4, 0x1fac70)
void Cronet_DateTime_Destroy(void* obj);
void Cronet_AuthDelegate_Destroy(void* obj);
void Cronet_Engine_SetClientContext(void* obj, void* client_context);
void Cronet_UrlRequest_SetClientContext(void* obj, void* client_context);

// Core Cronet / TTQuicHe / Q_* Factory Functions
sscronet::CronetThrottleObject* Cronet_Throttle_Create();               // 0x267f10
void* Q_Eng_Create();                                                   // 0x279dd0
sscronet::QConnObject* Q_Conn_Create();                                 // 0x27caf4
sscronet::QStreamObject* Q_Stream_Create();                             // 0x27f834
sscronet::TTQuicHeEngineObject* TTQuicHe_Engine_Create();               // 0x28a96c
sscronet::TTQuicHeHttpRequestObject* TTQuicHe_HttpRequest_Create();     // 0x28a9f8

} // extern "C"

namespace sscronet {

// BBR / QUIC Cubic Congestion Window & RTT Smoothed Estimator (RFC 9002 / TTQuicHe)
struct QuicRttAndCwndState {
    double srtt_ms{0.0};
    double rttvar_ms{0.0};
    double min_rtt_ms{1e9};
    uint64_t cwnd_bytes{14720}; // 10 * 1472 MTU
};

void UpdateQuicRttRFC9002(QuicRttAndCwndState& state, double latest_rtt_ms, double ack_delay_ms) noexcept;
uint64_t ComputeBbrPacingRateBytesPerSec(uint64_t cwnd_bytes, double min_rtt_ms, double pacing_gain) noexcept;

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);

} // namespace sscronet
