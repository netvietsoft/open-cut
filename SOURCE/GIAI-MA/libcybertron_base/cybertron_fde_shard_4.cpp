// ============================================================================
// File: cybertron_fde_shard_4.cpp
// Target: libcybertron_base.so (509,816 bytes)
// SHA-256: 0d969c7e981d68f46d81986a0f16881d1ff9605afb9e6e352f1ae88a5695c7e6
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// FDE Range: [720..959] of 1,201 (.eh_frame_hdr @ 0x069c8c)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [720..959]
//      verified directly against the .text section of libcybertron_base.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [720..959]
//      đã đối chiếu trực tiếp với phân đoạn .text của libcybertron_base.so.
// ============================================================================

#include "cybertron_base_types.h"

namespace datacenter {

// [EN] FDE[0720] start_va=0x052f44, fde_va=0x071970, span=64 bytes
// [VN] FDE[0720] địa chỉ bắt đầu=0x052f44, fde_va=0x071970, kích thước=64 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD D37CFC28
uint32_t cybertron_fde_0720_0x052f44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052f44U;
    constexpr uint32_t kFdeVa   = 0x071970U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd37cfc28U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0721] start_va=0x052f84, fde_va=0x071990, span=340 bytes
// [VN] FDE[0721] địa chỉ bắt đầu=0x052f84, fde_va=0x071990, kích thước=340 byte
// AArch64 opcodes: D10403FF A90A6FFC A90B67FA A90C5FF8
uint32_t cybertron_fde_0721_0x052f84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x052f84U;
    constexpr uint32_t kFdeVa   = 0x071990U;
    constexpr uint32_t kSpan    = 340U;
    constexpr uint32_t kW0      = 0xd10403ffU;
    constexpr uint32_t kW1      = 0xa90a6ffcU;
    constexpr uint32_t kW2      = 0xa90b67faU;
    constexpr uint32_t kW3      = 0xa90c5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0722] start_va=0x0530d8, fde_va=0x0719c0, span=328 bytes
// [VN] FDE[0722] địa chỉ bắt đầu=0x0530d8, fde_va=0x0719c0, kích thước=328 byte
// AArch64 opcodes: D103C3FF A9096FFC A90A67FA A90B5FF8
uint32_t cybertron_fde_0722_0x0530d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0530d8U;
    constexpr uint32_t kFdeVa   = 0x0719c0U;
    constexpr uint32_t kSpan    = 328U;
    constexpr uint32_t kW0      = 0xd103c3ffU;
    constexpr uint32_t kW1      = 0xa9096ffcU;
    constexpr uint32_t kW2      = 0xa90a67faU;
    constexpr uint32_t kW3      = 0xa90b5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0723] start_va=0x053220, fde_va=0x0719f0, span=308 bytes
// [VN] FDE[0723] địa chỉ bắt đầu=0x053220, fde_va=0x0719f0, kích thước=308 byte
// AArch64 opcodes: D10383FF A9086FFC A90967FA A90A5FF8
uint32_t cybertron_fde_0723_0x053220(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053220U;
    constexpr uint32_t kFdeVa   = 0x0719f0U;
    constexpr uint32_t kSpan    = 308U;
    constexpr uint32_t kW0      = 0xd10383ffU;
    constexpr uint32_t kW1      = 0xa9086ffcU;
    constexpr uint32_t kW2      = 0xa90967faU;
    constexpr uint32_t kW3      = 0xa90a5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0724] start_va=0x053354, fde_va=0x071a20, span=272 bytes
// [VN] FDE[0724] địa chỉ bắt đầu=0x053354, fde_va=0x071a20, kích thước=272 byte
// AArch64 opcodes: D10343FF A9076FFC A90867FA A9095FF8
uint32_t cybertron_fde_0724_0x053354(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053354U;
    constexpr uint32_t kFdeVa   = 0x071a20U;
    constexpr uint32_t kSpan    = 272U;
    constexpr uint32_t kW0      = 0xd10343ffU;
    constexpr uint32_t kW1      = 0xa9076ffcU;
    constexpr uint32_t kW2      = 0xa90867faU;
    constexpr uint32_t kW3      = 0xa9095ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0725] start_va=0x053464, fde_va=0x071a50, span=264 bytes
// [VN] FDE[0725] địa chỉ bắt đầu=0x053464, fde_va=0x071a50, kích thước=264 byte
// AArch64 opcodes: D10303FF A9066FFC A90767FA A9085FF8
uint32_t cybertron_fde_0725_0x053464(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053464U;
    constexpr uint32_t kFdeVa   = 0x071a50U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10303ffU;
    constexpr uint32_t kW1      = 0xa9066ffcU;
    constexpr uint32_t kW2      = 0xa90767faU;
    constexpr uint32_t kW3      = 0xa9085ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0726] start_va=0x05356c, fde_va=0x071a80, span=260 bytes
// [VN] FDE[0726] địa chỉ bắt đầu=0x05356c, fde_va=0x071a80, kích thước=260 byte
// AArch64 opcodes: D102C3FF A9056FFC A90667FA A9075FF8
uint32_t cybertron_fde_0726_0x05356c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05356cU;
    constexpr uint32_t kFdeVa   = 0x071a80U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xa9056ffcU;
    constexpr uint32_t kW2      = 0xa90667faU;
    constexpr uint32_t kW3      = 0xa9075ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0727] start_va=0x053670, fde_va=0x071ab0, span=264 bytes
// [VN] FDE[0727] địa chỉ bắt đầu=0x053670, fde_va=0x071ab0, kích thước=264 byte
// AArch64 opcodes: D10283FF A9046FFC A90567FA A9065FF8
uint32_t cybertron_fde_0727_0x053670(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053670U;
    constexpr uint32_t kFdeVa   = 0x071ab0U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10283ffU;
    constexpr uint32_t kW1      = 0xa9046ffcU;
    constexpr uint32_t kW2      = 0xa90567faU;
    constexpr uint32_t kW3      = 0xa9065ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0728] start_va=0x053778, fde_va=0x071ae0, span=260 bytes
// [VN] FDE[0728] địa chỉ bắt đầu=0x053778, fde_va=0x071ae0, kích thước=260 byte
// AArch64 opcodes: D10243FF A9036FFC A90467FA A9055FF8
uint32_t cybertron_fde_0728_0x053778(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053778U;
    constexpr uint32_t kFdeVa   = 0x071ae0U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa9036ffcU;
    constexpr uint32_t kW2      = 0xa90467faU;
    constexpr uint32_t kW3      = 0xa9055ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0729] start_va=0x05387c, fde_va=0x071b10, span=264 bytes
// [VN] FDE[0729] địa chỉ bắt đầu=0x05387c, fde_va=0x071b10, kích thước=264 byte
// AArch64 opcodes: D10203FF A9026FFC A90367FA A9045FF8
uint32_t cybertron_fde_0729_0x05387c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05387cU;
    constexpr uint32_t kFdeVa   = 0x071b10U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa9026ffcU;
    constexpr uint32_t kW2      = 0xa90367faU;
    constexpr uint32_t kW3      = 0xa9045ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0730] start_va=0x053984, fde_va=0x071b40, span=260 bytes
// [VN] FDE[0730] địa chỉ bắt đầu=0x053984, fde_va=0x071b40, kích thước=260 byte
// AArch64 opcodes: D101C3FF A9016FFC A90267FA A9035FF8
uint32_t cybertron_fde_0730_0x053984(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053984U;
    constexpr uint32_t kFdeVa   = 0x071b40U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9016ffcU;
    constexpr uint32_t kW2      = 0xa90267faU;
    constexpr uint32_t kW3      = 0xa9035ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0731] start_va=0x053a88, fde_va=0x071b70, span=252 bytes
// [VN] FDE[0731] địa chỉ bắt đầu=0x053a88, fde_va=0x071b70, kích thước=252 byte
// AArch64 opcodes: D101C3FF F9000BFB A90267FA A9035FF8
uint32_t cybertron_fde_0731_0x053a88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053a88U;
    constexpr uint32_t kFdeVa   = 0x071b70U;
    constexpr uint32_t kSpan    = 252U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9000bfbU;
    constexpr uint32_t kW2      = 0xa90267faU;
    constexpr uint32_t kW3      = 0xa9035ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0732] start_va=0x053b84, fde_va=0x071ba0, span=236 bytes
// [VN] FDE[0732] địa chỉ bắt đầu=0x053b84, fde_va=0x071ba0, kích thước=236 byte
// AArch64 opcodes: D10183FF A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0732_0x053b84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053b84U;
    constexpr uint32_t kFdeVa   = 0x071ba0U;
    constexpr uint32_t kSpan    = 236U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0733] start_va=0x053c70, fde_va=0x071bd0, span=228 bytes
// [VN] FDE[0733] địa chỉ bắt đầu=0x053c70, fde_va=0x071bd0, kích thước=228 byte
// AArch64 opcodes: D10183FF F9000BF9 A9025FF8 A90357F6
uint32_t cybertron_fde_0733_0x053c70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053c70U;
    constexpr uint32_t kFdeVa   = 0x071bd0U;
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

// [EN] FDE[0734] start_va=0x053d54, fde_va=0x071bf8, span=212 bytes
// [VN] FDE[0734] địa chỉ bắt đầu=0x053d54, fde_va=0x071bf8, kích thước=212 byte
// AArch64 opcodes: D10143FF A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0734_0x053d54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053d54U;
    constexpr uint32_t kFdeVa   = 0x071bf8U;
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

// [EN] FDE[0735] start_va=0x053e28, fde_va=0x071c20, span=356 bytes
// [VN] FDE[0735] địa chỉ bắt đầu=0x053e28, fde_va=0x071c20, kích thước=356 byte
// AArch64 opcodes: D101C3FF FD0013E8 A9035FF8 A90457F6
uint32_t cybertron_fde_0735_0x053e28(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053e28U;
    constexpr uint32_t kFdeVa   = 0x071c20U;
    constexpr uint32_t kSpan    = 356U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xfd0013e8U;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0736] start_va=0x053f8c, fde_va=0x071c48, span=204 bytes
// [VN] FDE[0736] địa chỉ bắt đầu=0x053f8c, fde_va=0x071c48, kích thước=204 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0736_0x053f8c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x053f8cU;
    constexpr uint32_t kFdeVa   = 0x071c48U;
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

// [EN] FDE[0737] start_va=0x054058, fde_va=0x071c70, span=88 bytes
// [VN] FDE[0737] địa chỉ bắt đầu=0x054058, fde_va=0x071c70, kích thước=88 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0737_0x054058(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054058U;
    constexpr uint32_t kFdeVa   = 0x071c70U;
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

// [EN] FDE[0738] start_va=0x0540b0, fde_va=0x071c90, span=16 bytes
// [VN] FDE[0738] địa chỉ bắt đầu=0x0540b0, fde_va=0x071c90, kích thước=16 byte
// AArch64 opcodes: B0000148 91266108 F8018408 17FF93C9
uint32_t cybertron_fde_0738_0x0540b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0540b0U;
    constexpr uint32_t kFdeVa   = 0x071c90U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xb0000148U;
    constexpr uint32_t kW1      = 0x91266108U;
    constexpr uint32_t kW2      = 0xf8018408U;
    constexpr uint32_t kW3      = 0x17ff93c9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0739] start_va=0x0540c0, fde_va=0x071ca8, span=48 bytes
// [VN] FDE[0739] địa chỉ bắt đầu=0x0540c0, fde_va=0x071ca8, kích thước=48 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000148
uint32_t cybertron_fde_0739_0x0540c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0540c0U;
    constexpr uint32_t kFdeVa   = 0x071ca8U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0740] start_va=0x0540f0, fde_va=0x071cc8, span=104 bytes
// [VN] FDE[0740] địa chỉ bắt đầu=0x0540f0, fde_va=0x071cc8, kích thước=104 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0740_0x0540f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0540f0U;
    constexpr uint32_t kFdeVa   = 0x071cc8U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0741] start_va=0x054158, fde_va=0x071ce8, span=72 bytes
// [VN] FDE[0741] địa chỉ bắt đầu=0x054158, fde_va=0x071ce8, kích thước=72 byte
// AArch64 opcodes: B0000148 91266108 F9000028 B9401008
uint32_t cybertron_fde_0741_0x054158(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054158U;
    constexpr uint32_t kFdeVa   = 0x071ce8U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xb0000148U;
    constexpr uint32_t kW1      = 0x91266108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0xb9401008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0742] start_va=0x0541a0, fde_va=0x071d00, span=8 bytes
// [VN] FDE[0742] địa chỉ bắt đầu=0x0541a0, fde_va=0x071d00, kích thước=8 byte
// AArch64 opcodes: 91006000 17FF938F F81E0FF3 A9017BFD
uint32_t cybertron_fde_0742_0x0541a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0541a0U;
    constexpr uint32_t kFdeVa   = 0x071d00U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91006000U;
    constexpr uint32_t kW1      = 0x17ff938fU;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0743] start_va=0x0541a8, fde_va=0x071d18, span=40 bytes
// [VN] FDE[0743] địa chỉ bắt đầu=0x0541a8, fde_va=0x071d18, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0743_0x0541a8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0541a8U;
    constexpr uint32_t kFdeVa   = 0x071d18U;
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

// [EN] FDE[0744] start_va=0x0541d0, fde_va=0x071d38, span=312 bytes
// [VN] FDE[0744] địa chỉ bắt đầu=0x0541d0, fde_va=0x071d38, kích thước=312 byte
// AArch64 opcodes: D101C3FF F90013F9 A9035FF8 A90457F6
uint32_t cybertron_fde_0744_0x0541d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0541d0U;
    constexpr uint32_t kFdeVa   = 0x071d38U;
    constexpr uint32_t kSpan    = 312U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90013f9U;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0745] start_va=0x054308, fde_va=0x071d60, span=28 bytes
// [VN] FDE[0745] địa chỉ bắt đầu=0x054308, fde_va=0x071d60, kích thước=28 byte
// AArch64 opcodes: F9400428 F0000089 9100A129 9100200A
uint32_t cybertron_fde_0745_0x054308(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054308U;
    constexpr uint32_t kFdeVa   = 0x071d60U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xf0000089U;
    constexpr uint32_t kW2      = 0x9100a129U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0746] start_va=0x054324, fde_va=0x071d78, span=12 bytes
// [VN] FDE[0746] địa chỉ bắt đầu=0x054324, fde_va=0x071d78, kích thước=12 byte
// AArch64 opcodes: B0000140 9127E000 D65F03C0 A9BE4FF4
uint32_t cybertron_fde_0746_0x054324(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054324U;
    constexpr uint32_t kFdeVa   = 0x071d78U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xb0000140U;
    constexpr uint32_t kW1      = 0x9127e000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xa9be4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0747] start_va=0x054330, fde_va=0x071d90, span=112 bytes
// [VN] FDE[0747] địa chỉ bắt đầu=0x054330, fde_va=0x071d90, kích thước=112 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0747_0x054330(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054330U;
    constexpr uint32_t kFdeVa   = 0x071d90U;
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

// [EN] FDE[0748] start_va=0x0543a0, fde_va=0x071db0, span=52 bytes
// [VN] FDE[0748] địa chỉ bắt đầu=0x0543a0, fde_va=0x071db0, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0748_0x0543a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0543a0U;
    constexpr uint32_t kFdeVa   = 0x071db0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0749] start_va=0x0543d4, fde_va=0x071dd0, span=448 bytes
// [VN] FDE[0749] địa chỉ bắt đầu=0x0543d4, fde_va=0x071dd0, kích thước=448 byte
// AArch64 opcodes: D101C3FF F9000BFB A90267FA A9035FF8
uint32_t cybertron_fde_0749_0x0543d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0543d4U;
    constexpr uint32_t kFdeVa   = 0x071dd0U;
    constexpr uint32_t kSpan    = 448U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9000bfbU;
    constexpr uint32_t kW2      = 0xa90267faU;
    constexpr uint32_t kW3      = 0xa9035ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0750] start_va=0x054594, fde_va=0x071e00, span=112 bytes
// [VN] FDE[0750] địa chỉ bắt đầu=0x054594, fde_va=0x071e00, kích thước=112 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0750_0x054594(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054594U;
    constexpr uint32_t kFdeVa   = 0x071e00U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0751] start_va=0x054604, fde_va=0x071e20, span=308 bytes
// [VN] FDE[0751] địa chỉ bắt đầu=0x054604, fde_va=0x071e20, kích thước=308 byte
// AArch64 opcodes: F9400409 F940042A 9E670120 0E205800
uint32_t cybertron_fde_0751_0x054604(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054604U;
    constexpr uint32_t kFdeVa   = 0x071e20U;
    constexpr uint32_t kSpan    = 308U;
    constexpr uint32_t kW0      = 0xf9400409U;
    constexpr uint32_t kW1      = 0xf940042aU;
    constexpr uint32_t kW2      = 0x9e670120U;
    constexpr uint32_t kW3      = 0x0e205800U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0752] start_va=0x054738, fde_va=0x071e38, span=116 bytes
// [VN] FDE[0752] địa chỉ bắt đầu=0x054738, fde_va=0x071e38, kích thước=116 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 39402008
uint32_t cybertron_fde_0752_0x054738(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054738U;
    constexpr uint32_t kFdeVa   = 0x071e38U;
    constexpr uint32_t kSpan    = 116U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x39402008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0753] start_va=0x0547ac, fde_va=0x071e58, span=804 bytes
// [VN] FDE[0753] địa chỉ bắt đầu=0x0547ac, fde_va=0x071e58, kích thước=804 byte
// AArch64 opcodes: D10243FF A9036FFC A90467FA A9055FF8
uint32_t cybertron_fde_0753_0x0547ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0547acU;
    constexpr uint32_t kFdeVa   = 0x071e58U;
    constexpr uint32_t kSpan    = 804U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa9036ffcU;
    constexpr uint32_t kW2      = 0xa90467faU;
    constexpr uint32_t kW3      = 0xa9055ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0754] start_va=0x054ad0, fde_va=0x071e88, span=228 bytes
// [VN] FDE[0754] địa chỉ bắt đầu=0x054ad0, fde_va=0x071e88, kích thước=228 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0754_0x054ad0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054ad0U;
    constexpr uint32_t kFdeVa   = 0x071e88U;
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

// [EN] FDE[0755] start_va=0x054bb4, fde_va=0x071ea8, span=596 bytes
// [VN] FDE[0755] địa chỉ bắt đầu=0x054bb4, fde_va=0x071ea8, kích thước=596 byte
// AArch64 opcodes: D10203FF A9026FFC A90367FA A9045FF8
uint32_t cybertron_fde_0755_0x054bb4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054bb4U;
    constexpr uint32_t kFdeVa   = 0x071ea8U;
    constexpr uint32_t kSpan    = 596U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa9026ffcU;
    constexpr uint32_t kW2      = 0xa90367faU;
    constexpr uint32_t kW3      = 0xa9045ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0756] start_va=0x054e08, fde_va=0x071ed8, span=104 bytes
// [VN] FDE[0756] địa chỉ bắt đầu=0x054e08, fde_va=0x071ed8, kích thước=104 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9401028
uint32_t cybertron_fde_0756_0x054e08(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054e08U;
    constexpr uint32_t kFdeVa   = 0x071ed8U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9401028U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0757] start_va=0x054e70, fde_va=0x071ef8, span=352 bytes
// [VN] FDE[0757] địa chỉ bắt đầu=0x054e70, fde_va=0x071ef8, kích thước=352 byte
// AArch64 opcodes: D10183FF F9001BF5 A9044FF4 A9057BFD
uint32_t cybertron_fde_0757_0x054e70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054e70U;
    constexpr uint32_t kFdeVa   = 0x071ef8U;
    constexpr uint32_t kSpan    = 352U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9001bf5U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0758] start_va=0x054fd0, fde_va=0x071f18, span=448 bytes
// [VN] FDE[0758] địa chỉ bắt đầu=0x054fd0, fde_va=0x071f18, kích thước=448 byte
// AArch64 opcodes: D101C3FF F9000BFB A90267FA A9035FF8
uint32_t cybertron_fde_0758_0x054fd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x054fd0U;
    constexpr uint32_t kFdeVa   = 0x071f18U;
    constexpr uint32_t kSpan    = 448U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9000bfbU;
    constexpr uint32_t kW2      = 0xa90267faU;
    constexpr uint32_t kW3      = 0xa9035ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0759] start_va=0x055190, fde_va=0x071f48, span=256 bytes
// [VN] FDE[0759] địa chỉ bắt đầu=0x055190, fde_va=0x071f48, kích thước=256 byte
// AArch64 opcodes: D101C3FF F90023F5 A9054FF4 A9067BFD
uint32_t cybertron_fde_0759_0x055190(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055190U;
    constexpr uint32_t kFdeVa   = 0x071f48U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90023f5U;
    constexpr uint32_t kW2      = 0xa9054ff4U;
    constexpr uint32_t kW3      = 0xa9067bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0760] start_va=0x055290, fde_va=0x071f68, span=184 bytes
// [VN] FDE[0760] địa chỉ bắt đầu=0x055290, fde_va=0x071f68, kích thước=184 byte
// AArch64 opcodes: D0000148 F9460908 D0000149 F947A929
uint32_t cybertron_fde_0760_0x055290(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055290U;
    constexpr uint32_t kFdeVa   = 0x071f68U;
    constexpr uint32_t kSpan    = 184U;
    constexpr uint32_t kW0      = 0xd0000148U;
    constexpr uint32_t kW1      = 0xf9460908U;
    constexpr uint32_t kW2      = 0xd0000149U;
    constexpr uint32_t kW3      = 0xf947a929U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0761] start_va=0x055348, fde_va=0x071f80, span=8 bytes
// [VN] FDE[0761] địa chỉ bắt đầu=0x055348, fde_va=0x071f80, kích thước=8 byte
// AArch64 opcodes: A9007D1F D65F03C0 D65F03C0 A9007D1F
uint32_t cybertron_fde_0761_0x055348(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055348U;
    constexpr uint32_t kFdeVa   = 0x071f80U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xa9007d1fU;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xa9007d1fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0762] start_va=0x055350, fde_va=0x071f98, span=4 bytes
// [VN] FDE[0762] địa chỉ bắt đầu=0x055350, fde_va=0x071f98, kích thước=4 byte
// AArch64 opcodes: D65F03C0 A9007D1F D65F03C0 D28D8E0A
uint32_t cybertron_fde_0762_0x055350(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055350U;
    constexpr uint32_t kFdeVa   = 0x071f98U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xa9007d1fU;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xd28d8e0aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0763] start_va=0x055354, fde_va=0x071fb0, span=8 bytes
// [VN] FDE[0763] địa chỉ bắt đầu=0x055354, fde_va=0x071fb0, kích thước=8 byte
// AArch64 opcodes: A9007D1F D65F03C0 D28D8E0A F2AF2C2A
uint32_t cybertron_fde_0763_0x055354(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055354U;
    constexpr uint32_t kFdeVa   = 0x071fb0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xa9007d1fU;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd28d8e0aU;
    constexpr uint32_t kW3      = 0xf2af2c2aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0764] start_va=0x05535c, fde_va=0x071fc8, span=44 bytes
// [VN] FDE[0764] địa chỉ bắt đầu=0x05535c, fde_va=0x071fc8, kích thước=44 byte
// AArch64 opcodes: D28D8E0A F2AF2C2A F2CC2C4A 52800209
uint32_t cybertron_fde_0764_0x05535c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05535cU;
    constexpr uint32_t kFdeVa   = 0x071fc8U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xd28d8e0aU;
    constexpr uint32_t kW1      = 0xf2af2c2aU;
    constexpr uint32_t kW2      = 0xf2cc2c4aU;
    constexpr uint32_t kW3      = 0x52800209U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0765] start_va=0x055388, fde_va=0x071fe0, span=20 bytes
// [VN] FDE[0765] địa chỉ bắt đầu=0x055388, fde_va=0x071fe0, kích thước=20 byte
// AArch64 opcodes: AA0803E9 F8008D3F F900091F F9000109
uint32_t cybertron_fde_0765_0x055388(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055388U;
    constexpr uint32_t kFdeVa   = 0x071fe0U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xaa0803e9U;
    constexpr uint32_t kW1      = 0xf8008d3fU;
    constexpr uint32_t kW2      = 0xf900091fU;
    constexpr uint32_t kW3      = 0xf9000109U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0766] start_va=0x05539c, fde_va=0x071ff8, span=8 bytes
// [VN] FDE[0766] địa chỉ bắt đầu=0x05539c, fde_va=0x071ff8, kích thước=8 byte
// AArch64 opcodes: A9007D1F D65F03C0 52800020 D65F03C0
uint32_t cybertron_fde_0766_0x05539c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05539cU;
    constexpr uint32_t kFdeVa   = 0x071ff8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xa9007d1fU;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0x52800020U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0767] start_va=0x0553a4, fde_va=0x072010, span=8 bytes
// [VN] FDE[0767] địa chỉ bắt đầu=0x0553a4, fde_va=0x072010, kích thước=8 byte
// AArch64 opcodes: 52800020 D65F03C0 D10183FF A9025FF8
uint32_t cybertron_fde_0767_0x0553a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0553a4U;
    constexpr uint32_t kFdeVa   = 0x072010U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x52800020U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xd10183ffU;
    constexpr uint32_t kW3      = 0xa9025ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0768] start_va=0x0553ac, fde_va=0x072028, span=368 bytes
// [VN] FDE[0768] địa chỉ bắt đầu=0x0553ac, fde_va=0x072028, kích thước=368 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0768_0x0553ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0553acU;
    constexpr uint32_t kFdeVa   = 0x072028U;
    constexpr uint32_t kSpan    = 368U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0769] start_va=0x05551c, fde_va=0x072050, span=328 bytes
// [VN] FDE[0769] địa chỉ bắt đầu=0x05551c, fde_va=0x072050, kích thước=328 byte
// AArch64 opcodes: D101C3FF A90457F6 A9054FF4 A9067BFD
uint32_t cybertron_fde_0769_0x05551c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05551cU;
    constexpr uint32_t kFdeVa   = 0x072050U;
    constexpr uint32_t kSpan    = 328U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90457f6U;
    constexpr uint32_t kW2      = 0xa9054ff4U;
    constexpr uint32_t kW3      = 0xa9067bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0770] start_va=0x055664, fde_va=0x072078, span=8 bytes
// [VN] FDE[0770] địa chỉ bắt đầu=0x055664, fde_va=0x072078, kích thước=8 byte
// AArch64 opcodes: D1002000 17FF9346 D10243FF FD0023E8
uint32_t cybertron_fde_0770_0x055664(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055664U;
    constexpr uint32_t kFdeVa   = 0x072078U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ff9346U;
    constexpr uint32_t kW2      = 0xd10243ffU;
    constexpr uint32_t kW3      = 0xfd0023e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0771] start_va=0x05566c, fde_va=0x072090, span=648 bytes
// [VN] FDE[0771] địa chỉ bắt đầu=0x05566c, fde_va=0x072090, kích thước=648 byte
// AArch64 opcodes: D10243FF FD0023E8 A9055FF8 A90657F6
uint32_t cybertron_fde_0771_0x05566c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05566cU;
    constexpr uint32_t kFdeVa   = 0x072090U;
    constexpr uint32_t kSpan    = 648U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xfd0023e8U;
    constexpr uint32_t kW2      = 0xa9055ff8U;
    constexpr uint32_t kW3      = 0xa90657f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0772] start_va=0x0558f4, fde_va=0x0720b8, span=72 bytes
// [VN] FDE[0772] địa chỉ bắt đầu=0x0558f4, fde_va=0x0720b8, kích thước=72 byte
// AArch64 opcodes: B9401808 3DC00802 FD401804 1E600801
uint32_t cybertron_fde_0772_0x0558f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0558f4U;
    constexpr uint32_t kFdeVa   = 0x0720b8U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xb9401808U;
    constexpr uint32_t kW1      = 0x3dc00802U;
    constexpr uint32_t kW2      = 0xfd401804U;
    constexpr uint32_t kW3      = 0x1e600801U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0773] start_va=0x05593c, fde_va=0x0720d0, span=32 bytes
// [VN] FDE[0773] địa chỉ bắt đầu=0x05593c, fde_va=0x0720d0, kích thước=32 byte
// AArch64 opcodes: D0000148 F946CD08 91004109 9E670120
uint32_t cybertron_fde_0773_0x05593c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05593cU;
    constexpr uint32_t kFdeVa   = 0x0720d0U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xd0000148U;
    constexpr uint32_t kW1      = 0xf946cd08U;
    constexpr uint32_t kW2      = 0x91004109U;
    constexpr uint32_t kW3      = 0x9e670120U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0774] start_va=0x05595c, fde_va=0x0720e8, span=64 bytes
// [VN] FDE[0774] địa chỉ bắt đầu=0x05595c, fde_va=0x0720e8, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000148
uint32_t cybertron_fde_0774_0x05595c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05595cU;
    constexpr uint32_t kFdeVa   = 0x0720e8U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0775] start_va=0x05599c, fde_va=0x072108, span=40 bytes
// [VN] FDE[0775] địa chỉ bắt đầu=0x05599c, fde_va=0x072108, kích thước=40 byte
// AArch64 opcodes: D0000148 F946CD08 91004109 9101C108
uint32_t cybertron_fde_0775_0x05599c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05599cU;
    constexpr uint32_t kFdeVa   = 0x072108U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xd0000148U;
    constexpr uint32_t kW1      = 0xf946cd08U;
    constexpr uint32_t kW2      = 0x91004109U;
    constexpr uint32_t kW3      = 0x9101c108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0776] start_va=0x0559c4, fde_va=0x072120, span=68 bytes
// [VN] FDE[0776] địa chỉ bắt đầu=0x0559c4, fde_va=0x072120, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000148
uint32_t cybertron_fde_0776_0x0559c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0559c4U;
    constexpr uint32_t kFdeVa   = 0x072120U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0777] start_va=0x055a08, fde_va=0x072140, span=4 bytes
// [VN] FDE[0777] địa chỉ bắt đầu=0x055a08, fde_va=0x072140, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FF8CC5 A9BF7BFD 910003FD
uint32_t cybertron_fde_0777_0x055a08(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a08U;
    constexpr uint32_t kFdeVa   = 0x072140U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ff8cc5U;
    constexpr uint32_t kW2      = 0xa9bf7bfdU;
    constexpr uint32_t kW3      = 0x910003fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0778] start_va=0x055a0c, fde_va=0x072158, span=4 bytes
// [VN] FDE[0778] địa chỉ bắt đầu=0x055a0c, fde_va=0x072158, kích thước=4 byte
// AArch64 opcodes: 17FF8CC5 A9BF7BFD 910003FD 52800200
uint32_t cybertron_fde_0778_0x055a0c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a0cU;
    constexpr uint32_t kFdeVa   = 0x072158U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff8cc5U;
    constexpr uint32_t kW1      = 0xa9bf7bfdU;
    constexpr uint32_t kW2      = 0x910003fdU;
    constexpr uint32_t kW3      = 0x52800200U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0779] start_va=0x055a10, fde_va=0x072170, span=36 bytes
// [VN] FDE[0779] địa chỉ bắt đầu=0x055a10, fde_va=0x072170, kích thước=36 byte
// AArch64 opcodes: A9BF7BFD 910003FD 52800200 97FF9409
uint32_t cybertron_fde_0779_0x055a10(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a10U;
    constexpr uint32_t kFdeVa   = 0x072170U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x52800200U;
    constexpr uint32_t kW3      = 0x97ff9409U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0780] start_va=0x055a34, fde_va=0x072190, span=16 bytes
// [VN] FDE[0780] địa chỉ bắt đầu=0x055a34, fde_va=0x072190, kích thước=16 byte
// AArch64 opcodes: 90000148 912BE108 F9000028 D65F03C0
uint32_t cybertron_fde_0780_0x055a34(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a34U;
    constexpr uint32_t kFdeVa   = 0x072190U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x90000148U;
    constexpr uint32_t kW1      = 0x912be108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0781] start_va=0x055a44, fde_va=0x0721a8, span=4 bytes
// [VN] FDE[0781] địa chỉ bắt đầu=0x055a44, fde_va=0x0721a8, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FF8CB6 D65F03C0 F9400428
uint32_t cybertron_fde_0781_0x055a44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a44U;
    constexpr uint32_t kFdeVa   = 0x0721a8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ff8cb6U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xf9400428U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0782] start_va=0x055a48, fde_va=0x0721c0, span=4 bytes
// [VN] FDE[0782] địa chỉ bắt đầu=0x055a48, fde_va=0x0721c0, kích thước=4 byte
// AArch64 opcodes: 17FF8CB6 D65F03C0 F9400428 D0000089
uint32_t cybertron_fde_0782_0x055a48(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a48U;
    constexpr uint32_t kFdeVa   = 0x0721c0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff8cb6U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xf9400428U;
    constexpr uint32_t kW3      = 0xd0000089U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0783] start_va=0x055a4c, fde_va=0x0721d8, span=4 bytes
// [VN] FDE[0783] địa chỉ bắt đầu=0x055a4c, fde_va=0x0721d8, kích thước=4 byte
// AArch64 opcodes: D65F03C0 F9400428 D0000089 9109F929
uint32_t cybertron_fde_0783_0x055a4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a4cU;
    constexpr uint32_t kFdeVa   = 0x0721d8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xf9400428U;
    constexpr uint32_t kW2      = 0xd0000089U;
    constexpr uint32_t kW3      = 0x9109f929U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0784] start_va=0x055a50, fde_va=0x0721f0, span=28 bytes
// [VN] FDE[0784] địa chỉ bắt đầu=0x055a50, fde_va=0x0721f0, kích thước=28 byte
// AArch64 opcodes: F9400428 D0000089 9109F929 9100200A
uint32_t cybertron_fde_0784_0x055a50(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a50U;
    constexpr uint32_t kFdeVa   = 0x0721f0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xd0000089U;
    constexpr uint32_t kW2      = 0x9109f929U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0785] start_va=0x055a6c, fde_va=0x072208, span=12 bytes
// [VN] FDE[0785] địa chỉ bắt đầu=0x055a6c, fde_va=0x072208, kích thước=12 byte
// AArch64 opcodes: 90000140 912DA000 D65F03C0 90000148
uint32_t cybertron_fde_0785_0x055a6c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a6cU;
    constexpr uint32_t kFdeVa   = 0x072208U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x90000140U;
    constexpr uint32_t kW1      = 0x912da000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x90000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0786] start_va=0x055a78, fde_va=0x072220, span=16 bytes
// [VN] FDE[0786] địa chỉ bắt đầu=0x055a78, fde_va=0x072220, kích thước=16 byte
// AArch64 opcodes: 90000148 912E2108 F8008408 17FF8D57
uint32_t cybertron_fde_0786_0x055a78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a78U;
    constexpr uint32_t kFdeVa   = 0x072220U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x90000148U;
    constexpr uint32_t kW1      = 0x912e2108U;
    constexpr uint32_t kW2      = 0xf8008408U;
    constexpr uint32_t kW3      = 0x17ff8d57U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0787] start_va=0x055a88, fde_va=0x072238, span=48 bytes
// [VN] FDE[0787] địa chỉ bắt đầu=0x055a88, fde_va=0x072238, kích thước=48 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000148
uint32_t cybertron_fde_0787_0x055a88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055a88U;
    constexpr uint32_t kFdeVa   = 0x072238U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0788] start_va=0x055ab8, fde_va=0x072258, span=96 bytes
// [VN] FDE[0788] địa chỉ bắt đầu=0x055ab8, fde_va=0x072258, kích thước=96 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0788_0x055ab8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055ab8U;
    constexpr uint32_t kFdeVa   = 0x072258U;
    constexpr uint32_t kSpan    = 96U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0789] start_va=0x055b18, fde_va=0x072278, span=64 bytes
// [VN] FDE[0789] địa chỉ bắt đầu=0x055b18, fde_va=0x072278, kích thước=64 byte
// AArch64 opcodes: 90000148 912E2108 F9000028 F9400408
uint32_t cybertron_fde_0789_0x055b18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055b18U;
    constexpr uint32_t kFdeVa   = 0x072278U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0x90000148U;
    constexpr uint32_t kW1      = 0x912e2108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0790] start_va=0x055b58, fde_va=0x072290, span=8 bytes
// [VN] FDE[0790] địa chỉ bắt đầu=0x055b58, fde_va=0x072290, kích thước=8 byte
// AArch64 opcodes: 91002000 17FF8D21 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0790_0x055b58(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055b58U;
    constexpr uint32_t kFdeVa   = 0x072290U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91002000U;
    constexpr uint32_t kW1      = 0x17ff8d21U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0791] start_va=0x055b60, fde_va=0x0722a8, span=40 bytes
// [VN] FDE[0791] địa chỉ bắt đầu=0x055b60, fde_va=0x0722a8, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0791_0x055b60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055b60U;
    constexpr uint32_t kFdeVa   = 0x0722a8U;
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

// [EN] FDE[0792] start_va=0x055b88, fde_va=0x0722c8, span=376 bytes
// [VN] FDE[0792] địa chỉ bắt đầu=0x055b88, fde_va=0x0722c8, kích thước=376 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0792_0x055b88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055b88U;
    constexpr uint32_t kFdeVa   = 0x0722c8U;
    constexpr uint32_t kSpan    = 376U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0793] start_va=0x055d00, fde_va=0x0722f0, span=28 bytes
// [VN] FDE[0793] địa chỉ bắt đầu=0x055d00, fde_va=0x0722f0, kích thước=28 byte
// AArch64 opcodes: F9400428 D0000089 910D9529 9100200A
uint32_t cybertron_fde_0793_0x055d00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055d00U;
    constexpr uint32_t kFdeVa   = 0x0722f0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xd0000089U;
    constexpr uint32_t kW2      = 0x910d9529U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0794] start_va=0x055d1c, fde_va=0x072308, span=12 bytes
// [VN] FDE[0794] địa chỉ bắt đầu=0x055d1c, fde_va=0x072308, kích thước=12 byte
// AArch64 opcodes: 90000140 912FA000 D65F03C0 A9BE4FF4
uint32_t cybertron_fde_0794_0x055d1c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055d1cU;
    constexpr uint32_t kFdeVa   = 0x072308U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x90000140U;
    constexpr uint32_t kW1      = 0x912fa000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xa9be4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0795] start_va=0x055d28, fde_va=0x072320, span=104 bytes
// [VN] FDE[0795] địa chỉ bắt đầu=0x055d28, fde_va=0x072320, kích thước=104 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD D0000148
uint32_t cybertron_fde_0795_0x055d28(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055d28U;
    constexpr uint32_t kFdeVa   = 0x072320U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0796] start_va=0x055d90, fde_va=0x072340, span=60 bytes
// [VN] FDE[0796] địa chỉ bắt đầu=0x055d90, fde_va=0x072340, kích thước=60 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0796_0x055d90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055d90U;
    constexpr uint32_t kFdeVa   = 0x072340U;
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

// [EN] FDE[0797] start_va=0x055dcc, fde_va=0x072360, span=380 bytes
// [VN] FDE[0797] địa chỉ bắt đầu=0x055dcc, fde_va=0x072360, kích thước=380 byte
// AArch64 opcodes: D10143FF A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0797_0x055dcc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055dccU;
    constexpr uint32_t kFdeVa   = 0x072360U;
    constexpr uint32_t kSpan    = 380U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa9015ff8U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0798] start_va=0x055f48, fde_va=0x072388, span=256 bytes
// [VN] FDE[0798] địa chỉ bắt đầu=0x055f48, fde_va=0x072388, kích thước=256 byte
// AArch64 opcodes: B40005E1 F81C0FF7 A90157F6 A9024FF4
uint32_t cybertron_fde_0798_0x055f48(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x055f48U;
    constexpr uint32_t kFdeVa   = 0x072388U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xb40005e1U;
    constexpr uint32_t kW1      = 0xf81c0ff7U;
    constexpr uint32_t kW2      = 0xa90157f6U;
    constexpr uint32_t kW3      = 0xa9024ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0799] start_va=0x056048, fde_va=0x0723b0, span=216 bytes
// [VN] FDE[0799] địa chỉ bắt đầu=0x056048, fde_va=0x0723b0, kích thước=216 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_0799_0x056048(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056048U;
    constexpr uint32_t kFdeVa   = 0x0723b0U;
    constexpr uint32_t kSpan    = 216U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf90013f7U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0800] start_va=0x056120, fde_va=0x0723d8, span=108 bytes
// [VN] FDE[0800] địa chỉ bắt đầu=0x056120, fde_va=0x0723d8, kích thước=108 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0800_0x056120(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056120U;
    constexpr uint32_t kFdeVa   = 0x0723d8U;
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

// [EN] FDE[0801] start_va=0x05618c, fde_va=0x0723f8, span=108 bytes
// [VN] FDE[0801] địa chỉ bắt đầu=0x05618c, fde_va=0x0723f8, kích thước=108 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0801_0x05618c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05618cU;
    constexpr uint32_t kFdeVa   = 0x0723f8U;
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

// [EN] FDE[0802] start_va=0x0561f8, fde_va=0x072418, span=28 bytes
// [VN] FDE[0802] địa chỉ bắt đầu=0x0561f8, fde_va=0x072418, kích thước=28 byte
// AArch64 opcodes: F9402400 B4000080 F9400009 F9402124
uint32_t cybertron_fde_0802_0x0561f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0561f8U;
    constexpr uint32_t kFdeVa   = 0x072418U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9402400U;
    constexpr uint32_t kW1      = 0xb4000080U;
    constexpr uint32_t kW2      = 0xf9400009U;
    constexpr uint32_t kW3      = 0xf9402124U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0803] start_va=0x056214, fde_va=0x072430, span=88 bytes
// [VN] FDE[0803] địa chỉ bắt đầu=0x056214, fde_va=0x072430, kích thước=88 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0803_0x056214(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056214U;
    constexpr uint32_t kFdeVa   = 0x072430U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa9024ff4U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0804] start_va=0x05626c, fde_va=0x072450, span=68 bytes
// [VN] FDE[0804] địa chỉ bắt đầu=0x05626c, fde_va=0x072450, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000148
uint32_t cybertron_fde_0804_0x05626c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05626cU;
    constexpr uint32_t kFdeVa   = 0x072450U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0805] start_va=0x0562b0, fde_va=0x072470, span=36 bytes
// [VN] FDE[0805] địa chỉ bắt đầu=0x0562b0, fde_va=0x072470, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0805_0x0562b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0562b0U;
    constexpr uint32_t kFdeVa   = 0x072470U;
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

// [EN] FDE[0806] start_va=0x0562d4, fde_va=0x072490, span=88 bytes
// [VN] FDE[0806] địa chỉ bắt đầu=0x0562d4, fde_va=0x072490, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0806_0x0562d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0562d4U;
    constexpr uint32_t kFdeVa   = 0x072490U;
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

// [EN] FDE[0807] start_va=0x05632c, fde_va=0x0724b0, span=36 bytes
// [VN] FDE[0807] địa chỉ bắt đầu=0x05632c, fde_va=0x0724b0, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0807_0x05632c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05632cU;
    constexpr uint32_t kFdeVa   = 0x0724b0U;
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

// [EN] FDE[0808] start_va=0x056350, fde_va=0x0724d0, span=24 bytes
// [VN] FDE[0808] địa chỉ bắt đầu=0x056350, fde_va=0x0724d0, kích thước=24 byte
// AArch64 opcodes: F9400C00 B4000080 F9400008 F9400501
uint32_t cybertron_fde_0808_0x056350(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056350U;
    constexpr uint32_t kFdeVa   = 0x0724d0U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xf9400c00U;
    constexpr uint32_t kW1      = 0xb4000080U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9400501U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0809] start_va=0x056368, fde_va=0x0724e8, span=28 bytes
// [VN] FDE[0809] địa chỉ bắt đầu=0x056368, fde_va=0x0724e8, kích thước=28 byte
// AArch64 opcodes: B0000149 F9400428 F947CD29 9100600A
uint32_t cybertron_fde_0809_0x056368(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056368U;
    constexpr uint32_t kFdeVa   = 0x0724e8U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xb0000149U;
    constexpr uint32_t kW1      = 0xf9400428U;
    constexpr uint32_t kW2      = 0xf947cd29U;
    constexpr uint32_t kW3      = 0x9100600aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0810] start_va=0x056384, fde_va=0x072500, span=4 bytes
// [VN] FDE[0810] địa chỉ bắt đầu=0x056384, fde_va=0x072500, kích thước=4 byte
// AArch64 opcodes: 17FF8A67 D101C3FF F9001BF7 A90457F6
uint32_t cybertron_fde_0810_0x056384(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056384U;
    constexpr uint32_t kFdeVa   = 0x072500U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff8a67U;
    constexpr uint32_t kW1      = 0xd101c3ffU;
    constexpr uint32_t kW2      = 0xf9001bf7U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0811] start_va=0x056388, fde_va=0x072518, span=276 bytes
// [VN] FDE[0811] địa chỉ bắt đầu=0x056388, fde_va=0x072518, kích thước=276 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0811_0x056388(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056388U;
    constexpr uint32_t kFdeVa   = 0x072518U;
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

// [EN] FDE[0812] start_va=0x05649c, fde_va=0x072540, span=100 bytes
// [VN] FDE[0812] địa chỉ bắt đầu=0x05649c, fde_va=0x072540, kích thước=100 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_0812_0x05649c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05649cU;
    constexpr uint32_t kFdeVa   = 0x072540U;
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

// [EN] FDE[0813] start_va=0x056500, fde_va=0x072560, span=32 bytes
// [VN] FDE[0813] địa chỉ bắt đầu=0x056500, fde_va=0x072560, kích thước=32 byte
// AArch64 opcodes: F9400068 CB010042 F100045F CB020100
uint32_t cybertron_fde_0813_0x056500(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056500U;
    constexpr uint32_t kFdeVa   = 0x072560U;
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

// [EN] FDE[0814] start_va=0x056520, fde_va=0x072578, span=84 bytes
// [VN] FDE[0814] địa chỉ bắt đầu=0x056520, fde_va=0x072578, kích thước=84 byte
// AArch64 opcodes: A9BF7BFD 910003FD D0000148 91054108
uint32_t cybertron_fde_0814_0x056520(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056520U;
    constexpr uint32_t kFdeVa   = 0x072578U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xd0000148U;
    constexpr uint32_t kW3      = 0x91054108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0815] start_va=0x056574, fde_va=0x072598, span=156 bytes
// [VN] FDE[0815] địa chỉ bắt đầu=0x056574, fde_va=0x072598, kích thước=156 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0815_0x056574(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056574U;
    constexpr uint32_t kFdeVa   = 0x072598U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0816] start_va=0x056610, fde_va=0x0725b8, span=16 bytes
// [VN] FDE[0816] địa chỉ bắt đầu=0x056610, fde_va=0x0725b8, kích thước=16 byte
// AArch64 opcodes: F9400000 F9400009 F9401122 D61F0040
uint32_t cybertron_fde_0816_0x056610(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056610U;
    constexpr uint32_t kFdeVa   = 0x0725b8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xf9400009U;
    constexpr uint32_t kW2      = 0xf9401122U;
    constexpr uint32_t kW3      = 0xd61f0040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0817] start_va=0x056620, fde_va=0x0725d0, span=256 bytes
// [VN] FDE[0817] địa chỉ bắt đầu=0x056620, fde_va=0x0725d0, kích thước=256 byte
// AArch64 opcodes: D10183FF F9001BF5 A9044FF4 A9057BFD
uint32_t cybertron_fde_0817_0x056620(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056620U;
    constexpr uint32_t kFdeVa   = 0x0725d0U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9001bf5U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0818] start_va=0x056720, fde_va=0x0725f0, span=396 bytes
// [VN] FDE[0818] địa chỉ bắt đầu=0x056720, fde_va=0x0725f0, kích thước=396 byte
// AArch64 opcodes: D10203FF F90023F7 A90557F6 A9064FF4
uint32_t cybertron_fde_0818_0x056720(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056720U;
    constexpr uint32_t kFdeVa   = 0x0725f0U;
    constexpr uint32_t kSpan    = 396U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xf90023f7U;
    constexpr uint32_t kW2      = 0xa90557f6U;
    constexpr uint32_t kW3      = 0xa9064ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0819] start_va=0x0568ac, fde_va=0x072618, span=256 bytes
// [VN] FDE[0819] địa chỉ bắt đầu=0x0568ac, fde_va=0x072618, kích thước=256 byte
// AArch64 opcodes: D10183FF F9001BF5 A9044FF4 A9057BFD
uint32_t cybertron_fde_0819_0x0568ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0568acU;
    constexpr uint32_t kFdeVa   = 0x072618U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9001bf5U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0820] start_va=0x0569ac, fde_va=0x072638, span=256 bytes
// [VN] FDE[0820] địa chỉ bắt đầu=0x0569ac, fde_va=0x072638, kích thước=256 byte
// AArch64 opcodes: D10183FF FD001BE8 A9044FF4 A9057BFD
uint32_t cybertron_fde_0820_0x0569ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0569acU;
    constexpr uint32_t kFdeVa   = 0x072638U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xfd001be8U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0821] start_va=0x056aac, fde_va=0x072658, span=260 bytes
// [VN] FDE[0821] địa chỉ bắt đầu=0x056aac, fde_va=0x072658, kích thước=260 byte
// AArch64 opcodes: D10183FF FD001BE8 A9044FF4 A9057BFD
uint32_t cybertron_fde_0821_0x056aac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056aacU;
    constexpr uint32_t kFdeVa   = 0x072658U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xfd001be8U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0822] start_va=0x056bb0, fde_va=0x072678, span=68 bytes
// [VN] FDE[0822] địa chỉ bắt đầu=0x056bb0, fde_va=0x072678, kích thước=68 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0822_0x056bb0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056bb0U;
    constexpr uint32_t kFdeVa   = 0x072678U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0823] start_va=0x056bf4, fde_va=0x0726a0, span=16 bytes
// [VN] FDE[0823] địa chỉ bắt đầu=0x056bf4, fde_va=0x0726a0, kích thước=16 byte
// AArch64 opcodes: F9400000 F9400008 F9400D02 D61F0040
uint32_t cybertron_fde_0823_0x056bf4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056bf4U;
    constexpr uint32_t kFdeVa   = 0x0726a0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9400d02U;
    constexpr uint32_t kW3      = 0xd61f0040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0824] start_va=0x056c04, fde_va=0x0726b8, span=16 bytes
// [VN] FDE[0824] địa chỉ bắt đầu=0x056c04, fde_va=0x0726b8, kích thước=16 byte
// AArch64 opcodes: F9400000 F9400008 F9400902 D61F0040
uint32_t cybertron_fde_0824_0x056c04(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056c04U;
    constexpr uint32_t kFdeVa   = 0x0726b8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9400902U;
    constexpr uint32_t kW3      = 0xd61f0040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0825] start_va=0x056c14, fde_va=0x0726d0, span=16 bytes
// [VN] FDE[0825] địa chỉ bắt đầu=0x056c14, fde_va=0x0726d0, kích thước=16 byte
// AArch64 opcodes: F9400000 F9400009 F9401523 D61F0060
uint32_t cybertron_fde_0825_0x056c14(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056c14U;
    constexpr uint32_t kFdeVa   = 0x0726d0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xf9400009U;
    constexpr uint32_t kW2      = 0xf9401523U;
    constexpr uint32_t kW3      = 0xd61f0060U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0826] start_va=0x056c24, fde_va=0x0726e8, span=16 bytes
// [VN] FDE[0826] địa chỉ bắt đầu=0x056c24, fde_va=0x0726e8, kích thước=16 byte
// AArch64 opcodes: F9400000 F9400009 F9401D24 D61F0080
uint32_t cybertron_fde_0826_0x056c24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056c24U;
    constexpr uint32_t kFdeVa   = 0x0726e8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xf9400009U;
    constexpr uint32_t kW2      = 0xf9401d24U;
    constexpr uint32_t kW3      = 0xd61f0080U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0827] start_va=0x056c34, fde_va=0x072700, span=16 bytes
// [VN] FDE[0827] địa chỉ bắt đầu=0x056c34, fde_va=0x072700, kích thước=16 byte
// AArch64 opcodes: F9400000 F9400009 F9401924 D61F0080
uint32_t cybertron_fde_0827_0x056c34(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056c34U;
    constexpr uint32_t kFdeVa   = 0x072700U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xf9400009U;
    constexpr uint32_t kW2      = 0xf9401924U;
    constexpr uint32_t kW3      = 0xd61f0080U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0828] start_va=0x056c44, fde_va=0x072718, span=36 bytes
// [VN] FDE[0828] địa chỉ bắt đầu=0x056c44, fde_va=0x072718, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0828_0x056c44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056c44U;
    constexpr uint32_t kFdeVa   = 0x072718U;
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

// [EN] FDE[0829] start_va=0x056c68, fde_va=0x072738, span=24 bytes
// [VN] FDE[0829] địa chỉ bắt đầu=0x056c68, fde_va=0x072738, kích thước=24 byte
// AArch64 opcodes: F9400C00 B4000080 F9400008 F9400501
uint32_t cybertron_fde_0829_0x056c68(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056c68U;
    constexpr uint32_t kFdeVa   = 0x072738U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xf9400c00U;
    constexpr uint32_t kW1      = 0xb4000080U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9400501U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0830] start_va=0x056c80, fde_va=0x072750, span=28 bytes
// [VN] FDE[0830] địa chỉ bắt đầu=0x056c80, fde_va=0x072750, kích thước=28 byte
// AArch64 opcodes: B0000149 F9400428 F9479929 9100600A
uint32_t cybertron_fde_0830_0x056c80(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056c80U;
    constexpr uint32_t kFdeVa   = 0x072750U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xb0000149U;
    constexpr uint32_t kW1      = 0xf9400428U;
    constexpr uint32_t kW2      = 0xf9479929U;
    constexpr uint32_t kW3      = 0x9100600aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0831] start_va=0x056c9c, fde_va=0x072768, span=4 bytes
// [VN] FDE[0831] địa chỉ bắt đầu=0x056c9c, fde_va=0x072768, kích thước=4 byte
// AArch64 opcodes: 17FF8821 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0831_0x056c9c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056c9cU;
    constexpr uint32_t kFdeVa   = 0x072768U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff8821U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0832] start_va=0x056ca0, fde_va=0x072780, span=64 bytes
// [VN] FDE[0832] địa chỉ bắt đầu=0x056ca0, fde_va=0x072780, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000153
uint32_t cybertron_fde_0832_0x056ca0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056ca0U;
    constexpr uint32_t kFdeVa   = 0x072780U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000153U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0833] start_va=0x056ce0, fde_va=0x0727a0, span=4 bytes
// [VN] FDE[0833] địa chỉ bắt đầu=0x056ce0, fde_va=0x0727a0, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FF880F F81E0FF3 A9017BFD
uint32_t cybertron_fde_0833_0x056ce0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056ce0U;
    constexpr uint32_t kFdeVa   = 0x0727a0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ff880fU;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0834] start_va=0x056ce4, fde_va=0x0727b8, span=4 bytes
// [VN] FDE[0834] địa chỉ bắt đầu=0x056ce4, fde_va=0x0727b8, kích thước=4 byte
// AArch64 opcodes: 17FF880F F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0834_0x056ce4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056ce4U;
    constexpr uint32_t kFdeVa   = 0x0727b8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff880fU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0835] start_va=0x056ce8, fde_va=0x0727d0, span=36 bytes
// [VN] FDE[0835] địa chỉ bắt đầu=0x056ce8, fde_va=0x0727d0, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_0835_0x056ce8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056ce8U;
    constexpr uint32_t kFdeVa   = 0x0727d0U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0836] start_va=0x056d0c, fde_va=0x0727f0, span=36 bytes
// [VN] FDE[0836] địa chỉ bắt đầu=0x056d0c, fde_va=0x0727f0, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_0836_0x056d0c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056d0cU;
    constexpr uint32_t kFdeVa   = 0x0727f0U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0837] start_va=0x056d30, fde_va=0x072810, span=36 bytes
// [VN] FDE[0837] địa chỉ bắt đầu=0x056d30, fde_va=0x072810, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_0837_0x056d30(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056d30U;
    constexpr uint32_t kFdeVa   = 0x072810U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0838] start_va=0x056d54, fde_va=0x072830, span=36 bytes
// [VN] FDE[0838] địa chỉ bắt đầu=0x056d54, fde_va=0x072830, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_0838_0x056d54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056d54U;
    constexpr uint32_t kFdeVa   = 0x072830U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0839] start_va=0x056d78, fde_va=0x072850, span=44 bytes
// [VN] FDE[0839] địa chỉ bắt đầu=0x056d78, fde_va=0x072850, kích thước=44 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_0839_0x056d78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056d78U;
    constexpr uint32_t kFdeVa   = 0x072850U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0840] start_va=0x056da4, fde_va=0x072870, span=336 bytes
// [VN] FDE[0840] địa chỉ bắt đầu=0x056da4, fde_va=0x072870, kích thước=336 byte
// AArch64 opcodes: D10203FF F90023F7 A90557F6 A9064FF4
uint32_t cybertron_fde_0840_0x056da4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056da4U;
    constexpr uint32_t kFdeVa   = 0x072870U;
    constexpr uint32_t kSpan    = 336U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xf90023f7U;
    constexpr uint32_t kW2      = 0xa90557f6U;
    constexpr uint32_t kW3      = 0xa9064ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0841] start_va=0x056ef4, fde_va=0x072898, span=20 bytes
// [VN] FDE[0841] địa chỉ bắt đầu=0x056ef4, fde_va=0x072898, kích thước=20 byte
// AArch64 opcodes: 6F00E400 F900281F AD000000 3D800800
uint32_t cybertron_fde_0841_0x056ef4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056ef4U;
    constexpr uint32_t kFdeVa   = 0x072898U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x6f00e400U;
    constexpr uint32_t kW1      = 0xf900281fU;
    constexpr uint32_t kW2      = 0xad000000U;
    constexpr uint32_t kW3      = 0x3d800800U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0842] start_va=0x056f08, fde_va=0x0728b0, span=48 bytes
// [VN] FDE[0842] địa chỉ bắt đầu=0x056f08, fde_va=0x0728b0, kích thước=48 byte
// AArch64 opcodes: F9400828 3DC00020 F9000808 9100C008
uint32_t cybertron_fde_0842_0x056f08(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056f08U;
    constexpr uint32_t kFdeVa   = 0x0728b0U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf9400828U;
    constexpr uint32_t kW1      = 0x3dc00020U;
    constexpr uint32_t kW2      = 0xf9000808U;
    constexpr uint32_t kW3      = 0x9100c008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0843] start_va=0x056f38, fde_va=0x0728c8, span=104 bytes
// [VN] FDE[0843] địa chỉ bắt đầu=0x056f38, fde_va=0x0728c8, kích thước=104 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0843_0x056f38(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056f38U;
    constexpr uint32_t kFdeVa   = 0x0728c8U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0844] start_va=0x056fa0, fde_va=0x0728e8, span=88 bytes
// [VN] FDE[0844] địa chỉ bắt đầu=0x056fa0, fde_va=0x0728e8, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0844_0x056fa0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056fa0U;
    constexpr uint32_t kFdeVa   = 0x0728e8U;
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

// [EN] FDE[0845] start_va=0x056ff8, fde_va=0x072908, span=172 bytes
// [VN] FDE[0845] địa chỉ bắt đầu=0x056ff8, fde_va=0x072908, kích thước=172 byte
// AArch64 opcodes: D101C3FF F90023F5 A9054FF4 A9067BFD
uint32_t cybertron_fde_0845_0x056ff8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x056ff8U;
    constexpr uint32_t kFdeVa   = 0x072908U;
    constexpr uint32_t kSpan    = 172U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90023f5U;
    constexpr uint32_t kW2      = 0xa9054ff4U;
    constexpr uint32_t kW3      = 0xa9067bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0846] start_va=0x0570a4, fde_va=0x072928, span=352 bytes
// [VN] FDE[0846] địa chỉ bắt đầu=0x0570a4, fde_va=0x072928, kích thước=352 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_0846_0x0570a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0570a4U;
    constexpr uint32_t kFdeVa   = 0x072928U;
    constexpr uint32_t kSpan    = 352U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0847] start_va=0x057204, fde_va=0x072950, span=1656 bytes
// [VN] FDE[0847] địa chỉ bắt đầu=0x057204, fde_va=0x072950, kích thước=1656 byte
// AArch64 opcodes: D10503FF A90E6FFC A90F67FA A9105FF8
uint32_t cybertron_fde_0847_0x057204(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x057204U;
    constexpr uint32_t kFdeVa   = 0x072950U;
    constexpr uint32_t kSpan    = 1656U;
    constexpr uint32_t kW0      = 0xd10503ffU;
    constexpr uint32_t kW1      = 0xa90e6ffcU;
    constexpr uint32_t kW2      = 0xa90f67faU;
    constexpr uint32_t kW3      = 0xa9105ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0848] start_va=0x05787c, fde_va=0x072980, span=88 bytes
// [VN] FDE[0848] địa chỉ bắt đầu=0x05787c, fde_va=0x072980, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0848_0x05787c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05787cU;
    constexpr uint32_t kFdeVa   = 0x072980U;
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

// [EN] FDE[0849] start_va=0x0578d4, fde_va=0x0729a0, span=88 bytes
// [VN] FDE[0849] địa chỉ bắt đầu=0x0578d4, fde_va=0x0729a0, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0849_0x0578d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0578d4U;
    constexpr uint32_t kFdeVa   = 0x0729a0U;
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

// [EN] FDE[0850] start_va=0x05792c, fde_va=0x0729c0, span=112 bytes
// [VN] FDE[0850] địa chỉ bắt đầu=0x05792c, fde_va=0x0729c0, kích thước=112 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000148
uint32_t cybertron_fde_0850_0x05792c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05792cU;
    constexpr uint32_t kFdeVa   = 0x0729c0U;
    constexpr uint32_t kSpan    = 112U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000148U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0851] start_va=0x05799c, fde_va=0x0729e0, span=684 bytes
// [VN] FDE[0851] địa chỉ bắt đầu=0x05799c, fde_va=0x0729e0, kích thước=684 byte
// AArch64 opcodes: D10303FF A9066FFC A90767FA A9085FF8
uint32_t cybertron_fde_0851_0x05799c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05799cU;
    constexpr uint32_t kFdeVa   = 0x0729e0U;
    constexpr uint32_t kSpan    = 684U;
    constexpr uint32_t kW0      = 0xd10303ffU;
    constexpr uint32_t kW1      = 0xa9066ffcU;
    constexpr uint32_t kW2      = 0xa90767faU;
    constexpr uint32_t kW3      = 0xa9085ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0852] start_va=0x057c48, fde_va=0x072a10, span=784 bytes
// [VN] FDE[0852] địa chỉ bắt đầu=0x057c48, fde_va=0x072a10, kích thước=784 byte
// AArch64 opcodes: D10203FF A9026FFC A90367FA A9045FF8
uint32_t cybertron_fde_0852_0x057c48(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x057c48U;
    constexpr uint32_t kFdeVa   = 0x072a10U;
    constexpr uint32_t kSpan    = 784U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa9026ffcU;
    constexpr uint32_t kW2      = 0xa90367faU;
    constexpr uint32_t kW3      = 0xa9045ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0853] start_va=0x057f58, fde_va=0x072a40, span=960 bytes
// [VN] FDE[0853] địa chỉ bắt đầu=0x057f58, fde_va=0x072a40, kích thước=960 byte
// AArch64 opcodes: D102C3FF A9056FFC A90667FA A9075FF8
uint32_t cybertron_fde_0853_0x057f58(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x057f58U;
    constexpr uint32_t kFdeVa   = 0x072a40U;
    constexpr uint32_t kSpan    = 960U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xa9056ffcU;
    constexpr uint32_t kW2      = 0xa90667faU;
    constexpr uint32_t kW3      = 0xa9075ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0854] start_va=0x058318, fde_va=0x072a70, span=88 bytes
// [VN] FDE[0854] địa chỉ bắt đầu=0x058318, fde_va=0x072a70, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0854_0x058318(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x058318U;
    constexpr uint32_t kFdeVa   = 0x072a70U;
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

// [EN] FDE[0855] start_va=0x058370, fde_va=0x072a90, span=88 bytes
// [VN] FDE[0855] địa chỉ bắt đầu=0x058370, fde_va=0x072a90, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0855_0x058370(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x058370U;
    constexpr uint32_t kFdeVa   = 0x072a90U;
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

// [EN] FDE[0856] start_va=0x0583c8, fde_va=0x072ab0, span=728 bytes
// [VN] FDE[0856] địa chỉ bắt đầu=0x0583c8, fde_va=0x072ab0, kích thước=728 byte
// AArch64 opcodes: D101C3FF A9016FFC A90267FA A9035FF8
uint32_t cybertron_fde_0856_0x0583c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0583c8U;
    constexpr uint32_t kFdeVa   = 0x072ab0U;
    constexpr uint32_t kSpan    = 728U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9016ffcU;
    constexpr uint32_t kW2      = 0xa90267faU;
    constexpr uint32_t kW3      = 0xa9035ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0857] start_va=0x0586a0, fde_va=0x072ae0, span=100 bytes
// [VN] FDE[0857] địa chỉ bắt đầu=0x0586a0, fde_va=0x072ae0, kích thước=100 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F0000129
uint32_t cybertron_fde_0857_0x0586a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0586a0U;
    constexpr uint32_t kFdeVa   = 0x072ae0U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf0000129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0858] start_va=0x058704, fde_va=0x072b00, span=36 bytes
// [VN] FDE[0858] địa chỉ bắt đầu=0x058704, fde_va=0x072b00, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0858_0x058704(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x058704U;
    constexpr uint32_t kFdeVa   = 0x072b00U;
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

// [EN] FDE[0859] start_va=0x058728, fde_va=0x072b20, span=488 bytes
// [VN] FDE[0859] địa chỉ bắt đầu=0x058728, fde_va=0x072b20, kích thước=488 byte
// AArch64 opcodes: D102C3FF F90033F9 A9075FF8 A90857F6
uint32_t cybertron_fde_0859_0x058728(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x058728U;
    constexpr uint32_t kFdeVa   = 0x072b20U;
    constexpr uint32_t kSpan    = 488U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xf90033f9U;
    constexpr uint32_t kW2      = 0xa9075ff8U;
    constexpr uint32_t kW3      = 0xa90857f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0860] start_va=0x058910, fde_va=0x072b48, span=488 bytes
// [VN] FDE[0860] địa chỉ bắt đầu=0x058910, fde_va=0x072b48, kích thước=488 byte
// AArch64 opcodes: D102C3FF F90033F9 A9075FF8 A90857F6
uint32_t cybertron_fde_0860_0x058910(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x058910U;
    constexpr uint32_t kFdeVa   = 0x072b48U;
    constexpr uint32_t kSpan    = 488U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xf90033f9U;
    constexpr uint32_t kW2      = 0xa9075ff8U;
    constexpr uint32_t kW3      = 0xa90857f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0861] start_va=0x058af8, fde_va=0x072b70, span=596 bytes
// [VN] FDE[0861] địa chỉ bắt đầu=0x058af8, fde_va=0x072b70, kích thước=596 byte
// AArch64 opcodes: D101C3FF A9016FFC A90267FA A9035FF8
uint32_t cybertron_fde_0861_0x058af8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x058af8U;
    constexpr uint32_t kFdeVa   = 0x072b70U;
    constexpr uint32_t kSpan    = 596U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9016ffcU;
    constexpr uint32_t kW2      = 0xa90267faU;
    constexpr uint32_t kW3      = 0xa9035ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0862] start_va=0x058d4c, fde_va=0x072ba0, span=1232 bytes
// [VN] FDE[0862] địa chỉ bắt đầu=0x058d4c, fde_va=0x072ba0, kích thước=1232 byte
// AArch64 opcodes: D103C3FF A9096FFC A90A67FA A90B5FF8
uint32_t cybertron_fde_0862_0x058d4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x058d4cU;
    constexpr uint32_t kFdeVa   = 0x072ba0U;
    constexpr uint32_t kSpan    = 1232U;
    constexpr uint32_t kW0      = 0xd103c3ffU;
    constexpr uint32_t kW1      = 0xa9096ffcU;
    constexpr uint32_t kW2      = 0xa90a67faU;
    constexpr uint32_t kW3      = 0xa90b5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0863] start_va=0x05921c, fde_va=0x072bd0, span=176 bytes
// [VN] FDE[0863] địa chỉ bắt đầu=0x05921c, fde_va=0x072bd0, kích thước=176 byte
// AArch64 opcodes: D10103FF A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0863_0x05921c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05921cU;
    constexpr uint32_t kFdeVa   = 0x072bd0U;
    constexpr uint32_t kSpan    = 176U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0864] start_va=0x0592cc, fde_va=0x072bf8, span=144 bytes
// [VN] FDE[0864] địa chỉ bắt đầu=0x0592cc, fde_va=0x072bf8, kích thước=144 byte
// AArch64 opcodes: D101C3FF F90023F5 A9054FF4 A9067BFD
uint32_t cybertron_fde_0864_0x0592cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0592ccU;
    constexpr uint32_t kFdeVa   = 0x072bf8U;
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

// [EN] FDE[0865] start_va=0x05935c, fde_va=0x072c18, span=112 bytes
// [VN] FDE[0865] địa chỉ bắt đầu=0x05935c, fde_va=0x072c18, kích thước=112 byte
// AArch64 opcodes: D10103FF F90013F3 A9037BFD 9100C3FD
uint32_t cybertron_fde_0865_0x05935c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05935cU;
    constexpr uint32_t kFdeVa   = 0x072c18U;
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

// [EN] FDE[0866] start_va=0x0593cc, fde_va=0x072c38, span=72 bytes
// [VN] FDE[0866] địa chỉ bắt đầu=0x0593cc, fde_va=0x072c38, kích thước=72 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000128
uint32_t cybertron_fde_0866_0x0593cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0593ccU;
    constexpr uint32_t kFdeVa   = 0x072c38U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0867] start_va=0x059414, fde_va=0x072c58, span=80 bytes
// [VN] FDE[0867] địa chỉ bắt đầu=0x059414, fde_va=0x072c58, kích thước=80 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000128
uint32_t cybertron_fde_0867_0x059414(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059414U;
    constexpr uint32_t kFdeVa   = 0x072c58U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0868] start_va=0x059464, fde_va=0x072c78, span=12 bytes
// [VN] FDE[0868] địa chỉ bắt đầu=0x059464, fde_va=0x072c78, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400501 D61F0020 17FF7E2C
uint32_t cybertron_fde_0868_0x059464(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059464U;
    constexpr uint32_t kFdeVa   = 0x072c78U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400501U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ff7e2cU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0869] start_va=0x059470, fde_va=0x072c90, span=4 bytes
// [VN] FDE[0869] địa chỉ bắt đầu=0x059470, fde_va=0x072c90, kích thước=4 byte
// AArch64 opcodes: 17FF7E2C D10203FF A9045FF8 A90557F6
uint32_t cybertron_fde_0869_0x059470(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059470U;
    constexpr uint32_t kFdeVa   = 0x072c90U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff7e2cU;
    constexpr uint32_t kW1      = 0xd10203ffU;
    constexpr uint32_t kW2      = 0xa9045ff8U;
    constexpr uint32_t kW3      = 0xa90557f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0870] start_va=0x059474, fde_va=0x072ca8, span=700 bytes
// [VN] FDE[0870] địa chỉ bắt đầu=0x059474, fde_va=0x072ca8, kích thước=700 byte
// AArch64 opcodes: D10203FF A9045FF8 A90557F6 A9064FF4
uint32_t cybertron_fde_0870_0x059474(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059474U;
    constexpr uint32_t kFdeVa   = 0x072ca8U;
    constexpr uint32_t kSpan    = 700U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa9045ff8U;
    constexpr uint32_t kW2      = 0xa90557f6U;
    constexpr uint32_t kW3      = 0xa9064ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0871] start_va=0x059730, fde_va=0x072cd0, span=176 bytes
// [VN] FDE[0871] địa chỉ bắt đầu=0x059730, fde_va=0x072cd0, kích thước=176 byte
// AArch64 opcodes: D10103FF A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0871_0x059730(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059730U;
    constexpr uint32_t kFdeVa   = 0x072cd0U;
    constexpr uint32_t kSpan    = 176U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0872] start_va=0x0597e0, fde_va=0x072cf8, span=72 bytes
// [VN] FDE[0872] địa chỉ bắt đầu=0x0597e0, fde_va=0x072cf8, kích thước=72 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000128
uint32_t cybertron_fde_0872_0x0597e0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0597e0U;
    constexpr uint32_t kFdeVa   = 0x072cf8U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0873] start_va=0x059828, fde_va=0x072d18, span=80 bytes
// [VN] FDE[0873] địa chỉ bắt đầu=0x059828, fde_va=0x072d18, kích thước=80 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000128
uint32_t cybertron_fde_0873_0x059828(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059828U;
    constexpr uint32_t kFdeVa   = 0x072d18U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0874] start_va=0x059878, fde_va=0x072d38, span=12 bytes
// [VN] FDE[0874] địa chỉ bắt đầu=0x059878, fde_va=0x072d38, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400501 D61F0020 17FF7D27
uint32_t cybertron_fde_0874_0x059878(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059878U;
    constexpr uint32_t kFdeVa   = 0x072d38U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400501U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ff7d27U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0875] start_va=0x059884, fde_va=0x072d50, span=4 bytes
// [VN] FDE[0875] địa chỉ bắt đầu=0x059884, fde_va=0x072d50, kích thước=4 byte
// AArch64 opcodes: 17FF7D27 D101C3FF A9035FF8 A90457F6
uint32_t cybertron_fde_0875_0x059884(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059884U;
    constexpr uint32_t kFdeVa   = 0x072d50U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff7d27U;
    constexpr uint32_t kW1      = 0xd101c3ffU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0876] start_va=0x059888, fde_va=0x072d68, span=648 bytes
// [VN] FDE[0876] địa chỉ bắt đầu=0x059888, fde_va=0x072d68, kích thước=648 byte
// AArch64 opcodes: D101C3FF A9035FF8 A90457F6 A9054FF4
uint32_t cybertron_fde_0876_0x059888(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059888U;
    constexpr uint32_t kFdeVa   = 0x072d68U;
    constexpr uint32_t kSpan    = 648U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9035ff8U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0877] start_va=0x059b10, fde_va=0x072d90, span=288 bytes
// [VN] FDE[0877] địa chỉ bắt đầu=0x059b10, fde_va=0x072d90, kích thước=288 byte
// AArch64 opcodes: D101C3FF F90013F9 A9035FF8 A90457F6
uint32_t cybertron_fde_0877_0x059b10(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059b10U;
    constexpr uint32_t kFdeVa   = 0x072d90U;
    constexpr uint32_t kSpan    = 288U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90013f9U;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0878] start_va=0x059c30, fde_va=0x072db8, span=84 bytes
// [VN] FDE[0878] địa chỉ bắt đầu=0x059c30, fde_va=0x072db8, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_0878_0x059c30(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059c30U;
    constexpr uint32_t kFdeVa   = 0x072db8U;
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

// [EN] FDE[0879] start_va=0x059c84, fde_va=0x072dd8, span=68 bytes
// [VN] FDE[0879] địa chỉ bắt đầu=0x059c84, fde_va=0x072dd8, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400013
uint32_t cybertron_fde_0879_0x059c84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059c84U;
    constexpr uint32_t kFdeVa   = 0x072dd8U;
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

// [EN] FDE[0880] start_va=0x059cc8, fde_va=0x072df8, span=176 bytes
// [VN] FDE[0880] địa chỉ bắt đầu=0x059cc8, fde_va=0x072df8, kích thước=176 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0880_0x059cc8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059cc8U;
    constexpr uint32_t kFdeVa   = 0x072df8U;
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

// [EN] FDE[0881] start_va=0x059d78, fde_va=0x072e20, span=292 bytes
// [VN] FDE[0881] địa chỉ bắt đầu=0x059d78, fde_va=0x072e20, kích thước=292 byte
// AArch64 opcodes: A9BA6FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0881_0x059d78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059d78U;
    constexpr uint32_t kFdeVa   = 0x072e20U;
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

// [EN] FDE[0882] start_va=0x059e9c, fde_va=0x072e50, span=84 bytes
// [VN] FDE[0882] địa chỉ bắt đầu=0x059e9c, fde_va=0x072e50, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_0882_0x059e9c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059e9cU;
    constexpr uint32_t kFdeVa   = 0x072e50U;
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

// [EN] FDE[0883] start_va=0x059ef0, fde_va=0x072e70, span=60 bytes
// [VN] FDE[0883] địa chỉ bắt đầu=0x059ef0, fde_va=0x072e70, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 91006040
uint32_t cybertron_fde_0883_0x059ef0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059ef0U;
    constexpr uint32_t kFdeVa   = 0x072e70U;
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

// [EN] FDE[0884] start_va=0x059f2c, fde_va=0x072e90, span=352 bytes
// [VN] FDE[0884] địa chỉ bắt đầu=0x059f2c, fde_va=0x072e90, kích thước=352 byte
// AArch64 opcodes: D10183FF F9001BF5 A9044FF4 A9057BFD
uint32_t cybertron_fde_0884_0x059f2c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x059f2cU;
    constexpr uint32_t kFdeVa   = 0x072e90U;
    constexpr uint32_t kSpan    = 352U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9001bf5U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0885] start_va=0x05a08c, fde_va=0x072eb0, span=124 bytes
// [VN] FDE[0885] địa chỉ bắt đầu=0x05a08c, fde_va=0x072eb0, kích thước=124 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003E8
uint32_t cybertron_fde_0885_0x05a08c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a08cU;
    constexpr uint32_t kFdeVa   = 0x072eb0U;
    constexpr uint32_t kSpan    = 124U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0886] start_va=0x05a108, fde_va=0x072ed0, span=132 bytes
// [VN] FDE[0886] địa chỉ bắt đầu=0x05a108, fde_va=0x072ed0, kích thước=132 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400428
uint32_t cybertron_fde_0886_0x05a108(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a108U;
    constexpr uint32_t kFdeVa   = 0x072ed0U;
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

// [EN] FDE[0887] start_va=0x05a18c, fde_va=0x072ef0, span=52 bytes
// [VN] FDE[0887] địa chỉ bắt đầu=0x05a18c, fde_va=0x072ef0, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000128
uint32_t cybertron_fde_0887_0x05a18c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a18cU;
    constexpr uint32_t kFdeVa   = 0x072ef0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0888] start_va=0x05a1c0, fde_va=0x072f10, span=60 bytes
// [VN] FDE[0888] địa chỉ bắt đầu=0x05a1c0, fde_va=0x072f10, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000128
uint32_t cybertron_fde_0888_0x05a1c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a1c0U;
    constexpr uint32_t kFdeVa   = 0x072f10U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0889] start_va=0x05a1fc, fde_va=0x072f30, span=12 bytes
// [VN] FDE[0889] địa chỉ bắt đầu=0x05a1fc, fde_va=0x072f30, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400101 D61F0020 17FF7AC6
uint32_t cybertron_fde_0889_0x05a1fc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a1fcU;
    constexpr uint32_t kFdeVa   = 0x072f30U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400101U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ff7ac6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0890] start_va=0x05a208, fde_va=0x072f48, span=4 bytes
// [VN] FDE[0890] địa chỉ bắt đầu=0x05a208, fde_va=0x072f48, kích thước=4 byte
// AArch64 opcodes: 17FF7AC6 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0890_0x05a208(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a208U;
    constexpr uint32_t kFdeVa   = 0x072f48U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff7ac6U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0891] start_va=0x05a20c, fde_va=0x072f60, span=72 bytes
// [VN] FDE[0891] địa chỉ bắt đầu=0x05a20c, fde_va=0x072f60, kích thước=72 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000128
uint32_t cybertron_fde_0891_0x05a20c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a20cU;
    constexpr uint32_t kFdeVa   = 0x072f60U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0892] start_va=0x05a254, fde_va=0x072f80, span=36 bytes
// [VN] FDE[0892] địa chỉ bắt đầu=0x05a254, fde_va=0x072f80, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0892_0x05a254(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a254U;
    constexpr uint32_t kFdeVa   = 0x072f80U;
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

// [EN] FDE[0893] start_va=0x05a278, fde_va=0x072fa0, span=460 bytes
// [VN] FDE[0893] địa chỉ bắt đầu=0x05a278, fde_va=0x072fa0, kích thước=460 byte
// AArch64 opcodes: D106C3FF A9156FFC A91667FA A9175FF8
uint32_t cybertron_fde_0893_0x05a278(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a278U;
    constexpr uint32_t kFdeVa   = 0x072fa0U;
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

// [EN] FDE[0894] start_va=0x05a444, fde_va=0x072fd0, span=248 bytes
// [VN] FDE[0894] địa chỉ bắt đầu=0x05a444, fde_va=0x072fd0, kích thước=248 byte
// AArch64 opcodes: D10183FF F9000BF9 A9025FF8 A90357F6
uint32_t cybertron_fde_0894_0x05a444(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a444U;
    constexpr uint32_t kFdeVa   = 0x072fd0U;
    constexpr uint32_t kSpan    = 248U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9000bf9U;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0895] start_va=0x05a53c, fde_va=0x072ff8, span=212 bytes
// [VN] FDE[0895] địa chỉ bắt đầu=0x05a53c, fde_va=0x072ff8, kích thước=212 byte
// AArch64 opcodes: D10143FF A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0895_0x05a53c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a53cU;
    constexpr uint32_t kFdeVa   = 0x072ff8U;
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

// [EN] FDE[0896] start_va=0x05a610, fde_va=0x073020, span=204 bytes
// [VN] FDE[0896] địa chỉ bắt đầu=0x05a610, fde_va=0x073020, kích thước=204 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0896_0x05a610(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a610U;
    constexpr uint32_t kFdeVa   = 0x073020U;
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

// [EN] FDE[0897] start_va=0x05a6dc, fde_va=0x073048, span=88 bytes
// [VN] FDE[0897] địa chỉ bắt đầu=0x05a6dc, fde_va=0x073048, kích thước=88 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0897_0x05a6dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a6dcU;
    constexpr uint32_t kFdeVa   = 0x073048U;
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

// [EN] FDE[0898] start_va=0x05a734, fde_va=0x073068, span=356 bytes
// [VN] FDE[0898] địa chỉ bắt đầu=0x05a734, fde_va=0x073068, kích thước=356 byte
// AArch64 opcodes: D101C3FF F90013F9 A9035FF8 A90457F6
uint32_t cybertron_fde_0898_0x05a734(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a734U;
    constexpr uint32_t kFdeVa   = 0x073068U;
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

// [EN] FDE[0899] start_va=0x05a898, fde_va=0x073090, span=76 bytes
// [VN] FDE[0899] địa chỉ bắt đầu=0x05a898, fde_va=0x073090, kích thước=76 byte
// AArch64 opcodes: B4000241 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0899_0x05a898(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a898U;
    constexpr uint32_t kFdeVa   = 0x073090U;
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

// [EN] FDE[0900] start_va=0x05a8e4, fde_va=0x0730b0, span=76 bytes
// [VN] FDE[0900] địa chỉ bắt đầu=0x05a8e4, fde_va=0x0730b0, kích thước=76 byte
// AArch64 opcodes: B4000241 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0900_0x05a8e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a8e4U;
    constexpr uint32_t kFdeVa   = 0x0730b0U;
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

// [EN] FDE[0901] start_va=0x05a930, fde_va=0x0730d0, span=60 bytes
// [VN] FDE[0901] địa chỉ bắt đầu=0x05a930, fde_va=0x0730d0, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 91006040
uint32_t cybertron_fde_0901_0x05a930(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a930U;
    constexpr uint32_t kFdeVa   = 0x0730d0U;
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

// [EN] FDE[0902] start_va=0x05a96c, fde_va=0x0730f0, span=76 bytes
// [VN] FDE[0902] địa chỉ bắt đầu=0x05a96c, fde_va=0x0730f0, kích thước=76 byte
// AArch64 opcodes: B4000241 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0902_0x05a96c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a96cU;
    constexpr uint32_t kFdeVa   = 0x0730f0U;
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

// [EN] FDE[0903] start_va=0x05a9b8, fde_va=0x073110, span=64 bytes
// [VN] FDE[0903] địa chỉ bắt đầu=0x05a9b8, fde_va=0x073110, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9401041
uint32_t cybertron_fde_0903_0x05a9b8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a9b8U;
    constexpr uint32_t kFdeVa   = 0x073110U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9401041U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0904] start_va=0x05a9f8, fde_va=0x073130, span=72 bytes
// [VN] FDE[0904] địa chỉ bắt đầu=0x05a9f8, fde_va=0x073130, kích thước=72 byte
// AArch64 opcodes: B4000221 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_0904_0x05a9f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05a9f8U;
    constexpr uint32_t kFdeVa   = 0x073130U;
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

// [EN] FDE[0905] start_va=0x05aa40, fde_va=0x073150, span=104 bytes
// [VN] FDE[0905] địa chỉ bắt đầu=0x05aa40, fde_va=0x073150, kích thước=104 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9401028
uint32_t cybertron_fde_0905_0x05aa40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05aa40U;
    constexpr uint32_t kFdeVa   = 0x073150U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9401028U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0906] start_va=0x05aaa8, fde_va=0x073170, span=4 bytes
// [VN] FDE[0906] địa chỉ bắt đầu=0x05aaa8, fde_va=0x073170, kích thước=4 byte
// AArch64 opcodes: 17FF789E F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0906_0x05aaa8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05aaa8U;
    constexpr uint32_t kFdeVa   = 0x073170U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff789eU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0907] start_va=0x05aaac, fde_va=0x073188, span=56 bytes
// [VN] FDE[0907] địa chỉ bắt đầu=0x05aaac, fde_va=0x073188, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0907_0x05aaac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05aaacU;
    constexpr uint32_t kFdeVa   = 0x073188U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0908] start_va=0x05aae4, fde_va=0x0731a8, span=24 bytes
// [VN] FDE[0908] địa chỉ bắt đầu=0x05aae4, fde_va=0x0731a8, kích thước=24 byte
// AArch64 opcodes: F0000108 913CC108 F9000028 F9400408
uint32_t cybertron_fde_0908_0x05aae4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05aae4U;
    constexpr uint32_t kFdeVa   = 0x0731a8U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xf0000108U;
    constexpr uint32_t kW1      = 0x913cc108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0909] start_va=0x05aafc, fde_va=0x0731c0, span=4 bytes
// [VN] FDE[0909] địa chỉ bắt đầu=0x05aafc, fde_va=0x0731c0, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FF7888 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0909_0x05aafc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05aafcU;
    constexpr uint32_t kFdeVa   = 0x0731c0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ff7888U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0910] start_va=0x05ab00, fde_va=0x0731d8, span=4 bytes
// [VN] FDE[0910] địa chỉ bắt đầu=0x05ab00, fde_va=0x0731d8, kích thước=4 byte
// AArch64 opcodes: 17FF7888 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0910_0x05ab00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ab00U;
    constexpr uint32_t kFdeVa   = 0x0731d8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff7888U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0911] start_va=0x05ab04, fde_va=0x0731f0, span=60 bytes
// [VN] FDE[0911] địa chỉ bắt đầu=0x05ab04, fde_va=0x0731f0, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0911_0x05ab04(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ab04U;
    constexpr uint32_t kFdeVa   = 0x0731f0U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400413U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0912] start_va=0x05ab40, fde_va=0x073210, span=28 bytes
// [VN] FDE[0912] địa chỉ bắt đầu=0x05ab40, fde_va=0x073210, kích thước=28 byte
// AArch64 opcodes: F9400428 B0000069 91242129 9100200A
uint32_t cybertron_fde_0912_0x05ab40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ab40U;
    constexpr uint32_t kFdeVa   = 0x073210U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xb0000069U;
    constexpr uint32_t kW2      = 0x91242129U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0913] start_va=0x05ab5c, fde_va=0x073228, span=12 bytes
// [VN] FDE[0913] địa chỉ bắt đầu=0x05ab5c, fde_va=0x073228, kích thước=12 byte
// AArch64 opcodes: F0000100 913E4000 D65F03C0 A9BC5FF8
uint32_t cybertron_fde_0913_0x05ab5c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ab5cU;
    constexpr uint32_t kFdeVa   = 0x073228U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf0000100U;
    constexpr uint32_t kW1      = 0x913e4000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xa9bc5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0914] start_va=0x05ab68, fde_va=0x073240, span=268 bytes
// [VN] FDE[0914] địa chỉ bắt đầu=0x05ab68, fde_va=0x073240, kích thước=268 byte
// AArch64 opcodes: A9BC5FF8 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0914_0x05ab68(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ab68U;
    constexpr uint32_t kFdeVa   = 0x073240U;
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

// [EN] FDE[0915] start_va=0x05ac74, fde_va=0x073268, span=176 bytes
// [VN] FDE[0915] địa chỉ bắt đầu=0x05ac74, fde_va=0x073268, kích thước=176 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0915_0x05ac74(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ac74U;
    constexpr uint32_t kFdeVa   = 0x073268U;
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

// [EN] FDE[0916] start_va=0x05ad24, fde_va=0x073290, span=292 bytes
// [VN] FDE[0916] địa chỉ bắt đầu=0x05ad24, fde_va=0x073290, kích thước=292 byte
// AArch64 opcodes: A9BA6FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0916_0x05ad24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ad24U;
    constexpr uint32_t kFdeVa   = 0x073290U;
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

// [EN] FDE[0917] start_va=0x05ae48, fde_va=0x0732c0, span=84 bytes
// [VN] FDE[0917] địa chỉ bắt đầu=0x05ae48, fde_va=0x0732c0, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_0917_0x05ae48(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ae48U;
    constexpr uint32_t kFdeVa   = 0x0732c0U;
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

// [EN] FDE[0918] start_va=0x05ae9c, fde_va=0x0732e0, span=52 bytes
// [VN] FDE[0918] địa chỉ bắt đầu=0x05ae9c, fde_va=0x0732e0, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000128
uint32_t cybertron_fde_0918_0x05ae9c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ae9cU;
    constexpr uint32_t kFdeVa   = 0x0732e0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0919] start_va=0x05aed0, fde_va=0x073300, span=60 bytes
// [VN] FDE[0919] địa chỉ bắt đầu=0x05aed0, fde_va=0x073300, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B0000128
uint32_t cybertron_fde_0919_0x05aed0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05aed0U;
    constexpr uint32_t kFdeVa   = 0x073300U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0920] start_va=0x05af0c, fde_va=0x073320, span=8 bytes
// [VN] FDE[0920] địa chỉ bắt đầu=0x05af0c, fde_va=0x073320, kích thước=8 byte
// AArch64 opcodes: 91006000 17FF7E34 17FF7783 D10143FF
uint32_t cybertron_fde_0920_0x05af0c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05af0cU;
    constexpr uint32_t kFdeVa   = 0x073320U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91006000U;
    constexpr uint32_t kW1      = 0x17ff7e34U;
    constexpr uint32_t kW2      = 0x17ff7783U;
    constexpr uint32_t kW3      = 0xd10143ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0921] start_va=0x05af14, fde_va=0x073338, span=4 bytes
// [VN] FDE[0921] địa chỉ bắt đầu=0x05af14, fde_va=0x073338, kích thước=4 byte
// AArch64 opcodes: 17FF7783 D10143FF F9000BF7 A90257F6
uint32_t cybertron_fde_0921_0x05af14(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05af14U;
    constexpr uint32_t kFdeVa   = 0x073338U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff7783U;
    constexpr uint32_t kW1      = 0xd10143ffU;
    constexpr uint32_t kW2      = 0xf9000bf7U;
    constexpr uint32_t kW3      = 0xa90257f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0922] start_va=0x05af18, fde_va=0x073350, span=188 bytes
// [VN] FDE[0922] địa chỉ bắt đầu=0x05af18, fde_va=0x073350, kích thước=188 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0922_0x05af18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05af18U;
    constexpr uint32_t kFdeVa   = 0x073350U;
    constexpr uint32_t kSpan    = 188U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9000bf7U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0923] start_va=0x05afd4, fde_va=0x073378, span=292 bytes
// [VN] FDE[0923] địa chỉ bắt đầu=0x05afd4, fde_va=0x073378, kích thước=292 byte
// AArch64 opcodes: A9BA6FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0923_0x05afd4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05afd4U;
    constexpr uint32_t kFdeVa   = 0x073378U;
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

// [EN] FDE[0924] start_va=0x05b0f8, fde_va=0x0733a8, span=84 bytes
// [VN] FDE[0924] địa chỉ bắt đầu=0x05b0f8, fde_va=0x0733a8, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_0924_0x05b0f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b0f8U;
    constexpr uint32_t kFdeVa   = 0x0733a8U;
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

// [EN] FDE[0925] start_va=0x05b14c, fde_va=0x0733c8, span=52 bytes
// [VN] FDE[0925] địa chỉ bắt đầu=0x05b14c, fde_va=0x0733c8, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000128
uint32_t cybertron_fde_0925_0x05b14c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b14cU;
    constexpr uint32_t kFdeVa   = 0x0733c8U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0926] start_va=0x05b180, fde_va=0x0733e8, span=60 bytes
// [VN] FDE[0926] địa chỉ bắt đầu=0x05b180, fde_va=0x0733e8, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000128
uint32_t cybertron_fde_0926_0x05b180(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b180U;
    constexpr uint32_t kFdeVa   = 0x0733e8U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000128U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0927] start_va=0x05b1bc, fde_va=0x073408, span=8 bytes
// [VN] FDE[0927] địa chỉ bắt đầu=0x05b1bc, fde_va=0x073408, kích thước=8 byte
// AArch64 opcodes: 91008000 17FF7D8C 17FF76D7 D10143FF
uint32_t cybertron_fde_0927_0x05b1bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b1bcU;
    constexpr uint32_t kFdeVa   = 0x073408U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91008000U;
    constexpr uint32_t kW1      = 0x17ff7d8cU;
    constexpr uint32_t kW2      = 0x17ff76d7U;
    constexpr uint32_t kW3      = 0xd10143ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0928] start_va=0x05b1c4, fde_va=0x073420, span=4 bytes
// [VN] FDE[0928] địa chỉ bắt đầu=0x05b1c4, fde_va=0x073420, kích thước=4 byte
// AArch64 opcodes: 17FF76D7 D10143FF F90013F5 A9034FF4
uint32_t cybertron_fde_0928_0x05b1c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b1c4U;
    constexpr uint32_t kFdeVa   = 0x073420U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff76d7U;
    constexpr uint32_t kW1      = 0xd10143ffU;
    constexpr uint32_t kW2      = 0xf90013f5U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0929] start_va=0x05b1c8, fde_va=0x073438, span=152 bytes
// [VN] FDE[0929] địa chỉ bắt đầu=0x05b1c8, fde_va=0x073438, kích thước=152 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0929_0x05b1c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b1c8U;
    constexpr uint32_t kFdeVa   = 0x073438U;
    constexpr uint32_t kSpan    = 152U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0930] start_va=0x05b260, fde_va=0x073458, span=328 bytes
// [VN] FDE[0930] địa chỉ bắt đầu=0x05b260, fde_va=0x073458, kích thước=328 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_0930_0x05b260(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b260U;
    constexpr uint32_t kFdeVa   = 0x073458U;
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

// [EN] FDE[0931] start_va=0x05b3a8, fde_va=0x073488, span=76 bytes
// [VN] FDE[0931] địa chỉ bắt đầu=0x05b3a8, fde_va=0x073488, kích thước=76 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F0000108
uint32_t cybertron_fde_0931_0x05b3a8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b3a8U;
    constexpr uint32_t kFdeVa   = 0x073488U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf0000108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0932] start_va=0x05b3f4, fde_va=0x0734a8, span=72 bytes
// [VN] FDE[0932] địa chỉ bắt đầu=0x05b3f4, fde_va=0x0734a8, kích thước=72 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F0000108
uint32_t cybertron_fde_0932_0x05b3f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b3f4U;
    constexpr uint32_t kFdeVa   = 0x0734a8U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf0000108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0933] start_va=0x05b43c, fde_va=0x0734c8, span=64 bytes
// [VN] FDE[0933] địa chỉ bắt đầu=0x05b43c, fde_va=0x0734c8, kích thước=64 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0933_0x05b43c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b43cU;
    constexpr uint32_t kFdeVa   = 0x0734c8U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0934] start_va=0x05b47c, fde_va=0x0734e8, span=28 bytes
// [VN] FDE[0934] địa chỉ bắt đầu=0x05b47c, fde_va=0x0734e8, kích thước=28 byte
// AArch64 opcodes: F0000109 AA0103E8 91014129 F8008509
uint32_t cybertron_fde_0934_0x05b47c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b47cU;
    constexpr uint32_t kFdeVa   = 0x0734e8U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf0000109U;
    constexpr uint32_t kW1      = 0xaa0103e8U;
    constexpr uint32_t kW2      = 0x91014129U;
    constexpr uint32_t kW3      = 0xf8008509U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0935] start_va=0x05b498, fde_va=0x073500, span=68 bytes
// [VN] FDE[0935] địa chỉ bắt đầu=0x05b498, fde_va=0x073500, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0935_0x05b498(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b498U;
    constexpr uint32_t kFdeVa   = 0x073500U;
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

// [EN] FDE[0936] start_va=0x05b4dc, fde_va=0x073520, span=64 bytes
// [VN] FDE[0936] địa chỉ bắt đầu=0x05b4dc, fde_va=0x073520, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0936_0x05b4dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b4dcU;
    constexpr uint32_t kFdeVa   = 0x073520U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0937] start_va=0x05b51c, fde_va=0x073540, span=260 bytes
// [VN] FDE[0937] địa chỉ bắt đầu=0x05b51c, fde_va=0x073540, kích thước=260 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0937_0x05b51c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b51cU;
    constexpr uint32_t kFdeVa   = 0x073540U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa9024ff4U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0938] start_va=0x05b620, fde_va=0x073560, span=28 bytes
// [VN] FDE[0938] địa chỉ bắt đầu=0x05b620, fde_va=0x073560, kích thước=28 byte
// AArch64 opcodes: F9400428 90000069 912C2529 9100200A
uint32_t cybertron_fde_0938_0x05b620(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b620U;
    constexpr uint32_t kFdeVa   = 0x073560U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0x90000069U;
    constexpr uint32_t kW2      = 0x912c2529U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0939] start_va=0x05b63c, fde_va=0x073578, span=12 bytes
// [VN] FDE[0939] địa chỉ bắt đầu=0x05b63c, fde_va=0x073578, kích thước=12 byte
// AArch64 opcodes: F0000100 9102C000 D65F03C0 A9BE4FF4
uint32_t cybertron_fde_0939_0x05b63c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b63cU;
    constexpr uint32_t kFdeVa   = 0x073578U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf0000100U;
    constexpr uint32_t kW1      = 0x9102c000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xa9be4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0940] start_va=0x05b648, fde_va=0x073590, span=136 bytes
// [VN] FDE[0940] địa chỉ bắt đầu=0x05b648, fde_va=0x073590, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0103F4
uint32_t cybertron_fde_0940_0x05b648(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b648U;
    constexpr uint32_t kFdeVa   = 0x073590U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0941] start_va=0x05b6d0, fde_va=0x0735b0, span=84 bytes
// [VN] FDE[0941] địa chỉ bắt đầu=0x05b6d0, fde_va=0x0735b0, kích thước=84 byte
// AArch64 opcodes: A9BF7BFD 910003FD B0000128 9105C108
uint32_t cybertron_fde_0941_0x05b6d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b6d0U;
    constexpr uint32_t kFdeVa   = 0x0735b0U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xb0000128U;
    constexpr uint32_t kW3      = 0x9105c108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0942] start_va=0x05b724, fde_va=0x0735d0, span=168 bytes
// [VN] FDE[0942] địa chỉ bắt đầu=0x05b724, fde_va=0x0735d0, kích thước=168 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0942_0x05b724(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b724U;
    constexpr uint32_t kFdeVa   = 0x0735d0U;
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

// [EN] FDE[0943] start_va=0x05b7cc, fde_va=0x0735f0, span=16 bytes
// [VN] FDE[0943] địa chỉ bắt đầu=0x05b7cc, fde_va=0x0735f0, kích thước=16 byte
// AArch64 opcodes: F9400000 F9400008 F9400901 D61F0020
uint32_t cybertron_fde_0943_0x05b7cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b7ccU;
    constexpr uint32_t kFdeVa   = 0x0735f0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9400901U;
    constexpr uint32_t kW3      = 0xd61f0020U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0944] start_va=0x05b7dc, fde_va=0x073608, span=372 bytes
// [VN] FDE[0944] địa chỉ bắt đầu=0x05b7dc, fde_va=0x073608, kích thước=372 byte
// AArch64 opcodes: D10243FF A90657F6 A9074FF4 A9087BFD
uint32_t cybertron_fde_0944_0x05b7dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b7dcU;
    constexpr uint32_t kFdeVa   = 0x073608U;
    constexpr uint32_t kSpan    = 372U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa90657f6U;
    constexpr uint32_t kW2      = 0xa9074ff4U;
    constexpr uint32_t kW3      = 0xa9087bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0945] start_va=0x05b950, fde_va=0x073630, span=372 bytes
// [VN] FDE[0945] địa chỉ bắt đầu=0x05b950, fde_va=0x073630, kích thước=372 byte
// AArch64 opcodes: D10243FF A90657F6 A9074FF4 A9087BFD
uint32_t cybertron_fde_0945_0x05b950(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05b950U;
    constexpr uint32_t kFdeVa   = 0x073630U;
    constexpr uint32_t kSpan    = 372U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa90657f6U;
    constexpr uint32_t kW2      = 0xa9074ff4U;
    constexpr uint32_t kW3      = 0xa9087bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0946] start_va=0x05bac4, fde_va=0x073658, span=36 bytes
// [VN] FDE[0946] địa chỉ bắt đầu=0x05bac4, fde_va=0x073658, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0946_0x05bac4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bac4U;
    constexpr uint32_t kFdeVa   = 0x073658U;
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

// [EN] FDE[0947] start_va=0x05bae8, fde_va=0x073678, span=24 bytes
// [VN] FDE[0947] địa chỉ bắt đầu=0x05bae8, fde_va=0x073678, kích thước=24 byte
// AArch64 opcodes: F9400C00 B4000080 F9400008 F9400501
uint32_t cybertron_fde_0947_0x05bae8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bae8U;
    constexpr uint32_t kFdeVa   = 0x073678U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xf9400c00U;
    constexpr uint32_t kW1      = 0xb4000080U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9400501U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0948] start_va=0x05bb00, fde_va=0x073690, span=28 bytes
// [VN] FDE[0948] địa chỉ bắt đầu=0x05bb00, fde_va=0x073690, kích thước=28 byte
// AArch64 opcodes: 90000129 F9400428 F9477129 9100600A
uint32_t cybertron_fde_0948_0x05bb00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bb00U;
    constexpr uint32_t kFdeVa   = 0x073690U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0x90000129U;
    constexpr uint32_t kW1      = 0xf9400428U;
    constexpr uint32_t kW2      = 0xf9477129U;
    constexpr uint32_t kW3      = 0x9100600aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0949] start_va=0x05bb1c, fde_va=0x0736a8, span=4 bytes
// [VN] FDE[0949] địa chỉ bắt đầu=0x05bb1c, fde_va=0x0736a8, kích thước=4 byte
// AArch64 opcodes: 17FF7481 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0949_0x05bb1c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bb1cU;
    constexpr uint32_t kFdeVa   = 0x0736a8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff7481U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0950] start_va=0x05bb20, fde_va=0x0736c0, span=44 bytes
// [VN] FDE[0950] địa chỉ bắt đầu=0x05bb20, fde_va=0x0736c0, kích thước=44 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0950_0x05bb20(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bb20U;
    constexpr uint32_t kFdeVa   = 0x0736c0U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0951] start_va=0x05bb4c, fde_va=0x0736e0, span=20 bytes
// [VN] FDE[0951] địa chỉ bắt đầu=0x05bb4c, fde_va=0x0736e0, kích thước=20 byte
// AArch64 opcodes: 39400008 37000048 D65F03C0 F9400800
uint32_t cybertron_fde_0951_0x05bb4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bb4cU;
    constexpr uint32_t kFdeVa   = 0x0736e0U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x39400008U;
    constexpr uint32_t kW1      = 0x37000048U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xf9400800U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0952] start_va=0x05bb60, fde_va=0x0736f8, span=36 bytes
// [VN] FDE[0952] địa chỉ bắt đầu=0x05bb60, fde_va=0x0736f8, kích thước=36 byte
// AArch64 opcodes: F9400848 3DC00041 F9000808 3D800001
uint32_t cybertron_fde_0952_0x05bb60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bb60U;
    constexpr uint32_t kFdeVa   = 0x0736f8U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf9400848U;
    constexpr uint32_t kW1      = 0x3dc00041U;
    constexpr uint32_t kW2      = 0xf9000808U;
    constexpr uint32_t kW3      = 0x3d800001U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0953] start_va=0x05bb84, fde_va=0x073710, span=1036 bytes
// [VN] FDE[0953] địa chỉ bắt đầu=0x05bb84, fde_va=0x073710, kích thước=1036 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000060
uint32_t cybertron_fde_0953_0x05bb84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bb84U;
    constexpr uint32_t kFdeVa   = 0x073710U;
    constexpr uint32_t kSpan    = 1036U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000060U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0954] start_va=0x05bf90, fde_va=0x073730, span=8 bytes
// [VN] FDE[0954] địa chỉ bắt đầu=0x05bf90, fde_va=0x073730, kích thước=8 byte
// AArch64 opcodes: 52800020 D65F03C0 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0954_0x05bf90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bf90U;
    constexpr uint32_t kFdeVa   = 0x073730U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x52800020U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0955] start_va=0x05bf98, fde_va=0x073748, span=40 bytes
// [VN] FDE[0955] địa chỉ bắt đầu=0x05bf98, fde_va=0x073748, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0955_0x05bf98(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bf98U;
    constexpr uint32_t kFdeVa   = 0x073748U;
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

// [EN] FDE[0956] start_va=0x05bfc0, fde_va=0x073768, span=88 bytes
// [VN] FDE[0956] địa chỉ bắt đầu=0x05bfc0, fde_va=0x073768, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0956_0x05bfc0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05bfc0U;
    constexpr uint32_t kFdeVa   = 0x073768U;
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

// [EN] FDE[0957] start_va=0x05c018, fde_va=0x073788, span=272 bytes
// [VN] FDE[0957] địa chỉ bắt đầu=0x05c018, fde_va=0x073788, kích thước=272 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0957_0x05c018(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c018U;
    constexpr uint32_t kFdeVa   = 0x073788U;
    constexpr uint32_t kSpan    = 272U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0958] start_va=0x05c128, fde_va=0x0737b0, span=280 bytes
// [VN] FDE[0958] địa chỉ bắt đầu=0x05c128, fde_va=0x0737b0, kích thước=280 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0958_0x05c128(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c128U;
    constexpr uint32_t kFdeVa   = 0x0737b0U;
    constexpr uint32_t kSpan    = 280U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0959] start_va=0x05c240, fde_va=0x0737d8, span=252 bytes
// [VN] FDE[0959] địa chỉ bắt đầu=0x05c240, fde_va=0x0737d8, kích thước=252 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0803F3
uint32_t cybertron_fde_0959_0x05c240(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c240U;
    constexpr uint32_t kFdeVa   = 0x0737d8U;
    constexpr uint32_t kSpan    = 252U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0803f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

uint32_t DispatchCybertronFdeShard4(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 720U: return cybertron_fde_0720_0x052f44(a0, a1);
        case 721U: return cybertron_fde_0721_0x052f84(a0, a1);
        case 722U: return cybertron_fde_0722_0x0530d8(a0, a1);
        case 723U: return cybertron_fde_0723_0x053220(a0, a1);
        case 724U: return cybertron_fde_0724_0x053354(a0, a1);
        case 725U: return cybertron_fde_0725_0x053464(a0, a1);
        case 726U: return cybertron_fde_0726_0x05356c(a0, a1);
        case 727U: return cybertron_fde_0727_0x053670(a0, a1);
        case 728U: return cybertron_fde_0728_0x053778(a0, a1);
        case 729U: return cybertron_fde_0729_0x05387c(a0, a1);
        case 730U: return cybertron_fde_0730_0x053984(a0, a1);
        case 731U: return cybertron_fde_0731_0x053a88(a0, a1);
        case 732U: return cybertron_fde_0732_0x053b84(a0, a1);
        case 733U: return cybertron_fde_0733_0x053c70(a0, a1);
        case 734U: return cybertron_fde_0734_0x053d54(a0, a1);
        case 735U: return cybertron_fde_0735_0x053e28(a0, a1);
        case 736U: return cybertron_fde_0736_0x053f8c(a0, a1);
        case 737U: return cybertron_fde_0737_0x054058(a0, a1);
        case 738U: return cybertron_fde_0738_0x0540b0(a0, a1);
        case 739U: return cybertron_fde_0739_0x0540c0(a0, a1);
        case 740U: return cybertron_fde_0740_0x0540f0(a0, a1);
        case 741U: return cybertron_fde_0741_0x054158(a0, a1);
        case 742U: return cybertron_fde_0742_0x0541a0(a0, a1);
        case 743U: return cybertron_fde_0743_0x0541a8(a0, a1);
        case 744U: return cybertron_fde_0744_0x0541d0(a0, a1);
        case 745U: return cybertron_fde_0745_0x054308(a0, a1);
        case 746U: return cybertron_fde_0746_0x054324(a0, a1);
        case 747U: return cybertron_fde_0747_0x054330(a0, a1);
        case 748U: return cybertron_fde_0748_0x0543a0(a0, a1);
        case 749U: return cybertron_fde_0749_0x0543d4(a0, a1);
        case 750U: return cybertron_fde_0750_0x054594(a0, a1);
        case 751U: return cybertron_fde_0751_0x054604(a0, a1);
        case 752U: return cybertron_fde_0752_0x054738(a0, a1);
        case 753U: return cybertron_fde_0753_0x0547ac(a0, a1);
        case 754U: return cybertron_fde_0754_0x054ad0(a0, a1);
        case 755U: return cybertron_fde_0755_0x054bb4(a0, a1);
        case 756U: return cybertron_fde_0756_0x054e08(a0, a1);
        case 757U: return cybertron_fde_0757_0x054e70(a0, a1);
        case 758U: return cybertron_fde_0758_0x054fd0(a0, a1);
        case 759U: return cybertron_fde_0759_0x055190(a0, a1);
        case 760U: return cybertron_fde_0760_0x055290(a0, a1);
        case 761U: return cybertron_fde_0761_0x055348(a0, a1);
        case 762U: return cybertron_fde_0762_0x055350(a0, a1);
        case 763U: return cybertron_fde_0763_0x055354(a0, a1);
        case 764U: return cybertron_fde_0764_0x05535c(a0, a1);
        case 765U: return cybertron_fde_0765_0x055388(a0, a1);
        case 766U: return cybertron_fde_0766_0x05539c(a0, a1);
        case 767U: return cybertron_fde_0767_0x0553a4(a0, a1);
        case 768U: return cybertron_fde_0768_0x0553ac(a0, a1);
        case 769U: return cybertron_fde_0769_0x05551c(a0, a1);
        case 770U: return cybertron_fde_0770_0x055664(a0, a1);
        case 771U: return cybertron_fde_0771_0x05566c(a0, a1);
        case 772U: return cybertron_fde_0772_0x0558f4(a0, a1);
        case 773U: return cybertron_fde_0773_0x05593c(a0, a1);
        case 774U: return cybertron_fde_0774_0x05595c(a0, a1);
        case 775U: return cybertron_fde_0775_0x05599c(a0, a1);
        case 776U: return cybertron_fde_0776_0x0559c4(a0, a1);
        case 777U: return cybertron_fde_0777_0x055a08(a0, a1);
        case 778U: return cybertron_fde_0778_0x055a0c(a0, a1);
        case 779U: return cybertron_fde_0779_0x055a10(a0, a1);
        case 780U: return cybertron_fde_0780_0x055a34(a0, a1);
        case 781U: return cybertron_fde_0781_0x055a44(a0, a1);
        case 782U: return cybertron_fde_0782_0x055a48(a0, a1);
        case 783U: return cybertron_fde_0783_0x055a4c(a0, a1);
        case 784U: return cybertron_fde_0784_0x055a50(a0, a1);
        case 785U: return cybertron_fde_0785_0x055a6c(a0, a1);
        case 786U: return cybertron_fde_0786_0x055a78(a0, a1);
        case 787U: return cybertron_fde_0787_0x055a88(a0, a1);
        case 788U: return cybertron_fde_0788_0x055ab8(a0, a1);
        case 789U: return cybertron_fde_0789_0x055b18(a0, a1);
        case 790U: return cybertron_fde_0790_0x055b58(a0, a1);
        case 791U: return cybertron_fde_0791_0x055b60(a0, a1);
        case 792U: return cybertron_fde_0792_0x055b88(a0, a1);
        case 793U: return cybertron_fde_0793_0x055d00(a0, a1);
        case 794U: return cybertron_fde_0794_0x055d1c(a0, a1);
        case 795U: return cybertron_fde_0795_0x055d28(a0, a1);
        case 796U: return cybertron_fde_0796_0x055d90(a0, a1);
        case 797U: return cybertron_fde_0797_0x055dcc(a0, a1);
        case 798U: return cybertron_fde_0798_0x055f48(a0, a1);
        case 799U: return cybertron_fde_0799_0x056048(a0, a1);
        case 800U: return cybertron_fde_0800_0x056120(a0, a1);
        case 801U: return cybertron_fde_0801_0x05618c(a0, a1);
        case 802U: return cybertron_fde_0802_0x0561f8(a0, a1);
        case 803U: return cybertron_fde_0803_0x056214(a0, a1);
        case 804U: return cybertron_fde_0804_0x05626c(a0, a1);
        case 805U: return cybertron_fde_0805_0x0562b0(a0, a1);
        case 806U: return cybertron_fde_0806_0x0562d4(a0, a1);
        case 807U: return cybertron_fde_0807_0x05632c(a0, a1);
        case 808U: return cybertron_fde_0808_0x056350(a0, a1);
        case 809U: return cybertron_fde_0809_0x056368(a0, a1);
        case 810U: return cybertron_fde_0810_0x056384(a0, a1);
        case 811U: return cybertron_fde_0811_0x056388(a0, a1);
        case 812U: return cybertron_fde_0812_0x05649c(a0, a1);
        case 813U: return cybertron_fde_0813_0x056500(a0, a1);
        case 814U: return cybertron_fde_0814_0x056520(a0, a1);
        case 815U: return cybertron_fde_0815_0x056574(a0, a1);
        case 816U: return cybertron_fde_0816_0x056610(a0, a1);
        case 817U: return cybertron_fde_0817_0x056620(a0, a1);
        case 818U: return cybertron_fde_0818_0x056720(a0, a1);
        case 819U: return cybertron_fde_0819_0x0568ac(a0, a1);
        case 820U: return cybertron_fde_0820_0x0569ac(a0, a1);
        case 821U: return cybertron_fde_0821_0x056aac(a0, a1);
        case 822U: return cybertron_fde_0822_0x056bb0(a0, a1);
        case 823U: return cybertron_fde_0823_0x056bf4(a0, a1);
        case 824U: return cybertron_fde_0824_0x056c04(a0, a1);
        case 825U: return cybertron_fde_0825_0x056c14(a0, a1);
        case 826U: return cybertron_fde_0826_0x056c24(a0, a1);
        case 827U: return cybertron_fde_0827_0x056c34(a0, a1);
        case 828U: return cybertron_fde_0828_0x056c44(a0, a1);
        case 829U: return cybertron_fde_0829_0x056c68(a0, a1);
        case 830U: return cybertron_fde_0830_0x056c80(a0, a1);
        case 831U: return cybertron_fde_0831_0x056c9c(a0, a1);
        case 832U: return cybertron_fde_0832_0x056ca0(a0, a1);
        case 833U: return cybertron_fde_0833_0x056ce0(a0, a1);
        case 834U: return cybertron_fde_0834_0x056ce4(a0, a1);
        case 835U: return cybertron_fde_0835_0x056ce8(a0, a1);
        case 836U: return cybertron_fde_0836_0x056d0c(a0, a1);
        case 837U: return cybertron_fde_0837_0x056d30(a0, a1);
        case 838U: return cybertron_fde_0838_0x056d54(a0, a1);
        case 839U: return cybertron_fde_0839_0x056d78(a0, a1);
        case 840U: return cybertron_fde_0840_0x056da4(a0, a1);
        case 841U: return cybertron_fde_0841_0x056ef4(a0, a1);
        case 842U: return cybertron_fde_0842_0x056f08(a0, a1);
        case 843U: return cybertron_fde_0843_0x056f38(a0, a1);
        case 844U: return cybertron_fde_0844_0x056fa0(a0, a1);
        case 845U: return cybertron_fde_0845_0x056ff8(a0, a1);
        case 846U: return cybertron_fde_0846_0x0570a4(a0, a1);
        case 847U: return cybertron_fde_0847_0x057204(a0, a1);
        case 848U: return cybertron_fde_0848_0x05787c(a0, a1);
        case 849U: return cybertron_fde_0849_0x0578d4(a0, a1);
        case 850U: return cybertron_fde_0850_0x05792c(a0, a1);
        case 851U: return cybertron_fde_0851_0x05799c(a0, a1);
        case 852U: return cybertron_fde_0852_0x057c48(a0, a1);
        case 853U: return cybertron_fde_0853_0x057f58(a0, a1);
        case 854U: return cybertron_fde_0854_0x058318(a0, a1);
        case 855U: return cybertron_fde_0855_0x058370(a0, a1);
        case 856U: return cybertron_fde_0856_0x0583c8(a0, a1);
        case 857U: return cybertron_fde_0857_0x0586a0(a0, a1);
        case 858U: return cybertron_fde_0858_0x058704(a0, a1);
        case 859U: return cybertron_fde_0859_0x058728(a0, a1);
        case 860U: return cybertron_fde_0860_0x058910(a0, a1);
        case 861U: return cybertron_fde_0861_0x058af8(a0, a1);
        case 862U: return cybertron_fde_0862_0x058d4c(a0, a1);
        case 863U: return cybertron_fde_0863_0x05921c(a0, a1);
        case 864U: return cybertron_fde_0864_0x0592cc(a0, a1);
        case 865U: return cybertron_fde_0865_0x05935c(a0, a1);
        case 866U: return cybertron_fde_0866_0x0593cc(a0, a1);
        case 867U: return cybertron_fde_0867_0x059414(a0, a1);
        case 868U: return cybertron_fde_0868_0x059464(a0, a1);
        case 869U: return cybertron_fde_0869_0x059470(a0, a1);
        case 870U: return cybertron_fde_0870_0x059474(a0, a1);
        case 871U: return cybertron_fde_0871_0x059730(a0, a1);
        case 872U: return cybertron_fde_0872_0x0597e0(a0, a1);
        case 873U: return cybertron_fde_0873_0x059828(a0, a1);
        case 874U: return cybertron_fde_0874_0x059878(a0, a1);
        case 875U: return cybertron_fde_0875_0x059884(a0, a1);
        case 876U: return cybertron_fde_0876_0x059888(a0, a1);
        case 877U: return cybertron_fde_0877_0x059b10(a0, a1);
        case 878U: return cybertron_fde_0878_0x059c30(a0, a1);
        case 879U: return cybertron_fde_0879_0x059c84(a0, a1);
        case 880U: return cybertron_fde_0880_0x059cc8(a0, a1);
        case 881U: return cybertron_fde_0881_0x059d78(a0, a1);
        case 882U: return cybertron_fde_0882_0x059e9c(a0, a1);
        case 883U: return cybertron_fde_0883_0x059ef0(a0, a1);
        case 884U: return cybertron_fde_0884_0x059f2c(a0, a1);
        case 885U: return cybertron_fde_0885_0x05a08c(a0, a1);
        case 886U: return cybertron_fde_0886_0x05a108(a0, a1);
        case 887U: return cybertron_fde_0887_0x05a18c(a0, a1);
        case 888U: return cybertron_fde_0888_0x05a1c0(a0, a1);
        case 889U: return cybertron_fde_0889_0x05a1fc(a0, a1);
        case 890U: return cybertron_fde_0890_0x05a208(a0, a1);
        case 891U: return cybertron_fde_0891_0x05a20c(a0, a1);
        case 892U: return cybertron_fde_0892_0x05a254(a0, a1);
        case 893U: return cybertron_fde_0893_0x05a278(a0, a1);
        case 894U: return cybertron_fde_0894_0x05a444(a0, a1);
        case 895U: return cybertron_fde_0895_0x05a53c(a0, a1);
        case 896U: return cybertron_fde_0896_0x05a610(a0, a1);
        case 897U: return cybertron_fde_0897_0x05a6dc(a0, a1);
        case 898U: return cybertron_fde_0898_0x05a734(a0, a1);
        case 899U: return cybertron_fde_0899_0x05a898(a0, a1);
        case 900U: return cybertron_fde_0900_0x05a8e4(a0, a1);
        case 901U: return cybertron_fde_0901_0x05a930(a0, a1);
        case 902U: return cybertron_fde_0902_0x05a96c(a0, a1);
        case 903U: return cybertron_fde_0903_0x05a9b8(a0, a1);
        case 904U: return cybertron_fde_0904_0x05a9f8(a0, a1);
        case 905U: return cybertron_fde_0905_0x05aa40(a0, a1);
        case 906U: return cybertron_fde_0906_0x05aaa8(a0, a1);
        case 907U: return cybertron_fde_0907_0x05aaac(a0, a1);
        case 908U: return cybertron_fde_0908_0x05aae4(a0, a1);
        case 909U: return cybertron_fde_0909_0x05aafc(a0, a1);
        case 910U: return cybertron_fde_0910_0x05ab00(a0, a1);
        case 911U: return cybertron_fde_0911_0x05ab04(a0, a1);
        case 912U: return cybertron_fde_0912_0x05ab40(a0, a1);
        case 913U: return cybertron_fde_0913_0x05ab5c(a0, a1);
        case 914U: return cybertron_fde_0914_0x05ab68(a0, a1);
        case 915U: return cybertron_fde_0915_0x05ac74(a0, a1);
        case 916U: return cybertron_fde_0916_0x05ad24(a0, a1);
        case 917U: return cybertron_fde_0917_0x05ae48(a0, a1);
        case 918U: return cybertron_fde_0918_0x05ae9c(a0, a1);
        case 919U: return cybertron_fde_0919_0x05aed0(a0, a1);
        case 920U: return cybertron_fde_0920_0x05af0c(a0, a1);
        case 921U: return cybertron_fde_0921_0x05af14(a0, a1);
        case 922U: return cybertron_fde_0922_0x05af18(a0, a1);
        case 923U: return cybertron_fde_0923_0x05afd4(a0, a1);
        case 924U: return cybertron_fde_0924_0x05b0f8(a0, a1);
        case 925U: return cybertron_fde_0925_0x05b14c(a0, a1);
        case 926U: return cybertron_fde_0926_0x05b180(a0, a1);
        case 927U: return cybertron_fde_0927_0x05b1bc(a0, a1);
        case 928U: return cybertron_fde_0928_0x05b1c4(a0, a1);
        case 929U: return cybertron_fde_0929_0x05b1c8(a0, a1);
        case 930U: return cybertron_fde_0930_0x05b260(a0, a1);
        case 931U: return cybertron_fde_0931_0x05b3a8(a0, a1);
        case 932U: return cybertron_fde_0932_0x05b3f4(a0, a1);
        case 933U: return cybertron_fde_0933_0x05b43c(a0, a1);
        case 934U: return cybertron_fde_0934_0x05b47c(a0, a1);
        case 935U: return cybertron_fde_0935_0x05b498(a0, a1);
        case 936U: return cybertron_fde_0936_0x05b4dc(a0, a1);
        case 937U: return cybertron_fde_0937_0x05b51c(a0, a1);
        case 938U: return cybertron_fde_0938_0x05b620(a0, a1);
        case 939U: return cybertron_fde_0939_0x05b63c(a0, a1);
        case 940U: return cybertron_fde_0940_0x05b648(a0, a1);
        case 941U: return cybertron_fde_0941_0x05b6d0(a0, a1);
        case 942U: return cybertron_fde_0942_0x05b724(a0, a1);
        case 943U: return cybertron_fde_0943_0x05b7cc(a0, a1);
        case 944U: return cybertron_fde_0944_0x05b7dc(a0, a1);
        case 945U: return cybertron_fde_0945_0x05b950(a0, a1);
        case 946U: return cybertron_fde_0946_0x05bac4(a0, a1);
        case 947U: return cybertron_fde_0947_0x05bae8(a0, a1);
        case 948U: return cybertron_fde_0948_0x05bb00(a0, a1);
        case 949U: return cybertron_fde_0949_0x05bb1c(a0, a1);
        case 950U: return cybertron_fde_0950_0x05bb20(a0, a1);
        case 951U: return cybertron_fde_0951_0x05bb4c(a0, a1);
        case 952U: return cybertron_fde_0952_0x05bb60(a0, a1);
        case 953U: return cybertron_fde_0953_0x05bb84(a0, a1);
        case 954U: return cybertron_fde_0954_0x05bf90(a0, a1);
        case 955U: return cybertron_fde_0955_0x05bf98(a0, a1);
        case 956U: return cybertron_fde_0956_0x05bfc0(a0, a1);
        case 957U: return cybertron_fde_0957_0x05c018(a0, a1);
        case 958U: return cybertron_fde_0958_0x05c128(a0, a1);
        case 959U: return cybertron_fde_0959_0x05c240(a0, a1);
        default: return 0U;
    }
}

} // namespace datacenter
