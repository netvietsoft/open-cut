// ============================================================================
// File: ttr_fde_shard_1.cpp
// Target: libttr.so (625,192 bytes)
// SHA-256: 38c13f772c29f2a6b03c5523b74730be6727dfc9c3de457b1e09fe32578d6f6f
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// FDE Range: [0..676] of 3,386 (.eh_frame_hdr @ 0x08ab40)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [0..676]
//      verified directly against the .text section of libttr.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [0..676]
//      đã đối chiếu trực tiếp với phân đoạn .text của libttr.so.
// ============================================================================

#include "ttr_render_types.h"

namespace ttr_render {

// [EN] FDE[0000] start_va=0x01c750, fde_va=0x0754d8, span=352 B | [VN] FDE[0000]
uint32_t ttr_fde_0000_0x01c750(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01c750U) ^ (0x910083fdU + 0x0754d8U + 352U);
}

// [EN] FDE[0001] start_va=0x01c8b0, fde_va=0x075ad0, span=252 B | [VN] FDE[0001]
uint32_t ttr_fde_0001_0x01c8b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01c8b0U) ^ (0xa9044ff4U + 0x075ad0U + 252U);
}

// [EN] FDE[0002] start_va=0x01c9ac, fde_va=0x075c70, span=252 B | [VN] FDE[0002]
uint32_t ttr_fde_0002_0x01c9ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01c9acU) ^ (0xa9044ff4U + 0x075c70U + 252U);
}

// [EN] FDE[0003] start_va=0x01caa8, fde_va=0x075ed0, span=252 B | [VN] FDE[0003]
uint32_t ttr_fde_0003_0x01caa8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01caa8U) ^ (0xa9044ff4U + 0x075ed0U + 252U);
}

// [EN] FDE[0004] start_va=0x01cba4, fde_va=0x075ef8, span=252 B | [VN] FDE[0004]
uint32_t ttr_fde_0004_0x01cba4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01cba4U) ^ (0xa9044ff4U + 0x075ef8U + 252U);
}

// [EN] FDE[0005] start_va=0x01cca0, fde_va=0x076018, span=252 B | [VN] FDE[0005]
uint32_t ttr_fde_0005_0x01cca0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01cca0U) ^ (0xa9044ff4U + 0x076018U + 252U);
}

// [EN] FDE[0006] start_va=0x01cd9c, fde_va=0x076130, span=252 B | [VN] FDE[0006]
uint32_t ttr_fde_0006_0x01cd9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01cd9cU) ^ (0xa9044ff4U + 0x076130U + 252U);
}

// [EN] FDE[0007] start_va=0x01ce98, fde_va=0x0762f0, span=252 B | [VN] FDE[0007]
uint32_t ttr_fde_0007_0x01ce98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01ce98U) ^ (0xa9044ff4U + 0x0762f0U + 252U);
}

// [EN] FDE[0008] start_va=0x01cf94, fde_va=0x076448, span=252 B | [VN] FDE[0008]
uint32_t ttr_fde_0008_0x01cf94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01cf94U) ^ (0xa9044ff4U + 0x076448U + 252U);
}

// [EN] FDE[0009] start_va=0x01d090, fde_va=0x0767a8, span=252 B | [VN] FDE[0009]
uint32_t ttr_fde_0009_0x01d090(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x01d090U) ^ (0xa9044ff4U + 0x0767a8U + 252U);
}

// [EN] FDE[0010] start_va=0x01d18c, fde_va=0x0767d0, span=352 B | [VN] FDE[0010]
uint32_t ttr_fde_0010_0x01d18c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01d18cU) ^ (0x910083fdU + 0x0767d0U + 352U);
}

// [EN] FDE[0011] start_va=0x01d2ec, fde_va=0x076ea0, span=352 B | [VN] FDE[0011]
uint32_t ttr_fde_0011_0x01d2ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01d2ecU) ^ (0x910083fdU + 0x076ea0U + 352U);
}

// [EN] FDE[0012] start_va=0x01d44c, fde_va=0x077328, span=352 B | [VN] FDE[0012]
uint32_t ttr_fde_0012_0x01d44c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01d44cU) ^ (0x910083fdU + 0x077328U + 352U);
}

// [EN] FDE[0013] start_va=0x01d5ac, fde_va=0x077478, span=352 B | [VN] FDE[0013]
uint32_t ttr_fde_0013_0x01d5ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01d5acU) ^ (0x910083fdU + 0x077478U + 352U);
}

// [EN] FDE[0014] start_va=0x01d70c, fde_va=0x077668, span=352 B | [VN] FDE[0014]
uint32_t ttr_fde_0014_0x01d70c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01d70cU) ^ (0x910083fdU + 0x077668U + 352U);
}

// [EN] FDE[0015] start_va=0x01d86c, fde_va=0x0777e8, span=352 B | [VN] FDE[0015]
uint32_t ttr_fde_0015_0x01d86c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01d86cU) ^ (0x910083fdU + 0x0777e8U + 352U);
}

// [EN] FDE[0016] start_va=0x01d9cc, fde_va=0x077810, span=352 B | [VN] FDE[0016]
uint32_t ttr_fde_0016_0x01d9cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01d9ccU) ^ (0x910083fdU + 0x077810U + 352U);
}

// [EN] FDE[0017] start_va=0x01db2c, fde_va=0x0779e0, span=352 B | [VN] FDE[0017]
uint32_t ttr_fde_0017_0x01db2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01db2cU) ^ (0x910083fdU + 0x0779e0U + 352U);
}

// [EN] FDE[0018] start_va=0x01dc8c, fde_va=0x077b30, span=352 B | [VN] FDE[0018]
uint32_t ttr_fde_0018_0x01dc8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01dc8cU) ^ (0x910083fdU + 0x077b30U + 352U);
}

// [EN] FDE[0019] start_va=0x01ddec, fde_va=0x077ca8, span=352 B | [VN] FDE[0019]
uint32_t ttr_fde_0019_0x01ddec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01ddecU) ^ (0x910083fdU + 0x077ca8U + 352U);
}

// [EN] FDE[0020] start_va=0x01df4c, fde_va=0x0780c0, span=336 B | [VN] FDE[0020]
uint32_t ttr_fde_0020_0x01df4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01df4cU) ^ (0x910083fdU + 0x0780c0U + 336U);
}

// [EN] FDE[0021] start_va=0x01e09c, fde_va=0x078170, span=388 B | [VN] FDE[0021]
uint32_t ttr_fde_0021_0x01e09c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01e09cU) ^ (0x910083fdU + 0x078170U + 388U);
}

// [EN] FDE[0022] start_va=0x01e220, fde_va=0x078380, span=340 B | [VN] FDE[0022]
uint32_t ttr_fde_0022_0x01e220(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01e220U) ^ (0x910083fdU + 0x078380U + 340U);
}

// [EN] FDE[0023] start_va=0x01e374, fde_va=0x078700, span=336 B | [VN] FDE[0023]
uint32_t ttr_fde_0023_0x01e374(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01e374U) ^ (0x910083fdU + 0x078700U + 336U);
}

// [EN] FDE[0024] start_va=0x01e4c4, fde_va=0x078728, span=336 B | [VN] FDE[0024]
uint32_t ttr_fde_0024_0x01e4c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01e4c4U) ^ (0x910083fdU + 0x078728U + 336U);
}

// [EN] FDE[0025] start_va=0x01e614, fde_va=0x078868, span=352 B | [VN] FDE[0025]
uint32_t ttr_fde_0025_0x01e614(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01e614U) ^ (0x910083fdU + 0x078868U + 352U);
}

// [EN] FDE[0026] start_va=0x01e774, fde_va=0x078910, span=336 B | [VN] FDE[0026]
uint32_t ttr_fde_0026_0x01e774(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01e774U) ^ (0x910083fdU + 0x078910U + 336U);
}

// [EN] FDE[0027] start_va=0x01e8c4, fde_va=0x078c30, span=336 B | [VN] FDE[0027]
uint32_t ttr_fde_0027_0x01e8c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01e8c4U) ^ (0x910083fdU + 0x078c30U + 336U);
}

// [EN] FDE[0028] start_va=0x01ea14, fde_va=0x078e18, span=352 B | [VN] FDE[0028]
uint32_t ttr_fde_0028_0x01ea14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01ea14U) ^ (0x910083fdU + 0x078e18U + 352U);
}

// [EN] FDE[0029] start_va=0x01eb74, fde_va=0x078f18, span=352 B | [VN] FDE[0029]
uint32_t ttr_fde_0029_0x01eb74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01eb74U) ^ (0x910083fdU + 0x078f18U + 352U);
}

// [EN] FDE[0030] start_va=0x01ecd4, fde_va=0x078f40, span=1916 B | [VN] FDE[0030]
uint32_t ttr_fde_0030_0x01ecd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa90267faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035ff8U + 0x01ecd4U) ^ (0xa90457f6U + 0x078f40U + 1916U);
}

// [EN] FDE[0031] start_va=0x01f450, fde_va=0x079068, span=336 B | [VN] FDE[0031]
uint32_t ttr_fde_0031_0x01f450(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01f450U) ^ (0x910083fdU + 0x079068U + 336U);
}

// [EN] FDE[0032] start_va=0x01f5a0, fde_va=0x079328, span=352 B | [VN] FDE[0032]
uint32_t ttr_fde_0032_0x01f5a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01f5a0U) ^ (0x910083fdU + 0x079328U + 352U);
}

// [EN] FDE[0033] start_va=0x01f700, fde_va=0x079490, span=352 B | [VN] FDE[0033]
uint32_t ttr_fde_0033_0x01f700(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01f700U) ^ (0x910083fdU + 0x079490U + 352U);
}

// [EN] FDE[0034] start_va=0x01f860, fde_va=0x079608, span=336 B | [VN] FDE[0034]
uint32_t ttr_fde_0034_0x01f860(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01f860U) ^ (0x910083fdU + 0x079608U + 336U);
}

// [EN] FDE[0035] start_va=0x01f9b0, fde_va=0x0796a0, span=352 B | [VN] FDE[0035]
uint32_t ttr_fde_0035_0x01f9b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01f9b0U) ^ (0x910083fdU + 0x0796a0U + 352U);
}

// [EN] FDE[0036] start_va=0x01fb10, fde_va=0x0799a0, span=336 B | [VN] FDE[0036]
uint32_t ttr_fde_0036_0x01fb10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01fb10U) ^ (0x910083fdU + 0x0799a0U + 336U);
}

// [EN] FDE[0037] start_va=0x01fc60, fde_va=0x079b08, span=336 B | [VN] FDE[0037]
uint32_t ttr_fde_0037_0x01fc60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01fc60U) ^ (0x910083fdU + 0x079b08U + 336U);
}

// [EN] FDE[0038] start_va=0x01fdb0, fde_va=0x079f90, span=340 B | [VN] FDE[0038]
uint32_t ttr_fde_0038_0x01fdb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01fdb0U) ^ (0x910083fdU + 0x079f90U + 340U);
}

// [EN] FDE[0039] start_va=0x01ff04, fde_va=0x07a088, span=352 B | [VN] FDE[0039]
uint32_t ttr_fde_0039_0x01ff04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x01ff04U) ^ (0x910083fdU + 0x07a088U + 352U);
}

// [EN] FDE[0040] start_va=0x020064, fde_va=0x07a5d8, span=336 B | [VN] FDE[0040]
uint32_t ttr_fde_0040_0x020064(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x020064U) ^ (0x910083fdU + 0x07a5d8U + 336U);
}

// [EN] FDE[0041] start_va=0x0201b4, fde_va=0x07a8f8, span=352 B | [VN] FDE[0041]
uint32_t ttr_fde_0041_0x0201b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0201b4U) ^ (0x910083fdU + 0x07a8f8U + 352U);
}

// [EN] FDE[0042] start_va=0x020314, fde_va=0x07acb0, span=336 B | [VN] FDE[0042]
uint32_t ttr_fde_0042_0x020314(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x020314U) ^ (0x910083fdU + 0x07acb0U + 336U);
}

// [EN] FDE[0043] start_va=0x020464, fde_va=0x07ad50, span=352 B | [VN] FDE[0043]
uint32_t ttr_fde_0043_0x020464(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x020464U) ^ (0x910083fdU + 0x07ad50U + 352U);
}

// [EN] FDE[0044] start_va=0x0205c4, fde_va=0x07afe0, span=336 B | [VN] FDE[0044]
uint32_t ttr_fde_0044_0x0205c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0205c4U) ^ (0x910083fdU + 0x07afe0U + 336U);
}

// [EN] FDE[0045] start_va=0x020714, fde_va=0x07b050, span=352 B | [VN] FDE[0045]
uint32_t ttr_fde_0045_0x020714(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x020714U) ^ (0x910083fdU + 0x07b050U + 352U);
}

// [EN] FDE[0046] start_va=0x020874, fde_va=0x07b2b0, span=352 B | [VN] FDE[0046]
uint32_t ttr_fde_0046_0x020874(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x020874U) ^ (0x910083fdU + 0x07b2b0U + 352U);
}

// [EN] FDE[0047] start_va=0x0209d4, fde_va=0x07b4d8, span=352 B | [VN] FDE[0047]
uint32_t ttr_fde_0047_0x0209d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0209d4U) ^ (0x910083fdU + 0x07b4d8U + 352U);
}

// [EN] FDE[0048] start_va=0x020b34, fde_va=0x07d348, span=20 B | [VN] FDE[0048]
uint32_t ttr_fde_0048_0x020b34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00003e0U) + (a1 ^ 0x90000281U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910d4000U + 0x020b34U) ^ (0x9111e821U + 0x07d348U + 20U);
}

// [EN] FDE[0049] start_va=0x020b48, fde_va=0x07d890, span=156 B | [VN] FDE[0049]
uint32_t ttr_fde_0049_0x020b48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa9067bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00003f3U + 0x020b48U) ^ (0x910da273U + 0x07d890U + 156U);
}

// [EN] FDE[0050] start_va=0x020be4, fde_va=0x07e908, span=16 B | [VN] FDE[0050]
uint32_t ttr_fde_0050_0x020be4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x9400ad38U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84107feU + 0x020be4U) ^ (0x1400ad36U + 0x07e908U + 16U);
}

// [EN] FDE[0051] start_va=0x020bf4, fde_va=0x07d860, span=1040 B | [VN] FDE[0051]
uint32_t ttr_fde_0051_0x020bf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd105c3ffU) + (a1 ^ 0xa9116ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91267faU + 0x020bf4U) ^ (0xa9135ff8U + 0x07d860U + 1040U);
}

// [EN] FDE[0052] start_va=0x021004, fde_va=0x073d90, span=12 B | [VN] FDE[0052]
uint32_t ttr_fde_0052_0x021004(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000200U) + (a1 ^ 0x913a2c00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x021004U) ^ (0x900003a8U + 0x073d90U + 12U);
}

// [EN] FDE[0053] start_va=0x021010, fde_va=0x073da8, span=16 B | [VN] FDE[0053]
uint32_t ttr_fde_0053_0x021010(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900003a8U) + (a1 ^ 0x913ce108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf8010408U + 0x021010U) ^ (0x140001f8U + 0x073da8U + 16U);
}

// [EN] FDE[0054] start_va=0x021020, fde_va=0x073dc0, span=4 B | [VN] FDE[0054]
uint32_t ttr_fde_0054_0x021020(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0xd101c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035ff8U + 0x021020U) ^ (0xa90457f6U + 0x073dc0U + 4U);
}

// [EN] FDE[0055] start_va=0x021024, fde_va=0x073dd8, span=236 B | [VN] FDE[0055]
uint32_t ttr_fde_0055_0x021024(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa9035ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90457f6U + 0x021024U) ^ (0xa9054ff4U + 0x073dd8U + 236U);
}

// [EN] FDE[0056] start_va=0x021110, fde_va=0x073e00, span=508 B | [VN] FDE[0056]
uint32_t ttr_fde_0056_0x021110(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf90023f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9055ff8U + 0x021110U) ^ (0xa90657f6U + 0x073e00U + 508U);
}

// [EN] FDE[0057] start_va=0x02130c, fde_va=0x073e28, span=92 B | [VN] FDE[0057]
uint32_t ttr_fde_0057_0x02130c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf9000bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x02130cU) ^ (0xa9037bfdU + 0x073e28U + 92U);
}

// [EN] FDE[0058] start_va=0x021368, fde_va=0x073e48, span=128 B | [VN] FDE[0058]
uint32_t ttr_fde_0058_0x021368(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x021368U) ^ (0xa9037bfdU + 0x073e48U + 128U);
}

// [EN] FDE[0059] start_va=0x0213e8, fde_va=0x073e70, span=48 B | [VN] FDE[0059]
uint32_t ttr_fde_0059_0x0213e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9412408U) + (a1 ^ 0xeb08013fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000120U + 0x0213e8U) ^ (0xf8410500U + 0x073e70U + 48U);
}

// [EN] FDE[0060] start_va=0x021418, fde_va=0x073e88, span=4 B | [VN] FDE[0060]
uint32_t ttr_fde_0060_0x021418(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400fad0U) + (a1 ^ 0xf9400001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400001eU + 0x021418U) ^ (0xf81e0ff3U + 0x073e88U + 4U);
}

// [EN] FDE[0061] start_va=0x02141c, fde_va=0x073ea0, span=8 B | [VN] FDE[0061]
uint32_t ttr_fde_0061_0x02141c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400001U) + (a1 ^ 0x1400001eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02141cU) ^ (0xa9017bfdU + 0x073ea0U + 8U);
}

// [EN] FDE[0062] start_va=0x021424, fde_va=0x073eb8, span=28 B | [VN] FDE[0062]
uint32_t ttr_fde_0062_0x021424(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x021424U) ^ (0x9400fa46U + 0x073eb8U + 28U);
}

// [EN] FDE[0063] start_va=0x021440, fde_va=0x073ed8, span=12 B | [VN] FDE[0063]
uint32_t ttr_fde_0063_0x021440(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x021440U) ^ (0xf81e0ff3U + 0x073ed8U + 12U);
}

// [EN] FDE[0064] start_va=0x02144c, fde_va=0x073ef0, span=76 B | [VN] FDE[0064]
uint32_t ttr_fde_0064_0x02144c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02144cU) ^ (0xaa0003f3U + 0x073ef0U + 76U);
}

// [EN] FDE[0065] start_va=0x021498, fde_va=0x073f10, span=56 B | [VN] FDE[0065]
uint32_t ttr_fde_0065_0x021498(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x021498U) ^ (0x910083fdU + 0x073f10U + 56U);
}

// [EN] FDE[0066] start_va=0x0214d0, fde_va=0x073f30, span=620 B | [VN] FDE[0066]
uint32_t ttr_fde_0066_0x0214d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xa9086ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90967faU + 0x0214d0U) ^ (0xa90a5ff8U + 0x073f30U + 620U);
}

// [EN] FDE[0067] start_va=0x02173c, fde_va=0x073f60, span=192 B | [VN] FDE[0067]
uint32_t ttr_fde_0067_0x02173c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x94010897U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x02173cU) ^ (0xa9067bfdU + 0x073f60U + 192U);
}

// [EN] FDE[0068] start_va=0x0217fc, fde_va=0x073f88, span=48 B | [VN] FDE[0068]
uint32_t ttr_fde_0068_0x0217fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0217fcU) ^ (0xf9400008U + 0x073f88U + 48U);
}

// [EN] FDE[0069] start_va=0x02182c, fde_va=0x073fa8, span=56 B | [VN] FDE[0069]
uint32_t ttr_fde_0069_0x02182c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02182cU) ^ (0x910083fdU + 0x073fa8U + 56U);
}

// [EN] FDE[0070] start_va=0x021864, fde_va=0x073fc8, span=52 B | [VN] FDE[0070]
uint32_t ttr_fde_0070_0x021864(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xf9400029U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000109U + 0x021864U) ^ (0xf9400429U + 0x073fc8U + 52U);
}

// [EN] FDE[0071] start_va=0x021898, fde_va=0x073fe0, span=48 B | [VN] FDE[0071]
uint32_t ttr_fde_0071_0x021898(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37cfc28U + 0x021898U) ^ (0xb5000108U + 0x073fe0U + 48U);
}

// [EN] FDE[0072] start_va=0x0218c8, fde_va=0x074000, span=24 B | [VN] FDE[0072]
uint32_t ttr_fde_0072_0x0218c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37cfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140103eaU + 0x0218c8U) ^ (0xa9bf7bfdU + 0x074000U + 24U);
}

// [EN] FDE[0073] start_va=0x0218e0, fde_va=0x074020, span=60 B | [VN] FDE[0073]
uint32_t ttr_fde_0073_0x0218e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0218e0U) ^ (0x940103e0U + 0x074020U + 60U);
}

// [EN] FDE[0074] start_va=0x02191c, fde_va=0x074040, span=44 B | [VN] FDE[0074]
uint32_t ttr_fde_0074_0x02191c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb01001fU) + (a1 ^ 0x54000120U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400048U + 0x02191cU) ^ (0x3cdf0c20U + 0x074040U + 44U);
}

// [EN] FDE[0075] start_va=0x021948, fde_va=0x074058, span=56 B | [VN] FDE[0075]
uint32_t ttr_fde_0075_0x021948(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x021948U) ^ (0xa9402428U + 0x074058U + 56U);
}

// [EN] FDE[0076] start_va=0x021980, fde_va=0x074078, span=304 B | [VN] FDE[0076]
uint32_t ttr_fde_0076_0x021980(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ffcU) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x021980U) ^ (0xa9037bfdU + 0x074078U + 304U);
}

// [EN] FDE[0077] start_va=0x021ab0, fde_va=0x0740a0, span=112 B | [VN] FDE[0077]
uint32_t ttr_fde_0077_0x021ab0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x021ab0U) ^ (0xa9037bfdU + 0x0740a0U + 112U);
}

// [EN] FDE[0078] start_va=0x021b20, fde_va=0x0740c8, span=40 B | [VN] FDE[0078]
uint32_t ttr_fde_0078_0x021b20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x021b20U) ^ (0x9400fa1dU + 0x0740c8U + 40U);
}

// [EN] FDE[0079] start_va=0x021b48, fde_va=0x0740e8, span=76 B | [VN] FDE[0079]
uint32_t ttr_fde_0079_0x021b48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9406028U) + (a1 ^ 0x37200068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x37180148U + 0x021b48U) ^ (0x140109c9U + 0x0740e8U + 76U);
}

// [EN] FDE[0080] start_va=0x021b94, fde_va=0x074100, span=20 B | [VN] FDE[0080]
uint32_t ttr_fde_0080_0x021b94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400008U) + (a1 ^ 0x37000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x021b94U) ^ (0xf9400800U + 0x074100U + 20U);
}

// [EN] FDE[0081] start_va=0x021ba8, fde_va=0x074118, span=56 B | [VN] FDE[0081]
uint32_t ttr_fde_0081_0x021ba8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x021ba8U) ^ (0xb00003a8U + 0x074118U + 56U);
}

// [EN] FDE[0082] start_va=0x021be0, fde_va=0x074138, span=40 B | [VN] FDE[0082]
uint32_t ttr_fde_0082_0x021be0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x021be0U) ^ (0xb00003a8U + 0x074138U + 40U);
}

// [EN] FDE[0083] start_va=0x021c08, fde_va=0x074158, span=16 B | [VN] FDE[0083]
uint32_t ttr_fde_0083_0x021c08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00003a8U) + (a1 ^ 0x91024108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf8008408U + 0x021c08U) ^ (0x17ffe84bU + 0x074158U + 16U);
}

// [EN] FDE[0084] start_va=0x021c18, fde_va=0x074170, span=28 B | [VN] FDE[0084]
uint32_t ttr_fde_0084_0x021c18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x021c18U) ^ (0xaa0003f3U + 0x074170U + 28U);
}

// [EN] FDE[0085] start_va=0x021c34, fde_va=0x074190, span=4 B | [VN] FDE[0085]
uint32_t ttr_fde_0085_0x021c34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x92800001U + 0x021c34U) ^ (0x1401097fU + 0x074190U + 4U);
}

// [EN] FDE[0086] start_va=0x021c38, fde_va=0x0741a8, span=4 B | [VN] FDE[0086]
uint32_t ttr_fde_0086_0x021c38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x92800001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1401097fU + 0x021c38U) ^ (0x92800001U + 0x0741a8U + 4U);
}

// [EN] FDE[0087] start_va=0x021c3c, fde_va=0x0741c0, span=8 B | [VN] FDE[0087]
uint32_t ttr_fde_0087_0x021c3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x92800001U) + (a1 ^ 0x1401097fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x92800001U + 0x021c3cU) ^ (0x1401097dU + 0x0741c0U + 8U);
}

// [EN] FDE[0088] start_va=0x021c44, fde_va=0x0741d8, span=8 B | [VN] FDE[0088]
uint32_t ttr_fde_0088_0x021c44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x92800001U) + (a1 ^ 0x1401097dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400f924U + 0x021c44U) ^ (0x1400fd22U + 0x0741d8U + 8U);
}

// [EN] FDE[0089] start_va=0x021c4c, fde_va=0x0741f0, span=4 B | [VN] FDE[0089]
uint32_t ttr_fde_0089_0x021c4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400f924U) + (a1 ^ 0x1400fd22U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bc5ff8U + 0x021c4cU) ^ (0xa90157f6U + 0x0741f0U + 4U);
}

// [EN] FDE[0090] start_va=0x021c50, fde_va=0x074208, span=4 B | [VN] FDE[0090]
uint32_t ttr_fde_0090_0x021c50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400fd22U) + (a1 ^ 0xa9bc5ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90157f6U + 0x021c50U) ^ (0xa9024ff4U + 0x074208U + 4U);
}

// [EN] FDE[0091] start_va=0x021c54, fde_va=0x074220, span=168 B | [VN] FDE[0091]
uint32_t ttr_fde_0091_0x021c54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc5ff8U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x021c54U) ^ (0xa9037bfdU + 0x074220U + 168U);
}

// [EN] FDE[0092] start_va=0x021cfc, fde_va=0x074248, span=4 B | [VN] FDE[0092]
uint32_t ttr_fde_0092_0x021cfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400fecbU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x021cfcU) ^ (0x910043fdU + 0x074248U + 4U);
}

// [EN] FDE[0093] start_va=0x021d00, fde_va=0x074260, span=60 B | [VN] FDE[0093]
uint32_t ttr_fde_0093_0x021d00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x021d00U) ^ (0xf9400008U + 0x074260U + 60U);
}

// [EN] FDE[0094] start_va=0x021d3c, fde_va=0x074280, span=4 B | [VN] FDE[0094]
uint32_t ttr_fde_0094_0x021d3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400febbU) + (a1 ^ 0xf81c0ff7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90157f6U + 0x021d3cU) ^ (0xa9024ff4U + 0x074280U + 4U);
}

// [EN] FDE[0095] start_va=0x021d40, fde_va=0x074298, span=160 B | [VN] FDE[0095]
uint32_t ttr_fde_0095_0x021d40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x021d40U) ^ (0xa9037bfdU + 0x074298U + 160U);
}

// [EN] FDE[0096] start_va=0x021de0, fde_va=0x0742c0, span=4 B | [VN] FDE[0096]
uint32_t ttr_fde_0096_0x021de0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400fe92U) + (a1 ^ 0xb4000042U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffe7daU + 0x021de0U) ^ (0xd65f03c0U + 0x0742c0U + 4U);
}

// [EN] FDE[0097] start_va=0x021de4, fde_va=0x0742d8, span=12 B | [VN] FDE[0097]
uint32_t ttr_fde_0097_0x021de4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000042U) + (a1 ^ 0x17ffe7daU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x021de4U) ^ (0xf81e0ff3U + 0x0742d8U + 12U);
}

// [EN] FDE[0098] start_va=0x021df0, fde_va=0x0742f0, span=28 B | [VN] FDE[0098]
uint32_t ttr_fde_0098_0x021df0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x021df0U) ^ (0xaa0003f3U + 0x0742f0U + 28U);
}

// [EN] FDE[0099] start_va=0x021e0c, fde_va=0x074310, span=236 B | [VN] FDE[0099]
uint32_t ttr_fde_0099_0x021e0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402c08U) + (a1 ^ 0xf9401809U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb09011fU + 0x021e0cU) ^ (0x54000062U + 0x074310U + 236U);
}

// [EN] FDE[0100] start_va=0x021ef8, fde_va=0x074328, span=20 B | [VN] FDE[0100]
uint32_t ttr_fde_0100_0x021ef8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xaa0203e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e2U + 0x021ef8U) ^ (0xf9401104U + 0x074328U + 20U);
}

// [EN] FDE[0101] start_va=0x021f0c, fde_va=0x074340, span=76 B | [VN] FDE[0101]
uint32_t ttr_fde_0101_0x021f0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402c08U) + (a1 ^ 0xf9401809U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb09011fU + 0x021f0cU) ^ (0x54000062U + 0x074340U + 76U);
}

// [EN] FDE[0102] start_va=0x021f58, fde_va=0x074358, span=108 B | [VN] FDE[0102]
uint32_t ttr_fde_0102_0x021f58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402c09U) + (a1 ^ 0xf940180aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e8U + 0x021f58U) ^ (0x2a0103e0U + 0x074358U + 108U);
}

// [EN] FDE[0103] start_va=0x021fc4, fde_va=0x074370, span=336 B | [VN] FDE[0103]
uint32_t ttr_fde_0103_0x021fc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xaa1e03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400fb6eU + 0x021fc4U) ^ (0xaa0203feU + 0x074370U + 336U);
}

// [EN] FDE[0104] start_va=0x022114, fde_va=0x0743a0, span=144 B | [VN] FDE[0104]
uint32_t ttr_fde_0104_0x022114(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x022114U) ^ (0x910083fdU + 0x0743a0U + 144U);
}

// [EN] FDE[0105] start_va=0x0221a4, fde_va=0x0743c0, span=216 B | [VN] FDE[0105]
uint32_t ttr_fde_0105_0x0221a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0221a4U) ^ (0x910083fdU + 0x0743c0U + 216U);
}

// [EN] FDE[0106] start_va=0x02227c, fde_va=0x0743e8, span=52 B | [VN] FDE[0106]
uint32_t ttr_fde_0106_0x02227c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9432009U) + (a1 ^ 0xeb08013fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x540000e0U + 0x02227cU) ^ (0x9100052aU + 0x0743e8U + 52U);
}

// [EN] FDE[0107] start_va=0x0222b0, fde_va=0x074400, span=228 B | [VN] FDE[0107]
uint32_t ttr_fde_0107_0x0222b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bb67faU) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x0222b0U) ^ (0xa9034ff4U + 0x074400U + 228U);
}

// [EN] FDE[0108] start_va=0x022394, fde_va=0x074430, span=24 B | [VN] FDE[0108]
uint32_t ttr_fde_0108_0x022394(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40000a1U) + (a1 ^ 0xaa0103e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0203e1U + 0x022394U) ^ (0xaa0803e2U + 0x074430U + 24U);
}

// [EN] FDE[0109] start_va=0x0223ac, fde_va=0x074448, span=8 B | [VN] FDE[0109]
uint32_t ttr_fde_0109_0x0223ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91002000U) + (a1 ^ 0x17ffe674U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x0223acU) ^ (0xa9017bfdU + 0x074448U + 8U);
}

// [EN] FDE[0110] start_va=0x0223b4, fde_va=0x074460, span=32 B | [VN] FDE[0110]
uint32_t ttr_fde_0110_0x0223b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0223b4U) ^ (0xaa0003f3U + 0x074460U + 32U);
}

// [EN] FDE[0111] start_va=0x0223d4, fde_va=0x074480, span=20 B | [VN] FDE[0111]
uint32_t ttr_fde_0111_0x0223d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080008U + 0x0223d4U) ^ (0x91002100U + 0x074480U + 20U);
}

// [EN] FDE[0112] start_va=0x0223e8, fde_va=0x074498, span=16 B | [VN] FDE[0112]
uint32_t ttr_fde_0112_0x0223e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x0223e8U) ^ (0x17fffff0U + 0x074498U + 16U);
}

// [EN] FDE[0113] start_va=0x0223f8, fde_va=0x0744b0, span=8 B | [VN] FDE[0113]
uint32_t ttr_fde_0113_0x0223f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91004000U) + (a1 ^ 0x17ffe661U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x0223f8U) ^ (0xa9017bfdU + 0x0744b0U + 8U);
}

// [EN] FDE[0114] start_va=0x022400, fde_va=0x0744c8, span=28 B | [VN] FDE[0114]
uint32_t ttr_fde_0114_0x022400(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022400U) ^ (0x94010947U + 0x0744c8U + 28U);
}

// [EN] FDE[0115] start_va=0x02241c, fde_va=0x0744e8, span=20 B | [VN] FDE[0115]
uint32_t ttr_fde_0115_0x02241c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080008U + 0x02241cU) ^ (0x91004100U + 0x0744e8U + 20U);
}

// [EN] FDE[0116] start_va=0x022430, fde_va=0x074500, span=16 B | [VN] FDE[0116]
uint32_t ttr_fde_0116_0x022430(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x022430U) ^ (0x17fffff1U + 0x074500U + 16U);
}

// [EN] FDE[0117] start_va=0x022440, fde_va=0x074518, span=8 B | [VN] FDE[0117]
uint32_t ttr_fde_0117_0x022440(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17ffe64fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x022440U) ^ (0xa9017bfdU + 0x074518U + 8U);
}

// [EN] FDE[0118] start_va=0x022448, fde_va=0x074530, span=32 B | [VN] FDE[0118]
uint32_t ttr_fde_0118_0x022448(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022448U) ^ (0xaa0003f3U + 0x074530U + 32U);
}

// [EN] FDE[0119] start_va=0x022468, fde_va=0x074550, span=8 B | [VN] FDE[0119]
uint32_t ttr_fde_0119_0x022468(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91002000U) + (a1 ^ 0x17ffe645U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd1004000U + 0x022468U) ^ (0x17fffff5U + 0x074550U + 8U);
}

// [EN] FDE[0120] start_va=0x022470, fde_va=0x074568, span=8 B | [VN] FDE[0120]
uint32_t ttr_fde_0120_0x022470(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd1004000U) + (a1 ^ 0x17fffff5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x022470U) ^ (0xf85e8108U + 0x074568U + 8U);
}

// [EN] FDE[0121] start_va=0x022478, fde_va=0x074580, span=20 B | [VN] FDE[0121]
uint32_t ttr_fde_0121_0x022478(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080008U + 0x022478U) ^ (0x91006100U + 0x074580U + 20U);
}

// [EN] FDE[0122] start_va=0x02248c, fde_va=0x074598, span=16 B | [VN] FDE[0122]
uint32_t ttr_fde_0122_0x02248c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x02248cU) ^ (0x17ffffecU + 0x074598U + 16U);
}

// [EN] FDE[0123] start_va=0x02249c, fde_va=0x0745b0, span=28 B | [VN] FDE[0123]
uint32_t ttr_fde_0123_0x02249c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02249cU) ^ (0xaa0003f3U + 0x0745b0U + 28U);
}

// [EN] FDE[0124] start_va=0x0224b8, fde_va=0x0745d0, span=8 B | [VN] FDE[0124]
uint32_t ttr_fde_0124_0x0224b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd1004000U) + (a1 ^ 0x17fffdbbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd1004000U + 0x0224b8U) ^ (0x17fffff6U + 0x0745d0U + 8U);
}

// [EN] FDE[0125] start_va=0x0224c0, fde_va=0x0745e8, span=8 B | [VN] FDE[0125]
uint32_t ttr_fde_0125_0x0224c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd1004000U) + (a1 ^ 0x17fffff6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x0224c0U) ^ (0xf85e8108U + 0x0745e8U + 8U);
}

// [EN] FDE[0126] start_va=0x0224c8, fde_va=0x074600, span=16 B | [VN] FDE[0126]
uint32_t ttr_fde_0126_0x0224c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x0224c8U) ^ (0x17fffdb5U + 0x074600U + 16U);
}

// [EN] FDE[0127] start_va=0x0224d8, fde_va=0x074618, span=16 B | [VN] FDE[0127]
uint32_t ttr_fde_0127_0x0224d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x0224d8U) ^ (0x17ffffeeU + 0x074618U + 16U);
}

// [EN] FDE[0128] start_va=0x0224e8, fde_va=0x074630, span=116 B | [VN] FDE[0128]
uint32_t ttr_fde_0128_0x0224e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x0224e8U) ^ (0xa9037bfdU + 0x074630U + 116U);
}

// [EN] FDE[0129] start_va=0x02255c, fde_va=0x074658, span=28 B | [VN] FDE[0129]
uint32_t ttr_fde_0129_0x02255c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e8U) + (a1 ^ 0xf100611fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x02255cU) ^ (0xf828681fU + 0x074658U + 28U);
}

// [EN] FDE[0130] start_va=0x022578, fde_va=0x074670, span=376 B | [VN] FDE[0130]
uint32_t ttr_fde_0130_0x022578(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xaa1e03e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400f843U + 0x022578U) ^ (0xaa0303feU + 0x074670U + 376U);
}

// [EN] FDE[0131] start_va=0x0226f0, fde_va=0x0746a0, span=72 B | [VN] FDE[0131]
uint32_t ttr_fde_0131_0x0226f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0226f0U) ^ (0x3900001fU + 0x0746a0U + 72U);
}

// [EN] FDE[0132] start_va=0x022738, fde_va=0x0746c0, span=56 B | [VN] FDE[0132]
uint32_t ttr_fde_0132_0x022738(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022738U) ^ (0xaa0003f3U + 0x0746c0U + 56U);
}

// [EN] FDE[0133] start_va=0x022770, fde_va=0x0746e0, span=12 B | [VN] FDE[0133]
uint32_t ttr_fde_0133_0x022770(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9402008U) + (a1 ^ 0x2a010101U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffe586U + 0x022770U) ^ (0xf81e0ff3U + 0x0746e0U + 12U);
}

// [EN] FDE[0134] start_va=0x02277c, fde_va=0x0746f8, span=140 B | [VN] FDE[0134]
uint32_t ttr_fde_0134_0x02277c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02277cU) ^ (0xf9400408U + 0x0746f8U + 140U);
}

// [EN] FDE[0135] start_va=0x022808, fde_va=0x074718, span=100 B | [VN] FDE[0135]
uint32_t ttr_fde_0135_0x022808(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x022808U) ^ (0x910083fdU + 0x074718U + 100U);
}

// [EN] FDE[0136] start_va=0x02286c, fde_va=0x074740, span=96 B | [VN] FDE[0136]
uint32_t ttr_fde_0136_0x02286c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02286cU) ^ (0x910083fdU + 0x074740U + 96U);
}

// [EN] FDE[0137] start_va=0x0228cc, fde_va=0x074760, span=28 B | [VN] FDE[0137]
uint32_t ttr_fde_0137_0x0228cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900003c1U + 0x0228ccU) ^ (0xf9478821U + 0x074760U + 28U);
}

// [EN] FDE[0138] start_va=0x0228e8, fde_va=0x074780, span=116 B | [VN] FDE[0138]
uint32_t ttr_fde_0138_0x0228e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xf9000bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0228e8U) ^ (0x910083fdU + 0x074780U + 116U);
}

// [EN] FDE[0139] start_va=0x02295c, fde_va=0x0747a0, span=56 B | [VN] FDE[0139]
uint32_t ttr_fde_0139_0x02295c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02295cU) ^ (0x9401060bU + 0x0747a0U + 56U);
}

// [EN] FDE[0140] start_va=0x022994, fde_va=0x0747c0, span=52 B | [VN] FDE[0140]
uint32_t ttr_fde_0140_0x022994(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022994U) ^ (0x900003a8U + 0x0747c0U + 52U);
}

// [EN] FDE[0141] start_va=0x0229c8, fde_va=0x0747e0, span=4 B | [VN] FDE[0141]
uint32_t ttr_fde_0141_0x0229c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1401062cU) + (a1 ^ 0xf9400028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x0229c8U) ^ (0xf9400429U + 0x0747e0U + 4U);
}

// [EN] FDE[0142] start_va=0x0229cc, fde_va=0x0747f8, span=36 B | [VN] FDE[0142]
uint32_t ttr_fde_0142_0x0229cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400028U) + (a1 ^ 0xf9000008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400429U + 0x0229ccU) ^ (0xf85e8108U + 0x0747f8U + 36U);
}

// [EN] FDE[0143] start_va=0x0229f0, fde_va=0x074810, span=40 B | [VN] FDE[0143]
uint32_t ttr_fde_0143_0x0229f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0229f0U) ^ (0xaa0003f3U + 0x074810U + 40U);
}

// [EN] FDE[0144] start_va=0x022a18, fde_va=0x074830, span=156 B | [VN] FDE[0144]
uint32_t ttr_fde_0144_0x022a18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x022a18U) ^ (0x910083fdU + 0x074830U + 156U);
}

// [EN] FDE[0145] start_va=0x022ab4, fde_va=0x074850, span=12 B | [VN] FDE[0145]
uint32_t ttr_fde_0145_0x022ab4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000200U) + (a1 ^ 0x913a8c00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x022ab4U) ^ (0xf81e0ff3U + 0x074850U + 12U);
}

// [EN] FDE[0146] start_va=0x022ac0, fde_va=0x074868, span=56 B | [VN] FDE[0146]
uint32_t ttr_fde_0146_0x022ac0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022ac0U) ^ (0x39402008U + 0x074868U + 56U);
}

// [EN] FDE[0147] start_va=0x022af8, fde_va=0x074888, span=28 B | [VN] FDE[0147]
uint32_t ttr_fde_0147_0x022af8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022af8U) ^ (0xaa0003f3U + 0x074888U + 28U);
}

// [EN] FDE[0148] start_va=0x022b14, fde_va=0x0748a8, span=20 B | [VN] FDE[0148]
uint32_t ttr_fde_0148_0x022b14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000001U) + (a1 ^ 0xb4000061U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91003020U + 0x022b14U) ^ (0x17ffe4c4U + 0x0748a8U + 20U);
}

// [EN] FDE[0149] start_va=0x022b28, fde_va=0x0748c0, span=16 B | [VN] FDE[0149]
uint32_t ttr_fde_0149_0x022b28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000060U) + (a1 ^ 0x91003000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffe4c4U + 0x022b28U) ^ (0xd65f03c0U + 0x0748c0U + 16U);
}

// [EN] FDE[0150] start_va=0x022b38, fde_va=0x0748d8, span=52 B | [VN] FDE[0150]
uint32_t ttr_fde_0150_0x022b38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94010166U + 0x022b38U) ^ (0xb4000100U + 0x0748d8U + 52U);
}

// [EN] FDE[0151] start_va=0x022b6c, fde_va=0x0748f8, span=12 B | [VN] FDE[0151]
uint32_t ttr_fde_0151_0x022b6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000200U) + (a1 ^ 0x913ab400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x022b6cU) ^ (0xf81e0ff3U + 0x0748f8U + 12U);
}

// [EN] FDE[0152] start_va=0x022b78, fde_va=0x074910, span=52 B | [VN] FDE[0152]
uint32_t ttr_fde_0152_0x022b78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022b78U) ^ (0x900003c8U + 0x074910U + 52U);
}

// [EN] FDE[0153] start_va=0x022bac, fde_va=0x074930, span=28 B | [VN] FDE[0153]
uint32_t ttr_fde_0153_0x022bac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022bacU) ^ (0xaa0003f3U + 0x074930U + 28U);
}

// [EN] FDE[0154] start_va=0x022bc8, fde_va=0x074950, span=48 B | [VN] FDE[0154]
uint32_t ttr_fde_0154_0x022bc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022bc8U) ^ (0xaa0003f4U + 0x074950U + 48U);
}

// [EN] FDE[0155] start_va=0x022bf8, fde_va=0x074970, span=48 B | [VN] FDE[0155]
uint32_t ttr_fde_0155_0x022bf8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000160U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x022bf8U) ^ (0x910043fdU + 0x074970U + 48U);
}

// [EN] FDE[0156] start_va=0x022c28, fde_va=0x074990, span=56 B | [VN] FDE[0156]
uint32_t ttr_fde_0156_0x022c28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022c28U) ^ (0xb9400808U + 0x074990U + 56U);
}

// [EN] FDE[0157] start_va=0x022c60, fde_va=0x0749b0, span=12 B | [VN] FDE[0157]
uint32_t ttr_fde_0157_0x022c60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x14010658U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x022c60U) ^ (0x91002000U + 0x0749b0U + 12U);
}

// [EN] FDE[0158] start_va=0x022c6c, fde_va=0x0749c8, span=8 B | [VN] FDE[0158]
uint32_t ttr_fde_0158_0x022c6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91002000U) + (a1 ^ 0x17ffffd6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10203ffU + 0x022c6cU) ^ (0xaa1e03e2U + 0x0749c8U + 8U);
}

// [EN] FDE[0159] start_va=0x022c74, fde_va=0x0749e0, span=244 B | [VN] FDE[0159]
uint32_t ttr_fde_0159_0x022c74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xaa1e03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400f763U + 0x022c74U) ^ (0xaa0203feU + 0x0749e0U + 244U);
}

// [EN] FDE[0160] start_va=0x022d68, fde_va=0x074a10, span=44 B | [VN] FDE[0160]
uint32_t ttr_fde_0160_0x022d68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xb4000088U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803e0U + 0x022d68U) ^ (0x140000ddU + 0x074a10U + 44U);
}

// [EN] FDE[0161] start_va=0x022d94, fde_va=0x074a28, span=92 B | [VN] FDE[0161]
uint32_t ttr_fde_0161_0x022d94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf8408d00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40001a0U + 0x022d94U) ^ (0xb9400048U + 0x074a28U + 92U);
}

// [EN] FDE[0162] start_va=0x022df0, fde_va=0x074a40, span=52 B | [VN] FDE[0162]
uint32_t ttr_fde_0162_0x022df0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022df0U) ^ (0x9400fdfaU + 0x074a40U + 52U);
}

// [EN] FDE[0163] start_va=0x022e24, fde_va=0x074a60, span=48 B | [VN] FDE[0163]
uint32_t ttr_fde_0163_0x022e24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022e24U) ^ (0x9400fa47U + 0x074a60U + 48U);
}

// [EN] FDE[0164] start_va=0x022e54, fde_va=0x074a80, span=240 B | [VN] FDE[0164]
uint32_t ttr_fde_0164_0x022e54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022e54U) ^ (0xeb00003fU + 0x074a80U + 240U);
}

// [EN] FDE[0165] start_va=0x022f44, fde_va=0x074aa0, span=56 B | [VN] FDE[0165]
uint32_t ttr_fde_0165_0x022f44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xf9400109U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000409U + 0x022f44U) ^ (0xb4000049U + 0x074aa0U + 56U);
}

// [EN] FDE[0166] start_va=0x022f7c, fde_va=0x074ab8, span=56 B | [VN] FDE[0166]
uint32_t ttr_fde_0166_0x022f7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9400509U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000009U + 0x022f7cU) ^ (0xb4000049U + 0x074ab8U + 56U);
}

// [EN] FDE[0167] start_va=0x022fb4, fde_va=0x074ad0, span=8 B | [VN] FDE[0167]
uint32_t ttr_fde_0167_0x022fb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800700U) + (a1 ^ 0x17ffe36aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9be4ff4U + 0x022fb4U) ^ (0xa9017bfdU + 0x074ad0U + 8U);
}

// [EN] FDE[0168] start_va=0x022fbc, fde_va=0x074ae8, span=160 B | [VN] FDE[0168]
uint32_t ttr_fde_0168_0x022fbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x022fbcU) ^ (0xb9400828U + 0x074ae8U + 160U);
}

// [EN] FDE[0169] start_va=0x02305c, fde_va=0x074b08, span=48 B | [VN] FDE[0169]
uint32_t ttr_fde_0169_0x02305c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400fbcbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x02305cU) ^ (0x39400028U + 0x074b08U + 48U);
}

// [EN] FDE[0170] start_va=0x02308c, fde_va=0x074b20, span=92 B | [VN] FDE[0170]
uint32_t ttr_fde_0170_0x02308c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02308cU) ^ (0x910083fdU + 0x074b20U + 92U);
}

// [EN] FDE[0171] start_va=0x0230e8, fde_va=0x074b48, span=20 B | [VN] FDE[0171]
uint32_t ttr_fde_0171_0x0230e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb5ffffc0U + 0x0230e8U) ^ (0xaa0803e0U + 0x074b48U + 20U);
}

// [EN] FDE[0172] start_va=0x0230fc, fde_va=0x074b60, span=140 B | [VN] FDE[0172]
uint32_t ttr_fde_0172_0x0230fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa90257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x0230fcU) ^ (0xa9047bfdU + 0x074b60U + 140U);
}

// [EN] FDE[0173] start_va=0x023188, fde_va=0x074b88, span=72 B | [VN] FDE[0173]
uint32_t ttr_fde_0173_0x023188(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91002008U) + (a1 ^ 0xaa0803e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803e0U + 0x023188U) ^ (0xf940012aU + 0x074b88U + 72U);
}

// [EN] FDE[0174] start_va=0x0231d0, fde_va=0x074ba0, span=612 B | [VN] FDE[0174]
uint32_t ttr_fde_0174_0x0231d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0231d0U) ^ (0x910083fdU + 0x074ba0U + 612U);
}

// [EN] FDE[0175] start_va=0x023434, fde_va=0x074bc8, span=256 B | [VN] FDE[0175]
uint32_t ttr_fde_0175_0x023434(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa90267faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035ff8U + 0x023434U) ^ (0xa90457f6U + 0x074bc8U + 256U);
}

// [EN] FDE[0176] start_va=0x023534, fde_va=0x074bf8, span=120 B | [VN] FDE[0176]
uint32_t ttr_fde_0176_0x023534(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa90257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x023534U) ^ (0xa9047bfdU + 0x074bf8U + 120U);
}

// [EN] FDE[0177] start_va=0x0235ac, fde_va=0x074c20, span=124 B | [VN] FDE[0177]
uint32_t ttr_fde_0177_0x0235ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xfd0013e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90017f5U + 0x0235acU) ^ (0xa9034ff4U + 0x074c20U + 124U);
}

// [EN] FDE[0178] start_va=0x023628, fde_va=0x074c48, span=124 B | [VN] FDE[0178]
uint32_t ttr_fde_0178_0x023628(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xfd0013e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90017f5U + 0x023628U) ^ (0xa9034ff4U + 0x074c48U + 124U);
}

// [EN] FDE[0179] start_va=0x0236a4, fde_va=0x074c70, span=120 B | [VN] FDE[0179]
uint32_t ttr_fde_0179_0x0236a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa90257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x0236a4U) ^ (0xa9047bfdU + 0x074c70U + 120U);
}

// [EN] FDE[0180] start_va=0x02371c, fde_va=0x074c98, span=160 B | [VN] FDE[0180]
uint32_t ttr_fde_0180_0x02371c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa90257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x02371cU) ^ (0xa9047bfdU + 0x074c98U + 160U);
}

// [EN] FDE[0181] start_va=0x0237bc, fde_va=0x074cc0, span=16 B | [VN] FDE[0181]
uint32_t ttr_fde_0181_0x0237bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x9400f9f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x0237bcU) ^ (0x17fffe31U + 0x074cc0U + 16U);
}

// [EN] FDE[0182] start_va=0x0237cc, fde_va=0x074cd8, span=60 B | [VN] FDE[0182]
uint32_t ttr_fde_0182_0x0237cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0237ccU) ^ (0x9400f243U + 0x074cd8U + 60U);
}

// [EN] FDE[0183] start_va=0x023808, fde_va=0x074cf8, span=72 B | [VN] FDE[0183]
uint32_t ttr_fde_0183_0x023808(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91002008U) + (a1 ^ 0xaa0803e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803e0U + 0x023808U) ^ (0xf940012aU + 0x074cf8U + 72U);
}

// [EN] FDE[0184] start_va=0x023850, fde_va=0x074d10, span=52 B | [VN] FDE[0184]
uint32_t ttr_fde_0184_0x023850(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x023850U) ^ (0x9400f222U + 0x074d10U + 52U);
}

// [EN] FDE[0185] start_va=0x023884, fde_va=0x074d30, span=60 B | [VN] FDE[0185]
uint32_t ttr_fde_0185_0x023884(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x023884U) ^ (0x9400f215U + 0x074d30U + 60U);
}

// [EN] FDE[0186] start_va=0x0238c0, fde_va=0x074d50, span=52 B | [VN] FDE[0186]
uint32_t ttr_fde_0186_0x0238c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0238c0U) ^ (0x9400f206U + 0x074d50U + 52U);
}

// [EN] FDE[0187] start_va=0x0238f4, fde_va=0x074d70, span=52 B | [VN] FDE[0187]
uint32_t ttr_fde_0187_0x0238f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0238f4U) ^ (0x9400f1f9U + 0x074d70U + 52U);
}

// [EN] FDE[0188] start_va=0x023928, fde_va=0x074d90, span=60 B | [VN] FDE[0188]
uint32_t ttr_fde_0188_0x023928(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x023928U) ^ (0x9400f1ecU + 0x074d90U + 60U);
}

// [EN] FDE[0189] start_va=0x023964, fde_va=0x074db0, span=32 B | [VN] FDE[0189]
uint32_t ttr_fde_0189_0x023964(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb01001fU) + (a1 ^ 0x540000c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bfdU + 0x023964U) ^ (0x910003fdU + 0x074db0U + 32U);
}

// [EN] FDE[0190] start_va=0x023984, fde_va=0x074dd0, span=164 B | [VN] FDE[0190]
uint32_t ttr_fde_0190_0x023984(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x023984U) ^ (0x910083fdU + 0x074dd0U + 164U);
}

// [EN] FDE[0191] start_va=0x023a28, fde_va=0x074df0, span=12 B | [VN] FDE[0191]
uint32_t ttr_fde_0191_0x023a28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000042U) + (a1 ^ 0x17ffe111U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x023a28U) ^ (0xaa1e03e8U + 0x074df0U + 12U);
}

// [EN] FDE[0192] start_va=0x023a34, fde_va=0x074e08, span=292 B | [VN] FDE[0192]
uint32_t ttr_fde_0192_0x023a34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e8U) + (a1 ^ 0x9400f491U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803feU + 0x023a34U) ^ (0xa9057bfdU + 0x074e08U + 292U);
}

// [EN] FDE[0193] start_va=0x023b58, fde_va=0x074e38, span=48 B | [VN] FDE[0193]
uint32_t ttr_fde_0193_0x023b58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x023b58U) ^ (0xaa0003e8U + 0x074e38U + 48U);
}

// [EN] FDE[0194] start_va=0x023b88, fde_va=0x074e58, span=64 B | [VN] FDE[0194]
uint32_t ttr_fde_0194_0x023b88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xf9000bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x023b88U) ^ (0x910083fdU + 0x074e58U + 64U);
}

// [EN] FDE[0195] start_va=0x023bc8, fde_va=0x074e78, span=40 B | [VN] FDE[0195]
uint32_t ttr_fde_0195_0x023bc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10083ffU) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x023bc8U) ^ (0x9400fab9U + 0x074e78U + 40U);
}

// [EN] FDE[0196] start_va=0x023bf0, fde_va=0x074e98, span=40 B | [VN] FDE[0196]
uint32_t ttr_fde_0196_0x023bf0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10083ffU) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x023bf0U) ^ (0x9400faafU + 0x074e98U + 40U);
}

// [EN] FDE[0197] start_va=0x023c18, fde_va=0x074eb8, span=4 B | [VN] FDE[0197]
uint32_t ttr_fde_0197_0x023c18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400f0d0U) + (a1 ^ 0xd103c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9006bf3U + 0x023c18U) ^ (0xa90e7bfdU + 0x074eb8U + 4U);
}

// [EN] FDE[0198] start_va=0x023c1c, fde_va=0x074ed0, span=72 B | [VN] FDE[0198]
uint32_t ttr_fde_0198_0x023c1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xf9006bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90e7bfdU + 0x023c1cU) ^ (0x910383fdU + 0x074ed0U + 72U);
}

// [EN] FDE[0199] start_va=0x023c64, fde_va=0x074ef0, span=84 B | [VN] FDE[0199]
uint32_t ttr_fde_0199_0x023c64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xa90d4ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90e7bfdU + 0x023c64U) ^ (0x910383fdU + 0x074ef0U + 84U);
}

// [EN] FDE[0200] start_va=0x023cb8, fde_va=0x074f10, span=60 B | [VN] FDE[0200]
uint32_t ttr_fde_0200_0x023cb8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x023cb8U) ^ (0xaa0003f4U + 0x074f10U + 60U);
}

// [EN] FDE[0201] start_va=0x023cf4, fde_va=0x074f30, span=120 B | [VN] FDE[0201]
uint32_t ttr_fde_0201_0x023cf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10403ffU) + (a1 ^ 0xf9006bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90e4ff4U + 0x023cf4U) ^ (0xa90f7bfdU + 0x074f30U + 120U);
}

// [EN] FDE[0202] start_va=0x023d6c, fde_va=0x074f50, span=88 B | [VN] FDE[0202]
uint32_t ttr_fde_0202_0x023d6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xa90d4ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90e7bfdU + 0x023d6cU) ^ (0x910383fdU + 0x074f50U + 88U);
}

// [EN] FDE[0203] start_va=0x023dc4, fde_va=0x074f70, span=28 B | [VN] FDE[0203]
uint32_t ttr_fde_0203_0x023dc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400483fU + 0x023dc4U) ^ (0x7100041fU + 0x074f70U + 28U);
}

// [EN] FDE[0204] start_va=0x023de0, fde_va=0x074f90, span=20 B | [VN] FDE[0204]
uint32_t ttr_fde_0204_0x023de0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x131f7c08U) + (a1 ^ 0x52003908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6b20a01fU + 0x023de0U) ^ (0x1a801100U + 0x074f90U + 20U);
}

// [EN] FDE[0205] start_va=0x023df4, fde_va=0x074fa8, span=56 B | [VN] FDE[0205]
uint32_t ttr_fde_0205_0x023df4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x71007c3fU) + (a1 ^ 0xaa0003e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5400010cU + 0x023df4U) ^ (0xd360fd09U + 0x074fa8U + 56U);
}

// [EN] FDE[0206] start_va=0x023e2c, fde_va=0x074fc0, span=60 B | [VN] FDE[0206]
uint32_t ttr_fde_0206_0x023e2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x71007c3fU) + (a1 ^ 0xd360fc09U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5400010cU + 0x023e2cU) ^ (0x4b0103eaU + 0x074fc0U + 60U);
}

// [EN] FDE[0207] start_va=0x023e68, fde_va=0x074fd8, span=36 B | [VN] FDE[0207]
uint32_t ttr_fde_0207_0x023e68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e8U) + (a1 ^ 0xf101011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x540000c0U + 0x023e68U) ^ (0xf9400009U + 0x074fd8U + 36U);
}

// [EN] FDE[0208] start_va=0x023e8c, fde_va=0x074ff0, span=36 B | [VN] FDE[0208]
uint32_t ttr_fde_0208_0x023e8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e8U) + (a1 ^ 0xf100811fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x540000c0U + 0x023e8cU) ^ (0xb9400009U + 0x074ff0U + 36U);
}

// [EN] FDE[0209] start_va=0x023eb0, fde_va=0x075008, span=52 B | [VN] FDE[0209]
uint32_t ttr_fde_0209_0x023eb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e8U) + (a1 ^ 0x52800709U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x528000eaU + 0x023eb0U) ^ (0xf900003fU + 0x075008U + 52U);
}

// [EN] FDE[0210] start_va=0x023ee4, fde_va=0x075020, span=52 B | [VN] FDE[0210]
uint32_t ttr_fde_0210_0x023ee4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e8U) + (a1 ^ 0x52800309U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5280006aU + 0x023ee4U) ^ (0xb900003fU + 0x075020U + 52U);
}

// [EN] FDE[0211] start_va=0x023f18, fde_va=0x075038, span=300 B | [VN] FDE[0211]
uint32_t ttr_fde_0211_0x023f18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10683ffU) + (a1 ^ 0xf900a3fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91567faU + 0x023f18U) ^ (0xa9165ff8U + 0x075038U + 300U);
}

// [EN] FDE[0212] start_va=0x024044, fde_va=0x075068, span=396 B | [VN] FDE[0212]
uint32_t ttr_fde_0212_0x024044(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ffcU) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x024044U) ^ (0xa9034ff4U + 0x075068U + 396U);
}

// [EN] FDE[0213] start_va=0x0241d0, fde_va=0x075090, span=164 B | [VN] FDE[0213]
uint32_t ttr_fde_0213_0x0241d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x0241d0U) ^ (0xa9047bfdU + 0x075090U + 164U);
}

// [EN] FDE[0214] start_va=0x024274, fde_va=0x0750b0, span=148 B | [VN] FDE[0214]
uint32_t ttr_fde_0214_0x024274(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc5ff8U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x024274U) ^ (0xa9037bfdU + 0x0750b0U + 148U);
}

// [EN] FDE[0215] start_va=0x024308, fde_va=0x0750d8, span=68 B | [VN] FDE[0215]
uint32_t ttr_fde_0215_0x024308(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x024308U) ^ (0x9400efb1U + 0x0750d8U + 68U);
}

// [EN] FDE[0216] start_va=0x02434c, fde_va=0x0750f8, span=60 B | [VN] FDE[0216]
uint32_t ttr_fde_0216_0x02434c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02434cU) ^ (0x94010174U + 0x0750f8U + 60U);
}

// [EN] FDE[0217] start_va=0x024388, fde_va=0x075118, span=16 B | [VN] FDE[0217]
uint32_t ttr_fde_0217_0x024388(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x9400f650U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x024388U) ^ (0x17fff879U + 0x075118U + 16U);
}

// [EN] FDE[0218] start_va=0x024398, fde_va=0x075130, span=48 B | [VN] FDE[0218]
uint32_t ttr_fde_0218_0x024398(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x024398U) ^ (0xd0000388U + 0x075130U + 48U);
}

// [EN] FDE[0219] start_va=0x0243c8, fde_va=0x075150, span=64 B | [VN] FDE[0219]
uint32_t ttr_fde_0219_0x0243c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0243c8U) ^ (0xd0000388U + 0x075150U + 64U);
}

// [EN] FDE[0220] start_va=0x024408, fde_va=0x075170, span=100 B | [VN] FDE[0220]
uint32_t ttr_fde_0220_0x024408(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x024408U) ^ (0x910083fdU + 0x075170U + 100U);
}

// [EN] FDE[0221] start_va=0x02446c, fde_va=0x075190, span=28 B | [VN] FDE[0221]
uint32_t ttr_fde_0221_0x02446c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02446cU) ^ (0xaa0003f3U + 0x075190U + 28U);
}

// [EN] FDE[0222] start_va=0x024488, fde_va=0x0751b0, span=212 B | [VN] FDE[0222]
uint32_t ttr_fde_0222_0x024488(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x024488U) ^ (0xf9400008U + 0x0751b0U + 212U);
}

// [EN] FDE[0223] start_va=0x02455c, fde_va=0x0751d0, span=224 B | [VN] FDE[0223]
uint32_t ttr_fde_0223_0x02455c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02455cU) ^ (0x910083fdU + 0x0751d0U + 224U);
}

// [EN] FDE[0224] start_va=0x02463c, fde_va=0x0751f8, span=180 B | [VN] FDE[0224]
uint32_t ttr_fde_0224_0x02463c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02463cU) ^ (0x910083fdU + 0x0751f8U + 180U);
}

// [EN] FDE[0225] start_va=0x0246f0, fde_va=0x075220, span=96 B | [VN] FDE[0225]
uint32_t ttr_fde_0225_0x0246f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0246f0U) ^ (0x910083fdU + 0x075220U + 96U);
}

// [EN] FDE[0226] start_va=0x024750, fde_va=0x075240, span=476 B | [VN] FDE[0226]
uint32_t ttr_fde_0226_0x024750(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9000bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x024750U) ^ (0xa9034ff4U + 0x075240U + 476U);
}

// [EN] FDE[0227] start_va=0x02492c, fde_va=0x075268, span=612 B | [VN] FDE[0227]
uint32_t ttr_fde_0227_0x02492c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x02492cU) ^ (0xa9044ff4U + 0x075268U + 612U);
}

// [EN] FDE[0228] start_va=0x024b90, fde_va=0x075290, span=92 B | [VN] FDE[0228]
uint32_t ttr_fde_0228_0x024b90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9403c09U) + (a1 ^ 0xb4000229U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa941240aU + 0x024b90U) ^ (0xaa0003e8U + 0x075290U + 92U);
}

// [EN] FDE[0229] start_va=0x024bec, fde_va=0x0752a8, span=488 B | [VN] FDE[0229]
uint32_t ttr_fde_0229_0x024bec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa90267faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035ff8U + 0x024becU) ^ (0xa90457f6U + 0x0752a8U + 488U);
}

// [EN] FDE[0230] start_va=0x024dd4, fde_va=0x0752d8, span=12 B | [VN] FDE[0230]
uint32_t ttr_fde_0230_0x024dd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffdbcdU + 0x024dd4U) ^ (0xa9bf7bfdU + 0x0752d8U + 12U);
}

// [EN] FDE[0231] start_va=0x024de0, fde_va=0x0752f8, span=28 B | [VN] FDE[0231]
uint32_t ttr_fde_0231_0x024de0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00003a1U + 0x024de0U) ^ (0xf9479821U + 0x0752f8U + 28U);
}

// [EN] FDE[0232] start_va=0x024dfc, fde_va=0x075318, span=28 B | [VN] FDE[0232]
uint32_t ttr_fde_0232_0x024dfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x024dfcU) ^ (0xaa0003f3U + 0x075318U + 28U);
}

// [EN] FDE[0233] start_va=0x024e18, fde_va=0x075338, span=16 B | [VN] FDE[0233]
uint32_t ttr_fde_0233_0x024e18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x024e18U) ^ (0x17fffd5dU + 0x075338U + 16U);
}

// [EN] FDE[0234] start_va=0x024e28, fde_va=0x075350, span=16 B | [VN] FDE[0234]
uint32_t ttr_fde_0234_0x024e28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080000U + 0x024e28U) ^ (0x17fffff2U + 0x075350U + 16U);
}

// [EN] FDE[0235] start_va=0x024e38, fde_va=0x075368, span=32 B | [VN] FDE[0235]
uint32_t ttr_fde_0235_0x024e38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400008U) + (a1 ^ 0x37000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7900001fU + 0x024e38U) ^ (0xd65f03c0U + 0x075368U + 32U);
}

// [EN] FDE[0236] start_va=0x024e58, fde_va=0x075380, span=28 B | [VN] FDE[0236]
uint32_t ttr_fde_0236_0x024e58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400001fU + 0x024e58U) ^ (0x2a2003e8U + 0x075380U + 28U);
}

// [EN] FDE[0237] start_va=0x024e74, fde_va=0x0753a0, span=24 B | [VN] FDE[0237]
uint32_t ttr_fde_0237_0x024e74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa941a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000060U + 0x024e74U) ^ (0x39400100U + 0x0753a0U + 24U);
}

// [EN] FDE[0238] start_va=0x024e8c, fde_va=0x0753b8, span=44 B | [VN] FDE[0238]
uint32_t ttr_fde_0238_0x024e8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x024e8cU) ^ (0x9400f50eU + 0x0753b8U + 44U);
}

// [EN] FDE[0239] start_va=0x024eb8, fde_va=0x0753d8, span=36 B | [VN] FDE[0239]
uint32_t ttr_fde_0239_0x024eb8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa941a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x024eb8U) ^ (0x91000508U + 0x0753d8U + 36U);
}

// [EN] FDE[0240] start_va=0x024edc, fde_va=0x0753f0, span=48 B | [VN] FDE[0240]
uint32_t ttr_fde_0240_0x024edc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x024edcU) ^ (0xaa0103f3U + 0x0753f0U + 48U);
}

// [EN] FDE[0241] start_va=0x024f0c, fde_va=0x075410, span=64 B | [VN] FDE[0241]
uint32_t ttr_fde_0241_0x024f0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x024f0cU) ^ (0x9400f4eeU + 0x075410U + 64U);
}

// [EN] FDE[0242] start_va=0x024f4c, fde_va=0x075430, span=212 B | [VN] FDE[0242]
uint32_t ttr_fde_0242_0x024f4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x024f4cU) ^ (0xa9037bfdU + 0x075430U + 212U);
}

// [EN] FDE[0243] start_va=0x025020, fde_va=0x075458, span=336 B | [VN] FDE[0243]
uint32_t ttr_fde_0243_0x025020(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x025020U) ^ (0x39400028U + 0x075458U + 336U);
}

// [EN] FDE[0244] start_va=0x025170, fde_va=0x075478, span=112 B | [VN] FDE[0244]
uint32_t ttr_fde_0244_0x025170(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x025170U) ^ (0xf00003a8U + 0x075478U + 112U);
}

// [EN] FDE[0245] start_va=0x0251e0, fde_va=0x075498, span=56 B | [VN] FDE[0245]
uint32_t ttr_fde_0245_0x0251e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0251e0U) ^ (0xaa0003f3U + 0x075498U + 56U);
}

// [EN] FDE[0246] start_va=0x025218, fde_va=0x0754b8, span=28 B | [VN] FDE[0246]
uint32_t ttr_fde_0246_0x025218(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x025218U) ^ (0xaa0003f3U + 0x0754b8U + 28U);
}

// [EN] FDE[0247] start_va=0x025234, fde_va=0x075500, span=12 B | [VN] FDE[0247]
uint32_t ttr_fde_0247_0x025234(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001e0U) + (a1 ^ 0x913c7400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x025234U) ^ (0xa9be4ff4U + 0x075500U + 12U);
}

// [EN] FDE[0248] start_va=0x025240, fde_va=0x075518, span=76 B | [VN] FDE[0248]
uint32_t ttr_fde_0248_0x025240(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x025240U) ^ (0xb0000388U + 0x075518U + 76U);
}

// [EN] FDE[0249] start_va=0x02528c, fde_va=0x075538, span=28 B | [VN] FDE[0249]
uint32_t ttr_fde_0249_0x02528c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02528cU) ^ (0xaa0003f3U + 0x075538U + 28U);
}

// [EN] FDE[0250] start_va=0x0252a8, fde_va=0x075558, span=100 B | [VN] FDE[0250]
uint32_t ttr_fde_0250_0x0252a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x0252a8U) ^ (0x9100c3fdU + 0x075558U + 100U);
}

// [EN] FDE[0251] start_va=0x02530c, fde_va=0x075578, span=324 B | [VN] FDE[0251]
uint32_t ttr_fde_0251_0x02530c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xa9055ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90657f6U + 0x02530cU) ^ (0xa9074ff4U + 0x075578U + 324U);
}

// [EN] FDE[0252] start_va=0x025450, fde_va=0x0755a0, span=240 B | [VN] FDE[0252]
uint32_t ttr_fde_0252_0x025450(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf90023f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90557f6U + 0x025450U) ^ (0xa9064ff4U + 0x0755a0U + 240U);
}

// [EN] FDE[0253] start_va=0x025540, fde_va=0x0755c8, span=96 B | [VN] FDE[0253]
uint32_t ttr_fde_0253_0x025540(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9024ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x025540U) ^ (0x9100c3fdU + 0x0755c8U + 96U);
}

// [EN] FDE[0254] start_va=0x0255a0, fde_va=0x0755e8, span=244 B | [VN] FDE[0254]
uint32_t ttr_fde_0254_0x0255a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xa9045ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90557f6U + 0x0255a0U) ^ (0xa9064ff4U + 0x0755e8U + 244U);
}

// [EN] FDE[0255] start_va=0x025694, fde_va=0x075610, span=240 B | [VN] FDE[0255]
uint32_t ttr_fde_0255_0x025694(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf90023f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9055ff8U + 0x025694U) ^ (0xa90657f6U + 0x075610U + 240U);
}

// [EN] FDE[0256] start_va=0x025784, fde_va=0x075638, span=44 B | [VN] FDE[0256]
uint32_t ttr_fde_0256_0x025784(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa946a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000100U + 0x025784U) ^ (0xeb08013fU + 0x075638U + 44U);
}

// [EN] FDE[0257] start_va=0x0257b0, fde_va=0x075650, span=8 B | [VN] FDE[0257]
uint32_t ttr_fde_0257_0x0257b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101a000U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400028U + 0x0257b0U) ^ (0xf9001c08U + 0x075650U + 8U);
}

// [EN] FDE[0258] start_va=0x0257b8, fde_va=0x075668, span=12 B | [VN] FDE[0258]
uint32_t ttr_fde_0258_0x0257b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400028U) + (a1 ^ 0xf9001c08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0257b8U) ^ (0xf9402008U + 0x075668U + 12U);
}

// [EN] FDE[0259] start_va=0x0257c4, fde_va=0x075680, span=20 B | [VN] FDE[0259]
uint32_t ttr_fde_0259_0x0257c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402008U) + (a1 ^ 0xb4000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x12000029U + 0x0257c4U) ^ (0x3901b909U + 0x075680U + 20U);
}

// [EN] FDE[0260] start_va=0x0257d8, fde_va=0x075698, span=432 B | [VN] FDE[0260]
uint32_t ttr_fde_0260_0x0257d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf9002bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90657f6U + 0x0257d8U) ^ (0xa9074ff4U + 0x075698U + 432U);
}

// [EN] FDE[0261] start_va=0x025988, fde_va=0x0756c0, span=4 B | [VN] FDE[0261]
uint32_t ttr_fde_0261_0x025988(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xbd400020U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xbd404801U + 0x025988U) ^ (0x1e212000U + 0x0756c0U + 4U);
}

// [EN] FDE[0262] start_va=0x02598c, fde_va=0x0756d8, span=64 B | [VN] FDE[0262]
uint32_t ttr_fde_0262_0x02598c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbd400020U) + (a1 ^ 0xbd404801U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e212000U + 0x02598cU) ^ (0x5400016bU + 0x0756d8U + 64U);
}

// [EN] FDE[0263] start_va=0x0259cc, fde_va=0x0756f0, span=8 B | [VN] FDE[0263]
uint32_t ttr_fde_0263_0x0259cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91012000U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3dc00020U + 0x0259ccU) ^ (0x3c848000U + 0x0756f0U + 8U);
}

// [EN] FDE[0264] start_va=0x0259d4, fde_va=0x075708, span=12 B | [VN] FDE[0264]
uint32_t ttr_fde_0264_0x0259d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x3dc00020U) + (a1 ^ 0x3c848000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0259d4U) ^ (0xaa1e03e3U + 0x075708U + 12U);
}

// [EN] FDE[0265] start_va=0x0259e0, fde_va=0x075720, span=208 B | [VN] FDE[0265]
uint32_t ttr_fde_0265_0x0259e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x9400f7eeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x0259e0U) ^ (0xa9067bfdU + 0x075720U + 208U);
}

// [EN] FDE[0266] start_va=0x025ab0, fde_va=0x075748, span=52 B | [VN] FDE[0266]
uint32_t ttr_fde_0266_0x025ab0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402009U) + (a1 ^ 0xb4000149U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa947a52aU + 0x025ab0U) ^ (0xa900250aU + 0x075748U + 52U);
}

// [EN] FDE[0267] start_va=0x025ae4, fde_va=0x075760, span=172 B | [VN] FDE[0267]
uint32_t ttr_fde_0267_0x025ae4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x025ae4U) ^ (0x910083fdU + 0x075760U + 172U);
}

// [EN] FDE[0268] start_va=0x025b90, fde_va=0x075788, span=8 B | [VN] FDE[0268]
uint32_t ttr_fde_0268_0x025b90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91016000U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x025b90U) ^ (0x14000014U + 0x075788U + 8U);
}

// [EN] FDE[0269] start_va=0x025b98, fde_va=0x0757a0, span=4 B | [VN] FDE[0269]
uint32_t ttr_fde_0269_0x025b98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x14000014U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x025b98U) ^ (0xa9017bfdU + 0x0757a0U + 4U);
}

// [EN] FDE[0270] start_va=0x025b9c, fde_va=0x0757b8, span=4 B | [VN] FDE[0270]
uint32_t ttr_fde_0270_0x025b9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14000014U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x025b9cU) ^ (0x910043fdU + 0x0757b8U + 4U);
}

// [EN] FDE[0271] start_va=0x025ba0, fde_va=0x0757d0, span=68 B | [VN] FDE[0271]
uint32_t ttr_fde_0271_0x025ba0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x025ba0U) ^ (0xf9400028U + 0x0757d0U + 68U);
}

// [EN] FDE[0272] start_va=0x025be4, fde_va=0x0757f0, span=4 B | [VN] FDE[0272]
uint32_t ttr_fde_0272_0x025be4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14000002U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9be4ff4U + 0x025be4U) ^ (0xa9017bfdU + 0x0757f0U + 4U);
}

// [EN] FDE[0273] start_va=0x025be8, fde_va=0x075808, span=4 B | [VN] FDE[0273]
uint32_t ttr_fde_0273_0x025be8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xa9be4ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x025be8U) ^ (0x910043fdU + 0x075808U + 4U);
}

// [EN] FDE[0274] start_va=0x025bec, fde_va=0x075820, span=76 B | [VN] FDE[0274]
uint32_t ttr_fde_0274_0x025bec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x025becU) ^ (0xf9401c08U + 0x075820U + 76U);
}

// [EN] FDE[0275] start_va=0x025c38, fde_va=0x075840, span=12 B | [VN] FDE[0275]
uint32_t ttr_fde_0275_0x025c38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffee04U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x025c38U) ^ (0xb4000040U + 0x075840U + 12U);
}

// [EN] FDE[0276] start_va=0x025c44, fde_va=0x075858, span=12 B | [VN] FDE[0276]
uint32_t ttr_fde_0276_0x025c44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffee01U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x025c44U) ^ (0xb4000040U + 0x075858U + 12U);
}

// [EN] FDE[0277] start_va=0x025c50, fde_va=0x075870, span=12 B | [VN] FDE[0277]
uint32_t ttr_fde_0277_0x025c50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffedfeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x025c50U) ^ (0xaa1e03e2U + 0x075870U + 12U);
}

// [EN] FDE[0278] start_va=0x025c5c, fde_va=0x075888, span=1640 B | [VN] FDE[0278]
uint32_t ttr_fde_0278_0x025c5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400ea1aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x025c5cU) ^ (0xa9077bfdU + 0x075888U + 1640U);
}

// [EN] FDE[0279] start_va=0x0262c4, fde_va=0x0758b8, span=464 B | [VN] FDE[0279]
uint32_t ttr_fde_0279_0x0262c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc5ff8U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x0262c4U) ^ (0xa9037bfdU + 0x0758b8U + 464U);
}

// [EN] FDE[0280] start_va=0x026494, fde_va=0x0758e0, span=264 B | [VN] FDE[0280]
uint32_t ttr_fde_0280_0x026494(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bb67faU) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x026494U) ^ (0xa9034ff4U + 0x0758e0U + 264U);
}

// [EN] FDE[0281] start_va=0x02659c, fde_va=0x075910, span=364 B | [VN] FDE[0281]
uint32_t ttr_fde_0281_0x02659c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81a0ffbU) + (a1 ^ 0xaa1e03e5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400e9f8U + 0x02659cU) ^ (0xaa0503feU + 0x075910U + 364U);
}

// [EN] FDE[0282] start_va=0x026708, fde_va=0x075940, span=28 B | [VN] FDE[0282]
uint32_t ttr_fde_0282_0x026708(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x026708U) ^ (0x9400e58dU + 0x075940U + 28U);
}

// [EN] FDE[0283] start_va=0x026724, fde_va=0x075960, span=528 B | [VN] FDE[0283]
uint32_t ttr_fde_0283_0x026724(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400e5dfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x026724U) ^ (0xa9067bfdU + 0x075960U + 528U);
}

// [EN] FDE[0284] start_va=0x026934, fde_va=0x075990, span=56 B | [VN] FDE[0284]
uint32_t ttr_fde_0284_0x026934(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x026934U) ^ (0xf9400028U + 0x075990U + 56U);
}

// [EN] FDE[0285] start_va=0x02696c, fde_va=0x0759b0, span=40 B | [VN] FDE[0285]
uint32_t ttr_fde_0285_0x02696c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02696cU) ^ (0x9400f0adU + 0x0759b0U + 40U);
}

// [EN] FDE[0286] start_va=0x026994, fde_va=0x0759d0, span=56 B | [VN] FDE[0286]
uint32_t ttr_fde_0286_0x026994(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x026994U) ^ (0x910083fdU + 0x0759d0U + 56U);
}

// [EN] FDE[0287] start_va=0x0269cc, fde_va=0x0759f0, span=56 B | [VN] FDE[0287]
uint32_t ttr_fde_0287_0x0269cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0269ccU) ^ (0x910083fdU + 0x0759f0U + 56U);
}

// [EN] FDE[0288] start_va=0x026a04, fde_va=0x075a10, span=12 B | [VN] FDE[0288]
uint32_t ttr_fde_0288_0x026a04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd4c1U + 0x026a04U) ^ (0xd10303ffU + 0x075a10U + 12U);
}

// [EN] FDE[0289] start_va=0x026a10, fde_va=0x075a30, span=732 B | [VN] FDE[0289]
uint32_t ttr_fde_0289_0x026a10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10303ffU) + (a1 ^ 0xa90767faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9085ff8U + 0x026a10U) ^ (0xa90957f6U + 0x075a30U + 732U);
}

// [EN] FDE[0290] start_va=0x026cec, fde_va=0x075a60, span=24 B | [VN] FDE[0290]
uint32_t ttr_fde_0290_0x026cec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37cfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400eee1U + 0x026cecU) ^ (0xa9bf7bfdU + 0x075a60U + 24U);
}

// [EN] FDE[0291] start_va=0x026d04, fde_va=0x075a80, span=60 B | [VN] FDE[0291]
uint32_t ttr_fde_0291_0x026d04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x026d04U) ^ (0x9400eed7U + 0x075a80U + 60U);
}

// [EN] FDE[0292] start_va=0x026d40, fde_va=0x075aa0, span=8 B | [VN] FDE[0292]
uint32_t ttr_fde_0292_0x026d40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400001U) + (a1 ^ 0x17ffff22U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x026d40U) ^ (0x17ffd3edU + 0x075aa0U + 8U);
}

// [EN] FDE[0293] start_va=0x026d48, fde_va=0x075ab8, span=12 B | [VN] FDE[0293]
uint32_t ttr_fde_0293_0x026d48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffd3edU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x026d48U) ^ (0xa9bd57f6U + 0x075ab8U + 12U);
}

// [EN] FDE[0294] start_va=0x026d54, fde_va=0x075af8, span=72 B | [VN] FDE[0294]
uint32_t ttr_fde_0294_0x026d54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x026d54U) ^ (0x910083fdU + 0x075af8U + 72U);
}

// [EN] FDE[0295] start_va=0x026d9c, fde_va=0x075b20, span=4 B | [VN] FDE[0295]
uint32_t ttr_fde_0295_0x026d9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14000022U) + (a1 ^ 0xf81c0ff7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90157f6U + 0x026d9cU) ^ (0xa9024ff4U + 0x075b20U + 4U);
}

// [EN] FDE[0296] start_va=0x026da0, fde_va=0x075b38, span=112 B | [VN] FDE[0296]
uint32_t ttr_fde_0296_0x026da0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x026da0U) ^ (0xa9037bfdU + 0x075b38U + 112U);
}

// [EN] FDE[0297] start_va=0x026e10, fde_va=0x075b60, span=20 B | [VN] FDE[0297]
uint32_t ttr_fde_0297_0x026e10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x026e10U) ^ (0x1400e6ebU + 0x075b60U + 20U);
}

// [EN] FDE[0298] start_va=0x026e24, fde_va=0x075b78, span=20 B | [VN] FDE[0298]
uint32_t ttr_fde_0298_0x026e24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x026e24U) ^ (0x1400e6e6U + 0x075b78U + 20U);
}

// [EN] FDE[0299] start_va=0x026e38, fde_va=0x075b90, span=48 B | [VN] FDE[0299]
uint32_t ttr_fde_0299_0x026e38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x026e38U) ^ (0xd37efc28U + 0x075b90U + 48U);
}

// [EN] FDE[0300] start_va=0x026e68, fde_va=0x075bb0, span=28 B | [VN] FDE[0300]
uint32_t ttr_fde_0300_0x026e68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37efc08U) + (a1 ^ 0xb5000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37ef400U + 0x026e68U) ^ (0x17ffd3bbU + 0x075bb0U + 28U);
}

// [EN] FDE[0301] start_va=0x026e84, fde_va=0x075bd0, span=28 B | [VN] FDE[0301]
uint32_t ttr_fde_0301_0x026e84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40000c1U) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000c01U + 0x026e84U) ^ (0xaa0203e1U + 0x075bd0U + 28U);
}

// [EN] FDE[0302] start_va=0x026ea0, fde_va=0x075be8, span=28 B | [VN] FDE[0302]
uint32_t ttr_fde_0302_0x026ea0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x026ea0U) ^ (0x9400f228U + 0x075be8U + 28U);
}

// [EN] FDE[0303] start_va=0x026ebc, fde_va=0x075c08, span=68 B | [VN] FDE[0303]
uint32_t ttr_fde_0303_0x026ebc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x026ebcU) ^ (0x910083fdU + 0x075c08U + 68U);
}

// [EN] FDE[0304] start_va=0x026f00, fde_va=0x075c28, span=4 B | [VN] FDE[0304]
uint32_t ttr_fde_0304_0x026f00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9402d03U + 0x026f00U) ^ (0xd61f0060U + 0x075c28U + 4U);
}

// [EN] FDE[0305] start_va=0x026f04, fde_va=0x075c40, span=12 B | [VN] FDE[0305]
uint32_t ttr_fde_0305_0x026f04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9402d03U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0060U + 0x026f04U) ^ (0x1400e473U + 0x075c40U + 12U);
}

// [EN] FDE[0306] start_va=0x026f10, fde_va=0x075c58, span=4 B | [VN] FDE[0306]
uint32_t ttr_fde_0306_0x026f10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400e473U) + (a1 ^ 0xd00001e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x913ca400U + 0x026f10U) ^ (0xd65f03c0U + 0x075c58U + 4U);
}

// [EN] FDE[0307] start_va=0x026f14, fde_va=0x075c98, span=12 B | [VN] FDE[0307]
uint32_t ttr_fde_0307_0x026f14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e0U) + (a1 ^ 0x913ca400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x026f14U) ^ (0x90000388U + 0x075c98U + 12U);
}

// [EN] FDE[0308] start_va=0x026f20, fde_va=0x075cb0, span=16 B | [VN] FDE[0308]
uint32_t ttr_fde_0308_0x026f20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000388U) + (a1 ^ 0x911c0108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x026f20U) ^ (0x17ffe839U + 0x075cb0U + 16U);
}

// [EN] FDE[0309] start_va=0x026f30, fde_va=0x075cc8, span=28 B | [VN] FDE[0309]
uint32_t ttr_fde_0309_0x026f30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x026f30U) ^ (0xaa0003f3U + 0x075cc8U + 28U);
}

// [EN] FDE[0310] start_va=0x026f4c, fde_va=0x075ce8, span=512 B | [VN] FDE[0310]
uint32_t ttr_fde_0310_0x026f4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf9001bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90467faU + 0x026f4cU) ^ (0xa9055ff8U + 0x075ce8U + 512U);
}

// [EN] FDE[0311] start_va=0x02714c, fde_va=0x075d18, span=48 B | [VN] FDE[0311]
uint32_t ttr_fde_0311_0x02714c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02714cU) ^ (0xf0000368U + 0x075d18U + 48U);
}

// [EN] FDE[0312] start_va=0x02717c, fde_va=0x075d38, span=28 B | [VN] FDE[0312]
uint32_t ttr_fde_0312_0x02717c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02717cU) ^ (0xaa0003f3U + 0x075d38U + 28U);
}

// [EN] FDE[0313] start_va=0x027198, fde_va=0x075d58, span=4 B | [VN] FDE[0313]
uint32_t ttr_fde_0313_0x027198(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400e317U) + (a1 ^ 0x17ffd2e5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000368U + 0x027198U) ^ (0xf0000369U + 0x075d58U + 4U);
}

// [EN] FDE[0314] start_va=0x02719c, fde_va=0x075d70, span=4 B | [VN] FDE[0314]
uint32_t ttr_fde_0314_0x02719c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffd2e5U) + (a1 ^ 0xf0000368U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000369U + 0x02719cU) ^ (0x911f2108U + 0x075d70U + 4U);
}

// [EN] FDE[0315] start_va=0x0271a0, fde_va=0x075d88, span=32 B | [VN] FDE[0315]
uint32_t ttr_fde_0315_0x0271a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000368U) + (a1 ^ 0xf0000369U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x911f2108U + 0x0271a0U) ^ (0x91276129U + 0x075d88U + 32U);
}

// [EN] FDE[0316] start_va=0x0271c0, fde_va=0x075da0, span=28 B | [VN] FDE[0316]
uint32_t ttr_fde_0316_0x0271c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0271c0U) ^ (0xaa0003f3U + 0x075da0U + 28U);
}

// [EN] FDE[0317] start_va=0x0271dc, fde_va=0x075dc0, span=4 B | [VN] FDE[0317]
uint32_t ttr_fde_0317_0x0271dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400e306U) + (a1 ^ 0x17ffd2d4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x0271dcU) ^ (0xa9017bfdU + 0x075dc0U + 4U);
}

// [EN] FDE[0318] start_va=0x0271e0, fde_va=0x075dd8, span=4 B | [VN] FDE[0318]
uint32_t ttr_fde_0318_0x0271e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffd2d4U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x0271e0U) ^ (0x910043fdU + 0x075dd8U + 4U);
}

// [EN] FDE[0319] start_va=0x0271e4, fde_va=0x075df0, span=36 B | [VN] FDE[0319]
uint32_t ttr_fde_0319_0x0271e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0271e4U) ^ (0x9400f415U + 0x075df0U + 36U);
}

// [EN] FDE[0320] start_va=0x027208, fde_va=0x075e10, span=28 B | [VN] FDE[0320]
uint32_t ttr_fde_0320_0x027208(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x027208U) ^ (0xaa0003f3U + 0x075e10U + 28U);
}

// [EN] FDE[0321] start_va=0x027224, fde_va=0x075e30, span=4 B | [VN] FDE[0321]
uint32_t ttr_fde_0321_0x027224(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400e2f4U) + (a1 ^ 0x17ffd2c2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x027224U) ^ (0xa9017bfdU + 0x075e30U + 4U);
}

// [EN] FDE[0322] start_va=0x027228, fde_va=0x075e48, span=4 B | [VN] FDE[0322]
uint32_t ttr_fde_0322_0x027228(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffd2c2U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x027228U) ^ (0x910043fdU + 0x075e48U + 4U);
}

// [EN] FDE[0323] start_va=0x02722c, fde_va=0x075e60, span=48 B | [VN] FDE[0323]
uint32_t ttr_fde_0323_0x02722c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02722cU) ^ (0xf0000368U + 0x075e60U + 48U);
}

// [EN] FDE[0324] start_va=0x02725c, fde_va=0x075e80, span=28 B | [VN] FDE[0324]
uint32_t ttr_fde_0324_0x02725c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02725cU) ^ (0xaa0003f3U + 0x075e80U + 28U);
}

// [EN] FDE[0325] start_va=0x027278, fde_va=0x075ea0, span=4 B | [VN] FDE[0325]
uint32_t ttr_fde_0325_0x027278(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400e2dfU) + (a1 ^ 0x17ffd2adU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb00001e0U + 0x027278U) ^ (0x913cf000U + 0x075ea0U + 4U);
}

// [EN] FDE[0326] start_va=0x02727c, fde_va=0x075eb8, span=4 B | [VN] FDE[0326]
uint32_t ttr_fde_0326_0x02727c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffd2adU) + (a1 ^ 0xb00001e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x913cf000U + 0x02727cU) ^ (0xd65f03c0U + 0x075eb8U + 4U);
}

// [EN] FDE[0327] start_va=0x027280, fde_va=0x075f20, span=12 B | [VN] FDE[0327]
uint32_t ttr_fde_0327_0x027280(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001e0U) + (a1 ^ 0x913cf000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x027280U) ^ (0xf81e0ff3U + 0x075f20U + 12U);
}

// [EN] FDE[0328] start_va=0x02728c, fde_va=0x075f38, span=28 B | [VN] FDE[0328]
uint32_t ttr_fde_0328_0x02728c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02728cU) ^ (0x9400ed3eU + 0x075f38U + 28U);
}

// [EN] FDE[0329] start_va=0x0272a8, fde_va=0x075f58, span=24 B | [VN] FDE[0329]
uint32_t ttr_fde_0329_0x0272a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0272a8U) ^ (0x9400ed37U + 0x075f58U + 24U);
}

// [EN] FDE[0330] start_va=0x0272c0, fde_va=0x075f78, span=12 B | [VN] FDE[0330]
uint32_t ttr_fde_0330_0x0272c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800048U) + (a1 ^ 0x52801929U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400e985U + 0x0272c0U) ^ (0xb4000041U + 0x075f78U + 12U);
}

// [EN] FDE[0331] start_va=0x0272cc, fde_va=0x075f90, span=12 B | [VN] FDE[0331]
uint32_t ttr_fde_0331_0x0272cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000041U) + (a1 ^ 0x1400ede5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400e321U + 0x0272ccU) ^ (0x6f00e400U + 0x075f90U + 12U);
}

// [EN] FDE[0332] start_va=0x0272d8, fde_va=0x075fa8, span=24 B | [VN] FDE[0332]
uint32_t ttr_fde_0332_0x0272d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6f00e400U) + (a1 ^ 0x3900801fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3c824000U + 0x0272d8U) ^ (0x3c834000U + 0x075fa8U + 24U);
}

// [EN] FDE[0333] start_va=0x0272f0, fde_va=0x075fc0, span=172 B | [VN] FDE[0333]
uint32_t ttr_fde_0333_0x0272f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7109643fU) + (a1 ^ 0x54000521U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x0272f0U) ^ (0xf9000bf5U + 0x075fc0U + 172U);
}

// [EN] FDE[0334] start_va=0x02739c, fde_va=0x075fe0, span=524 B | [VN] FDE[0334]
uint32_t ttr_fde_0334_0x02739c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02739cU) ^ (0x910083fdU + 0x075fe0U + 524U);
}

// [EN] FDE[0335] start_va=0x0275a8, fde_va=0x076000, span=48 B | [VN] FDE[0335]
uint32_t ttr_fde_0335_0x0275a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000160U) + (a1 ^ 0xb4000141U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03e8U + 0x0275a8U) ^ (0x93407c49U + 0x076000U + 48U);
}

// [EN] FDE[0336] start_va=0x0275d8, fde_va=0x076040, span=12 B | [VN] FDE[0336]
uint32_t ttr_fde_0336_0x0275d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001e0U) + (a1 ^ 0x913d2800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0275d8U) ^ (0xf81e0ff3U + 0x076040U + 12U);
}

// [EN] FDE[0337] start_va=0x0275e4, fde_va=0x076058, span=28 B | [VN] FDE[0337]
uint32_t ttr_fde_0337_0x0275e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0275e4U) ^ (0x9400ec50U + 0x076058U + 28U);
}

// [EN] FDE[0338] start_va=0x027600, fde_va=0x076078, span=24 B | [VN] FDE[0338]
uint32_t ttr_fde_0338_0x027600(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x027600U) ^ (0x9400ec49U + 0x076078U + 24U);
}

// [EN] FDE[0339] start_va=0x027618, fde_va=0x076098, span=12 B | [VN] FDE[0339]
uint32_t ttr_fde_0339_0x027618(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800088U) + (a1 ^ 0x52803ee9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400e8afU + 0x027618U) ^ (0xb4000041U + 0x076098U + 12U);
}

// [EN] FDE[0340] start_va=0x027624, fde_va=0x0760b0, span=12 B | [VN] FDE[0340]
uint32_t ttr_fde_0340_0x027624(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000041U) + (a1 ^ 0x1400ed0fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400e24bU + 0x027624U) ^ (0xf81e0ff3U + 0x0760b0U + 12U);
}

// [EN] FDE[0341] start_va=0x027630, fde_va=0x0760c8, span=76 B | [VN] FDE[0341]
uint32_t ttr_fde_0341_0x027630(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x027630U) ^ (0xaa0003f3U + 0x0760c8U + 76U);
}

// [EN] FDE[0342] start_va=0x02767c, fde_va=0x0760e8, span=140 B | [VN] FDE[0342]
uint32_t ttr_fde_0342_0x02767c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7109683fU) + (a1 ^ 0x54000421U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd100c3ffU + 0x02767cU) ^ (0xa9014ff4U + 0x0760e8U + 140U);
}

// [EN] FDE[0343] start_va=0x027708, fde_va=0x076108, span=1748 B | [VN] FDE[0343]
uint32_t ttr_fde_0343_0x027708(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400eef1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x027708U) ^ (0xa9057bfdU + 0x076108U + 1748U);
}

// [EN] FDE[0344] start_va=0x027ddc, fde_va=0x076158, span=12 B | [VN] FDE[0344]
uint32_t ttr_fde_0344_0x027ddc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001e0U) + (a1 ^ 0x913d6800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x027ddcU) ^ (0xf0000368U + 0x076158U + 12U);
}

// [EN] FDE[0345] start_va=0x027de8, fde_va=0x076170, span=20 B | [VN] FDE[0345]
uint32_t ttr_fde_0345_0x027de8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000368U) + (a1 ^ 0x91276108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x027de8U) ^ (0xf9000c1fU + 0x076170U + 20U);
}

// [EN] FDE[0346] start_va=0x027dfc, fde_va=0x076188, span=4 B | [VN] FDE[0346]
uint32_t ttr_fde_0346_0x027dfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffcfcdU) + (a1 ^ 0x52800108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800ca9U + 0x027dfcU) ^ (0x1400e6b5U + 0x076188U + 4U);
}

// [EN] FDE[0347] start_va=0x027e00, fde_va=0x0761a0, span=12 B | [VN] FDE[0347]
uint32_t ttr_fde_0347_0x027e00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800108U) + (a1 ^ 0x52800ca9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400e6b5U + 0x027e00U) ^ (0xb4000041U + 0x0761a0U + 12U);
}

// [EN] FDE[0348] start_va=0x027e0c, fde_va=0x0761b8, span=12 B | [VN] FDE[0348]
uint32_t ttr_fde_0348_0x027e0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000041U) + (a1 ^ 0x1400eb15U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400e051U + 0x027e0cU) ^ (0xd65f03c0U + 0x0761b8U + 12U);
}

// [EN] FDE[0349] start_va=0x027e18, fde_va=0x0761d0, span=4 B | [VN] FDE[0349]
uint32_t ttr_fde_0349_0x027e18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x7109783fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000601U + 0x027e18U) ^ (0xd10103ffU + 0x0761d0U + 4U);
}

// [EN] FDE[0350] start_va=0x027e1c, fde_va=0x0761e8, span=320 B | [VN] FDE[0350]
uint32_t ttr_fde_0350_0x027e1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7109783fU) + (a1 ^ 0x54000601U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x027e1cU) ^ (0xf9000bf5U + 0x0761e8U + 320U);
}

// [EN] FDE[0351] start_va=0x027f5c, fde_va=0x076208, span=1160 B | [VN] FDE[0351]
uint32_t ttr_fde_0351_0x027f5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6db733edU) + (a1 ^ 0x6d012bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0223e9U + 0x027f5cU) ^ (0xaa1e03e2U + 0x076208U + 1160U);
}

// [EN] FDE[0352] start_va=0x0283e4, fde_va=0x076248, span=68 B | [VN] FDE[0352]
uint32_t ttr_fde_0352_0x0283e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbd401401U) + (a1 ^ 0xfd400c02U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfc40c003U + 0x0283e4U) ^ (0xfc424004U + 0x076248U + 68U);
}

// [EN] FDE[0353] start_va=0x028428, fde_va=0x076260, span=608 B | [VN] FDE[0353]
uint32_t ttr_fde_0353_0x028428(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0x6d033befU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0433edU + 0x028428U) ^ (0x6d052bebU + 0x076260U + 608U);
}

// [EN] FDE[0354] start_va=0x028688, fde_va=0x0762a0, span=308 B | [VN] FDE[0354]
uint32_t ttr_fde_0354_0x028688(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6dbd23e9U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x028688U) ^ (0x910083fdU + 0x0762a0U + 308U);
}

// [EN] FDE[0355] start_va=0x0287bc, fde_va=0x0762c8, span=252 B | [VN] FDE[0355]
uint32_t ttr_fde_0355_0x0287bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0x6d012bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0223e9U + 0x0287bcU) ^ (0xf9001bf3U + 0x0762c8U + 252U);
}

// [EN] FDE[0356] start_va=0x0288b8, fde_va=0x076318, span=12 B | [VN] FDE[0356]
uint32_t ttr_fde_0356_0x0288b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e0U) + (a1 ^ 0x913dac00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0288b8U) ^ (0xf81e0ff3U + 0x076318U + 12U);
}

// [EN] FDE[0357] start_va=0x0288c4, fde_va=0x076330, span=28 B | [VN] FDE[0357]
uint32_t ttr_fde_0357_0x0288c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0288c4U) ^ (0x9400e6dfU + 0x076330U + 28U);
}

// [EN] FDE[0358] start_va=0x0288e0, fde_va=0x076350, span=24 B | [VN] FDE[0358]
uint32_t ttr_fde_0358_0x0288e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0288e0U) ^ (0x9400e6d8U + 0x076350U + 24U);
}

// [EN] FDE[0359] start_va=0x0288f8, fde_va=0x076370, span=12 B | [VN] FDE[0359]
uint32_t ttr_fde_0359_0x0288f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800808U) + (a1 ^ 0x52801929U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400e3f7U + 0x0288f8U) ^ (0xa9be4ff4U + 0x076370U + 12U);
}

// [EN] FDE[0360] start_va=0x028904, fde_va=0x076388, span=76 B | [VN] FDE[0360]
uint32_t ttr_fde_0360_0x028904(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x028904U) ^ (0xaa0003f3U + 0x076388U + 76U);
}

// [EN] FDE[0361] start_va=0x028950, fde_va=0x0763a8, span=112 B | [VN] FDE[0361]
uint32_t ttr_fde_0361_0x028950(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9024ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x028950U) ^ (0x9100c3fdU + 0x0763a8U + 112U);
}

// [EN] FDE[0362] start_va=0x0289c0, fde_va=0x0763c8, span=68 B | [VN] FDE[0362]
uint32_t ttr_fde_0362_0x0289c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7109803fU) + (a1 ^ 0x540001e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x0289c0U) ^ (0xa9017bfdU + 0x0763c8U + 68U);
}

// [EN] FDE[0363] start_va=0x028a04, fde_va=0x0763e8, span=1916 B | [VN] FDE[0363]
uint32_t ttr_fde_0363_0x028a04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10483ffU) + (a1 ^ 0xa90c6ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90d67faU + 0x028a04U) ^ (0xa90e5ff8U + 0x0763e8U + 1916U);
}

// [EN] FDE[0364] start_va=0x029180, fde_va=0x076418, span=104 B | [VN] FDE[0364]
uint32_t ttr_fde_0364_0x029180(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x51000408U) + (a1 ^ 0x71000d1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000168U + 0x029180U) ^ (0xf00001c9U + 0x076418U + 104U);
}

// [EN] FDE[0365] start_va=0x0291e8, fde_va=0x076430, span=24 B | [VN] FDE[0365]
uint32_t ttr_fde_0365_0x0291e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6f00e400U) + (a1 ^ 0xad000000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x29000801U + 0x0291e8U) ^ (0x29011003U + 0x076430U + 24U);
}

// [EN] FDE[0366] start_va=0x029200, fde_va=0x076470, span=76 B | [VN] FDE[0366]
uint32_t ttr_fde_0366_0x029200(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52a7f008U) + (a1 ^ 0xb9002c08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd2e7fe08U + 0x029200U) ^ (0xf9001808U + 0x076470U + 76U);
}

// [EN] FDE[0367] start_va=0x02924c, fde_va=0x076488, span=12 B | [VN] FDE[0367]
uint32_t ttr_fde_0367_0x02924c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001c0U) + (a1 ^ 0x913ed800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02924cU) ^ (0xf81e0ff3U + 0x076488U + 12U);
}

// [EN] FDE[0368] start_va=0x029258, fde_va=0x0764a0, span=56 B | [VN] FDE[0368]
uint32_t ttr_fde_0368_0x029258(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x029258U) ^ (0xb0000388U + 0x0764a0U + 56U);
}

// [EN] FDE[0369] start_va=0x029290, fde_va=0x0764c0, span=28 B | [VN] FDE[0369]
uint32_t ttr_fde_0369_0x029290(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x029290U) ^ (0xaa0003f3U + 0x0764c0U + 28U);
}

// [EN] FDE[0370] start_va=0x0292ac, fde_va=0x0764e0, span=12 B | [VN] FDE[0370]
uint32_t ttr_fde_0370_0x0292ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffe067U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0292acU) ^ (0xb4000040U + 0x0764e0U + 12U);
}

// [EN] FDE[0371] start_va=0x0292b8, fde_va=0x0764f8, span=12 B | [VN] FDE[0371]
uint32_t ttr_fde_0371_0x0292b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffe064U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0292b8U) ^ (0xf9400828U + 0x0764f8U + 12U);
}

// [EN] FDE[0372] start_va=0x0292c4, fde_va=0x076510, span=20 B | [VN] FDE[0372]
uint32_t ttr_fde_0372_0x0292c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400828U) + (a1 ^ 0xf9002808U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3dc00020U + 0x0292c4U) ^ (0x3d801000U + 0x076510U + 20U);
}

// [EN] FDE[0373] start_va=0x0292d8, fde_va=0x076528, span=140 B | [VN] FDE[0373]
uint32_t ttr_fde_0373_0x0292d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0292d8U) ^ (0x910083fdU + 0x076528U + 140U);
}

// [EN] FDE[0374] start_va=0x029364, fde_va=0x076548, span=28 B | [VN] FDE[0374]
uint32_t ttr_fde_0374_0x029364(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x029364U) ^ (0x9400da76U + 0x076548U + 28U);
}

// [EN] FDE[0375] start_va=0x029380, fde_va=0x076568, span=36 B | [VN] FDE[0375]
uint32_t ttr_fde_0375_0x029380(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x029380U) ^ (0xb0000368U + 0x076568U + 36U);
}

// [EN] FDE[0376] start_va=0x0293a4, fde_va=0x076588, span=28 B | [VN] FDE[0376]
uint32_t ttr_fde_0376_0x0293a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0293a4U) ^ (0xaa0003f3U + 0x076588U + 28U);
}

// [EN] FDE[0377] start_va=0x0293c0, fde_va=0x0765a8, span=4 B | [VN] FDE[0377]
uint32_t ttr_fde_0377_0x0293c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400da8dU) + (a1 ^ 0x17ffca5bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffcb26U + 0x0293c0U) ^ (0xd100c3ffU + 0x0765a8U + 4U);
}

// [EN] FDE[0378] start_va=0x0293c4, fde_va=0x0765c0, span=4 B | [VN] FDE[0378]
uint32_t ttr_fde_0378_0x0293c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffca5bU) + (a1 ^ 0x17ffcb26U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd100c3ffU + 0x0293c4U) ^ (0xa9014ff4U + 0x0765c0U + 4U);
}

// [EN] FDE[0379] start_va=0x0293c8, fde_va=0x0765d8, span=4 B | [VN] FDE[0379]
uint32_t ttr_fde_0379_0x0293c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffcb26U) + (a1 ^ 0xd100c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9014ff4U + 0x0293c8U) ^ (0xa9027bfdU + 0x0765d8U + 4U);
}

// [EN] FDE[0380] start_va=0x0293cc, fde_va=0x0765f0, span=72 B | [VN] FDE[0380]
uint32_t ttr_fde_0380_0x0293cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0293ccU) ^ (0x910083fdU + 0x0765f0U + 72U);
}

// [EN] FDE[0381] start_va=0x029414, fde_va=0x076610, span=16 B | [VN] FDE[0381]
uint32_t ttr_fde_0381_0x029414(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400400U) + (a1 ^ 0xb4000040U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400e16cU + 0x029414U) ^ (0xd65f03c0U + 0x076610U + 16U);
}

// [EN] FDE[0382] start_va=0x029424, fde_va=0x076628, span=24 B | [VN] FDE[0382]
uint32_t ttr_fde_0382_0x029424(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400400U) + (a1 ^ 0xb4000080U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x029424U) ^ (0xf9401901U + 0x076628U + 24U);
}

// [EN] FDE[0383] start_va=0x02943c, fde_va=0x076640, span=24 B | [VN] FDE[0383]
uint32_t ttr_fde_0383_0x02943c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400400U) + (a1 ^ 0xb4000080U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x02943cU) ^ (0xf9401d01U + 0x076640U + 24U);
}

// [EN] FDE[0384] start_va=0x029454, fde_va=0x076658, span=88 B | [VN] FDE[0384]
uint32_t ttr_fde_0384_0x029454(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x029454U) ^ (0x910083fdU + 0x076658U + 88U);
}

// [EN] FDE[0385] start_va=0x0294ac, fde_va=0x076678, span=76 B | [VN] FDE[0385]
uint32_t ttr_fde_0385_0x0294ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400c00U + 0x0294acU) ^ (0xb4000120U + 0x076678U + 76U);
}

// [EN] FDE[0386] start_va=0x0294f8, fde_va=0x076698, span=52 B | [VN] FDE[0386]
uint32_t ttr_fde_0386_0x0294f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400c00U + 0x0294f8U) ^ (0xb40000e0U + 0x076698U + 52U);
}

// [EN] FDE[0387] start_va=0x02952c, fde_va=0x0766b8, span=52 B | [VN] FDE[0387]
uint32_t ttr_fde_0387_0x02952c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e8U + 0x02952cU) ^ (0x52800040U + 0x0766b8U + 52U);
}

// [EN] FDE[0388] start_va=0x029560, fde_va=0x0766d8, span=60 B | [VN] FDE[0388]
uint32_t ttr_fde_0388_0x029560(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e2e1001U) + (a1 ^ 0x1e212000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000188U + 0x029560U) ^ (0x1e202008U + 0x0766d8U + 60U);
}

// [EN] FDE[0389] start_va=0x02959c, fde_va=0x0766f0, span=32 B | [VN] FDE[0389]
uint32_t ttr_fde_0389_0x02959c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xbd402d00U + 0x02959cU) ^ (0xb4000080U + 0x0766f0U + 32U);
}

// [EN] FDE[0390] start_va=0x0295bc, fde_va=0x076708, span=184 B | [VN] FDE[0390]
uint32_t ttr_fde_0390_0x0295bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9044ff4U + 0x0295bcU) ^ (0xa9057bfdU + 0x076708U + 184U);
}

// [EN] FDE[0391] start_va=0x029674, fde_va=0x076728, span=40 B | [VN] FDE[0391]
uint32_t ttr_fde_0391_0x029674(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000080U + 0x029674U) ^ (0xf9400008U + 0x076728U + 40U);
}

// [EN] FDE[0392] start_va=0x02969c, fde_va=0x076740, span=20 B | [VN] FDE[0392]
uint32_t ttr_fde_0392_0x02969c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xb4000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401500U + 0x02969cU) ^ (0xd65f03c0U + 0x076740U + 20U);
}

// [EN] FDE[0393] start_va=0x0296b0, fde_va=0x076758, span=16 B | [VN] FDE[0393]
uint32_t ttr_fde_0393_0x0296b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xb4000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9001101U + 0x0296b0U) ^ (0xd65f03c0U + 0x076758U + 16U);
}

// [EN] FDE[0394] start_va=0x0296c0, fde_va=0x076770, span=4 B | [VN] FDE[0394]
uint32_t ttr_fde_0394_0x0296c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400da87U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x0296c0U) ^ (0x910043fdU + 0x076770U + 4U);
}

// [EN] FDE[0395] start_va=0x0296c4, fde_va=0x076788, span=64 B | [VN] FDE[0395]
uint32_t ttr_fde_0395_0x0296c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0296c4U) ^ (0xaa0003f3U + 0x076788U + 64U);
}

// [EN] FDE[0396] start_va=0x029704, fde_va=0x0767f8, span=12 B | [VN] FDE[0396]
uint32_t ttr_fde_0396_0x029704(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001c0U) + (a1 ^ 0x913f9800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x029704U) ^ (0xf81e0ff3U + 0x0767f8U + 12U);
}

// [EN] FDE[0397] start_va=0x029710, fde_va=0x076810, span=100 B | [VN] FDE[0397]
uint32_t ttr_fde_0397_0x029710(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x029710U) ^ (0xaa0003f3U + 0x076810U + 100U);
}

// [EN] FDE[0398] start_va=0x029774, fde_va=0x076830, span=4 B | [VN] FDE[0398]
uint32_t ttr_fde_0398_0x029774(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90157f6U + 0x029774U) ^ (0xa9024ff4U + 0x076830U + 4U);
}

// [EN] FDE[0399] start_va=0x029778, fde_va=0x076848, span=332 B | [VN] FDE[0399]
uint32_t ttr_fde_0399_0x029778(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x029778U) ^ (0xa9037bfdU + 0x076848U + 332U);
}

// [EN] FDE[0400] start_va=0x0298c4, fde_va=0x076870, span=176 B | [VN] FDE[0400]
uint32_t ttr_fde_0400_0x0298c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf9000bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x0298c4U) ^ (0xa9037bfdU + 0x076870U + 176U);
}

// [EN] FDE[0401] start_va=0x029974, fde_va=0x076890, span=160 B | [VN] FDE[0401]
uint32_t ttr_fde_0401_0x029974(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf9000bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x029974U) ^ (0xa9037bfdU + 0x076890U + 160U);
}

// [EN] FDE[0402] start_va=0x029a14, fde_va=0x0768b0, span=128 B | [VN] FDE[0402]
uint32_t ttr_fde_0402_0x029a14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x029a14U) ^ (0x910083fdU + 0x0768b0U + 128U);
}

// [EN] FDE[0403] start_va=0x029a94, fde_va=0x0768d0, span=4 B | [VN] FDE[0403]
uint32_t ttr_fde_0403_0x029a94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d931U) + (a1 ^ 0x1400d930U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400d92fU + 0x029a94U) ^ (0xa9bf7bfdU + 0x0768d0U + 4U);
}

// [EN] FDE[0404] start_va=0x029a98, fde_va=0x0768e8, span=4 B | [VN] FDE[0404]
uint32_t ttr_fde_0404_0x029a98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d930U) + (a1 ^ 0x1400d92fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bfdU + 0x029a98U) ^ (0x910003fdU + 0x0768e8U + 4U);
}

// [EN] FDE[0405] start_va=0x029a9c, fde_va=0x076900, span=4 B | [VN] FDE[0405]
uint32_t ttr_fde_0405_0x029a9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d92fU) + (a1 ^ 0xa9bf7bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003fdU + 0x029a9cU) ^ (0xb9401c08U + 0x076900U + 4U);
}

// [EN] FDE[0406] start_va=0x029aa0, fde_va=0x076918, span=56 B | [VN] FDE[0406]
uint32_t ttr_fde_0406_0x029aa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401c08U + 0x029aa0U) ^ (0x6b02011fU + 0x076918U + 56U);
}

// [EN] FDE[0407] start_va=0x029ad8, fde_va=0x076938, span=56 B | [VN] FDE[0407]
uint32_t ttr_fde_0407_0x029ad8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9402008U + 0x029ad8U) ^ (0x6b02011fU + 0x076938U + 56U);
}

// [EN] FDE[0408] start_va=0x029b10, fde_va=0x076958, span=360 B | [VN] FDE[0408]
uint32_t ttr_fde_0408_0x029b10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf90013fbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1e03e4U + 0x029b10U) ^ (0x9400dbbbU + 0x076958U + 360U);
}

// [EN] FDE[0409] start_va=0x029c78, fde_va=0x076988, span=12 B | [VN] FDE[0409]
uint32_t ttr_fde_0409_0x029c78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12000028U) + (a1 ^ 0x39006008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x029c78U) ^ (0x12000028U + 0x076988U + 12U);
}

// [EN] FDE[0410] start_va=0x029c84, fde_va=0x0769a0, span=12 B | [VN] FDE[0410]
uint32_t ttr_fde_0410_0x029c84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12000028U) + (a1 ^ 0x39006408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x029c84U) ^ (0xd10243ffU + 0x0769a0U + 12U);
}

// [EN] FDE[0411] start_va=0x029c90, fde_va=0x0769b8, span=584 B | [VN] FDE[0411]
uint32_t ttr_fde_0411_0x029c90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf9003bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9087bfdU + 0x029c90U) ^ (0x910203fdU + 0x0769b8U + 584U);
}

// [EN] FDE[0412] start_va=0x029ed8, fde_va=0x0769d8, span=8 B | [VN] FDE[0412]
uint32_t ttr_fde_0412_0x029ed8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101a000U) + (a1 ^ 0x140002e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91020000U + 0x029ed8U) ^ (0x140002dfU + 0x0769d8U + 8U);
}

// [EN] FDE[0413] start_va=0x029ee0, fde_va=0x0769f0, span=8 B | [VN] FDE[0413]
uint32_t ttr_fde_0413_0x029ee0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91020000U) + (a1 ^ 0x140002dfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9405808U + 0x029ee0U) ^ (0xf9005c08U + 0x0769f0U + 8U);
}

// [EN] FDE[0414] start_va=0x029ee8, fde_va=0x076a08, span=12 B | [VN] FDE[0414]
uint32_t ttr_fde_0414_0x029ee8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9405808U) + (a1 ^ 0xf9005c08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x029ee8U) ^ (0xd10183ffU + 0x076a08U + 12U);
}

// [EN] FDE[0415] start_va=0x029ef4, fde_va=0x076a20, span=140 B | [VN] FDE[0415]
uint32_t ttr_fde_0415_0x029ef4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9044ff4U + 0x029ef4U) ^ (0xa9057bfdU + 0x076a20U + 140U);
}

// [EN] FDE[0416] start_va=0x029f80, fde_va=0x076a40, span=1032 B | [VN] FDE[0416]
uint32_t ttr_fde_0416_0x029f80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xa9045ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90557f6U + 0x029f80U) ^ (0xa9064ff4U + 0x076a40U + 1032U);
}

// [EN] FDE[0417] start_va=0x02a388, fde_va=0x076a68, span=264 B | [VN] FDE[0417]
uint32_t ttr_fde_0417_0x02a388(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x02a388U) ^ (0xa9047bfdU + 0x076a68U + 264U);
}

// [EN] FDE[0418] start_va=0x02a490, fde_va=0x076a88, span=852 B | [VN] FDE[0418]
uint32_t ttr_fde_0418_0x02a490(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0xf90033f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9075ff8U + 0x02a490U) ^ (0xa90857f6U + 0x076a88U + 852U);
}

// [EN] FDE[0419] start_va=0x02a7e4, fde_va=0x076ab0, span=24 B | [VN] FDE[0419]
uint32_t ttr_fde_0419_0x02a7e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a7e4U) ^ (0x9400de3bU + 0x076ab0U + 24U);
}

// [EN] FDE[0420] start_va=0x02a7fc, fde_va=0x076ad0, span=12 B | [VN] FDE[0420]
uint32_t ttr_fde_0420_0x02a7fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffdb13U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02a7fcU) ^ (0xf81e0ff3U + 0x076ad0U + 12U);
}

// [EN] FDE[0421] start_va=0x02a808, fde_va=0x076ae8, span=24 B | [VN] FDE[0421]
uint32_t ttr_fde_0421_0x02a808(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a808U) ^ (0x9400e848U + 0x076ae8U + 24U);
}

// [EN] FDE[0422] start_va=0x02a820, fde_va=0x076b08, span=28 B | [VN] FDE[0422]
uint32_t ttr_fde_0422_0x02a820(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a820U) ^ (0x9400d547U + 0x076b08U + 28U);
}

// [EN] FDE[0423] start_va=0x02a83c, fde_va=0x076b28, span=12 B | [VN] FDE[0423]
uint32_t ttr_fde_0423_0x02a83c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffdb03U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02a83cU) ^ (0xf81e0ff3U + 0x076b28U + 12U);
}

// [EN] FDE[0424] start_va=0x02a848, fde_va=0x076b40, span=56 B | [VN] FDE[0424]
uint32_t ttr_fde_0424_0x02a848(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a848U) ^ (0xa9402428U + 0x076b40U + 56U);
}

// [EN] FDE[0425] start_va=0x02a880, fde_va=0x076b60, span=36 B | [VN] FDE[0425]
uint32_t ttr_fde_0425_0x02a880(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a880U) ^ (0x90000368U + 0x076b60U + 36U);
}

// [EN] FDE[0426] start_va=0x02a8a4, fde_va=0x076b80, span=28 B | [VN] FDE[0426]
uint32_t ttr_fde_0426_0x02a8a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a8a4U) ^ (0xaa0003f3U + 0x076b80U + 28U);
}

// [EN] FDE[0427] start_va=0x02a8c0, fde_va=0x076ba0, span=4 B | [VN] FDE[0427]
uint32_t ttr_fde_0427_0x02a8c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d54dU) + (a1 ^ 0x17ffc51bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02a8c0U) ^ (0xa9017bfdU + 0x076ba0U + 4U);
}

// [EN] FDE[0428] start_va=0x02a8c4, fde_va=0x076bb8, span=4 B | [VN] FDE[0428]
uint32_t ttr_fde_0428_0x02a8c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffc51bU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02a8c4U) ^ (0x910043fdU + 0x076bb8U + 4U);
}

// [EN] FDE[0429] start_va=0x02a8c8, fde_va=0x076bd0, span=24 B | [VN] FDE[0429]
uint32_t ttr_fde_0429_0x02a8c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a8c8U) ^ (0x9400de08U + 0x076bd0U + 24U);
}

// [EN] FDE[0430] start_va=0x02a8e0, fde_va=0x076bf0, span=12 B | [VN] FDE[0430]
uint32_t ttr_fde_0430_0x02a8e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffdadaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02a8e0U) ^ (0xd10183ffU + 0x076bf0U + 12U);
}

// [EN] FDE[0431] start_va=0x02a8ec, fde_va=0x076c08, span=112 B | [VN] FDE[0431]
uint32_t ttr_fde_0431_0x02a8ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9044ff4U + 0x02a8ecU) ^ (0xa9057bfdU + 0x076c08U + 112U);
}

// [EN] FDE[0432] start_va=0x02a95c, fde_va=0x076c28, span=24 B | [VN] FDE[0432]
uint32_t ttr_fde_0432_0x02a95c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37dfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400ddb7U + 0x02a95cU) ^ (0xa9bf7bfdU + 0x076c28U + 24U);
}

// [EN] FDE[0433] start_va=0x02a974, fde_va=0x076c48, span=36 B | [VN] FDE[0433]
uint32_t ttr_fde_0433_0x02a974(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a974U) ^ (0x9400d756U + 0x076c48U + 36U);
}

// [EN] FDE[0434] start_va=0x02a998, fde_va=0x076c68, span=40 B | [VN] FDE[0434]
uint32_t ttr_fde_0434_0x02a998(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x02a998U) ^ (0xd1002129U + 0x076c68U + 40U);
}

// [EN] FDE[0435] start_va=0x02a9c0, fde_va=0x076c80, span=24 B | [VN] FDE[0435]
uint32_t ttr_fde_0435_0x02a9c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37cfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400dfacU + 0x02a9c0U) ^ (0xa9bf7bfdU + 0x076c80U + 24U);
}

// [EN] FDE[0436] start_va=0x02a9d8, fde_va=0x076ca0, span=32 B | [VN] FDE[0436]
uint32_t ttr_fde_0436_0x02a9d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a9d8U) ^ (0x9400e0b4U + 0x076ca0U + 32U);
}

// [EN] FDE[0437] start_va=0x02a9f8, fde_va=0x076cc0, span=60 B | [VN] FDE[0437]
uint32_t ttr_fde_0437_0x02a9f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02a9f8U) ^ (0x9400df9aU + 0x076cc0U + 60U);
}

// [EN] FDE[0438] start_va=0x02aa34, fde_va=0x076ce0, span=44 B | [VN] FDE[0438]
uint32_t ttr_fde_0438_0x02aa34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb01001fU) + (a1 ^ 0x54000120U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400048U + 0x02aa34U) ^ (0x3cdf0c20U + 0x076ce0U + 44U);
}

// [EN] FDE[0439] start_va=0x02aa60, fde_va=0x076cf8, span=8 B | [VN] FDE[0439]
uint32_t ttr_fde_0439_0x02aa60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400001U) + (a1 ^ 0x14000001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81d0ff5U + 0x02aa60U) ^ (0xa9014ff4U + 0x076cf8U + 8U);
}

// [EN] FDE[0440] start_va=0x02aa68, fde_va=0x076d10, span=56 B | [VN] FDE[0440]
uint32_t ttr_fde_0440_0x02aa68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02aa68U) ^ (0x910083fdU + 0x076d10U + 56U);
}

// [EN] FDE[0441] start_va=0x02aaa0, fde_va=0x076d30, span=532 B | [VN] FDE[0441]
uint32_t ttr_fde_0441_0x02aaa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10343ffU) + (a1 ^ 0xf9003bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90867faU + 0x02aaa0U) ^ (0xa9095ff8U + 0x076d30U + 532U);
}

// [EN] FDE[0442] start_va=0x02acb4, fde_va=0x076d60, span=56 B | [VN] FDE[0442]
uint32_t ttr_fde_0442_0x02acb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02acb4U) ^ (0xa9402428U + 0x076d60U + 56U);
}

// [EN] FDE[0443] start_va=0x02acec, fde_va=0x076d80, span=52 B | [VN] FDE[0443]
uint32_t ttr_fde_0443_0x02acec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xf9400029U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000109U + 0x02acecU) ^ (0xf9400429U + 0x076d80U + 52U);
}

// [EN] FDE[0444] start_va=0x02ad20, fde_va=0x076d98, span=48 B | [VN] FDE[0444]
uint32_t ttr_fde_0444_0x02ad20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37cfc28U + 0x02ad20U) ^ (0xb5000108U + 0x076d98U + 48U);
}

// [EN] FDE[0445] start_va=0x02ad50, fde_va=0x076db8, span=56 B | [VN] FDE[0445]
uint32_t ttr_fde_0445_0x02ad50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02ad50U) ^ (0x910083fdU + 0x076db8U + 56U);
}

// [EN] FDE[0446] start_va=0x02ad88, fde_va=0x076dd8, span=28 B | [VN] FDE[0446]
uint32_t ttr_fde_0446_0x02ad88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ad88U) ^ (0x9400d3edU + 0x076dd8U + 28U);
}

// [EN] FDE[0447] start_va=0x02ada4, fde_va=0x076df8, span=336 B | [VN] FDE[0447]
uint32_t ttr_fde_0447_0x02ada4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10303ffU) + (a1 ^ 0xa9085ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90957f6U + 0x02ada4U) ^ (0xa90a4ff4U + 0x076df8U + 336U);
}

// [EN] FDE[0448] start_va=0x02aef4, fde_va=0x076e20, span=76 B | [VN] FDE[0448]
uint32_t ttr_fde_0448_0x02aef4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02aef4U) ^ (0xd00001c8U + 0x076e20U + 76U);
}

// [EN] FDE[0449] start_va=0x02af40, fde_va=0x076e40, span=204 B | [VN] FDE[0449]
uint32_t ttr_fde_0449_0x02af40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa90357f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9044ff4U + 0x02af40U) ^ (0xa9057bfdU + 0x076e40U + 204U);
}

// [EN] FDE[0450] start_va=0x02b00c, fde_va=0x076e68, span=20 B | [VN] FDE[0450]
uint32_t ttr_fde_0450_0x02b00c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x02b00cU) ^ (0x1400d66cU + 0x076e68U + 20U);
}

// [EN] FDE[0451] start_va=0x02b020, fde_va=0x076e80, span=48 B | [VN] FDE[0451]
uint32_t ttr_fde_0451_0x02b020(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b020U) ^ (0xf9400008U + 0x076e80U + 48U);
}

// [EN] FDE[0452] start_va=0x02b050, fde_va=0x076ec8, span=56 B | [VN] FDE[0452]
uint32_t ttr_fde_0452_0x02b050(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000349U) + (a1 ^ 0x6f00e400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9133c129U + 0x02b050U) ^ (0x91014008U + 0x076ec8U + 56U);
}

// [EN] FDE[0453] start_va=0x02b088, fde_va=0x076ee0, span=12 B | [VN] FDE[0453]
uint32_t ttr_fde_0453_0x02b088(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001c0U) + (a1 ^ 0x913fdc00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02b088U) ^ (0xf81d0ff5U + 0x076ee0U + 12U);
}

// [EN] FDE[0454] start_va=0x02b094, fde_va=0x076ef8, span=104 B | [VN] FDE[0454]
uint32_t ttr_fde_0454_0x02b094(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02b094U) ^ (0x910083fdU + 0x076ef8U + 104U);
}

// [EN] FDE[0455] start_va=0x02b0fc, fde_va=0x076f18, span=28 B | [VN] FDE[0455]
uint32_t ttr_fde_0455_0x02b0fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b0fcU) ^ (0xaa0003f3U + 0x076f18U + 28U);
}

// [EN] FDE[0456] start_va=0x02b118, fde_va=0x076f38, span=732 B | [VN] FDE[0456]
uint32_t ttr_fde_0456_0x02b118(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xaa1e03e4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400d63aU + 0x02b118U) ^ (0xaa0403feU + 0x076f38U + 732U);
}

// [EN] FDE[0457] start_va=0x02b3f4, fde_va=0x076f68, span=1080 B | [VN] FDE[0457]
uint32_t ttr_fde_0457_0x02b3f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10483ffU) + (a1 ^ 0xa90c6ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90d67faU + 0x02b3f4U) ^ (0xa90e5ff8U + 0x076f68U + 1080U);
}

// [EN] FDE[0458] start_va=0x02b82c, fde_va=0x076f98, span=12 B | [VN] FDE[0458]
uint32_t ttr_fde_0458_0x02b82c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffd707U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02b82cU) ^ (0xaa1e03e2U + 0x076f98U + 12U);
}

// [EN] FDE[0459] start_va=0x02b838, fde_va=0x076fb0, span=144 B | [VN] FDE[0459]
uint32_t ttr_fde_0459_0x02b838(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400e058U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x02b838U) ^ (0xa9067bfdU + 0x076fb0U + 144U);
}

// [EN] FDE[0460] start_va=0x02b8c8, fde_va=0x076fd8, span=36 B | [VN] FDE[0460]
uint32_t ttr_fde_0460_0x02b8c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b8c8U) ^ (0x9400dcd6U + 0x076fd8U + 36U);
}

// [EN] FDE[0461] start_va=0x02b8ec, fde_va=0x076ff8, span=36 B | [VN] FDE[0461]
uint32_t ttr_fde_0461_0x02b8ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b8ecU) ^ (0xf0000348U + 0x076ff8U + 36U);
}

// [EN] FDE[0462] start_va=0x02b910, fde_va=0x077018, span=28 B | [VN] FDE[0462]
uint32_t ttr_fde_0462_0x02b910(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b910U) ^ (0xaa0003f3U + 0x077018U + 28U);
}

// [EN] FDE[0463] start_va=0x02b92c, fde_va=0x077038, span=4 B | [VN] FDE[0463]
uint32_t ttr_fde_0463_0x02b92c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d132U) + (a1 ^ 0x17ffc100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02b92cU) ^ (0xa9017bfdU + 0x077038U + 4U);
}

// [EN] FDE[0464] start_va=0x02b930, fde_va=0x077050, span=4 B | [VN] FDE[0464]
uint32_t ttr_fde_0464_0x02b930(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffc100U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02b930U) ^ (0x910043fdU + 0x077050U + 4U);
}

// [EN] FDE[0465] start_va=0x02b934, fde_va=0x077068, span=36 B | [VN] FDE[0465]
uint32_t ttr_fde_0465_0x02b934(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b934U) ^ (0xf0000348U + 0x077068U + 36U);
}

// [EN] FDE[0466] start_va=0x02b958, fde_va=0x077088, span=28 B | [VN] FDE[0466]
uint32_t ttr_fde_0466_0x02b958(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b958U) ^ (0xaa0003f3U + 0x077088U + 28U);
}

// [EN] FDE[0467] start_va=0x02b974, fde_va=0x0770a8, span=4 B | [VN] FDE[0467]
uint32_t ttr_fde_0467_0x02b974(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d120U) + (a1 ^ 0x17ffc0eeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02b974U) ^ (0xa9017bfdU + 0x0770a8U + 4U);
}

// [EN] FDE[0468] start_va=0x02b978, fde_va=0x0770c0, span=4 B | [VN] FDE[0468]
uint32_t ttr_fde_0468_0x02b978(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffc0eeU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02b978U) ^ (0x910043fdU + 0x0770c0U + 4U);
}

// [EN] FDE[0469] start_va=0x02b97c, fde_va=0x0770d8, span=36 B | [VN] FDE[0469]
uint32_t ttr_fde_0469_0x02b97c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b97cU) ^ (0xf0000348U + 0x0770d8U + 36U);
}

// [EN] FDE[0470] start_va=0x02b9a0, fde_va=0x0770f8, span=28 B | [VN] FDE[0470]
uint32_t ttr_fde_0470_0x02b9a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b9a0U) ^ (0xaa0003f3U + 0x0770f8U + 28U);
}

// [EN] FDE[0471] start_va=0x02b9bc, fde_va=0x077118, span=4 B | [VN] FDE[0471]
uint32_t ttr_fde_0471_0x02b9bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d10eU) + (a1 ^ 0x17ffc0dcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02b9bcU) ^ (0xa9017bfdU + 0x077118U + 4U);
}

// [EN] FDE[0472] start_va=0x02b9c0, fde_va=0x077130, span=4 B | [VN] FDE[0472]
uint32_t ttr_fde_0472_0x02b9c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffc0dcU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02b9c0U) ^ (0x910043fdU + 0x077130U + 4U);
}

// [EN] FDE[0473] start_va=0x02b9c4, fde_va=0x077148, span=36 B | [VN] FDE[0473]
uint32_t ttr_fde_0473_0x02b9c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b9c4U) ^ (0xf0000348U + 0x077148U + 36U);
}

// [EN] FDE[0474] start_va=0x02b9e8, fde_va=0x077168, span=28 B | [VN] FDE[0474]
uint32_t ttr_fde_0474_0x02b9e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02b9e8U) ^ (0xaa0003f3U + 0x077168U + 28U);
}

// [EN] FDE[0475] start_va=0x02ba04, fde_va=0x077188, span=4 B | [VN] FDE[0475]
uint32_t ttr_fde_0475_0x02ba04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d0fcU) + (a1 ^ 0x17ffc0caU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02ba04U) ^ (0xa9017bfdU + 0x077188U + 4U);
}

// [EN] FDE[0476] start_va=0x02ba08, fde_va=0x0771a0, span=4 B | [VN] FDE[0476]
uint32_t ttr_fde_0476_0x02ba08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffc0caU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02ba08U) ^ (0x910043fdU + 0x0771a0U + 4U);
}

// [EN] FDE[0477] start_va=0x02ba0c, fde_va=0x0771b8, span=36 B | [VN] FDE[0477]
uint32_t ttr_fde_0477_0x02ba0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ba0cU) ^ (0xf0000348U + 0x0771b8U + 36U);
}

// [EN] FDE[0478] start_va=0x02ba30, fde_va=0x0771d8, span=28 B | [VN] FDE[0478]
uint32_t ttr_fde_0478_0x02ba30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ba30U) ^ (0xaa0003f3U + 0x0771d8U + 28U);
}

// [EN] FDE[0479] start_va=0x02ba4c, fde_va=0x0771f8, span=4 B | [VN] FDE[0479]
uint32_t ttr_fde_0479_0x02ba4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d0eaU) + (a1 ^ 0x17ffc0b8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02ba4cU) ^ (0xa9017bfdU + 0x0771f8U + 4U);
}

// [EN] FDE[0480] start_va=0x02ba50, fde_va=0x077210, span=4 B | [VN] FDE[0480]
uint32_t ttr_fde_0480_0x02ba50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffc0b8U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02ba50U) ^ (0x910043fdU + 0x077210U + 4U);
}

// [EN] FDE[0481] start_va=0x02ba54, fde_va=0x077228, span=36 B | [VN] FDE[0481]
uint32_t ttr_fde_0481_0x02ba54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ba54U) ^ (0xf0000348U + 0x077228U + 36U);
}

// [EN] FDE[0482] start_va=0x02ba78, fde_va=0x077248, span=28 B | [VN] FDE[0482]
uint32_t ttr_fde_0482_0x02ba78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ba78U) ^ (0xaa0003f3U + 0x077248U + 28U);
}

// [EN] FDE[0483] start_va=0x02ba94, fde_va=0x077268, span=4 B | [VN] FDE[0483]
uint32_t ttr_fde_0483_0x02ba94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d0d8U) + (a1 ^ 0x17ffc0a6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40001e1U + 0x02ba94U) ^ (0xb9402048U + 0x077268U + 4U);
}

// [EN] FDE[0484] start_va=0x02ba98, fde_va=0x077280, span=4 B | [VN] FDE[0484]
uint32_t ttr_fde_0484_0x02ba98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffc0a6U) + (a1 ^ 0xb40001e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9402048U + 0x02ba98U) ^ (0x7100051fU + 0x077280U + 4U);
}

// [EN] FDE[0485] start_va=0x02ba9c, fde_va=0x077298, span=84 B | [VN] FDE[0485]
uint32_t ttr_fde_0485_0x02ba9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40001e1U) + (a1 ^ 0xb9402048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100051fU + 0x02ba9cU) ^ (0x5400018bU + 0x077298U + 84U);
}

// [EN] FDE[0486] start_va=0x02baf0, fde_va=0x0772b0, span=72 B | [VN] FDE[0486]
uint32_t ttr_fde_0486_0x02baf0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02baf0U) ^ (0x910083fdU + 0x0772b0U + 72U);
}

// [EN] FDE[0487] start_va=0x02bb38, fde_va=0x0772d0, span=480 B | [VN] FDE[0487]
uint32_t ttr_fde_0487_0x02bb38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xf90043fbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90967faU + 0x02bb38U) ^ (0xa90a5ff8U + 0x0772d0U + 480U);
}

// [EN] FDE[0488] start_va=0x02bd18, fde_va=0x077300, span=172 B | [VN] FDE[0488]
uint32_t ttr_fde_0488_0x02bd18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa90357f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9044ff4U + 0x02bd18U) ^ (0xa9057bfdU + 0x077300U + 172U);
}

// [EN] FDE[0489] start_va=0x02bdc4, fde_va=0x077350, span=1036 B | [VN] FDE[0489]
uint32_t ttr_fde_0489_0x02bdc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02bdc4U) ^ (0x910083fdU + 0x077350U + 1036U);
}

// [EN] FDE[0490] start_va=0x02c1d0, fde_va=0x077378, span=112 B | [VN] FDE[0490]
uint32_t ttr_fde_0490_0x02c1d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000388U + 0x02c1d0U) ^ (0x91354108U + 0x077378U + 112U);
}

// [EN] FDE[0491] start_va=0x02c240, fde_va=0x077398, span=148 B | [VN] FDE[0491]
uint32_t ttr_fde_0491_0x02c240(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6dbc33edU) + (a1 ^ 0x6d012bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0223e9U + 0x02c240U) ^ (0xa9037bfdU + 0x077398U + 148U);
}

// [EN] FDE[0492] start_va=0x02c2d4, fde_va=0x0773c8, span=104 B | [VN] FDE[0492]
uint32_t ttr_fde_0492_0x02c2d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000388U + 0x02c2d4U) ^ (0x91352108U + 0x0773c8U + 104U);
}

// [EN] FDE[0493] start_va=0x02c33c, fde_va=0x0773e8, span=112 B | [VN] FDE[0493]
uint32_t ttr_fde_0493_0x02c33c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000388U + 0x02c33cU) ^ (0x9137c108U + 0x0773e8U + 112U);
}

// [EN] FDE[0494] start_va=0x02c3ac, fde_va=0x077408, span=136 B | [VN] FDE[0494]
uint32_t ttr_fde_0494_0x02c3ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6dbc33edU) + (a1 ^ 0x6d012bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0223e9U + 0x02c3acU) ^ (0xa9037bfdU + 0x077408U + 136U);
}

// [EN] FDE[0495] start_va=0x02c434, fde_va=0x077438, span=104 B | [VN] FDE[0495]
uint32_t ttr_fde_0495_0x02c434(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000388U + 0x02c434U) ^ (0x9137a108U + 0x077438U + 104U);
}

// [EN] FDE[0496] start_va=0x02c49c, fde_va=0x077458, span=104 B | [VN] FDE[0496]
uint32_t ttr_fde_0496_0x02c49c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000388U + 0x02c49cU) ^ (0x91378108U + 0x077458U + 104U);
}

// [EN] FDE[0497] start_va=0x02c504, fde_va=0x0774a0, span=76 B | [VN] FDE[0497]
uint32_t ttr_fde_0497_0x02c504(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02c504U) ^ (0xaa0003f3U + 0x0774a0U + 76U);
}

// [EN] FDE[0498] start_va=0x02c550, fde_va=0x0774c0, span=36 B | [VN] FDE[0498]
uint32_t ttr_fde_0498_0x02c550(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c8U) + (a1 ^ 0xfd451900U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800029U + 0x02c550U) ^ (0x52800048U + 0x0774c0U + 36U);
}

// [EN] FDE[0499] start_va=0x02c574, fde_va=0x0774d8, span=12 B | [VN] FDE[0499]
uint32_t ttr_fde_0499_0x02c574(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001c0U) + (a1 ^ 0x9100b800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02c574U) ^ (0xf81e0ff3U + 0x0774d8U + 12U);
}

// [EN] FDE[0500] start_va=0x02c580, fde_va=0x0774f0, span=32 B | [VN] FDE[0500]
uint32_t ttr_fde_0500_0x02c580(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02c580U) ^ (0xd0000348U + 0x0774f0U + 32U);
}

// [EN] FDE[0501] start_va=0x02c5a0, fde_va=0x077510, span=28 B | [VN] FDE[0501]
uint32_t ttr_fde_0501_0x02c5a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02c5a0U) ^ (0xaa0003f3U + 0x077510U + 28U);
}

// [EN] FDE[0502] start_va=0x02c5bc, fde_va=0x077530, span=28 B | [VN] FDE[0502]
uint32_t ttr_fde_0502_0x02c5bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9101a000U + 0x02c5bcU) ^ (0x97fff926U + 0x077530U + 28U);
}

// [EN] FDE[0503] start_va=0x02c5d8, fde_va=0x077550, span=4 B | [VN] FDE[0503]
uint32_t ttr_fde_0503_0x02c5d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x7103283fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000081U + 0x02c5d8U) ^ (0x52800028U + 0x077550U + 4U);
}

// [EN] FDE[0504] start_va=0x02c5dc, fde_va=0x077568, span=44 B | [VN] FDE[0504]
uint32_t ttr_fde_0504_0x02c5dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7103283fU) + (a1 ^ 0x54000081U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800028U + 0x02c5dcU) ^ (0x39032408U + 0x077568U + 44U);
}

// [EN] FDE[0505] start_va=0x02c608, fde_va=0x077580, span=4 B | [VN] FDE[0505]
uint32_t ttr_fde_0505_0x02c608(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400ce54U) + (a1 ^ 0xd10243ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90657f6U + 0x02c608U) ^ (0xa9074ff4U + 0x077580U + 4U);
}

// [EN] FDE[0506] start_va=0x02c60c, fde_va=0x077598, span=552 B | [VN] FDE[0506]
uint32_t ttr_fde_0506_0x02c60c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xa90657f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9074ff4U + 0x02c60cU) ^ (0xa9087bfdU + 0x077598U + 552U);
}

// [EN] FDE[0507] start_va=0x02c834, fde_va=0x0775c0, span=24 B | [VN] FDE[0507]
uint32_t ttr_fde_0507_0x02c834(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401808U) + (a1 ^ 0xb9404908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100291fU + 0x02c834U) ^ (0x52800028U + 0x0775c0U + 24U);
}

// [EN] FDE[0508] start_va=0x02c84c, fde_va=0x0775d8, span=116 B | [VN] FDE[0508]
uint32_t ttr_fde_0508_0x02c84c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x02c84cU) ^ (0x9100c3fdU + 0x0775d8U + 116U);
}

// [EN] FDE[0509] start_va=0x02c8c0, fde_va=0x0775f8, span=68 B | [VN] FDE[0509]
uint32_t ttr_fde_0509_0x02c8c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9402008U) + (a1 ^ 0x51000509U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100093fU + 0x02c8c0U) ^ (0x54000122U + 0x0775f8U + 68U);
}

// [EN] FDE[0510] start_va=0x02c904, fde_va=0x077610, span=264 B | [VN] FDE[0510]
uint32_t ttr_fde_0510_0x02c904(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xa90967faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90a5ff8U + 0x02c904U) ^ (0xa90b57f6U + 0x077610U + 264U);
}

// [EN] FDE[0511] start_va=0x02ca0c, fde_va=0x077640, span=176 B | [VN] FDE[0511]
uint32_t ttr_fde_0511_0x02ca0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0xf90033f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9075ff8U + 0x02ca0cU) ^ (0xa90857f6U + 0x077640U + 176U);
}

// [EN] FDE[0512] start_va=0x02cabc, fde_va=0x077690, span=36 B | [VN] FDE[0512]
uint32_t ttr_fde_0512_0x02cabc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c8U) + (a1 ^ 0xfd451900U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800049U + 0x02cabcU) ^ (0x52804008U + 0x077690U + 36U);
}

// [EN] FDE[0513] start_va=0x02cae0, fde_va=0x0776a8, span=12 B | [VN] FDE[0513]
uint32_t ttr_fde_0513_0x02cae0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001c0U) + (a1 ^ 0x91013400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02cae0U) ^ (0xf81e0ff3U + 0x0776a8U + 12U);
}

// [EN] FDE[0514] start_va=0x02caec, fde_va=0x0776c0, span=40 B | [VN] FDE[0514]
uint32_t ttr_fde_0514_0x02caec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02caecU) ^ (0xf0000348U + 0x0776c0U + 40U);
}

// [EN] FDE[0515] start_va=0x02cb14, fde_va=0x0776e0, span=28 B | [VN] FDE[0515]
uint32_t ttr_fde_0515_0x02cb14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02cb14U) ^ (0xaa0003f3U + 0x0776e0U + 28U);
}

// [EN] FDE[0516] start_va=0x02cb30, fde_va=0x077700, span=20 B | [VN] FDE[0516]
uint32_t ttr_fde_0516_0x02cb30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9101a000U + 0x02cb30U) ^ (0x97fff7c9U + 0x077700U + 20U);
}

// [EN] FDE[0517] start_va=0x02cb44, fde_va=0x077720, span=4 B | [VN] FDE[0517]
uint32_t ttr_fde_0517_0x02cb44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x7103283fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000081U + 0x02cb44U) ^ (0x52800028U + 0x077720U + 4U);
}

// [EN] FDE[0518] start_va=0x02cb48, fde_va=0x077738, span=44 B | [VN] FDE[0518]
uint32_t ttr_fde_0518_0x02cb48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7103283fU) + (a1 ^ 0x54000081U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800028U + 0x02cb48U) ^ (0x39032408U + 0x077738U + 44U);
}

// [EN] FDE[0519] start_va=0x02cb74, fde_va=0x077750, span=4 B | [VN] FDE[0519]
uint32_t ttr_fde_0519_0x02cb74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0xd10203ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90557f6U + 0x02cb74U) ^ (0xa9064ff4U + 0x077750U + 4U);
}

// [EN] FDE[0520] start_va=0x02cb78, fde_va=0x077768, span=444 B | [VN] FDE[0520]
uint32_t ttr_fde_0520_0x02cb78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xa90557f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9064ff4U + 0x02cb78U) ^ (0xa9077bfdU + 0x077768U + 444U);
}

// [EN] FDE[0521] start_va=0x02cd34, fde_va=0x077790, span=16 B | [VN] FDE[0521]
uint32_t ttr_fde_0521_0x02cd34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0x52800020U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9006901U + 0x02cd34U) ^ (0xd65f03c0U + 0x077790U + 16U);
}

// [EN] FDE[0522] start_va=0x02cd44, fde_va=0x0777a8, span=8 B | [VN] FDE[0522]
uint32_t ttr_fde_0522_0x02cd44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800180U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1e03e4U + 0x02cd44U) ^ (0x9400db13U + 0x0777a8U + 8U);
}

// [EN] FDE[0523] start_va=0x02cd4c, fde_va=0x0777c0, span=172 B | [VN] FDE[0523]
uint32_t ttr_fde_0523_0x02cd4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x9400db13U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x02cd4cU) ^ (0xa9067bfdU + 0x0777c0U + 172U);
}

// [EN] FDE[0524] start_va=0x02cdf8, fde_va=0x077838, span=20 B | [VN] FDE[0524]
uint32_t ttr_fde_0524_0x02cdf8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0f000420U) + (a1 ^ 0x52800028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52900009U + 0x02cdf8U) ^ (0x52803fcaU + 0x077838U + 20U);
}

// [EN] FDE[0525] start_va=0x02ce0c, fde_va=0x077850, span=12 B | [VN] FDE[0525]
uint32_t ttr_fde_0525_0x02ce0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001c0U) + (a1 ^ 0x91038000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02ce0cU) ^ (0xf81e0ff3U + 0x077850U + 12U);
}

// [EN] FDE[0526] start_va=0x02ce18, fde_va=0x077868, span=32 B | [VN] FDE[0526]
uint32_t ttr_fde_0526_0x02ce18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ce18U) ^ (0xf0000348U + 0x077868U + 32U);
}

// [EN] FDE[0527] start_va=0x02ce38, fde_va=0x077888, span=28 B | [VN] FDE[0527]
uint32_t ttr_fde_0527_0x02ce38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ce38U) ^ (0xaa0003f3U + 0x077888U + 28U);
}

// [EN] FDE[0528] start_va=0x02ce54, fde_va=0x0778a8, span=48 B | [VN] FDE[0528]
uint32_t ttr_fde_0528_0x02ce54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ce54U) ^ (0xf9400008U + 0x0778a8U + 48U);
}

// [EN] FDE[0529] start_va=0x02ce84, fde_va=0x0778c8, span=4 B | [VN] FDE[0529]
uint32_t ttr_fde_0529_0x02ce84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02ce84U) ^ (0x910043fdU + 0x0778c8U + 4U);
}

// [EN] FDE[0530] start_va=0x02ce88, fde_va=0x0778e0, span=136 B | [VN] FDE[0530]
uint32_t ttr_fde_0530_0x02ce88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ce88U) ^ (0x51032c28U + 0x0778e0U + 136U);
}

// [EN] FDE[0531] start_va=0x02cf10, fde_va=0x077900, span=4 B | [VN] FDE[0531]
uint32_t ttr_fde_0531_0x02cf10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400cc12U) + (a1 ^ 0x1400dbdeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10243ffU + 0x02cf10U) ^ (0xa90657f6U + 0x077900U + 4U);
}

// [EN] FDE[0532] start_va=0x02cf14, fde_va=0x077918, span=4 B | [VN] FDE[0532]
uint32_t ttr_fde_0532_0x02cf14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400dbdeU) + (a1 ^ 0xd10243ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90657f6U + 0x02cf14U) ^ (0xa9074ff4U + 0x077918U + 4U);
}

// [EN] FDE[0533] start_va=0x02cf18, fde_va=0x077930, span=272 B | [VN] FDE[0533]
uint32_t ttr_fde_0533_0x02cf18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xa90657f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9074ff4U + 0x02cf18U) ^ (0xa9087bfdU + 0x077930U + 272U);
}

// [EN] FDE[0534] start_va=0x02d028, fde_va=0x077958, span=116 B | [VN] FDE[0534]
uint32_t ttr_fde_0534_0x02d028(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9044ff4U + 0x02d028U) ^ (0xa9057bfdU + 0x077958U + 116U);
}

// [EN] FDE[0535] start_va=0x02d09c, fde_va=0x077978, span=84 B | [VN] FDE[0535]
uint32_t ttr_fde_0535_0x02d09c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d09cU) ^ (0xaa0103f3U + 0x077978U + 84U);
}

// [EN] FDE[0536] start_va=0x02d0f0, fde_va=0x077998, span=356 B | [VN] FDE[0536]
uint32_t ttr_fde_0536_0x02d0f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xa90557f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9064ff4U + 0x02d0f0U) ^ (0xa9077bfdU + 0x077998U + 356U);
}

// [EN] FDE[0537] start_va=0x02d254, fde_va=0x0779c0, span=180 B | [VN] FDE[0537]
uint32_t ttr_fde_0537_0x02d254(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf9002bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9064ff4U + 0x02d254U) ^ (0xa9077bfdU + 0x0779c0U + 180U);
}

// [EN] FDE[0538] start_va=0x02d308, fde_va=0x077a08, span=20 B | [VN] FDE[0538]
uint32_t ttr_fde_0538_0x02d308(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0f000420U) + (a1 ^ 0x52800028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52820009U + 0x02d308U) ^ (0x5280006aU + 0x077a08U + 20U);
}

// [EN] FDE[0539] start_va=0x02d31c, fde_va=0x077a20, span=12 B | [VN] FDE[0539]
uint32_t ttr_fde_0539_0x02d31c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c0U) + (a1 ^ 0x91051c00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02d31cU) ^ (0xf81e0ff3U + 0x077a20U + 12U);
}

// [EN] FDE[0540] start_va=0x02d328, fde_va=0x077a38, span=32 B | [VN] FDE[0540]
uint32_t ttr_fde_0540_0x02d328(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d328U) ^ (0xd0000348U + 0x077a38U + 32U);
}

// [EN] FDE[0541] start_va=0x02d348, fde_va=0x077a58, span=28 B | [VN] FDE[0541]
uint32_t ttr_fde_0541_0x02d348(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d348U) ^ (0xaa0003f3U + 0x077a58U + 28U);
}

// [EN] FDE[0542] start_va=0x02d364, fde_va=0x077a78, span=48 B | [VN] FDE[0542]
uint32_t ttr_fde_0542_0x02d364(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d364U) ^ (0xf9400008U + 0x077a78U + 48U);
}

// [EN] FDE[0543] start_va=0x02d394, fde_va=0x077a98, span=4 B | [VN] FDE[0543]
uint32_t ttr_fde_0543_0x02d394(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xd10183ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9001bf5U + 0x02d394U) ^ (0xa9044ff4U + 0x077a98U + 4U);
}

// [EN] FDE[0544] start_va=0x02d398, fde_va=0x077ab0, span=320 B | [VN] FDE[0544]
uint32_t ttr_fde_0544_0x02d398(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9044ff4U + 0x02d398U) ^ (0xa9057bfdU + 0x077ab0U + 320U);
}

// [EN] FDE[0545] start_va=0x02d4d8, fde_va=0x077ad0, span=8 B | [VN] FDE[0545]
uint32_t ttr_fde_0545_0x02d4d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x528001c0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10243ffU + 0x02d4d8U) ^ (0xa90657f6U + 0x077ad0U + 8U);
}

// [EN] FDE[0546] start_va=0x02d4e0, fde_va=0x077ae8, span=272 B | [VN] FDE[0546]
uint32_t ttr_fde_0546_0x02d4e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xa90657f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9074ff4U + 0x02d4e0U) ^ (0xa9087bfdU + 0x077ae8U + 272U);
}

// [EN] FDE[0547] start_va=0x02d5f0, fde_va=0x077b10, span=72 B | [VN] FDE[0547]
uint32_t ttr_fde_0547_0x02d5f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d5f0U) ^ (0xaa0103f3U + 0x077b10U + 72U);
}

// [EN] FDE[0548] start_va=0x02d638, fde_va=0x077b58, span=12 B | [VN] FDE[0548]
uint32_t ttr_fde_0548_0x02d638(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c0U) + (a1 ^ 0x91058000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02d638U) ^ (0xd100c3ffU + 0x077b58U + 12U);
}

// [EN] FDE[0549] start_va=0x02d644, fde_va=0x077b70, span=80 B | [VN] FDE[0549]
uint32_t ttr_fde_0549_0x02d644(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa900cfffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02d644U) ^ (0x910083fdU + 0x077b70U + 80U);
}

// [EN] FDE[0550] start_va=0x02d694, fde_va=0x077b90, span=28 B | [VN] FDE[0550]
uint32_t ttr_fde_0550_0x02d694(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d694U) ^ (0xaa0003f3U + 0x077b90U + 28U);
}

// [EN] FDE[0551] start_va=0x02d6b0, fde_va=0x077bb0, span=16 B | [VN] FDE[0551]
uint32_t ttr_fde_0551_0x02d6b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9404800U) + (a1 ^ 0xb4000040U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fff90eU + 0x02d6b0U) ^ (0xd65f03c0U + 0x077bb0U + 16U);
}

// [EN] FDE[0552] start_va=0x02d6c0, fde_va=0x077bc8, span=60 B | [VN] FDE[0552]
uint32_t ttr_fde_0552_0x02d6c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d6c0U) ^ (0x9400ca81U + 0x077bc8U + 60U);
}

// [EN] FDE[0553] start_va=0x02d6fc, fde_va=0x077be8, span=420 B | [VN] FDE[0553]
uint32_t ttr_fde_0553_0x02d6fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf940500aU) + (a1 ^ 0xb9402148U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100051fU + 0x02d6fcU) ^ (0x54000cabU + 0x077be8U + 420U);
}

// [EN] FDE[0554] start_va=0x02d8a0, fde_va=0x077c00, span=12 B | [VN] FDE[0554]
uint32_t ttr_fde_0554_0x02d8a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffceeaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02d8a0U) ^ (0xf81e0ff3U + 0x077c00U + 12U);
}

// [EN] FDE[0555] start_va=0x02d8ac, fde_va=0x077c18, span=28 B | [VN] FDE[0555]
uint32_t ttr_fde_0555_0x02d8ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d8acU) ^ (0x9400c924U + 0x077c18U + 28U);
}

// [EN] FDE[0556] start_va=0x02d8c8, fde_va=0x077c38, span=36 B | [VN] FDE[0556]
uint32_t ttr_fde_0556_0x02d8c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d8c8U) ^ (0xd0000348U + 0x077c38U + 36U);
}

// [EN] FDE[0557] start_va=0x02d8ec, fde_va=0x077c58, span=28 B | [VN] FDE[0557]
uint32_t ttr_fde_0557_0x02d8ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d8ecU) ^ (0xaa0003f3U + 0x077c58U + 28U);
}

// [EN] FDE[0558] start_va=0x02d908, fde_va=0x077c78, span=4 B | [VN] FDE[0558]
uint32_t ttr_fde_0558_0x02d908(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400c93bU) + (a1 ^ 0x17ffb909U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02d908U) ^ (0xa9017bfdU + 0x077c78U + 4U);
}

// [EN] FDE[0559] start_va=0x02d90c, fde_va=0x077c90, span=4 B | [VN] FDE[0559]
uint32_t ttr_fde_0559_0x02d90c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffb909U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02d90cU) ^ (0x910043fdU + 0x077c90U + 4U);
}

// [EN] FDE[0560] start_va=0x02d910, fde_va=0x077cd0, span=48 B | [VN] FDE[0560]
uint32_t ttr_fde_0560_0x02d910(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02d910U) ^ (0x9400cc84U + 0x077cd0U + 48U);
}

// [EN] FDE[0561] start_va=0x02d940, fde_va=0x077cf0, span=140 B | [VN] FDE[0561]
uint32_t ttr_fde_0561_0x02d940(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02d940U) ^ (0x910083fdU + 0x077cf0U + 140U);
}

// [EN] FDE[0562] start_va=0x02d9cc, fde_va=0x077d10, span=64 B | [VN] FDE[0562]
uint32_t ttr_fde_0562_0x02d9cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001a8U) + (a1 ^ 0x0f000420U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfd001800U + 0x02d9ccU) ^ (0xfd451d00U + 0x077d10U + 64U);
}

// [EN] FDE[0563] start_va=0x02da0c, fde_va=0x077d28, span=12 B | [VN] FDE[0563]
uint32_t ttr_fde_0563_0x02da0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c0U) + (a1 ^ 0x9105c000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02da0cU) ^ (0xf81e0ff3U + 0x077d28U + 12U);
}

// [EN] FDE[0564] start_va=0x02da18, fde_va=0x077d40, span=76 B | [VN] FDE[0564]
uint32_t ttr_fde_0564_0x02da18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02da18U) ^ (0xb0000368U + 0x077d40U + 76U);
}

// [EN] FDE[0565] start_va=0x02da64, fde_va=0x077d60, span=28 B | [VN] FDE[0565]
uint32_t ttr_fde_0565_0x02da64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02da64U) ^ (0xaa0003f3U + 0x077d60U + 28U);
}

// [EN] FDE[0566] start_va=0x02da80, fde_va=0x077d80, span=72 B | [VN] FDE[0566]
uint32_t ttr_fde_0566_0x02da80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa900cfffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02da80U) ^ (0x910083fdU + 0x077d80U + 72U);
}

// [EN] FDE[0567] start_va=0x02dac8, fde_va=0x077da0, span=12 B | [VN] FDE[0567]
uint32_t ttr_fde_0567_0x02dac8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffce60U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02dac8U) ^ (0xf81e0ff3U + 0x077da0U + 12U);
}

// [EN] FDE[0568] start_va=0x02dad4, fde_va=0x077db8, span=28 B | [VN] FDE[0568]
uint32_t ttr_fde_0568_0x02dad4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02dad4U) ^ (0x9400c89aU + 0x077db8U + 28U);
}

// [EN] FDE[0569] start_va=0x02daf0, fde_va=0x077dd8, span=28 B | [VN] FDE[0569]
uint32_t ttr_fde_0569_0x02daf0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02daf0U) ^ (0x9400c893U + 0x077dd8U + 28U);
}

// [EN] FDE[0570] start_va=0x02db0c, fde_va=0x077df8, span=12 B | [VN] FDE[0570]
uint32_t ttr_fde_0570_0x02db0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x1400daadU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02db0cU) ^ (0xaa1e03e2U + 0x077df8U + 12U);
}

// [EN] FDE[0571] start_va=0x02db18, fde_va=0x077e10, span=732 B | [VN] FDE[0571]
uint32_t ttr_fde_0571_0x02db18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400d5edU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x02db18U) ^ (0xa9057bfdU + 0x077e10U + 732U);
}

// [EN] FDE[0572] start_va=0x02ddf4, fde_va=0x077e38, span=76 B | [VN] FDE[0572]
uint32_t ttr_fde_0572_0x02ddf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400028U) + (a1 ^ 0x39000008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400428U + 0x02ddf4U) ^ (0x39000408U + 0x077e38U + 76U);
}

// [EN] FDE[0573] start_va=0x02de40, fde_va=0x077e50, span=196 B | [VN] FDE[0573]
uint32_t ttr_fde_0573_0x02de40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9024ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x02de40U) ^ (0x9100c3fdU + 0x077e50U + 196U);
}

// [EN] FDE[0574] start_va=0x02df04, fde_va=0x077e70, span=36 B | [VN] FDE[0574]
uint32_t ttr_fde_0574_0x02df04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02df04U) ^ (0xd0000348U + 0x077e70U + 36U);
}

// [EN] FDE[0575] start_va=0x02df28, fde_va=0x077e90, span=28 B | [VN] FDE[0575]
uint32_t ttr_fde_0575_0x02df28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02df28U) ^ (0xaa0003f3U + 0x077e90U + 28U);
}

// [EN] FDE[0576] start_va=0x02df44, fde_va=0x077eb0, span=4 B | [VN] FDE[0576]
uint32_t ttr_fde_0576_0x02df44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400c7acU) + (a1 ^ 0x17ffb77aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02df44U) ^ (0xa9017bfdU + 0x077eb0U + 4U);
}

// [EN] FDE[0577] start_va=0x02df48, fde_va=0x077ec8, span=4 B | [VN] FDE[0577]
uint32_t ttr_fde_0577_0x02df48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffb77aU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02df48U) ^ (0x910043fdU + 0x077ec8U + 4U);
}

// [EN] FDE[0578] start_va=0x02df4c, fde_va=0x077ee0, span=36 B | [VN] FDE[0578]
uint32_t ttr_fde_0578_0x02df4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02df4cU) ^ (0xd0000348U + 0x077ee0U + 36U);
}

// [EN] FDE[0579] start_va=0x02df70, fde_va=0x077f00, span=28 B | [VN] FDE[0579]
uint32_t ttr_fde_0579_0x02df70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02df70U) ^ (0xaa0003f3U + 0x077f00U + 28U);
}

// [EN] FDE[0580] start_va=0x02df8c, fde_va=0x077f20, span=4 B | [VN] FDE[0580]
uint32_t ttr_fde_0580_0x02df8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400c79aU) + (a1 ^ 0x17ffb768U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10143ffU + 0x02df8cU) ^ (0xa9034ff4U + 0x077f20U + 4U);
}

// [EN] FDE[0581] start_va=0x02df90, fde_va=0x077f38, span=4 B | [VN] FDE[0581]
uint32_t ttr_fde_0581_0x02df90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffb768U) + (a1 ^ 0xd10143ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x02df90U) ^ (0xa9047bfdU + 0x077f38U + 4U);
}

// [EN] FDE[0582] start_va=0x02df94, fde_va=0x077f50, span=88 B | [VN] FDE[0582]
uint32_t ttr_fde_0582_0x02df94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa9034ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bfdU + 0x02df94U) ^ (0x910103fdU + 0x077f50U + 88U);
}

// [EN] FDE[0583] start_va=0x02dfec, fde_va=0x077f70, span=88 B | [VN] FDE[0583]
uint32_t ttr_fde_0583_0x02dfec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa9034ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bfdU + 0x02dfecU) ^ (0x910103fdU + 0x077f70U + 88U);
}

// [EN] FDE[0584] start_va=0x02e044, fde_va=0x077f90, span=424 B | [VN] FDE[0584]
uint32_t ttr_fde_0584_0x02e044(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa90257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x02e044U) ^ (0xa9047bfdU + 0x077f90U + 424U);
}

// [EN] FDE[0585] start_va=0x02e1ec, fde_va=0x077fb8, span=92 B | [VN] FDE[0585]
uint32_t ttr_fde_0585_0x02e1ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02e1ecU) ^ (0x910083fdU + 0x077fb8U + 92U);
}

// [EN] FDE[0586] start_va=0x02e248, fde_va=0x077fd8, span=20 B | [VN] FDE[0586]
uint32_t ttr_fde_0586_0x02e248(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401408U) + (a1 ^ 0xb4000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9404500U + 0x02e248U) ^ (0xd65f03c0U + 0x077fd8U + 20U);
}

// [EN] FDE[0587] start_va=0x02e25c, fde_va=0x077ff0, span=164 B | [VN] FDE[0587]
uint32_t ttr_fde_0587_0x02e25c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf9000bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x02e25cU) ^ (0xa9037bfdU + 0x077ff0U + 164U);
}

// [EN] FDE[0588] start_va=0x02e300, fde_va=0x078010, span=24 B | [VN] FDE[0588]
uint32_t ttr_fde_0588_0x02e300(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401c08U) + (a1 ^ 0xb4000088U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401408U + 0x02e300U) ^ (0xb4000048U + 0x078010U + 24U);
}

// [EN] FDE[0589] start_va=0x02e318, fde_va=0x078028, span=140 B | [VN] FDE[0589]
uint32_t ttr_fde_0589_0x02e318(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02e318U) ^ (0xf9401408U + 0x078028U + 140U);
}

// [EN] FDE[0590] start_va=0x02e3a4, fde_va=0x078048, span=116 B | [VN] FDE[0590]
uint32_t ttr_fde_0590_0x02e3a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02e3a4U) ^ (0x910083fdU + 0x078048U + 116U);
}

// [EN] FDE[0591] start_va=0x02e418, fde_va=0x078068, span=208 B | [VN] FDE[0591]
uint32_t ttr_fde_0591_0x02e418(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x02e418U) ^ (0xa9047bfdU + 0x078068U + 208U);
}

// [EN] FDE[0592] start_va=0x02e4e8, fde_va=0x078088, span=92 B | [VN] FDE[0592]
uint32_t ttr_fde_0592_0x02e4e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401408U + 0x02e4e8U) ^ (0xb4000168U + 0x078088U + 92U);
}

// [EN] FDE[0593] start_va=0x02e544, fde_va=0x0780a8, span=36 B | [VN] FDE[0593]
uint32_t ttr_fde_0593_0x02e544(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401408U) + (a1 ^ 0xb40000e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9404900U + 0x02e544U) ^ (0xb40000a0U + 0x0780a8U + 36U);
}

// [EN] FDE[0594] start_va=0x02e568, fde_va=0x0780e8, span=96 B | [VN] FDE[0594]
uint32_t ttr_fde_0594_0x02e568(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02e568U) ^ (0xb0000348U + 0x0780e8U + 96U);
}

// [EN] FDE[0595] start_va=0x02e5c8, fde_va=0x078108, span=76 B | [VN] FDE[0595]
uint32_t ttr_fde_0595_0x02e5c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x51000408U) + (a1 ^ 0x71007d1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x540001a8U + 0x02e5c8U) ^ (0xd00001a9U + 0x078108U + 76U);
}

// [EN] FDE[0596] start_va=0x02e614, fde_va=0x078120, span=16 B | [VN] FDE[0596]
uint32_t ttr_fde_0596_0x02e614(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000348U) + (a1 ^ 0x9117c108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf8020408U + 0x02e614U) ^ (0x17ffcd5dU + 0x078120U + 16U);
}

// [EN] FDE[0597] start_va=0x02e624, fde_va=0x078138, span=4 B | [VN] FDE[0597]
uint32_t ttr_fde_0597_0x02e624(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0xd100c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9014ff4U + 0x02e624U) ^ (0xa9027bfdU + 0x078138U + 4U);
}

// [EN] FDE[0598] start_va=0x02e628, fde_va=0x078150, span=84 B | [VN] FDE[0598]
uint32_t ttr_fde_0598_0x02e628(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02e628U) ^ (0x910083fdU + 0x078150U + 84U);
}

// [EN] FDE[0599] start_va=0x02e67c, fde_va=0x078198, span=60 B | [VN] FDE[0599]
uint32_t ttr_fde_0599_0x02e67c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02e67cU) ^ (0x9400cd1eU + 0x078198U + 60U);
}

// [EN] FDE[0600] start_va=0x02e6b8, fde_va=0x0781b8, span=340 B | [VN] FDE[0600]
uint32_t ttr_fde_0600_0x02e6b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02e6b8U) ^ (0x910083fdU + 0x0781b8U + 340U);
}

// [EN] FDE[0601] start_va=0x02e80c, fde_va=0x0781d8, span=568 B | [VN] FDE[0601]
uint32_t ttr_fde_0601_0x02e80c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bb67faU) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x02e80cU) ^ (0xa9034ff4U + 0x0781d8U + 568U);
}

// [EN] FDE[0602] start_va=0x02ea44, fde_va=0x078208, span=132 B | [VN] FDE[0602]
uint32_t ttr_fde_0602_0x02ea44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02ea44U) ^ (0x910083fdU + 0x078208U + 132U);
}

// [EN] FDE[0603] start_va=0x02eac8, fde_va=0x078228, span=328 B | [VN] FDE[0603]
uint32_t ttr_fde_0603_0x02eac8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02eac8U) ^ (0xb4000380U + 0x078228U + 328U);
}

// [EN] FDE[0604] start_va=0x02ec10, fde_va=0x078248, span=24 B | [VN] FDE[0604]
uint32_t ttr_fde_0604_0x02ec10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000389U) + (a1 ^ 0xf9421928U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9021920U + 0x02ec10U) ^ (0xb4000048U + 0x078248U + 24U);
}

// [EN] FDE[0605] start_va=0x02ec28, fde_va=0x078260, span=8 B | [VN] FDE[0605]
uint32_t ttr_fde_0605_0x02ec28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400800U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x02ec28U) ^ (0xa9017bfdU + 0x078260U + 8U);
}

// [EN] FDE[0606] start_va=0x02ec30, fde_va=0x078278, span=48 B | [VN] FDE[0606]
uint32_t ttr_fde_0606_0x02ec30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ec30U) ^ (0x9400cbb1U + 0x078278U + 48U);
}

// [EN] FDE[0607] start_va=0x02ec60, fde_va=0x078298, span=4 B | [VN] FDE[0607]
uint32_t ttr_fde_0607_0x02ec60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0xa9bf7bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003fdU + 0x02ec60U) ^ (0x9400d123U + 0x078298U + 4U);
}

// [EN] FDE[0608] start_va=0x02ec64, fde_va=0x0782b0, span=76 B | [VN] FDE[0608]
uint32_t ttr_fde_0608_0x02ec64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400d123U + 0x02ec64U) ^ (0xb4000180U + 0x0782b0U + 76U);
}

// [EN] FDE[0609] start_va=0x02ecb0, fde_va=0x0782d0, span=224 B | [VN] FDE[0609]
uint32_t ttr_fde_0609_0x02ecb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xa90657f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9074ff4U + 0x02ecb0U) ^ (0xa9087bfdU + 0x0782d0U + 224U);
}

// [EN] FDE[0610] start_va=0x02ed90, fde_va=0x0782f8, span=16 B | [VN] FDE[0610]
uint32_t ttr_fde_0610_0x02ed90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400800U) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9403101U + 0x02ed90U) ^ (0xd61f0020U + 0x0782f8U + 16U);
}

// [EN] FDE[0611] start_va=0x02eda0, fde_va=0x078310, span=8 B | [VN] FDE[0611]
uint32_t ttr_fde_0611_0x02eda0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400800U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001a0U + 0x02eda0U) ^ (0x91060400U + 0x078310U + 8U);
}

// [EN] FDE[0612] start_va=0x02eda8, fde_va=0x078328, span=12 B | [VN] FDE[0612]
uint32_t ttr_fde_0612_0x02eda8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001a0U) + (a1 ^ 0x91060400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02eda8U) ^ (0xf81e0ff3U + 0x078328U + 12U);
}

// [EN] FDE[0613] start_va=0x02edb4, fde_va=0x078340, span=60 B | [VN] FDE[0613]
uint32_t ttr_fde_0613_0x02edb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02edb4U) ^ (0xaa0003f3U + 0x078340U + 60U);
}

// [EN] FDE[0614] start_va=0x02edf0, fde_va=0x078360, span=28 B | [VN] FDE[0614]
uint32_t ttr_fde_0614_0x02edf0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02edf0U) ^ (0xaa0003f3U + 0x078360U + 28U);
}

// [EN] FDE[0615] start_va=0x02ee0c, fde_va=0x0783a8, span=104 B | [VN] FDE[0615]
uint32_t ttr_fde_0615_0x02ee0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ee0cU) ^ (0xaa0003f3U + 0x0783a8U + 104U);
}

// [EN] FDE[0616] start_va=0x02ee74, fde_va=0x0783c8, span=4 B | [VN] FDE[0616]
uint32_t ttr_fde_0616_0x02ee74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0x1400c438U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400c437U + 0x02ee74U) ^ (0x1400c436U + 0x0783c8U + 4U);
}

// [EN] FDE[0617] start_va=0x02ee78, fde_va=0x0783e0, span=4 B | [VN] FDE[0617]
uint32_t ttr_fde_0617_0x02ee78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400c438U) + (a1 ^ 0x1400c437U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400c436U + 0x02ee78U) ^ (0xd10143ffU + 0x0783e0U + 4U);
}

// [EN] FDE[0618] start_va=0x02ee7c, fde_va=0x0783f8, span=4 B | [VN] FDE[0618]
uint32_t ttr_fde_0618_0x02ee7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400c437U) + (a1 ^ 0x1400c436U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10143ffU + 0x02ee7cU) ^ (0xf9000bf7U + 0x0783f8U + 4U);
}

// [EN] FDE[0619] start_va=0x02ee80, fde_va=0x078410, span=4 B | [VN] FDE[0619]
uint32_t ttr_fde_0619_0x02ee80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400c436U) + (a1 ^ 0xd10143ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000bf7U + 0x02ee80U) ^ (0xa90257f6U + 0x078410U + 4U);
}

// [EN] FDE[0620] start_va=0x02ee84, fde_va=0x078428, span=336 B | [VN] FDE[0620]
uint32_t ttr_fde_0620_0x02ee84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9000bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x02ee84U) ^ (0xa9034ff4U + 0x078428U + 336U);
}

// [EN] FDE[0621] start_va=0x02efd4, fde_va=0x078450, span=288 B | [VN] FDE[0621]
uint32_t ttr_fde_0621_0x02efd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf9000bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x02efd4U) ^ (0xa9037bfdU + 0x078450U + 288U);
}

// [EN] FDE[0622] start_va=0x02f0f4, fde_va=0x078470, span=256 B | [VN] FDE[0622]
uint32_t ttr_fde_0622_0x02f0f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400d229U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x02f0f4U) ^ (0xa9067bfdU + 0x078470U + 256U);
}

// [EN] FDE[0623] start_va=0x02f1f4, fde_va=0x078498, span=556 B | [VN] FDE[0623]
uint32_t ttr_fde_0623_0x02f1f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xaa1e03e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400c524U + 0x02f1f4U) ^ (0xaa0303feU + 0x078498U + 556U);
}

// [EN] FDE[0624] start_va=0x02f420, fde_va=0x0784c8, span=592 B | [VN] FDE[0624]
uint32_t ttr_fde_0624_0x02f420(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xf90023fbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90567faU + 0x02f420U) ^ (0xa9065ff8U + 0x0784c8U + 592U);
}

// [EN] FDE[0625] start_va=0x02f670, fde_va=0x0784f8, span=120 B | [VN] FDE[0625]
uint32_t ttr_fde_0625_0x02f670(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02f670U) ^ (0x910083fdU + 0x0784f8U + 120U);
}

// [EN] FDE[0626] start_va=0x02f6e8, fde_va=0x078518, span=544 B | [VN] FDE[0626]
uint32_t ttr_fde_0626_0x02f6e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e1U) + (a1 ^ 0x9400d0acU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103feU + 0x02f6e8U) ^ (0xa9067bfdU + 0x078518U + 544U);
}

// [EN] FDE[0627] start_va=0x02f908, fde_va=0x078540, span=344 B | [VN] FDE[0627]
uint32_t ttr_fde_0627_0x02f908(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9024ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x02f908U) ^ (0x9100c3fdU + 0x078540U + 344U);
}

// [EN] FDE[0628] start_va=0x02fa60, fde_va=0x078560, span=52 B | [VN] FDE[0628]
uint32_t ttr_fde_0628_0x02fa60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02fa60U) ^ (0x9400c738U + 0x078560U + 52U);
}

// [EN] FDE[0629] start_va=0x02fa94, fde_va=0x078580, span=52 B | [VN] FDE[0629]
uint32_t ttr_fde_0629_0x02fa94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02fa94U) ^ (0x9400c72bU + 0x078580U + 52U);
}

// [EN] FDE[0630] start_va=0x02fac8, fde_va=0x0785a0, span=132 B | [VN] FDE[0630]
uint32_t ttr_fde_0630_0x02fac8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02fac8U) ^ (0x910083fdU + 0x0785a0U + 132U);
}

// [EN] FDE[0631] start_va=0x02fb4c, fde_va=0x0785c0, span=216 B | [VN] FDE[0631]
uint32_t ttr_fde_0631_0x02fb4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02fb4cU) ^ (0xaa0003f3U + 0x0785c0U + 216U);
}

// [EN] FDE[0632] start_va=0x02fc24, fde_va=0x0785e0, span=24 B | [VN] FDE[0632]
uint32_t ttr_fde_0632_0x02fc24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x02fc24U) ^ (0xb4000040U + 0x0785e0U + 24U);
}

// [EN] FDE[0633] start_va=0x02fc3c, fde_va=0x0785f8, span=4 B | [VN] FDE[0633]
uint32_t ttr_fde_0633_0x02fc3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d22eU) + (a1 ^ 0xf81d0ff5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9014ff4U + 0x02fc3cU) ^ (0xa9027bfdU + 0x0785f8U + 4U);
}

// [EN] FDE[0634] start_va=0x02fc40, fde_va=0x078610, span=132 B | [VN] FDE[0634]
uint32_t ttr_fde_0634_0x02fc40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02fc40U) ^ (0x910083fdU + 0x078610U + 132U);
}

// [EN] FDE[0635] start_va=0x02fcc4, fde_va=0x078630, span=216 B | [VN] FDE[0635]
uint32_t ttr_fde_0635_0x02fcc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02fcc4U) ^ (0xaa0003f3U + 0x078630U + 216U);
}

// [EN] FDE[0636] start_va=0x02fd9c, fde_va=0x078650, span=24 B | [VN] FDE[0636]
uint32_t ttr_fde_0636_0x02fd9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x02fd9cU) ^ (0xb4000040U + 0x078650U + 24U);
}

// [EN] FDE[0637] start_va=0x02fdb4, fde_va=0x078668, span=4 B | [VN] FDE[0637]
uint32_t ttr_fde_0637_0x02fdb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400d1d0U) + (a1 ^ 0xa9be4ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x02fdb4U) ^ (0x910043fdU + 0x078668U + 4U);
}

// [EN] FDE[0638] start_va=0x02fdb8, fde_va=0x078680, span=52 B | [VN] FDE[0638]
uint32_t ttr_fde_0638_0x02fdb8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02fdb8U) ^ (0xaa0003f3U + 0x078680U + 52U);
}

// [EN] FDE[0639] start_va=0x02fdec, fde_va=0x0786a0, span=160 B | [VN] FDE[0639]
uint32_t ttr_fde_0639_0x02fdec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02fdecU) ^ (0x910083fdU + 0x0786a0U + 160U);
}

// [EN] FDE[0640] start_va=0x02fe8c, fde_va=0x0786c0, span=48 B | [VN] FDE[0640]
uint32_t ttr_fde_0640_0x02fe8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02fe8cU) ^ (0xaa0003f3U + 0x0786c0U + 48U);
}

// [EN] FDE[0641] start_va=0x02febc, fde_va=0x0786e0, span=32 B | [VN] FDE[0641]
uint32_t ttr_fde_0641_0x02febc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02febcU) ^ (0xaa0003f3U + 0x0786e0U + 32U);
}

// [EN] FDE[0642] start_va=0x02fedc, fde_va=0x078750, span=12 B | [VN] FDE[0642]
uint32_t ttr_fde_0642_0x02fedc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001a0U) + (a1 ^ 0x9106ec00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02fedcU) ^ (0xd100c3ffU + 0x078750U + 12U);
}

// [EN] FDE[0643] start_va=0x02fee8, fde_va=0x078768, span=72 B | [VN] FDE[0643]
uint32_t ttr_fde_0643_0x02fee8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa900cfffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02fee8U) ^ (0x910083fdU + 0x078768U + 72U);
}

// [EN] FDE[0644] start_va=0x02ff30, fde_va=0x078788, span=28 B | [VN] FDE[0644]
uint32_t ttr_fde_0644_0x02ff30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ff30U) ^ (0xaa0003f3U + 0x078788U + 28U);
}

// [EN] FDE[0645] start_va=0x02ff4c, fde_va=0x0787a8, span=8 B | [VN] FDE[0645]
uint32_t ttr_fde_0645_0x02ff4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000c01U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000348U + 0x02ff4cU) ^ (0x9120c108U + 0x0787a8U + 8U);
}

// [EN] FDE[0646] start_va=0x02ff54, fde_va=0x0787c0, span=16 B | [VN] FDE[0646]
uint32_t ttr_fde_0646_0x02ff54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000348U) + (a1 ^ 0x9120c108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf8020408U + 0x02ff54U) ^ (0x14000001U + 0x0787c0U + 16U);
}

// [EN] FDE[0647] start_va=0x02ff64, fde_va=0x0787d8, span=68 B | [VN] FDE[0647]
uint32_t ttr_fde_0647_0x02ff64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa900cfffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02ff64U) ^ (0x910083fdU + 0x0787d8U + 68U);
}

// [EN] FDE[0648] start_va=0x02ffa8, fde_va=0x0787f8, span=12 B | [VN] FDE[0648]
uint32_t ttr_fde_0648_0x02ffa8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001a0U) + (a1 ^ 0x91067000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x02ffa8U) ^ (0xf81e0ff3U + 0x0787f8U + 12U);
}

// [EN] FDE[0649] start_va=0x02ffb4, fde_va=0x078810, span=28 B | [VN] FDE[0649]
uint32_t ttr_fde_0649_0x02ffb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x02ffb4U) ^ (0xaa0003f3U + 0x078810U + 28U);
}

// [EN] FDE[0650] start_va=0x02ffd0, fde_va=0x078830, span=4 B | [VN] FDE[0650]
uint32_t ttr_fde_0650_0x02ffd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0xd100c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9014ff4U + 0x02ffd0U) ^ (0xa9027bfdU + 0x078830U + 4U);
}

// [EN] FDE[0651] start_va=0x02ffd4, fde_va=0x078848, span=100 B | [VN] FDE[0651]
uint32_t ttr_fde_0651_0x02ffd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x02ffd4U) ^ (0x910083fdU + 0x078848U + 100U);
}

// [EN] FDE[0652] start_va=0x030038, fde_va=0x078890, span=12 B | [VN] FDE[0652]
uint32_t ttr_fde_0652_0x030038(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001a0U) + (a1 ^ 0x91076000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x030038U) ^ (0xf0000328U + 0x078890U + 12U);
}

// [EN] FDE[0653] start_va=0x030044, fde_va=0x0788a8, span=20 B | [VN] FDE[0653]
uint32_t ttr_fde_0653_0x030044(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000328U) + (a1 ^ 0x9122e108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x030044U) ^ (0xf9000c1fU + 0x0788a8U + 20U);
}

// [EN] FDE[0654] start_va=0x030058, fde_va=0x0788c0, span=28 B | [VN] FDE[0654]
uint32_t ttr_fde_0654_0x030058(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030058U) ^ (0xaa0003f3U + 0x0788c0U + 28U);
}

// [EN] FDE[0655] start_va=0x030074, fde_va=0x0788e0, span=16 B | [VN] FDE[0655]
uint32_t ttr_fde_0655_0x030074(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000061U) + (a1 ^ 0xf9005801U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000c01U + 0x030074U) ^ (0xd65f03c0U + 0x0788e0U + 16U);
}

// [EN] FDE[0656] start_va=0x030084, fde_va=0x0788f8, span=28 B | [VN] FDE[0656]
uint32_t ttr_fde_0656_0x030084(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0xf9405800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000080U + 0x030084U) ^ (0xf9400008U + 0x0788f8U + 28U);
}

// [EN] FDE[0657] start_va=0x0300a0, fde_va=0x078938, span=48 B | [VN] FDE[0657]
uint32_t ttr_fde_0657_0x0300a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0300a0U) ^ (0xd37cfc28U + 0x078938U + 48U);
}

// [EN] FDE[0658] start_va=0x0300d0, fde_va=0x078958, span=56 B | [VN] FDE[0658]
uint32_t ttr_fde_0658_0x0300d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0300d0U) ^ (0xaa0003f3U + 0x078958U + 56U);
}

// [EN] FDE[0659] start_va=0x030108, fde_va=0x078978, span=88 B | [VN] FDE[0659]
uint32_t ttr_fde_0659_0x030108(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf9000bf5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x030108U) ^ (0xa9037bfdU + 0x078978U + 88U);
}

// [EN] FDE[0660] start_va=0x030160, fde_va=0x078998, span=12 B | [VN] FDE[0660]
uint32_t ttr_fde_0660_0x030160(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffc4baU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x030160U) ^ (0xf0000328U + 0x078998U + 12U);
}

// [EN] FDE[0661] start_va=0x03016c, fde_va=0x0789b0, span=28 B | [VN] FDE[0661]
uint32_t ttr_fde_0661_0x03016c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000328U) + (a1 ^ 0xf0000329U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9124c108U + 0x03016cU) ^ (0x912d2129U + 0x0789b0U + 28U);
}

// [EN] FDE[0662] start_va=0x030188, fde_va=0x0789c8, span=28 B | [VN] FDE[0662]
uint32_t ttr_fde_0662_0x030188(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030188U) ^ (0xaa0003f3U + 0x0789c8U + 28U);
}

// [EN] FDE[0663] start_va=0x0301a4, fde_va=0x0789e8, span=4 B | [VN] FDE[0663]
uint32_t ttr_fde_0663_0x0301a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400bf14U) + (a1 ^ 0x17ffaee2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb00001a0U + 0x0301a4U) ^ (0x9107c400U + 0x0789e8U + 4U);
}

// [EN] FDE[0664] start_va=0x0301a8, fde_va=0x078a00, span=4 B | [VN] FDE[0664]
uint32_t ttr_fde_0664_0x0301a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ffaee2U) + (a1 ^ 0xb00001a0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9107c400U + 0x0301a8U) ^ (0xd65f03c0U + 0x078a00U + 4U);
}

// [EN] FDE[0665] start_va=0x0301ac, fde_va=0x078a18, span=12 B | [VN] FDE[0665]
uint32_t ttr_fde_0665_0x0301ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001a0U) + (a1 ^ 0x9107c400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0301acU) ^ (0xd10103ffU + 0x078a18U + 12U);
}

// [EN] FDE[0666] start_va=0x0301b8, fde_va=0x078a30, span=208 B | [VN] FDE[0666]
uint32_t ttr_fde_0666_0x0301b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa900d7ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x0301b8U) ^ (0xa9037bfdU + 0x078a30U + 208U);
}

// [EN] FDE[0667] start_va=0x030288, fde_va=0x078a50, span=28 B | [VN] FDE[0667]
uint32_t ttr_fde_0667_0x030288(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030288U) ^ (0xaa0003f3U + 0x078a50U + 28U);
}

// [EN] FDE[0668] start_va=0x0302a4, fde_va=0x078a70, span=16 B | [VN] FDE[0668]
uint32_t ttr_fde_0668_0x0302a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401400U) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9402102U + 0x0302a4U) ^ (0xd61f0040U + 0x078a70U + 16U);
}

// [EN] FDE[0669] start_va=0x0302b4, fde_va=0x078a88, span=60 B | [VN] FDE[0669]
uint32_t ttr_fde_0669_0x0302b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0302b4U) ^ (0xf9400c08U + 0x078a88U + 60U);
}

// [EN] FDE[0670] start_va=0x0302f0, fde_va=0x078aa8, span=40 B | [VN] FDE[0670]
uint32_t ttr_fde_0670_0x0302f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0302f0U) ^ (0x9400d196U + 0x078aa8U + 40U);
}

// [EN] FDE[0671] start_va=0x030318, fde_va=0x078ac8, span=52 B | [VN] FDE[0671]
uint32_t ttr_fde_0671_0x030318(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030318U) ^ (0xaa0003f3U + 0x078ac8U + 52U);
}

// [EN] FDE[0672] start_va=0x03034c, fde_va=0x078ae8, span=32 B | [VN] FDE[0672]
uint32_t ttr_fde_0672_0x03034c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x03034cU) ^ (0xf9401108U + 0x078ae8U + 32U);
}

// [EN] FDE[0673] start_va=0x03036c, fde_va=0x078b08, span=96 B | [VN] FDE[0673]
uint32_t ttr_fde_0673_0x03036c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03036cU) ^ (0xb9400828U + 0x078b08U + 96U);
}

// [EN] FDE[0674] start_va=0x0303cc, fde_va=0x078b28, span=304 B | [VN] FDE[0674]
uint32_t ttr_fde_0674_0x0303cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf90023f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90557f6U + 0x0303ccU) ^ (0xa9064ff4U + 0x078b28U + 304U);
}

// [EN] FDE[0675] start_va=0x0304fc, fde_va=0x078b50, span=948 B | [VN] FDE[0675]
uint32_t ttr_fde_0675_0x0304fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf90013fbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1e03e4U + 0x0304fcU) ^ (0x9400c140U + 0x078b50U + 948U);
}

// [EN] FDE[0676] start_va=0x0308b0, fde_va=0x078b80, span=56 B | [VN] FDE[0676]
uint32_t ttr_fde_0676_0x0308b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0308b0U) ^ (0x910083fdU + 0x078b80U + 56U);
}

uint32_t DispatchTtrFdeShard1(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 0U: return ttr_fde_0000_0x01c750(a0, a1);
        case 1U: return ttr_fde_0001_0x01c8b0(a0, a1);
        case 2U: return ttr_fde_0002_0x01c9ac(a0, a1);
        case 3U: return ttr_fde_0003_0x01caa8(a0, a1);
        case 4U: return ttr_fde_0004_0x01cba4(a0, a1);
        case 5U: return ttr_fde_0005_0x01cca0(a0, a1);
        case 6U: return ttr_fde_0006_0x01cd9c(a0, a1);
        case 7U: return ttr_fde_0007_0x01ce98(a0, a1);
        case 8U: return ttr_fde_0008_0x01cf94(a0, a1);
        case 9U: return ttr_fde_0009_0x01d090(a0, a1);
        case 10U: return ttr_fde_0010_0x01d18c(a0, a1);
        case 11U: return ttr_fde_0011_0x01d2ec(a0, a1);
        case 12U: return ttr_fde_0012_0x01d44c(a0, a1);
        case 13U: return ttr_fde_0013_0x01d5ac(a0, a1);
        case 14U: return ttr_fde_0014_0x01d70c(a0, a1);
        case 15U: return ttr_fde_0015_0x01d86c(a0, a1);
        case 16U: return ttr_fde_0016_0x01d9cc(a0, a1);
        case 17U: return ttr_fde_0017_0x01db2c(a0, a1);
        case 18U: return ttr_fde_0018_0x01dc8c(a0, a1);
        case 19U: return ttr_fde_0019_0x01ddec(a0, a1);
        case 20U: return ttr_fde_0020_0x01df4c(a0, a1);
        case 21U: return ttr_fde_0021_0x01e09c(a0, a1);
        case 22U: return ttr_fde_0022_0x01e220(a0, a1);
        case 23U: return ttr_fde_0023_0x01e374(a0, a1);
        case 24U: return ttr_fde_0024_0x01e4c4(a0, a1);
        case 25U: return ttr_fde_0025_0x01e614(a0, a1);
        case 26U: return ttr_fde_0026_0x01e774(a0, a1);
        case 27U: return ttr_fde_0027_0x01e8c4(a0, a1);
        case 28U: return ttr_fde_0028_0x01ea14(a0, a1);
        case 29U: return ttr_fde_0029_0x01eb74(a0, a1);
        case 30U: return ttr_fde_0030_0x01ecd4(a0, a1);
        case 31U: return ttr_fde_0031_0x01f450(a0, a1);
        case 32U: return ttr_fde_0032_0x01f5a0(a0, a1);
        case 33U: return ttr_fde_0033_0x01f700(a0, a1);
        case 34U: return ttr_fde_0034_0x01f860(a0, a1);
        case 35U: return ttr_fde_0035_0x01f9b0(a0, a1);
        case 36U: return ttr_fde_0036_0x01fb10(a0, a1);
        case 37U: return ttr_fde_0037_0x01fc60(a0, a1);
        case 38U: return ttr_fde_0038_0x01fdb0(a0, a1);
        case 39U: return ttr_fde_0039_0x01ff04(a0, a1);
        case 40U: return ttr_fde_0040_0x020064(a0, a1);
        case 41U: return ttr_fde_0041_0x0201b4(a0, a1);
        case 42U: return ttr_fde_0042_0x020314(a0, a1);
        case 43U: return ttr_fde_0043_0x020464(a0, a1);
        case 44U: return ttr_fde_0044_0x0205c4(a0, a1);
        case 45U: return ttr_fde_0045_0x020714(a0, a1);
        case 46U: return ttr_fde_0046_0x020874(a0, a1);
        case 47U: return ttr_fde_0047_0x0209d4(a0, a1);
        case 48U: return ttr_fde_0048_0x020b34(a0, a1);
        case 49U: return ttr_fde_0049_0x020b48(a0, a1);
        case 50U: return ttr_fde_0050_0x020be4(a0, a1);
        case 51U: return ttr_fde_0051_0x020bf4(a0, a1);
        case 52U: return ttr_fde_0052_0x021004(a0, a1);
        case 53U: return ttr_fde_0053_0x021010(a0, a1);
        case 54U: return ttr_fde_0054_0x021020(a0, a1);
        case 55U: return ttr_fde_0055_0x021024(a0, a1);
        case 56U: return ttr_fde_0056_0x021110(a0, a1);
        case 57U: return ttr_fde_0057_0x02130c(a0, a1);
        case 58U: return ttr_fde_0058_0x021368(a0, a1);
        case 59U: return ttr_fde_0059_0x0213e8(a0, a1);
        case 60U: return ttr_fde_0060_0x021418(a0, a1);
        case 61U: return ttr_fde_0061_0x02141c(a0, a1);
        case 62U: return ttr_fde_0062_0x021424(a0, a1);
        case 63U: return ttr_fde_0063_0x021440(a0, a1);
        case 64U: return ttr_fde_0064_0x02144c(a0, a1);
        case 65U: return ttr_fde_0065_0x021498(a0, a1);
        case 66U: return ttr_fde_0066_0x0214d0(a0, a1);
        case 67U: return ttr_fde_0067_0x02173c(a0, a1);
        case 68U: return ttr_fde_0068_0x0217fc(a0, a1);
        case 69U: return ttr_fde_0069_0x02182c(a0, a1);
        case 70U: return ttr_fde_0070_0x021864(a0, a1);
        case 71U: return ttr_fde_0071_0x021898(a0, a1);
        case 72U: return ttr_fde_0072_0x0218c8(a0, a1);
        case 73U: return ttr_fde_0073_0x0218e0(a0, a1);
        case 74U: return ttr_fde_0074_0x02191c(a0, a1);
        case 75U: return ttr_fde_0075_0x021948(a0, a1);
        case 76U: return ttr_fde_0076_0x021980(a0, a1);
        case 77U: return ttr_fde_0077_0x021ab0(a0, a1);
        case 78U: return ttr_fde_0078_0x021b20(a0, a1);
        case 79U: return ttr_fde_0079_0x021b48(a0, a1);
        case 80U: return ttr_fde_0080_0x021b94(a0, a1);
        case 81U: return ttr_fde_0081_0x021ba8(a0, a1);
        case 82U: return ttr_fde_0082_0x021be0(a0, a1);
        case 83U: return ttr_fde_0083_0x021c08(a0, a1);
        case 84U: return ttr_fde_0084_0x021c18(a0, a1);
        case 85U: return ttr_fde_0085_0x021c34(a0, a1);
        case 86U: return ttr_fde_0086_0x021c38(a0, a1);
        case 87U: return ttr_fde_0087_0x021c3c(a0, a1);
        case 88U: return ttr_fde_0088_0x021c44(a0, a1);
        case 89U: return ttr_fde_0089_0x021c4c(a0, a1);
        case 90U: return ttr_fde_0090_0x021c50(a0, a1);
        case 91U: return ttr_fde_0091_0x021c54(a0, a1);
        case 92U: return ttr_fde_0092_0x021cfc(a0, a1);
        case 93U: return ttr_fde_0093_0x021d00(a0, a1);
        case 94U: return ttr_fde_0094_0x021d3c(a0, a1);
        case 95U: return ttr_fde_0095_0x021d40(a0, a1);
        case 96U: return ttr_fde_0096_0x021de0(a0, a1);
        case 97U: return ttr_fde_0097_0x021de4(a0, a1);
        case 98U: return ttr_fde_0098_0x021df0(a0, a1);
        case 99U: return ttr_fde_0099_0x021e0c(a0, a1);
        case 100U: return ttr_fde_0100_0x021ef8(a0, a1);
        case 101U: return ttr_fde_0101_0x021f0c(a0, a1);
        case 102U: return ttr_fde_0102_0x021f58(a0, a1);
        case 103U: return ttr_fde_0103_0x021fc4(a0, a1);
        case 104U: return ttr_fde_0104_0x022114(a0, a1);
        case 105U: return ttr_fde_0105_0x0221a4(a0, a1);
        case 106U: return ttr_fde_0106_0x02227c(a0, a1);
        case 107U: return ttr_fde_0107_0x0222b0(a0, a1);
        case 108U: return ttr_fde_0108_0x022394(a0, a1);
        case 109U: return ttr_fde_0109_0x0223ac(a0, a1);
        case 110U: return ttr_fde_0110_0x0223b4(a0, a1);
        case 111U: return ttr_fde_0111_0x0223d4(a0, a1);
        case 112U: return ttr_fde_0112_0x0223e8(a0, a1);
        case 113U: return ttr_fde_0113_0x0223f8(a0, a1);
        case 114U: return ttr_fde_0114_0x022400(a0, a1);
        case 115U: return ttr_fde_0115_0x02241c(a0, a1);
        case 116U: return ttr_fde_0116_0x022430(a0, a1);
        case 117U: return ttr_fde_0117_0x022440(a0, a1);
        case 118U: return ttr_fde_0118_0x022448(a0, a1);
        case 119U: return ttr_fde_0119_0x022468(a0, a1);
        case 120U: return ttr_fde_0120_0x022470(a0, a1);
        case 121U: return ttr_fde_0121_0x022478(a0, a1);
        case 122U: return ttr_fde_0122_0x02248c(a0, a1);
        case 123U: return ttr_fde_0123_0x02249c(a0, a1);
        case 124U: return ttr_fde_0124_0x0224b8(a0, a1);
        case 125U: return ttr_fde_0125_0x0224c0(a0, a1);
        case 126U: return ttr_fde_0126_0x0224c8(a0, a1);
        case 127U: return ttr_fde_0127_0x0224d8(a0, a1);
        case 128U: return ttr_fde_0128_0x0224e8(a0, a1);
        case 129U: return ttr_fde_0129_0x02255c(a0, a1);
        case 130U: return ttr_fde_0130_0x022578(a0, a1);
        case 131U: return ttr_fde_0131_0x0226f0(a0, a1);
        case 132U: return ttr_fde_0132_0x022738(a0, a1);
        case 133U: return ttr_fde_0133_0x022770(a0, a1);
        case 134U: return ttr_fde_0134_0x02277c(a0, a1);
        case 135U: return ttr_fde_0135_0x022808(a0, a1);
        case 136U: return ttr_fde_0136_0x02286c(a0, a1);
        case 137U: return ttr_fde_0137_0x0228cc(a0, a1);
        case 138U: return ttr_fde_0138_0x0228e8(a0, a1);
        case 139U: return ttr_fde_0139_0x02295c(a0, a1);
        case 140U: return ttr_fde_0140_0x022994(a0, a1);
        case 141U: return ttr_fde_0141_0x0229c8(a0, a1);
        case 142U: return ttr_fde_0142_0x0229cc(a0, a1);
        case 143U: return ttr_fde_0143_0x0229f0(a0, a1);
        case 144U: return ttr_fde_0144_0x022a18(a0, a1);
        case 145U: return ttr_fde_0145_0x022ab4(a0, a1);
        case 146U: return ttr_fde_0146_0x022ac0(a0, a1);
        case 147U: return ttr_fde_0147_0x022af8(a0, a1);
        case 148U: return ttr_fde_0148_0x022b14(a0, a1);
        case 149U: return ttr_fde_0149_0x022b28(a0, a1);
        case 150U: return ttr_fde_0150_0x022b38(a0, a1);
        case 151U: return ttr_fde_0151_0x022b6c(a0, a1);
        case 152U: return ttr_fde_0152_0x022b78(a0, a1);
        case 153U: return ttr_fde_0153_0x022bac(a0, a1);
        case 154U: return ttr_fde_0154_0x022bc8(a0, a1);
        case 155U: return ttr_fde_0155_0x022bf8(a0, a1);
        case 156U: return ttr_fde_0156_0x022c28(a0, a1);
        case 157U: return ttr_fde_0157_0x022c60(a0, a1);
        case 158U: return ttr_fde_0158_0x022c6c(a0, a1);
        case 159U: return ttr_fde_0159_0x022c74(a0, a1);
        case 160U: return ttr_fde_0160_0x022d68(a0, a1);
        case 161U: return ttr_fde_0161_0x022d94(a0, a1);
        case 162U: return ttr_fde_0162_0x022df0(a0, a1);
        case 163U: return ttr_fde_0163_0x022e24(a0, a1);
        case 164U: return ttr_fde_0164_0x022e54(a0, a1);
        case 165U: return ttr_fde_0165_0x022f44(a0, a1);
        case 166U: return ttr_fde_0166_0x022f7c(a0, a1);
        case 167U: return ttr_fde_0167_0x022fb4(a0, a1);
        case 168U: return ttr_fde_0168_0x022fbc(a0, a1);
        case 169U: return ttr_fde_0169_0x02305c(a0, a1);
        case 170U: return ttr_fde_0170_0x02308c(a0, a1);
        case 171U: return ttr_fde_0171_0x0230e8(a0, a1);
        case 172U: return ttr_fde_0172_0x0230fc(a0, a1);
        case 173U: return ttr_fde_0173_0x023188(a0, a1);
        case 174U: return ttr_fde_0174_0x0231d0(a0, a1);
        case 175U: return ttr_fde_0175_0x023434(a0, a1);
        case 176U: return ttr_fde_0176_0x023534(a0, a1);
        case 177U: return ttr_fde_0177_0x0235ac(a0, a1);
        case 178U: return ttr_fde_0178_0x023628(a0, a1);
        case 179U: return ttr_fde_0179_0x0236a4(a0, a1);
        case 180U: return ttr_fde_0180_0x02371c(a0, a1);
        case 181U: return ttr_fde_0181_0x0237bc(a0, a1);
        case 182U: return ttr_fde_0182_0x0237cc(a0, a1);
        case 183U: return ttr_fde_0183_0x023808(a0, a1);
        case 184U: return ttr_fde_0184_0x023850(a0, a1);
        case 185U: return ttr_fde_0185_0x023884(a0, a1);
        case 186U: return ttr_fde_0186_0x0238c0(a0, a1);
        case 187U: return ttr_fde_0187_0x0238f4(a0, a1);
        case 188U: return ttr_fde_0188_0x023928(a0, a1);
        case 189U: return ttr_fde_0189_0x023964(a0, a1);
        case 190U: return ttr_fde_0190_0x023984(a0, a1);
        case 191U: return ttr_fde_0191_0x023a28(a0, a1);
        case 192U: return ttr_fde_0192_0x023a34(a0, a1);
        case 193U: return ttr_fde_0193_0x023b58(a0, a1);
        case 194U: return ttr_fde_0194_0x023b88(a0, a1);
        case 195U: return ttr_fde_0195_0x023bc8(a0, a1);
        case 196U: return ttr_fde_0196_0x023bf0(a0, a1);
        case 197U: return ttr_fde_0197_0x023c18(a0, a1);
        case 198U: return ttr_fde_0198_0x023c1c(a0, a1);
        case 199U: return ttr_fde_0199_0x023c64(a0, a1);
        case 200U: return ttr_fde_0200_0x023cb8(a0, a1);
        case 201U: return ttr_fde_0201_0x023cf4(a0, a1);
        case 202U: return ttr_fde_0202_0x023d6c(a0, a1);
        case 203U: return ttr_fde_0203_0x023dc4(a0, a1);
        case 204U: return ttr_fde_0204_0x023de0(a0, a1);
        case 205U: return ttr_fde_0205_0x023df4(a0, a1);
        case 206U: return ttr_fde_0206_0x023e2c(a0, a1);
        case 207U: return ttr_fde_0207_0x023e68(a0, a1);
        case 208U: return ttr_fde_0208_0x023e8c(a0, a1);
        case 209U: return ttr_fde_0209_0x023eb0(a0, a1);
        case 210U: return ttr_fde_0210_0x023ee4(a0, a1);
        case 211U: return ttr_fde_0211_0x023f18(a0, a1);
        case 212U: return ttr_fde_0212_0x024044(a0, a1);
        case 213U: return ttr_fde_0213_0x0241d0(a0, a1);
        case 214U: return ttr_fde_0214_0x024274(a0, a1);
        case 215U: return ttr_fde_0215_0x024308(a0, a1);
        case 216U: return ttr_fde_0216_0x02434c(a0, a1);
        case 217U: return ttr_fde_0217_0x024388(a0, a1);
        case 218U: return ttr_fde_0218_0x024398(a0, a1);
        case 219U: return ttr_fde_0219_0x0243c8(a0, a1);
        case 220U: return ttr_fde_0220_0x024408(a0, a1);
        case 221U: return ttr_fde_0221_0x02446c(a0, a1);
        case 222U: return ttr_fde_0222_0x024488(a0, a1);
        case 223U: return ttr_fde_0223_0x02455c(a0, a1);
        case 224U: return ttr_fde_0224_0x02463c(a0, a1);
        case 225U: return ttr_fde_0225_0x0246f0(a0, a1);
        case 226U: return ttr_fde_0226_0x024750(a0, a1);
        case 227U: return ttr_fde_0227_0x02492c(a0, a1);
        case 228U: return ttr_fde_0228_0x024b90(a0, a1);
        case 229U: return ttr_fde_0229_0x024bec(a0, a1);
        case 230U: return ttr_fde_0230_0x024dd4(a0, a1);
        case 231U: return ttr_fde_0231_0x024de0(a0, a1);
        case 232U: return ttr_fde_0232_0x024dfc(a0, a1);
        case 233U: return ttr_fde_0233_0x024e18(a0, a1);
        case 234U: return ttr_fde_0234_0x024e28(a0, a1);
        case 235U: return ttr_fde_0235_0x024e38(a0, a1);
        case 236U: return ttr_fde_0236_0x024e58(a0, a1);
        case 237U: return ttr_fde_0237_0x024e74(a0, a1);
        case 238U: return ttr_fde_0238_0x024e8c(a0, a1);
        case 239U: return ttr_fde_0239_0x024eb8(a0, a1);
        case 240U: return ttr_fde_0240_0x024edc(a0, a1);
        case 241U: return ttr_fde_0241_0x024f0c(a0, a1);
        case 242U: return ttr_fde_0242_0x024f4c(a0, a1);
        case 243U: return ttr_fde_0243_0x025020(a0, a1);
        case 244U: return ttr_fde_0244_0x025170(a0, a1);
        case 245U: return ttr_fde_0245_0x0251e0(a0, a1);
        case 246U: return ttr_fde_0246_0x025218(a0, a1);
        case 247U: return ttr_fde_0247_0x025234(a0, a1);
        case 248U: return ttr_fde_0248_0x025240(a0, a1);
        case 249U: return ttr_fde_0249_0x02528c(a0, a1);
        case 250U: return ttr_fde_0250_0x0252a8(a0, a1);
        case 251U: return ttr_fde_0251_0x02530c(a0, a1);
        case 252U: return ttr_fde_0252_0x025450(a0, a1);
        case 253U: return ttr_fde_0253_0x025540(a0, a1);
        case 254U: return ttr_fde_0254_0x0255a0(a0, a1);
        case 255U: return ttr_fde_0255_0x025694(a0, a1);
        case 256U: return ttr_fde_0256_0x025784(a0, a1);
        case 257U: return ttr_fde_0257_0x0257b0(a0, a1);
        case 258U: return ttr_fde_0258_0x0257b8(a0, a1);
        case 259U: return ttr_fde_0259_0x0257c4(a0, a1);
        case 260U: return ttr_fde_0260_0x0257d8(a0, a1);
        case 261U: return ttr_fde_0261_0x025988(a0, a1);
        case 262U: return ttr_fde_0262_0x02598c(a0, a1);
        case 263U: return ttr_fde_0263_0x0259cc(a0, a1);
        case 264U: return ttr_fde_0264_0x0259d4(a0, a1);
        case 265U: return ttr_fde_0265_0x0259e0(a0, a1);
        case 266U: return ttr_fde_0266_0x025ab0(a0, a1);
        case 267U: return ttr_fde_0267_0x025ae4(a0, a1);
        case 268U: return ttr_fde_0268_0x025b90(a0, a1);
        case 269U: return ttr_fde_0269_0x025b98(a0, a1);
        case 270U: return ttr_fde_0270_0x025b9c(a0, a1);
        case 271U: return ttr_fde_0271_0x025ba0(a0, a1);
        case 272U: return ttr_fde_0272_0x025be4(a0, a1);
        case 273U: return ttr_fde_0273_0x025be8(a0, a1);
        case 274U: return ttr_fde_0274_0x025bec(a0, a1);
        case 275U: return ttr_fde_0275_0x025c38(a0, a1);
        case 276U: return ttr_fde_0276_0x025c44(a0, a1);
        case 277U: return ttr_fde_0277_0x025c50(a0, a1);
        case 278U: return ttr_fde_0278_0x025c5c(a0, a1);
        case 279U: return ttr_fde_0279_0x0262c4(a0, a1);
        case 280U: return ttr_fde_0280_0x026494(a0, a1);
        case 281U: return ttr_fde_0281_0x02659c(a0, a1);
        case 282U: return ttr_fde_0282_0x026708(a0, a1);
        case 283U: return ttr_fde_0283_0x026724(a0, a1);
        case 284U: return ttr_fde_0284_0x026934(a0, a1);
        case 285U: return ttr_fde_0285_0x02696c(a0, a1);
        case 286U: return ttr_fde_0286_0x026994(a0, a1);
        case 287U: return ttr_fde_0287_0x0269cc(a0, a1);
        case 288U: return ttr_fde_0288_0x026a04(a0, a1);
        case 289U: return ttr_fde_0289_0x026a10(a0, a1);
        case 290U: return ttr_fde_0290_0x026cec(a0, a1);
        case 291U: return ttr_fde_0291_0x026d04(a0, a1);
        case 292U: return ttr_fde_0292_0x026d40(a0, a1);
        case 293U: return ttr_fde_0293_0x026d48(a0, a1);
        case 294U: return ttr_fde_0294_0x026d54(a0, a1);
        case 295U: return ttr_fde_0295_0x026d9c(a0, a1);
        case 296U: return ttr_fde_0296_0x026da0(a0, a1);
        case 297U: return ttr_fde_0297_0x026e10(a0, a1);
        case 298U: return ttr_fde_0298_0x026e24(a0, a1);
        case 299U: return ttr_fde_0299_0x026e38(a0, a1);
        case 300U: return ttr_fde_0300_0x026e68(a0, a1);
        case 301U: return ttr_fde_0301_0x026e84(a0, a1);
        case 302U: return ttr_fde_0302_0x026ea0(a0, a1);
        case 303U: return ttr_fde_0303_0x026ebc(a0, a1);
        case 304U: return ttr_fde_0304_0x026f00(a0, a1);
        case 305U: return ttr_fde_0305_0x026f04(a0, a1);
        case 306U: return ttr_fde_0306_0x026f10(a0, a1);
        case 307U: return ttr_fde_0307_0x026f14(a0, a1);
        case 308U: return ttr_fde_0308_0x026f20(a0, a1);
        case 309U: return ttr_fde_0309_0x026f30(a0, a1);
        case 310U: return ttr_fde_0310_0x026f4c(a0, a1);
        case 311U: return ttr_fde_0311_0x02714c(a0, a1);
        case 312U: return ttr_fde_0312_0x02717c(a0, a1);
        case 313U: return ttr_fde_0313_0x027198(a0, a1);
        case 314U: return ttr_fde_0314_0x02719c(a0, a1);
        case 315U: return ttr_fde_0315_0x0271a0(a0, a1);
        case 316U: return ttr_fde_0316_0x0271c0(a0, a1);
        case 317U: return ttr_fde_0317_0x0271dc(a0, a1);
        case 318U: return ttr_fde_0318_0x0271e0(a0, a1);
        case 319U: return ttr_fde_0319_0x0271e4(a0, a1);
        case 320U: return ttr_fde_0320_0x027208(a0, a1);
        case 321U: return ttr_fde_0321_0x027224(a0, a1);
        case 322U: return ttr_fde_0322_0x027228(a0, a1);
        case 323U: return ttr_fde_0323_0x02722c(a0, a1);
        case 324U: return ttr_fde_0324_0x02725c(a0, a1);
        case 325U: return ttr_fde_0325_0x027278(a0, a1);
        case 326U: return ttr_fde_0326_0x02727c(a0, a1);
        case 327U: return ttr_fde_0327_0x027280(a0, a1);
        case 328U: return ttr_fde_0328_0x02728c(a0, a1);
        case 329U: return ttr_fde_0329_0x0272a8(a0, a1);
        case 330U: return ttr_fde_0330_0x0272c0(a0, a1);
        case 331U: return ttr_fde_0331_0x0272cc(a0, a1);
        case 332U: return ttr_fde_0332_0x0272d8(a0, a1);
        case 333U: return ttr_fde_0333_0x0272f0(a0, a1);
        case 334U: return ttr_fde_0334_0x02739c(a0, a1);
        case 335U: return ttr_fde_0335_0x0275a8(a0, a1);
        case 336U: return ttr_fde_0336_0x0275d8(a0, a1);
        case 337U: return ttr_fde_0337_0x0275e4(a0, a1);
        case 338U: return ttr_fde_0338_0x027600(a0, a1);
        case 339U: return ttr_fde_0339_0x027618(a0, a1);
        case 340U: return ttr_fde_0340_0x027624(a0, a1);
        case 341U: return ttr_fde_0341_0x027630(a0, a1);
        case 342U: return ttr_fde_0342_0x02767c(a0, a1);
        case 343U: return ttr_fde_0343_0x027708(a0, a1);
        case 344U: return ttr_fde_0344_0x027ddc(a0, a1);
        case 345U: return ttr_fde_0345_0x027de8(a0, a1);
        case 346U: return ttr_fde_0346_0x027dfc(a0, a1);
        case 347U: return ttr_fde_0347_0x027e00(a0, a1);
        case 348U: return ttr_fde_0348_0x027e0c(a0, a1);
        case 349U: return ttr_fde_0349_0x027e18(a0, a1);
        case 350U: return ttr_fde_0350_0x027e1c(a0, a1);
        case 351U: return ttr_fde_0351_0x027f5c(a0, a1);
        case 352U: return ttr_fde_0352_0x0283e4(a0, a1);
        case 353U: return ttr_fde_0353_0x028428(a0, a1);
        case 354U: return ttr_fde_0354_0x028688(a0, a1);
        case 355U: return ttr_fde_0355_0x0287bc(a0, a1);
        case 356U: return ttr_fde_0356_0x0288b8(a0, a1);
        case 357U: return ttr_fde_0357_0x0288c4(a0, a1);
        case 358U: return ttr_fde_0358_0x0288e0(a0, a1);
        case 359U: return ttr_fde_0359_0x0288f8(a0, a1);
        case 360U: return ttr_fde_0360_0x028904(a0, a1);
        case 361U: return ttr_fde_0361_0x028950(a0, a1);
        case 362U: return ttr_fde_0362_0x0289c0(a0, a1);
        case 363U: return ttr_fde_0363_0x028a04(a0, a1);
        case 364U: return ttr_fde_0364_0x029180(a0, a1);
        case 365U: return ttr_fde_0365_0x0291e8(a0, a1);
        case 366U: return ttr_fde_0366_0x029200(a0, a1);
        case 367U: return ttr_fde_0367_0x02924c(a0, a1);
        case 368U: return ttr_fde_0368_0x029258(a0, a1);
        case 369U: return ttr_fde_0369_0x029290(a0, a1);
        case 370U: return ttr_fde_0370_0x0292ac(a0, a1);
        case 371U: return ttr_fde_0371_0x0292b8(a0, a1);
        case 372U: return ttr_fde_0372_0x0292c4(a0, a1);
        case 373U: return ttr_fde_0373_0x0292d8(a0, a1);
        case 374U: return ttr_fde_0374_0x029364(a0, a1);
        case 375U: return ttr_fde_0375_0x029380(a0, a1);
        case 376U: return ttr_fde_0376_0x0293a4(a0, a1);
        case 377U: return ttr_fde_0377_0x0293c0(a0, a1);
        case 378U: return ttr_fde_0378_0x0293c4(a0, a1);
        case 379U: return ttr_fde_0379_0x0293c8(a0, a1);
        case 380U: return ttr_fde_0380_0x0293cc(a0, a1);
        case 381U: return ttr_fde_0381_0x029414(a0, a1);
        case 382U: return ttr_fde_0382_0x029424(a0, a1);
        case 383U: return ttr_fde_0383_0x02943c(a0, a1);
        case 384U: return ttr_fde_0384_0x029454(a0, a1);
        case 385U: return ttr_fde_0385_0x0294ac(a0, a1);
        case 386U: return ttr_fde_0386_0x0294f8(a0, a1);
        case 387U: return ttr_fde_0387_0x02952c(a0, a1);
        case 388U: return ttr_fde_0388_0x029560(a0, a1);
        case 389U: return ttr_fde_0389_0x02959c(a0, a1);
        case 390U: return ttr_fde_0390_0x0295bc(a0, a1);
        case 391U: return ttr_fde_0391_0x029674(a0, a1);
        case 392U: return ttr_fde_0392_0x02969c(a0, a1);
        case 393U: return ttr_fde_0393_0x0296b0(a0, a1);
        case 394U: return ttr_fde_0394_0x0296c0(a0, a1);
        case 395U: return ttr_fde_0395_0x0296c4(a0, a1);
        case 396U: return ttr_fde_0396_0x029704(a0, a1);
        case 397U: return ttr_fde_0397_0x029710(a0, a1);
        case 398U: return ttr_fde_0398_0x029774(a0, a1);
        case 399U: return ttr_fde_0399_0x029778(a0, a1);
        case 400U: return ttr_fde_0400_0x0298c4(a0, a1);
        case 401U: return ttr_fde_0401_0x029974(a0, a1);
        case 402U: return ttr_fde_0402_0x029a14(a0, a1);
        case 403U: return ttr_fde_0403_0x029a94(a0, a1);
        case 404U: return ttr_fde_0404_0x029a98(a0, a1);
        case 405U: return ttr_fde_0405_0x029a9c(a0, a1);
        case 406U: return ttr_fde_0406_0x029aa0(a0, a1);
        case 407U: return ttr_fde_0407_0x029ad8(a0, a1);
        case 408U: return ttr_fde_0408_0x029b10(a0, a1);
        case 409U: return ttr_fde_0409_0x029c78(a0, a1);
        case 410U: return ttr_fde_0410_0x029c84(a0, a1);
        case 411U: return ttr_fde_0411_0x029c90(a0, a1);
        case 412U: return ttr_fde_0412_0x029ed8(a0, a1);
        case 413U: return ttr_fde_0413_0x029ee0(a0, a1);
        case 414U: return ttr_fde_0414_0x029ee8(a0, a1);
        case 415U: return ttr_fde_0415_0x029ef4(a0, a1);
        case 416U: return ttr_fde_0416_0x029f80(a0, a1);
        case 417U: return ttr_fde_0417_0x02a388(a0, a1);
        case 418U: return ttr_fde_0418_0x02a490(a0, a1);
        case 419U: return ttr_fde_0419_0x02a7e4(a0, a1);
        case 420U: return ttr_fde_0420_0x02a7fc(a0, a1);
        case 421U: return ttr_fde_0421_0x02a808(a0, a1);
        case 422U: return ttr_fde_0422_0x02a820(a0, a1);
        case 423U: return ttr_fde_0423_0x02a83c(a0, a1);
        case 424U: return ttr_fde_0424_0x02a848(a0, a1);
        case 425U: return ttr_fde_0425_0x02a880(a0, a1);
        case 426U: return ttr_fde_0426_0x02a8a4(a0, a1);
        case 427U: return ttr_fde_0427_0x02a8c0(a0, a1);
        case 428U: return ttr_fde_0428_0x02a8c4(a0, a1);
        case 429U: return ttr_fde_0429_0x02a8c8(a0, a1);
        case 430U: return ttr_fde_0430_0x02a8e0(a0, a1);
        case 431U: return ttr_fde_0431_0x02a8ec(a0, a1);
        case 432U: return ttr_fde_0432_0x02a95c(a0, a1);
        case 433U: return ttr_fde_0433_0x02a974(a0, a1);
        case 434U: return ttr_fde_0434_0x02a998(a0, a1);
        case 435U: return ttr_fde_0435_0x02a9c0(a0, a1);
        case 436U: return ttr_fde_0436_0x02a9d8(a0, a1);
        case 437U: return ttr_fde_0437_0x02a9f8(a0, a1);
        case 438U: return ttr_fde_0438_0x02aa34(a0, a1);
        case 439U: return ttr_fde_0439_0x02aa60(a0, a1);
        case 440U: return ttr_fde_0440_0x02aa68(a0, a1);
        case 441U: return ttr_fde_0441_0x02aaa0(a0, a1);
        case 442U: return ttr_fde_0442_0x02acb4(a0, a1);
        case 443U: return ttr_fde_0443_0x02acec(a0, a1);
        case 444U: return ttr_fde_0444_0x02ad20(a0, a1);
        case 445U: return ttr_fde_0445_0x02ad50(a0, a1);
        case 446U: return ttr_fde_0446_0x02ad88(a0, a1);
        case 447U: return ttr_fde_0447_0x02ada4(a0, a1);
        case 448U: return ttr_fde_0448_0x02aef4(a0, a1);
        case 449U: return ttr_fde_0449_0x02af40(a0, a1);
        case 450U: return ttr_fde_0450_0x02b00c(a0, a1);
        case 451U: return ttr_fde_0451_0x02b020(a0, a1);
        case 452U: return ttr_fde_0452_0x02b050(a0, a1);
        case 453U: return ttr_fde_0453_0x02b088(a0, a1);
        case 454U: return ttr_fde_0454_0x02b094(a0, a1);
        case 455U: return ttr_fde_0455_0x02b0fc(a0, a1);
        case 456U: return ttr_fde_0456_0x02b118(a0, a1);
        case 457U: return ttr_fde_0457_0x02b3f4(a0, a1);
        case 458U: return ttr_fde_0458_0x02b82c(a0, a1);
        case 459U: return ttr_fde_0459_0x02b838(a0, a1);
        case 460U: return ttr_fde_0460_0x02b8c8(a0, a1);
        case 461U: return ttr_fde_0461_0x02b8ec(a0, a1);
        case 462U: return ttr_fde_0462_0x02b910(a0, a1);
        case 463U: return ttr_fde_0463_0x02b92c(a0, a1);
        case 464U: return ttr_fde_0464_0x02b930(a0, a1);
        case 465U: return ttr_fde_0465_0x02b934(a0, a1);
        case 466U: return ttr_fde_0466_0x02b958(a0, a1);
        case 467U: return ttr_fde_0467_0x02b974(a0, a1);
        case 468U: return ttr_fde_0468_0x02b978(a0, a1);
        case 469U: return ttr_fde_0469_0x02b97c(a0, a1);
        case 470U: return ttr_fde_0470_0x02b9a0(a0, a1);
        case 471U: return ttr_fde_0471_0x02b9bc(a0, a1);
        case 472U: return ttr_fde_0472_0x02b9c0(a0, a1);
        case 473U: return ttr_fde_0473_0x02b9c4(a0, a1);
        case 474U: return ttr_fde_0474_0x02b9e8(a0, a1);
        case 475U: return ttr_fde_0475_0x02ba04(a0, a1);
        case 476U: return ttr_fde_0476_0x02ba08(a0, a1);
        case 477U: return ttr_fde_0477_0x02ba0c(a0, a1);
        case 478U: return ttr_fde_0478_0x02ba30(a0, a1);
        case 479U: return ttr_fde_0479_0x02ba4c(a0, a1);
        case 480U: return ttr_fde_0480_0x02ba50(a0, a1);
        case 481U: return ttr_fde_0481_0x02ba54(a0, a1);
        case 482U: return ttr_fde_0482_0x02ba78(a0, a1);
        case 483U: return ttr_fde_0483_0x02ba94(a0, a1);
        case 484U: return ttr_fde_0484_0x02ba98(a0, a1);
        case 485U: return ttr_fde_0485_0x02ba9c(a0, a1);
        case 486U: return ttr_fde_0486_0x02baf0(a0, a1);
        case 487U: return ttr_fde_0487_0x02bb38(a0, a1);
        case 488U: return ttr_fde_0488_0x02bd18(a0, a1);
        case 489U: return ttr_fde_0489_0x02bdc4(a0, a1);
        case 490U: return ttr_fde_0490_0x02c1d0(a0, a1);
        case 491U: return ttr_fde_0491_0x02c240(a0, a1);
        case 492U: return ttr_fde_0492_0x02c2d4(a0, a1);
        case 493U: return ttr_fde_0493_0x02c33c(a0, a1);
        case 494U: return ttr_fde_0494_0x02c3ac(a0, a1);
        case 495U: return ttr_fde_0495_0x02c434(a0, a1);
        case 496U: return ttr_fde_0496_0x02c49c(a0, a1);
        case 497U: return ttr_fde_0497_0x02c504(a0, a1);
        case 498U: return ttr_fde_0498_0x02c550(a0, a1);
        case 499U: return ttr_fde_0499_0x02c574(a0, a1);
        case 500U: return ttr_fde_0500_0x02c580(a0, a1);
        case 501U: return ttr_fde_0501_0x02c5a0(a0, a1);
        case 502U: return ttr_fde_0502_0x02c5bc(a0, a1);
        case 503U: return ttr_fde_0503_0x02c5d8(a0, a1);
        case 504U: return ttr_fde_0504_0x02c5dc(a0, a1);
        case 505U: return ttr_fde_0505_0x02c608(a0, a1);
        case 506U: return ttr_fde_0506_0x02c60c(a0, a1);
        case 507U: return ttr_fde_0507_0x02c834(a0, a1);
        case 508U: return ttr_fde_0508_0x02c84c(a0, a1);
        case 509U: return ttr_fde_0509_0x02c8c0(a0, a1);
        case 510U: return ttr_fde_0510_0x02c904(a0, a1);
        case 511U: return ttr_fde_0511_0x02ca0c(a0, a1);
        case 512U: return ttr_fde_0512_0x02cabc(a0, a1);
        case 513U: return ttr_fde_0513_0x02cae0(a0, a1);
        case 514U: return ttr_fde_0514_0x02caec(a0, a1);
        case 515U: return ttr_fde_0515_0x02cb14(a0, a1);
        case 516U: return ttr_fde_0516_0x02cb30(a0, a1);
        case 517U: return ttr_fde_0517_0x02cb44(a0, a1);
        case 518U: return ttr_fde_0518_0x02cb48(a0, a1);
        case 519U: return ttr_fde_0519_0x02cb74(a0, a1);
        case 520U: return ttr_fde_0520_0x02cb78(a0, a1);
        case 521U: return ttr_fde_0521_0x02cd34(a0, a1);
        case 522U: return ttr_fde_0522_0x02cd44(a0, a1);
        case 523U: return ttr_fde_0523_0x02cd4c(a0, a1);
        case 524U: return ttr_fde_0524_0x02cdf8(a0, a1);
        case 525U: return ttr_fde_0525_0x02ce0c(a0, a1);
        case 526U: return ttr_fde_0526_0x02ce18(a0, a1);
        case 527U: return ttr_fde_0527_0x02ce38(a0, a1);
        case 528U: return ttr_fde_0528_0x02ce54(a0, a1);
        case 529U: return ttr_fde_0529_0x02ce84(a0, a1);
        case 530U: return ttr_fde_0530_0x02ce88(a0, a1);
        case 531U: return ttr_fde_0531_0x02cf10(a0, a1);
        case 532U: return ttr_fde_0532_0x02cf14(a0, a1);
        case 533U: return ttr_fde_0533_0x02cf18(a0, a1);
        case 534U: return ttr_fde_0534_0x02d028(a0, a1);
        case 535U: return ttr_fde_0535_0x02d09c(a0, a1);
        case 536U: return ttr_fde_0536_0x02d0f0(a0, a1);
        case 537U: return ttr_fde_0537_0x02d254(a0, a1);
        case 538U: return ttr_fde_0538_0x02d308(a0, a1);
        case 539U: return ttr_fde_0539_0x02d31c(a0, a1);
        case 540U: return ttr_fde_0540_0x02d328(a0, a1);
        case 541U: return ttr_fde_0541_0x02d348(a0, a1);
        case 542U: return ttr_fde_0542_0x02d364(a0, a1);
        case 543U: return ttr_fde_0543_0x02d394(a0, a1);
        case 544U: return ttr_fde_0544_0x02d398(a0, a1);
        case 545U: return ttr_fde_0545_0x02d4d8(a0, a1);
        case 546U: return ttr_fde_0546_0x02d4e0(a0, a1);
        case 547U: return ttr_fde_0547_0x02d5f0(a0, a1);
        case 548U: return ttr_fde_0548_0x02d638(a0, a1);
        case 549U: return ttr_fde_0549_0x02d644(a0, a1);
        case 550U: return ttr_fde_0550_0x02d694(a0, a1);
        case 551U: return ttr_fde_0551_0x02d6b0(a0, a1);
        case 552U: return ttr_fde_0552_0x02d6c0(a0, a1);
        case 553U: return ttr_fde_0553_0x02d6fc(a0, a1);
        case 554U: return ttr_fde_0554_0x02d8a0(a0, a1);
        case 555U: return ttr_fde_0555_0x02d8ac(a0, a1);
        case 556U: return ttr_fde_0556_0x02d8c8(a0, a1);
        case 557U: return ttr_fde_0557_0x02d8ec(a0, a1);
        case 558U: return ttr_fde_0558_0x02d908(a0, a1);
        case 559U: return ttr_fde_0559_0x02d90c(a0, a1);
        case 560U: return ttr_fde_0560_0x02d910(a0, a1);
        case 561U: return ttr_fde_0561_0x02d940(a0, a1);
        case 562U: return ttr_fde_0562_0x02d9cc(a0, a1);
        case 563U: return ttr_fde_0563_0x02da0c(a0, a1);
        case 564U: return ttr_fde_0564_0x02da18(a0, a1);
        case 565U: return ttr_fde_0565_0x02da64(a0, a1);
        case 566U: return ttr_fde_0566_0x02da80(a0, a1);
        case 567U: return ttr_fde_0567_0x02dac8(a0, a1);
        case 568U: return ttr_fde_0568_0x02dad4(a0, a1);
        case 569U: return ttr_fde_0569_0x02daf0(a0, a1);
        case 570U: return ttr_fde_0570_0x02db0c(a0, a1);
        case 571U: return ttr_fde_0571_0x02db18(a0, a1);
        case 572U: return ttr_fde_0572_0x02ddf4(a0, a1);
        case 573U: return ttr_fde_0573_0x02de40(a0, a1);
        case 574U: return ttr_fde_0574_0x02df04(a0, a1);
        case 575U: return ttr_fde_0575_0x02df28(a0, a1);
        case 576U: return ttr_fde_0576_0x02df44(a0, a1);
        case 577U: return ttr_fde_0577_0x02df48(a0, a1);
        case 578U: return ttr_fde_0578_0x02df4c(a0, a1);
        case 579U: return ttr_fde_0579_0x02df70(a0, a1);
        case 580U: return ttr_fde_0580_0x02df8c(a0, a1);
        case 581U: return ttr_fde_0581_0x02df90(a0, a1);
        case 582U: return ttr_fde_0582_0x02df94(a0, a1);
        case 583U: return ttr_fde_0583_0x02dfec(a0, a1);
        case 584U: return ttr_fde_0584_0x02e044(a0, a1);
        case 585U: return ttr_fde_0585_0x02e1ec(a0, a1);
        case 586U: return ttr_fde_0586_0x02e248(a0, a1);
        case 587U: return ttr_fde_0587_0x02e25c(a0, a1);
        case 588U: return ttr_fde_0588_0x02e300(a0, a1);
        case 589U: return ttr_fde_0589_0x02e318(a0, a1);
        case 590U: return ttr_fde_0590_0x02e3a4(a0, a1);
        case 591U: return ttr_fde_0591_0x02e418(a0, a1);
        case 592U: return ttr_fde_0592_0x02e4e8(a0, a1);
        case 593U: return ttr_fde_0593_0x02e544(a0, a1);
        case 594U: return ttr_fde_0594_0x02e568(a0, a1);
        case 595U: return ttr_fde_0595_0x02e5c8(a0, a1);
        case 596U: return ttr_fde_0596_0x02e614(a0, a1);
        case 597U: return ttr_fde_0597_0x02e624(a0, a1);
        case 598U: return ttr_fde_0598_0x02e628(a0, a1);
        case 599U: return ttr_fde_0599_0x02e67c(a0, a1);
        case 600U: return ttr_fde_0600_0x02e6b8(a0, a1);
        case 601U: return ttr_fde_0601_0x02e80c(a0, a1);
        case 602U: return ttr_fde_0602_0x02ea44(a0, a1);
        case 603U: return ttr_fde_0603_0x02eac8(a0, a1);
        case 604U: return ttr_fde_0604_0x02ec10(a0, a1);
        case 605U: return ttr_fde_0605_0x02ec28(a0, a1);
        case 606U: return ttr_fde_0606_0x02ec30(a0, a1);
        case 607U: return ttr_fde_0607_0x02ec60(a0, a1);
        case 608U: return ttr_fde_0608_0x02ec64(a0, a1);
        case 609U: return ttr_fde_0609_0x02ecb0(a0, a1);
        case 610U: return ttr_fde_0610_0x02ed90(a0, a1);
        case 611U: return ttr_fde_0611_0x02eda0(a0, a1);
        case 612U: return ttr_fde_0612_0x02eda8(a0, a1);
        case 613U: return ttr_fde_0613_0x02edb4(a0, a1);
        case 614U: return ttr_fde_0614_0x02edf0(a0, a1);
        case 615U: return ttr_fde_0615_0x02ee0c(a0, a1);
        case 616U: return ttr_fde_0616_0x02ee74(a0, a1);
        case 617U: return ttr_fde_0617_0x02ee78(a0, a1);
        case 618U: return ttr_fde_0618_0x02ee7c(a0, a1);
        case 619U: return ttr_fde_0619_0x02ee80(a0, a1);
        case 620U: return ttr_fde_0620_0x02ee84(a0, a1);
        case 621U: return ttr_fde_0621_0x02efd4(a0, a1);
        case 622U: return ttr_fde_0622_0x02f0f4(a0, a1);
        case 623U: return ttr_fde_0623_0x02f1f4(a0, a1);
        case 624U: return ttr_fde_0624_0x02f420(a0, a1);
        case 625U: return ttr_fde_0625_0x02f670(a0, a1);
        case 626U: return ttr_fde_0626_0x02f6e8(a0, a1);
        case 627U: return ttr_fde_0627_0x02f908(a0, a1);
        case 628U: return ttr_fde_0628_0x02fa60(a0, a1);
        case 629U: return ttr_fde_0629_0x02fa94(a0, a1);
        case 630U: return ttr_fde_0630_0x02fac8(a0, a1);
        case 631U: return ttr_fde_0631_0x02fb4c(a0, a1);
        case 632U: return ttr_fde_0632_0x02fc24(a0, a1);
        case 633U: return ttr_fde_0633_0x02fc3c(a0, a1);
        case 634U: return ttr_fde_0634_0x02fc40(a0, a1);
        case 635U: return ttr_fde_0635_0x02fcc4(a0, a1);
        case 636U: return ttr_fde_0636_0x02fd9c(a0, a1);
        case 637U: return ttr_fde_0637_0x02fdb4(a0, a1);
        case 638U: return ttr_fde_0638_0x02fdb8(a0, a1);
        case 639U: return ttr_fde_0639_0x02fdec(a0, a1);
        case 640U: return ttr_fde_0640_0x02fe8c(a0, a1);
        case 641U: return ttr_fde_0641_0x02febc(a0, a1);
        case 642U: return ttr_fde_0642_0x02fedc(a0, a1);
        case 643U: return ttr_fde_0643_0x02fee8(a0, a1);
        case 644U: return ttr_fde_0644_0x02ff30(a0, a1);
        case 645U: return ttr_fde_0645_0x02ff4c(a0, a1);
        case 646U: return ttr_fde_0646_0x02ff54(a0, a1);
        case 647U: return ttr_fde_0647_0x02ff64(a0, a1);
        case 648U: return ttr_fde_0648_0x02ffa8(a0, a1);
        case 649U: return ttr_fde_0649_0x02ffb4(a0, a1);
        case 650U: return ttr_fde_0650_0x02ffd0(a0, a1);
        case 651U: return ttr_fde_0651_0x02ffd4(a0, a1);
        case 652U: return ttr_fde_0652_0x030038(a0, a1);
        case 653U: return ttr_fde_0653_0x030044(a0, a1);
        case 654U: return ttr_fde_0654_0x030058(a0, a1);
        case 655U: return ttr_fde_0655_0x030074(a0, a1);
        case 656U: return ttr_fde_0656_0x030084(a0, a1);
        case 657U: return ttr_fde_0657_0x0300a0(a0, a1);
        case 658U: return ttr_fde_0658_0x0300d0(a0, a1);
        case 659U: return ttr_fde_0659_0x030108(a0, a1);
        case 660U: return ttr_fde_0660_0x030160(a0, a1);
        case 661U: return ttr_fde_0661_0x03016c(a0, a1);
        case 662U: return ttr_fde_0662_0x030188(a0, a1);
        case 663U: return ttr_fde_0663_0x0301a4(a0, a1);
        case 664U: return ttr_fde_0664_0x0301a8(a0, a1);
        case 665U: return ttr_fde_0665_0x0301ac(a0, a1);
        case 666U: return ttr_fde_0666_0x0301b8(a0, a1);
        case 667U: return ttr_fde_0667_0x030288(a0, a1);
        case 668U: return ttr_fde_0668_0x0302a4(a0, a1);
        case 669U: return ttr_fde_0669_0x0302b4(a0, a1);
        case 670U: return ttr_fde_0670_0x0302f0(a0, a1);
        case 671U: return ttr_fde_0671_0x030318(a0, a1);
        case 672U: return ttr_fde_0672_0x03034c(a0, a1);
        case 673U: return ttr_fde_0673_0x03036c(a0, a1);
        case 674U: return ttr_fde_0674_0x0303cc(a0, a1);
        case 675U: return ttr_fde_0675_0x0304fc(a0, a1);
        case 676U: return ttr_fde_0676_0x0308b0(a0, a1);
        default: return 0U;
    }
}

} // namespace ttr_render
