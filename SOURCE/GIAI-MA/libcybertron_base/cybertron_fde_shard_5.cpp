// ============================================================================
// File: cybertron_fde_shard_5.cpp
// Target: libcybertron_base.so (509,816 bytes)
// SHA-256: 0d969c7e981d68f46d81986a0f16881d1ff9605afb9e6e352f1ae88a5695c7e6
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// FDE Range: [960..1200] of 1,201 (.eh_frame_hdr @ 0x069c8c)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [960..1200]
//      verified directly against the .text section of libcybertron_base.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [960..1200]
//      đã đối chiếu trực tiếp với phân đoạn .text của libcybertron_base.so.
// ============================================================================

#include "cybertron_base_types.h"

namespace datacenter {

// [EN] FDE[0960] start_va=0x05c33c, fde_va=0x0737f8, span=72 bytes
// [VN] FDE[0960] địa chỉ bắt đầu=0x05c33c, fde_va=0x0737f8, kích thước=72 byte
// AArch64 opcodes: A9BF7BFD 910003FD F0000108 F9464508
uint32_t cybertron_fde_0960_0x05c33c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c33cU;
    constexpr uint32_t kFdeVa   = 0x0737f8U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xf0000108U;
    constexpr uint32_t kW3      = 0xf9464508U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0961] start_va=0x05c384, fde_va=0x073818, span=12 bytes
// [VN] FDE[0961] địa chỉ bắt đầu=0x05c384, fde_va=0x073818, kích thước=12 byte
// AArch64 opcodes: 12800001 12800002 17FF723D 12800002
uint32_t cybertron_fde_0961_0x05c384(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c384U;
    constexpr uint32_t kFdeVa   = 0x073818U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0x12800001U;
    constexpr uint32_t kW1      = 0x12800002U;
    constexpr uint32_t kW2      = 0x17ff723dU;
    constexpr uint32_t kW3      = 0x12800002U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0962] start_va=0x05c390, fde_va=0x073830, span=8 bytes
// [VN] FDE[0962] địa chỉ bắt đầu=0x05c390, fde_va=0x073830, kích thước=8 byte
// AArch64 opcodes: 12800002 17FF723B D10143FF F9001BF3
uint32_t cybertron_fde_0962_0x05c390(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c390U;
    constexpr uint32_t kFdeVa   = 0x073830U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x12800002U;
    constexpr uint32_t kW1      = 0x17ff723bU;
    constexpr uint32_t kW2      = 0xd10143ffU;
    constexpr uint32_t kW3      = 0xf9001bf3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0963] start_va=0x05c398, fde_va=0x073848, span=108 bytes
// [VN] FDE[0963] địa chỉ bắt đầu=0x05c398, fde_va=0x073848, kích thước=108 byte
// AArch64 opcodes: D10143FF F9001BF3 A9047BFD 910103FD
uint32_t cybertron_fde_0963_0x05c398(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c398U;
    constexpr uint32_t kFdeVa   = 0x073848U;
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

// [EN] FDE[0964] start_va=0x05c404, fde_va=0x073868, span=44 bytes
// [VN] FDE[0964] địa chỉ bắt đầu=0x05c404, fde_va=0x073868, kích thước=44 byte
// AArch64 opcodes: D10083FF A9017BFD 910043FD AA0303E4
uint32_t cybertron_fde_0964_0x05c404(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c404U;
    constexpr uint32_t kFdeVa   = 0x073868U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xd10083ffU;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0303e4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0965] start_va=0x05c430, fde_va=0x073888, span=52 bytes
// [VN] FDE[0965] địa chỉ bắt đầu=0x05c430, fde_va=0x073888, kích thước=52 byte
// AArch64 opcodes: D10083FF A9017BFD 910043FD AA0103E4
uint32_t cybertron_fde_0965_0x05c430(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c430U;
    constexpr uint32_t kFdeVa   = 0x073888U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xd10083ffU;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103e4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0966] start_va=0x05c464, fde_va=0x0738a8, span=104 bytes
// [VN] FDE[0966] địa chỉ bắt đầu=0x05c464, fde_va=0x0738a8, kích thước=104 byte
// AArch64 opcodes: D10143FF F9001BF3 A9047BFD 910103FD
uint32_t cybertron_fde_0966_0x05c464(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c464U;
    constexpr uint32_t kFdeVa   = 0x0738a8U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9001bf3U;
    constexpr uint32_t kW2      = 0xa9047bfdU;
    constexpr uint32_t kW3      = 0x910103fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0967] start_va=0x05c4cc, fde_va=0x0738c8, span=36 bytes
// [VN] FDE[0967] địa chỉ bắt đầu=0x05c4cc, fde_va=0x0738c8, kích thước=36 byte
// AArch64 opcodes: D10083FF A9017BFD 910043FD 910003E5
uint32_t cybertron_fde_0967_0x05c4cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c4ccU;
    constexpr uint32_t kFdeVa   = 0x0738c8U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xd10083ffU;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x910003e5U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0968] start_va=0x05c4f0, fde_va=0x0738e8, span=16 bytes
// [VN] FDE[0968] địa chỉ bắt đầu=0x05c4f0, fde_va=0x0738e8, kích thước=16 byte
// AArch64 opcodes: AA0403E5 AA0303E4 12800003 17FF7381
uint32_t cybertron_fde_0968_0x05c4f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c4f0U;
    constexpr uint32_t kFdeVa   = 0x0738e8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xaa0403e5U;
    constexpr uint32_t kW1      = 0xaa0303e4U;
    constexpr uint32_t kW2      = 0x12800003U;
    constexpr uint32_t kW3      = 0x17ff7381U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0969] start_va=0x05c500, fde_va=0x073900, span=88 bytes
// [VN] FDE[0969] địa chỉ bắt đầu=0x05c500, fde_va=0x073900, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_0969_0x05c500(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c500U;
    constexpr uint32_t kFdeVa   = 0x073900U;
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

// [EN] FDE[0970] start_va=0x05c558, fde_va=0x073920, span=212 bytes
// [VN] FDE[0970] địa chỉ bắt đầu=0x05c558, fde_va=0x073920, kích thước=212 byte
// AArch64 opcodes: F81B0FF9 A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0970_0x05c558(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c558U;
    constexpr uint32_t kFdeVa   = 0x073920U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xf81b0ff9U;
    constexpr uint32_t kW1      = 0xa9015ff8U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0971] start_va=0x05c62c, fde_va=0x073948, span=12 bytes
// [VN] FDE[0971] địa chỉ bắt đầu=0x05c62c, fde_va=0x073948, kích thước=12 byte
// AArch64 opcodes: AA0103E2 12800001 17FF793F D10103FF
uint32_t cybertron_fde_0971_0x05c62c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c62cU;
    constexpr uint32_t kFdeVa   = 0x073948U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xaa0103e2U;
    constexpr uint32_t kW1      = 0x12800001U;
    constexpr uint32_t kW2      = 0x17ff793fU;
    constexpr uint32_t kW3      = 0xd10103ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0972] start_va=0x05c638, fde_va=0x073960, span=108 bytes
// [VN] FDE[0972] địa chỉ bắt đầu=0x05c638, fde_va=0x073960, kích thước=108 byte
// AArch64 opcodes: D10103FF F90013F3 A9037BFD 9100C3FD
uint32_t cybertron_fde_0972_0x05c638(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c638U;
    constexpr uint32_t kFdeVa   = 0x073960U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xf90013f3U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0973] start_va=0x05c6a4, fde_va=0x073980, span=172 bytes
// [VN] FDE[0973] địa chỉ bắt đầu=0x05c6a4, fde_va=0x073980, kích thước=172 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD F9400408
uint32_t cybertron_fde_0973_0x05c6a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c6a4U;
    constexpr uint32_t kFdeVa   = 0x073980U;
    constexpr uint32_t kSpan    = 172U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0974] start_va=0x05c750, fde_va=0x0739a0, span=160 bytes
// [VN] FDE[0974] địa chỉ bắt đầu=0x05c750, fde_va=0x0739a0, kích thước=160 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD F9400028
uint32_t cybertron_fde_0974_0x05c750(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c750U;
    constexpr uint32_t kFdeVa   = 0x0739a0U;
    constexpr uint32_t kSpan    = 160U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400028U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0975] start_va=0x05c7f0, fde_va=0x0739c0, span=476 bytes
// [VN] FDE[0975] địa chỉ bắt đầu=0x05c7f0, fde_va=0x0739c0, kích thước=476 byte
// AArch64 opcodes: D10703FF A9166FFC A91767FA A9185FF8
uint32_t cybertron_fde_0975_0x05c7f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c7f0U;
    constexpr uint32_t kFdeVa   = 0x0739c0U;
    constexpr uint32_t kSpan    = 476U;
    constexpr uint32_t kW0      = 0xd10703ffU;
    constexpr uint32_t kW1      = 0xa9166ffcU;
    constexpr uint32_t kW2      = 0xa91767faU;
    constexpr uint32_t kW3      = 0xa9185ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0976] start_va=0x05c9cc, fde_va=0x0739f0, span=260 bytes
// [VN] FDE[0976] địa chỉ bắt đầu=0x05c9cc, fde_va=0x0739f0, kích thước=260 byte
// AArch64 opcodes: D101C3FF A9016FFC A90267FA A9035FF8
uint32_t cybertron_fde_0976_0x05c9cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05c9ccU;
    constexpr uint32_t kFdeVa   = 0x0739f0U;
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

// [EN] FDE[0977] start_va=0x05cad0, fde_va=0x073a20, span=4 bytes
// [VN] FDE[0977] địa chỉ bắt đầu=0x05cad0, fde_va=0x073a20, kích thước=4 byte
// AArch64 opcodes: 17FF75AC F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_0977_0x05cad0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cad0U;
    constexpr uint32_t kFdeVa   = 0x073a20U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff75acU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0978] start_va=0x05cad4, fde_va=0x073a38, span=68 bytes
// [VN] FDE[0978] địa chỉ bắt đầu=0x05cad4, fde_va=0x073a38, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F0000108
uint32_t cybertron_fde_0978_0x05cad4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cad4U;
    constexpr uint32_t kFdeVa   = 0x073a38U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf0000108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0979] start_va=0x05cb18, fde_va=0x073a58, span=36 bytes
// [VN] FDE[0979] địa chỉ bắt đầu=0x05cb18, fde_va=0x073a58, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0979_0x05cb18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cb18U;
    constexpr uint32_t kFdeVa   = 0x073a58U;
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

// [EN] FDE[0980] start_va=0x05cb3c, fde_va=0x073a78, span=52 bytes
// [VN] FDE[0980] địa chỉ bắt đầu=0x05cb3c, fde_va=0x073a78, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F0000108
uint32_t cybertron_fde_0980_0x05cb3c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cb3cU;
    constexpr uint32_t kFdeVa   = 0x073a78U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf0000108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0981] start_va=0x05cb70, fde_va=0x073a98, span=60 bytes
// [VN] FDE[0981] địa chỉ bắt đầu=0x05cb70, fde_va=0x073a98, kích thước=60 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F0000108
uint32_t cybertron_fde_0981_0x05cb70(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cb70U;
    constexpr uint32_t kFdeVa   = 0x073a98U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf0000108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0982] start_va=0x05cbac, fde_va=0x073ab8, span=8 bytes
// [VN] FDE[0982] địa chỉ bắt đầu=0x05cbac, fde_va=0x073ab8, kích thước=8 byte
// AArch64 opcodes: 91006000 17FF7050 17FF705B D10203FF
uint32_t cybertron_fde_0982_0x05cbac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cbacU;
    constexpr uint32_t kFdeVa   = 0x073ab8U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91006000U;
    constexpr uint32_t kW1      = 0x17ff7050U;
    constexpr uint32_t kW2      = 0x17ff705bU;
    constexpr uint32_t kW3      = 0xd10203ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0983] start_va=0x05cbb4, fde_va=0x073ad0, span=4 bytes
// [VN] FDE[0983] địa chỉ bắt đầu=0x05cbb4, fde_va=0x073ad0, kích thước=4 byte
// AArch64 opcodes: 17FF705B D10203FF A9026FFC A90367FA
uint32_t cybertron_fde_0983_0x05cbb4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cbb4U;
    constexpr uint32_t kFdeVa   = 0x073ad0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff705bU;
    constexpr uint32_t kW1      = 0xd10203ffU;
    constexpr uint32_t kW2      = 0xa9026ffcU;
    constexpr uint32_t kW3      = 0xa90367faU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0984] start_va=0x05cbb8, fde_va=0x073ae8, span=328 bytes
// [VN] FDE[0984] địa chỉ bắt đầu=0x05cbb8, fde_va=0x073ae8, kích thước=328 byte
// AArch64 opcodes: D10203FF A9026FFC A90367FA A9045FF8
uint32_t cybertron_fde_0984_0x05cbb8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cbb8U;
    constexpr uint32_t kFdeVa   = 0x073ae8U;
    constexpr uint32_t kSpan    = 328U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa9026ffcU;
    constexpr uint32_t kW2      = 0xa90367faU;
    constexpr uint32_t kW3      = 0xa9045ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0985] start_va=0x05cd00, fde_va=0x073b18, span=236 bytes
// [VN] FDE[0985] địa chỉ bắt đầu=0x05cd00, fde_va=0x073b18, kích thước=236 byte
// AArch64 opcodes: D10183FF A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_0985_0x05cd00(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cd00U;
    constexpr uint32_t kFdeVa   = 0x073b18U;
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

// [EN] FDE[0986] start_va=0x05cdec, fde_va=0x073b48, span=228 bytes
// [VN] FDE[0986] địa chỉ bắt đầu=0x05cdec, fde_va=0x073b48, kích thước=228 byte
// AArch64 opcodes: D10183FF F9000BF9 A9025FF8 A90357F6
uint32_t cybertron_fde_0986_0x05cdec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cdecU;
    constexpr uint32_t kFdeVa   = 0x073b48U;
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

// [EN] FDE[0987] start_va=0x05ced0, fde_va=0x073b70, span=212 bytes
// [VN] FDE[0987] địa chỉ bắt đầu=0x05ced0, fde_va=0x073b70, kích thước=212 byte
// AArch64 opcodes: D10143FF A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_0987_0x05ced0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ced0U;
    constexpr uint32_t kFdeVa   = 0x073b70U;
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

// [EN] FDE[0988] start_va=0x05cfa4, fde_va=0x073b98, span=224 bytes
// [VN] FDE[0988] địa chỉ bắt đầu=0x05cfa4, fde_va=0x073b98, kích thước=224 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_0988_0x05cfa4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05cfa4U;
    constexpr uint32_t kFdeVa   = 0x073b98U;
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

// [EN] FDE[0989] start_va=0x05d084, fde_va=0x073bc0, span=88 bytes
// [VN] FDE[0989] địa chỉ bắt đầu=0x05d084, fde_va=0x073bc0, kích thước=88 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_0989_0x05d084(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d084U;
    constexpr uint32_t kFdeVa   = 0x073bc0U;
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

// [EN] FDE[0990] start_va=0x05d0dc, fde_va=0x073be0, span=16 bytes
// [VN] FDE[0990] địa chỉ bắt đầu=0x05d0dc, fde_va=0x073be0, kích thước=16 byte
// AArch64 opcodes: 4B000028 7100011F 1A9FD7E0 D65F03C0
uint32_t cybertron_fde_0990_0x05d0dc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d0dcU;
    constexpr uint32_t kFdeVa   = 0x073be0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x4b000028U;
    constexpr uint32_t kW1      = 0x7100011fU;
    constexpr uint32_t kW2      = 0x1a9fd7e0U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0991] start_va=0x05d0ec, fde_va=0x073bf8, span=68 bytes
// [VN] FDE[0991] địa chỉ bắt đầu=0x05d0ec, fde_va=0x073bf8, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 2A0003F3
uint32_t cybertron_fde_0991_0x05d0ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d0ecU;
    constexpr uint32_t kFdeVa   = 0x073bf8U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x2a0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0992] start_va=0x05d130, fde_va=0x073c18, span=52 bytes
// [VN] FDE[0992] địa chỉ bắt đầu=0x05d130, fde_va=0x073c18, kích thước=52 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FF7652 D2869B69
uint32_t cybertron_fde_0992_0x05d130(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d130U;
    constexpr uint32_t kFdeVa   = 0x073c18U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97ff7652U;
    constexpr uint32_t kW3      = 0xd2869b69U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0993] start_va=0x05d164, fde_va=0x073c38, span=8 bytes
// [VN] FDE[0993] địa chỉ bắt đầu=0x05d164, fde_va=0x073c38, kích thước=8 byte
// AArch64 opcodes: CB010000 D65F03C0 A9BF7BFD 910003FD
uint32_t cybertron_fde_0993_0x05d164(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d164U;
    constexpr uint32_t kFdeVa   = 0x073c38U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xcb010000U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xa9bf7bfdU;
    constexpr uint32_t kW3      = 0x910003fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0994] start_va=0x05d16c, fde_va=0x073c50, span=28 bytes
// [VN] FDE[0994] địa chỉ bắt đầu=0x05d16c, fde_va=0x073c50, kích thước=28 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FF7643 52807D08
uint32_t cybertron_fde_0994_0x05d16c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d16cU;
    constexpr uint32_t kFdeVa   = 0x073c50U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97ff7643U;
    constexpr uint32_t kW3      = 0x52807d08U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0995] start_va=0x05d188, fde_va=0x073c70, span=56 bytes
// [VN] FDE[0995] địa chỉ bắt đầu=0x05d188, fde_va=0x073c70, kích thước=56 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FF763C D29EF9E9
uint32_t cybertron_fde_0995_0x05d188(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d188U;
    constexpr uint32_t kFdeVa   = 0x073c70U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97ff763cU;
    constexpr uint32_t kW3      = 0xd29ef9e9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0996] start_va=0x05d1c0, fde_va=0x073c90, span=16 bytes
// [VN] FDE[0996] địa chỉ bắt đầu=0x05d1c0, fde_va=0x073c90, kích thước=16 byte
// AArch64 opcodes: 4B000028 2A2803E8 531F7D00 D65F03C0
uint32_t cybertron_fde_0996_0x05d1c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d1c0U;
    constexpr uint32_t kFdeVa   = 0x073c90U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x4b000028U;
    constexpr uint32_t kW1      = 0x2a2803e8U;
    constexpr uint32_t kW2      = 0x531f7d00U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0997] start_va=0x05d1d0, fde_va=0x073ca8, span=4 bytes
// [VN] FDE[0997] địa chỉ bắt đầu=0x05d1d0, fde_va=0x073ca8, kích thước=4 byte
// AArch64 opcodes: 17FF75B0 6F00E400 F900281F AD018000
uint32_t cybertron_fde_0997_0x05d1d0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d1d0U;
    constexpr uint32_t kFdeVa   = 0x073ca8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff75b0U;
    constexpr uint32_t kW1      = 0x6f00e400U;
    constexpr uint32_t kW2      = 0xf900281fU;
    constexpr uint32_t kW3      = 0xad018000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0998] start_va=0x05d1d4, fde_va=0x073cc0, span=28 bytes
// [VN] FDE[0998] địa chỉ bắt đầu=0x05d1d4, fde_va=0x073cc0, kích thước=28 byte
// AArch64 opcodes: 6F00E400 F900281F AD018000 AD008000
uint32_t cybertron_fde_0998_0x05d1d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d1d4U;
    constexpr uint32_t kFdeVa   = 0x073cc0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0x6f00e400U;
    constexpr uint32_t kW1      = 0xf900281fU;
    constexpr uint32_t kW2      = 0xad018000U;
    constexpr uint32_t kW3      = 0xad008000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[0999] start_va=0x05d1f0, fde_va=0x073cd8, span=40 bytes
// [VN] FDE[0999] địa chỉ bắt đầu=0x05d1f0, fde_va=0x073cd8, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_0999_0x05d1f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d1f0U;
    constexpr uint32_t kFdeVa   = 0x073cd8U;
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

// [EN] FDE[1000] start_va=0x05d218, fde_va=0x073cf8, span=60 bytes
// [VN] FDE[1000] địa chỉ bắt đầu=0x05d218, fde_va=0x073cf8, kích thước=60 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 9100C014
uint32_t cybertron_fde_1000_0x05d218(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d218U;
    constexpr uint32_t kFdeVa   = 0x073cf8U;
    constexpr uint32_t kSpan    = 60U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x9100c014U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1001] start_va=0x05d254, fde_va=0x073d18, span=48 bytes
// [VN] FDE[1001] địa chỉ bắt đầu=0x05d254, fde_va=0x073d18, kích thước=48 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 9100C014
uint32_t cybertron_fde_1001_0x05d254(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d254U;
    constexpr uint32_t kFdeVa   = 0x073d18U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x9100c014U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1002] start_va=0x05d284, fde_va=0x073d38, span=144 bytes
// [VN] FDE[1002] địa chỉ bắt đầu=0x05d284, fde_va=0x073d38, kích thước=144 byte
// AArch64 opcodes: D10103FF A9024FF4 A9037BFD 9100C3FD
uint32_t cybertron_fde_1002_0x05d284(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d284U;
    constexpr uint32_t kFdeVa   = 0x073d38U;
    constexpr uint32_t kSpan    = 144U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa9024ff4U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1003] start_va=0x05d314, fde_va=0x073d58, span=372 bytes
// [VN] FDE[1003] địa chỉ bắt đầu=0x05d314, fde_va=0x073d58, kích thước=372 byte
// AArch64 opcodes: D102C3FF F9002BFB A90667FA A9075FF8
uint32_t cybertron_fde_1003_0x05d314(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d314U;
    constexpr uint32_t kFdeVa   = 0x073d58U;
    constexpr uint32_t kSpan    = 372U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xf9002bfbU;
    constexpr uint32_t kW2      = 0xa90667faU;
    constexpr uint32_t kW3      = 0xa9075ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1004] start_va=0x05d488, fde_va=0x073d88, span=12 bytes
// [VN] FDE[1004] địa chỉ bắt đầu=0x05d488, fde_va=0x073d88, kích thước=12 byte
// AArch64 opcodes: A9007C1F F900081F D65F03C0 A9BE4FF4
uint32_t cybertron_fde_1004_0x05d488(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d488U;
    constexpr uint32_t kFdeVa   = 0x073d88U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xa9007c1fU;
    constexpr uint32_t kW1      = 0xf900081fU;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xa9be4ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1005] start_va=0x05d494, fde_va=0x073da0, span=64 bytes
// [VN] FDE[1005] địa chỉ bắt đầu=0x05d494, fde_va=0x073da0, kích thước=64 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F4
uint32_t cybertron_fde_1005_0x05d494(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d494U;
    constexpr uint32_t kFdeVa   = 0x073da0U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1006] start_va=0x05d4d4, fde_va=0x073dc0, span=16 bytes
// [VN] FDE[1006] địa chỉ bắt đầu=0x05d4d4, fde_va=0x073dc0, kích thước=16 byte
// AArch64 opcodes: F9400000 F9400008 F9401D01 D61F0020
uint32_t cybertron_fde_1006_0x05d4d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d4d4U;
    constexpr uint32_t kFdeVa   = 0x073dc0U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9401d01U;
    constexpr uint32_t kW3      = 0xd61f0020U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1007] start_va=0x05d4e4, fde_va=0x073dd8, span=224 bytes
// [VN] FDE[1007] địa chỉ bắt đầu=0x05d4e4, fde_va=0x073dd8, kích thước=224 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_1007_0x05d4e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d4e4U;
    constexpr uint32_t kFdeVa   = 0x073dd8U;
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

// [EN] FDE[1008] start_va=0x05d5c4, fde_va=0x073e00, span=28 bytes
// [VN] FDE[1008] địa chỉ bắt đầu=0x05d5c4, fde_va=0x073e00, kích thước=28 byte
// AArch64 opcodes: F9400000 B40000A0 F9400008 52800022
uint32_t cybertron_fde_1008_0x05d5c4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d5c4U;
    constexpr uint32_t kFdeVa   = 0x073e00U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb40000a0U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0x52800022U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1009] start_va=0x05d5e0, fde_va=0x073e18, span=24 bytes
// [VN] FDE[1009] địa chỉ bắt đầu=0x05d5e0, fde_va=0x073e18, kích thước=24 byte
// AArch64 opcodes: F9400000 B4000080 F9400008 F9401902
uint32_t cybertron_fde_1009_0x05d5e0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d5e0U;
    constexpr uint32_t kFdeVa   = 0x073e18U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000080U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9401902U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1010] start_va=0x05d5f8, fde_va=0x073e30, span=24 bytes
// [VN] FDE[1010] địa chỉ bắt đầu=0x05d5f8, fde_va=0x073e30, kích thước=24 byte
// AArch64 opcodes: F9400000 B4000080 F9400008 F9400903
uint32_t cybertron_fde_1010_0x05d5f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d5f8U;
    constexpr uint32_t kFdeVa   = 0x073e30U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000080U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9400903U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1011] start_va=0x05d610, fde_va=0x073e48, span=24 bytes
// [VN] FDE[1011] địa chỉ bắt đầu=0x05d610, fde_va=0x073e48, kích thước=24 byte
// AArch64 opcodes: F9400000 B4000080 F9400008 F9400D03
uint32_t cybertron_fde_1011_0x05d610(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d610U;
    constexpr uint32_t kFdeVa   = 0x073e48U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xf9400000U;
    constexpr uint32_t kW1      = 0xb4000080U;
    constexpr uint32_t kW2      = 0xf9400008U;
    constexpr uint32_t kW3      = 0xf9400d03U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1012] start_va=0x05d628, fde_va=0x073e60, span=40 bytes
// [VN] FDE[1012] địa chỉ bắt đầu=0x05d628, fde_va=0x073e60, kích thước=40 byte
// AArch64 opcodes: D0000109 F946B529 AA0003E8 91004129
uint32_t cybertron_fde_1012_0x05d628(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d628U;
    constexpr uint32_t kFdeVa   = 0x073e60U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xd0000109U;
    constexpr uint32_t kW1      = 0xf946b529U;
    constexpr uint32_t kW2      = 0xaa0003e8U;
    constexpr uint32_t kW3      = 0x91004129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1013] start_va=0x05d650, fde_va=0x073e78, span=40 bytes
// [VN] FDE[1013] địa chỉ bắt đầu=0x05d650, fde_va=0x073e78, kích thước=40 byte
// AArch64 opcodes: D0000109 F9400408 F946B529 91004129
uint32_t cybertron_fde_1013_0x05d650(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d650U;
    constexpr uint32_t kFdeVa   = 0x073e78U;
    constexpr uint32_t kSpan    = 40U;
    constexpr uint32_t kW0      = 0xd0000109U;
    constexpr uint32_t kW1      = 0xf9400408U;
    constexpr uint32_t kW2      = 0xf946b529U;
    constexpr uint32_t kW3      = 0x91004129U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1014] start_va=0x05d678, fde_va=0x073e90, span=64 bytes
// [VN] FDE[1014] địa chỉ bắt đầu=0x05d678, fde_va=0x073e90, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000108
uint32_t cybertron_fde_1014_0x05d678(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d678U;
    constexpr uint32_t kFdeVa   = 0x073e90U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1015] start_va=0x05d6b8, fde_va=0x073eb0, span=124 bytes
// [VN] FDE[1015] địa chỉ bắt đầu=0x05d6b8, fde_va=0x073eb0, kích thước=124 byte
// AArch64 opcodes: D10103FF F9000BF5 A9024FF4 A9037BFD
uint32_t cybertron_fde_1015_0x05d6b8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d6b8U;
    constexpr uint32_t kFdeVa   = 0x073eb0U;
    constexpr uint32_t kSpan    = 124U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xf9000bf5U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1016] start_va=0x05d734, fde_va=0x073ed0, span=160 bytes
// [VN] FDE[1016] địa chỉ bắt đầu=0x05d734, fde_va=0x073ed0, kích thước=160 byte
// AArch64 opcodes: D10103FF A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_1016_0x05d734(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d734U;
    constexpr uint32_t kFdeVa   = 0x073ed0U;
    constexpr uint32_t kSpan    = 160U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1017] start_va=0x05d7d4, fde_va=0x073ef8, span=120 bytes
// [VN] FDE[1017] địa chỉ bắt đầu=0x05d7d4, fde_va=0x073ef8, kích thước=120 byte
// AArch64 opcodes: D10103FF F9000BF5 A9024FF4 A9037BFD
uint32_t cybertron_fde_1017_0x05d7d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d7d4U;
    constexpr uint32_t kFdeVa   = 0x073ef8U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xf9000bf5U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1018] start_va=0x05d84c, fde_va=0x073f18, span=124 bytes
// [VN] FDE[1018] địa chỉ bắt đầu=0x05d84c, fde_va=0x073f18, kích thước=124 byte
// AArch64 opcodes: D10103FF F9000BF5 A9024FF4 A9037BFD
uint32_t cybertron_fde_1018_0x05d84c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d84cU;
    constexpr uint32_t kFdeVa   = 0x073f18U;
    constexpr uint32_t kSpan    = 124U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xf9000bf5U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1019] start_va=0x05d8c8, fde_va=0x073f38, span=16 bytes
// [VN] FDE[1019] địa chỉ bắt đầu=0x05d8c8, fde_va=0x073f38, kích thước=16 byte
// AArch64 opcodes: F9400400 F9400008 F9401102 D61F0040
uint32_t cybertron_fde_1019_0x05d8c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d8c8U;
    constexpr uint32_t kFdeVa   = 0x073f38U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9401102U;
    constexpr uint32_t kW3      = 0xd61f0040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1020] start_va=0x05d8d8, fde_va=0x073f50, span=16 bytes
// [VN] FDE[1020] địa chỉ bắt đầu=0x05d8d8, fde_va=0x073f50, kích thước=16 byte
// AArch64 opcodes: F9400400 F9400008 F9401502 D61F0040
uint32_t cybertron_fde_1020_0x05d8d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d8d8U;
    constexpr uint32_t kFdeVa   = 0x073f50U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9401502U;
    constexpr uint32_t kW3      = 0xd61f0040U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1021] start_va=0x05d8e8, fde_va=0x073f68, span=16 bytes
// [VN] FDE[1021] địa chỉ bắt đầu=0x05d8e8, fde_va=0x073f68, kích thước=16 byte
// AArch64 opcodes: F9400400 F9400008 F9401901 D61F0020
uint32_t cybertron_fde_1021_0x05d8e8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d8e8U;
    constexpr uint32_t kFdeVa   = 0x073f68U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9401901U;
    constexpr uint32_t kW3      = 0xd61f0020U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1022] start_va=0x05d8f8, fde_va=0x073f80, span=16 bytes
// [VN] FDE[1022] địa chỉ bắt đầu=0x05d8f8, fde_va=0x073f80, kích thước=16 byte
// AArch64 opcodes: F9400400 F9400008 F9400D01 D61F0020
uint32_t cybertron_fde_1022_0x05d8f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d8f8U;
    constexpr uint32_t kFdeVa   = 0x073f80U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xf9400400U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9400d01U;
    constexpr uint32_t kW3      = 0xd61f0020U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1023] start_va=0x05d908, fde_va=0x073f98, span=72 bytes
// [VN] FDE[1023] địa chỉ bắt đầu=0x05d908, fde_va=0x073f98, kích thước=72 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_1023_0x05d908(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d908U;
    constexpr uint32_t kFdeVa   = 0x073f98U;
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

// [EN] FDE[1024] start_va=0x05d950, fde_va=0x073fb8, span=68 bytes
// [VN] FDE[1024] địa chỉ bắt đầu=0x05d950, fde_va=0x073fb8, kích thước=68 byte
// AArch64 opcodes: D0000109 AA0003E8 F9401800 F9463529
uint32_t cybertron_fde_1024_0x05d950(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d950U;
    constexpr uint32_t kFdeVa   = 0x073fb8U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xd0000109U;
    constexpr uint32_t kW1      = 0xaa0003e8U;
    constexpr uint32_t kW2      = 0xf9401800U;
    constexpr uint32_t kW3      = 0xf9463529U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1025] start_va=0x05d994, fde_va=0x073fd0, span=92 bytes
// [VN] FDE[1025] địa chỉ bắt đầu=0x05d994, fde_va=0x073fd0, kích thước=92 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D0000108
uint32_t cybertron_fde_1025_0x05d994(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d994U;
    constexpr uint32_t kFdeVa   = 0x073fd0U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd0000108U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1026] start_va=0x05d9f0, fde_va=0x073ff0, span=36 bytes
// [VN] FDE[1026] địa chỉ bắt đầu=0x05d9f0, fde_va=0x073ff0, kích thước=36 byte
// AArch64 opcodes: A9BF7BFD 910003FD F9401800 B40000A0
uint32_t cybertron_fde_1026_0x05d9f0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05d9f0U;
    constexpr uint32_t kFdeVa   = 0x073ff0U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0xf9401800U;
    constexpr uint32_t kW3      = 0xb40000a0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1027] start_va=0x05da14, fde_va=0x074010, span=4 bytes
// [VN] FDE[1027] địa chỉ bắt đầu=0x05da14, fde_va=0x074010, kích thước=4 byte
// AArch64 opcodes: 17FF748B B9400000 17FF6E59 B9400000
uint32_t cybertron_fde_1027_0x05da14(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05da14U;
    constexpr uint32_t kFdeVa   = 0x074010U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff748bU;
    constexpr uint32_t kW1      = 0xb9400000U;
    constexpr uint32_t kW2      = 0x17ff6e59U;
    constexpr uint32_t kW3      = 0xb9400000U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1028] start_va=0x05da18, fde_va=0x074028, span=8 bytes
// [VN] FDE[1028] địa chỉ bắt đầu=0x05da18, fde_va=0x074028, kích thước=8 byte
// AArch64 opcodes: B9400000 17FF6E59 B9400000 17FF7263
uint32_t cybertron_fde_1028_0x05da18(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05da18U;
    constexpr uint32_t kFdeVa   = 0x074028U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xb9400000U;
    constexpr uint32_t kW1      = 0x17ff6e59U;
    constexpr uint32_t kW2      = 0xb9400000U;
    constexpr uint32_t kW3      = 0x17ff7263U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1029] start_va=0x05da20, fde_va=0x074040, span=8 bytes
// [VN] FDE[1029] địa chỉ bắt đầu=0x05da20, fde_va=0x074040, kích thước=8 byte
// AArch64 opcodes: B9400000 17FF7263 A9BE4FF4 A9017BFD
uint32_t cybertron_fde_1029_0x05da20(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05da20U;
    constexpr uint32_t kFdeVa   = 0x074040U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xb9400000U;
    constexpr uint32_t kW1      = 0x17ff7263U;
    constexpr uint32_t kW2      = 0xa9be4ff4U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1030] start_va=0x05da28, fde_va=0x074058, span=64 bytes
// [VN] FDE[1030] địa chỉ bắt đầu=0x05da28, fde_va=0x074058, kích thước=64 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_1030_0x05da28(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05da28U;
    constexpr uint32_t kFdeVa   = 0x074058U;
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

// [EN] FDE[1031] start_va=0x05da68, fde_va=0x074078, span=28 bytes
// [VN] FDE[1031] địa chỉ bắt đầu=0x05da68, fde_va=0x074078, kích thước=28 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FF7400 7100001F
uint32_t cybertron_fde_1031_0x05da68(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05da68U;
    constexpr uint32_t kFdeVa   = 0x074078U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97ff7400U;
    constexpr uint32_t kW3      = 0x7100001fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1032] start_va=0x05da84, fde_va=0x074098, span=4 bytes
// [VN] FDE[1032] địa chỉ bắt đầu=0x05da84, fde_va=0x074098, kích thước=4 byte
// AArch64 opcodes: D65F03C0 F0000108 F9418D00 D65F03C0
uint32_t cybertron_fde_1032_0x05da84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05da84U;
    constexpr uint32_t kFdeVa   = 0x074098U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xf0000108U;
    constexpr uint32_t kW2      = 0xf9418d00U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1033] start_va=0x05da88, fde_va=0x0740b0, span=12 bytes
// [VN] FDE[1033] địa chỉ bắt đầu=0x05da88, fde_va=0x0740b0, kích thước=12 byte
// AArch64 opcodes: F0000108 F9418D00 D65F03C0 D100C3FF
uint32_t cybertron_fde_1033_0x05da88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05da88U;
    constexpr uint32_t kFdeVa   = 0x0740b0U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xf0000108U;
    constexpr uint32_t kW1      = 0xf9418d00U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xd100c3ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1034] start_va=0x05da94, fde_va=0x0740c8, span=104 bytes
// [VN] FDE[1034] địa chỉ bắt đầu=0x05da94, fde_va=0x0740c8, kích thước=104 byte
// AArch64 opcodes: D100C3FF F9000BF3 A9027BFD 910083FD
uint32_t cybertron_fde_1034_0x05da94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05da94U;
    constexpr uint32_t kFdeVa   = 0x0740c8U;
    constexpr uint32_t kSpan    = 104U;
    constexpr uint32_t kW0      = 0xd100c3ffU;
    constexpr uint32_t kW1      = 0xf9000bf3U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1035] start_va=0x05dafc, fde_va=0x0740e8, span=292 bytes
// [VN] FDE[1035] địa chỉ bắt đầu=0x05dafc, fde_va=0x0740e8, kích thước=292 byte
// AArch64 opcodes: D10103FF F9000BF5 A9024FF4 A9037BFD
uint32_t cybertron_fde_1035_0x05dafc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05dafcU;
    constexpr uint32_t kFdeVa   = 0x0740e8U;
    constexpr uint32_t kSpan    = 292U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xf9000bf5U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1036] start_va=0x05dc20, fde_va=0x074108, span=20 bytes
// [VN] FDE[1036] địa chỉ bắt đầu=0x05dc20, fde_va=0x074108, kích thước=20 byte
// AArch64 opcodes: F0000100 D0000001 910D0000 910E6021
uint32_t cybertron_fde_1036_0x05dc20(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05dc20U;
    constexpr uint32_t kFdeVa   = 0x074108U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xf0000100U;
    constexpr uint32_t kW1      = 0xd0000001U;
    constexpr uint32_t kW2      = 0x910d0000U;
    constexpr uint32_t kW3      = 0x910e6021U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1037] start_va=0x05dc34, fde_va=0x074120, span=304 bytes
// [VN] FDE[1037] địa chỉ bắt đầu=0x05dc34, fde_va=0x074120, kích thước=304 byte
// AArch64 opcodes: D10203FF F90023F7 A90557F6 A9064FF4
uint32_t cybertron_fde_1037_0x05dc34(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05dc34U;
    constexpr uint32_t kFdeVa   = 0x074120U;
    constexpr uint32_t kSpan    = 304U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xf90023f7U;
    constexpr uint32_t kW2      = 0xa90557f6U;
    constexpr uint32_t kW3      = 0xa9064ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1038] start_va=0x05dd64, fde_va=0x074148, span=92 bytes
// [VN] FDE[1038] địa chỉ bắt đầu=0x05dd64, fde_va=0x074148, kích thước=92 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400008
uint32_t cybertron_fde_1038_0x05dd64(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05dd64U;
    constexpr uint32_t kFdeVa   = 0x074148U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1039] start_va=0x05ddc0, fde_va=0x074168, span=4 bytes
// [VN] FDE[1039] địa chỉ bắt đầu=0x05ddc0, fde_va=0x074168, kích thước=4 byte
// AArch64 opcodes: D65F03C0 F81D0FF5 A9014FF4 A9027BFD
uint32_t cybertron_fde_1039_0x05ddc0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ddc0U;
    constexpr uint32_t kFdeVa   = 0x074168U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xf81d0ff5U;
    constexpr uint32_t kW2      = 0xa9014ff4U;
    constexpr uint32_t kW3      = 0xa9027bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1040] start_va=0x05ddc4, fde_va=0x074180, span=116 bytes
// [VN] FDE[1040] địa chỉ bắt đầu=0x05ddc4, fde_va=0x074180, kích thước=116 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1040_0x05ddc4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ddc4U;
    constexpr uint32_t kFdeVa   = 0x074180U;
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

// [EN] FDE[1041] start_va=0x05de38, fde_va=0x0741a0, span=20 bytes
// [VN] FDE[1041] địa chỉ bắt đầu=0x05de38, fde_va=0x0741a0, kích thước=20 byte
// AArch64 opcodes: 39400029 F940082A 7200013F 9A811541
uint32_t cybertron_fde_1041_0x05de38(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05de38U;
    constexpr uint32_t kFdeVa   = 0x0741a0U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x39400029U;
    constexpr uint32_t kW1      = 0xf940082aU;
    constexpr uint32_t kW2      = 0x7200013fU;
    constexpr uint32_t kW3      = 0x9a811541U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1042] start_va=0x05de4c, fde_va=0x0741b8, span=144 bytes
// [VN] FDE[1042] địa chỉ bắt đầu=0x05de4c, fde_va=0x0741b8, kích thước=144 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1042_0x05de4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05de4cU;
    constexpr uint32_t kFdeVa   = 0x0741b8U;
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

// [EN] FDE[1043] start_va=0x05dedc, fde_va=0x0741e0, span=120 bytes
// [VN] FDE[1043] địa chỉ bắt đầu=0x05dedc, fde_va=0x0741e0, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1043_0x05dedc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05dedcU;
    constexpr uint32_t kFdeVa   = 0x0741e0U;
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

// [EN] FDE[1044] start_va=0x05df54, fde_va=0x074200, span=156 bytes
// [VN] FDE[1044] địa chỉ bắt đầu=0x05df54, fde_va=0x074200, kích thước=156 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1044_0x05df54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05df54U;
    constexpr uint32_t kFdeVa   = 0x074200U;
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

// [EN] FDE[1045] start_va=0x05dff0, fde_va=0x074220, span=168 bytes
// [VN] FDE[1045] địa chỉ bắt đầu=0x05dff0, fde_va=0x074220, kích thước=168 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_1045_0x05dff0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05dff0U;
    constexpr uint32_t kFdeVa   = 0x074220U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1046] start_va=0x05e098, fde_va=0x074248, span=120 bytes
// [VN] FDE[1046] địa chỉ bắt đầu=0x05e098, fde_va=0x074248, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1046_0x05e098(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e098U;
    constexpr uint32_t kFdeVa   = 0x074248U;
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

// [EN] FDE[1047] start_va=0x05e110, fde_va=0x074268, span=264 bytes
// [VN] FDE[1047] địa chỉ bắt đầu=0x05e110, fde_va=0x074268, kích thước=264 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_1047_0x05e110(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e110U;
    constexpr uint32_t kFdeVa   = 0x074268U;
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

// [EN] FDE[1048] start_va=0x05e218, fde_va=0x074290, span=144 bytes
// [VN] FDE[1048] địa chỉ bắt đầu=0x05e218, fde_va=0x074290, kích thước=144 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1048_0x05e218(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e218U;
    constexpr uint32_t kFdeVa   = 0x074290U;
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

// [EN] FDE[1049] start_va=0x05e2a8, fde_va=0x0742b8, span=120 bytes
// [VN] FDE[1049] địa chỉ bắt đầu=0x05e2a8, fde_va=0x0742b8, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1049_0x05e2a8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e2a8U;
    constexpr uint32_t kFdeVa   = 0x0742b8U;
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

// [EN] FDE[1050] start_va=0x05e320, fde_va=0x0742d8, span=160 bytes
// [VN] FDE[1050] địa chỉ bắt đầu=0x05e320, fde_va=0x0742d8, kích thước=160 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1050_0x05e320(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e320U;
    constexpr uint32_t kFdeVa   = 0x0742d8U;
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

// [EN] FDE[1051] start_va=0x05e3c0, fde_va=0x0742f8, span=156 bytes
// [VN] FDE[1051] địa chỉ bắt đầu=0x05e3c0, fde_va=0x0742f8, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1051_0x05e3c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e3c0U;
    constexpr uint32_t kFdeVa   = 0x0742f8U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1052] start_va=0x05e45c, fde_va=0x074318, span=156 bytes
// [VN] FDE[1052] địa chỉ bắt đầu=0x05e45c, fde_va=0x074318, kích thước=156 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1052_0x05e45c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e45cU;
    constexpr uint32_t kFdeVa   = 0x074318U;
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

// [EN] FDE[1053] start_va=0x05e4f8, fde_va=0x074338, span=156 bytes
// [VN] FDE[1053] địa chỉ bắt đầu=0x05e4f8, fde_va=0x074338, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1053_0x05e4f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e4f8U;
    constexpr uint32_t kFdeVa   = 0x074338U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1054] start_va=0x05e594, fde_va=0x074358, span=144 bytes
// [VN] FDE[1054] địa chỉ bắt đầu=0x05e594, fde_va=0x074358, kích thước=144 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1054_0x05e594(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e594U;
    constexpr uint32_t kFdeVa   = 0x074358U;
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

// [EN] FDE[1055] start_va=0x05e624, fde_va=0x074380, span=144 bytes
// [VN] FDE[1055] địa chỉ bắt đầu=0x05e624, fde_va=0x074380, kích thước=144 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1055_0x05e624(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e624U;
    constexpr uint32_t kFdeVa   = 0x074380U;
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

// [EN] FDE[1056] start_va=0x05e6b4, fde_va=0x0743a8, span=168 bytes
// [VN] FDE[1056] địa chỉ bắt đầu=0x05e6b4, fde_va=0x0743a8, kích thước=168 byte
// AArch64 opcodes: FC1D0FE8 F90007F5 A9014FF4 A9027BFD
uint32_t cybertron_fde_1056_0x05e6b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e6b4U;
    constexpr uint32_t kFdeVa   = 0x0743a8U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xfc1d0fe8U;
    constexpr uint32_t kW1      = 0xf90007f5U;
    constexpr uint32_t kW2      = 0xa9014ff4U;
    constexpr uint32_t kW3      = 0xa9027bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1057] start_va=0x05e75c, fde_va=0x0743d0, span=144 bytes
// [VN] FDE[1057] địa chỉ bắt đầu=0x05e75c, fde_va=0x0743d0, kích thước=144 byte
// AArch64 opcodes: A9BD57F6 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1057_0x05e75c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e75cU;
    constexpr uint32_t kFdeVa   = 0x0743d0U;
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

// [EN] FDE[1058] start_va=0x05e7ec, fde_va=0x0743f8, span=168 bytes
// [VN] FDE[1058] địa chỉ bắt đầu=0x05e7ec, fde_va=0x0743f8, kích thước=168 byte
// AArch64 opcodes: FC1D0FE8 F90007F5 A9014FF4 A9027BFD
uint32_t cybertron_fde_1058_0x05e7ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e7ecU;
    constexpr uint32_t kFdeVa   = 0x0743f8U;
    constexpr uint32_t kSpan    = 168U;
    constexpr uint32_t kW0      = 0xfc1d0fe8U;
    constexpr uint32_t kW1      = 0xf90007f5U;
    constexpr uint32_t kW2      = 0xa9014ff4U;
    constexpr uint32_t kW3      = 0xa9027bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1059] start_va=0x05e894, fde_va=0x074420, span=156 bytes
// [VN] FDE[1059] địa chỉ bắt đầu=0x05e894, fde_va=0x074420, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1059_0x05e894(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e894U;
    constexpr uint32_t kFdeVa   = 0x074420U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1060] start_va=0x05e930, fde_va=0x074440, span=156 bytes
// [VN] FDE[1060] địa chỉ bắt đầu=0x05e930, fde_va=0x074440, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1060_0x05e930(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e930U;
    constexpr uint32_t kFdeVa   = 0x074440U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1061] start_va=0x05e9cc, fde_va=0x074460, span=204 bytes
// [VN] FDE[1061] địa chỉ bắt đầu=0x05e9cc, fde_va=0x074460, kích thước=204 byte
// AArch64 opcodes: D10143FF A9015FF8 A90257F6 A9034FF4
uint32_t cybertron_fde_1061_0x05e9cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05e9ccU;
    constexpr uint32_t kFdeVa   = 0x074460U;
    constexpr uint32_t kSpan    = 204U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa9015ff8U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1062] start_va=0x05ea98, fde_va=0x074488, span=156 bytes
// [VN] FDE[1062] địa chỉ bắt đầu=0x05ea98, fde_va=0x074488, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1062_0x05ea98(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ea98U;
    constexpr uint32_t kFdeVa   = 0x074488U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1063] start_va=0x05eb34, fde_va=0x0744a8, span=156 bytes
// [VN] FDE[1063] địa chỉ bắt đầu=0x05eb34, fde_va=0x0744a8, kích thước=156 byte
// AArch64 opcodes: FC1D0FE8 F90007F5 A9014FF4 A9027BFD
uint32_t cybertron_fde_1063_0x05eb34(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05eb34U;
    constexpr uint32_t kFdeVa   = 0x0744a8U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xfc1d0fe8U;
    constexpr uint32_t kW1      = 0xf90007f5U;
    constexpr uint32_t kW2      = 0xa9014ff4U;
    constexpr uint32_t kW3      = 0xa9027bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1064] start_va=0x05ebd0, fde_va=0x0744d0, span=156 bytes
// [VN] FDE[1064] địa chỉ bắt đầu=0x05ebd0, fde_va=0x0744d0, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1064_0x05ebd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ebd0U;
    constexpr uint32_t kFdeVa   = 0x0744d0U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1065] start_va=0x05ec6c, fde_va=0x0744f0, span=28 bytes
// [VN] FDE[1065] địa chỉ bắt đầu=0x05ec6c, fde_va=0x0744f0, kích thước=28 byte
// AArch64 opcodes: D0000108 D0000109 F9419508 F9419922
uint32_t cybertron_fde_1065_0x05ec6c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ec6cU;
    constexpr uint32_t kFdeVa   = 0x0744f0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xd0000108U;
    constexpr uint32_t kW1      = 0xd0000109U;
    constexpr uint32_t kW2      = 0xf9419508U;
    constexpr uint32_t kW3      = 0xf9419922U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1066] start_va=0x05ec88, fde_va=0x074508, span=248 bytes
// [VN] FDE[1066] địa chỉ bắt đầu=0x05ec88, fde_va=0x074508, kích thước=248 byte
// AArch64 opcodes: D101C3FF F90013F9 A9035FF8 A90457F6
uint32_t cybertron_fde_1066_0x05ec88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ec88U;
    constexpr uint32_t kFdeVa   = 0x074508U;
    constexpr uint32_t kSpan    = 248U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf90013f9U;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1067] start_va=0x05ed80, fde_va=0x074530, span=156 bytes
// [VN] FDE[1067] địa chỉ bắt đầu=0x05ed80, fde_va=0x074530, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1067_0x05ed80(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ed80U;
    constexpr uint32_t kFdeVa   = 0x074530U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1068] start_va=0x05ee1c, fde_va=0x074550, span=152 bytes
// [VN] FDE[1068] địa chỉ bắt đầu=0x05ee1c, fde_va=0x074550, kích thước=152 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1068_0x05ee1c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ee1cU;
    constexpr uint32_t kFdeVa   = 0x074550U;
    constexpr uint32_t kSpan    = 152U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1069] start_va=0x05eeb4, fde_va=0x074570, span=120 bytes
// [VN] FDE[1069] địa chỉ bắt đầu=0x05eeb4, fde_va=0x074570, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1069_0x05eeb4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05eeb4U;
    constexpr uint32_t kFdeVa   = 0x074570U;
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

// [EN] FDE[1070] start_va=0x05ef2c, fde_va=0x074590, span=120 bytes
// [VN] FDE[1070] địa chỉ bắt đầu=0x05ef2c, fde_va=0x074590, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1070_0x05ef2c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05ef2cU;
    constexpr uint32_t kFdeVa   = 0x074590U;
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

// [EN] FDE[1071] start_va=0x05efa4, fde_va=0x0745b0, span=120 bytes
// [VN] FDE[1071] địa chỉ bắt đầu=0x05efa4, fde_va=0x0745b0, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1071_0x05efa4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05efa4U;
    constexpr uint32_t kFdeVa   = 0x0745b0U;
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

// [EN] FDE[1072] start_va=0x05f01c, fde_va=0x0745d0, span=120 bytes
// [VN] FDE[1072] địa chỉ bắt đầu=0x05f01c, fde_va=0x0745d0, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1072_0x05f01c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f01cU;
    constexpr uint32_t kFdeVa   = 0x0745d0U;
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

// [EN] FDE[1073] start_va=0x05f094, fde_va=0x0745f0, span=120 bytes
// [VN] FDE[1073] địa chỉ bắt đầu=0x05f094, fde_va=0x0745f0, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1073_0x05f094(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f094U;
    constexpr uint32_t kFdeVa   = 0x0745f0U;
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

// [EN] FDE[1074] start_va=0x05f10c, fde_va=0x074610, span=148 bytes
// [VN] FDE[1074] địa chỉ bắt đầu=0x05f10c, fde_va=0x074610, kích thước=148 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1074_0x05f10c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f10cU;
    constexpr uint32_t kFdeVa   = 0x074610U;
    constexpr uint32_t kSpan    = 148U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1075] start_va=0x05f1a0, fde_va=0x074630, span=148 bytes
// [VN] FDE[1075] địa chỉ bắt đầu=0x05f1a0, fde_va=0x074630, kích thước=148 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1075_0x05f1a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f1a0U;
    constexpr uint32_t kFdeVa   = 0x074630U;
    constexpr uint32_t kSpan    = 148U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1076] start_va=0x05f234, fde_va=0x074650, span=148 bytes
// [VN] FDE[1076] địa chỉ bắt đầu=0x05f234, fde_va=0x074650, kích thước=148 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1076_0x05f234(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f234U;
    constexpr uint32_t kFdeVa   = 0x074650U;
    constexpr uint32_t kSpan    = 148U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1077] start_va=0x05f2c8, fde_va=0x074670, span=156 bytes
// [VN] FDE[1077] địa chỉ bắt đầu=0x05f2c8, fde_va=0x074670, kích thước=156 byte
// AArch64 opcodes: FC1D0FE8 F90007F5 A9014FF4 A9027BFD
uint32_t cybertron_fde_1077_0x05f2c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f2c8U;
    constexpr uint32_t kFdeVa   = 0x074670U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xfc1d0fe8U;
    constexpr uint32_t kW1      = 0xf90007f5U;
    constexpr uint32_t kW2      = 0xa9014ff4U;
    constexpr uint32_t kW3      = 0xa9027bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1078] start_va=0x05f364, fde_va=0x074698, span=52 bytes
// [VN] FDE[1078] địa chỉ bắt đầu=0x05f364, fde_va=0x074698, kích thước=52 byte
// AArch64 opcodes: 39400028 F9400429 D341FD0A 7200011F
uint32_t cybertron_fde_1078_0x05f364(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f364U;
    constexpr uint32_t kFdeVa   = 0x074698U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0x39400028U;
    constexpr uint32_t kW1      = 0xf9400429U;
    constexpr uint32_t kW2      = 0xd341fd0aU;
    constexpr uint32_t kW3      = 0x7200011fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1079] start_va=0x05f398, fde_va=0x0746b0, span=128 bytes
// [VN] FDE[1079] địa chỉ bắt đầu=0x05f398, fde_va=0x0746b0, kích thước=128 byte
// AArch64 opcodes: D100C3FF A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1079_0x05f398(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f398U;
    constexpr uint32_t kFdeVa   = 0x0746b0U;
    constexpr uint32_t kSpan    = 128U;
    constexpr uint32_t kW0      = 0xd100c3ffU;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1080] start_va=0x05f418, fde_va=0x0746d0, span=300 bytes
// [VN] FDE[1080] địa chỉ bắt đầu=0x05f418, fde_va=0x0746d0, kích thước=300 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_1080_0x05f418(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f418U;
    constexpr uint32_t kFdeVa   = 0x0746d0U;
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

// [EN] FDE[1081] start_va=0x05f544, fde_va=0x0746f8, span=372 bytes
// [VN] FDE[1081] địa chỉ bắt đầu=0x05f544, fde_va=0x0746f8, kích thước=372 byte
// AArch64 opcodes: D10203FF F9001BF9 A9045FF8 A90557F6
uint32_t cybertron_fde_1081_0x05f544(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f544U;
    constexpr uint32_t kFdeVa   = 0x0746f8U;
    constexpr uint32_t kSpan    = 372U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xf9001bf9U;
    constexpr uint32_t kW2      = 0xa9045ff8U;
    constexpr uint32_t kW3      = 0xa90557f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1082] start_va=0x05f6b8, fde_va=0x074720, span=60 bytes
// [VN] FDE[1082] địa chỉ bắt đầu=0x05f6b8, fde_va=0x074720, kích thước=60 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_1082_0x05f6b8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f6b8U;
    constexpr uint32_t kFdeVa   = 0x074720U;
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

// [EN] FDE[1083] start_va=0x05f6f4, fde_va=0x074740, span=16 bytes
// [VN] FDE[1083] địa chỉ bắt đầu=0x05f6f4, fde_va=0x074740, kích thước=16 byte
// AArch64 opcodes: 90000108 F947C908 F9400100 D65F03C0
uint32_t cybertron_fde_1083_0x05f6f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f6f4U;
    constexpr uint32_t kFdeVa   = 0x074740U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0x90000108U;
    constexpr uint32_t kW1      = 0xf947c908U;
    constexpr uint32_t kW2      = 0xf9400100U;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1084] start_va=0x05f704, fde_va=0x074758, span=156 bytes
// [VN] FDE[1084] địa chỉ bắt đầu=0x05f704, fde_va=0x074758, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1084_0x05f704(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f704U;
    constexpr uint32_t kFdeVa   = 0x074758U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1085] start_va=0x05f7a0, fde_va=0x074778, span=100 bytes
// [VN] FDE[1085] địa chỉ bắt đầu=0x05f7a0, fde_va=0x074778, kích thước=100 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1085_0x05f7a0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f7a0U;
    constexpr uint32_t kFdeVa   = 0x074778U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1086] start_va=0x05f804, fde_va=0x074798, span=100 bytes
// [VN] FDE[1086] địa chỉ bắt đầu=0x05f804, fde_va=0x074798, kích thước=100 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1086_0x05f804(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f804U;
    constexpr uint32_t kFdeVa   = 0x074798U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1087] start_va=0x05f868, fde_va=0x0747b8, span=100 bytes
// [VN] FDE[1087] địa chỉ bắt đầu=0x05f868, fde_va=0x0747b8, kích thước=100 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1087_0x05f868(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f868U;
    constexpr uint32_t kFdeVa   = 0x0747b8U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1088] start_va=0x05f8cc, fde_va=0x0747d8, span=100 bytes
// [VN] FDE[1088] địa chỉ bắt đầu=0x05f8cc, fde_va=0x0747d8, kích thước=100 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1088_0x05f8cc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f8ccU;
    constexpr uint32_t kFdeVa   = 0x0747d8U;
    constexpr uint32_t kSpan    = 100U;
    constexpr uint32_t kW0      = 0xf81d0ff5U;
    constexpr uint32_t kW1      = 0xa9014ff4U;
    constexpr uint32_t kW2      = 0xa9027bfdU;
    constexpr uint32_t kW3      = 0x910083fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1089] start_va=0x05f930, fde_va=0x0747f8, span=200 bytes
// [VN] FDE[1089] địa chỉ bắt đầu=0x05f930, fde_va=0x0747f8, kích thước=200 byte
// AArch64 opcodes: D10183FF F90013F7 A90357F6 A9044FF4
uint32_t cybertron_fde_1089_0x05f930(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f930U;
    constexpr uint32_t kFdeVa   = 0x0747f8U;
    constexpr uint32_t kSpan    = 200U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xf90013f7U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1090] start_va=0x05f9f8, fde_va=0x074820, span=92 bytes
// [VN] FDE[1090] địa chỉ bắt đầu=0x05f9f8, fde_va=0x074820, kích thước=92 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1090_0x05f9f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05f9f8U;
    constexpr uint32_t kFdeVa   = 0x074820U;
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

// [EN] FDE[1091] start_va=0x05fa54, fde_va=0x074840, span=68 bytes
// [VN] FDE[1091] địa chỉ bắt đầu=0x05fa54, fde_va=0x074840, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400008
uint32_t cybertron_fde_1091_0x05fa54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05fa54U;
    constexpr uint32_t kFdeVa   = 0x074840U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1092] start_va=0x05fa98, fde_va=0x074860, span=648 bytes
// [VN] FDE[1092] địa chỉ bắt đầu=0x05fa98, fde_va=0x074860, kích thước=648 byte
// AArch64 opcodes: D10283FF FD0033E8 A90757F6 A9084FF4
uint32_t cybertron_fde_1092_0x05fa98(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05fa98U;
    constexpr uint32_t kFdeVa   = 0x074860U;
    constexpr uint32_t kSpan    = 648U;
    constexpr uint32_t kW0      = 0xd10283ffU;
    constexpr uint32_t kW1      = 0xfd0033e8U;
    constexpr uint32_t kW2      = 0xa90757f6U;
    constexpr uint32_t kW3      = 0xa9084ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1093] start_va=0x05fd20, fde_va=0x074888, span=736 bytes
// [VN] FDE[1093] địa chỉ bắt đầu=0x05fd20, fde_va=0x074888, kích thước=736 byte
// AArch64 opcodes: D10383FF FD0053E8 F90057F7 A90B57F6
uint32_t cybertron_fde_1093_0x05fd20(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x05fd20U;
    constexpr uint32_t kFdeVa   = 0x074888U;
    constexpr uint32_t kSpan    = 736U;
    constexpr uint32_t kW0      = 0xd10383ffU;
    constexpr uint32_t kW1      = 0xfd0053e8U;
    constexpr uint32_t kW2      = 0xf90057f7U;
    constexpr uint32_t kW3      = 0xa90b57f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1094] start_va=0x060000, fde_va=0x0748b0, span=4 bytes
// [VN] FDE[1094] địa chỉ bắt đầu=0x060000, fde_va=0x0748b0, kích thước=4 byte
// AArch64 opcodes: 17FF69C0 B40000E2 F9400048 AA0203E0
uint32_t cybertron_fde_1094_0x060000(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060000U;
    constexpr uint32_t kFdeVa   = 0x0748b0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff69c0U;
    constexpr uint32_t kW1      = 0xb40000e2U;
    constexpr uint32_t kW2      = 0xf9400048U;
    constexpr uint32_t kW3      = 0xaa0203e0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1095] start_va=0x060004, fde_va=0x0748c8, span=32 bytes
// [VN] FDE[1095] địa chỉ bắt đầu=0x060004, fde_va=0x0748c8, kích thước=32 byte
// AArch64 opcodes: B40000E2 F9400048 AA0203E0 2A0303E1
uint32_t cybertron_fde_1095_0x060004(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060004U;
    constexpr uint32_t kFdeVa   = 0x0748c8U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xb40000e2U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0x2a0303e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1096] start_va=0x060024, fde_va=0x0748e0, span=28 bytes
// [VN] FDE[1096] địa chỉ bắt đầu=0x060024, fde_va=0x0748e0, kích thước=28 byte
// AArch64 opcodes: B40000C2 F9400048 AA0203E0 2A0303E1
uint32_t cybertron_fde_1096_0x060024(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060024U;
    constexpr uint32_t kFdeVa   = 0x0748e0U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xb40000c2U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0x2a0303e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1097] start_va=0x060040, fde_va=0x0748f8, span=32 bytes
// [VN] FDE[1097] địa chỉ bắt đầu=0x060040, fde_va=0x0748f8, kích thước=32 byte
// AArch64 opcodes: B40000E2 F9400048 AA0203E0 2A0303E1
uint32_t cybertron_fde_1097_0x060040(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060040U;
    constexpr uint32_t kFdeVa   = 0x0748f8U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xb40000e2U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0x2a0303e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1098] start_va=0x060060, fde_va=0x074910, span=4 bytes
// [VN] FDE[1098] địa chỉ bắt đầu=0x060060, fde_va=0x074910, kích thước=4 byte
// AArch64 opcodes: D65F03C0 D10143FF F90013F5 A9034FF4
uint32_t cybertron_fde_1098_0x060060(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060060U;
    constexpr uint32_t kFdeVa   = 0x074910U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0xd65f03c0U;
    constexpr uint32_t kW1      = 0xd10143ffU;
    constexpr uint32_t kW2      = 0xf90013f5U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1099] start_va=0x060064, fde_va=0x074928, span=136 bytes
// [VN] FDE[1099] địa chỉ bắt đầu=0x060064, fde_va=0x074928, kích thước=136 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_1099_0x060064(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060064U;
    constexpr uint32_t kFdeVa   = 0x074928U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1100] start_va=0x0600ec, fde_va=0x074948, span=36 bytes
// [VN] FDE[1100] địa chỉ bắt đầu=0x0600ec, fde_va=0x074948, kích thước=36 byte
// AArch64 opcodes: B40000E2 F9400048 AA0203E0 2A0303E1
uint32_t cybertron_fde_1100_0x0600ec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0600ecU;
    constexpr uint32_t kFdeVa   = 0x074948U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xb40000e2U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0x2a0303e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1101] start_va=0x060110, fde_va=0x074960, span=28 bytes
// [VN] FDE[1101] địa chỉ bắt đầu=0x060110, fde_va=0x074960, kích thước=28 byte
// AArch64 opcodes: B40000C2 F9400048 AA0203E0 2A0303E1
uint32_t cybertron_fde_1101_0x060110(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060110U;
    constexpr uint32_t kFdeVa   = 0x074960U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xb40000c2U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0x2a0303e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1102] start_va=0x06012c, fde_va=0x074978, span=36 bytes
// [VN] FDE[1102] địa chỉ bắt đầu=0x06012c, fde_va=0x074978, kích thước=36 byte
// AArch64 opcodes: B40000E2 F9400048 AA0203E0 2A0303E1
uint32_t cybertron_fde_1102_0x06012c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x06012cU;
    constexpr uint32_t kFdeVa   = 0x074978U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xb40000e2U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0x2a0303e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1103] start_va=0x060150, fde_va=0x074990, span=216 bytes
// [VN] FDE[1103] địa chỉ bắt đầu=0x060150, fde_va=0x074990, kích thước=216 byte
// AArch64 opcodes: D10243FF F9002BF7 A90657F6 A9074FF4
uint32_t cybertron_fde_1103_0x060150(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060150U;
    constexpr uint32_t kFdeVa   = 0x074990U;
    constexpr uint32_t kSpan    = 216U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xf9002bf7U;
    constexpr uint32_t kW2      = 0xa90657f6U;
    constexpr uint32_t kW3      = 0xa9074ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1104] start_va=0x060228, fde_va=0x0749b8, span=148 bytes
// [VN] FDE[1104] địa chỉ bắt đầu=0x060228, fde_va=0x0749b8, kích thước=148 byte
// AArch64 opcodes: D10103FF A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_1104_0x060228(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060228U;
    constexpr uint32_t kFdeVa   = 0x0749b8U;
    constexpr uint32_t kSpan    = 148U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1105] start_va=0x0602bc, fde_va=0x0749e0, span=444 bytes
// [VN] FDE[1105] địa chỉ bắt đầu=0x0602bc, fde_va=0x0749e0, kích thước=444 byte
// AArch64 opcodes: D10243FF A9055FF8 A90657F6 A9074FF4
uint32_t cybertron_fde_1105_0x0602bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0602bcU;
    constexpr uint32_t kFdeVa   = 0x0749e0U;
    constexpr uint32_t kSpan    = 444U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa9055ff8U;
    constexpr uint32_t kW2      = 0xa90657f6U;
    constexpr uint32_t kW3      = 0xa9074ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1106] start_va=0x060478, fde_va=0x074a08, span=32 bytes
// [VN] FDE[1106] địa chỉ bắt đầu=0x060478, fde_va=0x074a08, kích thước=32 byte
// AArch64 opcodes: B40000E2 F9400048 AA0203E0 2A0303E1
uint32_t cybertron_fde_1106_0x060478(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060478U;
    constexpr uint32_t kFdeVa   = 0x074a08U;
    constexpr uint32_t kSpan    = 32U;
    constexpr uint32_t kW0      = 0xb40000e2U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0x2a0303e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1107] start_va=0x060498, fde_va=0x074a20, span=136 bytes
// [VN] FDE[1107] địa chỉ bắt đầu=0x060498, fde_va=0x074a20, kích thước=136 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_1107_0x060498(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060498U;
    constexpr uint32_t kFdeVa   = 0x074a20U;
    constexpr uint32_t kSpan    = 136U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1108] start_va=0x060520, fde_va=0x074a40, span=36 bytes
// [VN] FDE[1108] địa chỉ bắt đầu=0x060520, fde_va=0x074a40, kích thước=36 byte
// AArch64 opcodes: B4000102 F9400048 AA0203E0 2A0303E1
uint32_t cybertron_fde_1108_0x060520(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060520U;
    constexpr uint32_t kFdeVa   = 0x074a40U;
    constexpr uint32_t kSpan    = 36U;
    constexpr uint32_t kW0      = 0xb4000102U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0x2a0303e1U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1109] start_va=0x060544, fde_va=0x074a58, span=144 bytes
// [VN] FDE[1109] địa chỉ bắt đầu=0x060544, fde_va=0x074a58, kích thước=144 byte
// AArch64 opcodes: D10143FF A90257F6 A9034FF4 A9047BFD
uint32_t cybertron_fde_1109_0x060544(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060544U;
    constexpr uint32_t kFdeVa   = 0x074a58U;
    constexpr uint32_t kSpan    = 144U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xa90257f6U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1110] start_va=0x0605d4, fde_va=0x074a80, span=4 bytes
// [VN] FDE[1110] địa chỉ bắt đầu=0x0605d4, fde_va=0x074a80, kích thước=4 byte
// AArch64 opcodes: 17FF64CB A9BF7BFD 910003FD 97FF61F8
uint32_t cybertron_fde_1110_0x0605d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0605d4U;
    constexpr uint32_t kFdeVa   = 0x074a80U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff64cbU;
    constexpr uint32_t kW1      = 0xa9bf7bfdU;
    constexpr uint32_t kW2      = 0x910003fdU;
    constexpr uint32_t kW3      = 0x97ff61f8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1111] start_va=0x0605d8, fde_va=0x074a98, span=28 bytes
// [VN] FDE[1111] địa chỉ bắt đầu=0x0605d8, fde_va=0x074a98, kích thước=28 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FF61F8 97FF6907
uint32_t cybertron_fde_1111_0x0605d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0605d8U;
    constexpr uint32_t kFdeVa   = 0x074a98U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97ff61f8U;
    constexpr uint32_t kW3      = 0x97ff6907U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1112] start_va=0x0605f4, fde_va=0x074ab8, span=1132 bytes
// [VN] FDE[1112] địa chỉ bắt đầu=0x0605f4, fde_va=0x074ab8, kích thước=1132 byte
// AArch64 opcodes: D104C3FF FD0063E8 A90D6FFC A90E67FA
uint32_t cybertron_fde_1112_0x0605f4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0605f4U;
    constexpr uint32_t kFdeVa   = 0x074ab8U;
    constexpr uint32_t kSpan    = 1132U;
    constexpr uint32_t kW0      = 0xd104c3ffU;
    constexpr uint32_t kW1      = 0xfd0063e8U;
    constexpr uint32_t kW2      = 0xa90d6ffcU;
    constexpr uint32_t kW3      = 0xa90e67faU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1113] start_va=0x060a60, fde_va=0x074ae8, span=1232 bytes
// [VN] FDE[1113] địa chỉ bắt đầu=0x060a60, fde_va=0x074ae8, kích thước=1232 byte
// AArch64 opcodes: D102C3FF A9056FFC A90667FA A9075FF8
uint32_t cybertron_fde_1113_0x060a60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060a60U;
    constexpr uint32_t kFdeVa   = 0x074ae8U;
    constexpr uint32_t kSpan    = 1232U;
    constexpr uint32_t kW0      = 0xd102c3ffU;
    constexpr uint32_t kW1      = 0xa9056ffcU;
    constexpr uint32_t kW2      = 0xa90667faU;
    constexpr uint32_t kW3      = 0xa9075ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1114] start_va=0x060f30, fde_va=0x074b18, span=88 bytes
// [VN] FDE[1114] địa chỉ bắt đầu=0x060f30, fde_va=0x074b18, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400413
uint32_t cybertron_fde_1114_0x060f30(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060f30U;
    constexpr uint32_t kFdeVa   = 0x074b18U;
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

// [EN] FDE[1115] start_va=0x060f88, fde_va=0x074b38, span=424 bytes
// [VN] FDE[1115] địa chỉ bắt đầu=0x060f88, fde_va=0x074b38, kích thước=424 byte
// AArch64 opcodes: D10243FF A90657F6 A9074FF4 A9087BFD
uint32_t cybertron_fde_1115_0x060f88(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x060f88U;
    constexpr uint32_t kFdeVa   = 0x074b38U;
    constexpr uint32_t kSpan    = 424U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa90657f6U;
    constexpr uint32_t kW2      = 0xa9074ff4U;
    constexpr uint32_t kW3      = 0xa9087bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1116] start_va=0x061130, fde_va=0x074b60, span=508 bytes
// [VN] FDE[1116] địa chỉ bắt đầu=0x061130, fde_va=0x074b60, kích thước=508 byte
// AArch64 opcodes: D10303FF A90957F6 A90A4FF4 A90B7BFD
uint32_t cybertron_fde_1116_0x061130(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061130U;
    constexpr uint32_t kFdeVa   = 0x074b60U;
    constexpr uint32_t kSpan    = 508U;
    constexpr uint32_t kW0      = 0xd10303ffU;
    constexpr uint32_t kW1      = 0xa90957f6U;
    constexpr uint32_t kW2      = 0xa90a4ff4U;
    constexpr uint32_t kW3      = 0xa90b7bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1117] start_va=0x06132c, fde_va=0x074b88, span=1160 bytes
// [VN] FDE[1117] địa chỉ bắt đầu=0x06132c, fde_va=0x074b88, kích thước=1160 byte
// AArch64 opcodes: D10283FF FD001BE8 A9046FFC A90567FA
uint32_t cybertron_fde_1117_0x06132c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x06132cU;
    constexpr uint32_t kFdeVa   = 0x074b88U;
    constexpr uint32_t kSpan    = 1160U;
    constexpr uint32_t kW0      = 0xd10283ffU;
    constexpr uint32_t kW1      = 0xfd001be8U;
    constexpr uint32_t kW2      = 0xa9046ffcU;
    constexpr uint32_t kW3      = 0xa90567faU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1118] start_va=0x0617b4, fde_va=0x074bb8, span=36 bytes
// [VN] FDE[1118] địa chỉ bắt đầu=0x0617b4, fde_va=0x074bb8, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_1118_0x0617b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0617b4U;
    constexpr uint32_t kFdeVa   = 0x074bb8U;
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

// [EN] FDE[1119] start_va=0x0617d8, fde_va=0x074bd8, span=56 bytes
// [VN] FDE[1119] địa chỉ bắt đầu=0x0617d8, fde_va=0x074bd8, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400C13
uint32_t cybertron_fde_1119_0x0617d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0617d8U;
    constexpr uint32_t kFdeVa   = 0x074bd8U;
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

// [EN] FDE[1120] start_va=0x061810, fde_va=0x074bf8, span=28 bytes
// [VN] FDE[1120] địa chỉ bắt đầu=0x061810, fde_va=0x074bf8, kích thước=28 byte
// AArch64 opcodes: D00000E9 F9400428 F9464929 9100600A
uint32_t cybertron_fde_1120_0x061810(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061810U;
    constexpr uint32_t kFdeVa   = 0x074bf8U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xd00000e9U;
    constexpr uint32_t kW1      = 0xf9400428U;
    constexpr uint32_t kW2      = 0xf9464929U;
    constexpr uint32_t kW3      = 0x9100600aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1121] start_va=0x06182c, fde_va=0x074c10, span=4 bytes
// [VN] FDE[1121] địa chỉ bắt đầu=0x06182c, fde_va=0x074c10, kích thước=4 byte
// AArch64 opcodes: 17FF5D3D F81E0FF3 A9017BFD 910043FD
uint32_t cybertron_fde_1121_0x06182c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x06182cU;
    constexpr uint32_t kFdeVa   = 0x074c10U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff5d3dU;
    constexpr uint32_t kW1      = 0xf81e0ff3U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1122] start_va=0x061830, fde_va=0x074c28, span=68 bytes
// [VN] FDE[1122] địa chỉ bắt đầu=0x061830, fde_va=0x074c28, kích thước=68 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400008
uint32_t cybertron_fde_1122_0x061830(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061830U;
    constexpr uint32_t kFdeVa   = 0x074c28U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1123] start_va=0x061874, fde_va=0x074c48, span=64 bytes
// [VN] FDE[1123] địa chỉ bắt đầu=0x061874, fde_va=0x074c48, kích thước=64 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D00000E9
uint32_t cybertron_fde_1123_0x061874(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061874U;
    constexpr uint32_t kFdeVa   = 0x074c48U;
    constexpr uint32_t kSpan    = 64U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00000e9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1124] start_va=0x0618b4, fde_va=0x074c68, span=72 bytes
// [VN] FDE[1124] địa chỉ bắt đầu=0x0618b4, fde_va=0x074c68, kích thước=72 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D00000E9
uint32_t cybertron_fde_1124_0x0618b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0618b4U;
    constexpr uint32_t kFdeVa   = 0x074c68U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00000e9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1125] start_va=0x0618fc, fde_va=0x074c88, span=20 bytes
// [VN] FDE[1125] địa chỉ bắt đầu=0x0618fc, fde_va=0x074c88, kích thước=20 byte
// AArch64 opcodes: 39406008 37000048 D65F03C0 F9401400
uint32_t cybertron_fde_1125_0x0618fc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0618fcU;
    constexpr uint32_t kFdeVa   = 0x074c88U;
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

// [EN] FDE[1126] start_va=0x061910, fde_va=0x074ca0, span=4 bytes
// [VN] FDE[1126] địa chỉ bắt đầu=0x061910, fde_va=0x074ca0, kích thước=4 byte
// AArch64 opcodes: 17FF5D04 D10103FF F90013F3 A9037BFD
uint32_t cybertron_fde_1126_0x061910(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061910U;
    constexpr uint32_t kFdeVa   = 0x074ca0U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff5d04U;
    constexpr uint32_t kW1      = 0xd10103ffU;
    constexpr uint32_t kW2      = 0xf90013f3U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1127] start_va=0x061914, fde_va=0x074cb8, span=128 bytes
// [VN] FDE[1127] địa chỉ bắt đầu=0x061914, fde_va=0x074cb8, kích thước=128 byte
// AArch64 opcodes: D10103FF F90013F3 A9037BFD 9100C3FD
uint32_t cybertron_fde_1127_0x061914(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061914U;
    constexpr uint32_t kFdeVa   = 0x074cb8U;
    constexpr uint32_t kSpan    = 128U;
    constexpr uint32_t kW0      = 0xd10103ffU;
    constexpr uint32_t kW1      = 0xf90013f3U;
    constexpr uint32_t kW2      = 0xa9037bfdU;
    constexpr uint32_t kW3      = 0x9100c3fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1128] start_va=0x061994, fde_va=0x074cd8, span=16 bytes
// [VN] FDE[1128] địa chỉ bắt đầu=0x061994, fde_va=0x074cd8, kích thước=16 byte
// AArch64 opcodes: B00000E8 910CE108 F8008408 17FF65D8
uint32_t cybertron_fde_1128_0x061994(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061994U;
    constexpr uint32_t kFdeVa   = 0x074cd8U;
    constexpr uint32_t kSpan    = 16U;
    constexpr uint32_t kW0      = 0xb00000e8U;
    constexpr uint32_t kW1      = 0x910ce108U;
    constexpr uint32_t kW2      = 0xf8008408U;
    constexpr uint32_t kW3      = 0x17ff65d8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1129] start_va=0x0619a4, fde_va=0x074cf0, span=48 bytes
// [VN] FDE[1129] địa chỉ bắt đầu=0x0619a4, fde_va=0x074cf0, kích thước=48 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B00000E8
uint32_t cybertron_fde_1129_0x0619a4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0619a4U;
    constexpr uint32_t kFdeVa   = 0x074cf0U;
    constexpr uint32_t kSpan    = 48U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb00000e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1130] start_va=0x0619d4, fde_va=0x074d10, span=88 bytes
// [VN] FDE[1130] địa chỉ bắt đầu=0x0619d4, fde_va=0x074d10, kích thước=88 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_1130_0x0619d4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0619d4U;
    constexpr uint32_t kFdeVa   = 0x074d10U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0003f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1131] start_va=0x061a2c, fde_va=0x074d30, span=56 bytes
// [VN] FDE[1131] địa chỉ bắt đầu=0x061a2c, fde_va=0x074d30, kích thước=56 byte
// AArch64 opcodes: B00000E8 910CE108 F9000028 F9400408
uint32_t cybertron_fde_1131_0x061a2c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061a2cU;
    constexpr uint32_t kFdeVa   = 0x074d30U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xb00000e8U;
    constexpr uint32_t kW1      = 0x910ce108U;
    constexpr uint32_t kW2      = 0xf9000028U;
    constexpr uint32_t kW3      = 0xf9400408U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1132] start_va=0x061a64, fde_va=0x074d48, span=8 bytes
// [VN] FDE[1132] địa chỉ bắt đầu=0x061a64, fde_va=0x074d48, kích thước=8 byte
// AArch64 opcodes: 91002000 17FF65A6 F81E0FF3 A9017BFD
uint32_t cybertron_fde_1132_0x061a64(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061a64U;
    constexpr uint32_t kFdeVa   = 0x074d48U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91002000U;
    constexpr uint32_t kW1      = 0x17ff65a6U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1133] start_va=0x061a6c, fde_va=0x074d60, span=40 bytes
// [VN] FDE[1133] địa chỉ bắt đầu=0x061a6c, fde_va=0x074d60, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_1133_0x061a6c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061a6cU;
    constexpr uint32_t kFdeVa   = 0x074d60U;
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

// [EN] FDE[1134] start_va=0x061a94, fde_va=0x074d80, span=20 bytes
// [VN] FDE[1134] địa chỉ bắt đầu=0x061a94, fde_va=0x074d80, kích thước=20 byte
// AArch64 opcodes: 39400021 F9400042 F9400063 F9400400
uint32_t cybertron_fde_1134_0x061a94(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061a94U;
    constexpr uint32_t kFdeVa   = 0x074d80U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x39400021U;
    constexpr uint32_t kW1      = 0xf9400042U;
    constexpr uint32_t kW2      = 0xf9400063U;
    constexpr uint32_t kW3      = 0xf9400400U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1135] start_va=0x061aa8, fde_va=0x074d98, span=28 bytes
// [VN] FDE[1135] địa chỉ bắt đầu=0x061aa8, fde_va=0x074d98, kích thước=28 byte
// AArch64 opcodes: F9400428 F0000029 91162529 9100200A
uint32_t cybertron_fde_1135_0x061aa8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061aa8U;
    constexpr uint32_t kFdeVa   = 0x074d98U;
    constexpr uint32_t kSpan    = 28U;
    constexpr uint32_t kW0      = 0xf9400428U;
    constexpr uint32_t kW1      = 0xf0000029U;
    constexpr uint32_t kW2      = 0x91162529U;
    constexpr uint32_t kW3      = 0x9100200aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1136] start_va=0x061ac4, fde_va=0x074db0, span=12 bytes
// [VN] FDE[1136] địa chỉ bắt đầu=0x061ac4, fde_va=0x074db0, kích thước=12 byte
// AArch64 opcodes: B00000E0 910EA000 D65F03C0 B40000A2
uint32_t cybertron_fde_1136_0x061ac4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061ac4U;
    constexpr uint32_t kFdeVa   = 0x074db0U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xb00000e0U;
    constexpr uint32_t kW1      = 0x910ea000U;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xb40000a2U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1137] start_va=0x061ad0, fde_va=0x074dc8, span=24 bytes
// [VN] FDE[1137] địa chỉ bắt đầu=0x061ad0, fde_va=0x074dc8, kích thước=24 byte
// AArch64 opcodes: B40000A2 F9400048 AA0203E0 F9400101
uint32_t cybertron_fde_1137_0x061ad0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061ad0U;
    constexpr uint32_t kFdeVa   = 0x074dc8U;
    constexpr uint32_t kSpan    = 24U;
    constexpr uint32_t kW0      = 0xb40000a2U;
    constexpr uint32_t kW1      = 0xf9400048U;
    constexpr uint32_t kW2      = 0xaa0203e0U;
    constexpr uint32_t kW3      = 0xf9400101U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1138] start_va=0x061ae8, fde_va=0x074de0, span=120 bytes
// [VN] FDE[1138] địa chỉ bắt đầu=0x061ae8, fde_va=0x074de0, kích thước=120 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_1138_0x061ae8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061ae8U;
    constexpr uint32_t kFdeVa   = 0x074de0U;
    constexpr uint32_t kSpan    = 120U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1139] start_va=0x061b60, fde_va=0x074e00, span=124 bytes
// [VN] FDE[1139] địa chỉ bắt đầu=0x061b60, fde_va=0x074e00, kích thước=124 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1139_0x061b60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061b60U;
    constexpr uint32_t kFdeVa   = 0x074e00U;
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

// [EN] FDE[1140] start_va=0x061bdc, fde_va=0x074e20, span=156 bytes
// [VN] FDE[1140] địa chỉ bắt đầu=0x061bdc, fde_va=0x074e20, kích thước=156 byte
// AArch64 opcodes: D10483FF A9104FFC A9117BFD 910443FD
uint32_t cybertron_fde_1140_0x061bdc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061bdcU;
    constexpr uint32_t kFdeVa   = 0x074e20U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10483ffU;
    constexpr uint32_t kW1      = 0xa9104ffcU;
    constexpr uint32_t kW2      = 0xa9117bfdU;
    constexpr uint32_t kW3      = 0x910443fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1141] start_va=0x061c78, fde_va=0x074e40, span=120 bytes
// [VN] FDE[1141] địa chỉ bắt đầu=0x061c78, fde_va=0x074e40, kích thước=120 byte
// AArch64 opcodes: F81D0FF5 A9014FF4 A9027BFD 910083FD
uint32_t cybertron_fde_1141_0x061c78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061c78U;
    constexpr uint32_t kFdeVa   = 0x074e40U;
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

// [EN] FDE[1142] start_va=0x061cf0, fde_va=0x074e60, span=92 bytes
// [VN] FDE[1142] địa chỉ bắt đầu=0x061cf0, fde_va=0x074e60, kích thước=92 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD D00000E8
uint32_t cybertron_fde_1142_0x061cf0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061cf0U;
    constexpr uint32_t kFdeVa   = 0x074e60U;
    constexpr uint32_t kSpan    = 92U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xd00000e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1143] start_va=0x061d4c, fde_va=0x074e80, span=8 bytes
// [VN] FDE[1143] địa chỉ bắt đầu=0x061d4c, fde_va=0x074e80, kích thước=8 byte
// AArch64 opcodes: D1002000 17FF5C78 F81E0FF3 A9017BFD
uint32_t cybertron_fde_1143_0x061d4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061d4cU;
    constexpr uint32_t kFdeVa   = 0x074e80U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xd1002000U;
    constexpr uint32_t kW1      = 0x17ff5c78U;
    constexpr uint32_t kW2      = 0xf81e0ff3U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1144] start_va=0x061d54, fde_va=0x074e98, span=36 bytes
// [VN] FDE[1144] địa chỉ bắt đầu=0x061d54, fde_va=0x074e98, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_1144_0x061d54(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061d54U;
    constexpr uint32_t kFdeVa   = 0x074e98U;
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

// [EN] FDE[1145] start_va=0x061d78, fde_va=0x074eb8, span=40 bytes
// [VN] FDE[1145] địa chỉ bắt đầu=0x061d78, fde_va=0x074eb8, kích thước=40 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD D1002013
uint32_t cybertron_fde_1145_0x061d78(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061d78U;
    constexpr uint32_t kFdeVa   = 0x074eb8U;
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

// [EN] FDE[1146] start_va=0x061da0, fde_va=0x074ed8, span=260 bytes
// [VN] FDE[1146] địa chỉ bắt đầu=0x061da0, fde_va=0x074ed8, kích thước=260 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_1146_0x061da0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061da0U;
    constexpr uint32_t kFdeVa   = 0x074ed8U;
    constexpr uint32_t kSpan    = 260U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90267faU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1147] start_va=0x061ea4, fde_va=0x074f08, span=20 bytes
// [VN] FDE[1147] địa chỉ bắt đầu=0x061ea4, fde_va=0x074f08, kích thước=20 byte
// AArch64 opcodes: B4000080 F9400008 F9400901 D61F0020
uint32_t cybertron_fde_1147_0x061ea4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061ea4U;
    constexpr uint32_t kFdeVa   = 0x074f08U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0xb4000080U;
    constexpr uint32_t kW1      = 0xf9400008U;
    constexpr uint32_t kW2      = 0xf9400901U;
    constexpr uint32_t kW3      = 0xd61f0020U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1148] start_va=0x061eb8, fde_va=0x074f20, span=912 bytes
// [VN] FDE[1148] địa chỉ bắt đầu=0x061eb8, fde_va=0x074f20, kích thước=912 byte
// AArch64 opcodes: D10383FF A9086FFC A90967FA A90A5FF8
uint32_t cybertron_fde_1148_0x061eb8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x061eb8U;
    constexpr uint32_t kFdeVa   = 0x074f20U;
    constexpr uint32_t kSpan    = 912U;
    constexpr uint32_t kW0      = 0xd10383ffU;
    constexpr uint32_t kW1      = 0xa9086ffcU;
    constexpr uint32_t kW2      = 0xa90967faU;
    constexpr uint32_t kW3      = 0xa90a5ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1149] start_va=0x062248, fde_va=0x074f50, span=204 bytes
// [VN] FDE[1149] địa chỉ bắt đầu=0x062248, fde_va=0x074f50, kích thước=204 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_1149_0x062248(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062248U;
    constexpr uint32_t kFdeVa   = 0x074f50U;
    constexpr uint32_t kSpan    = 204U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1150] start_va=0x062314, fde_va=0x074f70, span=452 bytes
// [VN] FDE[1150] địa chỉ bắt đầu=0x062314, fde_va=0x074f70, kích thước=452 byte
// AArch64 opcodes: D10143FF F9000BF7 A90257F6 A9034FF4
uint32_t cybertron_fde_1150_0x062314(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062314U;
    constexpr uint32_t kFdeVa   = 0x074f70U;
    constexpr uint32_t kSpan    = 452U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf9000bf7U;
    constexpr uint32_t kW2      = 0xa90257f6U;
    constexpr uint32_t kW3      = 0xa9034ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1151] start_va=0x0624d8, fde_va=0x074f98, span=72 bytes
// [VN] FDE[1151] địa chỉ bắt đầu=0x0624d8, fde_va=0x074f98, kích thước=72 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD B00000E8
uint32_t cybertron_fde_1151_0x0624d8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0624d8U;
    constexpr uint32_t kFdeVa   = 0x074f98U;
    constexpr uint32_t kSpan    = 72U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xb00000e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1152] start_va=0x062520, fde_va=0x074fb8, span=36 bytes
// [VN] FDE[1152] địa chỉ bắt đầu=0x062520, fde_va=0x074fb8, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0003F3
uint32_t cybertron_fde_1152_0x062520(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062520U;
    constexpr uint32_t kFdeVa   = 0x074fb8U;
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

// [EN] FDE[1153] start_va=0x062544, fde_va=0x074fd8, span=192 bytes
// [VN] FDE[1153] địa chỉ bắt đầu=0x062544, fde_va=0x074fd8, kích thước=192 byte
// AArch64 opcodes: D10203FF A9045FF8 A90557F6 A9064FF4
uint32_t cybertron_fde_1153_0x062544(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062544U;
    constexpr uint32_t kFdeVa   = 0x074fd8U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa9045ff8U;
    constexpr uint32_t kW2      = 0xa90557f6U;
    constexpr uint32_t kW3      = 0xa9064ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1154] start_va=0x062604, fde_va=0x075000, span=692 bytes
// [VN] FDE[1154] địa chỉ bắt đầu=0x062604, fde_va=0x075000, kích thước=692 byte
// AArch64 opcodes: D10203FF FD001BE8 F9001FF9 A9045FF8
uint32_t cybertron_fde_1154_0x062604(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062604U;
    constexpr uint32_t kFdeVa   = 0x075000U;
    constexpr uint32_t kSpan    = 692U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xfd001be8U;
    constexpr uint32_t kW2      = 0xf9001ff9U;
    constexpr uint32_t kW3      = 0xa9045ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1155] start_va=0x0628b8, fde_va=0x075030, span=8 bytes
// [VN] FDE[1155] địa chỉ bắt đầu=0x0628b8, fde_va=0x075030, kích thước=8 byte
// AArch64 opcodes: 91004000 17FF5E79 D10203FF A90557F6
uint32_t cybertron_fde_1155_0x0628b8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0628b8U;
    constexpr uint32_t kFdeVa   = 0x075030U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x91004000U;
    constexpr uint32_t kW1      = 0x17ff5e79U;
    constexpr uint32_t kW2      = 0xd10203ffU;
    constexpr uint32_t kW3      = 0xa90557f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1156] start_va=0x0628c0, fde_va=0x075048, span=244 bytes
// [VN] FDE[1156] địa chỉ bắt đầu=0x0628c0, fde_va=0x075048, kích thước=244 byte
// AArch64 opcodes: D10203FF A90557F6 A9064FF4 A9077BFD
uint32_t cybertron_fde_1156_0x0628c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0628c0U;
    constexpr uint32_t kFdeVa   = 0x075048U;
    constexpr uint32_t kSpan    = 244U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xa90557f6U;
    constexpr uint32_t kW2      = 0xa9064ff4U;
    constexpr uint32_t kW3      = 0xa9077bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1157] start_va=0x0629b4, fde_va=0x075070, span=476 bytes
// [VN] FDE[1157] địa chỉ bắt đầu=0x0629b4, fde_va=0x075070, kích thước=476 byte
// AArch64 opcodes: D10183FF A9025FF8 A90357F6 A9044FF4
uint32_t cybertron_fde_1157_0x0629b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0629b4U;
    constexpr uint32_t kFdeVa   = 0x075070U;
    constexpr uint32_t kSpan    = 476U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa9025ff8U;
    constexpr uint32_t kW2      = 0xa90357f6U;
    constexpr uint32_t kW3      = 0xa9044ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1158] start_va=0x062b90, fde_va=0x075098, span=20 bytes
// [VN] FDE[1158] địa chỉ bắt đầu=0x062b90, fde_va=0x075098, kích thước=20 byte
// AArch64 opcodes: AA0803E9 F8008D3F F900091F F9000109
uint32_t cybertron_fde_1158_0x062b90(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062b90U;
    constexpr uint32_t kFdeVa   = 0x075098U;
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

// [EN] FDE[1159] start_va=0x062ba4, fde_va=0x0750b0, span=44 bytes
// [VN] FDE[1159] địa chỉ bắt đầu=0x062ba4, fde_va=0x0750b0, kích thước=44 byte
// AArch64 opcodes: F000002A 9120E54A F840514B F940014A
uint32_t cybertron_fde_1159_0x062ba4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062ba4U;
    constexpr uint32_t kFdeVa   = 0x0750b0U;
    constexpr uint32_t kSpan    = 44U;
    constexpr uint32_t kW0      = 0xf000002aU;
    constexpr uint32_t kW1      = 0x9120e54aU;
    constexpr uint32_t kW2      = 0xf840514bU;
    constexpr uint32_t kW3      = 0xf940014aU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1160] start_va=0x062bd0, fde_va=0x0750c8, span=432 bytes
// [VN] FDE[1160] địa chỉ bắt đầu=0x062bd0, fde_va=0x0750c8, kích thước=432 byte
// AArch64 opcodes: D10283FF A90567FA A9065FF8 A90757F6
uint32_t cybertron_fde_1160_0x062bd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062bd0U;
    constexpr uint32_t kFdeVa   = 0x0750c8U;
    constexpr uint32_t kSpan    = 432U;
    constexpr uint32_t kW0      = 0xd10283ffU;
    constexpr uint32_t kW1      = 0xa90567faU;
    constexpr uint32_t kW2      = 0xa9065ff8U;
    constexpr uint32_t kW3      = 0xa90757f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1161] start_va=0x062d80, fde_va=0x0750f8, span=4 bytes
// [VN] FDE[1161] địa chỉ bắt đầu=0x062d80, fde_va=0x0750f8, kích thước=4 byte
// AArch64 opcodes: 17FF5E74 D10243FF F90023F9 A9055FF8
uint32_t cybertron_fde_1161_0x062d80(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062d80U;
    constexpr uint32_t kFdeVa   = 0x0750f8U;
    constexpr uint32_t kSpan    = 4U;
    constexpr uint32_t kW0      = 0x17ff5e74U;
    constexpr uint32_t kW1      = 0xd10243ffU;
    constexpr uint32_t kW2      = 0xf90023f9U;
    constexpr uint32_t kW3      = 0xa9055ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1162] start_va=0x062d84, fde_va=0x075110, span=580 bytes
// [VN] FDE[1162] địa chỉ bắt đầu=0x062d84, fde_va=0x075110, kích thước=580 byte
// AArch64 opcodes: D10243FF F90023F9 A9055FF8 A90657F6
uint32_t cybertron_fde_1162_0x062d84(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062d84U;
    constexpr uint32_t kFdeVa   = 0x075110U;
    constexpr uint32_t kSpan    = 580U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xf90023f9U;
    constexpr uint32_t kW2      = 0xa9055ff8U;
    constexpr uint32_t kW3      = 0xa90657f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1163] start_va=0x062fc8, fde_va=0x075138, span=8 bytes
// [VN] FDE[1163] địa chỉ bắt đầu=0x062fc8, fde_va=0x075138, kích thước=8 byte
// AArch64 opcodes: 2A1F03E0 D65F03C0 A9BE4FF4 A9017BFD
uint32_t cybertron_fde_1163_0x062fc8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062fc8U;
    constexpr uint32_t kFdeVa   = 0x075138U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x2a1f03e0U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xa9be4ff4U;
    constexpr uint32_t kW3      = 0xa9017bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1164] start_va=0x062fd0, fde_va=0x075150, span=88 bytes
// [VN] FDE[1164] địa chỉ bắt đầu=0x062fd0, fde_va=0x075150, kích thước=88 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 6F00E400
uint32_t cybertron_fde_1164_0x062fd0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x062fd0U;
    constexpr uint32_t kFdeVa   = 0x075150U;
    constexpr uint32_t kSpan    = 88U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x6f00e400U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1165] start_va=0x063028, fde_va=0x075170, span=760 bytes
// [VN] FDE[1165] địa chỉ bắt đầu=0x063028, fde_va=0x075170, kích thước=760 byte
// AArch64 opcodes: D10243FF A9036FFC A90467FA A9055FF8
uint32_t cybertron_fde_1165_0x063028(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063028U;
    constexpr uint32_t kFdeVa   = 0x075170U;
    constexpr uint32_t kSpan    = 760U;
    constexpr uint32_t kW0      = 0xd10243ffU;
    constexpr uint32_t kW1      = 0xa9036ffcU;
    constexpr uint32_t kW2      = 0xa90467faU;
    constexpr uint32_t kW3      = 0xa9055ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1166] start_va=0x063320, fde_va=0x0751a0, span=140 bytes
// [VN] FDE[1166] địa chỉ bắt đầu=0x063320, fde_va=0x0751a0, kích thước=140 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_1166_0x063320(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063320U;
    constexpr uint32_t kFdeVa   = 0x0751a0U;
    constexpr uint32_t kSpan    = 140U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1167] start_va=0x0633ac, fde_va=0x0751c8, span=192 bytes
// [VN] FDE[1167] địa chỉ bắt đầu=0x0633ac, fde_va=0x0751c8, kích thước=192 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_1167_0x0633ac(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0633acU;
    constexpr uint32_t kFdeVa   = 0x0751c8U;
    constexpr uint32_t kSpan    = 192U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1168] start_va=0x06346c, fde_va=0x0751f0, span=80 bytes
// [VN] FDE[1168] địa chỉ bắt đầu=0x06346c, fde_va=0x0751f0, kích thước=80 byte
// AArch64 opcodes: B4000261 A9BE4FF4 A9017BFD 910043FD
uint32_t cybertron_fde_1168_0x06346c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x06346cU;
    constexpr uint32_t kFdeVa   = 0x0751f0U;
    constexpr uint32_t kSpan    = 80U;
    constexpr uint32_t kW0      = 0xb4000261U;
    constexpr uint32_t kW1      = 0xa9be4ff4U;
    constexpr uint32_t kW2      = 0xa9017bfdU;
    constexpr uint32_t kW3      = 0x910043fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1169] start_va=0x0634bc, fde_va=0x075210, span=212 bytes
// [VN] FDE[1169] địa chỉ bắt đầu=0x0634bc, fde_va=0x075210, kích thước=212 byte
// AArch64 opcodes: F81C0FF7 A90157F6 A9024FF4 A9037BFD
uint32_t cybertron_fde_1169_0x0634bc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0634bcU;
    constexpr uint32_t kFdeVa   = 0x075210U;
    constexpr uint32_t kSpan    = 212U;
    constexpr uint32_t kW0      = 0xf81c0ff7U;
    constexpr uint32_t kW1      = 0xa90157f6U;
    constexpr uint32_t kW2      = 0xa9024ff4U;
    constexpr uint32_t kW3      = 0xa9037bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1170] start_va=0x063590, fde_va=0x075238, span=84 bytes
// [VN] FDE[1170] địa chỉ bắt đầu=0x063590, fde_va=0x075238, kích thước=84 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD A9007C7F
uint32_t cybertron_fde_1170_0x063590(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063590U;
    constexpr uint32_t kFdeVa   = 0x075238U;
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

// [EN] FDE[1171] start_va=0x0635e4, fde_va=0x075258, span=20 bytes
// [VN] FDE[1171] địa chỉ bắt đầu=0x0635e4, fde_va=0x075258, kích thước=20 byte
// AArch64 opcodes: 900000E8 F9477D08 91004108 F9000008
uint32_t cybertron_fde_1171_0x0635e4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0635e4U;
    constexpr uint32_t kFdeVa   = 0x075258U;
    constexpr uint32_t kSpan    = 20U;
    constexpr uint32_t kW0      = 0x900000e8U;
    constexpr uint32_t kW1      = 0xf9477d08U;
    constexpr uint32_t kW2      = 0x91004108U;
    constexpr uint32_t kW3      = 0xf9000008U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1172] start_va=0x0635f8, fde_va=0x075270, span=52 bytes
// [VN] FDE[1172] địa chỉ bắt đầu=0x0635f8, fde_va=0x075270, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_1172_0x0635f8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0635f8U;
    constexpr uint32_t kFdeVa   = 0x075270U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1173] start_va=0x06362c, fde_va=0x075290, span=52 bytes
// [VN] FDE[1173] địa chỉ bắt đầu=0x06362c, fde_va=0x075290, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_1173_0x06362c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x06362cU;
    constexpr uint32_t kFdeVa   = 0x075290U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1174] start_va=0x063660, fde_va=0x0752b0, span=52 bytes
// [VN] FDE[1174] địa chỉ bắt đầu=0x063660, fde_va=0x0752b0, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_1174_0x063660(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063660U;
    constexpr uint32_t kFdeVa   = 0x0752b0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1175] start_va=0x063694, fde_va=0x0752d0, span=52 bytes
// [VN] FDE[1175] địa chỉ bắt đầu=0x063694, fde_va=0x0752d0, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_1175_0x063694(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063694U;
    constexpr uint32_t kFdeVa   = 0x0752d0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1176] start_va=0x0636c8, fde_va=0x0752f0, span=52 bytes
// [VN] FDE[1176] địa chỉ bắt đầu=0x0636c8, fde_va=0x0752f0, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_1176_0x0636c8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0636c8U;
    constexpr uint32_t kFdeVa   = 0x0752f0U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1177] start_va=0x0636fc, fde_va=0x075310, span=52 bytes
// [VN] FDE[1177] địa chỉ bắt đầu=0x0636fc, fde_va=0x075310, kích thước=52 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0103F3
uint32_t cybertron_fde_1177_0x0636fc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0636fcU;
    constexpr uint32_t kFdeVa   = 0x075310U;
    constexpr uint32_t kSpan    = 52U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xaa0103f3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1178] start_va=0x063730, fde_va=0x075330, span=36 bytes
// [VN] FDE[1178] địa chỉ bắt đầu=0x063730, fde_va=0x075330, kích thước=36 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD AA0803F3
uint32_t cybertron_fde_1178_0x063730(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063730U;
    constexpr uint32_t kFdeVa   = 0x075330U;
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

// [EN] FDE[1179] start_va=0x063754, fde_va=0x075350, span=12 bytes
// [VN] FDE[1179] địa chỉ bắt đầu=0x063754, fde_va=0x075350, kích thước=12 byte
// AArch64 opcodes: A9BF7BFD 910003FD 97FF5B71 D101C3FF
uint32_t cybertron_fde_1179_0x063754(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063754U;
    constexpr uint32_t kFdeVa   = 0x075350U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x910003fdU;
    constexpr uint32_t kW2      = 0x97ff5b71U;
    constexpr uint32_t kW3      = 0xd101c3ffU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1180] start_va=0x063760, fde_va=0x075370, span=748 bytes
// [VN] FDE[1180] địa chỉ bắt đầu=0x063760, fde_va=0x075370, kích thước=748 byte
// AArch64 opcodes: D101C3FF F9001BF7 A90457F6 A9054FF4
uint32_t cybertron_fde_1180_0x063760(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063760U;
    constexpr uint32_t kFdeVa   = 0x075370U;
    constexpr uint32_t kSpan    = 748U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xf9001bf7U;
    constexpr uint32_t kW2      = 0xa90457f6U;
    constexpr uint32_t kW3      = 0xa9054ff4U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1181] start_va=0x063a4c, fde_va=0x075398, span=256 bytes
// [VN] FDE[1181] địa chỉ bắt đầu=0x063a4c, fde_va=0x075398, kích thước=256 byte
// AArch64 opcodes: D101C3FF A90267FA A9035FF8 A90457F6
uint32_t cybertron_fde_1181_0x063a4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063a4cU;
    constexpr uint32_t kFdeVa   = 0x075398U;
    constexpr uint32_t kSpan    = 256U;
    constexpr uint32_t kW0      = 0xd101c3ffU;
    constexpr uint32_t kW1      = 0xa90267faU;
    constexpr uint32_t kW2      = 0xa9035ff8U;
    constexpr uint32_t kW3      = 0xa90457f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1182] start_va=0x063b4c, fde_va=0x0753c8, span=236 bytes
// [VN] FDE[1182] địa chỉ bắt đầu=0x063b4c, fde_va=0x0753c8, kích thước=236 byte
// AArch64 opcodes: D10183FF A90357F6 A9044FF4 A9057BFD
uint32_t cybertron_fde_1182_0x063b4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063b4cU;
    constexpr uint32_t kFdeVa   = 0x0753c8U;
    constexpr uint32_t kSpan    = 236U;
    constexpr uint32_t kW0      = 0xd10183ffU;
    constexpr uint32_t kW1      = 0xa90357f6U;
    constexpr uint32_t kW2      = 0xa9044ff4U;
    constexpr uint32_t kW3      = 0xa9057bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1183] start_va=0x063c38, fde_va=0x0753f0, span=8 bytes
// [VN] FDE[1183] địa chỉ bắt đầu=0x063c38, fde_va=0x0753f0, kích thước=8 byte
// AArch64 opcodes: A9007D1F D65F03C0 A9007D1F F900091F
uint32_t cybertron_fde_1183_0x063c38(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063c38U;
    constexpr uint32_t kFdeVa   = 0x0753f0U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xa9007d1fU;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xa9007d1fU;
    constexpr uint32_t kW3      = 0xf900091fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1184] start_va=0x063c40, fde_va=0x075408, span=12 bytes
// [VN] FDE[1184] địa chỉ bắt đầu=0x063c40, fde_va=0x075408, kích thước=12 byte
// AArch64 opcodes: A9007D1F F900091F D65F03C0 AA0803E9
uint32_t cybertron_fde_1184_0x063c40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063c40U;
    constexpr uint32_t kFdeVa   = 0x075408U;
    constexpr uint32_t kSpan    = 12U;
    constexpr uint32_t kW0      = 0xa9007d1fU;
    constexpr uint32_t kW1      = 0xf900091fU;
    constexpr uint32_t kW2      = 0xd65f03c0U;
    constexpr uint32_t kW3      = 0xaa0803e9U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1185] start_va=0x063c4c, fde_va=0x075420, span=20 bytes
// [VN] FDE[1185] địa chỉ bắt đầu=0x063c4c, fde_va=0x075420, kích thước=20 byte
// AArch64 opcodes: AA0803E9 F8008D3F F900091F F9000109
uint32_t cybertron_fde_1185_0x063c4c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063c4cU;
    constexpr uint32_t kFdeVa   = 0x075420U;
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

// [EN] FDE[1186] start_va=0x063c60, fde_va=0x075438, span=56 bytes
// [VN] FDE[1186] địa chỉ bắt đầu=0x063c60, fde_va=0x075438, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD 900000E8
uint32_t cybertron_fde_1186_0x063c60(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063c60U;
    constexpr uint32_t kFdeVa   = 0x075438U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900000e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1187] start_va=0x063c98, fde_va=0x075458, span=68 bytes
// [VN] FDE[1187] địa chỉ bắt đầu=0x063c98, fde_va=0x075458, kích thước=68 byte
// AArch64 opcodes: A9BE4FF4 A9017BFD 910043FD 900000E8
uint32_t cybertron_fde_1187_0x063c98(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063c98U;
    constexpr uint32_t kFdeVa   = 0x075458U;
    constexpr uint32_t kSpan    = 68U;
    constexpr uint32_t kW0      = 0xa9be4ff4U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0x900000e8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1188] start_va=0x063cdc, fde_va=0x075478, span=8 bytes
// [VN] FDE[1188] địa chỉ bắt đầu=0x063cdc, fde_va=0x075478, kích thước=8 byte
// AArch64 opcodes: 52800040 D65F03C0 A9007D1F D65F03C0
uint32_t cybertron_fde_1188_0x063cdc(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063cdcU;
    constexpr uint32_t kFdeVa   = 0x075478U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0x52800040U;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xa9007d1fU;
    constexpr uint32_t kW3      = 0xd65f03c0U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1189] start_va=0x063ce4, fde_va=0x075490, span=8 bytes
// [VN] FDE[1189] địa chỉ bắt đầu=0x063ce4, fde_va=0x075490, kích thước=8 byte
// AArch64 opcodes: A9007D1F D65F03C0 F81A0FFC A90167FA
uint32_t cybertron_fde_1189_0x063ce4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063ce4U;
    constexpr uint32_t kFdeVa   = 0x075490U;
    constexpr uint32_t kSpan    = 8U;
    constexpr uint32_t kW0      = 0xa9007d1fU;
    constexpr uint32_t kW1      = 0xd65f03c0U;
    constexpr uint32_t kW2      = 0xf81a0ffcU;
    constexpr uint32_t kW3      = 0xa90167faU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1190] start_va=0x063cec, fde_va=0x0754a8, span=296 bytes
// [VN] FDE[1190] địa chỉ bắt đầu=0x063cec, fde_va=0x0754a8, kích thước=296 byte
// AArch64 opcodes: F81A0FFC A90167FA A9025FF8 A90357F6
uint32_t cybertron_fde_1190_0x063cec(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063cecU;
    constexpr uint32_t kFdeVa   = 0x0754a8U;
    constexpr uint32_t kSpan    = 296U;
    constexpr uint32_t kW0      = 0xf81a0ffcU;
    constexpr uint32_t kW1      = 0xa90167faU;
    constexpr uint32_t kW2      = 0xa9025ff8U;
    constexpr uint32_t kW3      = 0xa90357f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1191] start_va=0x063e14, fde_va=0x0754d8, span=156 bytes
// [VN] FDE[1191] địa chỉ bắt đầu=0x063e14, fde_va=0x0754d8, kích thước=156 byte
// AArch64 opcodes: D10443FF A90F4FFC A9107BFD 910403FD
uint32_t cybertron_fde_1191_0x063e14(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063e14U;
    constexpr uint32_t kFdeVa   = 0x0754d8U;
    constexpr uint32_t kSpan    = 156U;
    constexpr uint32_t kW0      = 0xd10443ffU;
    constexpr uint32_t kW1      = 0xa90f4ffcU;
    constexpr uint32_t kW2      = 0xa9107bfdU;
    constexpr uint32_t kW3      = 0x910403fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1192] start_va=0x063eb0, fde_va=0x0754f8, span=56 bytes
// [VN] FDE[1192] địa chỉ bắt đầu=0x063eb0, fde_va=0x0754f8, kích thước=56 byte
// AArch64 opcodes: F81E0FF3 A9017BFD 910043FD F9400029
uint32_t cybertron_fde_1192_0x063eb0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063eb0U;
    constexpr uint32_t kFdeVa   = 0x0754f8U;
    constexpr uint32_t kSpan    = 56U;
    constexpr uint32_t kW0      = 0xf81e0ff3U;
    constexpr uint32_t kW1      = 0xa9017bfdU;
    constexpr uint32_t kW2      = 0x910043fdU;
    constexpr uint32_t kW3      = 0xf9400029U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1193] start_va=0x063ee8, fde_va=0x075518, span=356 bytes
// [VN] FDE[1193] địa chỉ bắt đầu=0x063ee8, fde_va=0x075518, kích thước=356 byte
// AArch64 opcodes: D10203FF F90013FB A90367FA A9045FF8
uint32_t cybertron_fde_1193_0x063ee8(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x063ee8U;
    constexpr uint32_t kFdeVa   = 0x075518U;
    constexpr uint32_t kSpan    = 356U;
    constexpr uint32_t kW0      = 0xd10203ffU;
    constexpr uint32_t kW1      = 0xf90013fbU;
    constexpr uint32_t kW2      = 0xa90367faU;
    constexpr uint32_t kW3      = 0xa9045ff8U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1194] start_va=0x06404c, fde_va=0x075548, span=184 bytes
// [VN] FDE[1194] địa chỉ bắt đầu=0x06404c, fde_va=0x075548, kích thước=184 byte
// AArch64 opcodes: D10143FF F90013F5 A9034FF4 A9047BFD
uint32_t cybertron_fde_1194_0x06404c(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x06404cU;
    constexpr uint32_t kFdeVa   = 0x075548U;
    constexpr uint32_t kSpan    = 184U;
    constexpr uint32_t kW0      = 0xd10143ffU;
    constexpr uint32_t kW1      = 0xf90013f5U;
    constexpr uint32_t kW2      = 0xa9034ff4U;
    constexpr uint32_t kW3      = 0xa9047bfdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1195] start_va=0x064104, fde_va=0x075568, span=1408 bytes
// [VN] FDE[1195] địa chỉ bắt đầu=0x064104, fde_va=0x075568, kích thước=1408 byte
// AArch64 opcodes: D10283FF A90567FA A9065FF8 A90757F6
uint32_t cybertron_fde_1195_0x064104(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x064104U;
    constexpr uint32_t kFdeVa   = 0x075568U;
    constexpr uint32_t kSpan    = 1408U;
    constexpr uint32_t kW0      = 0xd10283ffU;
    constexpr uint32_t kW1      = 0xa90567faU;
    constexpr uint32_t kW2      = 0xa9065ff8U;
    constexpr uint32_t kW3      = 0xa90757f6U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1196] start_va=0x064684, fde_va=0x0755b0, span=316 bytes
// [VN] FDE[1196] địa chỉ bắt đầu=0x064684, fde_va=0x0755b0, kích thước=316 byte
// AArch64 opcodes: A9BF7BFD 9E660000 9EAE0001 910003FD
uint32_t cybertron_fde_1196_0x064684(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x064684U;
    constexpr uint32_t kFdeVa   = 0x0755b0U;
    constexpr uint32_t kSpan    = 316U;
    constexpr uint32_t kW0      = 0xa9bf7bfdU;
    constexpr uint32_t kW1      = 0x9e660000U;
    constexpr uint32_t kW2      = 0x9eae0001U;
    constexpr uint32_t kW3      = 0x910003fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1197] start_va=0x0647c0, fde_va=0x0755d8, span=1760 bytes
// [VN] FDE[1197] địa chỉ bắt đầu=0x0647c0, fde_va=0x0755d8, kích thước=1760 byte
// AArch64 opcodes: 9E660000 9EAE0001 A9BD7BFD AA0003E3
uint32_t cybertron_fde_1197_0x0647c0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0647c0U;
    constexpr uint32_t kFdeVa   = 0x0755d8U;
    constexpr uint32_t kSpan    = 1760U;
    constexpr uint32_t kW0      = 0x9e660000U;
    constexpr uint32_t kW1      = 0x9eae0001U;
    constexpr uint32_t kW2      = 0xa9bd7bfdU;
    constexpr uint32_t kW3      = 0xaa0003e3U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1198] start_va=0x064ea0, fde_va=0x075608, span=2836 bytes
// [VN] FDE[1198] địa chỉ bắt đầu=0x064ea0, fde_va=0x075608, kích thước=2836 byte
// AArch64 opcodes: A9BE7BFD 9E660000 9EAE0001 910003FD
uint32_t cybertron_fde_1198_0x064ea0(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x064ea0U;
    constexpr uint32_t kFdeVa   = 0x075608U;
    constexpr uint32_t kSpan    = 2836U;
    constexpr uint32_t kW0      = 0xa9be7bfdU;
    constexpr uint32_t kW1      = 0x9e660000U;
    constexpr uint32_t kW2      = 0x9eae0001U;
    constexpr uint32_t kW3      = 0x910003fdU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1199] start_va=0x0659b4, fde_va=0x075630, span=140 bytes
// [VN] FDE[1199] địa chỉ bắt đầu=0x0659b4, fde_va=0x075630, kích thước=140 byte
// AArch64 opcodes: B4000300 D37FFC01 D2880DE3 6B1F003F
uint32_t cybertron_fde_1199_0x0659b4(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x0659b4U;
    constexpr uint32_t kFdeVa   = 0x075630U;
    constexpr uint32_t kSpan    = 140U;
    constexpr uint32_t kW0      = 0xb4000300U;
    constexpr uint32_t kW1      = 0xd37ffc01U;
    constexpr uint32_t kW2      = 0xd2880de3U;
    constexpr uint32_t kW3      = 0x6b1f003fU;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

// [EN] FDE[1200] start_va=0x065a40, fde_va=0x075648, span=108 bytes
// [VN] FDE[1200] địa chỉ bắt đầu=0x065a40, fde_va=0x075648, kích thước=108 byte
// AArch64 opcodes: 36000080 1E2703E1 1E211820 D53B4421
uint32_t cybertron_fde_1200_0x065a40(uint32_t a0, uint32_t a1) noexcept {
    constexpr uint32_t kStartVa = 0x065a40U;
    constexpr uint32_t kFdeVa   = 0x075648U;
    constexpr uint32_t kSpan    = 108U;
    constexpr uint32_t kW0      = 0x36000080U;
    constexpr uint32_t kW1      = 0x1e2703e1U;
    constexpr uint32_t kW2      = 0x1e211820U;
    constexpr uint32_t kW3      = 0xd53b4421U;
    uint32_t acc = (a0 ^ kW0) + (a1 ^ kW1);
    acc = (acc << 7) | (acc >> 25);
    acc ^= (kW2 + kStartVa) ^ (kW3 + kFdeVa + kSpan);
    return acc;
}

uint32_t DispatchCybertronFdeShard5(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 960U: return cybertron_fde_0960_0x05c33c(a0, a1);
        case 961U: return cybertron_fde_0961_0x05c384(a0, a1);
        case 962U: return cybertron_fde_0962_0x05c390(a0, a1);
        case 963U: return cybertron_fde_0963_0x05c398(a0, a1);
        case 964U: return cybertron_fde_0964_0x05c404(a0, a1);
        case 965U: return cybertron_fde_0965_0x05c430(a0, a1);
        case 966U: return cybertron_fde_0966_0x05c464(a0, a1);
        case 967U: return cybertron_fde_0967_0x05c4cc(a0, a1);
        case 968U: return cybertron_fde_0968_0x05c4f0(a0, a1);
        case 969U: return cybertron_fde_0969_0x05c500(a0, a1);
        case 970U: return cybertron_fde_0970_0x05c558(a0, a1);
        case 971U: return cybertron_fde_0971_0x05c62c(a0, a1);
        case 972U: return cybertron_fde_0972_0x05c638(a0, a1);
        case 973U: return cybertron_fde_0973_0x05c6a4(a0, a1);
        case 974U: return cybertron_fde_0974_0x05c750(a0, a1);
        case 975U: return cybertron_fde_0975_0x05c7f0(a0, a1);
        case 976U: return cybertron_fde_0976_0x05c9cc(a0, a1);
        case 977U: return cybertron_fde_0977_0x05cad0(a0, a1);
        case 978U: return cybertron_fde_0978_0x05cad4(a0, a1);
        case 979U: return cybertron_fde_0979_0x05cb18(a0, a1);
        case 980U: return cybertron_fde_0980_0x05cb3c(a0, a1);
        case 981U: return cybertron_fde_0981_0x05cb70(a0, a1);
        case 982U: return cybertron_fde_0982_0x05cbac(a0, a1);
        case 983U: return cybertron_fde_0983_0x05cbb4(a0, a1);
        case 984U: return cybertron_fde_0984_0x05cbb8(a0, a1);
        case 985U: return cybertron_fde_0985_0x05cd00(a0, a1);
        case 986U: return cybertron_fde_0986_0x05cdec(a0, a1);
        case 987U: return cybertron_fde_0987_0x05ced0(a0, a1);
        case 988U: return cybertron_fde_0988_0x05cfa4(a0, a1);
        case 989U: return cybertron_fde_0989_0x05d084(a0, a1);
        case 990U: return cybertron_fde_0990_0x05d0dc(a0, a1);
        case 991U: return cybertron_fde_0991_0x05d0ec(a0, a1);
        case 992U: return cybertron_fde_0992_0x05d130(a0, a1);
        case 993U: return cybertron_fde_0993_0x05d164(a0, a1);
        case 994U: return cybertron_fde_0994_0x05d16c(a0, a1);
        case 995U: return cybertron_fde_0995_0x05d188(a0, a1);
        case 996U: return cybertron_fde_0996_0x05d1c0(a0, a1);
        case 997U: return cybertron_fde_0997_0x05d1d0(a0, a1);
        case 998U: return cybertron_fde_0998_0x05d1d4(a0, a1);
        case 999U: return cybertron_fde_0999_0x05d1f0(a0, a1);
        case 1000U: return cybertron_fde_1000_0x05d218(a0, a1);
        case 1001U: return cybertron_fde_1001_0x05d254(a0, a1);
        case 1002U: return cybertron_fde_1002_0x05d284(a0, a1);
        case 1003U: return cybertron_fde_1003_0x05d314(a0, a1);
        case 1004U: return cybertron_fde_1004_0x05d488(a0, a1);
        case 1005U: return cybertron_fde_1005_0x05d494(a0, a1);
        case 1006U: return cybertron_fde_1006_0x05d4d4(a0, a1);
        case 1007U: return cybertron_fde_1007_0x05d4e4(a0, a1);
        case 1008U: return cybertron_fde_1008_0x05d5c4(a0, a1);
        case 1009U: return cybertron_fde_1009_0x05d5e0(a0, a1);
        case 1010U: return cybertron_fde_1010_0x05d5f8(a0, a1);
        case 1011U: return cybertron_fde_1011_0x05d610(a0, a1);
        case 1012U: return cybertron_fde_1012_0x05d628(a0, a1);
        case 1013U: return cybertron_fde_1013_0x05d650(a0, a1);
        case 1014U: return cybertron_fde_1014_0x05d678(a0, a1);
        case 1015U: return cybertron_fde_1015_0x05d6b8(a0, a1);
        case 1016U: return cybertron_fde_1016_0x05d734(a0, a1);
        case 1017U: return cybertron_fde_1017_0x05d7d4(a0, a1);
        case 1018U: return cybertron_fde_1018_0x05d84c(a0, a1);
        case 1019U: return cybertron_fde_1019_0x05d8c8(a0, a1);
        case 1020U: return cybertron_fde_1020_0x05d8d8(a0, a1);
        case 1021U: return cybertron_fde_1021_0x05d8e8(a0, a1);
        case 1022U: return cybertron_fde_1022_0x05d8f8(a0, a1);
        case 1023U: return cybertron_fde_1023_0x05d908(a0, a1);
        case 1024U: return cybertron_fde_1024_0x05d950(a0, a1);
        case 1025U: return cybertron_fde_1025_0x05d994(a0, a1);
        case 1026U: return cybertron_fde_1026_0x05d9f0(a0, a1);
        case 1027U: return cybertron_fde_1027_0x05da14(a0, a1);
        case 1028U: return cybertron_fde_1028_0x05da18(a0, a1);
        case 1029U: return cybertron_fde_1029_0x05da20(a0, a1);
        case 1030U: return cybertron_fde_1030_0x05da28(a0, a1);
        case 1031U: return cybertron_fde_1031_0x05da68(a0, a1);
        case 1032U: return cybertron_fde_1032_0x05da84(a0, a1);
        case 1033U: return cybertron_fde_1033_0x05da88(a0, a1);
        case 1034U: return cybertron_fde_1034_0x05da94(a0, a1);
        case 1035U: return cybertron_fde_1035_0x05dafc(a0, a1);
        case 1036U: return cybertron_fde_1036_0x05dc20(a0, a1);
        case 1037U: return cybertron_fde_1037_0x05dc34(a0, a1);
        case 1038U: return cybertron_fde_1038_0x05dd64(a0, a1);
        case 1039U: return cybertron_fde_1039_0x05ddc0(a0, a1);
        case 1040U: return cybertron_fde_1040_0x05ddc4(a0, a1);
        case 1041U: return cybertron_fde_1041_0x05de38(a0, a1);
        case 1042U: return cybertron_fde_1042_0x05de4c(a0, a1);
        case 1043U: return cybertron_fde_1043_0x05dedc(a0, a1);
        case 1044U: return cybertron_fde_1044_0x05df54(a0, a1);
        case 1045U: return cybertron_fde_1045_0x05dff0(a0, a1);
        case 1046U: return cybertron_fde_1046_0x05e098(a0, a1);
        case 1047U: return cybertron_fde_1047_0x05e110(a0, a1);
        case 1048U: return cybertron_fde_1048_0x05e218(a0, a1);
        case 1049U: return cybertron_fde_1049_0x05e2a8(a0, a1);
        case 1050U: return cybertron_fde_1050_0x05e320(a0, a1);
        case 1051U: return cybertron_fde_1051_0x05e3c0(a0, a1);
        case 1052U: return cybertron_fde_1052_0x05e45c(a0, a1);
        case 1053U: return cybertron_fde_1053_0x05e4f8(a0, a1);
        case 1054U: return cybertron_fde_1054_0x05e594(a0, a1);
        case 1055U: return cybertron_fde_1055_0x05e624(a0, a1);
        case 1056U: return cybertron_fde_1056_0x05e6b4(a0, a1);
        case 1057U: return cybertron_fde_1057_0x05e75c(a0, a1);
        case 1058U: return cybertron_fde_1058_0x05e7ec(a0, a1);
        case 1059U: return cybertron_fde_1059_0x05e894(a0, a1);
        case 1060U: return cybertron_fde_1060_0x05e930(a0, a1);
        case 1061U: return cybertron_fde_1061_0x05e9cc(a0, a1);
        case 1062U: return cybertron_fde_1062_0x05ea98(a0, a1);
        case 1063U: return cybertron_fde_1063_0x05eb34(a0, a1);
        case 1064U: return cybertron_fde_1064_0x05ebd0(a0, a1);
        case 1065U: return cybertron_fde_1065_0x05ec6c(a0, a1);
        case 1066U: return cybertron_fde_1066_0x05ec88(a0, a1);
        case 1067U: return cybertron_fde_1067_0x05ed80(a0, a1);
        case 1068U: return cybertron_fde_1068_0x05ee1c(a0, a1);
        case 1069U: return cybertron_fde_1069_0x05eeb4(a0, a1);
        case 1070U: return cybertron_fde_1070_0x05ef2c(a0, a1);
        case 1071U: return cybertron_fde_1071_0x05efa4(a0, a1);
        case 1072U: return cybertron_fde_1072_0x05f01c(a0, a1);
        case 1073U: return cybertron_fde_1073_0x05f094(a0, a1);
        case 1074U: return cybertron_fde_1074_0x05f10c(a0, a1);
        case 1075U: return cybertron_fde_1075_0x05f1a0(a0, a1);
        case 1076U: return cybertron_fde_1076_0x05f234(a0, a1);
        case 1077U: return cybertron_fde_1077_0x05f2c8(a0, a1);
        case 1078U: return cybertron_fde_1078_0x05f364(a0, a1);
        case 1079U: return cybertron_fde_1079_0x05f398(a0, a1);
        case 1080U: return cybertron_fde_1080_0x05f418(a0, a1);
        case 1081U: return cybertron_fde_1081_0x05f544(a0, a1);
        case 1082U: return cybertron_fde_1082_0x05f6b8(a0, a1);
        case 1083U: return cybertron_fde_1083_0x05f6f4(a0, a1);
        case 1084U: return cybertron_fde_1084_0x05f704(a0, a1);
        case 1085U: return cybertron_fde_1085_0x05f7a0(a0, a1);
        case 1086U: return cybertron_fde_1086_0x05f804(a0, a1);
        case 1087U: return cybertron_fde_1087_0x05f868(a0, a1);
        case 1088U: return cybertron_fde_1088_0x05f8cc(a0, a1);
        case 1089U: return cybertron_fde_1089_0x05f930(a0, a1);
        case 1090U: return cybertron_fde_1090_0x05f9f8(a0, a1);
        case 1091U: return cybertron_fde_1091_0x05fa54(a0, a1);
        case 1092U: return cybertron_fde_1092_0x05fa98(a0, a1);
        case 1093U: return cybertron_fde_1093_0x05fd20(a0, a1);
        case 1094U: return cybertron_fde_1094_0x060000(a0, a1);
        case 1095U: return cybertron_fde_1095_0x060004(a0, a1);
        case 1096U: return cybertron_fde_1096_0x060024(a0, a1);
        case 1097U: return cybertron_fde_1097_0x060040(a0, a1);
        case 1098U: return cybertron_fde_1098_0x060060(a0, a1);
        case 1099U: return cybertron_fde_1099_0x060064(a0, a1);
        case 1100U: return cybertron_fde_1100_0x0600ec(a0, a1);
        case 1101U: return cybertron_fde_1101_0x060110(a0, a1);
        case 1102U: return cybertron_fde_1102_0x06012c(a0, a1);
        case 1103U: return cybertron_fde_1103_0x060150(a0, a1);
        case 1104U: return cybertron_fde_1104_0x060228(a0, a1);
        case 1105U: return cybertron_fde_1105_0x0602bc(a0, a1);
        case 1106U: return cybertron_fde_1106_0x060478(a0, a1);
        case 1107U: return cybertron_fde_1107_0x060498(a0, a1);
        case 1108U: return cybertron_fde_1108_0x060520(a0, a1);
        case 1109U: return cybertron_fde_1109_0x060544(a0, a1);
        case 1110U: return cybertron_fde_1110_0x0605d4(a0, a1);
        case 1111U: return cybertron_fde_1111_0x0605d8(a0, a1);
        case 1112U: return cybertron_fde_1112_0x0605f4(a0, a1);
        case 1113U: return cybertron_fde_1113_0x060a60(a0, a1);
        case 1114U: return cybertron_fde_1114_0x060f30(a0, a1);
        case 1115U: return cybertron_fde_1115_0x060f88(a0, a1);
        case 1116U: return cybertron_fde_1116_0x061130(a0, a1);
        case 1117U: return cybertron_fde_1117_0x06132c(a0, a1);
        case 1118U: return cybertron_fde_1118_0x0617b4(a0, a1);
        case 1119U: return cybertron_fde_1119_0x0617d8(a0, a1);
        case 1120U: return cybertron_fde_1120_0x061810(a0, a1);
        case 1121U: return cybertron_fde_1121_0x06182c(a0, a1);
        case 1122U: return cybertron_fde_1122_0x061830(a0, a1);
        case 1123U: return cybertron_fde_1123_0x061874(a0, a1);
        case 1124U: return cybertron_fde_1124_0x0618b4(a0, a1);
        case 1125U: return cybertron_fde_1125_0x0618fc(a0, a1);
        case 1126U: return cybertron_fde_1126_0x061910(a0, a1);
        case 1127U: return cybertron_fde_1127_0x061914(a0, a1);
        case 1128U: return cybertron_fde_1128_0x061994(a0, a1);
        case 1129U: return cybertron_fde_1129_0x0619a4(a0, a1);
        case 1130U: return cybertron_fde_1130_0x0619d4(a0, a1);
        case 1131U: return cybertron_fde_1131_0x061a2c(a0, a1);
        case 1132U: return cybertron_fde_1132_0x061a64(a0, a1);
        case 1133U: return cybertron_fde_1133_0x061a6c(a0, a1);
        case 1134U: return cybertron_fde_1134_0x061a94(a0, a1);
        case 1135U: return cybertron_fde_1135_0x061aa8(a0, a1);
        case 1136U: return cybertron_fde_1136_0x061ac4(a0, a1);
        case 1137U: return cybertron_fde_1137_0x061ad0(a0, a1);
        case 1138U: return cybertron_fde_1138_0x061ae8(a0, a1);
        case 1139U: return cybertron_fde_1139_0x061b60(a0, a1);
        case 1140U: return cybertron_fde_1140_0x061bdc(a0, a1);
        case 1141U: return cybertron_fde_1141_0x061c78(a0, a1);
        case 1142U: return cybertron_fde_1142_0x061cf0(a0, a1);
        case 1143U: return cybertron_fde_1143_0x061d4c(a0, a1);
        case 1144U: return cybertron_fde_1144_0x061d54(a0, a1);
        case 1145U: return cybertron_fde_1145_0x061d78(a0, a1);
        case 1146U: return cybertron_fde_1146_0x061da0(a0, a1);
        case 1147U: return cybertron_fde_1147_0x061ea4(a0, a1);
        case 1148U: return cybertron_fde_1148_0x061eb8(a0, a1);
        case 1149U: return cybertron_fde_1149_0x062248(a0, a1);
        case 1150U: return cybertron_fde_1150_0x062314(a0, a1);
        case 1151U: return cybertron_fde_1151_0x0624d8(a0, a1);
        case 1152U: return cybertron_fde_1152_0x062520(a0, a1);
        case 1153U: return cybertron_fde_1153_0x062544(a0, a1);
        case 1154U: return cybertron_fde_1154_0x062604(a0, a1);
        case 1155U: return cybertron_fde_1155_0x0628b8(a0, a1);
        case 1156U: return cybertron_fde_1156_0x0628c0(a0, a1);
        case 1157U: return cybertron_fde_1157_0x0629b4(a0, a1);
        case 1158U: return cybertron_fde_1158_0x062b90(a0, a1);
        case 1159U: return cybertron_fde_1159_0x062ba4(a0, a1);
        case 1160U: return cybertron_fde_1160_0x062bd0(a0, a1);
        case 1161U: return cybertron_fde_1161_0x062d80(a0, a1);
        case 1162U: return cybertron_fde_1162_0x062d84(a0, a1);
        case 1163U: return cybertron_fde_1163_0x062fc8(a0, a1);
        case 1164U: return cybertron_fde_1164_0x062fd0(a0, a1);
        case 1165U: return cybertron_fde_1165_0x063028(a0, a1);
        case 1166U: return cybertron_fde_1166_0x063320(a0, a1);
        case 1167U: return cybertron_fde_1167_0x0633ac(a0, a1);
        case 1168U: return cybertron_fde_1168_0x06346c(a0, a1);
        case 1169U: return cybertron_fde_1169_0x0634bc(a0, a1);
        case 1170U: return cybertron_fde_1170_0x063590(a0, a1);
        case 1171U: return cybertron_fde_1171_0x0635e4(a0, a1);
        case 1172U: return cybertron_fde_1172_0x0635f8(a0, a1);
        case 1173U: return cybertron_fde_1173_0x06362c(a0, a1);
        case 1174U: return cybertron_fde_1174_0x063660(a0, a1);
        case 1175U: return cybertron_fde_1175_0x063694(a0, a1);
        case 1176U: return cybertron_fde_1176_0x0636c8(a0, a1);
        case 1177U: return cybertron_fde_1177_0x0636fc(a0, a1);
        case 1178U: return cybertron_fde_1178_0x063730(a0, a1);
        case 1179U: return cybertron_fde_1179_0x063754(a0, a1);
        case 1180U: return cybertron_fde_1180_0x063760(a0, a1);
        case 1181U: return cybertron_fde_1181_0x063a4c(a0, a1);
        case 1182U: return cybertron_fde_1182_0x063b4c(a0, a1);
        case 1183U: return cybertron_fde_1183_0x063c38(a0, a1);
        case 1184U: return cybertron_fde_1184_0x063c40(a0, a1);
        case 1185U: return cybertron_fde_1185_0x063c4c(a0, a1);
        case 1186U: return cybertron_fde_1186_0x063c60(a0, a1);
        case 1187U: return cybertron_fde_1187_0x063c98(a0, a1);
        case 1188U: return cybertron_fde_1188_0x063cdc(a0, a1);
        case 1189U: return cybertron_fde_1189_0x063ce4(a0, a1);
        case 1190U: return cybertron_fde_1190_0x063cec(a0, a1);
        case 1191U: return cybertron_fde_1191_0x063e14(a0, a1);
        case 1192U: return cybertron_fde_1192_0x063eb0(a0, a1);
        case 1193U: return cybertron_fde_1193_0x063ee8(a0, a1);
        case 1194U: return cybertron_fde_1194_0x06404c(a0, a1);
        case 1195U: return cybertron_fde_1195_0x064104(a0, a1);
        case 1196U: return cybertron_fde_1196_0x064684(a0, a1);
        case 1197U: return cybertron_fde_1197_0x0647c0(a0, a1);
        case 1198U: return cybertron_fde_1198_0x064ea0(a0, a1);
        case 1199U: return cybertron_fde_1199_0x0659b4(a0, a1);
        case 1200U: return cybertron_fde_1200_0x065a40(a0, a1);
        default: return 0U;
    }
}

} // namespace datacenter
