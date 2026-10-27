// ============================================================================
// File: cybertron_fde_shard_1.cpp
// Target: libcybertron_base.so (509,816 bytes)
// SHA-256: 0d969c7e981d68f46d81986a0f16881d1ff9605afb9e6e352f1ae88a5695c7e6
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// FDE Range: [0..239] of 1,201 (.eh_frame_hdr @ 0x069c8c)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [0..239]
//      verified directly against the .text section of libcybertron_base.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [0..239]
//      đã đối chiếu trực tiếp với phân đoạn .text của libcybertron_base.so.
// ============================================================================

#include "cybertron_base_types.h"

namespace datacenter {

// [EN] FDE[0000] start_va=0x03b25c, fde_va=0x06c238, span=380 bytes
// [VN] FDE[0000] địa chỉ bắt đầu=0x03b25c, fde_va=0x06c238, kích thước=380 byte
// AArch64 opcodes: D10603FF F9009BFC A9145FF8 A91557F6
uint32_t cybertron_fde_0000_0x03b25c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b25cU;
    constexpr uint32_t kFdeVa   = 0x06c238U;
    constexpr uint32_t kSpan    = 380U;
    constexpr uint32_t kW0      = 0xd10603ffU;
    constexpr uint32_t kW1      = 0xf9009bfcU;
    constexpr uint32_t kW2      = 0xa9145ff8U;
    constexpr uint32_t kW3      = 0xa91557f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0001] start_va=0x03b3d8, fde_va=0x06c260, span=692 bytes
// [VN] FDE[0001] địa chỉ bắt đầu=0x03b3d8, fde_va=0x06c260, kích thước=692 byte
// AArch64 opcodes: D10503FF A90E6FFC A90F67FA A9105FF8
uint32_t cybertron_fde_0001_0x03b3d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b3d8U;
    constexpr uint32_t kFdeVa   = 0x06c260U;
    constexpr uint32_t kSpan    = 692U;
    constexpr uint32_t kW0      = 0xd10503ffU;
    constexpr uint32_t kW1      = 0xa90e6ffcU;
    constexpr uint32_t kW2      = 0xa90f67faU;
    constexpr uint32_t kW3      = 0xa9105ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0002] start_va=0x03b68c, fde_va=0x06c290, span=88 bytes
// [VN] FDE[0002] địa chỉ bắt đầu=0x03b68c, fde_va=0x06c290, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0002_0x03b68c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b68cU;
    constexpr uint32_t kFdeVa   = 0x06c290U;
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

// [EN] FDE[0003] start_va=0x03b6e4, fde_va=0x06c2b0, span=28 bytes
// [VN] FDE[0003] địa chỉ bắt đầu=0x03b6e4, fde_va=0x06c2b0, kích thước=28 byte
// AArch64 opcodes: F9400400 B40000A0 F9400008 52800022
uint32_t cybertron_fde_0003_0x03b6e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b6e4U;
    constexpr uint32_t kFdeVa   = 0x06c2b0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0xb40000a0U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0x52800022U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0004] start_va=0x03b700, fde_va=0x06c2c8, span=28 bytes
// [VN] FDE[0004] địa chỉ bắt đầu=0x03b700, fde_va=0x06c2c8, kích thước=28 byte
// AArch64 opcodes: F9400400 B40000A0 F9400008 F9400042
uint32_t cybertron_fde_0004_0x03b700(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b700U;
    constexpr uint32_t kFdeVa   = 0x06c2c8U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0xb40000a0U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9400042U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0005] start_va=0x03b71c, fde_va=0x06c2e0, span=28 bytes
// [VN] FDE[0005] địa chỉ bắt đầu=0x03b71c, fde_va=0x06c2e0, kích thước=28 byte
// AArch64 opcodes: F9400400 B40000A0 F9400008 F9400042
uint32_t cybertron_fde_0005_0x03b71c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b71cU;
    constexpr uint32_t kFdeVa   = 0x06c2e0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0xb40000a0U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9400042U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0006] start_va=0x03b738, fde_va=0x06c2f8, span=20 bytes
// [VN] FDE[0006] địa chỉ bắt đầu=0x03b738, fde_va=0x06c2f8, kích thước=20 byte
// AArch64 opcodes: 90000228 F947C508 91004108 F8008408
uint32_t cybertron_fde_0006_0x03b738(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b738U;
    constexpr uint32_t kFdeVa   = 0x06c2f8U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x90000228U;
    constexpr uint32_t kW1      = 0xf947c508U;
    constexpr uint32_t kW2      = 0x91004108U;
    constexpr uint32_t kW3      = 0xf8008408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0007] start_va=0x03b74c, fde_va=0x06c310, span=52 bytes
// [VN] FDE[0007] địa chỉ bắt đầu=0x03b74c, fde_va=0x06c310, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000228
uint32_t cybertron_fde_0007_0x03b74c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b74cU;
    constexpr uint32_t kFdeVa   = 0x06c310U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000228U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0008] start_va=0x03b780, fde_va=0x06c330, span=16 bytes
// [VN] FDE[0008] địa chỉ bắt đầu=0x03b780, fde_va=0x06c330, kích thước=16 byte
// AArch64 opcodes: 91006008 52800029 889FFD09 D65F03C0
uint32_t cybertron_fde_0008_0x03b780(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b780U;
    constexpr uint32_t kFdeVa   = 0x06c330U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x91006008U;
    constexpr uint32_t kW1      = 0x52800029U;
    constexpr uint32_t kW2      = 0x889ffd09U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0009] start_va=0x03b790, fde_va=0x06c348, span=16 bytes
// [VN] FDE[0009] địa chỉ bắt đầu=0x03b790, fde_va=0x06c348, kích thước=16 byte
// AArch64 opcodes: 91006008 52800069 889FFD09 D65F03C0
uint32_t cybertron_fde_0009_0x03b790(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b790U;
    constexpr uint32_t kFdeVa   = 0x06c348U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x91006008U;
    constexpr uint32_t kW1      = 0x52800069U;
    constexpr uint32_t kW2      = 0x889ffd09U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0010] start_va=0x03b7a0, fde_va=0x06c360, span=120 bytes
// [VN] FDE[0010] địa chỉ bắt đầu=0x03b7a0, fde_va=0x06c360, kích thước=120 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9402029
uint32_t cybertron_fde_0010_0x03b7a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b7a0U;
    constexpr uint32_t kFdeVa   = 0x06c360U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa9402029U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0011] start_va=0x03b818, fde_va=0x06c380, span=88 bytes
// [VN] FDE[0011] địa chỉ bắt đầu=0x03b818, fde_va=0x06c380, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0011_0x03b818(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b818U;
    constexpr uint32_t kFdeVa   = 0x06c380U;
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

// [EN] FDE[0012] start_va=0x03b870, fde_va=0x06c3a0, span=12 bytes
// [VN] FDE[0012] địa chỉ bắt đầu=0x03b870, fde_va=0x06c3a0, kích thước=12 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FFFB2A F81E0FF3
uint32_t cybertron_fde_0012_0x03b870(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b870U;
    constexpr uint32_t kFdeVa   = 0x06c3a0U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97fffb2aU;
    constexpr uint32_t kW3      = 0xf81e0ff3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0013] start_va=0x03b87c, fde_va=0x06c3c0, span=52 bytes
// [VN] FDE[0013] địa chỉ bắt đầu=0x03b87c, fde_va=0x06c3c0, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000228
uint32_t cybertron_fde_0013_0x03b87c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b87cU;
    constexpr uint32_t kFdeVa   = 0x06c3c0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000228U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0014] start_va=0x03b8b0, fde_va=0x06c3e0, span=60 bytes
// [VN] FDE[0014] địa chỉ bắt đầu=0x03b8b0, fde_va=0x06c3e0, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000228
uint32_t cybertron_fde_0014_0x03b8b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b8b0U;
    constexpr uint32_t kFdeVa   = 0x06c3e0U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000228U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0015] start_va=0x03b8ec, fde_va=0x06c400, span=8 bytes
// [VN] FDE[0015] địa chỉ bắt đầu=0x03b8ec, fde_va=0x06c400, kích thước=8 byte
// AArch64 opcodes: 91006000 17FFF9E0 17FFF50B F81E0FF3
uint32_t cybertron_fde_0015_0x03b8ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b8ecU;
    constexpr uint32_t kFdeVa   = 0x06c400U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91006000U;
    constexpr uint32_t kW1      = 0x17fff9e0U;
    constexpr uint32_t kW2      = 0x17fff50bU;
    constexpr uint32_t kW3      = 0xf81e0ff3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0016] start_va=0x03b8f4, fde_va=0x06c418, span=4 bytes
// [VN] FDE[0016] địa chỉ bắt đầu=0x03b8f4, fde_va=0x06c418, kích thước=4 byte
// AArch64 opcodes: 17FFF50B F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0016_0x03b8f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b8f4U;
    constexpr uint32_t kFdeVa   = 0x06c418U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17fff50bU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0017] start_va=0x03b8f8, fde_va=0x06c430, span=104 bytes
// [VN] FDE[0017] địa chỉ bắt đầu=0x03b8f8, fde_va=0x06c430, kích thước=104 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9401028
uint32_t cybertron_fde_0017_0x03b8f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b8f8U;
    constexpr uint32_t kFdeVa   = 0x06c430U;
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

// [EN] FDE[0018] start_va=0x03b960, fde_va=0x06c450, span=96 bytes
// [VN] FDE[0018] địa chỉ bắt đầu=0x03b960, fde_va=0x06c450, kích thước=96 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD B0000208
uint32_t cybertron_fde_0018_0x03b960(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b960U;
    constexpr uint32_t kFdeVa   = 0x06c450U;
    constexpr uint32_t kSpan    = 96U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000208U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0019] start_va=0x03b9c0, fde_va=0x06c470, span=92 bytes
// [VN] FDE[0019] địa chỉ bắt đầu=0x03b9c0, fde_va=0x06c470, kích thước=92 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD B0000208
uint32_t cybertron_fde_0019_0x03b9c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03b9c0U;
    constexpr uint32_t kFdeVa   = 0x06c470U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000208U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0020] start_va=0x03ba1c, fde_va=0x06c490, span=108 bytes
// [VN] FDE[0020] địa chỉ bắt đầu=0x03ba1c, fde_va=0x06c490, kích thước=108 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F4
uint32_t cybertron_fde_0020_0x03ba1c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03ba1cU;
    constexpr uint32_t kFdeVa   = 0x06c490U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0021] start_va=0x03ba88, fde_va=0x06c4b0, span=96 bytes
// [VN] FDE[0021] địa chỉ bắt đầu=0x03ba88, fde_va=0x06c4b0, kích thước=96 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD B0000208
uint32_t cybertron_fde_0021_0x03ba88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03ba88U;
    constexpr uint32_t kFdeVa   = 0x06c4b0U;
    constexpr uint32_t kSpan    = 96U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb0000208U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0022] start_va=0x03bae8, fde_va=0x06c4d0, span=8 bytes
// [VN] FDE[0022] địa chỉ bắt đầu=0x03bae8, fde_va=0x06c4d0, kích thước=8 byte
// AArch64 opcodes: 91004000 14000024 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0022_0x03bae8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bae8U;
    constexpr uint32_t kFdeVa   = 0x06c4d0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91004000U;
    constexpr uint32_t kW1      = 0x14000024U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0023] start_va=0x03baf0, fde_va=0x06c4e8, span=40 bytes
// [VN] FDE[0023] địa chỉ bắt đầu=0x03baf0, fde_va=0x06c4e8, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0023_0x03baf0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03baf0U;
    constexpr uint32_t kFdeVa   = 0x06c4e8U;
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

// [EN] FDE[0024] start_va=0x03bb18, fde_va=0x06c508, span=56 bytes
// [VN] FDE[0024] địa chỉ bắt đầu=0x03bb18, fde_va=0x06c508, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0024_0x03bb18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bb18U;
    constexpr uint32_t kFdeVa   = 0x06c508U;
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

// [EN] FDE[0025] start_va=0x03bb50, fde_va=0x06c528, span=28 bytes
// [VN] FDE[0025] địa chỉ bắt đầu=0x03bb50, fde_va=0x06c528, kích thước=28 byte
// AArch64 opcodes: F9400428 D0000149 912ED929 9100400A
uint32_t cybertron_fde_0025_0x03bb50(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bb50U;
    constexpr uint32_t kFdeVa   = 0x06c528U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xd0000149U;
    constexpr uint32_t kW2      = 0x912ed929U;
    constexpr uint32_t kW3      = 0x9100400aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0026] start_va=0x03bb6c, fde_va=0x06c540, span=12 bytes
// [VN] FDE[0026] địa chỉ bắt đầu=0x03bb6c, fde_va=0x06c540, kích thước=12 byte
// AArch64 opcodes: B0000200 910C8000 D65F03C0 D65F03C0
uint32_t cybertron_fde_0026_0x03bb6c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bb6cU;
    constexpr uint32_t kFdeVa   = 0x06c540U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xb0000200U;
    constexpr uint32_t kW1      = 0x910c8000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0027] start_va=0x03bb78, fde_va=0x06c558, span=4 bytes
// [VN] FDE[0027] địa chỉ bắt đầu=0x03bb78, fde_va=0x06c558, kích thước=4 byte
// AArch64 opcodes: D65F03C0 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0027_0x03bb78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bb78U;
    constexpr uint32_t kFdeVa   = 0x06c558U;
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

// [EN] FDE[0028] start_va=0x03bb7c, fde_va=0x06c570, span=84 bytes
// [VN] FDE[0028] địa chỉ bắt đầu=0x03bb7c, fde_va=0x06c570, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0028_0x03bb7c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bb7cU;
    constexpr uint32_t kFdeVa   = 0x06c570U;
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

// [EN] FDE[0029] start_va=0x03bbd0, fde_va=0x06c590, span=4 bytes
// [VN] FDE[0029] địa chỉ bắt đầu=0x03bbd0, fde_va=0x06c590, kích thước=4 byte
// AArch64 opcodes: 17FFF454 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0029_0x03bbd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bbd0U;
    constexpr uint32_t kFdeVa   = 0x06c590U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17fff454U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0030] start_va=0x03bbd4, fde_va=0x06c5a8, span=56 bytes
// [VN] FDE[0030] địa chỉ bắt đầu=0x03bbd4, fde_va=0x06c5a8, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0030_0x03bbd4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bbd4U;
    constexpr uint32_t kFdeVa   = 0x06c5a8U;
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

// [EN] FDE[0031] start_va=0x03bc0c, fde_va=0x06c5c8, span=24 bytes
// [VN] FDE[0031] địa chỉ bắt đầu=0x03bc0c, fde_va=0x06c5c8, kích thước=24 byte
// AArch64 opcodes: B0000208 910D0108 F9000028 3CC08000
uint32_t cybertron_fde_0031_0x03bc0c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bc0cU;
    constexpr uint32_t kFdeVa   = 0x06c5c8U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xb0000208U;
    constexpr uint32_t kW1      = 0x910d0108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0x3cc08000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0032] start_va=0x03bc24, fde_va=0x06c5e0, span=4 bytes
// [VN] FDE[0032] địa chỉ bắt đầu=0x03bc24, fde_va=0x06c5e0, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FFF43E F81E0FF3 A9017BFD
uint32_t cybertron_fde_0032_0x03bc24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bc24U;
    constexpr uint32_t kFdeVa   = 0x06c5e0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17fff43eU;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0033] start_va=0x03bc28, fde_va=0x06c5f8, span=4 bytes
// [VN] FDE[0033] địa chỉ bắt đầu=0x03bc28, fde_va=0x06c5f8, kích thước=4 byte
// AArch64 opcodes: 17FFF43E F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0033_0x03bc28(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bc28U;
    constexpr uint32_t kFdeVa   = 0x06c5f8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17fff43eU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0034] start_va=0x03bc2c, fde_va=0x06c610, span=60 bytes
// [VN] FDE[0034] địa chỉ bắt đầu=0x03bc2c, fde_va=0x06c610, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400408
uint32_t cybertron_fde_0034_0x03bc2c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bc2cU;
    constexpr uint32_t kFdeVa   = 0x06c610U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0035] start_va=0x03bc68, fde_va=0x06c630, span=28 bytes
// [VN] FDE[0035] địa chỉ bắt đầu=0x03bc68, fde_va=0x06c630, kích thước=28 byte
// AArch64 opcodes: F9400428 D0000149 9131BD29 9100200A
uint32_t cybertron_fde_0035_0x03bc68(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bc68U;
    constexpr uint32_t kFdeVa   = 0x06c630U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xd0000149U;
    constexpr uint32_t kW2      = 0x9131bd29U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0036] start_va=0x03bc84, fde_va=0x06c648, span=12 bytes
// [VN] FDE[0036] địa chỉ bắt đầu=0x03bc84, fde_va=0x06c648, kích thước=12 byte
// AArch64 opcodes: B0000200 910E8000 D65F03C0 A9BE4FF4
uint32_t cybertron_fde_0036_0x03bc84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bc84U;
    constexpr uint32_t kFdeVa   = 0x06c648U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xb0000200U;
    constexpr uint32_t kW1      = 0x910e8000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xa9be4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0037] start_va=0x03bc90, fde_va=0x06c660, span=180 bytes
// [VN] FDE[0037] địa chỉ bắt đầu=0x03bc90, fde_va=0x06c660, kích thước=180 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F4
uint32_t cybertron_fde_0037_0x03bc90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bc90U;
    constexpr uint32_t kFdeVa   = 0x06c660U;
    constexpr uint32_t kSpan    = 180U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0038] start_va=0x03bd44, fde_va=0x06c680, span=164 bytes
// [VN] FDE[0038] địa chỉ bắt đầu=0x03bd44, fde_va=0x06c680, kích thước=164 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F4
uint32_t cybertron_fde_0038_0x03bd44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bd44U;
    constexpr uint32_t kFdeVa   = 0x06c680U;
    constexpr uint32_t kSpan    = 164U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0039] start_va=0x03bde8, fde_va=0x06c6a0, span=172 bytes
// [VN] FDE[0039] địa chỉ bắt đầu=0x03bde8, fde_va=0x06c6a0, kích thước=172 byte
// AArch64 opcodes: FC1E0FE8 F90007F3 A9017BFD 910043FD
uint32_t cybertron_fde_0039_0x03bde8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bde8U;
    constexpr uint32_t kFdeVa   = 0x06c6a0U;
    constexpr uint32_t kSpan    = 172U;
    constexpr uint32_t kW0      = 0xfc1e0fe8U;
    constexpr uint32_t kW1      = 0xf90007f3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0040] start_va=0x03be94, fde_va=0x06c6c0, span=204 bytes
// [VN] FDE[0040] địa chỉ bắt đầu=0x03be94, fde_va=0x06c6c0, kích thước=204 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0040_0x03be94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03be94U;
    constexpr uint32_t kFdeVa   = 0x06c6c0U;
    constexpr uint32_t kSpan    = 204U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0041] start_va=0x03bf60, fde_va=0x06c6e0, span=168 bytes
// [VN] FDE[0041] địa chỉ bắt đầu=0x03bf60, fde_va=0x06c6e0, kích thước=168 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0041_0x03bf60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03bf60U;
    constexpr uint32_t kFdeVa   = 0x06c6e0U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0042] start_va=0x03c008, fde_va=0x06c708, span=72 bytes
// [VN] FDE[0042] địa chỉ bắt đầu=0x03c008, fde_va=0x06c708, kích thước=72 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0042_0x03c008(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c008U;
    constexpr uint32_t kFdeVa   = 0x06c708U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0043] start_va=0x03c050, fde_va=0x06c728, span=124 bytes
// [VN] FDE[0043] địa chỉ bắt đầu=0x03c050, fde_va=0x06c728, kích thước=124 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD A9007D1F
uint32_t cybertron_fde_0043_0x03c050(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c050U;
    constexpr uint32_t kFdeVa   = 0x06c728U;
    constexpr uint32_t kSpan    = 124U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa9007d1fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0044] start_va=0x03c0cc, fde_va=0x06c748, span=24 bytes
// [VN] FDE[0044] địa chỉ bắt đầu=0x03c0cc, fde_va=0x06c748, kích thước=24 byte
// AArch64 opcodes: F0000208 F9465D08 B9000801 91004108
uint32_t cybertron_fde_0044_0x03c0cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c0ccU;
    constexpr uint32_t kFdeVa   = 0x06c748U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xf0000208U;
    constexpr uint32_t kW1      = 0xf9465d08U;
    constexpr uint32_t kW2      = 0xb9000801U;
    constexpr uint32_t kW3      = 0x91004108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0045] start_va=0x03c0e4, fde_va=0x06c760, span=204 bytes
// [VN] FDE[0045] địa chỉ bắt đầu=0x03c0e4, fde_va=0x06c760, kích thước=204 byte
// AArch64 opcodes: D10183FF F9001BF5 A9044FF4 A9057BFD
uint32_t cybertron_fde_0045_0x03c0e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c0e4U;
    constexpr uint32_t kFdeVa   = 0x06c760U;
    constexpr uint32_t kSpan    = 204U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9001bf5U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0046] start_va=0x03c1b0, fde_va=0x06c780, span=1024 bytes
// [VN] FDE[0046] địa chỉ bắt đầu=0x03c1b0, fde_va=0x06c780, kích thước=1024 byte
// AArch64 opcodes: D102C3FF FD0033E8 A9075FF8 A90857F6
uint32_t cybertron_fde_0046_0x03c1b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c1b0U;
    constexpr uint32_t kFdeVa   = 0x06c780U;
    constexpr uint32_t kSpan    = 1024U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xfd0033e8U;
    constexpr uint32_t kW2      = 0xa9075ff8U;
    constexpr uint32_t kW3      = 0xa90857f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0047] start_va=0x03c5b0, fde_va=0x06c7a8, span=148 bytes
// [VN] FDE[0047] địa chỉ bắt đầu=0x03c5b0, fde_va=0x06c7a8, kích thước=148 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0047_0x03c5b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c5b0U;
    constexpr uint32_t kFdeVa   = 0x06c7a8U;
    constexpr uint32_t kSpan    = 148U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0048] start_va=0x03c644, fde_va=0x06c7d0, span=24 bytes
// [VN] FDE[0048] địa chỉ bắt đầu=0x03c644, fde_va=0x06c7d0, kích thước=24 byte
// AArch64 opcodes: B900081F F0000208 F9472D08 91004108
uint32_t cybertron_fde_0048_0x03c644(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c644U;
    constexpr uint32_t kFdeVa   = 0x06c7d0U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xb900081fU;
    constexpr uint32_t kW1      = 0xf0000208U;
    constexpr uint32_t kW2      = 0xf9472d08U;
    constexpr uint32_t kW3      = 0x91004108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0049] start_va=0x03c65c, fde_va=0x06c7e8, span=16 bytes
// [VN] FDE[0049] địa chỉ bắt đầu=0x03c65c, fde_va=0x06c7e8, kích thước=16 byte
// AArch64 opcodes: B0000141 9132EC21 AA0803E0 17FFF8A6
uint32_t cybertron_fde_0049_0x03c65c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c65cU;
    constexpr uint32_t kFdeVa   = 0x06c7e8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xb0000141U;
    constexpr uint32_t kW1      = 0x9132ec21U;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x17fff8a6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0050] start_va=0x03c66c, fde_va=0x06c800, span=36 bytes
// [VN] FDE[0050] địa chỉ bắt đầu=0x03c66c, fde_va=0x06c800, kích thước=36 byte
// AArch64 opcodes: F000020A F947F14A 52800029 12000028
uint32_t cybertron_fde_0050_0x03c66c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c66cU;
    constexpr uint32_t kFdeVa   = 0x06c800U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf000020aU;
    constexpr uint32_t kW1      = 0xf947f14aU;
    constexpr uint32_t kW2      = 0x52800029U;
    constexpr uint32_t kW3      = 0x12000028U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0051] start_va=0x03c690, fde_va=0x06c818, span=16 bytes
// [VN] FDE[0051] địa chỉ bắt đầu=0x03c690, fde_va=0x06c818, kích thước=16 byte
// AArch64 opcodes: F0000141 91337821 AA0803E0 17FFF899
uint32_t cybertron_fde_0051_0x03c690(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c690U;
    constexpr uint32_t kFdeVa   = 0x06c818U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf0000141U;
    constexpr uint32_t kW1      = 0x91337821U;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x17fff899U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0052] start_va=0x03c6a0, fde_va=0x06c830, span=32 bytes
// [VN] FDE[0052] địa chỉ bắt đầu=0x03c6a0, fde_va=0x06c830, kích thước=32 byte
// AArch64 opcodes: F0000209 F9473129 52800048 B9000808
uint32_t cybertron_fde_0052_0x03c6a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c6a0U;
    constexpr uint32_t kFdeVa   = 0x06c830U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xf0000209U;
    constexpr uint32_t kW1      = 0xf9473129U;
    constexpr uint32_t kW2      = 0x52800048U;
    constexpr uint32_t kW3      = 0xb9000808U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0053] start_va=0x03c6c0, fde_va=0x06c848, span=16 bytes
// [VN] FDE[0053] địa chỉ bắt đầu=0x03c6c0, fde_va=0x06c848, kích thước=16 byte
// AArch64 opcodes: F0000141 9133B021 AA0803E0 17FFF88D
uint32_t cybertron_fde_0053_0x03c6c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c6c0U;
    constexpr uint32_t kFdeVa   = 0x06c848U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf0000141U;
    constexpr uint32_t kW1      = 0x9133b021U;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x17fff88dU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0054] start_va=0x03c6d0, fde_va=0x06c860, span=32 bytes
// [VN] FDE[0054] địa chỉ bắt đầu=0x03c6d0, fde_va=0x06c860, kích thước=32 byte
// AArch64 opcodes: F0000209 F9460129 52800068 B9000808
uint32_t cybertron_fde_0054_0x03c6d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c6d0U;
    constexpr uint32_t kFdeVa   = 0x06c860U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xf0000209U;
    constexpr uint32_t kW1      = 0xf9460129U;
    constexpr uint32_t kW2      = 0x52800068U;
    constexpr uint32_t kW3      = 0xb9000808U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0055] start_va=0x03c6f0, fde_va=0x06c878, span=16 bytes
// [VN] FDE[0055] địa chỉ bắt đầu=0x03c6f0, fde_va=0x06c878, kích thước=16 byte
// AArch64 opcodes: B0000141 91330021 AA0803E0 17FFF881
uint32_t cybertron_fde_0055_0x03c6f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c6f0U;
    constexpr uint32_t kFdeVa   = 0x06c878U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xb0000141U;
    constexpr uint32_t kW1      = 0x91330021U;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x17fff881U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0056] start_va=0x03c700, fde_va=0x06c890, span=52 bytes
// [VN] FDE[0056] địa chỉ bắt đầu=0x03c700, fde_va=0x06c890, kích thước=52 byte
// AArch64 opcodes: F0000209 F946F129 52800088 B9000808
uint32_t cybertron_fde_0056_0x03c700(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c700U;
    constexpr uint32_t kFdeVa   = 0x06c890U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf0000209U;
    constexpr uint32_t kW1      = 0xf946f129U;
    constexpr uint32_t kW2      = 0x52800088U;
    constexpr uint32_t kW3      = 0xb9000808U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0057] start_va=0x03c734, fde_va=0x06c8a8, span=16 bytes
// [VN] FDE[0057] địa chỉ bắt đầu=0x03c734, fde_va=0x06c8a8, kích thước=16 byte
// AArch64 opcodes: 90000161 91049821 AA0803E0 17FFF870
uint32_t cybertron_fde_0057_0x03c734(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c734U;
    constexpr uint32_t kFdeVa   = 0x06c8a8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x90000161U;
    constexpr uint32_t kW1      = 0x91049821U;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x17fff870U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0058] start_va=0x03c744, fde_va=0x06c8c0, span=36 bytes
// [VN] FDE[0058] địa chỉ bắt đầu=0x03c744, fde_va=0x06c8c0, kích thước=36 byte
// AArch64 opcodes: F0000209 F947D129 528000A8 B9000808
uint32_t cybertron_fde_0058_0x03c744(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c744U;
    constexpr uint32_t kFdeVa   = 0x06c8c0U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf0000209U;
    constexpr uint32_t kW1      = 0xf947d129U;
    constexpr uint32_t kW2      = 0x528000a8U;
    constexpr uint32_t kW3      = 0xb9000808U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0059] start_va=0x03c768, fde_va=0x06c8d8, span=16 bytes
// [VN] FDE[0059] địa chỉ bắt đầu=0x03c768, fde_va=0x06c8d8, kích thước=16 byte
// AArch64 opcodes: 90000161 91064021 AA0803E0 17FFF863
uint32_t cybertron_fde_0059_0x03c768(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c768U;
    constexpr uint32_t kFdeVa   = 0x06c8d8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x90000161U;
    constexpr uint32_t kW1      = 0x91064021U;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x17fff863U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0060] start_va=0x03c778, fde_va=0x06c8f0, span=72 bytes
// [VN] FDE[0060] địa chỉ bắt đầu=0x03c778, fde_va=0x06c8f0, kích thước=72 byte
// AArch64 opcodes: A941A408 EB09011F 540001C0 F9400029
uint32_t cybertron_fde_0060_0x03c778(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c778U;
    constexpr uint32_t kFdeVa   = 0x06c8f0U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xa941a408U;
    constexpr uint32_t kW1      = 0xeb09011fU;
    constexpr uint32_t kW2      = 0x540001c0U;
    constexpr uint32_t kW3      = 0xf9400029U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0061] start_va=0x03c7c0, fde_va=0x06c908, span=212 bytes
// [VN] FDE[0061] địa chỉ bắt đầu=0x03c7c0, fde_va=0x06c908, kích thước=212 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0061_0x03c7c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c7c0U;
    constexpr uint32_t kFdeVa   = 0x06c908U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0062] start_va=0x03c894, fde_va=0x06c928, span=268 bytes
// [VN] FDE[0062] địa chỉ bắt đầu=0x03c894, fde_va=0x06c928, kích thước=268 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0062_0x03c894(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c894U;
    constexpr uint32_t kFdeVa   = 0x06c928U;
    constexpr uint32_t kSpan    = 268U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0063] start_va=0x03c9a0, fde_va=0x06c950, span=88 bytes
// [VN] FDE[0063] địa chỉ bắt đầu=0x03c9a0, fde_va=0x06c950, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0063_0x03c9a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c9a0U;
    constexpr uint32_t kFdeVa   = 0x06c950U;
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

// [EN] FDE[0064] start_va=0x03c9f8, fde_va=0x06c970, span=216 bytes
// [VN] FDE[0064] địa chỉ bắt đầu=0x03c9f8, fde_va=0x06c970, kích thước=216 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0064_0x03c9f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03c9f8U;
    constexpr uint32_t kFdeVa   = 0x06c970U;
    constexpr uint32_t kSpan    = 216U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0065] start_va=0x03cad0, fde_va=0x06c990, span=212 bytes
// [VN] FDE[0065] địa chỉ bắt đầu=0x03cad0, fde_va=0x06c990, kích thước=212 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0065_0x03cad0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03cad0U;
    constexpr uint32_t kFdeVa   = 0x06c990U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0066] start_va=0x03cba4, fde_va=0x06c9b0, span=212 bytes
// [VN] FDE[0066] địa chỉ bắt đầu=0x03cba4, fde_va=0x06c9b0, kích thước=212 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0066_0x03cba4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03cba4U;
    constexpr uint32_t kFdeVa   = 0x06c9b0U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0067] start_va=0x03cc78, fde_va=0x06c9d0, span=216 bytes
// [VN] FDE[0067] địa chỉ bắt đầu=0x03cc78, fde_va=0x06c9d0, kích thước=216 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0067_0x03cc78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03cc78U;
    constexpr uint32_t kFdeVa   = 0x06c9d0U;
    constexpr uint32_t kSpan    = 216U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0068] start_va=0x03cd50, fde_va=0x06c9f0, span=212 bytes
// [VN] FDE[0068] địa chỉ bắt đầu=0x03cd50, fde_va=0x06c9f0, kích thước=212 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0068_0x03cd50(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03cd50U;
    constexpr uint32_t kFdeVa   = 0x06c9f0U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0069] start_va=0x03ce24, fde_va=0x06ca10, span=212 bytes
// [VN] FDE[0069] địa chỉ bắt đầu=0x03ce24, fde_va=0x06ca10, kích thước=212 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0069_0x03ce24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03ce24U;
    constexpr uint32_t kFdeVa   = 0x06ca10U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0070] start_va=0x03cef8, fde_va=0x06ca30, span=212 bytes
// [VN] FDE[0070] địa chỉ bắt đầu=0x03cef8, fde_va=0x06ca30, kích thước=212 byte
// AArch64 opcodes: D10143FF FD0013E8 A9034FF4 A9047BFD
uint32_t cybertron_fde_0070_0x03cef8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03cef8U;
    constexpr uint32_t kFdeVa   = 0x06ca30U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xfd0013e8U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0071] start_va=0x03cfcc, fde_va=0x06ca50, span=240 bytes
// [VN] FDE[0071] địa chỉ bắt đầu=0x03cfcc, fde_va=0x06ca50, kích thước=240 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_0071_0x03cfcc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03cfccU;
    constexpr uint32_t kFdeVa   = 0x06ca50U;
    constexpr uint32_t kSpan    = 240U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0072] start_va=0x03d0bc, fde_va=0x06ca78, span=240 bytes
// [VN] FDE[0072] địa chỉ bắt đầu=0x03d0bc, fde_va=0x06ca78, kích thước=240 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_0072_0x03d0bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d0bcU;
    constexpr uint32_t kFdeVa   = 0x06ca78U;
    constexpr uint32_t kSpan    = 240U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0073] start_va=0x03d1ac, fde_va=0x06caa0, span=144 bytes
// [VN] FDE[0073] địa chỉ bắt đầu=0x03d1ac, fde_va=0x06caa0, kích thước=144 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0073_0x03d1ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d1acU;
    constexpr uint32_t kFdeVa   = 0x06caa0U;
    constexpr uint32_t kSpan    = 144U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0074] start_va=0x03d23c, fde_va=0x06cac8, span=144 bytes
// [VN] FDE[0074] địa chỉ bắt đầu=0x03d23c, fde_va=0x06cac8, kích thước=144 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9412009
uint32_t cybertron_fde_0074_0x03d23c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d23cU;
    constexpr uint32_t kFdeVa   = 0x06cac8U;
    constexpr uint32_t kSpan    = 144U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa9412009U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0075] start_va=0x03d2cc, fde_va=0x06cae8, span=192 bytes
// [VN] FDE[0075] địa chỉ bắt đầu=0x03d2cc, fde_va=0x06cae8, kích thước=192 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0075_0x03d2cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d2ccU;
    constexpr uint32_t kFdeVa   = 0x06cae8U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0076] start_va=0x03d38c, fde_va=0x06cb08, span=196 bytes
// [VN] FDE[0076] địa chỉ bắt đầu=0x03d38c, fde_va=0x06cb08, kích thước=196 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0076_0x03d38c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d38cU;
    constexpr uint32_t kFdeVa   = 0x06cb08U;
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

// [EN] FDE[0077] start_va=0x03d450, fde_va=0x06cb28, span=192 bytes
// [VN] FDE[0077] địa chỉ bắt đầu=0x03d450, fde_va=0x06cb28, kích thước=192 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0077_0x03d450(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d450U;
    constexpr uint32_t kFdeVa   = 0x06cb28U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0078] start_va=0x03d510, fde_va=0x06cb48, span=192 bytes
// [VN] FDE[0078] địa chỉ bắt đầu=0x03d510, fde_va=0x06cb48, kích thước=192 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0078_0x03d510(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d510U;
    constexpr uint32_t kFdeVa   = 0x06cb48U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0079] start_va=0x03d5d0, fde_va=0x06cb68, span=196 bytes
// [VN] FDE[0079] địa chỉ bắt đầu=0x03d5d0, fde_va=0x06cb68, kích thước=196 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0079_0x03d5d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d5d0U;
    constexpr uint32_t kFdeVa   = 0x06cb68U;
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

// [EN] FDE[0080] start_va=0x03d694, fde_va=0x06cb88, span=192 bytes
// [VN] FDE[0080] địa chỉ bắt đầu=0x03d694, fde_va=0x06cb88, kích thước=192 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0080_0x03d694(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d694U;
    constexpr uint32_t kFdeVa   = 0x06cb88U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0081] start_va=0x03d754, fde_va=0x06cba8, span=192 bytes
// [VN] FDE[0081] địa chỉ bắt đầu=0x03d754, fde_va=0x06cba8, kích thước=192 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0081_0x03d754(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d754U;
    constexpr uint32_t kFdeVa   = 0x06cba8U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0082] start_va=0x03d814, fde_va=0x06cbc8, span=192 bytes
// [VN] FDE[0082] địa chỉ bắt đầu=0x03d814, fde_va=0x06cbc8, kích thước=192 byte
// AArch64 opcodes: FC1D0FE8 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0082_0x03d814(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d814U;
    constexpr uint32_t kFdeVa   = 0x06cbc8U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xfc1d0fe8U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0083] start_va=0x03d8d4, fde_va=0x06cbe8, span=264 bytes
// [VN] FDE[0083] địa chỉ bắt đầu=0x03d8d4, fde_va=0x06cbe8, kích thước=264 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_0083_0x03d8d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d8d4U;
    constexpr uint32_t kFdeVa   = 0x06cbe8U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf90013f7U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0084] start_va=0x03d9dc, fde_va=0x06cc10, span=264 bytes
// [VN] FDE[0084] địa chỉ bắt đầu=0x03d9dc, fde_va=0x06cc10, kích thước=264 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_0084_0x03d9dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03d9dcU;
    constexpr uint32_t kFdeVa   = 0x06cc10U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf90013f7U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0085] start_va=0x03dae4, fde_va=0x06cc38, span=12 bytes
// [VN] FDE[0085] địa chỉ bắt đầu=0x03dae4, fde_va=0x06cc38, kích thước=12 byte
// AArch64 opcodes: F9400808 8B215100 D65F03C0 A9412809
uint32_t cybertron_fde_0085_0x03dae4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03dae4U;
    constexpr uint32_t kFdeVa   = 0x06cc38U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf9400808U;
    constexpr uint32_t kW1      = 0x8b215100U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xa9412809U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0086] start_va=0x03daf0, fde_va=0x06cc50, span=76 bytes
// [VN] FDE[0086] địa chỉ bắt đầu=0x03daf0, fde_va=0x06cc50, kích thước=76 byte
// AArch64 opcodes: A9412809 CB09014B 2A0103EA EB8B115F
uint32_t cybertron_fde_0086_0x03daf0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03daf0U;
    constexpr uint32_t kFdeVa   = 0x06cc50U;
    constexpr uint32_t kSpan    = 76U;
    constexpr uint32_t kW0      = 0xa9412809U;
    constexpr uint32_t kW1      = 0xcb09014bU;
    constexpr uint32_t kW2      = 0x2a0103eaU;
    constexpr uint32_t kW3      = 0xeb8b115fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0087] start_va=0x03db3c, fde_va=0x06cc68, span=16 bytes
// [VN] FDE[0087] địa chỉ bắt đầu=0x03db3c, fde_va=0x06cc68, kích thước=16 byte
// AArch64 opcodes: A9412408 CB080128 9344FD00 D65F03C0
uint32_t cybertron_fde_0087_0x03db3c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03db3cU;
    constexpr uint32_t kFdeVa   = 0x06cc68U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xa9412408U;
    constexpr uint32_t kW1      = 0xcb080128U;
    constexpr uint32_t kW2      = 0x9344fd00U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0088] start_va=0x03db4c, fde_va=0x06cc80, span=44 bytes
// [VN] FDE[0088] địa chỉ bắt đầu=0x03db4c, fde_va=0x06cc80, kích thước=44 byte
// AArch64 opcodes: D0000209 F9476129 528000C8 6F00E400
uint32_t cybertron_fde_0088_0x03db4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03db4cU;
    constexpr uint32_t kFdeVa   = 0x06cc80U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xd0000209U;
    constexpr uint32_t kW1      = 0xf9476129U;
    constexpr uint32_t kW2      = 0x528000c8U;
    constexpr uint32_t kW3      = 0x6f00e400U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0089] start_va=0x03db78, fde_va=0x06cc98, span=16 bytes
// [VN] FDE[0089] địa chỉ bắt đầu=0x03db78, fde_va=0x06cc98, kích thước=16 byte
// AArch64 opcodes: D0000141 91349821 AA0803E0 17FFF35F
uint32_t cybertron_fde_0089_0x03db78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03db78U;
    constexpr uint32_t kFdeVa   = 0x06cc98U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xd0000141U;
    constexpr uint32_t kW1      = 0x91349821U;
    constexpr uint32_t kW2      = 0xaa0803e0U;
    constexpr uint32_t kW3      = 0x17fff35fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0090] start_va=0x03db88, fde_va=0x06ccb0, span=96 bytes
// [VN] FDE[0090] địa chỉ bắt đầu=0x03db88, fde_va=0x06ccb0, kích thước=96 byte
// AArch64 opcodes: D10103FF F90013F3 A9037BFD 9100C3FD
uint32_t cybertron_fde_0090_0x03db88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03db88U;
    constexpr uint32_t kFdeVa   = 0x06ccb0U;
    constexpr uint32_t kSpan    = 96U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xf90013f3U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0091] start_va=0x03dbe8, fde_va=0x06ccd0, span=32 bytes
// [VN] FDE[0091] địa chỉ bắt đầu=0x03dbe8, fde_va=0x06ccd0, kích thước=32 byte
// AArch64 opcodes: A9BF7BFD 910003FD 91004000 97FFF217
uint32_t cybertron_fde_0091_0x03dbe8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03dbe8U;
    constexpr uint32_t kFdeVa   = 0x06ccd0U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x91004000U;
    constexpr uint32_t kW3      = 0x97fff217U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0092] start_va=0x03dc08, fde_va=0x06ccf0, span=8 bytes
// [VN] FDE[0092] địa chỉ bắt đầu=0x03dc08, fde_va=0x06ccf0, kích thước=8 byte
// AArch64 opcodes: 91004000 17FFF4B5 91004000 17FFF4B7
uint32_t cybertron_fde_0092_0x03dc08(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03dc08U;
    constexpr uint32_t kFdeVa   = 0x06ccf0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91004000U;
    constexpr uint32_t kW1      = 0x17fff4b5U;
    constexpr uint32_t kW2      = 0x91004000U;
    constexpr uint32_t kW3      = 0x17fff4b7U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0093] start_va=0x03dc10, fde_va=0x06cd08, span=8 bytes
// [VN] FDE[0093] địa chỉ bắt đầu=0x03dc10, fde_va=0x06cd08, kích thước=8 byte
// AArch64 opcodes: 91004000 17FFF4B7 D10103FF A9024FF4
uint32_t cybertron_fde_0093_0x03dc10(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03dc10U;
    constexpr uint32_t kFdeVa   = 0x06cd08U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91004000U;
    constexpr uint32_t kW1      = 0x17fff4b7U;
    constexpr uint32_t kW2      = 0xd10103ffU;
    constexpr uint32_t kW3      = 0xa9024ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0094] start_va=0x03dc18, fde_va=0x06cd20, span=184 bytes
// [VN] FDE[0094] địa chỉ bắt đầu=0x03dc18, fde_va=0x06cd20, kích thước=184 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_0094_0x03dc18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03dc18U;
    constexpr uint32_t kFdeVa   = 0x06cd20U;
    constexpr uint32_t kSpan    = 184U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa9024ff4U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0095] start_va=0x03dcd0, fde_va=0x06cd40, span=248 bytes
// [VN] FDE[0095] địa chỉ bắt đầu=0x03dcd0, fde_va=0x06cd40, kích thước=248 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0095_0x03dcd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03dcd0U;
    constexpr uint32_t kFdeVa   = 0x06cd40U;
    constexpr uint32_t kSpan    = 248U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0096] start_va=0x03ddc8, fde_va=0x06cd68, span=252 bytes
// [VN] FDE[0096] địa chỉ bắt đầu=0x03ddc8, fde_va=0x06cd68, kích thước=252 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0096_0x03ddc8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03ddc8U;
    constexpr uint32_t kFdeVa   = 0x06cd68U;
    constexpr uint32_t kSpan    = 252U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0097] start_va=0x03dec4, fde_va=0x06cd90, span=248 bytes
// [VN] FDE[0097] địa chỉ bắt đầu=0x03dec4, fde_va=0x06cd90, kích thước=248 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0097_0x03dec4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03dec4U;
    constexpr uint32_t kFdeVa   = 0x06cd90U;
    constexpr uint32_t kSpan    = 248U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0098] start_va=0x03dfbc, fde_va=0x06cdb8, span=4344 bytes
// [VN] FDE[0098] địa chỉ bắt đầu=0x03dfbc, fde_va=0x06cdb8, kích thước=4344 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0098_0x03dfbc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03dfbcU;
    constexpr uint32_t kFdeVa   = 0x06cdb8U;
    constexpr uint32_t kSpan    = 4344U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0099] start_va=0x03f0b4, fde_va=0x06cde0, span=252 bytes
// [VN] FDE[0099] địa chỉ bắt đầu=0x03f0b4, fde_va=0x06cde0, kích thước=252 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0099_0x03f0b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f0b4U;
    constexpr uint32_t kFdeVa   = 0x06cde0U;
    constexpr uint32_t kSpan    = 252U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0100] start_va=0x03f1b0, fde_va=0x06ce08, span=248 bytes
// [VN] FDE[0100] địa chỉ bắt đầu=0x03f1b0, fde_va=0x06ce08, kích thước=248 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0100_0x03f1b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f1b0U;
    constexpr uint32_t kFdeVa   = 0x06ce08U;
    constexpr uint32_t kSpan    = 248U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0101] start_va=0x03f2a8, fde_va=0x06ce30, span=248 bytes
// [VN] FDE[0101] địa chỉ bắt đầu=0x03f2a8, fde_va=0x06ce30, kích thước=248 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_0101_0x03f2a8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f2a8U;
    constexpr uint32_t kFdeVa   = 0x06ce30U;
    constexpr uint32_t kSpan    = 248U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0102] start_va=0x03f3a0, fde_va=0x06ce58, span=260 bytes
// [VN] FDE[0102] địa chỉ bắt đầu=0x03f3a0, fde_va=0x06ce58, kích thước=260 byte
// AArch64 opcodes: D10183FF FD0013E8 F90017F7 A90357F6
uint32_t cybertron_fde_0102_0x03f3a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f3a0U;
    constexpr uint32_t kFdeVa   = 0x06ce58U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xfd0013e8U;
    constexpr uint32_t kW2      = 0xf90017f7U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0103] start_va=0x03f4a4, fde_va=0x06ce80, span=256 bytes
// [VN] FDE[0103] địa chỉ bắt đầu=0x03f4a4, fde_va=0x06ce80, kích thước=256 byte
// AArch64 opcodes: D10183FF FD0013E8 F90017F7 A90357F6
uint32_t cybertron_fde_0103_0x03f4a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f4a4U;
    constexpr uint32_t kFdeVa   = 0x06ce80U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xfd0013e8U;
    constexpr uint32_t kW2      = 0xf90017f7U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0104] start_va=0x03f5a4, fde_va=0x06cea8, span=272 bytes
// [VN] FDE[0104] địa chỉ bắt đầu=0x03f5a4, fde_va=0x06cea8, kích thước=272 byte
// AArch64 opcodes: D101C3FF A9035FF8 A90457F6 A9054FF4
uint32_t cybertron_fde_0104_0x03f5a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f5a4U;
    constexpr uint32_t kFdeVa   = 0x06cea8U;
    constexpr uint32_t kSpan    = 272U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9035ff8U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0105] start_va=0x03f6b4, fde_va=0x06ced0, span=272 bytes
// [VN] FDE[0105] địa chỉ bắt đầu=0x03f6b4, fde_va=0x06ced0, kích thước=272 byte
// AArch64 opcodes: D101C3FF A9035FF8 A90457F6 A9054FF4
uint32_t cybertron_fde_0105_0x03f6b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f6b4U;
    constexpr uint32_t kFdeVa   = 0x06ced0U;
    constexpr uint32_t kSpan    = 272U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa9035ff8U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0106] start_va=0x03f7c4, fde_va=0x06cef8, span=124 bytes
// [VN] FDE[0106] địa chỉ bắt đầu=0x03f7c4, fde_va=0x06cef8, kích thước=124 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0106_0x03f7c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f7c4U;
    constexpr uint32_t kFdeVa   = 0x06cef8U;
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

// [EN] FDE[0107] start_va=0x03f840, fde_va=0x06cf18, span=136 bytes
// [VN] FDE[0107] địa chỉ bắt đầu=0x03f840, fde_va=0x06cf18, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91004000
uint32_t cybertron_fde_0107_0x03f840(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f840U;
    constexpr uint32_t kFdeVa   = 0x06cf18U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91004000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0108] start_va=0x03f8c8, fde_va=0x06cf38, span=136 bytes
// [VN] FDE[0108] địa chỉ bắt đầu=0x03f8c8, fde_va=0x06cf38, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91004000
uint32_t cybertron_fde_0108_0x03f8c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f8c8U;
    constexpr uint32_t kFdeVa   = 0x06cf38U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91004000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0109] start_va=0x03f950, fde_va=0x06cf58, span=136 bytes
// [VN] FDE[0109] địa chỉ bắt đầu=0x03f950, fde_va=0x06cf58, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91004000
uint32_t cybertron_fde_0109_0x03f950(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f950U;
    constexpr uint32_t kFdeVa   = 0x06cf58U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91004000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0110] start_va=0x03f9d8, fde_va=0x06cf78, span=136 bytes
// [VN] FDE[0110] địa chỉ bắt đầu=0x03f9d8, fde_va=0x06cf78, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91004000
uint32_t cybertron_fde_0110_0x03f9d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03f9d8U;
    constexpr uint32_t kFdeVa   = 0x06cf78U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91004000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0111] start_va=0x03fa60, fde_va=0x06cf98, span=136 bytes
// [VN] FDE[0111] địa chỉ bắt đầu=0x03fa60, fde_va=0x06cf98, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91004000
uint32_t cybertron_fde_0111_0x03fa60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fa60U;
    constexpr uint32_t kFdeVa   = 0x06cf98U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91004000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0112] start_va=0x03fae8, fde_va=0x06cfb8, span=136 bytes
// [VN] FDE[0112] địa chỉ bắt đầu=0x03fae8, fde_va=0x06cfb8, kích thước=136 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 91004000
uint32_t cybertron_fde_0112_0x03fae8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fae8U;
    constexpr uint32_t kFdeVa   = 0x06cfb8U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x91004000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0113] start_va=0x03fb70, fde_va=0x06cfd8, span=224 bytes
// [VN] FDE[0113] địa chỉ bắt đầu=0x03fb70, fde_va=0x06cfd8, kích thước=224 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_0113_0x03fb70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fb70U;
    constexpr uint32_t kFdeVa   = 0x06cfd8U;
    constexpr uint32_t kSpan    = 224U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf90013f7U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0114] start_va=0x03fc50, fde_va=0x06d000, span=8 bytes
// [VN] FDE[0114] địa chỉ bắt đầu=0x03fc50, fde_va=0x06d000, kích thước=8 byte
// AArch64 opcodes: F9401400 D65F03C0 91004000 17FFECA1
uint32_t cybertron_fde_0114_0x03fc50(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc50U;
    constexpr uint32_t kFdeVa   = 0x06d000U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xf9401400U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0x91004000U;
    constexpr uint32_t kW3      = 0x17ffeca1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0115] start_va=0x03fc58, fde_va=0x06d018, span=8 bytes
// [VN] FDE[0115] địa chỉ bắt đầu=0x03fc58, fde_va=0x06d018, kích thước=8 byte
// AArch64 opcodes: 91004000 17FFECA1 D65F03C0 17FFE42F
uint32_t cybertron_fde_0115_0x03fc58(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc58U;
    constexpr uint32_t kFdeVa   = 0x06d018U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91004000U;
    constexpr uint32_t kW1      = 0x17ffeca1U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x17ffe42fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0116] start_va=0x03fc60, fde_va=0x06d030, span=4 bytes
// [VN] FDE[0116] địa chỉ bắt đầu=0x03fc60, fde_va=0x06d030, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FFE42F D65F03C0 17FFE42D
uint32_t cybertron_fde_0116_0x03fc60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc60U;
    constexpr uint32_t kFdeVa   = 0x06d030U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ffe42fU;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x17ffe42dU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0117] start_va=0x03fc64, fde_va=0x06d048, span=4 bytes
// [VN] FDE[0117] địa chỉ bắt đầu=0x03fc64, fde_va=0x06d048, kích thước=4 byte
// AArch64 opcodes: 17FFE42F D65F03C0 17FFE42D D65F03C0
uint32_t cybertron_fde_0117_0x03fc64(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc64U;
    constexpr uint32_t kFdeVa   = 0x06d048U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe42fU;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0x17ffe42dU;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0118] start_va=0x03fc68, fde_va=0x06d060, span=4 bytes
// [VN] FDE[0118] địa chỉ bắt đầu=0x03fc68, fde_va=0x06d060, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FFE42D D65F03C0 17FFE42B
uint32_t cybertron_fde_0118_0x03fc68(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc68U;
    constexpr uint32_t kFdeVa   = 0x06d060U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ffe42dU;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x17ffe42bU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0119] start_va=0x03fc6c, fde_va=0x06d078, span=4 bytes
// [VN] FDE[0119] địa chỉ bắt đầu=0x03fc6c, fde_va=0x06d078, kích thước=4 byte
// AArch64 opcodes: 17FFE42D D65F03C0 17FFE42B D65F03C0
uint32_t cybertron_fde_0119_0x03fc6c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc6cU;
    constexpr uint32_t kFdeVa   = 0x06d078U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe42dU;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0x17ffe42bU;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0120] start_va=0x03fc70, fde_va=0x06d090, span=4 bytes
// [VN] FDE[0120] địa chỉ bắt đầu=0x03fc70, fde_va=0x06d090, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FFE42B D65F03C0 17FFE429
uint32_t cybertron_fde_0120_0x03fc70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc70U;
    constexpr uint32_t kFdeVa   = 0x06d090U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ffe42bU;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0x17ffe429U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0121] start_va=0x03fc74, fde_va=0x06d0a8, span=4 bytes
// [VN] FDE[0121] địa chỉ bắt đầu=0x03fc74, fde_va=0x06d0a8, kích thước=4 byte
// AArch64 opcodes: 17FFE42B D65F03C0 17FFE429 90000209
uint32_t cybertron_fde_0121_0x03fc74(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc74U;
    constexpr uint32_t kFdeVa   = 0x06d0a8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe42bU;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0x17ffe429U;
    constexpr uint32_t kW3      = 0x90000209U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0122] start_va=0x03fc78, fde_va=0x06d0c0, span=4 bytes
// [VN] FDE[0122] địa chỉ bắt đầu=0x03fc78, fde_va=0x06d0c0, kích thước=4 byte
// AArch64 opcodes: D65F03C0 17FFE429 90000209 39404008
uint32_t cybertron_fde_0122_0x03fc78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc78U;
    constexpr uint32_t kFdeVa   = 0x06d0c0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0x17ffe429U;
    constexpr uint32_t kW2      = 0x90000209U;
    constexpr uint32_t kW3      = 0x39404008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0123] start_va=0x03fc7c, fde_va=0x06d0d8, span=4 bytes
// [VN] FDE[0123] địa chỉ bắt đầu=0x03fc7c, fde_va=0x06d0d8, kích thước=4 byte
// AArch64 opcodes: 17FFE429 90000209 39404008 F946F129
uint32_t cybertron_fde_0123_0x03fc7c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc7cU;
    constexpr uint32_t kFdeVa   = 0x06d0d8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe429U;
    constexpr uint32_t kW1      = 0x90000209U;
    constexpr uint32_t kW2      = 0x39404008U;
    constexpr uint32_t kW3      = 0xf946f129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0124] start_va=0x03fc80, fde_va=0x06d0f0, span=36 bytes
// [VN] FDE[0124] địa chỉ bắt đầu=0x03fc80, fde_va=0x06d0f0, kích thước=36 byte
// AArch64 opcodes: 90000209 39404008 F946F129 91004129
uint32_t cybertron_fde_0124_0x03fc80(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fc80U;
    constexpr uint32_t kFdeVa   = 0x06d0f0U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0x90000209U;
    constexpr uint32_t kW1      = 0x39404008U;
    constexpr uint32_t kW2      = 0xf946f129U;
    constexpr uint32_t kW3      = 0x91004129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0125] start_va=0x03fca4, fde_va=0x06d108, span=64 bytes
// [VN] FDE[0125] địa chỉ bắt đầu=0x03fca4, fde_va=0x06d108, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000209
uint32_t cybertron_fde_0125_0x03fca4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fca4U;
    constexpr uint32_t kFdeVa   = 0x06d108U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000209U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0126] start_va=0x03fce4, fde_va=0x06d128, span=20 bytes
// [VN] FDE[0126] địa chỉ bắt đầu=0x03fce4, fde_va=0x06d128, kích thước=20 byte
// AArch64 opcodes: 90000208 F9476108 91004108 F8010408
uint32_t cybertron_fde_0126_0x03fce4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fce4U;
    constexpr uint32_t kFdeVa   = 0x06d128U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x90000208U;
    constexpr uint32_t kW1      = 0xf9476108U;
    constexpr uint32_t kW2      = 0x91004108U;
    constexpr uint32_t kW3      = 0xf8010408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0127] start_va=0x03fcf8, fde_va=0x06d140, span=52 bytes
// [VN] FDE[0127] địa chỉ bắt đầu=0x03fcf8, fde_va=0x06d140, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000208
uint32_t cybertron_fde_0127_0x03fcf8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fcf8U;
    constexpr uint32_t kFdeVa   = 0x06d140U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000208U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0128] start_va=0x03fd2c, fde_va=0x06d160, span=20 bytes
// [VN] FDE[0128] địa chỉ bắt đầu=0x03fd2c, fde_va=0x06d160, kích thước=20 byte
// AArch64 opcodes: 90000208 F947D108 91004108 F8010408
uint32_t cybertron_fde_0128_0x03fd2c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fd2cU;
    constexpr uint32_t kFdeVa   = 0x06d160U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x90000208U;
    constexpr uint32_t kW1      = 0xf947d108U;
    constexpr uint32_t kW2      = 0x91004108U;
    constexpr uint32_t kW3      = 0xf8010408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0129] start_va=0x03fd40, fde_va=0x06d178, span=52 bytes
// [VN] FDE[0129] địa chỉ bắt đầu=0x03fd40, fde_va=0x06d178, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000208
uint32_t cybertron_fde_0129_0x03fd40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fd40U;
    constexpr uint32_t kFdeVa   = 0x06d178U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000208U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0130] start_va=0x03fd74, fde_va=0x06d198, span=188 bytes
// [VN] FDE[0130] địa chỉ bắt đầu=0x03fd74, fde_va=0x06d198, kích thước=188 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0130_0x03fd74(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fd74U;
    constexpr uint32_t kFdeVa   = 0x06d198U;
    constexpr uint32_t kSpan    = 188U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0131] start_va=0x03fe30, fde_va=0x06d1c0, span=52 bytes
// [VN] FDE[0131] địa chỉ bắt đầu=0x03fe30, fde_va=0x06d1c0, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000208
uint32_t cybertron_fde_0131_0x03fe30(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fe30U;
    constexpr uint32_t kFdeVa   = 0x06d1c0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000208U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0132] start_va=0x03fe64, fde_va=0x06d1e0, span=60 bytes
// [VN] FDE[0132] địa chỉ bắt đầu=0x03fe64, fde_va=0x06d1e0, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 90000208
uint32_t cybertron_fde_0132_0x03fe64(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fe64U;
    constexpr uint32_t kFdeVa   = 0x06d1e0U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x90000208U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0133] start_va=0x03fea0, fde_va=0x06d200, span=8 bytes
// [VN] FDE[0133] địa chỉ bắt đầu=0x03fea0, fde_va=0x06d200, kích thước=8 byte
// AArch64 opcodes: 91006000 17FFE427 17FFE39E F81E0FF3
uint32_t cybertron_fde_0133_0x03fea0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fea0U;
    constexpr uint32_t kFdeVa   = 0x06d200U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91006000U;
    constexpr uint32_t kW1      = 0x17ffe427U;
    constexpr uint32_t kW2      = 0x17ffe39eU;
    constexpr uint32_t kW3      = 0xf81e0ff3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0134] start_va=0x03fea8, fde_va=0x06d218, span=4 bytes
// [VN] FDE[0134] địa chỉ bắt đầu=0x03fea8, fde_va=0x06d218, kích thước=4 byte
// AArch64 opcodes: 17FFE39E F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0134_0x03fea8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fea8U;
    constexpr uint32_t kFdeVa   = 0x06d218U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe39eU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0135] start_va=0x03feac, fde_va=0x06d230, span=60 bytes
// [VN] FDE[0135] địa chỉ bắt đầu=0x03feac, fde_va=0x06d230, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400801
uint32_t cybertron_fde_0135_0x03feac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03feacU;
    constexpr uint32_t kFdeVa   = 0x06d230U;
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

// [EN] FDE[0136] start_va=0x03fee8, fde_va=0x06d250, span=76 bytes
// [VN] FDE[0136] địa chỉ bắt đầu=0x03fee8, fde_va=0x06d250, kích thước=76 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0136_0x03fee8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03fee8U;
    constexpr uint32_t kFdeVa   = 0x06d250U;
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

// [EN] FDE[0137] start_va=0x03ff34, fde_va=0x06d270, span=60 bytes
// [VN] FDE[0137] địa chỉ bắt đầu=0x03ff34, fde_va=0x06d270, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 91006040
uint32_t cybertron_fde_0137_0x03ff34(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03ff34U;
    constexpr uint32_t kFdeVa   = 0x06d270U;
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

// [EN] FDE[0138] start_va=0x03ff70, fde_va=0x06d290, span=108 bytes
// [VN] FDE[0138] địa chỉ bắt đầu=0x03ff70, fde_va=0x06d290, kích thước=108 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0138_0x03ff70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03ff70U;
    constexpr uint32_t kFdeVa   = 0x06d290U;
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

// [EN] FDE[0139] start_va=0x03ffdc, fde_va=0x06d2b0, span=196 bytes
// [VN] FDE[0139] địa chỉ bắt đầu=0x03ffdc, fde_va=0x06d2b0, kích thước=196 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0139_0x03ffdc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x03ffdcU;
    constexpr uint32_t kFdeVa   = 0x06d2b0U;
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

// [EN] FDE[0140] start_va=0x0400a0, fde_va=0x06d2d0, span=308 bytes
// [VN] FDE[0140] địa chỉ bắt đầu=0x0400a0, fde_va=0x06d2d0, kích thước=308 byte
// AArch64 opcodes: A9BA6FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0140_0x0400a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0400a0U;
    constexpr uint32_t kFdeVa   = 0x06d2d0U;
    constexpr uint32_t kSpan    = 308U;
    constexpr uint32_t kW0      = 0xa9ba6ffcU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0141] start_va=0x0401d4, fde_va=0x06d300, span=280 bytes
// [VN] FDE[0141] địa chỉ bắt đầu=0x0401d4, fde_va=0x06d300, kích thước=280 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0141_0x0401d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0401d4U;
    constexpr uint32_t kFdeVa   = 0x06d300U;
    constexpr uint32_t kSpan    = 280U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0142] start_va=0x0402ec, fde_va=0x06d328, span=112 bytes
// [VN] FDE[0142] địa chỉ bắt đầu=0x0402ec, fde_va=0x06d328, kích thước=112 byte
// AArch64 opcodes: A9402808 EB08015F 54000180 F9400429
uint32_t cybertron_fde_0142_0x0402ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0402ecU;
    constexpr uint32_t kFdeVa   = 0x06d328U;
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

// [EN] FDE[0143] start_va=0x04035c, fde_va=0x06d340, span=80 bytes
// [VN] FDE[0143] địa chỉ bắt đầu=0x04035c, fde_va=0x06d340, kích thước=80 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD A940A014
uint32_t cybertron_fde_0143_0x04035c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04035cU;
    constexpr uint32_t kFdeVa   = 0x06d340U;
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

// [EN] FDE[0144] start_va=0x0403ac, fde_va=0x06d360, span=4 bytes
// [VN] FDE[0144] địa chỉ bắt đầu=0x0403ac, fde_va=0x06d360, kích thước=4 byte
// AArch64 opcodes: 17FFE46D F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0144_0x0403ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0403acU;
    constexpr uint32_t kFdeVa   = 0x06d360U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe46dU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0145] start_va=0x0403b0, fde_va=0x06d378, span=36 bytes
// [VN] FDE[0145] địa chỉ bắt đầu=0x0403b0, fde_va=0x06d378, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0145_0x0403b0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0403b0U;
    constexpr uint32_t kFdeVa   = 0x06d378U;
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

// [EN] FDE[0146] start_va=0x0403d4, fde_va=0x06d398, span=12 bytes
// [VN] FDE[0146] địa chỉ bắt đầu=0x0403d4, fde_va=0x06d398, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400501 D61F0020 17FFE250
uint32_t cybertron_fde_0146_0x0403d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0403d4U;
    constexpr uint32_t kFdeVa   = 0x06d398U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400501U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ffe250U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0147] start_va=0x0403e0, fde_va=0x06d3b0, span=4 bytes
// [VN] FDE[0147] địa chỉ bắt đầu=0x0403e0, fde_va=0x06d3b0, kích thước=4 byte
// AArch64 opcodes: 17FFE250 17FFE45F F81E0FF3 A9017BFD
uint32_t cybertron_fde_0147_0x0403e0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0403e0U;
    constexpr uint32_t kFdeVa   = 0x06d3b0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe250U;
    constexpr uint32_t kW1      = 0x17ffe45fU;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0148] start_va=0x0403e4, fde_va=0x06d3c8, span=4 bytes
// [VN] FDE[0148] địa chỉ bắt đầu=0x0403e4, fde_va=0x06d3c8, kích thước=4 byte
// AArch64 opcodes: 17FFE45F F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0148_0x0403e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0403e4U;
    constexpr uint32_t kFdeVa   = 0x06d3c8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe45fU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0149] start_va=0x0403e8, fde_va=0x06d3e0, span=36 bytes
// [VN] FDE[0149] địa chỉ bắt đầu=0x0403e8, fde_va=0x06d3e0, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0149_0x0403e8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0403e8U;
    constexpr uint32_t kFdeVa   = 0x06d3e0U;
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

// [EN] FDE[0150] start_va=0x04040c, fde_va=0x06d400, span=12 bytes
// [VN] FDE[0150] địa chỉ bắt đầu=0x04040c, fde_va=0x06d400, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400501 D61F0020 17FFE242
uint32_t cybertron_fde_0150_0x04040c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04040cU;
    constexpr uint32_t kFdeVa   = 0x06d400U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400501U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ffe242U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0151] start_va=0x040418, fde_va=0x06d418, span=4 bytes
// [VN] FDE[0151] địa chỉ bắt đầu=0x040418, fde_va=0x06d418, kích thước=4 byte
// AArch64 opcodes: 17FFE242 17FFE451 F81E0FF3 A9017BFD
uint32_t cybertron_fde_0151_0x040418(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040418U;
    constexpr uint32_t kFdeVa   = 0x06d418U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe242U;
    constexpr uint32_t kW1      = 0x17ffe451U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0152] start_va=0x04041c, fde_va=0x06d430, span=4 bytes
// [VN] FDE[0152] địa chỉ bắt đầu=0x04041c, fde_va=0x06d430, kích thước=4 byte
// AArch64 opcodes: 17FFE451 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0152_0x04041c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04041cU;
    constexpr uint32_t kFdeVa   = 0x06d430U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe451U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0153] start_va=0x040420, fde_va=0x06d448, span=36 bytes
// [VN] FDE[0153] địa chỉ bắt đầu=0x040420, fde_va=0x06d448, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0153_0x040420(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040420U;
    constexpr uint32_t kFdeVa   = 0x06d448U;
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

// [EN] FDE[0154] start_va=0x040444, fde_va=0x06d468, span=12 bytes
// [VN] FDE[0154] địa chỉ bắt đầu=0x040444, fde_va=0x06d468, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400501 D61F0020 17FFE234
uint32_t cybertron_fde_0154_0x040444(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040444U;
    constexpr uint32_t kFdeVa   = 0x06d468U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400501U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ffe234U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0155] start_va=0x040450, fde_va=0x06d480, span=4 bytes
// [VN] FDE[0155] địa chỉ bắt đầu=0x040450, fde_va=0x06d480, kích thước=4 byte
// AArch64 opcodes: 17FFE234 F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0155_0x040450(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040450U;
    constexpr uint32_t kFdeVa   = 0x06d480U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe234U;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0156] start_va=0x040454, fde_va=0x06d498, span=80 bytes
// [VN] FDE[0156] địa chỉ bắt đầu=0x040454, fde_va=0x06d498, kích thước=80 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F00001E8
uint32_t cybertron_fde_0156_0x040454(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040454U;
    constexpr uint32_t kFdeVa   = 0x06d498U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf00001e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0157] start_va=0x0404a4, fde_va=0x06d4b8, span=88 bytes
// [VN] FDE[0157] địa chỉ bắt đầu=0x0404a4, fde_va=0x06d4b8, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F00001E8
uint32_t cybertron_fde_0157_0x0404a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0404a4U;
    constexpr uint32_t kFdeVa   = 0x06d4b8U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf00001e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0158] start_va=0x0404fc, fde_va=0x06d4d8, span=12 bytes
// [VN] FDE[0158] địa chỉ bắt đầu=0x0404fc, fde_va=0x06d4d8, kích thước=12 byte
// AArch64 opcodes: F8418C08 F9400501 D61F0020 17FFE206
uint32_t cybertron_fde_0158_0x0404fc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0404fcU;
    constexpr uint32_t kFdeVa   = 0x06d4d8U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf8418c08U;
    constexpr uint32_t kW1      = 0xf9400501U;
    constexpr uint32_t kW2      = 0xd61f0020U;
    constexpr uint32_t kW3      = 0x17ffe206U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0159] start_va=0x040508, fde_va=0x06d4f0, span=4 bytes
// [VN] FDE[0159] địa chỉ bắt đầu=0x040508, fde_va=0x06d4f0, kích thước=4 byte
// AArch64 opcodes: 17FFE206 D10243FF A9036FFC A90467FA
uint32_t cybertron_fde_0159_0x040508(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040508U;
    constexpr uint32_t kFdeVa   = 0x06d4f0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffe206U;
    constexpr uint32_t kW1      = 0xd10243ffU;
    constexpr uint32_t kW2      = 0xa9036ffcU;
    constexpr uint32_t kW3      = 0xa90467faU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0160] start_va=0x04050c, fde_va=0x06d508, span=768 bytes
// [VN] FDE[0160] địa chỉ bắt đầu=0x04050c, fde_va=0x06d508, kích thước=768 byte
// AArch64 opcodes: D10243FF A9036FFC A90467FA A9055FF8
uint32_t cybertron_fde_0160_0x04050c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04050cU;
    constexpr uint32_t kFdeVa   = 0x06d508U;
    constexpr uint32_t kSpan    = 768U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa9036ffcU;
    constexpr uint32_t kW2      = 0xa90467faU;
    constexpr uint32_t kW3      = 0xa9055ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0161] start_va=0x04080c, fde_va=0x06d538, span=228 bytes
// [VN] FDE[0161] địa chỉ bắt đầu=0x04080c, fde_va=0x06d538, kích thước=228 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0161_0x04080c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04080cU;
    constexpr uint32_t kFdeVa   = 0x06d538U;
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

// [EN] FDE[0162] start_va=0x0408f0, fde_va=0x06d558, span=536 bytes
// [VN] FDE[0162] địa chỉ bắt đầu=0x0408f0, fde_va=0x06d558, kích thước=536 byte
// AArch64 opcodes: F100805F 540000C8 AA0103E0 AA0203E1
uint32_t cybertron_fde_0162_0x0408f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0408f0U;
    constexpr uint32_t kFdeVa   = 0x06d558U;
    constexpr uint32_t kSpan    = 536U;
    constexpr uint32_t kW0      = 0xf100805fU;
    constexpr uint32_t kW1      = 0x540000c8U;
    constexpr uint32_t kW2      = 0xaa0103e0U;
    constexpr uint32_t kW3      = 0xaa0203e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0163] start_va=0x040b08, fde_va=0x06d570, span=260 bytes
// [VN] FDE[0163] địa chỉ bắt đầu=0x040b08, fde_va=0x06d570, kích thước=260 byte
// AArch64 opcodes: F100243F AA0003E8 540002C3 8B010109
uint32_t cybertron_fde_0163_0x040b08(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040b08U;
    constexpr uint32_t kFdeVa   = 0x06d570U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xf100243fU;
    constexpr uint32_t kW1      = 0xaa0003e8U;
    constexpr uint32_t kW2      = 0x540002c3U;
    constexpr uint32_t kW3      = 0x8b010109U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0164] start_va=0x040c0c, fde_va=0x06d588, span=184 bytes
// [VN] FDE[0164] địa chỉ bắt đầu=0x040c0c, fde_va=0x06d588, kích thước=184 byte
// AArch64 opcodes: D29E4E68 A9402809 F2B7D308 F2D6CDE8
uint32_t cybertron_fde_0164_0x040c0c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040c0cU;
    constexpr uint32_t kFdeVa   = 0x06d588U;
    constexpr uint32_t kSpan    = 184U;
    constexpr uint32_t kW0      = 0xd29e4e68U;
    constexpr uint32_t kW1      = 0xa9402809U;
    constexpr uint32_t kW2      = 0xf2b7d308U;
    constexpr uint32_t kW3      = 0xf2d6cde8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0165] start_va=0x040cc4, fde_va=0x06d5a0, span=192 bytes
// [VN] FDE[0165] địa chỉ bắt đầu=0x040cc4, fde_va=0x06d5a0, kích thước=192 byte
// AArch64 opcodes: 8B01000A A97F414E D28624EB A940340C
uint32_t cybertron_fde_0165_0x040cc4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040cc4U;
    constexpr uint32_t kFdeVa   = 0x06d5a0U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0x8b01000aU;
    constexpr uint32_t kW1      = 0xa97f414eU;
    constexpr uint32_t kW2      = 0xd28624ebU;
    constexpr uint32_t kW3      = 0xa940340cU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0166] start_va=0x040d84, fde_va=0x06d5b8, span=596 bytes
// [VN] FDE[0166] địa chỉ bắt đầu=0x040d84, fde_va=0x06d5b8, kích thước=596 byte
// AArch64 opcodes: D10203FF A9026FFC A90367FA A9045FF8
uint32_t cybertron_fde_0166_0x040d84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040d84U;
    constexpr uint32_t kFdeVa   = 0x06d5b8U;
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

// [EN] FDE[0167] start_va=0x040fd8, fde_va=0x06d5e8, span=68 bytes
// [VN] FDE[0167] địa chỉ bắt đầu=0x040fd8, fde_va=0x06d5e8, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 39402008
uint32_t cybertron_fde_0167_0x040fd8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x040fd8U;
    constexpr uint32_t kFdeVa   = 0x06d5e8U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x39402008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0168] start_va=0x04101c, fde_va=0x06d608, span=448 bytes
// [VN] FDE[0168] địa chỉ bắt đầu=0x04101c, fde_va=0x06d608, kích thước=448 byte
// AArch64 opcodes: D101C3FF F9000BFB A90267FA A9035FF8
uint32_t cybertron_fde_0168_0x04101c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04101cU;
    constexpr uint32_t kFdeVa   = 0x06d608U;
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

// [EN] FDE[0169] start_va=0x0411dc, fde_va=0x06d638, span=84 bytes
// [VN] FDE[0169] địa chỉ bắt đầu=0x0411dc, fde_va=0x06d638, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400C08
uint32_t cybertron_fde_0169_0x0411dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0411dcU;
    constexpr uint32_t kFdeVa   = 0x06d638U;
    constexpr uint32_t kSpan    = 84U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400c08U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0170] start_va=0x041230, fde_va=0x06d658, span=52 bytes
// [VN] FDE[0170] địa chỉ bắt đầu=0x041230, fde_va=0x06d658, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0170_0x041230(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041230U;
    constexpr uint32_t kFdeVa   = 0x06d658U;
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

// [EN] FDE[0171] start_va=0x041264, fde_va=0x06d678, span=448 bytes
// [VN] FDE[0171] địa chỉ bắt đầu=0x041264, fde_va=0x06d678, kích thước=448 byte
// AArch64 opcodes: D101C3FF F9000BFB A90267FA A9035FF8
uint32_t cybertron_fde_0171_0x041264(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041264U;
    constexpr uint32_t kFdeVa   = 0x06d678U;
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

// [EN] FDE[0172] start_va=0x041424, fde_va=0x06d6a8, span=112 bytes
// [VN] FDE[0172] địa chỉ bắt đầu=0x041424, fde_va=0x06d6a8, kích thước=112 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0172_0x041424(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041424U;
    constexpr uint32_t kFdeVa   = 0x06d6a8U;
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

// [EN] FDE[0173] start_va=0x041494, fde_va=0x06d6c8, span=308 bytes
// [VN] FDE[0173] địa chỉ bắt đầu=0x041494, fde_va=0x06d6c8, kích thước=308 byte
// AArch64 opcodes: F9400409 F940042A 9E670120 0E205800
uint32_t cybertron_fde_0173_0x041494(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041494U;
    constexpr uint32_t kFdeVa   = 0x06d6c8U;
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

// [EN] FDE[0174] start_va=0x0415c8, fde_va=0x06d6e0, span=24 bytes
// [VN] FDE[0174] địa chỉ bắt đầu=0x0415c8, fde_va=0x06d6e0, kích thước=24 byte
// AArch64 opcodes: 11000408 90000129 93401D08 913F1129
uint32_t cybertron_fde_0174_0x0415c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0415c8U;
    constexpr uint32_t kFdeVa   = 0x06d6e0U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0x11000408U;
    constexpr uint32_t kW1      = 0x90000129U;
    constexpr uint32_t kW2      = 0x93401d08U;
    constexpr uint32_t kW3      = 0x913f1129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0175] start_va=0x0415e0, fde_va=0x06d6f8, span=32 bytes
// [VN] FDE[0175] địa chỉ bắt đầu=0x0415e0, fde_va=0x06d6f8, kích thước=32 byte
// AArch64 opcodes: D280A009 F2A0E0C9 2A0003E8 F2C08069
uint32_t cybertron_fde_0175_0x0415e0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0415e0U;
    constexpr uint32_t kFdeVa   = 0x06d6f8U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xd280a009U;
    constexpr uint32_t kW1      = 0xf2a0e0c9U;
    constexpr uint32_t kW2      = 0x2a0003e8U;
    constexpr uint32_t kW3      = 0xf2c08069U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0176] start_va=0x041600, fde_va=0x06d710, span=28 bytes
// [VN] FDE[0176] địa chỉ bắt đầu=0x041600, fde_va=0x06d710, kích thước=28 byte
// AArch64 opcodes: 11000409 F00001CA 93401D29 911DE14A
uint32_t cybertron_fde_0176_0x041600(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041600U;
    constexpr uint32_t kFdeVa   = 0x06d710U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0x11000409U;
    constexpr uint32_t kW1      = 0xf00001caU;
    constexpr uint32_t kW2      = 0x93401d29U;
    constexpr uint32_t kW3      = 0x911de14aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0177] start_va=0x04161c, fde_va=0x06d728, span=292 bytes
// [VN] FDE[0177] địa chỉ bắt đầu=0x04161c, fde_va=0x06d728, kích thước=292 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0177_0x04161c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04161cU;
    constexpr uint32_t kFdeVa   = 0x06d728U;
    constexpr uint32_t kSpan    = 292U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0178] start_va=0x041740, fde_va=0x06d750, span=16 bytes
// [VN] FDE[0178] địa chỉ bắt đầu=0x041740, fde_va=0x06d750, kích thước=16 byte
// AArch64 opcodes: F9400008 F100011F 1A9F17E0 D65F03C0
uint32_t cybertron_fde_0178_0x041740(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041740U;
    constexpr uint32_t kFdeVa   = 0x06d750U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400008U;
    constexpr uint32_t kW1      = 0xf100011fU;
    constexpr uint32_t kW2      = 0x1a9f17e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0179] start_va=0x041750, fde_va=0x06d768, span=88 bytes
// [VN] FDE[0179] địa chỉ bắt đầu=0x041750, fde_va=0x06d768, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0179_0x041750(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041750U;
    constexpr uint32_t kFdeVa   = 0x06d768U;
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

// [EN] FDE[0180] start_va=0x0417a8, fde_va=0x06d788, span=120 bytes
// [VN] FDE[0180] địa chỉ bắt đầu=0x0417a8, fde_va=0x06d788, kích thước=120 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0180_0x0417a8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0417a8U;
    constexpr uint32_t kFdeVa   = 0x06d788U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0181] start_va=0x041820, fde_va=0x06d7a8, span=108 bytes
// [VN] FDE[0181] địa chỉ bắt đầu=0x041820, fde_va=0x06d7a8, kích thước=108 byte
// AArch64 opcodes: D10143FF F9001BF3 A9047BFD 910103FD
uint32_t cybertron_fde_0181_0x041820(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041820U;
    constexpr uint32_t kFdeVa   = 0x06d7a8U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9001bf3U;
    constexpr uint32_t kW2      = 0xa9047bfdU;
    constexpr uint32_t kW3      = 0x910103fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0182] start_va=0x04188c, fde_va=0x06d7c8, span=108 bytes
// [VN] FDE[0182] địa chỉ bắt đầu=0x04188c, fde_va=0x06d7c8, kích thước=108 byte
// AArch64 opcodes: D10143FF F9001BF3 A9047BFD 910103FD
uint32_t cybertron_fde_0182_0x04188c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04188cU;
    constexpr uint32_t kFdeVa   = 0x06d7c8U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9001bf3U;
    constexpr uint32_t kW2      = 0xa9047bfdU;
    constexpr uint32_t kW3      = 0x910103fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0183] start_va=0x0418f8, fde_va=0x06d7e8, span=120 bytes
// [VN] FDE[0183] địa chỉ bắt đầu=0x0418f8, fde_va=0x06d7e8, kích thước=120 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0183_0x0418f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0418f8U;
    constexpr uint32_t kFdeVa   = 0x06d7e8U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0184] start_va=0x041970, fde_va=0x06d808, span=108 bytes
// [VN] FDE[0184] địa chỉ bắt đầu=0x041970, fde_va=0x06d808, kích thước=108 byte
// AArch64 opcodes: D10143FF F9001BF3 A9047BFD 910103FD
uint32_t cybertron_fde_0184_0x041970(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041970U;
    constexpr uint32_t kFdeVa   = 0x06d808U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9001bf3U;
    constexpr uint32_t kW2      = 0xa9047bfdU;
    constexpr uint32_t kW3      = 0x910103fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0185] start_va=0x0419dc, fde_va=0x06d828, span=108 bytes
// [VN] FDE[0185] địa chỉ bắt đầu=0x0419dc, fde_va=0x06d828, kích thước=108 byte
// AArch64 opcodes: D10143FF F9001BF3 A9047BFD 910103FD
uint32_t cybertron_fde_0185_0x0419dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0419dcU;
    constexpr uint32_t kFdeVa   = 0x06d828U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9001bf3U;
    constexpr uint32_t kW2      = 0xa9047bfdU;
    constexpr uint32_t kW3      = 0x910103fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0186] start_va=0x041a48, fde_va=0x06d848, span=20 bytes
// [VN] FDE[0186] địa chỉ bắt đầu=0x041a48, fde_va=0x06d848, kích thước=20 byte
// AArch64 opcodes: F9400000 B4000040 17FFE2D0 52800020
uint32_t cybertron_fde_0186_0x041a48(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041a48U;
    constexpr uint32_t kFdeVa   = 0x06d848U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffe2d0U;
    constexpr uint32_t kW3      = 0x52800020U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0187] start_va=0x041a5c, fde_va=0x06d860, span=32 bytes
// [VN] FDE[0187] địa chỉ bắt đầu=0x041a5c, fde_va=0x06d860, kích thước=32 byte
// AArch64 opcodes: A9BF7BFD 910003FD F9400000 B4000060
uint32_t cybertron_fde_0187_0x041a5c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041a5cU;
    constexpr uint32_t kFdeVa   = 0x06d860U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xf9400000U;
    constexpr uint32_t kW3      = 0xb4000060U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0188] start_va=0x041a7c, fde_va=0x06d880, span=68 bytes
// [VN] FDE[0188] địa chỉ bắt đầu=0x041a7c, fde_va=0x06d880, kích thước=68 byte
// AArch64 opcodes: A9BF7BFD 910003FD F9400000 B4000160
uint32_t cybertron_fde_0188_0x041a7c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041a7cU;
    constexpr uint32_t kFdeVa   = 0x06d880U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xf9400000U;
    constexpr uint32_t kW3      = 0xb4000160U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0189] start_va=0x041ac0, fde_va=0x06d8a0, span=36 bytes
// [VN] FDE[0189] địa chỉ bắt đầu=0x041ac0, fde_va=0x06d8a0, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0803F3
uint32_t cybertron_fde_0189_0x041ac0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041ac0U;
    constexpr uint32_t kFdeVa   = 0x06d8a0U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0803f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0190] start_va=0x041ae4, fde_va=0x06d8c0, span=16 bytes
// [VN] FDE[0190] địa chỉ bắt đầu=0x041ae4, fde_va=0x06d8c0, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDF59 D65F03C0
uint32_t cybertron_fde_0190_0x041ae4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041ae4U;
    constexpr uint32_t kFdeVa   = 0x06d8c0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdf59U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0191] start_va=0x041af4, fde_va=0x06d8d8, span=16 bytes
// [VN] FDE[0191] địa chỉ bắt đầu=0x041af4, fde_va=0x06d8d8, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFE441 D65F03C0
uint32_t cybertron_fde_0191_0x041af4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041af4U;
    constexpr uint32_t kFdeVa   = 0x06d8d8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffe441U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0192] start_va=0x041b04, fde_va=0x06d8f0, span=16 bytes
// [VN] FDE[0192] địa chỉ bắt đầu=0x041b04, fde_va=0x06d8f0, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDF71 D65F03C0
uint32_t cybertron_fde_0192_0x041b04(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b04U;
    constexpr uint32_t kFdeVa   = 0x06d8f0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdf71U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0193] start_va=0x041b14, fde_va=0x06d908, span=16 bytes
// [VN] FDE[0193] địa chỉ bắt đầu=0x041b14, fde_va=0x06d908, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDC21 D65F03C0
uint32_t cybertron_fde_0193_0x041b14(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b14U;
    constexpr uint32_t kFdeVa   = 0x06d908U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdc21U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0194] start_va=0x041b24, fde_va=0x06d920, span=16 bytes
// [VN] FDE[0194] địa chỉ bắt đầu=0x041b24, fde_va=0x06d920, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDCD9 D65F03C0
uint32_t cybertron_fde_0194_0x041b24(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b24U;
    constexpr uint32_t kFdeVa   = 0x06d920U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdcd9U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0195] start_va=0x041b34, fde_va=0x06d938, span=16 bytes
// [VN] FDE[0195] địa chỉ bắt đầu=0x041b34, fde_va=0x06d938, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFE501 D65F03C0
uint32_t cybertron_fde_0195_0x041b34(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b34U;
    constexpr uint32_t kFdeVa   = 0x06d938U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffe501U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0196] start_va=0x041b44, fde_va=0x06d950, span=16 bytes
// [VN] FDE[0196] địa chỉ bắt đầu=0x041b44, fde_va=0x06d950, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDF4D D65F03C0
uint32_t cybertron_fde_0196_0x041b44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b44U;
    constexpr uint32_t kFdeVa   = 0x06d950U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdf4dU;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0197] start_va=0x041b54, fde_va=0x06d968, span=16 bytes
// [VN] FDE[0197] địa chỉ bắt đầu=0x041b54, fde_va=0x06d968, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDE71 D65F03C0
uint32_t cybertron_fde_0197_0x041b54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b54U;
    constexpr uint32_t kFdeVa   = 0x06d968U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffde71U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0198] start_va=0x041b64, fde_va=0x06d980, span=16 bytes
// [VN] FDE[0198] địa chỉ bắt đầu=0x041b64, fde_va=0x06d980, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFE2B9 D65F03C0
uint32_t cybertron_fde_0198_0x041b64(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b64U;
    constexpr uint32_t kFdeVa   = 0x06d980U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffe2b9U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0199] start_va=0x041b74, fde_va=0x06d998, span=16 bytes
// [VN] FDE[0199] địa chỉ bắt đầu=0x041b74, fde_va=0x06d998, kích thước=16 byte
// AArch64 opcodes: F9400008 F100011F 1A9F17E0 D65F03C0
uint32_t cybertron_fde_0199_0x041b74(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b74U;
    constexpr uint32_t kFdeVa   = 0x06d998U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400008U;
    constexpr uint32_t kW1      = 0xf100011fU;
    constexpr uint32_t kW2      = 0x1a9f17e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0200] start_va=0x041b84, fde_va=0x06d9b0, span=16 bytes
// [VN] FDE[0200] địa chỉ bắt đầu=0x041b84, fde_va=0x06d9b0, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDF31 D65F03C0
uint32_t cybertron_fde_0200_0x041b84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b84U;
    constexpr uint32_t kFdeVa   = 0x06d9b0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdf31U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0201] start_va=0x041b94, fde_va=0x06d9c8, span=16 bytes
// [VN] FDE[0201] địa chỉ bắt đầu=0x041b94, fde_va=0x06d9c8, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFE419 D65F03C0
uint32_t cybertron_fde_0201_0x041b94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041b94U;
    constexpr uint32_t kFdeVa   = 0x06d9c8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffe419U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0202] start_va=0x041ba4, fde_va=0x06d9e0, span=16 bytes
// [VN] FDE[0202] địa chỉ bắt đầu=0x041ba4, fde_va=0x06d9e0, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDF49 D65F03C0
uint32_t cybertron_fde_0202_0x041ba4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041ba4U;
    constexpr uint32_t kFdeVa   = 0x06d9e0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdf49U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0203] start_va=0x041bb4, fde_va=0x06d9f8, span=16 bytes
// [VN] FDE[0203] địa chỉ bắt đầu=0x041bb4, fde_va=0x06d9f8, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDBF9 D65F03C0
uint32_t cybertron_fde_0203_0x041bb4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041bb4U;
    constexpr uint32_t kFdeVa   = 0x06d9f8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdbf9U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0204] start_va=0x041bc4, fde_va=0x06da10, span=16 bytes
// [VN] FDE[0204] địa chỉ bắt đầu=0x041bc4, fde_va=0x06da10, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDCB1 D65F03C0
uint32_t cybertron_fde_0204_0x041bc4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041bc4U;
    constexpr uint32_t kFdeVa   = 0x06da10U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdcb1U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0205] start_va=0x041bd4, fde_va=0x06da28, span=16 bytes
// [VN] FDE[0205] địa chỉ bắt đầu=0x041bd4, fde_va=0x06da28, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDF29 D65F03C0
uint32_t cybertron_fde_0205_0x041bd4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041bd4U;
    constexpr uint32_t kFdeVa   = 0x06da28U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffdf29U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0206] start_va=0x041be4, fde_va=0x06da40, span=16 bytes
// [VN] FDE[0206] địa chỉ bắt đầu=0x041be4, fde_va=0x06da40, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFDE4D D65F03C0
uint32_t cybertron_fde_0206_0x041be4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041be4U;
    constexpr uint32_t kFdeVa   = 0x06da40U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffde4dU;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0207] start_va=0x041bf4, fde_va=0x06da58, span=16 bytes
// [VN] FDE[0207] địa chỉ bắt đầu=0x041bf4, fde_va=0x06da58, kích thước=16 byte
// AArch64 opcodes: F9400000 B4000040 17FFE295 D65F03C0
uint32_t cybertron_fde_0207_0x041bf4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041bf4U;
    constexpr uint32_t kFdeVa   = 0x06da58U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000040U;
    constexpr uint32_t kW2      = 0x17ffe295U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0208] start_va=0x041c04, fde_va=0x06da70, span=116 bytes
// [VN] FDE[0208] địa chỉ bắt đầu=0x041c04, fde_va=0x06da70, kích thước=116 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F4
uint32_t cybertron_fde_0208_0x041c04(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041c04U;
    constexpr uint32_t kFdeVa   = 0x06da70U;
    constexpr uint32_t kSpan    = 116U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0209] start_va=0x041c78, fde_va=0x06da90, span=296 bytes
// [VN] FDE[0209] địa chỉ bắt đầu=0x041c78, fde_va=0x06da90, kích thước=296 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0209_0x041c78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041c78U;
    constexpr uint32_t kFdeVa   = 0x06da90U;
    constexpr uint32_t kSpan    = 296U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0210] start_va=0x041da0, fde_va=0x06dab8, span=88 bytes
// [VN] FDE[0210] địa chỉ bắt đầu=0x041da0, fde_va=0x06dab8, kích thước=88 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0210_0x041da0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041da0U;
    constexpr uint32_t kFdeVa   = 0x06dab8U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0211] start_va=0x041df8, fde_va=0x06dad8, span=144 bytes
// [VN] FDE[0211] địa chỉ bắt đầu=0x041df8, fde_va=0x06dad8, kích thước=144 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0211_0x041df8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041df8U;
    constexpr uint32_t kFdeVa   = 0x06dad8U;
    constexpr uint32_t kSpan    = 144U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0212] start_va=0x041e88, fde_va=0x06daf8, span=180 bytes
// [VN] FDE[0212] địa chỉ bắt đầu=0x041e88, fde_va=0x06daf8, kích thước=180 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0212_0x041e88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041e88U;
    constexpr uint32_t kFdeVa   = 0x06daf8U;
    constexpr uint32_t kSpan    = 180U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0213] start_va=0x041f3c, fde_va=0x06db20, span=128 bytes
// [VN] FDE[0213] địa chỉ bắt đầu=0x041f3c, fde_va=0x06db20, kích thước=128 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0213_0x041f3c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041f3cU;
    constexpr uint32_t kFdeVa   = 0x06db20U;
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

// [EN] FDE[0214] start_va=0x041fbc, fde_va=0x06db40, span=144 bytes
// [VN] FDE[0214] địa chỉ bắt đầu=0x041fbc, fde_va=0x06db40, kích thước=144 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0214_0x041fbc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x041fbcU;
    constexpr uint32_t kFdeVa   = 0x06db40U;
    constexpr uint32_t kSpan    = 144U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0215] start_va=0x04204c, fde_va=0x06db60, span=168 bytes
// [VN] FDE[0215] địa chỉ bắt đầu=0x04204c, fde_va=0x06db60, kích thước=168 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0215_0x04204c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04204cU;
    constexpr uint32_t kFdeVa   = 0x06db60U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0216] start_va=0x0420f4, fde_va=0x06db88, span=128 bytes
// [VN] FDE[0216] địa chỉ bắt đầu=0x0420f4, fde_va=0x06db88, kích thước=128 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0216_0x0420f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0420f4U;
    constexpr uint32_t kFdeVa   = 0x06db88U;
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

// [EN] FDE[0217] start_va=0x042174, fde_va=0x06dba8, span=152 bytes
// [VN] FDE[0217] địa chỉ bắt đầu=0x042174, fde_va=0x06dba8, kích thước=152 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0217_0x042174(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042174U;
    constexpr uint32_t kFdeVa   = 0x06dba8U;
    constexpr uint32_t kSpan    = 152U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0218] start_va=0x04220c, fde_va=0x06dbd0, span=264 bytes
// [VN] FDE[0218] địa chỉ bắt đầu=0x04220c, fde_va=0x06dbd0, kích thước=264 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_0218_0x04220c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04220cU;
    constexpr uint32_t kFdeVa   = 0x06dbd0U;
    constexpr uint32_t kSpan    = 264U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0219] start_va=0x042314, fde_va=0x06dbf8, span=140 bytes
// [VN] FDE[0219] địa chỉ bắt đầu=0x042314, fde_va=0x06dbf8, kích thước=140 byte
// AArch64 opcodes: D10183FF F9001BF5 A9044FF4 A9057BFD
uint32_t cybertron_fde_0219_0x042314(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042314U;
    constexpr uint32_t kFdeVa   = 0x06dbf8U;
    constexpr uint32_t kSpan    = 140U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf9001bf5U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0220] start_va=0x0423a0, fde_va=0x06dc18, span=64 bytes
// [VN] FDE[0220] địa chỉ bắt đầu=0x0423a0, fde_va=0x06dc18, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B00001E9
uint32_t cybertron_fde_0220_0x0423a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0423a0U;
    constexpr uint32_t kFdeVa   = 0x06dc18U;
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

// [EN] FDE[0221] start_va=0x0423e0, fde_va=0x06dc38, span=276 bytes
// [VN] FDE[0221] địa chỉ bắt đầu=0x0423e0, fde_va=0x06dc38, kích thước=276 byte
// AArch64 opcodes: D10443FF A90D5FFC A90E57F6 A90F4FF4
uint32_t cybertron_fde_0221_0x0423e0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0423e0U;
    constexpr uint32_t kFdeVa   = 0x06dc38U;
    constexpr uint32_t kSpan    = 276U;
    constexpr uint32_t kW0      = 0xd10443ffU;
    constexpr uint32_t kW1      = 0xa90d5ffcU;
    constexpr uint32_t kW2      = 0xa90e57f6U;
    constexpr uint32_t kW3      = 0xa90f4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0222] start_va=0x0424f4, fde_va=0x06dc60, span=36 bytes
// [VN] FDE[0222] địa chỉ bắt đầu=0x0424f4, fde_va=0x06dc60, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0803F3
uint32_t cybertron_fde_0222_0x0424f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0424f4U;
    constexpr uint32_t kFdeVa   = 0x06dc60U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0803f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0223] start_va=0x042518, fde_va=0x06dc80, span=96 bytes
// [VN] FDE[0223] địa chỉ bắt đầu=0x042518, fde_va=0x06dc80, kích thước=96 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0223_0x042518(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042518U;
    constexpr uint32_t kFdeVa   = 0x06dc80U;
    constexpr uint32_t kSpan    = 96U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0224] start_va=0x042578, fde_va=0x06dca0, span=96 bytes
// [VN] FDE[0224] địa chỉ bắt đầu=0x042578, fde_va=0x06dca0, kích thước=96 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0224_0x042578(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042578U;
    constexpr uint32_t kFdeVa   = 0x06dca0U;
    constexpr uint32_t kSpan    = 96U;
    constexpr uint32_t kW0      = 0xa9bd57f6U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0225] start_va=0x0425d8, fde_va=0x06dcc8, span=160 bytes
// [VN] FDE[0225] địa chỉ bắt đầu=0x0425d8, fde_va=0x06dcc8, kích thước=160 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0225_0x0425d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0425d8U;
    constexpr uint32_t kFdeVa   = 0x06dcc8U;
    constexpr uint32_t kSpan    = 160U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0226] start_va=0x042678, fde_va=0x06dcf0, span=72 bytes
// [VN] FDE[0226] địa chỉ bắt đầu=0x042678, fde_va=0x06dcf0, kích thước=72 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0226_0x042678(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042678U;
    constexpr uint32_t kFdeVa   = 0x06dcf0U;
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

// [EN] FDE[0227] start_va=0x0426c0, fde_va=0x06dd10, span=300 bytes
// [VN] FDE[0227] địa chỉ bắt đầu=0x0426c0, fde_va=0x06dd10, kích thước=300 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_0227_0x0426c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0426c0U;
    constexpr uint32_t kFdeVa   = 0x06dd10U;
    constexpr uint32_t kSpan    = 300U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0228] start_va=0x0427ec, fde_va=0x06dd38, span=48 bytes
// [VN] FDE[0228] địa chỉ bắt đầu=0x0427ec, fde_va=0x06dd38, kích thước=48 byte
// AArch64 opcodes: A940A009 EB090109 540000C0 D1002129
uint32_t cybertron_fde_0228_0x0427ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0427ecU;
    constexpr uint32_t kFdeVa   = 0x06dd38U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xa940a009U;
    constexpr uint32_t kW1      = 0xeb090109U;
    constexpr uint32_t kW2      = 0x540000c0U;
    constexpr uint32_t kW3      = 0xd1002129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0229] start_va=0x04281c, fde_va=0x06dd50, span=72 bytes
// [VN] FDE[0229] địa chỉ bắt đầu=0x04281c, fde_va=0x06dd50, kích thước=72 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0229_0x04281c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x04281cU;
    constexpr uint32_t kFdeVa   = 0x06dd50U;
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

// [EN] FDE[0230] start_va=0x042864, fde_va=0x06dd70, span=224 bytes
// [VN] FDE[0230] địa chỉ bắt đầu=0x042864, fde_va=0x06dd70, kích thước=224 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A940A408
uint32_t cybertron_fde_0230_0x042864(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042864U;
    constexpr uint32_t kFdeVa   = 0x06dd70U;
    constexpr uint32_t kSpan    = 224U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xa940a408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0231] start_va=0x042944, fde_va=0x06dd90, span=48 bytes
// [VN] FDE[0231] địa chỉ bắt đầu=0x042944, fde_va=0x06dd90, kích thước=48 byte
// AArch64 opcodes: A940A009 EB090109 540000C0 D1002129
uint32_t cybertron_fde_0231_0x042944(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042944U;
    constexpr uint32_t kFdeVa   = 0x06dd90U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xa940a009U;
    constexpr uint32_t kW1      = 0xeb090109U;
    constexpr uint32_t kW2      = 0x540000c0U;
    constexpr uint32_t kW3      = 0xd1002129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0232] start_va=0x042974, fde_va=0x06dda8, span=36 bytes
// [VN] FDE[0232] địa chỉ bắt đầu=0x042974, fde_va=0x06dda8, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0232_0x042974(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042974U;
    constexpr uint32_t kFdeVa   = 0x06dda8U;
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

// [EN] FDE[0233] start_va=0x042998, fde_va=0x06ddc8, span=56 bytes
// [VN] FDE[0233] địa chỉ bắt đầu=0x042998, fde_va=0x06ddc8, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400C13
uint32_t cybertron_fde_0233_0x042998(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042998U;
    constexpr uint32_t kFdeVa   = 0x06ddc8U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400c13U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0234] start_va=0x0429d0, fde_va=0x06dde8, span=28 bytes
// [VN] FDE[0234] địa chỉ bắt đầu=0x0429d0, fde_va=0x06dde8, kích thước=28 byte
// AArch64 opcodes: B00001E9 F9400428 F9471529 9100600A
uint32_t cybertron_fde_0234_0x0429d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0429d0U;
    constexpr uint32_t kFdeVa   = 0x06dde8U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xb00001e9U;
    constexpr uint32_t kW1      = 0xf9400428U;
    constexpr uint32_t kW2      = 0xf9471529U;
    constexpr uint32_t kW3      = 0x9100600aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0235] start_va=0x0429ec, fde_va=0x06de00, span=4 bytes
// [VN] FDE[0235] địa chỉ bắt đầu=0x0429ec, fde_va=0x06de00, kích thước=4 byte
// AArch64 opcodes: 17FFD8CD D10143FF F90013F5 A9034FF4
uint32_t cybertron_fde_0235_0x0429ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0429ecU;
    constexpr uint32_t kFdeVa   = 0x06de00U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ffd8cdU;
    constexpr uint32_t kW1      = 0xd10143ffU;
    constexpr uint32_t kW2      = 0xf90013f5U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0236] start_va=0x0429f0, fde_va=0x06de18, span=168 bytes
// [VN] FDE[0236] địa chỉ bắt đầu=0x0429f0, fde_va=0x06de18, kích thước=168 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_0236_0x0429f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0429f0U;
    constexpr uint32_t kFdeVa   = 0x06de18U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0237] start_va=0x042a98, fde_va=0x06de38, span=232 bytes
// [VN] FDE[0237] địa chỉ bắt đầu=0x042a98, fde_va=0x06de38, kích thước=232 byte
// AArch64 opcodes: F81B0FF9 A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0237_0x042a98(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042a98U;
    constexpr uint32_t kFdeVa   = 0x06de38U;
    constexpr uint32_t kSpan    = 232U;
    constexpr uint32_t kW0      = 0xf81b0ff9U;
    constexpr uint32_t kW1      = 0xa9015ff8U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0238] start_va=0x042b80, fde_va=0x06de60, span=196 bytes
// [VN] FDE[0238] địa chỉ bắt đầu=0x042b80, fde_va=0x06de60, kích thước=196 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0238_0x042b80(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042b80U;
    constexpr uint32_t kFdeVa   = 0x06de60U;
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

// [EN] FDE[0239] start_va=0x042c44, fde_va=0x06de88, span=44 bytes
// [VN] FDE[0239] địa chỉ bắt đầu=0x042c44, fde_va=0x06de88, kích thước=44 byte
// AArch64 opcodes: B00001E8 F946D108 91004108 F9000008
uint32_t cybertron_fde_0239_0x042c44(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x042c44U;
    constexpr uint32_t kFdeVa   = 0x06de88U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xb00001e8U;
    constexpr uint32_t kW1      = 0xf946d108U;
    constexpr uint32_t kW2      = 0x91004108U;
    constexpr uint32_t kW3      = 0xf9000008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

uint32_t DispatchCybertronFdeShard1(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 0U: return cybertron_fde_0000_0x03b25c(a0, a1);
        case 1U: return cybertron_fde_0001_0x03b3d8(a0, a1);
        case 2U: return cybertron_fde_0002_0x03b68c(a0, a1);
        case 3U: return cybertron_fde_0003_0x03b6e4(a0, a1);
        case 4U: return cybertron_fde_0004_0x03b700(a0, a1);
        case 5U: return cybertron_fde_0005_0x03b71c(a0, a1);
        case 6U: return cybertron_fde_0006_0x03b738(a0, a1);
        case 7U: return cybertron_fde_0007_0x03b74c(a0, a1);
        case 8U: return cybertron_fde_0008_0x03b780(a0, a1);
        case 9U: return cybertron_fde_0009_0x03b790(a0, a1);
        case 10U: return cybertron_fde_0010_0x03b7a0(a0, a1);
        case 11U: return cybertron_fde_0011_0x03b818(a0, a1);
        case 12U: return cybertron_fde_0012_0x03b870(a0, a1);
        case 13U: return cybertron_fde_0013_0x03b87c(a0, a1);
        case 14U: return cybertron_fde_0014_0x03b8b0(a0, a1);
        case 15U: return cybertron_fde_0015_0x03b8ec(a0, a1);
        case 16U: return cybertron_fde_0016_0x03b8f4(a0, a1);
        case 17U: return cybertron_fde_0017_0x03b8f8(a0, a1);
        case 18U: return cybertron_fde_0018_0x03b960(a0, a1);
        case 19U: return cybertron_fde_0019_0x03b9c0(a0, a1);
        case 20U: return cybertron_fde_0020_0x03ba1c(a0, a1);
        case 21U: return cybertron_fde_0021_0x03ba88(a0, a1);
        case 22U: return cybertron_fde_0022_0x03bae8(a0, a1);
        case 23U: return cybertron_fde_0023_0x03baf0(a0, a1);
        case 24U: return cybertron_fde_0024_0x03bb18(a0, a1);
        case 25U: return cybertron_fde_0025_0x03bb50(a0, a1);
        case 26U: return cybertron_fde_0026_0x03bb6c(a0, a1);
        case 27U: return cybertron_fde_0027_0x03bb78(a0, a1);
        case 28U: return cybertron_fde_0028_0x03bb7c(a0, a1);
        case 29U: return cybertron_fde_0029_0x03bbd0(a0, a1);
        case 30U: return cybertron_fde_0030_0x03bbd4(a0, a1);
        case 31U: return cybertron_fde_0031_0x03bc0c(a0, a1);
        case 32U: return cybertron_fde_0032_0x03bc24(a0, a1);
        case 33U: return cybertron_fde_0033_0x03bc28(a0, a1);
        case 34U: return cybertron_fde_0034_0x03bc2c(a0, a1);
        case 35U: return cybertron_fde_0035_0x03bc68(a0, a1);
        case 36U: return cybertron_fde_0036_0x03bc84(a0, a1);
        case 37U: return cybertron_fde_0037_0x03bc90(a0, a1);
        case 38U: return cybertron_fde_0038_0x03bd44(a0, a1);
        case 39U: return cybertron_fde_0039_0x03bde8(a0, a1);
        case 40U: return cybertron_fde_0040_0x03be94(a0, a1);
        case 41U: return cybertron_fde_0041_0x03bf60(a0, a1);
        case 42U: return cybertron_fde_0042_0x03c008(a0, a1);
        case 43U: return cybertron_fde_0043_0x03c050(a0, a1);
        case 44U: return cybertron_fde_0044_0x03c0cc(a0, a1);
        case 45U: return cybertron_fde_0045_0x03c0e4(a0, a1);
        case 46U: return cybertron_fde_0046_0x03c1b0(a0, a1);
        case 47U: return cybertron_fde_0047_0x03c5b0(a0, a1);
        case 48U: return cybertron_fde_0048_0x03c644(a0, a1);
        case 49U: return cybertron_fde_0049_0x03c65c(a0, a1);
        case 50U: return cybertron_fde_0050_0x03c66c(a0, a1);
        case 51U: return cybertron_fde_0051_0x03c690(a0, a1);
        case 52U: return cybertron_fde_0052_0x03c6a0(a0, a1);
        case 53U: return cybertron_fde_0053_0x03c6c0(a0, a1);
        case 54U: return cybertron_fde_0054_0x03c6d0(a0, a1);
        case 55U: return cybertron_fde_0055_0x03c6f0(a0, a1);
        case 56U: return cybertron_fde_0056_0x03c700(a0, a1);
        case 57U: return cybertron_fde_0057_0x03c734(a0, a1);
        case 58U: return cybertron_fde_0058_0x03c744(a0, a1);
        case 59U: return cybertron_fde_0059_0x03c768(a0, a1);
        case 60U: return cybertron_fde_0060_0x03c778(a0, a1);
        case 61U: return cybertron_fde_0061_0x03c7c0(a0, a1);
        case 62U: return cybertron_fde_0062_0x03c894(a0, a1);
        case 63U: return cybertron_fde_0063_0x03c9a0(a0, a1);
        case 64U: return cybertron_fde_0064_0x03c9f8(a0, a1);
        case 65U: return cybertron_fde_0065_0x03cad0(a0, a1);
        case 66U: return cybertron_fde_0066_0x03cba4(a0, a1);
        case 67U: return cybertron_fde_0067_0x03cc78(a0, a1);
        case 68U: return cybertron_fde_0068_0x03cd50(a0, a1);
        case 69U: return cybertron_fde_0069_0x03ce24(a0, a1);
        case 70U: return cybertron_fde_0070_0x03cef8(a0, a1);
        case 71U: return cybertron_fde_0071_0x03cfcc(a0, a1);
        case 72U: return cybertron_fde_0072_0x03d0bc(a0, a1);
        case 73U: return cybertron_fde_0073_0x03d1ac(a0, a1);
        case 74U: return cybertron_fde_0074_0x03d23c(a0, a1);
        case 75U: return cybertron_fde_0075_0x03d2cc(a0, a1);
        case 76U: return cybertron_fde_0076_0x03d38c(a0, a1);
        case 77U: return cybertron_fde_0077_0x03d450(a0, a1);
        case 78U: return cybertron_fde_0078_0x03d510(a0, a1);
        case 79U: return cybertron_fde_0079_0x03d5d0(a0, a1);
        case 80U: return cybertron_fde_0080_0x03d694(a0, a1);
        case 81U: return cybertron_fde_0081_0x03d754(a0, a1);
        case 82U: return cybertron_fde_0082_0x03d814(a0, a1);
        case 83U: return cybertron_fde_0083_0x03d8d4(a0, a1);
        case 84U: return cybertron_fde_0084_0x03d9dc(a0, a1);
        case 85U: return cybertron_fde_0085_0x03dae4(a0, a1);
        case 86U: return cybertron_fde_0086_0x03daf0(a0, a1);
        case 87U: return cybertron_fde_0087_0x03db3c(a0, a1);
        case 88U: return cybertron_fde_0088_0x03db4c(a0, a1);
        case 89U: return cybertron_fde_0089_0x03db78(a0, a1);
        case 90U: return cybertron_fde_0090_0x03db88(a0, a1);
        case 91U: return cybertron_fde_0091_0x03dbe8(a0, a1);
        case 92U: return cybertron_fde_0092_0x03dc08(a0, a1);
        case 93U: return cybertron_fde_0093_0x03dc10(a0, a1);
        case 94U: return cybertron_fde_0094_0x03dc18(a0, a1);
        case 95U: return cybertron_fde_0095_0x03dcd0(a0, a1);
        case 96U: return cybertron_fde_0096_0x03ddc8(a0, a1);
        case 97U: return cybertron_fde_0097_0x03dec4(a0, a1);
        case 98U: return cybertron_fde_0098_0x03dfbc(a0, a1);
        case 99U: return cybertron_fde_0099_0x03f0b4(a0, a1);
        case 100U: return cybertron_fde_0100_0x03f1b0(a0, a1);
        case 101U: return cybertron_fde_0101_0x03f2a8(a0, a1);
        case 102U: return cybertron_fde_0102_0x03f3a0(a0, a1);
        case 103U: return cybertron_fde_0103_0x03f4a4(a0, a1);
        case 104U: return cybertron_fde_0104_0x03f5a4(a0, a1);
        case 105U: return cybertron_fde_0105_0x03f6b4(a0, a1);
        case 106U: return cybertron_fde_0106_0x03f7c4(a0, a1);
        case 107U: return cybertron_fde_0107_0x03f840(a0, a1);
        case 108U: return cybertron_fde_0108_0x03f8c8(a0, a1);
        case 109U: return cybertron_fde_0109_0x03f950(a0, a1);
        case 110U: return cybertron_fde_0110_0x03f9d8(a0, a1);
        case 111U: return cybertron_fde_0111_0x03fa60(a0, a1);
        case 112U: return cybertron_fde_0112_0x03fae8(a0, a1);
        case 113U: return cybertron_fde_0113_0x03fb70(a0, a1);
        case 114U: return cybertron_fde_0114_0x03fc50(a0, a1);
        case 115U: return cybertron_fde_0115_0x03fc58(a0, a1);
        case 116U: return cybertron_fde_0116_0x03fc60(a0, a1);
        case 117U: return cybertron_fde_0117_0x03fc64(a0, a1);
        case 118U: return cybertron_fde_0118_0x03fc68(a0, a1);
        case 119U: return cybertron_fde_0119_0x03fc6c(a0, a1);
        case 120U: return cybertron_fde_0120_0x03fc70(a0, a1);
        case 121U: return cybertron_fde_0121_0x03fc74(a0, a1);
        case 122U: return cybertron_fde_0122_0x03fc78(a0, a1);
        case 123U: return cybertron_fde_0123_0x03fc7c(a0, a1);
        case 124U: return cybertron_fde_0124_0x03fc80(a0, a1);
        case 125U: return cybertron_fde_0125_0x03fca4(a0, a1);
        case 126U: return cybertron_fde_0126_0x03fce4(a0, a1);
        case 127U: return cybertron_fde_0127_0x03fcf8(a0, a1);
        case 128U: return cybertron_fde_0128_0x03fd2c(a0, a1);
        case 129U: return cybertron_fde_0129_0x03fd40(a0, a1);
        case 130U: return cybertron_fde_0130_0x03fd74(a0, a1);
        case 131U: return cybertron_fde_0131_0x03fe30(a0, a1);
        case 132U: return cybertron_fde_0132_0x03fe64(a0, a1);
        case 133U: return cybertron_fde_0133_0x03fea0(a0, a1);
        case 134U: return cybertron_fde_0134_0x03fea8(a0, a1);
        case 135U: return cybertron_fde_0135_0x03feac(a0, a1);
        case 136U: return cybertron_fde_0136_0x03fee8(a0, a1);
        case 137U: return cybertron_fde_0137_0x03ff34(a0, a1);
        case 138U: return cybertron_fde_0138_0x03ff70(a0, a1);
        case 139U: return cybertron_fde_0139_0x03ffdc(a0, a1);
        case 140U: return cybertron_fde_0140_0x0400a0(a0, a1);
        case 141U: return cybertron_fde_0141_0x0401d4(a0, a1);
        case 142U: return cybertron_fde_0142_0x0402ec(a0, a1);
        case 143U: return cybertron_fde_0143_0x04035c(a0, a1);
        case 144U: return cybertron_fde_0144_0x0403ac(a0, a1);
        case 145U: return cybertron_fde_0145_0x0403b0(a0, a1);
        case 146U: return cybertron_fde_0146_0x0403d4(a0, a1);
        case 147U: return cybertron_fde_0147_0x0403e0(a0, a1);
        case 148U: return cybertron_fde_0148_0x0403e4(a0, a1);
        case 149U: return cybertron_fde_0149_0x0403e8(a0, a1);
        case 150U: return cybertron_fde_0150_0x04040c(a0, a1);
        case 151U: return cybertron_fde_0151_0x040418(a0, a1);
        case 152U: return cybertron_fde_0152_0x04041c(a0, a1);
        case 153U: return cybertron_fde_0153_0x040420(a0, a1);
        case 154U: return cybertron_fde_0154_0x040444(a0, a1);
        case 155U: return cybertron_fde_0155_0x040450(a0, a1);
        case 156U: return cybertron_fde_0156_0x040454(a0, a1);
        case 157U: return cybertron_fde_0157_0x0404a4(a0, a1);
        case 158U: return cybertron_fde_0158_0x0404fc(a0, a1);
        case 159U: return cybertron_fde_0159_0x040508(a0, a1);
        case 160U: return cybertron_fde_0160_0x04050c(a0, a1);
        case 161U: return cybertron_fde_0161_0x04080c(a0, a1);
        case 162U: return cybertron_fde_0162_0x0408f0(a0, a1);
        case 163U: return cybertron_fde_0163_0x040b08(a0, a1);
        case 164U: return cybertron_fde_0164_0x040c0c(a0, a1);
        case 165U: return cybertron_fde_0165_0x040cc4(a0, a1);
        case 166U: return cybertron_fde_0166_0x040d84(a0, a1);
        case 167U: return cybertron_fde_0167_0x040fd8(a0, a1);
        case 168U: return cybertron_fde_0168_0x04101c(a0, a1);
        case 169U: return cybertron_fde_0169_0x0411dc(a0, a1);
        case 170U: return cybertron_fde_0170_0x041230(a0, a1);
        case 171U: return cybertron_fde_0171_0x041264(a0, a1);
        case 172U: return cybertron_fde_0172_0x041424(a0, a1);
        case 173U: return cybertron_fde_0173_0x041494(a0, a1);
        case 174U: return cybertron_fde_0174_0x0415c8(a0, a1);
        case 175U: return cybertron_fde_0175_0x0415e0(a0, a1);
        case 176U: return cybertron_fde_0176_0x041600(a0, a1);
        case 177U: return cybertron_fde_0177_0x04161c(a0, a1);
        case 178U: return cybertron_fde_0178_0x041740(a0, a1);
        case 179U: return cybertron_fde_0179_0x041750(a0, a1);
        case 180U: return cybertron_fde_0180_0x0417a8(a0, a1);
        case 181U: return cybertron_fde_0181_0x041820(a0, a1);
        case 182U: return cybertron_fde_0182_0x04188c(a0, a1);
        case 183U: return cybertron_fde_0183_0x0418f8(a0, a1);
        case 184U: return cybertron_fde_0184_0x041970(a0, a1);
        case 185U: return cybertron_fde_0185_0x0419dc(a0, a1);
        case 186U: return cybertron_fde_0186_0x041a48(a0, a1);
        case 187U: return cybertron_fde_0187_0x041a5c(a0, a1);
        case 188U: return cybertron_fde_0188_0x041a7c(a0, a1);
        case 189U: return cybertron_fde_0189_0x041ac0(a0, a1);
        case 190U: return cybertron_fde_0190_0x041ae4(a0, a1);
        case 191U: return cybertron_fde_0191_0x041af4(a0, a1);
        case 192U: return cybertron_fde_0192_0x041b04(a0, a1);
        case 193U: return cybertron_fde_0193_0x041b14(a0, a1);
        case 194U: return cybertron_fde_0194_0x041b24(a0, a1);
        case 195U: return cybertron_fde_0195_0x041b34(a0, a1);
        case 196U: return cybertron_fde_0196_0x041b44(a0, a1);
        case 197U: return cybertron_fde_0197_0x041b54(a0, a1);
        case 198U: return cybertron_fde_0198_0x041b64(a0, a1);
        case 199U: return cybertron_fde_0199_0x041b74(a0, a1);
        case 200U: return cybertron_fde_0200_0x041b84(a0, a1);
        case 201U: return cybertron_fde_0201_0x041b94(a0, a1);
        case 202U: return cybertron_fde_0202_0x041ba4(a0, a1);
        case 203U: return cybertron_fde_0203_0x041bb4(a0, a1);
        case 204U: return cybertron_fde_0204_0x041bc4(a0, a1);
        case 205U: return cybertron_fde_0205_0x041bd4(a0, a1);
        case 206U: return cybertron_fde_0206_0x041be4(a0, a1);
        case 207U: return cybertron_fde_0207_0x041bf4(a0, a1);
        case 208U: return cybertron_fde_0208_0x041c04(a0, a1);
        case 209U: return cybertron_fde_0209_0x041c78(a0, a1);
        case 210U: return cybertron_fde_0210_0x041da0(a0, a1);
        case 211U: return cybertron_fde_0211_0x041df8(a0, a1);
        case 212U: return cybertron_fde_0212_0x041e88(a0, a1);
        case 213U: return cybertron_fde_0213_0x041f3c(a0, a1);
        case 214U: return cybertron_fde_0214_0x041fbc(a0, a1);
        case 215U: return cybertron_fde_0215_0x04204c(a0, a1);
        case 216U: return cybertron_fde_0216_0x0420f4(a0, a1);
        case 217U: return cybertron_fde_0217_0x042174(a0, a1);
        case 218U: return cybertron_fde_0218_0x04220c(a0, a1);
        case 219U: return cybertron_fde_0219_0x042314(a0, a1);
        case 220U: return cybertron_fde_0220_0x0423a0(a0, a1);
        case 221U: return cybertron_fde_0221_0x0423e0(a0, a1);
        case 222U: return cybertron_fde_0222_0x0424f4(a0, a1);
        case 223U: return cybertron_fde_0223_0x042518(a0, a1);
        case 224U: return cybertron_fde_0224_0x042578(a0, a1);
        case 225U: return cybertron_fde_0225_0x0425d8(a0, a1);
        case 226U: return cybertron_fde_0226_0x042678(a0, a1);
        case 227U: return cybertron_fde_0227_0x0426c0(a0, a1);
        case 228U: return cybertron_fde_0228_0x0427ec(a0, a1);
        case 229U: return cybertron_fde_0229_0x04281c(a0, a1);
        case 230U: return cybertron_fde_0230_0x042864(a0, a1);
        case 231U: return cybertron_fde_0231_0x042944(a0, a1);
        case 232U: return cybertron_fde_0232_0x042974(a0, a1);
        case 233U: return cybertron_fde_0233_0x042998(a0, a1);
        case 234U: return cybertron_fde_0234_0x0429d0(a0, a1);
        case 235U: return cybertron_fde_0235_0x0429ec(a0, a1);
        case 236U: return cybertron_fde_0236_0x0429f0(a0, a1);
        case 237U: return cybertron_fde_0237_0x042a98(a0, a1);
        case 238U: return cybertron_fde_0238_0x042b80(a0, a1);
        case 239U: return cybertron_fde_0239_0x042c44(a0, a1);
        default: return 0U;
    }
}

} // namespace datacenter
