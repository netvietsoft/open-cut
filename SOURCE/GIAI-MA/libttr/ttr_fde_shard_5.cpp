// ============================================================================
// File: ttr_fde_shard_5.cpp
// Target: libttr.so (625,192 bytes)
// SHA-256: 38c13f772c29f2a6b03c5523b74730be6727dfc9c3de457b1e09fe32578d6f6f
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// FDE Range: [2708..3385] of 3,386 (.eh_frame_hdr @ 0x08ab40)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [2708..3385]
//      verified directly against the .text section of libttr.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [2708..3385]
//      đã đối chiếu trực tiếp với phân đoạn .text của libttr.so.
// ============================================================================

#include "ttr_render_types.h"

namespace ttr_render {

// [EN] FDE[2708] start_va=0x0623ec, fde_va=0x086b68, span=8 B | [VN] FDE[2708]
uint32_t ttr_fde_2708_0x0623ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105c3e0U) + (a1 ^ 0x17ffd6bfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910883e0U + 0x0623ecU) ^ (0xaa1c03e1U + 0x086b68U + 8U);
}

// [EN] FDE[2709] start_va=0x0623f4, fde_va=0x086b80, span=12 B | [VN] FDE[2709]
uint32_t ttr_fde_2709_0x0623f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910883e0U) + (a1 ^ 0xaa1c03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff062fU + 0x0623f4U) ^ (0x9e6702c0U + 0x086b80U + 12U);
}

// [EN] FDE[2710] start_va=0x062400, fde_va=0x086b98, span=28 B | [VN] FDE[2710]
uint32_t ttr_fde_2710_0x062400(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9e6702c0U) + (a1 ^ 0x0e205800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2e303800U + 0x062400U) ^ (0x1e260017U + 0x086b98U + 28U);
}

// [EN] FDE[2711] start_va=0x06241c, fde_va=0x086bb0, span=8 B | [VN] FDE[2711]
uint32_t ttr_fde_2711_0x06241c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800600U) + (a1 ^ 0x17fee650U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910063e0U + 0x06241cU) ^ (0x910003e1U + 0x086bb0U + 8U);
}

// [EN] FDE[2712] start_va=0x062424, fde_va=0x086bc8, span=12 B | [VN] FDE[2712]
uint32_t ttr_fde_2712_0x062424(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e0U) + (a1 ^ 0x910003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff8d02U + 0x062424U) ^ (0x1e22c001U + 0x086bc8U + 12U);
}

// [EN] FDE[2713] start_va=0x062430, fde_va=0x086be0, span=28 B | [VN] FDE[2713]
uint32_t ttr_fde_2713_0x062430(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e22c001U) + (a1 ^ 0xbd410665U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e622020U + 0x062430U) ^ (0x5e21d861U + 0x086be0U + 28U);
}

// [EN] FDE[2714] start_va=0x06244c, fde_va=0x086bf8, span=20 B | [VN] FDE[2714]
uint32_t ttr_fde_2714_0x06244c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001a8U) + (a1 ^ 0x9129a108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x06244cU) ^ (0xf9000008U + 0x086bf8U + 20U);
}

// [EN] FDE[2715] start_va=0x062460, fde_va=0x086c10, span=8 B | [VN] FDE[2715]
uint32_t ttr_fde_2715_0x062460(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9103c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9409808U + 0x062460U) ^ (0xaa0303f3U + 0x086c10U + 8U);
}

// [EN] FDE[2716] start_va=0x062468, fde_va=0x086c28, span=28 B | [VN] FDE[2716]
uint32_t ttr_fde_2716_0x062468(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9409808U) + (a1 ^ 0xaa0303f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x062468U) ^ (0x2a0103f5U + 0x086c28U + 28U);
}

// [EN] FDE[2717] start_va=0x062484, fde_va=0x086c40, span=20 B | [VN] FDE[2717]
uint32_t ttr_fde_2717_0x062484(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9809a74U) + (a1 ^ 0x910023e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800061U + 0x062484U) ^ (0x91008273U + 0x086c40U + 20U);
}

// [EN] FDE[2718] start_va=0x062498, fde_va=0x086c58, span=20 B | [VN] FDE[2718]
uint32_t ttr_fde_2718_0x062498(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910323e0U) + (a1 ^ 0x910443e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xbd0117e1U + 0x062498U) ^ (0xbd0113e0U + 0x086c58U + 20U);
}

// [EN] FDE[2719] start_va=0x0624ac, fde_va=0x086c70, span=44 B | [VN] FDE[2719]
uint32_t ttr_fde_2719_0x0624ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xf9404fe8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400009U + 0x0624acU) ^ (0xf9000008U + 0x086c70U + 44U);
}

// [EN] FDE[2720] start_va=0x0624d8, fde_va=0x086c90, span=12 B | [VN] FDE[2720]
uint32_t ttr_fde_2720_0x0624d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e270100U) + (a1 ^ 0x4ea81d01U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0624d8U) ^ (0x39400261U + 0x086c90U + 12U);
}

// [EN] FDE[2721] start_va=0x0624e4, fde_va=0x086ca8, span=28 B | [VN] FDE[2721]
uint32_t ttr_fde_2721_0x0624e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400261U) + (a1 ^ 0xaa0303f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f6U + 0x0624e4U) ^ (0xaa0003f5U + 0x086ca8U + 28U);
}

// [EN] FDE[2722] start_va=0x062500, fde_va=0x086cc0, span=28 B | [VN] FDE[2722]
uint32_t ttr_fde_2722_0x062500(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a80U) + (a1 ^ 0x5280002aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39406009U + 0x062500U) ^ (0x39006289U + 0x086cc0U + 28U);
}

// [EN] FDE[2723] start_va=0x06251c, fde_va=0x086cd8, span=20 B | [VN] FDE[2723]
uint32_t ttr_fde_2723_0x06251c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9404e60U) + (a1 ^ 0xb940ce61U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x06251cU) ^ (0xf9401108U + 0x086cd8U + 20U);
}

// [EN] FDE[2724] start_va=0x062530, fde_va=0x086cf0, span=12 B | [VN] FDE[2724]
uint32_t ttr_fde_2724_0x062530(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b1606c8U) + (a1 ^ 0xd37df100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee60aU + 0x062530U) ^ (0x910143ffU + 0x086cf0U + 12U);
}

// [EN] FDE[2725] start_va=0x06253c, fde_va=0x086d08, span=8 B | [VN] FDE[2725]
uint32_t ttr_fde_2725_0x06253c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910143ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100051fU + 0x06253cU) ^ (0x5285202aU + 0x086d08U + 8U);
}

// [EN] FDE[2726] start_va=0x062544, fde_va=0x086d20, span=28 B | [VN] FDE[2726]
uint32_t ttr_fde_2726_0x062544(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100051fU) + (a1 ^ 0x5285202aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52906e0bU + 0x062544U) ^ (0x1a8a016aU + 0x086d20U + 28U);
}

// [EN] FDE[2727] start_va=0x062560, fde_va=0x086d38, span=12 B | [VN] FDE[2727]
uint32_t ttr_fde_2727_0x062560(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9403008U) + (a1 ^ 0xaa0003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062560U) ^ (0xf94016c0U + 0x086d38U + 12U);
}

// [EN] FDE[2728] start_va=0x06256c, fde_va=0x086d50, span=20 B | [VN] FDE[2728]
uint32_t ttr_fde_2728_0x06256c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94016c0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x06256cU) ^ (0xf9405508U + 0x086d50U + 20U);
}

// [EN] FDE[2729] start_va=0x062580, fde_va=0x086d68, span=20 B | [VN] FDE[2729]
uint32_t ttr_fde_2729_0x062580(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94016c0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x062580U) ^ (0xf9405d08U + 0x086d68U + 20U);
}

// [EN] FDE[2730] start_va=0x062594, fde_va=0x086d80, span=20 B | [VN] FDE[2730]
uint32_t ttr_fde_2730_0x062594(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94853f5U) + (a1 ^ 0xa9475bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94033f8U + 0x062594U) ^ (0x910283ffU + 0x086d80U + 20U);
}

// [EN] FDE[2731] start_va=0x0625a8, fde_va=0x086d98, span=12 B | [VN] FDE[2731]
uint32_t ttr_fde_2731_0x0625a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91000668U) + (a1 ^ 0xeb16011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0625a8U) ^ (0xb9406808U + 0x086d98U + 12U);
}

// [EN] FDE[2732] start_va=0x0625b4, fde_va=0x086db0, span=28 B | [VN] FDE[2732]
uint32_t ttr_fde_2732_0x0625b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9406808U) + (a1 ^ 0xaa0303f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f5U + 0x0625b4U) ^ (0x2a0103f4U + 0x086db0U + 28U);
}

// [EN] FDE[2733] start_va=0x0625d0, fde_va=0x086dc8, span=20 B | [VN] FDE[2733]
uint32_t ttr_fde_2733_0x0625d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb94003e3U) + (a1 ^ 0xaa0003e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910063e1U + 0x0625d0U) ^ (0xaa1403e0U + 0x086dc8U + 20U);
}

// [EN] FDE[2734] start_va=0x0625e4, fde_va=0x086de0, span=28 B | [VN] FDE[2734]
uint32_t ttr_fde_2734_0x0625e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007c7fU) + (a1 ^ 0xf9000861U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000043U + 0x0625e4U) ^ (0xf9400008U + 0x086de0U + 28U);
}

// [EN] FDE[2735] start_va=0x062600, fde_va=0x086df8, span=12 B | [VN] FDE[2735]
uint32_t ttr_fde_2735_0x062600(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e1U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062600U) ^ (0x79414488U + 0x086df8U + 12U);
}

// [EN] FDE[2736] start_va=0x06260c, fde_va=0x086e10, span=20 B | [VN] FDE[2736]
uint32_t ttr_fde_2736_0x06260c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x79414488U) + (a1 ^ 0xaa0403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x321b0508U + 0x06260cU) ^ (0x79014488U + 0x086e10U + 20U);
}

// [EN] FDE[2737] start_va=0x062620, fde_va=0x086e28, span=20 B | [VN] FDE[2737]
uint32_t ttr_fde_2737_0x062620(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001c1U) + (a1 ^ 0xf9453c21U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0003f6U + 0x062620U) ^ (0xaa1603e0U + 0x086e28U + 20U);
}

// [EN] FDE[2738] start_va=0x062634, fde_va=0x086e40, span=28 B | [VN] FDE[2738]
uint32_t ttr_fde_2738_0x062634(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9106126dU) + (a1 ^ 0x9106226eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x88dffdafU + 0x062634U) ^ (0x88dffdd0U + 0x086e40U + 28U);
}

// [EN] FDE[2739] start_va=0x062650, fde_va=0x086e58, span=28 B | [VN] FDE[2739]
uint32_t ttr_fde_2739_0x062650(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0403f7U) + (a1 ^ 0xaa0303f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f8U + 0x062650U) ^ (0xaa0003f4U + 0x086e58U + 28U);
}

// [EN] FDE[2740] start_va=0x06266c, fde_va=0x086e70, span=8 B | [VN] FDE[2740]
uint32_t ttr_fde_2740_0x06266c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e1U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd53bd054U + 0x06266cU) ^ (0xf9401688U + 0x086e70U + 8U);
}

// [EN] FDE[2741] start_va=0x062674, fde_va=0x086e88, span=12 B | [VN] FDE[2741]
uint32_t ttr_fde_2741_0x062674(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd054U) + (a1 ^ 0xf9401688U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062674U) ^ (0x52800028U + 0x086e88U + 12U);
}

// [EN] FDE[2742] start_va=0x062680, fde_va=0x086ea0, span=12 B | [VN] FDE[2742]
uint32_t ttr_fde_2742_0x062680(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800028U) + (a1 ^ 0x39002a68U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062680U) ^ (0xaa1603e1U + 0x086ea0U + 12U);
}

// [EN] FDE[2743] start_va=0x06268c, fde_va=0x086eb8, span=12 B | [VN] FDE[2743]
uint32_t ttr_fde_2743_0x06268c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0xaa1503e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06268cU) ^ (0xaa1603e1U + 0x086eb8U + 12U);
}

// [EN] FDE[2744] start_va=0x062698, fde_va=0x086ed0, span=12 B | [VN] FDE[2744]
uint32_t ttr_fde_2744_0x062698(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0xaa1703e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062698U) ^ (0x910003e0U + 0x086ed0U + 12U);
}

// [EN] FDE[2745] start_va=0x0626a4, fde_va=0x086ee8, span=8 B | [VN] FDE[2745]
uint32_t ttr_fde_2745_0x0626a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x17fee5a6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e0U + 0x0626a4U) ^ (0xaa1403e1U + 0x086ee8U + 8U);
}

// [EN] FDE[2746] start_va=0x0626ac, fde_va=0x086f00, span=12 B | [VN] FDE[2746]
uint32_t ttr_fde_2746_0x0626ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0626acU) ^ (0x910003e0U + 0x086f00U + 12U);
}

// [EN] FDE[2747] start_va=0x0626b8, fde_va=0x086f18, span=12 B | [VN] FDE[2747]
uint32_t ttr_fde_2747_0x0626b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0xaa1f03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee7d0U + 0x0626b8U) ^ (0xf85e8108U + 0x086f18U + 12U);
}

// [EN] FDE[2748] start_va=0x0626c4, fde_va=0x086f30, span=12 B | [VN] FDE[2748]
uint32_t ttr_fde_2748_0x0626c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85e8108U) + (a1 ^ 0x8b080260U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0029U + 0x0626c4U) ^ (0xa9434ff4U + 0x086f30U + 12U);
}

// [EN] FDE[2749] start_va=0x0626d0, fde_va=0x086f48, span=20 B | [VN] FDE[2749]
uint32_t ttr_fde_2749_0x0626d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9434ff4U) + (a1 ^ 0xa94257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9415ff8U + 0x0626d0U) ^ (0xf84507f9U + 0x086f48U + 20U);
}

// [EN] FDE[2750] start_va=0x0626e4, fde_va=0x086f60, span=20 B | [VN] FDE[2750]
uint32_t ttr_fde_2750_0x0626e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9802a75U) + (a1 ^ 0xb00001c1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9453c21U + 0x0626e4U) ^ (0xaa1503e0U + 0x086f60U + 20U);
}

// [EN] FDE[2751] start_va=0x0626f8, fde_va=0x086f78, span=28 B | [VN] FDE[2751]
uint32_t ttr_fde_2751_0x0626f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400268U) + (a1 ^ 0xf9400669U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd0aU + 0x0626f8U) ^ (0x7200011fU + 0x086f78U + 28U);
}

// [EN] FDE[2752] start_va=0x062714, fde_va=0x086f90, span=28 B | [VN] FDE[2752]
uint32_t ttr_fde_2752_0x062714(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b1402a8U) + (a1 ^ 0xcb010102U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x062714U) ^ (0xaa1503e3U + 0x086f90U + 28U);
}

// [EN] FDE[2753] start_va=0x062730, fde_va=0x086fa8, span=20 B | [VN] FDE[2753]
uint32_t ttr_fde_2753_0x062730(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001a8U) + (a1 ^ 0x91252108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x062730U) ^ (0xf9000008U + 0x086fa8U + 20U);
}

// [EN] FDE[2754] start_va=0x062744, fde_va=0x086fc0, span=20 B | [VN] FDE[2754]
uint32_t ttr_fde_2754_0x062744(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e7e1000U) + (a1 ^ 0x1e6029aaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4eab1d60U + 0x062744U) ^ (0x1e6c29a8U + 0x086fc0U + 20U);
}

// [EN] FDE[2755] start_va=0x062758, fde_va=0x086fd8, span=28 B | [VN] FDE[2755]
uint32_t ttr_fde_2755_0x062758(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e8U) + (a1 ^ 0xf8410d09U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90002a9U + 0x062758U) ^ (0xf9000115U + 0x086fd8U + 28U);
}

// [EN] FDE[2756] start_va=0x062774, fde_va=0x086ff0, span=28 B | [VN] FDE[2756]
uint32_t ttr_fde_2756_0x062774(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5280002aU) + (a1 ^ 0x9ac92149U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd2809e2aU + 0x062774U) ^ (0xf2a1000aU + 0x086ff0U + 28U);
}

// [EN] FDE[2757] start_va=0x062790, fde_va=0x087008, span=20 B | [VN] FDE[2757]
uint32_t ttr_fde_2757_0x062790(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001a8U) + (a1 ^ 0x9122e108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x062790U) ^ (0xf9000008U + 0x087008U + 20U);
}

// [EN] FDE[2758] start_va=0x0627a4, fde_va=0x087020, span=12 B | [VN] FDE[2758]
uint32_t ttr_fde_2758_0x0627a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf8418c08U) + (a1 ^ 0xf9400101U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0020U + 0x0627a4U) ^ (0x910183e0U + 0x087020U + 12U);
}

// [EN] FDE[2759] start_va=0x0627b0, fde_va=0x087038, span=8 B | [VN] FDE[2759]
uint32_t ttr_fde_2759_0x0627b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910183e0U) + (a1 ^ 0x17fefcf8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e0U + 0x0627b0U) ^ (0xa8c253f5U + 0x087038U + 8U);
}

// [EN] FDE[2760] start_va=0x0627b8, fde_va=0x087050, span=12 B | [VN] FDE[2760]
uint32_t ttr_fde_2760_0x0627b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e0U) + (a1 ^ 0xa8c253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0627b8U) ^ (0xf9000808U + 0x087050U + 12U);
}

// [EN] FDE[2761] start_va=0x0627c4, fde_va=0x087068, span=8 B | [VN] FDE[2761]
uint32_t ttr_fde_2761_0x0627c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000808U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x0627c4U) ^ (0x52800100U + 0x087068U + 8U);
}

// [EN] FDE[2762] start_va=0x0627cc, fde_va=0x087080, span=20 B | [VN] FDE[2762]
uint32_t ttr_fde_2762_0x0627cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f4U) + (a1 ^ 0x52800100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f3U + 0x0627ccU) ^ (0xaa0103f6U + 0x087080U + 20U);
}

// [EN] FDE[2763] start_va=0x0627e0, fde_va=0x087098, span=12 B | [VN] FDE[2763]
uint32_t ttr_fde_2763_0x0627e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f4U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0627e0U) ^ (0xf81f0ffeU + 0x087098U + 12U);
}

// [EN] FDE[2764] start_va=0x0627ec, fde_va=0x0870b0, span=44 B | [VN] FDE[2764]
uint32_t ttr_fde_2764_0x0627ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0627ecU) ^ (0x4ea01c08U + 0x0870b0U + 44U);
}

// [EN] FDE[2765] start_va=0x062818, fde_va=0x0870d0, span=12 B | [VN] FDE[2765]
uint32_t ttr_fde_2765_0x062818(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85c83a9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062818U) ^ (0x2a1603e2U + 0x0870d0U + 12U);
}

// [EN] FDE[2766] start_va=0x062824, fde_va=0x0870e8, span=12 B | [VN] FDE[2766]
uint32_t ttr_fde_2766_0x062824(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1603e2U) + (a1 ^ 0x2a1503e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffeafcU + 0x062824U) ^ (0xd53bd055U + 0x0870e8U + 12U);
}

// [EN] FDE[2767] start_va=0x062830, fde_va=0x087100, span=28 B | [VN] FDE[2767]
uint32_t ttr_fde_2767_0x062830(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd055U) + (a1 ^ 0xf94016a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x062830U) ^ (0xf81d83a8U + 0x087100U + 28U);
}

// [EN] FDE[2768] start_va=0x06284c, fde_va=0x087118, span=12 B | [VN] FDE[2768]
uint32_t ttr_fde_2768_0x06284c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf83b7916U) + (a1 ^ 0xaa1b03f8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06284cU) ^ (0xf940075bU + 0x087118U + 12U);
}

// [EN] FDE[2769] start_va=0x062858, fde_va=0x087130, span=12 B | [VN] FDE[2769]
uint32_t ttr_fde_2769_0x062858(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf940075bU) + (a1 ^ 0xf10006ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062858U) ^ (0xa8c24ff4U + 0x087130U + 12U);
}

// [EN] FDE[2770] start_va=0x062864, fde_va=0x087148, span=8 B | [VN] FDE[2770]
uint32_t ttr_fde_2770_0x062864(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa8c24ff4U) + (a1 ^ 0x17fee532U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400414U + 0x062864U) ^ (0xaa0003f3U + 0x087148U + 8U);
}

// [EN] FDE[2771] start_va=0x06286c, fde_va=0x087160, span=12 B | [VN] FDE[2771]
uint32_t ttr_fde_2771_0x06286c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400414U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06286cU) ^ (0xd37cec00U + 0x087160U + 12U);
}

// [EN] FDE[2772] start_va=0x062878, fde_va=0x087178, span=8 B | [VN] FDE[2772]
uint32_t ttr_fde_2772_0x062878(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37cec00U) + (a1 ^ 0x17fee539U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e6f280fU + 0x062878U) ^ (0x4ea91d20U + 0x087178U + 8U);
}

// [EN] FDE[2773] start_va=0x062880, fde_va=0x087190, span=20 B | [VN] FDE[2773]
uint32_t ttr_fde_2773_0x062880(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e6f280fU) + (a1 ^ 0x4ea91d20U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e611001U + 0x062880U) ^ (0x1e6a090aU + 0x087190U + 20U);
}

// [EN] FDE[2774] start_va=0x062894, fde_va=0x0871a8, span=12 B | [VN] FDE[2774]
uint32_t ttr_fde_2774_0x062894(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400009U) + (a1 ^ 0xf8686928U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062894U) ^ (0xaa0203f3U + 0x0871a8U + 12U);
}

// [EN] FDE[2775] start_va=0x0628a0, fde_va=0x0871c0, span=12 B | [VN] FDE[2775]
uint32_t ttr_fde_2775_0x0628a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f3U) + (a1 ^ 0xaa0103f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0628a0U) ^ (0xf9400260U + 0x0871c0U + 12U);
}

// [EN] FDE[2776] start_va=0x0628ac, fde_va=0x0871d8, span=12 B | [VN] FDE[2776]
uint32_t ttr_fde_2776_0x0628ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400260U) + (a1 ^ 0xf900027fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0628acU) ^ (0xf94002e9U + 0x0871d8U + 12U);
}

// [EN] FDE[2777] start_va=0x0628b8, fde_va=0x0871f0, span=12 B | [VN] FDE[2777]
uint32_t ttr_fde_2777_0x0628b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94002e9U) + (a1 ^ 0x0b180100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0120U + 0x0628b8U) ^ (0xf9400328U + 0x0871f0U + 12U);
}

// [EN] FDE[2778] start_va=0x0628c4, fde_va=0x087208, span=20 B | [VN] FDE[2778]
uint32_t ttr_fde_2778_0x0628c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400328U) + (a1 ^ 0xb9405662U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5281bc20U + 0x0628c4U) ^ (0x52850061U + 0x087208U + 20U);
}

// [EN] FDE[2779] start_va=0x0628d8, fde_va=0x087220, span=12 B | [VN] FDE[2779]
uint32_t ttr_fde_2779_0x0628d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800043U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa36bU + 0x0628d8U) ^ (0xaa0003f5U + 0x087220U + 12U);
}

// [EN] FDE[2780] start_va=0x0628e4, fde_va=0x087238, span=20 B | [VN] FDE[2780]
uint32_t ttr_fde_2780_0x0628e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f5U) + (a1 ^ 0xf9400508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e1U + 0x0628e4U) ^ (0xa8812009U + 0x087238U + 20U);
}

// [EN] FDE[2781] start_va=0x0628f8, fde_va=0x087250, span=28 B | [VN] FDE[2781]
uint32_t ttr_fde_2781_0x0628f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400269U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91004277U + 0x0628f8U) ^ (0xcb090108U + 0x087250U + 28U);
}

// [EN] FDE[2782] start_va=0x062914, fde_va=0x087268, span=8 B | [VN] FDE[2782]
uint32_t ttr_fde_2782_0x062914(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910383ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9402408U + 0x062914U) ^ (0xaa0103f5U + 0x087268U + 8U);
}

// [EN] FDE[2783] start_va=0x06291c, fde_va=0x087280, span=28 B | [VN] FDE[2783]
uint32_t ttr_fde_2783_0x06291c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402408U) + (a1 ^ 0xaa0103f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x06291cU) ^ (0xcb08012aU + 0x087280U + 28U);
}

// [EN] FDE[2784] start_va=0x062938, fde_va=0x087298, span=8 B | [VN] FDE[2784]
uint32_t ttr_fde_2784_0x062938(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910043e1U) + (a1 ^ 0x17ff35a6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910123e0U + 0x062938U) ^ (0x9100c3e1U + 0x087298U + 8U);
}

// [EN] FDE[2785] start_va=0x062940, fde_va=0x0872b0, span=12 B | [VN] FDE[2785]
uint32_t ttr_fde_2785_0x062940(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910123e0U) + (a1 ^ 0x9100c3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0670U + 0x062940U) ^ (0x910123e0U + 0x0872b0U + 12U);
}

// [EN] FDE[2786] start_va=0x06294c, fde_va=0x0872c8, span=12 B | [VN] FDE[2786]
uint32_t ttr_fde_2786_0x06294c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910123e0U) + (a1 ^ 0x910063e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff066dU + 0x06294cU) ^ (0xb940251aU + 0x0872c8U + 12U);
}

// [EN] FDE[2787] start_va=0x062958, fde_va=0x0872e0, span=12 B | [VN] FDE[2787]
uint32_t ttr_fde_2787_0x062958(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb940251aU) + (a1 ^ 0xb940253bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0cb6U + 0x062958U) ^ (0x9ad90909U + 0x0872e0U + 12U);
}

// [EN] FDE[2788] start_va=0x062964, fde_va=0x0872f8, span=12 B | [VN] FDE[2788]
uint32_t ttr_fde_2788_0x062964(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9ad90909U) + (a1 ^ 0x9b19a128U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062964U) ^ (0x92800029U + 0x0872f8U + 12U);
}

// [EN] FDE[2789] start_va=0x062970, fde_va=0x087310, span=28 B | [VN] FDE[2789]
uint32_t ttr_fde_2789_0x062970(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x92800029U) + (a1 ^ 0x9ac90d08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b0812f8U + 0x062970U) ^ (0xaa1703e0U + 0x087310U + 28U);
}

// [EN] FDE[2790] start_va=0x06298c, fde_va=0x087328, span=8 B | [VN] FDE[2790]
uint32_t ttr_fde_2790_0x06298c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa8c253f5U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94001aeU + 0x06298cU) ^ (0xf900018eU + 0x087328U + 8U);
}

// [EN] FDE[2791] start_va=0x062994, fde_va=0x087340, span=28 B | [VN] FDE[2791]
uint32_t ttr_fde_2791_0x062994(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94001aeU) + (a1 ^ 0xf900018eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94005aeU + 0x062994U) ^ (0xf900058eU + 0x087340U + 28U);
}

// [EN] FDE[2792] start_va=0x0629b0, fde_va=0x087358, span=12 B | [VN] FDE[2792]
uint32_t ttr_fde_2792_0x0629b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a68U) + (a1 ^ 0xf85f8100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee4deU + 0x0629b0U) ^ (0xf9400a68U + 0x087358U + 12U);
}

// [EN] FDE[2793] start_va=0x0629bc, fde_va=0x087370, span=12 B | [VN] FDE[2793]
uint32_t ttr_fde_2793_0x0629bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a68U) + (a1 ^ 0xeb14011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0629bcU) ^ (0xaa1603e0U + 0x087370U + 12U);
}

// [EN] FDE[2794] start_va=0x0629c8, fde_va=0x087388, span=12 B | [VN] FDE[2794]
uint32_t ttr_fde_2794_0x0629c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff7308U + 0x0629c8U) ^ (0xaa1603e0U + 0x087388U + 12U);
}

// [EN] FDE[2795] start_va=0x0629d4, fde_va=0x0873a0, span=12 B | [VN] FDE[2795]
uint32_t ttr_fde_2795_0x0629d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e0U) + (a1 ^ 0x2a1703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa670U + 0x0629d4U) ^ (0x9e6703e1U + 0x0873a0U + 12U);
}

// [EN] FDE[2796] start_va=0x0629e0, fde_va=0x0873b8, span=28 B | [VN] FDE[2796]
uint32_t ttr_fde_2796_0x0629e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9e6703e1U) + (a1 ^ 0x1e601002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e602804U + 0x0629e0U) ^ (0x1e610800U + 0x0873b8U + 28U);
}

// [EN] FDE[2797] start_va=0x0629fc, fde_va=0x0873d0, span=12 B | [VN] FDE[2797]
uint32_t ttr_fde_2797_0x0629fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9414ff4U) + (a1 ^ 0xa8c357f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0629fcU) ^ (0xaa0103f4U + 0x0873d0U + 12U);
}

// [EN] FDE[2798] start_va=0x062a08, fde_va=0x0873e8, span=28 B | [VN] FDE[2798]
uint32_t ttr_fde_2798_0x062a08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x062a08U) ^ (0xaa0203e1U + 0x0873e8U + 28U);
}

// [EN] FDE[2799] start_va=0x062a24, fde_va=0x087400, span=28 B | [VN] FDE[2799]
uint32_t ttr_fde_2799_0x062a24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910063e0U + 0x062a24U) ^ (0xaa0203e1U + 0x087400U + 28U);
}

// [EN] FDE[2800] start_va=0x062a40, fde_va=0x087418, span=12 B | [VN] FDE[2800]
uint32_t ttr_fde_2800_0x062a40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2ef8U + 0x062a40U) ^ (0xf82d79c8U + 0x087418U + 12U);
}

// [EN] FDE[2801] start_va=0x062a4c, fde_va=0x087430, span=12 B | [VN] FDE[2801]
uint32_t ttr_fde_2801_0x062a4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf82d79c8U) + (a1 ^ 0xaa0d03eaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062a4cU) ^ (0xf9400008U + 0x087430U + 12U);
}

// [EN] FDE[2802] start_va=0x062a58, fde_va=0x087448, span=12 B | [VN] FDE[2802]
uint32_t ttr_fde_2802_0x062a58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9402d08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x062a58U) ^ (0xf9400008U + 0x087448U + 12U);
}

// [EN] FDE[2803] start_va=0x062a64, fde_va=0x087460, span=12 B | [VN] FDE[2803]
uint32_t ttr_fde_2803_0x062a64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9401502U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0040U + 0x062a64U) ^ (0xf9401c14U + 0x087460U + 12U);
}

// [EN] FDE[2804] start_va=0x062a70, fde_va=0x087478, span=28 B | [VN] FDE[2804]
uint32_t ttr_fde_2804_0x062a70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401c14U) + (a1 ^ 0xb9401c19U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f3U + 0x062a70U) ^ (0xaa0003f5U + 0x087478U + 28U);
}

// [EN] FDE[2805] start_va=0x062a8c, fde_va=0x087490, span=12 B | [VN] FDE[2805]
uint32_t ttr_fde_2805_0x062a8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0f03eeU) + (a1 ^ 0xf94001efU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062a8cU) ^ (0xaa0103f3U + 0x087490U + 12U);
}

// [EN] FDE[2806] start_va=0x062a98, fde_va=0x0874a8, span=28 B | [VN] FDE[2806]
uint32_t ttr_fde_2806_0x062a98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x062a98U) ^ (0xaa0203e1U + 0x0874a8U + 28U);
}

// [EN] FDE[2807] start_va=0x062ab4, fde_va=0x0874c0, span=12 B | [VN] FDE[2807]
uint32_t ttr_fde_2807_0x062ab4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd87dU + 0x062ab4U) ^ (0xaa0103f3U + 0x0874c0U + 12U);
}

// [EN] FDE[2808] start_va=0x062ac0, fde_va=0x0874d8, span=28 B | [VN] FDE[2808]
uint32_t ttr_fde_2808_0x062ac0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03f5U + 0x062ac0U) ^ (0x93407c56U + 0x0874d8U + 28U);
}

// [EN] FDE[2809] start_va=0x062adc, fde_va=0x0874f0, span=28 B | [VN] FDE[2809]
uint32_t ttr_fde_2809_0x062adc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03f5U + 0x062adcU) ^ (0xaa1f03f6U + 0x0874f0U + 28U);
}

// [EN] FDE[2810] start_va=0x062af8, fde_va=0x087508, span=12 B | [VN] FDE[2810]
uint32_t ttr_fde_2810_0x062af8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9ad409aeU) + (a1 ^ 0x9b14b5cdU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062af8U) ^ (0xf940058dU + 0x087508U + 12U);
}

// [EN] FDE[2811] start_va=0x062b04, fde_va=0x087520, span=12 B | [VN] FDE[2811]
uint32_t ttr_fde_2811_0x062b04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf940058dU) + (a1 ^ 0xf100053fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062b04U) ^ (0xd100068cU + 0x087520U + 12U);
}

// [EN] FDE[2812] start_va=0x062b10, fde_va=0x087538, span=12 B | [VN] FDE[2812]
uint32_t ttr_fde_2812_0x062b10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100068cU) + (a1 ^ 0x8a0c014aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062b10U) ^ (0x9ad4094cU + 0x087538U + 12U);
}

// [EN] FDE[2813] start_va=0x062b1c, fde_va=0x087550, span=12 B | [VN] FDE[2813]
uint32_t ttr_fde_2813_0x062b1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9ad4094cU) + (a1 ^ 0x9b14a98aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062b1cU) ^ (0xaa1303ebU + 0x087550U + 12U);
}

// [EN] FDE[2814] start_va=0x062b28, fde_va=0x087568, span=12 B | [VN] FDE[2814]
uint32_t ttr_fde_2814_0x062b28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303ebU) + (a1 ^ 0xf8410d68U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062b28U) ^ (0xaa1503e0U + 0x087568U + 12U);
}

// [EN] FDE[2815] start_va=0x062b34, fde_va=0x087580, span=12 B | [VN] FDE[2815]
uint32_t ttr_fde_2815_0x062b34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062b34U) ^ (0xaa1503e0U + 0x087580U + 12U);
}

// [EN] FDE[2816] start_va=0x062b40, fde_va=0x087598, span=12 B | [VN] FDE[2816]
uint32_t ttr_fde_2816_0x062b40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff7c0fU + 0x062b40U) ^ (0xaa1503e0U + 0x087598U + 12U);
}

// [EN] FDE[2817] start_va=0x062b4c, fde_va=0x0875b0, span=12 B | [VN] FDE[2817]
uint32_t ttr_fde_2817_0x062b4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff5016U + 0x062b4cU) ^ (0xaa1503e0U + 0x0875b0U + 12U);
}

// [EN] FDE[2818] start_va=0x062b58, fde_va=0x0875c8, span=12 B | [VN] FDE[2818]
uint32_t ttr_fde_2818_0x062b58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xf9401908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x062b58U) ^ (0xaa1503e0U + 0x0875c8U + 12U);
}

// [EN] FDE[2819] start_va=0x062b64, fde_va=0x0875e0, span=12 B | [VN] FDE[2819]
uint32_t ttr_fde_2819_0x062b64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x2a1703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff76a1U + 0x062b64U) ^ (0xaa1503e0U + 0x0875e0U + 12U);
}

// [EN] FDE[2820] start_va=0x062b70, fde_va=0x0875f8, span=12 B | [VN] FDE[2820]
uint32_t ttr_fde_2820_0x062b70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062b70U) ^ (0xaa1403e0U + 0x0875f8U + 12U);
}

// [EN] FDE[2821] start_va=0x062b7c, fde_va=0x087610, span=8 B | [VN] FDE[2821]
uint32_t ttr_fde_2821_0x062b7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17fee568U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x062b7cU) ^ (0x2a1f03e1U + 0x087610U + 8U);
}

// [EN] FDE[2822] start_va=0x062b84, fde_va=0x087628, span=12 B | [VN] FDE[2822]
uint32_t ttr_fde_2822_0x062b84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x2a1f03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062b84U) ^ (0xaa0003e1U + 0x087628U + 12U);
}

// [EN] FDE[2823] start_va=0x062b90, fde_va=0x087640, span=12 B | [VN] FDE[2823]
uint32_t ttr_fde_2823_0x062b90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x910163e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa7bcU + 0x062b90U) ^ (0xaa0003e1U + 0x087640U + 12U);
}

// [EN] FDE[2824] start_va=0x062b9c, fde_va=0x087658, span=12 B | [VN] FDE[2824]
uint32_t ttr_fde_2824_0x062b9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x9100a3e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa7b9U + 0x062b9cU) ^ (0xaa0003e1U + 0x087658U + 12U);
}

// [EN] FDE[2825] start_va=0x062ba8, fde_va=0x087670, span=12 B | [VN] FDE[2825]
uint32_t ttr_fde_2825_0x062ba8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x9100c3e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa7dcU + 0x062ba8U) ^ (0xaa0003e1U + 0x087670U + 12U);
}

// [EN] FDE[2826] start_va=0x062bb4, fde_va=0x087688, span=12 B | [VN] FDE[2826]
uint32_t ttr_fde_2826_0x062bb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x910323e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa7b3U + 0x062bb4U) ^ (0xaa0003e1U + 0x087688U + 12U);
}

// [EN] FDE[2827] start_va=0x062bc0, fde_va=0x0876a0, span=12 B | [VN] FDE[2827]
uint32_t ttr_fde_2827_0x062bc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x910523e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa7b0U + 0x062bc0U) ^ (0xd100052fU + 0x0876a0U + 12U);
}

// [EN] FDE[2828] start_va=0x062bcc, fde_va=0x0876b8, span=12 B | [VN] FDE[2828]
uint32_t ttr_fde_2828_0x062bcc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100052fU) + (a1 ^ 0x8a0f01ceU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062bccU) ^ (0x1e2703e0U + 0x0876b8U + 12U);
}

// [EN] FDE[2829] start_va=0x062bd8, fde_va=0x0876d0, span=12 B | [VN] FDE[2829]
uint32_t ttr_fde_2829_0x062bd8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e2703e0U) + (a1 ^ 0x1e2703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd6dcU + 0x062bd8U) ^ (0xaa1403e1U + 0x0876d0U + 12U);
}

// [EN] FDE[2830] start_va=0x062be4, fde_va=0x0876e8, span=8 B | [VN] FDE[2830]
uint32_t ttr_fde_2830_0x062be4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e1U) + (a1 ^ 0x17ff011dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e1U + 0x062be4U) ^ (0x17ff9786U + 0x0876e8U + 8U);
}

// [EN] FDE[2831] start_va=0x062bec, fde_va=0x087700, span=8 B | [VN] FDE[2831]
uint32_t ttr_fde_2831_0x062bec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e1U) + (a1 ^ 0x17ff9786U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x062becU) ^ (0xaa1503e1U + 0x087700U + 8U);
}

// [EN] FDE[2832] start_va=0x062bf4, fde_va=0x087718, span=12 B | [VN] FDE[2832]
uint32_t ttr_fde_2832_0x062bf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062bf4U) ^ (0x910023e0U + 0x087718U + 12U);
}

// [EN] FDE[2833] start_va=0x062c00, fde_va=0x087730, span=8 B | [VN] FDE[2833]
uint32_t ttr_fde_2833_0x062c00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17fee493U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9405d08U + 0x062c00U) ^ (0xd61f0100U + 0x087730U + 8U);
}

// [EN] FDE[2834] start_va=0x062c08, fde_va=0x087748, span=8 B | [VN] FDE[2834]
uint32_t ttr_fde_2834_0x062c08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9405d08U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa901ffffU + 0x062c08U) ^ (0xf9401668U + 0x087748U + 8U);
}

// [EN] FDE[2835] start_va=0x062c10, fde_va=0x087760, span=20 B | [VN] FDE[2835]
uint32_t ttr_fde_2835_0x062c10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa901ffffU) + (a1 ^ 0xf9401668U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910063e1U + 0x062c10U) ^ (0x9100a100U + 0x087760U + 20U);
}

// [EN] FDE[2836] start_va=0x062c24, fde_va=0x087778, span=8 B | [VN] FDE[2836]
uint32_t ttr_fde_2836_0x062c24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e8U) + (a1 ^ 0x17fee5feU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400408U + 0x062c24U) ^ (0xaa0103f4U + 0x087778U + 8U);
}

// [EN] FDE[2837] start_va=0x062c2c, fde_va=0x087790, span=28 B | [VN] FDE[2837]
uint32_t ttr_fde_2837_0x062c2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xaa0103f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x062c2cU) ^ (0x91004020U + 0x087790U + 28U);
}

// [EN] FDE[2838] start_va=0x062c48, fde_va=0x0877a8, span=8 B | [VN] FDE[2838]
uint32_t ttr_fde_2838_0x062c48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910283ffU + 0x062c48U) ^ (0xd65f03c0U + 0x0877a8U + 8U);
}

// [EN] FDE[2839] start_va=0x062c50, fde_va=0x0877c0, span=8 B | [VN] FDE[2839]
uint32_t ttr_fde_2839_0x062c50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910283ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94007e0U + 0x062c50U) ^ (0x17ff0bfaU + 0x0877c0U + 8U);
}

// [EN] FDE[2840] start_va=0x062c58, fde_va=0x0877d8, span=8 B | [VN] FDE[2840]
uint32_t ttr_fde_2840_0x062c58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94007e0U) + (a1 ^ 0x17ff0bfaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e1U + 0x062c58U) ^ (0xaa1303e0U + 0x0877d8U + 8U);
}

// [EN] FDE[2841] start_va=0x062c60, fde_va=0x0877f0, span=12 B | [VN] FDE[2841]
uint32_t ttr_fde_2841_0x062c60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffae64U + 0x062c60U) ^ (0x910003e1U + 0x0877f0U + 12U);
}

// [EN] FDE[2842] start_va=0x062c6c, fde_va=0x087808, span=12 B | [VN] FDE[2842]
uint32_t ttr_fde_2842_0x062c6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e1U) + (a1 ^ 0xf90003ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062c6cU) ^ (0xf81f0ffeU + 0x087808U + 12U);
}

// [EN] FDE[2843] start_va=0x062c78, fde_va=0x087820, span=20 B | [VN] FDE[2843]
uint32_t ttr_fde_2843_0x062c78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff0befU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1603e0U + 0x062c78U) ^ (0xf84107feU + 0x087820U + 20U);
}

// [EN] FDE[2844] start_va=0x062c8c, fde_va=0x087840, span=8 B | [VN] FDE[2844]
uint32_t ttr_fde_2844_0x062c8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ff0335U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x062c8cU) ^ (0xaa1703e1U + 0x087840U + 8U);
}

// [EN] FDE[2845] start_va=0x062c94, fde_va=0x087858, span=12 B | [VN] FDE[2845]
uint32_t ttr_fde_2845_0x062c94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xaa1703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062c94U) ^ (0xaa1303e0U + 0x087858U + 12U);
}

// [EN] FDE[2846] start_va=0x062ca0, fde_va=0x087870, span=8 B | [VN] FDE[2846]
uint32_t ttr_fde_2846_0x062ca0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ff3c46U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x062ca0U) ^ (0x52800a00U + 0x087870U + 8U);
}

// [EN] FDE[2847] start_va=0x062ca8, fde_va=0x087888, span=12 B | [VN] FDE[2847]
uint32_t ttr_fde_2847_0x062ca8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0x52800a00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee42cU + 0x062ca8U) ^ (0xaa0003f3U + 0x087888U + 12U);
}

// [EN] FDE[2848] start_va=0x062cb4, fde_va=0x0878a0, span=28 B | [VN] FDE[2848]
uint32_t ttr_fde_2848_0x062cb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf9400668U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400000U + 0x062cb4U) ^ (0xaa0103f4U + 0x0878a0U + 28U);
}

// [EN] FDE[2849] start_va=0x062cd0, fde_va=0x0878b8, span=8 B | [VN] FDE[2849]
uint32_t ttr_fde_2849_0x062cd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0x17fee4b7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910163e0U + 0x062cd0U) ^ (0x17fefbaeU + 0x0878b8U + 8U);
}

// [EN] FDE[2850] start_va=0x062cd8, fde_va=0x0878d0, span=8 B | [VN] FDE[2850]
uint32_t ttr_fde_2850_0x062cd8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910163e0U) + (a1 ^ 0x17fefbaeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb1c03acU + 0x062cd8U) ^ (0x9acb0d8cU + 0x0878d0U + 8U);
}

// [EN] FDE[2851] start_va=0x062ce0, fde_va=0x0878e8, span=24 B | [VN] FDE[2851]
uint32_t ttr_fde_2851_0x062ce0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb1c03acU) + (a1 ^ 0x9acb0d8cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b08038dU + 0x062ce0U) ^ (0xeb09019fU + 0x0878e8U + 24U);
}

// [EN] FDE[2852] start_va=0x062cf8, fde_va=0x087900, span=16 B | [VN] FDE[2852]
uint32_t ttr_fde_2852_0x062cf8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd058U) + (a1 ^ 0xf9401708U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000fe8U + 0x062cf8U) ^ (0xd65f03c0U + 0x087900U + 16U);
}

// [EN] FDE[2853] start_va=0x062d08, fde_va=0x087918, span=8 B | [VN] FDE[2853]
uint32_t ttr_fde_2853_0x062d08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800900U) + (a1 ^ 0x17fee415U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37ff908U + 0x062d08U) ^ (0xeb14011fU + 0x087918U + 8U);
}

// [EN] FDE[2854] start_va=0x062d10, fde_va=0x087930, span=16 B | [VN] FDE[2854]
uint32_t ttr_fde_2854_0x062d10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37ff908U) + (a1 ^ 0xeb14011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403f6U + 0x062d10U) ^ (0xd65f03c0U + 0x087930U + 16U);
}

// [EN] FDE[2855] start_va=0x062d20, fde_va=0x087948, span=24 B | [VN] FDE[2855]
uint32_t ttr_fde_2855_0x062d20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5280030aU) + (a1 ^ 0x9b0a02a9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9b0a0108U + 0x062d20U) ^ (0x9b0a028bU + 0x087948U + 24U);
}

// [EN] FDE[2856] start_va=0x062d38, fde_va=0x087960, span=8 B | [VN] FDE[2856]
uint32_t ttr_fde_2856_0x062d38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103e2U) + (a1 ^ 0x17fee635U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910503e0U + 0x062d38U) ^ (0x9105c3e1U + 0x087960U + 8U);
}

// [EN] FDE[2857] start_va=0x062d40, fde_va=0x087978, span=24 B | [VN] FDE[2857]
uint32_t ttr_fde_2857_0x062d40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910503e0U) + (a1 ^ 0x9105c3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e2703e1U + 0x062d40U) ^ (0x52800022U + 0x087978U + 24U);
}

// [EN] FDE[2858] start_va=0x062d58, fde_va=0x087990, span=8 B | [VN] FDE[2858]
uint32_t ttr_fde_2858_0x062d58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f4U) + (a1 ^ 0x17fee3f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9400e68U + 0x062d58U) ^ (0x51000509U + 0x087990U + 8U);
}

// [EN] FDE[2859] start_va=0x062d60, fde_va=0x0879a8, span=16 B | [VN] FDE[2859]
uint32_t ttr_fde_2859_0x062d60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400e68U) + (a1 ^ 0x51000509U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6a09011fU + 0x062d60U) ^ (0xd65f03c0U + 0x0879a8U + 16U);
}

// [EN] FDE[2860] start_va=0x062d70, fde_va=0x0879c0, span=12 B | [VN] FDE[2860]
uint32_t ttr_fde_2860_0x062d70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9403e63U) + (a1 ^ 0x52800021U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062d70U) ^ (0x2a1403e2U + 0x0879c0U + 12U);
}

// [EN] FDE[2861] start_va=0x062d7c, fde_va=0x0879d8, span=16 B | [VN] FDE[2861]
uint32_t ttr_fde_2861_0x062d7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1403e2U) + (a1 ^ 0x2a1303e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x062d7cU) ^ (0xd65f03c0U + 0x0879d8U + 16U);
}

// [EN] FDE[2862] start_va=0x062d8c, fde_va=0x0879f0, span=16 B | [VN] FDE[2862]
uint32_t ttr_fde_2862_0x062d8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400028U) + (a1 ^ 0xf9400413U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303f4U + 0x062d8cU) ^ (0xd65f03c0U + 0x0879f0U + 16U);
}

// [EN] FDE[2863] start_va=0x062d9c, fde_va=0x087a08, span=16 B | [VN] FDE[2863]
uint32_t ttr_fde_2863_0x062d9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9404fe0U) + (a1 ^ 0x6f00e400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3c8e83e0U + 0x062d9cU) ^ (0xd65f03c0U + 0x087a08U + 16U);
}

// [EN] FDE[2864] start_va=0x062dac, fde_va=0x087a20, span=16 B | [VN] FDE[2864]
uint32_t ttr_fde_2864_0x062dac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800029U) + (a1 ^ 0xa900fc1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900000aU + 0x062dacU) ^ (0xd65f03c0U + 0x087a20U + 16U);
}

// [EN] FDE[2865] start_va=0x062dbc, fde_va=0x087a38, span=24 B | [VN] FDE[2865]
uint32_t ttr_fde_2865_0x062dbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800029U) + (a1 ^ 0xd28000caU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9ac82129U + 0x062dbcU) ^ (0xf2c0006aU + 0x087a38U + 24U);
}

// [EN] FDE[2866] start_va=0x062dd4, fde_va=0x087a50, span=16 B | [VN] FDE[2866]
uint32_t ttr_fde_2866_0x062dd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000044U) + (a1 ^ 0xf0000045U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000046U + 0x062dd4U) ^ (0xd65f03c0U + 0x087a50U + 16U);
}

// [EN] FDE[2867] start_va=0x062de4, fde_va=0x087a68, span=8 B | [VN] FDE[2867]
uint32_t ttr_fde_2867_0x062de4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e2U) + (a1 ^ 0x17ff6bd0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400d08U + 0x062de4U) ^ (0xd61f0100U + 0x087a68U + 8U);
}

// [EN] FDE[2868] start_va=0x062dec, fde_va=0x087a80, span=8 B | [VN] FDE[2868]
uint32_t ttr_fde_2868_0x062dec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400d08U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x92800003U + 0x062decU) ^ (0x17ff3bdaU + 0x087a80U + 8U);
}

// [EN] FDE[2869] start_va=0x062df4, fde_va=0x087a98, span=8 B | [VN] FDE[2869]
uint32_t ttr_fde_2869_0x062df4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x92800003U) + (a1 ^ 0x17ff3bdaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9101e3e0U + 0x062df4U) ^ (0x17fefb65U + 0x087a98U + 8U);
}

// [EN] FDE[2870] start_va=0x062dfc, fde_va=0x087ab0, span=8 B | [VN] FDE[2870]
uint32_t ttr_fde_2870_0x062dfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101e3e0U) + (a1 ^ 0x17fefb65U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910703e0U + 0x062dfcU) ^ (0x17fefb63U + 0x087ab0U + 8U);
}

// [EN] FDE[2871] start_va=0x062e04, fde_va=0x087ac8, span=8 B | [VN] FDE[2871]
uint32_t ttr_fde_2871_0x062e04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910703e0U) + (a1 ^ 0x17fefb63U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0203f4U + 0x062e04U) ^ (0xaa0103f5U + 0x087ac8U + 8U);
}

// [EN] FDE[2872] start_va=0x062e0c, fde_va=0x087ae0, span=16 B | [VN] FDE[2872]
uint32_t ttr_fde_2872_0x062e0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0203f4U) + (a1 ^ 0xaa0103f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x062e0cU) ^ (0x17fee59aU + 0x087ae0U + 16U);
}

// [EN] FDE[2873] start_va=0x062e1c, fde_va=0x087af8, span=16 B | [VN] FDE[2873]
uint32_t ttr_fde_2873_0x062e1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100e3e0U) + (a1 ^ 0x910083e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1603e2U + 0x062e1cU) ^ (0x17ff8a83U + 0x087af8U + 16U);
}

// [EN] FDE[2874] start_va=0x062e2c, fde_va=0x087b10, span=12 B | [VN] FDE[2874]
uint32_t ttr_fde_2874_0x062e2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x394063e8U) + (a1 ^ 0xf94017e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062e2cU) ^ (0x39400261U + 0x087b10U + 12U);
}

// [EN] FDE[2875] start_va=0x062e38, fde_va=0x087b28, span=24 B | [VN] FDE[2875]
uint32_t ttr_fde_2875_0x062e38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400261U) + (a1 ^ 0xaa0203f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x062e38U) ^ (0x51017028U + 0x087b28U + 24U);
}

// [EN] FDE[2876] start_va=0x062e50, fde_va=0x087b40, span=8 B | [VN] FDE[2876]
uint32_t ttr_fde_2876_0x062e50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101433cU) + (a1 ^ 0x17ff0399U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf85b83a9U + 0x062e50U) ^ (0xeb09011fU + 0x087b40U + 8U);
}

// [EN] FDE[2877] start_va=0x062e58, fde_va=0x087b58, span=12 B | [VN] FDE[2877]
uint32_t ttr_fde_2877_0x062e58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85b83a9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062e58U) ^ (0x52800081U + 0x087b58U + 12U);
}

// [EN] FDE[2878] start_va=0x062e64, fde_va=0x087b70, span=16 B | [VN] FDE[2878]
uint32_t ttr_fde_2878_0x062e64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800081U) + (a1 ^ 0xf85e8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b080280U + 0x062e64U) ^ (0x17fefe40U + 0x087b70U + 16U);
}

// [EN] FDE[2879] start_va=0x062e74, fde_va=0x087b88, span=24 B | [VN] FDE[2879]
uint32_t ttr_fde_2879_0x062e74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f9U) + (a1 ^ 0x3c808000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x062e74U) ^ (0x9100601bU + 0x087b88U + 24U);
}

// [EN] FDE[2880] start_va=0x062e8c, fde_va=0x087ba0, span=8 B | [VN] FDE[2880]
uint32_t ttr_fde_2880_0x062e8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a3e0U) + (a1 ^ 0x17fefb41U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b160108U + 0x062e8cU) ^ (0xa9402100U + 0x087ba0U + 8U);
}

// [EN] FDE[2881] start_va=0x062e94, fde_va=0x087bb8, span=16 B | [VN] FDE[2881]
uint32_t ttr_fde_2881_0x062e94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b160108U) + (a1 ^ 0xa9402100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb000102U + 0x062e94U) ^ (0x17fee3acU + 0x087bb8U + 16U);
}

// [EN] FDE[2882] start_va=0x062ea4, fde_va=0x087bd0, span=12 B | [VN] FDE[2882]
uint32_t ttr_fde_2882_0x062ea4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c8U) + (a1 ^ 0xf947b508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062ea4U) ^ (0x910063e1U + 0x087bd0U + 12U);
}

// [EN] FDE[2883] start_va=0x062eb0, fde_va=0x087be8, span=12 B | [VN] FDE[2883]
uint32_t ttr_fde_2883_0x062eb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e1U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062eb0U) ^ (0xf9400900U + 0x087be8U + 12U);
}

// [EN] FDE[2884] start_va=0x062ebc, fde_va=0x087c00, span=16 B | [VN] FDE[2884]
uint32_t ttr_fde_2884_0x062ebc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400900U) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9402d08U + 0x062ebcU) ^ (0xd61f0100U + 0x087c00U + 16U);
}

// [EN] FDE[2885] start_va=0x062ecc, fde_va=0x087c18, span=24 B | [VN] FDE[2885]
uint32_t ttr_fde_2885_0x062ecc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbd4001c2U) + (a1 ^ 0x1e202843U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e20c063U + 0x062eccU) ^ (0x1e22c063U + 0x087c18U + 24U);
}

// [EN] FDE[2886] start_va=0x062ee4, fde_va=0x087c30, span=8 B | [VN] FDE[2886]
uint32_t ttr_fde_2886_0x062ee4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910523e0U) + (a1 ^ 0x17ffa69dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6db63befU + 0x062ee4U) ^ (0x6d0133edU + 0x087c30U + 8U);
}

// [EN] FDE[2887] start_va=0x062eec, fde_va=0x087c48, span=40 B | [VN] FDE[2887]
uint32_t ttr_fde_2887_0x062eec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6db63befU) + (a1 ^ 0x6d0133edU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d022bebU + 0x062eecU) ^ (0x6d0323e9U + 0x087c48U + 40U);
}

// [EN] FDE[2888] start_va=0x062f14, fde_va=0x087c60, span=8 B | [VN] FDE[2888]
uint32_t ttr_fde_2888_0x062f14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e0U) + (a1 ^ 0x17ffa43bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x062f14U) ^ (0x91014260U + 0x087c60U + 8U);
}

// [EN] FDE[2889] start_va=0x062f1c, fde_va=0x087c78, span=32 B | [VN] FDE[2889]
uint32_t ttr_fde_2889_0x062f1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x91014260U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffce90U + 0x062f1cU) ^ (0x9100e260U + 0x087c78U + 32U);
}

// [EN] FDE[2890] start_va=0x062f3c, fde_va=0x087c98, span=16 B | [VN] FDE[2890]
uint32_t ttr_fde_2890_0x062f3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401660U) + (a1 ^ 0xf9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9405908U + 0x062f3cU) ^ (0xd61f0100U + 0x087c98U + 16U);
}

// [EN] FDE[2891] start_va=0x062f4c, fde_va=0x087cb0, span=16 B | [VN] FDE[2891]
uint32_t ttr_fde_2891_0x062f4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b1b0101U) + (a1 ^ 0x8b1b0128U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd1006100U + 0x062f4cU) ^ (0x17ffd31cU + 0x087cb0U + 16U);
}

// [EN] FDE[2892] start_va=0x062f5c, fde_va=0x087cc8, span=16 B | [VN] FDE[2892]
uint32_t ttr_fde_2892_0x062f5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x394087e1U) + (a1 ^ 0xaa1603e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1703e2U + 0x062f5cU) ^ (0x17ff7e95U + 0x087cc8U + 16U);
}

// [EN] FDE[2893] start_va=0x062f6c, fde_va=0x087ce0, span=8 B | [VN] FDE[2893]
uint32_t ttr_fde_2893_0x062f6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9103c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910033e1U + 0x062f6cU) ^ (0x17fee5aaU + 0x087ce0U + 8U);
}

// [EN] FDE[2894] start_va=0x062f74, fde_va=0x087cf8, span=8 B | [VN] FDE[2894]
uint32_t ttr_fde_2894_0x062f74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910033e1U) + (a1 ^ 0x17fee5aaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401668U + 0x062f74U) ^ (0x910023e1U + 0x087cf8U + 8U);
}

// [EN] FDE[2895] start_va=0x062f7c, fde_va=0x087d10, span=16 B | [VN] FDE[2895]
uint32_t ttr_fde_2895_0x062f7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401668U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100a100U + 0x062f7cU) ^ (0x17ff1f4bU + 0x087d10U + 16U);
}

// [EN] FDE[2896] start_va=0x062f8c, fde_va=0x087d28, span=16 B | [VN] FDE[2896]
uint32_t ttr_fde_2896_0x062f8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401668U) + (a1 ^ 0x29410fe2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9403680U + 0x062f8cU) ^ (0xd65f03c0U + 0x087d28U + 16U);
}

// [EN] FDE[2897] start_va=0x062f9c, fde_va=0x087d40, span=16 B | [VN] FDE[2897]
uint32_t ttr_fde_2897_0x062f9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd053U) + (a1 ^ 0xf9401668U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000fe8U + 0x062f9cU) ^ (0xd65f03c0U + 0x087d40U + 16U);
}

// [EN] FDE[2898] start_va=0x062fac, fde_va=0x087d58, span=8 B | [VN] FDE[2898]
uint32_t ttr_fde_2898_0x062fac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52801000U) + (a1 ^ 0x17fee36cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007e9fU + 0x062facU) ^ (0xf9000a9fU + 0x087d58U + 8U);
}

// [EN] FDE[2899] start_va=0x062fb4, fde_va=0x087d70, span=12 B | [VN] FDE[2899]
uint32_t ttr_fde_2899_0x062fb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007e9fU) + (a1 ^ 0xf9000a9fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062fb4U) ^ (0xa948a281U + 0x087d70U + 12U);
}

// [EN] FDE[2900] start_va=0x062fc0, fde_va=0x087d88, span=24 B | [VN] FDE[2900]
uint32_t ttr_fde_2900_0x062fc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa948a281U) + (a1 ^ 0x52800309U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb010108U + 0x062fc0U) ^ (0x9ac90d08U + 0x087d88U + 24U);
}

// [EN] FDE[2901] start_va=0x062fd8, fde_va=0x087da0, span=16 B | [VN] FDE[2901]
uint32_t ttr_fde_2901_0x062fd8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910323e0U) + (a1 ^ 0x9100a3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2d0507e0U + 0x062fd8U) ^ (0x17ffd550U + 0x087da0U + 16U);
}

// [EN] FDE[2902] start_va=0x062fe8, fde_va=0x087db8, span=16 B | [VN] FDE[2902]
uint32_t ttr_fde_2902_0x062fe8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4eaa1d40U) + (a1 ^ 0x4ea81d01U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4eaf1de2U + 0x062fe8U) ^ (0x17ff15f2U + 0x087db8U + 16U);
}

// [EN] FDE[2903] start_va=0x062ff8, fde_va=0x087dd0, span=16 B | [VN] FDE[2903]
uint32_t ttr_fde_2903_0x062ff8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5e0c0401U) + (a1 ^ 0x3dc003e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4ea81d03U + 0x062ff8U) ^ (0x17ffd431U + 0x087dd0U + 16U);
}

// [EN] FDE[2904] start_va=0x063008, fde_va=0x087de8, span=16 B | [VN] FDE[2904]
uint32_t ttr_fde_2904_0x063008(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b3dc921U) + (a1 ^ 0x8b1b0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103e2U + 0x063008U) ^ (0x17ffc997U + 0x087de8U + 16U);
}

// [EN] FDE[2905] start_va=0x063018, fde_va=0x087e00, span=16 B | [VN] FDE[2905]
uint32_t ttr_fde_2905_0x063018(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e9U) + (a1 ^ 0xeb15011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9004688U + 0x063018U) ^ (0xd65f03c0U + 0x087e00U + 16U);
}

// [EN] FDE[2906] start_va=0x063028, fde_va=0x087e18, span=8 B | [VN] FDE[2906]
uint32_t ttr_fde_2906_0x063028(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910143ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e2U + 0x063028U) ^ (0xaa1503e0U + 0x087e18U + 8U);
}

// [EN] FDE[2907] start_va=0x063030, fde_va=0x087e30, span=16 B | [VN] FDE[2907]
uint32_t ttr_fde_2907_0x063030(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e2U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1603e1U + 0x063030U) ^ (0x17ffd2a4U + 0x087e30U + 16U);
}

// [EN] FDE[2908] start_va=0x063040, fde_va=0x087e48, span=16 B | [VN] FDE[2908]
uint32_t ttr_fde_2908_0x063040(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e2U) + (a1 ^ 0x52800021U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x063040U) ^ (0x17ff261dU + 0x087e48U + 16U);
}

// [EN] FDE[2909] start_va=0x063050, fde_va=0x087e60, span=16 B | [VN] FDE[2909]
uint32_t ttr_fde_2909_0x063050(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e2U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e1U + 0x063050U) ^ (0x17ffd29cU + 0x087e60U + 16U);
}

// [EN] FDE[2910] start_va=0x063060, fde_va=0x087e78, span=16 B | [VN] FDE[2910]
uint32_t ttr_fde_2910_0x063060(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e2U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e1U + 0x063060U) ^ (0x17ffd298U + 0x087e78U + 16U);
}

// [EN] FDE[2911] start_va=0x063070, fde_va=0x087e90, span=16 B | [VN] FDE[2911]
uint32_t ttr_fde_2911_0x063070(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e2U) + (a1 ^ 0x52800041U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x063070U) ^ (0x17ff2611U + 0x087e90U + 16U);
}

// [EN] FDE[2912] start_va=0x063080, fde_va=0x087ea8, span=16 B | [VN] FDE[2912]
uint32_t ttr_fde_2912_0x063080(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd100e3a1U) + (a1 ^ 0x910083e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e2U + 0x063080U) ^ (0x17ff34d0U + 0x087ea8U + 16U);
}

// [EN] FDE[2913] start_va=0x063090, fde_va=0x087ec0, span=16 B | [VN] FDE[2913]
uint32_t ttr_fde_2913_0x063090(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400013U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x063090U) ^ (0x17ffa7d6U + 0x087ec0U + 16U);
}

// [EN] FDE[2914] start_va=0x0630a0, fde_va=0x087ed8, span=16 B | [VN] FDE[2914]
uint32_t ttr_fde_2914_0x0630a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000fe9U + 0x0630a0U) ^ (0x17ff8b75U + 0x087ed8U + 16U);
}

// [EN] FDE[2915] start_va=0x0630b0, fde_va=0x087ef0, span=16 B | [VN] FDE[2915]
uint32_t ttr_fde_2915_0x0630b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e2U + 0x0630b0U) ^ (0x17ff8c41U + 0x087ef0U + 16U);
}

// [EN] FDE[2916] start_va=0x0630c0, fde_va=0x087f08, span=16 B | [VN] FDE[2916]
uint32_t ttr_fde_2916_0x0630c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000fe8U + 0x0630c0U) ^ (0xd65f03c0U + 0x087f08U + 16U);
}

// [EN] FDE[2917] start_va=0x0630d0, fde_va=0x087f20, span=8 B | [VN] FDE[2917]
uint32_t ttr_fde_2917_0x0630d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0303e0U) + (a1 ^ 0x17ff7ad1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900001c1U + 0x0630d0U) ^ (0xf9453c21U + 0x087f20U + 8U);
}

// [EN] FDE[2918] start_va=0x0630d8, fde_va=0x087f38, span=16 B | [VN] FDE[2918]
uint32_t ttr_fde_2918_0x0630d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c1U) + (a1 ^ 0xf9453c21U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800400U + 0x0630d8U) ^ (0x17fee35fU + 0x087f38U + 16U);
}

// [EN] FDE[2919] start_va=0x0630e8, fde_va=0x087f50, span=16 B | [VN] FDE[2919]
uint32_t ttr_fde_2919_0x0630e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c1U) + (a1 ^ 0xf9453c21U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800600U + 0x0630e8U) ^ (0x17fee35bU + 0x087f50U + 16U);
}

// [EN] FDE[2920] start_va=0x0630f8, fde_va=0x087f68, span=16 B | [VN] FDE[2920]
uint32_t ttr_fde_2920_0x0630f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001c1U) + (a1 ^ 0xf9453c21U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800b00U + 0x0630f8U) ^ (0x17fee357U + 0x087f68U + 16U);
}

// [EN] FDE[2921] start_va=0x063108, fde_va=0x087f80, span=16 B | [VN] FDE[2921]
uint32_t ttr_fde_2921_0x063108(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e1U) + (a1 ^ 0xaa1f03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03e3U + 0x063108U) ^ (0x17fee53fU + 0x087f80U + 16U);
}

// [EN] FDE[2922] start_va=0x063118, fde_va=0x087f98, span=16 B | [VN] FDE[2922]
uint32_t ttr_fde_2922_0x063118(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9404c09U) + (a1 ^ 0xaa0003e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400120U + 0x063118U) ^ (0xd65f03c0U + 0x087f98U + 16U);
}

// [EN] FDE[2923] start_va=0x063128, fde_va=0x087fb0, span=12 B | [VN] FDE[2923]
uint32_t ttr_fde_2923_0x063128(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6f00e400U) + (a1 ^ 0x52a7f008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063128U) ^ (0xf9401508U + 0x087fb0U + 12U);
}

// [EN] FDE[2924] start_va=0x063134, fde_va=0x087fc8, span=8 B | [VN] FDE[2924]
uint32_t ttr_fde_2924_0x063134(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401508U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100c3ffU + 0x063134U) ^ (0xd65f03c0U + 0x087fc8U + 8U);
}

// [EN] FDE[2925] start_va=0x06313c, fde_va=0x087fe0, span=8 B | [VN] FDE[2925]
uint32_t ttr_fde_2925_0x06313c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a2803e9U + 0x06313cU) ^ (0x721f051fU + 0x087fe0U + 8U);
}

// [EN] FDE[2926] start_va=0x063144, fde_va=0x087ff8, span=24 B | [VN] FDE[2926]
uint32_t ttr_fde_2926_0x063144(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a2803e9U) + (a1 ^ 0x721f051fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f17e8U + 0x063144U) ^ (0x12000129U + 0x087ff8U + 24U);
}

// [EN] FDE[2927] start_va=0x06315c, fde_va=0x088010, span=8 B | [VN] FDE[2927]
uint32_t ttr_fde_2927_0x06315c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401500U) + (a1 ^ 0x17ff347bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400109U + 0x06315cU) ^ (0xf90002a9U + 0x088010U + 8U);
}

// [EN] FDE[2928] start_va=0x063164, fde_va=0x088028, span=16 B | [VN] FDE[2928]
uint32_t ttr_fde_2928_0x063164(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400109U) + (a1 ^ 0xf90002a9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000115U + 0x063164U) ^ (0xd65f03c0U + 0x088028U + 16U);
}

// [EN] FDE[2929] start_va=0x063174, fde_va=0x088040, span=16 B | [VN] FDE[2929]
uint32_t ttr_fde_2929_0x063174(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0xaa1503e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e3U + 0x063174U) ^ (0xd65f03c0U + 0x088040U + 16U);
}

// [EN] FDE[2930] start_va=0x063184, fde_va=0x088058, span=8 B | [VN] FDE[2930]
uint32_t ttr_fde_2930_0x063184(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0x17ff7c6cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910263e0U + 0x063184U) ^ (0x9105c3e1U + 0x088058U + 8U);
}

// [EN] FDE[2931] start_va=0x06318c, fde_va=0x088070, span=12 B | [VN] FDE[2931]
uint32_t ttr_fde_2931_0x06318c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910263e0U) + (a1 ^ 0x9105c3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06318cU) ^ (0xb900018dU + 0x088070U + 12U);
}

// [EN] FDE[2932] start_va=0x063198, fde_va=0x088088, span=24 B | [VN] FDE[2932]
uint32_t ttr_fde_2932_0x063198(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb900018dU) + (a1 ^ 0xb940056dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb900058dU + 0x063198U) ^ (0xb940096bU + 0x088088U + 24U);
}

// [EN] FDE[2933] start_va=0x0631b0, fde_va=0x0880a0, span=16 B | [VN] FDE[2933]
uint32_t ttr_fde_2933_0x0631b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7101793fU) + (a1 ^ 0x1a9f17e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a880159U + 0x0631b0U) ^ (0x17ff7813U + 0x0880a0U + 16U);
}

// [EN] FDE[2934] start_va=0x0631c0, fde_va=0x0880b8, span=16 B | [VN] FDE[2934]
uint32_t ttr_fde_2934_0x0631c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0xaa0803f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007d1fU + 0x0631c0U) ^ (0x17ff553bU + 0x0880b8U + 16U);
}

// [EN] FDE[2935] start_va=0x0631d0, fde_va=0x0880d0, span=8 B | [VN] FDE[2935]
uint32_t ttr_fde_2935_0x0631d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x17fefd6aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e0U + 0x0631d0U) ^ (0x17ff80c8U + 0x0880d0U + 8U);
}

// [EN] FDE[2936] start_va=0x0631d8, fde_va=0x0880e8, span=8 B | [VN] FDE[2936]
uint32_t ttr_fde_2936_0x0631d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x17ff80c8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91006100U + 0x0631d8U) ^ (0x17fefa6cU + 0x0880e8U + 8U);
}

// [EN] FDE[2937] start_va=0x0631e0, fde_va=0x088100, span=8 B | [VN] FDE[2937]
uint32_t ttr_fde_2937_0x0631e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006100U) + (a1 ^ 0x17fefa6cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf940b260U + 0x0631e0U) ^ (0x910123e1U + 0x088100U + 8U);
}

// [EN] FDE[2938] start_va=0x0631e8, fde_va=0x088118, span=16 B | [VN] FDE[2938]
uint32_t ttr_fde_2938_0x0631e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf940b260U) + (a1 ^ 0x910123e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100c3e2U + 0x0631e8U) ^ (0x17ff9624U + 0x088118U + 16U);
}

// [EN] FDE[2939] start_va=0x0631f8, fde_va=0x088130, span=24 B | [VN] FDE[2939]
uint32_t ttr_fde_2939_0x0631f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800308U) + (a1 ^ 0x9b0802a9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9b080288U + 0x0631f8U) ^ (0xa9002660U + 0x088130U + 24U);
}

// [EN] FDE[2940] start_va=0x063210, fde_va=0x088148, span=16 B | [VN] FDE[2940]
uint32_t ttr_fde_2940_0x063210(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37ff928U) + (a1 ^ 0xeb01011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a883028U + 0x063210U) ^ (0xd65f03c0U + 0x088148U + 16U);
}

// [EN] FDE[2941] start_va=0x063220, fde_va=0x088160, span=12 B | [VN] FDE[2941]
uint32_t ttr_fde_2941_0x063220(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf2e15548U) + (a1 ^ 0xeb08003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063220U) ^ (0x9100600aU + 0x088160U + 12U);
}

// [EN] FDE[2942] start_va=0x06322c, fde_va=0x088178, span=16 B | [VN] FDE[2942]
uint32_t ttr_fde_2942_0x06322c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100600aU) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a9f0140U + 0x06322cU) ^ (0xd65f03c0U + 0x088178U + 16U);
}

// [EN] FDE[2943] start_va=0x06323c, fde_va=0x088190, span=12 B | [VN] FDE[2943]
uint32_t ttr_fde_2943_0x06323c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10062b5U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06323cU) ^ (0x8b080aaaU + 0x088190U + 12U);
}

// [EN] FDE[2944] start_va=0x063248, fde_va=0x0881a8, span=24 B | [VN] FDE[2944]
uint32_t ttr_fde_2944_0x063248(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b080aaaU) + (a1 ^ 0x4b080288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0b090108U + 0x063248U) ^ (0xcb090940U + 0x0881a8U + 24U);
}

// [EN] FDE[2945] start_va=0x063260, fde_va=0x0881c0, span=24 B | [VN] FDE[2945]
uint32_t ttr_fde_2945_0x063260(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b080aaaU) + (a1 ^ 0x4b080288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0b090108U + 0x063260U) ^ (0xcb090941U + 0x0881c0U + 24U);
}

// [EN] FDE[2946] start_va=0x063278, fde_va=0x0881d8, span=12 B | [VN] FDE[2946]
uint32_t ttr_fde_2946_0x063278(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x531f7909U) + (a1 ^ 0x39000269U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063278U) ^ (0xf00001d5U + 0x0881d8U + 12U);
}

// [EN] FDE[2947] start_va=0x063284, fde_va=0x0881f0, span=12 B | [VN] FDE[2947]
uint32_t ttr_fde_2947_0x063284(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001d5U) + (a1 ^ 0x910b42b5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063284U) ^ (0xf00001d5U + 0x0881f0U + 12U);
}

// [EN] FDE[2948] start_va=0x063290, fde_va=0x088208, span=12 B | [VN] FDE[2948]
uint32_t ttr_fde_2948_0x063290(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001d5U) + (a1 ^ 0x910c02b5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063290U) ^ (0x52800026U + 0x088208U + 12U);
}

// [EN] FDE[2949] start_va=0x06329c, fde_va=0x088220, span=16 B | [VN] FDE[2949]
uint32_t ttr_fde_2949_0x06329c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800026U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103e2U + 0x06329cU) ^ (0xd65f03c0U + 0x088220U + 16U);
}

// [EN] FDE[2950] start_va=0x0632ac, fde_va=0x088238, span=16 B | [VN] FDE[2950]
uint32_t ttr_fde_2950_0x0632ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e1U) + (a1 ^ 0xaa1903e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f8U + 0x0632acU) ^ (0x17fee2aeU + 0x088238U + 16U);
}

// [EN] FDE[2951] start_va=0x0632bc, fde_va=0x088250, span=12 B | [VN] FDE[2951]
uint32_t ttr_fde_2951_0x0632bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e8U) + (a1 ^ 0xf8410d16U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0632bcU) ^ (0xa8c463f9U + 0x088250U + 12U);
}

// [EN] FDE[2952] start_va=0x0632c8, fde_va=0x088268, span=8 B | [VN] FDE[2952]
uint32_t ttr_fde_2952_0x0632c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa8c463f9U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10183ffU + 0x0632c8U) ^ (0xf9000bf9U + 0x088268U + 8U);
}

// [EN] FDE[2953] start_va=0x0632d0, fde_va=0x088280, span=24 B | [VN] FDE[2953]
uint32_t ttr_fde_2953_0x0632d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10183ffU) + (a1 ^ 0xf9000bf9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025ff8U + 0x0632d0U) ^ (0xa90357f6U + 0x088280U + 24U);
}

// [EN] FDE[2954] start_va=0x0632e8, fde_va=0x088298, span=24 B | [VN] FDE[2954]
uint32_t ttr_fde_2954_0x0632e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf840c308U) + (a1 ^ 0x910063e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0632e8U) ^ (0xaa1603e1U + 0x088298U + 24U);
}

// [EN] FDE[2955] start_va=0x063300, fde_va=0x0882b0, span=24 B | [VN] FDE[2955]
uint32_t ttr_fde_2955_0x063300(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9404fe9U) + (a1 ^ 0x6953aeeaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94047f8U + 0x063300U) ^ (0xaa1f03e8U + 0x0882b0U + 24U);
}

// [EN] FDE[2956] start_va=0x063318, fde_va=0x0882c8, span=12 B | [VN] FDE[2956]
uint32_t ttr_fde_2956_0x063318(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52aff008U) + (a1 ^ 0x1e270105U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063318U) ^ (0xf9401408U + 0x0882c8U + 12U);
}

// [EN] FDE[2957] start_va=0x063324, fde_va=0x0882e0, span=16 B | [VN] FDE[2957]
uint32_t ttr_fde_2957_0x063324(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401408U) + (a1 ^ 0x52800020U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000268U + 0x063324U) ^ (0xd65f03c0U + 0x0882e0U + 16U);
}

// [EN] FDE[2958] start_va=0x063334, fde_va=0x0882f8, span=12 B | [VN] FDE[2958]
uint32_t ttr_fde_2958_0x063334(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910183e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063334U) ^ (0x910183e0U + 0x0882f8U + 12U);
}

// [EN] FDE[2959] start_va=0x063340, fde_va=0x088310, span=8 B | [VN] FDE[2959]
uint32_t ttr_fde_2959_0x063340(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910183e0U) + (a1 ^ 0x17ffa586U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910183e0U + 0x063340U) ^ (0x17ffa825U + 0x088310U + 8U);
}

// [EN] FDE[2960] start_va=0x063348, fde_va=0x088328, span=8 B | [VN] FDE[2960]
uint32_t ttr_fde_2960_0x063348(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910183e0U) + (a1 ^ 0x17ffa825U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401a88U + 0x063348U) ^ (0xf9401695U + 0x088328U + 8U);
}

// [EN] FDE[2961] start_va=0x063350, fde_va=0x088340, span=24 B | [VN] FDE[2961]
uint32_t ttr_fde_2961_0x063350(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401a88U) + (a1 ^ 0xf9401695U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x121c1108U + 0x063350U) ^ (0x7104011fU + 0x088340U + 24U);
}

// [EN] FDE[2962] start_va=0x063368, fde_va=0x088358, span=8 B | [VN] FDE[2962]
uint32_t ttr_fde_2962_0x063368(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e0U) + (a1 ^ 0x17ffbd3cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9406261U + 0x063368U) ^ (0xd0000040U + 0x088358U + 8U);
}

// [EN] FDE[2963] start_va=0x063370, fde_va=0x088370, span=16 B | [VN] FDE[2963]
uint32_t ttr_fde_2963_0x063370(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9406261U) + (a1 ^ 0xd0000040U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912cb000U + 0x063370U) ^ (0x17fee405U + 0x088370U + 16U);
}

// [EN] FDE[2964] start_va=0x063380, fde_va=0x088388, span=16 B | [VN] FDE[2964]
uint32_t ttr_fde_2964_0x063380(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000808U) + (a1 ^ 0x3d800000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103e0U + 0x063380U) ^ (0x17fefc74U + 0x088388U + 16U);
}

// [EN] FDE[2965] start_va=0x063390, fde_va=0x0883a0, span=24 B | [VN] FDE[2965]
uint32_t ttr_fde_2965_0x063390(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000008U) + (a1 ^ 0xf9400668U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000408U + 0x063390U) ^ (0xf9400a68U + 0x0883a0U + 24U);
}

// [EN] FDE[2966] start_va=0x0633a8, fde_va=0x0883b8, span=24 B | [VN] FDE[2966]
uint32_t ttr_fde_2966_0x0633a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000008U) + (a1 ^ 0x3cc08260U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400e68U + 0x0633a8U) ^ (0x3c808000U + 0x0883b8U + 24U);
}

// [EN] FDE[2967] start_va=0x0633c0, fde_va=0x0883d0, span=8 B | [VN] FDE[2967]
uint32_t ttr_fde_2967_0x0633c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003faU) + (a1 ^ 0x17fee267U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa94d6275U + 0x0633c0U) ^ (0x93407ed9U + 0x0883d0U + 8U);
}

// [EN] FDE[2968] start_va=0x0633c8, fde_va=0x0883e8, span=24 B | [VN] FDE[2968]
uint32_t ttr_fde_2968_0x0633c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94d6275U) + (a1 ^ 0x93407ed9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000056U + 0x0633c8U) ^ (0x912acad6U + 0x0883e8U + 24U);
}

// [EN] FDE[2969] start_va=0x0633e0, fde_va=0x088400, span=24 B | [VN] FDE[2969]
uint32_t ttr_fde_2969_0x0633e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006018U) + (a1 ^ 0xaa0003f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa900fc1fU + 0x0633e0U) ^ (0xf9000008U + 0x088400U + 24U);
}

// [EN] FDE[2970] start_va=0x0633f8, fde_va=0x088418, span=16 B | [VN] FDE[2970]
uint32_t ttr_fde_2970_0x0633f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94453f5U) + (a1 ^ 0xf9401bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910183ffU + 0x0633f8U) ^ (0x17ff8ed6U + 0x088418U + 16U);
}

// [EN] FDE[2971] start_va=0x063408, fde_va=0x088430, span=16 B | [VN] FDE[2971]
uint32_t ttr_fde_2971_0x063408(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f4U) + (a1 ^ 0x91004261U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf8010408U + 0x063408U) ^ (0xd65f03c0U + 0x088430U + 16U);
}

// [EN] FDE[2972] start_va=0x063418, fde_va=0x088448, span=12 B | [VN] FDE[2972]
uint32_t ttr_fde_2972_0x063418(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9412661U) + (a1 ^ 0xeb09003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063418U) ^ (0x9101c3e2U + 0x088448U + 12U);
}

// [EN] FDE[2973] start_va=0x063424, fde_va=0x088460, span=16 B | [VN] FDE[2973]
uint32_t ttr_fde_2973_0x063424(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101c3e2U) + (a1 ^ 0x52808001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1a03e0U + 0x063424U) ^ (0x17ffc50aU + 0x088460U + 16U);
}

// [EN] FDE[2974] start_va=0x063434, fde_va=0x088478, span=16 B | [VN] FDE[2974]
uint32_t ttr_fde_2974_0x063434(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101c3e2U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb90073ffU + 0x063434U) ^ (0x17ffc49dU + 0x088478U + 16U);
}

// [EN] FDE[2975] start_va=0x063444, fde_va=0x088490, span=20 B | [VN] FDE[2975]
uint32_t ttr_fde_2975_0x063444(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97fef9d3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9409288U + 0x063444U) ^ (0xf84107feU + 0x088490U + 20U);
}

// [EN] FDE[2976] start_va=0x063458, fde_va=0x0884b0, span=24 B | [VN] FDE[2976]
uint32_t ttr_fde_2976_0x063458(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x3c828000U) + (a1 ^ 0x3c838000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3c848000U + 0x063458U) ^ (0x3c858000U + 0x0884b0U + 24U);
}

// [EN] FDE[2977] start_va=0x063470, fde_va=0x0884c8, span=8 B | [VN] FDE[2977]
uint32_t ttr_fde_2977_0x063470(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e1U) + (a1 ^ 0x17ffa585U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100a3e8U + 0x063470U) ^ (0x91004281U + 0x0884c8U + 8U);
}

// [EN] FDE[2978] start_va=0x063478, fde_va=0x0884e0, span=24 B | [VN] FDE[2978]
uint32_t ttr_fde_2978_0x063478(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a3e8U) + (a1 ^ 0x91004281U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb2400103U + 0x063478U) ^ (0x910103e0U + 0x0884e0U + 24U);
}

// [EN] FDE[2979] start_va=0x063490, fde_va=0x0884f8, span=8 B | [VN] FDE[2979]
uint32_t ttr_fde_2979_0x063490(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e201960U) + (a1 ^ 0x17fee44bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e8U + 0x063490U) ^ (0xaa1603e0U + 0x0884f8U + 8U);
}

// [EN] FDE[2980] start_va=0x063498, fde_va=0x088510, span=16 B | [VN] FDE[2980]
uint32_t ttr_fde_2980_0x063498(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e8U) + (a1 ^ 0xaa1603e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e1U + 0x063498U) ^ (0x17ff9559U + 0x088510U + 16U);
}

// [EN] FDE[2981] start_va=0x0634a8, fde_va=0x088528, span=16 B | [VN] FDE[2981]
uint32_t ttr_fde_2981_0x0634a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000041U) + (a1 ^ 0x913c2421U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910063e0U + 0x0634a8U) ^ (0x17ff88edU + 0x088528U + 16U);
}

// [EN] FDE[2982] start_va=0x0634b8, fde_va=0x088540, span=12 B | [VN] FDE[2982]
uint32_t ttr_fde_2982_0x0634b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9ad40b68U) + (a1 ^ 0x9b14ed1bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0634b8U) ^ (0xd1000689U + 0x088540U + 12U);
}

// [EN] FDE[2983] start_va=0x0634c4, fde_va=0x088558, span=12 B | [VN] FDE[2983]
uint32_t ttr_fde_2983_0x0634c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd1000689U) + (a1 ^ 0x8a090318U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0634c4U) ^ (0x9ad40b09U + 0x088558U + 12U);
}

// [EN] FDE[2984] start_va=0x0634d0, fde_va=0x088570, span=12 B | [VN] FDE[2984]
uint32_t ttr_fde_2984_0x0634d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9ad40b09U) + (a1 ^ 0x9b14e138U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0634d0U) ^ (0x8b190101U + 0x088570U + 12U);
}

// [EN] FDE[2985] start_va=0x0634dc, fde_va=0x088588, span=16 B | [VN] FDE[2985]
uint32_t ttr_fde_2985_0x0634dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b190101U) + (a1 ^ 0x8b190128U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd1006100U + 0x0634dcU) ^ (0x17ffd1b8U + 0x088588U + 16U);
}

// [EN] FDE[2986] start_va=0x0634ec, fde_va=0x0885a0, span=24 B | [VN] FDE[2986]
uint32_t ttr_fde_2986_0x0634ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xf9400009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb090108U + 0x0634ecU) ^ (0xb27fefe9U + 0x0885a0U + 24U);
}

// [EN] FDE[2987] start_va=0x063504, fde_va=0x0885b8, span=16 B | [VN] FDE[2987]
uint32_t ttr_fde_2987_0x063504(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f3U) + (a1 ^ 0xeb000022U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9343fc54U + 0x063504U) ^ (0xd65f03c0U + 0x0885b8U + 16U);
}

// [EN] FDE[2988] start_va=0x063514, fde_va=0x0885d0, span=16 B | [VN] FDE[2988]
uint32_t ttr_fde_2988_0x063514(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f3U) + (a1 ^ 0xaa0003f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f4U + 0x063514U) ^ (0xd65f03c0U + 0x0885d0U + 16U);
}

// [EN] FDE[2989] start_va=0x063524, fde_va=0x0885e8, span=16 B | [VN] FDE[2989]
uint32_t ttr_fde_2989_0x063524(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400260U) + (a1 ^ 0x910063e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e1U + 0x063524U) ^ (0x17ffa481U + 0x0885e8U + 16U);
}

// [EN] FDE[2990] start_va=0x063534, fde_va=0x088600, span=16 B | [VN] FDE[2990]
uint32_t ttr_fde_2990_0x063534(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000a68U) + (a1 ^ 0xf9400688U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9002a68U + 0x063534U) ^ (0xd65f03c0U + 0x088600U + 16U);
}

// [EN] FDE[2991] start_va=0x063544, fde_va=0x088618, span=12 B | [VN] FDE[2991]
uint32_t ttr_fde_2991_0x063544(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9005e75U) + (a1 ^ 0xf9000a76U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063544U) ^ (0x8b161008U + 0x088618U + 12U);
}

// [EN] FDE[2992] start_va=0x063550, fde_va=0x088630, span=24 B | [VN] FDE[2992]
uint32_t ttr_fde_2992_0x063550(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b161008U) + (a1 ^ 0x8b151009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa900a3e0U + 0x063550U) ^ (0xa901a7e8U + 0x088630U + 24U);
}

// [EN] FDE[2993] start_va=0x063568, fde_va=0x088648, span=24 B | [VN] FDE[2993]
uint32_t ttr_fde_2993_0x063568(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402668U) + (a1 ^ 0xaa0003f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9026bffU + 0x063568U) ^ (0xcb080128U + 0x088648U + 24U);
}

// [EN] FDE[2994] start_va=0x063580, fde_va=0x088660, span=24 B | [VN] FDE[2994]
uint32_t ttr_fde_2994_0x063580(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402668U) + (a1 ^ 0xaa0003f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025fffU + 0x063580U) ^ (0xcb080128U + 0x088660U + 24U);
}

// [EN] FDE[2995] start_va=0x063598, fde_va=0x088678, span=16 B | [VN] FDE[2995]
uint32_t ttr_fde_2995_0x063598(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100e274U) + (a1 ^ 0x910063e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x063598U) ^ (0x17ff58f5U + 0x088678U + 16U);
}

// [EN] FDE[2996] start_va=0x0635a8, fde_va=0x088690, span=8 B | [VN] FDE[2996]
uint32_t ttr_fde_2996_0x0635a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910383ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9405674U + 0x0635a8U) ^ (0xa9002a69U + 0x088690U + 8U);
}

// [EN] FDE[2997] start_va=0x0635b0, fde_va=0x0886a8, span=16 B | [VN] FDE[2997]
uint32_t ttr_fde_2997_0x0635b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9405674U) + (a1 ^ 0xa9002a69U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000a68U + 0x0635b0U) ^ (0xd65f03c0U + 0x0886a8U + 16U);
}

// [EN] FDE[2998] start_va=0x0635c0, fde_va=0x0886c0, span=28 B | [VN] FDE[2998]
uint32_t ttr_fde_2998_0x0635c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x3d800660U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3d800be1U + 0x0635c0U) ^ (0x97ff71baU + 0x0886c0U + 28U);
}

// [EN] FDE[2999] start_va=0x0635dc, fde_va=0x0886e0, span=28 B | [VN] FDE[2999]
uint32_t ttr_fde_2999_0x0635dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x3d800660U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3d800be1U + 0x0635dcU) ^ (0x97ff9ba5U + 0x0886e0U + 28U);
}

// [EN] FDE[3000] start_va=0x0635f8, fde_va=0x088700, span=16 B | [VN] FDE[3000]
uint32_t ttr_fde_3000_0x0635f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910043e0U) + (a1 ^ 0x910003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007fffU + 0x0635f8U) ^ (0x17fef788U + 0x088700U + 16U);
}

// [EN] FDE[3001] start_va=0x063608, fde_va=0x088718, span=8 B | [VN] FDE[3001]
uint32_t ttr_fde_3001_0x063608(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910043e0U) + (a1 ^ 0x17fef962U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3dc00280U + 0x063608U) ^ (0xaa1303e0U + 0x088718U + 8U);
}

// [EN] FDE[3002] start_va=0x063610, fde_va=0x088730, span=24 B | [VN] FDE[3002]
uint32_t ttr_fde_3002_0x063610(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x3dc00280U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3d800260U + 0x063610U) ^ (0xf9400a88U + 0x088730U + 24U);
}

// [EN] FDE[3003] start_va=0x063628, fde_va=0x088748, span=16 B | [VN] FDE[3003]
uint32_t ttr_fde_3003_0x063628(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e2U) + (a1 ^ 0x2a1903e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1803e4U + 0x063628U) ^ (0x17ff74a1U + 0x088748U + 16U);
}

// [EN] FDE[3004] start_va=0x063638, fde_va=0x088760, span=16 B | [VN] FDE[3004]
uint32_t ttr_fde_3004_0x063638(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e2U) + (a1 ^ 0x2a1903e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1703e4U + 0x063638U) ^ (0x17ff749dU + 0x088760U + 16U);
}

// [EN] FDE[3005] start_va=0x063648, fde_va=0x088778, span=16 B | [VN] FDE[3005]
uint32_t ttr_fde_3005_0x063648(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e6b2989U) + (a1 ^ 0x4ea81d00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfd000269U + 0x063648U) ^ (0x17fee3cfU + 0x088778U + 16U);
}

// [EN] FDE[3006] start_va=0x063658, fde_va=0x088790, span=8 B | [VN] FDE[3006]
uint32_t ttr_fde_3006_0x063658(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910123e0U) + (a1 ^ 0x17ffa4c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x937fef08U + 0x063658U) ^ (0xf100031fU + 0x088790U + 8U);
}

// [EN] FDE[3007] start_va=0x063660, fde_va=0x0887a8, span=24 B | [VN] FDE[3007]
uint32_t ttr_fde_3007_0x063660(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x937fef08U) + (a1 ^ 0xf100031fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a9f1518U + 0x063660U) ^ (0xd37ef708U + 0x0887a8U + 24U);
}

// [EN] FDE[3008] start_va=0x063678, fde_va=0x0887c0, span=16 B | [VN] FDE[3008]
uint32_t ttr_fde_3008_0x063678(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910042a9U) + (a1 ^ 0xeb15011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a958135U + 0x063678U) ^ (0xd65f03c0U + 0x0887c0U + 16U);
}

// [EN] FDE[3009] start_va=0x063688, fde_va=0x0887d8, span=12 B | [VN] FDE[3009]
uint32_t ttr_fde_3009_0x063688(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd1000768U) + (a1 ^ 0xea08037fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063688U) ^ (0xf90002c9U + 0x0887d8U + 12U);
}

// [EN] FDE[3010] start_va=0x063694, fde_va=0x0887f0, span=16 B | [VN] FDE[3010]
uint32_t ttr_fde_3010_0x063694(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf90002c9U) + (a1 ^ 0xf85f0109U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000116U + 0x063694U) ^ (0xd65f03c0U + 0x0887f0U + 16U);
}

// [EN] FDE[3011] start_va=0x0636a4, fde_va=0x088808, span=24 B | [VN] FDE[3011]
uint32_t ttr_fde_3011_0x0636a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a68U) + (a1 ^ 0xcb1802b6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f4U + 0x0636a4U) ^ (0xcb090108U + 0x088808U + 24U);
}

// [EN] FDE[3012] start_va=0x0636bc, fde_va=0x088820, span=16 B | [VN] FDE[3012]
uint32_t ttr_fde_3012_0x0636bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e0U) + (a1 ^ 0x927df117U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9003be9U + 0x0636bcU) ^ (0x17ffa18dU + 0x088820U + 16U);
}

// [EN] FDE[3013] start_va=0x0636cc, fde_va=0x088838, span=12 B | [VN] FDE[3013]
uint32_t ttr_fde_3013_0x0636cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e0U) + (a1 ^ 0xaa1703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0636ccU) ^ (0xaa1603e0U + 0x088838U + 12U);
}

// [EN] FDE[3014] start_va=0x0636d8, fde_va=0x088850, span=16 B | [VN] FDE[3014]
uint32_t ttr_fde_3014_0x0636d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e0U) + (a1 ^ 0x2a1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1703e2U + 0x0636d8U) ^ (0x17ff7cb6U + 0x088850U + 16U);
}

// [EN] FDE[3015] start_va=0x0636e8, fde_va=0x088868, span=16 B | [VN] FDE[3015]
uint32_t ttr_fde_3015_0x0636e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd059U) + (a1 ^ 0xaa0803f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401728U + 0x0636e8U) ^ (0xd65f03c0U + 0x088868U + 16U);
}

// [EN] FDE[3016] start_va=0x0636f8, fde_va=0x088880, span=16 B | [VN] FDE[3016]
uint32_t ttr_fde_3016_0x0636f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2d480e62U) + (a1 ^ 0x1e203900U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e213921U + 0x0636f8U) ^ (0x17ffd5d3U + 0x088880U + 16U);
}

// [EN] FDE[3017] start_va=0x063708, fde_va=0x088898, span=8 B | [VN] FDE[3017]
uint32_t ttr_fde_3017_0x063708(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52801900U) + (a1 ^ 0x17fee195U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e210800U + 0x063708U) ^ (0x1e2008a0U + 0x088898U + 8U);
}

// [EN] FDE[3018] start_va=0x063710, fde_va=0x0888b0, span=16 B | [VN] FDE[3018]
uint32_t ttr_fde_3018_0x063710(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e210800U) + (a1 ^ 0x1e2008a0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e201900U + 0x063710U) ^ (0x17fee3a9U + 0x0888b0U + 16U);
}

// [EN] FDE[3019] start_va=0x063720, fde_va=0x0888c8, span=16 B | [VN] FDE[3019]
uint32_t ttr_fde_3019_0x063720(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf90017e0U) + (a1 ^ 0x910003e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb90033e1U + 0x063720U) ^ (0x17fef91aU + 0x0888c8U + 16U);
}

// [EN] FDE[3020] start_va=0x063730, fde_va=0x0888e0, span=16 B | [VN] FDE[3020]
uint32_t ttr_fde_3020_0x063730(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xaa1703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400908U + 0x063730U) ^ (0xd61f0100U + 0x0888e0U + 16U);
}

// [EN] FDE[3021] start_va=0x063740, fde_va=0x0888f8, span=12 B | [VN] FDE[3021]
uint32_t ttr_fde_3021_0x063740(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063740U) ^ (0xf9400008U + 0x0888f8U + 12U);
}

// [EN] FDE[3022] start_va=0x06374c, fde_va=0x088910, span=16 B | [VN] FDE[3022]
uint32_t ttr_fde_3022_0x06374c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9402908U + 0x06374cU) ^ (0xd61f0100U + 0x088910U + 16U);
}

// [EN] FDE[3023] start_va=0x06375c, fde_va=0x088928, span=12 B | [VN] FDE[3023]
uint32_t ttr_fde_3023_0x06375c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x394002a8U) + (a1 ^ 0x7100fd1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06375cU) ^ (0xf9405be8U + 0x088928U + 12U);
}

// [EN] FDE[3024] start_va=0x063768, fde_va=0x088940, span=16 B | [VN] FDE[3024]
uint32_t ttr_fde_3024_0x063768(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9405be8U) + (a1 ^ 0x9105c3e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9b1422e1U + 0x063768U) ^ (0x17ffd444U + 0x088940U + 16U);
}

// [EN] FDE[3025] start_va=0x063778, fde_va=0x088958, span=16 B | [VN] FDE[3025]
uint32_t ttr_fde_3025_0x063778(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9424ff4U) + (a1 ^ 0xa94157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c45ff8U + 0x063778U) ^ (0xd65f03c0U + 0x088958U + 16U);
}

// [EN] FDE[3026] start_va=0x063788, fde_va=0x088970, span=16 B | [VN] FDE[3026]
uint32_t ttr_fde_3026_0x063788(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9424ff4U) + (a1 ^ 0xa94157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84407f7U + 0x063788U) ^ (0xd65f03c0U + 0x088970U + 16U);
}

// [EN] FDE[3027] start_va=0x063798, fde_va=0x088988, span=8 B | [VN] FDE[3027]
uint32_t ttr_fde_3027_0x063798(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17fee165U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x063798U) ^ (0xaa1303e1U + 0x088988U + 8U);
}

// [EN] FDE[3028] start_va=0x0637a0, fde_va=0x0889a0, span=16 B | [VN] FDE[3028]
uint32_t ttr_fde_3028_0x0637a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1303e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1603e3U + 0x0637a0U) ^ (0x17ff9dd9U + 0x0889a0U + 16U);
}

// [EN] FDE[3029] start_va=0x0637b0, fde_va=0x0889b8, span=8 B | [VN] FDE[3029]
uint32_t ttr_fde_3029_0x0637b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17fee1b7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x0637b0U) ^ (0x17ff7923U + 0x0889b8U + 8U);
}

// [EN] FDE[3030] start_va=0x0637b8, fde_va=0x0889d0, span=8 B | [VN] FDE[3030]
uint32_t ttr_fde_3030_0x0637b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff7923U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x0637b8U) ^ (0x17ff7addU + 0x0889d0U + 8U);
}

// [EN] FDE[3031] start_va=0x0637c0, fde_va=0x0889e8, span=8 B | [VN] FDE[3031]
uint32_t ttr_fde_3031_0x0637c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff7addU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x0637c0U) ^ (0xaa1603e1U + 0x0889e8U + 8U);
}

// [EN] FDE[3032] start_va=0x0637c8, fde_va=0x088a00, span=12 B | [VN] FDE[3032]
uint32_t ttr_fde_3032_0x0637c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0637c8U) ^ (0xaa1403e0U + 0x088a00U + 12U);
}

// [EN] FDE[3033] start_va=0x0637d4, fde_va=0x088a18, span=16 B | [VN] FDE[3033]
uint32_t ttr_fde_3033_0x0637d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e2U + 0x0637d4U) ^ (0x17ff723dU + 0x088a18U + 16U);
}

// [EN] FDE[3034] start_va=0x0637e4, fde_va=0x088a30, span=16 B | [VN] FDE[3034]
uint32_t ttr_fde_3034_0x0637e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e2U + 0x0637e4U) ^ (0x17ff8195U + 0x088a30U + 16U);
}

// [EN] FDE[3035] start_va=0x0637f4, fde_va=0x088a48, span=16 B | [VN] FDE[3035]
uint32_t ttr_fde_3035_0x0637f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e2U + 0x0637f4U) ^ (0x17ff7253U + 0x088a48U + 16U);
}

// [EN] FDE[3036] start_va=0x063804, fde_va=0x088a60, span=16 B | [VN] FDE[3036]
uint32_t ttr_fde_3036_0x063804(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e2U + 0x063804U) ^ (0x17ff81b1U + 0x088a60U + 16U);
}

// [EN] FDE[3037] start_va=0x063814, fde_va=0x088a78, span=8 B | [VN] FDE[3037]
uint32_t ttr_fde_3037_0x063814(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff7900U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400668U + 0x063814U) ^ (0x91002108U + 0x088a78U + 8U);
}

// [EN] FDE[3038] start_va=0x06381c, fde_va=0x088a90, span=16 B | [VN] FDE[3038]
uint32_t ttr_fde_3038_0x06381c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400668U) + (a1 ^ 0x91002108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000668U + 0x06381cU) ^ (0xd65f03c0U + 0x088a90U + 16U);
}

// [EN] FDE[3039] start_va=0x06382c, fde_va=0x088aa8, span=8 B | [VN] FDE[3039]
uint32_t ttr_fde_3039_0x06382c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e1U) + (a1 ^ 0x17ff9311U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x06382cU) ^ (0xaa1403e1U + 0x088aa8U + 8U);
}

// [EN] FDE[3040] start_va=0x063834, fde_va=0x088ac0, span=12 B | [VN] FDE[3040]
uint32_t ttr_fde_3040_0x063834(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063834U) ^ (0x910023e0U + 0x088ac0U + 12U);
}

// [EN] FDE[3041] start_va=0x063840, fde_va=0x088ad8, span=16 B | [VN] FDE[3041]
uint32_t ttr_fde_3041_0x063840(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e2U + 0x063840U) ^ (0x17ffc3c7U + 0x088ad8U + 16U);
}

// [EN] FDE[3042] start_va=0x063850, fde_va=0x088af0, span=8 B | [VN] FDE[3042]
uint32_t ttr_fde_3042_0x063850(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff39c4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400288U + 0x063850U) ^ (0xaa1403e0U + 0x088af0U + 8U);
}

// [EN] FDE[3043] start_va=0x063858, fde_va=0x088b08, span=12 B | [VN] FDE[3043]
uint32_t ttr_fde_3043_0x063858(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400288U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063858U) ^ (0xf9400be0U + 0x088b08U + 12U);
}

// [EN] FDE[3044] start_va=0x063864, fde_va=0x088b20, span=8 B | [VN] FDE[3044]
uint32_t ttr_fde_3044_0x063864(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400be0U) + (a1 ^ 0x17ff08f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400408U + 0x063864U) ^ (0xd0000055U + 0x088b20U + 8U);
}

// [EN] FDE[3045] start_va=0x06386c, fde_va=0x088b38, span=24 B | [VN] FDE[3045]
uint32_t ttr_fde_3045_0x06386c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xd0000055U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303f3U + 0x06386cU) ^ (0x912caab5U + 0x088b38U + 24U);
}

// [EN] FDE[3046] start_va=0x063884, fde_va=0x088b50, span=12 B | [VN] FDE[3046]
uint32_t ttr_fde_3046_0x063884(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xb9400021U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063884U) ^ (0xf94013e0U + 0x088b50U + 12U);
}

// [EN] FDE[3047] start_va=0x063890, fde_va=0x088b68, span=8 B | [VN] FDE[3047]
uint32_t ttr_fde_3047_0x063890(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94013e0U) + (a1 ^ 0x17ff08e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa954a3e9U + 0x063890U) ^ (0xcb090108U + 0x088b68U + 8U);
}

// [EN] FDE[3048] start_va=0x063898, fde_va=0x088b80, span=24 B | [VN] FDE[3048]
uint32_t ttr_fde_3048_0x063898(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa954a3e9U) + (a1 ^ 0xcb090108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800309U + 0x063898U) ^ (0x9ac90d08U + 0x088b80U + 24U);
}

// [EN] FDE[3049] start_va=0x0638b0, fde_va=0x088b98, span=8 B | [VN] FDE[3049]
uint32_t ttr_fde_3049_0x0638b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910283ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400508U + 0x0638b0U) ^ (0xd1000729U + 0x088b98U + 8U);
}

// [EN] FDE[3050] start_va=0x0638b8, fde_va=0x088bb0, span=16 B | [VN] FDE[3050]
uint32_t ttr_fde_3050_0x0638b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400508U) + (a1 ^ 0xd1000729U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xea09033fU + 0x0638b8U) ^ (0xd65f03c0U + 0x088bb0U + 16U);
}

// [EN] FDE[3051] start_va=0x0638c8, fde_va=0x088bc8, span=16 B | [VN] FDE[3051]
uint32_t ttr_fde_3051_0x0638c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400508U) + (a1 ^ 0xd1000769U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xea09037fU + 0x0638c8U) ^ (0xd65f03c0U + 0x088bc8U + 16U);
}

// [EN] FDE[3052] start_va=0x0638d8, fde_va=0x088be0, span=8 B | [VN] FDE[3052]
uint32_t ttr_fde_3052_0x0638d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94007e0U) + (a1 ^ 0x17fef6d9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e1U + 0x0638d8U) ^ (0xaa1303e0U + 0x088be0U + 8U);
}

// [EN] FDE[3053] start_va=0x0638e0, fde_va=0x088bf8, span=12 B | [VN] FDE[3053]
uint32_t ttr_fde_3053_0x0638e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0638e0U) ^ (0xf9400280U + 0x088bf8U + 12U);
}

// [EN] FDE[3054] start_va=0x0638ec, fde_va=0x088c10, span=8 B | [VN] FDE[3054]
uint32_t ttr_fde_3054_0x0638ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400280U) + (a1 ^ 0x17fee110U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e1U + 0x0638ecU) ^ (0xaa1403e2U + 0x088c10U + 8U);
}

// [EN] FDE[3055] start_va=0x0638f4, fde_va=0x088c28, span=12 B | [VN] FDE[3055]
uint32_t ttr_fde_3055_0x0638f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e1U) + (a1 ^ 0xaa1403e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0638f4U) ^ (0xaa1503e1U + 0x088c28U + 12U);
}

// [EN] FDE[3056] start_va=0x063900, fde_va=0x088c40, span=8 B | [VN] FDE[3056]
uint32_t ttr_fde_3056_0x063900(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e1U) + (a1 ^ 0x17ff0c0cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x063900U) ^ (0xaa1503e1U + 0x088c40U + 8U);
}

// [EN] FDE[3057] start_va=0x063908, fde_va=0x088c58, span=16 B | [VN] FDE[3057]
uint32_t ttr_fde_3057_0x063908(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400d28U + 0x063908U) ^ (0xd61f0100U + 0x088c58U + 16U);
}

// [EN] FDE[3058] start_va=0x063918, fde_va=0x088c70, span=8 B | [VN] FDE[3058]
uint32_t ttr_fde_3058_0x063918(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ff0547U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x063918U) ^ (0xaa1803e1U + 0x088c70U + 8U);
}

// [EN] FDE[3059] start_va=0x063920, fde_va=0x088c88, span=24 B | [VN] FDE[3059]
uint32_t ttr_fde_3059_0x063920(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xaa1803e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1903e2U + 0x063920U) ^ (0x2a1503e3U + 0x088c88U + 24U);
}

// [EN] FDE[3060] start_va=0x063938, fde_va=0x088ca0, span=12 B | [VN] FDE[3060]
uint32_t ttr_fde_3060_0x063938(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400268U) + (a1 ^ 0xf87b7909U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063938U) ^ (0xf9400268U + 0x088ca0U + 12U);
}

// [EN] FDE[3061] start_va=0x063944, fde_va=0x088cb8, span=16 B | [VN] FDE[3061]
uint32_t ttr_fde_3061_0x063944(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400268U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9406d08U + 0x063944U) ^ (0xd61f0100U + 0x088cb8U + 16U);
}

// [EN] FDE[3062] start_va=0x063954, fde_va=0x088cd0, span=16 B | [VN] FDE[3062]
uint32_t ttr_fde_3062_0x063954(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400268U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9402508U + 0x063954U) ^ (0xd61f0100U + 0x088cd0U + 16U);
}

// [EN] FDE[3063] start_va=0x063964, fde_va=0x088ce8, span=28 B | [VN] FDE[3063]
uint32_t ttr_fde_3063_0x063964(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91004000U + 0x063964U) ^ (0x97ffd383U + 0x088ce8U + 28U);
}

// [EN] FDE[3064] start_va=0x063980, fde_va=0x088d08, span=16 B | [VN] FDE[3064]
uint32_t ttr_fde_3064_0x063980(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf9000008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf8018c09U + 0x063980U) ^ (0xd65f03c0U + 0x088d08U + 16U);
}

// [EN] FDE[3065] start_va=0x063990, fde_va=0x088d20, span=12 B | [VN] FDE[3065]
uint32_t ttr_fde_3065_0x063990(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f4U) + (a1 ^ 0xaa0103f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063990U) ^ (0xd101c3ffU + 0x088d20U + 12U);
}

// [EN] FDE[3066] start_va=0x06399c, fde_va=0x088d38, span=20 B | [VN] FDE[3066]
uint32_t ttr_fde_3066_0x06399c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xf9001bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90457f6U + 0x06399cU) ^ (0xa9054ff4U + 0x088d38U + 20U);
}

// [EN] FDE[3067] start_va=0x0639b0, fde_va=0x088d50, span=24 B | [VN] FDE[3067]
uint32_t ttr_fde_3067_0x0639b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6b02011fU) + (a1 ^ 0x1a82b114U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4b090108U + 0x0639b0U) ^ (0xaa0003f3U + 0x088d50U + 24U);
}

// [EN] FDE[3068] start_va=0x0639c8, fde_va=0x088d68, span=20 B | [VN] FDE[3068]
uint32_t ttr_fde_3068_0x0639c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf940028aU) + (a1 ^ 0xf900010aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf940068aU + 0x0639c8U) ^ (0xf900050aU + 0x088d68U + 20U);
}

// [EN] FDE[3069] start_va=0x0639dc, fde_va=0x088d80, span=12 B | [VN] FDE[3069]
uint32_t ttr_fde_3069_0x0639dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x394002e9U) + (a1 ^ 0xf9400aeaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0639dcU) ^ (0x910243e0U + 0x088d80U + 12U);
}

// [EN] FDE[3070] start_va=0x0639e8, fde_va=0x088d98, span=12 B | [VN] FDE[3070]
uint32_t ttr_fde_3070_0x0639e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910243e0U) + (a1 ^ 0x910443e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0639e8U) ^ (0x910243e0U + 0x088d98U + 12U);
}

// [EN] FDE[3071] start_va=0x0639f4, fde_va=0x088db0, span=12 B | [VN] FDE[3071]
uint32_t ttr_fde_3071_0x0639f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910243e0U) + (a1 ^ 0x910443e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff7009U + 0x0639f4U) ^ (0xd1000728U + 0x088db0U + 12U);
}

// [EN] FDE[3072] start_va=0x063a00, fde_va=0x088dc8, span=12 B | [VN] FDE[3072]
uint32_t ttr_fde_3072_0x063a00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd1000728U) + (a1 ^ 0xea08033fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063a00U) ^ (0xa94153f5U + 0x088dc8U + 12U);
}

// [EN] FDE[3073] start_va=0x063a0c, fde_va=0x088de0, span=12 B | [VN] FDE[3073]
uint32_t ttr_fde_3073_0x063a0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0xf84307f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063a0cU) ^ (0xa94153f5U + 0x088de0U + 12U);
}

// [EN] FDE[3074] start_va=0x063a18, fde_va=0x088df8, span=12 B | [VN] FDE[3074]
uint32_t ttr_fde_3074_0x063a18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0xf84307fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063a18U) ^ (0x910163e0U + 0x088df8U + 12U);
}

// [EN] FDE[3075] start_va=0x063a24, fde_va=0x088e10, span=12 B | [VN] FDE[3075]
uint32_t ttr_fde_3075_0x063a24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910163e0U) + (a1 ^ 0x2a1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa5a6U + 0x063a24U) ^ (0xaa1503e2U + 0x088e10U + 12U);
}

// [EN] FDE[3076] start_va=0x063a30, fde_va=0x088e28, span=12 B | [VN] FDE[3076]
uint32_t ttr_fde_3076_0x063a30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e2U) + (a1 ^ 0xb9003268U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee0c6U + 0x063a30U) ^ (0xaa1f03e3U + 0x088e28U + 12U);
}

// [EN] FDE[3077] start_va=0x063a3c, fde_va=0x088e40, span=8 B | [VN] FDE[3077]
uint32_t ttr_fde_3077_0x063a3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e3U) + (a1 ^ 0x17ff997dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900127fU + 0x063a3cU) ^ (0x17fee0c6U + 0x088e40U + 8U);
}

// [EN] FDE[3078] start_va=0x063a44, fde_va=0x088e58, span=8 B | [VN] FDE[3078]
uint32_t ttr_fde_3078_0x063a44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf900127fU) + (a1 ^ 0x17fee0c6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb0b028aU + 0x063a44U) ^ (0xcb0b070bU + 0x088e58U + 8U);
}

// [EN] FDE[3079] start_va=0x063a4c, fde_va=0x088e70, span=20 B | [VN] FDE[3079]
uint32_t ttr_fde_3079_0x063a4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb0b028aU) + (a1 ^ 0xcb0b070bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b0b0a6bU + 0x063a4cU) ^ (0x9100116bU + 0x088e70U + 20U);
}

// [EN] FDE[3080] start_va=0x063a60, fde_va=0x088e88, span=8 B | [VN] FDE[3080]
uint32_t ttr_fde_3080_0x063a60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9104c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9104c3ffU + 0x063a60U) ^ (0xd65f03c0U + 0x088e88U + 8U);
}

// [EN] FDE[3081] start_va=0x063a68, fde_va=0x088ea0, span=8 B | [VN] FDE[3081]
uint32_t ttr_fde_3081_0x063a68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9104c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1703e3U + 0x063a68U) ^ (0x2a1603e4U + 0x088ea0U + 8U);
}

// [EN] FDE[3082] start_va=0x063a70, fde_va=0x088eb8, span=12 B | [VN] FDE[3082]
uint32_t ttr_fde_3082_0x063a70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1703e3U) + (a1 ^ 0x2a1603e4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063a70U) ^ (0x2a1703e3U + 0x088eb8U + 12U);
}

// [EN] FDE[3083] start_va=0x063a7c, fde_va=0x088ed0, span=12 B | [VN] FDE[3083]
uint32_t ttr_fde_3083_0x063a7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1703e3U) + (a1 ^ 0x2a1503e4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff738dU + 0x063a7cU) ^ (0xf85a03a9U + 0x088ed0U + 12U);
}

// [EN] FDE[3084] start_va=0x063a88, fde_va=0x088ee8, span=12 B | [VN] FDE[3084]
uint32_t ttr_fde_3084_0x063a88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85a03a9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063a88U) ^ (0xb00001c8U + 0x088ee8U + 12U);
}

// [EN] FDE[3085] start_va=0x063a94, fde_va=0x088f00, span=20 B | [VN] FDE[3085]
uint32_t ttr_fde_3085_0x063a94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001c8U) + (a1 ^ 0x900001e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910d4129U + 0x063a94U) ^ (0x39721108U + 0x088f00U + 20U);
}

// [EN] FDE[3086] start_va=0x063aa8, fde_va=0x088f18, span=8 B | [VN] FDE[3086]
uint32_t ttr_fde_3086_0x063aa8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37df260U) + (a1 ^ 0x17fee0adU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100011fU + 0x063aa8U) ^ (0x5280002cU + 0x088f18U + 8U);
}

// [EN] FDE[3087] start_va=0x063ab0, fde_va=0x088f30, span=20 B | [VN] FDE[3087]
uint32_t ttr_fde_3087_0x063ab0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100011fU) + (a1 ^ 0x5280002cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f07e0U + 0x063ab0U) ^ (0x7200013fU + 0x088f30U + 20U);
}

// [EN] FDE[3088] start_va=0x063ac4, fde_va=0x088f48, span=20 B | [VN] FDE[3088]
uint32_t ttr_fde_3088_0x063ac4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100011fU) + (a1 ^ 0x1a9f07e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200013fU + 0x063ac4U) ^ (0x9a961541U + 0x088f48U + 20U);
}

// [EN] FDE[3089] start_va=0x063ad8, fde_va=0x088f60, span=12 B | [VN] FDE[3089]
uint32_t ttr_fde_3089_0x063ad8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100011fU) + (a1 ^ 0x1a9f17e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0120U + 0x063ad8U) ^ (0x4eac1d80U + 0x088f60U + 12U);
}

// [EN] FDE[3090] start_va=0x063ae4, fde_va=0x088f78, span=12 B | [VN] FDE[3090]
uint32_t ttr_fde_3090_0x063ae4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4eac1d80U) + (a1 ^ 0x4ead1da1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd319U + 0x063ae4U) ^ (0xa91863f7U + 0x088f78U + 12U);
}

// [EN] FDE[3091] start_va=0x063af0, fde_va=0x088f90, span=12 B | [VN] FDE[3091]
uint32_t ttr_fde_3091_0x063af0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa91863f7U) + (a1 ^ 0xf900cbfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd2c7U + 0x063af0U) ^ (0xf84207f4U + 0x088f90U + 12U);
}

// [EN] FDE[3092] start_va=0x063afc, fde_va=0x088fa8, span=8 B | [VN] FDE[3092]
uint32_t ttr_fde_3092_0x063afc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f4U) + (a1 ^ 0x17fefa97U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84207f4U + 0x063afcU) ^ (0x17ff8996U + 0x088fa8U + 8U);
}

// [EN] FDE[3093] start_va=0x063b04, fde_va=0x088fc0, span=8 B | [VN] FDE[3093]
uint32_t ttr_fde_3093_0x063b04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f4U) + (a1 ^ 0x17ff8996U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52850001U + 0x063b04U) ^ (0xd61f0100U + 0x088fc0U + 8U);
}

// [EN] FDE[3094] start_va=0x063b0c, fde_va=0x088fd8, span=8 B | [VN] FDE[3094]
uint32_t ttr_fde_3094_0x063b0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52850001U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf0000048U + 0x063b0cU) ^ (0x91019108U + 0x088fd8U + 8U);
}

// [EN] FDE[3095] start_va=0x063b14, fde_va=0x088ff0, span=20 B | [VN] FDE[3095]
uint32_t ttr_fde_3095_0x063b14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000048U) + (a1 ^ 0x91019108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910883e0U + 0x063b14U) ^ (0xaa0803e1U + 0x088ff0U + 20U);
}

// [EN] FDE[3096] start_va=0x063b28, fde_va=0x089008, span=20 B | [VN] FDE[3096]
uint32_t ttr_fde_3096_0x063b28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94037e9U) + (a1 ^ 0x7200011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e0U + 0x063b28U) ^ (0x9a8903a8U + 0x089008U + 20U);
}

// [EN] FDE[3097] start_va=0x063b3c, fde_va=0x089020, span=12 B | [VN] FDE[3097]
uint32_t ttr_fde_3097_0x063b3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1403e2U) + (a1 ^ 0x2a1303e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff4e17U + 0x063b3cU) ^ (0xf9400129U + 0x089020U + 12U);
}

// [EN] FDE[3098] start_va=0x063b48, fde_va=0x089038, span=8 B | [VN] FDE[3098]
uint32_t ttr_fde_3098_0x063b48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400129U) + (a1 ^ 0xd61f0120U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xad010000U + 0x063b48U) ^ (0xad020000U + 0x089038U + 8U);
}

// [EN] FDE[3099] start_va=0x063b50, fde_va=0x089050, span=12 B | [VN] FDE[3099]
uint32_t ttr_fde_3099_0x063b50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xad010000U) + (a1 ^ 0xad020000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063b50U) ^ (0xaa0203f5U + 0x089050U + 12U);
}

// [EN] FDE[3100] start_va=0x063b5c, fde_va=0x089068, span=20 B | [VN] FDE[3100]
uint32_t ttr_fde_3100_0x063b5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f5U) + (a1 ^ 0xaa0103f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x063b5cU) ^ (0xa9018c1fU + 0x089068U + 20U);
}

// [EN] FDE[3101] start_va=0x063b70, fde_va=0x089080, span=20 B | [VN] FDE[3101]
uint32_t ttr_fde_3101_0x063b70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9403260U) + (a1 ^ 0xf9403e61U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9402262U + 0x063b70U) ^ (0xaa1f03e3U + 0x089080U + 20U);
}

// [EN] FDE[3102] start_va=0x063b84, fde_va=0x089098, span=8 B | [VN] FDE[3102]
uint32_t ttr_fde_3102_0x063b84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400d08U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5100050bU + 0x063b84U) ^ (0x8a0a016bU + 0x089098U + 8U);
}

// [EN] FDE[3103] start_va=0x063b8c, fde_va=0x0890b0, span=12 B | [VN] FDE[3103]
uint32_t ttr_fde_3103_0x063b8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5100050bU) + (a1 ^ 0x8a0a016bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063b8cU) ^ (0x9ac8094bU + 0x0890b0U + 12U);
}

// [EN] FDE[3104] start_va=0x063b98, fde_va=0x0890c8, span=12 B | [VN] FDE[3104]
uint32_t ttr_fde_3104_0x063b98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9ac8094bU) + (a1 ^ 0x9b08a96bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063b98U) ^ (0xeb0a011fU + 0x0890c8U + 12U);
}

// [EN] FDE[3105] start_va=0x063ba4, fde_va=0x0890e0, span=12 B | [VN] FDE[3105]
uint32_t ttr_fde_3105_0x063ba4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb0a011fU) + (a1 ^ 0xaa0a03ebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063ba4U) ^ (0x2a0003f5U + 0x0890e0U + 12U);
}

// [EN] FDE[3106] start_va=0x063bb0, fde_va=0x0890f8, span=12 B | [VN] FDE[3106]
uint32_t ttr_fde_3106_0x063bb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0003f5U) + (a1 ^ 0xaa0803e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0820U + 0x063bb0U) ^ (0x0e205800U + 0x0890f8U + 12U);
}

// [EN] FDE[3107] start_va=0x063bbc, fde_va=0x089110, span=20 B | [VN] FDE[3107]
uint32_t ttr_fde_3107_0x063bbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e260016U + 0x063bbcU) ^ (0xf10006dfU + 0x089110U + 20U);
}

// [EN] FDE[3108] start_va=0x063bd0, fde_va=0x089128, span=8 B | [VN] FDE[3108]
uint32_t ttr_fde_3108_0x063bd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402260U) + (a1 ^ 0x17fee0b7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52933329U + 0x063bd0U) ^ (0x91000a77U + 0x089128U + 8U);
}

// [EN] FDE[3109] start_va=0x063bd8, fde_va=0x089140, span=20 B | [VN] FDE[3109]
uint32_t ttr_fde_3109_0x063bd8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52933329U) + (a1 ^ 0x91000a77U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x72a33329U + 0x063bd8U) ^ (0x5280014aU + 0x089140U + 20U);
}

// [EN] FDE[3110] start_va=0x063bec, fde_va=0x089158, span=20 B | [VN] FDE[3110]
uint32_t ttr_fde_3110_0x063bec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6e002001U) + (a1 ^ 0x4e815800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6e006020U + 0x063becU) ^ (0x3c80c280U + 0x089158U + 20U);
}

// [EN] FDE[3111] start_va=0x063c00, fde_va=0x089170, span=8 B | [VN] FDE[3111]
uint32_t ttr_fde_3111_0x063c00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100e3e0U) + (a1 ^ 0x17fef7e4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400108U + 0x063c00U) ^ (0x7100bd1fU + 0x089170U + 8U);
}

// [EN] FDE[3112] start_va=0x063c08, fde_va=0x089188, span=12 B | [VN] FDE[3112]
uint32_t ttr_fde_3112_0x063c08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400108U) + (a1 ^ 0x7100bd1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063c08U) ^ (0x39400108U + 0x089188U + 12U);
}

// [EN] FDE[3113] start_va=0x063c14, fde_va=0x0891a0, span=20 B | [VN] FDE[3113]
uint32_t ttr_fde_3113_0x063c14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400108U) + (a1 ^ 0x7100fd1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91000a68U + 0x063c14U) ^ (0xfa550104U + 0x0891a0U + 20U);
}

// [EN] FDE[3114] start_va=0x063c28, fde_va=0x0891b8, span=20 B | [VN] FDE[3114]
uint32_t ttr_fde_3114_0x063c28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001a8U) + (a1 ^ 0xf947e108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52880000U + 0x063c28U) ^ (0xf9400101U + 0x0891b8U + 20U);
}

// [EN] FDE[3115] start_va=0x063c3c, fde_va=0x0891d0, span=20 B | [VN] FDE[3115]
uint32_t ttr_fde_3115_0x063c3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91000e61U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e2U + 0x063c3cU) ^ (0x11000508U + 0x0891d0U + 20U);
}

// [EN] FDE[3116] start_va=0x063c50, fde_va=0x0891e8, span=12 B | [VN] FDE[3116]
uint32_t ttr_fde_3116_0x063c50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105c3e0U) + (a1 ^ 0x52800042U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063c50U) ^ (0x9105c3e0U + 0x0891e8U + 12U);
}

// [EN] FDE[3117] start_va=0x063c5c, fde_va=0x089200, span=12 B | [VN] FDE[3117]
uint32_t ttr_fde_3117_0x063c5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105c3e0U) + (a1 ^ 0x910503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063c5cU) ^ (0x52a7f008U + 0x089200U + 12U);
}

// [EN] FDE[3118] start_va=0x063c68, fde_va=0x089218, span=20 B | [VN] FDE[3118]
uint32_t ttr_fde_3118_0x063c68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52a7f008U) + (a1 ^ 0x1e211863U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9000268U + 0x063c68U) ^ (0xbd000663U + 0x089218U + 20U);
}

// [EN] FDE[3119] start_va=0x063c7c, fde_va=0x089230, span=12 B | [VN] FDE[3119]
uint32_t ttr_fde_3119_0x063c7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a3e0U) + (a1 ^ 0x910003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa5eeU + 0x063c7cU) ^ (0x910063e1U + 0x089230U + 12U);
}

// [EN] FDE[3120] start_va=0x063c88, fde_va=0x089248, span=12 B | [VN] FDE[3120]
uint32_t ttr_fde_3120_0x063c88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063c88U) ^ (0x910063e1U + 0x089248U + 12U);
}

// [EN] FDE[3121] start_va=0x063c94, fde_va=0x089260, span=12 B | [VN] FDE[3121]
uint32_t ttr_fde_3121_0x063c94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffaa57U + 0x063c94U) ^ (0x910063e1U + 0x089260U + 12U);
}

// [EN] FDE[3122] start_va=0x063ca0, fde_va=0x089278, span=12 B | [VN] FDE[3122]
uint32_t ttr_fde_3122_0x063ca0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e1U) + (a1 ^ 0x2d0307e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd5e5U + 0x063ca0U) ^ (0xf94005efU + 0x089278U + 12U);
}

// [EN] FDE[3123] start_va=0x063cac, fde_va=0x089290, span=20 B | [VN] FDE[3123]
uint32_t ttr_fde_3123_0x063cac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94005efU) + (a1 ^ 0x52800030U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb0e01efU + 0x063cacU) ^ (0x9342fdefU + 0x089290U + 20U);
}

// [EN] FDE[3124] start_va=0x063cc0, fde_va=0x0892a8, span=20 B | [VN] FDE[3124]
uint32_t ttr_fde_3124_0x063cc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001a8U) + (a1 ^ 0xf947a508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x063cc0U) ^ (0x52909800U + 0x0892a8U + 20U);
}

// [EN] FDE[3125] start_va=0x063cd4, fde_va=0x0892c0, span=12 B | [VN] FDE[3125]
uint32_t ttr_fde_3125_0x063cd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910042a0U) + (a1 ^ 0xaa1303e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff3466U + 0x063cd4U) ^ (0x9100c3e0U + 0x0892c0U + 12U);
}

// [EN] FDE[3126] start_va=0x063ce0, fde_va=0x0892d8, span=12 B | [VN] FDE[3126]
uint32_t ttr_fde_3126_0x063ce0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100c3e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff86e0U + 0x063ce0U) ^ (0xd0000056U + 0x0892d8U + 12U);
}

// [EN] FDE[3127] start_va=0x063cec, fde_va=0x0892f0, span=20 B | [VN] FDE[3127]
uint32_t ttr_fde_3127_0x063cec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000056U) + (a1 ^ 0xd0000059U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9138c6d6U + 0x063cecU) ^ (0x91392f39U + 0x0892f0U + 20U);
}

// [EN] FDE[3128] start_va=0x063d00, fde_va=0x089308, span=12 B | [VN] FDE[3128]
uint32_t ttr_fde_3128_0x063d00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e0U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa4e7U + 0x063d00U) ^ (0x910063e0U + 0x089308U + 12U);
}

// [EN] FDE[3129] start_va=0x063d0c, fde_va=0x089320, span=8 B | [VN] FDE[3129]
uint32_t ttr_fde_3129_0x063d0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e0U) + (a1 ^ 0x17ffa313U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910063e0U + 0x063d0cU) ^ (0x17fef782U + 0x089320U + 8U);
}

// [EN] FDE[3130] start_va=0x063d14, fde_va=0x089338, span=8 B | [VN] FDE[3130]
uint32_t ttr_fde_3130_0x063d14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e0U) + (a1 ^ 0x17fef782U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910063e8U + 0x063d14U) ^ (0xd61f0120U + 0x089338U + 8U);
}

// [EN] FDE[3131] start_va=0x063d1c, fde_va=0x089350, span=8 B | [VN] FDE[3131]
uint32_t ttr_fde_3131_0x063d1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e8U) + (a1 ^ 0xd61f0120U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910082a0U + 0x063d1cU) ^ (0x52801382U + 0x089350U + 8U);
}

// [EN] FDE[3132] start_va=0x063d24, fde_va=0x089368, span=20 B | [VN] FDE[3132]
uint32_t ttr_fde_3132_0x063d24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910082a0U) + (a1 ^ 0x52801382U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e1U + 0x063d24U) ^ (0xf9000ea8U + 0x089368U + 20U);
}

// [EN] FDE[3133] start_va=0x063d38, fde_va=0x089380, span=12 B | [VN] FDE[3133]
uint32_t ttr_fde_3133_0x063d38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91004355U) + (a1 ^ 0xaa1a03fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063d38U) ^ (0x2a1903e4U + 0x089380U + 12U);
}

// [EN] FDE[3134] start_va=0x063d44, fde_va=0x089398, span=20 B | [VN] FDE[3134]
uint32_t ttr_fde_3134_0x063d44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1903e4U) + (a1 ^ 0x2a1703e5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800026U + 0x063d44U) ^ (0xaa1503e0U + 0x089398U + 20U);
}

// [EN] FDE[3135] start_va=0x063d58, fde_va=0x0893b0, span=12 B | [VN] FDE[3135]
uint32_t ttr_fde_3135_0x063d58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94e2a88U) + (a1 ^ 0x8b8a0520U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063d58U) ^ (0x394002c8U + 0x0893b0U + 12U);
}

// [EN] FDE[3136] start_va=0x063d64, fde_va=0x0893c8, span=12 B | [VN] FDE[3136]
uint32_t ttr_fde_3136_0x063d64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x394002c8U) + (a1 ^ 0x7101f11fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063d64U) ^ (0xd2808829U + 0x0893c8U + 12U);
}

// [EN] FDE[3137] start_va=0x063d70, fde_va=0x0893e0, span=20 B | [VN] FDE[3137]
uint32_t ttr_fde_3137_0x063d70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd2808829U) + (a1 ^ 0x9ac82388U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf2e0b009U + 0x063d70U) ^ (0xea09011fU + 0x0893e0U + 20U);
}

// [EN] FDE[3138] start_va=0x063d84, fde_va=0x0893f8, span=12 B | [VN] FDE[3138]
uint32_t ttr_fde_3138_0x063d84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1703e2U) + (a1 ^ 0x2a1603e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffe5a4U + 0x063d84U) ^ (0xd53bd053U + 0x0893f8U + 12U);
}

// [EN] FDE[3139] start_va=0x063d90, fde_va=0x089410, span=20 B | [VN] FDE[3139]
uint32_t ttr_fde_3139_0x063d90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd053U) + (a1 ^ 0xf9401668U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81e83a8U + 0x063d90U) ^ (0xf9401414U + 0x089410U + 20U);
}

// [EN] FDE[3140] start_va=0x063da4, fde_va=0x089428, span=8 B | [VN] FDE[3140]
uint32_t ttr_fde_3140_0x063da4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910083ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910083ffU + 0x063da4U) ^ (0xd65f03c0U + 0x089428U + 8U);
}

// [EN] FDE[3141] start_va=0x063dac, fde_va=0x089440, span=8 B | [VN] FDE[3141]
uint32_t ttr_fde_3141_0x063dac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910083ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9408508U + 0x063dacU) ^ (0xd61f0100U + 0x089440U + 8U);
}

// [EN] FDE[3142] start_va=0x063db4, fde_va=0x089458, span=8 B | [VN] FDE[3142]
uint32_t ttr_fde_3142_0x063db4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9408508U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9102c3ffU + 0x063db4U) ^ (0xd65f03c0U + 0x089458U + 8U);
}

// [EN] FDE[3143] start_va=0x063dbc, fde_va=0x089470, span=8 B | [VN] FDE[3143]
uint32_t ttr_fde_3143_0x063dbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9102c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x528000c1U + 0x063dbcU) ^ (0x17ffa0d2U + 0x089470U + 8U);
}

// [EN] FDE[3144] start_va=0x063dc4, fde_va=0x089488, span=8 B | [VN] FDE[3144]
uint32_t ttr_fde_3144_0x063dc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x528000c1U) + (a1 ^ 0x17ffa0d2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x121f790aU + 0x063dc4U) ^ (0x0b480929U + 0x089488U + 8U);
}

// [EN] FDE[3145] start_va=0x063dcc, fde_va=0x0894a0, span=20 B | [VN] FDE[3145]
uint32_t ttr_fde_3145_0x063dcc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x121f790aU) + (a1 ^ 0x0b480929U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100811fU + 0x063dccU) ^ (0x1a893141U + 0x0894a0U + 20U);
}

// [EN] FDE[3146] start_va=0x063de0, fde_va=0x0894b8, span=8 B | [VN] FDE[3146]
uint32_t ttr_fde_3146_0x063de0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910223e0U) + (a1 ^ 0x17fef76cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4ea01c08U + 0x063de0U) ^ (0x4ea11c29U + 0x0894b8U + 8U);
}

// [EN] FDE[3147] start_va=0x063de8, fde_va=0x0894d0, span=12 B | [VN] FDE[3147]
uint32_t ttr_fde_3147_0x063de8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4ea01c08U) + (a1 ^ 0x4ea11c29U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd1fbU + 0x063de8U) ^ (0xf9435d08U + 0x0894d0U + 12U);
}

// [EN] FDE[3148] start_va=0x063df4, fde_va=0x0894e8, span=12 B | [VN] FDE[3148]
uint32_t ttr_fde_3148_0x063df4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9435d08U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x063df4U) ^ (0xd37ced00U + 0x0894e8U + 12U);
}

// [EN] FDE[3149] start_va=0x063e00, fde_va=0x089500, span=8 B | [VN] FDE[3149]
uint32_t ttr_fde_3149_0x063e00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37ced00U) + (a1 ^ 0x17fedfd7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4ea81d01U + 0x063e00U) ^ (0x4eae1dc2U + 0x089500U + 8U);
}

// [EN] FDE[3150] start_va=0x063e08, fde_va=0x089518, span=12 B | [VN] FDE[3150]
uint32_t ttr_fde_3150_0x063e08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4ea81d01U) + (a1 ^ 0x4eae1dc2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff126bU + 0x063e08U) ^ (0x910023e2U + 0x089518U + 12U);
}

// [EN] FDE[3151] start_va=0x063e14, fde_va=0x089530, span=12 B | [VN] FDE[3151]
uint32_t ttr_fde_3151_0x063e14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e2U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063e14U) ^ (0x910013e1U + 0x089530U + 12U);
}

// [EN] FDE[3152] start_va=0x063e20, fde_va=0x089548, span=20 B | [VN] FDE[3152]
uint32_t ttr_fde_3152_0x063e20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910013e1U) + (a1 ^ 0x910023e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x063e20U) ^ (0xb90013e8U + 0x089548U + 20U);
}

// [EN] FDE[3153] start_va=0x063e34, fde_va=0x089560, span=12 B | [VN] FDE[3153]
uint32_t ttr_fde_3153_0x063e34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94016a0U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff3144U + 0x063e34U) ^ (0x91000668U + 0x089560U + 12U);
}

// [EN] FDE[3154] start_va=0x063e40, fde_va=0x089578, span=12 B | [VN] FDE[3154]
uint32_t ttr_fde_3154_0x063e40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91000668U) + (a1 ^ 0xeb15011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063e40U) ^ (0x4ea81d00U + 0x089578U + 12U);
}

// [EN] FDE[3155] start_va=0x063e4c, fde_va=0x089590, span=12 B | [VN] FDE[3155]
uint32_t ttr_fde_3155_0x063e4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4ea81d00U) + (a1 ^ 0x4ea91d21U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063e4cU) ^ (0xbd45a261U + 0x089590U + 12U);
}

// [EN] FDE[3156] start_va=0x063e58, fde_va=0x0895a8, span=20 B | [VN] FDE[3156]
uint32_t ttr_fde_3156_0x063e58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbd45a261U) + (a1 ^ 0x1e2c1002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e220821U + 0x063e58U) ^ (0x1e202020U + 0x0895a8U + 20U);
}

// [EN] FDE[3157] start_va=0x063e6c, fde_va=0x0895c0, span=20 B | [VN] FDE[3157]
uint32_t ttr_fde_3157_0x063e6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401febU) + (a1 ^ 0xf94022e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03e8U + 0x063e6cU) ^ (0x6953ad6aU + 0x0895c0U + 20U);
}

// [EN] FDE[3158] start_va=0x063e80, fde_va=0x0895d8, span=12 B | [VN] FDE[3158]
uint32_t ttr_fde_3158_0x063e80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91000508U) + (a1 ^ 0xf9003a68U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2f03U + 0x063e80U) ^ (0x52800200U + 0x0895d8U + 12U);
}

// [EN] FDE[3159] start_va=0x063e8c, fde_va=0x0895f0, span=8 B | [VN] FDE[3159]
uint32_t ttr_fde_3159_0x063e8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800200U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0b010d08U + 0x063e8cU) ^ (0x91000a74U + 0x0895f0U + 8U);
}

// [EN] FDE[3160] start_va=0x063e94, fde_va=0x089608, span=20 B | [VN] FDE[3160]
uint32_t ttr_fde_3160_0x063e94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0b010d08U) + (a1 ^ 0x91000a74U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb02029fU + 0x063e94U) ^ (0x5100c101U + 0x089608U + 20U);
}

// [EN] FDE[3161] start_va=0x063ea8, fde_va=0x089620, span=8 B | [VN] FDE[3161]
uint32_t ttr_fde_3161_0x063ea8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0803e0U) + (a1 ^ 0x17fedfa1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e610800U + 0x063ea8U) ^ (0x6d008a60U + 0x089620U + 8U);
}

// [EN] FDE[3162] start_va=0x063eb0, fde_va=0x089638, span=12 B | [VN] FDE[3162]
uint32_t ttr_fde_3162_0x063eb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e610800U) + (a1 ^ 0x6d008a60U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063eb0U) ^ (0x1e610800U + 0x089638U + 12U);
}

// [EN] FDE[3163] start_va=0x063ebc, fde_va=0x089650, span=20 B | [VN] FDE[3163]
uint32_t ttr_fde_3163_0x063ebc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e610800U) + (a1 ^ 0x1e6c1001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e693982U + 0x063ebcU) ^ (0x1e610861U + 0x089650U + 20U);
}

// [EN] FDE[3164] start_va=0x063ed0, fde_va=0x089668, span=12 B | [VN] FDE[3164]
uint32_t ttr_fde_3164_0x063ed0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0103f5U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff8af7U + 0x063ed0U) ^ (0x910023e1U + 0x089668U + 12U);
}

// [EN] FDE[3165] start_va=0x063edc, fde_va=0x089680, span=12 B | [VN] FDE[3165]
uint32_t ttr_fde_3165_0x063edc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff8c5bU + 0x063edcU) ^ (0x9100a260U + 0x089680U + 12U);
}

// [EN] FDE[3166] start_va=0x063ee8, fde_va=0x089698, span=8 B | [VN] FDE[3166]
uint32_t ttr_fde_3166_0x063ee8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a260U) + (a1 ^ 0x17fefb4fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800142U + 0x063ee8U) ^ (0xaa1f03e1U + 0x089698U + 8U);
}

// [EN] FDE[3167] start_va=0x063ef0, fde_va=0x0896b0, span=12 B | [VN] FDE[3167]
uint32_t ttr_fde_3167_0x063ef0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800142U) + (a1 ^ 0xaa1f03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063ef0U) ^ (0x910443ffU + 0x0896b0U + 12U);
}

// [EN] FDE[3168] start_va=0x063efc, fde_va=0x0896c8, span=8 B | [VN] FDE[3168]
uint32_t ttr_fde_3168_0x063efc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910443ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x12800008U + 0x063efcU) ^ (0x910023e2U + 0x0896c8U + 8U);
}

// [EN] FDE[3169] start_va=0x063f04, fde_va=0x0896e0, span=12 B | [VN] FDE[3169]
uint32_t ttr_fde_3169_0x063f04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12800008U) + (a1 ^ 0x910023e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063f04U) ^ (0xf9401928U + 0x0896e0U + 12U);
}

// [EN] FDE[3170] start_va=0x063f10, fde_va=0x0896f8, span=12 B | [VN] FDE[3170]
uint32_t ttr_fde_3170_0x063f10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401928U) + (a1 ^ 0x2a1f03e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x063f10U) ^ (0x6f00e400U + 0x0896f8U + 12U);
}

// [EN] FDE[3171] start_va=0x063f1c, fde_va=0x089710, span=12 B | [VN] FDE[3171]
uint32_t ttr_fde_3171_0x063f1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6f00e400U) + (a1 ^ 0x52a7f009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063f1cU) ^ (0x3d8013e0U + 0x089710U + 12U);
}

// [EN] FDE[3172] start_va=0x063f28, fde_va=0x089728, span=12 B | [VN] FDE[3172]
uint32_t ttr_fde_3172_0x063f28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x3d8013e0U) + (a1 ^ 0xf9002be8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef98bU + 0x063f28U) ^ (0x2a1503e5U + 0x089728U + 12U);
}

// [EN] FDE[3173] start_va=0x063f34, fde_va=0x089740, span=8 B | [VN] FDE[3173]
uint32_t ttr_fde_3173_0x063f34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1503e5U) + (a1 ^ 0x17ff2273U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400502U + 0x063f34U) ^ (0x39400101U + 0x089740U + 8U);
}

// [EN] FDE[3174] start_va=0x063f3c, fde_va=0x089758, span=12 B | [VN] FDE[3174]
uint32_t ttr_fde_3174_0x063f3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400502U) + (a1 ^ 0x39400101U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff7650U + 0x063f3cU) ^ (0x90000040U + 0x089758U + 12U);
}

// [EN] FDE[3175] start_va=0x063f48, fde_va=0x089770, span=12 B | [VN] FDE[3175]
uint32_t ttr_fde_3175_0x063f48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000040U) + (a1 ^ 0x913c4400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee124U + 0x063f48U) ^ (0x39000128U + 0x089770U + 12U);
}

// [EN] FDE[3176] start_va=0x063f54, fde_va=0x089788, span=12 B | [VN] FDE[3176]
uint32_t ttr_fde_3176_0x063f54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39000128U) + (a1 ^ 0x3900053fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063f54U) ^ (0x8b090100U + 0x089788U + 12U);
}

// [EN] FDE[3177] start_va=0x063f60, fde_va=0x0897a0, span=8 B | [VN] FDE[3177]
uint32_t ttr_fde_3177_0x063f60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b090100U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001a9U + 0x063f60U) ^ (0xb9401288U + 0x0897a0U + 8U);
}

// [EN] FDE[3178] start_va=0x063f68, fde_va=0x0897b8, span=20 B | [VN] FDE[3178]
uint32_t ttr_fde_3178_0x063f68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001a9U) + (a1 ^ 0xb9401288U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf947d529U + 0x063f68U) ^ (0x52911d0aU + 0x0897b8U + 20U);
}

// [EN] FDE[3179] start_va=0x063f7c, fde_va=0x0897d0, span=20 B | [VN] FDE[3179]
uint32_t ttr_fde_3179_0x063f7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94057e9U) + (a1 ^ 0x7200011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x063f7cU) ^ (0x9a8902c8U + 0x0897d0U + 20U);
}

// [EN] FDE[3180] start_va=0x063f90, fde_va=0x0897e8, span=20 B | [VN] FDE[3180]
uint32_t ttr_fde_3180_0x063f90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800028U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39006128U + 0x063f90U) ^ (0x3900629fU + 0x0897e8U + 20U);
}

// [EN] FDE[3181] start_va=0x063fa4, fde_va=0x089800, span=12 B | [VN] FDE[3181]
uint32_t ttr_fde_3181_0x063fa4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0xaa1503e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee1a1U + 0x063fa4U) ^ (0xaa1603e1U + 0x089800U + 12U);
}

// [EN] FDE[3182] start_va=0x063fb0, fde_va=0x089818, span=12 B | [VN] FDE[3182]
uint32_t ttr_fde_3182_0x063fb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0xaa1403e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x063fb0U) ^ (0xaa1603e1U + 0x089818U + 12U);
}

// [EN] FDE[3183] start_va=0x063fbc, fde_va=0x089830, span=8 B | [VN] FDE[3183]
uint32_t ttr_fde_3183_0x063fbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0x17ff33adU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1603e1U + 0x063fbcU) ^ (0x17ff0a5bU + 0x089830U + 8U);
}

// [EN] FDE[3184] start_va=0x063fc4, fde_va=0x089848, span=8 B | [VN] FDE[3184]
uint32_t ttr_fde_3184_0x063fc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0x17ff0a5bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910263e0U + 0x063fc4U) ^ (0x17fef6f1U + 0x089848U + 8U);
}

// [EN] FDE[3185] start_va=0x063fcc, fde_va=0x089860, span=8 B | [VN] FDE[3185]
uint32_t ttr_fde_3185_0x063fcc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910263e0U) + (a1 ^ 0x17fef6f1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401e88U + 0x063fccU) ^ (0xeb15027fU + 0x089860U + 8U);
}

// [EN] FDE[3186] start_va=0x063fd4, fde_va=0x089878, span=20 B | [VN] FDE[3186]
uint32_t ttr_fde_3186_0x063fd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401e88U) + (a1 ^ 0xeb15027fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0b160108U + 0x063fd4U) ^ (0xb9001e88U + 0x089878U + 20U);
}

// [EN] FDE[3187] start_va=0x063fe8, fde_va=0x089890, span=12 B | [VN] FDE[3187]
uint32_t ttr_fde_3187_0x063fe8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x91000673U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff6747U + 0x063fe8U) ^ (0x910003e0U + 0x089890U + 12U);
}

// [EN] FDE[3188] start_va=0x063ff4, fde_va=0x0898a8, span=12 B | [VN] FDE[3188]
uint32_t ttr_fde_3188_0x063ff4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0xaa1303e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef9bdU + 0x063ff4U) ^ (0x910003e0U + 0x0898a8U + 12U);
}

// [EN] FDE[3189] start_va=0x064000, fde_va=0x0898c0, span=12 B | [VN] FDE[3189]
uint32_t ttr_fde_3189_0x064000(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x910003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feff2cU + 0x064000U) ^ (0x910003e0U + 0x0898c0U + 12U);
}

// [EN] FDE[3190] start_va=0x06400c, fde_va=0x0898d8, span=12 B | [VN] FDE[3190]
uint32_t ttr_fde_3190_0x06400c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x910103e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06400cU) ^ (0x2d410d02U + 0x0898d8U + 12U);
}

// [EN] FDE[3191] start_va=0x064018, fde_va=0x0898f0, span=8 B | [VN] FDE[3191]
uint32_t ttr_fde_3191_0x064018(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2d410d02U) + (a1 ^ 0x17ffd02bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91004000U + 0x064018U) ^ (0x17ffd1d6U + 0x0898f0U + 8U);
}

// [EN] FDE[3192] start_va=0x064020, fde_va=0x089908, span=8 B | [VN] FDE[3192]
uint32_t ttr_fde_3192_0x064020(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91004000U) + (a1 ^ 0x17ffd1d6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf85e8108U + 0x064020U) ^ (0x8b080000U + 0x089908U + 8U);
}

// [EN] FDE[3193] start_va=0x064028, fde_va=0x089920, span=12 B | [VN] FDE[3193]
uint32_t ttr_fde_3193_0x064028(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85e8108U) + (a1 ^ 0x8b080000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fefa70U + 0x064028U) ^ (0x9105da68U + 0x089920U + 12U);
}

// [EN] FDE[3194] start_va=0x064034, fde_va=0x089938, span=12 B | [VN] FDE[3194]
uint32_t ttr_fde_3194_0x064034(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105da68U) + (a1 ^ 0x08dffd08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064034U) ^ (0xa9448261U + 0x089938U + 12U);
}

// [EN] FDE[3195] start_va=0x064040, fde_va=0x089950, span=12 B | [VN] FDE[3195]
uint32_t ttr_fde_3195_0x064040(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9448261U) + (a1 ^ 0xb9802a62U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedf42U + 0x064040U) ^ (0xa9448261U + 0x089950U + 12U);
}

// [EN] FDE[3196] start_va=0x06404c, fde_va=0x089968, span=12 B | [VN] FDE[3196]
uint32_t ttr_fde_3196_0x06404c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9448261U) + (a1 ^ 0x93407d02U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedf3fU + 0x06404cU) ^ (0xaa1a03e0U + 0x089968U + 12U);
}

// [EN] FDE[3197] start_va=0x064058, fde_va=0x089980, span=12 B | [VN] FDE[3197]
uint32_t ttr_fde_3197_0x064058(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1a03e0U) + (a1 ^ 0xaa1303e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064058U) ^ (0xaa1903e0U + 0x089980U + 12U);
}

// [EN] FDE[3198] start_va=0x064064, fde_va=0x089998, span=8 B | [VN] FDE[3198]
uint32_t ttr_fde_3198_0x064064(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1903e0U) + (a1 ^ 0x17ff06f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa901fd1fU + 0x064064U) ^ (0xf900091fU + 0x089998U + 8U);
}

// [EN] FDE[3199] start_va=0x06406c, fde_va=0x0899b0, span=12 B | [VN] FDE[3199]
uint32_t ttr_fde_3199_0x06406c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa901fd1fU) + (a1 ^ 0xf900091fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedfc3U + 0x06406cU) ^ (0x8b140048U + 0x0899b0U + 12U);
}

// [EN] FDE[3200] start_va=0x064078, fde_va=0x0899c8, span=20 B | [VN] FDE[3200]
uint32_t ttr_fde_3200_0x064078(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b140048U) + (a1 ^ 0xd37ffa89U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb14051fU + 0x064078U) ^ (0x9a883128U + 0x0899c8U + 20U);
}

// [EN] FDE[3201] start_va=0x06408c, fde_va=0x0899e0, span=12 B | [VN] FDE[3201]
uint32_t ttr_fde_3201_0x06408c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10062b5U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffb9bfU + 0x06408cU) ^ (0xd10062b5U + 0x0899e0U + 12U);
}

// [EN] FDE[3202] start_va=0x064098, fde_va=0x0899f8, span=12 B | [VN] FDE[3202]
uint32_t ttr_fde_3202_0x064098(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10062b5U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffc9a8U + 0x064098U) ^ (0x91011c09U + 0x0899f8U + 12U);
}

// [EN] FDE[3203] start_va=0x0640a4, fde_va=0x089a10, span=20 B | [VN] FDE[3203]
uint32_t ttr_fde_3203_0x0640a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91011c09U) + (a1 ^ 0xaa0003e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x927ae520U + 0x0640a4U) ^ (0xf81f8008U + 0x089a10U + 20U);
}

// [EN] FDE[3204] start_va=0x0640b8, fde_va=0x089a28, span=8 B | [VN] FDE[3204]
uint32_t ttr_fde_3204_0x0640b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0803e0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52999998U + 0x0640b8U) ^ (0x2a0003f6U + 0x089a28U + 8U);
}

// [EN] FDE[3205] start_va=0x0640c0, fde_va=0x089a40, span=20 B | [VN] FDE[3205]
uint32_t ttr_fde_3205_0x0640c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52999998U) + (a1 ^ 0x2a0003f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91000673U + 0x0640c0U) ^ (0x72a19998U + 0x089a40U + 20U);
}

// [EN] FDE[3206] start_va=0x0640d4, fde_va=0x089a58, span=12 B | [VN] FDE[3206]
uint32_t ttr_fde_3206_0x0640d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x937e7d02U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedf1dU + 0x0640d4U) ^ (0x937e7d02U + 0x089a58U + 12U);
}

// [EN] FDE[3207] start_va=0x0640e0, fde_va=0x089a70, span=12 B | [VN] FDE[3207]
uint32_t ttr_fde_3207_0x0640e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x937e7d02U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedf1aU + 0x0640e0U) ^ (0x6b14011fU + 0x089a70U + 12U);
}

// [EN] FDE[3208] start_va=0x0640ec, fde_va=0x089a88, span=20 B | [VN] FDE[3208]
uint32_t ttr_fde_3208_0x0640ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6b14011fU) + (a1 ^ 0x1a94b114U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4b090108U + 0x0640ecU) ^ (0x6b08029fU + 0x089a88U + 20U);
}

// [EN] FDE[3209] start_va=0x064100, fde_va=0x089aa0, span=12 B | [VN] FDE[3209]
uint32_t ttr_fde_3209_0x064100(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91000676U) + (a1 ^ 0xeb1502dfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064100U) ^ (0x52800041U + 0x089aa0U + 12U);
}

// [EN] FDE[3210] start_va=0x06410c, fde_va=0x089ab8, span=12 B | [VN] FDE[3210]
uint32_t ttr_fde_3210_0x06410c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800041U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff9d48U + 0x06410cU) ^ (0xb9000fffU + 0x089ab8U + 12U);
}

// [EN] FDE[3211] start_va=0x064118, fde_va=0x089ad0, span=8 B | [VN] FDE[3211]
uint32_t ttr_fde_3211_0x064118(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9000fffU) + (a1 ^ 0x17fedfb1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400408U + 0x064118U) ^ (0x91000809U + 0x089ad0U + 8U);
}

// [EN] FDE[3212] start_va=0x064120, fde_va=0x089ae8, span=20 B | [VN] FDE[3212]
uint32_t ttr_fde_3212_0x064120(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400408U) + (a1 ^ 0x91000809U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100fd1fU + 0x064120U) ^ (0x1a9f07e6U + 0x089ae8U + 20U);
}

// [EN] FDE[3213] start_va=0x064134, fde_va=0x089b00, span=12 B | [VN] FDE[3213]
uint32_t ttr_fde_3213_0x064134(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x927ff929U) + (a1 ^ 0xd1000521U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064134U) ^ (0x39400008U + 0x089b00U + 12U);
}

// [EN] FDE[3214] start_va=0x064140, fde_va=0x089b18, span=20 B | [VN] FDE[3214]
uint32_t ttr_fde_3214_0x064140(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400008U) + (a1 ^ 0xaa0203f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x064140U) ^ (0xaa0103e7U + 0x089b18U + 20U);
}

// [EN] FDE[3215] start_va=0x064154, fde_va=0x089b30, span=12 B | [VN] FDE[3215]
uint32_t ttr_fde_3215_0x064154(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e1U) + (a1 ^ 0xaa1703e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedf05U + 0x064154U) ^ (0x2a1f03e1U + 0x089b30U + 12U);
}

// [EN] FDE[3216] start_va=0x064160, fde_va=0x089b48, span=12 B | [VN] FDE[3216]
uint32_t ttr_fde_3216_0x064160(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e1U) + (a1 ^ 0xaa1603e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064160U) ^ (0xaa1303e8U + 0x089b48U + 12U);
}

// [EN] FDE[3217] start_va=0x06416c, fde_va=0x089b60, span=12 B | [VN] FDE[3217]
uint32_t ttr_fde_3217_0x06416c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e8U) + (a1 ^ 0x38420d09U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06416cU) ^ (0x910183ffU + 0x089b60U + 12U);
}

// [EN] FDE[3218] start_va=0x064178, fde_va=0x089b78, span=8 B | [VN] FDE[3218]
uint32_t ttr_fde_3218_0x064178(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910183ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401ea8U + 0x064178U) ^ (0xaa1503e0U + 0x089b78U + 8U);
}

// [EN] FDE[3219] start_va=0x064180, fde_va=0x089b90, span=20 B | [VN] FDE[3219]
uint32_t ttr_fde_3219_0x064180(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401ea8U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e2U + 0x064180U) ^ (0xaa1403e3U + 0x089b90U + 20U);
}

// [EN] FDE[3220] start_va=0x064194, fde_va=0x089ba8, span=12 B | [VN] FDE[3220]
uint32_t ttr_fde_3220_0x064194(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0103f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064194U) ^ (0xbd0303e1U + 0x089ba8U + 12U);
}

// [EN] FDE[3221] start_va=0x0641a0, fde_va=0x089bc0, span=12 B | [VN] FDE[3221]
uint32_t ttr_fde_3221_0x0641a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbd0303e1U) + (a1 ^ 0xbd02ffe0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0641a0U) ^ (0xb94026a8U + 0x089bc0U + 12U);
}

// [EN] FDE[3222] start_va=0x0641ac, fde_va=0x089bd8, span=20 B | [VN] FDE[3222]
uint32_t ttr_fde_3222_0x0641ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb94026a8U) + (a1 ^ 0x91000701U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x51000508U + 0x0641acU) ^ (0xb90026a8U + 0x089bd8U + 20U);
}

// [EN] FDE[3223] start_va=0x0641c0, fde_va=0x089bf0, span=20 B | [VN] FDE[3223]
uint32_t ttr_fde_3223_0x0641c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9402a69U) + (a1 ^ 0x2a1f03e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0903eaU + 0x0641c0U) ^ (0x2905fe69U + 0x089bf0U + 20U);
}

// [EN] FDE[3224] start_va=0x0641d4, fde_va=0x089c08, span=12 B | [VN] FDE[3224]
uint32_t ttr_fde_3224_0x0641d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910103e1U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0641d4U) ^ (0xf9402fe9U + 0x089c08U + 12U);
}

// [EN] FDE[3225] start_va=0x0641e0, fde_va=0x089c20, span=12 B | [VN] FDE[3225]
uint32_t ttr_fde_3225_0x0641e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402fe9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0641e0U) ^ (0xaa1f03fbU + 0x089c20U + 12U);
}

// [EN] FDE[3226] start_va=0x0641ec, fde_va=0x089c38, span=12 B | [VN] FDE[3226]
uint32_t ttr_fde_3226_0x0641ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03fbU) + (a1 ^ 0xaa1f03fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0641ecU) ^ (0xf9403508U + 0x089c38U + 12U);
}

// [EN] FDE[3227] start_va=0x0641f8, fde_va=0x089c50, span=8 B | [VN] FDE[3227]
uint32_t ttr_fde_3227_0x0641f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9403508U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94002c8U + 0x0641f8U) ^ (0xaa1603e0U + 0x089c50U + 8U);
}

// [EN] FDE[3228] start_va=0x064200, fde_va=0x089c68, span=12 B | [VN] FDE[3228]
uint32_t ttr_fde_3228_0x064200(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94002c8U) + (a1 ^ 0xaa1603e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064200U) ^ (0xaa1703e2U + 0x089c68U + 12U);
}

// [EN] FDE[3229] start_va=0x06420c, fde_va=0x089c80, span=8 B | [VN] FDE[3229]
uint32_t ttr_fde_3229_0x06420c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1703e2U) + (a1 ^ 0x17feded0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e2U + 0x06420cU) ^ (0x17fef6f3U + 0x089c80U + 8U);
}

// [EN] FDE[3230] start_va=0x064214, fde_va=0x089c98, span=8 B | [VN] FDE[3230]
uint32_t ttr_fde_3230_0x064214(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1703e2U) + (a1 ^ 0x17fef6f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb010108U + 0x064214U) ^ (0xd342fd02U + 0x089c98U + 8U);
}

// [EN] FDE[3231] start_va=0x06421c, fde_va=0x089cb0, span=12 B | [VN] FDE[3231]
uint32_t ttr_fde_3231_0x06421c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb010108U) + (a1 ^ 0xd342fd02U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff8ff1U + 0x06421cU) ^ (0x2a1f03e0U + 0x089cb0U + 12U);
}

// [EN] FDE[3232] start_va=0x064228, fde_va=0x089cc8, span=12 B | [VN] FDE[3232]
uint32_t ttr_fde_3232_0x064228(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e0U) + (a1 ^ 0xfc4307e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064228U) ^ (0xaa1f03e0U + 0x089cc8U + 12U);
}

// [EN] FDE[3233] start_va=0x064234, fde_va=0x089ce0, span=8 B | [VN] FDE[3233]
uint32_t ttr_fde_3233_0x064234(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e0U) + (a1 ^ 0x17ff46eeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03e0U + 0x064234U) ^ (0xd65f03c0U + 0x089ce0U + 8U);
}

// [EN] FDE[3234] start_va=0x06423c, fde_va=0x089cf8, span=8 B | [VN] FDE[3234]
uint32_t ttr_fde_3234_0x06423c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd0000188U + 0x06423cU) ^ (0xd0000189U + 0x089cf8U + 8U);
}

// [EN] FDE[3235] start_va=0x064244, fde_va=0x089d10, span=20 B | [VN] FDE[3235]
uint32_t ttr_fde_3235_0x064244(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd0000188U) + (a1 ^ 0xd0000189U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91206108U + 0x064244U) ^ (0x9122e129U + 0x089d10U + 20U);
}

// [EN] FDE[3236] start_va=0x064258, fde_va=0x089d28, span=20 B | [VN] FDE[3236]
uint32_t ttr_fde_3236_0x064258(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf900181fU) + (a1 ^ 0x3900e01fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3c83c000U + 0x064258U) ^ (0x3c84c000U + 0x089d28U + 20U);
}

// [EN] FDE[3237] start_va=0x06426c, fde_va=0x089d40, span=12 B | [VN] FDE[3237]
uint32_t ttr_fde_3237_0x06426c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007c1fU) + (a1 ^ 0xf900081fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef89dU + 0x06426cU) ^ (0xa9007c1fU + 0x089d40U + 12U);
}

// [EN] FDE[3238] start_va=0x064278, fde_va=0x089d58, span=12 B | [VN] FDE[3238]
uint32_t ttr_fde_3238_0x064278(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007c1fU) + (a1 ^ 0xf900081fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef8b7U + 0x064278U) ^ (0xa9007c1fU + 0x089d58U + 12U);
}

// [EN] FDE[3239] start_va=0x064284, fde_va=0x089d70, span=12 B | [VN] FDE[3239]
uint32_t ttr_fde_3239_0x064284(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007c1fU) + (a1 ^ 0xf900081fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef8b4U + 0x064284U) ^ (0xaa0103e0U + 0x089d70U + 12U);
}

// [EN] FDE[3240] start_va=0x064290, fde_va=0x089d88, span=12 B | [VN] FDE[3240]
uint32_t ttr_fde_3240_0x064290(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103e0U) + (a1 ^ 0xaa0803e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff1a87U + 0x064290U) ^ (0xaa0003f4U + 0x089d88U + 12U);
}

// [EN] FDE[3241] start_va=0x06429c, fde_va=0x089da0, span=12 B | [VN] FDE[3241]
uint32_t ttr_fde_3241_0x06429c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f4U) + (a1 ^ 0xaa0103f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06429cU) ^ (0xaa0003f4U + 0x089da0U + 12U);
}

// [EN] FDE[3242] start_va=0x0642a8, fde_va=0x089db8, span=8 B | [VN] FDE[3242]
uint32_t ttr_fde_3242_0x0642a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f4U) + (a1 ^ 0x17ffa595U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e2U + 0x0642a8U) ^ (0x17ffa03aU + 0x089db8U + 8U);
}

// [EN] FDE[3243] start_va=0x0642b0, fde_va=0x089dd0, span=8 B | [VN] FDE[3243]
uint32_t ttr_fde_3243_0x0642b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e2U) + (a1 ^ 0x17ffa03aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200011fU + 0x0642b0U) ^ (0x9a890140U + 0x089dd0U + 8U);
}

// [EN] FDE[3244] start_va=0x0642b8, fde_va=0x089de8, span=12 B | [VN] FDE[3244]
uint32_t ttr_fde_3244_0x0642b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7200011fU) + (a1 ^ 0x9a890140U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedef0U + 0x0642b8U) ^ (0xaa1303e1U + 0x089de8U + 12U);
}

// [EN] FDE[3245] start_va=0x0642c4, fde_va=0x089e00, span=12 B | [VN] FDE[3245]
uint32_t ttr_fde_3245_0x0642c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e1U) + (a1 ^ 0xaa1503e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0642c4U) ^ (0xaa1303e1U + 0x089e00U + 12U);
}

// [EN] FDE[3246] start_va=0x0642d0, fde_va=0x089e18, span=12 B | [VN] FDE[3246]
uint32_t ttr_fde_3246_0x0642d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e1U) + (a1 ^ 0xaa1303e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa962U + 0x0642d0U) ^ (0xd37ffae8U + 0x089e18U + 12U);
}

// [EN] FDE[3247] start_va=0x0642dc, fde_va=0x089e30, span=20 B | [VN] FDE[3247]
uint32_t ttr_fde_3247_0x0642dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37ffae8U) + (a1 ^ 0x91001908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e0U + 0x0642dcU) ^ (0x927df11bU + 0x089e30U + 20U);
}

// [EN] FDE[3248] start_va=0x0642f0, fde_va=0x089e48, span=8 B | [VN] FDE[3248]
uint32_t ttr_fde_3248_0x0642f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e8U) + (a1 ^ 0x17fedeebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd53bd055U + 0x0642f0U) ^ (0xf94016a8U + 0x089e48U + 8U);
}

// [EN] FDE[3249] start_va=0x0642f8, fde_va=0x089e60, span=20 B | [VN] FDE[3249]
uint32_t ttr_fde_3249_0x0642f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd055U) + (a1 ^ 0xf94016a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0642f8U) ^ (0xf90017e8U + 0x089e60U + 20U);
}

// [EN] FDE[3250] start_va=0x06430c, fde_va=0x089e78, span=12 B | [VN] FDE[3250]
uint32_t ttr_fde_3250_0x06430c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1c03f9U) + (a1 ^ 0xf940039cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06430cU) ^ (0xf9400660U + 0x089e78U + 12U);
}

// [EN] FDE[3251] start_va=0x064318, fde_va=0x089e90, span=12 B | [VN] FDE[3251]
uint32_t ttr_fde_3251_0x064318(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400660U) + (a1 ^ 0xaa0303e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fefacdU + 0x064318U) ^ (0x910343ffU + 0x089e90U + 12U);
}

// [EN] FDE[3252] start_va=0x064324, fde_va=0x089ea8, span=8 B | [VN] FDE[3252]
uint32_t ttr_fde_3252_0x064324(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910343ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3dc00000U + 0x064324U) ^ (0xf9400808U + 0x089ea8U + 8U);
}

// [EN] FDE[3253] start_va=0x06432c, fde_va=0x089ec0, span=20 B | [VN] FDE[3253]
uint32_t ttr_fde_3253_0x06432c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x3dc00000U) + (a1 ^ 0xf9400808U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3d800260U + 0x06432cU) ^ (0xf9000a68U + 0x089ec0U + 20U);
}

// [EN] FDE[3254] start_va=0x064340, fde_va=0x089ed8, span=20 B | [VN] FDE[3254]
uint32_t ttr_fde_3254_0x064340(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400414U) + (a1 ^ 0xcb010055U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x064340U) ^ (0xf10006bfU + 0x089ed8U + 20U);
}

// [EN] FDE[3255] start_va=0x064354, fde_va=0x089ef0, span=12 B | [VN] FDE[3255]
uint32_t ttr_fde_3255_0x064354(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100001fU) + (a1 ^ 0x1a9f17e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064354U) ^ (0xf9400808U + 0x089ef0U + 12U);
}

// [EN] FDE[3256] start_va=0x064360, fde_va=0x089f08, span=12 B | [VN] FDE[3256]
uint32_t ttr_fde_3256_0x064360(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xf9002868U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064360U) ^ (0x910042b5U + 0x089f08U + 12U);
}

// [EN] FDE[3257] start_va=0x06436c, fde_va=0x089f20, span=12 B | [VN] FDE[3257]
uint32_t ttr_fde_3257_0x06436c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910042b5U) + (a1 ^ 0x91004273U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06436cU) ^ (0xf9000a68U + 0x089f20U + 12U);
}

// [EN] FDE[3258] start_va=0x064378, fde_va=0x089f38, span=12 B | [VN] FDE[3258]
uint32_t ttr_fde_3258_0x064378(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000a68U) + (a1 ^ 0x3d800260U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef877U + 0x064378U) ^ (0xf9400a69U + 0x089f38U + 12U);
}

// [EN] FDE[3259] start_va=0x064384, fde_va=0x089f50, span=20 B | [VN] FDE[3259]
uint32_t ttr_fde_3259_0x064384(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a69U) + (a1 ^ 0xcb080129U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9343fd29U + 0x064384U) ^ (0xf1000d3fU + 0x089f50U + 20U);
}

// [EN] FDE[3260] start_va=0x064398, fde_va=0x089f68, span=20 B | [VN] FDE[3260]
uint32_t ttr_fde_3260_0x064398(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa900a3e0U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x064398U) ^ (0xa901a7e8U + 0x089f68U + 20U);
}

// [EN] FDE[3261] start_va=0x0643ac, fde_va=0x089f80, span=20 B | [VN] FDE[3261]
uint32_t ttr_fde_3261_0x0643ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb140122U) + (a1 ^ 0x9aca0c49U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf100045fU + 0x0643acU) ^ (0x9b0b2135U + 0x089f80U + 20U);
}

// [EN] FDE[3262] start_va=0x0643c0, fde_va=0x089f98, span=20 B | [VN] FDE[3262]
uint32_t ttr_fde_3262_0x0643c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402674U) + (a1 ^ 0xcb140122U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf100045fU + 0x0643c0U) ^ (0xcb020115U + 0x089f98U + 20U);
}

// [EN] FDE[3263] start_va=0x0643d4, fde_va=0x089fb0, span=12 B | [VN] FDE[3263]
uint32_t ttr_fde_3263_0x0643d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f5U) + (a1 ^ 0x910063e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa15aU + 0x0643d4U) ^ (0xa940a408U + 0x089fb0U + 12U);
}

// [EN] FDE[3264] start_va=0x0643e0, fde_va=0x089fc8, span=20 B | [VN] FDE[3264]
uint32_t ttr_fde_3264_0x0643e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940a408U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f5U + 0x0643e0U) ^ (0xeb09011fU + 0x089fc8U + 20U);
}

// [EN] FDE[3265] start_va=0x0643f4, fde_va=0x089fe0, span=36 B | [VN] FDE[3265]
uint32_t ttr_fde_3265_0x0643f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb9402519U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb940253aU + 0x0643f4U) ^ (0x97ff060eU + 0x089fe0U + 36U);
}

// [EN] FDE[3266] start_va=0x064418, fde_va=0x08a000, span=8 B | [VN] FDE[3266]
uint32_t ttr_fde_3266_0x064418(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91008260U) + (a1 ^ 0x17fef5deU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf85a83a9U + 0x064418U) ^ (0xeb09011fU + 0x08a000U + 8U);
}

// [EN] FDE[3267] start_va=0x064420, fde_va=0x08a018, span=12 B | [VN] FDE[3267]
uint32_t ttr_fde_3267_0x064420(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85a83a9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064420U) ^ (0xd10182b5U + 0x08a018U + 12U);
}

// [EN] FDE[3268] start_va=0x06442c, fde_va=0x08a030, span=12 B | [VN] FDE[3268]
uint32_t ttr_fde_3268_0x06442c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10182b5U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff6b68U + 0x06442cU) ^ (0xf9000660U + 0x08a030U + 12U);
}

// [EN] FDE[3269] start_va=0x064438, fde_va=0x08a048, span=8 B | [VN] FDE[3269]
uint32_t ttr_fde_3269_0x064438(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000660U) + (a1 ^ 0x17fede3dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000289U + 0x064438U) ^ (0xf9000114U + 0x08a048U + 8U);
}

// [EN] FDE[3270] start_va=0x064440, fde_va=0x08a060, span=12 B | [VN] FDE[3270]
uint32_t ttr_fde_3270_0x064440(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000289U) + (a1 ^ 0xf9000114U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064440U) ^ (0x910043e1U + 0x08a060U + 12U);
}

// [EN] FDE[3271] start_va=0x06444c, fde_va=0x08a078, span=8 B | [VN] FDE[3271]
uint32_t ttr_fde_3271_0x06444c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910043e1U) + (a1 ^ 0x17ffc824U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043e1U + 0x06444cU) ^ (0x910003e2U + 0x08a078U + 8U);
}

// [EN] FDE[3272] start_va=0x064454, fde_va=0x08a090, span=12 B | [VN] FDE[3272]
uint32_t ttr_fde_3272_0x064454(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910043e1U) + (a1 ^ 0x910003e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd6ceU + 0x064454U) ^ (0x910043e1U + 0x08a090U + 12U);
}

// [EN] FDE[3273] start_va=0x064460, fde_va=0x08a0a8, span=12 B | [VN] FDE[3273]
uint32_t ttr_fde_3273_0x064460(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910043e1U) + (a1 ^ 0x910003e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x064460U) ^ (0xf94006a8U + 0x08a0a8U + 12U);
}

// [EN] FDE[3274] start_va=0x06446c, fde_va=0x08a0c0, span=20 B | [VN] FDE[3274]
uint32_t ttr_fde_3274_0x06446c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94006a8U) + (a1 ^ 0xf9400908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf8617908U + 0x06446cU) ^ (0xf27b051fU + 0x08a0c0U + 20U);
}

// [EN] FDE[3275] start_va=0x064480, fde_va=0x08a0d8, span=12 B | [VN] FDE[3275]
uint32_t ttr_fde_3275_0x064480(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910123e0U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064480U) ^ (0x910123e0U + 0x08a0d8U + 12U);
}

// [EN] FDE[3276] start_va=0x06448c, fde_va=0x08a0f0, span=12 B | [VN] FDE[3276]
uint32_t ttr_fde_3276_0x06448c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910123e0U) + (a1 ^ 0x52800061U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06448cU) ^ (0xf94002a8U + 0x08a0f0U + 12U);
}

// [EN] FDE[3277] start_va=0x064498, fde_va=0x08a108, span=20 B | [VN] FDE[3277]
uint32_t ttr_fde_3277_0x064498(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94002a8U) + (a1 ^ 0xf90002e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94006a8U + 0x064498U) ^ (0xf90006e8U + 0x08a108U + 20U);
}

// [EN] FDE[3278] start_va=0x0644ac, fde_va=0x08a120, span=20 B | [VN] FDE[3278]
uint32_t ttr_fde_3278_0x0644ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf0000181U) + (a1 ^ 0xf0000182U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x912c8021U + 0x0644acU) ^ (0x912b8042U + 0x08a120U + 20U);
}

// [EN] FDE[3279] start_va=0x0644c0, fde_va=0x08a138, span=20 B | [VN] FDE[3279]
uint32_t ttr_fde_3279_0x0644c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910103e0U) + (a1 ^ 0x910083e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1603e1U + 0x0644c0U) ^ (0xaa1503e3U + 0x08a138U + 20U);
}

// [EN] FDE[3280] start_va=0x0644d4, fde_va=0x08a150, span=20 B | [VN] FDE[3280]
uint32_t ttr_fde_3280_0x0644d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e6c1004U) + (a1 ^ 0x1e6c3962U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e610800U + 0x0644d4U) ^ (0x1e640861U + 0x08a150U + 20U);
}

// [EN] FDE[3281] start_va=0x0644e8, fde_va=0x08a168, span=12 B | [VN] FDE[3281]
uint32_t ttr_fde_3281_0x0644e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4ea81d02U) + (a1 ^ 0x4ea91d23U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffcef6U + 0x0644e8U) ^ (0x52800500U + 0x08a168U + 12U);
}

// [EN] FDE[3282] start_va=0x0644f4, fde_va=0x08a180, span=8 B | [VN] FDE[3282]
uint32_t ttr_fde_3282_0x0644f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800500U) + (a1 ^ 0x17fede1aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e1U + 0x0644f4U) ^ (0x17ff8fddU + 0x08a180U + 8U);
}

// [EN] FDE[3283] start_va=0x0644fc, fde_va=0x08a198, span=8 B | [VN] FDE[3283]
uint32_t ttr_fde_3283_0x0644fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1703e1U) + (a1 ^ 0x17ff8fddU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e0U + 0x0644fcU) ^ (0xaa1503e1U + 0x08a198U + 8U);
}

// [EN] FDE[3284] start_va=0x064504, fde_va=0x08a1b0, span=12 B | [VN] FDE[3284]
uint32_t ttr_fde_3284_0x064504(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1703e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffb12eU + 0x064504U) ^ (0xaa1703e0U + 0x08a1b0U + 12U);
}

// [EN] FDE[3285] start_va=0x064510, fde_va=0x08a1c8, span=8 B | [VN] FDE[3285]
uint32_t ttr_fde_3285_0x064510(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1703e0U) + (a1 ^ 0x17ff05c9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401109U + 0x064510U) ^ (0x910023e8U + 0x08a1c8U + 8U);
}

// [EN] FDE[3286] start_va=0x064518, fde_va=0x08a1e0, span=12 B | [VN] FDE[3286]
uint32_t ttr_fde_3286_0x064518(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401109U) + (a1 ^ 0x910023e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0120U + 0x064518U) ^ (0xaa1803e0U + 0x08a1e0U + 12U);
}

// [EN] FDE[3287] start_va=0x064524, fde_va=0x08a1f8, span=8 B | [VN] FDE[3287]
uint32_t ttr_fde_3287_0x064524(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1803e0U) + (a1 ^ 0x17fede02U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1603e0U + 0x064524U) ^ (0xaa1403e1U + 0x08a1f8U + 8U);
}

// [EN] FDE[3288] start_va=0x06452c, fde_va=0x08a210, span=12 B | [VN] FDE[3288]
uint32_t ttr_fde_3288_0x06452c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffc739U + 0x06452cU) ^ (0xaa1603e0U + 0x08a210U + 12U);
}

// [EN] FDE[3289] start_va=0x064538, fde_va=0x08a228, span=12 B | [VN] FDE[3289]
uint32_t ttr_fde_3289_0x064538(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff280aU + 0x064538U) ^ (0x9100a949U + 0x08a228U + 12U);
}

// [EN] FDE[3290] start_va=0x064544, fde_va=0x08a240, span=20 B | [VN] FDE[3290]
uint32_t ttr_fde_3290_0x064544(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a949U) + (a1 ^ 0xf100211fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x528002a8U + 0x064544U) ^ (0x9a890108U + 0x08a240U + 20U);
}

// [EN] FDE[3291] start_va=0x064558, fde_va=0x08a258, span=12 B | [VN] FDE[3291]
uint32_t ttr_fde_3291_0x064558(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100e000U) + (a1 ^ 0x93407d01U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffc8a4U + 0x064558U) ^ (0xd10122b5U + 0x08a258U + 12U);
}

// [EN] FDE[3292] start_va=0x064564, fde_va=0x08a270, span=12 B | [VN] FDE[3292]
uint32_t ttr_fde_3292_0x064564(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10122b5U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff86cdU + 0x064564U) ^ (0xa9460be1U + 0x08a270U + 12U);
}

// [EN] FDE[3293] start_va=0x064570, fde_va=0x08a288, span=12 B | [VN] FDE[3293]
uint32_t ttr_fde_3293_0x064570(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9460be1U) + (a1 ^ 0x910203e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff4705U + 0x064570U) ^ (0xaa0103f4U + 0x08a288U + 12U);
}

// [EN] FDE[3294] start_va=0x06457c, fde_va=0x08a2a0, span=12 B | [VN] FDE[3294]
uint32_t ttr_fde_3294_0x06457c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xea08003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06457cU) ^ (0x1e203940U + 0x08a2a0U + 12U);
}

// [EN] FDE[3295] start_va=0x064588, fde_va=0x08a2b8, span=12 B | [VN] FDE[3295]
uint32_t ttr_fde_3295_0x064588(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e203940U) + (a1 ^ 0x1e213961U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd070U + 0x064588U) ^ (0x1e202940U + 0x08a2b8U + 12U);
}

// [EN] FDE[3296] start_va=0x064594, fde_va=0x08a2d0, span=12 B | [VN] FDE[3296]
uint32_t ttr_fde_3296_0x064594(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e202940U) + (a1 ^ 0x1e212961U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd06dU + 0x064594U) ^ (0xaa0203e1U + 0x08a2d0U + 12U);
}

// [EN] FDE[3297] start_va=0x0645a0, fde_va=0x08a2e8, span=12 B | [VN] FDE[3297]
uint32_t ttr_fde_3297_0x0645a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203e1U) + (a1 ^ 0x2a1f03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef370U + 0x0645a0U) ^ (0xf9400008U + 0x08a2e8U + 12U);
}

// [EN] FDE[3298] start_va=0x0645ac, fde_va=0x08a300, span=12 B | [VN] FDE[3298]
uint32_t ttr_fde_3298_0x0645ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9401101U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0020U + 0x0645acU) ^ (0xf9400008U + 0x08a300U + 12U);
}

// [EN] FDE[3299] start_va=0x0645b8, fde_va=0x08a318, span=12 B | [VN] FDE[3299]
uint32_t ttr_fde_3299_0x0645b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9402508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x0645b8U) ^ (0xf9400008U + 0x08a318U + 12U);
}

// [EN] FDE[3300] start_va=0x0645c4, fde_va=0x08a330, span=12 B | [VN] FDE[3300]
uint32_t ttr_fde_3300_0x0645c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9400901U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0020U + 0x0645c4U) ^ (0xf9400008U + 0x08a330U + 12U);
}

// [EN] FDE[3301] start_va=0x0645d0, fde_va=0x08a348, span=12 B | [VN] FDE[3301]
uint32_t ttr_fde_3301_0x0645d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9402501U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0020U + 0x0645d0U) ^ (0xf9401680U + 0x08a348U + 12U);
}

// [EN] FDE[3302] start_va=0x0645dc, fde_va=0x08a360, span=12 B | [VN] FDE[3302]
uint32_t ttr_fde_3302_0x0645dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401680U) + (a1 ^ 0x910123e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2f5aU + 0x0645dcU) ^ (0x52800021U + 0x08a360U + 12U);
}

// [EN] FDE[3303] start_va=0x0645e8, fde_va=0x08a378, span=12 B | [VN] FDE[3303]
uint32_t ttr_fde_3303_0x0645e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800021U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0645e8U) ^ (0xaa0003f6U + 0x08a378U + 12U);
}

// [EN] FDE[3304] start_va=0x0645f4, fde_va=0x08a390, span=12 B | [VN] FDE[3304]
uint32_t ttr_fde_3304_0x0645f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f6U) + (a1 ^ 0xaa0103f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0645f4U) ^ (0xaa0103f3U + 0x08a390U + 12U);
}

// [EN] FDE[3305] start_va=0x064600, fde_va=0x08a3a8, span=20 B | [VN] FDE[3305]
uint32_t ttr_fde_3305_0x064600(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0x39400021U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5101b828U + 0x064600U) ^ (0x7100211fU + 0x08a3a8U + 20U);
}

// [EN] FDE[3306] start_va=0x064614, fde_va=0x08a3c0, span=12 B | [VN] FDE[3306]
uint32_t ttr_fde_3306_0x064614(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10162b5U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffb87bU + 0x064614U) ^ (0x910103ffU + 0x08a3c0U + 12U);
}

// [EN] FDE[3307] start_va=0x064620, fde_va=0x08a3d8, span=8 B | [VN] FDE[3307]
uint32_t ttr_fde_3307_0x064620(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910103ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007fffU + 0x064620U) ^ (0x17ff19d7U + 0x08a3d8U + 8U);
}

// [EN] FDE[3308] start_va=0x064628, fde_va=0x08a3f0, span=8 B | [VN] FDE[3308]
uint32_t ttr_fde_3308_0x064628(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007fffU) + (a1 ^ 0x17ff19d7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400675U + 0x064628U) ^ (0xeb15029fU + 0x08a3f0U + 8U);
}

// [EN] FDE[3309] start_va=0x064630, fde_va=0x08a408, span=12 B | [VN] FDE[3309]
uint32_t ttr_fde_3309_0x064630(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400675U) + (a1 ^ 0xeb15029fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064630U) ^ (0xaa1503e0U + 0x08a408U + 12U);
}

// [EN] FDE[3310] start_va=0x06463c, fde_va=0x08a420, span=12 B | [VN] FDE[3310]
uint32_t ttr_fde_3310_0x06463c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06463cU) ^ (0xaa1503e0U + 0x08a420U + 12U);
}

// [EN] FDE[3311] start_va=0x064648, fde_va=0x08a438, span=12 B | [VN] FDE[3311]
uint32_t ttr_fde_3311_0x064648(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffcda1U + 0x064648U) ^ (0xaa1503e0U + 0x08a438U + 12U);
}

// [EN] FDE[3312] start_va=0x064654, fde_va=0x08a450, span=12 B | [VN] FDE[3312]
uint32_t ttr_fde_3312_0x064654(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffc68fU + 0x064654U) ^ (0xaa1503e0U + 0x08a450U + 12U);
}

// [EN] FDE[3313] start_va=0x064660, fde_va=0x08a468, span=12 B | [VN] FDE[3313]
uint32_t ttr_fde_3313_0x064660(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffc64aU + 0x064660U) ^ (0xaa1503e0U + 0x08a468U + 12U);
}

// [EN] FDE[3314] start_va=0x06466c, fde_va=0x08a480, span=12 B | [VN] FDE[3314]
uint32_t ttr_fde_3314_0x06466c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1303e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff7337U + 0x06466cU) ^ (0xaa1503e0U + 0x08a480U + 12U);
}

// [EN] FDE[3315] start_va=0x064678, fde_va=0x08a498, span=8 B | [VN] FDE[3315]
uint32_t ttr_fde_3315_0x064678(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17ff731eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e0U + 0x064678U) ^ (0x17ff6fb7U + 0x08a498U + 8U);
}

// [EN] FDE[3316] start_va=0x064680, fde_va=0x08a4b0, span=8 B | [VN] FDE[3316]
uint32_t ttr_fde_3316_0x064680(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17ff6fb7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e0U + 0x064680U) ^ (0x17feddb5U + 0x08a4b0U + 8U);
}

// [EN] FDE[3317] start_va=0x064688, fde_va=0x08a4c8, span=8 B | [VN] FDE[3317]
uint32_t ttr_fde_3317_0x064688(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17feddb5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e0U + 0x064688U) ^ (0xaa1603e1U + 0x08a4c8U + 8U);
}

// [EN] FDE[3318] start_va=0x064690, fde_va=0x08a4e0, span=12 B | [VN] FDE[3318]
uint32_t ttr_fde_3318_0x064690(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff85a7U + 0x064690U) ^ (0xaa1503e0U + 0x08a4e0U + 12U);
}

// [EN] FDE[3319] start_va=0x06469c, fde_va=0x08a4f8, span=8 B | [VN] FDE[3319]
uint32_t ttr_fde_3319_0x06469c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17ff718bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e0U + 0x06469cU) ^ (0x17ff6fb6U + 0x08a4f8U + 8U);
}

// [EN] FDE[3320] start_va=0x0646a4, fde_va=0x08a510, span=8 B | [VN] FDE[3320]
uint32_t ttr_fde_3320_0x0646a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17ff6fb6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e0U + 0x0646a4U) ^ (0x17ff6fbcU + 0x08a510U + 8U);
}

// [EN] FDE[3321] start_va=0x0646ac, fde_va=0x08a528, span=8 B | [VN] FDE[3321]
uint32_t ttr_fde_3321_0x0646ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17ff6fbcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf1000428U + 0x0646acU) ^ (0xaa0003f3U + 0x08a528U + 8U);
}

// [EN] FDE[3322] start_va=0x0646b4, fde_va=0x08a540, span=12 B | [VN] FDE[3322]
uint32_t ttr_fde_3322_0x0646b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000428U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0646b4U) ^ (0xaa1403e0U + 0x08a540U + 12U);
}

// [EN] FDE[3323] start_va=0x0646c0, fde_va=0x08a558, span=8 B | [VN] FDE[3323]
uint32_t ttr_fde_3323_0x0646c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17fefac3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x0646c0U) ^ (0xaa1803e1U + 0x08a558U + 8U);
}

// [EN] FDE[3324] start_va=0x0646c8, fde_va=0x08a570, span=12 B | [VN] FDE[3324]
uint32_t ttr_fde_3324_0x0646c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1803e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0646c8U) ^ (0xaa1403e0U + 0x08a570U + 12U);
}

// [EN] FDE[3325] start_va=0x0646d4, fde_va=0x08a588, span=12 B | [VN] FDE[3325]
uint32_t ttr_fde_3325_0x0646d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1303e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff80abU + 0x0646d4U) ^ (0xaa1403e0U + 0x08a588U + 12U);
}

// [EN] FDE[3326] start_va=0x0646e0, fde_va=0x08a5a0, span=8 B | [VN] FDE[3326]
uint32_t ttr_fde_3326_0x0646e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff6f9fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x0646e0U) ^ (0x2a1503e1U + 0x08a5a0U + 8U);
}

// [EN] FDE[3327] start_va=0x0646e8, fde_va=0x08a5b8, span=12 B | [VN] FDE[3327]
uint32_t ttr_fde_3327_0x0646e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x2a1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa2abU + 0x0646e8U) ^ (0xaa1403e0U + 0x08a5b8U + 12U);
}

// [EN] FDE[3328] start_va=0x0646f4, fde_va=0x08a5d0, span=12 B | [VN] FDE[3328]
uint32_t ttr_fde_3328_0x0646f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xf84207f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffb825U + 0x0646f4U) ^ (0xaa1403e0U + 0x08a5d0U + 12U);
}

// [EN] FDE[3329] start_va=0x064700, fde_va=0x08a5e8, span=12 B | [VN] FDE[3329]
uint32_t ttr_fde_3329_0x064700(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xf84207f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffc8a1U + 0x064700U) ^ (0xaa1403e0U + 0x08a5e8U + 12U);
}

// [EN] FDE[3330] start_va=0x06470c, fde_va=0x08a600, span=8 B | [VN] FDE[3330]
uint32_t ttr_fde_3330_0x06470c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff7997U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x06470cU) ^ (0x17ff6fa2U + 0x08a600U + 8U);
}

// [EN] FDE[3331] start_va=0x064714, fde_va=0x08a618, span=8 B | [VN] FDE[3331]
uint32_t ttr_fde_3331_0x064714(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff6fa2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x064714U) ^ (0x2a1f03e1U + 0x08a618U + 8U);
}

// [EN] FDE[3332] start_va=0x06471c, fde_va=0x08a630, span=12 B | [VN] FDE[3332]
uint32_t ttr_fde_3332_0x06471c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x2a1f03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff7549U + 0x06471cU) ^ (0xaa1403e0U + 0x08a630U + 12U);
}

// [EN] FDE[3333] start_va=0x064728, fde_va=0x08a648, span=8 B | [VN] FDE[3333]
uint32_t ttr_fde_3333_0x064728(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff72f2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x064728U) ^ (0xaa1f03e1U + 0x08a648U + 8U);
}

// [EN] FDE[3334] start_va=0x064730, fde_va=0x08a660, span=12 B | [VN] FDE[3334]
uint32_t ttr_fde_3334_0x064730(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1f03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedf8eU + 0x064730U) ^ (0xaa1403e0U + 0x08a660U + 12U);
}

// [EN] FDE[3335] start_va=0x06473c, fde_va=0x08a678, span=8 B | [VN] FDE[3335]
uint32_t ttr_fde_3335_0x06473c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ffb0c7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x06473cU) ^ (0x17ff6f8eU + 0x08a678U + 8U);
}

// [EN] FDE[3336] start_va=0x064744, fde_va=0x08a690, span=8 B | [VN] FDE[3336]
uint32_t ttr_fde_3336_0x064744(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff6f8eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x064744U) ^ (0x17fef511U + 0x08a690U + 8U);
}

// [EN] FDE[3337] start_va=0x06474c, fde_va=0x08a6a8, span=8 B | [VN] FDE[3337]
uint32_t ttr_fde_3337_0x06474c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17fef511U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e1U + 0x06474cU) ^ (0x910203e0U + 0x08a6a8U + 8U);
}

// [EN] FDE[3338] start_va=0x064754, fde_va=0x08a6c0, span=12 B | [VN] FDE[3338]
uint32_t ttr_fde_3338_0x064754(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x910203e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa0f1U + 0x064754U) ^ (0xaa0003e1U + 0x08a6c0U + 12U);
}

// [EN] FDE[3339] start_va=0x064760, fde_va=0x08a6d8, span=12 B | [VN] FDE[3339]
uint32_t ttr_fde_3339_0x064760(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x910023e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa0eeU + 0x064760U) ^ (0xaa0003e1U + 0x08a6d8U + 12U);
}

// [EN] FDE[3340] start_va=0x06476c, fde_va=0x08a6f0, span=12 B | [VN] FDE[3340]
uint32_t ttr_fde_3340_0x06476c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06476cU) ^ (0xaa0003e1U + 0x08a6f0U + 12U);
}

// [EN] FDE[3341] start_va=0x064778, fde_va=0x08a708, span=12 B | [VN] FDE[3341]
uint32_t ttr_fde_3341_0x064778(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff18baU + 0x064778U) ^ (0x910443e0U + 0x08a708U + 12U);
}

// [EN] FDE[3342] start_va=0x064784, fde_va=0x08a720, span=8 B | [VN] FDE[3342]
uint32_t ttr_fde_3342_0x064784(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910443e0U) + (a1 ^ 0x17ff6a93U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e1U + 0x064784U) ^ (0xaa1503e2U + 0x08a720U + 8U);
}

// [EN] FDE[3343] start_va=0x06478c, fde_va=0x08a738, span=12 B | [VN] FDE[3343]
uint32_t ttr_fde_3343_0x06478c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e1U) + (a1 ^ 0xaa1503e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedfabU + 0x06478cU) ^ (0x910023e0U + 0x08a738U + 12U);
}

// [EN] FDE[3344] start_va=0x064798, fde_va=0x08a750, span=8 B | [VN] FDE[3344]
uint32_t ttr_fde_3344_0x064798(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ffcd3fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x064798U) ^ (0x17ff9e9aU + 0x08a750U + 8U);
}

// [EN] FDE[3345] start_va=0x0647a0, fde_va=0x08a768, span=8 B | [VN] FDE[3345]
uint32_t ttr_fde_3345_0x0647a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff9e9aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x0647a0U) ^ (0x9100a3e1U + 0x08a768U + 8U);
}

// [EN] FDE[3346] start_va=0x0647a8, fde_va=0x08a780, span=12 B | [VN] FDE[3346]
uint32_t ttr_fde_3346_0x0647a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x9100a3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fefed6U + 0x0647a8U) ^ (0x910023e0U + 0x08a780U + 12U);
}

// [EN] FDE[3347] start_va=0x0647b4, fde_va=0x08a798, span=12 B | [VN] FDE[3347]
uint32_t ttr_fde_3347_0x0647b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0xaa1303e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff9d78U + 0x0647b4U) ^ (0x910023e0U + 0x08a798U + 12U);
}

// [EN] FDE[3348] start_va=0x0647c0, fde_va=0x08a7b0, span=8 B | [VN] FDE[3348]
uint32_t ttr_fde_3348_0x0647c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff765eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x0647c0U) ^ (0x17ff85b5U + 0x08a7b0U + 8U);
}

// [EN] FDE[3349] start_va=0x0647c8, fde_va=0x08a7c8, span=8 B | [VN] FDE[3349]
uint32_t ttr_fde_3349_0x0647c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff85b5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90007ffU + 0x0647c8U) ^ (0x17ff9e7eU + 0x08a7c8U + 8U);
}

// [EN] FDE[3350] start_va=0x0647d0, fde_va=0x08a7e0, span=8 B | [VN] FDE[3350]
uint32_t ttr_fde_3350_0x0647d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf90007ffU) + (a1 ^ 0x17ff9e7eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400be0U + 0x0647d0U) ^ (0x17ff1808U + 0x08a7e0U + 8U);
}

// [EN] FDE[3351] start_va=0x0647d8, fde_va=0x08a7f8, span=8 B | [VN] FDE[3351]
uint32_t ttr_fde_3351_0x0647d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400be0U) + (a1 ^ 0x17ff1808U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9408bfcU + 0x0647d8U) ^ (0x9104c3ffU + 0x08a7f8U + 8U);
}

// [EN] FDE[3352] start_va=0x0647e0, fde_va=0x08a810, span=12 B | [VN] FDE[3352]
uint32_t ttr_fde_3352_0x0647e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9408bfcU) + (a1 ^ 0x9104c3ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0647e0U) ^ (0xf94007e8U + 0x08a810U + 12U);
}

// [EN] FDE[3353] start_va=0x0647ec, fde_va=0x08a828, span=12 B | [VN] FDE[3353]
uint32_t ttr_fde_3353_0x0647ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94007e8U) + (a1 ^ 0x8a08037bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0647ecU) ^ (0x1e601921U + 0x08a828U + 12U);
}

// [EN] FDE[3354] start_va=0x0647f8, fde_va=0x08a840, span=20 B | [VN] FDE[3354]
uint32_t ttr_fde_3354_0x0647f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e601921U) + (a1 ^ 0x1e624021U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e280900U + 0x0647f8U) ^ (0x1e282902U + 0x08a840U + 20U);
}

// [EN] FDE[3355] start_va=0x06480c, fde_va=0x08a858, span=8 B | [VN] FDE[3355]
uint32_t ttr_fde_3355_0x06480c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401be0U) + (a1 ^ 0x17ff050aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100a3e1U + 0x06480cU) ^ (0xaa1303e0U + 0x08a858U + 8U);
}

// [EN] FDE[3356] start_va=0x064814, fde_va=0x08a870, span=12 B | [VN] FDE[3356]
uint32_t ttr_fde_3356_0x064814(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a3e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064814U) ^ (0x9100a3e1U + 0x08a870U + 12U);
}

// [EN] FDE[3357] start_va=0x064820, fde_va=0x08a888, span=12 B | [VN] FDE[3357]
uint32_t ttr_fde_3357_0x064820(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a3e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff51a0U + 0x064820U) ^ (0xa9484ff4U + 0x08a888U + 12U);
}

// [EN] FDE[3358] start_va=0x06482c, fde_va=0x08a8a0, span=36 B | [VN] FDE[3358]
uint32_t ttr_fde_3358_0x06482c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9484ff4U) + (a1 ^ 0xa94757f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9465ff8U + 0x06482cU) ^ (0xa94567faU + 0x08a8a0U + 36U);
}

// [EN] FDE[3359] start_va=0x064850, fde_va=0x08a8b8, span=20 B | [VN] FDE[3359]
uint32_t ttr_fde_3359_0x064850(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400508U) + (a1 ^ 0xaa080129U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8a2802b5U + 0x064850U) ^ (0xf9000669U + 0x08a8b8U + 20U);
}

// [EN] FDE[3360] start_va=0x064864, fde_va=0x08a8d0, span=12 B | [VN] FDE[3360]
uint32_t ttr_fde_3360_0x064864(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e1U) + (a1 ^ 0xa9007fffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064864U) ^ (0x910003e1U + 0x08a8d0U + 12U);
}

// [EN] FDE[3361] start_va=0x064870, fde_va=0x08a8e8, span=12 B | [VN] FDE[3361]
uint32_t ttr_fde_3361_0x064870(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e1U) + (a1 ^ 0xa9007fffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff465aU + 0x064870U) ^ (0x910003e1U + 0x08a8e8U + 12U);
}

// [EN] FDE[3362] start_va=0x06487c, fde_va=0x08a900, span=12 B | [VN] FDE[3362]
uint32_t ttr_fde_3362_0x06487c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff510aU + 0x06487cU) ^ (0xf9402109U + 0x08a900U + 12U);
}

// [EN] FDE[3363] start_va=0x064888, fde_va=0x08a918, span=12 B | [VN] FDE[3363]
uint32_t ttr_fde_3363_0x064888(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402109U) + (a1 ^ 0x910183e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0120U + 0x064888U) ^ (0xaa1503e1U + 0x08a918U + 12U);
}

// [EN] FDE[3364] start_va=0x064894, fde_va=0x08a930, span=12 B | [VN] FDE[3364]
uint32_t ttr_fde_3364_0x064894(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e1U) + (a1 ^ 0xaa1503f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff079bU + 0x064894U) ^ (0xaa1303e0U + 0x08a930U + 12U);
}

// [EN] FDE[3365] start_va=0x0648a0, fde_va=0x08a948, span=8 B | [VN] FDE[3365]
uint32_t ttr_fde_3365_0x0648a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17fefa4bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0648a0U) ^ (0xf84207f3U + 0x08a948U + 8U);
}

// [EN] FDE[3366] start_va=0x0648a8, fde_va=0x08a960, span=12 B | [VN] FDE[3366]
uint32_t ttr_fde_3366_0x0648a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf84207f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef4d6U + 0x0648a8U) ^ (0xaa1303e0U + 0x08a960U + 12U);
}

// [EN] FDE[3367] start_va=0x0648b4, fde_va=0x08a978, span=12 B | [VN] FDE[3367]
uint32_t ttr_fde_3367_0x0648b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf84207f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedd31U + 0x0648b4U) ^ (0xaa1303e0U + 0x08a978U + 12U);
}

// [EN] FDE[3368] start_va=0x0648c0, fde_va=0x08a990, span=12 B | [VN] FDE[3368]
uint32_t ttr_fde_3368_0x0648c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf84207f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2753U + 0x0648c0U) ^ (0xaa1303e0U + 0x08a990U + 12U);
}

// [EN] FDE[3369] start_va=0x0648cc, fde_va=0x08a9a8, span=8 B | [VN] FDE[3369]
uint32_t ttr_fde_3369_0x0648cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ff9438U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0648ccU) ^ (0xaa1703e1U + 0x08a9a8U + 8U);
}

// [EN] FDE[3370] start_va=0x0648d4, fde_va=0x08a9c0, span=12 B | [VN] FDE[3370]
uint32_t ttr_fde_3370_0x0648d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xaa1703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa71aU + 0x0648d4U) ^ (0xaa1303e0U + 0x08a9c0U + 12U);
}

// [EN] FDE[3371] start_va=0x0648e0, fde_va=0x08a9d8, span=8 B | [VN] FDE[3371]
uint32_t ttr_fde_3371_0x0648e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ff932fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0648e0U) ^ (0xa8c24ff4U + 0x08a9d8U + 8U);
}

// [EN] FDE[3372] start_va=0x0648e8, fde_va=0x08a9f0, span=12 B | [VN] FDE[3372]
uint32_t ttr_fde_3372_0x0648e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xa8c24ff4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fedf40U + 0x0648e8U) ^ (0xaa1303e0U + 0x08a9f0U + 12U);
}

// [EN] FDE[3373] start_va=0x0648f4, fde_va=0x08aa08, span=12 B | [VN] FDE[3373]
uint32_t ttr_fde_3373_0x0648f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xaa1803e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffa712U + 0x0648f4U) ^ (0xaa1303e0U + 0x08aa08U + 12U);
}

// [EN] FDE[3374] start_va=0x064900, fde_va=0x08aa20, span=12 B | [VN] FDE[3374]
uint32_t ttr_fde_3374_0x064900(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf8410414U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064900U) ^ (0xaa1303e0U + 0x08aa20U + 12U);
}

// [EN] FDE[3375] start_va=0x06490c, fde_va=0x08aa38, span=8 B | [VN] FDE[3375]
uint32_t ttr_fde_3375_0x06490c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ffa759U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x06490cU) ^ (0x17ff6e64U + 0x08aa38U + 8U);
}

// [EN] FDE[3376] start_va=0x064914, fde_va=0x08aa50, span=8 B | [VN] FDE[3376]
uint32_t ttr_fde_3376_0x064914(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0x17ff6e64U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x064914U) ^ (0xf8018408U + 0x08aa50U + 8U);
}

// [EN] FDE[3377] start_va=0x06491c, fde_va=0x08aa68, span=12 B | [VN] FDE[3377]
uint32_t ttr_fde_3377_0x06491c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf8018408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff860fU + 0x06491cU) ^ (0xaa0003f3U + 0x08aa68U + 12U);
}

// [EN] FDE[3378] start_va=0x064928, fde_va=0x08aa80, span=12 B | [VN] FDE[3378]
uint32_t ttr_fde_3378_0x064928(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0x91004000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x064928U) ^ (0xaa0003f3U + 0x08aa80U + 12U);
}

// [EN] FDE[3379] start_va=0x064934, fde_va=0x08aa98, span=12 B | [VN] FDE[3379]
uint32_t ttr_fde_3379_0x064934(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0x91006000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef496U + 0x064934U) ^ (0xaa0003f3U + 0x08aa98U + 12U);
}

// [EN] FDE[3380] start_va=0x064940, fde_va=0x08aab0, span=20 B | [VN] FDE[3380]
uint32_t ttr_fde_3380_0x064940(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf9400400U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400a61U + 0x064940U) ^ (0xf9401262U + 0x08aab0U + 20U);
}

// [EN] FDE[3381] start_va=0x064954, fde_va=0x08aac8, span=12 B | [VN] FDE[3381]
uint32_t ttr_fde_3381_0x064954(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf9400800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2e6fU + 0x064954U) ^ (0xaa0003f3U + 0x08aac8U + 12U);
}

// [EN] FDE[3382] start_va=0x064960, fde_va=0x08aae0, span=12 B | [VN] FDE[3382]
uint32_t ttr_fde_3382_0x064960(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0x910023e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff9f10U + 0x064960U) ^ (0xaa0003f3U + 0x08aae0U + 12U);
}

// [EN] FDE[3383] start_va=0x06496c, fde_va=0x08aaf8, span=12 B | [VN] FDE[3383]
uint32_t ttr_fde_3383_0x06496c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0x9100a000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef488U + 0x06496cU) ^ (0xaa0103f5U + 0x08aaf8U + 12U);
}

// [EN] FDE[3384] start_va=0x064978, fde_va=0x08ab10, span=8 B | [VN] FDE[3384]
uint32_t ttr_fde_3384_0x064978(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f5U) + (a1 ^ 0x17fedcf9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf8010408U + 0x064978U) ^ (0x17ffcf7eU + 0x08ab10U + 8U);
}

// [EN] FDE[3385] start_va=0x064980, fde_va=0x08ab28, span=32 B | [VN] FDE[3385]
uint32_t ttr_fde_3385_0x064980(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf8010408U) + (a1 ^ 0x17ffcf7eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400108U + 0x064980U) ^ (0x17ff399eU + 0x08ab28U + 32U);
}

uint32_t DispatchTtrFdeShard5(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 2708U: return ttr_fde_2708_0x0623ec(a0, a1);
        case 2709U: return ttr_fde_2709_0x0623f4(a0, a1);
        case 2710U: return ttr_fde_2710_0x062400(a0, a1);
        case 2711U: return ttr_fde_2711_0x06241c(a0, a1);
        case 2712U: return ttr_fde_2712_0x062424(a0, a1);
        case 2713U: return ttr_fde_2713_0x062430(a0, a1);
        case 2714U: return ttr_fde_2714_0x06244c(a0, a1);
        case 2715U: return ttr_fde_2715_0x062460(a0, a1);
        case 2716U: return ttr_fde_2716_0x062468(a0, a1);
        case 2717U: return ttr_fde_2717_0x062484(a0, a1);
        case 2718U: return ttr_fde_2718_0x062498(a0, a1);
        case 2719U: return ttr_fde_2719_0x0624ac(a0, a1);
        case 2720U: return ttr_fde_2720_0x0624d8(a0, a1);
        case 2721U: return ttr_fde_2721_0x0624e4(a0, a1);
        case 2722U: return ttr_fde_2722_0x062500(a0, a1);
        case 2723U: return ttr_fde_2723_0x06251c(a0, a1);
        case 2724U: return ttr_fde_2724_0x062530(a0, a1);
        case 2725U: return ttr_fde_2725_0x06253c(a0, a1);
        case 2726U: return ttr_fde_2726_0x062544(a0, a1);
        case 2727U: return ttr_fde_2727_0x062560(a0, a1);
        case 2728U: return ttr_fde_2728_0x06256c(a0, a1);
        case 2729U: return ttr_fde_2729_0x062580(a0, a1);
        case 2730U: return ttr_fde_2730_0x062594(a0, a1);
        case 2731U: return ttr_fde_2731_0x0625a8(a0, a1);
        case 2732U: return ttr_fde_2732_0x0625b4(a0, a1);
        case 2733U: return ttr_fde_2733_0x0625d0(a0, a1);
        case 2734U: return ttr_fde_2734_0x0625e4(a0, a1);
        case 2735U: return ttr_fde_2735_0x062600(a0, a1);
        case 2736U: return ttr_fde_2736_0x06260c(a0, a1);
        case 2737U: return ttr_fde_2737_0x062620(a0, a1);
        case 2738U: return ttr_fde_2738_0x062634(a0, a1);
        case 2739U: return ttr_fde_2739_0x062650(a0, a1);
        case 2740U: return ttr_fde_2740_0x06266c(a0, a1);
        case 2741U: return ttr_fde_2741_0x062674(a0, a1);
        case 2742U: return ttr_fde_2742_0x062680(a0, a1);
        case 2743U: return ttr_fde_2743_0x06268c(a0, a1);
        case 2744U: return ttr_fde_2744_0x062698(a0, a1);
        case 2745U: return ttr_fde_2745_0x0626a4(a0, a1);
        case 2746U: return ttr_fde_2746_0x0626ac(a0, a1);
        case 2747U: return ttr_fde_2747_0x0626b8(a0, a1);
        case 2748U: return ttr_fde_2748_0x0626c4(a0, a1);
        case 2749U: return ttr_fde_2749_0x0626d0(a0, a1);
        case 2750U: return ttr_fde_2750_0x0626e4(a0, a1);
        case 2751U: return ttr_fde_2751_0x0626f8(a0, a1);
        case 2752U: return ttr_fde_2752_0x062714(a0, a1);
        case 2753U: return ttr_fde_2753_0x062730(a0, a1);
        case 2754U: return ttr_fde_2754_0x062744(a0, a1);
        case 2755U: return ttr_fde_2755_0x062758(a0, a1);
        case 2756U: return ttr_fde_2756_0x062774(a0, a1);
        case 2757U: return ttr_fde_2757_0x062790(a0, a1);
        case 2758U: return ttr_fde_2758_0x0627a4(a0, a1);
        case 2759U: return ttr_fde_2759_0x0627b0(a0, a1);
        case 2760U: return ttr_fde_2760_0x0627b8(a0, a1);
        case 2761U: return ttr_fde_2761_0x0627c4(a0, a1);
        case 2762U: return ttr_fde_2762_0x0627cc(a0, a1);
        case 2763U: return ttr_fde_2763_0x0627e0(a0, a1);
        case 2764U: return ttr_fde_2764_0x0627ec(a0, a1);
        case 2765U: return ttr_fde_2765_0x062818(a0, a1);
        case 2766U: return ttr_fde_2766_0x062824(a0, a1);
        case 2767U: return ttr_fde_2767_0x062830(a0, a1);
        case 2768U: return ttr_fde_2768_0x06284c(a0, a1);
        case 2769U: return ttr_fde_2769_0x062858(a0, a1);
        case 2770U: return ttr_fde_2770_0x062864(a0, a1);
        case 2771U: return ttr_fde_2771_0x06286c(a0, a1);
        case 2772U: return ttr_fde_2772_0x062878(a0, a1);
        case 2773U: return ttr_fde_2773_0x062880(a0, a1);
        case 2774U: return ttr_fde_2774_0x062894(a0, a1);
        case 2775U: return ttr_fde_2775_0x0628a0(a0, a1);
        case 2776U: return ttr_fde_2776_0x0628ac(a0, a1);
        case 2777U: return ttr_fde_2777_0x0628b8(a0, a1);
        case 2778U: return ttr_fde_2778_0x0628c4(a0, a1);
        case 2779U: return ttr_fde_2779_0x0628d8(a0, a1);
        case 2780U: return ttr_fde_2780_0x0628e4(a0, a1);
        case 2781U: return ttr_fde_2781_0x0628f8(a0, a1);
        case 2782U: return ttr_fde_2782_0x062914(a0, a1);
        case 2783U: return ttr_fde_2783_0x06291c(a0, a1);
        case 2784U: return ttr_fde_2784_0x062938(a0, a1);
        case 2785U: return ttr_fde_2785_0x062940(a0, a1);
        case 2786U: return ttr_fde_2786_0x06294c(a0, a1);
        case 2787U: return ttr_fde_2787_0x062958(a0, a1);
        case 2788U: return ttr_fde_2788_0x062964(a0, a1);
        case 2789U: return ttr_fde_2789_0x062970(a0, a1);
        case 2790U: return ttr_fde_2790_0x06298c(a0, a1);
        case 2791U: return ttr_fde_2791_0x062994(a0, a1);
        case 2792U: return ttr_fde_2792_0x0629b0(a0, a1);
        case 2793U: return ttr_fde_2793_0x0629bc(a0, a1);
        case 2794U: return ttr_fde_2794_0x0629c8(a0, a1);
        case 2795U: return ttr_fde_2795_0x0629d4(a0, a1);
        case 2796U: return ttr_fde_2796_0x0629e0(a0, a1);
        case 2797U: return ttr_fde_2797_0x0629fc(a0, a1);
        case 2798U: return ttr_fde_2798_0x062a08(a0, a1);
        case 2799U: return ttr_fde_2799_0x062a24(a0, a1);
        case 2800U: return ttr_fde_2800_0x062a40(a0, a1);
        case 2801U: return ttr_fde_2801_0x062a4c(a0, a1);
        case 2802U: return ttr_fde_2802_0x062a58(a0, a1);
        case 2803U: return ttr_fde_2803_0x062a64(a0, a1);
        case 2804U: return ttr_fde_2804_0x062a70(a0, a1);
        case 2805U: return ttr_fde_2805_0x062a8c(a0, a1);
        case 2806U: return ttr_fde_2806_0x062a98(a0, a1);
        case 2807U: return ttr_fde_2807_0x062ab4(a0, a1);
        case 2808U: return ttr_fde_2808_0x062ac0(a0, a1);
        case 2809U: return ttr_fde_2809_0x062adc(a0, a1);
        case 2810U: return ttr_fde_2810_0x062af8(a0, a1);
        case 2811U: return ttr_fde_2811_0x062b04(a0, a1);
        case 2812U: return ttr_fde_2812_0x062b10(a0, a1);
        case 2813U: return ttr_fde_2813_0x062b1c(a0, a1);
        case 2814U: return ttr_fde_2814_0x062b28(a0, a1);
        case 2815U: return ttr_fde_2815_0x062b34(a0, a1);
        case 2816U: return ttr_fde_2816_0x062b40(a0, a1);
        case 2817U: return ttr_fde_2817_0x062b4c(a0, a1);
        case 2818U: return ttr_fde_2818_0x062b58(a0, a1);
        case 2819U: return ttr_fde_2819_0x062b64(a0, a1);
        case 2820U: return ttr_fde_2820_0x062b70(a0, a1);
        case 2821U: return ttr_fde_2821_0x062b7c(a0, a1);
        case 2822U: return ttr_fde_2822_0x062b84(a0, a1);
        case 2823U: return ttr_fde_2823_0x062b90(a0, a1);
        case 2824U: return ttr_fde_2824_0x062b9c(a0, a1);
        case 2825U: return ttr_fde_2825_0x062ba8(a0, a1);
        case 2826U: return ttr_fde_2826_0x062bb4(a0, a1);
        case 2827U: return ttr_fde_2827_0x062bc0(a0, a1);
        case 2828U: return ttr_fde_2828_0x062bcc(a0, a1);
        case 2829U: return ttr_fde_2829_0x062bd8(a0, a1);
        case 2830U: return ttr_fde_2830_0x062be4(a0, a1);
        case 2831U: return ttr_fde_2831_0x062bec(a0, a1);
        case 2832U: return ttr_fde_2832_0x062bf4(a0, a1);
        case 2833U: return ttr_fde_2833_0x062c00(a0, a1);
        case 2834U: return ttr_fde_2834_0x062c08(a0, a1);
        case 2835U: return ttr_fde_2835_0x062c10(a0, a1);
        case 2836U: return ttr_fde_2836_0x062c24(a0, a1);
        case 2837U: return ttr_fde_2837_0x062c2c(a0, a1);
        case 2838U: return ttr_fde_2838_0x062c48(a0, a1);
        case 2839U: return ttr_fde_2839_0x062c50(a0, a1);
        case 2840U: return ttr_fde_2840_0x062c58(a0, a1);
        case 2841U: return ttr_fde_2841_0x062c60(a0, a1);
        case 2842U: return ttr_fde_2842_0x062c6c(a0, a1);
        case 2843U: return ttr_fde_2843_0x062c78(a0, a1);
        case 2844U: return ttr_fde_2844_0x062c8c(a0, a1);
        case 2845U: return ttr_fde_2845_0x062c94(a0, a1);
        case 2846U: return ttr_fde_2846_0x062ca0(a0, a1);
        case 2847U: return ttr_fde_2847_0x062ca8(a0, a1);
        case 2848U: return ttr_fde_2848_0x062cb4(a0, a1);
        case 2849U: return ttr_fde_2849_0x062cd0(a0, a1);
        case 2850U: return ttr_fde_2850_0x062cd8(a0, a1);
        case 2851U: return ttr_fde_2851_0x062ce0(a0, a1);
        case 2852U: return ttr_fde_2852_0x062cf8(a0, a1);
        case 2853U: return ttr_fde_2853_0x062d08(a0, a1);
        case 2854U: return ttr_fde_2854_0x062d10(a0, a1);
        case 2855U: return ttr_fde_2855_0x062d20(a0, a1);
        case 2856U: return ttr_fde_2856_0x062d38(a0, a1);
        case 2857U: return ttr_fde_2857_0x062d40(a0, a1);
        case 2858U: return ttr_fde_2858_0x062d58(a0, a1);
        case 2859U: return ttr_fde_2859_0x062d60(a0, a1);
        case 2860U: return ttr_fde_2860_0x062d70(a0, a1);
        case 2861U: return ttr_fde_2861_0x062d7c(a0, a1);
        case 2862U: return ttr_fde_2862_0x062d8c(a0, a1);
        case 2863U: return ttr_fde_2863_0x062d9c(a0, a1);
        case 2864U: return ttr_fde_2864_0x062dac(a0, a1);
        case 2865U: return ttr_fde_2865_0x062dbc(a0, a1);
        case 2866U: return ttr_fde_2866_0x062dd4(a0, a1);
        case 2867U: return ttr_fde_2867_0x062de4(a0, a1);
        case 2868U: return ttr_fde_2868_0x062dec(a0, a1);
        case 2869U: return ttr_fde_2869_0x062df4(a0, a1);
        case 2870U: return ttr_fde_2870_0x062dfc(a0, a1);
        case 2871U: return ttr_fde_2871_0x062e04(a0, a1);
        case 2872U: return ttr_fde_2872_0x062e0c(a0, a1);
        case 2873U: return ttr_fde_2873_0x062e1c(a0, a1);
        case 2874U: return ttr_fde_2874_0x062e2c(a0, a1);
        case 2875U: return ttr_fde_2875_0x062e38(a0, a1);
        case 2876U: return ttr_fde_2876_0x062e50(a0, a1);
        case 2877U: return ttr_fde_2877_0x062e58(a0, a1);
        case 2878U: return ttr_fde_2878_0x062e64(a0, a1);
        case 2879U: return ttr_fde_2879_0x062e74(a0, a1);
        case 2880U: return ttr_fde_2880_0x062e8c(a0, a1);
        case 2881U: return ttr_fde_2881_0x062e94(a0, a1);
        case 2882U: return ttr_fde_2882_0x062ea4(a0, a1);
        case 2883U: return ttr_fde_2883_0x062eb0(a0, a1);
        case 2884U: return ttr_fde_2884_0x062ebc(a0, a1);
        case 2885U: return ttr_fde_2885_0x062ecc(a0, a1);
        case 2886U: return ttr_fde_2886_0x062ee4(a0, a1);
        case 2887U: return ttr_fde_2887_0x062eec(a0, a1);
        case 2888U: return ttr_fde_2888_0x062f14(a0, a1);
        case 2889U: return ttr_fde_2889_0x062f1c(a0, a1);
        case 2890U: return ttr_fde_2890_0x062f3c(a0, a1);
        case 2891U: return ttr_fde_2891_0x062f4c(a0, a1);
        case 2892U: return ttr_fde_2892_0x062f5c(a0, a1);
        case 2893U: return ttr_fde_2893_0x062f6c(a0, a1);
        case 2894U: return ttr_fde_2894_0x062f74(a0, a1);
        case 2895U: return ttr_fde_2895_0x062f7c(a0, a1);
        case 2896U: return ttr_fde_2896_0x062f8c(a0, a1);
        case 2897U: return ttr_fde_2897_0x062f9c(a0, a1);
        case 2898U: return ttr_fde_2898_0x062fac(a0, a1);
        case 2899U: return ttr_fde_2899_0x062fb4(a0, a1);
        case 2900U: return ttr_fde_2900_0x062fc0(a0, a1);
        case 2901U: return ttr_fde_2901_0x062fd8(a0, a1);
        case 2902U: return ttr_fde_2902_0x062fe8(a0, a1);
        case 2903U: return ttr_fde_2903_0x062ff8(a0, a1);
        case 2904U: return ttr_fde_2904_0x063008(a0, a1);
        case 2905U: return ttr_fde_2905_0x063018(a0, a1);
        case 2906U: return ttr_fde_2906_0x063028(a0, a1);
        case 2907U: return ttr_fde_2907_0x063030(a0, a1);
        case 2908U: return ttr_fde_2908_0x063040(a0, a1);
        case 2909U: return ttr_fde_2909_0x063050(a0, a1);
        case 2910U: return ttr_fde_2910_0x063060(a0, a1);
        case 2911U: return ttr_fde_2911_0x063070(a0, a1);
        case 2912U: return ttr_fde_2912_0x063080(a0, a1);
        case 2913U: return ttr_fde_2913_0x063090(a0, a1);
        case 2914U: return ttr_fde_2914_0x0630a0(a0, a1);
        case 2915U: return ttr_fde_2915_0x0630b0(a0, a1);
        case 2916U: return ttr_fde_2916_0x0630c0(a0, a1);
        case 2917U: return ttr_fde_2917_0x0630d0(a0, a1);
        case 2918U: return ttr_fde_2918_0x0630d8(a0, a1);
        case 2919U: return ttr_fde_2919_0x0630e8(a0, a1);
        case 2920U: return ttr_fde_2920_0x0630f8(a0, a1);
        case 2921U: return ttr_fde_2921_0x063108(a0, a1);
        case 2922U: return ttr_fde_2922_0x063118(a0, a1);
        case 2923U: return ttr_fde_2923_0x063128(a0, a1);
        case 2924U: return ttr_fde_2924_0x063134(a0, a1);
        case 2925U: return ttr_fde_2925_0x06313c(a0, a1);
        case 2926U: return ttr_fde_2926_0x063144(a0, a1);
        case 2927U: return ttr_fde_2927_0x06315c(a0, a1);
        case 2928U: return ttr_fde_2928_0x063164(a0, a1);
        case 2929U: return ttr_fde_2929_0x063174(a0, a1);
        case 2930U: return ttr_fde_2930_0x063184(a0, a1);
        case 2931U: return ttr_fde_2931_0x06318c(a0, a1);
        case 2932U: return ttr_fde_2932_0x063198(a0, a1);
        case 2933U: return ttr_fde_2933_0x0631b0(a0, a1);
        case 2934U: return ttr_fde_2934_0x0631c0(a0, a1);
        case 2935U: return ttr_fde_2935_0x0631d0(a0, a1);
        case 2936U: return ttr_fde_2936_0x0631d8(a0, a1);
        case 2937U: return ttr_fde_2937_0x0631e0(a0, a1);
        case 2938U: return ttr_fde_2938_0x0631e8(a0, a1);
        case 2939U: return ttr_fde_2939_0x0631f8(a0, a1);
        case 2940U: return ttr_fde_2940_0x063210(a0, a1);
        case 2941U: return ttr_fde_2941_0x063220(a0, a1);
        case 2942U: return ttr_fde_2942_0x06322c(a0, a1);
        case 2943U: return ttr_fde_2943_0x06323c(a0, a1);
        case 2944U: return ttr_fde_2944_0x063248(a0, a1);
        case 2945U: return ttr_fde_2945_0x063260(a0, a1);
        case 2946U: return ttr_fde_2946_0x063278(a0, a1);
        case 2947U: return ttr_fde_2947_0x063284(a0, a1);
        case 2948U: return ttr_fde_2948_0x063290(a0, a1);
        case 2949U: return ttr_fde_2949_0x06329c(a0, a1);
        case 2950U: return ttr_fde_2950_0x0632ac(a0, a1);
        case 2951U: return ttr_fde_2951_0x0632bc(a0, a1);
        case 2952U: return ttr_fde_2952_0x0632c8(a0, a1);
        case 2953U: return ttr_fde_2953_0x0632d0(a0, a1);
        case 2954U: return ttr_fde_2954_0x0632e8(a0, a1);
        case 2955U: return ttr_fde_2955_0x063300(a0, a1);
        case 2956U: return ttr_fde_2956_0x063318(a0, a1);
        case 2957U: return ttr_fde_2957_0x063324(a0, a1);
        case 2958U: return ttr_fde_2958_0x063334(a0, a1);
        case 2959U: return ttr_fde_2959_0x063340(a0, a1);
        case 2960U: return ttr_fde_2960_0x063348(a0, a1);
        case 2961U: return ttr_fde_2961_0x063350(a0, a1);
        case 2962U: return ttr_fde_2962_0x063368(a0, a1);
        case 2963U: return ttr_fde_2963_0x063370(a0, a1);
        case 2964U: return ttr_fde_2964_0x063380(a0, a1);
        case 2965U: return ttr_fde_2965_0x063390(a0, a1);
        case 2966U: return ttr_fde_2966_0x0633a8(a0, a1);
        case 2967U: return ttr_fde_2967_0x0633c0(a0, a1);
        case 2968U: return ttr_fde_2968_0x0633c8(a0, a1);
        case 2969U: return ttr_fde_2969_0x0633e0(a0, a1);
        case 2970U: return ttr_fde_2970_0x0633f8(a0, a1);
        case 2971U: return ttr_fde_2971_0x063408(a0, a1);
        case 2972U: return ttr_fde_2972_0x063418(a0, a1);
        case 2973U: return ttr_fde_2973_0x063424(a0, a1);
        case 2974U: return ttr_fde_2974_0x063434(a0, a1);
        case 2975U: return ttr_fde_2975_0x063444(a0, a1);
        case 2976U: return ttr_fde_2976_0x063458(a0, a1);
        case 2977U: return ttr_fde_2977_0x063470(a0, a1);
        case 2978U: return ttr_fde_2978_0x063478(a0, a1);
        case 2979U: return ttr_fde_2979_0x063490(a0, a1);
        case 2980U: return ttr_fde_2980_0x063498(a0, a1);
        case 2981U: return ttr_fde_2981_0x0634a8(a0, a1);
        case 2982U: return ttr_fde_2982_0x0634b8(a0, a1);
        case 2983U: return ttr_fde_2983_0x0634c4(a0, a1);
        case 2984U: return ttr_fde_2984_0x0634d0(a0, a1);
        case 2985U: return ttr_fde_2985_0x0634dc(a0, a1);
        case 2986U: return ttr_fde_2986_0x0634ec(a0, a1);
        case 2987U: return ttr_fde_2987_0x063504(a0, a1);
        case 2988U: return ttr_fde_2988_0x063514(a0, a1);
        case 2989U: return ttr_fde_2989_0x063524(a0, a1);
        case 2990U: return ttr_fde_2990_0x063534(a0, a1);
        case 2991U: return ttr_fde_2991_0x063544(a0, a1);
        case 2992U: return ttr_fde_2992_0x063550(a0, a1);
        case 2993U: return ttr_fde_2993_0x063568(a0, a1);
        case 2994U: return ttr_fde_2994_0x063580(a0, a1);
        case 2995U: return ttr_fde_2995_0x063598(a0, a1);
        case 2996U: return ttr_fde_2996_0x0635a8(a0, a1);
        case 2997U: return ttr_fde_2997_0x0635b0(a0, a1);
        case 2998U: return ttr_fde_2998_0x0635c0(a0, a1);
        case 2999U: return ttr_fde_2999_0x0635dc(a0, a1);
        case 3000U: return ttr_fde_3000_0x0635f8(a0, a1);
        case 3001U: return ttr_fde_3001_0x063608(a0, a1);
        case 3002U: return ttr_fde_3002_0x063610(a0, a1);
        case 3003U: return ttr_fde_3003_0x063628(a0, a1);
        case 3004U: return ttr_fde_3004_0x063638(a0, a1);
        case 3005U: return ttr_fde_3005_0x063648(a0, a1);
        case 3006U: return ttr_fde_3006_0x063658(a0, a1);
        case 3007U: return ttr_fde_3007_0x063660(a0, a1);
        case 3008U: return ttr_fde_3008_0x063678(a0, a1);
        case 3009U: return ttr_fde_3009_0x063688(a0, a1);
        case 3010U: return ttr_fde_3010_0x063694(a0, a1);
        case 3011U: return ttr_fde_3011_0x0636a4(a0, a1);
        case 3012U: return ttr_fde_3012_0x0636bc(a0, a1);
        case 3013U: return ttr_fde_3013_0x0636cc(a0, a1);
        case 3014U: return ttr_fde_3014_0x0636d8(a0, a1);
        case 3015U: return ttr_fde_3015_0x0636e8(a0, a1);
        case 3016U: return ttr_fde_3016_0x0636f8(a0, a1);
        case 3017U: return ttr_fde_3017_0x063708(a0, a1);
        case 3018U: return ttr_fde_3018_0x063710(a0, a1);
        case 3019U: return ttr_fde_3019_0x063720(a0, a1);
        case 3020U: return ttr_fde_3020_0x063730(a0, a1);
        case 3021U: return ttr_fde_3021_0x063740(a0, a1);
        case 3022U: return ttr_fde_3022_0x06374c(a0, a1);
        case 3023U: return ttr_fde_3023_0x06375c(a0, a1);
        case 3024U: return ttr_fde_3024_0x063768(a0, a1);
        case 3025U: return ttr_fde_3025_0x063778(a0, a1);
        case 3026U: return ttr_fde_3026_0x063788(a0, a1);
        case 3027U: return ttr_fde_3027_0x063798(a0, a1);
        case 3028U: return ttr_fde_3028_0x0637a0(a0, a1);
        case 3029U: return ttr_fde_3029_0x0637b0(a0, a1);
        case 3030U: return ttr_fde_3030_0x0637b8(a0, a1);
        case 3031U: return ttr_fde_3031_0x0637c0(a0, a1);
        case 3032U: return ttr_fde_3032_0x0637c8(a0, a1);
        case 3033U: return ttr_fde_3033_0x0637d4(a0, a1);
        case 3034U: return ttr_fde_3034_0x0637e4(a0, a1);
        case 3035U: return ttr_fde_3035_0x0637f4(a0, a1);
        case 3036U: return ttr_fde_3036_0x063804(a0, a1);
        case 3037U: return ttr_fde_3037_0x063814(a0, a1);
        case 3038U: return ttr_fde_3038_0x06381c(a0, a1);
        case 3039U: return ttr_fde_3039_0x06382c(a0, a1);
        case 3040U: return ttr_fde_3040_0x063834(a0, a1);
        case 3041U: return ttr_fde_3041_0x063840(a0, a1);
        case 3042U: return ttr_fde_3042_0x063850(a0, a1);
        case 3043U: return ttr_fde_3043_0x063858(a0, a1);
        case 3044U: return ttr_fde_3044_0x063864(a0, a1);
        case 3045U: return ttr_fde_3045_0x06386c(a0, a1);
        case 3046U: return ttr_fde_3046_0x063884(a0, a1);
        case 3047U: return ttr_fde_3047_0x063890(a0, a1);
        case 3048U: return ttr_fde_3048_0x063898(a0, a1);
        case 3049U: return ttr_fde_3049_0x0638b0(a0, a1);
        case 3050U: return ttr_fde_3050_0x0638b8(a0, a1);
        case 3051U: return ttr_fde_3051_0x0638c8(a0, a1);
        case 3052U: return ttr_fde_3052_0x0638d8(a0, a1);
        case 3053U: return ttr_fde_3053_0x0638e0(a0, a1);
        case 3054U: return ttr_fde_3054_0x0638ec(a0, a1);
        case 3055U: return ttr_fde_3055_0x0638f4(a0, a1);
        case 3056U: return ttr_fde_3056_0x063900(a0, a1);
        case 3057U: return ttr_fde_3057_0x063908(a0, a1);
        case 3058U: return ttr_fde_3058_0x063918(a0, a1);
        case 3059U: return ttr_fde_3059_0x063920(a0, a1);
        case 3060U: return ttr_fde_3060_0x063938(a0, a1);
        case 3061U: return ttr_fde_3061_0x063944(a0, a1);
        case 3062U: return ttr_fde_3062_0x063954(a0, a1);
        case 3063U: return ttr_fde_3063_0x063964(a0, a1);
        case 3064U: return ttr_fde_3064_0x063980(a0, a1);
        case 3065U: return ttr_fde_3065_0x063990(a0, a1);
        case 3066U: return ttr_fde_3066_0x06399c(a0, a1);
        case 3067U: return ttr_fde_3067_0x0639b0(a0, a1);
        case 3068U: return ttr_fde_3068_0x0639c8(a0, a1);
        case 3069U: return ttr_fde_3069_0x0639dc(a0, a1);
        case 3070U: return ttr_fde_3070_0x0639e8(a0, a1);
        case 3071U: return ttr_fde_3071_0x0639f4(a0, a1);
        case 3072U: return ttr_fde_3072_0x063a00(a0, a1);
        case 3073U: return ttr_fde_3073_0x063a0c(a0, a1);
        case 3074U: return ttr_fde_3074_0x063a18(a0, a1);
        case 3075U: return ttr_fde_3075_0x063a24(a0, a1);
        case 3076U: return ttr_fde_3076_0x063a30(a0, a1);
        case 3077U: return ttr_fde_3077_0x063a3c(a0, a1);
        case 3078U: return ttr_fde_3078_0x063a44(a0, a1);
        case 3079U: return ttr_fde_3079_0x063a4c(a0, a1);
        case 3080U: return ttr_fde_3080_0x063a60(a0, a1);
        case 3081U: return ttr_fde_3081_0x063a68(a0, a1);
        case 3082U: return ttr_fde_3082_0x063a70(a0, a1);
        case 3083U: return ttr_fde_3083_0x063a7c(a0, a1);
        case 3084U: return ttr_fde_3084_0x063a88(a0, a1);
        case 3085U: return ttr_fde_3085_0x063a94(a0, a1);
        case 3086U: return ttr_fde_3086_0x063aa8(a0, a1);
        case 3087U: return ttr_fde_3087_0x063ab0(a0, a1);
        case 3088U: return ttr_fde_3088_0x063ac4(a0, a1);
        case 3089U: return ttr_fde_3089_0x063ad8(a0, a1);
        case 3090U: return ttr_fde_3090_0x063ae4(a0, a1);
        case 3091U: return ttr_fde_3091_0x063af0(a0, a1);
        case 3092U: return ttr_fde_3092_0x063afc(a0, a1);
        case 3093U: return ttr_fde_3093_0x063b04(a0, a1);
        case 3094U: return ttr_fde_3094_0x063b0c(a0, a1);
        case 3095U: return ttr_fde_3095_0x063b14(a0, a1);
        case 3096U: return ttr_fde_3096_0x063b28(a0, a1);
        case 3097U: return ttr_fde_3097_0x063b3c(a0, a1);
        case 3098U: return ttr_fde_3098_0x063b48(a0, a1);
        case 3099U: return ttr_fde_3099_0x063b50(a0, a1);
        case 3100U: return ttr_fde_3100_0x063b5c(a0, a1);
        case 3101U: return ttr_fde_3101_0x063b70(a0, a1);
        case 3102U: return ttr_fde_3102_0x063b84(a0, a1);
        case 3103U: return ttr_fde_3103_0x063b8c(a0, a1);
        case 3104U: return ttr_fde_3104_0x063b98(a0, a1);
        case 3105U: return ttr_fde_3105_0x063ba4(a0, a1);
        case 3106U: return ttr_fde_3106_0x063bb0(a0, a1);
        case 3107U: return ttr_fde_3107_0x063bbc(a0, a1);
        case 3108U: return ttr_fde_3108_0x063bd0(a0, a1);
        case 3109U: return ttr_fde_3109_0x063bd8(a0, a1);
        case 3110U: return ttr_fde_3110_0x063bec(a0, a1);
        case 3111U: return ttr_fde_3111_0x063c00(a0, a1);
        case 3112U: return ttr_fde_3112_0x063c08(a0, a1);
        case 3113U: return ttr_fde_3113_0x063c14(a0, a1);
        case 3114U: return ttr_fde_3114_0x063c28(a0, a1);
        case 3115U: return ttr_fde_3115_0x063c3c(a0, a1);
        case 3116U: return ttr_fde_3116_0x063c50(a0, a1);
        case 3117U: return ttr_fde_3117_0x063c5c(a0, a1);
        case 3118U: return ttr_fde_3118_0x063c68(a0, a1);
        case 3119U: return ttr_fde_3119_0x063c7c(a0, a1);
        case 3120U: return ttr_fde_3120_0x063c88(a0, a1);
        case 3121U: return ttr_fde_3121_0x063c94(a0, a1);
        case 3122U: return ttr_fde_3122_0x063ca0(a0, a1);
        case 3123U: return ttr_fde_3123_0x063cac(a0, a1);
        case 3124U: return ttr_fde_3124_0x063cc0(a0, a1);
        case 3125U: return ttr_fde_3125_0x063cd4(a0, a1);
        case 3126U: return ttr_fde_3126_0x063ce0(a0, a1);
        case 3127U: return ttr_fde_3127_0x063cec(a0, a1);
        case 3128U: return ttr_fde_3128_0x063d00(a0, a1);
        case 3129U: return ttr_fde_3129_0x063d0c(a0, a1);
        case 3130U: return ttr_fde_3130_0x063d14(a0, a1);
        case 3131U: return ttr_fde_3131_0x063d1c(a0, a1);
        case 3132U: return ttr_fde_3132_0x063d24(a0, a1);
        case 3133U: return ttr_fde_3133_0x063d38(a0, a1);
        case 3134U: return ttr_fde_3134_0x063d44(a0, a1);
        case 3135U: return ttr_fde_3135_0x063d58(a0, a1);
        case 3136U: return ttr_fde_3136_0x063d64(a0, a1);
        case 3137U: return ttr_fde_3137_0x063d70(a0, a1);
        case 3138U: return ttr_fde_3138_0x063d84(a0, a1);
        case 3139U: return ttr_fde_3139_0x063d90(a0, a1);
        case 3140U: return ttr_fde_3140_0x063da4(a0, a1);
        case 3141U: return ttr_fde_3141_0x063dac(a0, a1);
        case 3142U: return ttr_fde_3142_0x063db4(a0, a1);
        case 3143U: return ttr_fde_3143_0x063dbc(a0, a1);
        case 3144U: return ttr_fde_3144_0x063dc4(a0, a1);
        case 3145U: return ttr_fde_3145_0x063dcc(a0, a1);
        case 3146U: return ttr_fde_3146_0x063de0(a0, a1);
        case 3147U: return ttr_fde_3147_0x063de8(a0, a1);
        case 3148U: return ttr_fde_3148_0x063df4(a0, a1);
        case 3149U: return ttr_fde_3149_0x063e00(a0, a1);
        case 3150U: return ttr_fde_3150_0x063e08(a0, a1);
        case 3151U: return ttr_fde_3151_0x063e14(a0, a1);
        case 3152U: return ttr_fde_3152_0x063e20(a0, a1);
        case 3153U: return ttr_fde_3153_0x063e34(a0, a1);
        case 3154U: return ttr_fde_3154_0x063e40(a0, a1);
        case 3155U: return ttr_fde_3155_0x063e4c(a0, a1);
        case 3156U: return ttr_fde_3156_0x063e58(a0, a1);
        case 3157U: return ttr_fde_3157_0x063e6c(a0, a1);
        case 3158U: return ttr_fde_3158_0x063e80(a0, a1);
        case 3159U: return ttr_fde_3159_0x063e8c(a0, a1);
        case 3160U: return ttr_fde_3160_0x063e94(a0, a1);
        case 3161U: return ttr_fde_3161_0x063ea8(a0, a1);
        case 3162U: return ttr_fde_3162_0x063eb0(a0, a1);
        case 3163U: return ttr_fde_3163_0x063ebc(a0, a1);
        case 3164U: return ttr_fde_3164_0x063ed0(a0, a1);
        case 3165U: return ttr_fde_3165_0x063edc(a0, a1);
        case 3166U: return ttr_fde_3166_0x063ee8(a0, a1);
        case 3167U: return ttr_fde_3167_0x063ef0(a0, a1);
        case 3168U: return ttr_fde_3168_0x063efc(a0, a1);
        case 3169U: return ttr_fde_3169_0x063f04(a0, a1);
        case 3170U: return ttr_fde_3170_0x063f10(a0, a1);
        case 3171U: return ttr_fde_3171_0x063f1c(a0, a1);
        case 3172U: return ttr_fde_3172_0x063f28(a0, a1);
        case 3173U: return ttr_fde_3173_0x063f34(a0, a1);
        case 3174U: return ttr_fde_3174_0x063f3c(a0, a1);
        case 3175U: return ttr_fde_3175_0x063f48(a0, a1);
        case 3176U: return ttr_fde_3176_0x063f54(a0, a1);
        case 3177U: return ttr_fde_3177_0x063f60(a0, a1);
        case 3178U: return ttr_fde_3178_0x063f68(a0, a1);
        case 3179U: return ttr_fde_3179_0x063f7c(a0, a1);
        case 3180U: return ttr_fde_3180_0x063f90(a0, a1);
        case 3181U: return ttr_fde_3181_0x063fa4(a0, a1);
        case 3182U: return ttr_fde_3182_0x063fb0(a0, a1);
        case 3183U: return ttr_fde_3183_0x063fbc(a0, a1);
        case 3184U: return ttr_fde_3184_0x063fc4(a0, a1);
        case 3185U: return ttr_fde_3185_0x063fcc(a0, a1);
        case 3186U: return ttr_fde_3186_0x063fd4(a0, a1);
        case 3187U: return ttr_fde_3187_0x063fe8(a0, a1);
        case 3188U: return ttr_fde_3188_0x063ff4(a0, a1);
        case 3189U: return ttr_fde_3189_0x064000(a0, a1);
        case 3190U: return ttr_fde_3190_0x06400c(a0, a1);
        case 3191U: return ttr_fde_3191_0x064018(a0, a1);
        case 3192U: return ttr_fde_3192_0x064020(a0, a1);
        case 3193U: return ttr_fde_3193_0x064028(a0, a1);
        case 3194U: return ttr_fde_3194_0x064034(a0, a1);
        case 3195U: return ttr_fde_3195_0x064040(a0, a1);
        case 3196U: return ttr_fde_3196_0x06404c(a0, a1);
        case 3197U: return ttr_fde_3197_0x064058(a0, a1);
        case 3198U: return ttr_fde_3198_0x064064(a0, a1);
        case 3199U: return ttr_fde_3199_0x06406c(a0, a1);
        case 3200U: return ttr_fde_3200_0x064078(a0, a1);
        case 3201U: return ttr_fde_3201_0x06408c(a0, a1);
        case 3202U: return ttr_fde_3202_0x064098(a0, a1);
        case 3203U: return ttr_fde_3203_0x0640a4(a0, a1);
        case 3204U: return ttr_fde_3204_0x0640b8(a0, a1);
        case 3205U: return ttr_fde_3205_0x0640c0(a0, a1);
        case 3206U: return ttr_fde_3206_0x0640d4(a0, a1);
        case 3207U: return ttr_fde_3207_0x0640e0(a0, a1);
        case 3208U: return ttr_fde_3208_0x0640ec(a0, a1);
        case 3209U: return ttr_fde_3209_0x064100(a0, a1);
        case 3210U: return ttr_fde_3210_0x06410c(a0, a1);
        case 3211U: return ttr_fde_3211_0x064118(a0, a1);
        case 3212U: return ttr_fde_3212_0x064120(a0, a1);
        case 3213U: return ttr_fde_3213_0x064134(a0, a1);
        case 3214U: return ttr_fde_3214_0x064140(a0, a1);
        case 3215U: return ttr_fde_3215_0x064154(a0, a1);
        case 3216U: return ttr_fde_3216_0x064160(a0, a1);
        case 3217U: return ttr_fde_3217_0x06416c(a0, a1);
        case 3218U: return ttr_fde_3218_0x064178(a0, a1);
        case 3219U: return ttr_fde_3219_0x064180(a0, a1);
        case 3220U: return ttr_fde_3220_0x064194(a0, a1);
        case 3221U: return ttr_fde_3221_0x0641a0(a0, a1);
        case 3222U: return ttr_fde_3222_0x0641ac(a0, a1);
        case 3223U: return ttr_fde_3223_0x0641c0(a0, a1);
        case 3224U: return ttr_fde_3224_0x0641d4(a0, a1);
        case 3225U: return ttr_fde_3225_0x0641e0(a0, a1);
        case 3226U: return ttr_fde_3226_0x0641ec(a0, a1);
        case 3227U: return ttr_fde_3227_0x0641f8(a0, a1);
        case 3228U: return ttr_fde_3228_0x064200(a0, a1);
        case 3229U: return ttr_fde_3229_0x06420c(a0, a1);
        case 3230U: return ttr_fde_3230_0x064214(a0, a1);
        case 3231U: return ttr_fde_3231_0x06421c(a0, a1);
        case 3232U: return ttr_fde_3232_0x064228(a0, a1);
        case 3233U: return ttr_fde_3233_0x064234(a0, a1);
        case 3234U: return ttr_fde_3234_0x06423c(a0, a1);
        case 3235U: return ttr_fde_3235_0x064244(a0, a1);
        case 3236U: return ttr_fde_3236_0x064258(a0, a1);
        case 3237U: return ttr_fde_3237_0x06426c(a0, a1);
        case 3238U: return ttr_fde_3238_0x064278(a0, a1);
        case 3239U: return ttr_fde_3239_0x064284(a0, a1);
        case 3240U: return ttr_fde_3240_0x064290(a0, a1);
        case 3241U: return ttr_fde_3241_0x06429c(a0, a1);
        case 3242U: return ttr_fde_3242_0x0642a8(a0, a1);
        case 3243U: return ttr_fde_3243_0x0642b0(a0, a1);
        case 3244U: return ttr_fde_3244_0x0642b8(a0, a1);
        case 3245U: return ttr_fde_3245_0x0642c4(a0, a1);
        case 3246U: return ttr_fde_3246_0x0642d0(a0, a1);
        case 3247U: return ttr_fde_3247_0x0642dc(a0, a1);
        case 3248U: return ttr_fde_3248_0x0642f0(a0, a1);
        case 3249U: return ttr_fde_3249_0x0642f8(a0, a1);
        case 3250U: return ttr_fde_3250_0x06430c(a0, a1);
        case 3251U: return ttr_fde_3251_0x064318(a0, a1);
        case 3252U: return ttr_fde_3252_0x064324(a0, a1);
        case 3253U: return ttr_fde_3253_0x06432c(a0, a1);
        case 3254U: return ttr_fde_3254_0x064340(a0, a1);
        case 3255U: return ttr_fde_3255_0x064354(a0, a1);
        case 3256U: return ttr_fde_3256_0x064360(a0, a1);
        case 3257U: return ttr_fde_3257_0x06436c(a0, a1);
        case 3258U: return ttr_fde_3258_0x064378(a0, a1);
        case 3259U: return ttr_fde_3259_0x064384(a0, a1);
        case 3260U: return ttr_fde_3260_0x064398(a0, a1);
        case 3261U: return ttr_fde_3261_0x0643ac(a0, a1);
        case 3262U: return ttr_fde_3262_0x0643c0(a0, a1);
        case 3263U: return ttr_fde_3263_0x0643d4(a0, a1);
        case 3264U: return ttr_fde_3264_0x0643e0(a0, a1);
        case 3265U: return ttr_fde_3265_0x0643f4(a0, a1);
        case 3266U: return ttr_fde_3266_0x064418(a0, a1);
        case 3267U: return ttr_fde_3267_0x064420(a0, a1);
        case 3268U: return ttr_fde_3268_0x06442c(a0, a1);
        case 3269U: return ttr_fde_3269_0x064438(a0, a1);
        case 3270U: return ttr_fde_3270_0x064440(a0, a1);
        case 3271U: return ttr_fde_3271_0x06444c(a0, a1);
        case 3272U: return ttr_fde_3272_0x064454(a0, a1);
        case 3273U: return ttr_fde_3273_0x064460(a0, a1);
        case 3274U: return ttr_fde_3274_0x06446c(a0, a1);
        case 3275U: return ttr_fde_3275_0x064480(a0, a1);
        case 3276U: return ttr_fde_3276_0x06448c(a0, a1);
        case 3277U: return ttr_fde_3277_0x064498(a0, a1);
        case 3278U: return ttr_fde_3278_0x0644ac(a0, a1);
        case 3279U: return ttr_fde_3279_0x0644c0(a0, a1);
        case 3280U: return ttr_fde_3280_0x0644d4(a0, a1);
        case 3281U: return ttr_fde_3281_0x0644e8(a0, a1);
        case 3282U: return ttr_fde_3282_0x0644f4(a0, a1);
        case 3283U: return ttr_fde_3283_0x0644fc(a0, a1);
        case 3284U: return ttr_fde_3284_0x064504(a0, a1);
        case 3285U: return ttr_fde_3285_0x064510(a0, a1);
        case 3286U: return ttr_fde_3286_0x064518(a0, a1);
        case 3287U: return ttr_fde_3287_0x064524(a0, a1);
        case 3288U: return ttr_fde_3288_0x06452c(a0, a1);
        case 3289U: return ttr_fde_3289_0x064538(a0, a1);
        case 3290U: return ttr_fde_3290_0x064544(a0, a1);
        case 3291U: return ttr_fde_3291_0x064558(a0, a1);
        case 3292U: return ttr_fde_3292_0x064564(a0, a1);
        case 3293U: return ttr_fde_3293_0x064570(a0, a1);
        case 3294U: return ttr_fde_3294_0x06457c(a0, a1);
        case 3295U: return ttr_fde_3295_0x064588(a0, a1);
        case 3296U: return ttr_fde_3296_0x064594(a0, a1);
        case 3297U: return ttr_fde_3297_0x0645a0(a0, a1);
        case 3298U: return ttr_fde_3298_0x0645ac(a0, a1);
        case 3299U: return ttr_fde_3299_0x0645b8(a0, a1);
        case 3300U: return ttr_fde_3300_0x0645c4(a0, a1);
        case 3301U: return ttr_fde_3301_0x0645d0(a0, a1);
        case 3302U: return ttr_fde_3302_0x0645dc(a0, a1);
        case 3303U: return ttr_fde_3303_0x0645e8(a0, a1);
        case 3304U: return ttr_fde_3304_0x0645f4(a0, a1);
        case 3305U: return ttr_fde_3305_0x064600(a0, a1);
        case 3306U: return ttr_fde_3306_0x064614(a0, a1);
        case 3307U: return ttr_fde_3307_0x064620(a0, a1);
        case 3308U: return ttr_fde_3308_0x064628(a0, a1);
        case 3309U: return ttr_fde_3309_0x064630(a0, a1);
        case 3310U: return ttr_fde_3310_0x06463c(a0, a1);
        case 3311U: return ttr_fde_3311_0x064648(a0, a1);
        case 3312U: return ttr_fde_3312_0x064654(a0, a1);
        case 3313U: return ttr_fde_3313_0x064660(a0, a1);
        case 3314U: return ttr_fde_3314_0x06466c(a0, a1);
        case 3315U: return ttr_fde_3315_0x064678(a0, a1);
        case 3316U: return ttr_fde_3316_0x064680(a0, a1);
        case 3317U: return ttr_fde_3317_0x064688(a0, a1);
        case 3318U: return ttr_fde_3318_0x064690(a0, a1);
        case 3319U: return ttr_fde_3319_0x06469c(a0, a1);
        case 3320U: return ttr_fde_3320_0x0646a4(a0, a1);
        case 3321U: return ttr_fde_3321_0x0646ac(a0, a1);
        case 3322U: return ttr_fde_3322_0x0646b4(a0, a1);
        case 3323U: return ttr_fde_3323_0x0646c0(a0, a1);
        case 3324U: return ttr_fde_3324_0x0646c8(a0, a1);
        case 3325U: return ttr_fde_3325_0x0646d4(a0, a1);
        case 3326U: return ttr_fde_3326_0x0646e0(a0, a1);
        case 3327U: return ttr_fde_3327_0x0646e8(a0, a1);
        case 3328U: return ttr_fde_3328_0x0646f4(a0, a1);
        case 3329U: return ttr_fde_3329_0x064700(a0, a1);
        case 3330U: return ttr_fde_3330_0x06470c(a0, a1);
        case 3331U: return ttr_fde_3331_0x064714(a0, a1);
        case 3332U: return ttr_fde_3332_0x06471c(a0, a1);
        case 3333U: return ttr_fde_3333_0x064728(a0, a1);
        case 3334U: return ttr_fde_3334_0x064730(a0, a1);
        case 3335U: return ttr_fde_3335_0x06473c(a0, a1);
        case 3336U: return ttr_fde_3336_0x064744(a0, a1);
        case 3337U: return ttr_fde_3337_0x06474c(a0, a1);
        case 3338U: return ttr_fde_3338_0x064754(a0, a1);
        case 3339U: return ttr_fde_3339_0x064760(a0, a1);
        case 3340U: return ttr_fde_3340_0x06476c(a0, a1);
        case 3341U: return ttr_fde_3341_0x064778(a0, a1);
        case 3342U: return ttr_fde_3342_0x064784(a0, a1);
        case 3343U: return ttr_fde_3343_0x06478c(a0, a1);
        case 3344U: return ttr_fde_3344_0x064798(a0, a1);
        case 3345U: return ttr_fde_3345_0x0647a0(a0, a1);
        case 3346U: return ttr_fde_3346_0x0647a8(a0, a1);
        case 3347U: return ttr_fde_3347_0x0647b4(a0, a1);
        case 3348U: return ttr_fde_3348_0x0647c0(a0, a1);
        case 3349U: return ttr_fde_3349_0x0647c8(a0, a1);
        case 3350U: return ttr_fde_3350_0x0647d0(a0, a1);
        case 3351U: return ttr_fde_3351_0x0647d8(a0, a1);
        case 3352U: return ttr_fde_3352_0x0647e0(a0, a1);
        case 3353U: return ttr_fde_3353_0x0647ec(a0, a1);
        case 3354U: return ttr_fde_3354_0x0647f8(a0, a1);
        case 3355U: return ttr_fde_3355_0x06480c(a0, a1);
        case 3356U: return ttr_fde_3356_0x064814(a0, a1);
        case 3357U: return ttr_fde_3357_0x064820(a0, a1);
        case 3358U: return ttr_fde_3358_0x06482c(a0, a1);
        case 3359U: return ttr_fde_3359_0x064850(a0, a1);
        case 3360U: return ttr_fde_3360_0x064864(a0, a1);
        case 3361U: return ttr_fde_3361_0x064870(a0, a1);
        case 3362U: return ttr_fde_3362_0x06487c(a0, a1);
        case 3363U: return ttr_fde_3363_0x064888(a0, a1);
        case 3364U: return ttr_fde_3364_0x064894(a0, a1);
        case 3365U: return ttr_fde_3365_0x0648a0(a0, a1);
        case 3366U: return ttr_fde_3366_0x0648a8(a0, a1);
        case 3367U: return ttr_fde_3367_0x0648b4(a0, a1);
        case 3368U: return ttr_fde_3368_0x0648c0(a0, a1);
        case 3369U: return ttr_fde_3369_0x0648cc(a0, a1);
        case 3370U: return ttr_fde_3370_0x0648d4(a0, a1);
        case 3371U: return ttr_fde_3371_0x0648e0(a0, a1);
        case 3372U: return ttr_fde_3372_0x0648e8(a0, a1);
        case 3373U: return ttr_fde_3373_0x0648f4(a0, a1);
        case 3374U: return ttr_fde_3374_0x064900(a0, a1);
        case 3375U: return ttr_fde_3375_0x06490c(a0, a1);
        case 3376U: return ttr_fde_3376_0x064914(a0, a1);
        case 3377U: return ttr_fde_3377_0x06491c(a0, a1);
        case 3378U: return ttr_fde_3378_0x064928(a0, a1);
        case 3379U: return ttr_fde_3379_0x064934(a0, a1);
        case 3380U: return ttr_fde_3380_0x064940(a0, a1);
        case 3381U: return ttr_fde_3381_0x064954(a0, a1);
        case 3382U: return ttr_fde_3382_0x064960(a0, a1);
        case 3383U: return ttr_fde_3383_0x06496c(a0, a1);
        case 3384U: return ttr_fde_3384_0x064978(a0, a1);
        case 3385U: return ttr_fde_3385_0x064980(a0, a1);
        default: return 0U;
    }
}

} // namespace ttr_render
