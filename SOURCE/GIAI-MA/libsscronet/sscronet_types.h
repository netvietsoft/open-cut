// ============================================================================
// Clean-Room C++17 Type Definitions for libsscronet.so (Target 122 / 169)
// Định nghĩa kiểu dữ liệu C++17 sạch cho libsscronet.so (Mục tiêu 122 / 169)
// Binary: 5,973,416 bytes | SHA-256: 2005c6574bf4c56204365be7f9cca38981e6bffb8bbd2eab03f2abb1a6b052c6
// Architecture: AArch64 (ARMv8.3-A PAC/BTI) | .eh_frame_hdr: 19,032 FDEs @ 0x0f1dd8
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <atomic>
#include <vector>
#include <string>

namespace sscronet {

// Exact Allocation Sizes Reconstructed from AArch64 Constructor Disassembly:
// Kích thước cấp phát cấu trúc chuẩn xác tái dựng từ mã máy AArch64:
constexpr size_t kCronetThrottleStructSize       = 0x0088; // 136 B  (0x267f20: mov w0, #0x88)
constexpr size_t kTTQuicHeEngineStructSize       = 0x0098; // 152 B  (0x28a97c: mov w0, #0x98)
constexpr size_t kQConnStructSize                = 0x0168; // 360 B  (0x27cb04: mov w0, #0x168)
constexpr size_t kQEngStructSize                 = 0x01C0; // 448 B  (0x279de0: mov w0, #0x1c0)
constexpr size_t kQStreamStructSize              = 0x0B60; // 2,912 B (0x27f844: mov w0, #0xb60)
constexpr size_t kTTQuicHeHttpRequestStructSize  = 0x0EE8; // 3,816 B (0x28aa08: mov w0, #0xee8)

// Shared base layout for all 38 Cronet/TTQuicHe/Q_* objects supporting SetClientContext (0x1fac70):
//   0x1fac70: D503245F  bti c
//   0x1fac74: F9000401  str x1, [x0, #8]
//   0x1fac78: D65F03C0  ret
struct CronetClientContextBase {
    void* vptr{nullptr};           // +0x00
    void* client_context{nullptr}; // +0x08 (str x1, [x0, #8] @ 0x1fac74)
};

// Reconstructed from 0x267f10..0x267f80 (Cronet_Throttle_Create, 0x88 = 136 bytes)
struct CronetThrottleObject {
    void* vptr_primary{nullptr};    // +0x00 (0x598710 @ 0x267f64)
    void* client_context{nullptr};  // +0x08
    void* vptr_delegate{nullptr};   // +0x10 (0x598780 @ 0x267f70)
    void* vptr_observer{nullptr};   // +0x18 (0x5987b0 @ 0x267f70)
    uint8_t mutex_and_state[0x60]{0}; // +0x20..+0x7f
    void* tail_ptr{nullptr};        // +0x80 (str xzr, [x19, #0x80] @ 0x267f6c)
};
static_assert(sizeof(CronetThrottleObject) == kCronetThrottleStructSize, "CronetThrottleObject must be 0x88 (136) bytes");

// Reconstructed from 0x279dd0..0x279ec4 (Q_Eng_Create, 0x1c0 = 448 bytes)
// Note: Q_Eng_Create returns x19 + 0x10 (secondary subobject pointer) when allocation succeeds!
struct QEngObject {
    void* vptr_outer{nullptr};      // +0x00 (0x5991f0 @ 0x279e18)
    void* outer_ctx{nullptr};       // +0x08 (str xzr, [x0, #8] @ 0x279e08)
    void* vptr_qeng{nullptr};       // +0x10 (0x5992a0 @ 0x279e1c: str x9, [x20, #0x10]!)
    void* client_context{nullptr};  // +0x18 (stp xzr, x10, [x19, #0x18] @ 0x279e20 -> +0x08 relative to x20!)
    void* vptr_inner{nullptr};      // +0x20 (0x599300 @ 0x279e20)
    uint8_t lock_and_cond[0x38]{0}; // +0x28..+0x5f (initialized via 0x2da744 & 0x2da6d0)
    uint32_t max_streams{0x100};    // +0x60 (mov w8, #0x100; str w8, [x19, #0x60] @ 0x279e30..0x279e44)
    uint8_t is_closed{0};           // +0x64 (strb wzr, [x19, #0x64] @ 0x279e38)
    uint8_t pad_65[3]{0};
    uint64_t active_conns{0};       // +0x68
    uint32_t flags{0};              // +0x70
    uint32_t pad_74{0};
    uint8_t MapAndLists[0xA0]{0};   // +0x78..+0x117
    uint64_t idle_timeout_ms{500};  // +0x118 (mov w8, #0x1f4; stp x8, x9, [x19, #0x118] @ 0x279e88..0x279e90)
    uint8_t tail_fields[0xA0]{0};   // +0x120..+0x1bf
};
static_assert(sizeof(QEngObject) == kQEngStructSize, "QEngObject must be 0x1c0 (448) bytes");

// Reconstructed from 0x27caf4..0x27cba4 (Q_Conn_Create, 0x168 = 360 bytes)
struct QConnObject {
    void* vptr_primary{nullptr};    // +0x00 (0x5993a0 @ 0x27cb24)
    void* client_context{nullptr};  // +0x08
    void* vptr_secondary{nullptr};  // +0x10 (0x599460 @ 0x27cb28)
    uint8_t conn_core[0x68]{0};     // +0x18..+0x7f (initialized via 0x56f1cc)
    int32_t socket_fd{-1};          // +0x80 (mov w8, #-1; str w8, [x19, #0x80] @ 0x27cb40..0x27cb48)
    uint32_t pad_84{0};
    uint8_t stream_map_and_state[0xE0]{0}; // +0x88..+0x167
};
static_assert(sizeof(QConnObject) == kQConnStructSize, "QConnObject must be 0x168 (360) bytes");

// Reconstructed from 0x27f834..0x27f92c (Q_Stream_Create, 0xb60 = 2,912 bytes)
struct QStreamObject {
    void* vptr_primary{nullptr};    // +0x00 (0x5994e0 @ 0x27f86c)
    void* client_context{nullptr};  // +0x08
    void* vptr_secondary{nullptr};  // +0x10 (0x5995c0 @ 0x27f870)
    uint8_t headers_and_buf[0xC8]{0}; // +0x18..+0xdf
    uint16_t stream_flags{0x0101};  // +0xe0 (mov w8, #0x101; strh w8, [x19, #0xe0] @ 0x27f898..0x27f8a0)
    uint8_t frame_state[0xA7E]{0};  // +0xe2..+0xb5f
};
static_assert(sizeof(QStreamObject) == kQStreamStructSize, "QStreamObject must be 0xb60 (2,912) bytes");

// Reconstructed from 0x28a96c..0x28a9f4 (TTQuicHe_Engine_Create, 0x98 = 152 bytes)
struct TTQuicHeEngineObject {
    void* vptr_primary{nullptr};    // +0x00 (0x599a50 @ 0x28a9a4)
    void* client_context{nullptr};  // +0x08
    uint8_t is_started{0};          // +0x10 (strb wzr, [x19, #0x10] @ 0x28a99c)
    uint8_t pad_11[7]{0};
    uint8_t sync_prim[0x28]{0};     // +0x18..+0x3f
    uint16_t version_flags{1};      // +0x40 (mov w20, #1; strh w20, [x19, #0x40] @ 0x28a9a0..0x28a9c4)
    uint8_t quic_enabled{0};        // +0x42 (strb wzr, [x19, #0x42] @ 0x28a9c8)
    uint8_t pad_43[5]{0};
    uint8_t stats_and_cfg[0x48]{0}; // +0x48..+0x8f
    void* backend_handle{nullptr};  // +0x90 (str xzr, [x19, #0x90] @ 0x28a9e4)
};
static_assert(sizeof(TTQuicHeEngineObject) == kTTQuicHeEngineStructSize, "TTQuicHeEngineObject must be 0x98 (152) bytes");

// Reconstructed from 0x28a9f8..0x28ab3c (TTQuicHe_HttpRequest_Create, 0xee8 = 3,816 bytes)
struct TTQuicHeHttpRequestObject {
    void* vptr_primary{nullptr};    // +0x00 (0x599b30 @ 0x28aa2c)
    void* client_context{nullptr};  // +0x08
    void* vptr_cb1{nullptr};        // +0x10 (0x599c10 @ 0x28aa30)
    void* vptr_cb2{nullptr};        // +0x18 (0x599c90 @ 0x28aa30)
    uint8_t request_state[0xEC8]{0}; // +0x20..+0xee7
};
static_assert(sizeof(TTQuicHeHttpRequestObject) == kTTQuicHeHttpRequestStructSize, "TTQuicHeHttpRequestObject must be 0xee8 (3,816) bytes");

} // namespace sscronet
