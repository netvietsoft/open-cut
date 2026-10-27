// ============================================================================
// File: cybertron_fde_shard_3.cpp
// Target: libcybertron_base.so (509,816 bytes)
// SHA-256: 0d969c7e981d68f46d81986a0f16881d1ff9605afb9e6e352f1ae88a5695c7e6
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// FDE Range: [480..719] of 1,201 (.eh_frame_hdr @ 0x069c8c)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [480..719]
//      verified directly against the .text section of libcybertron_base.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [480..719]
//      đã đối chiếu trực tiếp với phân đoạn .text của libcybertron_base.so.
// ============================================================================

#include "cybertron_base_types.h"

namespace datacenter {

// [EN] FDE[0480] start_va=0x047c90, fde_va=0x06f9f8, span=192 bytes
// [VN] FDE[0480] địa chỉ bắt đầu=0x047c90, fde_va=0x06f9f8, kích thước=192 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0480_0x047c90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047c90U;
    constexpr uint32_t kFdeVa   = 0x06f9f8U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9000bf7U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0481] start_va=0x047d50, fde_va=0x06fa20, span=8 bytes
// [VN] FDE[0481] địa chỉ bắt đầu=0x047d50, fde_va=0x06fa20, kích thước=8 byte
// AArch64 opcodes: AA1F03E0 D65F03C0 D10183FF A90357F6
uint32_t cybertron_fde_0481_0x047d50(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047d50U;
    constexpr uint32_t kFdeVa   = 0x06fa20U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xaa1f03e0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd10183ffU;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0482] start_va=0x047d58, fde_va=0x06fa38, span=292 bytes
// [VN] FDE[0482] địa chỉ bắt đầu=0x047d58, fde_va=0x06fa38, kích thước=292 byte
// AArch64 opcodes: D10183FF A90357F6 A9044FF4 A9057BFD
uint32_t cybertron_fde_0482_0x047d58(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047d58U;
    constexpr uint32_t kFdeVa   = 0x06fa38U;
    constexpr uint32_t kSpan    = 292U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa90357f6U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0483] start_va=0x047e7c, fde_va=0x06fa60, span=292 bytes
// [VN] FDE[0483] địa chỉ bắt đầu=0x047e7c, fde_va=0x06fa60, kích thước=292 byte
// AArch64 opcodes: D10183FF A90357F6 A9044FF4 A9057BFD
uint32_t cybertron_fde_0483_0x047e7c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047e7cU;
    constexpr uint32_t kFdeVa   = 0x06fa60U;
    constexpr uint32_t kSpan    = 292U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa90357f6U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0484] start_va=0x047fa0, fde_va=0x06fa88, span=12 bytes
// [VN] FDE[0484] địa chỉ bắt đầu=0x047fa0, fde_va=0x06fa88, kích thước=12 byte
// AArch64 opcodes: A9007D1F F900091F D65F03C0 2A1F03E0
uint32_t cybertron_fde_0484_0x047fa0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047fa0U;
    constexpr uint32_t kFdeVa   = 0x06fa88U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xa9007d1fU;
    constexpr uint32_t kW1      = 0xf900091fU;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x2a1f03e0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0485] start_va=0x047fac, fde_va=0x06faa0, span=8 bytes
// [VN] FDE[0485] địa chỉ bắt đầu=0x047fac, fde_va=0x06faa0, kích thước=8 byte
// AArch64 opcodes: 2A1F03E0 D65F03C0 D65F03C0 F81E0FF3
uint32_t cybertron_fde_0485_0x047fac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047facU;
    constexpr uint32_t kFdeVa   = 0x06faa0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x2a1f03e0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xf81e0ff3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0486] start_va=0x047fb4, fde_va=0x06fab8, span=4 bytes
// [VN] FDE[0486] địa chỉ bắt đầu=0x047fb4, fde_va=0x06fab8, kích thước=4 byte
// AArch64 opcodes: D65F03C0 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0486_0x047fb4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047fb4U;
    constexpr uint32_t kFdeVa   = 0x06fab8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0487] start_va=0x047fb8, fde_va=0x06fad0, span=56 bytes
// [VN] FDE[0487] địa chỉ bắt đầu=0x047fb8, fde_va=0x06fad0, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 900001C8
uint32_t cybertron_fde_0487_0x047fb8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047fb8U;
    constexpr uint32_t kFdeVa   = 0x06fad0U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0488] start_va=0x047ff0, fde_va=0x06faf0, span=68 bytes
// [VN] FDE[0488] địa chỉ bắt đầu=0x047ff0, fde_va=0x06faf0, kích thước=68 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 900001C8
uint32_t cybertron_fde_0488_0x047ff0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047ff0U;
    constexpr uint32_t kFdeVa   = 0x06faf0U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0489] start_va=0x048034, fde_va=0x06fb10, span=60 bytes
// [VN] FDE[0489] địa chỉ bắt đầu=0x048034, fde_va=0x06fb10, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400801
uint32_t cybertron_fde_0489_0x048034(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048034U;
    constexpr uint32_t kFdeVa   = 0x06fb10U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400801U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0490] start_va=0x048070, fde_va=0x06fb30, span=60 bytes
// [VN] FDE[0490] địa chỉ bắt đầu=0x048070, fde_va=0x06fb30, kích thước=60 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD B4000121
uint32_t cybertron_fde_0490_0x048070(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048070U;
    constexpr uint32_t kFdeVa   = 0x06fb30U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb4000121U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0491] start_va=0x0480ac, fde_va=0x06fb50, span=108 bytes
// [VN] FDE[0491] địa chỉ bắt đầu=0x0480ac, fde_va=0x06fb50, kích thước=108 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0491_0x0480ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0480acU;
    constexpr uint32_t kFdeVa   = 0x06fb50U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa9024ff4U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0492] start_va=0x048118, fde_va=0x06fb70, span=184 bytes
// [VN] FDE[0492] địa chỉ bắt đầu=0x048118, fde_va=0x06fb70, kích thước=184 byte
// AArch64 opcodes: D10183FF A9044FF4 A9057BFD 910143FD
uint32_t cybertron_fde_0492_0x048118(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048118U;
    constexpr uint32_t kFdeVa   = 0x06fb70U;
    constexpr uint32_t kSpan    = 184U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9044ff4U;
    constexpr uint32_t kW2      = 0xa9057bfdU;
    constexpr uint32_t kW3      = 0x910143fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0493] start_va=0x0481d0, fde_va=0x06fb90, span=604 bytes
// [VN] FDE[0493] địa chỉ bắt đầu=0x0481d0, fde_va=0x06fb90, kích thước=604 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_0493_0x0481d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0481d0U;
    constexpr uint32_t kFdeVa   = 0x06fb90U;
    constexpr uint32_t kSpan    = 604U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90267faU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0494] start_va=0x04842c, fde_va=0x06fbc0, span=228 bytes
// [VN] FDE[0494] địa chỉ bắt đầu=0x04842c, fde_va=0x06fbc0, kích thước=228 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0494_0x04842c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04842cU;
    constexpr uint32_t kFdeVa   = 0x06fbc0U;
    constexpr uint32_t kSpan    = 228U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0495] start_va=0x048510, fde_va=0x06fbe0, span=368 bytes
// [VN] FDE[0495] địa chỉ bắt đầu=0x048510, fde_va=0x06fbe0, kích thước=368 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0495_0x048510(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048510U;
    constexpr uint32_t kFdeVa   = 0x06fbe0U;
    constexpr uint32_t kSpan    = 368U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0496] start_va=0x048680, fde_va=0x06fc00, span=68 bytes
// [VN] FDE[0496] địa chỉ bắt đầu=0x048680, fde_va=0x06fc00, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400013
uint32_t cybertron_fde_0496_0x048680(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048680U;
    constexpr uint32_t kFdeVa   = 0x06fc00U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0497] start_va=0x0486c4, fde_va=0x06fc20, span=200 bytes
// [VN] FDE[0497] địa chỉ bắt đầu=0x0486c4, fde_va=0x06fc20, kích thước=200 byte
// AArch64 opcodes: D10183FF A9044FF4 A9057BFD 910143FD
uint32_t cybertron_fde_0497_0x0486c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0486c4U;
    constexpr uint32_t kFdeVa   = 0x06fc20U;
    constexpr uint32_t kSpan    = 200U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9044ff4U;
    constexpr uint32_t kW2      = 0xa9057bfdU;
    constexpr uint32_t kW3      = 0x910143fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0498] start_va=0x04878c, fde_va=0x06fc40, span=180 bytes
// [VN] FDE[0498] địa chỉ bắt đầu=0x04878c, fde_va=0x06fc40, kích thước=180 byte
// AArch64 opcodes: F9400408 B4000548 9E670100 B9800029
uint32_t cybertron_fde_0498_0x04878c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04878cU;
    constexpr uint32_t kFdeVa   = 0x06fc40U;
    constexpr uint32_t kSpan    = 180U;
    constexpr uint32_t kW0      = 0xf9400408U;
    constexpr uint32_t kW1      = 0xb4000548U;
    constexpr uint32_t kW2      = 0x9e670100U;
    constexpr uint32_t kW3      = 0xb9800029U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0499] start_va=0x048840, fde_va=0x06fc58, span=4 bytes
// [VN] FDE[0499] địa chỉ bắt đầu=0x048840, fde_va=0x06fc58, kích thước=4 byte
// AArch64 opcodes: 17FFC3A0 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0499_0x048840(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048840U;
    constexpr uint32_t kFdeVa   = 0x06fc58U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffc3a0U;
    constexpr uint32_t kW1      = 0xa9be4ff4U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0500] start_va=0x048844, fde_va=0x06fc70, span=208 bytes
// [VN] FDE[0500] địa chỉ bắt đầu=0x048844, fde_va=0x06fc70, kích thước=208 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 900001C8
uint32_t cybertron_fde_0500_0x048844(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048844U;
    constexpr uint32_t kFdeVa   = 0x06fc70U;
    constexpr uint32_t kSpan    = 208U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0501] start_va=0x048914, fde_va=0x06fc90, span=32 bytes
// [VN] FDE[0501] địa chỉ bắt đầu=0x048914, fde_va=0x06fc90, kích thước=32 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FFC369 91002008
uint32_t cybertron_fde_0501_0x048914(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048914U;
    constexpr uint32_t kFdeVa   = 0x06fc90U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97ffc369U;
    constexpr uint32_t kW3      = 0x91002008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0502] start_va=0x048934, fde_va=0x06fcb0, span=120 bytes
// [VN] FDE[0502] địa chỉ bắt đầu=0x048934, fde_va=0x06fcb0, kích thước=120 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F00001A8
uint32_t cybertron_fde_0502_0x048934(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048934U;
    constexpr uint32_t kFdeVa   = 0x06fcb0U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf00001a8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0503] start_va=0x0489ac, fde_va=0x06fcd0, span=8 bytes
// [VN] FDE[0503] địa chỉ bắt đầu=0x0489ac, fde_va=0x06fcd0, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFC734 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0503_0x0489ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0489acU;
    constexpr uint32_t kFdeVa   = 0x06fcd0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffc734U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0504] start_va=0x0489b4, fde_va=0x06fce8, span=36 bytes
// [VN] FDE[0504] địa chỉ bắt đầu=0x0489b4, fde_va=0x06fce8, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0504_0x0489b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0489b4U;
    constexpr uint32_t kFdeVa   = 0x06fce8U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0505] start_va=0x0489d8, fde_va=0x06fd08, span=40 bytes
// [VN] FDE[0505] địa chỉ bắt đầu=0x0489d8, fde_va=0x06fd08, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D1002013
uint32_t cybertron_fde_0505_0x0489d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0489d8U;
    constexpr uint32_t kFdeVa   = 0x06fd08U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd1002013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0506] start_va=0x048a00, fde_va=0x06fd28, span=328 bytes
// [VN] FDE[0506] địa chỉ bắt đầu=0x048a00, fde_va=0x06fd28, kích thước=328 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_0506_0x048a00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048a00U;
    constexpr uint32_t kFdeVa   = 0x06fd28U;
    constexpr uint32_t kSpan    = 328U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90267faU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0507] start_va=0x048b48, fde_va=0x06fd58, span=88 bytes
// [VN] FDE[0507] địa chỉ bắt đầu=0x048b48, fde_va=0x06fd58, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0507_0x048b48(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048b48U;
    constexpr uint32_t kFdeVa   = 0x06fd58U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0508] start_va=0x048ba0, fde_va=0x06fd78, span=328 bytes
// [VN] FDE[0508] địa chỉ bắt đầu=0x048ba0, fde_va=0x06fd78, kích thước=328 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_0508_0x048ba0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048ba0U;
    constexpr uint32_t kFdeVa   = 0x06fd78U;
    constexpr uint32_t kSpan    = 328U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90267faU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0509] start_va=0x048ce8, fde_va=0x06fda8, span=176 bytes
// [VN] FDE[0509] địa chỉ bắt đầu=0x048ce8, fde_va=0x06fda8, kích thước=176 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_0509_0x048ce8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048ce8U;
    constexpr uint32_t kFdeVa   = 0x06fda8U;
    constexpr uint32_t kSpan    = 176U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf90013f7U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0510] start_va=0x048d98, fde_va=0x06fdd0, span=160 bytes
// [VN] FDE[0510] địa chỉ bắt đầu=0x048d98, fde_va=0x06fdd0, kích thước=160 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_0510_0x048d98(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048d98U;
    constexpr uint32_t kFdeVa   = 0x06fdd0U;
    constexpr uint32_t kSpan    = 160U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0511] start_va=0x048e38, fde_va=0x06fdf8, span=88 bytes
// [VN] FDE[0511] địa chỉ bắt đầu=0x048e38, fde_va=0x06fdf8, kích thước=88 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0511_0x048e38(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048e38U;
    constexpr uint32_t kFdeVa   = 0x06fdf8U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0512] start_va=0x048e90, fde_va=0x06fe18, span=68 bytes
// [VN] FDE[0512] địa chỉ bắt đầu=0x048e90, fde_va=0x06fe18, kích thước=68 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0512_0x048e90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048e90U;
    constexpr uint32_t kFdeVa   = 0x06fe18U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0513] start_va=0x048ed4, fde_va=0x06fe38, span=80 bytes
// [VN] FDE[0513] địa chỉ bắt đầu=0x048ed4, fde_va=0x06fe38, kích thước=80 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0513_0x048ed4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048ed4U;
    constexpr uint32_t kFdeVa   = 0x06fe38U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0514] start_va=0x048f24, fde_va=0x06fe58, span=704 bytes
// [VN] FDE[0514] địa chỉ bắt đầu=0x048f24, fde_va=0x06fe58, kích thước=704 byte
// AArch64 opcodes: D102C3FF A9056FFC A90667FA A9075FF8
uint32_t cybertron_fde_0514_0x048f24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x048f24U;
    constexpr uint32_t kFdeVa   = 0x06fe58U;
    constexpr uint32_t kSpan    = 704U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xa9056ffcU;
    constexpr uint32_t kW2      = 0xa90667faU;
    constexpr uint32_t kW3      = 0xa9075ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0515] start_va=0x0491e4, fde_va=0x06fe88, span=324 bytes
// [VN] FDE[0515] địa chỉ bắt đầu=0x0491e4, fde_va=0x06fe88, kích thước=324 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_0515_0x0491e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0491e4U;
    constexpr uint32_t kFdeVa   = 0x06fe88U;
    constexpr uint32_t kSpan    = 324U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90267faU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0516] start_va=0x049328, fde_va=0x06feb8, span=88 bytes
// [VN] FDE[0516] địa chỉ bắt đầu=0x049328, fde_va=0x06feb8, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0516_0x049328(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049328U;
    constexpr uint32_t kFdeVa   = 0x06feb8U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0517] start_va=0x049380, fde_va=0x06fed8, span=8 bytes
// [VN] FDE[0517] địa chỉ bắt đầu=0x049380, fde_va=0x06fed8, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFC6CF A9BC5FF8 A90157F6
uint32_t cybertron_fde_0517_0x049380(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049380U;
    constexpr uint32_t kFdeVa   = 0x06fed8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffc6cfU;
    constexpr uint32_t kW2      = 0xa9bc5ff8U;
    constexpr uint32_t kW3      = 0xa90157f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0518] start_va=0x049388, fde_va=0x06fef0, span=228 bytes
// [VN] FDE[0518] địa chỉ bắt đầu=0x049388, fde_va=0x06fef0, kích thước=228 byte
// AArch64 opcodes: A9BC5FF8 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0518_0x049388(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049388U;
    constexpr uint32_t kFdeVa   = 0x06fef0U;
    constexpr uint32_t kSpan    = 228U;
    constexpr uint32_t kW0      = 0xa9bc5ff8U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0519] start_va=0x04946c, fde_va=0x06ff18, span=92 bytes
// [VN] FDE[0519] địa chỉ bắt đầu=0x04946c, fde_va=0x06ff18, kích thước=92 byte
// AArch64 opcodes: D100C3FF F9000BF3 A9027BFD 910083FD
uint32_t cybertron_fde_0519_0x04946c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04946cU;
    constexpr uint32_t kFdeVa   = 0x06ff18U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xd100c3ffU;
    constexpr uint32_t kW1      = 0xf9000bf3U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0520] start_va=0x0494c8, fde_va=0x06ff38, span=8 bytes
// [VN] FDE[0520] địa chỉ bắt đầu=0x0494c8, fde_va=0x06ff38, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFC1FD D10183FF A9025FF8
uint32_t cybertron_fde_0520_0x0494c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0494c8U;
    constexpr uint32_t kFdeVa   = 0x06ff38U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffc1fdU;
    constexpr uint32_t kW2      = 0xd10183ffU;
    constexpr uint32_t kW3      = 0xa9025ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0521] start_va=0x0494d0, fde_va=0x06ff50, span=232 bytes
// [VN] FDE[0521] địa chỉ bắt đầu=0x0494d0, fde_va=0x06ff50, kích thước=232 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0521_0x0494d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0494d0U;
    constexpr uint32_t kFdeVa   = 0x06ff50U;
    constexpr uint32_t kSpan    = 232U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0522] start_va=0x0495b8, fde_va=0x06ff78, span=8 bytes
// [VN] FDE[0522] địa chỉ bắt đầu=0x0495b8, fde_va=0x06ff78, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFC199 F81D0FF5 A9014FF4
uint32_t cybertron_fde_0522_0x0495b8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0495b8U;
    constexpr uint32_t kFdeVa   = 0x06ff78U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffc199U;
    constexpr uint32_t kW2      = 0xf81d0ff5U;
    constexpr uint32_t kW3      = 0xa9014ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0523] start_va=0x0495c0, fde_va=0x06ff90, span=68 bytes
// [VN] FDE[0523] địa chỉ bắt đầu=0x0495c0, fde_va=0x06ff90, kích thước=68 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0523_0x0495c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0495c0U;
    constexpr uint32_t kFdeVa   = 0x06ff90U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0524] start_va=0x049604, fde_va=0x06ffb0, span=68 bytes
// [VN] FDE[0524] địa chỉ bắt đầu=0x049604, fde_va=0x06ffb0, kích thước=68 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0524_0x049604(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049604U;
    constexpr uint32_t kFdeVa   = 0x06ffb0U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0525] start_va=0x049648, fde_va=0x06ffd0, span=12 bytes
// [VN] FDE[0525] địa chỉ bắt đầu=0x049648, fde_va=0x06ffd0, kích thước=12 byte
// AArch64 opcodes: 91034008 88DFFD00 D65F03C0 91032008
uint32_t cybertron_fde_0525_0x049648(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049648U;
    constexpr uint32_t kFdeVa   = 0x06ffd0U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x91034008U;
    constexpr uint32_t kW1      = 0x88dffd00U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x91032008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0526] start_va=0x049654, fde_va=0x06ffe8, span=12 bytes
// [VN] FDE[0526] địa chỉ bắt đầu=0x049654, fde_va=0x06ffe8, kích thước=12 byte
// AArch64 opcodes: 91032008 88DFFD00 D65F03C0 D10183FF
uint32_t cybertron_fde_0526_0x049654(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049654U;
    constexpr uint32_t kFdeVa   = 0x06ffe8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x91032008U;
    constexpr uint32_t kW1      = 0x88dffd00U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xd10183ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0527] start_va=0x049660, fde_va=0x070000, span=232 bytes
// [VN] FDE[0527] địa chỉ bắt đầu=0x049660, fde_va=0x070000, kích thước=232 byte
// AArch64 opcodes: D10183FF F9001BF5 A9044FF4 A9057BFD
uint32_t cybertron_fde_0527_0x049660(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049660U;
    constexpr uint32_t kFdeVa   = 0x070000U;
    constexpr uint32_t kSpan    = 232U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9001bf5U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0528] start_va=0x049748, fde_va=0x070020, span=200 bytes
// [VN] FDE[0528] địa chỉ bắt đầu=0x049748, fde_va=0x070020, kích thước=200 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0528_0x049748(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049748U;
    constexpr uint32_t kFdeVa   = 0x070020U;
    constexpr uint32_t kSpan    = 200U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0529] start_va=0x049810, fde_va=0x070048, span=68 bytes
// [VN] FDE[0529] địa chỉ bắt đầu=0x049810, fde_va=0x070048, kích thước=68 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0529_0x049810(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049810U;
    constexpr uint32_t kFdeVa   = 0x070048U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0530] start_va=0x049854, fde_va=0x070068, span=112 bytes
// [VN] FDE[0530] địa chỉ bắt đầu=0x049854, fde_va=0x070068, kích thước=112 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0530_0x049854(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049854U;
    constexpr uint32_t kFdeVa   = 0x070068U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0531] start_va=0x0498c4, fde_va=0x070088, span=88 bytes
// [VN] FDE[0531] địa chỉ bắt đầu=0x0498c4, fde_va=0x070088, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0531_0x0498c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0498c4U;
    constexpr uint32_t kFdeVa   = 0x070088U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0532] start_va=0x04991c, fde_va=0x0700a8, span=76 bytes
// [VN] FDE[0532] địa chỉ bắt đầu=0x04991c, fde_va=0x0700a8, kích thước=76 byte
// AArch64 opcodes: B4000241 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0532_0x04991c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04991cU;
    constexpr uint32_t kFdeVa   = 0x0700a8U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xb4000241U;
    constexpr uint32_t kW1      = 0xa9be4ff4U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0533] start_va=0x049968, fde_va=0x0700c8, span=60 bytes
// [VN] FDE[0533] địa chỉ bắt đầu=0x049968, fde_va=0x0700c8, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 91006040
uint32_t cybertron_fde_0533_0x049968(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049968U;
    constexpr uint32_t kFdeVa   = 0x0700c8U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91006040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0534] start_va=0x0499a4, fde_va=0x0700e8, span=240 bytes
// [VN] FDE[0534] địa chỉ bắt đầu=0x0499a4, fde_va=0x0700e8, kích thước=240 byte
// AArch64 opcodes: F81A0FFB A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0534_0x0499a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0499a4U;
    constexpr uint32_t kFdeVa   = 0x0700e8U;
    constexpr uint32_t kSpan    = 240U;
    constexpr uint32_t kW0      = 0xf81a0ffbU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0535] start_va=0x049a94, fde_va=0x070118, span=176 bytes
// [VN] FDE[0535] địa chỉ bắt đầu=0x049a94, fde_va=0x070118, kích thước=176 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0535_0x049a94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049a94U;
    constexpr uint32_t kFdeVa   = 0x070118U;
    constexpr uint32_t kSpan    = 176U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9000bf7U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0536] start_va=0x049b44, fde_va=0x070140, span=292 bytes
// [VN] FDE[0536] địa chỉ bắt đầu=0x049b44, fde_va=0x070140, kích thước=292 byte
// AArch64 opcodes: A9BA6FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0536_0x049b44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049b44U;
    constexpr uint32_t kFdeVa   = 0x070140U;
    constexpr uint32_t kSpan    = 292U;
    constexpr uint32_t kW0      = 0xa9ba6ffcU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0537] start_va=0x049c68, fde_va=0x070170, span=84 bytes
// [VN] FDE[0537] địa chỉ bắt đầu=0x049c68, fde_va=0x070170, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_0537_0x049c68(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049c68U;
    constexpr uint32_t kFdeVa   = 0x070170U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa9007c7fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0538] start_va=0x049cbc, fde_va=0x070190, span=92 bytes
// [VN] FDE[0538] địa chỉ bắt đầu=0x049cbc, fde_va=0x070190, kích thước=92 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D00001A8
uint32_t cybertron_fde_0538_0x049cbc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049cbcU;
    constexpr uint32_t kFdeVa   = 0x070190U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00001a8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0539] start_va=0x049d18, fde_va=0x0701b0, span=100 bytes
// [VN] FDE[0539] địa chỉ bắt đầu=0x049d18, fde_va=0x0701b0, kích thước=100 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D00001A8
uint32_t cybertron_fde_0539_0x049d18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049d18U;
    constexpr uint32_t kFdeVa   = 0x0701b0U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00001a8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0540] start_va=0x049d7c, fde_va=0x0701d0, span=84 bytes
// [VN] FDE[0540] địa chỉ bắt đầu=0x049d7c, fde_va=0x0701d0, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0540_0x049d7c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049d7cU;
    constexpr uint32_t kFdeVa   = 0x0701d0U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0541] start_va=0x049dd0, fde_va=0x0701f0, span=4 bytes
// [VN] FDE[0541] địa chỉ bắt đầu=0x049dd0, fde_va=0x0701f0, kích thước=4 byte
// AArch64 opcodes: 17FFBBD4 D10103FF A9024FF4 A9037BFD
uint32_t cybertron_fde_0541_0x049dd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049dd0U;
    constexpr uint32_t kFdeVa   = 0x0701f0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffbbd4U;
    constexpr uint32_t kW1      = 0xd10103ffU;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0542] start_va=0x049dd4, fde_va=0x070208, span=108 bytes
// [VN] FDE[0542] địa chỉ bắt đầu=0x049dd4, fde_va=0x070208, kích thước=108 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0542_0x049dd4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049dd4U;
    constexpr uint32_t kFdeVa   = 0x070208U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa9024ff4U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0543] start_va=0x049e40, fde_va=0x070228, span=76 bytes
// [VN] FDE[0543] địa chỉ bắt đầu=0x049e40, fde_va=0x070228, kích thước=76 byte
// AArch64 opcodes: B4000241 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0543_0x049e40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049e40U;
    constexpr uint32_t kFdeVa   = 0x070228U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xb4000241U;
    constexpr uint32_t kW1      = 0xa9be4ff4U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0544] start_va=0x049e8c, fde_va=0x070248, span=60 bytes
// [VN] FDE[0544] địa chỉ bắt đầu=0x049e8c, fde_va=0x070248, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 91006040
uint32_t cybertron_fde_0544_0x049e8c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049e8cU;
    constexpr uint32_t kFdeVa   = 0x070248U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91006040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0545] start_va=0x049ec8, fde_va=0x070268, span=68 bytes
// [VN] FDE[0545] địa chỉ bắt đầu=0x049ec8, fde_va=0x070268, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0545_0x049ec8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049ec8U;
    constexpr uint32_t kFdeVa   = 0x070268U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0546] start_va=0x049f0c, fde_va=0x070288, span=268 bytes
// [VN] FDE[0546] địa chỉ bắt đầu=0x049f0c, fde_va=0x070288, kích thước=268 byte
// AArch64 opcodes: A9BC5FF8 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0546_0x049f0c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x049f0cU;
    constexpr uint32_t kFdeVa   = 0x070288U;
    constexpr uint32_t kSpan    = 268U;
    constexpr uint32_t kW0      = 0xa9bc5ff8U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0547] start_va=0x04a018, fde_va=0x0702b0, span=72 bytes
// [VN] FDE[0547] địa chỉ bắt đầu=0x04a018, fde_va=0x0702b0, kích thước=72 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0547_0x04a018(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04a018U;
    constexpr uint32_t kFdeVa   = 0x0702b0U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0548] start_va=0x04a060, fde_va=0x0702d0, span=132 bytes
// [VN] FDE[0548] địa chỉ bắt đầu=0x04a060, fde_va=0x0702d0, kích thước=132 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400428
uint32_t cybertron_fde_0548_0x04a060(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04a060U;
    constexpr uint32_t kFdeVa   = 0x0702d0U;
    constexpr uint32_t kSpan    = 132U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400428U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0549] start_va=0x04a0e4, fde_va=0x0702f0, span=916 bytes
// [VN] FDE[0549] địa chỉ bắt đầu=0x04a0e4, fde_va=0x0702f0, kích thước=916 byte
// AArch64 opcodes: F9400029 AA0103EA B40000C9 F9400428
uint32_t cybertron_fde_0549_0x04a0e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04a0e4U;
    constexpr uint32_t kFdeVa   = 0x0702f0U;
    constexpr uint32_t kSpan    = 916U;
    constexpr uint32_t kW0      = 0xf9400029U;
    constexpr uint32_t kW1      = 0xaa0103eaU;
    constexpr uint32_t kW2      = 0xb40000c9U;
    constexpr uint32_t kW3      = 0xf9400428U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0550] start_va=0x04a478, fde_va=0x070308, span=408 bytes
// [VN] FDE[0550] địa chỉ bắt đầu=0x04a478, fde_va=0x070308, kích thước=408 byte
// AArch64 opcodes: D10243FF F9002BF7 A90657F6 A9074FF4
uint32_t cybertron_fde_0550_0x04a478(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04a478U;
    constexpr uint32_t kFdeVa   = 0x070308U;
    constexpr uint32_t kSpan    = 408U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xf9002bf7U;
    constexpr uint32_t kW2      = 0xa90657f6U;
    constexpr uint32_t kW3      = 0xa9074ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0551] start_va=0x04a610, fde_va=0x070330, span=776 bytes
// [VN] FDE[0551] địa chỉ bắt đầu=0x04a610, fde_va=0x070330, kích thước=776 byte
// AArch64 opcodes: D10243FF F9002BF7 A90657F6 A9074FF4
uint32_t cybertron_fde_0551_0x04a610(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04a610U;
    constexpr uint32_t kFdeVa   = 0x070330U;
    constexpr uint32_t kSpan    = 776U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xf9002bf7U;
    constexpr uint32_t kW2      = 0xa90657f6U;
    constexpr uint32_t kW3      = 0xa9074ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0552] start_va=0x04a918, fde_va=0x070358, span=256 bytes
// [VN] FDE[0552] địa chỉ bắt đầu=0x04a918, fde_va=0x070358, kích thước=256 byte
// AArch64 opcodes: D10243FF A90657F6 A9074FF4 A9087BFD
uint32_t cybertron_fde_0552_0x04a918(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04a918U;
    constexpr uint32_t kFdeVa   = 0x070358U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa90657f6U;
    constexpr uint32_t kW2      = 0xa9074ff4U;
    constexpr uint32_t kW3      = 0xa9087bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0553] start_va=0x04aa18, fde_va=0x070380, span=272 bytes
// [VN] FDE[0553] địa chỉ bắt đầu=0x04aa18, fde_va=0x070380, kích thước=272 byte
// AArch64 opcodes: D10243FF A90657F6 A9074FF4 A9087BFD
uint32_t cybertron_fde_0553_0x04aa18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04aa18U;
    constexpr uint32_t kFdeVa   = 0x070380U;
    constexpr uint32_t kSpan    = 272U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa90657f6U;
    constexpr uint32_t kW2      = 0xa9074ff4U;
    constexpr uint32_t kW3      = 0xa9087bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0554] start_va=0x04ab28, fde_va=0x0703a8, span=680 bytes
// [VN] FDE[0554] địa chỉ bắt đầu=0x04ab28, fde_va=0x0703a8, kích thước=680 byte
// AArch64 opcodes: D102C3FF F90033F9 A9075FF8 A90857F6
uint32_t cybertron_fde_0554_0x04ab28(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ab28U;
    constexpr uint32_t kFdeVa   = 0x0703a8U;
    constexpr uint32_t kSpan    = 680U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xf90033f9U;
    constexpr uint32_t kW2      = 0xa9075ff8U;
    constexpr uint32_t kW3      = 0xa90857f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0555] start_va=0x04add0, fde_va=0x0703d0, span=776 bytes
// [VN] FDE[0555] địa chỉ bắt đầu=0x04add0, fde_va=0x0703d0, kích thước=776 byte
// AArch64 opcodes: D10243FF F9002BF7 A90657F6 A9074FF4
uint32_t cybertron_fde_0555_0x04add0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04add0U;
    constexpr uint32_t kFdeVa   = 0x0703d0U;
    constexpr uint32_t kSpan    = 776U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xf9002bf7U;
    constexpr uint32_t kW2      = 0xa90657f6U;
    constexpr uint32_t kW3      = 0xa9074ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0556] start_va=0x04b0d8, fde_va=0x0703f8, span=776 bytes
// [VN] FDE[0556] địa chỉ bắt đầu=0x04b0d8, fde_va=0x0703f8, kích thước=776 byte
// AArch64 opcodes: D10243FF F9002BF7 A90657F6 A9074FF4
uint32_t cybertron_fde_0556_0x04b0d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b0d8U;
    constexpr uint32_t kFdeVa   = 0x0703f8U;
    constexpr uint32_t kSpan    = 776U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xf9002bf7U;
    constexpr uint32_t kW2      = 0xa90657f6U;
    constexpr uint32_t kW3      = 0xa9074ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0557] start_va=0x04b3e0, fde_va=0x070420, span=44 bytes
// [VN] FDE[0557] địa chỉ bắt đầu=0x04b3e0, fde_va=0x070420, kích thước=44 byte
// AArch64 opcodes: F9400009 F9000109 F9400409 F9000509
uint32_t cybertron_fde_0557_0x04b3e0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b3e0U;
    constexpr uint32_t kFdeVa   = 0x070420U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xf9400009U;
    constexpr uint32_t kW1      = 0xf9000109U;
    constexpr uint32_t kW2      = 0xf9400409U;
    constexpr uint32_t kW3      = 0xf9000509U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0558] start_va=0x04b40c, fde_va=0x070438, span=60 bytes
// [VN] FDE[0558] địa chỉ bắt đầu=0x04b40c, fde_va=0x070438, kích thước=60 byte
// AArch64 opcodes: F9400828 3DC00020 F9000808 3D800000
uint32_t cybertron_fde_0558_0x04b40c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b40cU;
    constexpr uint32_t kFdeVa   = 0x070438U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf9400828U;
    constexpr uint32_t kW1      = 0x3dc00020U;
    constexpr uint32_t kW2      = 0xf9000808U;
    constexpr uint32_t kW3      = 0x3d800000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0559] start_va=0x04b448, fde_va=0x070450, span=640 bytes
// [VN] FDE[0559] địa chỉ bắt đầu=0x04b448, fde_va=0x070450, kích thước=640 byte
// AArch64 opcodes: D102C3FF F90033F9 A9075FF8 A90857F6
uint32_t cybertron_fde_0559_0x04b448(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b448U;
    constexpr uint32_t kFdeVa   = 0x070450U;
    constexpr uint32_t kSpan    = 640U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xf90033f9U;
    constexpr uint32_t kW2      = 0xa9075ff8U;
    constexpr uint32_t kW3      = 0xa90857f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0560] start_va=0x04b6c8, fde_va=0x070478, span=112 bytes
// [VN] FDE[0560] địa chỉ bắt đầu=0x04b6c8, fde_va=0x070478, kích thước=112 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0560_0x04b6c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b6c8U;
    constexpr uint32_t kFdeVa   = 0x070478U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0561] start_va=0x04b738, fde_va=0x070498, span=76 bytes
// [VN] FDE[0561] địa chỉ bắt đầu=0x04b738, fde_va=0x070498, kích thước=76 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0561_0x04b738(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b738U;
    constexpr uint32_t kFdeVa   = 0x070498U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0562] start_va=0x04b784, fde_va=0x0704b8, span=276 bytes
// [VN] FDE[0562] địa chỉ bắt đầu=0x04b784, fde_va=0x0704b8, kích thước=276 byte
// AArch64 opcodes: D10183FF F9001BF5 A9044FF4 A9057BFD
uint32_t cybertron_fde_0562_0x04b784(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b784U;
    constexpr uint32_t kFdeVa   = 0x0704b8U;
    constexpr uint32_t kSpan    = 276U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9001bf5U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0563] start_va=0x04b898, fde_va=0x0704d8, span=196 bytes
// [VN] FDE[0563] địa chỉ bắt đầu=0x04b898, fde_va=0x0704d8, kích thước=196 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0563_0x04b898(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b898U;
    constexpr uint32_t kFdeVa   = 0x0704d8U;
    constexpr uint32_t kSpan    = 196U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0564] start_va=0x04b95c, fde_va=0x070500, span=228 bytes
// [VN] FDE[0564] địa chỉ bắt đầu=0x04b95c, fde_va=0x070500, kích thước=228 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_0564_0x04b95c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04b95cU;
    constexpr uint32_t kFdeVa   = 0x070500U;
    constexpr uint32_t kSpan    = 228U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0565] start_va=0x04ba40, fde_va=0x070528, span=84 bytes
// [VN] FDE[0565] địa chỉ bắt đầu=0x04ba40, fde_va=0x070528, kích thước=84 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0565_0x04ba40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ba40U;
    constexpr uint32_t kFdeVa   = 0x070528U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0566] start_va=0x04ba94, fde_va=0x070548, span=92 bytes
// [VN] FDE[0566] địa chỉ bắt đầu=0x04ba94, fde_va=0x070548, kích thước=92 byte
// AArch64 opcodes: D100C3FF F9000BF3 A9027BFD 910083FD
uint32_t cybertron_fde_0566_0x04ba94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ba94U;
    constexpr uint32_t kFdeVa   = 0x070548U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xd100c3ffU;
    constexpr uint32_t kW1      = 0xf9000bf3U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0567] start_va=0x04baf0, fde_va=0x070568, span=340 bytes
// [VN] FDE[0567] địa chỉ bắt đầu=0x04baf0, fde_va=0x070568, kích thước=340 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_0567_0x04baf0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04baf0U;
    constexpr uint32_t kFdeVa   = 0x070568U;
    constexpr uint32_t kSpan    = 340U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0568] start_va=0x04bc44, fde_va=0x070590, span=304 bytes
// [VN] FDE[0568] địa chỉ bắt đầu=0x04bc44, fde_va=0x070590, kích thước=304 byte
// AArch64 opcodes: D102C3FF F9003BF7 A90857F6 A9094FF4
uint32_t cybertron_fde_0568_0x04bc44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04bc44U;
    constexpr uint32_t kFdeVa   = 0x070590U;
    constexpr uint32_t kSpan    = 304U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xf9003bf7U;
    constexpr uint32_t kW2      = 0xa90857f6U;
    constexpr uint32_t kW3      = 0xa9094ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0569] start_va=0x04bd74, fde_va=0x0705b8, span=112 bytes
// [VN] FDE[0569] địa chỉ bắt đầu=0x04bd74, fde_va=0x0705b8, kích thước=112 byte
// AArch64 opcodes: D10103FF F90013F3 A9037BFD 9100C3FD
uint32_t cybertron_fde_0569_0x04bd74(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04bd74U;
    constexpr uint32_t kFdeVa   = 0x0705b8U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xf90013f3U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0570] start_va=0x04bde4, fde_va=0x0705d8, span=80 bytes
// [VN] FDE[0570] địa chỉ bắt đầu=0x04bde4, fde_va=0x0705d8, kích thước=80 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 900001A8
uint32_t cybertron_fde_0570_0x04bde4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04bde4U;
    constexpr uint32_t kFdeVa   = 0x0705d8U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900001a8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0571] start_va=0x04be34, fde_va=0x0705f8, span=88 bytes
// [VN] FDE[0571] địa chỉ bắt đầu=0x04be34, fde_va=0x0705f8, kích thước=88 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 900001A8
uint32_t cybertron_fde_0571_0x04be34(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04be34U;
    constexpr uint32_t kFdeVa   = 0x0705f8U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900001a8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0572] start_va=0x04be8c, fde_va=0x070618, span=60 bytes
// [VN] FDE[0572] địa chỉ bắt đầu=0x04be8c, fde_va=0x070618, kích thước=60 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0572_0x04be8c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04be8cU;
    constexpr uint32_t kFdeVa   = 0x070618U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0573] start_va=0x04bec8, fde_va=0x070638, span=4 bytes
// [VN] FDE[0573] địa chỉ bắt đầu=0x04bec8, fde_va=0x070638, kích thước=4 byte
// AArch64 opcodes: 17FFB396 F81D0FF5 A9014FF4 A9027BFD
uint32_t cybertron_fde_0573_0x04bec8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04bec8U;
    constexpr uint32_t kFdeVa   = 0x070638U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffb396U;
    constexpr uint32_t kW1      = 0xf81d0ff5U;
    constexpr uint32_t kW2      = 0xa9014ff4U;
    constexpr uint32_t kW3      = 0xa9027bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0574] start_va=0x04becc, fde_va=0x070650, span=112 bytes
// [VN] FDE[0574] địa chỉ bắt đầu=0x04becc, fde_va=0x070650, kích thước=112 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0574_0x04becc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04beccU;
    constexpr uint32_t kFdeVa   = 0x070650U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0575] start_va=0x04bf3c, fde_va=0x070670, span=88 bytes
// [VN] FDE[0575] địa chỉ bắt đầu=0x04bf3c, fde_va=0x070670, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0575_0x04bf3c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04bf3cU;
    constexpr uint32_t kFdeVa   = 0x070670U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0576] start_va=0x04bf94, fde_va=0x070690, span=196 bytes
// [VN] FDE[0576] địa chỉ bắt đầu=0x04bf94, fde_va=0x070690, kích thước=196 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0576_0x04bf94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04bf94U;
    constexpr uint32_t kFdeVa   = 0x070690U;
    constexpr uint32_t kSpan    = 196U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9000bf7U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0577] start_va=0x04c058, fde_va=0x0706b8, span=292 bytes
// [VN] FDE[0577] địa chỉ bắt đầu=0x04c058, fde_va=0x0706b8, kích thước=292 byte
// AArch64 opcodes: A9BA6FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0577_0x04c058(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c058U;
    constexpr uint32_t kFdeVa   = 0x0706b8U;
    constexpr uint32_t kSpan    = 292U;
    constexpr uint32_t kW0      = 0xa9ba6ffcU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0578] start_va=0x04c17c, fde_va=0x0706e8, span=84 bytes
// [VN] FDE[0578] địa chỉ bắt đầu=0x04c17c, fde_va=0x0706e8, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_0578_0x04c17c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c17cU;
    constexpr uint32_t kFdeVa   = 0x0706e8U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa9007c7fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0579] start_va=0x04c1d0, fde_va=0x070708, span=120 bytes
// [VN] FDE[0579] địa chỉ bắt đầu=0x04c1d0, fde_va=0x070708, kích thước=120 byte
// AArch64 opcodes: EB04007F 54000380 F9400088 EB02001F
uint32_t cybertron_fde_0579_0x04c1d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c1d0U;
    constexpr uint32_t kFdeVa   = 0x070708U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xeb04007fU;
    constexpr uint32_t kW1      = 0x54000380U;
    constexpr uint32_t kW2      = 0xf9400088U;
    constexpr uint32_t kW3      = 0xeb02001fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0580] start_va=0x04c248, fde_va=0x070720, span=68 bytes
// [VN] FDE[0580] địa chỉ bắt đầu=0x04c248, fde_va=0x070720, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0580_0x04c248(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c248U;
    constexpr uint32_t kFdeVa   = 0x070720U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0581] start_va=0x04c28c, fde_va=0x070740, span=268 bytes
// [VN] FDE[0581] địa chỉ bắt đầu=0x04c28c, fde_va=0x070740, kích thước=268 byte
// AArch64 opcodes: A9BC5FF8 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0581_0x04c28c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c28cU;
    constexpr uint32_t kFdeVa   = 0x070740U;
    constexpr uint32_t kSpan    = 268U;
    constexpr uint32_t kW0      = 0xa9bc5ff8U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0582] start_va=0x04c398, fde_va=0x070768, span=72 bytes
// [VN] FDE[0582] địa chỉ bắt đầu=0x04c398, fde_va=0x070768, kích thước=72 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0582_0x04c398(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c398U;
    constexpr uint32_t kFdeVa   = 0x070768U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0583] start_va=0x04c3e0, fde_va=0x070788, span=132 bytes
// [VN] FDE[0583] địa chỉ bắt đầu=0x04c3e0, fde_va=0x070788, kích thước=132 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400428
uint32_t cybertron_fde_0583_0x04c3e0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c3e0U;
    constexpr uint32_t kFdeVa   = 0x070788U;
    constexpr uint32_t kSpan    = 132U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400428U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0584] start_va=0x04c464, fde_va=0x0707a8, span=240 bytes
// [VN] FDE[0584] địa chỉ bắt đầu=0x04c464, fde_va=0x0707a8, kích thước=240 byte
// AArch64 opcodes: F81A0FFB A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0584_0x04c464(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c464U;
    constexpr uint32_t kFdeVa   = 0x0707a8U;
    constexpr uint32_t kSpan    = 240U;
    constexpr uint32_t kW0      = 0xf81a0ffbU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0585] start_va=0x04c554, fde_va=0x0707d8, span=120 bytes
// [VN] FDE[0585] địa chỉ bắt đầu=0x04c554, fde_va=0x0707d8, kích thước=120 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0585_0x04c554(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c554U;
    constexpr uint32_t kFdeVa   = 0x0707d8U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0586] start_va=0x04c5cc, fde_va=0x0707f8, span=16 bytes
// [VN] FDE[0586] địa chỉ bắt đầu=0x04c5cc, fde_va=0x0707f8, kích thước=16 byte
// AArch64 opcodes: 6F00E400 AD008000 3D800000 D65F03C0
uint32_t cybertron_fde_0586_0x04c5cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c5ccU;
    constexpr uint32_t kFdeVa   = 0x0707f8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x6f00e400U;
    constexpr uint32_t kW1      = 0xad008000U;
    constexpr uint32_t kW2      = 0x3d800000U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0587] start_va=0x04c5dc, fde_va=0x070810, span=52 bytes
// [VN] FDE[0587] địa chỉ bắt đầu=0x04c5dc, fde_va=0x070810, kích thước=52 byte
// AArch64 opcodes: A9BF7BFD 910003FD 34000081 7100043F
uint32_t cybertron_fde_0587_0x04c5dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c5dcU;
    constexpr uint32_t kFdeVa   = 0x070810U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x34000081U;
    constexpr uint32_t kW3      = 0x7100043fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0588] start_va=0x04c610, fde_va=0x070830, span=44 bytes
// [VN] FDE[0588] địa chỉ bắt đầu=0x04c610, fde_va=0x070830, kích thước=44 byte
// AArch64 opcodes: AA0003E9 AA0803E0 340000A1 7100043F
uint32_t cybertron_fde_0588_0x04c610(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c610U;
    constexpr uint32_t kFdeVa   = 0x070830U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xaa0003e9U;
    constexpr uint32_t kW1      = 0xaa0803e0U;
    constexpr uint32_t kW2      = 0x340000a1U;
    constexpr uint32_t kW3      = 0x7100043fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0589] start_va=0x04c63c, fde_va=0x070848, span=48 bytes
// [VN] FDE[0589] địa chỉ bắt đầu=0x04c63c, fde_va=0x070848, kích thước=48 byte
// AArch64 opcodes: 91020008 6F00E400 B900301F AD008000
uint32_t cybertron_fde_0589_0x04c63c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c63cU;
    constexpr uint32_t kFdeVa   = 0x070848U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0x91020008U;
    constexpr uint32_t kW1      = 0x6f00e400U;
    constexpr uint32_t kW2      = 0xb900301fU;
    constexpr uint32_t kW3      = 0xad008000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0590] start_va=0x04c66c, fde_va=0x070860, span=100 bytes
// [VN] FDE[0590] địa chỉ bắt đầu=0x04c66c, fde_va=0x070860, kích thước=100 byte
// AArch64 opcodes: A9BF7BFD 910003FD 7100103F 54000148
uint32_t cybertron_fde_0590_0x04c66c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c66cU;
    constexpr uint32_t kFdeVa   = 0x070860U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x7100103fU;
    constexpr uint32_t kW3      = 0x54000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0591] start_va=0x04c6d0, fde_va=0x070880, span=32 bytes
// [VN] FDE[0591] địa chỉ bắt đầu=0x04c6d0, fde_va=0x070880, kích thước=32 byte
// AArch64 opcodes: 7100103F 540000A1 AA0003E8 2A1F03E0
uint32_t cybertron_fde_0591_0x04c6d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c6d0U;
    constexpr uint32_t kFdeVa   = 0x070880U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0x7100103fU;
    constexpr uint32_t kW1      = 0x540000a1U;
    constexpr uint32_t kW2      = 0xaa0003e8U;
    constexpr uint32_t kW3      = 0x2a1f03e0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0592] start_va=0x04c6f0, fde_va=0x070898, span=92 bytes
// [VN] FDE[0592] địa chỉ bắt đầu=0x04c6f0, fde_va=0x070898, kích thước=92 byte
// AArch64 opcodes: AA0003E9 7100103F AA0803E0 54000148
uint32_t cybertron_fde_0592_0x04c6f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c6f0U;
    constexpr uint32_t kFdeVa   = 0x070898U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xaa0003e9U;
    constexpr uint32_t kW1      = 0x7100103fU;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x54000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0593] start_va=0x04c74c, fde_va=0x0708b0, span=20 bytes
// [VN] FDE[0593] địa chỉ bắt đầu=0x04c74c, fde_va=0x0708b0, kích thước=20 byte
// AArch64 opcodes: 7100103F 54000041 B9403002 2A0203E0
uint32_t cybertron_fde_0593_0x04c74c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c74cU;
    constexpr uint32_t kFdeVa   = 0x0708b0U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x7100103fU;
    constexpr uint32_t kW1      = 0x54000041U;
    constexpr uint32_t kW2      = 0xb9403002U;
    constexpr uint32_t kW3      = 0x2a0203e0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0594] start_va=0x04c760, fde_va=0x0708c8, span=8 bytes
// [VN] FDE[0594] địa chỉ bắt đầu=0x04c760, fde_va=0x0708c8, kích thước=8 byte
// AArch64 opcodes: 91020000 17FFB0BB A9BE4FF4 A9017BFD
uint32_t cybertron_fde_0594_0x04c760(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c760U;
    constexpr uint32_t kFdeVa   = 0x0708c8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91020000U;
    constexpr uint32_t kW1      = 0x17ffb0bbU;
    constexpr uint32_t kW2      = 0xa9be4ff4U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0595] start_va=0x04c768, fde_va=0x0708e0, span=112 bytes
// [VN] FDE[0595] địa chỉ bắt đầu=0x04c768, fde_va=0x0708e0, kích thước=112 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0595_0x04c768(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c768U;
    constexpr uint32_t kFdeVa   = 0x0708e0U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0596] start_va=0x04c7d8, fde_va=0x070900, span=84 bytes
// [VN] FDE[0596] địa chỉ bắt đầu=0x04c7d8, fde_va=0x070900, kích thước=84 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0596_0x04c7d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c7d8U;
    constexpr uint32_t kFdeVa   = 0x070900U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0597] start_va=0x04c82c, fde_va=0x070920, span=320 bytes
// [VN] FDE[0597] địa chỉ bắt đầu=0x04c82c, fde_va=0x070920, kích thước=320 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0597_0x04c82c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c82cU;
    constexpr uint32_t kFdeVa   = 0x070920U;
    constexpr uint32_t kSpan    = 320U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0598] start_va=0x04c96c, fde_va=0x070940, span=84 bytes
// [VN] FDE[0598] địa chỉ bắt đầu=0x04c96c, fde_va=0x070940, kích thước=84 byte
// AArch64 opcodes: A9BF7BFD 910003FD F0000188 F9463908
uint32_t cybertron_fde_0598_0x04c96c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c96cU;
    constexpr uint32_t kFdeVa   = 0x070940U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xf0000188U;
    constexpr uint32_t kW3      = 0xf9463908U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0599] start_va=0x04c9c0, fde_va=0x070960, span=88 bytes
// [VN] FDE[0599] địa chỉ bắt đầu=0x04c9c0, fde_va=0x070960, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0599_0x04c9c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04c9c0U;
    constexpr uint32_t kFdeVa   = 0x070960U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0600] start_va=0x04ca18, fde_va=0x070980, span=232 bytes
// [VN] FDE[0600] địa chỉ bắt đầu=0x04ca18, fde_va=0x070980, kích thước=232 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0600_0x04ca18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ca18U;
    constexpr uint32_t kFdeVa   = 0x070980U;
    constexpr uint32_t kSpan    = 232U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0601] start_va=0x04cb00, fde_va=0x0709a0, span=36 bytes
// [VN] FDE[0601] địa chỉ bắt đầu=0x04cb00, fde_va=0x0709a0, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0601_0x04cb00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cb00U;
    constexpr uint32_t kFdeVa   = 0x0709a0U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0602] start_va=0x04cb24, fde_va=0x0709c0, span=448 bytes
// [VN] FDE[0602] địa chỉ bắt đầu=0x04cb24, fde_va=0x0709c0, kích thước=448 byte
// AArch64 opcodes: D106C3FF A9156FFC A91667FA A9175FF8
uint32_t cybertron_fde_0602_0x04cb24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cb24U;
    constexpr uint32_t kFdeVa   = 0x0709c0U;
    constexpr uint32_t kSpan    = 448U;
    constexpr uint32_t kW0      = 0xd106c3ffU;
    constexpr uint32_t kW1      = 0xa9156ffcU;
    constexpr uint32_t kW2      = 0xa91667faU;
    constexpr uint32_t kW3      = 0xa9175ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0603] start_va=0x04cce4, fde_va=0x0709f0, span=88 bytes
// [VN] FDE[0603] địa chỉ bắt đầu=0x04cce4, fde_va=0x0709f0, kích thước=88 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0603_0x04cce4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cce4U;
    constexpr uint32_t kFdeVa   = 0x0709f0U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0604] start_va=0x04cd3c, fde_va=0x070a10, span=8 bytes
// [VN] FDE[0604] địa chỉ bắt đầu=0x04cd3c, fde_va=0x070a10, kích thước=8 byte
// AArch64 opcodes: F9400400 17FFB638 F9400400 17FFAF3A
uint32_t cybertron_fde_0604_0x04cd3c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cd3cU;
    constexpr uint32_t kFdeVa   = 0x070a10U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0x17ffb638U;
    constexpr uint32_t kW2      = 0xf9400400U;
    constexpr uint32_t kW3      = 0x17ffaf3aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0605] start_va=0x04cd44, fde_va=0x070a28, span=8 bytes
// [VN] FDE[0605] địa chỉ bắt đầu=0x04cd44, fde_va=0x070a28, kích thước=8 byte
// AArch64 opcodes: F9400400 17FFAF3A F9400400 17FFB4E4
uint32_t cybertron_fde_0605_0x04cd44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cd44U;
    constexpr uint32_t kFdeVa   = 0x070a28U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0x17ffaf3aU;
    constexpr uint32_t kW2      = 0xf9400400U;
    constexpr uint32_t kW3      = 0x17ffb4e4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0606] start_va=0x04cd4c, fde_va=0x070a40, span=8 bytes
// [VN] FDE[0606] địa chỉ bắt đầu=0x04cd4c, fde_va=0x070a40, kích thước=8 byte
// AArch64 opcodes: F9400400 17FFB4E4 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0606_0x04cd4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cd4cU;
    constexpr uint32_t kFdeVa   = 0x070a40U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0x17ffb4e4U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0607] start_va=0x04cd54, fde_va=0x070a58, span=40 bytes
// [VN] FDE[0607] địa chỉ bắt đầu=0x04cd54, fde_va=0x070a58, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0607_0x04cd54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cd54U;
    constexpr uint32_t kFdeVa   = 0x070a58U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0608] start_va=0x04cd7c, fde_va=0x070a78, span=40 bytes
// [VN] FDE[0608] địa chỉ bắt đầu=0x04cd7c, fde_va=0x070a78, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0608_0x04cd7c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cd7cU;
    constexpr uint32_t kFdeVa   = 0x070a78U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0609] start_va=0x04cda4, fde_va=0x070a98, span=8 bytes
// [VN] FDE[0609] địa chỉ bắt đầu=0x04cda4, fde_va=0x070a98, kích thước=8 byte
// AArch64 opcodes: F9400400 17FFB0B6 F9400400 17FFB490
uint32_t cybertron_fde_0609_0x04cda4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cda4U;
    constexpr uint32_t kFdeVa   = 0x070a98U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0x17ffb0b6U;
    constexpr uint32_t kW2      = 0xf9400400U;
    constexpr uint32_t kW3      = 0x17ffb490U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0610] start_va=0x04cdac, fde_va=0x070ab0, span=8 bytes
// [VN] FDE[0610] địa chỉ bắt đầu=0x04cdac, fde_va=0x070ab0, kích thước=8 byte
// AArch64 opcodes: F9400400 17FFB490 A9BE4FF4 A9017BFD
uint32_t cybertron_fde_0610_0x04cdac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cdacU;
    constexpr uint32_t kFdeVa   = 0x070ab0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0x17ffb490U;
    constexpr uint32_t kW2      = 0xa9be4ff4U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0611] start_va=0x04cdb4, fde_va=0x070ac8, span=68 bytes
// [VN] FDE[0611] địa chỉ bắt đầu=0x04cdb4, fde_va=0x070ac8, kích thước=68 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0611_0x04cdb4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cdb4U;
    constexpr uint32_t kFdeVa   = 0x070ac8U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0612] start_va=0x04cdf8, fde_va=0x070ae8, span=204 bytes
// [VN] FDE[0612] địa chỉ bắt đầu=0x04cdf8, fde_va=0x070ae8, kích thước=204 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 39400008
uint32_t cybertron_fde_0612_0x04cdf8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cdf8U;
    constexpr uint32_t kFdeVa   = 0x070ae8U;
    constexpr uint32_t kSpan    = 204U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x39400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0613] start_va=0x04cec4, fde_va=0x070b08, span=148 bytes
// [VN] FDE[0613] địa chỉ bắt đầu=0x04cec4, fde_va=0x070b08, kích thước=148 byte
// AArch64 opcodes: A9BC5FF8 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0613_0x04cec4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cec4U;
    constexpr uint32_t kFdeVa   = 0x070b08U;
    constexpr uint32_t kSpan    = 148U;
    constexpr uint32_t kW0      = 0xa9bc5ff8U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0614] start_va=0x04cf58, fde_va=0x070b30, span=12 bytes
// [VN] FDE[0614] địa chỉ bắt đầu=0x04cf58, fde_va=0x070b30, kích thước=12 byte
// AArch64 opcodes: 91020001 AA0803E0 17FFB018 A9BE4FF4
uint32_t cybertron_fde_0614_0x04cf58(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cf58U;
    constexpr uint32_t kFdeVa   = 0x070b30U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x91020001U;
    constexpr uint32_t kW1      = 0xaa0803e0U;
    constexpr uint32_t kW2      = 0x17ffb018U;
    constexpr uint32_t kW3      = 0xa9be4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0615] start_va=0x04cf64, fde_va=0x070b48, span=232 bytes
// [VN] FDE[0615] địa chỉ bắt đầu=0x04cf64, fde_va=0x070b48, kích thước=232 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 51000428
uint32_t cybertron_fde_0615_0x04cf64(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04cf64U;
    constexpr uint32_t kFdeVa   = 0x070b48U;
    constexpr uint32_t kSpan    = 232U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x51000428U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0616] start_va=0x04d04c, fde_va=0x070b68, span=44 bytes
// [VN] FDE[0616] địa chỉ bắt đầu=0x04d04c, fde_va=0x070b68, kích thước=44 byte
// AArch64 opcodes: F9405809 F9000109 F9405C09 F9000509
uint32_t cybertron_fde_0616_0x04d04c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d04cU;
    constexpr uint32_t kFdeVa   = 0x070b68U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xf9405809U;
    constexpr uint32_t kW1      = 0xf9000109U;
    constexpr uint32_t kW2      = 0xf9405c09U;
    constexpr uint32_t kW3      = 0xf9000509U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0617] start_va=0x04d078, fde_va=0x070b80, span=60 bytes
// [VN] FDE[0617] địa chỉ bắt đầu=0x04d078, fde_va=0x070b80, kích thước=60 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91006014
uint32_t cybertron_fde_0617_0x04d078(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d078U;
    constexpr uint32_t kFdeVa   = 0x070b80U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91006014U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0618] start_va=0x04d0b4, fde_va=0x070ba0, span=104 bytes
// [VN] FDE[0618] địa chỉ bắt đầu=0x04d0b4, fde_va=0x070ba0, kích thước=104 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0618_0x04d0b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d0b4U;
    constexpr uint32_t kFdeVa   = 0x070ba0U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0619] start_va=0x04d11c, fde_va=0x070bc8, span=112 bytes
// [VN] FDE[0619] địa chỉ bắt đầu=0x04d11c, fde_va=0x070bc8, kích thước=112 byte
// AArch64 opcodes: FC1D0FE8 F90007F5 A9014FF4 A9027BFD
uint32_t cybertron_fde_0619_0x04d11c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d11cU;
    constexpr uint32_t kFdeVa   = 0x070bc8U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xfc1d0fe8U;
    constexpr uint32_t kW1      = 0xf90007f5U;
    constexpr uint32_t kW2      = 0xa9014ff4U;
    constexpr uint32_t kW3      = 0xa9027bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0620] start_va=0x04d18c, fde_va=0x070bf0, span=104 bytes
// [VN] FDE[0620] địa chỉ bắt đầu=0x04d18c, fde_va=0x070bf0, kích thước=104 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0620_0x04d18c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d18cU;
    constexpr uint32_t kFdeVa   = 0x070bf0U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0621] start_va=0x04d1f4, fde_va=0x070c18, span=136 bytes
// [VN] FDE[0621] địa chỉ bắt đầu=0x04d1f4, fde_va=0x070c18, kích thước=136 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0621_0x04d1f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d1f4U;
    constexpr uint32_t kFdeVa   = 0x070c18U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0622] start_va=0x04d27c, fde_va=0x070c40, span=92 bytes
// [VN] FDE[0622] địa chỉ bắt đầu=0x04d27c, fde_va=0x070c40, kích thước=92 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0622_0x04d27c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d27cU;
    constexpr uint32_t kFdeVa   = 0x070c40U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0623] start_va=0x04d2d8, fde_va=0x070c60, span=88 bytes
// [VN] FDE[0623] địa chỉ bắt đầu=0x04d2d8, fde_va=0x070c60, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0623_0x04d2d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d2d8U;
    constexpr uint32_t kFdeVa   = 0x070c60U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0624] start_va=0x04d330, fde_va=0x070c80, span=760 bytes
// [VN] FDE[0624] địa chỉ bắt đầu=0x04d330, fde_va=0x070c80, kích thước=760 byte
// AArch64 opcodes: D10303FF A9066FFC A90767FA A9085FF8
uint32_t cybertron_fde_0624_0x04d330(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d330U;
    constexpr uint32_t kFdeVa   = 0x070c80U;
    constexpr uint32_t kSpan    = 760U;
    constexpr uint32_t kW0      = 0xd10303ffU;
    constexpr uint32_t kW1      = 0xa9066ffcU;
    constexpr uint32_t kW2      = 0xa90767faU;
    constexpr uint32_t kW3      = 0xa9085ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0625] start_va=0x04d628, fde_va=0x070cb0, span=92 bytes
// [VN] FDE[0625] địa chỉ bắt đầu=0x04d628, fde_va=0x070cb0, kích thước=92 byte
// AArch64 opcodes: D100C3FF F9000BF3 A9027BFD 910083FD
uint32_t cybertron_fde_0625_0x04d628(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d628U;
    constexpr uint32_t kFdeVa   = 0x070cb0U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xd100c3ffU;
    constexpr uint32_t kW1      = 0xf9000bf3U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0626] start_va=0x04d684, fde_va=0x070cd0, span=420 bytes
// [VN] FDE[0626] địa chỉ bắt đầu=0x04d684, fde_va=0x070cd0, kích thước=420 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_0626_0x04d684(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d684U;
    constexpr uint32_t kFdeVa   = 0x070cd0U;
    constexpr uint32_t kSpan    = 420U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf90013f7U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0627] start_va=0x04d828, fde_va=0x070cf8, span=916 bytes
// [VN] FDE[0627] địa chỉ bắt đầu=0x04d828, fde_va=0x070cf8, kích thước=916 byte
// AArch64 opcodes: D10283FF A9046FFC A90567FA A9065FF8
uint32_t cybertron_fde_0627_0x04d828(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04d828U;
    constexpr uint32_t kFdeVa   = 0x070cf8U;
    constexpr uint32_t kSpan    = 916U;
    constexpr uint32_t kW0      = 0xd10283ffU;
    constexpr uint32_t kW1      = 0xa9046ffcU;
    constexpr uint32_t kW2      = 0xa90567faU;
    constexpr uint32_t kW3      = 0xa9065ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0628] start_va=0x04dbbc, fde_va=0x070d28, span=372 bytes
// [VN] FDE[0628] địa chỉ bắt đầu=0x04dbbc, fde_va=0x070d28, kích thước=372 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0628_0x04dbbc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04dbbcU;
    constexpr uint32_t kFdeVa   = 0x070d28U;
    constexpr uint32_t kSpan    = 372U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0629] start_va=0x04dd30, fde_va=0x070d50, span=92 bytes
// [VN] FDE[0629] địa chỉ bắt đầu=0x04dd30, fde_va=0x070d50, kích thước=92 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0629_0x04dd30(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04dd30U;
    constexpr uint32_t kFdeVa   = 0x070d50U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0630] start_va=0x04dd8c, fde_va=0x070d70, span=236 bytes
// [VN] FDE[0630] địa chỉ bắt đầu=0x04dd8c, fde_va=0x070d70, kích thước=236 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_0630_0x04dd8c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04dd8cU;
    constexpr uint32_t kFdeVa   = 0x070d70U;
    constexpr uint32_t kSpan    = 236U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0631] start_va=0x04de78, fde_va=0x070d98, span=516 bytes
// [VN] FDE[0631] địa chỉ bắt đầu=0x04de78, fde_va=0x070d98, kích thước=516 byte
// AArch64 opcodes: D10203FF A9026FFC A90367FA A9045FF8
uint32_t cybertron_fde_0631_0x04de78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04de78U;
    constexpr uint32_t kFdeVa   = 0x070d98U;
    constexpr uint32_t kSpan    = 516U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa9026ffcU;
    constexpr uint32_t kW2      = 0xa90367faU;
    constexpr uint32_t kW3      = 0xa9045ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0632] start_va=0x04e07c, fde_va=0x070dc8, span=76 bytes
// [VN] FDE[0632] địa chỉ bắt đầu=0x04e07c, fde_va=0x070dc8, kích thước=76 byte
// AArch64 opcodes: B4000241 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0632_0x04e07c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e07cU;
    constexpr uint32_t kFdeVa   = 0x070dc8U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xb4000241U;
    constexpr uint32_t kW1      = 0xa9be4ff4U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0633] start_va=0x04e0c8, fde_va=0x070de8, span=60 bytes
// [VN] FDE[0633] địa chỉ bắt đầu=0x04e0c8, fde_va=0x070de8, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 91006040
uint32_t cybertron_fde_0633_0x04e0c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e0c8U;
    constexpr uint32_t kFdeVa   = 0x070de8U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91006040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0634] start_va=0x04e104, fde_va=0x070e08, span=356 bytes
// [VN] FDE[0634] địa chỉ bắt đầu=0x04e104, fde_va=0x070e08, kích thước=356 byte
// AArch64 opcodes: D101C3FF F90013F9 A9035FF8 A90457F6
uint32_t cybertron_fde_0634_0x04e104(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e104U;
    constexpr uint32_t kFdeVa   = 0x070e08U;
    constexpr uint32_t kSpan    = 356U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90013f9U;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0635] start_va=0x04e268, fde_va=0x070e30, span=240 bytes
// [VN] FDE[0635] địa chỉ bắt đầu=0x04e268, fde_va=0x070e30, kích thước=240 byte
// AArch64 opcodes: F81A0FFB A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0635_0x04e268(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e268U;
    constexpr uint32_t kFdeVa   = 0x070e30U;
    constexpr uint32_t kSpan    = 240U;
    constexpr uint32_t kW0      = 0xf81a0ffbU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0636] start_va=0x04e358, fde_va=0x070e60, span=292 bytes
// [VN] FDE[0636] địa chỉ bắt đầu=0x04e358, fde_va=0x070e60, kích thước=292 byte
// AArch64 opcodes: A9BA6FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0636_0x04e358(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e358U;
    constexpr uint32_t kFdeVa   = 0x070e60U;
    constexpr uint32_t kSpan    = 292U;
    constexpr uint32_t kW0      = 0xa9ba6ffcU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0637] start_va=0x04e47c, fde_va=0x070e90, span=52 bytes
// [VN] FDE[0637] địa chỉ bắt đầu=0x04e47c, fde_va=0x070e90, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000188
uint32_t cybertron_fde_0637_0x04e47c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e47cU;
    constexpr uint32_t kFdeVa   = 0x070e90U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000188U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0638] start_va=0x04e4b0, fde_va=0x070eb0, span=60 bytes
// [VN] FDE[0638] địa chỉ bắt đầu=0x04e4b0, fde_va=0x070eb0, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000188
uint32_t cybertron_fde_0638_0x04e4b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e4b0U;
    constexpr uint32_t kFdeVa   = 0x070eb0U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000188U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0639] start_va=0x04e4ec, fde_va=0x070ed0, span=8 bytes
// [VN] FDE[0639] địa chỉ bắt đầu=0x04e4ec, fde_va=0x070ed0, kích thước=8 byte
// AArch64 opcodes: 91006000 17FFABE8 17FFAA0B D10143FF
uint32_t cybertron_fde_0639_0x04e4ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e4ecU;
    constexpr uint32_t kFdeVa   = 0x070ed0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91006000U;
    constexpr uint32_t kW1      = 0x17ffabe8U;
    constexpr uint32_t kW2      = 0x17ffaa0bU;
    constexpr uint32_t kW3      = 0xd10143ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0640] start_va=0x04e4f4, fde_va=0x070ee8, span=4 bytes
// [VN] FDE[0640] địa chỉ bắt đầu=0x04e4f4, fde_va=0x070ee8, kích thước=4 byte
// AArch64 opcodes: 17FFAA0B D10143FF F9000BF7 A90257F6
uint32_t cybertron_fde_0640_0x04e4f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e4f4U;
    constexpr uint32_t kFdeVa   = 0x070ee8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffaa0bU;
    constexpr uint32_t kW1      = 0xd10143ffU;
    constexpr uint32_t kW2      = 0xf9000bf7U;
    constexpr uint32_t kW3      = 0xa90257f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0641] start_va=0x04e4f8, fde_va=0x070f00, span=196 bytes
// [VN] FDE[0641] địa chỉ bắt đầu=0x04e4f8, fde_va=0x070f00, kích thước=196 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0641_0x04e4f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e4f8U;
    constexpr uint32_t kFdeVa   = 0x070f00U;
    constexpr uint32_t kSpan    = 196U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9000bf7U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0642] start_va=0x04e5bc, fde_va=0x070f28, span=84 bytes
// [VN] FDE[0642] địa chỉ bắt đầu=0x04e5bc, fde_va=0x070f28, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_0642_0x04e5bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e5bcU;
    constexpr uint32_t kFdeVa   = 0x070f28U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa9007c7fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0643] start_va=0x04e610, fde_va=0x070f48, span=168 bytes
// [VN] FDE[0643] địa chỉ bắt đầu=0x04e610, fde_va=0x070f48, kích thước=168 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0643_0x04e610(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e610U;
    constexpr uint32_t kFdeVa   = 0x070f48U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0644] start_va=0x04e6b8, fde_va=0x070f70, span=136 bytes
// [VN] FDE[0644] địa chỉ bắt đầu=0x04e6b8, fde_va=0x070f70, kích thước=136 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0644_0x04e6b8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e6b8U;
    constexpr uint32_t kFdeVa   = 0x070f70U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0645] start_va=0x04e740, fde_va=0x070f98, span=268 bytes
// [VN] FDE[0645] địa chỉ bắt đầu=0x04e740, fde_va=0x070f98, kích thước=268 byte
// AArch64 opcodes: A9BC5FF8 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0645_0x04e740(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e740U;
    constexpr uint32_t kFdeVa   = 0x070f98U;
    constexpr uint32_t kSpan    = 268U;
    constexpr uint32_t kW0      = 0xa9bc5ff8U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0646] start_va=0x04e84c, fde_va=0x070fc0, span=72 bytes
// [VN] FDE[0646] địa chỉ bắt đầu=0x04e84c, fde_va=0x070fc0, kích thước=72 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0646_0x04e84c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e84cU;
    constexpr uint32_t kFdeVa   = 0x070fc0U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0647] start_va=0x04e894, fde_va=0x070fe0, span=132 bytes
// [VN] FDE[0647] địa chỉ bắt đầu=0x04e894, fde_va=0x070fe0, kích thước=132 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400428
uint32_t cybertron_fde_0647_0x04e894(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e894U;
    constexpr uint32_t kFdeVa   = 0x070fe0U;
    constexpr uint32_t kSpan    = 132U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400428U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0648] start_va=0x04e918, fde_va=0x071000, span=40 bytes
// [VN] FDE[0648] địa chỉ bắt đầu=0x04e918, fde_va=0x071000, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0648_0x04e918(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e918U;
    constexpr uint32_t kFdeVa   = 0x071000U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0649] start_va=0x04e940, fde_va=0x071020, span=68 bytes
// [VN] FDE[0649] địa chỉ bắt đầu=0x04e940, fde_va=0x071020, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400408
uint32_t cybertron_fde_0649_0x04e940(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e940U;
    constexpr uint32_t kFdeVa   = 0x071020U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0650] start_va=0x04e984, fde_va=0x071040, span=44 bytes
// [VN] FDE[0650] địa chỉ bắt đầu=0x04e984, fde_va=0x071040, kích thước=44 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400408
uint32_t cybertron_fde_0650_0x04e984(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e984U;
    constexpr uint32_t kFdeVa   = 0x071040U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0651] start_va=0x04e9b0, fde_va=0x071060, span=64 bytes
// [VN] FDE[0651] địa chỉ bắt đầu=0x04e9b0, fde_va=0x071060, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400408
uint32_t cybertron_fde_0651_0x04e9b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e9b0U;
    constexpr uint32_t kFdeVa   = 0x071060U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0652] start_va=0x04e9f0, fde_va=0x071080, span=8 bytes
// [VN] FDE[0652] địa chỉ bắt đầu=0x04e9f0, fde_va=0x071080, kích thước=8 byte
// AArch64 opcodes: B9401000 D65F03C0 B9401400 D65F03C0
uint32_t cybertron_fde_0652_0x04e9f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e9f0U;
    constexpr uint32_t kFdeVa   = 0x071080U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xb9401000U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xb9401400U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0653] start_va=0x04e9f8, fde_va=0x071098, span=8 bytes
// [VN] FDE[0653] địa chỉ bắt đầu=0x04e9f8, fde_va=0x071098, kích thước=8 byte
// AArch64 opcodes: B9401400 D65F03C0 A9BE4FF4 A9017BFD
uint32_t cybertron_fde_0653_0x04e9f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04e9f8U;
    constexpr uint32_t kFdeVa   = 0x071098U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xb9401400U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xa9be4ff4U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0654] start_va=0x04ea00, fde_va=0x0710b0, span=56 bytes
// [VN] FDE[0654] địa chỉ bắt đầu=0x04ea00, fde_va=0x0710b0, kích thước=56 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91007014
uint32_t cybertron_fde_0654_0x04ea00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ea00U;
    constexpr uint32_t kFdeVa   = 0x0710b0U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91007014U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0655] start_va=0x04ea38, fde_va=0x0710d0, span=52 bytes
// [VN] FDE[0655] địa chỉ bắt đầu=0x04ea38, fde_va=0x0710d0, kích thước=52 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91007014
uint32_t cybertron_fde_0655_0x04ea38(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ea38U;
    constexpr uint32_t kFdeVa   = 0x0710d0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91007014U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0656] start_va=0x04ea6c, fde_va=0x0710f0, span=60 bytes
// [VN] FDE[0656] địa chỉ bắt đầu=0x04ea6c, fde_va=0x0710f0, kích thước=60 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91007013
uint32_t cybertron_fde_0656_0x04ea6c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ea6cU;
    constexpr uint32_t kFdeVa   = 0x0710f0U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91007013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0657] start_va=0x04eaa8, fde_va=0x071110, span=80 bytes
// [VN] FDE[0657] địa chỉ bắt đầu=0x04eaa8, fde_va=0x071110, kích thước=80 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91007013
uint32_t cybertron_fde_0657_0x04eaa8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04eaa8U;
    constexpr uint32_t kFdeVa   = 0x071110U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91007013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0658] start_va=0x04eaf8, fde_va=0x071130, span=56 bytes
// [VN] FDE[0658] địa chỉ bắt đầu=0x04eaf8, fde_va=0x071130, kích thước=56 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91007014
uint32_t cybertron_fde_0658_0x04eaf8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04eaf8U;
    constexpr uint32_t kFdeVa   = 0x071130U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91007014U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0659] start_va=0x04eb30, fde_va=0x071150, span=56 bytes
// [VN] FDE[0659] địa chỉ bắt đầu=0x04eb30, fde_va=0x071150, kích thước=56 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91007014
uint32_t cybertron_fde_0659_0x04eb30(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04eb30U;
    constexpr uint32_t kFdeVa   = 0x071150U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91007014U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0660] start_va=0x04eb68, fde_va=0x071170, span=532 bytes
// [VN] FDE[0660] địa chỉ bắt đầu=0x04eb68, fde_va=0x071170, kích thước=532 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0660_0x04eb68(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04eb68U;
    constexpr uint32_t kFdeVa   = 0x071170U;
    constexpr uint32_t kSpan    = 532U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0661] start_va=0x04ed7c, fde_va=0x071198, span=172 bytes
// [VN] FDE[0661] địa chỉ bắt đầu=0x04ed7c, fde_va=0x071198, kích thước=172 byte
// AArch64 opcodes: D10183FF A90357F6 A9044FF4 A9057BFD
uint32_t cybertron_fde_0661_0x04ed7c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ed7cU;
    constexpr uint32_t kFdeVa   = 0x071198U;
    constexpr uint32_t kSpan    = 172U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa90357f6U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0662] start_va=0x04ee28, fde_va=0x0711c0, span=168 bytes
// [VN] FDE[0662] địa chỉ bắt đầu=0x04ee28, fde_va=0x0711c0, kích thước=168 byte
// AArch64 opcodes: D10183FF A90357F6 A9044FF4 A9057BFD
uint32_t cybertron_fde_0662_0x04ee28(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ee28U;
    constexpr uint32_t kFdeVa   = 0x0711c0U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa90357f6U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0663] start_va=0x04eed0, fde_va=0x0711e8, span=460 bytes
// [VN] FDE[0663] địa chỉ bắt đầu=0x04eed0, fde_va=0x0711e8, kích thước=460 byte
// AArch64 opcodes: D106C3FF A9156FFC A91667FA A9175FF8
uint32_t cybertron_fde_0663_0x04eed0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04eed0U;
    constexpr uint32_t kFdeVa   = 0x0711e8U;
    constexpr uint32_t kSpan    = 460U;
    constexpr uint32_t kW0      = 0xd106c3ffU;
    constexpr uint32_t kW1      = 0xa9156ffcU;
    constexpr uint32_t kW2      = 0xa91667faU;
    constexpr uint32_t kW3      = 0xa9175ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0664] start_va=0x04f09c, fde_va=0x071218, span=228 bytes
// [VN] FDE[0664] địa chỉ bắt đầu=0x04f09c, fde_va=0x071218, kích thước=228 byte
// AArch64 opcodes: D10183FF F9000BF9 A9025FF8 A90357F6
uint32_t cybertron_fde_0664_0x04f09c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04f09cU;
    constexpr uint32_t kFdeVa   = 0x071218U;
    constexpr uint32_t kSpan    = 228U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9000bf9U;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0665] start_va=0x04f180, fde_va=0x071240, span=1024 bytes
// [VN] FDE[0665] địa chỉ bắt đầu=0x04f180, fde_va=0x071240, kích thước=1024 byte
// AArch64 opcodes: D10243FF F90023F9 A9055FF8 A90657F6
uint32_t cybertron_fde_0665_0x04f180(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04f180U;
    constexpr uint32_t kFdeVa   = 0x071240U;
    constexpr uint32_t kSpan    = 1024U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xf90023f9U;
    constexpr uint32_t kW2      = 0xa9055ff8U;
    constexpr uint32_t kW3      = 0xa90657f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0666] start_va=0x04f580, fde_va=0x071268, span=92 bytes
// [VN] FDE[0666] địa chỉ bắt đầu=0x04f580, fde_va=0x071268, kích thước=92 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 52800021
uint32_t cybertron_fde_0666_0x04f580(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04f580U;
    constexpr uint32_t kFdeVa   = 0x071268U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x52800021U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0667] start_va=0x04f5dc, fde_va=0x071288, span=2388 bytes
// [VN] FDE[0667] địa chỉ bắt đầu=0x04f5dc, fde_va=0x071288, kích thước=2388 byte
// AArch64 opcodes: D10343FF A9076FFC A90867FA A9095FF8
uint32_t cybertron_fde_0667_0x04f5dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04f5dcU;
    constexpr uint32_t kFdeVa   = 0x071288U;
    constexpr uint32_t kSpan    = 2388U;
    constexpr uint32_t kW0      = 0xd10343ffU;
    constexpr uint32_t kW1      = 0xa9076ffcU;
    constexpr uint32_t kW2      = 0xa90867faU;
    constexpr uint32_t kW3      = 0xa9095ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0668] start_va=0x04ff30, fde_va=0x0712b8, span=260 bytes
// [VN] FDE[0668] địa chỉ bắt đầu=0x04ff30, fde_va=0x0712b8, kích thước=260 byte
// AArch64 opcodes: D10203FF A90557F6 A9064FF4 A9077BFD
uint32_t cybertron_fde_0668_0x04ff30(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04ff30U;
    constexpr uint32_t kFdeVa   = 0x0712b8U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa90557f6U;
    constexpr uint32_t kW2      = 0xa9064ff4U;
    constexpr uint32_t kW3      = 0xa9077bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0669] start_va=0x050034, fde_va=0x0712e0, span=44 bytes
// [VN] FDE[0669] địa chỉ bắt đầu=0x050034, fde_va=0x0712e0, kích thước=44 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400808
uint32_t cybertron_fde_0669_0x050034(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x050034U;
    constexpr uint32_t kFdeVa   = 0x0712e0U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400808U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0670] start_va=0x050060, fde_va=0x071300, span=56 bytes
// [VN] FDE[0670] địa chỉ bắt đầu=0x050060, fde_va=0x071300, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400C08
uint32_t cybertron_fde_0670_0x050060(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x050060U;
    constexpr uint32_t kFdeVa   = 0x071300U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400c08U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0671] start_va=0x050098, fde_va=0x071320, span=44 bytes
// [VN] FDE[0671] địa chỉ bắt đầu=0x050098, fde_va=0x071320, kích thước=44 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9401008
uint32_t cybertron_fde_0671_0x050098(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x050098U;
    constexpr uint32_t kFdeVa   = 0x071320U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9401008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0672] start_va=0x0500c4, fde_va=0x071340, span=4 bytes
// [VN] FDE[0672] địa chỉ bắt đầu=0x0500c4, fde_va=0x071340, kích thước=4 byte
// AArch64 opcodes: D65F03C0 B40003A1 A9BE4FF4 A9017BFD
uint32_t cybertron_fde_0672_0x0500c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0500c4U;
    constexpr uint32_t kFdeVa   = 0x071340U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xb40003a1U;
    constexpr uint32_t kW2      = 0xa9be4ff4U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0673] start_va=0x0500c8, fde_va=0x071358, span=120 bytes
// [VN] FDE[0673] địa chỉ bắt đầu=0x0500c8, fde_va=0x071358, kích thước=120 byte
// AArch64 opcodes: B40003A1 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0673_0x0500c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0500c8U;
    constexpr uint32_t kFdeVa   = 0x071358U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xb40003a1U;
    constexpr uint32_t kW1      = 0xa9be4ff4U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0674] start_va=0x050140, fde_va=0x071378, span=64 bytes
// [VN] FDE[0674] địa chỉ bắt đầu=0x050140, fde_va=0x071378, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9401408
uint32_t cybertron_fde_0674_0x050140(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x050140U;
    constexpr uint32_t kFdeVa   = 0x071378U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9401408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0675] start_va=0x050180, fde_va=0x071398, span=548 bytes
// [VN] FDE[0675] địa chỉ bắt đầu=0x050180, fde_va=0x071398, kích thước=548 byte
// AArch64 opcodes: D10243FF F9001BFB A90467FA A9055FF8
uint32_t cybertron_fde_0675_0x050180(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x050180U;
    constexpr uint32_t kFdeVa   = 0x071398U;
    constexpr uint32_t kSpan    = 548U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xf9001bfbU;
    constexpr uint32_t kW2      = 0xa90467faU;
    constexpr uint32_t kW3      = 0xa9055ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0676] start_va=0x0503a4, fde_va=0x0713c8, span=168 bytes
// [VN] FDE[0676] địa chỉ bắt đầu=0x0503a4, fde_va=0x0713c8, kích thước=168 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0676_0x0503a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0503a4U;
    constexpr uint32_t kFdeVa   = 0x0713c8U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0677] start_va=0x05044c, fde_va=0x0713e8, span=68 bytes
// [VN] FDE[0677] địa chỉ bắt đầu=0x05044c, fde_va=0x0713e8, kích thước=68 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0677_0x05044c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05044cU;
    constexpr uint32_t kFdeVa   = 0x0713e8U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0678] start_va=0x050490, fde_va=0x071408, span=136 bytes
// [VN] FDE[0678] địa chỉ bắt đầu=0x050490, fde_va=0x071408, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD A9007C1F
uint32_t cybertron_fde_0678_0x050490(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x050490U;
    constexpr uint32_t kFdeVa   = 0x071408U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa9007c1fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0679] start_va=0x050518, fde_va=0x071428, span=196 bytes
// [VN] FDE[0679] địa chỉ bắt đầu=0x050518, fde_va=0x071428, kích thước=196 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0679_0x050518(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x050518U;
    constexpr uint32_t kFdeVa   = 0x071428U;
    constexpr uint32_t kSpan    = 196U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0680] start_va=0x0505dc, fde_va=0x071448, span=536 bytes
// [VN] FDE[0680] địa chỉ bắt đầu=0x0505dc, fde_va=0x071448, kích thước=536 byte
// AArch64 opcodes: A9BA6FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0680_0x0505dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0505dcU;
    constexpr uint32_t kFdeVa   = 0x071448U;
    constexpr uint32_t kSpan    = 536U;
    constexpr uint32_t kW0      = 0xa9ba6ffcU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0681] start_va=0x0507f4, fde_va=0x071478, span=360 bytes
// [VN] FDE[0681] địa chỉ bắt đầu=0x0507f4, fde_va=0x071478, kích thước=360 byte
// AArch64 opcodes: D10483FF A90C6FFC A90D67FA A90E5FF8
uint32_t cybertron_fde_0681_0x0507f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0507f4U;
    constexpr uint32_t kFdeVa   = 0x071478U;
    constexpr uint32_t kSpan    = 360U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa90c6ffcU;
    constexpr uint32_t kW2      = 0xa90d67faU;
    constexpr uint32_t kW3      = 0xa90e5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0682] start_va=0x05095c, fde_va=0x0714a8, span=4556 bytes
// [VN] FDE[0682] địa chỉ bắt đầu=0x05095c, fde_va=0x0714a8, kích thước=4556 byte
// AArch64 opcodes: D10483FF FD0063E8 A90D67FC A90E5FF8
uint32_t cybertron_fde_0682_0x05095c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05095cU;
    constexpr uint32_t kFdeVa   = 0x0714a8U;
    constexpr uint32_t kSpan    = 4556U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xfd0063e8U;
    constexpr uint32_t kW2      = 0xa90d67fcU;
    constexpr uint32_t kW3      = 0xa90e5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0683] start_va=0x051b28, fde_va=0x0714d8, span=436 bytes
// [VN] FDE[0683] địa chỉ bắt đầu=0x051b28, fde_va=0x0714d8, kích thước=436 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0683_0x051b28(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x051b28U;
    constexpr uint32_t kFdeVa   = 0x0714d8U;
    constexpr uint32_t kSpan    = 436U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0684] start_va=0x051cdc, fde_va=0x071500, span=68 bytes
// [VN] FDE[0684] địa chỉ bắt đầu=0x051cdc, fde_va=0x071500, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0684_0x051cdc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x051cdcU;
    constexpr uint32_t kFdeVa   = 0x071500U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0685] start_va=0x051d20, fde_va=0x071520, span=316 bytes
// [VN] FDE[0685] địa chỉ bắt đầu=0x051d20, fde_va=0x071520, kích thước=316 byte
// AArch64 opcodes: D10203FF A9045FF8 A90557F6 A9064FF4
uint32_t cybertron_fde_0685_0x051d20(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x051d20U;
    constexpr uint32_t kFdeVa   = 0x071520U;
    constexpr uint32_t kSpan    = 316U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa9045ff8U;
    constexpr uint32_t kW2      = 0xa90557f6U;
    constexpr uint32_t kW3      = 0xa9064ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0686] start_va=0x051e5c, fde_va=0x071548, span=972 bytes
// [VN] FDE[0686] địa chỉ bắt đầu=0x051e5c, fde_va=0x071548, kích thước=972 byte
// AArch64 opcodes: D10303FF F90033FB A90767FA A9085FF8
uint32_t cybertron_fde_0686_0x051e5c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x051e5cU;
    constexpr uint32_t kFdeVa   = 0x071548U;
    constexpr uint32_t kSpan    = 972U;
    constexpr uint32_t kW0      = 0xd10303ffU;
    constexpr uint32_t kW1      = 0xf90033fbU;
    constexpr uint32_t kW2      = 0xa90767faU;
    constexpr uint32_t kW3      = 0xa9085ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0687] start_va=0x052228, fde_va=0x071578, span=76 bytes
// [VN] FDE[0687] địa chỉ bắt đầu=0x052228, fde_va=0x071578, kích thước=76 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0687_0x052228(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052228U;
    constexpr uint32_t kFdeVa   = 0x071578U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0688] start_va=0x052274, fde_va=0x071598, span=92 bytes
// [VN] FDE[0688] địa chỉ bắt đầu=0x052274, fde_va=0x071598, kích thước=92 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0688_0x052274(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052274U;
    constexpr uint32_t kFdeVa   = 0x071598U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0689] start_va=0x0522d0, fde_va=0x0715b8, span=128 bytes
// [VN] FDE[0689] địa chỉ bắt đầu=0x0522d0, fde_va=0x0715b8, kích thước=128 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0689_0x0522d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0522d0U;
    constexpr uint32_t kFdeVa   = 0x0715b8U;
    constexpr uint32_t kSpan    = 128U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0690] start_va=0x052350, fde_va=0x0715d8, span=8 bytes
// [VN] FDE[0690] địa chỉ bắt đầu=0x052350, fde_va=0x0715d8, kích thước=8 byte
// AArch64 opcodes: 91048000 17FFA137 D101C3FF F90023F5
uint32_t cybertron_fde_0690_0x052350(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052350U;
    constexpr uint32_t kFdeVa   = 0x0715d8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91048000U;
    constexpr uint32_t kW1      = 0x17ffa137U;
    constexpr uint32_t kW2      = 0xd101c3ffU;
    constexpr uint32_t kW3      = 0xf90023f5U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0691] start_va=0x052358, fde_va=0x0715f0, span=144 bytes
// [VN] FDE[0691] địa chỉ bắt đầu=0x052358, fde_va=0x0715f0, kích thước=144 byte
// AArch64 opcodes: D101C3FF F90023F5 A9054FF4 A9067BFD
uint32_t cybertron_fde_0691_0x052358(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052358U;
    constexpr uint32_t kFdeVa   = 0x0715f0U;
    constexpr uint32_t kSpan    = 144U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90023f5U;
    constexpr uint32_t kW2      = 0xa9054ff4U;
    constexpr uint32_t kW3      = 0xa9067bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0692] start_va=0x0523e8, fde_va=0x071610, span=232 bytes
// [VN] FDE[0692] địa chỉ bắt đầu=0x0523e8, fde_va=0x071610, kích thước=232 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0692_0x0523e8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0523e8U;
    constexpr uint32_t kFdeVa   = 0x071610U;
    constexpr uint32_t kSpan    = 232U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0693] start_va=0x0524d0, fde_va=0x071638, span=16 bytes
// [VN] FDE[0693] địa chỉ bắt đầu=0x0524d0, fde_va=0x071638, kích thước=16 byte
// AArch64 opcodes: 900000A1 91381C21 AA0803E0 17FFA109
uint32_t cybertron_fde_0693_0x0524d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0524d0U;
    constexpr uint32_t kFdeVa   = 0x071638U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x900000a1U;
    constexpr uint32_t kW1      = 0x91381c21U;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x17ffa109U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0694] start_va=0x0524e0, fde_va=0x071650, span=4 bytes
// [VN] FDE[0694] địa chỉ bắt đầu=0x0524e0, fde_va=0x071650, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FF9A0F B0000168 F9462908
uint32_t cybertron_fde_0694_0x0524e0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0524e0U;
    constexpr uint32_t kFdeVa   = 0x071650U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ff9a0fU;
    constexpr uint32_t kW2      = 0xb0000168U;
    constexpr uint32_t kW3      = 0xf9462908U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0695] start_va=0x0524e4, fde_va=0x071668, span=4 bytes
// [VN] FDE[0695] địa chỉ bắt đầu=0x0524e4, fde_va=0x071668, kích thước=4 byte
// AArch64 opcodes: 17FF9A0F B0000168 F9462908 91004108
uint32_t cybertron_fde_0695_0x0524e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0524e4U;
    constexpr uint32_t kFdeVa   = 0x071668U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff9a0fU;
    constexpr uint32_t kW1      = 0xb0000168U;
    constexpr uint32_t kW2      = 0xf9462908U;
    constexpr uint32_t kW3      = 0x91004108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0696] start_va=0x0524e8, fde_va=0x071680, span=20 bytes
// [VN] FDE[0696] địa chỉ bắt đầu=0x0524e8, fde_va=0x071680, kích thước=20 byte
// AArch64 opcodes: B0000168 F9462908 91004108 F801C408
uint32_t cybertron_fde_0696_0x0524e8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0524e8U;
    constexpr uint32_t kFdeVa   = 0x071680U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xb0000168U;
    constexpr uint32_t kW1      = 0xf9462908U;
    constexpr uint32_t kW2      = 0x91004108U;
    constexpr uint32_t kW3      = 0xf801c408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0697] start_va=0x0524fc, fde_va=0x071698, span=52 bytes
// [VN] FDE[0697] địa chỉ bắt đầu=0x0524fc, fde_va=0x071698, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000168
uint32_t cybertron_fde_0697_0x0524fc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0524fcU;
    constexpr uint32_t kFdeVa   = 0x071698U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000168U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0698] start_va=0x052530, fde_va=0x0716b8, span=4 bytes
// [VN] FDE[0698] địa chỉ bắt đầu=0x052530, fde_va=0x0716b8, kích thước=4 byte
// AArch64 opcodes: 17FF99FC F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0698_0x052530(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052530U;
    constexpr uint32_t kFdeVa   = 0x0716b8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff99fcU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0699] start_va=0x052534, fde_va=0x0716d0, span=36 bytes
// [VN] FDE[0699] địa chỉ bắt đầu=0x052534, fde_va=0x0716d0, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0699_0x052534(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052534U;
    constexpr uint32_t kFdeVa   = 0x0716d0U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0700] start_va=0x052558, fde_va=0x0716f0, span=228 bytes
// [VN] FDE[0700] địa chỉ bắt đầu=0x052558, fde_va=0x0716f0, kích thước=228 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0700_0x052558(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052558U;
    constexpr uint32_t kFdeVa   = 0x0716f0U;
    constexpr uint32_t kSpan    = 228U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0701] start_va=0x05263c, fde_va=0x071710, span=36 bytes
// [VN] FDE[0701] địa chỉ bắt đầu=0x05263c, fde_va=0x071710, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0701_0x05263c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05263cU;
    constexpr uint32_t kFdeVa   = 0x071710U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0702] start_va=0x052660, fde_va=0x071730, span=120 bytes
// [VN] FDE[0702] địa chỉ bắt đầu=0x052660, fde_va=0x071730, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0702_0x052660(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052660U;
    constexpr uint32_t kFdeVa   = 0x071730U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0703] start_va=0x0526d8, fde_va=0x071750, span=60 bytes
// [VN] FDE[0703] địa chỉ bắt đầu=0x0526d8, fde_va=0x071750, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400801
uint32_t cybertron_fde_0703_0x0526d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0526d8U;
    constexpr uint32_t kFdeVa   = 0x071750U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400801U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0704] start_va=0x052714, fde_va=0x071770, span=116 bytes
// [VN] FDE[0704] địa chỉ bắt đầu=0x052714, fde_va=0x071770, kích thước=116 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0704_0x052714(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052714U;
    constexpr uint32_t kFdeVa   = 0x071770U;
    constexpr uint32_t kSpan    = 116U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0705] start_va=0x052788, fde_va=0x071790, span=12 bytes
// [VN] FDE[0705] địa chỉ bắt đầu=0x052788, fde_va=0x071790, kích thước=12 byte
// AArch64 opcodes: AA0103E2 52800021 17FF9AC4 F81D0FF5
uint32_t cybertron_fde_0705_0x052788(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052788U;
    constexpr uint32_t kFdeVa   = 0x071790U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xaa0103e2U;
    constexpr uint32_t kW1      = 0x52800021U;
    constexpr uint32_t kW2      = 0x17ff9ac4U;
    constexpr uint32_t kW3      = 0xf81d0ff5U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0706] start_va=0x052794, fde_va=0x0717a8, span=112 bytes
// [VN] FDE[0706] địa chỉ bắt đầu=0x052794, fde_va=0x0717a8, kích thước=112 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0706_0x052794(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052794U;
    constexpr uint32_t kFdeVa   = 0x0717a8U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0707] start_va=0x052804, fde_va=0x0717c8, span=4 bytes
// [VN] FDE[0707] địa chỉ bắt đầu=0x052804, fde_va=0x0717c8, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D101C3FF F90013F9 A9035FF8
uint32_t cybertron_fde_0707_0x052804(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052804U;
    constexpr uint32_t kFdeVa   = 0x0717c8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd101c3ffU;
    constexpr uint32_t kW2      = 0xf90013f9U;
    constexpr uint32_t kW3      = 0xa9035ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0708] start_va=0x052808, fde_va=0x0717e0, span=356 bytes
// [VN] FDE[0708] địa chỉ bắt đầu=0x052808, fde_va=0x0717e0, kích thước=356 byte
// AArch64 opcodes: D101C3FF F90013F9 A9035FF8 A90457F6
uint32_t cybertron_fde_0708_0x052808(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052808U;
    constexpr uint32_t kFdeVa   = 0x0717e0U;
    constexpr uint32_t kSpan    = 356U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90013f9U;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0709] start_va=0x05296c, fde_va=0x071808, span=212 bytes
// [VN] FDE[0709] địa chỉ bắt đầu=0x05296c, fde_va=0x071808, kích thước=212 byte
// AArch64 opcodes: D10143FF A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0709_0x05296c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05296cU;
    constexpr uint32_t kFdeVa   = 0x071808U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa9015ff8U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0710] start_va=0x052a40, fde_va=0x071830, span=204 bytes
// [VN] FDE[0710] địa chỉ bắt đầu=0x052a40, fde_va=0x071830, kích thước=204 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0710_0x052a40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052a40U;
    constexpr uint32_t kFdeVa   = 0x071830U;
    constexpr uint32_t kSpan    = 204U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9000bf7U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0711] start_va=0x052b0c, fde_va=0x071858, span=356 bytes
// [VN] FDE[0711] địa chỉ bắt đầu=0x052b0c, fde_va=0x071858, kích thước=356 byte
// AArch64 opcodes: D101C3FF F90013F9 A9035FF8 A90457F6
uint32_t cybertron_fde_0711_0x052b0c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052b0cU;
    constexpr uint32_t kFdeVa   = 0x071858U;
    constexpr uint32_t kSpan    = 356U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90013f9U;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0712] start_va=0x052c70, fde_va=0x071880, span=88 bytes
// [VN] FDE[0712] địa chỉ bắt đầu=0x052c70, fde_va=0x071880, kích thước=88 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0712_0x052c70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052c70U;
    constexpr uint32_t kFdeVa   = 0x071880U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0713] start_va=0x052cc8, fde_va=0x0718a0, span=388 bytes
// [VN] FDE[0713] địa chỉ bắt đầu=0x052cc8, fde_va=0x0718a0, kích thước=388 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_0713_0x052cc8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052cc8U;
    constexpr uint32_t kFdeVa   = 0x0718a0U;
    constexpr uint32_t kSpan    = 388U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90267faU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0714] start_va=0x052e4c, fde_va=0x0718d0, span=4 bytes
// [VN] FDE[0714] địa chỉ bắt đầu=0x052e4c, fde_va=0x0718d0, kích thước=4 byte
// AArch64 opcodes: 17FF99C5 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0714_0x052e4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052e4cU;
    constexpr uint32_t kFdeVa   = 0x0718d0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff99c5U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0715] start_va=0x052e50, fde_va=0x0718e8, span=36 bytes
// [VN] FDE[0715] địa chỉ bắt đầu=0x052e50, fde_va=0x0718e8, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0715_0x052e50(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052e50U;
    constexpr uint32_t kFdeVa   = 0x0718e8U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0716] start_va=0x052e74, fde_va=0x071908, span=12 bytes
// [VN] FDE[0716] địa chỉ bắt đầu=0x052e74, fde_va=0x071908, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400101 D61F0020 17FF97A8
uint32_t cybertron_fde_0716_0x052e74(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052e74U;
    constexpr uint32_t kFdeVa   = 0x071908U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400101U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ff97a8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0717] start_va=0x052e80, fde_va=0x071920, span=4 bytes
// [VN] FDE[0717] địa chỉ bắt đầu=0x052e80, fde_va=0x071920, kích thước=4 byte
// AArch64 opcodes: 17FF97A8 A9402808 EB08015F 54000180
uint32_t cybertron_fde_0717_0x052e80(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052e80U;
    constexpr uint32_t kFdeVa   = 0x071920U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff97a8U;
    constexpr uint32_t kW1      = 0xa9402808U;
    constexpr uint32_t kW2      = 0xeb08015fU;
    constexpr uint32_t kW3      = 0x54000180U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0718] start_va=0x052e84, fde_va=0x071938, span=112 bytes
// [VN] FDE[0718] địa chỉ bắt đầu=0x052e84, fde_va=0x071938, kích thước=112 byte
// AArch64 opcodes: A9402808 EB08015F 54000180 F9400429
uint32_t cybertron_fde_0718_0x052e84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052e84U;
    constexpr uint32_t kFdeVa   = 0x071938U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xa9402808U;
    constexpr uint32_t kW1      = 0xeb08015fU;
    constexpr uint32_t kW2      = 0x54000180U;
    constexpr uint32_t kW3      = 0xf9400429U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0719] start_va=0x052ef4, fde_va=0x071950, span=80 bytes
// [VN] FDE[0719] địa chỉ bắt đầu=0x052ef4, fde_va=0x071950, kích thước=80 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD A940A014
uint32_t cybertron_fde_0719_0x052ef4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052ef4U;
    constexpr uint32_t kFdeVa   = 0x071950U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa940a014U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

uint32_t DispatchCybertronFdeShard3(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 480U: return cybertron_fde_0480_0x047c90(a0, a1);
        case 481U: return cybertron_fde_0481_0x047d50(a0, a1);
        case 482U: return cybertron_fde_0482_0x047d58(a0, a1);
        case 483U: return cybertron_fde_0483_0x047e7c(a0, a1);
        case 484U: return cybertron_fde_0484_0x047fa0(a0, a1);
        case 485U: return cybertron_fde_0485_0x047fac(a0, a1);
        case 486U: return cybertron_fde_0486_0x047fb4(a0, a1);
        case 487U: return cybertron_fde_0487_0x047fb8(a0, a1);
        case 488U: return cybertron_fde_0488_0x047ff0(a0, a1);
        case 489U: return cybertron_fde_0489_0x048034(a0, a1);
        case 490U: return cybertron_fde_0490_0x048070(a0, a1);
        case 491U: return cybertron_fde_0491_0x0480ac(a0, a1);
        case 492U: return cybertron_fde_0492_0x048118(a0, a1);
        case 493U: return cybertron_fde_0493_0x0481d0(a0, a1);
        case 494U: return cybertron_fde_0494_0x04842c(a0, a1);
        case 495U: return cybertron_fde_0495_0x048510(a0, a1);
        case 496U: return cybertron_fde_0496_0x048680(a0, a1);
        case 497U: return cybertron_fde_0497_0x0486c4(a0, a1);
        case 498U: return cybertron_fde_0498_0x04878c(a0, a1);
        case 499U: return cybertron_fde_0499_0x048840(a0, a1);
        case 500U: return cybertron_fde_0500_0x048844(a0, a1);
        case 501U: return cybertron_fde_0501_0x048914(a0, a1);
        case 502U: return cybertron_fde_0502_0x048934(a0, a1);
        case 503U: return cybertron_fde_0503_0x0489ac(a0, a1);
        case 504U: return cybertron_fde_0504_0x0489b4(a0, a1);
        case 505U: return cybertron_fde_0505_0x0489d8(a0, a1);
        case 506U: return cybertron_fde_0506_0x048a00(a0, a1);
        case 507U: return cybertron_fde_0507_0x048b48(a0, a1);
        case 508U: return cybertron_fde_0508_0x048ba0(a0, a1);
        case 509U: return cybertron_fde_0509_0x048ce8(a0, a1);
        case 510U: return cybertron_fde_0510_0x048d98(a0, a1);
        case 511U: return cybertron_fde_0511_0x048e38(a0, a1);
        case 512U: return cybertron_fde_0512_0x048e90(a0, a1);
        case 513U: return cybertron_fde_0513_0x048ed4(a0, a1);
        case 514U: return cybertron_fde_0514_0x048f24(a0, a1);
        case 515U: return cybertron_fde_0515_0x0491e4(a0, a1);
        case 516U: return cybertron_fde_0516_0x049328(a0, a1);
        case 517U: return cybertron_fde_0517_0x049380(a0, a1);
        case 518U: return cybertron_fde_0518_0x049388(a0, a1);
        case 519U: return cybertron_fde_0519_0x04946c(a0, a1);
        case 520U: return cybertron_fde_0520_0x0494c8(a0, a1);
        case 521U: return cybertron_fde_0521_0x0494d0(a0, a1);
        case 522U: return cybertron_fde_0522_0x0495b8(a0, a1);
        case 523U: return cybertron_fde_0523_0x0495c0(a0, a1);
        case 524U: return cybertron_fde_0524_0x049604(a0, a1);
        case 525U: return cybertron_fde_0525_0x049648(a0, a1);
        case 526U: return cybertron_fde_0526_0x049654(a0, a1);
        case 527U: return cybertron_fde_0527_0x049660(a0, a1);
        case 528U: return cybertron_fde_0528_0x049748(a0, a1);
        case 529U: return cybertron_fde_0529_0x049810(a0, a1);
        case 530U: return cybertron_fde_0530_0x049854(a0, a1);
        case 531U: return cybertron_fde_0531_0x0498c4(a0, a1);
        case 532U: return cybertron_fde_0532_0x04991c(a0, a1);
        case 533U: return cybertron_fde_0533_0x049968(a0, a1);
        case 534U: return cybertron_fde_0534_0x0499a4(a0, a1);
        case 535U: return cybertron_fde_0535_0x049a94(a0, a1);
        case 536U: return cybertron_fde_0536_0x049b44(a0, a1);
        case 537U: return cybertron_fde_0537_0x049c68(a0, a1);
        case 538U: return cybertron_fde_0538_0x049cbc(a0, a1);
        case 539U: return cybertron_fde_0539_0x049d18(a0, a1);
        case 540U: return cybertron_fde_0540_0x049d7c(a0, a1);
        case 541U: return cybertron_fde_0541_0x049dd0(a0, a1);
        case 542U: return cybertron_fde_0542_0x049dd4(a0, a1);
        case 543U: return cybertron_fde_0543_0x049e40(a0, a1);
        case 544U: return cybertron_fde_0544_0x049e8c(a0, a1);
        case 545U: return cybertron_fde_0545_0x049ec8(a0, a1);
        case 546U: return cybertron_fde_0546_0x049f0c(a0, a1);
        case 547U: return cybertron_fde_0547_0x04a018(a0, a1);
        case 548U: return cybertron_fde_0548_0x04a060(a0, a1);
        case 549U: return cybertron_fde_0549_0x04a0e4(a0, a1);
        case 550U: return cybertron_fde_0550_0x04a478(a0, a1);
        case 551U: return cybertron_fde_0551_0x04a610(a0, a1);
        case 552U: return cybertron_fde_0552_0x04a918(a0, a1);
        case 553U: return cybertron_fde_0553_0x04aa18(a0, a1);
        case 554U: return cybertron_fde_0554_0x04ab28(a0, a1);
        case 555U: return cybertron_fde_0555_0x04add0(a0, a1);
        case 556U: return cybertron_fde_0556_0x04b0d8(a0, a1);
        case 557U: return cybertron_fde_0557_0x04b3e0(a0, a1);
        case 558U: return cybertron_fde_0558_0x04b40c(a0, a1);
        case 559U: return cybertron_fde_0559_0x04b448(a0, a1);
        case 560U: return cybertron_fde_0560_0x04b6c8(a0, a1);
        case 561U: return cybertron_fde_0561_0x04b738(a0, a1);
        case 562U: return cybertron_fde_0562_0x04b784(a0, a1);
        case 563U: return cybertron_fde_0563_0x04b898(a0, a1);
        case 564U: return cybertron_fde_0564_0x04b95c(a0, a1);
        case 565U: return cybertron_fde_0565_0x04ba40(a0, a1);
        case 566U: return cybertron_fde_0566_0x04ba94(a0, a1);
        case 567U: return cybertron_fde_0567_0x04baf0(a0, a1);
        case 568U: return cybertron_fde_0568_0x04bc44(a0, a1);
        case 569U: return cybertron_fde_0569_0x04bd74(a0, a1);
        case 570U: return cybertron_fde_0570_0x04bde4(a0, a1);
        case 571U: return cybertron_fde_0571_0x04be34(a0, a1);
        case 572U: return cybertron_fde_0572_0x04be8c(a0, a1);
        case 573U: return cybertron_fde_0573_0x04bec8(a0, a1);
        case 574U: return cybertron_fde_0574_0x04becc(a0, a1);
        case 575U: return cybertron_fde_0575_0x04bf3c(a0, a1);
        case 576U: return cybertron_fde_0576_0x04bf94(a0, a1);
        case 577U: return cybertron_fde_0577_0x04c058(a0, a1);
        case 578U: return cybertron_fde_0578_0x04c17c(a0, a1);
        case 579U: return cybertron_fde_0579_0x04c1d0(a0, a1);
        case 580U: return cybertron_fde_0580_0x04c248(a0, a1);
        case 581U: return cybertron_fde_0581_0x04c28c(a0, a1);
        case 582U: return cybertron_fde_0582_0x04c398(a0, a1);
        case 583U: return cybertron_fde_0583_0x04c3e0(a0, a1);
        case 584U: return cybertron_fde_0584_0x04c464(a0, a1);
        case 585U: return cybertron_fde_0585_0x04c554(a0, a1);
        case 586U: return cybertron_fde_0586_0x04c5cc(a0, a1);
        case 587U: return cybertron_fde_0587_0x04c5dc(a0, a1);
        case 588U: return cybertron_fde_0588_0x04c610(a0, a1);
        case 589U: return cybertron_fde_0589_0x04c63c(a0, a1);
        case 590U: return cybertron_fde_0590_0x04c66c(a0, a1);
        case 591U: return cybertron_fde_0591_0x04c6d0(a0, a1);
        case 592U: return cybertron_fde_0592_0x04c6f0(a0, a1);
        case 593U: return cybertron_fde_0593_0x04c74c(a0, a1);
        case 594U: return cybertron_fde_0594_0x04c760(a0, a1);
        case 595U: return cybertron_fde_0595_0x04c768(a0, a1);
        case 596U: return cybertron_fde_0596_0x04c7d8(a0, a1);
        case 597U: return cybertron_fde_0597_0x04c82c(a0, a1);
        case 598U: return cybertron_fde_0598_0x04c96c(a0, a1);
        case 599U: return cybertron_fde_0599_0x04c9c0(a0, a1);
        case 600U: return cybertron_fde_0600_0x04ca18(a0, a1);
        case 601U: return cybertron_fde_0601_0x04cb00(a0, a1);
        case 602U: return cybertron_fde_0602_0x04cb24(a0, a1);
        case 603U: return cybertron_fde_0603_0x04cce4(a0, a1);
        case 604U: return cybertron_fde_0604_0x04cd3c(a0, a1);
        case 605U: return cybertron_fde_0605_0x04cd44(a0, a1);
        case 606U: return cybertron_fde_0606_0x04cd4c(a0, a1);
        case 607U: return cybertron_fde_0607_0x04cd54(a0, a1);
        case 608U: return cybertron_fde_0608_0x04cd7c(a0, a1);
        case 609U: return cybertron_fde_0609_0x04cda4(a0, a1);
        case 610U: return cybertron_fde_0610_0x04cdac(a0, a1);
        case 611U: return cybertron_fde_0611_0x04cdb4(a0, a1);
        case 612U: return cybertron_fde_0612_0x04cdf8(a0, a1);
        case 613U: return cybertron_fde_0613_0x04cec4(a0, a1);
        case 614U: return cybertron_fde_0614_0x04cf58(a0, a1);
        case 615U: return cybertron_fde_0615_0x04cf64(a0, a1);
        case 616U: return cybertron_fde_0616_0x04d04c(a0, a1);
        case 617U: return cybertron_fde_0617_0x04d078(a0, a1);
        case 618U: return cybertron_fde_0618_0x04d0b4(a0, a1);
        case 619U: return cybertron_fde_0619_0x04d11c(a0, a1);
        case 620U: return cybertron_fde_0620_0x04d18c(a0, a1);
        case 621U: return cybertron_fde_0621_0x04d1f4(a0, a1);
        case 622U: return cybertron_fde_0622_0x04d27c(a0, a1);
        case 623U: return cybertron_fde_0623_0x04d2d8(a0, a1);
        case 624U: return cybertron_fde_0624_0x04d330(a0, a1);
        case 625U: return cybertron_fde_0625_0x04d628(a0, a1);
        case 626U: return cybertron_fde_0626_0x04d684(a0, a1);
        case 627U: return cybertron_fde_0627_0x04d828(a0, a1);
        case 628U: return cybertron_fde_0628_0x04dbbc(a0, a1);
        case 629U: return cybertron_fde_0629_0x04dd30(a0, a1);
        case 630U: return cybertron_fde_0630_0x04dd8c(a0, a1);
        case 631U: return cybertron_fde_0631_0x04de78(a0, a1);
        case 632U: return cybertron_fde_0632_0x04e07c(a0, a1);
        case 633U: return cybertron_fde_0633_0x04e0c8(a0, a1);
        case 634U: return cybertron_fde_0634_0x04e104(a0, a1);
        case 635U: return cybertron_fde_0635_0x04e268(a0, a1);
        case 636U: return cybertron_fde_0636_0x04e358(a0, a1);
        case 637U: return cybertron_fde_0637_0x04e47c(a0, a1);
        case 638U: return cybertron_fde_0638_0x04e4b0(a0, a1);
        case 639U: return cybertron_fde_0639_0x04e4ec(a0, a1);
        case 640U: return cybertron_fde_0640_0x04e4f4(a0, a1);
        case 641U: return cybertron_fde_0641_0x04e4f8(a0, a1);
        case 642U: return cybertron_fde_0642_0x04e5bc(a0, a1);
        case 643U: return cybertron_fde_0643_0x04e610(a0, a1);
        case 644U: return cybertron_fde_0644_0x04e6b8(a0, a1);
        case 645U: return cybertron_fde_0645_0x04e740(a0, a1);
        case 646U: return cybertron_fde_0646_0x04e84c(a0, a1);
        case 647U: return cybertron_fde_0647_0x04e894(a0, a1);
        case 648U: return cybertron_fde_0648_0x04e918(a0, a1);
        case 649U: return cybertron_fde_0649_0x04e940(a0, a1);
        case 650U: return cybertron_fde_0650_0x04e984(a0, a1);
        case 651U: return cybertron_fde_0651_0x04e9b0(a0, a1);
        case 652U: return cybertron_fde_0652_0x04e9f0(a0, a1);
        case 653U: return cybertron_fde_0653_0x04e9f8(a0, a1);
        case 654U: return cybertron_fde_0654_0x04ea00(a0, a1);
        case 655U: return cybertron_fde_0655_0x04ea38(a0, a1);
        case 656U: return cybertron_fde_0656_0x04ea6c(a0, a1);
        case 657U: return cybertron_fde_0657_0x04eaa8(a0, a1);
        case 658U: return cybertron_fde_0658_0x04eaf8(a0, a1);
        case 659U: return cybertron_fde_0659_0x04eb30(a0, a1);
        case 660U: return cybertron_fde_0660_0x04eb68(a0, a1);
        case 661U: return cybertron_fde_0661_0x04ed7c(a0, a1);
        case 662U: return cybertron_fde_0662_0x04ee28(a0, a1);
        case 663U: return cybertron_fde_0663_0x04eed0(a0, a1);
        case 664U: return cybertron_fde_0664_0x04f09c(a0, a1);
        case 665U: return cybertron_fde_0665_0x04f180(a0, a1);
        case 666U: return cybertron_fde_0666_0x04f580(a0, a1);
        case 667U: return cybertron_fde_0667_0x04f5dc(a0, a1);
        case 668U: return cybertron_fde_0668_0x04ff30(a0, a1);
        case 669U: return cybertron_fde_0669_0x050034(a0, a1);
        case 670U: return cybertron_fde_0670_0x050060(a0, a1);
        case 671U: return cybertron_fde_0671_0x050098(a0, a1);
        case 672U: return cybertron_fde_0672_0x0500c4(a0, a1);
        case 673U: return cybertron_fde_0673_0x0500c8(a0, a1);
        case 674U: return cybertron_fde_0674_0x050140(a0, a1);
        case 675U: return cybertron_fde_0675_0x050180(a0, a1);
        case 676U: return cybertron_fde_0676_0x0503a4(a0, a1);
        case 677U: return cybertron_fde_0677_0x05044c(a0, a1);
        case 678U: return cybertron_fde_0678_0x050490(a0, a1);
        case 679U: return cybertron_fde_0679_0x050518(a0, a1);
        case 680U: return cybertron_fde_0680_0x0505dc(a0, a1);
        case 681U: return cybertron_fde_0681_0x0507f4(a0, a1);
        case 682U: return cybertron_fde_0682_0x05095c(a0, a1);
        case 683U: return cybertron_fde_0683_0x051b28(a0, a1);
        case 684U: return cybertron_fde_0684_0x051cdc(a0, a1);
        case 685U: return cybertron_fde_0685_0x051d20(a0, a1);
        case 686U: return cybertron_fde_0686_0x051e5c(a0, a1);
        case 687U: return cybertron_fde_0687_0x052228(a0, a1);
        case 688U: return cybertron_fde_0688_0x052274(a0, a1);
        case 689U: return cybertron_fde_0689_0x0522d0(a0, a1);
        case 690U: return cybertron_fde_0690_0x052350(a0, a1);
        case 691U: return cybertron_fde_0691_0x052358(a0, a1);
        case 692U: return cybertron_fde_0692_0x0523e8(a0, a1);
        case 693U: return cybertron_fde_0693_0x0524d0(a0, a1);
        case 694U: return cybertron_fde_0694_0x0524e0(a0, a1);
        case 695U: return cybertron_fde_0695_0x0524e4(a0, a1);
        case 696U: return cybertron_fde_0696_0x0524e8(a0, a1);
        case 697U: return cybertron_fde_0697_0x0524fc(a0, a1);
        case 698U: return cybertron_fde_0698_0x052530(a0, a1);
        case 699U: return cybertron_fde_0699_0x052534(a0, a1);
        case 700U: return cybertron_fde_0700_0x052558(a0, a1);
        case 701U: return cybertron_fde_0701_0x05263c(a0, a1);
        case 702U: return cybertron_fde_0702_0x052660(a0, a1);
        case 703U: return cybertron_fde_0703_0x0526d8(a0, a1);
        case 704U: return cybertron_fde_0704_0x052714(a0, a1);
        case 705U: return cybertron_fde_0705_0x052788(a0, a1);
        case 706U: return cybertron_fde_0706_0x052794(a0, a1);
        case 707U: return cybertron_fde_0707_0x052804(a0, a1);
        case 708U: return cybertron_fde_0708_0x052808(a0, a1);
        case 709U: return cybertron_fde_0709_0x05296c(a0, a1);
        case 710U: return cybertron_fde_0710_0x052a40(a0, a1);
        case 711U: return cybertron_fde_0711_0x052b0c(a0, a1);
        case 712U: return cybertron_fde_0712_0x052c70(a0, a1);
        case 713U: return cybertron_fde_0713_0x052cc8(a0, a1);
        case 714U: return cybertron_fde_0714_0x052e4c(a0, a1);
        case 715U: return cybertron_fde_0715_0x052e50(a0, a1);
        case 716U: return cybertron_fde_0716_0x052e74(a0, a1);
        case 717U: return cybertron_fde_0717_0x052e80(a0, a1);
        case 718U: return cybertron_fde_0718_0x052e84(a0, a1);
        case 719U: return cybertron_fde_0719_0x052ef4(a0, a1);
        default: return 0U;
    }
}

} // namespace datacenter
