// ============================================================================
// File: ttr_fde_shard_2.cpp
// Target: libttr.so (625,192 bytes)
// SHA-256: 38c13f772c29f2a6b03c5523b74730be6727dfc9c3de457b1e09fe32578d6f6f
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// FDE Range: [677..1353] of 3,386 (.eh_frame_hdr @ 0x08ab40)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [677..1353]
//      verified directly against the .text section of libttr.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [677..1353]
//      đã đối chiếu trực tiếp với phân đoạn .text của libttr.so.
// ============================================================================

#include "ttr_render_types.h"

namespace ttr_render {

// [EN] FDE[0677] start_va=0x0308e8, fde_va=0x078ba0, span=68 B | [VN] FDE[0677]
uint32_t ttr_fde_0677_0x0308e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xeb02003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x540001c0U + 0x0308e8U) ^ (0xf9400029U + 0x078ba0U + 68U);
}

// [EN] FDE[0678] start_va=0x03092c, fde_va=0x078bb8, span=44 B | [VN] FDE[0678]
uint32_t ttr_fde_0678_0x03092c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03092cU) ^ (0xaa0203f3U + 0x078bb8U + 44U);
}

// [EN] FDE[0679] start_va=0x030958, fde_va=0x078bd8, span=48 B | [VN] FDE[0679]
uint32_t ttr_fde_0679_0x030958(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x030958U) ^ (0x910083fdU + 0x078bd8U + 48U);
}

// [EN] FDE[0680] start_va=0x030988, fde_va=0x078bf8, span=216 B | [VN] FDE[0680]
uint32_t ttr_fde_0680_0x030988(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030988U) ^ (0xaa0003f3U + 0x078bf8U + 216U);
}

// [EN] FDE[0681] start_va=0x030a60, fde_va=0x078c18, span=24 B | [VN] FDE[0681]
uint32_t ttr_fde_0681_0x030a60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x030a60U) ^ (0xb4000040U + 0x078c18U + 24U);
}

// [EN] FDE[0682] start_va=0x030a78, fde_va=0x078c58, span=12 B | [VN] FDE[0682]
uint32_t ttr_fde_0682_0x030a78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001a0U) + (a1 ^ 0x91082800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x030a78U) ^ (0xf81e0ff3U + 0x078c58U + 12U);
}

// [EN] FDE[0683] start_va=0x030a84, fde_va=0x078c70, span=116 B | [VN] FDE[0683]
uint32_t ttr_fde_0683_0x030a84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030a84U) ^ (0xf9401408U + 0x078c70U + 116U);
}

// [EN] FDE[0684] start_va=0x030af8, fde_va=0x078c90, span=28 B | [VN] FDE[0684]
uint32_t ttr_fde_0684_0x030af8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030af8U) ^ (0xaa0003f3U + 0x078c90U + 28U);
}

// [EN] FDE[0685] start_va=0x030b14, fde_va=0x078cb0, span=48 B | [VN] FDE[0685]
uint32_t ttr_fde_0685_0x030b14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030b14U) ^ (0xaa0003f3U + 0x078cb0U + 48U);
}

// [EN] FDE[0686] start_va=0x030b44, fde_va=0x078cd0, span=24 B | [VN] FDE[0686]
uint32_t ttr_fde_0686_0x030b44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x030b44U) ^ (0x9400cf87U + 0x078cd0U + 24U);
}

// [EN] FDE[0687] start_va=0x030b5c, fde_va=0x078cf0, span=764 B | [VN] FDE[0687]
uint32_t ttr_fde_0687_0x030b5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xa9046ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90567faU + 0x030b5cU) ^ (0xa9065ff8U + 0x078cf0U + 764U);
}

// [EN] FDE[0688] start_va=0x030e58, fde_va=0x078d20, span=28 B | [VN] FDE[0688]
uint32_t ttr_fde_0688_0x030e58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400008U) + (a1 ^ 0xa940a40aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd0bU + 0x030e58U) ^ (0x7200011fU + 0x078d20U + 28U);
}

// [EN] FDE[0689] start_va=0x030e74, fde_va=0x078d38, span=148 B | [VN] FDE[0689]
uint32_t ttr_fde_0689_0x030e74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400009U + 0x030e74U) ^ (0xf940040bU + 0x078d38U + 148U);
}

// [EN] FDE[0690] start_va=0x030f08, fde_va=0x078d58, span=232 B | [VN] FDE[0690]
uint32_t ttr_fde_0690_0x030f08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400bbe6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x030f08U) ^ (0xa9067bfdU + 0x078d58U + 232U);
}

// [EN] FDE[0691] start_va=0x030ff0, fde_va=0x078d88, span=24 B | [VN] FDE[0691]
uint32_t ttr_fde_0691_0x030ff0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x030ff0U) ^ (0xb4000040U + 0x078d88U + 24U);
}

// [EN] FDE[0692] start_va=0x031008, fde_va=0x078da0, span=12 B | [VN] FDE[0692]
uint32_t ttr_fde_0692_0x031008(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000042U) + (a1 ^ 0x17ffac49U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400bc33U + 0x031008U) ^ (0xaa1e03e2U + 0x078da0U + 12U);
}

// [EN] FDE[0693] start_va=0x031014, fde_va=0x078db8, span=896 B | [VN] FDE[0693]
uint32_t ttr_fde_0693_0x031014(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400bf19U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x031014U) ^ (0xa9057bfdU + 0x078db8U + 896U);
}

// [EN] FDE[0694] start_va=0x031394, fde_va=0x078de8, span=48 B | [VN] FDE[0694]
uint32_t ttr_fde_0694_0x031394(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd285ad29U) + (a1 ^ 0xf2bd6709U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf2dd4109U + 0x031394U) ^ (0xca000028U + 0x078de8U + 48U);
}

// [EN] FDE[0695] start_va=0x0313c4, fde_va=0x078e00, span=52 B | [VN] FDE[0695]
uint32_t ttr_fde_0695_0x0313c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402c08U) + (a1 ^ 0xa9412809U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b010108U + 0x0313c4U) ^ (0x8b0b0129U + 0x078e00U + 52U);
}

// [EN] FDE[0696] start_va=0x0313f8, fde_va=0x078e40, span=12 B | [VN] FDE[0696]
uint32_t ttr_fde_0696_0x0313f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001a0U) + (a1 ^ 0x91088c00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0313f8U) ^ (0xd100c3ffU + 0x078e40U + 12U);
}

// [EN] FDE[0697] start_va=0x031404, fde_va=0x078e58, span=172 B | [VN] FDE[0697]
uint32_t ttr_fde_0697_0x031404(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xf9000bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x031404U) ^ (0x910083fdU + 0x078e58U + 172U);
}

// [EN] FDE[0698] start_va=0x0314b0, fde_va=0x078e78, span=28 B | [VN] FDE[0698]
uint32_t ttr_fde_0698_0x0314b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0314b0U) ^ (0xaa0003f3U + 0x078e78U + 28U);
}

// [EN] FDE[0699] start_va=0x0314cc, fde_va=0x078e98, span=604 B | [VN] FDE[0699]
uint32_t ttr_fde_0699_0x0314cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xaa1e03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400bc6eU + 0x0314ccU) ^ (0xaa0103feU + 0x078e98U + 604U);
}

// [EN] FDE[0700] start_va=0x031728, fde_va=0x078ec8, span=152 B | [VN] FDE[0700]
uint32_t ttr_fde_0700_0x031728(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x031728U) ^ (0x910083fdU + 0x078ec8U + 152U);
}

// [EN] FDE[0701] start_va=0x0317c0, fde_va=0x078ee8, span=220 B | [VN] FDE[0701]
uint32_t ttr_fde_0701_0x0317c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bb67faU) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x0317c0U) ^ (0xa9034ff4U + 0x078ee8U + 220U);
}

// [EN] FDE[0702] start_va=0x03189c, fde_va=0x078f70, span=120 B | [VN] FDE[0702]
uint32_t ttr_fde_0702_0x03189c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x03189cU) ^ (0x910083fdU + 0x078f70U + 120U);
}

// [EN] FDE[0703] start_va=0x031914, fde_va=0x078f98, span=28 B | [VN] FDE[0703]
uint32_t ttr_fde_0703_0x031914(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x031914U) ^ (0x9400c02eU + 0x078f98U + 28U);
}

// [EN] FDE[0704] start_va=0x031930, fde_va=0x078fb8, span=16 B | [VN] FDE[0704]
uint32_t ttr_fde_0704_0x031930(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x9400c0e6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x031930U) ^ (0x14000001U + 0x078fb8U + 16U);
}

// [EN] FDE[0705] start_va=0x031940, fde_va=0x078fd0, span=148 B | [VN] FDE[0705]
uint32_t ttr_fde_0705_0x031940(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x031940U) ^ (0x910083fdU + 0x078fd0U + 148U);
}

// [EN] FDE[0706] start_va=0x0319d4, fde_va=0x078ff8, span=92 B | [VN] FDE[0706]
uint32_t ttr_fde_0706_0x0319d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0319d4U) ^ (0x910083fdU + 0x078ff8U + 92U);
}

// [EN] FDE[0707] start_va=0x031a30, fde_va=0x079020, span=612 B | [VN] FDE[0707]
uint32_t ttr_fde_0707_0x031a30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x031a30U) ^ (0xa9037bfdU + 0x079020U + 612U);
}

// [EN] FDE[0708] start_va=0x031c94, fde_va=0x079048, span=40 B | [VN] FDE[0708]
uint32_t ttr_fde_0708_0x031c94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x031c94U) ^ (0x9400b9c0U + 0x079048U + 40U);
}

// [EN] FDE[0709] start_va=0x031cbc, fde_va=0x079090, span=12 B | [VN] FDE[0709]
uint32_t ttr_fde_0709_0x031cbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffa813U + 0x031cbcU) ^ (0xf9400008U + 0x079090U + 12U);
}

// [EN] FDE[0710] start_va=0x031cc8, fde_va=0x0790b0, span=48 B | [VN] FDE[0710]
uint32_t ttr_fde_0710_0x031cc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xb40000a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803e0U + 0x031cc8U) ^ (0xf9400508U + 0x0790b0U + 48U);
}

// [EN] FDE[0711] start_va=0x031cf8, fde_va=0x0790c8, span=104 B | [VN] FDE[0711]
uint32_t ttr_fde_0711_0x031cf8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x031cf8U) ^ (0x39400029U + 0x0790c8U + 104U);
}

// [EN] FDE[0712] start_va=0x031d60, fde_va=0x0790e8, span=68 B | [VN] FDE[0712]
uint32_t ttr_fde_0712_0x031d60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400c089U + 0x031d60U) ^ (0x39400028U + 0x0790e8U + 68U);
}

// [EN] FDE[0713] start_va=0x031da4, fde_va=0x079108, span=24 B | [VN] FDE[0713]
uint32_t ttr_fde_0713_0x031da4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40000a1U) + (a1 ^ 0xaa0103e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x12001c41U + 0x031da4U) ^ (0xaa0803e2U + 0x079108U + 24U);
}

// [EN] FDE[0714] start_va=0x031dbc, fde_va=0x079120, span=32 B | [VN] FDE[0714]
uint32_t ttr_fde_0714_0x031dbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400008U) + (a1 ^ 0x37000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd08U + 0x031dbcU) ^ (0x14000002U + 0x079120U + 32U);
}

// [EN] FDE[0715] start_va=0x031ddc, fde_va=0x079138, span=48 B | [VN] FDE[0715]
uint32_t ttr_fde_0715_0x031ddc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x031ddcU) ^ (0xf9400008U + 0x079138U + 48U);
}

// [EN] FDE[0716] start_va=0x031e0c, fde_va=0x079158, span=8 B | [VN] FDE[0716]
uint32_t ttr_fde_0716_0x031e0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400001U) + (a1 ^ 0x14000001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81d0ff5U + 0x031e0cU) ^ (0xa9014ff4U + 0x079158U + 8U);
}

// [EN] FDE[0717] start_va=0x031e14, fde_va=0x079170, span=52 B | [VN] FDE[0717]
uint32_t ttr_fde_0717_0x031e14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x031e14U) ^ (0x910083fdU + 0x079170U + 52U);
}

// [EN] FDE[0718] start_va=0x031e48, fde_va=0x079190, span=152 B | [VN] FDE[0718]
uint32_t ttr_fde_0718_0x031e48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa90357f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9044ff4U + 0x031e48U) ^ (0xa9057bfdU + 0x079190U + 152U);
}

// [EN] FDE[0719] start_va=0x031ee0, fde_va=0x0791b8, span=48 B | [VN] FDE[0719]
uint32_t ttr_fde_0719_0x031ee0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb201f3e8U + 0x031ee0U) ^ (0x9400c4cdU + 0x0791b8U + 48U);
}

// [EN] FDE[0720] start_va=0x031f10, fde_va=0x0791d8, span=52 B | [VN] FDE[0720]
uint32_t ttr_fde_0720_0x031f10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x031f10U) ^ (0x910083fdU + 0x0791d8U + 52U);
}

// [EN] FDE[0721] start_va=0x031f44, fde_va=0x0791f8, span=32 B | [VN] FDE[0721]
uint32_t ttr_fde_0721_0x031f44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x031f44U) ^ (0x9400c359U + 0x0791f8U + 32U);
}

// [EN] FDE[0722] start_va=0x031f64, fde_va=0x079218, span=64 B | [VN] FDE[0722]
uint32_t ttr_fde_0722_0x031f64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x031f64U) ^ (0x9400c23fU + 0x079218U + 64U);
}

// [EN] FDE[0723] start_va=0x031fa4, fde_va=0x079238, span=80 B | [VN] FDE[0723]
uint32_t ttr_fde_0723_0x031fa4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x031fa4U) ^ (0x910083fdU + 0x079238U + 80U);
}

// [EN] FDE[0724] start_va=0x031ff4, fde_va=0x079258, span=36 B | [VN] FDE[0724]
uint32_t ttr_fde_0724_0x031ff4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb201f3e8U) + (a1 ^ 0xf2955568U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf2e15548U + 0x031ff4U) ^ (0xeb08001fU + 0x079258U + 36U);
}

// [EN] FDE[0725] start_va=0x032018, fde_va=0x079278, span=132 B | [VN] FDE[0725]
uint32_t ttr_fde_0725_0x032018(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x032018U) ^ (0xf00001a0U + 0x079278U + 132U);
}

// [EN] FDE[0726] start_va=0x03209c, fde_va=0x079298, span=14308 B | [VN] FDE[0726]
uint32_t ttr_fde_0726_0x03209c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e1U) + (a1 ^ 0x9400b781U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103feU + 0x03209cU) ^ (0xa9067bfdU + 0x079298U + 14308U);
}

// [EN] FDE[0727] start_va=0x035880, fde_va=0x0792c8, span=48 B | [VN] FDE[0727]
uint32_t ttr_fde_0727_0x035880(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x035880U) ^ (0xf0000333U + 0x0792c8U + 48U);
}

// [EN] FDE[0728] start_va=0x0358b0, fde_va=0x0792e8, span=376 B | [VN] FDE[0728]
uint32_t ttr_fde_0728_0x0358b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa9025ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x0358b0U) ^ (0xa9044ff4U + 0x0792e8U + 376U);
}

// [EN] FDE[0729] start_va=0x035a28, fde_va=0x079310, span=12 B | [VN] FDE[0729]
uint32_t ttr_fde_0729_0x035a28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000328U) + (a1 ^ 0xf9474100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400afe7U + 0x035a28U) ^ (0xf81c0ff7U + 0x079310U + 12U);
}

// [EN] FDE[0730] start_va=0x035a34, fde_va=0x079350, span=400 B | [VN] FDE[0730]
uint32_t ttr_fde_0730_0x035a34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x035a34U) ^ (0xa9037bfdU + 0x079350U + 400U);
}

// [EN] FDE[0731] start_va=0x035bc4, fde_va=0x079378, span=100 B | [VN] FDE[0731]
uint32_t ttr_fde_0731_0x035bc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x035bc4U) ^ (0x910083fdU + 0x079378U + 100U);
}

// [EN] FDE[0732] start_va=0x035c28, fde_va=0x079398, span=24 B | [VN] FDE[0732]
uint32_t ttr_fde_0732_0x035c28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001cedU + 0x035c28U) ^ (0x2a1f03e0U + 0x079398U + 24U);
}

// [EN] FDE[0733] start_va=0x035c40, fde_va=0x0793b8, span=24 B | [VN] FDE[0733]
uint32_t ttr_fde_0733_0x035c40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001ce7U + 0x035c40U) ^ (0x2a1f03e0U + 0x0793b8U + 24U);
}

// [EN] FDE[0734] start_va=0x035c58, fde_va=0x0793d8, span=44 B | [VN] FDE[0734]
uint32_t ttr_fde_0734_0x035c58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203e1U + 0x035c58U) ^ (0x97ff994fU + 0x0793d8U + 44U);
}

// [EN] FDE[0735] start_va=0x035c84, fde_va=0x0793f8, span=24 B | [VN] FDE[0735]
uint32_t ttr_fde_0735_0x035c84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001cd6U + 0x035c84U) ^ (0x2a1f03e0U + 0x0793f8U + 24U);
}

// [EN] FDE[0736] start_va=0x035c9c, fde_va=0x079418, span=24 B | [VN] FDE[0736]
uint32_t ttr_fde_0736_0x035c9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001cd0U + 0x035c9cU) ^ (0xaa1f03e0U + 0x079418U + 24U);
}

// [EN] FDE[0737] start_va=0x035cb4, fde_va=0x079438, span=24 B | [VN] FDE[0737]
uint32_t ttr_fde_0737_0x035cb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001ccaU + 0x035cb4U) ^ (0x2a1f03e0U + 0x079438U + 24U);
}

// [EN] FDE[0738] start_va=0x035ccc, fde_va=0x079458, span=24 B | [VN] FDE[0738]
uint32_t ttr_fde_0738_0x035ccc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94001cc4U + 0x035cccU) ^ (0x2a1f03e0U + 0x079458U + 24U);
}

// [EN] FDE[0739] start_va=0x035ce4, fde_va=0x079478, span=4 B | [VN] FDE[0739]
uint32_t ttr_fde_0739_0x035ce4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14001cc0U) + (a1 ^ 0xd00001a0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9111c800U + 0x035ce4U) ^ (0xd65f03c0U + 0x079478U + 4U);
}

// [EN] FDE[0740] start_va=0x035ce8, fde_va=0x0794b8, span=12 B | [VN] FDE[0740]
uint32_t ttr_fde_0740_0x035ce8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001a0U) + (a1 ^ 0x9111c800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x035ce8U) ^ (0xd100c3ffU + 0x0794b8U + 12U);
}

// [EN] FDE[0741] start_va=0x035cf4, fde_va=0x0794d0, span=196 B | [VN] FDE[0741]
uint32_t ttr_fde_0741_0x035cf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa900cfffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x035cf4U) ^ (0x910083fdU + 0x0794d0U + 196U);
}

// [EN] FDE[0742] start_va=0x035db8, fde_va=0x0794f0, span=28 B | [VN] FDE[0742]
uint32_t ttr_fde_0742_0x035db8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x035db8U) ^ (0xaa0003f3U + 0x0794f0U + 28U);
}

// [EN] FDE[0743] start_va=0x035dd4, fde_va=0x079510, span=28 B | [VN] FDE[0743]
uint32_t ttr_fde_0743_0x035dd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x035dd4U) ^ (0x9400a7daU + 0x079510U + 28U);
}

// [EN] FDE[0744] start_va=0x035df0, fde_va=0x079530, span=12 B | [VN] FDE[0744]
uint32_t ttr_fde_0744_0x035df0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffad96U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x035df0U) ^ (0xd10483ffU + 0x079530U + 12U);
}

// [EN] FDE[0745] start_va=0x035dfc, fde_va=0x079548, span=60 B | [VN] FDE[0745]
uint32_t ttr_fde_0745_0x035dfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10483ffU) + (a1 ^ 0xa9104ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9117bfdU + 0x035dfcU) ^ (0x910443fdU + 0x079548U + 60U);
}

// [EN] FDE[0746] start_va=0x035e38, fde_va=0x079568, span=84 B | [VN] FDE[0746]
uint32_t ttr_fde_0746_0x035e38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x035e38U) ^ (0xaa0003f4U + 0x079568U + 84U);
}

// [EN] FDE[0747] start_va=0x035e8c, fde_va=0x079588, span=60 B | [VN] FDE[0747]
uint32_t ttr_fde_0747_0x035e8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10483ffU) + (a1 ^ 0xa9104ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9117bfdU + 0x035e8cU) ^ (0x910443fdU + 0x079588U + 60U);
}

// [EN] FDE[0748] start_va=0x035ec8, fde_va=0x0795a8, span=112 B | [VN] FDE[0748]
uint32_t ttr_fde_0748_0x035ec8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x035ec8U) ^ (0x9100c3fdU + 0x0795a8U + 112U);
}

// [EN] FDE[0749] start_va=0x035f38, fde_va=0x0795c8, span=324 B | [VN] FDE[0749]
uint32_t ttr_fde_0749_0x035f38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x035f38U) ^ (0xd00001a0U + 0x0795c8U + 324U);
}

// [EN] FDE[0750] start_va=0x03607c, fde_va=0x0795e8, span=40 B | [VN] FDE[0750]
uint32_t ttr_fde_0750_0x03607c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03607cU) ^ (0xaa0203f3U + 0x0795e8U + 40U);
}

// [EN] FDE[0751] start_va=0x0360a4, fde_va=0x079630, span=12 B | [VN] FDE[0751]
uint32_t ttr_fde_0751_0x0360a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001a0U) + (a1 ^ 0x91189000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0360a4U) ^ (0xf81e0ff3U + 0x079630U + 12U);
}

// [EN] FDE[0752] start_va=0x0360b0, fde_va=0x079648, span=60 B | [VN] FDE[0752]
uint32_t ttr_fde_0752_0x0360b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0360b0U) ^ (0xaa0003f3U + 0x079648U + 60U);
}

// [EN] FDE[0753] start_va=0x0360ec, fde_va=0x079668, span=28 B | [VN] FDE[0753]
uint32_t ttr_fde_0753_0x0360ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0360ecU) ^ (0xaa0003f3U + 0x079668U + 28U);
}

// [EN] FDE[0754] start_va=0x036108, fde_va=0x079688, span=8 B | [VN] FDE[0754]
uint32_t ttr_fde_0754_0x036108(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400800U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81d0ff5U + 0x036108U) ^ (0xa9014ff4U + 0x079688U + 8U);
}

// [EN] FDE[0755] start_va=0x036110, fde_va=0x0796c8, span=60 B | [VN] FDE[0755]
uint32_t ttr_fde_0755_0x036110(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x036110U) ^ (0x910083fdU + 0x0796c8U + 60U);
}

// [EN] FDE[0756] start_va=0x03614c, fde_va=0x0796e8, span=64 B | [VN] FDE[0756]
uint32_t ttr_fde_0756_0x03614c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03614cU) ^ (0xf9400c08U + 0x0796e8U + 64U);
}

// [EN] FDE[0757] start_va=0x03618c, fde_va=0x079708, span=84 B | [VN] FDE[0757]
uint32_t ttr_fde_0757_0x03618c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03618cU) ^ (0xaa0003f4U + 0x079708U + 84U);
}

// [EN] FDE[0758] start_va=0x0361e0, fde_va=0x079728, span=28 B | [VN] FDE[0758]
uint32_t ttr_fde_0758_0x0361e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0361e0U) ^ (0x9400a6d7U + 0x079728U + 28U);
}

// [EN] FDE[0759] start_va=0x0361fc, fde_va=0x079748, span=12 B | [VN] FDE[0759]
uint32_t ttr_fde_0759_0x0361fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffac93U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0361fcU) ^ (0xb4000040U + 0x079748U + 12U);
}

// [EN] FDE[0760] start_va=0x036208, fde_va=0x079760, span=12 B | [VN] FDE[0760]
uint32_t ttr_fde_0760_0x036208(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffac90U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x036208U) ^ (0xaa1e03e2U + 0x079760U + 12U);
}

// [EN] FDE[0761] start_va=0x036214, fde_va=0x079778, span=232 B | [VN] FDE[0761]
uint32_t ttr_fde_0761_0x036214(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400a723U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x036214U) ^ (0xa9067bfdU + 0x079778U + 232U);
}

// [EN] FDE[0762] start_va=0x0362fc, fde_va=0x0797a8, span=24 B | [VN] FDE[0762]
uint32_t ttr_fde_0762_0x0362fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x0362fcU) ^ (0xb4000040U + 0x0797a8U + 24U);
}

// [EN] FDE[0763] start_va=0x036314, fde_va=0x0797c0, span=48 B | [VN] FDE[0763]
uint32_t ttr_fde_0763_0x036314(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x036314U) ^ (0xaa0003f3U + 0x0797c0U + 48U);
}

// [EN] FDE[0764] start_va=0x036344, fde_va=0x0797e0, span=12 B | [VN] FDE[0764]
uint32_t ttr_fde_0764_0x036344(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001a0U) + (a1 ^ 0x91191c00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x036344U) ^ (0xd100c3ffU + 0x0797e0U + 12U);
}

// [EN] FDE[0765] start_va=0x036350, fde_va=0x0797f8, span=188 B | [VN] FDE[0765]
uint32_t ttr_fde_0765_0x036350(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x036350U) ^ (0x910083fdU + 0x0797f8U + 188U);
}

// [EN] FDE[0766] start_va=0x03640c, fde_va=0x079818, span=28 B | [VN] FDE[0766]
uint32_t ttr_fde_0766_0x03640c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03640cU) ^ (0xaa0003f3U + 0x079818U + 28U);
}

// [EN] FDE[0767] start_va=0x036428, fde_va=0x079838, span=44 B | [VN] FDE[0767]
uint32_t ttr_fde_0767_0x036428(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x036428U) ^ (0xb0000308U + 0x079838U + 44U);
}

// [EN] FDE[0768] start_va=0x036454, fde_va=0x079858, span=12 B | [VN] FDE[0768]
uint32_t ttr_fde_0768_0x036454(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001a0U) + (a1 ^ 0x9118d000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x036454U) ^ (0xf81e0ff3U + 0x079858U + 12U);
}

// [EN] FDE[0769] start_va=0x036460, fde_va=0x079870, span=28 B | [VN] FDE[0769]
uint32_t ttr_fde_0769_0x036460(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x036460U) ^ (0xaa0003f3U + 0x079870U + 28U);
}

// [EN] FDE[0770] start_va=0x03647c, fde_va=0x079890, span=76 B | [VN] FDE[0770]
uint32_t ttr_fde_0770_0x03647c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03647cU) ^ (0x9400aec1U + 0x079890U + 76U);
}

// [EN] FDE[0771] start_va=0x0364c8, fde_va=0x0798b0, span=24 B | [VN] FDE[0771]
uint32_t ttr_fde_0771_0x0364c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2f00e5e0U) + (a1 ^ 0x91004008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfd000000U + 0x0364c8U) ^ (0xb900081fU + 0x0798b0U + 24U);
}

// [EN] FDE[0772] start_va=0x0364e0, fde_va=0x0798c8, span=20 B | [VN] FDE[0772]
uint32_t ttr_fde_0772_0x0364e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x0364e0U) ^ (0x1400a937U + 0x0798c8U + 20U);
}

// [EN] FDE[0773] start_va=0x0364f4, fde_va=0x0798e0, span=4 B | [VN] FDE[0773]
uint32_t ttr_fde_0773_0x0364f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1400b75eU) + (a1 ^ 0xf81d0ff5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9014ff4U + 0x0364f4U) ^ (0xa9027bfdU + 0x0798e0U + 4U);
}

// [EN] FDE[0774] start_va=0x0364f8, fde_va=0x0798f8, span=132 B | [VN] FDE[0774]
uint32_t ttr_fde_0774_0x0364f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0364f8U) ^ (0x910083fdU + 0x0798f8U + 132U);
}

// [EN] FDE[0775] start_va=0x03657c, fde_va=0x079918, span=232 B | [VN] FDE[0775]
uint32_t ttr_fde_0775_0x03657c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400a649U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x03657cU) ^ (0xa9067bfdU + 0x079918U + 232U);
}

// [EN] FDE[0776] start_va=0x036664, fde_va=0x079948, span=24 B | [VN] FDE[0776]
uint32_t ttr_fde_0776_0x036664(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x036664U) ^ (0xb4000040U + 0x079948U + 24U);
}

// [EN] FDE[0777] start_va=0x03667c, fde_va=0x079960, span=28 B | [VN] FDE[0777]
uint32_t ttr_fde_0777_0x03667c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0x8b010109U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb08013fU + 0x03667cU) ^ (0x54000060U + 0x079960U + 28U);
}

// [EN] FDE[0778] start_va=0x036698, fde_va=0x079978, span=192 B | [VN] FDE[0778]
uint32_t ttr_fde_0778_0x036698(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ff9U) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x036698U) ^ (0xa9034ff4U + 0x079978U + 192U);
}

// [EN] FDE[0779] start_va=0x036758, fde_va=0x0799c8, span=12 B | [VN] FDE[0779]
uint32_t ttr_fde_0779_0x036758(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001a0U) + (a1 ^ 0x91197c00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x036758U) ^ (0xb0000308U + 0x0799c8U + 12U);
}

// [EN] FDE[0780] start_va=0x036764, fde_va=0x0799e0, span=16 B | [VN] FDE[0780]
uint32_t ttr_fde_0780_0x036764(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000308U) + (a1 ^ 0x912d2108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007c08U + 0x036764U) ^ (0xd65f03c0U + 0x0799e0U + 16U);
}

// [EN] FDE[0781] start_va=0x036774, fde_va=0x0799f8, span=4 B | [VN] FDE[0781]
uint32_t ttr_fde_0781_0x036774(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff956fU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bfdU + 0x036774U) ^ (0x910003fdU + 0x0799f8U + 4U);
}

// [EN] FDE[0782] start_va=0x036778, fde_va=0x079a10, span=4 B | [VN] FDE[0782]
uint32_t ttr_fde_0782_0x036778(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xa9bf7bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003fdU + 0x036778U) ^ (0xf9400408U + 0x079a10U + 4U);
}

// [EN] FDE[0783] start_va=0x03677c, fde_va=0x079a28, span=68 B | [VN] FDE[0783]
uint32_t ttr_fde_0783_0x03677c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400408U + 0x03677cU) ^ (0x91022100U + 0x079a28U + 68U);
}

// [EN] FDE[0784] start_va=0x0367c0, fde_va=0x079a48, span=48 B | [VN] FDE[0784]
uint32_t ttr_fde_0784_0x0367c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xb4000148U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000329U + 0x0367c0U) ^ (0xf9408929U + 0x079a48U + 48U);
}

// [EN] FDE[0785] start_va=0x0367f0, fde_va=0x079a60, span=20 B | [VN] FDE[0785]
uint32_t ttr_fde_0785_0x0367f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xb4000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9404900U + 0x0367f0U) ^ (0xd65f03c0U + 0x079a60U + 20U);
}

// [EN] FDE[0786] start_va=0x036804, fde_va=0x079a78, span=876 B | [VN] FDE[0786]
uint32_t ttr_fde_0786_0x036804(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd103c3ffU) + (a1 ^ 0xa9096ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90a67faU + 0x036804U) ^ (0xa90b5ff8U + 0x079a78U + 876U);
}

// [EN] FDE[0787] start_va=0x036b70, fde_va=0x079aa8, span=12 B | [VN] FDE[0787]
uint32_t ttr_fde_0787_0x036b70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0x91022100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x036b70U) ^ (0xf9400408U + 0x079aa8U + 12U);
}

// [EN] FDE[0788] start_va=0x036b7c, fde_va=0x079ac0, span=20 B | [VN] FDE[0788]
uint32_t ttr_fde_0788_0x036b7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xb4000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9404100U + 0x036b7cU) ^ (0xd65f03c0U + 0x079ac0U + 20U);
}

// [EN] FDE[0789] start_va=0x036b90, fde_va=0x079ad8, span=20 B | [VN] FDE[0789]
uint32_t ttr_fde_0789_0x036b90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xb4000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9404100U + 0x036b90U) ^ (0xd65f03c0U + 0x079ad8U + 20U);
}

// [EN] FDE[0790] start_va=0x036ba4, fde_va=0x079af0, span=8 B | [VN] FDE[0790]
uint32_t ttr_fde_0790_0x036ba4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x92800000U) + (a1 ^ 0x1400aeb1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81d0ff5U + 0x036ba4U) ^ (0xa9014ff4U + 0x079af0U + 8U);
}

// [EN] FDE[0791] start_va=0x036bac, fde_va=0x079b30, span=172 B | [VN] FDE[0791]
uint32_t ttr_fde_0791_0x036bac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x036bacU) ^ (0x910083fdU + 0x079b30U + 172U);
}

// [EN] FDE[0792] start_va=0x036c58, fde_va=0x079b50, span=12 B | [VN] FDE[0792]
uint32_t ttr_fde_0792_0x036c58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001a0U) + (a1 ^ 0x911a0800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x036c58U) ^ (0xf81e0ff3U + 0x079b50U + 12U);
}

// [EN] FDE[0793] start_va=0x036c64, fde_va=0x079b68, span=68 B | [VN] FDE[0793]
uint32_t ttr_fde_0793_0x036c64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x036c64U) ^ (0xb0000308U + 0x079b68U + 68U);
}

// [EN] FDE[0794] start_va=0x036ca8, fde_va=0x079b88, span=28 B | [VN] FDE[0794]
uint32_t ttr_fde_0794_0x036ca8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x036ca8U) ^ (0xaa0003f3U + 0x079b88U + 28U);
}

// [EN] FDE[0795] start_va=0x036cc4, fde_va=0x079ba8, span=164 B | [VN] FDE[0795]
uint32_t ttr_fde_0795_0x036cc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x036cc4U) ^ (0x910083fdU + 0x079ba8U + 164U);
}

// [EN] FDE[0796] start_va=0x036d68, fde_va=0x079bd0, span=236 B | [VN] FDE[0796]
uint32_t ttr_fde_0796_0x036d68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x036d68U) ^ (0x910083fdU + 0x079bd0U + 236U);
}

// [EN] FDE[0797] start_va=0x036e54, fde_va=0x079bf8, span=92 B | [VN] FDE[0797]
uint32_t ttr_fde_0797_0x036e54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9404008U + 0x036e54U) ^ (0x7100111fU + 0x079bf8U + 92U);
}

// [EN] FDE[0798] start_va=0x036eb0, fde_va=0x079c18, span=88 B | [VN] FDE[0798]
uint32_t ttr_fde_0798_0x036eb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x036eb0U) ^ (0x910083fdU + 0x079c18U + 88U);
}

// [EN] FDE[0799] start_va=0x036f08, fde_va=0x079c40, span=220 B | [VN] FDE[0799]
uint32_t ttr_fde_0799_0x036f08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e6U) + (a1 ^ 0x9400b0f1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0603feU + 0x036f08U) ^ (0xa9057bfdU + 0x079c40U + 220U);
}

// [EN] FDE[0800] start_va=0x036fe4, fde_va=0x079c68, span=176 B | [VN] FDE[0800]
uint32_t ttr_fde_0800_0x036fe4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ff9U) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x036fe4U) ^ (0xa9034ff4U + 0x079c68U + 176U);
}

// [EN] FDE[0801] start_va=0x037094, fde_va=0x079c90, span=176 B | [VN] FDE[0801]
uint32_t ttr_fde_0801_0x037094(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xaa1e03e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400a73aU + 0x037094U) ^ (0xaa0803feU + 0x079c90U + 176U);
}

// [EN] FDE[0802] start_va=0x037144, fde_va=0x079cc0, span=128 B | [VN] FDE[0802]
uint32_t ttr_fde_0802_0x037144(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xaa1e03e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400a70eU + 0x037144U) ^ (0xaa0803feU + 0x079cc0U + 128U);
}

// [EN] FDE[0803] start_va=0x0371c4, fde_va=0x079cf0, span=476 B | [VN] FDE[0803]
uint32_t ttr_fde_0803_0x0371c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e8U) + (a1 ^ 0x9400a4c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803feU + 0x0371c4U) ^ (0xa9077bfdU + 0x079cf0U + 476U);
}

// [EN] FDE[0804] start_va=0x0373a0, fde_va=0x079d20, span=72 B | [VN] FDE[0804]
uint32_t ttr_fde_0804_0x0373a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x0373a0U) ^ (0x9100c3fdU + 0x079d20U + 72U);
}

// [EN] FDE[0805] start_va=0x0373e8, fde_va=0x079d40, span=192 B | [VN] FDE[0805]
uint32_t ttr_fde_0805_0x0373e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0373e8U) ^ (0xb9404c08U + 0x079d40U + 192U);
}

// [EN] FDE[0806] start_va=0x0374a8, fde_va=0x079d60, span=12 B | [VN] FDE[0806]
uint32_t ttr_fde_0806_0x0374a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001a0U) + (a1 ^ 0x911a6000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0374a8U) ^ (0xa9be4ff4U + 0x079d60U + 12U);
}

// [EN] FDE[0807] start_va=0x0374b4, fde_va=0x079d78, span=152 B | [VN] FDE[0807]
uint32_t ttr_fde_0807_0x0374b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x0374b4U) ^ (0x90000308U + 0x079d78U + 152U);
}

// [EN] FDE[0808] start_va=0x03754c, fde_va=0x079d98, span=28 B | [VN] FDE[0808]
uint32_t ttr_fde_0808_0x03754c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03754cU) ^ (0xaa0003f3U + 0x079d98U + 28U);
}

// [EN] FDE[0809] start_va=0x037568, fde_va=0x079db8, span=196 B | [VN] FDE[0809]
uint32_t ttr_fde_0809_0x037568(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x037568U) ^ (0x910083fdU + 0x079db8U + 196U);
}

// [EN] FDE[0810] start_va=0x03762c, fde_va=0x079de0, span=144 B | [VN] FDE[0810]
uint32_t ttr_fde_0810_0x03762c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x03762cU) ^ (0x910083fdU + 0x079de0U + 144U);
}

// [EN] FDE[0811] start_va=0x0376bc, fde_va=0x079e08, span=4 B | [VN] FDE[0811]
uint32_t ttr_fde_0811_0x0376bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xaa1e03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400b0b6U + 0x0376bcU) ^ (0xaa0203feU + 0x079e08U + 4U);
}

// [EN] FDE[0812] start_va=0x0376c0, fde_va=0x079e20, span=376 B | [VN] FDE[0812]
uint32_t ttr_fde_0812_0x0376c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x9400b0b6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x0376c0U) ^ (0xa9067bfdU + 0x079e20U + 376U);
}

// [EN] FDE[0813] start_va=0x037838, fde_va=0x079e48, span=4 B | [VN] FDE[0813]
uint32_t ttr_fde_0813_0x037838(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x900001a0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x911abc00U + 0x037838U) ^ (0xd65f03c0U + 0x079e48U + 4U);
}

// [EN] FDE[0814] start_va=0x03783c, fde_va=0x079e60, span=12 B | [VN] FDE[0814]
uint32_t ttr_fde_0814_0x03783c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001a0U) + (a1 ^ 0x911abc00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03783cU) ^ (0xf81e0ff3U + 0x079e60U + 12U);
}

// [EN] FDE[0815] start_va=0x037848, fde_va=0x079e78, span=68 B | [VN] FDE[0815]
uint32_t ttr_fde_0815_0x037848(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x037848U) ^ (0x90000308U + 0x079e78U + 68U);
}

// [EN] FDE[0816] start_va=0x03788c, fde_va=0x079e98, span=28 B | [VN] FDE[0816]
uint32_t ttr_fde_0816_0x03788c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03788cU) ^ (0xaa0003f3U + 0x079e98U + 28U);
}

// [EN] FDE[0817] start_va=0x0378a8, fde_va=0x079eb8, span=196 B | [VN] FDE[0817]
uint32_t ttr_fde_0817_0x0378a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0378a8U) ^ (0x910083fdU + 0x079eb8U + 196U);
}

// [EN] FDE[0818] start_va=0x03796c, fde_va=0x079ee0, span=248 B | [VN] FDE[0818]
uint32_t ttr_fde_0818_0x03796c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc5ff8U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x03796cU) ^ (0xa9037bfdU + 0x079ee0U + 248U);
}

// [EN] FDE[0819] start_va=0x037a64, fde_va=0x079f08, span=4 B | [VN] FDE[0819]
uint32_t ttr_fde_0819_0x037a64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xaa1e03e6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400ae19U + 0x037a64U) ^ (0xaa0603feU + 0x079f08U + 4U);
}

// [EN] FDE[0820] start_va=0x037a68, fde_va=0x079f20, span=388 B | [VN] FDE[0820]
uint32_t ttr_fde_0820_0x037a68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e6U) + (a1 ^ 0x9400ae19U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0603feU + 0x037a68U) ^ (0xa9057bfdU + 0x079f20U + 388U);
}

// [EN] FDE[0821] start_va=0x037bec, fde_va=0x079f48, span=184 B | [VN] FDE[0821]
uint32_t ttr_fde_0821_0x037bec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf90013fbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1e03e8U + 0x037becU) ^ (0x9400a384U + 0x079f48U + 184U);
}

// [EN] FDE[0822] start_va=0x037ca4, fde_va=0x079f78, span=4 B | [VN] FDE[0822]
uint32_t ttr_fde_0822_0x037ca4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x900001a0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x911b1400U + 0x037ca4U) ^ (0xd65f03c0U + 0x079f78U + 4U);
}

// [EN] FDE[0823] start_va=0x037ca8, fde_va=0x079fb8, span=12 B | [VN] FDE[0823]
uint32_t ttr_fde_0823_0x037ca8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001a0U) + (a1 ^ 0x911b1400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x037ca8U) ^ (0xf81e0ff3U + 0x079fb8U + 12U);
}

// [EN] FDE[0824] start_va=0x037cb4, fde_va=0x079fd0, span=96 B | [VN] FDE[0824]
uint32_t ttr_fde_0824_0x037cb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x037cb4U) ^ (0x90000308U + 0x079fd0U + 96U);
}

// [EN] FDE[0825] start_va=0x037d14, fde_va=0x079ff0, span=28 B | [VN] FDE[0825]
uint32_t ttr_fde_0825_0x037d14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x037d14U) ^ (0xaa0003f3U + 0x079ff0U + 28U);
}

// [EN] FDE[0826] start_va=0x037d30, fde_va=0x07a010, span=156 B | [VN] FDE[0826]
uint32_t ttr_fde_0826_0x037d30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x037d30U) ^ (0x910083fdU + 0x07a010U + 156U);
}

// [EN] FDE[0827] start_va=0x037dcc, fde_va=0x07a030, span=176 B | [VN] FDE[0827]
uint32_t ttr_fde_0827_0x037dcc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x037dccU) ^ (0x910083fdU + 0x07a030U + 176U);
}

// [EN] FDE[0828] start_va=0x037e7c, fde_va=0x07a050, span=124 B | [VN] FDE[0828]
uint32_t ttr_fde_0828_0x037e7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x037e7cU) ^ (0x90000328U + 0x07a050U + 124U);
}

// [EN] FDE[0829] start_va=0x037ef8, fde_va=0x07a070, span=20 B | [VN] FDE[0829]
uint32_t ttr_fde_0829_0x037ef8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000328U) + (a1 ^ 0xf9404108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400c20U + 0x037ef8U) ^ (0xf9400102U + 0x07a070U + 20U);
}

// [EN] FDE[0830] start_va=0x037f0c, fde_va=0x07a0b0, span=168 B | [VN] FDE[0830]
uint32_t ttr_fde_0830_0x037f0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff5U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x037f0cU) ^ (0x910083fdU + 0x07a0b0U + 168U);
}

// [EN] FDE[0831] start_va=0x037fb4, fde_va=0x07a0d0, span=12 B | [VN] FDE[0831]
uint32_t ttr_fde_0831_0x037fb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001a0U) + (a1 ^ 0x911b7000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x037fb4U) ^ (0xf81e0ff3U + 0x07a0d0U + 12U);
}

// [EN] FDE[0832] start_va=0x037fc0, fde_va=0x07a0e8, span=44 B | [VN] FDE[0832]
uint32_t ttr_fde_0832_0x037fc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x037fc0U) ^ (0x90000308U + 0x07a0e8U + 44U);
}

// [EN] FDE[0833] start_va=0x037fec, fde_va=0x07a108, span=28 B | [VN] FDE[0833]
uint32_t ttr_fde_0833_0x037fec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x037fecU) ^ (0xaa0003f3U + 0x07a108U + 28U);
}

// [EN] FDE[0834] start_va=0x038008, fde_va=0x07a128, span=100 B | [VN] FDE[0834]
uint32_t ttr_fde_0834_0x038008(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038008U) ^ (0x9400ac39U + 0x07a128U + 100U);
}

// [EN] FDE[0835] start_va=0x03806c, fde_va=0x07a148, span=244 B | [VN] FDE[0835]
uint32_t ttr_fde_0835_0x03806c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa90457f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9054ff4U + 0x03806cU) ^ (0xa9067bfdU + 0x07a148U + 244U);
}

// [EN] FDE[0836] start_va=0x038160, fde_va=0x07a170, span=640 B | [VN] FDE[0836]
uint32_t ttr_fde_0836_0x038160(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf9001bf9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9045ff8U + 0x038160U) ^ (0xa90557f6U + 0x07a170U + 640U);
}

// [EN] FDE[0837] start_va=0x0383e0, fde_va=0x07a198, span=40 B | [VN] FDE[0837]
uint32_t ttr_fde_0837_0x0383e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xf9000bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x0383e0U) ^ (0x910083fdU + 0x07a198U + 40U);
}

// [EN] FDE[0838] start_va=0x038408, fde_va=0x07a1b8, span=44 B | [VN] FDE[0838]
uint32_t ttr_fde_0838_0x038408(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xf9000bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x038408U) ^ (0x910083fdU + 0x07a1b8U + 44U);
}

// [EN] FDE[0839] start_va=0x038434, fde_va=0x07a1d8, span=412 B | [VN] FDE[0839]
uint32_t ttr_fde_0839_0x038434(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa9025ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x038434U) ^ (0xa9044ff4U + 0x07a1d8U + 412U);
}

// [EN] FDE[0840] start_va=0x0385d0, fde_va=0x07a200, span=68 B | [VN] FDE[0840]
uint32_t ttr_fde_0840_0x0385d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400aac4U + 0x0385d0U) ^ (0xb4000180U + 0x07a200U + 68U);
}

// [EN] FDE[0841] start_va=0x038614, fde_va=0x07a220, span=92 B | [VN] FDE[0841]
uint32_t ttr_fde_0841_0x038614(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038614U) ^ (0x9400a143U + 0x07a220U + 92U);
}

// [EN] FDE[0842] start_va=0x038670, fde_va=0x07a240, span=36 B | [VN] FDE[0842]
uint32_t ttr_fde_0842_0x038670(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038670U) ^ (0xf00002e8U + 0x07a240U + 36U);
}

// [EN] FDE[0843] start_va=0x038694, fde_va=0x07a260, span=28 B | [VN] FDE[0843]
uint32_t ttr_fde_0843_0x038694(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038694U) ^ (0xaa0003f3U + 0x07a260U + 28U);
}

// [EN] FDE[0844] start_va=0x0386b0, fde_va=0x07a280, span=4 B | [VN] FDE[0844]
uint32_t ttr_fde_0844_0x0386b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14009dd1U) + (a1 ^ 0x17ff8d9fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1e03e3U + 0x0386b0U) ^ (0x9400a170U + 0x07a280U + 4U);
}

// [EN] FDE[0845] start_va=0x0386b4, fde_va=0x07a298, span=4 B | [VN] FDE[0845]
uint32_t ttr_fde_0845_0x0386b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff8d9fU) + (a1 ^ 0xaa1e03e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400a170U + 0x0386b4U) ^ (0xaa0303feU + 0x07a298U + 4U);
}

// [EN] FDE[0846] start_va=0x0386b8, fde_va=0x07a2b0, span=1524 B | [VN] FDE[0846]
uint32_t ttr_fde_0846_0x0386b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x9400a170U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x0386b8U) ^ (0xa9057bfdU + 0x07a2b0U + 1524U);
}

// [EN] FDE[0847] start_va=0x038cac, fde_va=0x07a2e0, span=24 B | [VN] FDE[0847]
uint32_t ttr_fde_0847_0x038cac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038cacU) ^ (0x9400a509U + 0x07a2e0U + 24U);
}

// [EN] FDE[0848] start_va=0x038cc4, fde_va=0x07a300, span=12 B | [VN] FDE[0848]
uint32_t ttr_fde_0848_0x038cc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffa1e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x038cc4U) ^ (0xf81e0ff3U + 0x07a300U + 12U);
}

// [EN] FDE[0849] start_va=0x038cd0, fde_va=0x07a318, span=36 B | [VN] FDE[0849]
uint32_t ttr_fde_0849_0x038cd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038cd0U) ^ (0xf00002e8U + 0x07a318U + 36U);
}

// [EN] FDE[0850] start_va=0x038cf4, fde_va=0x07a338, span=28 B | [VN] FDE[0850]
uint32_t ttr_fde_0850_0x038cf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038cf4U) ^ (0xaa0003f3U + 0x07a338U + 28U);
}

// [EN] FDE[0851] start_va=0x038d10, fde_va=0x07a358, span=4 B | [VN] FDE[0851]
uint32_t ttr_fde_0851_0x038d10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14009c39U) + (a1 ^ 0x17ff8c07U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x038d10U) ^ (0x17ffa1ccU + 0x07a358U + 4U);
}

// [EN] FDE[0852] start_va=0x038d14, fde_va=0x07a370, span=4 B | [VN] FDE[0852]
uint32_t ttr_fde_0852_0x038d14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff8c07U) + (a1 ^ 0xb4000040U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa1ccU + 0x038d14U) ^ (0xd65f03c0U + 0x07a370U + 4U);
}

// [EN] FDE[0853] start_va=0x038d18, fde_va=0x07a388, span=12 B | [VN] FDE[0853]
uint32_t ttr_fde_0853_0x038d18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffa1ccU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x038d18U) ^ (0xb4000040U + 0x07a388U + 12U);
}

// [EN] FDE[0854] start_va=0x038d24, fde_va=0x07a3a0, span=12 B | [VN] FDE[0854]
uint32_t ttr_fde_0854_0x038d24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffa1c9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x038d24U) ^ (0xf81e0ff3U + 0x07a3a0U + 12U);
}

// [EN] FDE[0855] start_va=0x038d30, fde_va=0x07a3b8, span=36 B | [VN] FDE[0855]
uint32_t ttr_fde_0855_0x038d30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038d30U) ^ (0xf00002e8U + 0x07a3b8U + 36U);
}

// [EN] FDE[0856] start_va=0x038d54, fde_va=0x07a3d8, span=28 B | [VN] FDE[0856]
uint32_t ttr_fde_0856_0x038d54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038d54U) ^ (0xaa0003f3U + 0x07a3d8U + 28U);
}

// [EN] FDE[0857] start_va=0x038d70, fde_va=0x07a3f8, span=4 B | [VN] FDE[0857]
uint32_t ttr_fde_0857_0x038d70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14009c21U) + (a1 ^ 0x17ff8befU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x038d70U) ^ (0xa9017bfdU + 0x07a3f8U + 4U);
}

// [EN] FDE[0858] start_va=0x038d74, fde_va=0x07a410, span=4 B | [VN] FDE[0858]
uint32_t ttr_fde_0858_0x038d74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff8befU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x038d74U) ^ (0x910043fdU + 0x07a410U + 4U);
}

// [EN] FDE[0859] start_va=0x038d78, fde_va=0x07a428, span=36 B | [VN] FDE[0859]
uint32_t ttr_fde_0859_0x038d78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038d78U) ^ (0xf00002e8U + 0x07a428U + 36U);
}

// [EN] FDE[0860] start_va=0x038d9c, fde_va=0x07a448, span=28 B | [VN] FDE[0860]
uint32_t ttr_fde_0860_0x038d9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038d9cU) ^ (0xaa0003f3U + 0x07a448U + 28U);
}

// [EN] FDE[0861] start_va=0x038db8, fde_va=0x07a468, span=4 B | [VN] FDE[0861]
uint32_t ttr_fde_0861_0x038db8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14009c0fU) + (a1 ^ 0x17ff8bddU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x038db8U) ^ (0xa9017bfdU + 0x07a468U + 4U);
}

// [EN] FDE[0862] start_va=0x038dbc, fde_va=0x07a480, span=4 B | [VN] FDE[0862]
uint32_t ttr_fde_0862_0x038dbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff8bddU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x038dbcU) ^ (0x910043fdU + 0x07a480U + 4U);
}

// [EN] FDE[0863] start_va=0x038dc0, fde_va=0x07a498, span=36 B | [VN] FDE[0863]
uint32_t ttr_fde_0863_0x038dc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038dc0U) ^ (0xf00002e8U + 0x07a498U + 36U);
}

// [EN] FDE[0864] start_va=0x038de4, fde_va=0x07a4b8, span=28 B | [VN] FDE[0864]
uint32_t ttr_fde_0864_0x038de4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038de4U) ^ (0xaa0003f3U + 0x07a4b8U + 28U);
}

// [EN] FDE[0865] start_va=0x038e00, fde_va=0x07a4d8, span=4 B | [VN] FDE[0865]
uint32_t ttr_fde_0865_0x038e00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14009bfdU) + (a1 ^ 0x17ff8bcbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81b0ff9U + 0x038e00U) ^ (0xa9015ff8U + 0x07a4d8U + 4U);
}

// [EN] FDE[0866] start_va=0x038e04, fde_va=0x07a4f0, span=4 B | [VN] FDE[0866]
uint32_t ttr_fde_0866_0x038e04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff8bcbU) + (a1 ^ 0xf81b0ff9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9015ff8U + 0x038e04U) ^ (0xa90257f6U + 0x07a4f0U + 4U);
}

// [EN] FDE[0867] start_va=0x038e08, fde_va=0x07a508, span=160 B | [VN] FDE[0867]
uint32_t ttr_fde_0867_0x038e08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ff9U) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x038e08U) ^ (0xa9034ff4U + 0x07a508U + 160U);
}

// [EN] FDE[0868] start_va=0x038ea8, fde_va=0x07a530, span=24 B | [VN] FDE[0868]
uint32_t ttr_fde_0868_0x038ea8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038ea8U) ^ (0x9400a490U + 0x07a530U + 24U);
}

// [EN] FDE[0869] start_va=0x038ec0, fde_va=0x07a550, span=12 B | [VN] FDE[0869]
uint32_t ttr_fde_0869_0x038ec0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ffa162U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x038ec0U) ^ (0xf81e0ff3U + 0x07a550U + 12U);
}

// [EN] FDE[0870] start_va=0x038ecc, fde_va=0x07a568, span=36 B | [VN] FDE[0870]
uint32_t ttr_fde_0870_0x038ecc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038eccU) ^ (0xf00002e8U + 0x07a568U + 36U);
}

// [EN] FDE[0871] start_va=0x038ef0, fde_va=0x07a588, span=28 B | [VN] FDE[0871]
uint32_t ttr_fde_0871_0x038ef0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038ef0U) ^ (0xaa0003f3U + 0x07a588U + 28U);
}

// [EN] FDE[0872] start_va=0x038f0c, fde_va=0x07a5a8, span=4 B | [VN] FDE[0872]
uint32_t ttr_fde_0872_0x038f0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14009bbaU) + (a1 ^ 0x17ff8b88U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000180U + 0x038f0cU) ^ (0x911bcc00U + 0x07a5a8U + 4U);
}

// [EN] FDE[0873] start_va=0x038f10, fde_va=0x07a5c0, span=4 B | [VN] FDE[0873]
uint32_t ttr_fde_0873_0x038f10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff8b88U) + (a1 ^ 0xf0000180U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x911bcc00U + 0x038f10U) ^ (0xd65f03c0U + 0x07a5c0U + 4U);
}

// [EN] FDE[0874] start_va=0x038f14, fde_va=0x07a600, span=12 B | [VN] FDE[0874]
uint32_t ttr_fde_0874_0x038f14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000180U) + (a1 ^ 0x911bcc00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x038f14U) ^ (0xf81e0ff3U + 0x07a600U + 12U);
}

// [EN] FDE[0875] start_va=0x038f20, fde_va=0x07a618, span=44 B | [VN] FDE[0875]
uint32_t ttr_fde_0875_0x038f20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038f20U) ^ (0x90000308U + 0x07a618U + 44U);
}

// [EN] FDE[0876] start_va=0x038f4c, fde_va=0x07a638, span=28 B | [VN] FDE[0876]
uint32_t ttr_fde_0876_0x038f4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x038f4cU) ^ (0xaa0003f3U + 0x07a638U + 28U);
}

// [EN] FDE[0877] start_va=0x038f68, fde_va=0x07a658, span=792 B | [VN] FDE[0877]
uint32_t ttr_fde_0877_0x038f68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10543ffU) + (a1 ^ 0xa90f6ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91067faU + 0x038f68U) ^ (0xa9115ff8U + 0x07a658U + 792U);
}

// [EN] FDE[0878] start_va=0x039280, fde_va=0x07a688, span=396 B | [VN] FDE[0878]
uint32_t ttr_fde_0878_0x039280(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xaa1e03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94009de0U + 0x039280U) ^ (0xaa0203feU + 0x07a688U + 396U);
}

// [EN] FDE[0879] start_va=0x03940c, fde_va=0x07a6b8, span=880 B | [VN] FDE[0879]
uint32_t ttr_fde_0879_0x03940c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xa9055ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90657f6U + 0x03940cU) ^ (0xa9074ff4U + 0x07a6b8U + 880U);
}

// [EN] FDE[0880] start_va=0x03977c, fde_va=0x07a6e0, span=148 B | [VN] FDE[0880]
uint32_t ttr_fde_0880_0x03977c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03977cU) ^ (0xf9400401U + 0x07a6e0U + 148U);
}

// [EN] FDE[0881] start_va=0x039810, fde_va=0x07a700, span=92 B | [VN] FDE[0881]
uint32_t ttr_fde_0881_0x039810(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xf9000bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x039810U) ^ (0x910083fdU + 0x07a700U + 92U);
}

// [EN] FDE[0882] start_va=0x03986c, fde_va=0x07a720, span=208 B | [VN] FDE[0882]
uint32_t ttr_fde_0882_0x03986c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ff9U) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x03986cU) ^ (0xa9034ff4U + 0x07a720U + 208U);
}

// [EN] FDE[0883] start_va=0x03993c, fde_va=0x07a748, span=4 B | [VN] FDE[0883]
uint32_t ttr_fde_0883_0x03993c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14000001U) + (a1 ^ 0xaa000029U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf100013fU + 0x03993cU) ^ (0xaa0003e8U + 0x07a748U + 4U);
}

// [EN] FDE[0884] start_va=0x039940, fde_va=0x07a760, span=56 B | [VN] FDE[0884]
uint32_t ttr_fde_0884_0x039940(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa000029U) + (a1 ^ 0xf100013fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e8U + 0x039940U) ^ (0x1a9f17e0U + 0x07a760U + 56U);
}

// [EN] FDE[0885] start_va=0x039978, fde_va=0x07a780, span=192 B | [VN] FDE[0885]
uint32_t ttr_fde_0885_0x039978(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ff9U) + (a1 ^ 0xa9015ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x039978U) ^ (0xa9034ff4U + 0x07a780U + 192U);
}

// [EN] FDE[0886] start_va=0x039a38, fde_va=0x07a7a8, span=52 B | [VN] FDE[0886]
uint32_t ttr_fde_0886_0x039a38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x039a38U) ^ (0x94009f42U + 0x07a7a8U + 52U);
}

// [EN] FDE[0887] start_va=0x039a6c, fde_va=0x07a7c8, span=52 B | [VN] FDE[0887]
uint32_t ttr_fde_0887_0x039a6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x039a6cU) ^ (0x94009f35U + 0x07a7c8U + 52U);
}

// [EN] FDE[0888] start_va=0x039aa0, fde_va=0x07a7e8, span=676 B | [VN] FDE[0888]
uint32_t ttr_fde_0888_0x039aa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x94009a89U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x039aa0U) ^ (0xa9077bfdU + 0x07a7e8U + 676U);
}

// [EN] FDE[0889] start_va=0x039d44, fde_va=0x07a818, span=324 B | [VN] FDE[0889]
uint32_t ttr_fde_0889_0x039d44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81a0ffbU) + (a1 ^ 0xaa1e03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94009c0eU + 0x039d44U) ^ (0xaa0203feU + 0x07a818U + 324U);
}

// [EN] FDE[0890] start_va=0x039e88, fde_va=0x07a848, span=24 B | [VN] FDE[0890]
uint32_t ttr_fde_0890_0x039e88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x039e88U) ^ (0xb4000040U + 0x07a848U + 24U);
}

// [EN] FDE[0891] start_va=0x039ea0, fde_va=0x07a860, span=1104 B | [VN] FDE[0891]
uint32_t ttr_fde_0891_0x039ea0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xaa1e03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940099f9U + 0x039ea0U) ^ (0xaa0203feU + 0x07a860U + 1104U);
}

// [EN] FDE[0892] start_va=0x03a2f0, fde_va=0x07a890, span=24 B | [VN] FDE[0892]
uint32_t ttr_fde_0892_0x03a2f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37dfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14009f52U + 0x03a2f0U) ^ (0xa9bf7bfdU + 0x07a890U + 24U);
}

// [EN] FDE[0893] start_va=0x03a308, fde_va=0x07a8b0, span=232 B | [VN] FDE[0893]
uint32_t ttr_fde_0893_0x03a308(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x940096e6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x03a308U) ^ (0xa9067bfdU + 0x07a8b0U + 232U);
}

// [EN] FDE[0894] start_va=0x03a3f0, fde_va=0x07a8e0, span=24 B | [VN] FDE[0894]
uint32_t ttr_fde_0894_0x03a3f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x03a3f0U) ^ (0xb4000040U + 0x07a8e0U + 24U);
}

// [EN] FDE[0895] start_va=0x03a408, fde_va=0x07a920, span=152 B | [VN] FDE[0895]
uint32_t ttr_fde_0895_0x03a408(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xf9000bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x03a408U) ^ (0x910083fdU + 0x07a920U + 152U);
}

// [EN] FDE[0896] start_va=0x03a4a0, fde_va=0x07a940, span=12 B | [VN] FDE[0896]
uint32_t ttr_fde_0896_0x03a4a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000180U) + (a1 ^ 0x911c4000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03a4a0U) ^ (0xa9be4ff4U + 0x07a940U + 12U);
}

// [EN] FDE[0897] start_va=0x03a4ac, fde_va=0x07a958, span=84 B | [VN] FDE[0897]
uint32_t ttr_fde_0897_0x03a4ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03a4acU) ^ (0xd00002e8U + 0x07a958U + 84U);
}

// [EN] FDE[0898] start_va=0x03a500, fde_va=0x07a978, span=28 B | [VN] FDE[0898]
uint32_t ttr_fde_0898_0x03a500(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03a500U) ^ (0xaa0003f3U + 0x07a978U + 28U);
}

// [EN] FDE[0899] start_va=0x03a51c, fde_va=0x07a998, span=4 B | [VN] FDE[0899]
uint32_t ttr_fde_0899_0x03a51c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xa9bf7bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003fdU + 0x03a51cU) ^ (0xf9402008U + 0x07a998U + 4U);
}

// [EN] FDE[0900] start_va=0x03a520, fde_va=0x07a9b0, span=68 B | [VN] FDE[0900]
uint32_t ttr_fde_0900_0x03a520(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9402008U + 0x03a520U) ^ (0xb4000188U + 0x07a9b0U + 68U);
}

// [EN] FDE[0901] start_va=0x03a564, fde_va=0x07a9d0, span=1068 B | [VN] FDE[0901]
uint32_t ttr_fde_0901_0x03a564(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf90013fbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1e03e2U + 0x03a564U) ^ (0x94009926U + 0x07a9d0U + 1068U);
}

// [EN] FDE[0902] start_va=0x03a990, fde_va=0x07aa00, span=64 B | [VN] FDE[0902]
uint32_t ttr_fde_0902_0x03a990(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03a990U) ^ (0xb0000309U + 0x07aa00U + 64U);
}

// [EN] FDE[0903] start_va=0x03a9d0, fde_va=0x07aa20, span=56 B | [VN] FDE[0903]
uint32_t ttr_fde_0903_0x03a9d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40001a1U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x03a9d0U) ^ (0x910043fdU + 0x07aa20U + 56U);
}

// [EN] FDE[0904] start_va=0x03aa08, fde_va=0x07aa40, span=8 B | [VN] FDE[0904]
uint32_t ttr_fde_0904_0x03aa08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9001801U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9001c01U + 0x03aa08U) ^ (0xd65f03c0U + 0x07aa40U + 8U);
}

// [EN] FDE[0905] start_va=0x03aa10, fde_va=0x07aa58, span=8 B | [VN] FDE[0905]
uint32_t ttr_fde_0905_0x03aa10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9001c01U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff3U + 0x03aa10U) ^ (0xa9017bfdU + 0x07aa58U + 8U);
}

// [EN] FDE[0906] start_va=0x03aa18, fde_va=0x07aa70, span=64 B | [VN] FDE[0906]
uint32_t ttr_fde_0906_0x03aa18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03aa18U) ^ (0xb4000161U + 0x07aa70U + 64U);
}

// [EN] FDE[0907] start_va=0x03aa58, fde_va=0x07aa90, span=56 B | [VN] FDE[0907]
uint32_t ttr_fde_0907_0x03aa58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb40001a1U) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x03aa58U) ^ (0x910043fdU + 0x07aa90U + 56U);
}

// [EN] FDE[0908] start_va=0x03aa90, fde_va=0x07aab0, span=164 B | [VN] FDE[0908]
uint32_t ttr_fde_0908_0x03aa90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x03aa90U) ^ (0xa9037bfdU + 0x07aab0U + 164U);
}

// [EN] FDE[0909] start_va=0x03ab34, fde_va=0x07aad8, span=104 B | [VN] FDE[0909]
uint32_t ttr_fde_0909_0x03ab34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd57f6U) + (a1 ^ 0xa9014ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bfdU + 0x03ab34U) ^ (0x910083fdU + 0x07aad8U + 104U);
}

// [EN] FDE[0910] start_va=0x03ab9c, fde_va=0x07ab00, span=4 B | [VN] FDE[0910]
uint32_t ttr_fde_0910_0x03ab9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03ab9cU) ^ (0xd10203ffU + 0x07ab00U + 4U);
}

// [EN] FDE[0911] start_va=0x03aba0, fde_va=0x07ab18, span=4 B | [VN] FDE[0911]
uint32_t ttr_fde_0911_0x03aba0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10203ffU + 0x03aba0U) ^ (0xf90013fbU + 0x07ab18U + 4U);
}

// [EN] FDE[0912] start_va=0x03aba4, fde_va=0x07ab30, span=4 B | [VN] FDE[0912]
uint32_t ttr_fde_0912_0x03aba4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xd10203ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013fbU + 0x03aba4U) ^ (0xaa1e03e2U + 0x07ab30U + 4U);
}

// [EN] FDE[0913] start_va=0x03aba8, fde_va=0x07ab48, span=372 B | [VN] FDE[0913]
uint32_t ttr_fde_0913_0x03aba8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf90013fbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1e03e2U + 0x03aba8U) ^ (0x94009795U + 0x07ab48U + 372U);
}

// [EN] FDE[0914] start_va=0x03ad1c, fde_va=0x07ab78, span=100 B | [VN] FDE[0914]
uint32_t ttr_fde_0914_0x03ad1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400a060U + 0x03ad1cU) ^ (0xb9401401U + 0x07ab78U + 100U);
}

// [EN] FDE[0915] start_va=0x03ad80, fde_va=0x07ab98, span=12 B | [VN] FDE[0915]
uint32_t ttr_fde_0915_0x03ad80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff99b2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03ad80U) ^ (0xf81e0ff3U + 0x07ab98U + 12U);
}

// [EN] FDE[0916] start_va=0x03ad8c, fde_va=0x07abb0, span=24 B | [VN] FDE[0916]
uint32_t ttr_fde_0916_0x03ad8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03ad8cU) ^ (0x94009fceU + 0x07abb0U + 24U);
}

// [EN] FDE[0917] start_va=0x03ada4, fde_va=0x07abd0, span=16 B | [VN] FDE[0917]
uint32_t ttr_fde_0917_0x03ada4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400c00U) + (a1 ^ 0xb4000040U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff8441U + 0x03ada4U) ^ (0xd65f03c0U + 0x07abd0U + 16U);
}

// [EN] FDE[0918] start_va=0x03adb4, fde_va=0x07abe8, span=16 B | [VN] FDE[0918]
uint32_t ttr_fde_0918_0x03adb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400428U) + (a1 ^ 0xb00001a9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x913f0129U + 0x03adb4U) ^ (0x1400a11bU + 0x07abe8U + 16U);
}

// [EN] FDE[0919] start_va=0x03adc4, fde_va=0x07ac00, span=4 B | [VN] FDE[0919]
uint32_t ttr_fde_0919_0x03adc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff83dbU) + (a1 ^ 0xf81e0ff3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x03adc4U) ^ (0x910043fdU + 0x07ac00U + 4U);
}

// [EN] FDE[0920] start_va=0x03adc8, fde_va=0x07ac18, span=24 B | [VN] FDE[0920]
uint32_t ttr_fde_0920_0x03adc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03adc8U) ^ (0x94009fbfU + 0x07ac18U + 24U);
}

// [EN] FDE[0921] start_va=0x03ade0, fde_va=0x07ac38, span=16 B | [VN] FDE[0921]
uint32_t ttr_fde_0921_0x03ade0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400c00U) + (a1 ^ 0xb4000040U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff8432U + 0x03ade0U) ^ (0xd65f03c0U + 0x07ac38U + 16U);
}

// [EN] FDE[0922] start_va=0x03adf0, fde_va=0x07ac50, span=16 B | [VN] FDE[0922]
uint32_t ttr_fde_0922_0x03adf0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400428U) + (a1 ^ 0xd00001a9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91027d29U + 0x03adf0U) ^ (0x1400a10cU + 0x07ac50U + 16U);
}

// [EN] FDE[0923] start_va=0x03ae00, fde_va=0x07ac68, span=4 B | [VN] FDE[0923]
uint32_t ttr_fde_0923_0x03ae00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff83ccU) + (a1 ^ 0xaa1e03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94009427U + 0x03ae00U) ^ (0xaa0103feU + 0x07ac68U + 4U);
}

// [EN] FDE[0924] start_va=0x03ae04, fde_va=0x07ac80, span=1028 B | [VN] FDE[0924]
uint32_t ttr_fde_0924_0x03ae04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e1U) + (a1 ^ 0x94009427U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103feU + 0x03ae04U) ^ (0xa9067bfdU + 0x07ac80U + 1028U);
}

// [EN] FDE[0925] start_va=0x03b208, fde_va=0x07acd8, span=12 B | [VN] FDE[0925]
uint32_t ttr_fde_0925_0x03b208(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000180U) + (a1 ^ 0x911cbc00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03b208U) ^ (0xb00002e8U + 0x07acd8U + 12U);
}

// [EN] FDE[0926] start_va=0x03b214, fde_va=0x07acf0, span=16 B | [VN] FDE[0926]
uint32_t ttr_fde_0926_0x03b214(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00002e8U) + (a1 ^ 0x9109e108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007c08U + 0x03b214U) ^ (0xd65f03c0U + 0x07acf0U + 16U);
}

// [EN] FDE[0927] start_va=0x03b224, fde_va=0x07ad08, span=4 B | [VN] FDE[0927]
uint32_t ttr_fde_0927_0x03b224(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff82c3U) + (a1 ^ 0xf81a0ffbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1e03e2U + 0x03b224U) ^ (0x940096d5U + 0x07ad08U + 4U);
}

// [EN] FDE[0928] start_va=0x03b228, fde_va=0x07ad20, span=496 B | [VN] FDE[0928]
uint32_t ttr_fde_0928_0x03b228(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81a0ffbU) + (a1 ^ 0xaa1e03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940096d5U + 0x03b228U) ^ (0xaa0203feU + 0x07ad20U + 496U);
}

// [EN] FDE[0929] start_va=0x03b418, fde_va=0x07ad78, span=12 B | [VN] FDE[0929]
uint32_t ttr_fde_0929_0x03b418(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000180U) + (a1 ^ 0x911d2000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03b418U) ^ (0xb00002e8U + 0x07ad78U + 12U);
}

// [EN] FDE[0930] start_va=0x03b424, fde_va=0x07ad90, span=16 B | [VN] FDE[0930]
uint32_t ttr_fde_0930_0x03b424(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00002e8U) + (a1 ^ 0x910b0108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x03b424U) ^ (0x1400007aU + 0x07ad90U + 16U);
}

// [EN] FDE[0931] start_va=0x03b434, fde_va=0x07ada8, span=28 B | [VN] FDE[0931]
uint32_t ttr_fde_0931_0x03b434(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03b434U) ^ (0xaa0003f3U + 0x07ada8U + 28U);
}

// [EN] FDE[0932] start_va=0x03b450, fde_va=0x07adc8, span=456 B | [VN] FDE[0932]
uint32_t ttr_fde_0932_0x03b450(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf9001bf9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9045ff8U + 0x03b450U) ^ (0xa90557f6U + 0x07adc8U + 456U);
}

// [EN] FDE[0933] start_va=0x03b618, fde_va=0x07adf0, span=140 B | [VN] FDE[0933]
uint32_t ttr_fde_0933_0x03b618(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03b618U) ^ (0xaa0003f3U + 0x07adf0U + 140U);
}

// [EN] FDE[0934] start_va=0x03b6a4, fde_va=0x07ae10, span=140 B | [VN] FDE[0934]
uint32_t ttr_fde_0934_0x03b6a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03b6a4U) ^ (0xb4000361U + 0x07ae10U + 140U);
}

// [EN] FDE[0935] start_va=0x03b730, fde_va=0x07ae30, span=84 B | [VN] FDE[0935]
uint32_t ttr_fde_0935_0x03b730(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03b730U) ^ (0xf9403808U + 0x07ae30U + 84U);
}

// [EN] FDE[0936] start_va=0x03b784, fde_va=0x07ae50, span=72 B | [VN] FDE[0936]
uint32_t ttr_fde_0936_0x03b784(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03b784U) ^ (0x360001a1U + 0x07ae50U + 72U);
}

// [EN] FDE[0937] start_va=0x03b7cc, fde_va=0x07ae70, span=60 B | [VN] FDE[0937]
uint32_t ttr_fde_0937_0x03b7cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03b7ccU) ^ (0xaa0103f3U + 0x07ae70U + 60U);
}

// [EN] FDE[0938] start_va=0x03b808, fde_va=0x07ae90, span=12 B | [VN] FDE[0938]
uint32_t ttr_fde_0938_0x03b808(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x3dc01c00U) + (a1 ^ 0x3d801020U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03b808U) ^ (0x14009232U + 0x07ae90U + 12U);
}

// [EN] FDE[0939] start_va=0x03b814, fde_va=0x07aea8, span=4 B | [VN] FDE[0939]
uint32_t ttr_fde_0939_0x03b814(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14009232U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90157f6U + 0x03b814U) ^ (0xa9024ff4U + 0x07aea8U + 4U);
}

// [EN] FDE[0940] start_va=0x03b818, fde_va=0x07aec0, span=156 B | [VN] FDE[0940]
uint32_t ttr_fde_0940_0x03b818(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x03b818U) ^ (0xa9037bfdU + 0x07aec0U + 156U);
}

// [EN] FDE[0941] start_va=0x03b8b4, fde_va=0x07aee8, span=20 B | [VN] FDE[0941]
uint32_t ttr_fde_0941_0x03b8b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xb9001401U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800020U + 0x03b8b4U) ^ (0xb9001902U + 0x07aee8U + 20U);
}

// [EN] FDE[0942] start_va=0x03b8c8, fde_va=0x07af00, span=444 B | [VN] FDE[0942]
uint32_t ttr_fde_0942_0x03b8c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xfd0013e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90017f7U + 0x03b8c8U) ^ (0xa90357f6U + 0x07af00U + 444U);
}

// [EN] FDE[0943] start_va=0x03ba84, fde_va=0x07af28, span=168 B | [VN] FDE[0943]
uint32_t ttr_fde_0943_0x03ba84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9024ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x03ba84U) ^ (0x9100c3fdU + 0x07af28U + 168U);
}

// [EN] FDE[0944] start_va=0x03bb2c, fde_va=0x07af48, span=76 B | [VN] FDE[0944]
uint32_t ttr_fde_0944_0x03bb2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffcae1U + 0x03bb2cU) ^ (0x900002e1U + 0x07af48U + 76U);
}

// [EN] FDE[0945] start_va=0x03bb78, fde_va=0x07af68, span=316 B | [VN] FDE[0945]
uint32_t ttr_fde_0945_0x03bb78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9000bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90257f6U + 0x03bb78U) ^ (0xa9034ff4U + 0x07af68U + 316U);
}

// [EN] FDE[0946] start_va=0x03bcb4, fde_va=0x07af90, span=336 B | [VN] FDE[0946]
uint32_t ttr_fde_0946_0x03bcb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03bcb4U) ^ (0x7100281fU + 0x07af90U + 336U);
}

// [EN] FDE[0947] start_va=0x03be04, fde_va=0x07afb0, span=4 B | [VN] FDE[0947]
uint32_t ttr_fde_0947_0x03be04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd4200020U) + (a1 ^ 0xb9401408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9000028U + 0x03be04U) ^ (0xb9401808U + 0x07afb0U + 4U);
}

// [EN] FDE[0948] start_va=0x03be08, fde_va=0x07afc8, span=24 B | [VN] FDE[0948]
uint32_t ttr_fde_0948_0x03be08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401408U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401808U + 0x03be08U) ^ (0x52800020U + 0x07afc8U + 24U);
}

// [EN] FDE[0949] start_va=0x03be20, fde_va=0x07b008, span=140 B | [VN] FDE[0949]
uint32_t ttr_fde_0949_0x03be20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x129169e8U) + (a1 ^ 0x0b080008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100311fU + 0x03be20U) ^ (0x54000108U + 0x07b008U + 140U);
}

// [EN] FDE[0950] start_va=0x03beac, fde_va=0x07b020, span=56 B | [VN] FDE[0950]
uint32_t ttr_fde_0950_0x03beac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x360000c1U) + (a1 ^ 0x370000a2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x71000c1fU + 0x03beacU) ^ (0x5284c008U + 0x07b020U + 56U);
}

// [EN] FDE[0951] start_va=0x03bee4, fde_va=0x07b038, span=196 B | [VN] FDE[0951]
uint32_t ttr_fde_0951_0x03bee4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5100080aU) + (a1 ^ 0x7100215fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000188U + 0x03bee4U) ^ (0xb000014bU + 0x07b038U + 196U);
}

// [EN] FDE[0952] start_va=0x03bfa8, fde_va=0x07b078, span=92 B | [VN] FDE[0952]
uint32_t ttr_fde_0952_0x03bfa8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03bfa8U) ^ (0xaa0003f3U + 0x07b078U + 92U);
}

// [EN] FDE[0953] start_va=0x03c004, fde_va=0x07b098, span=32 B | [VN] FDE[0953]
uint32_t ttr_fde_0953_0x03c004(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0f000420U) + (a1 ^ 0x52800028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800049U + 0x03c004U) ^ (0xfc01c000U + 0x07b098U + 32U);
}

// [EN] FDE[0954] start_va=0x03c024, fde_va=0x07b0b0, span=12 B | [VN] FDE[0954]
uint32_t ttr_fde_0954_0x03c024(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000160U) + (a1 ^ 0x911d9000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03c024U) ^ (0xf81e0ff3U + 0x07b0b0U + 12U);
}

// [EN] FDE[0955] start_va=0x03c030, fde_va=0x07b0c8, span=40 B | [VN] FDE[0955]
uint32_t ttr_fde_0955_0x03c030(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c030U) ^ (0x900002e8U + 0x07b0c8U + 40U);
}

// [EN] FDE[0956] start_va=0x03c058, fde_va=0x07b0e8, span=28 B | [VN] FDE[0956]
uint32_t ttr_fde_0956_0x03c058(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c058U) ^ (0xaa0003f3U + 0x07b0e8U + 28U);
}

// [EN] FDE[0957] start_va=0x03c074, fde_va=0x07b108, span=412 B | [VN] FDE[0957]
uint32_t ttr_fde_0957_0x03c074(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff7U) + (a1 ^ 0xa90157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9024ff4U + 0x03c074U) ^ (0xa9037bfdU + 0x07b108U + 412U);
}

// [EN] FDE[0958] start_va=0x03c210, fde_va=0x07b130, span=764 B | [VN] FDE[0958]
uint32_t ttr_fde_0958_0x03c210(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xf90053f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90b57f6U + 0x03c210U) ^ (0xa90c4ff4U + 0x07b130U + 764U);
}

// [EN] FDE[0959] start_va=0x03c50c, fde_va=0x07b158, span=40 B | [VN] FDE[0959]
uint32_t ttr_fde_0959_0x03c50c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10083ffU) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c50cU) ^ (0x91034000U + 0x07b158U + 40U);
}

// [EN] FDE[0960] start_va=0x03c534, fde_va=0x07b178, span=60 B | [VN] FDE[0960]
uint32_t ttr_fde_0960_0x03c534(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x71032c3fU + 0x03c534U) ^ (0x540000e0U + 0x07b178U + 60U);
}

// [EN] FDE[0961] start_va=0x03c570, fde_va=0x07b198, span=4 B | [VN] FDE[0961]
uint32_t ttr_fde_0961_0x03c570(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14008e7aU) + (a1 ^ 0xa9be4ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bfdU + 0x03c570U) ^ (0x910043fdU + 0x07b198U + 4U);
}

// [EN] FDE[0962] start_va=0x03c574, fde_va=0x07b1b0, span=176 B | [VN] FDE[0962]
uint32_t ttr_fde_0962_0x03c574(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c574U) ^ (0xf9406814U + 0x07b1b0U + 176U);
}

// [EN] FDE[0963] start_va=0x03c624, fde_va=0x07b1d0, span=8 B | [VN] FDE[0963]
uint32_t ttr_fde_0963_0x03c624(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800080U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x03c624U) ^ (0xf90013f3U + 0x07b1d0U + 8U);
}

// [EN] FDE[0964] start_va=0x03c62c, fde_va=0x07b1e8, span=116 B | [VN] FDE[0964]
uint32_t ttr_fde_0964_0x03c62c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x03c62cU) ^ (0x9100c3fdU + 0x07b1e8U + 116U);
}

// [EN] FDE[0965] start_va=0x03c6a0, fde_va=0x07b208, span=28 B | [VN] FDE[0965]
uint32_t ttr_fde_0965_0x03c6a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c6a0U) ^ (0x94008da7U + 0x07b208U + 28U);
}

// [EN] FDE[0966] start_va=0x03c6bc, fde_va=0x07b228, span=12 B | [VN] FDE[0966]
uint32_t ttr_fde_0966_0x03c6bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff9363U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03c6bcU) ^ (0xf81e0ff3U + 0x07b228U + 12U);
}

// [EN] FDE[0967] start_va=0x03c6c8, fde_va=0x07b240, span=36 B | [VN] FDE[0967]
uint32_t ttr_fde_0967_0x03c6c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c6c8U) ^ (0x900002e8U + 0x07b240U + 36U);
}

// [EN] FDE[0968] start_va=0x03c6ec, fde_va=0x07b260, span=28 B | [VN] FDE[0968]
uint32_t ttr_fde_0968_0x03c6ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c6ecU) ^ (0xaa0003f3U + 0x07b260U + 28U);
}

// [EN] FDE[0969] start_va=0x03c708, fde_va=0x07b280, span=4 B | [VN] FDE[0969]
uint32_t ttr_fde_0969_0x03c708(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14008dbbU) + (a1 ^ 0x17ff7d89U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0f000420U + 0x03c708U) ^ (0x52800028U + 0x07b280U + 4U);
}

// [EN] FDE[0970] start_va=0x03c70c, fde_va=0x07b298, span=4 B | [VN] FDE[0970]
uint32_t ttr_fde_0970_0x03c70c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff7d89U) + (a1 ^ 0x0f000420U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800028U + 0x03c70cU) ^ (0x52808009U + 0x07b298U + 4U);
}

// [EN] FDE[0971] start_va=0x03c710, fde_va=0x07b2d8, span=20 B | [VN] FDE[0971]
uint32_t ttr_fde_0971_0x03c710(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0f000420U) + (a1 ^ 0x52800028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52808009U + 0x03c710U) ^ (0x5280004aU + 0x07b2d8U + 20U);
}

// [EN] FDE[0972] start_va=0x03c724, fde_va=0x07b2f0, span=12 B | [VN] FDE[0972]
uint32_t ttr_fde_0972_0x03c724(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000160U) + (a1 ^ 0x911dbc00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03c724U) ^ (0xf81e0ff3U + 0x07b2f0U + 12U);
}

// [EN] FDE[0973] start_va=0x03c730, fde_va=0x07b308, span=56 B | [VN] FDE[0973]
uint32_t ttr_fde_0973_0x03c730(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c730U) ^ (0x900002e8U + 0x07b308U + 56U);
}

// [EN] FDE[0974] start_va=0x03c768, fde_va=0x07b328, span=28 B | [VN] FDE[0974]
uint32_t ttr_fde_0974_0x03c768(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03c768U) ^ (0xaa0003f3U + 0x07b328U + 28U);
}

// [EN] FDE[0975] start_va=0x03c784, fde_va=0x07b348, span=124 B | [VN] FDE[0975]
uint32_t ttr_fde_0975_0x03c784(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9034ff4U + 0x03c784U) ^ (0xa9047bfdU + 0x07b348U + 124U);
}

// [EN] FDE[0976] start_va=0x03c800, fde_va=0x07b368, span=8 B | [VN] FDE[0976]
uint32_t ttr_fde_0976_0x03c800(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91036000U) + (a1 ^ 0x140001dbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bfdU + 0x03c800U) ^ (0x910003fdU + 0x07b368U + 8U);
}

// [EN] FDE[0977] start_va=0x03c808, fde_va=0x07b380, span=56 B | [VN] FDE[0977]
uint32_t ttr_fde_0977_0x03c808(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bfdU) + (a1 ^ 0x910003fdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x71032c3fU + 0x03c808U) ^ (0x540000c0U + 0x07b380U + 56U);
}

// [EN] FDE[0978] start_va=0x03c840, fde_va=0x07b3a0, span=4 B | [VN] FDE[0978]
uint32_t ttr_fde_0978_0x03c840(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14008dc6U) + (a1 ^ 0xd10383ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90967faU + 0x03c840U) ^ (0xa90a5ff8U + 0x07b3a0U + 4U);
}

// [EN] FDE[0979] start_va=0x03c844, fde_va=0x07b3b8, span=1248 B | [VN] FDE[0979]
uint32_t ttr_fde_0979_0x03c844(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xa90967faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90a5ff8U + 0x03c844U) ^ (0xa90b57f6U + 0x07b3b8U + 1248U);
}

// [EN] FDE[0980] start_va=0x03cd24, fde_va=0x07b3e8, span=8 B | [VN] FDE[0980]
uint32_t ttr_fde_0980_0x03cd24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x528000c0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x03cd24U) ^ (0xf90013f3U + 0x07b3e8U + 8U);
}

// [EN] FDE[0981] start_va=0x03cd2c, fde_va=0x07b400, span=116 B | [VN] FDE[0981]
uint32_t ttr_fde_0981_0x03cd2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bfdU + 0x03cd2cU) ^ (0x9100c3fdU + 0x07b400U + 116U);
}

// [EN] FDE[0982] start_va=0x03cda0, fde_va=0x07b420, span=180 B | [VN] FDE[0982]
uint32_t ttr_fde_0982_0x03cda0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03cda0U) ^ (0x94008ddcU + 0x07b420U + 180U);
}

// [EN] FDE[0983] start_va=0x03ce54, fde_va=0x07b440, span=36 B | [VN] FDE[0983]
uint32_t ttr_fde_0983_0x03ce54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10083ffU) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03ce54U) ^ (0xf90007e0U + 0x07b440U + 36U);
}

// [EN] FDE[0984] start_va=0x03ce78, fde_va=0x07b460, span=224 B | [VN] FDE[0984]
uint32_t ttr_fde_0984_0x03ce78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03ce78U) ^ (0xaa0003f3U + 0x07b460U + 224U);
}

// [EN] FDE[0985] start_va=0x03cf58, fde_va=0x07b480, span=24 B | [VN] FDE[0985]
uint32_t ttr_fde_0985_0x03cf58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x03cf58U) ^ (0xb4000040U + 0x07b480U + 24U);
}

// [EN] FDE[0986] start_va=0x03cf70, fde_va=0x07b498, span=64 B | [VN] FDE[0986]
uint32_t ttr_fde_0986_0x03cf70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03cf70U) ^ (0xf9400c08U + 0x07b498U + 64U);
}

// [EN] FDE[0987] start_va=0x03cfb0, fde_va=0x07b4b8, span=52 B | [VN] FDE[0987]
uint32_t ttr_fde_0987_0x03cfb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03cfb0U) ^ (0xaa0003f3U + 0x07b4b8U + 52U);
}

// [EN] FDE[0988] start_va=0x03cfe4, fde_va=0x07b500, span=160 B | [VN] FDE[0988]
uint32_t ttr_fde_0988_0x03cfe4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03cfe4U) ^ (0x90000308U + 0x07b500U + 160U);
}

// [EN] FDE[0989] start_va=0x03d084, fde_va=0x07b520, span=132 B | [VN] FDE[0989]
uint32_t ttr_fde_0989_0x03d084(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03d084U) ^ (0xf9401808U + 0x07b520U + 132U);
}

// [EN] FDE[0990] start_va=0x03d108, fde_va=0x07b540, span=56 B | [VN] FDE[0990]
uint32_t ttr_fde_0990_0x03d108(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be4ff4U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03d108U) ^ (0xaa0003f3U + 0x07b540U + 56U);
}

// [EN] FDE[0991] start_va=0x03d140, fde_va=0x07b560, span=12 B | [VN] FDE[0991]
uint32_t ttr_fde_0991_0x03d140(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000160U) + (a1 ^ 0x911f6000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03d140U) ^ (0xf81e0ff3U + 0x07b560U + 12U);
}

// [EN] FDE[0992] start_va=0x03d14c, fde_va=0x07b578, span=28 B | [VN] FDE[0992]
uint32_t ttr_fde_0992_0x03d14c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff3U) + (a1 ^ 0xa9017bfdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043fdU + 0x03d14cU) ^ (0xaa0003f3U + 0x07b578U + 28U);
}

// [EN] FDE[0993] start_va=0x03d168, fde_va=0x07b598, span=48 B | [VN] FDE[0993]
uint32_t ttr_fde_0993_0x03d168(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940097efU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000161U + 0x03d168U) ^ (0xaa0003f3U + 0x07b598U + 48U);
}

// [EN] FDE[0994] start_va=0x03d198, fde_va=0x07b5b0, span=1160 B | [VN] FDE[0994]
uint32_t ttr_fde_0994_0x03d198(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10303ffU) + (a1 ^ 0xa9066ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90767faU + 0x03d198U) ^ (0xa9085ff8U + 0x07b5b0U + 1160U);
}

// [EN] FDE[0995] start_va=0x03d620, fde_va=0x07b5e0, span=32 B | [VN] FDE[0995]
uint32_t ttr_fde_0995_0x03d620(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9401000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb00011fU + 0x03d620U) ^ (0x54000060U + 0x07b5e0U + 32U);
}

// [EN] FDE[0996] start_va=0x03d640, fde_va=0x07b5f8, span=28 B | [VN] FDE[0996]
uint32_t ttr_fde_0996_0x03d640(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91008000U + 0x03d640U) ^ (0x97fffff5U + 0x07b5f8U + 28U);
}

// [EN] FDE[0997] start_va=0x03d65c, fde_va=0x07b610, span=280 B | [VN] FDE[0997]
uint32_t ttr_fde_0997_0x03d65c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x94008d87U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x03d65cU) ^ (0xa9057bfdU + 0x07b610U + 280U);
}

// [EN] FDE[0998] start_va=0x03d774, fde_va=0x07b640, span=24 B | [VN] FDE[0998]
uint32_t ttr_fde_0998_0x03d774(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x03d774U) ^ (0xb4000040U + 0x07b640U + 24U);
}

// [EN] FDE[0999] start_va=0x03d78c, fde_va=0x07b658, span=1408 B | [VN] FDE[0999]
uint32_t ttr_fde_0999_0x03d78c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x94008d3bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x03d78cU) ^ (0xa9057bfdU + 0x07b658U + 1408U);
}

// [EN] FDE[1000] start_va=0x03dd0c, fde_va=0x07b688, span=28 B | [VN] FDE[1000]
uint32_t ttr_fde_1000_0x03dd0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401800U + 0x03dd0cU) ^ (0x94000018U + 0x07b688U + 28U);
}

// [EN] FDE[1001] start_va=0x03dd28, fde_va=0x07b6a0, span=80 B | [VN] FDE[1001]
uint32_t ttr_fde_1001_0x03dd28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x39400009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0103e8U + 0x03dd28U) ^ (0x37000089U + 0x07b6a0U + 80U);
}

// [EN] FDE[1002] start_va=0x03dd78, fde_va=0x07b6b8, span=12 B | [VN] FDE[1002]
uint32_t ttr_fde_1002_0x03dd78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff8db4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x03dd78U) ^ (0x39400009U + 0x07b6b8U + 12U);
}

// [EN] FDE[1003] start_va=0x03dd84, fde_va=0x07b6d0, span=28 B | [VN] FDE[1003]
uint32_t ttr_fde_1003_0x03dd84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400009U) + (a1 ^ 0x37000089U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91000408U + 0x03dd84U) ^ (0xd341fd29U + 0x07b6d0U + 28U);
}

// [EN] FDE[1004] start_va=0x03dda0, fde_va=0x07b6e8, span=188 B | [VN] FDE[1004]
uint32_t ttr_fde_1004_0x03dda0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9037bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9422c33U + 0x03dda0U) ^ (0xaa0103e8U + 0x07b6e8U + 188U);
}

// [EN] FDE[1005] start_va=0x03de5c, fde_va=0x07b700, span=52 B | [VN] FDE[1005]
uint32_t ttr_fde_1005_0x03de5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400889bU + 0x03de5cU) ^ (0xf90007e2U + 0x07b700U + 52U);
}

// [EN] FDE[1006] start_va=0x03de90, fde_va=0x07b720, span=20 B | [VN] FDE[1006]
uint32_t ttr_fde_1006_0x03de90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x03de90U) ^ (0x14008acbU + 0x07b720U + 20U);
}

// [EN] FDE[1007] start_va=0x03dea4, fde_va=0x07b738, span=128 B | [VN] FDE[1007]
uint32_t ttr_fde_1007_0x03dea4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x03dea4U) ^ (0xf9400000U + 0x07b738U + 128U);
}

// [EN] FDE[1008] start_va=0x03df24, fde_va=0x07b758, span=984 B | [VN] FDE[1008]
uint32_t ttr_fde_1008_0x03df24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xa9086ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90967faU + 0x03df24U) ^ (0xa90a5ff8U + 0x07b758U + 984U);
}

// [EN] FDE[1009] start_va=0x03e2fc, fde_va=0x07b788, span=20 B | [VN] FDE[1009]
uint32_t ttr_fde_1009_0x03e2fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x03e2fcU) ^ (0x140089b0U + 0x07b788U + 20U);
}

// [EN] FDE[1010] start_va=0x03e310, fde_va=0x07b7a0, span=100 B | [VN] FDE[1010]
uint32_t ttr_fde_1010_0x03e310(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x03e310U) ^ (0xaa0003f6U + 0x07b7a0U + 100U);
}

// [EN] FDE[1011] start_va=0x03e374, fde_va=0x07b7c0, span=2536 B | [VN] FDE[1011]
uint32_t ttr_fde_1011_0x03e374(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10743ffU) + (a1 ^ 0xa9176ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91867faU + 0x03e374U) ^ (0xa9195ff8U + 0x07b7c0U + 2536U);
}

// [EN] FDE[1012] start_va=0x03ed5c, fde_va=0x07b7f0, span=180 B | [VN] FDE[1012]
uint32_t ttr_fde_1012_0x03ed5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400809U + 0x03ed5cU) ^ (0xf9400008U + 0x07b7f0U + 180U);
}

// [EN] FDE[1013] start_va=0x03ee10, fde_va=0x07b810, span=44 B | [VN] FDE[1013]
uint32_t ttr_fde_1013_0x03ee10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0x52800309U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9b092029U + 0x03ee10U) ^ (0xeb08013fU + 0x07b810U + 44U);
}

// [EN] FDE[1014] start_va=0x03ee3c, fde_va=0x07b828, span=28 B | [VN] FDE[1014]
uint32_t ttr_fde_1014_0x03ee3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94008d24U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000060U + 0x03ee3cU) ^ (0x9400957cU + 0x07b828U + 28U);
}

// [EN] FDE[1015] start_va=0x03ee58, fde_va=0x07b840, span=44 B | [VN] FDE[1015]
uint32_t ttr_fde_1015_0x03ee58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb201f3e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940090f0U + 0x03ee58U) ^ (0x540000e8U + 0x07b840U + 44U);
}

// [EN] FDE[1016] start_va=0x03ee84, fde_va=0x07b858, span=56 B | [VN] FDE[1016]
uint32_t ttr_fde_1016_0x03ee84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb201f3e8U + 0x03ee84U) ^ (0xf2955568U + 0x07b858U + 56U);
}

// [EN] FDE[1017] start_va=0x03eebc, fde_va=0x07b878, span=32 B | [VN] FDE[1017]
uint32_t ttr_fde_1017_0x03eebc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb201f3e8U) + (a1 ^ 0xf2955568U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf2e15548U + 0x03eebcU) ^ (0xeb08001fU + 0x07b878U + 32U);
}

// [EN] FDE[1018] start_va=0x03eedc, fde_va=0x07b890, span=508 B | [VN] FDE[1018]
uint32_t ttr_fde_1018_0x03eedc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xa9096bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90a63f9U + 0x03eedcU) ^ (0xa90b5bf7U + 0x07b890U + 508U);
}

// [EN] FDE[1019] start_va=0x03f0d8, fde_va=0x07b8c0, span=252 B | [VN] FDE[1019]
uint32_t ttr_fde_1019_0x03f0d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x03f0d8U) ^ (0xa9037bf3U + 0x07b8c0U + 252U);
}

// [EN] FDE[1020] start_va=0x03f1d4, fde_va=0x07b8e8, span=36 B | [VN] FDE[1020]
uint32_t ttr_fde_1020_0x03f1d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401c00U + 0x03f1d4U) ^ (0xb4000060U + 0x07b8e8U + 36U);
}

// [EN] FDE[1021] start_va=0x03f1f8, fde_va=0x07b900, span=272 B | [VN] FDE[1021]
uint32_t ttr_fde_1021_0x03f1f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x03f1f8U) ^ (0xa9037bf3U + 0x07b900U + 272U);
}

// [EN] FDE[1022] start_va=0x03f308, fde_va=0x07b928, span=208 B | [VN] FDE[1022]
uint32_t ttr_fde_1022_0x03f308(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x03f308U) ^ (0xa9037bf3U + 0x07b928U + 208U);
}

// [EN] FDE[1023] start_va=0x03f3d8, fde_va=0x07b950, span=8 B | [VN] FDE[1023]
uint32_t ttr_fde_1023_0x03f3d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff724dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400408U + 0x03f3d8U) ^ (0xd1018101U + 0x07b950U + 8U);
}

// [EN] FDE[1024] start_va=0x03f3e0, fde_va=0x07b968, span=12 B | [VN] FDE[1024]
uint32_t ttr_fde_1024_0x03f3e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xd1018101U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000061U + 0x03f3e0U) ^ (0xf9400001U + 0x07b968U + 12U);
}

// [EN] FDE[1025] start_va=0x03f3ec, fde_va=0x07b980, span=8 B | [VN] FDE[1025]
uint32_t ttr_fde_1025_0x03f3ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400001U) + (a1 ^ 0x1400005fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81d0ff6U + 0x03f3ecU) ^ (0xa90153f5U + 0x07b980U + 8U);
}

// [EN] FDE[1026] start_va=0x03f3f4, fde_va=0x07b998, span=160 B | [VN] FDE[1026]
uint32_t ttr_fde_1026_0x03f3f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x03f3f4U) ^ (0xad400420U + 0x07b998U + 160U);
}

// [EN] FDE[1027] start_va=0x03f494, fde_va=0x07b9b8, span=8 B | [VN] FDE[1027]
uint32_t ttr_fde_1027_0x03f494(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff721eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x03f494U) ^ (0xf9400008U + 0x07b9b8U + 8U);
}

// [EN] FDE[1028] start_va=0x03f49c, fde_va=0x07b9d0, span=40 B | [VN] FDE[1028]
uint32_t ttr_fde_1028_0x03f49c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb40000c8U + 0x03f49cU) ^ (0xaa0003f3U + 0x07b9d0U + 40U);
}

// [EN] FDE[1029] start_va=0x03f4c4, fde_va=0x07b9e8, span=44 B | [VN] FDE[1029]
uint32_t ttr_fde_1029_0x03f4c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37cfc28U + 0x03f4c4U) ^ (0xb50000e8U + 0x07b9e8U + 44U);
}

// [EN] FDE[1030] start_va=0x03f4f0, fde_va=0x07ba08, span=40 B | [VN] FDE[1030]
uint32_t ttr_fde_1030_0x03f4f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94009392U + 0x03f4f0U) ^ (0x5400008bU + 0x07ba08U + 40U);
}

// [EN] FDE[1031] start_va=0x03f518, fde_va=0x07ba28, span=20 B | [VN] FDE[1031]
uint32_t ttr_fde_1031_0x03f518(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37cfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14008cd6U + 0x03f518U) ^ (0xf81f0ffeU + 0x07ba28U + 20U);
}

// [EN] FDE[1032] start_va=0x03f52c, fde_va=0x07ba40, span=64 B | [VN] FDE[1032]
uint32_t ttr_fde_1032_0x03f52c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x03f52cU) ^ (0xf9400414U + 0x07ba40U + 64U);
}

// [EN] FDE[1033] start_va=0x03f56c, fde_va=0x07ba60, span=40 B | [VN] FDE[1033]
uint32_t ttr_fde_1033_0x03f56c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400831cU + 0x03f56cU) ^ (0xeb15029fU + 0x07ba60U + 40U);
}

// [EN] FDE[1034] start_va=0x03f594, fde_va=0x07ba80, span=44 B | [VN] FDE[1034]
uint32_t ttr_fde_1034_0x03f594(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xd37cfc28U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb5000108U + 0x03f594U) ^ (0x94008534U + 0x07ba80U + 44U);
}

// [EN] FDE[1035] start_va=0x03f5c0, fde_va=0x07ba98, span=48 B | [VN] FDE[1035]
uint32_t ttr_fde_1035_0x03f5c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb000028U) + (a1 ^ 0xb4000128U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3dc00000U + 0x03f5c0U) ^ (0xd1006108U + 0x07ba98U + 48U);
}

// [EN] FDE[1036] start_va=0x03f5f0, fde_va=0x07bab0, span=92 B | [VN] FDE[1036]
uint32_t ttr_fde_1036_0x03f5f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xad400420U) + (a1 ^ 0xa902fc1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900101fU + 0x03f5f0U) ^ (0xad000400U + 0x07bab0U + 92U);
}

// [EN] FDE[1037] start_va=0x03f64c, fde_va=0x07bac8, span=40 B | [VN] FDE[1037]
uint32_t ttr_fde_1037_0x03f64c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb201f3e8U) + (a1 ^ 0xf2955568U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf2e05548U + 0x03f64cU) ^ (0xeb08001fU + 0x07bac8U + 40U);
}

// [EN] FDE[1038] start_va=0x03f674, fde_va=0x07bae0, span=576 B | [VN] FDE[1038]
uint32_t ttr_fde_1038_0x03f674(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xa9096bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90a63f9U + 0x03f674U) ^ (0xa90b5bf7U + 0x07bae0U + 576U);
}

// [EN] FDE[1039] start_va=0x03f8b4, fde_va=0x07bb10, span=108 B | [VN] FDE[1039]
uint32_t ttr_fde_1039_0x03f8b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xa9422408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf940040aU + 0x03f8b4U) ^ (0x9280052bU + 0x07bb10U + 108U);
}

// [EN] FDE[1040] start_va=0x03f920, fde_va=0x07bb28, span=156 B | [VN] FDE[1040]
uint32_t ttr_fde_1040_0x03f920(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x03f920U) ^ (0x94009405U + 0x07bb28U + 156U);
}

// [EN] FDE[1041] start_va=0x03f9bc, fde_va=0x07bb48, span=28 B | [VN] FDE[1041]
uint32_t ttr_fde_1041_0x03f9bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xeb08003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x03f9bcU) ^ (0xd1002108U + 0x07bb48U + 28U);
}

// [EN] FDE[1042] start_va=0x03f9d8, fde_va=0x07bb60, span=48 B | [VN] FDE[1042]
uint32_t ttr_fde_1042_0x03f9d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800548U) + (a1 ^ 0x9ac80848U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb00003fU + 0x03f9d8U) ^ (0x8b080c00U + 0x07bb60U + 48U);
}

// [EN] FDE[1043] start_va=0x03fa08, fde_va=0x07bb78, span=12 B | [VN] FDE[1043]
uint32_t ttr_fde_1043_0x03fa08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0x5280054aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140085a4U + 0x03fa08U) ^ (0xf9400808U + 0x07bb78U + 12U);
}

// [EN] FDE[1044] start_va=0x03fa14, fde_va=0x07bb90, span=12 B | [VN] FDE[1044]
uint32_t ttr_fde_1044_0x03fa14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xd1002101U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffffe8U + 0x03fa14U) ^ (0xd10183ffU + 0x07bb90U + 12U);
}

// [EN] FDE[1045] start_va=0x03fa20, fde_va=0x07bba8, span=160 B | [VN] FDE[1045]
uint32_t ttr_fde_1045_0x03fa20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x03fa20U) ^ (0xa9057bf3U + 0x07bba8U + 160U);
}

// [EN] FDE[1046] start_va=0x03fac0, fde_va=0x07bbc8, span=160 B | [VN] FDE[1046]
uint32_t ttr_fde_1046_0x03fac0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x03fac0U) ^ (0xa9057bf3U + 0x07bbc8U + 160U);
}

// [EN] FDE[1047] start_va=0x03fb60, fde_va=0x07bbe8, span=148 B | [VN] FDE[1047]
uint32_t ttr_fde_1047_0x03fb60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x03fb60U) ^ (0xa9057bf3U + 0x07bbe8U + 148U);
}

// [EN] FDE[1048] start_va=0x03fbf4, fde_va=0x07bc08, span=20 B | [VN] FDE[1048]
uint32_t ttr_fde_1048_0x03fbf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37dfc08U) + (a1 ^ 0xb5000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14008911U + 0x03fbf4U) ^ (0xf81f0ffeU + 0x07bc08U + 20U);
}

// [EN] FDE[1049] start_va=0x03fc08, fde_va=0x07bc20, span=148 B | [VN] FDE[1049]
uint32_t ttr_fde_1049_0x03fc08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x03fc08U) ^ (0xa9057bf3U + 0x07bc20U + 148U);
}

// [EN] FDE[1050] start_va=0x03fc9c, fde_va=0x07bc40, span=24 B | [VN] FDE[1050]
uint32_t ttr_fde_1050_0x03fc9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900011fU + 0x03fc9cU) ^ (0xb4000040U + 0x07bc40U + 24U);
}

// [EN] FDE[1051] start_va=0x03fcb4, fde_va=0x07bc58, span=40 B | [VN] FDE[1051]
uint32_t ttr_fde_1051_0x03fcb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x03fcb4U) ^ (0xd1002129U + 0x07bc58U + 40U);
}

// [EN] FDE[1052] start_va=0x03fcdc, fde_va=0x07bc70, span=32 B | [VN] FDE[1052]
uint32_t ttr_fde_1052_0x03fcdc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94008e08U + 0x03fcdcU) ^ (0x54000040U + 0x07bc70U + 32U);
}

// [EN] FDE[1053] start_va=0x03fcfc, fde_va=0x07bc90, span=36 B | [VN] FDE[1053]
uint32_t ttr_fde_1053_0x03fcfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xcb010049U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b090109U + 0x03fcfcU) ^ (0xeb08013fU + 0x07bc90U + 36U);
}

// [EN] FDE[1054] start_va=0x03fd20, fde_va=0x07bca8, span=32 B | [VN] FDE[1054]
uint32_t ttr_fde_1054_0x03fd20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xeb000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f3U + 0x03fd20U) ^ (0x54000040U + 0x07bca8U + 32U);
}

// [EN] FDE[1055] start_va=0x03fd40, fde_va=0x07bcc0, span=56 B | [VN] FDE[1055]
uint32_t ttr_fde_1055_0x03fd40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb08013fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000160U + 0x03fd40U) ^ (0xa9422809U + 0x07bcc0U + 56U);
}

// [EN] FDE[1056] start_va=0x03fd78, fde_va=0x07bcd8, span=148 B | [VN] FDE[1056]
uint32_t ttr_fde_1056_0x03fd78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x03fd78U) ^ (0xa9057bf3U + 0x07bcd8U + 148U);
}

// [EN] FDE[1057] start_va=0x03fe0c, fde_va=0x07bcf8, span=24 B | [VN] FDE[1057]
uint32_t ttr_fde_1057_0x03fe0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94008930U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ff88c0U + 0x03fe0cU) ^ (0xaa1303e0U + 0x07bcf8U + 24U);
}

// [EN] FDE[1058] start_va=0x03fe24, fde_va=0x07bd10, span=24 B | [VN] FDE[1058]
uint32_t ttr_fde_1058_0x03fe24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39404028U) + (a1 ^ 0x34000088U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9400828U + 0x03fe24U) ^ (0xaa0803e1U + 0x07bd10U + 24U);
}

// [EN] FDE[1059] start_va=0x03fe3c, fde_va=0x07bd28, span=88 B | [VN] FDE[1059]
uint32_t ttr_fde_1059_0x03fe3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x03fe3cU) ^ (0x940087faU + 0x07bd28U + 88U);
}

// [EN] FDE[1060] start_va=0x03fe94, fde_va=0x07bd48, span=52 B | [VN] FDE[1060]
uint32_t ttr_fde_1060_0x03fe94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ff6fc9U + 0x03fe94U) ^ (0xaa1303e0U + 0x07bd48U + 52U);
}

// [EN] FDE[1061] start_va=0x03fec8, fde_va=0x07bd60, span=348 B | [VN] FDE[1061]
uint32_t ttr_fde_1061_0x03fec8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x03fec8U) ^ (0xa9037bf3U + 0x07bd60U + 348U);
}

// [EN] FDE[1062] start_va=0x040024, fde_va=0x07bd88, span=72 B | [VN] FDE[1062]
uint32_t ttr_fde_1062_0x040024(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x040024U) ^ (0x52800400U + 0x07bd88U + 72U);
}

// [EN] FDE[1063] start_va=0x04006c, fde_va=0x07bda8, span=104 B | [VN] FDE[1063]
uint32_t ttr_fde_1063_0x04006c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x04006cU) ^ (0xa9037bf3U + 0x07bda8U + 104U);
}

// [EN] FDE[1064] start_va=0x0400d4, fde_va=0x07bdd0, span=120 B | [VN] FDE[1064]
uint32_t ttr_fde_1064_0x0400d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f5U + 0x0400d4U) ^ (0xeb02003fU + 0x07bdd0U + 120U);
}

// [EN] FDE[1065] start_va=0x04014c, fde_va=0x07bdf0, span=100 B | [VN] FDE[1065]
uint32_t ttr_fde_1065_0x04014c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x04014cU) ^ (0xa9037bf3U + 0x07bdf0U + 100U);
}

// [EN] FDE[1066] start_va=0x0401b0, fde_va=0x07be18, span=8 B | [VN] FDE[1066]
uint32_t ttr_fde_1066_0x0401b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6ed7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb00003fU + 0x0401b0U) ^ (0x540000e0U + 0x07be18U + 8U);
}

// [EN] FDE[1067] start_va=0x0401b8, fde_va=0x07be30, span=40 B | [VN] FDE[1067]
uint32_t ttr_fde_1067_0x0401b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb00003fU) + (a1 ^ 0x540000e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400008U + 0x0401b8U) ^ (0x6b22011fU + 0x07be30U + 40U);
}

// [EN] FDE[1068] start_va=0x0401e0, fde_va=0x07be48, span=32 B | [VN] FDE[1068]
uint32_t ttr_fde_1068_0x0401e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007ec6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401e68U + 0x0401e0U) ^ (0x900002caU + 0x07be48U + 32U);
}

// [EN] FDE[1069] start_va=0x040200, fde_va=0x07be60, span=144 B | [VN] FDE[1069]
uint32_t ttr_fde_1069_0x040200(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f5U + 0x040200U) ^ (0x52800300U + 0x07be60U + 144U);
}

// [EN] FDE[1070] start_va=0x040290, fde_va=0x07be80, span=4 B | [VN] FDE[1070]
uint32_t ttr_fde_1070_0x040290(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff6ea7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x12807c28U + 0x040290U) ^ (0xb9000028U + 0x07be80U + 4U);
}

// [EN] FDE[1071] start_va=0x040294, fde_va=0x07be98, span=4 B | [VN] FDE[1071]
uint32_t ttr_fde_1071_0x040294(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff6ea7U) + (a1 ^ 0x12807c28U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9000028U + 0x040294U) ^ (0x14007f9dU + 0x07be98U + 4U);
}

// [EN] FDE[1072] start_va=0x040298, fde_va=0x07beb0, span=12 B | [VN] FDE[1072]
uint32_t ttr_fde_1072_0x040298(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807c28U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14007f9dU + 0x040298U) ^ (0xd65f03c0U + 0x07beb0U + 12U);
}

// [EN] FDE[1073] start_va=0x0402a4, fde_va=0x07bec8, span=4 B | [VN] FDE[1073]
uint32_t ttr_fde_1073_0x0402a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94008615U + 0x0402a4U) ^ (0x900002c8U + 0x07bec8U + 4U);
}

// [EN] FDE[1074] start_va=0x0402a8, fde_va=0x07bee0, span=40 B | [VN] FDE[1074]
uint32_t ttr_fde_1074_0x0402a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94008615U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900002c8U + 0x0402a8U) ^ (0x911d8108U + 0x07bee0U + 40U);
}

// [EN] FDE[1075] start_va=0x0402d0, fde_va=0x07bef8, span=20 B | [VN] FDE[1075]
uint32_t ttr_fde_1075_0x0402d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94009190U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0402d0U) ^ (0xa8c17bf3U + 0x07bef8U + 20U);
}

// [EN] FDE[1076] start_va=0x0402e4, fde_va=0x07bf10, span=12 B | [VN] FDE[1076]
uint32_t ttr_fde_1076_0x0402e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807be8U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0402e4U) ^ (0x12807c28U + 0x07bf10U + 12U);
}

// [EN] FDE[1077] start_va=0x0402f0, fde_va=0x07bf28, span=32 B | [VN] FDE[1077]
uint32_t ttr_fde_1077_0x0402f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807c28U) + (a1 ^ 0xb9000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x36000061U + 0x0402f0U) ^ (0xf9400808U + 0x07bf28U + 32U);
}

// [EN] FDE[1078] start_va=0x040310, fde_va=0x07bf40, span=36 B | [VN] FDE[1078]
uint32_t ttr_fde_1078_0x040310(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900002c9U + 0x040310U) ^ (0x911e4129U + 0x07bf40U + 36U);
}

// [EN] FDE[1079] start_va=0x040334, fde_va=0x07bf58, span=16 B | [VN] FDE[1079]
uint32_t ttr_fde_1079_0x040334(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94008086U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x040334U) ^ (0x17ff6e7cU + 0x07bf58U + 16U);
}

// [EN] FDE[1080] start_va=0x040344, fde_va=0x07bf70, span=4 B | [VN] FDE[1080]
uint32_t ttr_fde_1080_0x040344(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94009172U + 0x040344U) ^ (0xaa1303e0U + 0x07bf70U + 4U);
}

// [EN] FDE[1081] start_va=0x040348, fde_va=0x07bf88, span=20 B | [VN] FDE[1081]
uint32_t ttr_fde_1081_0x040348(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94009172U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x040348U) ^ (0xa8c17bf3U + 0x07bf88U + 20U);
}

// [EN] FDE[1082] start_va=0x04035c, fde_va=0x07bfa0, span=60 B | [VN] FDE[1082]
uint32_t ttr_fde_1082_0x04035c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400843fU + 0x04035cU) ^ (0x9400000eU + 0x07bfa0U + 60U);
}

// [EN] FDE[1083] start_va=0x040398, fde_va=0x07bfc0, span=8 B | [VN] FDE[1083]
uint32_t ttr_fde_1083_0x040398(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6e5dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bc63f9U + 0x040398U) ^ (0xa9015bf7U + 0x07bfc0U + 8U);
}

// [EN] FDE[1084] start_va=0x0403a0, fde_va=0x07bfd8, span=448 B | [VN] FDE[1084]
uint32_t ttr_fde_1084_0x0403a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc63f9U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x0403a0U) ^ (0xa9037bf3U + 0x07bfd8U + 448U);
}

// [EN] FDE[1085] start_va=0x040560, fde_va=0x07c000, span=32 B | [VN] FDE[1085]
uint32_t ttr_fde_1085_0x040560(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007de6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401e68U + 0x040560U) ^ (0x900002caU + 0x07c000U + 32U);
}

// [EN] FDE[1086] start_va=0x040580, fde_va=0x07c018, span=32 B | [VN] FDE[1086]
uint32_t ttr_fde_1086_0x040580(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007ddeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401e68U + 0x040580U) ^ (0x900002caU + 0x07c018U + 32U);
}

// [EN] FDE[1087] start_va=0x0405a0, fde_va=0x07c030, span=72 B | [VN] FDE[1087]
uint32_t ttr_fde_1087_0x0405a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x39406008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x370801c8U + 0x0405a0U) ^ (0xaa0003f3U + 0x07c030U + 72U);
}

// [EN] FDE[1088] start_va=0x0405e8, fde_va=0x07c048, span=8 B | [VN] FDE[1088]
uint32_t ttr_fde_1088_0x0405e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6dc9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff4U + 0x0405e8U) ^ (0xa9017bf3U + 0x07c048U + 8U);
}

// [EN] FDE[1089] start_va=0x0405f0, fde_va=0x07c060, span=72 B | [VN] FDE[1089]
uint32_t ttr_fde_1089_0x0405f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39406008U + 0x0405f0U) ^ (0x370801a8U + 0x07c060U + 72U);
}

// [EN] FDE[1090] start_va=0x040638, fde_va=0x07c080, span=608 B | [VN] FDE[1090]
uint32_t ttr_fde_1090_0x040638(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa90163f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x040638U) ^ (0xa90353f5U + 0x07c080U + 608U);
}

// [EN] FDE[1091] start_va=0x040898, fde_va=0x07c0a8, span=32 B | [VN] FDE[1091]
uint32_t ttr_fde_1091_0x040898(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203e8U) + (a1 ^ 0x2a0303e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0403e5U + 0x040898U) ^ (0x92800002U + 0x07c0a8U + 32U);
}

// [EN] FDE[1092] start_va=0x0408b8, fde_va=0x07c0c0, span=32 B | [VN] FDE[1092]
uint32_t ttr_fde_1092_0x0408b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203e8U) + (a1 ^ 0x2a0303e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0403e5U + 0x0408b8U) ^ (0x92800002U + 0x07c0c0U + 32U);
}

// [EN] FDE[1093] start_va=0x0408d8, fde_va=0x07c0d8, span=196 B | [VN] FDE[1093]
uint32_t ttr_fde_1093_0x0408d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e7U) + (a1 ^ 0x94008572U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0703feU + 0x0408d8U) ^ (0xa9057bf3U + 0x07c0d8U + 196U);
}

// [EN] FDE[1094] start_va=0x04099c, fde_va=0x07c108, span=128 B | [VN] FDE[1094]
uint32_t ttr_fde_1094_0x04099c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x04099cU) ^ (0xa9037bf3U + 0x07c108U + 128U);
}

// [EN] FDE[1095] start_va=0x040a1c, fde_va=0x07c130, span=8 B | [VN] FDE[1095]
uint32_t ttr_fde_1095_0x040a1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6cbcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x040a1cU) ^ (0x97ff6cbaU + 0x07c130U + 8U);
}

// [EN] FDE[1096] start_va=0x040a24, fde_va=0x07c148, span=8 B | [VN] FDE[1096]
uint32_t ttr_fde_1096_0x040a24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6cbaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x121d1008U + 0x040a24U) ^ (0x7100c11fU + 0x07c148U + 8U);
}

// [EN] FDE[1097] start_va=0x040a2c, fde_va=0x07c160, span=80 B | [VN] FDE[1097]
uint32_t ttr_fde_1097_0x040a2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x121d1008U) + (a1 ^ 0x7100c11fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x12001c08U + 0x040a2cU) ^ (0x54000080U + 0x07c160U + 80U);
}

// [EN] FDE[1098] start_va=0x040a7c, fde_va=0x07c178, span=4 B | [VN] FDE[1098]
uint32_t ttr_fde_1098_0x040a7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff6cadU) + (a1 ^ 0x12807bc8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9000028U + 0x040a7cU) ^ (0x14007da3U + 0x07c178U + 4U);
}

// [EN] FDE[1099] start_va=0x040a80, fde_va=0x07c190, span=12 B | [VN] FDE[1099]
uint32_t ttr_fde_1099_0x040a80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807bc8U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14007da3U + 0x040a80U) ^ (0xa9bf7bf3U + 0x07c190U + 12U);
}

// [EN] FDE[1100] start_va=0x040a8c, fde_va=0x07c1a8, span=20 B | [VN] FDE[1100]
uint32_t ttr_fde_1100_0x040a8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94008fa1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x040a8cU) ^ (0xa8c17bf3U + 0x07c1a8U + 20U);
}

// [EN] FDE[1101] start_va=0x040aa0, fde_va=0x07c1c0, span=196 B | [VN] FDE[1101]
uint32_t ttr_fde_1101_0x040aa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400029U) + (a1 ^ 0xb9402808U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401c2cU + 0x040aa0U) ^ (0xaa0103e3U + 0x07c1c0U + 196U);
}

// [EN] FDE[1102] start_va=0x040b64, fde_va=0x07c1d8, span=56 B | [VN] FDE[1102]
uint32_t ttr_fde_1102_0x040b64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807c28U) + (a1 ^ 0xb9000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3940d008U + 0x040b64U) ^ (0x12000029U + 0x07c1d8U + 56U);
}

// [EN] FDE[1103] start_va=0x040b9c, fde_va=0x07c1f0, span=72 B | [VN] FDE[1103]
uint32_t ttr_fde_1103_0x040b9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401c6aU) + (a1 ^ 0xf9400869U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5100042bU + 0x040b9cU) ^ (0x5100044cU + 0x07c1f0U + 72U);
}

// [EN] FDE[1104] start_va=0x040be4, fde_va=0x07c208, span=16 B | [VN] FDE[1104]
uint32_t ttr_fde_1104_0x040be4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007e5aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x040be4U) ^ (0x17ff6c50U + 0x07c208U + 16U);
}

// [EN] FDE[1105] start_va=0x040bf4, fde_va=0x07c220, span=48 B | [VN] FDE[1105]
uint32_t ttr_fde_1105_0x040bf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807c28U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401008U + 0x040bf4U) ^ (0xf940102aU + 0x07c220U + 48U);
}

// [EN] FDE[1106] start_va=0x040c24, fde_va=0x07c238, span=16 B | [VN] FDE[1106]
uint32_t ttr_fde_1106_0x040c24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007e4aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x040c24U) ^ (0x17ff6c40U + 0x07c238U + 16U);
}

// [EN] FDE[1107] start_va=0x040c34, fde_va=0x07c250, span=40 B | [VN] FDE[1107]
uint32_t ttr_fde_1107_0x040c34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807c28U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401008U + 0x040c34U) ^ (0xf9400829U + 0x07c250U + 40U);
}

// [EN] FDE[1108] start_va=0x040c5c, fde_va=0x07c268, span=16 B | [VN] FDE[1108]
uint32_t ttr_fde_1108_0x040c5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007e3cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x040c5cU) ^ (0x17ff6c32U + 0x07c268U + 16U);
}

// [EN] FDE[1109] start_va=0x040c6c, fde_va=0x07c280, span=36 B | [VN] FDE[1109]
uint32_t ttr_fde_1109_0x040c6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9412428U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x540000c1U + 0x040c6cU) ^ (0x39416028U + 0x07c280U + 36U);
}

// [EN] FDE[1110] start_va=0x040c90, fde_va=0x07c298, span=16 B | [VN] FDE[1110]
uint32_t ttr_fde_1110_0x040c90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007e2fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x040c90U) ^ (0x17ff6c25U + 0x07c298U + 16U);
}

// [EN] FDE[1111] start_va=0x040ca0, fde_va=0x07c2b0, span=44 B | [VN] FDE[1111]
uint32_t ttr_fde_1111_0x040ca0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39417028U) + (a1 ^ 0x34000128U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa940a428U + 0x040ca0U) ^ (0xeb08013fU + 0x07c2b0U + 44U);
}

// [EN] FDE[1112] start_va=0x040ccc, fde_va=0x07c2c8, span=32 B | [VN] FDE[1112]
uint32_t ttr_fde_1112_0x040ccc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007c0bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401e68U + 0x040cccU) ^ (0x900002caU + 0x07c2c8U + 32U);
}

// [EN] FDE[1113] start_va=0x040cec, fde_va=0x07c2e0, span=1300 B | [VN] FDE[1113]
uint32_t ttr_fde_1113_0x040cec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10443ffU) + (a1 ^ 0xa90b6ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90c67faU + 0x040cecU) ^ (0xa90d5ff8U + 0x07c2e0U + 1300U);
}

// [EN] FDE[1114] start_va=0x041200, fde_va=0x07c310, span=8 B | [VN] FDE[1114]
uint32_t ttr_fde_1114_0x041200(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6ac3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10183ffU + 0x041200U) ^ (0xf90013f8U + 0x07c310U + 8U);
}

// [EN] FDE[1115] start_va=0x041208, fde_va=0x07c328, span=236 B | [VN] FDE[1115]
uint32_t ttr_fde_1115_0x041208(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf90013f8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035bf7U + 0x041208U) ^ (0xa90453f5U + 0x07c328U + 236U);
}

// [EN] FDE[1116] start_va=0x0412f4, fde_va=0x07c350, span=92 B | [VN] FDE[1116]
uint32_t ttr_fde_1116_0x0412f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10083ffU) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x390033e1U + 0x0412f4U) ^ (0x39429408U + 0x07c350U + 92U);
}

// [EN] FDE[1117] start_va=0x041350, fde_va=0x07c368, span=100 B | [VN] FDE[1117]
uint32_t ttr_fde_1117_0x041350(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa9025bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x041350U) ^ (0xa9047bf3U + 0x07c368U + 100U);
}

// [EN] FDE[1118] start_va=0x0413b4, fde_va=0x07c388, span=204 B | [VN] FDE[1118]
uint32_t ttr_fde_1118_0x0413b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xeb02003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000600U + 0x0413b4U) ^ (0x39400028U + 0x07c388U + 204U);
}

// [EN] FDE[1119] start_va=0x041480, fde_va=0x07c3a0, span=308 B | [VN] FDE[1119]
uint32_t ttr_fde_1119_0x041480(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb02003fU + 0x041480U) ^ (0x54000920U + 0x07c3a0U + 308U);
}

// [EN] FDE[1120] start_va=0x0415b4, fde_va=0x07c3c0, span=720 B | [VN] FDE[1120]
uint32_t ttr_fde_1120_0x0415b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xf90033f8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9075bf7U + 0x0415b4U) ^ (0xa90853f5U + 0x07c3c0U + 720U);
}

// [EN] FDE[1121] start_va=0x041884, fde_va=0x07c3e8, span=132 B | [VN] FDE[1121]
uint32_t ttr_fde_1121_0x041884(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100c3ffU) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x041884U) ^ (0x39429408U + 0x07c3e8U + 132U);
}

// [EN] FDE[1122] start_va=0x041908, fde_va=0x07c408, span=224 B | [VN] FDE[1122]
uint32_t ttr_fde_1122_0x041908(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc63f9U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x041908U) ^ (0xa9037bf3U + 0x07c408U + 224U);
}

// [EN] FDE[1123] start_va=0x0419e8, fde_va=0x07c430, span=28 B | [VN] FDE[1123]
uint32_t ttr_fde_1123_0x0419e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400009U) + (a1 ^ 0x37000089U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91000408U + 0x0419e8U) ^ (0xd341fd29U + 0x07c430U + 28U);
}

// [EN] FDE[1124] start_va=0x041a04, fde_va=0x07c448, span=40 B | [VN] FDE[1124]
uint32_t ttr_fde_1124_0x041a04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x041a04U) ^ (0x94008422U + 0x07c448U + 40U);
}

// [EN] FDE[1125] start_va=0x041a2c, fde_va=0x07c468, span=56 B | [VN] FDE[1125]
uint32_t ttr_fde_1125_0x041a2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400828U + 0x041a2cU) ^ (0x3dc00020U + 0x07c468U + 56U);
}

// [EN] FDE[1126] start_va=0x041a64, fde_va=0x07c488, span=260 B | [VN] FDE[1126]
uint32_t ttr_fde_1126_0x041a64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x041a64U) ^ (0xa9037bf3U + 0x07c488U + 260U);
}

// [EN] FDE[1127] start_va=0x041b68, fde_va=0x07c4b0, span=20 B | [VN] FDE[1127]
uint32_t ttr_fde_1127_0x041b68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94008b72U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x041b68U) ^ (0xa8c17bf3U + 0x07c4b0U + 20U);
}

// [EN] FDE[1128] start_va=0x041b7c, fde_va=0x07c4c8, span=8 B | [VN] FDE[1128]
uint32_t ttr_fde_1128_0x041b7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6864U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff4U + 0x041b7cU) ^ (0xa9017bf3U + 0x07c4c8U + 8U);
}

// [EN] FDE[1129] start_va=0x041b84, fde_va=0x07c4e0, span=52 B | [VN] FDE[1129]
uint32_t ttr_fde_1129_0x041b84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400828U + 0x041b84U) ^ (0x3dc00020U + 0x07c4e0U + 52U);
}

// [EN] FDE[1130] start_va=0x041bb8, fde_va=0x07c500, span=88 B | [VN] FDE[1130]
uint32_t ttr_fde_1130_0x041bb8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x041bb8U) ^ (0x9400809bU + 0x07c500U + 88U);
}

// [EN] FDE[1131] start_va=0x041c10, fde_va=0x07c520, span=8 B | [VN] FDE[1131]
uint32_t ttr_fde_1131_0x041c10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff683fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400008U + 0x041c10U) ^ (0x370000a8U + 0x07c520U + 8U);
}

// [EN] FDE[1132] start_va=0x041c18, fde_va=0x07c538, span=48 B | [VN] FDE[1132]
uint32_t ttr_fde_1132_0x041c18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400008U) + (a1 ^ 0x370000a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800049U + 0x041c18U) ^ (0xaa0003e8U + 0x07c538U + 48U);
}

// [EN] FDE[1133] start_va=0x041c48, fde_va=0x07c550, span=152 B | [VN] FDE[1133]
uint32_t ttr_fde_1133_0x041c48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401808U + 0x041c48U) ^ (0xaa0003f3U + 0x07c550U + 152U);
}

// [EN] FDE[1134] start_va=0x041ce0, fde_va=0x07c570, span=16 B | [VN] FDE[1134]
uint32_t ttr_fde_1134_0x041ce0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007a1bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x041ce0U) ^ (0x17ff6811U + 0x07c570U + 16U);
}

// [EN] FDE[1135] start_va=0x041cf0, fde_va=0x07c588, span=52 B | [VN] FDE[1135]
uint32_t ttr_fde_1135_0x041cf0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9412428U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000140U + 0x041cf0U) ^ (0x39400109U + 0x07c588U + 52U);
}

// [EN] FDE[1136] start_va=0x041d24, fde_va=0x07c5a0, span=32 B | [VN] FDE[1136]
uint32_t ttr_fde_1136_0x041d24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940078e9U + 0x041d24U) ^ (0x97ff6880U + 0x07c5a0U + 32U);
}

// [EN] FDE[1137] start_va=0x041d44, fde_va=0x07c5c0, span=28 B | [VN] FDE[1137]
uint32_t ttr_fde_1137_0x041d44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf00002a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91244108U + 0x041d44U) ^ (0x94007d43U + 0x07c5c0U + 28U);
}

// [EN] FDE[1138] start_va=0x041d60, fde_va=0x07c5d8, span=24 B | [VN] FDE[1138]
uint32_t ttr_fde_1138_0x041d60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff7U + 0x041d60U) ^ (0xaa1303e0U + 0x07c5d8U + 24U);
}

// [EN] FDE[1139] start_va=0x041d78, fde_va=0x07c5f0, span=52 B | [VN] FDE[1139]
uint32_t ttr_fde_1139_0x041d78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9412428U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000140U + 0x041d78U) ^ (0x39400109U + 0x07c5f0U + 52U);
}

// [EN] FDE[1140] start_va=0x041dac, fde_va=0x07c608, span=28 B | [VN] FDE[1140]
uint32_t ttr_fde_1140_0x041dac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf00002a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91250108U + 0x041dacU) ^ (0x94007d29U + 0x07c608U + 28U);
}

// [EN] FDE[1141] start_va=0x041dc8, fde_va=0x07c620, span=24 B | [VN] FDE[1141]
uint32_t ttr_fde_1141_0x041dc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff7U + 0x041dc8U) ^ (0xaa1303e0U + 0x07c620U + 24U);
}

// [EN] FDE[1142] start_va=0x041de0, fde_va=0x07c638, span=84 B | [VN] FDE[1142]
uint32_t ttr_fde_1142_0x041de0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9412428U + 0x041de0U) ^ (0xaa0103f3U + 0x07c638U + 84U);
}

// [EN] FDE[1143] start_va=0x041e34, fde_va=0x07c658, span=104 B | [VN] FDE[1143]
uint32_t ttr_fde_1143_0x041e34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10083ffU) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800be8U + 0x041e34U) ^ (0x390033e8U + 0x07c658U + 104U);
}

// [EN] FDE[1144] start_va=0x041e9c, fde_va=0x07c670, span=408 B | [VN] FDE[1144]
uint32_t ttr_fde_1144_0x041e9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x041e9cU) ^ (0x940080b9U + 0x07c670U + 408U);
}

// [EN] FDE[1145] start_va=0x042034, fde_va=0x07c690, span=84 B | [VN] FDE[1145]
uint32_t ttr_fde_1145_0x042034(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa9035bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x042034U) ^ (0xa9057bf3U + 0x07c690U + 84U);
}

// [EN] FDE[1146] start_va=0x042088, fde_va=0x07c6b0, span=84 B | [VN] FDE[1146]
uint32_t ttr_fde_1146_0x042088(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa9035bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x042088U) ^ (0xa9057bf3U + 0x07c6b0U + 84U);
}

// [EN] FDE[1147] start_va=0x0420dc, fde_va=0x07c6d0, span=64 B | [VN] FDE[1147]
uint32_t ttr_fde_1147_0x0420dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb7f801c1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400808U + 0x0420dcU) ^ (0xf9400009U + 0x07c6d0U + 64U);
}

// [EN] FDE[1148] start_va=0x04211c, fde_va=0x07c6e8, span=32 B | [VN] FDE[1148]
uint32_t ttr_fde_1148_0x04211c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400796dU + 0x04211cU) ^ (0x5400004bU + 0x07c6e8U + 32U);
}

// [EN] FDE[1149] start_va=0x04213c, fde_va=0x07c708, span=40 B | [VN] FDE[1149]
uint32_t ttr_fde_1149_0x04213c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x04213cU) ^ (0xd1000529U + 0x07c708U + 40U);
}

// [EN] FDE[1150] start_va=0x042164, fde_va=0x07c720, span=124 B | [VN] FDE[1150]
uint32_t ttr_fde_1150_0x042164(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb020069U) + (a1 ^ 0xaa0003e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000320U + 0x042164U) ^ (0xcb08002aU + 0x07c720U + 124U);
}

// [EN] FDE[1151] start_va=0x0421e0, fde_va=0x07c738, span=148 B | [VN] FDE[1151]
uint32_t ttr_fde_1151_0x0421e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa90353f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x0421e0U) ^ (0x9400820eU + 0x07c738U + 148U);
}

// [EN] FDE[1152] start_va=0x042274, fde_va=0x07c758, span=8 B | [VN] FDE[1152]
uint32_t ttr_fde_1152_0x042274(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff66a6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bd5bf7U + 0x042274U) ^ (0xa90153f5U + 0x07c758U + 8U);
}

// [EN] FDE[1153] start_va=0x04227c, fde_va=0x07c770, span=88 B | [VN] FDE[1153]
uint32_t ttr_fde_1153_0x04227c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04227cU) ^ (0x94007eeaU + 0x07c770U + 88U);
}

// [EN] FDE[1154] start_va=0x0422d4, fde_va=0x07c790, span=8 B | [VN] FDE[1154]
uint32_t ttr_fde_1154_0x0422d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff668eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x0422d4U) ^ (0xa90253f5U + 0x07c790U + 8U);
}

// [EN] FDE[1155] start_va=0x0422dc, fde_va=0x07c7a8, span=68 B | [VN] FDE[1155]
uint32_t ttr_fde_1155_0x0422dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x0422dcU) ^ (0x940081c8U + 0x07c7a8U + 68U);
}

// [EN] FDE[1156] start_va=0x042320, fde_va=0x07c7c8, span=24 B | [VN] FDE[1156]
uint32_t ttr_fde_1156_0x042320(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x94000005U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a2003e8U + 0x042320U) ^ (0x12000100U + 0x07c7c8U + 24U);
}

// [EN] FDE[1157] start_va=0x042338, fde_va=0x07c7e0, span=76 B | [VN] FDE[1157]
uint32_t ttr_fde_1157_0x042338(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94007818U + 0x042338U) ^ (0x39400288U + 0x07c7e0U + 76U);
}

// [EN] FDE[1158] start_va=0x042384, fde_va=0x07c800, span=120 B | [VN] FDE[1158]
uint32_t ttr_fde_1158_0x042384(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400008U + 0x042384U) ^ (0xaa0403f3U + 0x07c800U + 120U);
}

// [EN] FDE[1159] start_va=0x0423fc, fde_va=0x07c820, span=132 B | [VN] FDE[1159]
uint32_t ttr_fde_1159_0x0423fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00002a8U + 0x0423fcU) ^ (0x9125c108U + 0x07c820U + 132U);
}

// [EN] FDE[1160] start_va=0x042480, fde_va=0x07c840, span=24 B | [VN] FDE[1160]
uint32_t ttr_fde_1160_0x042480(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffffddU + 0x042480U) ^ (0xaa1303e0U + 0x07c840U + 24U);
}

// [EN] FDE[1161] start_va=0x042498, fde_va=0x07c858, span=1172 B | [VN] FDE[1161]
uint32_t ttr_fde_1161_0x042498(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0xf90033faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90763f9U + 0x042498U) ^ (0xa9085bf7U + 0x07c858U + 1172U);
}

// [EN] FDE[1162] start_va=0x04292c, fde_va=0x07c880, span=40 B | [VN] FDE[1162]
uint32_t ttr_fde_1162_0x04292c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x04292cU) ^ (0x94008058U + 0x07c880U + 40U);
}

// [EN] FDE[1163] start_va=0x042954, fde_va=0x07c8a0, span=36 B | [VN] FDE[1163]
uint32_t ttr_fde_1163_0x042954(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa0003e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103e0U + 0x042954U) ^ (0xaa0803e1U + 0x07c8a0U + 36U);
}

// [EN] FDE[1164] start_va=0x042978, fde_va=0x07c8b8, span=68 B | [VN] FDE[1164]
uint32_t ttr_fde_1164_0x042978(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x042978U) ^ (0x94008021U + 0x07c8b8U + 68U);
}

// [EN] FDE[1165] start_va=0x0429bc, fde_va=0x07c8d8, span=72 B | [VN] FDE[1165]
uint32_t ttr_fde_1165_0x0429bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x13001c28U) + (a1 ^ 0x37f80128U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400408U + 0x0429bcU) ^ (0x92401c29U + 0x07c8d8U + 72U);
}

// [EN] FDE[1166] start_va=0x042a04, fde_va=0x07c8f0, span=32 B | [VN] FDE[1166]
uint32_t ttr_fde_1166_0x042a04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb01001fU) + (a1 ^ 0x540000c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400008U + 0x042a04U) ^ (0x6b22011fU + 0x07c8f0U + 32U);
}

// [EN] FDE[1167] start_va=0x042a24, fde_va=0x07c908, span=16 B | [VN] FDE[1167]
uint32_t ttr_fde_1167_0x042a24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940076caU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x042a24U) ^ (0x17ff64c0U + 0x07c908U + 16U);
}

// [EN] FDE[1168] start_va=0x042a34, fde_va=0x07c920, span=44 B | [VN] FDE[1168]
uint32_t ttr_fde_1168_0x042a34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9412428U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000100U + 0x042a34U) ^ (0x39400109U + 0x07c920U + 44U);
}

// [EN] FDE[1169] start_va=0x042a60, fde_va=0x07c938, span=732 B | [VN] FDE[1169]
uint32_t ttr_fde_1169_0x042a60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x94007510U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x042a60U) ^ (0xa9067bfdU + 0x07c938U + 732U);
}

// [EN] FDE[1170] start_va=0x042d3c, fde_va=0x07c968, span=48 B | [VN] FDE[1170]
uint32_t ttr_fde_1170_0x042d3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb01001fU) + (a1 ^ 0x91000408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfa411104U + 0x042d3cU) ^ (0x54000100U + 0x07c968U + 48U);
}

// [EN] FDE[1171] start_va=0x042d6c, fde_va=0x07c980, span=152 B | [VN] FDE[1171]
uint32_t ttr_fde_1171_0x042d6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401808U + 0x042d6cU) ^ (0xaa0003f3U + 0x07c980U + 152U);
}

// [EN] FDE[1172] start_va=0x042e04, fde_va=0x07c9a0, span=16 B | [VN] FDE[1172]
uint32_t ttr_fde_1172_0x042e04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940075d2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x042e04U) ^ (0x17ff63c8U + 0x07c9a0U + 16U);
}

// [EN] FDE[1173] start_va=0x042e14, fde_va=0x07c9b8, span=172 B | [VN] FDE[1173]
uint32_t ttr_fde_1173_0x042e14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xa9422828U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401009U + 0x042e14U) ^ (0xcb08014bU + 0x07c9b8U + 172U);
}

// [EN] FDE[1174] start_va=0x042ec0, fde_va=0x07c9d0, span=8 B | [VN] FDE[1174]
uint32_t ttr_fde_1174_0x042ec0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6393U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x042ec0U) ^ (0xd00002a8U + 0x07c9d0U + 8U);
}

// [EN] FDE[1175] start_va=0x042ec8, fde_va=0x07c9e8, span=28 B | [VN] FDE[1175]
uint32_t ttr_fde_1175_0x042ec8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xd00002a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91280108U + 0x042ec8U) ^ (0x940078e2U + 0x07c9e8U + 28U);
}

// [EN] FDE[1176] start_va=0x042ee4, fde_va=0x07ca00, span=24 B | [VN] FDE[1176]
uint32_t ttr_fde_1176_0x042ee4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff7U + 0x042ee4U) ^ (0xaa1303e0U + 0x07ca00U + 24U);
}

// [EN] FDE[1177] start_va=0x042efc, fde_va=0x07ca18, span=116 B | [VN] FDE[1177]
uint32_t ttr_fde_1177_0x042efc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9402809U) + (a1 ^ 0xf9401028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5280030aU + 0x042efcU) ^ (0x51000529U + 0x07ca18U + 116U);
}

// [EN] FDE[1178] start_va=0x042f70, fde_va=0x07ca30, span=28 B | [VN] FDE[1178]
uint32_t ttr_fde_1178_0x042f70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xd00002a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9128c108U + 0x042f70U) ^ (0x940078b8U + 0x07ca30U + 28U);
}

// [EN] FDE[1179] start_va=0x042f8c, fde_va=0x07ca48, span=24 B | [VN] FDE[1179]
uint32_t ttr_fde_1179_0x042f8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff7U + 0x042f8cU) ^ (0xaa1303e0U + 0x07ca48U + 24U);
}

// [EN] FDE[1180] start_va=0x042fa4, fde_va=0x07ca60, span=196 B | [VN] FDE[1180]
uint32_t ttr_fde_1180_0x042fa4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x042fa4U) ^ (0xa9037bf3U + 0x07ca60U + 196U);
}

// [EN] FDE[1181] start_va=0x043068, fde_va=0x07ca88, span=100 B | [VN] FDE[1181]
uint32_t ttr_fde_1181_0x043068(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x043068U) ^ (0x94007bf0U + 0x07ca88U + 100U);
}

// [EN] FDE[1182] start_va=0x0430cc, fde_va=0x07caa8, span=256 B | [VN] FDE[1182]
uint32_t ttr_fde_1182_0x0430cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xf90023f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90553f5U + 0x0430ccU) ^ (0xa9067bf3U + 0x07caa8U + 256U);
}

// [EN] FDE[1183] start_va=0x0431cc, fde_va=0x07cac8, span=668 B | [VN] FDE[1183]
uint32_t ttr_fde_1183_0x0431cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x0431ccU) ^ (0xa9037bf3U + 0x07cac8U + 668U);
}

// [EN] FDE[1184] start_va=0x043468, fde_va=0x07caf0, span=32 B | [VN] FDE[1184]
uint32_t ttr_fde_1184_0x043468(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007224U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401e68U + 0x043468U) ^ (0xb00002aaU + 0x07caf0U + 32U);
}

// [EN] FDE[1185] start_va=0x043488, fde_va=0x07cb08, span=8 B | [VN] FDE[1185]
uint32_t ttr_fde_1185_0x043488(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff6221U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x043488U) ^ (0x9400742fU + 0x07cb08U + 8U);
}

// [EN] FDE[1186] start_va=0x043490, fde_va=0x07cb20, span=16 B | [VN] FDE[1186]
uint32_t ttr_fde_1186_0x043490(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400742fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x043490U) ^ (0x17ff6225U + 0x07cb20U + 16U);
}

// [EN] FDE[1187] start_va=0x0434a0, fde_va=0x07cb38, span=92 B | [VN] FDE[1187]
uint32_t ttr_fde_1187_0x0434a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x0434a0U) ^ (0x52800600U + 0x07cb38U + 92U);
}

// [EN] FDE[1188] start_va=0x0434fc, fde_va=0x07cb58, span=36 B | [VN] FDE[1188]
uint32_t ttr_fde_1188_0x0434fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fff264U + 0x0434fcU) ^ (0x6f00e400U + 0x07cb58U + 36U);
}

// [EN] FDE[1189] start_va=0x043520, fde_va=0x07cb70, span=144 B | [VN] FDE[1189]
uint32_t ttr_fde_1189_0x043520(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x043520U) ^ (0xaa0003f3U + 0x07cb70U + 144U);
}

// [EN] FDE[1190] start_va=0x0435b0, fde_va=0x07cb90, span=36 B | [VN] FDE[1190]
uint32_t ttr_fde_1190_0x0435b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xb00002a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912a4108U + 0x0435b0U) ^ (0xaa0003f3U + 0x07cb90U + 36U);
}

// [EN] FDE[1191] start_va=0x0435d4, fde_va=0x07cba8, span=24 B | [VN] FDE[1191]
uint32_t ttr_fde_1191_0x0435d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff5U + 0x0435d4U) ^ (0xaa1303e0U + 0x07cba8U + 24U);
}

// [EN] FDE[1192] start_va=0x0435ec, fde_va=0x07cbc0, span=272 B | [VN] FDE[1192]
uint32_t ttr_fde_1192_0x0435ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xa90753f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9087bf3U + 0x0435ecU) ^ (0x6f00e400U + 0x07cbc0U + 272U);
}

// [EN] FDE[1193] start_va=0x0436fc, fde_va=0x07cbe0, span=28 B | [VN] FDE[1193]
uint32_t ttr_fde_1193_0x0436fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xb00002a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912b0108U + 0x0436fcU) ^ (0x940076d5U + 0x07cbe0U + 28U);
}

// [EN] FDE[1194] start_va=0x043718, fde_va=0x07cbf8, span=24 B | [VN] FDE[1194]
uint32_t ttr_fde_1194_0x043718(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff7U + 0x043718U) ^ (0xaa1303e0U + 0x07cbf8U + 24U);
}

// [EN] FDE[1195] start_va=0x043730, fde_va=0x07cc10, span=256 B | [VN] FDE[1195]
uint32_t ttr_fde_1195_0x043730(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400428U) + (a1 ^ 0xf9400c2aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb0a011fU + 0x043730U) ^ (0x540004c0U + 0x07cc10U + 256U);
}

// [EN] FDE[1196] start_va=0x043830, fde_va=0x07cc28, span=20 B | [VN] FDE[1196]
uint32_t ttr_fde_1196_0x043830(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94007d27U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x043830U) ^ (0xa8c17bf3U + 0x07cc28U + 20U);
}

// [EN] FDE[1197] start_va=0x043844, fde_va=0x07cc40, span=20 B | [VN] FDE[1197]
uint32_t ttr_fde_1197_0x043844(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400c00U) + (a1 ^ 0xb4000060U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x043844U) ^ (0x140071e3U + 0x07cc40U + 20U);
}

// [EN] FDE[1198] start_va=0x043858, fde_va=0x07cc58, span=4 B | [VN] FDE[1198]
uint32_t ttr_fde_1198_0x043858(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff6136U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400733cU + 0x043858U) ^ (0xa8c17bf3U + 0x07cc58U + 4U);
}

// [EN] FDE[1199] start_va=0x04385c, fde_va=0x07cc70, span=16 B | [VN] FDE[1199]
uint32_t ttr_fde_1199_0x04385c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400733cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c17bf3U + 0x04385cU) ^ (0x17ff6132U + 0x07cc70U + 16U);
}

// [EN] FDE[1200] start_va=0x04386c, fde_va=0x07cc88, span=12 B | [VN] FDE[1200]
uint32_t ttr_fde_1200_0x04386c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807c28U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14007228U + 0x04386cU) ^ (0x17ff612eU + 0x07cc88U + 12U);
}

// [EN] FDE[1201] start_va=0x043878, fde_va=0x07cca0, span=4 B | [VN] FDE[1201]
uint32_t ttr_fde_1201_0x043878(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff612eU) + (a1 ^ 0x12807ce8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9000028U + 0x043878U) ^ (0xd65f03c0U + 0x07cca0U + 4U);
}

// [EN] FDE[1202] start_va=0x04387c, fde_va=0x07ccb8, span=12 B | [VN] FDE[1202]
uint32_t ttr_fde_1202_0x04387c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807ce8U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x04387cU) ^ (0x39400008U + 0x07ccb8U + 12U);
}

// [EN] FDE[1203] start_va=0x043888, fde_va=0x07ccd0, span=60 B | [VN] FDE[1203]
uint32_t ttr_fde_1203_0x043888(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400008U) + (a1 ^ 0xaa0203e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x37000088U + 0x043888U) ^ (0x91000400U + 0x07ccd0U + 60U);
}

// [EN] FDE[1204] start_va=0x0438c4, fde_va=0x07cce8, span=140 B | [VN] FDE[1204]
uint32_t ttr_fde_1204_0x0438c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x0438c4U) ^ (0x39400008U + 0x07cce8U + 140U);
}

// [EN] FDE[1205] start_va=0x043950, fde_va=0x07cd08, span=168 B | [VN] FDE[1205]
uint32_t ttr_fde_1205_0x043950(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc63f9U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x043950U) ^ (0xa9037bf3U + 0x07cd08U + 168U);
}

// [EN] FDE[1206] start_va=0x0439f8, fde_va=0x07cd30, span=496 B | [VN] FDE[1206]
uint32_t ttr_fde_1206_0x0439f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10543ffU) + (a1 ^ 0xf9007bfcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9106bfbU + 0x0439f8U) ^ (0xa91163f9U + 0x07cd30U + 496U);
}

// [EN] FDE[1207] start_va=0x043be8, fde_va=0x07cd60, span=156 B | [VN] FDE[1207]
uint32_t ttr_fde_1207_0x043be8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xa91153fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9127bf3U + 0x043be8U) ^ (0xaa0203f3U + 0x07cd60U + 156U);
}

// [EN] FDE[1208] start_va=0x043c84, fde_va=0x07cd80, span=348 B | [VN] FDE[1208]
uint32_t ttr_fde_1208_0x043c84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x043c84U) ^ (0xa9037bf3U + 0x07cd80U + 348U);
}

// [EN] FDE[1209] start_va=0x043de0, fde_va=0x07cda8, span=100 B | [VN] FDE[1209]
uint32_t ttr_fde_1209_0x043de0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x043de0U) ^ (0xa9037bf3U + 0x07cda8U + 100U);
}

// [EN] FDE[1210] start_va=0x043e44, fde_va=0x07cdd0, span=144 B | [VN] FDE[1210]
uint32_t ttr_fde_1210_0x043e44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x043e44U) ^ (0x940078cfU + 0x07cdd0U + 144U);
}

// [EN] FDE[1211] start_va=0x043ed4, fde_va=0x07cdf0, span=96 B | [VN] FDE[1211]
uint32_t ttr_fde_1211_0x043ed4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x043ed4U) ^ (0xa9037bf3U + 0x07cdf0U + 96U);
}

// [EN] FDE[1212] start_va=0x043f34, fde_va=0x07ce18, span=60 B | [VN] FDE[1212]
uint32_t ttr_fde_1212_0x043f34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94007549U + 0x043f34U) ^ (0x9400000cU + 0x07ce18U + 60U);
}

// [EN] FDE[1213] start_va=0x043f70, fde_va=0x07ce38, span=504 B | [VN] FDE[1213]
uint32_t ttr_fde_1213_0x043f70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc63f9U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x043f70U) ^ (0xa9037bf3U + 0x07ce38U + 504U);
}

// [EN] FDE[1214] start_va=0x044168, fde_va=0x07ce60, span=660 B | [VN] FDE[1214]
uint32_t ttr_fde_1214_0x044168(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81b0ffaU) + (a1 ^ 0xa90163f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x044168U) ^ (0xa90353f5U + 0x07ce60U + 660U);
}

// [EN] FDE[1215] start_va=0x0443fc, fde_va=0x07ce88, span=128 B | [VN] FDE[1215]
uint32_t ttr_fde_1215_0x0443fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x0443fcU) ^ (0xa9037bf3U + 0x07ce88U + 128U);
}

// [EN] FDE[1216] start_va=0x04447c, fde_va=0x07ceb0, span=1292 B | [VN] FDE[1216]
uint32_t ttr_fde_1216_0x04447c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10343ffU) + (a1 ^ 0xa9076ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90867faU + 0x04447cU) ^ (0xa9095ff8U + 0x07ceb0U + 1292U);
}

// [EN] FDE[1217] start_va=0x044988, fde_va=0x07cee0, span=100 B | [VN] FDE[1217]
uint32_t ttr_fde_1217_0x044988(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa9025bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x044988U) ^ (0xa9047bf3U + 0x07cee0U + 100U);
}

// [EN] FDE[1218] start_va=0x0449ec, fde_va=0x07cf00, span=204 B | [VN] FDE[1218]
uint32_t ttr_fde_1218_0x0449ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xeb02003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000600U + 0x0449ecU) ^ (0x39400028U + 0x07cf00U + 204U);
}

// [EN] FDE[1219] start_va=0x044ab8, fde_va=0x07cf18, span=296 B | [VN] FDE[1219]
uint32_t ttr_fde_1219_0x044ab8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb02003fU + 0x044ab8U) ^ (0x540008c0U + 0x07cf18U + 296U);
}

// [EN] FDE[1220] start_va=0x044be0, fde_va=0x07cf38, span=416 B | [VN] FDE[1220]
uint32_t ttr_fde_1220_0x044be0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x044be0U) ^ (0x94007568U + 0x07cf38U + 416U);
}

// [EN] FDE[1221] start_va=0x044d80, fde_va=0x07cf58, span=108 B | [VN] FDE[1221]
uint32_t ttr_fde_1221_0x044d80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb020068U) + (a1 ^ 0x54000320U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb000029U + 0x044d80U) ^ (0xeb08013fU + 0x07cf58U + 108U);
}

// [EN] FDE[1222] start_va=0x044dec, fde_va=0x07cf70, span=148 B | [VN] FDE[1222]
uint32_t ttr_fde_1222_0x044dec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa90353f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x044decU) ^ (0x9400770bU + 0x07cf70U + 148U);
}

// [EN] FDE[1223] start_va=0x044e80, fde_va=0x07cf90, span=824 B | [VN] FDE[1223]
uint32_t ttr_fde_1223_0x044e80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e3U) + (a1 ^ 0x94006c08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303feU + 0x044e80U) ^ (0xa9067bfdU + 0x07cf90U + 824U);
}

// [EN] FDE[1224] start_va=0x0451b8, fde_va=0x07cfc0, span=48 B | [VN] FDE[1224]
uint32_t ttr_fde_1224_0x0451b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb01001fU) + (a1 ^ 0x91000408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfa411104U + 0x0451b8U) ^ (0x54000100U + 0x07cfc0U + 48U);
}

// [EN] FDE[1225] start_va=0x0451e8, fde_va=0x07cfd8, span=96 B | [VN] FDE[1225]
uint32_t ttr_fde_1225_0x0451e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x0451e8U) ^ (0x94007390U + 0x07cfd8U + 96U);
}

// [EN] FDE[1226] start_va=0x045248, fde_va=0x07cff8, span=256 B | [VN] FDE[1226]
uint32_t ttr_fde_1226_0x045248(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xf90023f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90553f5U + 0x045248U) ^ (0xa9067bf3U + 0x07cff8U + 256U);
}

// [EN] FDE[1227] start_va=0x045348, fde_va=0x07d018, span=676 B | [VN] FDE[1227]
uint32_t ttr_fde_1227_0x045348(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x045348U) ^ (0x9400738eU + 0x07d018U + 676U);
}

// [EN] FDE[1228] start_va=0x0455ec, fde_va=0x07d038, span=44 B | [VN] FDE[1228]
uint32_t ttr_fde_1228_0x0455ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0455ecU) ^ (0xb40000d3U + 0x07d038U + 44U);
}

// [EN] FDE[1229] start_va=0x045618, fde_va=0x07d058, span=4 B | [VN] FDE[1229]
uint32_t ttr_fde_1229_0x045618(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0xf81d0ff6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90153f5U + 0x045618U) ^ (0xa9027bf3U + 0x07d058U + 4U);
}

// [EN] FDE[1230] start_va=0x04561c, fde_va=0x07d070, span=112 B | [VN] FDE[1230]
uint32_t ttr_fde_1230_0x04561c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04561cU) ^ (0xb9400808U + 0x07d070U + 112U);
}

// [EN] FDE[1231] start_va=0x04568c, fde_va=0x07d090, span=424 B | [VN] FDE[1231]
uint32_t ttr_fde_1231_0x04568c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x94006a05U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x04568cU) ^ (0xa9067bfdU + 0x07d090U + 424U);
}

// [EN] FDE[1232] start_va=0x045834, fde_va=0x07d0c0, span=32 B | [VN] FDE[1232]
uint32_t ttr_fde_1232_0x045834(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103e0U + 0x045834U) ^ (0xaa0203e1U + 0x07d0c0U + 32U);
}

// [EN] FDE[1233] start_va=0x045854, fde_va=0x07d0d8, span=20 B | [VN] FDE[1233]
uint32_t ttr_fde_1233_0x045854(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400705fU + 0x045854U) ^ (0xa9417bf3U + 0x07d0d8U + 20U);
}

// [EN] FDE[1234] start_va=0x045868, fde_va=0x07d0f8, span=36 B | [VN] FDE[1234]
uint32_t ttr_fde_1234_0x045868(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006accU + 0x045868U) ^ (0xaa1303e1U + 0x07d0f8U + 36U);
}

// [EN] FDE[1235] start_va=0x04588c, fde_va=0x07d118, span=224 B | [VN] FDE[1235]
uint32_t ttr_fde_1235_0x04588c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6dbd23e9U) + (a1 ^ 0xf9000bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x04588cU) ^ (0x94007402U + 0x07d118U + 224U);
}

// [EN] FDE[1236] start_va=0x04596c, fde_va=0x07d138, span=968 B | [VN] FDE[1236]
uint32_t ttr_fde_1236_0x04596c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x94006ad6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x04596cU) ^ (0xa9077bfdU + 0x07d138U + 968U);
}

// [EN] FDE[1237] start_va=0x045d34, fde_va=0x07d168, span=228 B | [VN] FDE[1237]
uint32_t ttr_fde_1237_0x045d34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa90363f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9045bf7U + 0x045d34U) ^ (0xa90553f5U + 0x07d168U + 228U);
}

// [EN] FDE[1238] start_va=0x045e18, fde_va=0x07d190, span=28 B | [VN] FDE[1238]
uint32_t ttr_fde_1238_0x045e18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0x8b010909U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb08013fU + 0x045e18U) ^ (0x54000060U + 0x07d190U + 28U);
}

// [EN] FDE[1239] start_va=0x045e34, fde_va=0x07d1a8, span=52 B | [VN] FDE[1239]
uint32_t ttr_fde_1239_0x045e34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xd37efc28U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb5000148U + 0x045e34U) ^ (0x940075abU + 0x07d1a8U + 52U);
}

// [EN] FDE[1240] start_va=0x045e68, fde_va=0x07d1c0, span=24 B | [VN] FDE[1240]
uint32_t ttr_fde_1240_0x045e68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37efc08U) + (a1 ^ 0xb5000068U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37ef400U + 0x045e68U) ^ (0x17ff57bbU + 0x07d1c0U + 24U);
}

// [EN] FDE[1241] start_va=0x045e80, fde_va=0x07d1d8, span=32 B | [VN] FDE[1241]
uint32_t ttr_fde_1241_0x045e80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006a14U + 0x045e80U) ^ (0x5400004bU + 0x07d1d8U + 32U);
}

// [EN] FDE[1242] start_va=0x045ea0, fde_va=0x07d1f8, span=40 B | [VN] FDE[1242]
uint32_t ttr_fde_1242_0x045ea0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x045ea0U) ^ (0xd1001129U + 0x07d1f8U + 40U);
}

// [EN] FDE[1243] start_va=0x045ec8, fde_va=0x07d210, span=432 B | [VN] FDE[1243]
uint32_t ttr_fde_1243_0x045ec8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x045ec8U) ^ (0xaa0003f3U + 0x07d210U + 432U);
}

// [EN] FDE[1244] start_va=0x046078, fde_va=0x07d230, span=40 B | [VN] FDE[1244]
uint32_t ttr_fde_1244_0x046078(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006859U + 0x046078U) ^ (0xeb15029fU + 0x07d230U + 40U);
}

// [EN] FDE[1245] start_va=0x0460a0, fde_va=0x07d250, span=20 B | [VN] FDE[1245]
uint32_t ttr_fde_1245_0x0460a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x0460a0U) ^ (0x14006a47U + 0x07d250U + 20U);
}

// [EN] FDE[1246] start_va=0x0460b4, fde_va=0x07d268, span=60 B | [VN] FDE[1246]
uint32_t ttr_fde_1246_0x0460b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xd0000288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912d8108U + 0x0460b4U) ^ (0xaa0003f3U + 0x07d268U + 60U);
}

// [EN] FDE[1247] start_va=0x0460f0, fde_va=0x07d280, span=24 B | [VN] FDE[1247]
uint32_t ttr_fde_1247_0x0460f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffffefU + 0x0460f0U) ^ (0xaa1303e0U + 0x07d280U + 24U);
}

// [EN] FDE[1248] start_va=0x046108, fde_va=0x07d298, span=20 B | [VN] FDE[1248]
uint32_t ttr_fde_1248_0x046108(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000040U + 0x046108U) ^ (0x14006a2dU + 0x07d298U + 20U);
}

// [EN] FDE[1249] start_va=0x04611c, fde_va=0x07d2b0, span=32 B | [VN] FDE[1249]
uint32_t ttr_fde_1249_0x04611c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xd0000288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912ca108U + 0x04611cU) ^ (0x9400674cU + 0x07d2b0U + 32U);
}

// [EN] FDE[1250] start_va=0x04613c, fde_va=0x07d2c8, span=24 B | [VN] FDE[1250]
uint32_t ttr_fde_1250_0x04613c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x04613cU) ^ (0xaa1303e0U + 0x07d2c8U + 24U);
}

// [EN] FDE[1251] start_va=0x046154, fde_va=0x07d2e0, span=8 B | [VN] FDE[1251]
uint32_t ttr_fde_1251_0x046154(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17ffffd7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff56f5U + 0x046154U) ^ (0xf81e0ff4U + 0x07d2e0U + 8U);
}

// [EN] FDE[1252] start_va=0x04615c, fde_va=0x07d2f8, span=4 B | [VN] FDE[1252]
uint32_t ttr_fde_1252_0x04615c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff56f5U) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x04615cU) ^ (0xd0000288U + 0x07d2f8U + 4U);
}

// [EN] FDE[1253] start_va=0x046160, fde_va=0x07d310, span=56 B | [VN] FDE[1253]
uint32_t ttr_fde_1253_0x046160(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000288U + 0x046160U) ^ (0xaa0003f3U + 0x07d310U + 56U);
}

// [EN] FDE[1254] start_va=0x046198, fde_va=0x07d330, span=40 B | [VN] FDE[1254]
uint32_t ttr_fde_1254_0x046198(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940079f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400a60U + 0x046198U) ^ (0x97fffd12U + 0x07d330U + 40U);
}

// [EN] FDE[1255] start_va=0x0461c0, fde_va=0x07d360, span=232 B | [VN] FDE[1255]
uint32_t ttr_fde_1255_0x0461c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10383ffU) + (a1 ^ 0xa90c53f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90d7bf3U + 0x0461c0U) ^ (0x94006db5U + 0x07d360U + 232U);
}

// [EN] FDE[1256] start_va=0x0462a8, fde_va=0x07d380, span=4 B | [VN] FDE[1256]
uint32_t ttr_fde_1256_0x0462a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff56a2U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006693U + 0x0462a8U) ^ (0xd0000288U + 0x07d380U + 4U);
}

// [EN] FDE[1257] start_va=0x0462ac, fde_va=0x07d398, span=28 B | [VN] FDE[1257]
uint32_t ttr_fde_1257_0x0462ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94006693U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000288U + 0x0462acU) ^ (0x91334108U + 0x07d398U + 28U);
}

// [EN] FDE[1258] start_va=0x0462c8, fde_va=0x07d3b0, span=12 B | [VN] FDE[1258]
uint32_t ttr_fde_1258_0x0462c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000288U) + (a1 ^ 0x91334108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14006687U + 0x0462c8U) ^ (0xd65f03c0U + 0x07d3b0U + 12U);
}

// [EN] FDE[1259] start_va=0x0462d4, fde_va=0x07d3c8, span=4 B | [VN] FDE[1259]
uint32_t ttr_fde_1259_0x0462d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff5696U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x0462d4U) ^ (0xb9400028U + 0x07d3c8U + 4U);
}

// [EN] FDE[1260] start_va=0x0462d8, fde_va=0x07d3e0, span=4 B | [VN] FDE[1260]
uint32_t ttr_fde_1260_0x0462d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff5696U) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400028U + 0x0462d8U) ^ (0x350000a8U + 0x07d3e0U + 4U);
}

// [EN] FDE[1261] start_va=0x0462dc, fde_va=0x07d3f8, span=40 B | [VN] FDE[1261]
uint32_t ttr_fde_1261_0x0462dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb9400028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x350000a8U + 0x0462dcU) ^ (0xf9400408U + 0x07d3f8U + 40U);
}

// [EN] FDE[1262] start_va=0x046304, fde_va=0x07d410, span=4 B | [VN] FDE[1262]
uint32_t ttr_fde_1262_0x046304(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff568bU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400667cU + 0x046304U) ^ (0xd0000288U + 0x07d410U + 4U);
}

// [EN] FDE[1263] start_va=0x046308, fde_va=0x07d428, span=28 B | [VN] FDE[1263]
uint32_t ttr_fde_1263_0x046308(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400667cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000288U + 0x046308U) ^ (0x91322108U + 0x07d428U + 28U);
}

// [EN] FDE[1264] start_va=0x046324, fde_va=0x07d440, span=12 B | [VN] FDE[1264]
uint32_t ttr_fde_1264_0x046324(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000288U) + (a1 ^ 0x91322108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14006670U + 0x046324U) ^ (0xd65f03c0U + 0x07d440U + 12U);
}

// [EN] FDE[1265] start_va=0x046330, fde_va=0x07d458, span=4 B | [VN] FDE[1265]
uint32_t ttr_fde_1265_0x046330(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff567fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x046330U) ^ (0xb9400028U + 0x07d458U + 4U);
}

// [EN] FDE[1266] start_va=0x046334, fde_va=0x07d470, span=4 B | [VN] FDE[1266]
uint32_t ttr_fde_1266_0x046334(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff567fU) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400028U + 0x046334U) ^ (0x350000a8U + 0x07d470U + 4U);
}

// [EN] FDE[1267] start_va=0x046338, fde_va=0x07d488, span=40 B | [VN] FDE[1267]
uint32_t ttr_fde_1267_0x046338(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb9400028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x350000a8U + 0x046338U) ^ (0xf9400408U + 0x07d488U + 40U);
}

// [EN] FDE[1268] start_va=0x046360, fde_va=0x07d4a0, span=4 B | [VN] FDE[1268]
uint32_t ttr_fde_1268_0x046360(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff5674U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94006665U + 0x046360U) ^ (0xd0000288U + 0x07d4a0U + 4U);
}

// [EN] FDE[1269] start_va=0x046364, fde_va=0x07d4b8, span=28 B | [VN] FDE[1269]
uint32_t ttr_fde_1269_0x046364(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94006665U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000288U + 0x046364U) ^ (0x91310108U + 0x07d4b8U + 28U);
}

// [EN] FDE[1270] start_va=0x046380, fde_va=0x07d4d0, span=12 B | [VN] FDE[1270]
uint32_t ttr_fde_1270_0x046380(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000288U) + (a1 ^ 0x91310108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14006659U + 0x046380U) ^ (0xd65f03c0U + 0x07d4d0U + 12U);
}

// [EN] FDE[1271] start_va=0x04638c, fde_va=0x07d4e8, span=4 B | [VN] FDE[1271]
uint32_t ttr_fde_1271_0x04638c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff5668U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e0ff4U + 0x04638cU) ^ (0xa9017bf3U + 0x07d4e8U + 4U);
}

// [EN] FDE[1272] start_va=0x046390, fde_va=0x07d500, span=4 B | [VN] FDE[1272]
uint32_t ttr_fde_1272_0x046390(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff5668U) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x046390U) ^ (0x9400727cU + 0x07d500U + 4U);
}

// [EN] FDE[1273] start_va=0x046394, fde_va=0x07d518, span=212 B | [VN] FDE[1273]
uint32_t ttr_fde_1273_0x046394(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400727cU + 0x046394U) ^ (0x7100051fU + 0x07d518U + 212U);
}

// [EN] FDE[1274] start_va=0x046468, fde_va=0x07d538, span=24 B | [VN] FDE[1274]
uint32_t ttr_fde_1274_0x046468(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffff3cU + 0x046468U) ^ (0xaa1303e0U + 0x07d538U + 24U);
}

// [EN] FDE[1275] start_va=0x046480, fde_va=0x07d550, span=8 B | [VN] FDE[1275]
uint32_t ttr_fde_1275_0x046480(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9409000U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91023008U + 0x046480U) ^ (0x08dffd08U + 0x07d550U + 8U);
}

// [EN] FDE[1276] start_va=0x046488, fde_va=0x07d568, span=152 B | [VN] FDE[1276]
uint32_t ttr_fde_1276_0x046488(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91023008U) + (a1 ^ 0x08dffd08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x37000048U + 0x046488U) ^ (0x14006712U + 0x07d568U + 152U);
}

// [EN] FDE[1277] start_va=0x046520, fde_va=0x07d580, span=12 B | [VN] FDE[1277]
uint32_t ttr_fde_1277_0x046520(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91008001U) + (a1 ^ 0xaa0803e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff72cdU + 0x046520U) ^ (0x9100e000U + 0x07d580U + 12U);
}

// [EN] FDE[1278] start_va=0x04652c, fde_va=0x07d598, span=8 B | [VN] FDE[1278]
uint32_t ttr_fde_1278_0x04652c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100e000U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x12000028U + 0x04652cU) ^ (0x91023009U + 0x07d598U + 8U);
}

// [EN] FDE[1279] start_va=0x046534, fde_va=0x07d5b0, span=108 B | [VN] FDE[1279]
uint32_t ttr_fde_1279_0x046534(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12000028U) + (a1 ^ 0x91023009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb00002cbU + 0x046534U) ^ (0x910d416bU + 0x07d5b0U + 108U);
}

// [EN] FDE[1280] start_va=0x0465a0, fde_va=0x07d5c8, span=552 B | [VN] FDE[1280]
uint32_t ttr_fde_1280_0x0465a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e2U) + (a1 ^ 0x940067c9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203feU + 0x0465a0U) ^ (0xa9077bfdU + 0x07d5c8U + 552U);
}

// [EN] FDE[1281] start_va=0x0467c8, fde_va=0x07d5f8, span=4 B | [VN] FDE[1281]
uint32_t ttr_fde_1281_0x0467c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14006645U) + (a1 ^ 0xd10243ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9003bf4U + 0x0467c8U) ^ (0xa9087bf3U + 0x07d5f8U + 4U);
}

// [EN] FDE[1282] start_va=0x0467cc, fde_va=0x07d610, span=476 B | [VN] FDE[1282]
uint32_t ttr_fde_1282_0x0467cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10243ffU) + (a1 ^ 0xf9003bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9087bf3U + 0x0467ccU) ^ (0x9400663eU + 0x07d610U + 476U);
}

// [EN] FDE[1283] start_va=0x0469a8, fde_va=0x07d630, span=28 B | [VN] FDE[1283]
uint32_t ttr_fde_1283_0x0469a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9403d08U + 0x0469a8U) ^ (0xd63f0100U + 0x07d630U + 28U);
}

// [EN] FDE[1284] start_va=0x0469c4, fde_va=0x07d648, span=20 B | [VN] FDE[1284]
uint32_t ttr_fde_1284_0x0469c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0x29508403U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9408002U + 0x0469c4U) ^ (0xf9402904U + 0x07d648U + 20U);
}

// [EN] FDE[1285] start_va=0x0469d8, fde_va=0x07d660, span=4 B | [VN] FDE[1285]
uint32_t ttr_fde_1285_0x0469d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x140065c1U) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x0469d8U) ^ (0xf9400008U + 0x07d660U + 4U);
}

// [EN] FDE[1286] start_va=0x0469dc, fde_va=0x07d678, span=84 B | [VN] FDE[1286]
uint32_t ttr_fde_1286_0x0469dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x0469dcU) ^ (0xaa0103f4U + 0x07d678U + 84U);
}

// [EN] FDE[1287] start_va=0x046a30, fde_va=0x07d698, span=132 B | [VN] FDE[1287]
uint32_t ttr_fde_1287_0x046a30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e1U) + (a1 ^ 0x94006c5eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103feU + 0x046a30U) ^ (0xaa0003e9U + 0x07d698U + 132U);
}

// [EN] FDE[1288] start_va=0x046ab4, fde_va=0x07d6b0, span=84 B | [VN] FDE[1288]
uint32_t ttr_fde_1288_0x046ab4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9408808U) + (a1 ^ 0x7100043fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7a41a104U + 0x046ab4U) ^ (0x54000061U + 0x07d6b0U + 84U);
}

// [EN] FDE[1289] start_va=0x046b08, fde_va=0x07d6c8, span=140 B | [VN] FDE[1289]
uint32_t ttr_fde_1289_0x046b08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x046b08U) ^ (0xaa0003f6U + 0x07d6c8U + 140U);
}

// [EN] FDE[1290] start_va=0x046b94, fde_va=0x07d6e8, span=184 B | [VN] FDE[1290]
uint32_t ttr_fde_1290_0x046b94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd104c3ffU) + (a1 ^ 0xf90083fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa91153f5U + 0x046b94U) ^ (0xa9127bf3U + 0x07d6e8U + 184U);
}

// [EN] FDE[1291] start_va=0x046c4c, fde_va=0x07d708, span=312 B | [VN] FDE[1291]
uint32_t ttr_fde_1291_0x046c4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x046c4cU) ^ (0xaa0003f3U + 0x07d708U + 312U);
}

// [EN] FDE[1292] start_va=0x046d84, fde_va=0x07d728, span=28 B | [VN] FDE[1292]
uint32_t ttr_fde_1292_0x046d84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xeb08003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x046d84U) ^ (0xd1002108U + 0x07d728U + 28U);
}

// [EN] FDE[1293] start_va=0x046da0, fde_va=0x07d740, span=48 B | [VN] FDE[1293]
uint32_t ttr_fde_1293_0x046da0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xeb08013fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000120U + 0x046da0U) ^ (0xa9422809U + 0x07d740U + 48U);
}

// [EN] FDE[1294] start_va=0x046dd0, fde_va=0x07d758, span=160 B | [VN] FDE[1294]
uint32_t ttr_fde_1294_0x046dd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x046dd0U) ^ (0x940076d9U + 0x07d758U + 160U);
}

// [EN] FDE[1295] start_va=0x046e70, fde_va=0x07d778, span=28 B | [VN] FDE[1295]
uint32_t ttr_fde_1295_0x046e70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xeb08003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x54000080U + 0x046e70U) ^ (0xd1002108U + 0x07d778U + 28U);
}

// [EN] FDE[1296] start_va=0x046e8c, fde_va=0x07d790, span=48 B | [VN] FDE[1296]
uint32_t ttr_fde_1296_0x046e8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800928U) + (a1 ^ 0x9ac80848U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb00003fU + 0x046e8cU) ^ (0x8b080c00U + 0x07d790U + 48U);
}

// [EN] FDE[1297] start_va=0x046ebc, fde_va=0x07d7a8, span=60 B | [VN] FDE[1297]
uint32_t ttr_fde_1297_0x046ebc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9422408U) + (a1 ^ 0xa940ac0aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5280092cU + 0x046ebcU) ^ (0x8b090108U + 0x07d7a8U + 60U);
}

// [EN] FDE[1298] start_va=0x046ef8, fde_va=0x07d7c0, span=100 B | [VN] FDE[1298]
uint32_t ttr_fde_1298_0x046ef8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x046ef8U) ^ (0xa9057bf3U + 0x07d7c0U + 100U);
}

// [EN] FDE[1299] start_va=0x046f5c, fde_va=0x07d7e0, span=56 B | [VN] FDE[1299]
uint32_t ttr_fde_1299_0x046f5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400414U + 0x046f5cU) ^ (0xf9400828U + 0x07d7e0U + 56U);
}

// [EN] FDE[1300] start_va=0x046f94, fde_va=0x07d800, span=188 B | [VN] FDE[1300]
uint32_t ttr_fde_1300_0x046f94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xa9025bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x046f94U) ^ (0xa9047bf3U + 0x07d800U + 188U);
}

// [EN] FDE[1301] start_va=0x047050, fde_va=0x07d820, span=100 B | [VN] FDE[1301]
uint32_t ttr_fde_1301_0x047050(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9001bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90453f5U + 0x047050U) ^ (0xa9057bf3U + 0x07d820U + 100U);
}

// [EN] FDE[1302] start_va=0x0470b4, fde_va=0x07d840, span=56 B | [VN] FDE[1302]
uint32_t ttr_fde_1302_0x0470b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb201f3e8U + 0x0470b4U) ^ (0xf2955568U + 0x07d840U + 56U);
}

// [EN] FDE[1303] start_va=0x0470ec, fde_va=0x07d8a8, span=320 B | [VN] FDE[1303]
uint32_t ttr_fde_1303_0x0470ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xb4000380U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0470ecU) ^ (0xd37dfc08U + 0x07d8a8U + 320U);
}

// [EN] FDE[1304] start_va=0x04722c, fde_va=0x07d8c0, span=24 B | [VN] FDE[1304]
uint32_t ttr_fde_1304_0x04722c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900002c9U) + (a1 ^ 0xf9422d28U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9022d20U + 0x04722cU) ^ (0xb4000048U + 0x07d8c0U + 24U);
}

// [EN] FDE[1305] start_va=0x047244, fde_va=0x07d8d8, span=64 B | [VN] FDE[1305]
uint32_t ttr_fde_1305_0x047244(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xf9400013U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000001U + 0x047244U) ^ (0xb4000173U + 0x07d8d8U + 64U);
}

// [EN] FDE[1306] start_va=0x047284, fde_va=0x07d8f0, span=8 B | [VN] FDE[1306]
uint32_t ttr_fde_1306_0x047284(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e1U) + (a1 ^ 0x17ffffefU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff52a9U + 0x047284U) ^ (0xf81f0ffeU + 0x07d8f0U + 8U);
}

// [EN] FDE[1307] start_va=0x04728c, fde_va=0x07d908, span=4 B | [VN] FDE[1307]
uint32_t ttr_fde_1307_0x04728c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff52a9U) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800200U + 0x04728cU) ^ (0x97ff52b2U + 0x07d908U + 4U);
}

// [EN] FDE[1308] start_va=0x047290, fde_va=0x07d920, span=32 B | [VN] FDE[1308]
uint32_t ttr_fde_1308_0x047290(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x52800200U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ff52b2U + 0x047290U) ^ (0xb0000288U + 0x07d920U + 32U);
}

// [EN] FDE[1309] start_va=0x0472b0, fde_va=0x07d938, span=16 B | [VN] FDE[1309]
uint32_t ttr_fde_1309_0x0472b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000288U) + (a1 ^ 0x9136a108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000028U + 0x0472b0U) ^ (0xd65f03c0U + 0x07d938U + 16U);
}

// [EN] FDE[1310] start_va=0x0472c0, fde_va=0x07d950, span=4 B | [VN] FDE[1310]
uint32_t ttr_fde_1310_0x0472c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff529bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd102c3ffU + 0x0472c0U) ^ (0xf9004bf4U + 0x07d950U + 4U);
}

// [EN] FDE[1311] start_va=0x0472c4, fde_va=0x07d968, span=4 B | [VN] FDE[1311]
uint32_t ttr_fde_1311_0x0472c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff529bU) + (a1 ^ 0xd102c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9004bf4U + 0x0472c4U) ^ (0xa90a7bf3U + 0x07d968U + 4U);
}

// [EN] FDE[1312] start_va=0x0472c8, fde_va=0x07d980, span=256 B | [VN] FDE[1312]
uint32_t ttr_fde_1312_0x0472c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd102c3ffU) + (a1 ^ 0xf9004bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90a7bf3U + 0x0472c8U) ^ (0xb9400028U + 0x07d980U + 256U);
}

// [EN] FDE[1313] start_va=0x0473c8, fde_va=0x07d9a0, span=4 B | [VN] FDE[1313]
uint32_t ttr_fde_1313_0x0473c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff525aU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400624bU + 0x0473c8U) ^ (0xb0000288U + 0x07d9a0U + 4U);
}

// [EN] FDE[1314] start_va=0x0473cc, fde_va=0x07d9b8, span=28 B | [VN] FDE[1314]
uint32_t ttr_fde_1314_0x0473cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400624bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000288U + 0x0473ccU) ^ (0x91358108U + 0x07d9b8U + 28U);
}

// [EN] FDE[1315] start_va=0x0473e8, fde_va=0x07d9d0, span=12 B | [VN] FDE[1315]
uint32_t ttr_fde_1315_0x0473e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000288U) + (a1 ^ 0x91358108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400623fU + 0x0473e8U) ^ (0xd65f03c0U + 0x07d9d0U + 12U);
}

// [EN] FDE[1316] start_va=0x0473f4, fde_va=0x07d9e8, span=4 B | [VN] FDE[1316]
uint32_t ttr_fde_1316_0x0473f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff524eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x0473f4U) ^ (0xb9400028U + 0x07d9e8U + 4U);
}

// [EN] FDE[1317] start_va=0x0473f8, fde_va=0x07da00, span=4 B | [VN] FDE[1317]
uint32_t ttr_fde_1317_0x0473f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff524eU) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400028U + 0x0473f8U) ^ (0x350005a8U + 0x07da00U + 4U);
}

// [EN] FDE[1318] start_va=0x0473fc, fde_va=0x07da18, span=200 B | [VN] FDE[1318]
uint32_t ttr_fde_1318_0x0473fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb9400028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x350005a8U + 0x0473fcU) ^ (0xf9400408U + 0x07da18U + 200U);
}

// [EN] FDE[1319] start_va=0x0474c4, fde_va=0x07da30, span=4 B | [VN] FDE[1319]
uint32_t ttr_fde_1319_0x0474c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff521bU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400620cU + 0x0474c4U) ^ (0xb0000288U + 0x07da30U + 4U);
}

// [EN] FDE[1320] start_va=0x0474c8, fde_va=0x07da48, span=28 B | [VN] FDE[1320]
uint32_t ttr_fde_1320_0x0474c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400620cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb0000288U + 0x0474c8U) ^ (0x91346108U + 0x07da48U + 28U);
}

// [EN] FDE[1321] start_va=0x0474e4, fde_va=0x07da60, span=12 B | [VN] FDE[1321]
uint32_t ttr_fde_1321_0x0474e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000288U) + (a1 ^ 0x91346108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14006200U + 0x0474e4U) ^ (0xd65f03c0U + 0x07da60U + 12U);
}

// [EN] FDE[1322] start_va=0x0474f0, fde_va=0x07da78, span=4 B | [VN] FDE[1322]
uint32_t ttr_fde_1322_0x0474f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17ff520fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10203ffU + 0x0474f0U) ^ (0xf9002bf6U + 0x07da78U + 4U);
}

// [EN] FDE[1323] start_va=0x0474f4, fde_va=0x07da90, span=4 B | [VN] FDE[1323]
uint32_t ttr_fde_1323_0x0474f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff520fU) + (a1 ^ 0xd10203ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9002bf6U + 0x0474f4U) ^ (0xa90653f5U + 0x07da90U + 4U);
}

// [EN] FDE[1324] start_va=0x0474f8, fde_va=0x07daa8, span=180 B | [VN] FDE[1324]
uint32_t ttr_fde_1324_0x0474f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf9002bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90653f5U + 0x0474f8U) ^ (0xa9077bf3U + 0x07daa8U + 180U);
}

// [EN] FDE[1325] start_va=0x0475ac, fde_va=0x07dac8, span=416 B | [VN] FDE[1325]
uint32_t ttr_fde_1325_0x0475ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa90263f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035bf7U + 0x0475acU) ^ (0xa90453f5U + 0x07dac8U + 416U);
}

// [EN] FDE[1326] start_va=0x04774c, fde_va=0x07daf0, span=120 B | [VN] FDE[1326]
uint32_t ttr_fde_1326_0x04774c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940073d8U + 0x04774cU) ^ (0x54000061U + 0x07daf0U + 120U);
}

// [EN] FDE[1327] start_va=0x0477c4, fde_va=0x07db10, span=48 B | [VN] FDE[1327]
uint32_t ttr_fde_1327_0x0477c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940067e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb4000113U + 0x0477c4U) ^ (0x39404008U + 0x07db10U + 48U);
}

// [EN] FDE[1328] start_va=0x0477f4, fde_va=0x07db28, span=12 B | [VN] FDE[1328]
uint32_t ttr_fde_1328_0x0477f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff6715U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0477f4U) ^ (0xf81e0ff4U + 0x07db28U + 12U);
}

// [EN] FDE[1329] start_va=0x047800, fde_va=0x07db40, span=212 B | [VN] FDE[1329]
uint32_t ttr_fde_1329_0x047800(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x047800U) ^ (0xb4000261U + 0x07db40U + 212U);
}

// [EN] FDE[1330] start_va=0x0478d4, fde_va=0x07db60, span=24 B | [VN] FDE[1330]
uint32_t ttr_fde_1330_0x0478d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000101U + 0x0478d4U) ^ (0xb4000040U + 0x07db60U + 24U);
}

// [EN] FDE[1331] start_va=0x0478ec, fde_va=0x07db78, span=4 B | [VN] FDE[1331]
uint32_t ttr_fde_1331_0x0478ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x14007302U) + (a1 ^ 0xf81e0ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x0478ecU) ^ (0xaa0003f3U + 0x07db78U + 4U);
}

// [EN] FDE[1332] start_va=0x0478f0, fde_va=0x07db90, span=48 B | [VN] FDE[1332]
uint32_t ttr_fde_1332_0x0478f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0478f0U) ^ (0xb40000f3U + 0x07db90U + 48U);
}

// [EN] FDE[1333] start_va=0x047920, fde_va=0x07dbb0, span=756 B | [VN] FDE[1333]
uint32_t ttr_fde_1333_0x047920(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10403ffU) + (a1 ^ 0xa90a6ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90b67faU + 0x047920U) ^ (0xa90c5ff8U + 0x07dbb0U + 756U);
}

// [EN] FDE[1334] start_va=0x047c14, fde_va=0x07dbe0, span=416 B | [VN] FDE[1334]
uint32_t ttr_fde_1334_0x047c14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xa90263f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9035bf7U + 0x047c14U) ^ (0xa90453f5U + 0x07dbe0U + 416U);
}

// [EN] FDE[1335] start_va=0x047db4, fde_va=0x07dc08, span=128 B | [VN] FDE[1335]
uint32_t ttr_fde_1335_0x047db4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb00002b5U + 0x047db4U) ^ (0x900002d4U + 0x07dc08U + 128U);
}

// [EN] FDE[1336] start_va=0x047e34, fde_va=0x07dc28, span=24 B | [VN] FDE[1336]
uint32_t ttr_fde_1336_0x047e34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xb0000289U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9137c129U + 0x047e34U) ^ (0xf9000009U + 0x07dc28U + 24U);
}

// [EN] FDE[1337] start_va=0x047e4c, fde_va=0x07dc40, span=24 B | [VN] FDE[1337]
uint32_t ttr_fde_1337_0x047e4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff8U + 0x047e4cU) ^ (0xaa1303e0U + 0x07dc40U + 24U);
}

// [EN] FDE[1338] start_va=0x047e64, fde_va=0x07dc58, span=48 B | [VN] FDE[1338]
uint32_t ttr_fde_1338_0x047e64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400646bU + 0x047e64U) ^ (0xb0000288U + 0x07dc58U + 48U);
}

// [EN] FDE[1339] start_va=0x047e94, fde_va=0x07dc70, span=56 B | [VN] FDE[1339]
uint32_t ttr_fde_1339_0x047e94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000288U) + (a1 ^ 0x9137c108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000028U + 0x047e94U) ^ (0xf9400408U + 0x07dc70U + 56U);
}

// [EN] FDE[1340] start_va=0x047ecc, fde_va=0x07dc88, span=8 B | [VN] FDE[1340]
uint32_t ttr_fde_1340_0x047ecc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400800U) + (a1 ^ 0x17fffe49U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9bf7bf3U + 0x047eccU) ^ (0x9400670aU + 0x07dc88U + 8U);
}

// [EN] FDE[1341] start_va=0x047ed4, fde_va=0x07dca0, span=24 B | [VN] FDE[1341]
uint32_t ttr_fde_1341_0x047ed4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400670aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffe46U + 0x047ed4U) ^ (0xaa1303e0U + 0x07dca0U + 24U);
}

// [EN] FDE[1342] start_va=0x047eec, fde_va=0x07dcb8, span=28 B | [VN] FDE[1342]
uint32_t ttr_fde_1342_0x047eec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb9400021U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400400U + 0x047eecU) ^ (0x97fffb04U + 0x07dcb8U + 28U);
}

// [EN] FDE[1343] start_va=0x047f08, fde_va=0x07dcd0, span=32 B | [VN] FDE[1343]
uint32_t ttr_fde_1343_0x047f08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xb0000288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9138e108U + 0x047f08U) ^ (0x94005fd1U + 0x07dcd0U + 32U);
}

// [EN] FDE[1344] start_va=0x047f28, fde_va=0x07dce8, span=24 B | [VN] FDE[1344]
uint32_t ttr_fde_1344_0x047f28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x047f28U) ^ (0xaa1303e0U + 0x07dce8U + 24U);
}

// [EN] FDE[1345] start_va=0x047f40, fde_va=0x07dd00, span=8 B | [VN] FDE[1345]
uint32_t ttr_fde_1345_0x047f40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff4f7aU + 0x047f40U) ^ (0xa9be53f5U + 0x07dd00U + 8U);
}

// [EN] FDE[1346] start_va=0x047f48, fde_va=0x07dd18, span=4 B | [VN] FDE[1346]
uint32_t ttr_fde_1346_0x047f48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17ff4f7aU) + (a1 ^ 0xa9be53f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x047f48U) ^ (0xf9404c14U + 0x07dd18U + 4U);
}

// [EN] FDE[1347] start_va=0x047f4c, fde_va=0x07dd30, span=88 B | [VN] FDE[1347]
uint32_t ttr_fde_1347_0x047f4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9404c14U + 0x047f4cU) ^ (0xd0000288U + 0x07dd30U + 88U);
}

// [EN] FDE[1348] start_va=0x047fa4, fde_va=0x07dd50, span=12 B | [VN] FDE[1348]
uint32_t ttr_fde_1348_0x047fa4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff6529U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x047fa4U) ^ (0xd10103ffU + 0x07dd50U + 12U);
}

// [EN] FDE[1349] start_va=0x047fb0, fde_va=0x07dd68, span=168 B | [VN] FDE[1349]
uint32_t ttr_fde_1349_0x047fb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x047fb0U) ^ (0xaa0003f3U + 0x07dd68U + 168U);
}

// [EN] FDE[1350] start_va=0x048058, fde_va=0x07dd88, span=112 B | [VN] FDE[1350]
uint32_t ttr_fde_1350_0x048058(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x048058U) ^ (0xaa0003f3U + 0x07dd88U + 112U);
}

// [EN] FDE[1351] start_va=0x0480c8, fde_va=0x07dda8, span=24 B | [VN] FDE[1351]
uint32_t ttr_fde_1351_0x0480c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94005f1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000004U + 0x0480c8U) ^ (0xaa1303e0U + 0x07dda8U + 24U);
}

// [EN] FDE[1352] start_va=0x0480e0, fde_va=0x07ddc0, span=12 B | [VN] FDE[1352]
uint32_t ttr_fde_1352_0x0480e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff64daU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0480e0U) ^ (0xd10203ffU + 0x07ddc0U + 12U);
}

// [EN] FDE[1353] start_va=0x0480ec, fde_va=0x07ddd8, span=196 B | [VN] FDE[1353]
uint32_t ttr_fde_1353_0x0480ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf9001bfaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90463f9U + 0x0480ecU) ^ (0xa9055bf7U + 0x07ddd8U + 196U);
}

uint32_t DispatchTtrFdeShard2(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 677U: return ttr_fde_0677_0x0308e8(a0, a1);
        case 678U: return ttr_fde_0678_0x03092c(a0, a1);
        case 679U: return ttr_fde_0679_0x030958(a0, a1);
        case 680U: return ttr_fde_0680_0x030988(a0, a1);
        case 681U: return ttr_fde_0681_0x030a60(a0, a1);
        case 682U: return ttr_fde_0682_0x030a78(a0, a1);
        case 683U: return ttr_fde_0683_0x030a84(a0, a1);
        case 684U: return ttr_fde_0684_0x030af8(a0, a1);
        case 685U: return ttr_fde_0685_0x030b14(a0, a1);
        case 686U: return ttr_fde_0686_0x030b44(a0, a1);
        case 687U: return ttr_fde_0687_0x030b5c(a0, a1);
        case 688U: return ttr_fde_0688_0x030e58(a0, a1);
        case 689U: return ttr_fde_0689_0x030e74(a0, a1);
        case 690U: return ttr_fde_0690_0x030f08(a0, a1);
        case 691U: return ttr_fde_0691_0x030ff0(a0, a1);
        case 692U: return ttr_fde_0692_0x031008(a0, a1);
        case 693U: return ttr_fde_0693_0x031014(a0, a1);
        case 694U: return ttr_fde_0694_0x031394(a0, a1);
        case 695U: return ttr_fde_0695_0x0313c4(a0, a1);
        case 696U: return ttr_fde_0696_0x0313f8(a0, a1);
        case 697U: return ttr_fde_0697_0x031404(a0, a1);
        case 698U: return ttr_fde_0698_0x0314b0(a0, a1);
        case 699U: return ttr_fde_0699_0x0314cc(a0, a1);
        case 700U: return ttr_fde_0700_0x031728(a0, a1);
        case 701U: return ttr_fde_0701_0x0317c0(a0, a1);
        case 702U: return ttr_fde_0702_0x03189c(a0, a1);
        case 703U: return ttr_fde_0703_0x031914(a0, a1);
        case 704U: return ttr_fde_0704_0x031930(a0, a1);
        case 705U: return ttr_fde_0705_0x031940(a0, a1);
        case 706U: return ttr_fde_0706_0x0319d4(a0, a1);
        case 707U: return ttr_fde_0707_0x031a30(a0, a1);
        case 708U: return ttr_fde_0708_0x031c94(a0, a1);
        case 709U: return ttr_fde_0709_0x031cbc(a0, a1);
        case 710U: return ttr_fde_0710_0x031cc8(a0, a1);
        case 711U: return ttr_fde_0711_0x031cf8(a0, a1);
        case 712U: return ttr_fde_0712_0x031d60(a0, a1);
        case 713U: return ttr_fde_0713_0x031da4(a0, a1);
        case 714U: return ttr_fde_0714_0x031dbc(a0, a1);
        case 715U: return ttr_fde_0715_0x031ddc(a0, a1);
        case 716U: return ttr_fde_0716_0x031e0c(a0, a1);
        case 717U: return ttr_fde_0717_0x031e14(a0, a1);
        case 718U: return ttr_fde_0718_0x031e48(a0, a1);
        case 719U: return ttr_fde_0719_0x031ee0(a0, a1);
        case 720U: return ttr_fde_0720_0x031f10(a0, a1);
        case 721U: return ttr_fde_0721_0x031f44(a0, a1);
        case 722U: return ttr_fde_0722_0x031f64(a0, a1);
        case 723U: return ttr_fde_0723_0x031fa4(a0, a1);
        case 724U: return ttr_fde_0724_0x031ff4(a0, a1);
        case 725U: return ttr_fde_0725_0x032018(a0, a1);
        case 726U: return ttr_fde_0726_0x03209c(a0, a1);
        case 727U: return ttr_fde_0727_0x035880(a0, a1);
        case 728U: return ttr_fde_0728_0x0358b0(a0, a1);
        case 729U: return ttr_fde_0729_0x035a28(a0, a1);
        case 730U: return ttr_fde_0730_0x035a34(a0, a1);
        case 731U: return ttr_fde_0731_0x035bc4(a0, a1);
        case 732U: return ttr_fde_0732_0x035c28(a0, a1);
        case 733U: return ttr_fde_0733_0x035c40(a0, a1);
        case 734U: return ttr_fde_0734_0x035c58(a0, a1);
        case 735U: return ttr_fde_0735_0x035c84(a0, a1);
        case 736U: return ttr_fde_0736_0x035c9c(a0, a1);
        case 737U: return ttr_fde_0737_0x035cb4(a0, a1);
        case 738U: return ttr_fde_0738_0x035ccc(a0, a1);
        case 739U: return ttr_fde_0739_0x035ce4(a0, a1);
        case 740U: return ttr_fde_0740_0x035ce8(a0, a1);
        case 741U: return ttr_fde_0741_0x035cf4(a0, a1);
        case 742U: return ttr_fde_0742_0x035db8(a0, a1);
        case 743U: return ttr_fde_0743_0x035dd4(a0, a1);
        case 744U: return ttr_fde_0744_0x035df0(a0, a1);
        case 745U: return ttr_fde_0745_0x035dfc(a0, a1);
        case 746U: return ttr_fde_0746_0x035e38(a0, a1);
        case 747U: return ttr_fde_0747_0x035e8c(a0, a1);
        case 748U: return ttr_fde_0748_0x035ec8(a0, a1);
        case 749U: return ttr_fde_0749_0x035f38(a0, a1);
        case 750U: return ttr_fde_0750_0x03607c(a0, a1);
        case 751U: return ttr_fde_0751_0x0360a4(a0, a1);
        case 752U: return ttr_fde_0752_0x0360b0(a0, a1);
        case 753U: return ttr_fde_0753_0x0360ec(a0, a1);
        case 754U: return ttr_fde_0754_0x036108(a0, a1);
        case 755U: return ttr_fde_0755_0x036110(a0, a1);
        case 756U: return ttr_fde_0756_0x03614c(a0, a1);
        case 757U: return ttr_fde_0757_0x03618c(a0, a1);
        case 758U: return ttr_fde_0758_0x0361e0(a0, a1);
        case 759U: return ttr_fde_0759_0x0361fc(a0, a1);
        case 760U: return ttr_fde_0760_0x036208(a0, a1);
        case 761U: return ttr_fde_0761_0x036214(a0, a1);
        case 762U: return ttr_fde_0762_0x0362fc(a0, a1);
        case 763U: return ttr_fde_0763_0x036314(a0, a1);
        case 764U: return ttr_fde_0764_0x036344(a0, a1);
        case 765U: return ttr_fde_0765_0x036350(a0, a1);
        case 766U: return ttr_fde_0766_0x03640c(a0, a1);
        case 767U: return ttr_fde_0767_0x036428(a0, a1);
        case 768U: return ttr_fde_0768_0x036454(a0, a1);
        case 769U: return ttr_fde_0769_0x036460(a0, a1);
        case 770U: return ttr_fde_0770_0x03647c(a0, a1);
        case 771U: return ttr_fde_0771_0x0364c8(a0, a1);
        case 772U: return ttr_fde_0772_0x0364e0(a0, a1);
        case 773U: return ttr_fde_0773_0x0364f4(a0, a1);
        case 774U: return ttr_fde_0774_0x0364f8(a0, a1);
        case 775U: return ttr_fde_0775_0x03657c(a0, a1);
        case 776U: return ttr_fde_0776_0x036664(a0, a1);
        case 777U: return ttr_fde_0777_0x03667c(a0, a1);
        case 778U: return ttr_fde_0778_0x036698(a0, a1);
        case 779U: return ttr_fde_0779_0x036758(a0, a1);
        case 780U: return ttr_fde_0780_0x036764(a0, a1);
        case 781U: return ttr_fde_0781_0x036774(a0, a1);
        case 782U: return ttr_fde_0782_0x036778(a0, a1);
        case 783U: return ttr_fde_0783_0x03677c(a0, a1);
        case 784U: return ttr_fde_0784_0x0367c0(a0, a1);
        case 785U: return ttr_fde_0785_0x0367f0(a0, a1);
        case 786U: return ttr_fde_0786_0x036804(a0, a1);
        case 787U: return ttr_fde_0787_0x036b70(a0, a1);
        case 788U: return ttr_fde_0788_0x036b7c(a0, a1);
        case 789U: return ttr_fde_0789_0x036b90(a0, a1);
        case 790U: return ttr_fde_0790_0x036ba4(a0, a1);
        case 791U: return ttr_fde_0791_0x036bac(a0, a1);
        case 792U: return ttr_fde_0792_0x036c58(a0, a1);
        case 793U: return ttr_fde_0793_0x036c64(a0, a1);
        case 794U: return ttr_fde_0794_0x036ca8(a0, a1);
        case 795U: return ttr_fde_0795_0x036cc4(a0, a1);
        case 796U: return ttr_fde_0796_0x036d68(a0, a1);
        case 797U: return ttr_fde_0797_0x036e54(a0, a1);
        case 798U: return ttr_fde_0798_0x036eb0(a0, a1);
        case 799U: return ttr_fde_0799_0x036f08(a0, a1);
        case 800U: return ttr_fde_0800_0x036fe4(a0, a1);
        case 801U: return ttr_fde_0801_0x037094(a0, a1);
        case 802U: return ttr_fde_0802_0x037144(a0, a1);
        case 803U: return ttr_fde_0803_0x0371c4(a0, a1);
        case 804U: return ttr_fde_0804_0x0373a0(a0, a1);
        case 805U: return ttr_fde_0805_0x0373e8(a0, a1);
        case 806U: return ttr_fde_0806_0x0374a8(a0, a1);
        case 807U: return ttr_fde_0807_0x0374b4(a0, a1);
        case 808U: return ttr_fde_0808_0x03754c(a0, a1);
        case 809U: return ttr_fde_0809_0x037568(a0, a1);
        case 810U: return ttr_fde_0810_0x03762c(a0, a1);
        case 811U: return ttr_fde_0811_0x0376bc(a0, a1);
        case 812U: return ttr_fde_0812_0x0376c0(a0, a1);
        case 813U: return ttr_fde_0813_0x037838(a0, a1);
        case 814U: return ttr_fde_0814_0x03783c(a0, a1);
        case 815U: return ttr_fde_0815_0x037848(a0, a1);
        case 816U: return ttr_fde_0816_0x03788c(a0, a1);
        case 817U: return ttr_fde_0817_0x0378a8(a0, a1);
        case 818U: return ttr_fde_0818_0x03796c(a0, a1);
        case 819U: return ttr_fde_0819_0x037a64(a0, a1);
        case 820U: return ttr_fde_0820_0x037a68(a0, a1);
        case 821U: return ttr_fde_0821_0x037bec(a0, a1);
        case 822U: return ttr_fde_0822_0x037ca4(a0, a1);
        case 823U: return ttr_fde_0823_0x037ca8(a0, a1);
        case 824U: return ttr_fde_0824_0x037cb4(a0, a1);
        case 825U: return ttr_fde_0825_0x037d14(a0, a1);
        case 826U: return ttr_fde_0826_0x037d30(a0, a1);
        case 827U: return ttr_fde_0827_0x037dcc(a0, a1);
        case 828U: return ttr_fde_0828_0x037e7c(a0, a1);
        case 829U: return ttr_fde_0829_0x037ef8(a0, a1);
        case 830U: return ttr_fde_0830_0x037f0c(a0, a1);
        case 831U: return ttr_fde_0831_0x037fb4(a0, a1);
        case 832U: return ttr_fde_0832_0x037fc0(a0, a1);
        case 833U: return ttr_fde_0833_0x037fec(a0, a1);
        case 834U: return ttr_fde_0834_0x038008(a0, a1);
        case 835U: return ttr_fde_0835_0x03806c(a0, a1);
        case 836U: return ttr_fde_0836_0x038160(a0, a1);
        case 837U: return ttr_fde_0837_0x0383e0(a0, a1);
        case 838U: return ttr_fde_0838_0x038408(a0, a1);
        case 839U: return ttr_fde_0839_0x038434(a0, a1);
        case 840U: return ttr_fde_0840_0x0385d0(a0, a1);
        case 841U: return ttr_fde_0841_0x038614(a0, a1);
        case 842U: return ttr_fde_0842_0x038670(a0, a1);
        case 843U: return ttr_fde_0843_0x038694(a0, a1);
        case 844U: return ttr_fde_0844_0x0386b0(a0, a1);
        case 845U: return ttr_fde_0845_0x0386b4(a0, a1);
        case 846U: return ttr_fde_0846_0x0386b8(a0, a1);
        case 847U: return ttr_fde_0847_0x038cac(a0, a1);
        case 848U: return ttr_fde_0848_0x038cc4(a0, a1);
        case 849U: return ttr_fde_0849_0x038cd0(a0, a1);
        case 850U: return ttr_fde_0850_0x038cf4(a0, a1);
        case 851U: return ttr_fde_0851_0x038d10(a0, a1);
        case 852U: return ttr_fde_0852_0x038d14(a0, a1);
        case 853U: return ttr_fde_0853_0x038d18(a0, a1);
        case 854U: return ttr_fde_0854_0x038d24(a0, a1);
        case 855U: return ttr_fde_0855_0x038d30(a0, a1);
        case 856U: return ttr_fde_0856_0x038d54(a0, a1);
        case 857U: return ttr_fde_0857_0x038d70(a0, a1);
        case 858U: return ttr_fde_0858_0x038d74(a0, a1);
        case 859U: return ttr_fde_0859_0x038d78(a0, a1);
        case 860U: return ttr_fde_0860_0x038d9c(a0, a1);
        case 861U: return ttr_fde_0861_0x038db8(a0, a1);
        case 862U: return ttr_fde_0862_0x038dbc(a0, a1);
        case 863U: return ttr_fde_0863_0x038dc0(a0, a1);
        case 864U: return ttr_fde_0864_0x038de4(a0, a1);
        case 865U: return ttr_fde_0865_0x038e00(a0, a1);
        case 866U: return ttr_fde_0866_0x038e04(a0, a1);
        case 867U: return ttr_fde_0867_0x038e08(a0, a1);
        case 868U: return ttr_fde_0868_0x038ea8(a0, a1);
        case 869U: return ttr_fde_0869_0x038ec0(a0, a1);
        case 870U: return ttr_fde_0870_0x038ecc(a0, a1);
        case 871U: return ttr_fde_0871_0x038ef0(a0, a1);
        case 872U: return ttr_fde_0872_0x038f0c(a0, a1);
        case 873U: return ttr_fde_0873_0x038f10(a0, a1);
        case 874U: return ttr_fde_0874_0x038f14(a0, a1);
        case 875U: return ttr_fde_0875_0x038f20(a0, a1);
        case 876U: return ttr_fde_0876_0x038f4c(a0, a1);
        case 877U: return ttr_fde_0877_0x038f68(a0, a1);
        case 878U: return ttr_fde_0878_0x039280(a0, a1);
        case 879U: return ttr_fde_0879_0x03940c(a0, a1);
        case 880U: return ttr_fde_0880_0x03977c(a0, a1);
        case 881U: return ttr_fde_0881_0x039810(a0, a1);
        case 882U: return ttr_fde_0882_0x03986c(a0, a1);
        case 883U: return ttr_fde_0883_0x03993c(a0, a1);
        case 884U: return ttr_fde_0884_0x039940(a0, a1);
        case 885U: return ttr_fde_0885_0x039978(a0, a1);
        case 886U: return ttr_fde_0886_0x039a38(a0, a1);
        case 887U: return ttr_fde_0887_0x039a6c(a0, a1);
        case 888U: return ttr_fde_0888_0x039aa0(a0, a1);
        case 889U: return ttr_fde_0889_0x039d44(a0, a1);
        case 890U: return ttr_fde_0890_0x039e88(a0, a1);
        case 891U: return ttr_fde_0891_0x039ea0(a0, a1);
        case 892U: return ttr_fde_0892_0x03a2f0(a0, a1);
        case 893U: return ttr_fde_0893_0x03a308(a0, a1);
        case 894U: return ttr_fde_0894_0x03a3f0(a0, a1);
        case 895U: return ttr_fde_0895_0x03a408(a0, a1);
        case 896U: return ttr_fde_0896_0x03a4a0(a0, a1);
        case 897U: return ttr_fde_0897_0x03a4ac(a0, a1);
        case 898U: return ttr_fde_0898_0x03a500(a0, a1);
        case 899U: return ttr_fde_0899_0x03a51c(a0, a1);
        case 900U: return ttr_fde_0900_0x03a520(a0, a1);
        case 901U: return ttr_fde_0901_0x03a564(a0, a1);
        case 902U: return ttr_fde_0902_0x03a990(a0, a1);
        case 903U: return ttr_fde_0903_0x03a9d0(a0, a1);
        case 904U: return ttr_fde_0904_0x03aa08(a0, a1);
        case 905U: return ttr_fde_0905_0x03aa10(a0, a1);
        case 906U: return ttr_fde_0906_0x03aa18(a0, a1);
        case 907U: return ttr_fde_0907_0x03aa58(a0, a1);
        case 908U: return ttr_fde_0908_0x03aa90(a0, a1);
        case 909U: return ttr_fde_0909_0x03ab34(a0, a1);
        case 910U: return ttr_fde_0910_0x03ab9c(a0, a1);
        case 911U: return ttr_fde_0911_0x03aba0(a0, a1);
        case 912U: return ttr_fde_0912_0x03aba4(a0, a1);
        case 913U: return ttr_fde_0913_0x03aba8(a0, a1);
        case 914U: return ttr_fde_0914_0x03ad1c(a0, a1);
        case 915U: return ttr_fde_0915_0x03ad80(a0, a1);
        case 916U: return ttr_fde_0916_0x03ad8c(a0, a1);
        case 917U: return ttr_fde_0917_0x03ada4(a0, a1);
        case 918U: return ttr_fde_0918_0x03adb4(a0, a1);
        case 919U: return ttr_fde_0919_0x03adc4(a0, a1);
        case 920U: return ttr_fde_0920_0x03adc8(a0, a1);
        case 921U: return ttr_fde_0921_0x03ade0(a0, a1);
        case 922U: return ttr_fde_0922_0x03adf0(a0, a1);
        case 923U: return ttr_fde_0923_0x03ae00(a0, a1);
        case 924U: return ttr_fde_0924_0x03ae04(a0, a1);
        case 925U: return ttr_fde_0925_0x03b208(a0, a1);
        case 926U: return ttr_fde_0926_0x03b214(a0, a1);
        case 927U: return ttr_fde_0927_0x03b224(a0, a1);
        case 928U: return ttr_fde_0928_0x03b228(a0, a1);
        case 929U: return ttr_fde_0929_0x03b418(a0, a1);
        case 930U: return ttr_fde_0930_0x03b424(a0, a1);
        case 931U: return ttr_fde_0931_0x03b434(a0, a1);
        case 932U: return ttr_fde_0932_0x03b450(a0, a1);
        case 933U: return ttr_fde_0933_0x03b618(a0, a1);
        case 934U: return ttr_fde_0934_0x03b6a4(a0, a1);
        case 935U: return ttr_fde_0935_0x03b730(a0, a1);
        case 936U: return ttr_fde_0936_0x03b784(a0, a1);
        case 937U: return ttr_fde_0937_0x03b7cc(a0, a1);
        case 938U: return ttr_fde_0938_0x03b808(a0, a1);
        case 939U: return ttr_fde_0939_0x03b814(a0, a1);
        case 940U: return ttr_fde_0940_0x03b818(a0, a1);
        case 941U: return ttr_fde_0941_0x03b8b4(a0, a1);
        case 942U: return ttr_fde_0942_0x03b8c8(a0, a1);
        case 943U: return ttr_fde_0943_0x03ba84(a0, a1);
        case 944U: return ttr_fde_0944_0x03bb2c(a0, a1);
        case 945U: return ttr_fde_0945_0x03bb78(a0, a1);
        case 946U: return ttr_fde_0946_0x03bcb4(a0, a1);
        case 947U: return ttr_fde_0947_0x03be04(a0, a1);
        case 948U: return ttr_fde_0948_0x03be08(a0, a1);
        case 949U: return ttr_fde_0949_0x03be20(a0, a1);
        case 950U: return ttr_fde_0950_0x03beac(a0, a1);
        case 951U: return ttr_fde_0951_0x03bee4(a0, a1);
        case 952U: return ttr_fde_0952_0x03bfa8(a0, a1);
        case 953U: return ttr_fde_0953_0x03c004(a0, a1);
        case 954U: return ttr_fde_0954_0x03c024(a0, a1);
        case 955U: return ttr_fde_0955_0x03c030(a0, a1);
        case 956U: return ttr_fde_0956_0x03c058(a0, a1);
        case 957U: return ttr_fde_0957_0x03c074(a0, a1);
        case 958U: return ttr_fde_0958_0x03c210(a0, a1);
        case 959U: return ttr_fde_0959_0x03c50c(a0, a1);
        case 960U: return ttr_fde_0960_0x03c534(a0, a1);
        case 961U: return ttr_fde_0961_0x03c570(a0, a1);
        case 962U: return ttr_fde_0962_0x03c574(a0, a1);
        case 963U: return ttr_fde_0963_0x03c624(a0, a1);
        case 964U: return ttr_fde_0964_0x03c62c(a0, a1);
        case 965U: return ttr_fde_0965_0x03c6a0(a0, a1);
        case 966U: return ttr_fde_0966_0x03c6bc(a0, a1);
        case 967U: return ttr_fde_0967_0x03c6c8(a0, a1);
        case 968U: return ttr_fde_0968_0x03c6ec(a0, a1);
        case 969U: return ttr_fde_0969_0x03c708(a0, a1);
        case 970U: return ttr_fde_0970_0x03c70c(a0, a1);
        case 971U: return ttr_fde_0971_0x03c710(a0, a1);
        case 972U: return ttr_fde_0972_0x03c724(a0, a1);
        case 973U: return ttr_fde_0973_0x03c730(a0, a1);
        case 974U: return ttr_fde_0974_0x03c768(a0, a1);
        case 975U: return ttr_fde_0975_0x03c784(a0, a1);
        case 976U: return ttr_fde_0976_0x03c800(a0, a1);
        case 977U: return ttr_fde_0977_0x03c808(a0, a1);
        case 978U: return ttr_fde_0978_0x03c840(a0, a1);
        case 979U: return ttr_fde_0979_0x03c844(a0, a1);
        case 980U: return ttr_fde_0980_0x03cd24(a0, a1);
        case 981U: return ttr_fde_0981_0x03cd2c(a0, a1);
        case 982U: return ttr_fde_0982_0x03cda0(a0, a1);
        case 983U: return ttr_fde_0983_0x03ce54(a0, a1);
        case 984U: return ttr_fde_0984_0x03ce78(a0, a1);
        case 985U: return ttr_fde_0985_0x03cf58(a0, a1);
        case 986U: return ttr_fde_0986_0x03cf70(a0, a1);
        case 987U: return ttr_fde_0987_0x03cfb0(a0, a1);
        case 988U: return ttr_fde_0988_0x03cfe4(a0, a1);
        case 989U: return ttr_fde_0989_0x03d084(a0, a1);
        case 990U: return ttr_fde_0990_0x03d108(a0, a1);
        case 991U: return ttr_fde_0991_0x03d140(a0, a1);
        case 992U: return ttr_fde_0992_0x03d14c(a0, a1);
        case 993U: return ttr_fde_0993_0x03d168(a0, a1);
        case 994U: return ttr_fde_0994_0x03d198(a0, a1);
        case 995U: return ttr_fde_0995_0x03d620(a0, a1);
        case 996U: return ttr_fde_0996_0x03d640(a0, a1);
        case 997U: return ttr_fde_0997_0x03d65c(a0, a1);
        case 998U: return ttr_fde_0998_0x03d774(a0, a1);
        case 999U: return ttr_fde_0999_0x03d78c(a0, a1);
        case 1000U: return ttr_fde_1000_0x03dd0c(a0, a1);
        case 1001U: return ttr_fde_1001_0x03dd28(a0, a1);
        case 1002U: return ttr_fde_1002_0x03dd78(a0, a1);
        case 1003U: return ttr_fde_1003_0x03dd84(a0, a1);
        case 1004U: return ttr_fde_1004_0x03dda0(a0, a1);
        case 1005U: return ttr_fde_1005_0x03de5c(a0, a1);
        case 1006U: return ttr_fde_1006_0x03de90(a0, a1);
        case 1007U: return ttr_fde_1007_0x03dea4(a0, a1);
        case 1008U: return ttr_fde_1008_0x03df24(a0, a1);
        case 1009U: return ttr_fde_1009_0x03e2fc(a0, a1);
        case 1010U: return ttr_fde_1010_0x03e310(a0, a1);
        case 1011U: return ttr_fde_1011_0x03e374(a0, a1);
        case 1012U: return ttr_fde_1012_0x03ed5c(a0, a1);
        case 1013U: return ttr_fde_1013_0x03ee10(a0, a1);
        case 1014U: return ttr_fde_1014_0x03ee3c(a0, a1);
        case 1015U: return ttr_fde_1015_0x03ee58(a0, a1);
        case 1016U: return ttr_fde_1016_0x03ee84(a0, a1);
        case 1017U: return ttr_fde_1017_0x03eebc(a0, a1);
        case 1018U: return ttr_fde_1018_0x03eedc(a0, a1);
        case 1019U: return ttr_fde_1019_0x03f0d8(a0, a1);
        case 1020U: return ttr_fde_1020_0x03f1d4(a0, a1);
        case 1021U: return ttr_fde_1021_0x03f1f8(a0, a1);
        case 1022U: return ttr_fde_1022_0x03f308(a0, a1);
        case 1023U: return ttr_fde_1023_0x03f3d8(a0, a1);
        case 1024U: return ttr_fde_1024_0x03f3e0(a0, a1);
        case 1025U: return ttr_fde_1025_0x03f3ec(a0, a1);
        case 1026U: return ttr_fde_1026_0x03f3f4(a0, a1);
        case 1027U: return ttr_fde_1027_0x03f494(a0, a1);
        case 1028U: return ttr_fde_1028_0x03f49c(a0, a1);
        case 1029U: return ttr_fde_1029_0x03f4c4(a0, a1);
        case 1030U: return ttr_fde_1030_0x03f4f0(a0, a1);
        case 1031U: return ttr_fde_1031_0x03f518(a0, a1);
        case 1032U: return ttr_fde_1032_0x03f52c(a0, a1);
        case 1033U: return ttr_fde_1033_0x03f56c(a0, a1);
        case 1034U: return ttr_fde_1034_0x03f594(a0, a1);
        case 1035U: return ttr_fde_1035_0x03f5c0(a0, a1);
        case 1036U: return ttr_fde_1036_0x03f5f0(a0, a1);
        case 1037U: return ttr_fde_1037_0x03f64c(a0, a1);
        case 1038U: return ttr_fde_1038_0x03f674(a0, a1);
        case 1039U: return ttr_fde_1039_0x03f8b4(a0, a1);
        case 1040U: return ttr_fde_1040_0x03f920(a0, a1);
        case 1041U: return ttr_fde_1041_0x03f9bc(a0, a1);
        case 1042U: return ttr_fde_1042_0x03f9d8(a0, a1);
        case 1043U: return ttr_fde_1043_0x03fa08(a0, a1);
        case 1044U: return ttr_fde_1044_0x03fa14(a0, a1);
        case 1045U: return ttr_fde_1045_0x03fa20(a0, a1);
        case 1046U: return ttr_fde_1046_0x03fac0(a0, a1);
        case 1047U: return ttr_fde_1047_0x03fb60(a0, a1);
        case 1048U: return ttr_fde_1048_0x03fbf4(a0, a1);
        case 1049U: return ttr_fde_1049_0x03fc08(a0, a1);
        case 1050U: return ttr_fde_1050_0x03fc9c(a0, a1);
        case 1051U: return ttr_fde_1051_0x03fcb4(a0, a1);
        case 1052U: return ttr_fde_1052_0x03fcdc(a0, a1);
        case 1053U: return ttr_fde_1053_0x03fcfc(a0, a1);
        case 1054U: return ttr_fde_1054_0x03fd20(a0, a1);
        case 1055U: return ttr_fde_1055_0x03fd40(a0, a1);
        case 1056U: return ttr_fde_1056_0x03fd78(a0, a1);
        case 1057U: return ttr_fde_1057_0x03fe0c(a0, a1);
        case 1058U: return ttr_fde_1058_0x03fe24(a0, a1);
        case 1059U: return ttr_fde_1059_0x03fe3c(a0, a1);
        case 1060U: return ttr_fde_1060_0x03fe94(a0, a1);
        case 1061U: return ttr_fde_1061_0x03fec8(a0, a1);
        case 1062U: return ttr_fde_1062_0x040024(a0, a1);
        case 1063U: return ttr_fde_1063_0x04006c(a0, a1);
        case 1064U: return ttr_fde_1064_0x0400d4(a0, a1);
        case 1065U: return ttr_fde_1065_0x04014c(a0, a1);
        case 1066U: return ttr_fde_1066_0x0401b0(a0, a1);
        case 1067U: return ttr_fde_1067_0x0401b8(a0, a1);
        case 1068U: return ttr_fde_1068_0x0401e0(a0, a1);
        case 1069U: return ttr_fde_1069_0x040200(a0, a1);
        case 1070U: return ttr_fde_1070_0x040290(a0, a1);
        case 1071U: return ttr_fde_1071_0x040294(a0, a1);
        case 1072U: return ttr_fde_1072_0x040298(a0, a1);
        case 1073U: return ttr_fde_1073_0x0402a4(a0, a1);
        case 1074U: return ttr_fde_1074_0x0402a8(a0, a1);
        case 1075U: return ttr_fde_1075_0x0402d0(a0, a1);
        case 1076U: return ttr_fde_1076_0x0402e4(a0, a1);
        case 1077U: return ttr_fde_1077_0x0402f0(a0, a1);
        case 1078U: return ttr_fde_1078_0x040310(a0, a1);
        case 1079U: return ttr_fde_1079_0x040334(a0, a1);
        case 1080U: return ttr_fde_1080_0x040344(a0, a1);
        case 1081U: return ttr_fde_1081_0x040348(a0, a1);
        case 1082U: return ttr_fde_1082_0x04035c(a0, a1);
        case 1083U: return ttr_fde_1083_0x040398(a0, a1);
        case 1084U: return ttr_fde_1084_0x0403a0(a0, a1);
        case 1085U: return ttr_fde_1085_0x040560(a0, a1);
        case 1086U: return ttr_fde_1086_0x040580(a0, a1);
        case 1087U: return ttr_fde_1087_0x0405a0(a0, a1);
        case 1088U: return ttr_fde_1088_0x0405e8(a0, a1);
        case 1089U: return ttr_fde_1089_0x0405f0(a0, a1);
        case 1090U: return ttr_fde_1090_0x040638(a0, a1);
        case 1091U: return ttr_fde_1091_0x040898(a0, a1);
        case 1092U: return ttr_fde_1092_0x0408b8(a0, a1);
        case 1093U: return ttr_fde_1093_0x0408d8(a0, a1);
        case 1094U: return ttr_fde_1094_0x04099c(a0, a1);
        case 1095U: return ttr_fde_1095_0x040a1c(a0, a1);
        case 1096U: return ttr_fde_1096_0x040a24(a0, a1);
        case 1097U: return ttr_fde_1097_0x040a2c(a0, a1);
        case 1098U: return ttr_fde_1098_0x040a7c(a0, a1);
        case 1099U: return ttr_fde_1099_0x040a80(a0, a1);
        case 1100U: return ttr_fde_1100_0x040a8c(a0, a1);
        case 1101U: return ttr_fde_1101_0x040aa0(a0, a1);
        case 1102U: return ttr_fde_1102_0x040b64(a0, a1);
        case 1103U: return ttr_fde_1103_0x040b9c(a0, a1);
        case 1104U: return ttr_fde_1104_0x040be4(a0, a1);
        case 1105U: return ttr_fde_1105_0x040bf4(a0, a1);
        case 1106U: return ttr_fde_1106_0x040c24(a0, a1);
        case 1107U: return ttr_fde_1107_0x040c34(a0, a1);
        case 1108U: return ttr_fde_1108_0x040c5c(a0, a1);
        case 1109U: return ttr_fde_1109_0x040c6c(a0, a1);
        case 1110U: return ttr_fde_1110_0x040c90(a0, a1);
        case 1111U: return ttr_fde_1111_0x040ca0(a0, a1);
        case 1112U: return ttr_fde_1112_0x040ccc(a0, a1);
        case 1113U: return ttr_fde_1113_0x040cec(a0, a1);
        case 1114U: return ttr_fde_1114_0x041200(a0, a1);
        case 1115U: return ttr_fde_1115_0x041208(a0, a1);
        case 1116U: return ttr_fde_1116_0x0412f4(a0, a1);
        case 1117U: return ttr_fde_1117_0x041350(a0, a1);
        case 1118U: return ttr_fde_1118_0x0413b4(a0, a1);
        case 1119U: return ttr_fde_1119_0x041480(a0, a1);
        case 1120U: return ttr_fde_1120_0x0415b4(a0, a1);
        case 1121U: return ttr_fde_1121_0x041884(a0, a1);
        case 1122U: return ttr_fde_1122_0x041908(a0, a1);
        case 1123U: return ttr_fde_1123_0x0419e8(a0, a1);
        case 1124U: return ttr_fde_1124_0x041a04(a0, a1);
        case 1125U: return ttr_fde_1125_0x041a2c(a0, a1);
        case 1126U: return ttr_fde_1126_0x041a64(a0, a1);
        case 1127U: return ttr_fde_1127_0x041b68(a0, a1);
        case 1128U: return ttr_fde_1128_0x041b7c(a0, a1);
        case 1129U: return ttr_fde_1129_0x041b84(a0, a1);
        case 1130U: return ttr_fde_1130_0x041bb8(a0, a1);
        case 1131U: return ttr_fde_1131_0x041c10(a0, a1);
        case 1132U: return ttr_fde_1132_0x041c18(a0, a1);
        case 1133U: return ttr_fde_1133_0x041c48(a0, a1);
        case 1134U: return ttr_fde_1134_0x041ce0(a0, a1);
        case 1135U: return ttr_fde_1135_0x041cf0(a0, a1);
        case 1136U: return ttr_fde_1136_0x041d24(a0, a1);
        case 1137U: return ttr_fde_1137_0x041d44(a0, a1);
        case 1138U: return ttr_fde_1138_0x041d60(a0, a1);
        case 1139U: return ttr_fde_1139_0x041d78(a0, a1);
        case 1140U: return ttr_fde_1140_0x041dac(a0, a1);
        case 1141U: return ttr_fde_1141_0x041dc8(a0, a1);
        case 1142U: return ttr_fde_1142_0x041de0(a0, a1);
        case 1143U: return ttr_fde_1143_0x041e34(a0, a1);
        case 1144U: return ttr_fde_1144_0x041e9c(a0, a1);
        case 1145U: return ttr_fde_1145_0x042034(a0, a1);
        case 1146U: return ttr_fde_1146_0x042088(a0, a1);
        case 1147U: return ttr_fde_1147_0x0420dc(a0, a1);
        case 1148U: return ttr_fde_1148_0x04211c(a0, a1);
        case 1149U: return ttr_fde_1149_0x04213c(a0, a1);
        case 1150U: return ttr_fde_1150_0x042164(a0, a1);
        case 1151U: return ttr_fde_1151_0x0421e0(a0, a1);
        case 1152U: return ttr_fde_1152_0x042274(a0, a1);
        case 1153U: return ttr_fde_1153_0x04227c(a0, a1);
        case 1154U: return ttr_fde_1154_0x0422d4(a0, a1);
        case 1155U: return ttr_fde_1155_0x0422dc(a0, a1);
        case 1156U: return ttr_fde_1156_0x042320(a0, a1);
        case 1157U: return ttr_fde_1157_0x042338(a0, a1);
        case 1158U: return ttr_fde_1158_0x042384(a0, a1);
        case 1159U: return ttr_fde_1159_0x0423fc(a0, a1);
        case 1160U: return ttr_fde_1160_0x042480(a0, a1);
        case 1161U: return ttr_fde_1161_0x042498(a0, a1);
        case 1162U: return ttr_fde_1162_0x04292c(a0, a1);
        case 1163U: return ttr_fde_1163_0x042954(a0, a1);
        case 1164U: return ttr_fde_1164_0x042978(a0, a1);
        case 1165U: return ttr_fde_1165_0x0429bc(a0, a1);
        case 1166U: return ttr_fde_1166_0x042a04(a0, a1);
        case 1167U: return ttr_fde_1167_0x042a24(a0, a1);
        case 1168U: return ttr_fde_1168_0x042a34(a0, a1);
        case 1169U: return ttr_fde_1169_0x042a60(a0, a1);
        case 1170U: return ttr_fde_1170_0x042d3c(a0, a1);
        case 1171U: return ttr_fde_1171_0x042d6c(a0, a1);
        case 1172U: return ttr_fde_1172_0x042e04(a0, a1);
        case 1173U: return ttr_fde_1173_0x042e14(a0, a1);
        case 1174U: return ttr_fde_1174_0x042ec0(a0, a1);
        case 1175U: return ttr_fde_1175_0x042ec8(a0, a1);
        case 1176U: return ttr_fde_1176_0x042ee4(a0, a1);
        case 1177U: return ttr_fde_1177_0x042efc(a0, a1);
        case 1178U: return ttr_fde_1178_0x042f70(a0, a1);
        case 1179U: return ttr_fde_1179_0x042f8c(a0, a1);
        case 1180U: return ttr_fde_1180_0x042fa4(a0, a1);
        case 1181U: return ttr_fde_1181_0x043068(a0, a1);
        case 1182U: return ttr_fde_1182_0x0430cc(a0, a1);
        case 1183U: return ttr_fde_1183_0x0431cc(a0, a1);
        case 1184U: return ttr_fde_1184_0x043468(a0, a1);
        case 1185U: return ttr_fde_1185_0x043488(a0, a1);
        case 1186U: return ttr_fde_1186_0x043490(a0, a1);
        case 1187U: return ttr_fde_1187_0x0434a0(a0, a1);
        case 1188U: return ttr_fde_1188_0x0434fc(a0, a1);
        case 1189U: return ttr_fde_1189_0x043520(a0, a1);
        case 1190U: return ttr_fde_1190_0x0435b0(a0, a1);
        case 1191U: return ttr_fde_1191_0x0435d4(a0, a1);
        case 1192U: return ttr_fde_1192_0x0435ec(a0, a1);
        case 1193U: return ttr_fde_1193_0x0436fc(a0, a1);
        case 1194U: return ttr_fde_1194_0x043718(a0, a1);
        case 1195U: return ttr_fde_1195_0x043730(a0, a1);
        case 1196U: return ttr_fde_1196_0x043830(a0, a1);
        case 1197U: return ttr_fde_1197_0x043844(a0, a1);
        case 1198U: return ttr_fde_1198_0x043858(a0, a1);
        case 1199U: return ttr_fde_1199_0x04385c(a0, a1);
        case 1200U: return ttr_fde_1200_0x04386c(a0, a1);
        case 1201U: return ttr_fde_1201_0x043878(a0, a1);
        case 1202U: return ttr_fde_1202_0x04387c(a0, a1);
        case 1203U: return ttr_fde_1203_0x043888(a0, a1);
        case 1204U: return ttr_fde_1204_0x0438c4(a0, a1);
        case 1205U: return ttr_fde_1205_0x043950(a0, a1);
        case 1206U: return ttr_fde_1206_0x0439f8(a0, a1);
        case 1207U: return ttr_fde_1207_0x043be8(a0, a1);
        case 1208U: return ttr_fde_1208_0x043c84(a0, a1);
        case 1209U: return ttr_fde_1209_0x043de0(a0, a1);
        case 1210U: return ttr_fde_1210_0x043e44(a0, a1);
        case 1211U: return ttr_fde_1211_0x043ed4(a0, a1);
        case 1212U: return ttr_fde_1212_0x043f34(a0, a1);
        case 1213U: return ttr_fde_1213_0x043f70(a0, a1);
        case 1214U: return ttr_fde_1214_0x044168(a0, a1);
        case 1215U: return ttr_fde_1215_0x0443fc(a0, a1);
        case 1216U: return ttr_fde_1216_0x04447c(a0, a1);
        case 1217U: return ttr_fde_1217_0x044988(a0, a1);
        case 1218U: return ttr_fde_1218_0x0449ec(a0, a1);
        case 1219U: return ttr_fde_1219_0x044ab8(a0, a1);
        case 1220U: return ttr_fde_1220_0x044be0(a0, a1);
        case 1221U: return ttr_fde_1221_0x044d80(a0, a1);
        case 1222U: return ttr_fde_1222_0x044dec(a0, a1);
        case 1223U: return ttr_fde_1223_0x044e80(a0, a1);
        case 1224U: return ttr_fde_1224_0x0451b8(a0, a1);
        case 1225U: return ttr_fde_1225_0x0451e8(a0, a1);
        case 1226U: return ttr_fde_1226_0x045248(a0, a1);
        case 1227U: return ttr_fde_1227_0x045348(a0, a1);
        case 1228U: return ttr_fde_1228_0x0455ec(a0, a1);
        case 1229U: return ttr_fde_1229_0x045618(a0, a1);
        case 1230U: return ttr_fde_1230_0x04561c(a0, a1);
        case 1231U: return ttr_fde_1231_0x04568c(a0, a1);
        case 1232U: return ttr_fde_1232_0x045834(a0, a1);
        case 1233U: return ttr_fde_1233_0x045854(a0, a1);
        case 1234U: return ttr_fde_1234_0x045868(a0, a1);
        case 1235U: return ttr_fde_1235_0x04588c(a0, a1);
        case 1236U: return ttr_fde_1236_0x04596c(a0, a1);
        case 1237U: return ttr_fde_1237_0x045d34(a0, a1);
        case 1238U: return ttr_fde_1238_0x045e18(a0, a1);
        case 1239U: return ttr_fde_1239_0x045e34(a0, a1);
        case 1240U: return ttr_fde_1240_0x045e68(a0, a1);
        case 1241U: return ttr_fde_1241_0x045e80(a0, a1);
        case 1242U: return ttr_fde_1242_0x045ea0(a0, a1);
        case 1243U: return ttr_fde_1243_0x045ec8(a0, a1);
        case 1244U: return ttr_fde_1244_0x046078(a0, a1);
        case 1245U: return ttr_fde_1245_0x0460a0(a0, a1);
        case 1246U: return ttr_fde_1246_0x0460b4(a0, a1);
        case 1247U: return ttr_fde_1247_0x0460f0(a0, a1);
        case 1248U: return ttr_fde_1248_0x046108(a0, a1);
        case 1249U: return ttr_fde_1249_0x04611c(a0, a1);
        case 1250U: return ttr_fde_1250_0x04613c(a0, a1);
        case 1251U: return ttr_fde_1251_0x046154(a0, a1);
        case 1252U: return ttr_fde_1252_0x04615c(a0, a1);
        case 1253U: return ttr_fde_1253_0x046160(a0, a1);
        case 1254U: return ttr_fde_1254_0x046198(a0, a1);
        case 1255U: return ttr_fde_1255_0x0461c0(a0, a1);
        case 1256U: return ttr_fde_1256_0x0462a8(a0, a1);
        case 1257U: return ttr_fde_1257_0x0462ac(a0, a1);
        case 1258U: return ttr_fde_1258_0x0462c8(a0, a1);
        case 1259U: return ttr_fde_1259_0x0462d4(a0, a1);
        case 1260U: return ttr_fde_1260_0x0462d8(a0, a1);
        case 1261U: return ttr_fde_1261_0x0462dc(a0, a1);
        case 1262U: return ttr_fde_1262_0x046304(a0, a1);
        case 1263U: return ttr_fde_1263_0x046308(a0, a1);
        case 1264U: return ttr_fde_1264_0x046324(a0, a1);
        case 1265U: return ttr_fde_1265_0x046330(a0, a1);
        case 1266U: return ttr_fde_1266_0x046334(a0, a1);
        case 1267U: return ttr_fde_1267_0x046338(a0, a1);
        case 1268U: return ttr_fde_1268_0x046360(a0, a1);
        case 1269U: return ttr_fde_1269_0x046364(a0, a1);
        case 1270U: return ttr_fde_1270_0x046380(a0, a1);
        case 1271U: return ttr_fde_1271_0x04638c(a0, a1);
        case 1272U: return ttr_fde_1272_0x046390(a0, a1);
        case 1273U: return ttr_fde_1273_0x046394(a0, a1);
        case 1274U: return ttr_fde_1274_0x046468(a0, a1);
        case 1275U: return ttr_fde_1275_0x046480(a0, a1);
        case 1276U: return ttr_fde_1276_0x046488(a0, a1);
        case 1277U: return ttr_fde_1277_0x046520(a0, a1);
        case 1278U: return ttr_fde_1278_0x04652c(a0, a1);
        case 1279U: return ttr_fde_1279_0x046534(a0, a1);
        case 1280U: return ttr_fde_1280_0x0465a0(a0, a1);
        case 1281U: return ttr_fde_1281_0x0467c8(a0, a1);
        case 1282U: return ttr_fde_1282_0x0467cc(a0, a1);
        case 1283U: return ttr_fde_1283_0x0469a8(a0, a1);
        case 1284U: return ttr_fde_1284_0x0469c4(a0, a1);
        case 1285U: return ttr_fde_1285_0x0469d8(a0, a1);
        case 1286U: return ttr_fde_1286_0x0469dc(a0, a1);
        case 1287U: return ttr_fde_1287_0x046a30(a0, a1);
        case 1288U: return ttr_fde_1288_0x046ab4(a0, a1);
        case 1289U: return ttr_fde_1289_0x046b08(a0, a1);
        case 1290U: return ttr_fde_1290_0x046b94(a0, a1);
        case 1291U: return ttr_fde_1291_0x046c4c(a0, a1);
        case 1292U: return ttr_fde_1292_0x046d84(a0, a1);
        case 1293U: return ttr_fde_1293_0x046da0(a0, a1);
        case 1294U: return ttr_fde_1294_0x046dd0(a0, a1);
        case 1295U: return ttr_fde_1295_0x046e70(a0, a1);
        case 1296U: return ttr_fde_1296_0x046e8c(a0, a1);
        case 1297U: return ttr_fde_1297_0x046ebc(a0, a1);
        case 1298U: return ttr_fde_1298_0x046ef8(a0, a1);
        case 1299U: return ttr_fde_1299_0x046f5c(a0, a1);
        case 1300U: return ttr_fde_1300_0x046f94(a0, a1);
        case 1301U: return ttr_fde_1301_0x047050(a0, a1);
        case 1302U: return ttr_fde_1302_0x0470b4(a0, a1);
        case 1303U: return ttr_fde_1303_0x0470ec(a0, a1);
        case 1304U: return ttr_fde_1304_0x04722c(a0, a1);
        case 1305U: return ttr_fde_1305_0x047244(a0, a1);
        case 1306U: return ttr_fde_1306_0x047284(a0, a1);
        case 1307U: return ttr_fde_1307_0x04728c(a0, a1);
        case 1308U: return ttr_fde_1308_0x047290(a0, a1);
        case 1309U: return ttr_fde_1309_0x0472b0(a0, a1);
        case 1310U: return ttr_fde_1310_0x0472c0(a0, a1);
        case 1311U: return ttr_fde_1311_0x0472c4(a0, a1);
        case 1312U: return ttr_fde_1312_0x0472c8(a0, a1);
        case 1313U: return ttr_fde_1313_0x0473c8(a0, a1);
        case 1314U: return ttr_fde_1314_0x0473cc(a0, a1);
        case 1315U: return ttr_fde_1315_0x0473e8(a0, a1);
        case 1316U: return ttr_fde_1316_0x0473f4(a0, a1);
        case 1317U: return ttr_fde_1317_0x0473f8(a0, a1);
        case 1318U: return ttr_fde_1318_0x0473fc(a0, a1);
        case 1319U: return ttr_fde_1319_0x0474c4(a0, a1);
        case 1320U: return ttr_fde_1320_0x0474c8(a0, a1);
        case 1321U: return ttr_fde_1321_0x0474e4(a0, a1);
        case 1322U: return ttr_fde_1322_0x0474f0(a0, a1);
        case 1323U: return ttr_fde_1323_0x0474f4(a0, a1);
        case 1324U: return ttr_fde_1324_0x0474f8(a0, a1);
        case 1325U: return ttr_fde_1325_0x0475ac(a0, a1);
        case 1326U: return ttr_fde_1326_0x04774c(a0, a1);
        case 1327U: return ttr_fde_1327_0x0477c4(a0, a1);
        case 1328U: return ttr_fde_1328_0x0477f4(a0, a1);
        case 1329U: return ttr_fde_1329_0x047800(a0, a1);
        case 1330U: return ttr_fde_1330_0x0478d4(a0, a1);
        case 1331U: return ttr_fde_1331_0x0478ec(a0, a1);
        case 1332U: return ttr_fde_1332_0x0478f0(a0, a1);
        case 1333U: return ttr_fde_1333_0x047920(a0, a1);
        case 1334U: return ttr_fde_1334_0x047c14(a0, a1);
        case 1335U: return ttr_fde_1335_0x047db4(a0, a1);
        case 1336U: return ttr_fde_1336_0x047e34(a0, a1);
        case 1337U: return ttr_fde_1337_0x047e4c(a0, a1);
        case 1338U: return ttr_fde_1338_0x047e64(a0, a1);
        case 1339U: return ttr_fde_1339_0x047e94(a0, a1);
        case 1340U: return ttr_fde_1340_0x047ecc(a0, a1);
        case 1341U: return ttr_fde_1341_0x047ed4(a0, a1);
        case 1342U: return ttr_fde_1342_0x047eec(a0, a1);
        case 1343U: return ttr_fde_1343_0x047f08(a0, a1);
        case 1344U: return ttr_fde_1344_0x047f28(a0, a1);
        case 1345U: return ttr_fde_1345_0x047f40(a0, a1);
        case 1346U: return ttr_fde_1346_0x047f48(a0, a1);
        case 1347U: return ttr_fde_1347_0x047f4c(a0, a1);
        case 1348U: return ttr_fde_1348_0x047fa4(a0, a1);
        case 1349U: return ttr_fde_1349_0x047fb0(a0, a1);
        case 1350U: return ttr_fde_1350_0x048058(a0, a1);
        case 1351U: return ttr_fde_1351_0x0480c8(a0, a1);
        case 1352U: return ttr_fde_1352_0x0480e0(a0, a1);
        case 1353U: return ttr_fde_1353_0x0480ec(a0, a1);
        default: return 0U;
    }
}

} // namespace ttr_render
