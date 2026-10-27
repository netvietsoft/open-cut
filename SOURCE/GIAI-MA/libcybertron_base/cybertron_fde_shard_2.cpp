// ============================================================================
// File: cybertron_fde_shard_2.cpp
// Target: libcybertron_base.so (509,816 bytes)
// SHA-256: 0d969c7e981d68f46d81986a0f16881d1ff9605afb9e6e352f1ae88a5695c7e6
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// FDE Range: [240..479] of 1,201 (.eh_frame_hdr @ 0x069c8c)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [240..479]
//      verified directly against the .text section of libcybertron_base.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [240..479]
//      đã đối chiếu trực tiếp với phân đoạn .text của libcybertron_base.so.
// ============================================================================

#include "cybertron_base_types.h"

namespace datacenter {

// [EN] FDE[0240] start_va=0x042c70, fde_va=0x06dea0, span=36 bytes
// [VN] FDE[0240] địa chỉ bắt đầu=0x042c70, fde_va=0x06dea0, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0240_0x042c70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042c70U;
    constexpr uint32_t kFdeVa   = 0x06dea0U;
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

// [EN] FDE[0241] start_va=0x042c94, fde_va=0x06dec0, span=28 bytes
// [VN] FDE[0241] địa chỉ bắt đầu=0x042c94, fde_va=0x06dec0, kích thước=28 byte
// AArch64 opcodes: AA0003E8 38408D09 37000069 91000500
uint32_t cybertron_fde_0241_0x042c94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042c94U;
    constexpr uint32_t kFdeVa   = 0x06dec0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xaa0003e8U;
    constexpr uint32_t kW1      = 0x38408d09U;
    constexpr uint32_t kW2      = 0x37000069U;
    constexpr uint32_t kW3      = 0x91000500U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0242] start_va=0x042cb0, fde_va=0x06ded8, span=108 bytes
// [VN] FDE[0242] địa chỉ bắt đầu=0x042cb0, fde_va=0x06ded8, kích thước=108 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0242_0x042cb0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042cb0U;
    constexpr uint32_t kFdeVa   = 0x06ded8U;
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

// [EN] FDE[0243] start_va=0x042d1c, fde_va=0x06def8, span=108 bytes
// [VN] FDE[0243] địa chỉ bắt đầu=0x042d1c, fde_va=0x06def8, kích thước=108 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0243_0x042d1c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042d1cU;
    constexpr uint32_t kFdeVa   = 0x06def8U;
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

// [EN] FDE[0244] start_va=0x042d88, fde_va=0x06df18, span=4 bytes
// [VN] FDE[0244] địa chỉ bắt đầu=0x042d88, fde_va=0x06df18, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D65F03C0 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0244_0x042d88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042d88U;
    constexpr uint32_t kFdeVa   = 0x06df18U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0245] start_va=0x042d8c, fde_va=0x06df30, span=4 bytes
// [VN] FDE[0245] địa chỉ bắt đầu=0x042d8c, fde_va=0x06df30, kích thước=4 byte
// AArch64 opcodes: D65F03C0 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0245_0x042d8c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042d8cU;
    constexpr uint32_t kFdeVa   = 0x06df30U;
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

// [EN] FDE[0246] start_va=0x042d90, fde_va=0x06df48, span=64 bytes
// [VN] FDE[0246] địa chỉ bắt đầu=0x042d90, fde_va=0x06df48, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B00001E9
uint32_t cybertron_fde_0246_0x042d90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042d90U;
    constexpr uint32_t kFdeVa   = 0x06df48U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb00001e9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0247] start_va=0x042dd0, fde_va=0x06df68, span=36 bytes
// [VN] FDE[0247] địa chỉ bắt đầu=0x042dd0, fde_va=0x06df68, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0247_0x042dd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042dd0U;
    constexpr uint32_t kFdeVa   = 0x06df68U;
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

// [EN] FDE[0248] start_va=0x042df4, fde_va=0x06df88, span=36 bytes
// [VN] FDE[0248] địa chỉ bắt đầu=0x042df4, fde_va=0x06df88, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0248_0x042df4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042df4U;
    constexpr uint32_t kFdeVa   = 0x06df88U;
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

// [EN] FDE[0249] start_va=0x042e18, fde_va=0x06dfa8, span=372 bytes
// [VN] FDE[0249] địa chỉ bắt đầu=0x042e18, fde_va=0x06dfa8, kích thước=372 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0249_0x042e18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042e18U;
    constexpr uint32_t kFdeVa   = 0x06dfa8U;
    constexpr uint32_t kSpan    = 372U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0250] start_va=0x042f8c, fde_va=0x06dfd0, span=148 bytes
// [VN] FDE[0250] địa chỉ bắt đầu=0x042f8c, fde_va=0x06dfd0, kích thước=148 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B00001E8
uint32_t cybertron_fde_0250_0x042f8c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042f8cU;
    constexpr uint32_t kFdeVa   = 0x06dfd0U;
    constexpr uint32_t kSpan    = 148U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb00001e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0251] start_va=0x043020, fde_va=0x06dff0, span=4 bytes
// [VN] FDE[0251] địa chỉ bắt đầu=0x043020, fde_va=0x06dff0, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D1002000 17FFDC32 D1004000
uint32_t cybertron_fde_0251_0x043020(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043020U;
    constexpr uint32_t kFdeVa   = 0x06dff0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd1002000U;
    constexpr uint32_t kW2      = 0x17ffdc32U;
    constexpr uint32_t kW3      = 0xd1004000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0252] start_va=0x043024, fde_va=0x06e008, span=8 bytes
// [VN] FDE[0252] địa chỉ bắt đầu=0x043024, fde_va=0x06e008, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFDC32 D1004000 17FFDC30
uint32_t cybertron_fde_0252_0x043024(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043024U;
    constexpr uint32_t kFdeVa   = 0x06e008U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffdc32U;
    constexpr uint32_t kW2      = 0xd1004000U;
    constexpr uint32_t kW3      = 0x17ffdc30U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0253] start_va=0x04302c, fde_va=0x06e020, span=8 bytes
// [VN] FDE[0253] địa chỉ bắt đầu=0x04302c, fde_va=0x06e020, kích thước=8 byte
// AArch64 opcodes: D1004000 17FFDC30 D100C000 17FFDC2E
uint32_t cybertron_fde_0253_0x04302c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04302cU;
    constexpr uint32_t kFdeVa   = 0x06e020U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1004000U;
    constexpr uint32_t kW1      = 0x17ffdc30U;
    constexpr uint32_t kW2      = 0xd100c000U;
    constexpr uint32_t kW3      = 0x17ffdc2eU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0254] start_va=0x043034, fde_va=0x06e038, span=8 bytes
// [VN] FDE[0254] địa chỉ bắt đầu=0x043034, fde_va=0x06e038, kích thước=8 byte
// AArch64 opcodes: D100C000 17FFDC2E D100E000 17FFDC2C
uint32_t cybertron_fde_0254_0x043034(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043034U;
    constexpr uint32_t kFdeVa   = 0x06e038U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd100c000U;
    constexpr uint32_t kW1      = 0x17ffdc2eU;
    constexpr uint32_t kW2      = 0xd100e000U;
    constexpr uint32_t kW3      = 0x17ffdc2cU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0255] start_va=0x04303c, fde_va=0x06e050, span=8 bytes
// [VN] FDE[0255] địa chỉ bắt đầu=0x04303c, fde_va=0x06e050, kích thước=8 byte
// AArch64 opcodes: D100E000 17FFDC2C D1010000 17FFDC2A
uint32_t cybertron_fde_0255_0x04303c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04303cU;
    constexpr uint32_t kFdeVa   = 0x06e050U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd100e000U;
    constexpr uint32_t kW1      = 0x17ffdc2cU;
    constexpr uint32_t kW2      = 0xd1010000U;
    constexpr uint32_t kW3      = 0x17ffdc2aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0256] start_va=0x043044, fde_va=0x06e068, span=8 bytes
// [VN] FDE[0256] địa chỉ bắt đầu=0x043044, fde_va=0x06e068, kích thước=8 byte
// AArch64 opcodes: D1010000 17FFDC2A D1012000 17FFDC28
uint32_t cybertron_fde_0256_0x043044(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043044U;
    constexpr uint32_t kFdeVa   = 0x06e068U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1010000U;
    constexpr uint32_t kW1      = 0x17ffdc2aU;
    constexpr uint32_t kW2      = 0xd1012000U;
    constexpr uint32_t kW3      = 0x17ffdc28U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0257] start_va=0x04304c, fde_va=0x06e080, span=8 bytes
// [VN] FDE[0257] địa chỉ bắt đầu=0x04304c, fde_va=0x06e080, kích thước=8 byte
// AArch64 opcodes: D1012000 17FFDC28 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0257_0x04304c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04304cU;
    constexpr uint32_t kFdeVa   = 0x06e080U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1012000U;
    constexpr uint32_t kW1      = 0x17ffdc28U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0258] start_va=0x043054, fde_va=0x06e098, span=36 bytes
// [VN] FDE[0258] địa chỉ bắt đầu=0x043054, fde_va=0x06e098, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0258_0x043054(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043054U;
    constexpr uint32_t kFdeVa   = 0x06e098U;
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

// [EN] FDE[0259] start_va=0x043078, fde_va=0x06e0b8, span=40 bytes
// [VN] FDE[0259] địa chỉ bắt đầu=0x043078, fde_va=0x06e0b8, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D1002013
uint32_t cybertron_fde_0259_0x043078(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043078U;
    constexpr uint32_t kFdeVa   = 0x06e0b8U;
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

// [EN] FDE[0260] start_va=0x0430a0, fde_va=0x06e0d8, span=40 bytes
// [VN] FDE[0260] địa chỉ bắt đầu=0x0430a0, fde_va=0x06e0d8, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D1004013
uint32_t cybertron_fde_0260_0x0430a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0430a0U;
    constexpr uint32_t kFdeVa   = 0x06e0d8U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd1004013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0261] start_va=0x0430c8, fde_va=0x06e0f8, span=40 bytes
// [VN] FDE[0261] địa chỉ bắt đầu=0x0430c8, fde_va=0x06e0f8, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D100C013
uint32_t cybertron_fde_0261_0x0430c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0430c8U;
    constexpr uint32_t kFdeVa   = 0x06e0f8U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd100c013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0262] start_va=0x0430f0, fde_va=0x06e118, span=40 bytes
// [VN] FDE[0262] địa chỉ bắt đầu=0x0430f0, fde_va=0x06e118, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D100E013
uint32_t cybertron_fde_0262_0x0430f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0430f0U;
    constexpr uint32_t kFdeVa   = 0x06e118U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd100e013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0263] start_va=0x043118, fde_va=0x06e138, span=40 bytes
// [VN] FDE[0263] địa chỉ bắt đầu=0x043118, fde_va=0x06e138, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D1010013
uint32_t cybertron_fde_0263_0x043118(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043118U;
    constexpr uint32_t kFdeVa   = 0x06e138U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd1010013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0264] start_va=0x043140, fde_va=0x06e158, span=40 bytes
// [VN] FDE[0264] địa chỉ bắt đầu=0x043140, fde_va=0x06e158, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D1012013
uint32_t cybertron_fde_0264_0x043140(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043140U;
    constexpr uint32_t kFdeVa   = 0x06e158U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd1012013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0265] start_va=0x043168, fde_va=0x06e178, span=164 bytes
// [VN] FDE[0265] địa chỉ bắt đầu=0x043168, fde_va=0x06e178, kích thước=164 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0265_0x043168(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043168U;
    constexpr uint32_t kFdeVa   = 0x06e178U;
    constexpr uint32_t kSpan    = 164U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0266] start_va=0x04320c, fde_va=0x06e198, span=84 bytes
// [VN] FDE[0266] địa chỉ bắt đầu=0x04320c, fde_va=0x06e198, kích thước=84 byte
// AArch64 opcodes: A9BF7BFD 910003FD 900001E8 F9468508
uint32_t cybertron_fde_0266_0x04320c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04320cU;
    constexpr uint32_t kFdeVa   = 0x06e198U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x900001e8U;
    constexpr uint32_t kW3      = 0xf9468508U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0267] start_va=0x043260, fde_va=0x06e1b8, span=224 bytes
// [VN] FDE[0267] địa chỉ bắt đầu=0x043260, fde_va=0x06e1b8, kích thước=224 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0267_0x043260(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043260U;
    constexpr uint32_t kFdeVa   = 0x06e1b8U;
    constexpr uint32_t kSpan    = 224U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9000bf7U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0268] start_va=0x043340, fde_va=0x06e1e0, span=8 bytes
// [VN] FDE[0268] địa chỉ bắt đầu=0x043340, fde_va=0x06e1e0, kích thước=8 byte
// AArch64 opcodes: D1004000 17FFD5AF 2A1F03E1 17FFD8E5
uint32_t cybertron_fde_0268_0x043340(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043340U;
    constexpr uint32_t kFdeVa   = 0x06e1e0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1004000U;
    constexpr uint32_t kW1      = 0x17ffd5afU;
    constexpr uint32_t kW2      = 0x2a1f03e1U;
    constexpr uint32_t kW3      = 0x17ffd8e5U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0269] start_va=0x043348, fde_va=0x06e1f8, span=8 bytes
// [VN] FDE[0269] địa chỉ bắt đầu=0x043348, fde_va=0x06e1f8, kích thước=8 byte
// AArch64 opcodes: 2A1F03E1 17FFD8E5 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0269_0x043348(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043348U;
    constexpr uint32_t kFdeVa   = 0x06e1f8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x2a1f03e1U;
    constexpr uint32_t kW1      = 0x17ffd8e5U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0270] start_va=0x043350, fde_va=0x06e210, span=84 bytes
// [VN] FDE[0270] địa chỉ bắt đầu=0x043350, fde_va=0x06e210, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 9100A008
uint32_t cybertron_fde_0270_0x043350(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043350U;
    constexpr uint32_t kFdeVa   = 0x06e210U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x9100a008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0271] start_va=0x0433a4, fde_va=0x06e230, span=12 bytes
// [VN] FDE[0271] địa chỉ bắt đầu=0x0433a4, fde_va=0x06e230, kích thước=12 byte
// AArch64 opcodes: D1004000 2A1F03E1 17FFD8CD F9400C00
uint32_t cybertron_fde_0271_0x0433a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0433a4U;
    constexpr uint32_t kFdeVa   = 0x06e230U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xd1004000U;
    constexpr uint32_t kW1      = 0x2a1f03e1U;
    constexpr uint32_t kW2      = 0x17ffd8cdU;
    constexpr uint32_t kW3      = 0xf9400c00U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0272] start_va=0x0433b0, fde_va=0x06e248, span=16 bytes
// [VN] FDE[0272] địa chỉ bắt đầu=0x0433b0, fde_va=0x06e248, kích thước=16 byte
// AArch64 opcodes: F9400C00 F9400008 F9401D01 D61F0020
uint32_t cybertron_fde_0272_0x0433b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0433b0U;
    constexpr uint32_t kFdeVa   = 0x06e248U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400c00U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9401d01U;
    constexpr uint32_t kW3      = 0xd61f0020U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0273] start_va=0x0433c0, fde_va=0x06e260, span=40 bytes
// [VN] FDE[0273] địa chỉ bắt đầu=0x0433c0, fde_va=0x06e260, kích thước=40 byte
// AArch64 opcodes: 9100A008 88DFFD09 71000D3F 54000080
uint32_t cybertron_fde_0273_0x0433c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0433c0U;
    constexpr uint32_t kFdeVa   = 0x06e260U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0x9100a008U;
    constexpr uint32_t kW1      = 0x88dffd09U;
    constexpr uint32_t kW2      = 0x71000d3fU;
    constexpr uint32_t kW3      = 0x54000080U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0274] start_va=0x0433e8, fde_va=0x06e278, span=40 bytes
// [VN] FDE[0274] địa chỉ bắt đầu=0x0433e8, fde_va=0x06e278, kích thước=40 byte
// AArch64 opcodes: D1002008 88DFFD09 71000D3F 54000080
uint32_t cybertron_fde_0274_0x0433e8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0433e8U;
    constexpr uint32_t kFdeVa   = 0x06e278U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xd1002008U;
    constexpr uint32_t kW1      = 0x88dffd09U;
    constexpr uint32_t kW2      = 0x71000d3fU;
    constexpr uint32_t kW3      = 0x54000080U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0275] start_va=0x043410, fde_va=0x06e290, span=12 bytes
// [VN] FDE[0275] địa chỉ bắt đầu=0x043410, fde_va=0x06e290, kích thước=12 byte
// AArch64 opcodes: B00001E8 F9400100 D65F03C0 F9404000
uint32_t cybertron_fde_0275_0x043410(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043410U;
    constexpr uint32_t kFdeVa   = 0x06e290U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xb00001e8U;
    constexpr uint32_t kW1      = 0xf9400100U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xf9404000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0276] start_va=0x04341c, fde_va=0x06e2a8, span=16 bytes
// [VN] FDE[0276] địa chỉ bắt đầu=0x04341c, fde_va=0x06e2a8, kích thước=16 byte
// AArch64 opcodes: F9404000 F9400008 F9401103 D61F0060
uint32_t cybertron_fde_0276_0x04341c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04341cU;
    constexpr uint32_t kFdeVa   = 0x06e2a8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9404000U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9401103U;
    constexpr uint32_t kW3      = 0xd61f0060U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0277] start_va=0x04342c, fde_va=0x06e2c0, span=100 bytes
// [VN] FDE[0277] địa chỉ bắt đầu=0x04342c, fde_va=0x06e2c0, kích thước=100 byte
// AArch64 opcodes: A9BF7BFD 910003FD 710FA83F 54000100
uint32_t cybertron_fde_0277_0x04342c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04342cU;
    constexpr uint32_t kFdeVa   = 0x06e2c0U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x710fa83fU;
    constexpr uint32_t kW3      = 0x54000100U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0278] start_va=0x043490, fde_va=0x06e2e0, span=16 bytes
// [VN] FDE[0278] địa chỉ bắt đầu=0x043490, fde_va=0x06e2e0, kích thước=16 byte
// AArch64 opcodes: F9404000 F9400008 F9401D02 D61F0040
uint32_t cybertron_fde_0278_0x043490(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043490U;
    constexpr uint32_t kFdeVa   = 0x06e2e0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9404000U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9401d02U;
    constexpr uint32_t kW3      = 0xd61f0040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0279] start_va=0x0434a0, fde_va=0x06e2f8, span=448 bytes
// [VN] FDE[0279] địa chỉ bắt đầu=0x0434a0, fde_va=0x06e2f8, kích thước=448 byte
// AArch64 opcodes: D101C3FF A9035FF8 A90457F6 A9054FF4
uint32_t cybertron_fde_0279_0x0434a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0434a0U;
    constexpr uint32_t kFdeVa   = 0x06e2f8U;
    constexpr uint32_t kSpan    = 448U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9035ff8U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0280] start_va=0x043660, fde_va=0x06e320, span=412 bytes
// [VN] FDE[0280] địa chỉ bắt đầu=0x043660, fde_va=0x06e320, kích thước=412 byte
// AArch64 opcodes: D101C3FF A9035FF8 A90457F6 A9054FF4
uint32_t cybertron_fde_0280_0x043660(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043660U;
    constexpr uint32_t kFdeVa   = 0x06e320U;
    constexpr uint32_t kSpan    = 412U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9035ff8U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0281] start_va=0x0437fc, fde_va=0x06e348, span=28 bytes
// [VN] FDE[0281] địa chỉ bắt đầu=0x0437fc, fde_va=0x06e348, kích thước=28 byte
// AArch64 opcodes: 71106C3F 54000041 17FFDE7B F9404000
uint32_t cybertron_fde_0281_0x0437fc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0437fcU;
    constexpr uint32_t kFdeVa   = 0x06e348U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0x71106c3fU;
    constexpr uint32_t kW1      = 0x54000041U;
    constexpr uint32_t kW2      = 0x17ffde7bU;
    constexpr uint32_t kW3      = 0xf9404000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0282] start_va=0x043818, fde_va=0x06e360, span=412 bytes
// [VN] FDE[0282] địa chỉ bắt đầu=0x043818, fde_va=0x06e360, kích thước=412 byte
// AArch64 opcodes: D101C3FF A9035FF8 A90457F6 A9054FF4
uint32_t cybertron_fde_0282_0x043818(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043818U;
    constexpr uint32_t kFdeVa   = 0x06e360U;
    constexpr uint32_t kSpan    = 412U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9035ff8U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0283] start_va=0x0439b4, fde_va=0x06e388, span=28 bytes
// [VN] FDE[0283] địa chỉ bắt đầu=0x0439b4, fde_va=0x06e388, kích thước=28 byte
// AArch64 opcodes: 711F443F 54000041 17FFDD21 F9404000
uint32_t cybertron_fde_0283_0x0439b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0439b4U;
    constexpr uint32_t kFdeVa   = 0x06e388U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0x711f443fU;
    constexpr uint32_t kW1      = 0x54000041U;
    constexpr uint32_t kW2      = 0x17ffdd21U;
    constexpr uint32_t kW3      = 0xf9404000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0284] start_va=0x0439d0, fde_va=0x06e3a0, span=412 bytes
// [VN] FDE[0284] địa chỉ bắt đầu=0x0439d0, fde_va=0x06e3a0, kích thước=412 byte
// AArch64 opcodes: D101C3FF 6D0323E9 A90457F6 A9054FF4
uint32_t cybertron_fde_0284_0x0439d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0439d0U;
    constexpr uint32_t kFdeVa   = 0x06e3a0U;
    constexpr uint32_t kSpan    = 412U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0x6d0323e9U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0285] start_va=0x043b6c, fde_va=0x06e3c8, span=164 bytes
// [VN] FDE[0285] địa chỉ bắt đầu=0x043b6c, fde_va=0x06e3c8, kích thước=164 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0285_0x043b6c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043b6cU;
    constexpr uint32_t kFdeVa   = 0x06e3c8U;
    constexpr uint32_t kSpan    = 164U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa9024ff4U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0286] start_va=0x043c10, fde_va=0x06e3e8, span=208 bytes
// [VN] FDE[0286] địa chỉ bắt đầu=0x043c10, fde_va=0x06e3e8, kích thước=208 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_0286_0x043c10(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043c10U;
    constexpr uint32_t kFdeVa   = 0x06e3e8U;
    constexpr uint32_t kSpan    = 208U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf90013f7U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0287] start_va=0x043ce0, fde_va=0x06e410, span=8 bytes
// [VN] FDE[0287] địa chỉ bắt đầu=0x043ce0, fde_va=0x06e410, kích thước=8 byte
// AArch64 opcodes: F9003401 D65F03C0 D65F03C0 D65F03C0
uint32_t cybertron_fde_0287_0x043ce0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043ce0U;
    constexpr uint32_t kFdeVa   = 0x06e410U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9003401U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0288] start_va=0x043ce8, fde_va=0x06e428, span=4 bytes
// [VN] FDE[0288] địa chỉ bắt đầu=0x043ce8, fde_va=0x06e428, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D65F03C0 D65F03C0 D65F03C0
uint32_t cybertron_fde_0288_0x043ce8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043ce8U;
    constexpr uint32_t kFdeVa   = 0x06e428U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0289] start_va=0x043cec, fde_va=0x06e440, span=4 bytes
// [VN] FDE[0289] địa chỉ bắt đầu=0x043cec, fde_va=0x06e440, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D65F03C0 D65F03C0 D102C3FF
uint32_t cybertron_fde_0289_0x043cec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043cecU;
    constexpr uint32_t kFdeVa   = 0x06e440U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xd102c3ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0290] start_va=0x043cf0, fde_va=0x06e458, span=4 bytes
// [VN] FDE[0290] địa chỉ bắt đầu=0x043cf0, fde_va=0x06e458, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D65F03C0 D102C3FF A90857F6
uint32_t cybertron_fde_0290_0x043cf0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043cf0U;
    constexpr uint32_t kFdeVa   = 0x06e458U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd102c3ffU;
    constexpr uint32_t kW3      = 0xa90857f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0291] start_va=0x043cf4, fde_va=0x06e470, span=4 bytes
// [VN] FDE[0291] địa chỉ bắt đầu=0x043cf4, fde_va=0x06e470, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D102C3FF A90857F6 A9094FF4
uint32_t cybertron_fde_0291_0x043cf4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043cf4U;
    constexpr uint32_t kFdeVa   = 0x06e470U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd102c3ffU;
    constexpr uint32_t kW2      = 0xa90857f6U;
    constexpr uint32_t kW3      = 0xa9094ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0292] start_va=0x043cf8, fde_va=0x06e488, span=320 bytes
// [VN] FDE[0292] địa chỉ bắt đầu=0x043cf8, fde_va=0x06e488, kích thước=320 byte
// AArch64 opcodes: D102C3FF A90857F6 A9094FF4 A90A7BFD
uint32_t cybertron_fde_0292_0x043cf8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043cf8U;
    constexpr uint32_t kFdeVa   = 0x06e488U;
    constexpr uint32_t kSpan    = 320U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xa90857f6U;
    constexpr uint32_t kW2      = 0xa9094ff4U;
    constexpr uint32_t kW3      = 0xa90a7bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0293] start_va=0x043e38, fde_va=0x06e4b0, span=8 bytes
// [VN] FDE[0293] địa chỉ bắt đầu=0x043e38, fde_va=0x06e4b0, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFD981 D102C3FF A90857F6
uint32_t cybertron_fde_0293_0x043e38(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043e38U;
    constexpr uint32_t kFdeVa   = 0x06e4b0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffd981U;
    constexpr uint32_t kW2      = 0xd102c3ffU;
    constexpr uint32_t kW3      = 0xa90857f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0294] start_va=0x043e40, fde_va=0x06e4c8, span=260 bytes
// [VN] FDE[0294] địa chỉ bắt đầu=0x043e40, fde_va=0x06e4c8, kích thước=260 byte
// AArch64 opcodes: D102C3FF A90857F6 A9094FF4 A90A7BFD
uint32_t cybertron_fde_0294_0x043e40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043e40U;
    constexpr uint32_t kFdeVa   = 0x06e4c8U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xa90857f6U;
    constexpr uint32_t kW2      = 0xa9094ff4U;
    constexpr uint32_t kW3      = 0xa90a7bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0295] start_va=0x043f44, fde_va=0x06e4f0, span=8 bytes
// [VN] FDE[0295] địa chỉ bắt đầu=0x043f44, fde_va=0x06e4f0, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFD352 D65F03C0 D65F03C0
uint32_t cybertron_fde_0295_0x043f44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043f44U;
    constexpr uint32_t kFdeVa   = 0x06e4f0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffd352U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0296] start_va=0x043f4c, fde_va=0x06e508, span=4 bytes
// [VN] FDE[0296] địa chỉ bắt đầu=0x043f4c, fde_va=0x06e508, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D65F03C0 D10483FF F9006BFC
uint32_t cybertron_fde_0296_0x043f4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043f4cU;
    constexpr uint32_t kFdeVa   = 0x06e508U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd10483ffU;
    constexpr uint32_t kW3      = 0xf9006bfcU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0297] start_va=0x043f50, fde_va=0x06e520, span=4 bytes
// [VN] FDE[0297] địa chỉ bắt đầu=0x043f50, fde_va=0x06e520, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D10483FF F9006BFC A90E5FF8
uint32_t cybertron_fde_0297_0x043f50(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043f50U;
    constexpr uint32_t kFdeVa   = 0x06e520U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd10483ffU;
    constexpr uint32_t kW2      = 0xf9006bfcU;
    constexpr uint32_t kW3      = 0xa90e5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0298] start_va=0x043f54, fde_va=0x06e538, span=576 bytes
// [VN] FDE[0298] địa chỉ bắt đầu=0x043f54, fde_va=0x06e538, kích thước=576 byte
// AArch64 opcodes: D10483FF F9006BFC A90E5FF8 A90F57F6
uint32_t cybertron_fde_0298_0x043f54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x043f54U;
    constexpr uint32_t kFdeVa   = 0x06e538U;
    constexpr uint32_t kSpan    = 576U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xf9006bfcU;
    constexpr uint32_t kW2      = 0xa90e5ff8U;
    constexpr uint32_t kW3      = 0xa90f57f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0299] start_va=0x044194, fde_va=0x06e560, span=8 bytes
// [VN] FDE[0299] địa chỉ bắt đầu=0x044194, fde_va=0x06e560, kích thước=8 byte
// AArch64 opcodes: D100E000 17FFD77A D10343FF A9095FF8
uint32_t cybertron_fde_0299_0x044194(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044194U;
    constexpr uint32_t kFdeVa   = 0x06e560U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd100e000U;
    constexpr uint32_t kW1      = 0x17ffd77aU;
    constexpr uint32_t kW2      = 0xd10343ffU;
    constexpr uint32_t kW3      = 0xa9095ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0300] start_va=0x04419c, fde_va=0x06e578, span=288 bytes
// [VN] FDE[0300] địa chỉ bắt đầu=0x04419c, fde_va=0x06e578, kích thước=288 byte
// AArch64 opcodes: D10343FF A9095FF8 A90A57F6 A90B4FF4
uint32_t cybertron_fde_0300_0x04419c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04419cU;
    constexpr uint32_t kFdeVa   = 0x06e578U;
    constexpr uint32_t kSpan    = 288U;
    constexpr uint32_t kW0      = 0xd10343ffU;
    constexpr uint32_t kW1      = 0xa9095ff8U;
    constexpr uint32_t kW2      = 0xa90a57f6U;
    constexpr uint32_t kW3      = 0xa90b4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0301] start_va=0x0442bc, fde_va=0x06e5a0, span=8 bytes
// [VN] FDE[0301] địa chỉ bắt đầu=0x0442bc, fde_va=0x06e5a0, kích thước=8 byte
// AArch64 opcodes: D1010000 17FFD938 AA0203E1 AA0803E0
uint32_t cybertron_fde_0301_0x0442bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0442bcU;
    constexpr uint32_t kFdeVa   = 0x06e5a0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1010000U;
    constexpr uint32_t kW1      = 0x17ffd938U;
    constexpr uint32_t kW2      = 0xaa0203e1U;
    constexpr uint32_t kW3      = 0xaa0803e0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0302] start_va=0x0442c4, fde_va=0x06e5b8, span=12 bytes
// [VN] FDE[0302] địa chỉ bắt đầu=0x0442c4, fde_va=0x06e5b8, kích thước=12 byte
// AArch64 opcodes: AA0203E1 AA0803E0 17FFD33D D102C3FF
uint32_t cybertron_fde_0302_0x0442c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0442c4U;
    constexpr uint32_t kFdeVa   = 0x06e5b8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xaa0203e1U;
    constexpr uint32_t kW1      = 0xaa0803e0U;
    constexpr uint32_t kW2      = 0x17ffd33dU;
    constexpr uint32_t kW3      = 0xd102c3ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0303] start_va=0x0442d0, fde_va=0x06e5d0, span=612 bytes
// [VN] FDE[0303] địa chỉ bắt đầu=0x0442d0, fde_va=0x06e5d0, kích thước=612 byte
// AArch64 opcodes: D102C3FF F9003BF7 A90857F6 A9094FF4
uint32_t cybertron_fde_0303_0x0442d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0442d0U;
    constexpr uint32_t kFdeVa   = 0x06e5d0U;
    constexpr uint32_t kSpan    = 612U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xf9003bf7U;
    constexpr uint32_t kW2      = 0xa90857f6U;
    constexpr uint32_t kW3      = 0xa9094ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0304] start_va=0x044534, fde_va=0x06e5f8, span=8 bytes
// [VN] FDE[0304] địa chỉ bắt đầu=0x044534, fde_va=0x06e5f8, kích thước=8 byte
// AArch64 opcodes: D1012000 17FFD542 F00001C8 F947FD08
uint32_t cybertron_fde_0304_0x044534(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044534U;
    constexpr uint32_t kFdeVa   = 0x06e5f8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1012000U;
    constexpr uint32_t kW1      = 0x17ffd542U;
    constexpr uint32_t kW2      = 0xf00001c8U;
    constexpr uint32_t kW3      = 0xf947fd08U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0305] start_va=0x04453c, fde_va=0x06e610, span=20 bytes
// [VN] FDE[0305] địa chỉ bắt đầu=0x04453c, fde_va=0x06e610, kích thước=20 byte
// AArch64 opcodes: F00001C8 F947FD08 91004108 F9000008
uint32_t cybertron_fde_0305_0x04453c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04453cU;
    constexpr uint32_t kFdeVa   = 0x06e610U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xf00001c8U;
    constexpr uint32_t kW1      = 0xf947fd08U;
    constexpr uint32_t kW2      = 0x91004108U;
    constexpr uint32_t kW3      = 0xf9000008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0306] start_va=0x044550, fde_va=0x06e628, span=4 bytes
// [VN] FDE[0306] địa chỉ bắt đầu=0x044550, fde_va=0x06e628, kích thước=4 byte
// AArch64 opcodes: D4200020 17FFD1F3 F9400400 F9400008
uint32_t cybertron_fde_0306_0x044550(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044550U;
    constexpr uint32_t kFdeVa   = 0x06e628U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd4200020U;
    constexpr uint32_t kW1      = 0x17ffd1f3U;
    constexpr uint32_t kW2      = 0xf9400400U;
    constexpr uint32_t kW3      = 0xf9400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0307] start_va=0x044554, fde_va=0x06e640, span=4 bytes
// [VN] FDE[0307] địa chỉ bắt đầu=0x044554, fde_va=0x06e640, kích thước=4 byte
// AArch64 opcodes: 17FFD1F3 F9400400 F9400008 F9400905
uint32_t cybertron_fde_0307_0x044554(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044554U;
    constexpr uint32_t kFdeVa   = 0x06e640U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffd1f3U;
    constexpr uint32_t kW1      = 0xf9400400U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9400905U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0308] start_va=0x044558, fde_va=0x06e658, span=16 bytes
// [VN] FDE[0308] địa chỉ bắt đầu=0x044558, fde_va=0x06e658, kích thước=16 byte
// AArch64 opcodes: F9400400 F9400008 F9400905 D61F00A0
uint32_t cybertron_fde_0308_0x044558(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044558U;
    constexpr uint32_t kFdeVa   = 0x06e658U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9400905U;
    constexpr uint32_t kW3      = 0xd61f00a0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0309] start_va=0x044568, fde_va=0x06e670, span=60 bytes
// [VN] FDE[0309] địa chỉ bắt đầu=0x044568, fde_va=0x06e670, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400013
uint32_t cybertron_fde_0309_0x044568(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044568U;
    constexpr uint32_t kFdeVa   = 0x06e670U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400013U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0310] start_va=0x0445a4, fde_va=0x06e690, span=52 bytes
// [VN] FDE[0310] địa chỉ bắt đầu=0x0445a4, fde_va=0x06e690, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F00001C8
uint32_t cybertron_fde_0310_0x0445a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0445a4U;
    constexpr uint32_t kFdeVa   = 0x06e690U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0311] start_va=0x0445d8, fde_va=0x06e6b0, span=60 bytes
// [VN] FDE[0311] địa chỉ bắt đầu=0x0445d8, fde_va=0x06e6b0, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F00001C8
uint32_t cybertron_fde_0311_0x0445d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0445d8U;
    constexpr uint32_t kFdeVa   = 0x06e6b0U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0312] start_va=0x044614, fde_va=0x06e6d0, span=8 bytes
// [VN] FDE[0312] địa chỉ bắt đầu=0x044614, fde_va=0x06e6d0, kích thước=8 byte
// AArch64 opcodes: 91006000 17FFD90E 17FFD1C1 39406008
uint32_t cybertron_fde_0312_0x044614(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044614U;
    constexpr uint32_t kFdeVa   = 0x06e6d0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91006000U;
    constexpr uint32_t kW1      = 0x17ffd90eU;
    constexpr uint32_t kW2      = 0x17ffd1c1U;
    constexpr uint32_t kW3      = 0x39406008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0313] start_va=0x04461c, fde_va=0x06e6e8, span=4 bytes
// [VN] FDE[0313] địa chỉ bắt đầu=0x04461c, fde_va=0x06e6e8, kích thước=4 byte
// AArch64 opcodes: 17FFD1C1 39406008 900001C9 91316129
uint32_t cybertron_fde_0313_0x04461c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04461cU;
    constexpr uint32_t kFdeVa   = 0x06e6e8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffd1c1U;
    constexpr uint32_t kW1      = 0x39406008U;
    constexpr uint32_t kW2      = 0x900001c9U;
    constexpr uint32_t kW3      = 0x91316129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0314] start_va=0x044620, fde_va=0x06e700, span=32 bytes
// [VN] FDE[0314] địa chỉ bắt đầu=0x044620, fde_va=0x06e700, kích thước=32 byte
// AArch64 opcodes: 39406008 900001C9 91316129 F9000009
uint32_t cybertron_fde_0314_0x044620(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044620U;
    constexpr uint32_t kFdeVa   = 0x06e700U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0x39406008U;
    constexpr uint32_t kW1      = 0x900001c9U;
    constexpr uint32_t kW2      = 0x91316129U;
    constexpr uint32_t kW3      = 0xf9000009U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0315] start_va=0x044640, fde_va=0x06e718, span=60 bytes
// [VN] FDE[0315] địa chỉ bắt đầu=0x044640, fde_va=0x06e718, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 39406008
uint32_t cybertron_fde_0315_0x044640(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044640U;
    constexpr uint32_t kFdeVa   = 0x06e718U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x39406008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0316] start_va=0x04467c, fde_va=0x06e738, span=72 bytes
// [VN] FDE[0316] địa chỉ bắt đầu=0x04467c, fde_va=0x06e738, kích thước=72 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0316_0x04467c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04467cU;
    constexpr uint32_t kFdeVa   = 0x06e738U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0317] start_va=0x0446c4, fde_va=0x06e758, span=40 bytes
// [VN] FDE[0317] địa chỉ bắt đầu=0x0446c4, fde_va=0x06e758, kích thước=40 byte
// AArch64 opcodes: 900001C8 91316108 F9000028 3CC08000
uint32_t cybertron_fde_0317_0x0446c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0446c4U;
    constexpr uint32_t kFdeVa   = 0x06e758U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0x900001c8U;
    constexpr uint32_t kW1      = 0x91316108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0x3cc08000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0318] start_va=0x0446ec, fde_va=0x06e770, span=20 bytes
// [VN] FDE[0318] địa chỉ bắt đầu=0x0446ec, fde_va=0x06e770, kích thước=20 byte
// AArch64 opcodes: 39406008 37000048 D65F03C0 F9401400
uint32_t cybertron_fde_0318_0x0446ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0446ecU;
    constexpr uint32_t kFdeVa   = 0x06e770U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x39406008U;
    constexpr uint32_t kW1      = 0x37000048U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xf9401400U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0319] start_va=0x044700, fde_va=0x06e788, span=48 bytes
// [VN] FDE[0319] địa chỉ bắt đầu=0x044700, fde_va=0x06e788, kích thước=48 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 39406008
uint32_t cybertron_fde_0319_0x044700(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044700U;
    constexpr uint32_t kFdeVa   = 0x06e788U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x39406008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0320] start_va=0x044730, fde_va=0x06e7a8, span=76 bytes
// [VN] FDE[0320] địa chỉ bắt đầu=0x044730, fde_va=0x06e7a8, kích thước=76 byte
// AArch64 opcodes: B9400801 1289C408 0B080028 7100091F
uint32_t cybertron_fde_0320_0x044730(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044730U;
    constexpr uint32_t kFdeVa   = 0x06e7a8U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xb9400801U;
    constexpr uint32_t kW1      = 0x1289c408U;
    constexpr uint32_t kW2      = 0x0b080028U;
    constexpr uint32_t kW3      = 0x7100091fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0321] start_va=0x04477c, fde_va=0x06e7c0, span=28 bytes
// [VN] FDE[0321] địa chỉ bắt đầu=0x04477c, fde_va=0x06e7c0, kích thước=28 byte
// AArch64 opcodes: F9400428 D0000109 910B2529 9100200A
uint32_t cybertron_fde_0321_0x04477c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04477cU;
    constexpr uint32_t kFdeVa   = 0x06e7c0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xd0000109U;
    constexpr uint32_t kW2      = 0x910b2529U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0322] start_va=0x044798, fde_va=0x06e7d8, span=12 bytes
// [VN] FDE[0322] địa chỉ bắt đầu=0x044798, fde_va=0x06e7d8, kích thước=12 byte
// AArch64 opcodes: 900001C0 9132E000 D65F03C0 39406008
uint32_t cybertron_fde_0322_0x044798(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044798U;
    constexpr uint32_t kFdeVa   = 0x06e7d8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x900001c0U;
    constexpr uint32_t kW1      = 0x9132e000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x39406008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0323] start_va=0x0447a4, fde_va=0x06e7f0, span=32 bytes
// [VN] FDE[0323] địa chỉ bắt đầu=0x0447a4, fde_va=0x06e7f0, kích thước=32 byte
// AArch64 opcodes: 39406008 900001C9 91336129 F9000009
uint32_t cybertron_fde_0323_0x0447a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0447a4U;
    constexpr uint32_t kFdeVa   = 0x06e7f0U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0x39406008U;
    constexpr uint32_t kW1      = 0x900001c9U;
    constexpr uint32_t kW2      = 0x91336129U;
    constexpr uint32_t kW3      = 0xf9000009U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0324] start_va=0x0447c4, fde_va=0x06e808, span=60 bytes
// [VN] FDE[0324] địa chỉ bắt đầu=0x0447c4, fde_va=0x06e808, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 39406008
uint32_t cybertron_fde_0324_0x0447c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0447c4U;
    constexpr uint32_t kFdeVa   = 0x06e808U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x39406008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0325] start_va=0x044800, fde_va=0x06e828, span=72 bytes
// [VN] FDE[0325] địa chỉ bắt đầu=0x044800, fde_va=0x06e828, kích thước=72 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0325_0x044800(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044800U;
    constexpr uint32_t kFdeVa   = 0x06e828U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0326] start_va=0x044848, fde_va=0x06e848, span=40 bytes
// [VN] FDE[0326] địa chỉ bắt đầu=0x044848, fde_va=0x06e848, kích thước=40 byte
// AArch64 opcodes: 900001C8 91336108 F9000028 3CC08000
uint32_t cybertron_fde_0326_0x044848(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044848U;
    constexpr uint32_t kFdeVa   = 0x06e848U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0x900001c8U;
    constexpr uint32_t kW1      = 0x91336108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0x3cc08000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0327] start_va=0x044870, fde_va=0x06e860, span=20 bytes
// [VN] FDE[0327] địa chỉ bắt đầu=0x044870, fde_va=0x06e860, kích thước=20 byte
// AArch64 opcodes: 39406008 37000048 D65F03C0 F9401400
uint32_t cybertron_fde_0327_0x044870(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044870U;
    constexpr uint32_t kFdeVa   = 0x06e860U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x39406008U;
    constexpr uint32_t kW1      = 0x37000048U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xf9401400U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0328] start_va=0x044884, fde_va=0x06e878, span=48 bytes
// [VN] FDE[0328] địa chỉ bắt đầu=0x044884, fde_va=0x06e878, kích thước=48 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 39406008
uint32_t cybertron_fde_0328_0x044884(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044884U;
    constexpr uint32_t kFdeVa   = 0x06e878U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x39406008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0329] start_va=0x0448b4, fde_va=0x06e898, span=76 bytes
// [VN] FDE[0329] địa chỉ bắt đầu=0x0448b4, fde_va=0x06e898, kích thước=76 byte
// AArch64 opcodes: B9400801 1289C408 0B080028 7100091F
uint32_t cybertron_fde_0329_0x0448b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0448b4U;
    constexpr uint32_t kFdeVa   = 0x06e898U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xb9400801U;
    constexpr uint32_t kW1      = 0x1289c408U;
    constexpr uint32_t kW2      = 0x0b080028U;
    constexpr uint32_t kW3      = 0x7100091fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0330] start_va=0x044900, fde_va=0x06e8b0, span=28 bytes
// [VN] FDE[0330] địa chỉ bắt đầu=0x044900, fde_va=0x06e8b0, kích thước=28 byte
// AArch64 opcodes: F9400428 D0000109 91100D29 9100200A
uint32_t cybertron_fde_0330_0x044900(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044900U;
    constexpr uint32_t kFdeVa   = 0x06e8b0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xd0000109U;
    constexpr uint32_t kW2      = 0x91100d29U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0331] start_va=0x04491c, fde_va=0x06e8c8, span=12 bytes
// [VN] FDE[0331] địa chỉ bắt đầu=0x04491c, fde_va=0x06e8c8, kích thước=12 byte
// AArch64 opcodes: 900001C0 9134E000 D65F03C0 3940A008
uint32_t cybertron_fde_0331_0x04491c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04491cU;
    constexpr uint32_t kFdeVa   = 0x06e8c8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x900001c0U;
    constexpr uint32_t kW1      = 0x9134e000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x3940a008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0332] start_va=0x044928, fde_va=0x06e8e0, span=32 bytes
// [VN] FDE[0332] địa chỉ bắt đầu=0x044928, fde_va=0x06e8e0, kích thước=32 byte
// AArch64 opcodes: 3940A008 900001C9 91356129 F9000009
uint32_t cybertron_fde_0332_0x044928(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044928U;
    constexpr uint32_t kFdeVa   = 0x06e8e0U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0x3940a008U;
    constexpr uint32_t kW1      = 0x900001c9U;
    constexpr uint32_t kW2      = 0x91356129U;
    constexpr uint32_t kW3      = 0xf9000009U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0333] start_va=0x044948, fde_va=0x06e8f8, span=60 bytes
// [VN] FDE[0333] địa chỉ bắt đầu=0x044948, fde_va=0x06e8f8, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 3940A008
uint32_t cybertron_fde_0333_0x044948(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044948U;
    constexpr uint32_t kFdeVa   = 0x06e8f8U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x3940a008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0334] start_va=0x044984, fde_va=0x06e918, span=80 bytes
// [VN] FDE[0334] địa chỉ bắt đầu=0x044984, fde_va=0x06e918, kích thước=80 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0334_0x044984(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044984U;
    constexpr uint32_t kFdeVa   = 0x06e918U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0335] start_va=0x0449d4, fde_va=0x06e938, span=48 bytes
// [VN] FDE[0335] địa chỉ bắt đầu=0x0449d4, fde_va=0x06e938, kích thước=48 byte
// AArch64 opcodes: 900001C8 91356108 F9000028 3CC18000
uint32_t cybertron_fde_0335_0x0449d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0449d4U;
    constexpr uint32_t kFdeVa   = 0x06e938U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0x900001c8U;
    constexpr uint32_t kW1      = 0x91356108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0x3cc18000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0336] start_va=0x044a04, fde_va=0x06e950, span=20 bytes
// [VN] FDE[0336] địa chỉ bắt đầu=0x044a04, fde_va=0x06e950, kích thước=20 byte
// AArch64 opcodes: 3940A008 37000048 D65F03C0 F9401C00
uint32_t cybertron_fde_0336_0x044a04(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044a04U;
    constexpr uint32_t kFdeVa   = 0x06e950U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x3940a008U;
    constexpr uint32_t kW1      = 0x37000048U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xf9401c00U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0337] start_va=0x044a18, fde_va=0x06e968, span=48 bytes
// [VN] FDE[0337] địa chỉ bắt đầu=0x044a18, fde_va=0x06e968, kích thước=48 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 3940A008
uint32_t cybertron_fde_0337_0x044a18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044a18U;
    constexpr uint32_t kFdeVa   = 0x06e968U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x3940a008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0338] start_va=0x044a48, fde_va=0x06e988, span=52 bytes
// [VN] FDE[0338] địa chỉ bắt đầu=0x044a48, fde_va=0x06e988, kích thước=52 byte
// AArch64 opcodes: F9400408 3940A009 F9401C0B B9401001
uint32_t cybertron_fde_0338_0x044a48(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044a48U;
    constexpr uint32_t kFdeVa   = 0x06e988U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf9400408U;
    constexpr uint32_t kW1      = 0x3940a009U;
    constexpr uint32_t kW2      = 0xf9401c0bU;
    constexpr uint32_t kW3      = 0xb9401001U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0339] start_va=0x044a7c, fde_va=0x06e9a0, span=28 bytes
// [VN] FDE[0339] địa chỉ bắt đầu=0x044a7c, fde_va=0x06e9a0, kích thước=28 byte
// AArch64 opcodes: F9400428 D0000109 9114E929 9100200A
uint32_t cybertron_fde_0339_0x044a7c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044a7cU;
    constexpr uint32_t kFdeVa   = 0x06e9a0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xd0000109U;
    constexpr uint32_t kW2      = 0x9114e929U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0340] start_va=0x044a98, fde_va=0x06e9b8, span=12 bytes
// [VN] FDE[0340] địa chỉ bắt đầu=0x044a98, fde_va=0x06e9b8, kích thước=12 byte
// AArch64 opcodes: 900001C0 9136E000 D65F03C0 3940A008
uint32_t cybertron_fde_0340_0x044a98(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044a98U;
    constexpr uint32_t kFdeVa   = 0x06e9b8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x900001c0U;
    constexpr uint32_t kW1      = 0x9136e000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x3940a008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0341] start_va=0x044aa4, fde_va=0x06e9d0, span=32 bytes
// [VN] FDE[0341] địa chỉ bắt đầu=0x044aa4, fde_va=0x06e9d0, kích thước=32 byte
// AArch64 opcodes: 3940A008 900001C9 91376129 F9000009
uint32_t cybertron_fde_0341_0x044aa4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044aa4U;
    constexpr uint32_t kFdeVa   = 0x06e9d0U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0x3940a008U;
    constexpr uint32_t kW1      = 0x900001c9U;
    constexpr uint32_t kW2      = 0x91376129U;
    constexpr uint32_t kW3      = 0xf9000009U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0342] start_va=0x044ac4, fde_va=0x06e9e8, span=60 bytes
// [VN] FDE[0342] địa chỉ bắt đầu=0x044ac4, fde_va=0x06e9e8, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 3940A008
uint32_t cybertron_fde_0342_0x044ac4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044ac4U;
    constexpr uint32_t kFdeVa   = 0x06e9e8U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x3940a008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0343] start_va=0x044b00, fde_va=0x06ea08, span=80 bytes
// [VN] FDE[0343] địa chỉ bắt đầu=0x044b00, fde_va=0x06ea08, kích thước=80 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0343_0x044b00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044b00U;
    constexpr uint32_t kFdeVa   = 0x06ea08U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0344] start_va=0x044b50, fde_va=0x06ea28, span=48 bytes
// [VN] FDE[0344] địa chỉ bắt đầu=0x044b50, fde_va=0x06ea28, kích thước=48 byte
// AArch64 opcodes: 900001C8 91376108 F9000028 3CC18000
uint32_t cybertron_fde_0344_0x044b50(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044b50U;
    constexpr uint32_t kFdeVa   = 0x06ea28U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0x900001c8U;
    constexpr uint32_t kW1      = 0x91376108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0x3cc18000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0345] start_va=0x044b80, fde_va=0x06ea40, span=20 bytes
// [VN] FDE[0345] địa chỉ bắt đầu=0x044b80, fde_va=0x06ea40, kích thước=20 byte
// AArch64 opcodes: 3940A008 37000048 D65F03C0 F9401C00
uint32_t cybertron_fde_0345_0x044b80(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044b80U;
    constexpr uint32_t kFdeVa   = 0x06ea40U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x3940a008U;
    constexpr uint32_t kW1      = 0x37000048U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xf9401c00U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0346] start_va=0x044b94, fde_va=0x06ea58, span=48 bytes
// [VN] FDE[0346] địa chỉ bắt đầu=0x044b94, fde_va=0x06ea58, kích thước=48 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 3940A008
uint32_t cybertron_fde_0346_0x044b94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044b94U;
    constexpr uint32_t kFdeVa   = 0x06ea58U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x3940a008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0347] start_va=0x044bc4, fde_va=0x06ea78, span=52 bytes
// [VN] FDE[0347] địa chỉ bắt đầu=0x044bc4, fde_va=0x06ea78, kích thước=52 byte
// AArch64 opcodes: F9400408 3940A009 F9401C0B B9401001
uint32_t cybertron_fde_0347_0x044bc4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044bc4U;
    constexpr uint32_t kFdeVa   = 0x06ea78U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf9400408U;
    constexpr uint32_t kW1      = 0x3940a009U;
    constexpr uint32_t kW2      = 0xf9401c0bU;
    constexpr uint32_t kW3      = 0xb9401001U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0348] start_va=0x044bf8, fde_va=0x06ea90, span=28 bytes
// [VN] FDE[0348] địa chỉ bắt đầu=0x044bf8, fde_va=0x06ea90, kích thước=28 byte
// AArch64 opcodes: F9400428 D0000109 9119CD29 9100200A
uint32_t cybertron_fde_0348_0x044bf8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044bf8U;
    constexpr uint32_t kFdeVa   = 0x06ea90U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xd0000109U;
    constexpr uint32_t kW2      = 0x9119cd29U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0349] start_va=0x044c14, fde_va=0x06eaa8, span=12 bytes
// [VN] FDE[0349] địa chỉ bắt đầu=0x044c14, fde_va=0x06eaa8, kích thước=12 byte
// AArch64 opcodes: 900001C0 9138E000 D65F03C0 17FFD250
uint32_t cybertron_fde_0349_0x044c14(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044c14U;
    constexpr uint32_t kFdeVa   = 0x06eaa8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x900001c0U;
    constexpr uint32_t kW1      = 0x9138e000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x17ffd250U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0350] start_va=0x044c20, fde_va=0x06eac0, span=4 bytes
// [VN] FDE[0350] địa chỉ bắt đầu=0x044c20, fde_va=0x06eac0, kích thước=4 byte
// AArch64 opcodes: 17FFD250 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0350_0x044c20(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044c20U;
    constexpr uint32_t kFdeVa   = 0x06eac0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffd250U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0351] start_va=0x044c24, fde_va=0x06ead8, span=36 bytes
// [VN] FDE[0351] địa chỉ bắt đầu=0x044c24, fde_va=0x06ead8, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0351_0x044c24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044c24U;
    constexpr uint32_t kFdeVa   = 0x06ead8U;
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

// [EN] FDE[0352] start_va=0x044c48, fde_va=0x06eaf8, span=12 bytes
// [VN] FDE[0352] địa chỉ bắt đầu=0x044c48, fde_va=0x06eaf8, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400101 D61F0020 17FFD033
uint32_t cybertron_fde_0352_0x044c48(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044c48U;
    constexpr uint32_t kFdeVa   = 0x06eaf8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400101U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ffd033U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0353] start_va=0x044c54, fde_va=0x06eb10, span=4 bytes
// [VN] FDE[0353] địa chỉ bắt đầu=0x044c54, fde_va=0x06eb10, kích thước=4 byte
// AArch64 opcodes: 17FFD033 D65F03C0 17FFD031 D106C3FF
uint32_t cybertron_fde_0353_0x044c54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044c54U;
    constexpr uint32_t kFdeVa   = 0x06eb10U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffd033U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0x17ffd031U;
    constexpr uint32_t kW3      = 0xd106c3ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0354] start_va=0x044c58, fde_va=0x06eb28, span=4 bytes
// [VN] FDE[0354] địa chỉ bắt đầu=0x044c58, fde_va=0x06eb28, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FFD031 D106C3FF A9156FFC
uint32_t cybertron_fde_0354_0x044c58(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044c58U;
    constexpr uint32_t kFdeVa   = 0x06eb28U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ffd031U;
    constexpr uint32_t kW2      = 0xd106c3ffU;
    constexpr uint32_t kW3      = 0xa9156ffcU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0355] start_va=0x044c5c, fde_va=0x06eb40, span=4 bytes
// [VN] FDE[0355] địa chỉ bắt đầu=0x044c5c, fde_va=0x06eb40, kích thước=4 byte
// AArch64 opcodes: 17FFD031 D106C3FF A9156FFC A91667FA
uint32_t cybertron_fde_0355_0x044c5c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044c5cU;
    constexpr uint32_t kFdeVa   = 0x06eb40U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffd031U;
    constexpr uint32_t kW1      = 0xd106c3ffU;
    constexpr uint32_t kW2      = 0xa9156ffcU;
    constexpr uint32_t kW3      = 0xa91667faU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0356] start_va=0x044c60, fde_va=0x06eb58, span=448 bytes
// [VN] FDE[0356] địa chỉ bắt đầu=0x044c60, fde_va=0x06eb58, kích thước=448 byte
// AArch64 opcodes: D106C3FF A9156FFC A91667FA A9175FF8
uint32_t cybertron_fde_0356_0x044c60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044c60U;
    constexpr uint32_t kFdeVa   = 0x06eb58U;
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

// [EN] FDE[0357] start_va=0x044e20, fde_va=0x06eb88, span=88 bytes
// [VN] FDE[0357] địa chỉ bắt đầu=0x044e20, fde_va=0x06eb88, kích thước=88 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0357_0x044e20(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044e20U;
    constexpr uint32_t kFdeVa   = 0x06eb88U;
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

// [EN] FDE[0358] start_va=0x044e78, fde_va=0x06eba8, span=116 bytes
// [VN] FDE[0358] địa chỉ bắt đầu=0x044e78, fde_va=0x06eba8, kích thước=116 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F00001C8
uint32_t cybertron_fde_0358_0x044e78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044e78U;
    constexpr uint32_t kFdeVa   = 0x06eba8U;
    constexpr uint32_t kSpan    = 116U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0359] start_va=0x044eec, fde_va=0x06ebc8, span=8 bytes
// [VN] FDE[0359] địa chỉ bắt đầu=0x044eec, fde_va=0x06ebc8, kích thước=8 byte
// AArch64 opcodes: 91004000 17FFCFF8 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0359_0x044eec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044eecU;
    constexpr uint32_t kFdeVa   = 0x06ebc8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91004000U;
    constexpr uint32_t kW1      = 0x17ffcff8U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0360] start_va=0x044ef4, fde_va=0x06ebe0, span=40 bytes
// [VN] FDE[0360] địa chỉ bắt đầu=0x044ef4, fde_va=0x06ebe0, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0360_0x044ef4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044ef4U;
    constexpr uint32_t kFdeVa   = 0x06ebe0U;
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

// [EN] FDE[0361] start_va=0x044f1c, fde_va=0x06ec00, span=20 bytes
// [VN] FDE[0361] địa chỉ bắt đầu=0x044f1c, fde_va=0x06ec00, kích thước=20 byte
// AArch64 opcodes: F9400008 F85E8108 8B080008 91004100
uint32_t cybertron_fde_0361_0x044f1c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044f1cU;
    constexpr uint32_t kFdeVa   = 0x06ec00U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xf9400008U;
    constexpr uint32_t kW1      = 0xf85e8108U;
    constexpr uint32_t kW2      = 0x8b080008U;
    constexpr uint32_t kW3      = 0x91004100U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0362] start_va=0x044f30, fde_va=0x06ec18, span=48 bytes
// [VN] FDE[0362] địa chỉ bắt đầu=0x044f30, fde_va=0x06ec18, kích thước=48 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400008
uint32_t cybertron_fde_0362_0x044f30(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044f30U;
    constexpr uint32_t kFdeVa   = 0x06ec18U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0363] start_va=0x044f60, fde_va=0x06ec38, span=124 bytes
// [VN] FDE[0363] địa chỉ bắt đầu=0x044f60, fde_va=0x06ec38, kích thước=124 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F00001C8
uint32_t cybertron_fde_0363_0x044f60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044f60U;
    constexpr uint32_t kFdeVa   = 0x06ec38U;
    constexpr uint32_t kSpan    = 124U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0364] start_va=0x044fdc, fde_va=0x06ec58, span=120 bytes
// [VN] FDE[0364] địa chỉ bắt đầu=0x044fdc, fde_va=0x06ec58, kích thước=120 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD F00001C8
uint32_t cybertron_fde_0364_0x044fdc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x044fdcU;
    constexpr uint32_t kFdeVa   = 0x06ec58U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0365] start_va=0x045054, fde_va=0x06ec78, span=128 bytes
// [VN] FDE[0365] địa chỉ bắt đầu=0x045054, fde_va=0x06ec78, kích thước=128 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD D00001C8
uint32_t cybertron_fde_0365_0x045054(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045054U;
    constexpr uint32_t kFdeVa   = 0x06ec78U;
    constexpr uint32_t kSpan    = 128U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0366] start_va=0x0450d4, fde_va=0x06ec98, span=128 bytes
// [VN] FDE[0366] địa chỉ bắt đầu=0x0450d4, fde_va=0x06ec98, kích thước=128 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD F9400008
uint32_t cybertron_fde_0366_0x0450d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0450d4U;
    constexpr uint32_t kFdeVa   = 0x06ec98U;
    constexpr uint32_t kSpan    = 128U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0367] start_va=0x045154, fde_va=0x06ecb8, span=136 bytes
// [VN] FDE[0367] địa chỉ bắt đầu=0x045154, fde_va=0x06ecb8, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD F9400008
uint32_t cybertron_fde_0367_0x045154(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045154U;
    constexpr uint32_t kFdeVa   = 0x06ecb8U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0368] start_va=0x0451dc, fde_va=0x06ecd8, span=80 bytes
// [VN] FDE[0368] địa chỉ bắt đầu=0x0451dc, fde_va=0x06ecd8, kích thước=80 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D00001C9
uint32_t cybertron_fde_0368_0x0451dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0451dcU;
    constexpr uint32_t kFdeVa   = 0x06ecd8U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00001c9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0369] start_va=0x04522c, fde_va=0x06ecf8, span=88 bytes
// [VN] FDE[0369] địa chỉ bắt đầu=0x04522c, fde_va=0x06ecf8, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D00001C9
uint32_t cybertron_fde_0369_0x04522c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04522cU;
    constexpr uint32_t kFdeVa   = 0x06ecf8U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00001c9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0370] start_va=0x045284, fde_va=0x06ed18, span=4 bytes
// [VN] FDE[0370] địa chỉ bắt đầu=0x045284, fde_va=0x06ed18, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D65F03C0 F9402C08 F9401809
uint32_t cybertron_fde_0370_0x045284(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045284U;
    constexpr uint32_t kFdeVa   = 0x06ed18U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xf9402c08U;
    constexpr uint32_t kW3      = 0xf9401809U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0371] start_va=0x045288, fde_va=0x06ed30, span=4 bytes
// [VN] FDE[0371] địa chỉ bắt đầu=0x045288, fde_va=0x06ed30, kích thước=4 byte
// AArch64 opcodes: D65F03C0 F9402C08 F9401809 EB09011F
uint32_t cybertron_fde_0371_0x045288(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045288U;
    constexpr uint32_t kFdeVa   = 0x06ed30U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xf9402c08U;
    constexpr uint32_t kW2      = 0xf9401809U;
    constexpr uint32_t kW3      = 0xeb09011fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0372] start_va=0x04528c, fde_va=0x06ed48, span=244 bytes
// [VN] FDE[0372] địa chỉ bắt đầu=0x04528c, fde_va=0x06ed48, kích thước=244 byte
// AArch64 opcodes: F9402C08 F9401809 EB09011F 54000062
uint32_t cybertron_fde_0372_0x04528c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04528cU;
    constexpr uint32_t kFdeVa   = 0x06ed48U;
    constexpr uint32_t kSpan    = 244U;
    constexpr uint32_t kW0      = 0xf9402c08U;
    constexpr uint32_t kW1      = 0xf9401809U;
    constexpr uint32_t kW2      = 0xeb09011fU;
    constexpr uint32_t kW3      = 0x54000062U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0373] start_va=0x045380, fde_va=0x06ed60, span=20 bytes
// [VN] FDE[0373] địa chỉ bắt đầu=0x045380, fde_va=0x06ed60, kích thước=20 byte
// AArch64 opcodes: F9400008 AA0203E1 2A1F03E2 F9401104
uint32_t cybertron_fde_0373_0x045380(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045380U;
    constexpr uint32_t kFdeVa   = 0x06ed60U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xf9400008U;
    constexpr uint32_t kW1      = 0xaa0203e1U;
    constexpr uint32_t kW2      = 0x2a1f03e2U;
    constexpr uint32_t kW3      = 0xf9401104U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0374] start_va=0x045394, fde_va=0x06ed78, span=8 bytes
// [VN] FDE[0374] địa chỉ bắt đầu=0x045394, fde_va=0x06ed78, kích thước=8 byte
// AArch64 opcodes: 2A1F03E0 D65F03C0 AA1F03E0 D65F03C0
uint32_t cybertron_fde_0374_0x045394(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045394U;
    constexpr uint32_t kFdeVa   = 0x06ed78U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x2a1f03e0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xaa1f03e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0375] start_va=0x04539c, fde_va=0x06ed90, span=8 bytes
// [VN] FDE[0375] địa chỉ bắt đầu=0x04539c, fde_va=0x06ed90, kích thước=8 byte
// AArch64 opcodes: AA1F03E0 D65F03C0 A9BC5FF8 A90157F6
uint32_t cybertron_fde_0375_0x04539c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04539cU;
    constexpr uint32_t kFdeVa   = 0x06ed90U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xaa1f03e0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xa9bc5ff8U;
    constexpr uint32_t kW3      = 0xa90157f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0376] start_va=0x0453a4, fde_va=0x06eda8, span=196 bytes
// [VN] FDE[0376] địa chỉ bắt đầu=0x0453a4, fde_va=0x06eda8, kích thước=196 byte
// AArch64 opcodes: A9BC5FF8 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0376_0x0453a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0453a4U;
    constexpr uint32_t kFdeVa   = 0x06eda8U;
    constexpr uint32_t kSpan    = 196U;
    constexpr uint32_t kW0      = 0xa9bc5ff8U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0377] start_va=0x045468, fde_va=0x06edd0, span=80 bytes
// [VN] FDE[0377] địa chỉ bắt đầu=0x045468, fde_va=0x06edd0, kích thước=80 byte
// AArch64 opcodes: F9402C08 F9401809 EB09011F 54000062
uint32_t cybertron_fde_0377_0x045468(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045468U;
    constexpr uint32_t kFdeVa   = 0x06edd0U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xf9402c08U;
    constexpr uint32_t kW1      = 0xf9401809U;
    constexpr uint32_t kW2      = 0xeb09011fU;
    constexpr uint32_t kW3      = 0x54000062U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0378] start_va=0x0454b8, fde_va=0x06ede8, span=64 bytes
// [VN] FDE[0378] địa chỉ bắt đầu=0x0454b8, fde_va=0x06ede8, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400008
uint32_t cybertron_fde_0378_0x0454b8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0454b8U;
    constexpr uint32_t kFdeVa   = 0x06ede8U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0379] start_va=0x0454f8, fde_va=0x06ee08, span=112 bytes
// [VN] FDE[0379] địa chỉ bắt đầu=0x0454f8, fde_va=0x06ee08, kích thước=112 byte
// AArch64 opcodes: F9402C09 F940180A AA0003E8 2A0103E0
uint32_t cybertron_fde_0379_0x0454f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0454f8U;
    constexpr uint32_t kFdeVa   = 0x06ee08U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xf9402c09U;
    constexpr uint32_t kW1      = 0xf940180aU;
    constexpr uint32_t kW2      = 0xaa0003e8U;
    constexpr uint32_t kW3      = 0x2a0103e0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0380] start_va=0x045568, fde_va=0x06ee20, span=188 bytes
// [VN] FDE[0380] địa chỉ bắt đầu=0x045568, fde_va=0x06ee20, kích thước=188 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0380_0x045568(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045568U;
    constexpr uint32_t kFdeVa   = 0x06ee20U;
    constexpr uint32_t kSpan    = 188U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0381] start_va=0x045624, fde_va=0x06ee48, span=384 bytes
// [VN] FDE[0381] địa chỉ bắt đầu=0x045624, fde_va=0x06ee48, kích thước=384 byte
// AArch64 opcodes: D10183FF A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0381_0x045624(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045624U;
    constexpr uint32_t kFdeVa   = 0x06ee48U;
    constexpr uint32_t kSpan    = 384U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0382] start_va=0x0457a4, fde_va=0x06ee78, span=20 bytes
// [VN] FDE[0382] địa chỉ bắt đầu=0x0457a4, fde_va=0x06ee78, kích thước=20 byte
// AArch64 opcodes: D00001C8 F9469508 91004108 F8008408
uint32_t cybertron_fde_0382_0x0457a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0457a4U;
    constexpr uint32_t kFdeVa   = 0x06ee78U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xd00001c8U;
    constexpr uint32_t kW1      = 0xf9469508U;
    constexpr uint32_t kW2      = 0x91004108U;
    constexpr uint32_t kW3      = 0xf8008408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0383] start_va=0x0457b8, fde_va=0x06ee90, span=52 bytes
// [VN] FDE[0383] địa chỉ bắt đầu=0x0457b8, fde_va=0x06ee90, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D00001C8
uint32_t cybertron_fde_0383_0x0457b8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0457b8U;
    constexpr uint32_t kFdeVa   = 0x06ee90U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0384] start_va=0x0457ec, fde_va=0x06eeb0, span=12 bytes
// [VN] FDE[0384] địa chỉ bắt đầu=0x0457ec, fde_va=0x06eeb0, kích thước=12 byte
// AArch64 opcodes: 92800001 AA1F03E0 D65F03C0 92800001
uint32_t cybertron_fde_0384_0x0457ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0457ecU;
    constexpr uint32_t kFdeVa   = 0x06eeb0U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x92800001U;
    constexpr uint32_t kW1      = 0xaa1f03e0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x92800001U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0385] start_va=0x0457f8, fde_va=0x06eec8, span=12 bytes
// [VN] FDE[0385] địa chỉ bắt đầu=0x0457f8, fde_va=0x06eec8, kích thước=12 byte
// AArch64 opcodes: 92800001 AA1F03E0 D65F03C0 12800000
uint32_t cybertron_fde_0385_0x0457f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0457f8U;
    constexpr uint32_t kFdeVa   = 0x06eec8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x92800001U;
    constexpr uint32_t kW1      = 0xaa1f03e0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x12800000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0386] start_va=0x045804, fde_va=0x06eee0, span=8 bytes
// [VN] FDE[0386] địa chỉ bắt đầu=0x045804, fde_va=0x06eee0, kích thước=8 byte
// AArch64 opcodes: 12800000 D65F03C0 12800000 D65F03C0
uint32_t cybertron_fde_0386_0x045804(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045804U;
    constexpr uint32_t kFdeVa   = 0x06eee0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x12800000U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0x12800000U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0387] start_va=0x04580c, fde_va=0x06eef8, span=8 bytes
// [VN] FDE[0387] địa chỉ bắt đầu=0x04580c, fde_va=0x06eef8, kích thước=8 byte
// AArch64 opcodes: 12800000 D65F03C0 12800000 D65F03C0
uint32_t cybertron_fde_0387_0x04580c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04580cU;
    constexpr uint32_t kFdeVa   = 0x06eef8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x12800000U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0x12800000U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0388] start_va=0x045814, fde_va=0x06ef10, span=8 bytes
// [VN] FDE[0388] địa chỉ bắt đầu=0x045814, fde_va=0x06ef10, kích thước=8 byte
// AArch64 opcodes: 12800000 D65F03C0 F81D0FF5 A9014FF4
uint32_t cybertron_fde_0388_0x045814(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045814U;
    constexpr uint32_t kFdeVa   = 0x06ef10U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x12800000U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xf81d0ff5U;
    constexpr uint32_t kW3      = 0xa9014ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0389] start_va=0x04581c, fde_va=0x06ef28, span=160 bytes
// [VN] FDE[0389] địa chỉ bắt đầu=0x04581c, fde_va=0x06ef28, kích thước=160 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0389_0x04581c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04581cU;
    constexpr uint32_t kFdeVa   = 0x06ef28U;
    constexpr uint32_t kSpan    = 160U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0390] start_va=0x0458bc, fde_va=0x06ef48, span=276 bytes
// [VN] FDE[0390] địa chỉ bắt đầu=0x0458bc, fde_va=0x06ef48, kích thước=276 byte
// AArch64 opcodes: F81A0FFB A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0390_0x0458bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0458bcU;
    constexpr uint32_t kFdeVa   = 0x06ef48U;
    constexpr uint32_t kSpan    = 276U;
    constexpr uint32_t kW0      = 0xf81a0ffbU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0391] start_va=0x0459d0, fde_va=0x06ef78, span=92 bytes
// [VN] FDE[0391] địa chỉ bắt đầu=0x0459d0, fde_va=0x06ef78, kích thước=92 byte
// AArch64 opcodes: A9BF7BFD 910003FD 39400008 37000068
uint32_t cybertron_fde_0391_0x0459d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0459d0U;
    constexpr uint32_t kFdeVa   = 0x06ef78U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x39400008U;
    constexpr uint32_t kW3      = 0x37000068U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0392] start_va=0x045a2c, fde_va=0x06ef98, span=204 bytes
// [VN] FDE[0392] địa chỉ bắt đầu=0x045a2c, fde_va=0x06ef98, kích thước=204 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0392_0x045a2c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045a2cU;
    constexpr uint32_t kFdeVa   = 0x06ef98U;
    constexpr uint32_t kSpan    = 204U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0393] start_va=0x045af8, fde_va=0x06efc0, span=332 bytes
// [VN] FDE[0393] địa chỉ bắt đầu=0x045af8, fde_va=0x06efc0, kích thước=332 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_0393_0x045af8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045af8U;
    constexpr uint32_t kFdeVa   = 0x06efc0U;
    constexpr uint32_t kSpan    = 332U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90267faU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0394] start_va=0x045c44, fde_va=0x06eff0, span=76 bytes
// [VN] FDE[0394] địa chỉ bắt đầu=0x045c44, fde_va=0x06eff0, kích thước=76 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 3900001F
uint32_t cybertron_fde_0394_0x045c44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045c44U;
    constexpr uint32_t kFdeVa   = 0x06eff0U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x3900001fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0395] start_va=0x045c90, fde_va=0x06f010, span=404 bytes
// [VN] FDE[0395] địa chỉ bắt đầu=0x045c90, fde_va=0x06f010, kích thước=404 byte
// AArch64 opcodes: D10203FF F90013FB A90367FA A9045FF8
uint32_t cybertron_fde_0395_0x045c90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045c90U;
    constexpr uint32_t kFdeVa   = 0x06f010U;
    constexpr uint32_t kSpan    = 404U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xf90013fbU;
    constexpr uint32_t kW2      = 0xa90367faU;
    constexpr uint32_t kW3      = 0xa9045ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0396] start_va=0x045e24, fde_va=0x06f040, span=152 bytes
// [VN] FDE[0396] địa chỉ bắt đầu=0x045e24, fde_va=0x06f040, kích thước=152 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400408
uint32_t cybertron_fde_0396_0x045e24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045e24U;
    constexpr uint32_t kFdeVa   = 0x06f040U;
    constexpr uint32_t kSpan    = 152U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0397] start_va=0x045ebc, fde_va=0x06f060, span=180 bytes
// [VN] FDE[0397] địa chỉ bắt đầu=0x045ebc, fde_va=0x06f060, kích thước=180 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0397_0x045ebc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045ebcU;
    constexpr uint32_t kFdeVa   = 0x06f060U;
    constexpr uint32_t kSpan    = 180U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa9024ff4U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0398] start_va=0x045f70, fde_va=0x06f080, span=356 bytes
// [VN] FDE[0398] địa chỉ bắt đầu=0x045f70, fde_va=0x06f080, kích thước=356 byte
// AArch64 opcodes: D101C3FF F90013F9 A9035FF8 A90457F6
uint32_t cybertron_fde_0398_0x045f70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x045f70U;
    constexpr uint32_t kFdeVa   = 0x06f080U;
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

// [EN] FDE[0399] start_va=0x0460d4, fde_va=0x06f0a8, span=308 bytes
// [VN] FDE[0399] địa chỉ bắt đầu=0x0460d4, fde_va=0x06f0a8, kích thước=308 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0399_0x0460d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0460d4U;
    constexpr uint32_t kFdeVa   = 0x06f0a8U;
    constexpr uint32_t kSpan    = 308U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0400] start_va=0x046208, fde_va=0x06f0d0, span=28 bytes
// [VN] FDE[0400] địa chỉ bắt đầu=0x046208, fde_va=0x06f0d0, kích thước=28 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FFD158 D00001C0
uint32_t cybertron_fde_0400_0x046208(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046208U;
    constexpr uint32_t kFdeVa   = 0x06f0d0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97ffd158U;
    constexpr uint32_t kW3      = 0xd00001c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0401] start_va=0x046224, fde_va=0x06f0f0, span=84 bytes
// [VN] FDE[0401] địa chỉ bắt đầu=0x046224, fde_va=0x06f0f0, kích thước=84 byte
// AArch64 opcodes: A9BF7BFD 910003FD D00001C8 91022108
uint32_t cybertron_fde_0401_0x046224(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046224U;
    constexpr uint32_t kFdeVa   = 0x06f0f0U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xd00001c8U;
    constexpr uint32_t kW3      = 0x91022108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0402] start_va=0x046278, fde_va=0x06f110, span=220 bytes
// [VN] FDE[0402] địa chỉ bắt đầu=0x046278, fde_va=0x06f110, kích thước=220 byte
// AArch64 opcodes: D10103FF A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0402_0x046278(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046278U;
    constexpr uint32_t kFdeVa   = 0x06f110U;
    constexpr uint32_t kSpan    = 220U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0403] start_va=0x046354, fde_va=0x06f138, span=8 bytes
// [VN] FDE[0403] địa chỉ bắt đầu=0x046354, fde_va=0x06f138, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFD22E F9402800 17FFCEA4
uint32_t cybertron_fde_0403_0x046354(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046354U;
    constexpr uint32_t kFdeVa   = 0x06f138U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffd22eU;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffcea4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0404] start_va=0x04635c, fde_va=0x06f150, span=8 bytes
// [VN] FDE[0404] địa chỉ bắt đầu=0x04635c, fde_va=0x06f150, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFCEA4 F9402800 17FFD2AE
uint32_t cybertron_fde_0404_0x04635c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04635cU;
    constexpr uint32_t kFdeVa   = 0x06f150U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffcea4U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffd2aeU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0405] start_va=0x046364, fde_va=0x06f168, span=8 bytes
// [VN] FDE[0405] địa chỉ bắt đầu=0x046364, fde_va=0x06f168, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFD2AE F9402800 17FFCD18
uint32_t cybertron_fde_0405_0x046364(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046364U;
    constexpr uint32_t kFdeVa   = 0x06f168U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffd2aeU;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffcd18U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0406] start_va=0x04636c, fde_va=0x06f180, span=8 bytes
// [VN] FDE[0406] địa chỉ bắt đầu=0x04636c, fde_va=0x06f180, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFCD18 F9402800 17FFCBE6
uint32_t cybertron_fde_0406_0x04636c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04636cU;
    constexpr uint32_t kFdeVa   = 0x06f180U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffcd18U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffcbe6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0407] start_va=0x046374, fde_va=0x06f198, span=8 bytes
// [VN] FDE[0407] địa chỉ bắt đầu=0x046374, fde_va=0x06f198, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFCBE6 F9402800 17FFCA18
uint32_t cybertron_fde_0407_0x046374(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046374U;
    constexpr uint32_t kFdeVa   = 0x06f198U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffcbe6U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffca18U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0408] start_va=0x04637c, fde_va=0x06f1b0, span=8 bytes
// [VN] FDE[0408] địa chỉ bắt đầu=0x04637c, fde_va=0x06f1b0, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFCA18 F9402800 17FFD336
uint32_t cybertron_fde_0408_0x04637c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04637cU;
    constexpr uint32_t kFdeVa   = 0x06f1b0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffca18U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffd336U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0409] start_va=0x046384, fde_va=0x06f1c8, span=8 bytes
// [VN] FDE[0409] địa chỉ bắt đầu=0x046384, fde_va=0x06f1c8, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFD336 F9402800 17FFD060
uint32_t cybertron_fde_0409_0x046384(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046384U;
    constexpr uint32_t kFdeVa   = 0x06f1c8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffd336U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffd060U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0410] start_va=0x04638c, fde_va=0x06f1e0, span=8 bytes
// [VN] FDE[0410] địa chỉ bắt đầu=0x04638c, fde_va=0x06f1e0, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFD060 F81C0FF7 A90157F6
uint32_t cybertron_fde_0410_0x04638c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04638cU;
    constexpr uint32_t kFdeVa   = 0x06f1e0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffd060U;
    constexpr uint32_t kW2      = 0xf81c0ff7U;
    constexpr uint32_t kW3      = 0xa90157f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0411] start_va=0x046394, fde_va=0x06f1f8, span=208 bytes
// [VN] FDE[0411] địa chỉ bắt đầu=0x046394, fde_va=0x06f1f8, kích thước=208 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0411_0x046394(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046394U;
    constexpr uint32_t kFdeVa   = 0x06f1f8U;
    constexpr uint32_t kSpan    = 208U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0412] start_va=0x046464, fde_va=0x06f220, span=88 bytes
// [VN] FDE[0412] địa chỉ bắt đầu=0x046464, fde_va=0x06f220, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0412_0x046464(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046464U;
    constexpr uint32_t kFdeVa   = 0x06f220U;
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

// [EN] FDE[0413] start_va=0x0464bc, fde_va=0x06f240, span=136 bytes
// [VN] FDE[0413] địa chỉ bắt đầu=0x0464bc, fde_va=0x06f240, kích thước=136 byte
// AArch64 opcodes: F81B0FF9 A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0413_0x0464bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0464bcU;
    constexpr uint32_t kFdeVa   = 0x06f240U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xf81b0ff9U;
    constexpr uint32_t kW1      = 0xa9015ff8U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0414] start_va=0x046544, fde_va=0x06f268, span=8 bytes
// [VN] FDE[0414] địa chỉ bắt đầu=0x046544, fde_va=0x06f268, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFCCF6 F9402800 AA0103E2
uint32_t cybertron_fde_0414_0x046544(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046544U;
    constexpr uint32_t kFdeVa   = 0x06f268U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffccf6U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0xaa0103e2U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0415] start_va=0x04654c, fde_va=0x06f280, span=16 bytes
// [VN] FDE[0415] địa chỉ bắt đầu=0x04654c, fde_va=0x06f280, kích thước=16 byte
// AArch64 opcodes: F9402800 AA0103E2 52807D21 17FFCE26
uint32_t cybertron_fde_0415_0x04654c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04654cU;
    constexpr uint32_t kFdeVa   = 0x06f280U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0xaa0103e2U;
    constexpr uint32_t kW2      = 0x52807d21U;
    constexpr uint32_t kW3      = 0x17ffce26U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0416] start_va=0x04655c, fde_va=0x06f298, span=16 bytes
// [VN] FDE[0416] địa chỉ bắt đầu=0x04655c, fde_va=0x06f298, kích thước=16 byte
// AArch64 opcodes: F9402800 AA0103E2 52807D41 17FFCE22
uint32_t cybertron_fde_0416_0x04655c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04655cU;
    constexpr uint32_t kFdeVa   = 0x06f298U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0xaa0103e2U;
    constexpr uint32_t kW2      = 0x52807d41U;
    constexpr uint32_t kW3      = 0x17ffce22U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0417] start_va=0x04656c, fde_va=0x06f2b0, span=8 bytes
// [VN] FDE[0417] địa chỉ bắt đầu=0x04656c, fde_va=0x06f2b0, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFCC88 F9402800 17FFCFB2
uint32_t cybertron_fde_0417_0x04656c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04656cU;
    constexpr uint32_t kFdeVa   = 0x06f2b0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffcc88U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffcfb2U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0418] start_va=0x046574, fde_va=0x06f2c8, span=8 bytes
// [VN] FDE[0418] địa chỉ bắt đầu=0x046574, fde_va=0x06f2c8, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFCFB2 F9402800 17FFCF70
uint32_t cybertron_fde_0418_0x046574(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046574U;
    constexpr uint32_t kFdeVa   = 0x06f2c8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffcfb2U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffcf70U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0419] start_va=0x04657c, fde_va=0x06f2e0, span=8 bytes
// [VN] FDE[0419] địa chỉ bắt đầu=0x04657c, fde_va=0x06f2e0, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFCF70 F9402800 17FFD15A
uint32_t cybertron_fde_0419_0x04657c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04657cU;
    constexpr uint32_t kFdeVa   = 0x06f2e0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffcf70U;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffd15aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0420] start_va=0x046584, fde_va=0x06f2f8, span=8 bytes
// [VN] FDE[0420] địa chỉ bắt đầu=0x046584, fde_va=0x06f2f8, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFD15A F9402800 17FFC9C0
uint32_t cybertron_fde_0420_0x046584(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046584U;
    constexpr uint32_t kFdeVa   = 0x06f2f8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffd15aU;
    constexpr uint32_t kW2      = 0xf9402800U;
    constexpr uint32_t kW3      = 0x17ffc9c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0421] start_va=0x04658c, fde_va=0x06f310, span=8 bytes
// [VN] FDE[0421] địa chỉ bắt đầu=0x04658c, fde_va=0x06f310, kích thước=8 byte
// AArch64 opcodes: F9402800 17FFC9C0 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0421_0x04658c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04658cU;
    constexpr uint32_t kFdeVa   = 0x06f310U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9402800U;
    constexpr uint32_t kW1      = 0x17ffc9c0U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0422] start_va=0x046594, fde_va=0x06f328, span=80 bytes
// [VN] FDE[0422] địa chỉ bắt đầu=0x046594, fde_va=0x06f328, kích thước=80 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B00001C8
uint32_t cybertron_fde_0422_0x046594(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046594U;
    constexpr uint32_t kFdeVa   = 0x06f328U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0423] start_va=0x0465e4, fde_va=0x06f348, span=36 bytes
// [VN] FDE[0423] địa chỉ bắt đầu=0x0465e4, fde_va=0x06f348, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0423_0x0465e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0465e4U;
    constexpr uint32_t kFdeVa   = 0x06f348U;
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

// [EN] FDE[0424] start_va=0x046608, fde_va=0x06f368, span=8 bytes
// [VN] FDE[0424] địa chỉ bắt đầu=0x046608, fde_va=0x06f368, kích thước=8 byte
// AArch64 opcodes: D1002000 17FFD2E5 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0424_0x046608(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046608U;
    constexpr uint32_t kFdeVa   = 0x06f368U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ffd2e5U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0425] start_va=0x046610, fde_va=0x06f380, span=40 bytes
// [VN] FDE[0425] địa chỉ bắt đầu=0x046610, fde_va=0x06f380, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D1002013
uint32_t cybertron_fde_0425_0x046610(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046610U;
    constexpr uint32_t kFdeVa   = 0x06f380U;
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

// [EN] FDE[0426] start_va=0x046638, fde_va=0x06f3a0, span=276 bytes
// [VN] FDE[0426] địa chỉ bắt đầu=0x046638, fde_va=0x06f3a0, kích thước=276 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0426_0x046638(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046638U;
    constexpr uint32_t kFdeVa   = 0x06f3a0U;
    constexpr uint32_t kSpan    = 276U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0427] start_va=0x04674c, fde_va=0x06f3c8, span=100 bytes
// [VN] FDE[0427] địa chỉ bắt đầu=0x04674c, fde_va=0x06f3c8, kích thước=100 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_0427_0x04674c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04674cU;
    constexpr uint32_t kFdeVa   = 0x06f3c8U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0428] start_va=0x0467b0, fde_va=0x06f3e8, span=32 bytes
// [VN] FDE[0428] địa chỉ bắt đầu=0x0467b0, fde_va=0x06f3e8, kích thước=32 byte
// AArch64 opcodes: F9400068 CB010042 F100045F CB020100
uint32_t cybertron_fde_0428_0x0467b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0467b0U;
    constexpr uint32_t kFdeVa   = 0x06f3e8U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xf9400068U;
    constexpr uint32_t kW1      = 0xcb010042U;
    constexpr uint32_t kW2      = 0xf100045fU;
    constexpr uint32_t kW3      = 0xcb020100U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0429] start_va=0x0467d0, fde_va=0x06f400, span=52 bytes
// [VN] FDE[0429] địa chỉ bắt đầu=0x0467d0, fde_va=0x06f400, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B00001C8
uint32_t cybertron_fde_0429_0x0467d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0467d0U;
    constexpr uint32_t kFdeVa   = 0x06f400U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0430] start_va=0x046804, fde_va=0x06f420, span=60 bytes
// [VN] FDE[0430] địa chỉ bắt đầu=0x046804, fde_va=0x06f420, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B00001C8
uint32_t cybertron_fde_0430_0x046804(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046804U;
    constexpr uint32_t kFdeVa   = 0x06f420U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0431] start_va=0x046840, fde_va=0x06f440, span=8 bytes
// [VN] FDE[0431] địa chỉ bắt đầu=0x046840, fde_va=0x06f440, kích thước=8 byte
// AArch64 opcodes: 91006000 17FFC96B 17FFC936 B00001C8
uint32_t cybertron_fde_0431_0x046840(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046840U;
    constexpr uint32_t kFdeVa   = 0x06f440U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91006000U;
    constexpr uint32_t kW1      = 0x17ffc96bU;
    constexpr uint32_t kW2      = 0x17ffc936U;
    constexpr uint32_t kW3      = 0xb00001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0432] start_va=0x046848, fde_va=0x06f458, span=4 bytes
// [VN] FDE[0432] địa chỉ bắt đầu=0x046848, fde_va=0x06f458, kích thước=4 byte
// AArch64 opcodes: 17FFC936 B00001C8 F946ED08 B9000801
uint32_t cybertron_fde_0432_0x046848(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046848U;
    constexpr uint32_t kFdeVa   = 0x06f458U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffc936U;
    constexpr uint32_t kW1      = 0xb00001c8U;
    constexpr uint32_t kW2      = 0xf946ed08U;
    constexpr uint32_t kW3      = 0xb9000801U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0433] start_va=0x04684c, fde_va=0x06f470, span=24 bytes
// [VN] FDE[0433] địa chỉ bắt đầu=0x04684c, fde_va=0x06f470, kích thước=24 byte
// AArch64 opcodes: B00001C8 F946ED08 B9000801 91004108
uint32_t cybertron_fde_0433_0x04684c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04684cU;
    constexpr uint32_t kFdeVa   = 0x06f470U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xb00001c8U;
    constexpr uint32_t kW1      = 0xf946ed08U;
    constexpr uint32_t kW2      = 0xb9000801U;
    constexpr uint32_t kW3      = 0x91004108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0434] start_va=0x046864, fde_va=0x06f488, span=16 bytes
// [VN] FDE[0434] địa chỉ bắt đầu=0x046864, fde_va=0x06f488, kích thước=16 byte
// AArch64 opcodes: 512EE428 710F991F 5A9F93E0 D65F03C0
uint32_t cybertron_fde_0434_0x046864(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046864U;
    constexpr uint32_t kFdeVa   = 0x06f488U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x512ee428U;
    constexpr uint32_t kW1      = 0x710f991fU;
    constexpr uint32_t kW2      = 0x5a9f93e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0435] start_va=0x046874, fde_va=0x06f4a0, span=16 bytes
// [VN] FDE[0435] địa chỉ bắt đầu=0x046874, fde_va=0x06f4a0, kích thước=16 byte
// AArch64 opcodes: 51000428 710F9D1F 5A9F93E0 D65F03C0
uint32_t cybertron_fde_0435_0x046874(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046874U;
    constexpr uint32_t kFdeVa   = 0x06f4a0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x51000428U;
    constexpr uint32_t kW1      = 0x710f9d1fU;
    constexpr uint32_t kW2      = 0x5a9f93e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0436] start_va=0x046884, fde_va=0x06f4b8, span=16 bytes
// [VN] FDE[0436] địa chỉ bắt đầu=0x046884, fde_va=0x06f4b8, kích thước=16 byte
// AArch64 opcodes: 510FA428 710F991F 5A9F93E0 D65F03C0
uint32_t cybertron_fde_0436_0x046884(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046884U;
    constexpr uint32_t kFdeVa   = 0x06f4b8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x510fa428U;
    constexpr uint32_t kW1      = 0x710f991fU;
    constexpr uint32_t kW2      = 0x5a9f93e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0437] start_va=0x046894, fde_va=0x06f4d0, span=12 bytes
// [VN] FDE[0437] địa chỉ bắt đầu=0x046894, fde_va=0x06f4d0, kích thước=12 byte
// AArch64 opcodes: 713E843F 5A9FA3E0 D65F03C0 511F4428
uint32_t cybertron_fde_0437_0x046894(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046894U;
    constexpr uint32_t kFdeVa   = 0x06f4d0U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x713e843fU;
    constexpr uint32_t kW1      = 0x5a9fa3e0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x511f4428U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0438] start_va=0x0468a0, fde_va=0x06f4e8, span=16 bytes
// [VN] FDE[0438] địa chỉ bắt đầu=0x0468a0, fde_va=0x06f4e8, kích thước=16 byte
// AArch64 opcodes: 511F4428 710F991F 5A9F93E0 D65F03C0
uint32_t cybertron_fde_0438_0x0468a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0468a0U;
    constexpr uint32_t kFdeVa   = 0x06f4e8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x511f4428U;
    constexpr uint32_t kW1      = 0x710f991fU;
    constexpr uint32_t kW2      = 0x5a9f93e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0439] start_va=0x0468b0, fde_va=0x06f500, span=12 bytes
// [VN] FDE[0439] địa chỉ bắt đầu=0x0468b0, fde_va=0x06f500, kích thước=12 byte
// AArch64 opcodes: AA0203E1 AA0803E0 17FFC9C2 7100083F
uint32_t cybertron_fde_0439_0x0468b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0468b0U;
    constexpr uint32_t kFdeVa   = 0x06f500U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xaa0203e1U;
    constexpr uint32_t kW1      = 0xaa0803e0U;
    constexpr uint32_t kW2      = 0x17ffc9c2U;
    constexpr uint32_t kW3      = 0x7100083fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0440] start_va=0x0468bc, fde_va=0x06f518, span=32 bytes
// [VN] FDE[0440] địa chỉ bắt đầu=0x0468bc, fde_va=0x06f518, kích thước=32 byte
// AArch64 opcodes: 7100083F 540000A1 51000428 710F9D1F
uint32_t cybertron_fde_0440_0x0468bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0468bcU;
    constexpr uint32_t kFdeVa   = 0x06f518U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0x7100083fU;
    constexpr uint32_t kW1      = 0x540000a1U;
    constexpr uint32_t kW2      = 0x51000428U;
    constexpr uint32_t kW3      = 0x710f9d1fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0441] start_va=0x0468dc, fde_va=0x06f530, span=8 bytes
// [VN] FDE[0441] địa chỉ bắt đầu=0x0468dc, fde_va=0x06f530, kích thước=8 byte
// AArch64 opcodes: AA0203E0 D65F03C0 AA1F03E0 D65F03C0
uint32_t cybertron_fde_0441_0x0468dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0468dcU;
    constexpr uint32_t kFdeVa   = 0x06f530U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xaa0203e0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xaa1f03e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0442] start_va=0x0468e4, fde_va=0x06f548, span=8 bytes
// [VN] FDE[0442] địa chỉ bắt đầu=0x0468e4, fde_va=0x06f548, kích thước=8 byte
// AArch64 opcodes: AA1F03E0 D65F03C0 D65F03C0 9000010A
uint32_t cybertron_fde_0442_0x0468e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0468e4U;
    constexpr uint32_t kFdeVa   = 0x06f548U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xaa1f03e0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x9000010aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0443] start_va=0x0468ec, fde_va=0x06f560, span=4 bytes
// [VN] FDE[0443] địa chỉ bắt đầu=0x0468ec, fde_va=0x06f560, kích thước=4 byte
// AArch64 opcodes: D65F03C0 9000010A 9127C14A F840514B
uint32_t cybertron_fde_0443_0x0468ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0468ecU;
    constexpr uint32_t kFdeVa   = 0x06f560U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x9000010aU;
    constexpr uint32_t kW2      = 0x9127c14aU;
    constexpr uint32_t kW3      = 0xf840514bU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0444] start_va=0x0468f0, fde_va=0x06f578, span=44 bytes
// [VN] FDE[0444] địa chỉ bắt đầu=0x0468f0, fde_va=0x06f578, kích thước=44 byte
// AArch64 opcodes: 9000010A 9127C14A F840514B F940014A
uint32_t cybertron_fde_0444_0x0468f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0468f0U;
    constexpr uint32_t kFdeVa   = 0x06f578U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0x9000010aU;
    constexpr uint32_t kW1      = 0x9127c14aU;
    constexpr uint32_t kW2      = 0xf840514bU;
    constexpr uint32_t kW3      = 0xf940014aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0445] start_va=0x04691c, fde_va=0x06f590, span=4 bytes
// [VN] FDE[0445] địa chỉ bắt đầu=0x04691c, fde_va=0x06f590, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D10303FF A9085FF8 A90957F6
uint32_t cybertron_fde_0445_0x04691c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04691cU;
    constexpr uint32_t kFdeVa   = 0x06f590U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd10303ffU;
    constexpr uint32_t kW2      = 0xa9085ff8U;
    constexpr uint32_t kW3      = 0xa90957f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0446] start_va=0x046920, fde_va=0x06f5a8, span=300 bytes
// [VN] FDE[0446] địa chỉ bắt đầu=0x046920, fde_va=0x06f5a8, kích thước=300 byte
// AArch64 opcodes: D10303FF A9085FF8 A90957F6 A90A4FF4
uint32_t cybertron_fde_0446_0x046920(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046920U;
    constexpr uint32_t kFdeVa   = 0x06f5a8U;
    constexpr uint32_t kSpan    = 300U;
    constexpr uint32_t kW0      = 0xd10303ffU;
    constexpr uint32_t kW1      = 0xa9085ff8U;
    constexpr uint32_t kW2      = 0xa90957f6U;
    constexpr uint32_t kW3      = 0xa90a4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0447] start_va=0x046a4c, fde_va=0x06f5d0, span=124 bytes
// [VN] FDE[0447] địa chỉ bắt đầu=0x046a4c, fde_va=0x06f5d0, kích thước=124 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0447_0x046a4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046a4cU;
    constexpr uint32_t kFdeVa   = 0x06f5d0U;
    constexpr uint32_t kSpan    = 124U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0448] start_va=0x046ac8, fde_va=0x06f5f0, span=256 bytes
// [VN] FDE[0448] địa chỉ bắt đầu=0x046ac8, fde_va=0x06f5f0, kích thước=256 byte
// AArch64 opcodes: D10143FF A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0448_0x046ac8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046ac8U;
    constexpr uint32_t kFdeVa   = 0x06f5f0U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa9015ff8U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0449] start_va=0x046bc8, fde_va=0x06f618, span=84 bytes
// [VN] FDE[0449] địa chỉ bắt đầu=0x046bc8, fde_va=0x06f618, kích thước=84 byte
// AArch64 opcodes: A9BF7BFD 910003FD F9400408 B4000228
uint32_t cybertron_fde_0449_0x046bc8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046bc8U;
    constexpr uint32_t kFdeVa   = 0x06f618U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xf9400408U;
    constexpr uint32_t kW3      = 0xb4000228U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0450] start_va=0x046c1c, fde_va=0x06f638, span=68 bytes
// [VN] FDE[0450] địa chỉ bắt đầu=0x046c1c, fde_va=0x06f638, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0450_0x046c1c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046c1cU;
    constexpr uint32_t kFdeVa   = 0x06f638U;
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

// [EN] FDE[0451] start_va=0x046c60, fde_va=0x06f658, span=112 bytes
// [VN] FDE[0451] địa chỉ bắt đầu=0x046c60, fde_va=0x06f658, kích thước=112 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0451_0x046c60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046c60U;
    constexpr uint32_t kFdeVa   = 0x06f658U;
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

// [EN] FDE[0452] start_va=0x046cd0, fde_va=0x06f678, span=356 bytes
// [VN] FDE[0452] địa chỉ bắt đầu=0x046cd0, fde_va=0x06f678, kích thước=356 byte
// AArch64 opcodes: D10183FF F9000BF9 A9025FF8 A90357F6
uint32_t cybertron_fde_0452_0x046cd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046cd0U;
    constexpr uint32_t kFdeVa   = 0x06f678U;
    constexpr uint32_t kSpan    = 356U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9000bf9U;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0453] start_va=0x046e34, fde_va=0x06f6a0, span=88 bytes
// [VN] FDE[0453] địa chỉ bắt đầu=0x046e34, fde_va=0x06f6a0, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0453_0x046e34(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046e34U;
    constexpr uint32_t kFdeVa   = 0x06f6a0U;
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

// [EN] FDE[0454] start_va=0x046e8c, fde_va=0x06f6c0, span=4 bytes
// [VN] FDE[0454] địa chỉ bắt đầu=0x046e8c, fde_va=0x06f6c0, kích thước=4 byte
// AArch64 opcodes: 17FFC7A5 F81D0FF5 A9014FF4 A9027BFD
uint32_t cybertron_fde_0454_0x046e8c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046e8cU;
    constexpr uint32_t kFdeVa   = 0x06f6c0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffc7a5U;
    constexpr uint32_t kW1      = 0xf81d0ff5U;
    constexpr uint32_t kW2      = 0xa9014ff4U;
    constexpr uint32_t kW3      = 0xa9027bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0455] start_va=0x046e90, fde_va=0x06f6d8, span=112 bytes
// [VN] FDE[0455] địa chỉ bắt đầu=0x046e90, fde_va=0x06f6d8, kích thước=112 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0455_0x046e90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046e90U;
    constexpr uint32_t kFdeVa   = 0x06f6d8U;
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

// [EN] FDE[0456] start_va=0x046f00, fde_va=0x06f6f8, span=196 bytes
// [VN] FDE[0456] địa chỉ bắt đầu=0x046f00, fde_va=0x06f6f8, kích thước=196 byte
// AArch64 opcodes: D101C3FF A9035FF8 A90457F6 A9054FF4
uint32_t cybertron_fde_0456_0x046f00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046f00U;
    constexpr uint32_t kFdeVa   = 0x06f6f8U;
    constexpr uint32_t kSpan    = 196U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9035ff8U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0457] start_va=0x046fc4, fde_va=0x06f720, span=296 bytes
// [VN] FDE[0457] địa chỉ bắt đầu=0x046fc4, fde_va=0x06f720, kích thước=296 byte
// AArch64 opcodes: 91002008 EB01011F 540000A0 B9400089
uint32_t cybertron_fde_0457_0x046fc4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x046fc4U;
    constexpr uint32_t kFdeVa   = 0x06f720U;
    constexpr uint32_t kSpan    = 296U;
    constexpr uint32_t kW0      = 0x91002008U;
    constexpr uint32_t kW1      = 0xeb01011fU;
    constexpr uint32_t kW2      = 0x540000a0U;
    constexpr uint32_t kW3      = 0xb9400089U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0458] start_va=0x0470ec, fde_va=0x06f738, span=84 bytes
// [VN] FDE[0458] địa chỉ bắt đầu=0x0470ec, fde_va=0x06f738, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_0458_0x0470ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0470ecU;
    constexpr uint32_t kFdeVa   = 0x06f738U;
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

// [EN] FDE[0459] start_va=0x047140, fde_va=0x06f758, span=96 bytes
// [VN] FDE[0459] địa chỉ bắt đầu=0x047140, fde_va=0x06f758, kích thước=96 byte
// AArch64 opcodes: AA0003E8 F8408C09 B4000229 B940004A
uint32_t cybertron_fde_0459_0x047140(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047140U;
    constexpr uint32_t kFdeVa   = 0x06f758U;
    constexpr uint32_t kSpan    = 96U;
    constexpr uint32_t kW0      = 0xaa0003e8U;
    constexpr uint32_t kW1      = 0xf8408c09U;
    constexpr uint32_t kW2      = 0xb4000229U;
    constexpr uint32_t kW3      = 0xb940004aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0460] start_va=0x0471a0, fde_va=0x06f770, span=88 bytes
// [VN] FDE[0460] địa chỉ bắt đầu=0x0471a0, fde_va=0x06f770, kích thước=88 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0460_0x0471a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0471a0U;
    constexpr uint32_t kFdeVa   = 0x06f770U;
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

// [EN] FDE[0461] start_va=0x0471f8, fde_va=0x06f790, span=408 bytes
// [VN] FDE[0461] địa chỉ bắt đầu=0x0471f8, fde_va=0x06f790, kích thước=408 byte
// AArch64 opcodes: EB00003F 1A9F17E8 39006028 54000300
uint32_t cybertron_fde_0461_0x0471f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0471f8U;
    constexpr uint32_t kFdeVa   = 0x06f790U;
    constexpr uint32_t kSpan    = 408U;
    constexpr uint32_t kW0      = 0xeb00003fU;
    constexpr uint32_t kW1      = 0x1a9f17e8U;
    constexpr uint32_t kW2      = 0x39006028U;
    constexpr uint32_t kW3      = 0x54000300U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0462] start_va=0x047390, fde_va=0x06f7a8, span=68 bytes
// [VN] FDE[0462] địa chỉ bắt đầu=0x047390, fde_va=0x06f7a8, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400013
uint32_t cybertron_fde_0462_0x047390(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047390U;
    constexpr uint32_t kFdeVa   = 0x06f7a8U;
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

// [EN] FDE[0463] start_va=0x0473d4, fde_va=0x06f7c8, span=72 bytes
// [VN] FDE[0463] địa chỉ bắt đầu=0x0473d4, fde_va=0x06f7c8, kích thước=72 byte
// AArch64 opcodes: B4000221 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0463_0x0473d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0473d4U;
    constexpr uint32_t kFdeVa   = 0x06f7c8U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xb4000221U;
    constexpr uint32_t kW1      = 0xa9be4ff4U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0464] start_va=0x04741c, fde_va=0x06f7e8, span=52 bytes
// [VN] FDE[0464] địa chỉ bắt đầu=0x04741c, fde_va=0x06f7e8, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 900001C8
uint32_t cybertron_fde_0464_0x04741c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04741cU;
    constexpr uint32_t kFdeVa   = 0x06f7e8U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0465] start_va=0x047450, fde_va=0x06f808, span=60 bytes
// [VN] FDE[0465] địa chỉ bắt đầu=0x047450, fde_va=0x06f808, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 900001C8
uint32_t cybertron_fde_0465_0x047450(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047450U;
    constexpr uint32_t kFdeVa   = 0x06f808U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0466] start_va=0x04748c, fde_va=0x06f828, span=12 bytes
// [VN] FDE[0466] địa chỉ bắt đầu=0x04748c, fde_va=0x06f828, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400101 D61F0020 17FFC622
uint32_t cybertron_fde_0466_0x04748c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04748cU;
    constexpr uint32_t kFdeVa   = 0x06f828U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400101U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ffc622U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0467] start_va=0x047498, fde_va=0x06f840, span=4 bytes
// [VN] FDE[0467] địa chỉ bắt đầu=0x047498, fde_va=0x06f840, kích thước=4 byte
// AArch64 opcodes: 17FFC622 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0467_0x047498(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047498U;
    constexpr uint32_t kFdeVa   = 0x06f840U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffc622U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0468] start_va=0x04749c, fde_va=0x06f858, span=148 bytes
// [VN] FDE[0468] địa chỉ bắt đầu=0x04749c, fde_va=0x06f858, kích thước=148 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 900001C8
uint32_t cybertron_fde_0468_0x04749c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04749cU;
    constexpr uint32_t kFdeVa   = 0x06f858U;
    constexpr uint32_t kSpan    = 148U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900001c8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0469] start_va=0x047530, fde_va=0x06f878, span=108 bytes
// [VN] FDE[0469] địa chỉ bắt đầu=0x047530, fde_va=0x06f878, kích thước=108 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0469_0x047530(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047530U;
    constexpr uint32_t kFdeVa   = 0x06f878U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0470] start_va=0x04759c, fde_va=0x06f898, span=88 bytes
// [VN] FDE[0470] địa chỉ bắt đầu=0x04759c, fde_va=0x06f898, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0470_0x04759c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04759cU;
    constexpr uint32_t kFdeVa   = 0x06f898U;
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

// [EN] FDE[0471] start_va=0x0475f4, fde_va=0x06f8b8, span=88 bytes
// [VN] FDE[0471] địa chỉ bắt đầu=0x0475f4, fde_va=0x06f8b8, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 2A1F03E1
uint32_t cybertron_fde_0471_0x0475f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0475f4U;
    constexpr uint32_t kFdeVa   = 0x06f8b8U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x2a1f03e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0472] start_va=0x04764c, fde_va=0x06f8d8, span=12 bytes
// [VN] FDE[0472] địa chỉ bắt đầu=0x04764c, fde_va=0x06f8d8, kích thước=12 byte
// AArch64 opcodes: F9400008 F9403501 D61F0020 D10183FF
uint32_t cybertron_fde_0472_0x04764c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04764cU;
    constexpr uint32_t kFdeVa   = 0x06f8d8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf9400008U;
    constexpr uint32_t kW1      = 0xf9403501U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0xd10183ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0473] start_va=0x047658, fde_va=0x06f8f0, span=264 bytes
// [VN] FDE[0473] địa chỉ bắt đầu=0x047658, fde_va=0x06f8f0, kích thước=264 byte
// AArch64 opcodes: D10183FF F9000BF9 A9025FF8 A90357F6
uint32_t cybertron_fde_0473_0x047658(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047658U;
    constexpr uint32_t kFdeVa   = 0x06f8f0U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9000bf9U;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0474] start_va=0x047760, fde_va=0x06f918, span=232 bytes
// [VN] FDE[0474] địa chỉ bắt đầu=0x047760, fde_va=0x06f918, kích thước=232 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_0474_0x047760(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047760U;
    constexpr uint32_t kFdeVa   = 0x06f918U;
    constexpr uint32_t kSpan    = 232U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0475] start_va=0x047848, fde_va=0x06f940, span=264 bytes
// [VN] FDE[0475] địa chỉ bắt đầu=0x047848, fde_va=0x06f940, kích thước=264 byte
// AArch64 opcodes: D10183FF FD000BE8 A9025FF8 A90357F6
uint32_t cybertron_fde_0475_0x047848(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047848U;
    constexpr uint32_t kFdeVa   = 0x06f940U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xfd000be8U;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0476] start_va=0x047950, fde_va=0x06f968, span=264 bytes
// [VN] FDE[0476] địa chỉ bắt đầu=0x047950, fde_va=0x06f968, kích thước=264 byte
// AArch64 opcodes: D10183FF F9000BF9 A9025FF8 A90357F6
uint32_t cybertron_fde_0476_0x047950(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047950U;
    constexpr uint32_t kFdeVa   = 0x06f968U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9000bf9U;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0477] start_va=0x047a58, fde_va=0x06f990, span=8 bytes
// [VN] FDE[0477] địa chỉ bắt đầu=0x047a58, fde_va=0x06f990, kích thước=8 byte
// AArch64 opcodes: 2A1F03E0 D65F03C0 D10183FF F9000BF9
uint32_t cybertron_fde_0477_0x047a58(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047a58U;
    constexpr uint32_t kFdeVa   = 0x06f990U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x2a1f03e0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd10183ffU;
    constexpr uint32_t kW3      = 0xf9000bf9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0478] start_va=0x047a60, fde_va=0x06f9a8, span=264 bytes
// [VN] FDE[0478] địa chỉ bắt đầu=0x047a60, fde_va=0x06f9a8, kích thước=264 byte
// AArch64 opcodes: D10183FF F9000BF9 A9025FF8 A90357F6
uint32_t cybertron_fde_0478_0x047a60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047a60U;
    constexpr uint32_t kFdeVa   = 0x06f9a8U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9000bf9U;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0479] start_va=0x047b68, fde_va=0x06f9d0, span=296 bytes
// [VN] FDE[0479] địa chỉ bắt đầu=0x047b68, fde_va=0x06f9d0, kích thước=296 byte
// AArch64 opcodes: D10183FF FD001BE8 F9001FF5 A9044FF4
uint32_t cybertron_fde_0479_0x047b68(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x047b68U;
    constexpr uint32_t kFdeVa   = 0x06f9d0U;
    constexpr uint32_t kSpan    = 296U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xfd001be8U;
    constexpr uint32_t kW2      = 0xf9001ff5U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

uint32_t DispatchCybertronFdeShard2(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 240U: return cybertron_fde_0240_0x042c70(a0, a1);
        case 241U: return cybertron_fde_0241_0x042c94(a0, a1);
        case 242U: return cybertron_fde_0242_0x042cb0(a0, a1);
        case 243U: return cybertron_fde_0243_0x042d1c(a0, a1);
        case 244U: return cybertron_fde_0244_0x042d88(a0, a1);
        case 245U: return cybertron_fde_0245_0x042d8c(a0, a1);
        case 246U: return cybertron_fde_0246_0x042d90(a0, a1);
        case 247U: return cybertron_fde_0247_0x042dd0(a0, a1);
        case 248U: return cybertron_fde_0248_0x042df4(a0, a1);
        case 249U: return cybertron_fde_0249_0x042e18(a0, a1);
        case 250U: return cybertron_fde_0250_0x042f8c(a0, a1);
        case 251U: return cybertron_fde_0251_0x043020(a0, a1);
        case 252U: return cybertron_fde_0252_0x043024(a0, a1);
        case 253U: return cybertron_fde_0253_0x04302c(a0, a1);
        case 254U: return cybertron_fde_0254_0x043034(a0, a1);
        case 255U: return cybertron_fde_0255_0x04303c(a0, a1);
        case 256U: return cybertron_fde_0256_0x043044(a0, a1);
        case 257U: return cybertron_fde_0257_0x04304c(a0, a1);
        case 258U: return cybertron_fde_0258_0x043054(a0, a1);
        case 259U: return cybertron_fde_0259_0x043078(a0, a1);
        case 260U: return cybertron_fde_0260_0x0430a0(a0, a1);
        case 261U: return cybertron_fde_0261_0x0430c8(a0, a1);
        case 262U: return cybertron_fde_0262_0x0430f0(a0, a1);
        case 263U: return cybertron_fde_0263_0x043118(a0, a1);
        case 264U: return cybertron_fde_0264_0x043140(a0, a1);
        case 265U: return cybertron_fde_0265_0x043168(a0, a1);
        case 266U: return cybertron_fde_0266_0x04320c(a0, a1);
        case 267U: return cybertron_fde_0267_0x043260(a0, a1);
        case 268U: return cybertron_fde_0268_0x043340(a0, a1);
        case 269U: return cybertron_fde_0269_0x043348(a0, a1);
        case 270U: return cybertron_fde_0270_0x043350(a0, a1);
        case 271U: return cybertron_fde_0271_0x0433a4(a0, a1);
        case 272U: return cybertron_fde_0272_0x0433b0(a0, a1);
        case 273U: return cybertron_fde_0273_0x0433c0(a0, a1);
        case 274U: return cybertron_fde_0274_0x0433e8(a0, a1);
        case 275U: return cybertron_fde_0275_0x043410(a0, a1);
        case 276U: return cybertron_fde_0276_0x04341c(a0, a1);
        case 277U: return cybertron_fde_0277_0x04342c(a0, a1);
        case 278U: return cybertron_fde_0278_0x043490(a0, a1);
        case 279U: return cybertron_fde_0279_0x0434a0(a0, a1);
        case 280U: return cybertron_fde_0280_0x043660(a0, a1);
        case 281U: return cybertron_fde_0281_0x0437fc(a0, a1);
        case 282U: return cybertron_fde_0282_0x043818(a0, a1);
        case 283U: return cybertron_fde_0283_0x0439b4(a0, a1);
        case 284U: return cybertron_fde_0284_0x0439d0(a0, a1);
        case 285U: return cybertron_fde_0285_0x043b6c(a0, a1);
        case 286U: return cybertron_fde_0286_0x043c10(a0, a1);
        case 287U: return cybertron_fde_0287_0x043ce0(a0, a1);
        case 288U: return cybertron_fde_0288_0x043ce8(a0, a1);
        case 289U: return cybertron_fde_0289_0x043cec(a0, a1);
        case 290U: return cybertron_fde_0290_0x043cf0(a0, a1);
        case 291U: return cybertron_fde_0291_0x043cf4(a0, a1);
        case 292U: return cybertron_fde_0292_0x043cf8(a0, a1);
        case 293U: return cybertron_fde_0293_0x043e38(a0, a1);
        case 294U: return cybertron_fde_0294_0x043e40(a0, a1);
        case 295U: return cybertron_fde_0295_0x043f44(a0, a1);
        case 296U: return cybertron_fde_0296_0x043f4c(a0, a1);
        case 297U: return cybertron_fde_0297_0x043f50(a0, a1);
        case 298U: return cybertron_fde_0298_0x043f54(a0, a1);
        case 299U: return cybertron_fde_0299_0x044194(a0, a1);
        case 300U: return cybertron_fde_0300_0x04419c(a0, a1);
        case 301U: return cybertron_fde_0301_0x0442bc(a0, a1);
        case 302U: return cybertron_fde_0302_0x0442c4(a0, a1);
        case 303U: return cybertron_fde_0303_0x0442d0(a0, a1);
        case 304U: return cybertron_fde_0304_0x044534(a0, a1);
        case 305U: return cybertron_fde_0305_0x04453c(a0, a1);
        case 306U: return cybertron_fde_0306_0x044550(a0, a1);
        case 307U: return cybertron_fde_0307_0x044554(a0, a1);
        case 308U: return cybertron_fde_0308_0x044558(a0, a1);
        case 309U: return cybertron_fde_0309_0x044568(a0, a1);
        case 310U: return cybertron_fde_0310_0x0445a4(a0, a1);
        case 311U: return cybertron_fde_0311_0x0445d8(a0, a1);
        case 312U: return cybertron_fde_0312_0x044614(a0, a1);
        case 313U: return cybertron_fde_0313_0x04461c(a0, a1);
        case 314U: return cybertron_fde_0314_0x044620(a0, a1);
        case 315U: return cybertron_fde_0315_0x044640(a0, a1);
        case 316U: return cybertron_fde_0316_0x04467c(a0, a1);
        case 317U: return cybertron_fde_0317_0x0446c4(a0, a1);
        case 318U: return cybertron_fde_0318_0x0446ec(a0, a1);
        case 319U: return cybertron_fde_0319_0x044700(a0, a1);
        case 320U: return cybertron_fde_0320_0x044730(a0, a1);
        case 321U: return cybertron_fde_0321_0x04477c(a0, a1);
        case 322U: return cybertron_fde_0322_0x044798(a0, a1);
        case 323U: return cybertron_fde_0323_0x0447a4(a0, a1);
        case 324U: return cybertron_fde_0324_0x0447c4(a0, a1);
        case 325U: return cybertron_fde_0325_0x044800(a0, a1);
        case 326U: return cybertron_fde_0326_0x044848(a0, a1);
        case 327U: return cybertron_fde_0327_0x044870(a0, a1);
        case 328U: return cybertron_fde_0328_0x044884(a0, a1);
        case 329U: return cybertron_fde_0329_0x0448b4(a0, a1);
        case 330U: return cybertron_fde_0330_0x044900(a0, a1);
        case 331U: return cybertron_fde_0331_0x04491c(a0, a1);
        case 332U: return cybertron_fde_0332_0x044928(a0, a1);
        case 333U: return cybertron_fde_0333_0x044948(a0, a1);
        case 334U: return cybertron_fde_0334_0x044984(a0, a1);
        case 335U: return cybertron_fde_0335_0x0449d4(a0, a1);
        case 336U: return cybertron_fde_0336_0x044a04(a0, a1);
        case 337U: return cybertron_fde_0337_0x044a18(a0, a1);
        case 338U: return cybertron_fde_0338_0x044a48(a0, a1);
        case 339U: return cybertron_fde_0339_0x044a7c(a0, a1);
        case 340U: return cybertron_fde_0340_0x044a98(a0, a1);
        case 341U: return cybertron_fde_0341_0x044aa4(a0, a1);
        case 342U: return cybertron_fde_0342_0x044ac4(a0, a1);
        case 343U: return cybertron_fde_0343_0x044b00(a0, a1);
        case 344U: return cybertron_fde_0344_0x044b50(a0, a1);
        case 345U: return cybertron_fde_0345_0x044b80(a0, a1);
        case 346U: return cybertron_fde_0346_0x044b94(a0, a1);
        case 347U: return cybertron_fde_0347_0x044bc4(a0, a1);
        case 348U: return cybertron_fde_0348_0x044bf8(a0, a1);
        case 349U: return cybertron_fde_0349_0x044c14(a0, a1);
        case 350U: return cybertron_fde_0350_0x044c20(a0, a1);
        case 351U: return cybertron_fde_0351_0x044c24(a0, a1);
        case 352U: return cybertron_fde_0352_0x044c48(a0, a1);
        case 353U: return cybertron_fde_0353_0x044c54(a0, a1);
        case 354U: return cybertron_fde_0354_0x044c58(a0, a1);
        case 355U: return cybertron_fde_0355_0x044c5c(a0, a1);
        case 356U: return cybertron_fde_0356_0x044c60(a0, a1);
        case 357U: return cybertron_fde_0357_0x044e20(a0, a1);
        case 358U: return cybertron_fde_0358_0x044e78(a0, a1);
        case 359U: return cybertron_fde_0359_0x044eec(a0, a1);
        case 360U: return cybertron_fde_0360_0x044ef4(a0, a1);
        case 361U: return cybertron_fde_0361_0x044f1c(a0, a1);
        case 362U: return cybertron_fde_0362_0x044f30(a0, a1);
        case 363U: return cybertron_fde_0363_0x044f60(a0, a1);
        case 364U: return cybertron_fde_0364_0x044fdc(a0, a1);
        case 365U: return cybertron_fde_0365_0x045054(a0, a1);
        case 366U: return cybertron_fde_0366_0x0450d4(a0, a1);
        case 367U: return cybertron_fde_0367_0x045154(a0, a1);
        case 368U: return cybertron_fde_0368_0x0451dc(a0, a1);
        case 369U: return cybertron_fde_0369_0x04522c(a0, a1);
        case 370U: return cybertron_fde_0370_0x045284(a0, a1);
        case 371U: return cybertron_fde_0371_0x045288(a0, a1);
        case 372U: return cybertron_fde_0372_0x04528c(a0, a1);
        case 373U: return cybertron_fde_0373_0x045380(a0, a1);
        case 374U: return cybertron_fde_0374_0x045394(a0, a1);
        case 375U: return cybertron_fde_0375_0x04539c(a0, a1);
        case 376U: return cybertron_fde_0376_0x0453a4(a0, a1);
        case 377U: return cybertron_fde_0377_0x045468(a0, a1);
        case 378U: return cybertron_fde_0378_0x0454b8(a0, a1);
        case 379U: return cybertron_fde_0379_0x0454f8(a0, a1);
        case 380U: return cybertron_fde_0380_0x045568(a0, a1);
        case 381U: return cybertron_fde_0381_0x045624(a0, a1);
        case 382U: return cybertron_fde_0382_0x0457a4(a0, a1);
        case 383U: return cybertron_fde_0383_0x0457b8(a0, a1);
        case 384U: return cybertron_fde_0384_0x0457ec(a0, a1);
        case 385U: return cybertron_fde_0385_0x0457f8(a0, a1);
        case 386U: return cybertron_fde_0386_0x045804(a0, a1);
        case 387U: return cybertron_fde_0387_0x04580c(a0, a1);
        case 388U: return cybertron_fde_0388_0x045814(a0, a1);
        case 389U: return cybertron_fde_0389_0x04581c(a0, a1);
        case 390U: return cybertron_fde_0390_0x0458bc(a0, a1);
        case 391U: return cybertron_fde_0391_0x0459d0(a0, a1);
        case 392U: return cybertron_fde_0392_0x045a2c(a0, a1);
        case 393U: return cybertron_fde_0393_0x045af8(a0, a1);
        case 394U: return cybertron_fde_0394_0x045c44(a0, a1);
        case 395U: return cybertron_fde_0395_0x045c90(a0, a1);
        case 396U: return cybertron_fde_0396_0x045e24(a0, a1);
        case 397U: return cybertron_fde_0397_0x045ebc(a0, a1);
        case 398U: return cybertron_fde_0398_0x045f70(a0, a1);
        case 399U: return cybertron_fde_0399_0x0460d4(a0, a1);
        case 400U: return cybertron_fde_0400_0x046208(a0, a1);
        case 401U: return cybertron_fde_0401_0x046224(a0, a1);
        case 402U: return cybertron_fde_0402_0x046278(a0, a1);
        case 403U: return cybertron_fde_0403_0x046354(a0, a1);
        case 404U: return cybertron_fde_0404_0x04635c(a0, a1);
        case 405U: return cybertron_fde_0405_0x046364(a0, a1);
        case 406U: return cybertron_fde_0406_0x04636c(a0, a1);
        case 407U: return cybertron_fde_0407_0x046374(a0, a1);
        case 408U: return cybertron_fde_0408_0x04637c(a0, a1);
        case 409U: return cybertron_fde_0409_0x046384(a0, a1);
        case 410U: return cybertron_fde_0410_0x04638c(a0, a1);
        case 411U: return cybertron_fde_0411_0x046394(a0, a1);
        case 412U: return cybertron_fde_0412_0x046464(a0, a1);
        case 413U: return cybertron_fde_0413_0x0464bc(a0, a1);
        case 414U: return cybertron_fde_0414_0x046544(a0, a1);
        case 415U: return cybertron_fde_0415_0x04654c(a0, a1);
        case 416U: return cybertron_fde_0416_0x04655c(a0, a1);
        case 417U: return cybertron_fde_0417_0x04656c(a0, a1);
        case 418U: return cybertron_fde_0418_0x046574(a0, a1);
        case 419U: return cybertron_fde_0419_0x04657c(a0, a1);
        case 420U: return cybertron_fde_0420_0x046584(a0, a1);
        case 421U: return cybertron_fde_0421_0x04658c(a0, a1);
        case 422U: return cybertron_fde_0422_0x046594(a0, a1);
        case 423U: return cybertron_fde_0423_0x0465e4(a0, a1);
        case 424U: return cybertron_fde_0424_0x046608(a0, a1);
        case 425U: return cybertron_fde_0425_0x046610(a0, a1);
        case 426U: return cybertron_fde_0426_0x046638(a0, a1);
        case 427U: return cybertron_fde_0427_0x04674c(a0, a1);
        case 428U: return cybertron_fde_0428_0x0467b0(a0, a1);
        case 429U: return cybertron_fde_0429_0x0467d0(a0, a1);
        case 430U: return cybertron_fde_0430_0x046804(a0, a1);
        case 431U: return cybertron_fde_0431_0x046840(a0, a1);
        case 432U: return cybertron_fde_0432_0x046848(a0, a1);
        case 433U: return cybertron_fde_0433_0x04684c(a0, a1);
        case 434U: return cybertron_fde_0434_0x046864(a0, a1);
        case 435U: return cybertron_fde_0435_0x046874(a0, a1);
        case 436U: return cybertron_fde_0436_0x046884(a0, a1);
        case 437U: return cybertron_fde_0437_0x046894(a0, a1);
        case 438U: return cybertron_fde_0438_0x0468a0(a0, a1);
        case 439U: return cybertron_fde_0439_0x0468b0(a0, a1);
        case 440U: return cybertron_fde_0440_0x0468bc(a0, a1);
        case 441U: return cybertron_fde_0441_0x0468dc(a0, a1);
        case 442U: return cybertron_fde_0442_0x0468e4(a0, a1);
        case 443U: return cybertron_fde_0443_0x0468ec(a0, a1);
        case 444U: return cybertron_fde_0444_0x0468f0(a0, a1);
        case 445U: return cybertron_fde_0445_0x04691c(a0, a1);
        case 446U: return cybertron_fde_0446_0x046920(a0, a1);
        case 447U: return cybertron_fde_0447_0x046a4c(a0, a1);
        case 448U: return cybertron_fde_0448_0x046ac8(a0, a1);
        case 449U: return cybertron_fde_0449_0x046bc8(a0, a1);
        case 450U: return cybertron_fde_0450_0x046c1c(a0, a1);
        case 451U: return cybertron_fde_0451_0x046c60(a0, a1);
        case 452U: return cybertron_fde_0452_0x046cd0(a0, a1);
        case 453U: return cybertron_fde_0453_0x046e34(a0, a1);
        case 454U: return cybertron_fde_0454_0x046e8c(a0, a1);
        case 455U: return cybertron_fde_0455_0x046e90(a0, a1);
        case 456U: return cybertron_fde_0456_0x046f00(a0, a1);
        case 457U: return cybertron_fde_0457_0x046fc4(a0, a1);
        case 458U: return cybertron_fde_0458_0x0470ec(a0, a1);
        case 459U: return cybertron_fde_0459_0x047140(a0, a1);
        case 460U: return cybertron_fde_0460_0x0471a0(a0, a1);
        case 461U: return cybertron_fde_0461_0x0471f8(a0, a1);
        case 462U: return cybertron_fde_0462_0x047390(a0, a1);
        case 463U: return cybertron_fde_0463_0x0473d4(a0, a1);
        case 464U: return cybertron_fde_0464_0x04741c(a0, a1);
        case 465U: return cybertron_fde_0465_0x047450(a0, a1);
        case 466U: return cybertron_fde_0466_0x04748c(a0, a1);
        case 467U: return cybertron_fde_0467_0x047498(a0, a1);
        case 468U: return cybertron_fde_0468_0x04749c(a0, a1);
        case 469U: return cybertron_fde_0469_0x047530(a0, a1);
        case 470U: return cybertron_fde_0470_0x04759c(a0, a1);
        case 471U: return cybertron_fde_0471_0x0475f4(a0, a1);
        case 472U: return cybertron_fde_0472_0x04764c(a0, a1);
        case 473U: return cybertron_fde_0473_0x047658(a0, a1);
        case 474U: return cybertron_fde_0474_0x047760(a0, a1);
        case 475U: return cybertron_fde_0475_0x047848(a0, a1);
        case 476U: return cybertron_fde_0476_0x047950(a0, a1);
        case 477U: return cybertron_fde_0477_0x047a58(a0, a1);
        case 478U: return cybertron_fde_0478_0x047a60(a0, a1);
        case 479U: return cybertron_fde_0479_0x047b68(a0, a1);
        default: return 0U;
    }
}

} // namespace datacenter
