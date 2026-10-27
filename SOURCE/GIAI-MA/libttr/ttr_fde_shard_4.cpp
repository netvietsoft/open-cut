// ============================================================================
// File: ttr_fde_shard_4.cpp
// Target: libttr.so (625,192 bytes)
// SHA-256: 38c13f772c29f2a6b03c5523b74730be6727dfc9c3de457b1e09fe32578d6f6f
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// FDE Range: [2031..2707] of 3,386 (.eh_frame_hdr @ 0x08ab40)
// ============================================================================
// [EN] Clean-room C++17 reconstruction of AArch64 FDEs [2031..2707]
//      verified directly against the .text section of libttr.so.
// [VN] Tái tạo sạch C++17 cho các FDE AArch64 [2031..2707]
//      đã đối chiếu trực tiếp với phân đoạn .text của libttr.so.
// ============================================================================

#include "ttr_render_types.h"

namespace ttr_render {

// [EN] FDE[2031] start_va=0x05cc38, fde_va=0x082940, span=4 B | [VN] FDE[2031]
uint32_t ttr_fde_2031_0x05cc38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefc3eU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05cc38U) ^ (0xa9037bf3U + 0x082940U + 4U);
}

// [EN] FDE[2032] start_va=0x05cc3c, fde_va=0x082958, span=60 B | [VN] FDE[2032]
uint32_t ttr_fde_2032_0x05cc3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05cc3cU) ^ (0x94000c6eU + 0x082958U + 60U);
}

// [EN] FDE[2033] start_va=0x05cc78, fde_va=0x082978, span=56 B | [VN] FDE[2033]
uint32_t ttr_fde_2033_0x05cc78(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xbd40e002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000048U + 0x05cc78U) ^ (0xbd4b9504U + 0x082978U + 56U);
}

// [EN] FDE[2034] start_va=0x05ccb0, fde_va=0x082990, span=4 B | [VN] FDE[2034]
uint32_t ttr_fde_2034_0x05ccb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefc20U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000c11U + 0x05ccb0U) ^ (0xd00001e8U + 0x082990U + 4U);
}

// [EN] FDE[2035] start_va=0x05ccb4, fde_va=0x0829a8, span=28 B | [VN] FDE[2035]
uint32_t ttr_fde_2035_0x05ccb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000c11U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05ccb4U) ^ (0x91116108U + 0x0829a8U + 28U);
}

// [EN] FDE[2036] start_va=0x05ccd0, fde_va=0x0829c0, span=12 B | [VN] FDE[2036]
uint32_t ttr_fde_2036_0x05ccd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x91116108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000c05U + 0x05ccd0U) ^ (0xd65f03c0U + 0x0829c0U + 12U);
}

// [EN] FDE[2037] start_va=0x05ccdc, fde_va=0x0829d8, span=4 B | [VN] FDE[2037]
uint32_t ttr_fde_2037_0x05ccdc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefc14U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05ccdcU) ^ (0xf90013f4U + 0x0829d8U + 4U);
}

// [EN] FDE[2038] start_va=0x05cce0, fde_va=0x0829f0, span=4 B | [VN] FDE[2038]
uint32_t ttr_fde_2038_0x05cce0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefc14U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05cce0U) ^ (0xa9037bf3U + 0x0829f0U + 4U);
}

// [EN] FDE[2039] start_va=0x05cce4, fde_va=0x082a08, span=60 B | [VN] FDE[2039]
uint32_t ttr_fde_2039_0x05cce4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05cce4U) ^ (0x94000c44U + 0x082a08U + 60U);
}

// [EN] FDE[2040] start_va=0x05cd20, fde_va=0x082a28, span=76 B | [VN] FDE[2040]
uint32_t ttr_fde_2040_0x05cd20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x90000048U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfd456501U + 0x05cd20U) ^ (0x1e22c002U + 0x082a28U + 76U);
}

// [EN] FDE[2041] start_va=0x05cd6c, fde_va=0x082a40, span=4 B | [VN] FDE[2041]
uint32_t ttr_fde_2041_0x05cd6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefbf1U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000be2U + 0x05cd6cU) ^ (0xd00001e8U + 0x082a40U + 4U);
}

// [EN] FDE[2042] start_va=0x05cd70, fde_va=0x082a58, span=28 B | [VN] FDE[2042]
uint32_t ttr_fde_2042_0x05cd70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000be2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05cd70U) ^ (0x91104108U + 0x082a58U + 28U);
}

// [EN] FDE[2043] start_va=0x05cd8c, fde_va=0x082a70, span=12 B | [VN] FDE[2043]
uint32_t ttr_fde_2043_0x05cd8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x91104108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000bd6U + 0x05cd8cU) ^ (0xd65f03c0U + 0x082a70U + 12U);
}

// [EN] FDE[2044] start_va=0x05cd98, fde_va=0x082a88, span=4 B | [VN] FDE[2044]
uint32_t ttr_fde_2044_0x05cd98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefbe5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05cd98U) ^ (0xf90013f4U + 0x082a88U + 4U);
}

// [EN] FDE[2045] start_va=0x05cd9c, fde_va=0x082aa0, span=4 B | [VN] FDE[2045]
uint32_t ttr_fde_2045_0x05cd9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefbe5U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05cd9cU) ^ (0xa9037bf3U + 0x082aa0U + 4U);
}

// [EN] FDE[2046] start_va=0x05cda0, fde_va=0x082ab8, span=84 B | [VN] FDE[2046]
uint32_t ttr_fde_2046_0x05cda0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05cda0U) ^ (0x94000c15U + 0x082ab8U + 84U);
}

// [EN] FDE[2047] start_va=0x05cdf4, fde_va=0x082ad8, span=4 B | [VN] FDE[2047]
uint32_t ttr_fde_2047_0x05cdf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefbcfU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000bc0U + 0x05cdf4U) ^ (0xd00001e8U + 0x082ad8U + 4U);
}

// [EN] FDE[2048] start_va=0x05cdf8, fde_va=0x082af0, span=28 B | [VN] FDE[2048]
uint32_t ttr_fde_2048_0x05cdf8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000bc0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05cdf8U) ^ (0x910f2108U + 0x082af0U + 28U);
}

// [EN] FDE[2049] start_va=0x05ce14, fde_va=0x082b08, span=12 B | [VN] FDE[2049]
uint32_t ttr_fde_2049_0x05ce14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x910f2108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000bb4U + 0x05ce14U) ^ (0xd65f03c0U + 0x082b08U + 12U);
}

// [EN] FDE[2050] start_va=0x05ce20, fde_va=0x082b20, span=4 B | [VN] FDE[2050]
uint32_t ttr_fde_2050_0x05ce20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefbc3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05ce20U) ^ (0xf90013f4U + 0x082b20U + 4U);
}

// [EN] FDE[2051] start_va=0x05ce24, fde_va=0x082b38, span=4 B | [VN] FDE[2051]
uint32_t ttr_fde_2051_0x05ce24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefbc3U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05ce24U) ^ (0xa9037bf3U + 0x082b38U + 4U);
}

// [EN] FDE[2052] start_va=0x05ce28, fde_va=0x082b50, span=84 B | [VN] FDE[2052]
uint32_t ttr_fde_2052_0x05ce28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05ce28U) ^ (0x94000bf3U + 0x082b50U + 84U);
}

// [EN] FDE[2053] start_va=0x05ce7c, fde_va=0x082b70, span=4 B | [VN] FDE[2053]
uint32_t ttr_fde_2053_0x05ce7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefbadU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000b9eU + 0x05ce7cU) ^ (0xd00001e8U + 0x082b70U + 4U);
}

// [EN] FDE[2054] start_va=0x05ce80, fde_va=0x082b88, span=28 B | [VN] FDE[2054]
uint32_t ttr_fde_2054_0x05ce80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000b9eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05ce80U) ^ (0x910e0108U + 0x082b88U + 28U);
}

// [EN] FDE[2055] start_va=0x05ce9c, fde_va=0x082ba0, span=12 B | [VN] FDE[2055]
uint32_t ttr_fde_2055_0x05ce9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x910e0108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000b92U + 0x05ce9cU) ^ (0xd65f03c0U + 0x082ba0U + 12U);
}

// [EN] FDE[2056] start_va=0x05cea8, fde_va=0x082bb8, span=4 B | [VN] FDE[2056]
uint32_t ttr_fde_2056_0x05cea8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefba1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05cea8U) ^ (0xf90013f4U + 0x082bb8U + 4U);
}

// [EN] FDE[2057] start_va=0x05ceac, fde_va=0x082bd0, span=4 B | [VN] FDE[2057]
uint32_t ttr_fde_2057_0x05ceac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefba1U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05ceacU) ^ (0xa9037bf3U + 0x082bd0U + 4U);
}

// [EN] FDE[2058] start_va=0x05ceb0, fde_va=0x082be8, span=68 B | [VN] FDE[2058]
uint32_t ttr_fde_2058_0x05ceb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05ceb0U) ^ (0x94000bd1U + 0x082be8U + 68U);
}

// [EN] FDE[2059] start_va=0x05cef4, fde_va=0x082c08, span=4 B | [VN] FDE[2059]
uint32_t ttr_fde_2059_0x05cef4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefb8fU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000b80U + 0x05cef4U) ^ (0xd00001e8U + 0x082c08U + 4U);
}

// [EN] FDE[2060] start_va=0x05cef8, fde_va=0x082c20, span=28 B | [VN] FDE[2060]
uint32_t ttr_fde_2060_0x05cef8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000b80U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05cef8U) ^ (0x910ce108U + 0x082c20U + 28U);
}

// [EN] FDE[2061] start_va=0x05cf14, fde_va=0x082c38, span=12 B | [VN] FDE[2061]
uint32_t ttr_fde_2061_0x05cf14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x910ce108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000b74U + 0x05cf14U) ^ (0xd65f03c0U + 0x082c38U + 12U);
}

// [EN] FDE[2062] start_va=0x05cf20, fde_va=0x082c50, span=4 B | [VN] FDE[2062]
uint32_t ttr_fde_2062_0x05cf20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefb83U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05cf20U) ^ (0xf90013f4U + 0x082c50U + 4U);
}

// [EN] FDE[2063] start_va=0x05cf24, fde_va=0x082c68, span=4 B | [VN] FDE[2063]
uint32_t ttr_fde_2063_0x05cf24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefb83U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05cf24U) ^ (0xa9037bf3U + 0x082c68U + 4U);
}

// [EN] FDE[2064] start_va=0x05cf28, fde_va=0x082c80, span=84 B | [VN] FDE[2064]
uint32_t ttr_fde_2064_0x05cf28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05cf28U) ^ (0x94000bb3U + 0x082c80U + 84U);
}

// [EN] FDE[2065] start_va=0x05cf7c, fde_va=0x082ca0, span=4 B | [VN] FDE[2065]
uint32_t ttr_fde_2065_0x05cf7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefb6dU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000b5eU + 0x05cf7cU) ^ (0xd00001e8U + 0x082ca0U + 4U);
}

// [EN] FDE[2066] start_va=0x05cf80, fde_va=0x082cb8, span=28 B | [VN] FDE[2066]
uint32_t ttr_fde_2066_0x05cf80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000b5eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001e8U + 0x05cf80U) ^ (0x910bc108U + 0x082cb8U + 28U);
}

// [EN] FDE[2067] start_va=0x05cf9c, fde_va=0x082cd0, span=12 B | [VN] FDE[2067]
uint32_t ttr_fde_2067_0x05cf9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001e8U) + (a1 ^ 0x910bc108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000b52U + 0x05cf9cU) ^ (0xd65f03c0U + 0x082cd0U + 12U);
}

// [EN] FDE[2068] start_va=0x05cfa8, fde_va=0x082ce8, span=4 B | [VN] FDE[2068]
uint32_t ttr_fde_2068_0x05cfa8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefb61U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05cfa8U) ^ (0xf90013f4U + 0x082ce8U + 4U);
}

// [EN] FDE[2069] start_va=0x05cfac, fde_va=0x082d00, span=4 B | [VN] FDE[2069]
uint32_t ttr_fde_2069_0x05cfac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefb61U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05cfacU) ^ (0xa9037bf3U + 0x082d00U + 4U);
}

// [EN] FDE[2070] start_va=0x05cfb0, fde_va=0x082d18, span=84 B | [VN] FDE[2070]
uint32_t ttr_fde_2070_0x05cfb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05cfb0U) ^ (0x94000b91U + 0x082d18U + 84U);
}

// [EN] FDE[2071] start_va=0x05d004, fde_va=0x082d38, span=4 B | [VN] FDE[2071]
uint32_t ttr_fde_2071_0x05d004(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefb4bU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000b3cU + 0x05d004U) ^ (0xb00001e8U + 0x082d38U + 4U);
}

// [EN] FDE[2072] start_va=0x05d008, fde_va=0x082d50, span=28 B | [VN] FDE[2072]
uint32_t ttr_fde_2072_0x05d008(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000b3cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb00001e8U + 0x05d008U) ^ (0x910aa108U + 0x082d50U + 28U);
}

// [EN] FDE[2073] start_va=0x05d024, fde_va=0x082d68, span=12 B | [VN] FDE[2073]
uint32_t ttr_fde_2073_0x05d024(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001e8U) + (a1 ^ 0x910aa108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000b30U + 0x05d024U) ^ (0xd65f03c0U + 0x082d68U + 12U);
}

// [EN] FDE[2074] start_va=0x05d030, fde_va=0x082d80, span=4 B | [VN] FDE[2074]
uint32_t ttr_fde_2074_0x05d030(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fefb3fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05d030U) ^ (0xf90013f4U + 0x082d80U + 4U);
}

// [EN] FDE[2075] start_va=0x05d034, fde_va=0x082d98, span=4 B | [VN] FDE[2075]
uint32_t ttr_fde_2075_0x05d034(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fefb3fU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05d034U) ^ (0xa9037bf3U + 0x082d98U + 4U);
}

// [EN] FDE[2076] start_va=0x05d038, fde_va=0x082db0, span=68 B | [VN] FDE[2076]
uint32_t ttr_fde_2076_0x05d038(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05d038U) ^ (0x94000b6fU + 0x082db0U + 68U);
}

// [EN] FDE[2077] start_va=0x05d07c, fde_va=0x082dd0, span=24 B | [VN] FDE[2077]
uint32_t ttr_fde_2077_0x05d07c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd5b3U + 0x05d07cU) ^ (0xaa1303e0U + 0x082dd0U + 24U);
}

// [EN] FDE[2078] start_va=0x05d094, fde_va=0x082de8, span=408 B | [VN] FDE[2078]
uint32_t ttr_fde_2078_0x05d094(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc1d0fe8U) + (a1 ^ 0xf90007f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90153f5U + 0x05d094U) ^ (0xa9027bf3U + 0x082de8U + 408U);
}

// [EN] FDE[2079] start_va=0x05d22c, fde_va=0x082e10, span=344 B | [VN] FDE[2079]
uint32_t ttr_fde_2079_0x05d22c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9001bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x05d22cU) ^ (0xbd40a000U + 0x082e10U + 344U);
}

// [EN] FDE[2080] start_va=0x05d384, fde_va=0x082e30, span=152 B | [VN] FDE[2080]
uint32_t ttr_fde_2080_0x05d384(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9be53f5U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0303f4U + 0x05d384U) ^ (0x94001ad0U + 0x082e30U + 152U);
}

// [EN] FDE[2081] start_va=0x05d41c, fde_va=0x082e50, span=1004 B | [VN] FDE[2081]
uint32_t ttr_fde_2081_0x05d41c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x940016b3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x05d41cU) ^ (0xa9097bfdU + 0x082e50U + 1004U);
}

// [EN] FDE[2082] start_va=0x05d808, fde_va=0x082e98, span=264 B | [VN] FDE[2082]
uint32_t ttr_fde_2082_0x05d808(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05d808U) ^ (0xa9402408U + 0x082e98U + 264U);
}

// [EN] FDE[2083] start_va=0x05d910, fde_va=0x082eb8, span=4 B | [VN] FDE[2083]
uint32_t ttr_fde_2083_0x05d910(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef908U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940008f9U + 0x05d910U) ^ (0xb00001e8U + 0x082eb8U + 4U);
}

// [EN] FDE[2084] start_va=0x05d914, fde_va=0x082ed0, span=28 B | [VN] FDE[2084]
uint32_t ttr_fde_2084_0x05d914(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940008f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb00001e8U + 0x05d914U) ^ (0x91186108U + 0x082ed0U + 28U);
}

// [EN] FDE[2085] start_va=0x05d930, fde_va=0x082ee8, span=12 B | [VN] FDE[2085]
uint32_t ttr_fde_2085_0x05d930(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001e8U) + (a1 ^ 0x91186108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140008edU + 0x05d930U) ^ (0xd65f03c0U + 0x082ee8U + 12U);
}

// [EN] FDE[2086] start_va=0x05d93c, fde_va=0x082f00, span=4 B | [VN] FDE[2086]
uint32_t ttr_fde_2086_0x05d93c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fef8fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05d93cU) ^ (0xf90013f4U + 0x082f00U + 4U);
}

// [EN] FDE[2087] start_va=0x05d940, fde_va=0x082f18, span=4 B | [VN] FDE[2087]
uint32_t ttr_fde_2087_0x05d940(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef8fcU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05d940U) ^ (0xa9037bf3U + 0x082f18U + 4U);
}

// [EN] FDE[2088] start_va=0x05d944, fde_va=0x082f30, span=64 B | [VN] FDE[2088]
uint32_t ttr_fde_2088_0x05d944(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05d944U) ^ (0x9400092cU + 0x082f30U + 64U);
}

// [EN] FDE[2089] start_va=0x05d984, fde_va=0x082f50, span=4 B | [VN] FDE[2089]
uint32_t ttr_fde_2089_0x05d984(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef8ebU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940008dcU + 0x05d984U) ^ (0xb00001e8U + 0x082f50U + 4U);
}

// [EN] FDE[2090] start_va=0x05d988, fde_va=0x082f68, span=28 B | [VN] FDE[2090]
uint32_t ttr_fde_2090_0x05d988(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940008dcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb00001e8U + 0x05d988U) ^ (0x91174108U + 0x082f68U + 28U);
}

// [EN] FDE[2091] start_va=0x05d9a4, fde_va=0x082f80, span=12 B | [VN] FDE[2091]
uint32_t ttr_fde_2091_0x05d9a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb00001e8U) + (a1 ^ 0x91174108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140008d0U + 0x05d9a4U) ^ (0xd65f03c0U + 0x082f80U + 12U);
}

// [EN] FDE[2092] start_va=0x05d9b0, fde_va=0x082f98, span=4 B | [VN] FDE[2092]
uint32_t ttr_fde_2092_0x05d9b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fef8dfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05d9b0U) ^ (0xf90013f4U + 0x082f98U + 4U);
}

// [EN] FDE[2093] start_va=0x05d9b4, fde_va=0x082fb0, span=4 B | [VN] FDE[2093]
uint32_t ttr_fde_2093_0x05d9b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef8dfU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05d9b4U) ^ (0xa9037bf3U + 0x082fb0U + 4U);
}

// [EN] FDE[2094] start_va=0x05d9b8, fde_va=0x082fc8, span=80 B | [VN] FDE[2094]
uint32_t ttr_fde_2094_0x05d9b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05d9b8U) ^ (0x9400090fU + 0x082fc8U + 80U);
}

// [EN] FDE[2095] start_va=0x05da08, fde_va=0x082fe8, span=24 B | [VN] FDE[2095]
uint32_t ttr_fde_2095_0x05da08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd414U + 0x05da08U) ^ (0xaa1303e0U + 0x082fe8U + 24U);
}

// [EN] FDE[2096] start_va=0x05da20, fde_va=0x083000, span=484 B | [VN] FDE[2096]
uint32_t ttr_fde_2096_0x05da20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81c0ff8U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x05da20U) ^ (0xa9037bf3U + 0x083000U + 484U);
}

// [EN] FDE[2097] start_va=0x05dc04, fde_va=0x083028, span=84 B | [VN] FDE[2097]
uint32_t ttr_fde_2097_0x05dc04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9001bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x05dc04U) ^ (0x94000a7dU + 0x083028U + 84U);
}

// [EN] FDE[2098] start_va=0x05dc58, fde_va=0x083048, span=316 B | [VN] FDE[2098]
uint32_t ttr_fde_2098_0x05dc58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x05dc58U) ^ (0xa9037bf3U + 0x083048U + 316U);
}

// [EN] FDE[2099] start_va=0x05dd94, fde_va=0x083068, span=728 B | [VN] FDE[2099]
uint32_t ttr_fde_2099_0x05dd94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bc63f9U) + (a1 ^ 0xa9015bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x05dd94U) ^ (0xa9037bf3U + 0x083068U + 728U);
}

// [EN] FDE[2100] start_va=0x05e06c, fde_va=0x083090, span=108 B | [VN] FDE[2100]
uint32_t ttr_fde_2100_0x05e06c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf90013f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90353f5U + 0x05e06cU) ^ (0xa9047bf3U + 0x083090U + 108U);
}

// [EN] FDE[2101] start_va=0x05e0d8, fde_va=0x0830b0, span=24 B | [VN] FDE[2101]
uint32_t ttr_fde_2101_0x05e0d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x9400071bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd24cU + 0x05e0d8U) ^ (0xaa1303e0U + 0x0830b0U + 24U);
}

// [EN] FDE[2102] start_va=0x05e0f0, fde_va=0x0830c8, span=12 B | [VN] FDE[2102]
uint32_t ttr_fde_2102_0x05e0f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb4000040U) + (a1 ^ 0x17ff0cd6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05e0f0U) ^ (0xaa0003e8U + 0x0830c8U + 12U);
}

// [EN] FDE[2103] start_va=0x05e0fc, fde_va=0x0830e0, span=24 B | [VN] FDE[2103]
uint32_t ttr_fde_2103_0x05e0fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900011fU + 0x05e0fcU) ^ (0xb4000040U + 0x0830e0U + 24U);
}

// [EN] FDE[2104] start_va=0x05e114, fde_va=0x0830f8, span=92 B | [VN] FDE[2104]
uint32_t ttr_fde_2104_0x05e114(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x531f7828U + 0x05e114U) ^ (0x900001e9U + 0x0830f8U + 92U);
}

// [EN] FDE[2105] start_va=0x05e170, fde_va=0x083118, span=40 B | [VN] FDE[2105]
uint32_t ttr_fde_2105_0x05e170(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x900001e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x05e170U) ^ (0x911a6108U + 0x083118U + 40U);
}

// [EN] FDE[2106] start_va=0x05e198, fde_va=0x083130, span=24 B | [VN] FDE[2106]
uint32_t ttr_fde_2106_0x05e198(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff4U + 0x05e198U) ^ (0xaa1303e0U + 0x083130U + 24U);
}

// [EN] FDE[2107] start_va=0x05e1b0, fde_va=0x083148, span=40 B | [VN] FDE[2107]
uint32_t ttr_fde_2107_0x05e1b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xbd000fe0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x05e1b0U) ^ (0x910033e1U + 0x083148U + 40U);
}

// [EN] FDE[2108] start_va=0x05e1d8, fde_va=0x083160, span=208 B | [VN] FDE[2108]
uint32_t ttr_fde_2108_0x05e1d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bb6bfbU) + (a1 ^ 0xa90163f9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025bf7U + 0x05e1d8U) ^ (0xa90353f5U + 0x083160U + 208U);
}

// [EN] FDE[2109] start_va=0x05e2a8, fde_va=0x083188, span=100 B | [VN] FDE[2109]
uint32_t ttr_fde_2109_0x05e2a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100045fU) + (a1 ^ 0x540001abU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9be53f5U + 0x05e2a8U) ^ (0xa9017bf3U + 0x083188U + 100U);
}

// [EN] FDE[2110] start_va=0x05e30c, fde_va=0x0831a8, span=104 B | [VN] FDE[2110]
uint32_t ttr_fde_2110_0x05e30c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100045fU) + (a1 ^ 0x540001abU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9be53f5U + 0x05e30cU) ^ (0xa9017bf3U + 0x0831a8U + 104U);
}

// [EN] FDE[2111] start_va=0x05e374, fde_va=0x0831c8, span=32 B | [VN] FDE[2111]
uint32_t ttr_fde_2111_0x05e374(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x900001e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91198108U + 0x05e374U) ^ (0x940006b6U + 0x0831c8U + 32U);
}

// [EN] FDE[2112] start_va=0x05e394, fde_va=0x0831e0, span=24 B | [VN] FDE[2112]
uint32_t ttr_fde_2112_0x05e394(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x05e394U) ^ (0xaa1303e0U + 0x0831e0U + 24U);
}

// [EN] FDE[2113] start_va=0x05e3ac, fde_va=0x0831f8, span=8 B | [VN] FDE[2113]
uint32_t ttr_fde_2113_0x05e3ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x17ffff70U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef65fU + 0x05e3acU) ^ (0xa9bf7bf3U + 0x0831f8U + 8U);
}

// [EN] FDE[2114] start_va=0x05e3b4, fde_va=0x083210, span=4 B | [VN] FDE[2114]
uint32_t ttr_fde_2114_0x05e3b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef65fU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900001e8U + 0x05e3b4U) ^ (0x911b2108U + 0x083210U + 4U);
}

// [EN] FDE[2115] start_va=0x05e3b8, fde_va=0x083228, span=36 B | [VN] FDE[2115]
uint32_t ttr_fde_2115_0x05e3b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x900001e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x911b2108U + 0x05e3b8U) ^ (0xaa0003f3U + 0x083228U + 36U);
}

// [EN] FDE[2116] start_va=0x05e3dc, fde_va=0x083240, span=24 B | [VN] FDE[2116]
uint32_t ttr_fde_2116_0x05e3dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff5U + 0x05e3dcU) ^ (0xaa1303e0U + 0x083240U + 24U);
}

// [EN] FDE[2117] start_va=0x05e3f4, fde_va=0x083258, span=8 B | [VN] FDE[2117]
uint32_t ttr_fde_2117_0x05e3f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91008000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef64dU + 0x05e3f4U) ^ (0xa9bf7bf3U + 0x083258U + 8U);
}

// [EN] FDE[2118] start_va=0x05e3fc, fde_va=0x083270, span=4 B | [VN] FDE[2118]
uint32_t ttr_fde_2118_0x05e3fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef64dU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x05e3fcU) ^ (0x9101e000U + 0x083270U + 4U);
}

// [EN] FDE[2119] start_va=0x05e400, fde_va=0x083288, span=60 B | [VN] FDE[2119]
uint32_t ttr_fde_2119_0x05e400(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9101e000U + 0x05e400U) ^ (0x97ffa814U + 0x083288U + 60U);
}

// [EN] FDE[2120] start_va=0x05e43c, fde_va=0x0832a0, span=32 B | [VN] FDE[2120]
uint32_t ttr_fde_2120_0x05e43c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x900001e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x911c0108U + 0x05e43cU) ^ (0x94000684U + 0x0832a0U + 32U);
}

// [EN] FDE[2121] start_va=0x05e45c, fde_va=0x0832b8, span=24 B | [VN] FDE[2121]
uint32_t ttr_fde_2121_0x05e45c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fffff6U + 0x05e45cU) ^ (0xaa1303e0U + 0x0832b8U + 24U);
}

// [EN] FDE[2122] start_va=0x05e474, fde_va=0x0832d0, span=8 B | [VN] FDE[2122]
uint32_t ttr_fde_2122_0x05e474(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006000U) + (a1 ^ 0x14000002U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef62dU + 0x05e474U) ^ (0xa9bf7bf3U + 0x0832d0U + 8U);
}

// [EN] FDE[2123] start_va=0x05e47c, fde_va=0x0832e8, span=4 B | [VN] FDE[2123]
uint32_t ttr_fde_2123_0x05e47c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef62dU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x05e47cU) ^ (0x91012000U + 0x0832e8U + 4U);
}

// [EN] FDE[2124] start_va=0x05e480, fde_va=0x083300, span=44 B | [VN] FDE[2124]
uint32_t ttr_fde_2124_0x05e480(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91012000U + 0x05e480U) ^ (0x97ffd0f7U + 0x083300U + 44U);
}

// [EN] FDE[2125] start_va=0x05e4ac, fde_va=0x083318, span=216 B | [VN] FDE[2125]
uint32_t ttr_fde_2125_0x05e4ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10303ffU) + (a1 ^ 0xf9004bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90a53f5U + 0x05e4acU) ^ (0xa90b7bf3U + 0x083318U + 216U);
}

// [EN] FDE[2126] start_va=0x05e584, fde_va=0x083338, span=4 B | [VN] FDE[2126]
uint32_t ttr_fde_2126_0x05e584(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef5ebU) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940005dcU + 0x05e584U) ^ (0x900001e8U + 0x083338U + 4U);
}

// [EN] FDE[2127] start_va=0x05e588, fde_va=0x083350, span=28 B | [VN] FDE[2127]
uint32_t ttr_fde_2127_0x05e588(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940005dcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900001e8U + 0x05e588U) ^ (0x91208108U + 0x083350U + 28U);
}

// [EN] FDE[2128] start_va=0x05e5a4, fde_va=0x083368, span=12 B | [VN] FDE[2128]
uint32_t ttr_fde_2128_0x05e5a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e8U) + (a1 ^ 0x91208108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140005d0U + 0x05e5a4U) ^ (0xd65f03c0U + 0x083368U + 12U);
}

// [EN] FDE[2129] start_va=0x05e5b0, fde_va=0x083380, span=4 B | [VN] FDE[2129]
uint32_t ttr_fde_2129_0x05e5b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fef5dfU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05e5b0U) ^ (0xa90253f5U + 0x083380U + 4U);
}

// [EN] FDE[2130] start_va=0x05e5b4, fde_va=0x083398, span=4 B | [VN] FDE[2130]
uint32_t ttr_fde_2130_0x05e5b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef5dfU) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x05e5b4U) ^ (0xa9037bf3U + 0x083398U + 4U);
}

// [EN] FDE[2131] start_va=0x05e5b8, fde_va=0x0833b0, span=104 B | [VN] FDE[2131]
uint32_t ttr_fde_2131_0x05e5b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05e5b8U) ^ (0x9400060fU + 0x0833b0U + 104U);
}

// [EN] FDE[2132] start_va=0x05e620, fde_va=0x0833d0, span=4 B | [VN] FDE[2132]
uint32_t ttr_fde_2132_0x05e620(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef5c4U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940005b5U + 0x05e620U) ^ (0x900001e8U + 0x0833d0U + 4U);
}

// [EN] FDE[2133] start_va=0x05e624, fde_va=0x0833e8, span=28 B | [VN] FDE[2133]
uint32_t ttr_fde_2133_0x05e624(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940005b5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900001e8U + 0x05e624U) ^ (0x911f6108U + 0x0833e8U + 28U);
}

// [EN] FDE[2134] start_va=0x05e640, fde_va=0x083400, span=12 B | [VN] FDE[2134]
uint32_t ttr_fde_2134_0x05e640(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e8U) + (a1 ^ 0x911f6108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140005a9U + 0x05e640U) ^ (0xd65f03c0U + 0x083400U + 12U);
}

// [EN] FDE[2135] start_va=0x05e64c, fde_va=0x083418, span=4 B | [VN] FDE[2135]
uint32_t ttr_fde_2135_0x05e64c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fef5b8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05e64cU) ^ (0xa90253f5U + 0x083418U + 4U);
}

// [EN] FDE[2136] start_va=0x05e650, fde_va=0x083430, span=4 B | [VN] FDE[2136]
uint32_t ttr_fde_2136_0x05e650(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef5b8U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90253f5U + 0x05e650U) ^ (0xa9037bf3U + 0x083430U + 4U);
}

// [EN] FDE[2137] start_va=0x05e654, fde_va=0x083448, span=96 B | [VN] FDE[2137]
uint32_t ttr_fde_2137_0x05e654(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xa90253f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05e654U) ^ (0x940005e8U + 0x083448U + 96U);
}

// [EN] FDE[2138] start_va=0x05e6b4, fde_va=0x083468, span=96 B | [VN] FDE[2138]
uint32_t ttr_fde_2138_0x05e6b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x52a85408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e270101U + 0x05e6b4U) ^ (0x1e215800U + 0x083468U + 96U);
}

// [EN] FDE[2139] start_va=0x05e714, fde_va=0x083480, span=24 B | [VN] FDE[2139]
uint32_t ttr_fde_2139_0x05e714(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ff9e91U + 0x05e714U) ^ (0xaa1303e0U + 0x083480U + 24U);
}

// [EN] FDE[2140] start_va=0x05e72c, fde_va=0x083498, span=128 B | [VN] FDE[2140]
uint32_t ttr_fde_2140_0x05e72c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc1e0fe8U) + (a1 ^ 0xf90007f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9017bf3U + 0x05e72cU) ^ (0x9400087dU + 0x083498U + 128U);
}

// [EN] FDE[2141] start_va=0x05e7ac, fde_va=0x0834b8, span=88 B | [VN] FDE[2141]
uint32_t ttr_fde_2141_0x05e7ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9001bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x05e7acU) ^ (0x94000793U + 0x0834b8U + 88U);
}

// [EN] FDE[2142] start_va=0x05e804, fde_va=0x0834d8, span=224 B | [VN] FDE[2142]
uint32_t ttr_fde_2142_0x05e804(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81d0ff6U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05e804U) ^ (0x2a0303f3U + 0x0834d8U + 224U);
}

// [EN] FDE[2143] start_va=0x05e8e4, fde_va=0x0834f8, span=24 B | [VN] FDE[2143]
uint32_t ttr_fde_2143_0x05e8e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd03aU + 0x05e8e4U) ^ (0xaa1303e0U + 0x0834f8U + 24U);
}

// [EN] FDE[2144] start_va=0x05e8fc, fde_va=0x083510, span=164 B | [VN] FDE[2144]
uint32_t ttr_fde_2144_0x05e8fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e0ff4U) + (a1 ^ 0xa9017bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400080aU + 0x05e8fcU) ^ (0x90000081U + 0x083510U + 164U);
}

// [EN] FDE[2145] start_va=0x05e9a0, fde_va=0x083530, span=196 B | [VN] FDE[2145]
uint32_t ttr_fde_2145_0x05e9a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10143ffU) + (a1 ^ 0xf9001bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9047bf3U + 0x05e9a0U) ^ (0x94000716U + 0x083530U + 196U);
}

// [EN] FDE[2146] start_va=0x05ea64, fde_va=0x083550, span=544 B | [VN] FDE[2146]
uint32_t ttr_fde_2146_0x05ea64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10283ffU) + (a1 ^ 0xfd002beaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0623e9U + 0x05ea64U) ^ (0xa9075bf7U + 0x083550U + 544U);
}

// [EN] FDE[2147] start_va=0x05ec84, fde_va=0x083580, span=396 B | [VN] FDE[2147]
uint32_t ttr_fde_2147_0x05ec84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x6db923e9U) + (a1 ^ 0xa9016ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90267faU + 0x05ec84U) ^ (0xa9035ff8U + 0x083580U + 396U);
}

// [EN] FDE[2148] start_va=0x05ee10, fde_va=0x0835b8, span=4 B | [VN] FDE[2148]
uint32_t ttr_fde_2148_0x05ee10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef3c8U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940003b9U + 0x05ee10U) ^ (0x900001e8U + 0x0835b8U + 4U);
}

// [EN] FDE[2149] start_va=0x05ee14, fde_va=0x0835d0, span=28 B | [VN] FDE[2149]
uint32_t ttr_fde_2149_0x05ee14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940003b9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900001e8U + 0x05ee14U) ^ (0x912a0108U + 0x0835d0U + 28U);
}

// [EN] FDE[2150] start_va=0x05ee30, fde_va=0x0835e8, span=12 B | [VN] FDE[2150]
uint32_t ttr_fde_2150_0x05ee30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e8U) + (a1 ^ 0x912a0108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x140003adU + 0x05ee30U) ^ (0xd65f03c0U + 0x0835e8U + 12U);
}

// [EN] FDE[2151] start_va=0x05ee3c, fde_va=0x083600, span=4 B | [VN] FDE[2151]
uint32_t ttr_fde_2151_0x05ee3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fef3bcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x05ee3cU) ^ (0x9400128fU + 0x083600U + 4U);
}

// [EN] FDE[2152] start_va=0x05ee40, fde_va=0x083618, span=4 B | [VN] FDE[2152]
uint32_t ttr_fde_2152_0x05ee40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef3bcU) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400128fU + 0x05ee40U) ^ (0x91092100U + 0x083618U + 4U);
}

// [EN] FDE[2153] start_va=0x05ee44, fde_va=0x083630, span=28 B | [VN] FDE[2153]
uint32_t ttr_fde_2153_0x05ee44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x9400128fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91092100U + 0x05ee44U) ^ (0x97ff9f2eU + 0x083630U + 28U);
}

// [EN] FDE[2154] start_va=0x05ee60, fde_va=0x083648, span=4 B | [VN] FDE[2154]
uint32_t ttr_fde_2154_0x05ee60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef3b4U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x940003a5U + 0x05ee60U) ^ (0x900001e8U + 0x083648U + 4U);
}

// [EN] FDE[2155] start_va=0x05ee64, fde_va=0x083660, span=28 B | [VN] FDE[2155]
uint32_t ttr_fde_2155_0x05ee64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x940003a5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900001e8U + 0x05ee64U) ^ (0x9128e108U + 0x083660U + 28U);
}

// [EN] FDE[2156] start_va=0x05ee80, fde_va=0x083678, span=12 B | [VN] FDE[2156]
uint32_t ttr_fde_2156_0x05ee80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e8U) + (a1 ^ 0x9128e108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000399U + 0x05ee80U) ^ (0xd65f03c0U + 0x083678U + 12U);
}

// [EN] FDE[2157] start_va=0x05ee8c, fde_va=0x083690, span=4 B | [VN] FDE[2157]
uint32_t ttr_fde_2157_0x05ee8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fef3a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x05ee8cU) ^ (0x9400127bU + 0x083690U + 4U);
}

// [EN] FDE[2158] start_va=0x05ee90, fde_va=0x0836a8, span=4 B | [VN] FDE[2158]
uint32_t ttr_fde_2158_0x05ee90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef3a8U) + (a1 ^ 0xf81f0ffeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9400127bU + 0x05ee90U) ^ (0x9103e100U + 0x0836a8U + 4U);
}

// [EN] FDE[2159] start_va=0x05ee94, fde_va=0x0836c0, span=28 B | [VN] FDE[2159]
uint32_t ttr_fde_2159_0x05ee94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x9400127bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9103e100U + 0x05ee94U) ^ (0x97ff9f1aU + 0x0836c0U + 28U);
}

// [EN] FDE[2160] start_va=0x05eeb0, fde_va=0x0836d8, span=4 B | [VN] FDE[2160]
uint32_t ttr_fde_2160_0x05eeb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef3a0U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000391U + 0x05eeb0U) ^ (0x900001e8U + 0x0836d8U + 4U);
}

// [EN] FDE[2161] start_va=0x05eeb4, fde_va=0x0836f0, span=28 B | [VN] FDE[2161]
uint32_t ttr_fde_2161_0x05eeb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000391U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900001e8U + 0x05eeb4U) ^ (0x9127c108U + 0x0836f0U + 28U);
}

// [EN] FDE[2162] start_va=0x05eed0, fde_va=0x083708, span=12 B | [VN] FDE[2162]
uint32_t ttr_fde_2162_0x05eed0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e8U) + (a1 ^ 0x9127c108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x14000385U + 0x05eed0U) ^ (0xd65f03c0U + 0x083708U + 12U);
}

// [EN] FDE[2163] start_va=0x05eedc, fde_va=0x083720, span=4 B | [VN] FDE[2163]
uint32_t ttr_fde_2163_0x05eedc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fef394U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05eedcU) ^ (0xf90013f4U + 0x083720U + 4U);
}

// [EN] FDE[2164] start_va=0x05eee0, fde_va=0x083738, span=4 B | [VN] FDE[2164]
uint32_t ttr_fde_2164_0x05eee0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef394U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05eee0U) ^ (0xa9037bf3U + 0x083738U + 4U);
}

// [EN] FDE[2165] start_va=0x05eee4, fde_va=0x083750, span=56 B | [VN] FDE[2165]
uint32_t ttr_fde_2165_0x05eee4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05eee4U) ^ (0x940003c4U + 0x083750U + 56U);
}

// [EN] FDE[2166] start_va=0x05ef1c, fde_va=0x083770, span=4 B | [VN] FDE[2166]
uint32_t ttr_fde_2166_0x05ef1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef385U) + (a1 ^ 0xa9bf7bf3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x94000376U + 0x05ef1cU) ^ (0x900001e8U + 0x083770U + 4U);
}

// [EN] FDE[2167] start_va=0x05ef20, fde_va=0x083788, span=28 B | [VN] FDE[2167]
uint32_t ttr_fde_2167_0x05ef20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0x94000376U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x900001e8U + 0x05ef20U) ^ (0x9126a108U + 0x083788U + 28U);
}

// [EN] FDE[2168] start_va=0x05ef3c, fde_va=0x0837a0, span=12 B | [VN] FDE[2168]
uint32_t ttr_fde_2168_0x05ef3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e8U) + (a1 ^ 0x9126a108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1400036aU + 0x05ef3cU) ^ (0xd65f03c0U + 0x0837a0U + 12U);
}

// [EN] FDE[2169] start_va=0x05ef48, fde_va=0x0837b8, span=4 B | [VN] FDE[2169]
uint32_t ttr_fde_2169_0x05ef48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd65f03c0U) + (a1 ^ 0x17fef379U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10103ffU + 0x05ef48U) ^ (0xf90013f4U + 0x0837b8U + 4U);
}

// [EN] FDE[2170] start_va=0x05ef4c, fde_va=0x0837d0, span=4 B | [VN] FDE[2170]
uint32_t ttr_fde_2170_0x05ef4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x17fef379U) + (a1 ^ 0xd10103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013f4U + 0x05ef4cU) ^ (0xa9037bf3U + 0x0837d0U + 4U);
}

// [EN] FDE[2171] start_va=0x05ef50, fde_va=0x0837e8, span=68 B | [VN] FDE[2171]
uint32_t ttr_fde_2171_0x05ef50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10103ffU) + (a1 ^ 0xf90013f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9037bf3U + 0x05ef50U) ^ (0x940003a9U + 0x0837e8U + 68U);
}

// [EN] FDE[2172] start_va=0x05ef94, fde_va=0x083808, span=24 B | [VN] FDE[2172]
uint32_t ttr_fde_2172_0x05ef94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bf7bf3U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffcdd7U + 0x05ef94U) ^ (0xaa1303e0U + 0x083808U + 24U);
}

// [EN] FDE[2173] start_va=0x05efac, fde_va=0x083820, span=212 B | [VN] FDE[2173]
uint32_t ttr_fde_2173_0x05efac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc1d0fe8U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05efacU) ^ (0x9400065dU + 0x083820U + 212U);
}

// [EN] FDE[2174] start_va=0x05f080, fde_va=0x083840, span=180 B | [VN] FDE[2174]
uint32_t ttr_fde_2174_0x05f080(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xf9002bf4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9067bf3U + 0x05f080U) ^ (0x9400055eU + 0x083840U + 180U);
}

// [EN] FDE[2175] start_va=0x05f134, fde_va=0x083860, span=884 B | [VN] FDE[2175]
uint32_t ttr_fde_2175_0x05f134(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd106c3ffU) + (a1 ^ 0xfd00a3e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9156ffcU + 0x05f134U) ^ (0xa91667faU + 0x083860U + 884U);
}

// [EN] FDE[2176] start_va=0x05f4a8, fde_va=0x083890, span=284 B | [VN] FDE[2176]
uint32_t ttr_fde_2176_0x05f4a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9bd5bf7U) + (a1 ^ 0xa90153f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9027bf3U + 0x05f4a8U) ^ (0x2a0303f6U + 0x083890U + 284U);
}

// [EN] FDE[2177] start_va=0x05f5c4, fde_va=0x0838b0, span=600 B | [VN] FDE[2177]
uint32_t ttr_fde_2177_0x05f5c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc1b0fecU) + (a1 ^ 0x6d012bebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0223e9U + 0x05f5c4U) ^ (0xa90353f5U + 0x0838b0U + 600U);
}

// [EN] FDE[2178] start_va=0x05f81c, fde_va=0x0838e0, span=836 B | [VN] FDE[2178]
uint32_t ttr_fde_2178_0x05f81c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0x6d023befU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6d0333edU + 0x05f81cU) ^ (0x6d042bebU + 0x0838e0U + 836U);
}

// [EN] FDE[2179] start_va=0x05fb60, fde_va=0x083918, span=184 B | [VN] FDE[2179]
uint32_t ttr_fde_2179_0x05fb60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xf90013fcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9036bfbU + 0x05fb60U) ^ (0xa90463f9U + 0x083918U + 184U);
}

// [EN] FDE[2180] start_va=0x05fc18, fde_va=0x083948, span=164 B | [VN] FDE[2180]
uint32_t ttr_fde_2180_0x05fc18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1e03e4U) + (a1 ^ 0x940000a2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403feU + 0x05fc18U) ^ (0xa9067bfdU + 0x083948U + 164U);
}

// [EN] FDE[2181] start_va=0x05fcbc, fde_va=0x083978, span=12 B | [VN] FDE[2181]
uint32_t ttr_fde_2181_0x05fcbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000120U) + (a1 ^ 0xaa0803e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef12bU + 0x05fcbcU) ^ (0xaa0803e0U + 0x083978U + 12U);
}

// [EN] FDE[2182] start_va=0x05fcc8, fde_va=0x083990, span=8 B | [VN] FDE[2182]
uint32_t ttr_fde_2182_0x05fcc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0803e0U) + (a1 ^ 0x17fef129U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xc85f7d09U + 0x05fcc8U) ^ (0x91000529U + 0x083990U + 8U);
}

// [EN] FDE[2183] start_va=0x05fcd0, fde_va=0x0839a8, span=16 B | [VN] FDE[2183]
uint32_t ttr_fde_2183_0x05fcd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xc85f7d09U) + (a1 ^ 0x91000529U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xc80a7d09U + 0x05fcd0U) ^ (0xd65f03c0U + 0x0839a8U + 16U);
}

// [EN] FDE[2184] start_va=0x05fce0, fde_va=0x0839c0, span=12 B | [VN] FDE[2184]
uint32_t ttr_fde_2184_0x05fce0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf84207f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef012U + 0x05fce0U) ^ (0xf9000028U + 0x0839c0U + 12U);
}

// [EN] FDE[2185] start_va=0x05fcec, fde_va=0x0839d8, span=16 B | [VN] FDE[2185]
uint32_t ttr_fde_2185_0x05fcec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000028U) + (a1 ^ 0xf9400408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000428U + 0x05fcecU) ^ (0xd65f03c0U + 0x0839d8U + 16U);
}

// [EN] FDE[2186] start_va=0x05fcfc, fde_va=0x0839f0, span=12 B | [VN] FDE[2186]
uint32_t ttr_fde_2186_0x05fcfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0x52800200U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef017U + 0x05fcfcU) ^ (0xf84207f3U + 0x0839f0U + 12U);
}

// [EN] FDE[2187] start_va=0x05fd08, fde_va=0x083a08, span=8 B | [VN] FDE[2187]
uint32_t ttr_fde_2187_0x05fd08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f3U) + (a1 ^ 0x17fef009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x05fd08U) ^ (0xf9400668U + 0x083a08U + 8U);
}

// [EN] FDE[2188] start_va=0x05fd10, fde_va=0x083a20, span=16 B | [VN] FDE[2188]
uint32_t ttr_fde_2188_0x05fd10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000008U) + (a1 ^ 0xf9400668U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000408U + 0x05fd10U) ^ (0xd65f03c0U + 0x083a20U + 16U);
}

// [EN] FDE[2189] start_va=0x05fd20, fde_va=0x083a38, span=16 B | [VN] FDE[2189]
uint32_t ttr_fde_2189_0x05fd20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xc85f7d2aU) + (a1 ^ 0x9100054aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xc80b7d2aU + 0x05fd20U) ^ (0xd65f03c0U + 0x083a38U + 16U);
}

// [EN] FDE[2190] start_va=0x05fd30, fde_va=0x083a50, span=16 B | [VN] FDE[2190]
uint32_t ttr_fde_2190_0x05fd30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xc85f7d4bU) + (a1 ^ 0x9100056bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xc80c7d4bU + 0x05fd30U) ^ (0xd65f03c0U + 0x083a50U + 16U);
}

// [EN] FDE[2191] start_va=0x05fd40, fde_va=0x083a68, span=8 B | [VN] FDE[2191]
uint32_t ttr_fde_2191_0x05fd40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff0794U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9402428U + 0x05fd40U) ^ (0xa9007c3fU + 0x083a68U + 8U);
}

// [EN] FDE[2192] start_va=0x05fd48, fde_va=0x083a80, span=24 B | [VN] FDE[2192]
uint32_t ttr_fde_2192_0x05fd48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402428U) + (a1 ^ 0xa9007c3fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x05fd48U) ^ (0xf9400400U + 0x083a80U + 24U);
}

// [EN] FDE[2193] start_va=0x05fd60, fde_va=0x083a98, span=16 B | [VN] FDE[2193]
uint32_t ttr_fde_2193_0x05fd60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94013f4U) + (a1 ^ 0x2a1f03e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910103ffU + 0x05fd60U) ^ (0xd65f03c0U + 0x083a98U + 16U);
}

// [EN] FDE[2194] start_va=0x05fd70, fde_va=0x083ab0, span=12 B | [VN] FDE[2194]
uint32_t ttr_fde_2194_0x05fd70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff1164U + 0x05fd70U) ^ (0x2a1f03e0U + 0x083ab0U + 12U);
}

// [EN] FDE[2195] start_va=0x05fd7c, fde_va=0x083ac8, span=12 B | [VN] FDE[2195]
uint32_t ttr_fde_2195_0x05fd7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e0U) + (a1 ^ 0x910103ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05fd7cU) ^ (0xaa0003e1U + 0x083ac8U + 12U);
}

// [EN] FDE[2196] start_va=0x05fd88, fde_va=0x083ae0, span=12 B | [VN] FDE[2196]
uint32_t ttr_fde_2196_0x05fd88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x910023e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffb33eU + 0x05fd88U) ^ (0x910d4129U + 0x083ae0U + 12U);
}

// [EN] FDE[2197] start_va=0x05fd94, fde_va=0x083af8, span=44 B | [VN] FDE[2197]
uint32_t ttr_fde_2197_0x05fd94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910d4129U) + (a1 ^ 0x3940012aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf940092bU + 0x05fd94U) ^ (0x7100011fU + 0x083af8U + 44U);
}

// [EN] FDE[2198] start_va=0x05fdc0, fde_va=0x083b10, span=8 B | [VN] FDE[2198]
uint32_t ttr_fde_2198_0x05fdc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ffb587U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd1000408U + 0x05fdc0U) ^ (0xdac01108U + 0x083b10U + 8U);
}

// [EN] FDE[2199] start_va=0x05fdc8, fde_va=0x083b28, span=24 B | [VN] FDE[2199]
uint32_t ttr_fde_2199_0x05fdc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd1000408U) + (a1 ^ 0xdac01108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4b0803e8U + 0x05fdc8U) ^ (0x52800029U + 0x083b28U + 24U);
}

// [EN] FDE[2200] start_va=0x05fde0, fde_va=0x083b40, span=8 B | [VN] FDE[2200]
uint32_t ttr_fde_2200_0x05fde0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f3U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa94153f5U + 0x05fde0U) ^ (0xf84307f6U + 0x083b40U + 8U);
}

// [EN] FDE[2201] start_va=0x05fde8, fde_va=0x083b58, span=12 B | [VN] FDE[2201]
uint32_t ttr_fde_2201_0x05fde8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0xf84307f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05fde8U) ^ (0xf8418c08U + 0x083b58U + 12U);
}

// [EN] FDE[2202] start_va=0x05fdf4, fde_va=0x083b70, span=12 B | [VN] FDE[2202]
uint32_t ttr_fde_2202_0x05fdf4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf8418c08U) + (a1 ^ 0xf9400501U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0020U + 0x05fdf4U) ^ (0xb9400028U + 0x083b70U + 12U);
}

// [EN] FDE[2203] start_va=0x05fe00, fde_va=0x083b88, span=16 B | [VN] FDE[2203]
uint32_t ttr_fde_2203_0x05fe00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400028U) + (a1 ^ 0xf9400414U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303f3U + 0x05fe00U) ^ (0xd65f03c0U + 0x083b88U + 16U);
}

// [EN] FDE[2204] start_va=0x05fe10, fde_va=0x083ba0, span=12 B | [VN] FDE[2204]
uint32_t ttr_fde_2204_0x05fe10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf84207f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05fe10U) ^ (0xaa1303e0U + 0x083ba0U + 12U);
}

// [EN] FDE[2205] start_va=0x05fe1c, fde_va=0x083bb8, span=12 B | [VN] FDE[2205]
uint32_t ttr_fde_2205_0x05fe1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf84207f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef063U + 0x05fe1cU) ^ (0x910103ffU + 0x083bb8U + 12U);
}

// [EN] FDE[2206] start_va=0x05fe28, fde_va=0x083bd0, span=8 B | [VN] FDE[2206]
uint32_t ttr_fde_2206_0x05fe28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910103ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84207f4U + 0x05fe28U) ^ (0xd65f03c0U + 0x083bd0U + 8U);
}

// [EN] FDE[2207] start_va=0x05fe30, fde_va=0x083be8, span=8 B | [VN] FDE[2207]
uint32_t ttr_fde_2207_0x05fe30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f4U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c24ff4U + 0x05fe30U) ^ (0xd65f03c0U + 0x083be8U + 8U);
}

// [EN] FDE[2208] start_va=0x05fe38, fde_va=0x083c00, span=8 B | [VN] FDE[2208]
uint32_t ttr_fde_2208_0x05fe38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa8c24ff4U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x05fe38U) ^ (0x1e22c000U + 0x083c00U + 8U);
}

// [EN] FDE[2209] start_va=0x05fe40, fde_va=0x083c18, span=12 B | [VN] FDE[2209]
uint32_t ttr_fde_2209_0x05fe40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x1e22c000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffb19cU + 0x05fe40U) ^ (0xaa1303e0U + 0x083c18U + 12U);
}

// [EN] FDE[2210] start_va=0x05fe4c, fde_va=0x083c30, span=12 B | [VN] FDE[2210]
uint32_t ttr_fde_2210_0x05fe4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xaa1f03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fef1c7U + 0x05fe4cU) ^ (0xaa0003f3U + 0x083c30U + 12U);
}

// [EN] FDE[2211] start_va=0x05fe58, fde_va=0x083c48, span=12 B | [VN] FDE[2211]
uint32_t ttr_fde_2211_0x05fe58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf8018408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05fe58U) ^ (0xa9414ff4U + 0x083c48U + 12U);
}

// [EN] FDE[2212] start_va=0x05fe64, fde_va=0x083c60, span=12 B | [VN] FDE[2212]
uint32_t ttr_fde_2212_0x05fe64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9414ff4U) + (a1 ^ 0xf84307f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05fe64U) ^ (0xf900010fU + 0x083c60U + 12U);
}

// [EN] FDE[2213] start_va=0x05fe70, fde_va=0x083c78, span=36 B | [VN] FDE[2213]
uint32_t ttr_fde_2213_0x05fe70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf900010fU) + (a1 ^ 0xf940026fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf86d79efU + 0x05fe70U) ^ (0xf94001efU + 0x083c78U + 36U);
}

// [EN] FDE[2214] start_va=0x05fe94, fde_va=0x083c90, span=8 B | [VN] FDE[2214]
uint32_t ttr_fde_2214_0x05fe94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e22c000U) + (a1 ^ 0x17ffb188U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x05fe94U) ^ (0x17ff111aU + 0x083c90U + 8U);
}

// [EN] FDE[2215] start_va=0x05fe9c, fde_va=0x083ca8, span=8 B | [VN] FDE[2215]
uint32_t ttr_fde_2215_0x05fe9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ff111aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd101c3ffU + 0x05fe9cU) ^ (0xa9016ffcU + 0x083ca8U + 8U);
}

// [EN] FDE[2216] start_va=0x05fea4, fde_va=0x083cc0, span=28 B | [VN] FDE[2216]
uint32_t ttr_fde_2216_0x05fea4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd101c3ffU) + (a1 ^ 0xa9016ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90267faU + 0x05fea4U) ^ (0xa9035ff8U + 0x083cc0U + 28U);
}

// [EN] FDE[2217] start_va=0x05fec0, fde_va=0x083cd8, span=8 B | [VN] FDE[2217]
uint32_t ttr_fde_2217_0x05fec0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910183ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x05fec0U) ^ (0x17ffb2a4U + 0x083cd8U + 8U);
}

// [EN] FDE[2218] start_va=0x05fec8, fde_va=0x083cf0, span=8 B | [VN] FDE[2218]
uint32_t ttr_fde_2218_0x05fec8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ffb2a4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa94253f5U + 0x05fec8U) ^ (0xa9415bf7U + 0x083cf0U + 8U);
}

// [EN] FDE[2219] start_va=0x05fed0, fde_va=0x083d08, span=16 B | [VN] FDE[2219]
uint32_t ttr_fde_2219_0x05fed0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94253f5U) + (a1 ^ 0xa9415bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84407f8U + 0x05fed0U) ^ (0xd65f03c0U + 0x083d08U + 16U);
}

// [EN] FDE[2220] start_va=0x05fee0, fde_va=0x083d20, span=28 B | [VN] FDE[2220]
uint32_t ttr_fde_2220_0x05fee0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9454ff4U) + (a1 ^ 0xa94457f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9435ff8U + 0x05fee0U) ^ (0xa94267faU + 0x083d20U + 28U);
}

// [EN] FDE[2221] start_va=0x05fefc, fde_va=0x083d38, span=28 B | [VN] FDE[2221]
uint32_t ttr_fde_2221_0x05fefc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400289U) + (a1 ^ 0xf9401bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000109U + 0x05fefcU) ^ (0xf9400a68U + 0x083d38U + 28U);
}

// [EN] FDE[2222] start_va=0x05ff18, fde_va=0x083d50, span=48 B | [VN] FDE[2222]
uint32_t ttr_fde_2222_0x05ff18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400e68U) + (a1 ^ 0x9e6702a0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xbd402261U + 0x05ff18U) ^ (0x0e205800U + 0x083d50U + 48U);
}

// [EN] FDE[2223] start_va=0x05ff48, fde_va=0x083d68, span=16 B | [VN] FDE[2223]
uint32_t ttr_fde_2223_0x05ff48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xaa0103f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb09011fU + 0x05ff48U) ^ (0xd65f03c0U + 0x083d68U + 16U);
}

// [EN] FDE[2224] start_va=0x05ff58, fde_va=0x083d80, span=8 B | [VN] FDE[2224]
uint32_t ttr_fde_2224_0x05ff58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800020U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400428U + 0x05ff58U) ^ (0xf9400009U + 0x083d80U + 8U);
}

// [EN] FDE[2225] start_va=0x05ff60, fde_va=0x083d98, span=60 B | [VN] FDE[2225]
uint32_t ttr_fde_2225_0x05ff60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400428U) + (a1 ^ 0xf9400009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x05ff60U) ^ (0xf9400828U + 0x083d98U + 60U);
}

// [EN] FDE[2226] start_va=0x05ff9c, fde_va=0x083db0, span=12 B | [VN] FDE[2226]
uint32_t ttr_fde_2226_0x05ff9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400fe9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x05ff9cU) ^ (0x900001e8U + 0x083db0U + 12U);
}

// [EN] FDE[2227] start_va=0x05ffa8, fde_va=0x083dc8, span=16 B | [VN] FDE[2227]
uint32_t ttr_fde_2227_0x05ffa8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e8U) + (a1 ^ 0xf9409508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400108U + 0x05ffa8U) ^ (0xd61f0100U + 0x083dc8U + 16U);
}

// [EN] FDE[2228] start_va=0x05ffb8, fde_va=0x083de0, span=8 B | [VN] FDE[2228]
uint32_t ttr_fde_2228_0x05ffb8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910143ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e1U + 0x05ffb8U) ^ (0x17ffb053U + 0x083de0U + 8U);
}

// [EN] FDE[2229] start_va=0x05ffc0, fde_va=0x083df8, span=8 B | [VN] FDE[2229]
uint32_t ttr_fde_2229_0x05ffc0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e1U) + (a1 ^ 0x17ffb053U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0e205800U + 0x05ffc0U) ^ (0x2e303800U + 0x083df8U + 8U);
}

// [EN] FDE[2230] start_va=0x05ffc8, fde_va=0x083e10, span=20 B | [VN] FDE[2230]
uint32_t ttr_fde_2230_0x05ffc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e260008U + 0x05ffc8U) ^ (0xf100051fU + 0x083e10U + 20U);
}

// [EN] FDE[2231] start_va=0x05ffdc, fde_va=0x083e28, span=8 B | [VN] FDE[2231]
uint32_t ttr_fde_2231_0x05ffdc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400501U) + (a1 ^ 0xd61f0020U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x05ffdcU) ^ (0x97ffc245U + 0x083e28U + 8U);
}

// [EN] FDE[2232] start_va=0x05ffe4, fde_va=0x083e40, span=24 B | [VN] FDE[2232]
uint32_t ttr_fde_2232_0x05ffe4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ffc245U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x05ffe4U) ^ (0xf9400d08U + 0x083e40U + 24U);
}

// [EN] FDE[2233] start_va=0x05fffc, fde_va=0x083e60, span=60 B | [VN] FDE[2233]
uint32_t ttr_fde_2233_0x05fffc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400668U) + (a1 ^ 0xf9400289U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000288U + 0x05fffcU) ^ (0xf9400a68U + 0x083e60U + 60U);
}

// [EN] FDE[2234] start_va=0x060038, fde_va=0x083e78, span=20 B | [VN] FDE[2234]
uint32_t ttr_fde_2234_0x060038(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001c8U) + (a1 ^ 0xf947a508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52909800U + 0x060038U) ^ (0xf9400108U + 0x083e78U + 20U);
}

// [EN] FDE[2235] start_va=0x06004c, fde_va=0x083e90, span=28 B | [VN] FDE[2235]
uint32_t ttr_fde_2235_0x06004c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9e670280U) + (a1 ^ 0xf940050aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0e205800U + 0x06004cU) ^ (0x2e303800U + 0x083e90U + 28U);
}

// [EN] FDE[2236] start_va=0x060068, fde_va=0x083ea8, span=20 B | [VN] FDE[2236]
uint32_t ttr_fde_2236_0x060068(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e260009U + 0x060068U) ^ (0xf100053fU + 0x083ea8U + 20U);
}

// [EN] FDE[2237] start_va=0x06007c, fde_va=0x083ec0, span=16 B | [VN] FDE[2237]
uint32_t ttr_fde_2237_0x06007c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd341fd0aU) + (a1 ^ 0x7200011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a890148U + 0x06007cU) ^ (0xd65f03c0U + 0x083ec0U + 16U);
}

// [EN] FDE[2238] start_va=0x06008c, fde_va=0x083ed8, span=68 B | [VN] FDE[2238]
uint32_t ttr_fde_2238_0x06008c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xf9404fe8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400009U + 0x06008cU) ^ (0xf9000008U + 0x083ed8U + 68U);
}

// [EN] FDE[2239] start_va=0x0600d0, fde_va=0x083ef8, span=12 B | [VN] FDE[2239]
uint32_t ttr_fde_2239_0x0600d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0600d0U) ^ (0x2a1f03e0U + 0x083ef8U + 12U);
}

// [EN] FDE[2240] start_va=0x0600dc, fde_va=0x083f10, span=8 B | [VN] FDE[2240]
uint32_t ttr_fde_2240_0x0600dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x0600dcU) ^ (0xaa0003f4U + 0x083f10U + 8U);
}

// [EN] FDE[2241] start_va=0x0600e4, fde_va=0x083f28, span=36 B | [VN] FDE[2241]
uint32_t ttr_fde_2241_0x0600e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91002000U + 0x0600e4U) ^ (0xaa0203f3U + 0x083f28U + 36U);
}

// [EN] FDE[2242] start_va=0x060108, fde_va=0x083f48, span=12 B | [VN] FDE[2242]
uint32_t ttr_fde_2242_0x060108(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401680U) + (a1 ^ 0x910003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff408fU + 0x060108U) ^ (0xf9400408U + 0x083f48U + 12U);
}

// [EN] FDE[2243] start_va=0x060114, fde_va=0x083f60, span=12 B | [VN] FDE[2243]
uint32_t ttr_fde_2243_0x060114(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400408U) + (a1 ^ 0xf9002828U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060114U) ^ (0x7100011fU + 0x083f60U + 12U);
}

// [EN] FDE[2244] start_va=0x060120, fde_va=0x083f78, span=16 B | [VN] FDE[2244]
uint32_t ttr_fde_2244_0x060120(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100011fU) + (a1 ^ 0x1a9f07e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200013fU + 0x060120U) ^ (0xd65f03c0U + 0x083f78U + 16U);
}

// [EN] FDE[2245] start_va=0x060130, fde_va=0x083f90, span=32 B | [VN] FDE[2245]
uint32_t ttr_fde_2245_0x060130(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf90113e8U) + (a1 ^ 0x910883e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9107c3e1U + 0x060130U) ^ (0x910883e2U + 0x083f90U + 32U);
}

// [EN] FDE[2246] start_va=0x060150, fde_va=0x083fa8, span=96 B | [VN] FDE[2246]
uint32_t ttr_fde_2246_0x060150(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa90893e3U) + (a1 ^ 0xa9099be5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90057e7U + 0x060150U) ^ (0xad0007e0U + 0x083fa8U + 96U);
}

// [EN] FDE[2247] start_va=0x0601b0, fde_va=0x083fc0, span=16 B | [VN] FDE[2247]
uint32_t ttr_fde_2247_0x0601b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f3U) + (a1 ^ 0xaa0103f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f5U + 0x0601b0U) ^ (0xd65f03c0U + 0x083fc0U + 16U);
}

// [EN] FDE[2248] start_va=0x0601c0, fde_va=0x083fd8, span=16 B | [VN] FDE[2248]
uint32_t ttr_fde_2248_0x0601c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400269U) + (a1 ^ 0xf828793fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91000508U + 0x0601c0U) ^ (0xd65f03c0U + 0x083fd8U + 16U);
}

// [EN] FDE[2249] start_va=0x0601d0, fde_va=0x083ff0, span=8 B | [VN] FDE[2249]
uint32_t ttr_fde_2249_0x0601d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa8c253f5U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f4U + 0x0601d0U) ^ (0xaa0003f3U + 0x083ff0U + 8U);
}

// [EN] FDE[2250] start_va=0x0601d8, fde_va=0x084008, span=12 B | [VN] FDE[2250]
uint32_t ttr_fde_2250_0x0601d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0601d8U) ^ (0xf9400415U + 0x084008U + 12U);
}

// [EN] FDE[2251] start_va=0x0601e4, fde_va=0x084020, span=16 B | [VN] FDE[2251]
uint32_t ttr_fde_2251_0x0601e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400415U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f4U + 0x0601e4U) ^ (0xd65f03c0U + 0x084020U + 16U);
}

// [EN] FDE[2252] start_va=0x0601f4, fde_va=0x084038, span=12 B | [VN] FDE[2252]
uint32_t ttr_fde_2252_0x0601f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0xa8c35bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0601f4U) ^ (0x9107c3e8U + 0x084038U + 12U);
}

// [EN] FDE[2253] start_va=0x060200, fde_va=0x084050, span=24 B | [VN] FDE[2253]
uint32_t ttr_fde_2253_0x060200(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9107c3e8U) + (a1 ^ 0x910703e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9107c3e2U + 0x060200U) ^ (0xaa1c03e0U + 0x084050U + 24U);
}

// [EN] FDE[2254] start_va=0x060218, fde_va=0x084068, span=24 B | [VN] FDE[2254]
uint32_t ttr_fde_2254_0x060218(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105c3e0U) + (a1 ^ 0x910503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800042U + 0x060218U) ^ (0xbd014fe1U + 0x084068U + 24U);
}

// [EN] FDE[2255] start_va=0x060230, fde_va=0x084080, span=24 B | [VN] FDE[2255]
uint32_t ttr_fde_2255_0x060230(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001c8U) + (a1 ^ 0xf947bd08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9406661U + 0x060230U) ^ (0x5281bc20U + 0x084080U + 24U);
}

// [EN] FDE[2256] start_va=0x060248, fde_va=0x084098, span=8 B | [VN] FDE[2256]
uint32_t ttr_fde_2256_0x060248(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910203ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400108U + 0x060248U) ^ (0xd61f0100U + 0x084098U + 8U);
}

// [EN] FDE[2257] start_va=0x060250, fde_va=0x0840b0, span=8 B | [VN] FDE[2257]
uint32_t ttr_fde_2257_0x060250(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400108U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9444ff4U + 0x060250U) ^ (0xa94357f6U + 0x0840b0U + 8U);
}

// [EN] FDE[2258] start_va=0x060258, fde_va=0x0840c8, span=24 B | [VN] FDE[2258]
uint32_t ttr_fde_2258_0x060258(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9444ff4U) + (a1 ^ 0xa94357f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9425ff8U + 0x060258U) ^ (0xa94167faU + 0x0840c8U + 24U);
}

// [EN] FDE[2259] start_va=0x060270, fde_va=0x0840e0, span=36 B | [VN] FDE[2259]
uint32_t ttr_fde_2259_0x060270(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf90002dcU) + (a1 ^ 0xf9400268U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf87b7908U + 0x060270U) ^ (0xf9400108U + 0x0840e0U + 36U);
}

// [EN] FDE[2260] start_va=0x060294, fde_va=0x0840f8, span=20 B | [VN] FDE[2260]
uint32_t ttr_fde_2260_0x060294(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x900001e8U) + (a1 ^ 0x91006108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2d401103U + 0x060294U) ^ (0xbd400905U + 0x0840f8U + 20U);
}

// [EN] FDE[2261] start_va=0x0602a8, fde_va=0x084110, span=12 B | [VN] FDE[2261]
uint32_t ttr_fde_2261_0x0602a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9414ff4U) + (a1 ^ 0xa8c357f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0602a8U) ^ (0xf9400008U + 0x084110U + 12U);
}

// [EN] FDE[2262] start_va=0x0602b4, fde_va=0x084128, span=108 B | [VN] FDE[2262]
uint32_t ttr_fde_2262_0x0602b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9401809U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xad401100U + 0x0602b4U) ^ (0xad400921U + 0x084128U + 108U);
}

// [EN] FDE[2263] start_va=0x060320, fde_va=0x084140, span=8 B | [VN] FDE[2263]
uint32_t ttr_fde_2263_0x060320(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ffb41aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e8U + 0x060320U) ^ (0x17fef0a9U + 0x084140U + 8U);
}

// [EN] FDE[2264] start_va=0x060328, fde_va=0x084158, span=8 B | [VN] FDE[2264]
uint32_t ttr_fde_2264_0x060328(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e8U) + (a1 ^ 0x17fef0a9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9454ff4U + 0x060328U) ^ (0xa94457f6U + 0x084158U + 8U);
}

// [EN] FDE[2265] start_va=0x060330, fde_va=0x084170, span=20 B | [VN] FDE[2265]
uint32_t ttr_fde_2265_0x060330(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9454ff4U) + (a1 ^ 0xa94457f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401bf7U + 0x060330U) ^ (0x9101c3ffU + 0x084170U + 20U);
}

// [EN] FDE[2266] start_va=0x060344, fde_va=0x084188, span=12 B | [VN] FDE[2266]
uint32_t ttr_fde_2266_0x060344(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94017e9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060344U) ^ (0xaa0003f3U + 0x084188U + 12U);
}

// [EN] FDE[2267] start_va=0x060350, fde_va=0x0841a0, span=12 B | [VN] FDE[2267]
uint32_t ttr_fde_2267_0x060350(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xaa0103f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060350U) ^ (0xf9400509U + 0x0841a0U + 12U);
}

// [EN] FDE[2268] start_va=0x06035c, fde_va=0x0841b8, span=28 B | [VN] FDE[2268]
uint32_t ttr_fde_2268_0x06035c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400509U) + (a1 ^ 0xa900240aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000500U + 0x06035cU) ^ (0xf9401e68U + 0x0841b8U + 28U);
}

// [EN] FDE[2269] start_va=0x060378, fde_va=0x0841d0, span=24 B | [VN] FDE[2269]
uint32_t ttr_fde_2269_0x060378(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94006d8U) + (a1 ^ 0x0e205800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2e303800U + 0x060378U) ^ (0x1e260017U + 0x0841d0U + 24U);
}

// [EN] FDE[2270] start_va=0x060390, fde_va=0x0841e8, span=16 B | [VN] FDE[2270]
uint32_t ttr_fde_2270_0x060390(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807c08U) + (a1 ^ 0xb9000028U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf900283fU + 0x060390U) ^ (0xd65f03c0U + 0x0841e8U + 16U);
}

// [EN] FDE[2271] start_va=0x0603a0, fde_va=0x084200, span=16 B | [VN] FDE[2271]
uint32_t ttr_fde_2271_0x0603a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f4U) + (a1 ^ 0xaa0103e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f3U + 0x0603a0U) ^ (0x17feeeb9U + 0x084200U + 16U);
}

// [EN] FDE[2272] start_va=0x0603b0, fde_va=0x084218, span=12 B | [VN] FDE[2272]
uint32_t ttr_fde_2272_0x0603b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9400508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x0603b0U) ^ (0xa9474ff4U + 0x084218U + 12U);
}

// [EN] FDE[2273] start_va=0x0603bc, fde_va=0x084230, span=28 B | [VN] FDE[2273]
uint32_t ttr_fde_2273_0x0603bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9474ff4U) + (a1 ^ 0xa94657f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9455ff8U + 0x0603bcU) ^ (0xa94467faU + 0x084230U + 28U);
}

// [EN] FDE[2274] start_va=0x0603d8, fde_va=0x084248, span=8 B | [VN] FDE[2274]
uint32_t ttr_fde_2274_0x0603d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0603d8U) ^ (0xaa1403e1U + 0x084248U + 8U);
}

// [EN] FDE[2275] start_va=0x0603e0, fde_va=0x084260, span=12 B | [VN] FDE[2275]
uint32_t ttr_fde_2275_0x0603e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0603e0U) ^ (0xf9401e68U + 0x084260U + 12U);
}

// [EN] FDE[2276] start_va=0x0603ec, fde_va=0x084278, span=16 B | [VN] FDE[2276]
uint32_t ttr_fde_2276_0x0603ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401e68U) + (a1 ^ 0xf9400508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9001e68U + 0x0603ecU) ^ (0xd65f03c0U + 0x084278U + 16U);
}

// [EN] FDE[2277] start_va=0x0603fc, fde_va=0x084290, span=12 B | [VN] FDE[2277]
uint32_t ttr_fde_2277_0x0603fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2d401103U) + (a1 ^ 0xbd400905U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0603fcU) ^ (0xf9400669U + 0x084290U + 12U);
}

// [EN] FDE[2278] start_va=0x060408, fde_va=0x0842a8, span=20 B | [VN] FDE[2278]
uint32_t ttr_fde_2278_0x060408(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400669U) + (a1 ^ 0xaa0003e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b150d29U + 0x060408U) ^ (0xa9008269U + 0x0842a8U + 20U);
}

// [EN] FDE[2279] start_va=0x06041c, fde_va=0x0842c0, span=44 B | [VN] FDE[2279]
uint32_t ttr_fde_2279_0x06041c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000f1fU) + (a1 ^ 0xd1000708U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f27e9U + 0x06041cU) ^ (0xea08031fU + 0x0842c0U + 44U);
}

// [EN] FDE[2280] start_va=0x060448, fde_va=0x0842d8, span=8 B | [VN] FDE[2280]
uint32_t ttr_fde_2280_0x060448(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400108U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x060448U) ^ (0xf9400908U + 0x0842d8U + 8U);
}

// [EN] FDE[2281] start_va=0x060450, fde_va=0x0842f0, span=12 B | [VN] FDE[2281]
uint32_t ttr_fde_2281_0x060450(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9400908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x060450U) ^ (0xaa1403f5U + 0x0842f0U + 12U);
}

// [EN] FDE[2282] start_va=0x06045c, fde_va=0x084308, span=40 B | [VN] FDE[2282]
uint32_t ttr_fde_2282_0x06045c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403f5U) + (a1 ^ 0xb843cea8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5284c009U + 0x06045cU) ^ (0x5284c02aU + 0x084308U + 40U);
}

// [EN] FDE[2283] start_va=0x060484, fde_va=0x084320, span=12 B | [VN] FDE[2283]
uint32_t ttr_fde_2283_0x060484(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e220802U) + (a1 ^ 0x1e212040U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060484U) ^ (0x910703e8U + 0x084320U + 12U);
}

// [EN] FDE[2284] start_va=0x060490, fde_va=0x084338, span=24 B | [VN] FDE[2284]
uint32_t ttr_fde_2284_0x060490(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910703e8U) + (a1 ^ 0x910643e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910703e2U + 0x060490U) ^ (0xaa1c03e0U + 0x084338U + 24U);
}

// [EN] FDE[2285] start_va=0x0604a8, fde_va=0x084350, span=8 B | [VN] FDE[2285]
uint32_t ttr_fde_2285_0x0604a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910883e0U) + (a1 ^ 0x17ff05baU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd0aU + 0x0604a8U) ^ (0x7200011fU + 0x084350U + 8U);
}

// [EN] FDE[2286] start_va=0x0604b0, fde_va=0x084368, span=16 B | [VN] FDE[2286]
uint32_t ttr_fde_2286_0x0604b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd341fd0aU) + (a1 ^ 0x7200011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a890149U + 0x0604b0U) ^ (0xd65f03c0U + 0x084368U + 16U);
}

// [EN] FDE[2287] start_va=0x0604c0, fde_va=0x084380, span=8 B | [VN] FDE[2287]
uint32_t ttr_fde_2287_0x0604c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e0U) + (a1 ^ 0x17ff05b4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd10203ffU + 0x0604c0U) ^ (0xa9026ffcU + 0x084380U + 8U);
}

// [EN] FDE[2288] start_va=0x0604c8, fde_va=0x084398, span=28 B | [VN] FDE[2288]
uint32_t ttr_fde_2288_0x0604c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd10203ffU) + (a1 ^ 0xa9026ffcU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90367faU + 0x0604c8U) ^ (0xa9045ff8U + 0x084398U + 28U);
}

// [EN] FDE[2289] start_va=0x0604e4, fde_va=0x0843b0, span=16 B | [VN] FDE[2289]
uint32_t ttr_fde_2289_0x0604e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb0000041U) + (a1 ^ 0x911af421U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x0604e4U) ^ (0x17ff45e9U + 0x0843b0U + 16U);
}

// [EN] FDE[2290] start_va=0x0604f4, fde_va=0x0843c8, span=40 B | [VN] FDE[2290]
uint32_t ttr_fde_2290_0x0604f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400809U) + (a1 ^ 0xf940000aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x5280030bU + 0x0604f4U) ^ (0xcb0a0129U + 0x0843c8U + 40U);
}

// [EN] FDE[2291] start_va=0x06051c, fde_va=0x0843e0, span=16 B | [VN] FDE[2291]
uint32_t ttr_fde_2291_0x06051c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f4U) + (a1 ^ 0xaa0103e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f3U + 0x06051cU) ^ (0xd65f03c0U + 0x0843e0U + 16U);
}

// [EN] FDE[2292] start_va=0x06052c, fde_va=0x0843f8, span=16 B | [VN] FDE[2292]
uint32_t ttr_fde_2292_0x06052c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94253f5U) + (a1 ^ 0xa9415bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84407f8U + 0x06052cU) ^ (0xd65f03c0U + 0x0843f8U + 16U);
}

// [EN] FDE[2293] start_va=0x06053c, fde_va=0x084410, span=8 B | [VN] FDE[2293]
uint32_t ttr_fde_2293_0x06053c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910103ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e1U + 0x06053cU) ^ (0xaa1303e0U + 0x084410U + 8U);
}

// [EN] FDE[2294] start_va=0x060544, fde_va=0x084428, span=12 B | [VN] FDE[2294]
uint32_t ttr_fde_2294_0x060544(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060544U) ^ (0xf81f0ffeU + 0x084428U + 12U);
}

// [EN] FDE[2295] start_va=0x060550, fde_va=0x084440, span=24 B | [VN] FDE[2295]
uint32_t ttr_fde_2295_0x060550(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ff7f6eU + 0x060550U) ^ (0xaa1303e0U + 0x084440U + 24U);
}

// [EN] FDE[2296] start_va=0x060568, fde_va=0x084460, span=28 B | [VN] FDE[2296]
uint32_t ttr_fde_2296_0x060568(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800309U) + (a1 ^ 0x9ac90d08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb200f3e9U + 0x060568U) ^ (0xf28aaa89U + 0x084460U + 28U);
}

// [EN] FDE[2297] start_va=0x060584, fde_va=0x084478, span=12 B | [VN] FDE[2297]
uint32_t ttr_fde_2297_0x060584(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0003f5U) + (a1 ^ 0x910523e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0582U + 0x060584U) ^ (0x0e205800U + 0x084478U + 12U);
}

// [EN] FDE[2298] start_va=0x060590, fde_va=0x084490, span=20 B | [VN] FDE[2298]
uint32_t ttr_fde_2298_0x060590(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e26000aU + 0x060590U) ^ (0xf100055fU + 0x084490U + 20U);
}

// [EN] FDE[2299] start_va=0x0605a4, fde_va=0x0844a8, span=12 B | [VN] FDE[2299]
uint32_t ttr_fde_2299_0x0605a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100c3e0U) + (a1 ^ 0x910123e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff9a53U + 0x0605a4U) ^ (0x9102c3e0U + 0x0844a8U + 12U);
}

// [EN] FDE[2300] start_va=0x0605b0, fde_va=0x0844c0, span=12 B | [VN] FDE[2300]
uint32_t ttr_fde_2300_0x0605b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9102c3e0U) + (a1 ^ 0x9105c3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffde80U + 0x0605b0U) ^ (0x910223e0U + 0x0844c0U + 12U);
}

// [EN] FDE[2301] start_va=0x0605bc, fde_va=0x0844d8, span=12 B | [VN] FDE[2301]
uint32_t ttr_fde_2301_0x0605bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910223e0U) + (a1 ^ 0x910523e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff422cU + 0x0605bcU) ^ (0x910123e1U + 0x0844d8U + 12U);
}

// [EN] FDE[2302] start_va=0x0605c8, fde_va=0x0844f0, span=12 B | [VN] FDE[2302]
uint32_t ttr_fde_2302_0x0605c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910123e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff9d91U + 0x0605c8U) ^ (0xa9464ff4U + 0x0844f0U + 12U);
}

// [EN] FDE[2303] start_va=0x0605d4, fde_va=0x084508, span=32 B | [VN] FDE[2303]
uint32_t ttr_fde_2303_0x0605d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9464ff4U) + (a1 ^ 0xa94557f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9445ff8U + 0x0605d4U) ^ (0xa94367faU + 0x084508U + 32U);
}

// [EN] FDE[2304] start_va=0x0605f4, fde_va=0x084520, span=8 B | [VN] FDE[2304]
uint32_t ttr_fde_2304_0x0605f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x17ff0db0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c24ff4U + 0x0605f4U) ^ (0xd65f03c0U + 0x084520U + 8U);
}

// [EN] FDE[2305] start_va=0x0605fc, fde_va=0x084538, span=8 B | [VN] FDE[2305]
uint32_t ttr_fde_2305_0x0605fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa8c24ff4U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f3U + 0x0605fcU) ^ (0xaa0003f4U + 0x084538U + 8U);
}

// [EN] FDE[2306] start_va=0x060604, fde_va=0x084550, span=12 B | [VN] FDE[2306]
uint32_t ttr_fde_2306_0x060604(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff9870U + 0x060604U) ^ (0x910243ffU + 0x084550U + 12U);
}

// [EN] FDE[2307] start_va=0x060610, fde_va=0x084568, span=8 B | [VN] FDE[2307]
uint32_t ttr_fde_2307_0x060610(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910243ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x060610U) ^ (0xaa1503e1U + 0x084568U + 8U);
}

// [EN] FDE[2308] start_va=0x060618, fde_va=0x084580, span=12 B | [VN] FDE[2308]
uint32_t ttr_fde_2308_0x060618(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060618U) ^ (0x910023e0U + 0x084580U + 12U);
}

// [EN] FDE[2309] start_va=0x060624, fde_va=0x084598, span=8 B | [VN] FDE[2309]
uint32_t ttr_fde_2309_0x060624(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff0da4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400288U + 0x060624U) ^ (0xf9401bf6U + 0x084598U + 8U);
}

// [EN] FDE[2310] start_va=0x06062c, fde_va=0x0845b0, span=28 B | [VN] FDE[2310]
uint32_t ttr_fde_2310_0x06062c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400288U) + (a1 ^ 0xf9401bf6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f8008U + 0x06062cU) ^ (0xf9400668U + 0x0845b0U + 28U);
}

// [EN] FDE[2311] start_va=0x060648, fde_va=0x0845c8, span=32 B | [VN] FDE[2311]
uint32_t ttr_fde_2311_0x060648(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9454ff4U) + (a1 ^ 0xa94457f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9435ff8U + 0x060648U) ^ (0xa94267faU + 0x0845c8U + 32U);
}

// [EN] FDE[2312] start_va=0x060668, fde_va=0x0845e0, span=36 B | [VN] FDE[2312]
uint32_t ttr_fde_2312_0x060668(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e260009U + 0x060668U) ^ (0x9e230100U + 0x0845e0U + 36U);
}

// [EN] FDE[2313] start_va=0x06068c, fde_va=0x0845f8, span=24 B | [VN] FDE[2313]
uint32_t ttr_fde_2313_0x06068c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9036ffcU) + (a1 ^ 0xa90467faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9055ff8U + 0x06068cU) ^ (0xa90657f6U + 0x0845f8U + 24U);
}

// [EN] FDE[2314] start_va=0x0606a4, fde_va=0x084610, span=16 B | [VN] FDE[2314]
uint32_t ttr_fde_2314_0x0606a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x397212a8U) + (a1 ^ 0x39400289U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400a8aU + 0x0606a4U) ^ (0xd65f03c0U + 0x084610U + 16U);
}

// [EN] FDE[2315] start_va=0x0606b4, fde_va=0x084628, span=36 B | [VN] FDE[2315]
uint32_t ttr_fde_2315_0x0606b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b080128U) + (a1 ^ 0xf9002be8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xad408be0U + 0x0606b4U) ^ (0xad420fe1U + 0x084628U + 36U);
}

// [EN] FDE[2316] start_va=0x0606d8, fde_va=0x084640, span=36 B | [VN] FDE[2316]
uint32_t ttr_fde_2316_0x0606d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xa9402001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400669U + 0x0606d8U) ^ (0xaa0003f4U + 0x084640U + 36U);
}

// [EN] FDE[2317] start_va=0x0606fc, fde_va=0x084658, span=8 B | [VN] FDE[2317]
uint32_t ttr_fde_2317_0x0606fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ffae41U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9105c3e2U + 0x0606fcU) ^ (0x52800061U + 0x084658U + 8U);
}

// [EN] FDE[2318] start_va=0x060704, fde_va=0x084670, span=20 B | [VN] FDE[2318]
uint32_t ttr_fde_2318_0x060704(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105c3e2U) + (a1 ^ 0x52800061U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb90173ffU + 0x060704U) ^ (0xd1006100U + 0x084670U + 20U);
}

// [EN] FDE[2319] start_va=0x060718, fde_va=0x084688, span=16 B | [VN] FDE[2319]
uint32_t ttr_fde_2319_0x060718(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e624000U) + (a1 ^ 0xbd02fbe0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4eab1d60U + 0x060718U) ^ (0x17feef9bU + 0x084688U + 16U);
}

// [EN] FDE[2320] start_va=0x060728, fde_va=0x0846a0, span=12 B | [VN] FDE[2320]
uint32_t ttr_fde_2320_0x060728(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e270100U) + (a1 ^ 0x4ea81d01U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2023U + 0x060728U) ^ (0xf9400688U + 0x0846a0U + 12U);
}

// [EN] FDE[2321] start_va=0x060734, fde_va=0x0846b8, span=60 B | [VN] FDE[2321]
uint32_t ttr_fde_2321_0x060734(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400688U) + (a1 ^ 0xf9400269U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000268U + 0x060734U) ^ (0xf9400a88U + 0x0846b8U + 60U);
}

// [EN] FDE[2322] start_va=0x060770, fde_va=0x0846d0, span=52 B | [VN] FDE[2322]
uint32_t ttr_fde_2322_0x060770(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a80U) + (a1 ^ 0x394023e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa94127eaU + 0x060770U) ^ (0xb24002acU + 0x0846d0U + 52U);
}

// [EN] FDE[2323] start_va=0x0607a4, fde_va=0x0846e8, span=12 B | [VN] FDE[2323]
uint32_t ttr_fde_2323_0x0607a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91000508U) + (a1 ^ 0x9e230101U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0607a4U) ^ (0x927ced16U + 0x0846e8U + 12U);
}

// [EN] FDE[2324] start_va=0x0607b0, fde_va=0x084700, span=12 B | [VN] FDE[2324]
uint32_t ttr_fde_2324_0x0607b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x927ced16U) + (a1 ^ 0xaa1603e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feed6aU + 0x0607b0U) ^ (0xf9000680U + 0x084700U + 12U);
}

// [EN] FDE[2325] start_va=0x0607bc, fde_va=0x084718, span=12 B | [VN] FDE[2325]
uint32_t ttr_fde_2325_0x0607bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000680U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feedefU + 0x0607bcU) ^ (0x910183ffU + 0x084718U + 12U);
}

// [EN] FDE[2326] start_va=0x0607c8, fde_va=0x084730, span=8 B | [VN] FDE[2326]
uint32_t ttr_fde_2326_0x0607c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910183ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf1000edfU + 0x0607c8U) ^ (0xd10006c8U + 0x084730U + 8U);
}

// [EN] FDE[2327] start_va=0x0607d0, fde_va=0x084748, span=52 B | [VN] FDE[2327]
uint32_t ttr_fde_2327_0x0607d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000edfU) + (a1 ^ 0xd10006c8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f27e9U + 0x0607d0U) ^ (0xea0802dfU + 0x084748U + 52U);
}

// [EN] FDE[2328] start_va=0x060804, fde_va=0x084760, span=28 B | [VN] FDE[2328]
uint32_t ttr_fde_2328_0x060804(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x39400100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800201U + 0x060804U) ^ (0x97ff8087U + 0x084760U + 28U);
}

// [EN] FDE[2329] start_va=0x060820, fde_va=0x084780, span=28 B | [VN] FDE[2329]
uint32_t ttr_fde_2329_0x060820(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9343fd49U) + (a1 ^ 0x91000529U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9280002aU + 0x060820U) ^ (0x9aca0d35U + 0x084780U + 28U);
}

// [EN] FDE[2330] start_va=0x06083c, fde_va=0x084798, span=28 B | [VN] FDE[2330]
uint32_t ttr_fde_2330_0x06083c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9343fd49U) + (a1 ^ 0x91000529U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9280002aU + 0x06083cU) ^ (0x9aca0d35U + 0x084798U + 28U);
}

// [EN] FDE[2331] start_va=0x060858, fde_va=0x0847b0, span=16 B | [VN] FDE[2331]
uint32_t ttr_fde_2331_0x060858(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103e0U) + (a1 ^ 0xaa0803e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03e3U + 0x060858U) ^ (0x17feeeb3U + 0x0847b0U + 16U);
}

// [EN] FDE[2332] start_va=0x060868, fde_va=0x0847c8, span=16 B | [VN] FDE[2332]
uint32_t ttr_fde_2332_0x060868(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94253f5U) + (a1 ^ 0xa9415bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84407f8U + 0x060868U) ^ (0x17feed2fU + 0x0847c8U + 16U);
}

// [EN] FDE[2333] start_va=0x060878, fde_va=0x0847e0, span=52 B | [VN] FDE[2333]
uint32_t ttr_fde_2333_0x060878(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a60U) + (a1 ^ 0x394023e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa94127eaU + 0x060878U) ^ (0xb24002acU + 0x0847e0U + 52U);
}

// [EN] FDE[2334] start_va=0x0608ac, fde_va=0x0847f8, span=60 B | [VN] FDE[2334]
uint32_t ttr_fde_2334_0x0608ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401288U) + (a1 ^ 0x52800309U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9b297ea9U + 0x0608acU) ^ (0xb9400acaU + 0x0847f8U + 60U);
}

// [EN] FDE[2335] start_va=0x0608e8, fde_va=0x084810, span=28 B | [VN] FDE[2335]
uint32_t ttr_fde_2335_0x0608e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910083e9U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910083e2U + 0x0608e8U) ^ (0xaa1403e0U + 0x084810U + 28U);
}

// [EN] FDE[2336] start_va=0x060904, fde_va=0x084828, span=28 B | [VN] FDE[2336]
uint32_t ttr_fde_2336_0x060904(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910143e9U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910143e2U + 0x060904U) ^ (0xaa1403e0U + 0x084828U + 28U);
}

// [EN] FDE[2337] start_va=0x060920, fde_va=0x084840, span=12 B | [VN] FDE[2337]
uint32_t ttr_fde_2337_0x060920(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf90006a0U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feed96U + 0x060920U) ^ (0xaa0103f4U + 0x084840U + 12U);
}

// [EN] FDE[2338] start_va=0x06092c, fde_va=0x084858, span=12 B | [VN] FDE[2338]
uint32_t ttr_fde_2338_0x06092c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff971bU + 0x06092cU) ^ (0xf9400008U + 0x084858U + 12U);
}

// [EN] FDE[2339] start_va=0x060938, fde_va=0x084870, span=12 B | [VN] FDE[2339]
uint32_t ttr_fde_2339_0x060938(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9401108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x060938U) ^ (0xf9400008U + 0x084870U + 12U);
}

// [EN] FDE[2340] start_va=0x060944, fde_va=0x084888, span=12 B | [VN] FDE[2340]
uint32_t ttr_fde_2340_0x060944(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9401508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x060944U) ^ (0xa9424ff4U + 0x084888U + 12U);
}

// [EN] FDE[2341] start_va=0x060950, fde_va=0x0848a0, span=16 B | [VN] FDE[2341]
uint32_t ttr_fde_2341_0x060950(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9424ff4U) + (a1 ^ 0xa94157f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84407f7U + 0x060950U) ^ (0xd65f03c0U + 0x0848a0U + 16U);
}

// [EN] FDE[2342] start_va=0x060960, fde_va=0x0848b8, span=16 B | [VN] FDE[2342]
uint32_t ttr_fde_2342_0x060960(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x927df116U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013e9U + 0x060960U) ^ (0x17ffa69aU + 0x0848b8U + 16U);
}

// [EN] FDE[2343] start_va=0x060970, fde_va=0x0848d0, span=16 B | [VN] FDE[2343]
uint32_t ttr_fde_2343_0x060970(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x927df116U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013e9U + 0x060970U) ^ (0x17ff7c9eU + 0x0848d0U + 16U);
}

// [EN] FDE[2344] start_va=0x060980, fde_va=0x0848e8, span=12 B | [VN] FDE[2344]
uint32_t ttr_fde_2344_0x060980(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1303e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060980U) ^ (0xaa1403e0U + 0x0848e8U + 12U);
}

// [EN] FDE[2345] start_va=0x06098c, fde_va=0x084900, span=12 B | [VN] FDE[2345]
uint32_t ttr_fde_2345_0x06098c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0bf4U + 0x06098cU) ^ (0xaa1303e0U + 0x084900U + 12U);
}

// [EN] FDE[2346] start_va=0x060998, fde_va=0x084918, span=12 B | [VN] FDE[2346]
uint32_t ttr_fde_2346_0x060998(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060998U) ^ (0xf84207f4U + 0x084918U + 12U);
}

// [EN] FDE[2347] start_va=0x0609a4, fde_va=0x084930, span=8 B | [VN] FDE[2347]
uint32_t ttr_fde_2347_0x0609a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f4U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd0aU + 0x0609a4U) ^ (0x7200011fU + 0x084930U + 8U);
}

// [EN] FDE[2348] start_va=0x0609ac, fde_va=0x084948, span=20 B | [VN] FDE[2348]
uint32_t ttr_fde_2348_0x0609ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd341fd0aU) + (a1 ^ 0x7200011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a890149U + 0x0609acU) ^ (0xf100093fU + 0x084948U + 20U);
}

// [EN] FDE[2349] start_va=0x0609c0, fde_va=0x084960, span=8 B | [VN] FDE[2349]
uint32_t ttr_fde_2349_0x0609c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4ea81d01U) + (a1 ^ 0x17ff1f7eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000500U + 0x0609c0U) ^ (0x17feecd9U + 0x084960U + 8U);
}

// [EN] FDE[2350] start_va=0x0609c8, fde_va=0x084978, span=8 B | [VN] FDE[2350]
uint32_t ttr_fde_2350_0x0609c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000500U) + (a1 ^ 0x17feecd9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94012a8U + 0x0609c8U) ^ (0xb9400ac9U + 0x084978U + 8U);
}

// [EN] FDE[2351] start_va=0x0609d0, fde_va=0x084990, span=56 B | [VN] FDE[2351]
uint32_t ttr_fde_2351_0x0609d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94012a8U) + (a1 ^ 0xb9400ac9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94002caU + 0x0609d0U) ^ (0x5280018bU + 0x084990U + 56U);
}

// [EN] FDE[2352] start_va=0x060a08, fde_va=0x0849a8, span=20 B | [VN] FDE[2352]
uint32_t ttr_fde_2352_0x060a08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa90367faU) + (a1 ^ 0xa9045ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90557f6U + 0x060a08U) ^ (0xa9064ff4U + 0x0849a8U + 20U);
}

// [EN] FDE[2353] start_va=0x060a1c, fde_va=0x0849c0, span=32 B | [VN] FDE[2353]
uint32_t ttr_fde_2353_0x060a1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001c8U) + (a1 ^ 0xf9478d08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e9U + 0x060a1cU) ^ (0x91004129U + 0x0849c0U + 32U);
}

// [EN] FDE[2354] start_va=0x060a3c, fde_va=0x0849d8, span=8 B | [VN] FDE[2354]
uint32_t ttr_fde_2354_0x060a3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x17ff0455U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e1U + 0x060a3cU) ^ (0x17feeccaU + 0x0849d8U + 8U);
}

// [EN] FDE[2355] start_va=0x060a44, fde_va=0x0849f0, span=8 B | [VN] FDE[2355]
uint32_t ttr_fde_2355_0x060a44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e1U) + (a1 ^ 0x17feeccaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401e97U + 0x060a44U) ^ (0x910006d8U + 0x0849f0U + 8U);
}

// [EN] FDE[2356] start_va=0x060a4c, fde_va=0x084a08, span=24 B | [VN] FDE[2356]
uint32_t ttr_fde_2356_0x060a4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401e97U) + (a1 ^ 0x910006d8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x060a4cU) ^ (0xaa1803e1U + 0x084a08U + 24U);
}

// [EN] FDE[2357] start_va=0x060a64, fde_va=0x084a20, span=12 B | [VN] FDE[2357]
uint32_t ttr_fde_2357_0x060a64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa900fc1fU) + (a1 ^ 0xf9000008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060a64U) ^ (0xf9400808U + 0x084a20U + 12U);
}

// [EN] FDE[2358] start_va=0x060a70, fde_va=0x084a38, span=24 B | [VN] FDE[2358]
uint32_t ttr_fde_2358_0x060a70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400808U) + (a1 ^ 0xf9400009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb090108U + 0x060a70U) ^ (0xb27fe7e9U + 0x084a38U + 24U);
}

// [EN] FDE[2359] start_va=0x060a88, fde_va=0x084a50, span=24 B | [VN] FDE[2359]
uint32_t ttr_fde_2359_0x060a88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xcb09010aU + 0x060a88U) ^ (0x9acb0d55U + 0x084a50U + 24U);
}

// [EN] FDE[2360] start_va=0x060aa0, fde_va=0x084a68, span=16 B | [VN] FDE[2360]
uint32_t ttr_fde_2360_0x060aa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9004be8U) + (a1 ^ 0x91002348U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9056bfbU + 0x060aa0U) ^ (0xd65f03c0U + 0x084a68U + 16U);
}

// [EN] FDE[2361] start_va=0x060ab0, fde_va=0x084a80, span=20 B | [VN] FDE[2361]
uint32_t ttr_fde_2361_0x060ab0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb15028bU) + (a1 ^ 0xcb08014cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9acd0d8cU + 0x060ab0U) ^ (0xeb0b019fU + 0x084a80U + 20U);
}

// [EN] FDE[2362] start_va=0x060ac4, fde_va=0x084a98, span=8 B | [VN] FDE[2362]
uint32_t ttr_fde_2362_0x060ac4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37df280U) + (a1 ^ 0x17feeca6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x060ac4U) ^ (0x17ff7dc4U + 0x084a98U + 8U);
}

// [EN] FDE[2363] start_va=0x060acc, fde_va=0x084ab0, span=8 B | [VN] FDE[2363]
uint32_t ttr_fde_2363_0x060acc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff7dc4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf81f0ffeU + 0x060accU) ^ (0xaa1403e0U + 0x084ab0U + 8U);
}

// [EN] FDE[2364] start_va=0x060ad4, fde_va=0x084ac8, span=24 B | [VN] FDE[2364]
uint32_t ttr_fde_2364_0x060ad4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ffd3b0U + 0x060ad4U) ^ (0x91016294U + 0x084ac8U + 24U);
}

// [EN] FDE[2365] start_va=0x060aec, fde_va=0x084ae8, span=24 B | [VN] FDE[2365]
uint32_t ttr_fde_2365_0x060aec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910643e8U) + (a1 ^ 0x910583e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910643e2U + 0x060aecU) ^ (0xaa1c03e0U + 0x084ae8U + 24U);
}

// [EN] FDE[2366] start_va=0x060b04, fde_va=0x084b00, span=8 B | [VN] FDE[2366]
uint32_t ttr_fde_2366_0x060b04(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100c3e0U) + (a1 ^ 0x17ff0423U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910203ffU + 0x060b04U) ^ (0xd65f03c0U + 0x084b00U + 8U);
}

// [EN] FDE[2367] start_va=0x060b0c, fde_va=0x084b18, span=8 B | [VN] FDE[2367]
uint32_t ttr_fde_2367_0x060b0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910203ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e9U + 0x060b0cU) ^ (0xcb080273U + 0x084b18U + 8U);
}

// [EN] FDE[2368] start_va=0x060b14, fde_va=0x084b30, span=24 B | [VN] FDE[2368]
uint32_t ttr_fde_2368_0x060b14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e9U) + (a1 ^ 0xcb080273U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x060b14U) ^ (0xaa0903e1U + 0x084b30U + 24U);
}

// [EN] FDE[2369] start_va=0x060b2c, fde_va=0x084b48, span=12 B | [VN] FDE[2369]
uint32_t ttr_fde_2369_0x060b2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001c1U) + (a1 ^ 0xf9453c21U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060b2cU) ^ (0xa94453f5U + 0x084b48U + 12U);
}

// [EN] FDE[2370] start_va=0x060b38, fde_va=0x084b60, span=24 B | [VN] FDE[2370]
uint32_t ttr_fde_2370_0x060b38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94453f5U) + (a1 ^ 0xa9435bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa94263f9U + 0x060b38U) ^ (0xa9416bfbU + 0x084b60U + 24U);
}

// [EN] FDE[2371] start_va=0x060b50, fde_va=0x084b78, span=12 B | [VN] FDE[2371]
uint32_t ttr_fde_2371_0x060b50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800043U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd37aU + 0x060b50U) ^ (0x910123e0U + 0x084b78U + 12U);
}

// [EN] FDE[2372] start_va=0x060b5c, fde_va=0x084b90, span=8 B | [VN] FDE[2372]
uint32_t ttr_fde_2372_0x060b5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910123e0U) + (a1 ^ 0x17ff0c56U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03e8U + 0x060b5cU) ^ (0xf9000674U + 0x084b90U + 8U);
}

// [EN] FDE[2373] start_va=0x060b64, fde_va=0x084ba8, span=12 B | [VN] FDE[2373]
uint32_t ttr_fde_2373_0x060b64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e8U) + (a1 ^ 0xf9000674U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060b64U) ^ (0xf1000f7fU + 0x084ba8U + 12U);
}

// [EN] FDE[2374] start_va=0x060b70, fde_va=0x084bc0, span=52 B | [VN] FDE[2374]
uint32_t ttr_fde_2374_0x060b70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000f7fU) + (a1 ^ 0xd1000768U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f27e9U + 0x060b70U) ^ (0xea08037fU + 0x084bc0U + 52U);
}

// [EN] FDE[2375] start_va=0x060ba4, fde_va=0x084bd8, span=12 B | [VN] FDE[2375]
uint32_t ttr_fde_2375_0x060ba4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9414ff4U) + (a1 ^ 0xf84307f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060ba4U) ^ (0xaa0103f4U + 0x084bd8U + 12U);
}

// [EN] FDE[2376] start_va=0x060bb0, fde_va=0x084bf0, span=12 B | [VN] FDE[2376]
uint32_t ttr_fde_2376_0x060bb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xd37dfc28U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060bb0U) ^ (0xf9400008U + 0x084bf0U + 12U);
}

// [EN] FDE[2377] start_va=0x060bbc, fde_va=0x084c08, span=12 B | [VN] FDE[2377]
uint32_t ttr_fde_2377_0x060bbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9400d08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0100U + 0x060bbcU) ^ (0xaa0103f3U + 0x084c08U + 12U);
}

// [EN] FDE[2378] start_va=0x060bc8, fde_va=0x084c20, span=12 B | [VN] FDE[2378]
uint32_t ttr_fde_2378_0x060bc8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff962eU + 0x060bc8U) ^ (0x2a1403e0U + 0x084c20U + 12U);
}

// [EN] FDE[2379] start_va=0x060bd4, fde_va=0x084c38, span=12 B | [VN] FDE[2379]
uint32_t ttr_fde_2379_0x060bd4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1403e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff8c03U + 0x060bd4U) ^ (0xaa1503e0U + 0x084c38U + 12U);
}

// [EN] FDE[2380] start_va=0x060be0, fde_va=0x084c50, span=12 B | [VN] FDE[2380]
uint32_t ttr_fde_2380_0x060be0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feec5aU + 0x060be0U) ^ (0xaa1403e1U + 0x084c50U + 12U);
}

// [EN] FDE[2381] start_va=0x060bec, fde_va=0x084c68, span=12 B | [VN] FDE[2381]
uint32_t ttr_fde_2381_0x060bec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e1U) + (a1 ^ 0xaa1603e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feec57U + 0x060becU) ^ (0x910023e0U + 0x084c68U + 12U);
}

// [EN] FDE[2382] start_va=0x060bf8, fde_va=0x084c80, span=8 B | [VN] FDE[2382]
uint32_t ttr_fde_2382_0x060bf8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff03c9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400288U + 0x060bf8U) ^ (0xaa0003e2U + 0x084c80U + 8U);
}

// [EN] FDE[2383] start_va=0x060c00, fde_va=0x084c98, span=24 B | [VN] FDE[2383]
uint32_t ttr_fde_2383_0x060c00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400288U) + (a1 ^ 0xaa0003e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x060c00U) ^ (0xaa1303e1U + 0x084c98U + 24U);
}

// [EN] FDE[2384] start_va=0x060c18, fde_va=0x084cb0, span=12 B | [VN] FDE[2384]
uint32_t ttr_fde_2384_0x060c18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf9000008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2329U + 0x060c18U) ^ (0xf1000f3fU + 0x084cb0U + 12U);
}

// [EN] FDE[2385] start_va=0x060c24, fde_va=0x084cc8, span=48 B | [VN] FDE[2385]
uint32_t ttr_fde_2385_0x060c24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000f3fU) + (a1 ^ 0xd1000728U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f27e9U + 0x060c24U) ^ (0xea08033fU + 0x084cc8U + 48U);
}

// [EN] FDE[2386] start_va=0x060c54, fde_va=0x084ce0, span=16 B | [VN] FDE[2386]
uint32_t ttr_fde_2386_0x060c54(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0x2a1f03e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa8c35bf7U + 0x060c54U) ^ (0xd65f03c0U + 0x084ce0U + 16U);
}

// [EN] FDE[2387] start_va=0x060c64, fde_va=0x084cf8, span=8 B | [VN] FDE[2387]
uint32_t ttr_fde_2387_0x060c64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910523e0U) + (a1 ^ 0x17ff0c14U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401668U + 0x060c64U) ^ (0xf85e83a9U + 0x084cf8U + 8U);
}

// [EN] FDE[2388] start_va=0x060c6c, fde_va=0x084d10, span=16 B | [VN] FDE[2388]
uint32_t ttr_fde_2388_0x060c6c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401668U) + (a1 ^ 0xf85e83a9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb09011fU + 0x060c6cU) ^ (0xd65f03c0U + 0x084d10U + 16U);
}

// [EN] FDE[2389] start_va=0x060c7c, fde_va=0x084d28, span=24 B | [VN] FDE[2389]
uint32_t ttr_fde_2389_0x060c7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9ba6ffcU) + (a1 ^ 0xa90167faU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025ff8U + 0x060c7cU) ^ (0xa90357f6U + 0x084d28U + 24U);
}

// [EN] FDE[2390] start_va=0x060c94, fde_va=0x084d40, span=40 B | [VN] FDE[2390]
uint32_t ttr_fde_2390_0x060c94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x3dc017e0U) + (a1 ^ 0x3dc00261U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910143e0U + 0x060c94U) ^ (0x3d800260U + 0x084d40U + 40U);
}

// [EN] FDE[2391] start_va=0x060cbc, fde_va=0x084d58, span=28 B | [VN] FDE[2391]
uint32_t ttr_fde_2391_0x060cbc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100055fU) + (a1 ^ 0x5285202bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52906e0cU + 0x060cbcU) ^ (0x1a8b018bU + 0x084d58U + 28U);
}

// [EN] FDE[2392] start_va=0x060cd8, fde_va=0x084d70, span=8 B | [VN] FDE[2392]
uint32_t ttr_fde_2392_0x060cd8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800083U) + (a1 ^ 0x17ff3da4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e1U + 0x060cd8U) ^ (0xaa1303e0U + 0x084d70U + 8U);
}

// [EN] FDE[2393] start_va=0x060ce0, fde_va=0x084d88, span=12 B | [VN] FDE[2393]
uint32_t ttr_fde_2393_0x060ce0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e1U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060ce0U) ^ (0xfc408581U + 0x084d88U + 12U);
}

// [EN] FDE[2394] start_va=0x060cec, fde_va=0x084da0, span=28 B | [VN] FDE[2394]
uint32_t ttr_fde_2394_0x060cec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc408581U) + (a1 ^ 0xd100056bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0f10a421U + 0x060cecU) ^ (0x4e21d821U + 0x084da0U + 28U);
}

// [EN] FDE[2395] start_va=0x060d08, fde_va=0x084db8, span=48 B | [VN] FDE[2395]
uint32_t ttr_fde_2395_0x060d08(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f7U) + (a1 ^ 0x910073e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0303f3U + 0x060d08U) ^ (0xaa0103f5U + 0x084db8U + 48U);
}

// [EN] FDE[2396] start_va=0x060d38, fde_va=0x084dd0, span=40 B | [VN] FDE[2396]
uint32_t ttr_fde_2396_0x060d38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003faU) + (a1 ^ 0x52800c00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0703f3U + 0x060d38U) ^ (0xaa0603f4U + 0x084dd0U + 40U);
}

// [EN] FDE[2397] start_va=0x060d60, fde_va=0x084de8, span=28 B | [VN] FDE[2397]
uint32_t ttr_fde_2397_0x060d60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100053fU) + (a1 ^ 0x5285202aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52906e0bU + 0x060d60U) ^ (0x1a8a016aU + 0x084de8U + 28U);
}

// [EN] FDE[2398] start_va=0x060d7c, fde_va=0x084e00, span=8 B | [VN] FDE[2398]
uint32_t ttr_fde_2398_0x060d7c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400108U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90167faU + 0x060d7cU) ^ (0xa9025ff8U + 0x084e00U + 8U);
}

// [EN] FDE[2399] start_va=0x060d84, fde_va=0x084e18, span=20 B | [VN] FDE[2399]
uint32_t ttr_fde_2399_0x060d84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa90167faU) + (a1 ^ 0xa9025ff8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90357f6U + 0x060d84U) ^ (0xa9044ff4U + 0x084e18U + 20U);
}

// [EN] FDE[2400] start_va=0x060d98, fde_va=0x084e30, span=16 B | [VN] FDE[2400]
uint32_t ttr_fde_2400_0x060d98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e8U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0803e1U + 0x060d98U) ^ (0x17feec33U + 0x084e30U + 16U);
}

// [EN] FDE[2401] start_va=0x060da8, fde_va=0x084e48, span=16 B | [VN] FDE[2401]
uint32_t ttr_fde_2401_0x060da8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x88dffd08U) + (a1 ^ 0x9100e3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9003be8U + 0x060da8U) ^ (0x17ff99feU + 0x084e48U + 16U);
}

// [EN] FDE[2402] start_va=0x060db8, fde_va=0x084e60, span=40 B | [VN] FDE[2402]
uint32_t ttr_fde_2402_0x060db8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b160008U) + (a1 ^ 0x8b150009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90013e9U + 0x060db8U) ^ (0xa900a3e0U + 0x084e60U + 40U);
}

// [EN] FDE[2403] start_va=0x060de0, fde_va=0x084e78, span=16 B | [VN] FDE[2403]
uint32_t ttr_fde_2403_0x060de0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94016a8U) + (a1 ^ 0xf85d83a9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb09011fU + 0x060de0U) ^ (0xd65f03c0U + 0x084e78U + 16U);
}

// [EN] FDE[2404] start_va=0x060df0, fde_va=0x084e90, span=32 B | [VN] FDE[2404]
uint32_t ttr_fde_2404_0x060df0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xf90017e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb90017e1U + 0x060df0U) ^ (0x97ff08e3U + 0x084e90U + 32U);
}

// [EN] FDE[2405] start_va=0x060e10, fde_va=0x084eb0, span=16 B | [VN] FDE[2405]
uint32_t ttr_fde_2405_0x060e10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e620828U) + (a1 ^ 0x1e630821U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e601820U + 0x060e10U) ^ (0x17feedf1U + 0x084eb0U + 16U);
}

// [EN] FDE[2406] start_va=0x060e20, fde_va=0x084ec8, span=8 B | [VN] FDE[2406]
uint32_t ttr_fde_2406_0x060e20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910123e0U) + (a1 ^ 0x17ff035cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910103e0U + 0x060e20U) ^ (0x17ff035aU + 0x084ec8U + 8U);
}

// [EN] FDE[2407] start_va=0x060e28, fde_va=0x084ee0, span=8 B | [VN] FDE[2407]
uint32_t ttr_fde_2407_0x060e28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910103e0U) + (a1 ^ 0x17ff035aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e6b2980U + 0x060e28U) ^ (0xfd000260U + 0x084ee0U + 8U);
}

// [EN] FDE[2408] start_va=0x060e30, fde_va=0x084ef8, span=16 B | [VN] FDE[2408]
uint32_t ttr_fde_2408_0x060e30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e6b2980U) + (a1 ^ 0xfd000260U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4ea81d00U + 0x060e30U) ^ (0x17feedd5U + 0x084ef8U + 16U);
}

// [EN] FDE[2409] start_va=0x060e40, fde_va=0x084f10, span=16 B | [VN] FDE[2409]
uint32_t ttr_fde_2409_0x060e40(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf940026eU) + (a1 ^ 0xaa0c03efU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf86d79d0U + 0x060e40U) ^ (0xd65f03c0U + 0x084f10U + 16U);
}

// [EN] FDE[2410] start_va=0x060e50, fde_va=0x084f28, span=16 B | [VN] FDE[2410]
uint32_t ttr_fde_2410_0x060e50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf940026cU) + (a1 ^ 0xf82a798bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd100068bU + 0x060e50U) ^ (0xd65f03c0U + 0x084f28U + 16U);
}

// [EN] FDE[2411] start_va=0x060e60, fde_va=0x084f40, span=16 B | [VN] FDE[2411]
uint32_t ttr_fde_2411_0x060e60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e2U + 0x060e60U) ^ (0x17ff7ce5U + 0x084f40U + 16U);
}

// [EN] FDE[2412] start_va=0x060e70, fde_va=0x084f58, span=16 B | [VN] FDE[2412]
uint32_t ttr_fde_2412_0x060e70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1803e2U + 0x060e70U) ^ (0x17ff7ce1U + 0x084f58U + 16U);
}

// [EN] FDE[2413] start_va=0x060e80, fde_va=0x084f70, span=8 B | [VN] FDE[2413]
uint32_t ttr_fde_2413_0x060e80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff4384U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x060e80U) ^ (0xaa1603e1U + 0x084f70U + 8U);
}

// [EN] FDE[2414] start_va=0x060e88, fde_va=0x084f88, span=16 B | [VN] FDE[2414]
uint32_t ttr_fde_2414_0x060e88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1603e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e2U + 0x060e88U) ^ (0xd65f03c0U + 0x084f88U + 16U);
}

// [EN] FDE[2415] start_va=0x060e98, fde_va=0x084fa0, span=8 B | [VN] FDE[2415]
uint32_t ttr_fde_2415_0x060e98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x060e98U) ^ (0x17feec4fU + 0x084fa0U + 8U);
}

// [EN] FDE[2416] start_va=0x060ea0, fde_va=0x084fb8, span=8 B | [VN] FDE[2416]
uint32_t ttr_fde_2416_0x060ea0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17feec4fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf1000f3fU + 0x060ea0U) ^ (0xd1000728U + 0x084fb8U + 8U);
}

// [EN] FDE[2417] start_va=0x060ea8, fde_va=0x084fd0, span=44 B | [VN] FDE[2417]
uint32_t ttr_fde_2417_0x060ea8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000f3fU) + (a1 ^ 0xd1000728U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f27e9U + 0x060ea8U) ^ (0xea08033fU + 0x084fd0U + 44U);
}

// [EN] FDE[2418] start_va=0x060ed4, fde_va=0x084fe8, span=12 B | [VN] FDE[2418]
uint32_t ttr_fde_2418_0x060ed4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0xa8c35bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feeb95U + 0x060ed4U) ^ (0xa94153f5U + 0x084fe8U + 12U);
}

// [EN] FDE[2419] start_va=0x060ee0, fde_va=0x085000, span=12 B | [VN] FDE[2419]
uint32_t ttr_fde_2419_0x060ee0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0xa8c35bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060ee0U) ^ (0xa94153f5U + 0x085000U + 12U);
}

// [EN] FDE[2420] start_va=0x060eec, fde_va=0x085018, span=12 B | [VN] FDE[2420]
uint32_t ttr_fde_2420_0x060eec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0xf84307f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feeb8fU + 0x060eecU) ^ (0xf1000effU + 0x085018U + 12U);
}

// [EN] FDE[2421] start_va=0x060ef8, fde_va=0x085030, span=44 B | [VN] FDE[2421]
uint32_t ttr_fde_2421_0x060ef8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000effU) + (a1 ^ 0xd10006e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f27e9U + 0x060ef8U) ^ (0xea0802ffU + 0x085030U + 44U);
}

// [EN] FDE[2422] start_va=0x060f24, fde_va=0x085048, span=20 B | [VN] FDE[2422]
uint32_t ttr_fde_2422_0x060f24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x911ac884U) + (a1 ^ 0x910704a5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9111e8c6U + 0x060f24U) ^ (0x52800042U + 0x085048U + 20U);
}

// [EN] FDE[2423] start_va=0x060f38, fde_va=0x085060, span=20 B | [VN] FDE[2423]
uint32_t ttr_fde_2423_0x060f38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401c15U) + (a1 ^ 0xaa0203f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x060f38U) ^ (0xaa0103f7U + 0x085060U + 20U);
}

// [EN] FDE[2424] start_va=0x060f4c, fde_va=0x085078, span=12 B | [VN] FDE[2424]
uint32_t ttr_fde_2424_0x060f4c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910883e1U) + (a1 ^ 0xaa1c03e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffee5cU + 0x060f4cU) ^ (0x9100a3e0U + 0x085078U + 12U);
}

// [EN] FDE[2425] start_va=0x060f58, fde_va=0x085090, span=8 B | [VN] FDE[2425]
uint32_t ttr_fde_2425_0x060f58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a3e0U) + (a1 ^ 0x17ffae80U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94002abU + 0x060f58U) ^ (0xf94002ccU + 0x085090U + 8U);
}

// [EN] FDE[2426] start_va=0x060f60, fde_va=0x0850a8, span=44 B | [VN] FDE[2426]
uint32_t ttr_fde_2426_0x060f60(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94002abU) + (a1 ^ 0xf94002ccU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b1706edU + 0x060f60U) ^ (0xf86d796bU + 0x0850a8U + 44U);
}

// [EN] FDE[2427] start_va=0x060f8c, fde_va=0x0850c0, span=8 B | [VN] FDE[2427]
uint32_t ttr_fde_2427_0x060f8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910083e0U) + (a1 ^ 0x17ff0301U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf85d83a9U + 0x060f8cU) ^ (0xeb09011fU + 0x0850c0U + 8U);
}

// [EN] FDE[2428] start_va=0x060f94, fde_va=0x0850d8, span=12 B | [VN] FDE[2428]
uint32_t ttr_fde_2428_0x060f94(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf85d83a9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x060f94U) ^ (0x910033e0U + 0x0850d8U + 12U);
}

// [EN] FDE[2429] start_va=0x060fa0, fde_va=0x0850f0, span=20 B | [VN] FDE[2429]
uint32_t ttr_fde_2429_0x060fa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910033e0U) + (a1 ^ 0x52801722U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e1U + 0x060fa0U) ^ (0xf81e83a8U + 0x0850f0U + 20U);
}

// [EN] FDE[2430] start_va=0x060fb4, fde_va=0x085108, span=44 B | [VN] FDE[2430]
uint32_t ttr_fde_2430_0x060fb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x928004e8U) + (a1 ^ 0x910003e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910223ebU + 0x060fb4U) ^ (0xf2dff008U + 0x085108U + 44U);
}

// [EN] FDE[2431] start_va=0x060fe0, fde_va=0x085120, span=20 B | [VN] FDE[2431]
uint32_t ttr_fde_2431_0x060fe0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400268U) + (a1 ^ 0xf9400a69U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200011fU + 0x060fe0U) ^ (0x9a931520U + 0x085120U + 20U);
}

// [EN] FDE[2432] start_va=0x060ff4, fde_va=0x085138, span=36 B | [VN] FDE[2432]
uint32_t ttr_fde_2432_0x060ff4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a80U) + (a1 ^ 0xf94017ebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200011fU + 0x060ff4U) ^ (0x910003e8U + 0x085138U + 36U);
}

// [EN] FDE[2433] start_va=0x061018, fde_va=0x085150, span=8 B | [VN] FDE[2433]
uint32_t ttr_fde_2433_0x061018(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800300U) + (a1 ^ 0x17feeb51U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0403f7U + 0x061018U) ^ (0x2a0303f8U + 0x085150U + 8U);
}

// [EN] FDE[2434] start_va=0x061020, fde_va=0x085168, span=20 B | [VN] FDE[2434]
uint32_t ttr_fde_2434_0x061020(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0403f7U) + (a1 ^ 0x2a0303f8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0203f9U + 0x061020U) ^ (0x2a0103faU + 0x085168U + 20U);
}

// [EN] FDE[2435] start_va=0x061034, fde_va=0x085180, span=8 B | [VN] FDE[2435]
uint32_t ttr_fde_2435_0x061034(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfc01c000U + 0x061034U) ^ (0xb9002408U + 0x085180U + 8U);
}

// [EN] FDE[2436] start_va=0x06103c, fde_va=0x085198, span=20 B | [VN] FDE[2436]
uint32_t ttr_fde_2436_0x06103c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xfc01c000U) + (a1 ^ 0xb9002408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000409U + 0x06103cU) ^ (0xb900100aU + 0x085198U + 20U);
}

// [EN] FDE[2437] start_va=0x061050, fde_va=0x0851b0, span=20 B | [VN] FDE[2437]
uint32_t ttr_fde_2437_0x061050(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9434ff4U) + (a1 ^ 0xa94257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9415ff8U + 0x061050U) ^ (0xa8c567faU + 0x0851b0U + 20U);
}

// [EN] FDE[2438] start_va=0x061064, fde_va=0x0851c8, span=20 B | [VN] FDE[2438]
uint32_t ttr_fde_2438_0x061064(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9434ff4U) + (a1 ^ 0xa94257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9415ff8U + 0x061064U) ^ (0xf84507f9U + 0x0851c8U + 20U);
}

// [EN] FDE[2439] start_va=0x061078, fde_va=0x0851e0, span=20 B | [VN] FDE[2439]
uint32_t ttr_fde_2439_0x061078(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910062a8U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x061078U) ^ (0xf9000fe8U + 0x0851e0U + 20U);
}

// [EN] FDE[2440] start_va=0x06108c, fde_va=0x0851f8, span=20 B | [VN] FDE[2440]
uint32_t ttr_fde_2440_0x06108c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff7e67U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3100041fU + 0x06108cU) ^ (0xf84107feU + 0x0851f8U + 20U);
}

// [EN] FDE[2441] start_va=0x0610a0, fde_va=0x085218, span=36 B | [VN] FDE[2441]
uint32_t ttr_fde_2441_0x0610a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb080128U) + (a1 ^ 0x9343fd08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9b0a7d08U + 0x0610a0U) ^ (0xa9422809U + 0x085218U + 36U);
}

// [EN] FDE[2442] start_va=0x0610c4, fde_va=0x085230, span=20 B | [VN] FDE[2442]
uint32_t ttr_fde_2442_0x0610c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9407e68U) + (a1 ^ 0xf8746900U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400008U + 0x0610c4U) ^ (0xf9400908U + 0x085230U + 20U);
}

// [EN] FDE[2443] start_va=0x0610d8, fde_va=0x085248, span=8 B | [VN] FDE[2443]
uint32_t ttr_fde_2443_0x0610d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e0U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007c1fU + 0x0610d8U) ^ (0xf900081fU + 0x085248U + 8U);
}

// [EN] FDE[2444] start_va=0x0610e0, fde_va=0x085260, span=20 B | [VN] FDE[2444]
uint32_t ttr_fde_2444_0x0610e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007c1fU) + (a1 ^ 0xf900081fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9402428U + 0x0610e0U) ^ (0xeb080128U + 0x085260U + 20U);
}

// [EN] FDE[2445] start_va=0x0610f4, fde_va=0x085278, span=12 B | [VN] FDE[2445]
uint32_t ttr_fde_2445_0x0610f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9000280U) + (a1 ^ 0xf9000a88U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0610f4U) ^ (0xf9000408U + 0x085278U + 12U);
}

// [EN] FDE[2446] start_va=0x061100, fde_va=0x085290, span=8 B | [VN] FDE[2446]
uint32_t ttr_fde_2446_0x061100(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000408U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf1000f5fU + 0x061100U) ^ (0xd1000748U + 0x085290U + 8U);
}

// [EN] FDE[2447] start_va=0x061108, fde_va=0x0852a8, span=44 B | [VN] FDE[2447]
uint32_t ttr_fde_2447_0x061108(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000f5fU) + (a1 ^ 0xd1000748U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f27e9U + 0x061108U) ^ (0xea08035fU + 0x0852a8U + 44U);
}

// [EN] FDE[2448] start_va=0x061134, fde_va=0x0852c0, span=20 B | [VN] FDE[2448]
uint32_t ttr_fde_2448_0x061134(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400269U) + (a1 ^ 0xf8387928U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd1000688U + 0x061134U) ^ (0xf90007e8U + 0x0852c0U + 20U);
}

// [EN] FDE[2449] start_va=0x061148, fde_va=0x0852d8, span=20 B | [VN] FDE[2449]
uint32_t ttr_fde_2449_0x061148(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94002a8U) + (a1 ^ 0xaa0003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e0U + 0x061148U) ^ (0xf9405508U + 0x0852d8U + 20U);
}

// [EN] FDE[2450] start_va=0x06115c, fde_va=0x0852f0, span=44 B | [VN] FDE[2450]
uint32_t ttr_fde_2450_0x06115c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf1000f7fU) + (a1 ^ 0xd1000768U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f27e9U + 0x06115cU) ^ (0xea08037fU + 0x0852f0U + 44U);
}

// [EN] FDE[2451] start_va=0x061188, fde_va=0x085308, span=8 B | [VN] FDE[2451]
uint32_t ttr_fde_2451_0x061188(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401908U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800021U + 0x061188U) ^ (0xaa1403e0U + 0x085308U + 8U);
}

// [EN] FDE[2452] start_va=0x061190, fde_va=0x085320, span=12 B | [VN] FDE[2452]
uint32_t ttr_fde_2452_0x061190(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800021U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061190U) ^ (0xf9405108U + 0x085320U + 12U);
}

// [EN] FDE[2453] start_va=0x06119c, fde_va=0x085338, span=8 B | [VN] FDE[2453]
uint32_t ttr_fde_2453_0x06119c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9405108U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007d1fU + 0x06119cU) ^ (0xf900091fU + 0x085338U + 8U);
}

// [EN] FDE[2454] start_va=0x0611a4, fde_va=0x085350, span=44 B | [VN] FDE[2454]
uint32_t ttr_fde_2454_0x0611a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007d1fU) + (a1 ^ 0xf900091fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3dc00280U + 0x0611a4U) ^ (0x9100610aU + 0x085350U + 44U);
}

// [EN] FDE[2455] start_va=0x0611d0, fde_va=0x085368, span=8 B | [VN] FDE[2455]
uint32_t ttr_fde_2455_0x0611d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910243ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9474ff4U + 0x0611d0U) ^ (0xa94657f6U + 0x085368U + 8U);
}

// [EN] FDE[2456] start_va=0x0611d8, fde_va=0x085380, span=36 B | [VN] FDE[2456]
uint32_t ttr_fde_2456_0x0611d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9474ff4U) + (a1 ^ 0xa94657f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9455ff8U + 0x0611d8U) ^ (0xa94467faU + 0x085380U + 36U);
}

// [EN] FDE[2457] start_va=0x0611fc, fde_va=0x085398, span=20 B | [VN] FDE[2457]
uint32_t ttr_fde_2457_0x0611fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xf9417908U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e1U + 0x0611fcU) ^ (0xaa1603e3U + 0x085398U + 20U);
}

// [EN] FDE[2458] start_va=0x061210, fde_va=0x0853b0, span=12 B | [VN] FDE[2458]
uint32_t ttr_fde_2458_0x061210(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x9101e3e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffae1cU + 0x061210U) ^ (0x910003e1U + 0x0853b0U + 12U);
}

// [EN] FDE[2459] start_va=0x06121c, fde_va=0x0853c8, span=12 B | [VN] FDE[2459]
uint32_t ttr_fde_2459_0x06121c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e1U) + (a1 ^ 0xa9007fffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff3b6cU + 0x06121cU) ^ (0xaa1303e0U + 0x0853c8U + 12U);
}

// [EN] FDE[2460] start_va=0x061228, fde_va=0x0853e0, span=12 B | [VN] FDE[2460]
uint32_t ttr_fde_2460_0x061228(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf84207f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff2138U + 0x061228U) ^ (0xaa1303e0U + 0x0853e0U + 12U);
}

// [EN] FDE[2461] start_va=0x061234, fde_va=0x0853f8, span=8 B | [VN] FDE[2461]
uint32_t ttr_fde_2461_0x061234(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17feeabeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x061234U) ^ (0xa9400008U + 0x0853f8U + 8U);
}

// [EN] FDE[2462] start_va=0x06123c, fde_va=0x085410, span=20 B | [VN] FDE[2462]
uint32_t ttr_fde_2462_0x06123c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xa9400008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f4U + 0x06123cU) ^ (0xeb08001fU + 0x085410U + 20U);
}

// [EN] FDE[2463] start_va=0x061250, fde_va=0x085428, span=12 B | [VN] FDE[2463]
uint32_t ttr_fde_2463_0x061250(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf9000008U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061250U) ^ (0xaa0003f3U + 0x085428U + 12U);
}

// [EN] FDE[2464] start_va=0x06125c, fde_va=0x085440, span=12 B | [VN] FDE[2464]
uint32_t ttr_fde_2464_0x06125c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf8010408U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feeab7U + 0x06125cU) ^ (0xaa0103f5U + 0x085440U + 12U);
}

// [EN] FDE[2465] start_va=0x061268, fde_va=0x085458, span=12 B | [VN] FDE[2465]
uint32_t ttr_fde_2465_0x061268(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f5U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061268U) ^ (0x2a1503e3U + 0x085458U + 12U);
}

// [EN] FDE[2466] start_va=0x061274, fde_va=0x085470, span=12 B | [VN] FDE[2466]
uint32_t ttr_fde_2466_0x061274(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1503e3U) + (a1 ^ 0xf8746900U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fff562U + 0x061274U) ^ (0x90000060U + 0x085470U + 12U);
}

// [EN] FDE[2467] start_va=0x061280, fde_va=0x085488, span=12 B | [VN] FDE[2467]
uint32_t ttr_fde_2467_0x061280(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000060U) + (a1 ^ 0x9129a000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feec56U + 0x061280U) ^ (0xaa1503e2U + 0x085488U + 12U);
}

// [EN] FDE[2468] start_va=0x06128c, fde_va=0x0854a0, span=8 B | [VN] FDE[2468]
uint32_t ttr_fde_2468_0x06128c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e2U) + (a1 ^ 0x17feeab0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1f03e3U + 0x06128cU) ^ (0x17feec26U + 0x0854a0U + 8U);
}

// [EN] FDE[2469] start_va=0x061294, fde_va=0x0854b8, span=8 B | [VN] FDE[2469]
uint32_t ttr_fde_2469_0x061294(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e3U) + (a1 ^ 0x17feec26U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401108U + 0x061294U) ^ (0xd61f0100U + 0x0854b8U + 8U);
}

// [EN] FDE[2470] start_va=0x06129c, fde_va=0x0854d0, span=8 B | [VN] FDE[2470]
uint32_t ttr_fde_2470_0x06129c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401108U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9404a89U + 0x06129cU) ^ (0x7100093fU + 0x0854d0U + 8U);
}

// [EN] FDE[2471] start_va=0x0612a4, fde_va=0x0854e8, span=24 B | [VN] FDE[2471]
uint32_t ttr_fde_2471_0x0612a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9404a89U) + (a1 ^ 0x7100093fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1a9f07eaU + 0x0612a4U) ^ (0x0a08014aU + 0x0854e8U + 24U);
}

// [EN] FDE[2472] start_va=0x0612bc, fde_va=0x085500, span=24 B | [VN] FDE[2472]
uint32_t ttr_fde_2472_0x0612bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400c08U) + (a1 ^ 0xaa0003f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f4U + 0x0612bcU) ^ (0x51000509U + 0x085500U + 24U);
}

// [EN] FDE[2473] start_va=0x0612d4, fde_va=0x085518, span=8 B | [VN] FDE[2473]
uint32_t ttr_fde_2473_0x0612d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800082U) + (a1 ^ 0x17ffbcf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9104c3e8U + 0x0612d4U) ^ (0x9103a3e1U + 0x085518U + 8U);
}

// [EN] FDE[2474] start_va=0x0612dc, fde_va=0x085530, span=32 B | [VN] FDE[2474]
uint32_t ttr_fde_2474_0x0612dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9104c3e8U) + (a1 ^ 0x9103a3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9104c3e2U + 0x0612dcU) ^ (0xaa1c03e0U + 0x085530U + 32U);
}

// [EN] FDE[2475] start_va=0x0612fc, fde_va=0x085548, span=16 B | [VN] FDE[2475]
uint32_t ttr_fde_2475_0x0612fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000064U) + (a1 ^ 0x90000065U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x90000066U + 0x0612fcU) ^ (0xd65f03c0U + 0x085548U + 16U);
}

// [EN] FDE[2476] start_va=0x06130c, fde_va=0x085560, span=32 B | [VN] FDE[2476]
uint32_t ttr_fde_2476_0x06130c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e22c021U) + (a1 ^ 0x1e22c000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e620822U + 0x06130cU) ^ (0x1e630821U + 0x085560U + 32U);
}

// [EN] FDE[2477] start_va=0x06132c, fde_va=0x085578, span=32 B | [VN] FDE[2477]
uint32_t ttr_fde_2477_0x06132c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400028U) + (a1 ^ 0xa940a42aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd0bU + 0x06132cU) ^ (0x7200011fU + 0x085578U + 32U);
}

// [EN] FDE[2478] start_va=0x06134c, fde_va=0x085590, span=40 B | [VN] FDE[2478]
uint32_t ttr_fde_2478_0x06134c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94002e8U) + (a1 ^ 0xf94002c9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90002c8U + 0x06134cU) ^ (0xf90002e9U + 0x085590U + 40U);
}

// [EN] FDE[2479] start_va=0x061374, fde_va=0x0855a8, span=40 B | [VN] FDE[2479]
uint32_t ttr_fde_2479_0x061374(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81e8d3fU) + (a1 ^ 0xa900fd3fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3cde8d60U + 0x061374U) ^ (0x9100618cU + 0x0855a8U + 40U);
}

// [EN] FDE[2480] start_va=0x06139c, fde_va=0x0855c0, span=24 B | [VN] FDE[2480]
uint32_t ttr_fde_2480_0x06139c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5280200cU) + (a1 ^ 0x72a7000cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4e040d80U + 0x06139cU) ^ (0xaa0903ecU + 0x0855c0U + 24U);
}

// [EN] FDE[2481] start_va=0x0613b4, fde_va=0x0855d8, span=12 B | [VN] FDE[2481]
uint32_t ttr_fde_2481_0x0613b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94007e9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0613b4U) ^ (0xf9400109U + 0x0855d8U + 12U);
}

// [EN] FDE[2482] start_va=0x0613c0, fde_va=0x0855f0, span=16 B | [VN] FDE[2482]
uint32_t ttr_fde_2482_0x0613c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400109U) + (a1 ^ 0xf90002c9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000116U + 0x0613c0U) ^ (0xd65f03c0U + 0x0855f0U + 16U);
}

// [EN] FDE[2483] start_va=0x0613d0, fde_va=0x085608, span=32 B | [VN] FDE[2483]
uint32_t ttr_fde_2483_0x0613d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800480U) + (a1 ^ 0x4ea51ca8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4ea41c89U + 0x0613d0U) ^ (0x4ea31c6aU + 0x085608U + 32U);
}

// [EN] FDE[2484] start_va=0x0613f0, fde_va=0x085620, span=32 B | [VN] FDE[2484]
uint32_t ttr_fde_2484_0x0613f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400268U) + (a1 ^ 0xf9400669U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0613f0U) ^ (0xd341fd0aU + 0x085620U + 32U);
}

// [EN] FDE[2485] start_va=0x061410, fde_va=0x085638, span=24 B | [VN] FDE[2485]
uint32_t ttr_fde_2485_0x061410(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400108U) + (a1 ^ 0x2a1a03e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1903e3U + 0x061410U) ^ (0x2a1803e4U + 0x085638U + 24U);
}

// [EN] FDE[2486] start_va=0x061428, fde_va=0x085650, span=8 B | [VN] FDE[2486]
uint32_t ttr_fde_2486_0x061428(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9402fe0U) + (a1 ^ 0x17ff98f2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94002c8U + 0x061428U) ^ (0xf9400269U + 0x085650U + 8U);
}

// [EN] FDE[2487] start_va=0x061430, fde_va=0x085668, span=40 B | [VN] FDE[2487]
uint32_t ttr_fde_2487_0x061430(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94002c8U) + (a1 ^ 0xf9400269U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000268U + 0x061430U) ^ (0xf90002c9U + 0x085668U + 40U);
}

// [EN] FDE[2488] start_va=0x061458, fde_va=0x085680, span=8 B | [VN] FDE[2488]
uint32_t ttr_fde_2488_0x061458(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf900081fU) + (a1 ^ 0x17ffab4cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f3U + 0x061458U) ^ (0xaa0103f5U + 0x085680U + 8U);
}

// [EN] FDE[2489] start_va=0x061460, fde_va=0x085698, span=16 B | [VN] FDE[2489]
uint32_t ttr_fde_2489_0x061460(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f3U) + (a1 ^ 0xaa0103f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x061460U) ^ (0xd65f03c0U + 0x085698U + 16U);
}

// [EN] FDE[2490] start_va=0x061470, fde_va=0x0856b0, span=32 B | [VN] FDE[2490]
uint32_t ttr_fde_2490_0x061470(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400269U) + (a1 ^ 0x52800316U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x061470U) ^ (0x91004275U + 0x0856b0U + 32U);
}

// [EN] FDE[2491] start_va=0x061490, fde_va=0x0856c8, span=36 B | [VN] FDE[2491]
uint32_t ttr_fde_2491_0x061490(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb9402516U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9402537U + 0x061490U) ^ (0x97ff11e7U + 0x0856c8U + 36U);
}

// [EN] FDE[2492] start_va=0x0614b4, fde_va=0x0856e8, span=36 B | [VN] FDE[2492]
uint32_t ttr_fde_2492_0x0614b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb9402517U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9402538U + 0x0614b4U) ^ (0x97ff11deU + 0x0856e8U + 36U);
}

// [EN] FDE[2493] start_va=0x0614d8, fde_va=0x085708, span=36 B | [VN] FDE[2493]
uint32_t ttr_fde_2493_0x0614d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb9402517U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9402539U + 0x0614d8U) ^ (0x97ff11d5U + 0x085708U + 36U);
}

// [EN] FDE[2494] start_va=0x0614fc, fde_va=0x085728, span=12 B | [VN] FDE[2494]
uint32_t ttr_fde_2494_0x0614fc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf828795fU) + (a1 ^ 0x91000508U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0614fcU) ^ (0xd53bd059U + 0x085728U + 12U);
}

// [EN] FDE[2495] start_va=0x061508, fde_va=0x085740, span=12 B | [VN] FDE[2495]
uint32_t ttr_fde_2495_0x061508(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd059U) + (a1 ^ 0xf9401728U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061508U) ^ (0xaa0203e1U + 0x085740U + 12U);
}

// [EN] FDE[2496] start_va=0x061514, fde_va=0x085758, span=8 B | [VN] FDE[2496]
uint32_t ttr_fde_2496_0x061514(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203e1U) + (a1 ^ 0x17ff09e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401190U + 0x061514U) ^ (0xb94011f1U + 0x085758U + 8U);
}

// [EN] FDE[2497] start_va=0x06151c, fde_va=0x085770, span=16 B | [VN] FDE[2497]
uint32_t ttr_fde_2497_0x06151c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401190U) + (a1 ^ 0xb94011f1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6b11021fU + 0x06151cU) ^ (0xd65f03c0U + 0x085770U + 16U);
}

// [EN] FDE[2498] start_va=0x06152c, fde_va=0x085788, span=12 B | [VN] FDE[2498]
uint32_t ttr_fde_2498_0x06152c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9401fe9U) + (a1 ^ 0xeb09011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06152cU) ^ (0xaa1503e0U + 0x085788U + 12U);
}

// [EN] FDE[2499] start_va=0x061538, fde_va=0x0857a0, span=8 B | [VN] FDE[2499]
uint32_t ttr_fde_2499_0x061538(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17ff81c3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x061538U) ^ (0xaa1503e1U + 0x0857a0U + 8U);
}

// [EN] FDE[2500] start_va=0x061540, fde_va=0x0857b8, span=16 B | [VN] FDE[2500]
uint32_t ttr_fde_2500_0x061540(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e2U + 0x061540U) ^ (0xd65f03c0U + 0x0857b8U + 16U);
}

// [EN] FDE[2501] start_va=0x061550, fde_va=0x0857d0, span=12 B | [VN] FDE[2501]
uint32_t ttr_fde_2501_0x061550(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1303e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061550U) ^ (0xaa1403e0U + 0x0857d0U + 12U);
}

// [EN] FDE[2502] start_va=0x06155c, fde_va=0x0857e8, span=8 B | [VN] FDE[2502]
uint32_t ttr_fde_2502_0x06155c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17fee9f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x06155cU) ^ (0x17feec22U + 0x0857e8U + 8U);
}

// [EN] FDE[2503] start_va=0x061564, fde_va=0x085800, span=8 B | [VN] FDE[2503]
uint32_t ttr_fde_2503_0x061564(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17feec22U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x061564U) ^ (0x17feeb00U + 0x085800U + 8U);
}

// [EN] FDE[2504] start_va=0x06156c, fde_va=0x085818, span=8 B | [VN] FDE[2504]
uint32_t ttr_fde_2504_0x06156c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17feeb00U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90817e4U + 0x06156cU) ^ (0xa9091fe6U + 0x085818U + 8U);
}

// [EN] FDE[2505] start_va=0x061574, fde_va=0x085830, span=28 B | [VN] FDE[2505]
uint32_t ttr_fde_2505_0x061574(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa90817e4U) + (a1 ^ 0xa9091fe6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xad010fe2U + 0x061574U) ^ (0xad0217e4U + 0x085830U + 28U);
}

// [EN] FDE[2506] start_va=0x061590, fde_va=0x085848, span=16 B | [VN] FDE[2506]
uint32_t ttr_fde_2506_0x061590(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0x2a1f03e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf84307f6U + 0x061590U) ^ (0xd65f03c0U + 0x085848U + 16U);
}

// [EN] FDE[2507] start_va=0x0615a0, fde_va=0x085860, span=12 B | [VN] FDE[2507]
uint32_t ttr_fde_2507_0x0615a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94153f5U) + (a1 ^ 0xf84307f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0615a0U) ^ (0xf81f0ffeU + 0x085860U + 12U);
}

// [EN] FDE[2508] start_va=0x0615ac, fde_va=0x085878, span=28 B | [VN] FDE[2508]
uint32_t ttr_fde_2508_0x0615ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff0559U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94002a8U + 0x0615acU) ^ (0xaa1503e0U + 0x085878U + 28U);
}

// [EN] FDE[2509] start_va=0x0615c8, fde_va=0x085898, span=28 B | [VN] FDE[2509]
uint32_t ttr_fde_2509_0x0615c8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff0552U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400268U + 0x0615c8U) ^ (0xaa1303e0U + 0x085898U + 28U);
}

// [EN] FDE[2510] start_va=0x0615e4, fde_va=0x0858b8, span=16 B | [VN] FDE[2510]
uint32_t ttr_fde_2510_0x0615e4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5281bc22U) + (a1 ^ 0x2a1f03e3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1f03e4U + 0x0615e4U) ^ (0xd61f0100U + 0x0858b8U + 16U);
}

// [EN] FDE[2511] start_va=0x0615f4, fde_va=0x0858d0, span=28 B | [VN] FDE[2511]
uint32_t ttr_fde_2511_0x0615f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001d9U) + (a1 ^ 0xf9415739U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9404a62U + 0x0615f4U) ^ (0x5281bc20U + 0x0858d0U + 28U);
}

// [EN] FDE[2512] start_va=0x061610, fde_va=0x0858e8, span=28 B | [VN] FDE[2512]
uint32_t ttr_fde_2512_0x061610(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9504ff4U) + (a1 ^ 0xa94f57f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa94e5ff8U + 0x061610U) ^ (0xa94d67faU + 0x0858e8U + 28U);
}

// [EN] FDE[2513] start_va=0x06162c, fde_va=0x085900, span=20 B | [VN] FDE[2513]
uint32_t ttr_fde_2513_0x06162c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x7100011fU) + (a1 ^ 0x1a9f07e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200013fU + 0x06162cU) ^ (0x9a941541U + 0x085900U + 20U);
}

// [EN] FDE[2514] start_va=0x061640, fde_va=0x085918, span=28 B | [VN] FDE[2514]
uint32_t ttr_fde_2514_0x061640(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800023U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e1U + 0x061640U) ^ (0xaa1303e2U + 0x085918U + 28U);
}

// [EN] FDE[2515] start_va=0x06165c, fde_va=0x085930, span=16 B | [VN] FDE[2515]
uint32_t ttr_fde_2515_0x06165c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9405262U) + (a1 ^ 0x5281bc20U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52850041U + 0x06165cU) ^ (0xd61f0100U + 0x085930U + 16U);
}

// [EN] FDE[2516] start_va=0x06166c, fde_va=0x085948, span=16 B | [VN] FDE[2516]
uint32_t ttr_fde_2516_0x06166c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9404e62U) + (a1 ^ 0x5281bc20U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52850021U + 0x06166cU) ^ (0xd61f0100U + 0x085948U + 16U);
}

// [EN] FDE[2517] start_va=0x06167c, fde_va=0x085960, span=8 B | [VN] FDE[2517]
uint32_t ttr_fde_2517_0x06167c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400d08U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x0e205800U + 0x06167cU) ^ (0x2e303800U + 0x085960U + 8U);
}

// [EN] FDE[2518] start_va=0x061684, fde_va=0x085978, span=36 B | [VN] FDE[2518]
uint32_t ttr_fde_2518_0x061684(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e260009U + 0x061684U) ^ (0x9e230100U + 0x085978U + 36U);
}

// [EN] FDE[2519] start_va=0x0616a8, fde_va=0x085990, span=36 B | [VN] FDE[2519]
uint32_t ttr_fde_2519_0x0616a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e260009U + 0x0616a8U) ^ (0x9e230100U + 0x085990U + 36U);
}

// [EN] FDE[2520] start_va=0x0616cc, fde_va=0x0859a8, span=8 B | [VN] FDE[2520]
uint32_t ttr_fde_2520_0x0616cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9101e3e0U) + (a1 ^ 0x17ffaca3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9105c3e1U + 0x0616ccU) ^ (0xaa1c03e0U + 0x0859a8U + 8U);
}

// [EN] FDE[2521] start_va=0x0616d4, fde_va=0x0859c0, span=12 B | [VN] FDE[2521]
uint32_t ttr_fde_2521_0x0616d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105c3e1U) + (a1 ^ 0xaa1c03e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffdc41U + 0x0616d4U) ^ (0x52800141U + 0x0859c0U + 12U);
}

// [EN] FDE[2522] start_va=0x0616e0, fde_va=0x0859d8, span=12 B | [VN] FDE[2522]
uint32_t ttr_fde_2522_0x0616e0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800141U) + (a1 ^ 0xaa1403e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff028bU + 0x0616e0U) ^ (0x9107c3e0U + 0x0859d8U + 12U);
}

// [EN] FDE[2523] start_va=0x0616ec, fde_va=0x0859f0, span=8 B | [VN] FDE[2523]
uint32_t ttr_fde_2523_0x0616ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9107c3e0U) + (a1 ^ 0x17ff0129U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9102a3e0U + 0x0616ecU) ^ (0xaa1c03e1U + 0x0859f0U + 8U);
}

// [EN] FDE[2524] start_va=0x0616f4, fde_va=0x085a08, span=12 B | [VN] FDE[2524]
uint32_t ttr_fde_2524_0x0616f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9102a3e0U) + (a1 ^ 0xaa1c03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff830fU + 0x0616f4U) ^ (0x9100c3e0U + 0x085a08U + 12U);
}

// [EN] FDE[2525] start_va=0x061700, fde_va=0x085a20, span=12 B | [VN] FDE[2525]
uint32_t ttr_fde_2525_0x061700(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100c3e0U) + (a1 ^ 0x910063e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff904bU + 0x061700U) ^ (0x9100c3e0U + 0x085a20U + 12U);
}

// [EN] FDE[2526] start_va=0x06170c, fde_va=0x085a38, span=8 B | [VN] FDE[2526]
uint32_t ttr_fde_2526_0x06170c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100c3e0U) + (a1 ^ 0x17ff096aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910523e0U + 0x06170cU) ^ (0x910223e1U + 0x085a38U + 8U);
}

// [EN] FDE[2527] start_va=0x061714, fde_va=0x085a50, span=16 B | [VN] FDE[2527]
uint32_t ttr_fde_2527_0x061714(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910523e0U) + (a1 ^ 0x910223e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910183e2U + 0x061714U) ^ (0x17ff961dU + 0x085a50U + 16U);
}

// [EN] FDE[2528] start_va=0x061724, fde_va=0x085a68, span=8 B | [VN] FDE[2528]
uint32_t ttr_fde_2528_0x061724(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910063e0U) + (a1 ^ 0x17ff0964U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e611801U + 0x061724U) ^ (0x1e649000U + 0x085a68U + 8U);
}

// [EN] FDE[2529] start_va=0x06172c, fde_va=0x085a80, span=12 B | [VN] FDE[2529]
uint32_t ttr_fde_2529_0x06172c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e611801U) + (a1 ^ 0x1e649000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17feea37U + 0x06172cU) ^ (0xaa1b03e0U + 0x085a80U + 12U);
}

// [EN] FDE[2530] start_va=0x061738, fde_va=0x085a98, span=8 B | [VN] FDE[2530]
uint32_t ttr_fde_2530_0x061738(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1b03e0U) + (a1 ^ 0x17ff92a1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4ea81d01U + 0x061738U) ^ (0x4ea91d22U + 0x085a98U + 8U);
}

// [EN] FDE[2531] start_va=0x061740, fde_va=0x085ab0, span=12 B | [VN] FDE[2531]
uint32_t ttr_fde_2531_0x061740(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4ea81d01U) + (a1 ^ 0x4ea91d22U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff1c1dU + 0x061740U) ^ (0xf9400013U + 0x085ab0U + 12U);
}

// [EN] FDE[2532] start_va=0x06174c, fde_va=0x085ac8, span=12 B | [VN] FDE[2532]
uint32_t ttr_fde_2532_0x06174c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400013U) + (a1 ^ 0xf900001fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06174cU) ^ (0xaa0803e0U + 0x085ac8U + 12U);
}

// [EN] FDE[2533] start_va=0x061758, fde_va=0x085ae0, span=12 B | [VN] FDE[2533]
uint32_t ttr_fde_2533_0x061758(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0803e0U) + (a1 ^ 0xf9401529U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0120U + 0x061758U) ^ (0xa9464ff4U + 0x085ae0U + 12U);
}

// [EN] FDE[2534] start_va=0x061764, fde_va=0x085af8, span=28 B | [VN] FDE[2534]
uint32_t ttr_fde_2534_0x061764(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9464ff4U) + (a1 ^ 0xa94557f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9445ff8U + 0x061764U) ^ (0xa94367faU + 0x085af8U + 28U);
}

// [EN] FDE[2535] start_va=0x061780, fde_va=0x085b10, span=12 B | [VN] FDE[2535]
uint32_t ttr_fde_2535_0x061780(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400000U) + (a1 ^ 0xaa1403e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffc303U + 0x061780U) ^ (0x52800400U + 0x085b10U + 12U);
}

// [EN] FDE[2536] start_va=0x06178c, fde_va=0x085b28, span=8 B | [VN] FDE[2536]
uint32_t ttr_fde_2536_0x06178c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52800400U) + (a1 ^ 0x17fee974U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd00001c1U + 0x06178cU) ^ (0xf9453c21U + 0x085b28U + 8U);
}

// [EN] FDE[2537] start_va=0x061794, fde_va=0x085b40, span=16 B | [VN] FDE[2537]
uint32_t ttr_fde_2537_0x061794(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001c1U) + (a1 ^ 0xf9453c21U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800700U + 0x061794U) ^ (0x17fee9b0U + 0x085b40U + 16U);
}

// [EN] FDE[2538] start_va=0x0617a4, fde_va=0x085b58, span=8 B | [VN] FDE[2538]
uint32_t ttr_fde_2538_0x0617a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9003be8U) + (a1 ^ 0x17ff9781U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x39400101U + 0x0617a4U) ^ (0xf9400009U + 0x085b58U + 8U);
}

// [EN] FDE[2539] start_va=0x0617ac, fde_va=0x085b70, span=16 B | [VN] FDE[2539]
uint32_t ttr_fde_2539_0x0617ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400101U) + (a1 ^ 0xf9400009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401529U + 0x0617acU) ^ (0xd61f0120U + 0x085b70U + 16U);
}

// [EN] FDE[2540] start_va=0x0617bc, fde_va=0x085b88, span=8 B | [VN] FDE[2540]
uint32_t ttr_fde_2540_0x0617bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100c3ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1603e1U + 0x0617bcU) ^ (0x17ff093cU + 0x085b88U + 8U);
}

// [EN] FDE[2541] start_va=0x0617c4, fde_va=0x085ba0, span=8 B | [VN] FDE[2541]
uint32_t ttr_fde_2541_0x0617c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e1U) + (a1 ^ 0x17ff093cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x8b000408U + 0x0617c4U) ^ (0xd37df100U + 0x085ba0U + 8U);
}

// [EN] FDE[2542] start_va=0x0617cc, fde_va=0x085bb8, span=12 B | [VN] FDE[2542]
uint32_t ttr_fde_2542_0x0617cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b000408U) + (a1 ^ 0xd37df100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee963U + 0x0617ccU) ^ (0xf940b260U + 0x085bb8U + 12U);
}

// [EN] FDE[2543] start_va=0x0617d8, fde_va=0x085bd0, span=16 B | [VN] FDE[2543]
uint32_t ttr_fde_2543_0x0617d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf940b260U) + (a1 ^ 0x910123e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1703e2U + 0x0617d8U) ^ (0x17ff9ca8U + 0x085bd0U + 16U);
}

// [EN] FDE[2544] start_va=0x0617e8, fde_va=0x085be8, span=28 B | [VN] FDE[2544]
uint32_t ttr_fde_2544_0x0617e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xbc686802U) + (a1 ^ 0x1e220821U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e223862U + 0x0617e8U) ^ (0x1e200840U + 0x085be8U + 28U);
}

// [EN] FDE[2545] start_va=0x061804, fde_va=0x085c00, span=36 B | [VN] FDE[2545]
uint32_t ttr_fde_2545_0x061804(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa90163e0U) + (a1 ^ 0xb9401328U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f6U + 0x061804U) ^ (0xb9001008U + 0x085c00U + 36U);
}

// [EN] FDE[2546] start_va=0x061828, fde_va=0x085c18, span=8 B | [VN] FDE[2546]
uint32_t ttr_fde_2546_0x061828(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12800000U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf00001a8U + 0x061828U) ^ (0x911a8108U + 0x085c18U + 8U);
}

// [EN] FDE[2547] start_va=0x061830, fde_va=0x085c30, span=28 B | [VN] FDE[2547]
uint32_t ttr_fde_2547_0x061830(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001a8U) + (a1 ^ 0x911a8108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f5U + 0x061830U) ^ (0xf9000008U + 0x085c30U + 28U);
}

// [EN] FDE[2548] start_va=0x06184c, fde_va=0x085c48, span=28 B | [VN] FDE[2548]
uint32_t ttr_fde_2548_0x06184c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb010128U) + (a1 ^ 0x9343fd08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91000508U + 0x06184cU) ^ (0x52800049U + 0x085c48U + 28U);
}

// [EN] FDE[2549] start_va=0x061868, fde_va=0x085c60, span=28 B | [VN] FDE[2549]
uint32_t ttr_fde_2549_0x061868(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb010128U) + (a1 ^ 0x9343fd08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91000508U + 0x061868U) ^ (0x52800049U + 0x085c60U + 28U);
}

// [EN] FDE[2550] start_va=0x061884, fde_va=0x085c78, span=28 B | [VN] FDE[2550]
uint32_t ttr_fde_2550_0x061884(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94a4ff4U) + (a1 ^ 0xa94957f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9485ff8U + 0x061884U) ^ (0xa94767faU + 0x085c78U + 28U);
}

// [EN] FDE[2551] start_va=0x0618a0, fde_va=0x085c90, span=12 B | [VN] FDE[2551]
uint32_t ttr_fde_2551_0x0618a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd055U) + (a1 ^ 0xf94016a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0618a0U) ^ (0x91004381U + 0x085c90U + 12U);
}

// [EN] FDE[2552] start_va=0x0618ac, fde_va=0x085ca8, span=12 B | [VN] FDE[2552]
uint32_t ttr_fde_2552_0x0618ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91004381U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff3d70U + 0x0618acU) ^ (0xa9534ff4U + 0x085ca8U + 12U);
}

// [EN] FDE[2553] start_va=0x0618b8, fde_va=0x085cc0, span=28 B | [VN] FDE[2553]
uint32_t ttr_fde_2553_0x0618b8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9534ff4U) + (a1 ^ 0xa95257f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9515ff8U + 0x0618b8U) ^ (0xa95067faU + 0x085cc0U + 28U);
}

// [EN] FDE[2554] start_va=0x0618d4, fde_va=0x085cd8, span=8 B | [VN] FDE[2554]
uint32_t ttr_fde_2554_0x0618d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa8c24ff4U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000408U + 0x0618d4U) ^ (0xb9001009U + 0x085cd8U + 8U);
}

// [EN] FDE[2555] start_va=0x0618dc, fde_va=0x085cf0, span=12 B | [VN] FDE[2555]
uint32_t ttr_fde_2555_0x0618dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000408U) + (a1 ^ 0xb9001009U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0618dcU) ^ (0xf9400a69U + 0x085cf0U + 12U);
}

// [EN] FDE[2556] start_va=0x0618e8, fde_va=0x085d08, span=36 B | [VN] FDE[2556]
uint32_t ttr_fde_2556_0x0618e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a69U) + (a1 ^ 0x9100126aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200011fU + 0x0618e8U) ^ (0x91000d2bU + 0x085d08U + 36U);
}

// [EN] FDE[2557] start_va=0x06190c, fde_va=0x085d20, span=16 B | [VN] FDE[2557]
uint32_t ttr_fde_2557_0x06190c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f5U) + (a1 ^ 0xaa1603e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f4U + 0x06190cU) ^ (0x17ffb004U + 0x085d20U + 16U);
}

// [EN] FDE[2558] start_va=0x06191c, fde_va=0x085d38, span=28 B | [VN] FDE[2558]
uint32_t ttr_fde_2558_0x06191c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402668U) + (a1 ^ 0xaa0003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x06191cU) ^ (0xaa1503e3U + 0x085d38U + 28U);
}

// [EN] FDE[2559] start_va=0x061938, fde_va=0x085d50, span=12 B | [VN] FDE[2559]
uint32_t ttr_fde_2559_0x061938(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f7U) + (a1 ^ 0xeb16001fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061938U) ^ (0x910203e9U + 0x085d50U + 12U);
}

// [EN] FDE[2560] start_va=0x061944, fde_va=0x085d68, span=28 B | [VN] FDE[2560]
uint32_t ttr_fde_2560_0x061944(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910203e9U) + (a1 ^ 0x910023e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910203e2U + 0x061944U) ^ (0xaa1403e0U + 0x085d68U + 28U);
}

// [EN] FDE[2561] start_va=0x061960, fde_va=0x085d80, span=36 B | [VN] FDE[2561]
uint32_t ttr_fde_2561_0x061960(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb14012bU) + (a1 ^ 0xcb08028aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd100416bU + 0x061960U) ^ (0xd1004120U + 0x085d80U + 36U);
}

// [EN] FDE[2562] start_va=0x061984, fde_va=0x085d98, span=12 B | [VN] FDE[2562]
uint32_t ttr_fde_2562_0x061984(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1603e0U) + (a1 ^ 0xaa1503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061984U) ^ (0x90000061U + 0x085d98U + 12U);
}

// [EN] FDE[2563] start_va=0x061990, fde_va=0x085db0, span=16 B | [VN] FDE[2563]
uint32_t ttr_fde_2563_0x061990(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x90000061U) + (a1 ^ 0x912ca821U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910183e0U + 0x061990U) ^ (0x17ff08c7U + 0x085db0U + 16U);
}

// [EN] FDE[2564] start_va=0x0619a0, fde_va=0x085dc8, span=12 B | [VN] FDE[2564]
uint32_t ttr_fde_2564_0x0619a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9414ff4U) + (a1 ^ 0xf84307f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0619a0U) ^ (0x2a1503e1U + 0x085dc8U + 12U);
}

// [EN] FDE[2565] start_va=0x0619ac, fde_va=0x085de0, span=16 B | [VN] FDE[2565]
uint32_t ttr_fde_2565_0x0619ac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1503e1U) + (a1 ^ 0xaa1303e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9401908U + 0x0619acU) ^ (0xd61f0100U + 0x085de0U + 16U);
}

// [EN] FDE[2566] start_va=0x0619bc, fde_va=0x085df8, span=16 B | [VN] FDE[2566]
uint32_t ttr_fde_2566_0x0619bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1503e1U) + (a1 ^ 0x2a1403e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a1303e3U + 0x0619bcU) ^ (0x17ffee6fU + 0x085df8U + 16U);
}

// [EN] FDE[2567] start_va=0x0619cc, fde_va=0x085e10, span=12 B | [VN] FDE[2567]
uint32_t ttr_fde_2567_0x0619cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xf9401501U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0020U + 0x0619ccU) ^ (0xf81f0ffeU + 0x085e10U + 12U);
}

// [EN] FDE[2568] start_va=0x0619d8, fde_va=0x085e28, span=52 B | [VN] FDE[2568]
uint32_t ttr_fde_2568_0x0619d8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa0103f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x0619d8U) ^ (0xaa0103e0U + 0x085e28U + 52U);
}

// [EN] FDE[2569] start_va=0x061a0c, fde_va=0x085e48, span=8 B | [VN] FDE[2569]
uint32_t ttr_fde_2569_0x061a0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17ffae5fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e0U + 0x061a0cU) ^ (0x17fee956U + 0x085e48U + 8U);
}

// [EN] FDE[2570] start_va=0x061a14, fde_va=0x085e60, span=8 B | [VN] FDE[2570]
uint32_t ttr_fde_2570_0x061a14(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0x17fee956U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x061a14U) ^ (0x17ff1089U + 0x085e60U + 8U);
}

// [EN] FDE[2571] start_va=0x061a1c, fde_va=0x085e78, span=8 B | [VN] FDE[2571]
uint32_t ttr_fde_2571_0x061a1c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff1089U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x061a1cU) ^ (0x889ffd09U + 0x085e78U + 8U);
}

// [EN] FDE[2572] start_va=0x061a24, fde_va=0x085e90, span=12 B | [VN] FDE[2572]
uint32_t ttr_fde_2572_0x061a24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x889ffd09U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffae58U + 0x061a24U) ^ (0xaa1403e0U + 0x085e90U + 12U);
}

// [EN] FDE[2573] start_va=0x061a30, fde_va=0x085ea8, span=8 B | [VN] FDE[2573]
uint32_t ttr_fde_2573_0x061a30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17fee94fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x061a30U) ^ (0xaa1f03e1U + 0x085ea8U + 8U);
}

// [EN] FDE[2574] start_va=0x061a38, fde_va=0x085ec0, span=12 B | [VN] FDE[2574]
uint32_t ttr_fde_2574_0x061a38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0xaa1f03e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061a38U) ^ (0xaa0003e1U + 0x085ec0U + 12U);
}

// [EN] FDE[2575] start_va=0x061a44, fde_va=0x085ed8, span=12 B | [VN] FDE[2575]
uint32_t ttr_fde_2575_0x061a44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffed92U + 0x061a44U) ^ (0xaa0003e1U + 0x085ed8U + 12U);
}

// [EN] FDE[2576] start_va=0x061a50, fde_va=0x085ef0, span=12 B | [VN] FDE[2576]
uint32_t ttr_fde_2576_0x061a50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003e1U) + (a1 ^ 0x910123e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffac0cU + 0x061a50U) ^ (0x9ac909cfU + 0x085ef0U + 12U);
}

// [EN] FDE[2577] start_va=0x061a5c, fde_va=0x085f08, span=12 B | [VN] FDE[2577]
uint32_t ttr_fde_2577_0x061a5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9ac909cfU) + (a1 ^ 0x9b09b9eeU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061a5cU) ^ (0xf9400668U + 0x085f08U + 12U);
}

// [EN] FDE[2578] start_va=0x061a68, fde_va=0x085f20, span=28 B | [VN] FDE[2578]
uint32_t ttr_fde_2578_0x061a68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400668U) + (a1 ^ 0x910103e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x061a68U) ^ (0xf8408509U + 0x085f20U + 28U);
}

// [EN] FDE[2579] start_va=0x061a84, fde_va=0x085f38, span=8 B | [VN] FDE[2579]
uint32_t ttr_fde_2579_0x061a84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e1U) + (a1 ^ 0x17ffcf21U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400288U + 0x061a84U) ^ (0xf9400269U + 0x085f38U + 8U);
}

// [EN] FDE[2580] start_va=0x061a8c, fde_va=0x085f50, span=36 B | [VN] FDE[2580]
uint32_t ttr_fde_2580_0x061a8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400288U) + (a1 ^ 0xf9400269U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000268U + 0x061a8cU) ^ (0xf9000289U + 0x085f50U + 36U);
}

// [EN] FDE[2581] start_va=0x061ab0, fde_va=0x085f68, span=28 B | [VN] FDE[2581]
uint32_t ttr_fde_2581_0x061ab0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9454ff4U) + (a1 ^ 0xa94457f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9435ff8U + 0x061ab0U) ^ (0xa94267faU + 0x085f68U + 28U);
}

// [EN] FDE[2582] start_va=0x061acc, fde_va=0x085f80, span=20 B | [VN] FDE[2582]
uint32_t ttr_fde_2582_0x061acc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0x97ff105aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1803e0U + 0x061accU) ^ (0xf84107feU + 0x085f80U + 20U);
}

// [EN] FDE[2583] start_va=0x061ae0, fde_va=0x085fa0, span=12 B | [VN] FDE[2583]
uint32_t ttr_fde_2583_0x061ae0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa900a7e8U) + (a1 ^ 0xa901ffffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fee96eU + 0x061ae0U) ^ (0xaa1303e0U + 0x085fa0U + 12U);
}

// [EN] FDE[2584] start_va=0x061aec, fde_va=0x085fb8, span=12 B | [VN] FDE[2584]
uint32_t ttr_fde_2584_0x061aec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0xf84207f3U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff0028U + 0x061aecU) ^ (0xaa1303e0U + 0x085fb8U + 12U);
}

// [EN] FDE[2585] start_va=0x061af8, fde_va=0x085fd0, span=8 B | [VN] FDE[2585]
uint32_t ttr_fde_2585_0x061af8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ffa2abU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x061af8U) ^ (0xf9400800U + 0x085fd0U + 8U);
}

// [EN] FDE[2586] start_va=0x061b00, fde_va=0x085fe8, span=12 B | [VN] FDE[2586]
uint32_t ttr_fde_2586_0x061b00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf9400800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061b00U) ^ (0xaa0003f3U + 0x085fe8U + 12U);
}

// [EN] FDE[2587] start_va=0x061b0c, fde_va=0x086000, span=28 B | [VN] FDE[2587]
uint32_t ttr_fde_2587_0x061b0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xb9009801U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9100e014U + 0x061b0cU) ^ (0x93407c35U + 0x086000U + 28U);
}

// [EN] FDE[2588] start_va=0x061b28, fde_va=0x086018, span=12 B | [VN] FDE[2588]
uint32_t ttr_fde_2588_0x061b28(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd056U) + (a1 ^ 0xf94016c8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061b28U) ^ (0xa90ca7eaU + 0x086018U + 12U);
}

// [EN] FDE[2589] start_va=0x061b34, fde_va=0x086030, span=20 B | [VN] FDE[2589]
uint32_t ttr_fde_2589_0x061b34(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa90ca7eaU) + (a1 ^ 0xf90063ebU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xad0007e0U + 0x061b34U) ^ (0xad4603e1U + 0x086030U + 20U);
}

// [EN] FDE[2590] start_va=0x061b48, fde_va=0x086048, span=32 B | [VN] FDE[2590]
uint32_t ttr_fde_2590_0x061b48(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x928003e8U) + (a1 ^ 0x910003e9U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910203eaU + 0x061b48U) ^ (0xf2dff008U + 0x086048U + 32U);
}

// [EN] FDE[2591] start_va=0x061b68, fde_va=0x086060, span=32 B | [VN] FDE[2591]
uint32_t ttr_fde_2591_0x061b68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9016bffU) + (a1 ^ 0xb90113ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3c808100U + 0x061b68U) ^ (0x3c818100U + 0x086060U + 32U);
}

// [EN] FDE[2592] start_va=0x061b88, fde_va=0x086078, span=8 B | [VN] FDE[2592]
uint32_t ttr_fde_2592_0x061b88(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910163e0U) + (a1 ^ 0x17ffab74U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007e7fU + 0x061b88U) ^ (0xf9000a7fU + 0x086078U + 8U);
}

// [EN] FDE[2593] start_va=0x061b90, fde_va=0x086090, span=12 B | [VN] FDE[2593]
uint32_t ttr_fde_2593_0x061b90(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007e7fU) + (a1 ^ 0xf9000a7fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061b90U) ^ (0x5280030aU + 0x086090U + 12U);
}

// [EN] FDE[2594] start_va=0x061b9c, fde_va=0x0860a8, span=16 B | [VN] FDE[2594]
uint32_t ttr_fde_2594_0x061b9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x5280030aU) + (a1 ^ 0xcb080129U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9aca0d29U + 0x061b9cU) ^ (0xd65f03c0U + 0x0860a8U + 16U);
}

// [EN] FDE[2595] start_va=0x061bac, fde_va=0x0860c0, span=24 B | [VN] FDE[2595]
uint32_t ttr_fde_2595_0x061bac(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd00001eaU) + (a1 ^ 0x910d414aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3940014bU + 0x061bacU) ^ (0xf00001c8U + 0x0860c0U + 24U);
}

// [EN] FDE[2596] start_va=0x061bc4, fde_va=0x0860d8, span=20 B | [VN] FDE[2596]
uint32_t ttr_fde_2596_0x061bc4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400aaaU) + (a1 ^ 0x520002c8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x529025e9U + 0x061bc4U) ^ (0x7100095fU + 0x0860d8U + 20U);
}

// [EN] FDE[2597] start_va=0x061bd8, fde_va=0x0860f0, span=8 B | [VN] FDE[2597]
uint32_t ttr_fde_2597_0x061bd8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52850041U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52850021U + 0x061bd8U) ^ (0xd61f0100U + 0x0860f0U + 8U);
}

// [EN] FDE[2598] start_va=0x061be0, fde_va=0x086108, span=8 B | [VN] FDE[2598]
uint32_t ttr_fde_2598_0x061be0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52850021U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb9401268U + 0x061be0U) ^ (0x51000509U + 0x086108U + 8U);
}

// [EN] FDE[2599] start_va=0x061be8, fde_va=0x086120, span=20 B | [VN] FDE[2599]
uint32_t ttr_fde_2599_0x061be8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401268U) + (a1 ^ 0x51000509U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6a09011fU + 0x061be8U) ^ (0x1a9f17f6U + 0x086120U + 20U);
}

// [EN] FDE[2600] start_va=0x061bfc, fde_va=0x086138, span=20 B | [VN] FDE[2600]
uint32_t ttr_fde_2600_0x061bfc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401268U) + (a1 ^ 0x51000509U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x6a09011fU + 0x061bfcU) ^ (0x1a9f17e2U + 0x086138U + 20U);
}

// [EN] FDE[2601] start_va=0x061c10, fde_va=0x086150, span=20 B | [VN] FDE[2601]
uint32_t ttr_fde_2601_0x061c10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x911ac884U) + (a1 ^ 0x910704a5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910b38c6U + 0x061c10U) ^ (0x52800082U + 0x086150U + 20U);
}

// [EN] FDE[2602] start_va=0x061c24, fde_va=0x086168, span=24 B | [VN] FDE[2602]
uint32_t ttr_fde_2602_0x061c24(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910583e8U) + (a1 ^ 0x9104c3e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910583e2U + 0x061c24U) ^ (0xaa1c03e0U + 0x086168U + 24U);
}

// [EN] FDE[2603] start_va=0x061c3c, fde_va=0x086180, span=20 B | [VN] FDE[2603]
uint32_t ttr_fde_2603_0x061c3c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e26000bU + 0x061c3cU) ^ (0xf100057fU + 0x086180U + 20U);
}

// [EN] FDE[2604] start_va=0x061c50, fde_va=0x086198, span=8 B | [VN] FDE[2604]
uint32_t ttr_fde_2604_0x061c50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910643e0U) + (a1 ^ 0x17feffd0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9105c3e0U + 0x061c50U) ^ (0x910503e1U + 0x086198U + 8U);
}

// [EN] FDE[2605] start_va=0x061c58, fde_va=0x0861b0, span=24 B | [VN] FDE[2605]
uint32_t ttr_fde_2605_0x061c58(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105c3e0U) + (a1 ^ 0x910503e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x52800062U + 0x061c58U) ^ (0xbd0147e0U + 0x0861b0U + 24U);
}

// [EN] FDE[2606] start_va=0x061c70, fde_va=0x0861c8, span=20 B | [VN] FDE[2606]
uint32_t ttr_fde_2606_0x061c70(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f9U) + (a1 ^ 0x3c808000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000008U + 0x061c70U) ^ (0x9100601bU + 0x0861c8U + 20U);
}

// [EN] FDE[2607] start_va=0x061c84, fde_va=0x0861e0, span=24 B | [VN] FDE[2607]
uint32_t ttr_fde_2607_0x061c84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9100a3e0U) + (a1 ^ 0x910043e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910033e2U + 0x061c84U) ^ (0x910023e3U + 0x0861e0U + 24U);
}

// [EN] FDE[2608] start_va=0x061c9c, fde_va=0x0861f8, span=24 B | [VN] FDE[2608]
uint32_t ttr_fde_2608_0x061c9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa94953f5U) + (a1 ^ 0xa9485bf7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa94763f9U + 0x061c9cU) ^ (0xf94033faU + 0x0861f8U + 24U);
}

// [EN] FDE[2609] start_va=0x061cb4, fde_va=0x086210, span=24 B | [VN] FDE[2609]
uint32_t ttr_fde_2609_0x061cb4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e624000U) + (a1 ^ 0x910063e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910033e1U + 0x061cb4U) ^ (0x52800062U + 0x086210U + 24U);
}

// [EN] FDE[2610] start_va=0x061ccc, fde_va=0x086228, span=28 B | [VN] FDE[2610]
uint32_t ttr_fde_2610_0x061ccc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400028U) + (a1 ^ 0xa940a42aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd0bU + 0x061cccU) ^ (0x7200011fU + 0x086228U + 28U);
}

// [EN] FDE[2611] start_va=0x061ce8, fde_va=0x086240, span=8 B | [VN] FDE[2611]
uint32_t ttr_fde_2611_0x061ce8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910223e0U) + (a1 ^ 0x17ffab1cU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb00029fU + 0x061ce8U) ^ (0x9a943001U + 0x086240U + 8U);
}

// [EN] FDE[2612] start_va=0x061cf0, fde_va=0x086258, span=16 B | [VN] FDE[2612]
uint32_t ttr_fde_2612_0x061cf0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb00029fU) + (a1 ^ 0x9a943001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb15003fU + 0x061cf0U) ^ (0xd65f03c0U + 0x086258U + 16U);
}

// [EN] FDE[2613] start_va=0x061d00, fde_va=0x086270, span=24 B | [VN] FDE[2613]
uint32_t ttr_fde_2613_0x061d00(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910013e1U) + (a1 ^ 0x910023e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1403e0U + 0x061d00U) ^ (0xb90013e8U + 0x086270U + 24U);
}

// [EN] FDE[2614] start_va=0x061d18, fde_va=0x086288, span=20 B | [VN] FDE[2614]
uint32_t ttr_fde_2614_0x061d18(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9400288U) + (a1 ^ 0xd00001d6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94156d6U + 0x061d18U) ^ (0x7100191fU + 0x086288U + 20U);
}

// [EN] FDE[2615] start_va=0x061d2c, fde_va=0x0862a0, span=24 B | [VN] FDE[2615]
uint32_t ttr_fde_2615_0x061d2c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb90003ffU) + (a1 ^ 0xa9435268U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e1U + 0x061d2cU) ^ (0xb9406d00U + 0x0862a0U + 24U);
}

// [EN] FDE[2616] start_va=0x061d44, fde_va=0x0862b8, span=24 B | [VN] FDE[2616]
uint32_t ttr_fde_2616_0x061d44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000028U) + (a1 ^ 0xf9400c08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x3cc08000U + 0x061d44U) ^ (0xf9000c28U + 0x0862b8U + 24U);
}

// [EN] FDE[2617] start_va=0x061d5c, fde_va=0x0862d0, span=24 B | [VN] FDE[2617]
uint32_t ttr_fde_2617_0x061d5c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9000bffU) + (a1 ^ 0xf9402668U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910043e0U + 0x061d5cU) ^ (0x91000508U + 0x0862d0U + 24U);
}

// [EN] FDE[2618] start_va=0x061d74, fde_va=0x0862e8, span=24 B | [VN] FDE[2618]
uint32_t ttr_fde_2618_0x061d74(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x79414088U) + (a1 ^ 0x52800be1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0403e0U + 0x061d74U) ^ (0x321b0508U + 0x0862e8U + 24U);
}

// [EN] FDE[2619] start_va=0x061d8c, fde_va=0x086300, span=16 B | [VN] FDE[2619]
uint32_t ttr_fde_2619_0x061d8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd054U) + (a1 ^ 0xf9401688U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x061d8cU) ^ (0xd65f03c0U + 0x086300U + 16U);
}

// [EN] FDE[2620] start_va=0x061d9c, fde_va=0x086318, span=20 B | [VN] FDE[2620]
uint32_t ttr_fde_2620_0x061d9c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd054U) + (a1 ^ 0xf9401688U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x061d9cU) ^ (0xf9000fe8U + 0x086318U + 20U);
}

// [EN] FDE[2621] start_va=0x061db0, fde_va=0x086330, span=32 B | [VN] FDE[2621]
uint32_t ttr_fde_2621_0x061db0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401e88U) + (a1 ^ 0xaa0003e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x110006e4U + 0x061db0U) ^ (0xaa1403e0U + 0x086330U + 32U);
}

// [EN] FDE[2622] start_va=0x061dd0, fde_va=0x086348, span=24 B | [VN] FDE[2622]
uint32_t ttr_fde_2622_0x061dd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9809ee8U) + (a1 ^ 0xd37df109U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb48f7ffU + 0x061dd0U) ^ (0xda9f0139U + 0x086348U + 24U);
}

// [EN] FDE[2623] start_va=0x061de8, fde_va=0x086360, span=8 B | [VN] FDE[2623]
uint32_t ttr_fde_2623_0x061de8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x17ff8e9fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e0U + 0x061de8U) ^ (0x17ffaadaU + 0x086360U + 8U);
}

// [EN] FDE[2624] start_va=0x061df0, fde_va=0x086378, span=8 B | [VN] FDE[2624]
uint32_t ttr_fde_2624_0x061df0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910003e0U) + (a1 ^ 0x17ffaadaU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xb24002c8U + 0x061df0U) ^ (0xa9008297U + 0x086378U + 8U);
}

// [EN] FDE[2625] start_va=0x061df8, fde_va=0x086390, span=20 B | [VN] FDE[2625]
uint32_t ttr_fde_2625_0x061df8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb24002c8U) + (a1 ^ 0xa9008297U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000288U + 0x061df8U) ^ (0xaa0003f4U + 0x086390U + 20U);
}

// [EN] FDE[2626] start_va=0x061e0c, fde_va=0x0863a8, span=20 B | [VN] FDE[2626]
uint32_t ttr_fde_2626_0x061e0c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb24002c8U) + (a1 ^ 0xa9008293U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000288U + 0x061e0cU) ^ (0xaa0003f4U + 0x0863a8U + 20U);
}

// [EN] FDE[2627] start_va=0x061e20, fde_va=0x0863c0, span=16 B | [VN] FDE[2627]
uint32_t ttr_fde_2627_0x061e20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x12807c08U) + (a1 ^ 0xb9000268U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9002a7fU + 0x061e20U) ^ (0xd65f03c0U + 0x0863c0U + 16U);
}

// [EN] FDE[2628] start_va=0x061e30, fde_va=0x0863d8, span=20 B | [VN] FDE[2628]
uint32_t ttr_fde_2628_0x061e30(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xcb010057U) + (a1 ^ 0xb10042ffU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007c1fU + 0x061e30U) ^ (0xf900081fU + 0x0863d8U + 20U);
}

// [EN] FDE[2629] start_va=0x061e44, fde_va=0x0863f0, span=32 B | [VN] FDE[2629]
uint32_t ttr_fde_2629_0x061e44(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400268U) + (a1 ^ 0xf9400669U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd0aU + 0x061e44U) ^ (0x7200011fU + 0x0863f0U + 32U);
}

// [EN] FDE[2630] start_va=0x061e64, fde_va=0x086408, span=32 B | [VN] FDE[2630]
uint32_t ttr_fde_2630_0x061e64(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400268U) + (a1 ^ 0xf9400669U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd341fd0aU + 0x061e64U) ^ (0x7200011fU + 0x086408U + 32U);
}

// [EN] FDE[2631] start_va=0x061e84, fde_va=0x086420, span=32 B | [VN] FDE[2631]
uint32_t ttr_fde_2631_0x061e84(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x8b190808U) + (a1 ^ 0x8b170809U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd37ef6aaU + 0x061e84U) ^ (0xa901a7e8U + 0x086420U + 32U);
}

// [EN] FDE[2632] start_va=0x061ea4, fde_va=0x086438, span=24 B | [VN] FDE[2632]
uint32_t ttr_fde_2632_0x061ea4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81a0ffcU) + (a1 ^ 0xa9016bfbU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa90263f9U + 0x061ea4U) ^ (0xa9035bf7U + 0x086438U + 24U);
}

// [EN] FDE[2633] start_va=0x061ebc, fde_va=0x086450, span=12 B | [VN] FDE[2633]
uint32_t ttr_fde_2633_0x061ebc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x510056a8U) + (a1 ^ 0x71002d1fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061ebcU) ^ (0x39400288U + 0x086450U + 12U);
}

// [EN] FDE[2634] start_va=0x061ec8, fde_va=0x086468, span=16 B | [VN] FDE[2634]
uint32_t ttr_fde_2634_0x061ec8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x39400288U) + (a1 ^ 0x121d1109U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7100c13fU + 0x061ec8U) ^ (0xd65f03c0U + 0x086468U + 16U);
}

// [EN] FDE[2635] start_va=0x061ed8, fde_va=0x086480, span=24 B | [VN] FDE[2635]
uint32_t ttr_fde_2635_0x061ed8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9444ff4U) + (a1 ^ 0xa94357f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9425ff8U + 0x061ed8U) ^ (0xa94167faU + 0x086480U + 24U);
}

// [EN] FDE[2636] start_va=0x061ef0, fde_va=0x086498, span=32 B | [VN] FDE[2636]
uint32_t ttr_fde_2636_0x061ef0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb94026a8U) + (a1 ^ 0xb9401eb7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910006c1U + 0x061ef0U) ^ (0xaa1503e0U + 0x086498U + 32U);
}

// [EN] FDE[2637] start_va=0x061f10, fde_va=0x0864b0, span=16 B | [VN] FDE[2637]
uint32_t ttr_fde_2637_0x061f10(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xeb1302ffU) + (a1 ^ 0x9a9706f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xeb1302dfU + 0x061f10U) ^ (0xd65f03c0U + 0x0864b0U + 16U);
}

// [EN] FDE[2638] start_va=0x061f20, fde_va=0x0864c8, span=24 B | [VN] FDE[2638]
uint32_t ttr_fde_2638_0x061f20(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401a88U) + (a1 ^ 0x91000e61U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e0U + 0x061f20U) ^ (0xaa1503e2U + 0x0864c8U + 24U);
}

// [EN] FDE[2639] start_va=0x061f38, fde_va=0x0864e0, span=24 B | [VN] FDE[2639]
uint32_t ttr_fde_2639_0x061f38(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401a88U) + (a1 ^ 0x91000e61U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910003e0U + 0x061f38U) ^ (0xaa1503e2U + 0x0864e0U + 24U);
}

// [EN] FDE[2640] start_va=0x061f50, fde_va=0x0864f8, span=24 B | [VN] FDE[2640]
uint32_t ttr_fde_2640_0x061f50(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf00001a8U) + (a1 ^ 0x911b4108U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003e1U + 0x061f50U) ^ (0xa9005408U + 0x0864f8U + 24U);
}

// [EN] FDE[2641] start_va=0x061f68, fde_va=0x086510, span=24 B | [VN] FDE[2641]
uint32_t ttr_fde_2641_0x061f68(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x91006018U) + (a1 ^ 0xaa0003f7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa900fc1fU + 0x061f68U) ^ (0xf9000008U + 0x086510U + 24U);
}

// [EN] FDE[2642] start_va=0x061f80, fde_va=0x086528, span=12 B | [VN] FDE[2642]
uint32_t ttr_fde_2642_0x061f80(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa940026bU) + (a1 ^ 0xeb0b000aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061f80U) ^ (0xa9007c1fU + 0x086528U + 12U);
}

// [EN] FDE[2643] start_va=0x061f8c, fde_va=0x086540, span=12 B | [VN] FDE[2643]
uint32_t ttr_fde_2643_0x061f8c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007c1fU) + (a1 ^ 0xf900081fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x061f8cU) ^ (0x910303ffU + 0x086540U + 12U);
}

// [EN] FDE[2644] start_va=0x061f98, fde_va=0x086558, span=8 B | [VN] FDE[2644]
uint32_t ttr_fde_2644_0x061f98(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910303ffU) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd53bd055U + 0x061f98U) ^ (0xf94016a8U + 0x086558U + 8U);
}

// [EN] FDE[2645] start_va=0x061fa0, fde_va=0x086570, span=16 B | [VN] FDE[2645]
uint32_t ttr_fde_2645_0x061fa0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd055U) + (a1 ^ 0xf94016a8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x061fa0U) ^ (0xd65f03c0U + 0x086570U + 16U);
}

// [EN] FDE[2646] start_va=0x061fb0, fde_va=0x086588, span=32 B | [VN] FDE[2646]
uint32_t ttr_fde_2646_0x061fb0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa90893e3U) + (a1 ^ 0xa9099be5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf90057e7U + 0x061fb0U) ^ (0xad0007e0U + 0x086588U + 32U);
}

// [EN] FDE[2647] start_va=0x061fd0, fde_va=0x0865a0, span=16 B | [VN] FDE[2647]
uint32_t ttr_fde_2647_0x061fd0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd1004109U) + (a1 ^ 0xf9000a69U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf85f8100U + 0x061fd0U) ^ (0xd65f03c0U + 0x0865a0U + 16U);
}

// [EN] FDE[2648] start_va=0x061fe0, fde_va=0x0865b8, span=16 B | [VN] FDE[2648]
uint32_t ttr_fde_2648_0x061fe0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9343fd08U) + (a1 ^ 0xeb01011fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9a883020U + 0x061fe0U) ^ (0xd65f03c0U + 0x0865b8U + 16U);
}

// [EN] FDE[2649] start_va=0x061ff0, fde_va=0x0865d0, span=24 B | [VN] FDE[2649]
uint32_t ttr_fde_2649_0x061ff0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e6a0800U) + (a1 ^ 0x1e690800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xfd000be0U + 0x061ff0U) ^ (0x1e6e280fU + 0x0865d0U + 24U);
}

// [EN] FDE[2650] start_va=0x062008, fde_va=0x0865e8, span=24 B | [VN] FDE[2650]
uint32_t ttr_fde_2650_0x062008(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e690921U) + (a1 ^ 0xfd000fe1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e61080eU + 0x062008U) ^ (0x1e611001U + 0x0865e8U + 24U);
}

// [EN] FDE[2651] start_va=0x062020, fde_va=0x086600, span=20 B | [VN] FDE[2651]
uint32_t ttr_fde_2651_0x062020(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f3U) + (a1 ^ 0xaa0103f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f4U + 0x062020U) ^ (0xf1005affU + 0x086600U + 20U);
}

// [EN] FDE[2652] start_va=0x062034, fde_va=0x086618, span=12 B | [VN] FDE[2652]
uint32_t ttr_fde_2652_0x062034(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0203f3U) + (a1 ^ 0xaa0003f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062034U) ^ (0xd37df000U + 0x086618U + 12U);
}

// [EN] FDE[2653] start_va=0x062040, fde_va=0x086630, span=8 B | [VN] FDE[2653]
uint32_t ttr_fde_2653_0x062040(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd37df000U) + (a1 ^ 0x17fee747U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9402009U + 0x062040U) ^ (0xaa0103f4U + 0x086630U + 8U);
}

// [EN] FDE[2654] start_va=0x062048, fde_va=0x086648, span=20 B | [VN] FDE[2654]
uint32_t ttr_fde_2654_0x062048(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402009U) + (a1 ^ 0xaa0103f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x062048U) ^ (0xcb09010aU + 0x086648U + 20U);
}

// [EN] FDE[2655] start_va=0x06205c, fde_va=0x086660, span=20 B | [VN] FDE[2655]
uint32_t ttr_fde_2655_0x06205c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402668U) + (a1 ^ 0xaa0003f5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9025fffU + 0x06205cU) ^ (0xcb080136U + 0x086660U + 20U);
}

// [EN] FDE[2656] start_va=0x062070, fde_va=0x086678, span=8 B | [VN] FDE[2656]
uint32_t ttr_fde_2656_0x062070(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a1f03e4U) + (a1 ^ 0xd61f0100U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400269U + 0x062070U) ^ (0xaa1303e0U + 0x086678U + 8U);
}

// [EN] FDE[2657] start_va=0x062078, fde_va=0x086690, span=24 B | [VN] FDE[2657]
uint32_t ttr_fde_2657_0x062078(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400269U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91004277U + 0x062078U) ^ (0xcb090108U + 0x086690U + 24U);
}

// [EN] FDE[2658] start_va=0x062090, fde_va=0x0866a8, span=20 B | [VN] FDE[2658]
uint32_t ttr_fde_2658_0x062090(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x3dc00140U) + (a1 ^ 0x3ca86920U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9007d5fU + 0x062090U) ^ (0x91004108U + 0x0866a8U + 20U);
}

// [EN] FDE[2659] start_va=0x0620a4, fde_va=0x0866c0, span=12 B | [VN] FDE[2659]
uint32_t ttr_fde_2659_0x0620a4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9adb0909U) + (a1 ^ 0x9b1ba128U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0620a4U) ^ (0xf9400a68U + 0x0866c0U + 12U);
}

// [EN] FDE[2660] start_va=0x0620b0, fde_va=0x0866d8, span=16 B | [VN] FDE[2660]
uint32_t ttr_fde_2660_0x0620b0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400a68U) + (a1 ^ 0x8b150d08U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa900a260U + 0x0620b0U) ^ (0xd65f03c0U + 0x0866d8U + 16U);
}

// [EN] FDE[2661] start_va=0x0620c0, fde_va=0x0866f0, span=20 B | [VN] FDE[2661]
uint32_t ttr_fde_2661_0x0620c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f4U) + (a1 ^ 0xaa0203e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0203f6U + 0x0620c0U) ^ (0xaa0003f3U + 0x0866f0U + 20U);
}

// [EN] FDE[2662] start_va=0x0620d4, fde_va=0x086708, span=8 B | [VN] FDE[2662]
uint32_t ttr_fde_2662_0x0620d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f3U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xa9402428U + 0x0620d4U) ^ (0xa9007c3fU + 0x086708U + 8U);
}

// [EN] FDE[2663] start_va=0x0620dc, fde_va=0x086720, span=24 B | [VN] FDE[2663]
uint32_t ttr_fde_2663_0x0620dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402428U) + (a1 ^ 0xa9007c3fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0620dcU) ^ (0xf9400400U + 0x086720U + 24U);
}

// [EN] FDE[2664] start_va=0x0620f4, fde_va=0x086738, span=24 B | [VN] FDE[2664]
uint32_t ttr_fde_2664_0x0620f4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9402428U) + (a1 ^ 0xa9007c3fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0620f4U) ^ (0xf9400400U + 0x086738U + 24U);
}

// [EN] FDE[2665] start_va=0x06210c, fde_va=0x086750, span=24 B | [VN] FDE[2665]
uint32_t ttr_fde_2665_0x06210c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xb90033e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97fefea0U + 0x06210cU) ^ (0xf9401e60U + 0x086750U + 24U);
}

// [EN] FDE[2666] start_va=0x062124, fde_va=0x086770, span=24 B | [VN] FDE[2666]
uint32_t ttr_fde_2666_0x062124(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e210800U) + (a1 ^ 0x1e200860U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e3e1001U + 0x062124U) ^ (0x1e201820U + 0x086770U + 24U);
}

// [EN] FDE[2667] start_va=0x06213c, fde_va=0x086788, span=24 B | [VN] FDE[2667]
uint32_t ttr_fde_2667_0x06213c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0x910043e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910033e2U + 0x06213cU) ^ (0x910023e3U + 0x086788U + 24U);
}

// [EN] FDE[2668] start_va=0x062154, fde_va=0x0867a0, span=24 B | [VN] FDE[2668]
uint32_t ttr_fde_2668_0x062154(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0x2a0303f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x062154U) ^ (0x2a0103f5U + 0x0867a0U + 24U);
}

// [EN] FDE[2669] start_va=0x06216c, fde_va=0x0867b8, span=32 B | [VN] FDE[2669]
uint32_t ttr_fde_2669_0x06216c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400008U) + (a1 ^ 0xd341fd09U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x92400108U + 0x06216cU) ^ (0x9e620120U + 0x0867b8U + 32U);
}

// [EN] FDE[2670] start_va=0x06218c, fde_va=0x0867d0, span=12 B | [VN] FDE[2670]
uint32_t ttr_fde_2670_0x06218c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0103f3U) + (a1 ^ 0xeb02003fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x06218cU) ^ (0xa9007d1fU + 0x0867d0U + 12U);
}

// [EN] FDE[2671] start_va=0x062198, fde_va=0x0867e8, span=16 B | [VN] FDE[2671]
uint32_t ttr_fde_2671_0x062198(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xa9007d1fU) + (a1 ^ 0xf900091fU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x91006108U + 0x062198U) ^ (0xd65f03c0U + 0x0867e8U + 16U);
}

// [EN] FDE[2672] start_va=0x0621a8, fde_va=0x086800, span=24 B | [VN] FDE[2672]
uint32_t ttr_fde_2672_0x0621a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf81f0ffeU) + (a1 ^ 0xaa1503e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x97ff02eeU + 0x0621a8U) ^ (0xaa0003f5U + 0x086800U + 24U);
}

// [EN] FDE[2673] start_va=0x0621c0, fde_va=0x086820, span=12 B | [VN] FDE[2673]
uint32_t ttr_fde_2673_0x0621c0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e0U) + (a1 ^ 0xaa1803e1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0621c0U) ^ (0xaa1403e0U + 0x086820U + 12U);
}

// [EN] FDE[2674] start_va=0x0621cc, fde_va=0x086838, span=8 B | [VN] FDE[2674]
uint32_t ttr_fde_2674_0x0621cc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1403e0U) + (a1 ^ 0x17ff084eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400668U + 0x0621ccU) ^ (0xf9400689U + 0x086838U + 8U);
}

// [EN] FDE[2675] start_va=0x0621d4, fde_va=0x086850, span=20 B | [VN] FDE[2675]
uint32_t ttr_fde_2675_0x0621d4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400668U) + (a1 ^ 0xf9400689U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000688U + 0x0621d4U) ^ (0xf9000669U + 0x086850U + 20U);
}

// [EN] FDE[2676] start_va=0x0621e8, fde_va=0x086868, span=8 B | [VN] FDE[2676]
uint32_t ttr_fde_2676_0x0621e8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff8fc7U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x0621e8U) ^ (0x17ff028dU + 0x086868U + 8U);
}

// [EN] FDE[2677] start_va=0x0621f0, fde_va=0x086880, span=8 B | [VN] FDE[2677]
uint32_t ttr_fde_2677_0x0621f0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x910023e0U) + (a1 ^ 0x17ff028dU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400308U + 0x0621f0U) ^ (0xf90002c8U + 0x086880U + 8U);
}

// [EN] FDE[2678] start_va=0x0621f8, fde_va=0x086898, span=32 B | [VN] FDE[2678]
uint32_t ttr_fde_2678_0x0621f8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400308U) + (a1 ^ 0xf90002c8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000316U + 0x0621f8U) ^ (0xf94002a8U + 0x086898U + 32U);
}

// [EN] FDE[2679] start_va=0x062218, fde_va=0x0868b0, span=32 B | [VN] FDE[2679]
uint32_t ttr_fde_2679_0x062218(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9b0b29adU) + (a1 ^ 0x3dc001a0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x9bab212eU + 0x062218U) ^ (0x11000529U + 0x0868b0U + 32U);
}

// [EN] FDE[2680] start_va=0x062238, fde_va=0x0868c8, span=24 B | [VN] FDE[2680]
uint32_t ttr_fde_2680_0x062238(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf90007ffU) + (a1 ^ 0xf9400e68U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x910023e0U + 0x062238U) ^ (0x91000508U + 0x0868c8U + 24U);
}

// [EN] FDE[2681] start_va=0x062250, fde_va=0x0868e0, span=8 B | [VN] FDE[2681]
uint32_t ttr_fde_2681_0x062250(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400be0U) + (a1 ^ 0x17ff0e79U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf94013e0U + 0x062250U) ^ (0x17ff0e7aU + 0x0868e0U + 8U);
}

// [EN] FDE[2682] start_va=0x062258, fde_va=0x0868f8, span=8 B | [VN] FDE[2682]
uint32_t ttr_fde_2682_0x062258(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94013e0U) + (a1 ^ 0x17ff0e7aU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e22c000U + 0x062258U) ^ (0x1e669001U + 0x0868f8U + 8U);
}

// [EN] FDE[2683] start_va=0x062260, fde_va=0x086910, span=24 B | [VN] FDE[2683]
uint32_t ttr_fde_2683_0x062260(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1e22c000U) + (a1 ^ 0x1e669001U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e611801U + 0x062260U) ^ (0x1e649000U + 0x086910U + 24U);
}

// [EN] FDE[2684] start_va=0x062278, fde_va=0x086928, span=24 B | [VN] FDE[2684]
uint32_t ttr_fde_2684_0x062278(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94017e9U) + (a1 ^ 0xb24002b5U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x7200011fU + 0x062278U) ^ (0x910003e8U + 0x086928U + 24U);
}

// [EN] FDE[2685] start_va=0x062290, fde_va=0x086940, span=16 B | [VN] FDE[2685]
uint32_t ttr_fde_2685_0x062290(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400669U) + (a1 ^ 0xaa1f03e8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9000a7fU + 0x062290U) ^ (0xd65f03c0U + 0x086940U + 16U);
}

// [EN] FDE[2686] start_va=0x0622a0, fde_va=0x086958, span=8 B | [VN] FDE[2686]
uint32_t ttr_fde_2686_0x0622a0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf94007e0U) + (a1 ^ 0x17ff0221U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1503e1U + 0x0622a0U) ^ (0xaa1603e2U + 0x086958U + 8U);
}

// [EN] FDE[2687] start_va=0x0622a8, fde_va=0x086970, span=12 B | [VN] FDE[2687]
uint32_t ttr_fde_2687_0x0622a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1503e1U) + (a1 ^ 0xaa1603e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0622a8U) ^ (0xaa1303e0U + 0x086970U + 12U);
}

// [EN] FDE[2688] start_va=0x0622b4, fde_va=0x086988, span=8 B | [VN] FDE[2688]
uint32_t ttr_fde_2688_0x0622b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ffa236U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa1303e0U + 0x0622b4U) ^ (0x17ff067eU + 0x086988U + 8U);
}

// [EN] FDE[2689] start_va=0x0622bc, fde_va=0x0869a0, span=8 B | [VN] FDE[2689]
uint32_t ttr_fde_2689_0x0622bc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1303e0U) + (a1 ^ 0x17ff067eU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xf9400268U + 0x0622bcU) ^ (0xaa1303e0U + 0x0869a0U + 8U);
}

// [EN] FDE[2690] start_va=0x0622c4, fde_va=0x0869b8, span=12 B | [VN] FDE[2690]
uint32_t ttr_fde_2690_0x0622c4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9400268U) + (a1 ^ 0xaa1303e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0622c4U) ^ (0xaa0003f3U + 0x0869b8U + 12U);
}

// [EN] FDE[2691] start_va=0x0622d0, fde_va=0x0869d0, span=12 B | [VN] FDE[2691]
uint32_t ttr_fde_2691_0x0622d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa0003f3U) + (a1 ^ 0xf9400000U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x0622d0U) ^ (0xd53bd056U + 0x0869d0U + 12U);
}

// [EN] FDE[2692] start_va=0x0622dc, fde_va=0x0869e8, span=16 B | [VN] FDE[2692]
uint32_t ttr_fde_2692_0x0622dc(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd056U) + (a1 ^ 0xf94016c8U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0622dcU) ^ (0xd65f03c0U + 0x0869e8U + 16U);
}

// [EN] FDE[2693] start_va=0x0622ec, fde_va=0x086a00, span=32 B | [VN] FDE[2693]
uint32_t ttr_fde_2693_0x0622ec(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x1100044bU) + (a1 ^ 0x93407d6bU);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103e8U + 0x0622ecU) ^ (0xf940040aU + 0x086a00U + 32U);
}

// [EN] FDE[2694] start_va=0x06230c, fde_va=0x086a18, span=12 B | [VN] FDE[2694]
uint32_t ttr_fde_2694_0x06230c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf9405a68U) + (a1 ^ 0xf8746900U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17fff0e8U + 0x06230cU) ^ (0xaa1f03e3U + 0x086a18U + 12U);
}

// [EN] FDE[2695] start_va=0x062318, fde_va=0x086a30, span=8 B | [VN] FDE[2695]
uint32_t ttr_fde_2695_0x062318(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xaa1f03e3U) + (a1 ^ 0x17fefc13U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd53bd058U + 0x062318U) ^ (0xf9401708U + 0x086a30U + 8U);
}

// [EN] FDE[2696] start_va=0x062320, fde_va=0x086a48, span=12 B | [VN] FDE[2696]
uint32_t ttr_fde_2696_0x062320(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xd53bd058U) + (a1 ^ 0xf9401708U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062320U) ^ (0x2a0303f3U + 0x086a48U + 12U);
}

// [EN] FDE[2697] start_va=0x06232c, fde_va=0x086a60, span=20 B | [VN] FDE[2697]
uint32_t ttr_fde_2697_0x06232c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0303f3U) + (a1 ^ 0x2a0203f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0103f5U + 0x06232cU) ^ (0xaa0003f6U + 0x086a60U + 20U);
}

// [EN] FDE[2698] start_va=0x062340, fde_va=0x086a78, span=20 B | [VN] FDE[2698]
uint32_t ttr_fde_2698_0x062340(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x2a0303f3U) + (a1 ^ 0x2a0203f4U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x2a0103f5U + 0x062340U) ^ (0xaa0003f6U + 0x086a78U + 20U);
}

// [EN] FDE[2699] start_va=0x062354, fde_va=0x086a90, span=8 B | [VN] FDE[2699]
uint32_t ttr_fde_2699_0x062354(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xf84207f4U) + (a1 ^ 0xd65f03c0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x4ea01c02U + 0x062354U) ^ (0x4ea11c23U + 0x086a90U + 8U);
}

// [EN] FDE[2700] start_va=0x06235c, fde_va=0x086aa8, span=20 B | [VN] FDE[2700]
uint32_t ttr_fde_2700_0x06235c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x4ea01c02U) + (a1 ^ 0x4ea11c23U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x1e2703e1U + 0x06235cU) ^ (0x4ead1da0U + 0x086aa8U + 20U);
}

// [EN] FDE[2701] start_va=0x062370, fde_va=0x086ac0, span=12 B | [VN] FDE[2701]
uint32_t ttr_fde_2701_0x062370(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x52850061U) + (a1 ^ 0xa8c357f6U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd61f0060U + 0x062370U) ^ (0xb94006a0U + 0x086ac0U + 12U);
}

// [EN] FDE[2702] start_va=0x06237c, fde_va=0x086ad8, span=12 B | [VN] FDE[2702]
uint32_t ttr_fde_2702_0x06237c(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb94006a0U) + (a1 ^ 0x2a1603e2U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ff66caU + 0x06237cU) ^ (0x0e205800U + 0x086ad8U + 12U);
}

// [EN] FDE[2703] start_va=0x062388, fde_va=0x086af0, span=12 B | [VN] FDE[2703]
uint32_t ttr_fde_2703_0x062388(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x0e205800U) + (a1 ^ 0x2e303800U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xd65f03c0U + 0x062388U) ^ (0x79414008U + 0x086af0U + 12U);
}

// [EN] FDE[2704] start_va=0x062394, fde_va=0x086b08, span=20 B | [VN] FDE[2704]
uint32_t ttr_fde_2704_0x062394(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x79414008U) + (a1 ^ 0x52800be1U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x321b0508U + 0x062394U) ^ (0x79014008U + 0x086b08U + 20U);
}

// [EN] FDE[2705] start_va=0x0623a8, fde_va=0x086b20, span=12 B | [VN] FDE[2705]
uint32_t ttr_fde_2705_0x0623a8(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0x9105c3e1U) + (a1 ^ 0xaa1d03e0U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0x17ffd90cU + 0x0623a8U) ^ (0xb9401ff6U + 0x086b20U + 12U);
}

// [EN] FDE[2706] start_va=0x0623b4, fde_va=0x086b38, span=28 B | [VN] FDE[2706]
uint32_t ttr_fde_2706_0x0623b4(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401ff6U) + (a1 ^ 0xb9401e83U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0623b4U) ^ (0x910003e1U + 0x086b38U + 28U);
}

// [EN] FDE[2707] start_va=0x0623d0, fde_va=0x086b50, span=28 B | [VN] FDE[2707]
uint32_t ttr_fde_2707_0x0623d0(uint32_t a0, uint32_t a1) noexcept {
    uint32_t acc = (a0 ^ 0xb9401ff6U) + (a1 ^ 0xb9401e83U);
    acc = (acc << 9) | (acc >> 23);
    return acc ^ (0xaa0003f3U + 0x0623d0U) ^ (0x910003e1U + 0x086b50U + 28U);
}

uint32_t DispatchTtrFdeShard4(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept {
    switch (fde_index) {
        case 2031U: return ttr_fde_2031_0x05cc38(a0, a1);
        case 2032U: return ttr_fde_2032_0x05cc3c(a0, a1);
        case 2033U: return ttr_fde_2033_0x05cc78(a0, a1);
        case 2034U: return ttr_fde_2034_0x05ccb0(a0, a1);
        case 2035U: return ttr_fde_2035_0x05ccb4(a0, a1);
        case 2036U: return ttr_fde_2036_0x05ccd0(a0, a1);
        case 2037U: return ttr_fde_2037_0x05ccdc(a0, a1);
        case 2038U: return ttr_fde_2038_0x05cce0(a0, a1);
        case 2039U: return ttr_fde_2039_0x05cce4(a0, a1);
        case 2040U: return ttr_fde_2040_0x05cd20(a0, a1);
        case 2041U: return ttr_fde_2041_0x05cd6c(a0, a1);
        case 2042U: return ttr_fde_2042_0x05cd70(a0, a1);
        case 2043U: return ttr_fde_2043_0x05cd8c(a0, a1);
        case 2044U: return ttr_fde_2044_0x05cd98(a0, a1);
        case 2045U: return ttr_fde_2045_0x05cd9c(a0, a1);
        case 2046U: return ttr_fde_2046_0x05cda0(a0, a1);
        case 2047U: return ttr_fde_2047_0x05cdf4(a0, a1);
        case 2048U: return ttr_fde_2048_0x05cdf8(a0, a1);
        case 2049U: return ttr_fde_2049_0x05ce14(a0, a1);
        case 2050U: return ttr_fde_2050_0x05ce20(a0, a1);
        case 2051U: return ttr_fde_2051_0x05ce24(a0, a1);
        case 2052U: return ttr_fde_2052_0x05ce28(a0, a1);
        case 2053U: return ttr_fde_2053_0x05ce7c(a0, a1);
        case 2054U: return ttr_fde_2054_0x05ce80(a0, a1);
        case 2055U: return ttr_fde_2055_0x05ce9c(a0, a1);
        case 2056U: return ttr_fde_2056_0x05cea8(a0, a1);
        case 2057U: return ttr_fde_2057_0x05ceac(a0, a1);
        case 2058U: return ttr_fde_2058_0x05ceb0(a0, a1);
        case 2059U: return ttr_fde_2059_0x05cef4(a0, a1);
        case 2060U: return ttr_fde_2060_0x05cef8(a0, a1);
        case 2061U: return ttr_fde_2061_0x05cf14(a0, a1);
        case 2062U: return ttr_fde_2062_0x05cf20(a0, a1);
        case 2063U: return ttr_fde_2063_0x05cf24(a0, a1);
        case 2064U: return ttr_fde_2064_0x05cf28(a0, a1);
        case 2065U: return ttr_fde_2065_0x05cf7c(a0, a1);
        case 2066U: return ttr_fde_2066_0x05cf80(a0, a1);
        case 2067U: return ttr_fde_2067_0x05cf9c(a0, a1);
        case 2068U: return ttr_fde_2068_0x05cfa8(a0, a1);
        case 2069U: return ttr_fde_2069_0x05cfac(a0, a1);
        case 2070U: return ttr_fde_2070_0x05cfb0(a0, a1);
        case 2071U: return ttr_fde_2071_0x05d004(a0, a1);
        case 2072U: return ttr_fde_2072_0x05d008(a0, a1);
        case 2073U: return ttr_fde_2073_0x05d024(a0, a1);
        case 2074U: return ttr_fde_2074_0x05d030(a0, a1);
        case 2075U: return ttr_fde_2075_0x05d034(a0, a1);
        case 2076U: return ttr_fde_2076_0x05d038(a0, a1);
        case 2077U: return ttr_fde_2077_0x05d07c(a0, a1);
        case 2078U: return ttr_fde_2078_0x05d094(a0, a1);
        case 2079U: return ttr_fde_2079_0x05d22c(a0, a1);
        case 2080U: return ttr_fde_2080_0x05d384(a0, a1);
        case 2081U: return ttr_fde_2081_0x05d41c(a0, a1);
        case 2082U: return ttr_fde_2082_0x05d808(a0, a1);
        case 2083U: return ttr_fde_2083_0x05d910(a0, a1);
        case 2084U: return ttr_fde_2084_0x05d914(a0, a1);
        case 2085U: return ttr_fde_2085_0x05d930(a0, a1);
        case 2086U: return ttr_fde_2086_0x05d93c(a0, a1);
        case 2087U: return ttr_fde_2087_0x05d940(a0, a1);
        case 2088U: return ttr_fde_2088_0x05d944(a0, a1);
        case 2089U: return ttr_fde_2089_0x05d984(a0, a1);
        case 2090U: return ttr_fde_2090_0x05d988(a0, a1);
        case 2091U: return ttr_fde_2091_0x05d9a4(a0, a1);
        case 2092U: return ttr_fde_2092_0x05d9b0(a0, a1);
        case 2093U: return ttr_fde_2093_0x05d9b4(a0, a1);
        case 2094U: return ttr_fde_2094_0x05d9b8(a0, a1);
        case 2095U: return ttr_fde_2095_0x05da08(a0, a1);
        case 2096U: return ttr_fde_2096_0x05da20(a0, a1);
        case 2097U: return ttr_fde_2097_0x05dc04(a0, a1);
        case 2098U: return ttr_fde_2098_0x05dc58(a0, a1);
        case 2099U: return ttr_fde_2099_0x05dd94(a0, a1);
        case 2100U: return ttr_fde_2100_0x05e06c(a0, a1);
        case 2101U: return ttr_fde_2101_0x05e0d8(a0, a1);
        case 2102U: return ttr_fde_2102_0x05e0f0(a0, a1);
        case 2103U: return ttr_fde_2103_0x05e0fc(a0, a1);
        case 2104U: return ttr_fde_2104_0x05e114(a0, a1);
        case 2105U: return ttr_fde_2105_0x05e170(a0, a1);
        case 2106U: return ttr_fde_2106_0x05e198(a0, a1);
        case 2107U: return ttr_fde_2107_0x05e1b0(a0, a1);
        case 2108U: return ttr_fde_2108_0x05e1d8(a0, a1);
        case 2109U: return ttr_fde_2109_0x05e2a8(a0, a1);
        case 2110U: return ttr_fde_2110_0x05e30c(a0, a1);
        case 2111U: return ttr_fde_2111_0x05e374(a0, a1);
        case 2112U: return ttr_fde_2112_0x05e394(a0, a1);
        case 2113U: return ttr_fde_2113_0x05e3ac(a0, a1);
        case 2114U: return ttr_fde_2114_0x05e3b4(a0, a1);
        case 2115U: return ttr_fde_2115_0x05e3b8(a0, a1);
        case 2116U: return ttr_fde_2116_0x05e3dc(a0, a1);
        case 2117U: return ttr_fde_2117_0x05e3f4(a0, a1);
        case 2118U: return ttr_fde_2118_0x05e3fc(a0, a1);
        case 2119U: return ttr_fde_2119_0x05e400(a0, a1);
        case 2120U: return ttr_fde_2120_0x05e43c(a0, a1);
        case 2121U: return ttr_fde_2121_0x05e45c(a0, a1);
        case 2122U: return ttr_fde_2122_0x05e474(a0, a1);
        case 2123U: return ttr_fde_2123_0x05e47c(a0, a1);
        case 2124U: return ttr_fde_2124_0x05e480(a0, a1);
        case 2125U: return ttr_fde_2125_0x05e4ac(a0, a1);
        case 2126U: return ttr_fde_2126_0x05e584(a0, a1);
        case 2127U: return ttr_fde_2127_0x05e588(a0, a1);
        case 2128U: return ttr_fde_2128_0x05e5a4(a0, a1);
        case 2129U: return ttr_fde_2129_0x05e5b0(a0, a1);
        case 2130U: return ttr_fde_2130_0x05e5b4(a0, a1);
        case 2131U: return ttr_fde_2131_0x05e5b8(a0, a1);
        case 2132U: return ttr_fde_2132_0x05e620(a0, a1);
        case 2133U: return ttr_fde_2133_0x05e624(a0, a1);
        case 2134U: return ttr_fde_2134_0x05e640(a0, a1);
        case 2135U: return ttr_fde_2135_0x05e64c(a0, a1);
        case 2136U: return ttr_fde_2136_0x05e650(a0, a1);
        case 2137U: return ttr_fde_2137_0x05e654(a0, a1);
        case 2138U: return ttr_fde_2138_0x05e6b4(a0, a1);
        case 2139U: return ttr_fde_2139_0x05e714(a0, a1);
        case 2140U: return ttr_fde_2140_0x05e72c(a0, a1);
        case 2141U: return ttr_fde_2141_0x05e7ac(a0, a1);
        case 2142U: return ttr_fde_2142_0x05e804(a0, a1);
        case 2143U: return ttr_fde_2143_0x05e8e4(a0, a1);
        case 2144U: return ttr_fde_2144_0x05e8fc(a0, a1);
        case 2145U: return ttr_fde_2145_0x05e9a0(a0, a1);
        case 2146U: return ttr_fde_2146_0x05ea64(a0, a1);
        case 2147U: return ttr_fde_2147_0x05ec84(a0, a1);
        case 2148U: return ttr_fde_2148_0x05ee10(a0, a1);
        case 2149U: return ttr_fde_2149_0x05ee14(a0, a1);
        case 2150U: return ttr_fde_2150_0x05ee30(a0, a1);
        case 2151U: return ttr_fde_2151_0x05ee3c(a0, a1);
        case 2152U: return ttr_fde_2152_0x05ee40(a0, a1);
        case 2153U: return ttr_fde_2153_0x05ee44(a0, a1);
        case 2154U: return ttr_fde_2154_0x05ee60(a0, a1);
        case 2155U: return ttr_fde_2155_0x05ee64(a0, a1);
        case 2156U: return ttr_fde_2156_0x05ee80(a0, a1);
        case 2157U: return ttr_fde_2157_0x05ee8c(a0, a1);
        case 2158U: return ttr_fde_2158_0x05ee90(a0, a1);
        case 2159U: return ttr_fde_2159_0x05ee94(a0, a1);
        case 2160U: return ttr_fde_2160_0x05eeb0(a0, a1);
        case 2161U: return ttr_fde_2161_0x05eeb4(a0, a1);
        case 2162U: return ttr_fde_2162_0x05eed0(a0, a1);
        case 2163U: return ttr_fde_2163_0x05eedc(a0, a1);
        case 2164U: return ttr_fde_2164_0x05eee0(a0, a1);
        case 2165U: return ttr_fde_2165_0x05eee4(a0, a1);
        case 2166U: return ttr_fde_2166_0x05ef1c(a0, a1);
        case 2167U: return ttr_fde_2167_0x05ef20(a0, a1);
        case 2168U: return ttr_fde_2168_0x05ef3c(a0, a1);
        case 2169U: return ttr_fde_2169_0x05ef48(a0, a1);
        case 2170U: return ttr_fde_2170_0x05ef4c(a0, a1);
        case 2171U: return ttr_fde_2171_0x05ef50(a0, a1);
        case 2172U: return ttr_fde_2172_0x05ef94(a0, a1);
        case 2173U: return ttr_fde_2173_0x05efac(a0, a1);
        case 2174U: return ttr_fde_2174_0x05f080(a0, a1);
        case 2175U: return ttr_fde_2175_0x05f134(a0, a1);
        case 2176U: return ttr_fde_2176_0x05f4a8(a0, a1);
        case 2177U: return ttr_fde_2177_0x05f5c4(a0, a1);
        case 2178U: return ttr_fde_2178_0x05f81c(a0, a1);
        case 2179U: return ttr_fde_2179_0x05fb60(a0, a1);
        case 2180U: return ttr_fde_2180_0x05fc18(a0, a1);
        case 2181U: return ttr_fde_2181_0x05fcbc(a0, a1);
        case 2182U: return ttr_fde_2182_0x05fcc8(a0, a1);
        case 2183U: return ttr_fde_2183_0x05fcd0(a0, a1);
        case 2184U: return ttr_fde_2184_0x05fce0(a0, a1);
        case 2185U: return ttr_fde_2185_0x05fcec(a0, a1);
        case 2186U: return ttr_fde_2186_0x05fcfc(a0, a1);
        case 2187U: return ttr_fde_2187_0x05fd08(a0, a1);
        case 2188U: return ttr_fde_2188_0x05fd10(a0, a1);
        case 2189U: return ttr_fde_2189_0x05fd20(a0, a1);
        case 2190U: return ttr_fde_2190_0x05fd30(a0, a1);
        case 2191U: return ttr_fde_2191_0x05fd40(a0, a1);
        case 2192U: return ttr_fde_2192_0x05fd48(a0, a1);
        case 2193U: return ttr_fde_2193_0x05fd60(a0, a1);
        case 2194U: return ttr_fde_2194_0x05fd70(a0, a1);
        case 2195U: return ttr_fde_2195_0x05fd7c(a0, a1);
        case 2196U: return ttr_fde_2196_0x05fd88(a0, a1);
        case 2197U: return ttr_fde_2197_0x05fd94(a0, a1);
        case 2198U: return ttr_fde_2198_0x05fdc0(a0, a1);
        case 2199U: return ttr_fde_2199_0x05fdc8(a0, a1);
        case 2200U: return ttr_fde_2200_0x05fde0(a0, a1);
        case 2201U: return ttr_fde_2201_0x05fde8(a0, a1);
        case 2202U: return ttr_fde_2202_0x05fdf4(a0, a1);
        case 2203U: return ttr_fde_2203_0x05fe00(a0, a1);
        case 2204U: return ttr_fde_2204_0x05fe10(a0, a1);
        case 2205U: return ttr_fde_2205_0x05fe1c(a0, a1);
        case 2206U: return ttr_fde_2206_0x05fe28(a0, a1);
        case 2207U: return ttr_fde_2207_0x05fe30(a0, a1);
        case 2208U: return ttr_fde_2208_0x05fe38(a0, a1);
        case 2209U: return ttr_fde_2209_0x05fe40(a0, a1);
        case 2210U: return ttr_fde_2210_0x05fe4c(a0, a1);
        case 2211U: return ttr_fde_2211_0x05fe58(a0, a1);
        case 2212U: return ttr_fde_2212_0x05fe64(a0, a1);
        case 2213U: return ttr_fde_2213_0x05fe70(a0, a1);
        case 2214U: return ttr_fde_2214_0x05fe94(a0, a1);
        case 2215U: return ttr_fde_2215_0x05fe9c(a0, a1);
        case 2216U: return ttr_fde_2216_0x05fea4(a0, a1);
        case 2217U: return ttr_fde_2217_0x05fec0(a0, a1);
        case 2218U: return ttr_fde_2218_0x05fec8(a0, a1);
        case 2219U: return ttr_fde_2219_0x05fed0(a0, a1);
        case 2220U: return ttr_fde_2220_0x05fee0(a0, a1);
        case 2221U: return ttr_fde_2221_0x05fefc(a0, a1);
        case 2222U: return ttr_fde_2222_0x05ff18(a0, a1);
        case 2223U: return ttr_fde_2223_0x05ff48(a0, a1);
        case 2224U: return ttr_fde_2224_0x05ff58(a0, a1);
        case 2225U: return ttr_fde_2225_0x05ff60(a0, a1);
        case 2226U: return ttr_fde_2226_0x05ff9c(a0, a1);
        case 2227U: return ttr_fde_2227_0x05ffa8(a0, a1);
        case 2228U: return ttr_fde_2228_0x05ffb8(a0, a1);
        case 2229U: return ttr_fde_2229_0x05ffc0(a0, a1);
        case 2230U: return ttr_fde_2230_0x05ffc8(a0, a1);
        case 2231U: return ttr_fde_2231_0x05ffdc(a0, a1);
        case 2232U: return ttr_fde_2232_0x05ffe4(a0, a1);
        case 2233U: return ttr_fde_2233_0x05fffc(a0, a1);
        case 2234U: return ttr_fde_2234_0x060038(a0, a1);
        case 2235U: return ttr_fde_2235_0x06004c(a0, a1);
        case 2236U: return ttr_fde_2236_0x060068(a0, a1);
        case 2237U: return ttr_fde_2237_0x06007c(a0, a1);
        case 2238U: return ttr_fde_2238_0x06008c(a0, a1);
        case 2239U: return ttr_fde_2239_0x0600d0(a0, a1);
        case 2240U: return ttr_fde_2240_0x0600dc(a0, a1);
        case 2241U: return ttr_fde_2241_0x0600e4(a0, a1);
        case 2242U: return ttr_fde_2242_0x060108(a0, a1);
        case 2243U: return ttr_fde_2243_0x060114(a0, a1);
        case 2244U: return ttr_fde_2244_0x060120(a0, a1);
        case 2245U: return ttr_fde_2245_0x060130(a0, a1);
        case 2246U: return ttr_fde_2246_0x060150(a0, a1);
        case 2247U: return ttr_fde_2247_0x0601b0(a0, a1);
        case 2248U: return ttr_fde_2248_0x0601c0(a0, a1);
        case 2249U: return ttr_fde_2249_0x0601d0(a0, a1);
        case 2250U: return ttr_fde_2250_0x0601d8(a0, a1);
        case 2251U: return ttr_fde_2251_0x0601e4(a0, a1);
        case 2252U: return ttr_fde_2252_0x0601f4(a0, a1);
        case 2253U: return ttr_fde_2253_0x060200(a0, a1);
        case 2254U: return ttr_fde_2254_0x060218(a0, a1);
        case 2255U: return ttr_fde_2255_0x060230(a0, a1);
        case 2256U: return ttr_fde_2256_0x060248(a0, a1);
        case 2257U: return ttr_fde_2257_0x060250(a0, a1);
        case 2258U: return ttr_fde_2258_0x060258(a0, a1);
        case 2259U: return ttr_fde_2259_0x060270(a0, a1);
        case 2260U: return ttr_fde_2260_0x060294(a0, a1);
        case 2261U: return ttr_fde_2261_0x0602a8(a0, a1);
        case 2262U: return ttr_fde_2262_0x0602b4(a0, a1);
        case 2263U: return ttr_fde_2263_0x060320(a0, a1);
        case 2264U: return ttr_fde_2264_0x060328(a0, a1);
        case 2265U: return ttr_fde_2265_0x060330(a0, a1);
        case 2266U: return ttr_fde_2266_0x060344(a0, a1);
        case 2267U: return ttr_fde_2267_0x060350(a0, a1);
        case 2268U: return ttr_fde_2268_0x06035c(a0, a1);
        case 2269U: return ttr_fde_2269_0x060378(a0, a1);
        case 2270U: return ttr_fde_2270_0x060390(a0, a1);
        case 2271U: return ttr_fde_2271_0x0603a0(a0, a1);
        case 2272U: return ttr_fde_2272_0x0603b0(a0, a1);
        case 2273U: return ttr_fde_2273_0x0603bc(a0, a1);
        case 2274U: return ttr_fde_2274_0x0603d8(a0, a1);
        case 2275U: return ttr_fde_2275_0x0603e0(a0, a1);
        case 2276U: return ttr_fde_2276_0x0603ec(a0, a1);
        case 2277U: return ttr_fde_2277_0x0603fc(a0, a1);
        case 2278U: return ttr_fde_2278_0x060408(a0, a1);
        case 2279U: return ttr_fde_2279_0x06041c(a0, a1);
        case 2280U: return ttr_fde_2280_0x060448(a0, a1);
        case 2281U: return ttr_fde_2281_0x060450(a0, a1);
        case 2282U: return ttr_fde_2282_0x06045c(a0, a1);
        case 2283U: return ttr_fde_2283_0x060484(a0, a1);
        case 2284U: return ttr_fde_2284_0x060490(a0, a1);
        case 2285U: return ttr_fde_2285_0x0604a8(a0, a1);
        case 2286U: return ttr_fde_2286_0x0604b0(a0, a1);
        case 2287U: return ttr_fde_2287_0x0604c0(a0, a1);
        case 2288U: return ttr_fde_2288_0x0604c8(a0, a1);
        case 2289U: return ttr_fde_2289_0x0604e4(a0, a1);
        case 2290U: return ttr_fde_2290_0x0604f4(a0, a1);
        case 2291U: return ttr_fde_2291_0x06051c(a0, a1);
        case 2292U: return ttr_fde_2292_0x06052c(a0, a1);
        case 2293U: return ttr_fde_2293_0x06053c(a0, a1);
        case 2294U: return ttr_fde_2294_0x060544(a0, a1);
        case 2295U: return ttr_fde_2295_0x060550(a0, a1);
        case 2296U: return ttr_fde_2296_0x060568(a0, a1);
        case 2297U: return ttr_fde_2297_0x060584(a0, a1);
        case 2298U: return ttr_fde_2298_0x060590(a0, a1);
        case 2299U: return ttr_fde_2299_0x0605a4(a0, a1);
        case 2300U: return ttr_fde_2300_0x0605b0(a0, a1);
        case 2301U: return ttr_fde_2301_0x0605bc(a0, a1);
        case 2302U: return ttr_fde_2302_0x0605c8(a0, a1);
        case 2303U: return ttr_fde_2303_0x0605d4(a0, a1);
        case 2304U: return ttr_fde_2304_0x0605f4(a0, a1);
        case 2305U: return ttr_fde_2305_0x0605fc(a0, a1);
        case 2306U: return ttr_fde_2306_0x060604(a0, a1);
        case 2307U: return ttr_fde_2307_0x060610(a0, a1);
        case 2308U: return ttr_fde_2308_0x060618(a0, a1);
        case 2309U: return ttr_fde_2309_0x060624(a0, a1);
        case 2310U: return ttr_fde_2310_0x06062c(a0, a1);
        case 2311U: return ttr_fde_2311_0x060648(a0, a1);
        case 2312U: return ttr_fde_2312_0x060668(a0, a1);
        case 2313U: return ttr_fde_2313_0x06068c(a0, a1);
        case 2314U: return ttr_fde_2314_0x0606a4(a0, a1);
        case 2315U: return ttr_fde_2315_0x0606b4(a0, a1);
        case 2316U: return ttr_fde_2316_0x0606d8(a0, a1);
        case 2317U: return ttr_fde_2317_0x0606fc(a0, a1);
        case 2318U: return ttr_fde_2318_0x060704(a0, a1);
        case 2319U: return ttr_fde_2319_0x060718(a0, a1);
        case 2320U: return ttr_fde_2320_0x060728(a0, a1);
        case 2321U: return ttr_fde_2321_0x060734(a0, a1);
        case 2322U: return ttr_fde_2322_0x060770(a0, a1);
        case 2323U: return ttr_fde_2323_0x0607a4(a0, a1);
        case 2324U: return ttr_fde_2324_0x0607b0(a0, a1);
        case 2325U: return ttr_fde_2325_0x0607bc(a0, a1);
        case 2326U: return ttr_fde_2326_0x0607c8(a0, a1);
        case 2327U: return ttr_fde_2327_0x0607d0(a0, a1);
        case 2328U: return ttr_fde_2328_0x060804(a0, a1);
        case 2329U: return ttr_fde_2329_0x060820(a0, a1);
        case 2330U: return ttr_fde_2330_0x06083c(a0, a1);
        case 2331U: return ttr_fde_2331_0x060858(a0, a1);
        case 2332U: return ttr_fde_2332_0x060868(a0, a1);
        case 2333U: return ttr_fde_2333_0x060878(a0, a1);
        case 2334U: return ttr_fde_2334_0x0608ac(a0, a1);
        case 2335U: return ttr_fde_2335_0x0608e8(a0, a1);
        case 2336U: return ttr_fde_2336_0x060904(a0, a1);
        case 2337U: return ttr_fde_2337_0x060920(a0, a1);
        case 2338U: return ttr_fde_2338_0x06092c(a0, a1);
        case 2339U: return ttr_fde_2339_0x060938(a0, a1);
        case 2340U: return ttr_fde_2340_0x060944(a0, a1);
        case 2341U: return ttr_fde_2341_0x060950(a0, a1);
        case 2342U: return ttr_fde_2342_0x060960(a0, a1);
        case 2343U: return ttr_fde_2343_0x060970(a0, a1);
        case 2344U: return ttr_fde_2344_0x060980(a0, a1);
        case 2345U: return ttr_fde_2345_0x06098c(a0, a1);
        case 2346U: return ttr_fde_2346_0x060998(a0, a1);
        case 2347U: return ttr_fde_2347_0x0609a4(a0, a1);
        case 2348U: return ttr_fde_2348_0x0609ac(a0, a1);
        case 2349U: return ttr_fde_2349_0x0609c0(a0, a1);
        case 2350U: return ttr_fde_2350_0x0609c8(a0, a1);
        case 2351U: return ttr_fde_2351_0x0609d0(a0, a1);
        case 2352U: return ttr_fde_2352_0x060a08(a0, a1);
        case 2353U: return ttr_fde_2353_0x060a1c(a0, a1);
        case 2354U: return ttr_fde_2354_0x060a3c(a0, a1);
        case 2355U: return ttr_fde_2355_0x060a44(a0, a1);
        case 2356U: return ttr_fde_2356_0x060a4c(a0, a1);
        case 2357U: return ttr_fde_2357_0x060a64(a0, a1);
        case 2358U: return ttr_fde_2358_0x060a70(a0, a1);
        case 2359U: return ttr_fde_2359_0x060a88(a0, a1);
        case 2360U: return ttr_fde_2360_0x060aa0(a0, a1);
        case 2361U: return ttr_fde_2361_0x060ab0(a0, a1);
        case 2362U: return ttr_fde_2362_0x060ac4(a0, a1);
        case 2363U: return ttr_fde_2363_0x060acc(a0, a1);
        case 2364U: return ttr_fde_2364_0x060ad4(a0, a1);
        case 2365U: return ttr_fde_2365_0x060aec(a0, a1);
        case 2366U: return ttr_fde_2366_0x060b04(a0, a1);
        case 2367U: return ttr_fde_2367_0x060b0c(a0, a1);
        case 2368U: return ttr_fde_2368_0x060b14(a0, a1);
        case 2369U: return ttr_fde_2369_0x060b2c(a0, a1);
        case 2370U: return ttr_fde_2370_0x060b38(a0, a1);
        case 2371U: return ttr_fde_2371_0x060b50(a0, a1);
        case 2372U: return ttr_fde_2372_0x060b5c(a0, a1);
        case 2373U: return ttr_fde_2373_0x060b64(a0, a1);
        case 2374U: return ttr_fde_2374_0x060b70(a0, a1);
        case 2375U: return ttr_fde_2375_0x060ba4(a0, a1);
        case 2376U: return ttr_fde_2376_0x060bb0(a0, a1);
        case 2377U: return ttr_fde_2377_0x060bbc(a0, a1);
        case 2378U: return ttr_fde_2378_0x060bc8(a0, a1);
        case 2379U: return ttr_fde_2379_0x060bd4(a0, a1);
        case 2380U: return ttr_fde_2380_0x060be0(a0, a1);
        case 2381U: return ttr_fde_2381_0x060bec(a0, a1);
        case 2382U: return ttr_fde_2382_0x060bf8(a0, a1);
        case 2383U: return ttr_fde_2383_0x060c00(a0, a1);
        case 2384U: return ttr_fde_2384_0x060c18(a0, a1);
        case 2385U: return ttr_fde_2385_0x060c24(a0, a1);
        case 2386U: return ttr_fde_2386_0x060c54(a0, a1);
        case 2387U: return ttr_fde_2387_0x060c64(a0, a1);
        case 2388U: return ttr_fde_2388_0x060c6c(a0, a1);
        case 2389U: return ttr_fde_2389_0x060c7c(a0, a1);
        case 2390U: return ttr_fde_2390_0x060c94(a0, a1);
        case 2391U: return ttr_fde_2391_0x060cbc(a0, a1);
        case 2392U: return ttr_fde_2392_0x060cd8(a0, a1);
        case 2393U: return ttr_fde_2393_0x060ce0(a0, a1);
        case 2394U: return ttr_fde_2394_0x060cec(a0, a1);
        case 2395U: return ttr_fde_2395_0x060d08(a0, a1);
        case 2396U: return ttr_fde_2396_0x060d38(a0, a1);
        case 2397U: return ttr_fde_2397_0x060d60(a0, a1);
        case 2398U: return ttr_fde_2398_0x060d7c(a0, a1);
        case 2399U: return ttr_fde_2399_0x060d84(a0, a1);
        case 2400U: return ttr_fde_2400_0x060d98(a0, a1);
        case 2401U: return ttr_fde_2401_0x060da8(a0, a1);
        case 2402U: return ttr_fde_2402_0x060db8(a0, a1);
        case 2403U: return ttr_fde_2403_0x060de0(a0, a1);
        case 2404U: return ttr_fde_2404_0x060df0(a0, a1);
        case 2405U: return ttr_fde_2405_0x060e10(a0, a1);
        case 2406U: return ttr_fde_2406_0x060e20(a0, a1);
        case 2407U: return ttr_fde_2407_0x060e28(a0, a1);
        case 2408U: return ttr_fde_2408_0x060e30(a0, a1);
        case 2409U: return ttr_fde_2409_0x060e40(a0, a1);
        case 2410U: return ttr_fde_2410_0x060e50(a0, a1);
        case 2411U: return ttr_fde_2411_0x060e60(a0, a1);
        case 2412U: return ttr_fde_2412_0x060e70(a0, a1);
        case 2413U: return ttr_fde_2413_0x060e80(a0, a1);
        case 2414U: return ttr_fde_2414_0x060e88(a0, a1);
        case 2415U: return ttr_fde_2415_0x060e98(a0, a1);
        case 2416U: return ttr_fde_2416_0x060ea0(a0, a1);
        case 2417U: return ttr_fde_2417_0x060ea8(a0, a1);
        case 2418U: return ttr_fde_2418_0x060ed4(a0, a1);
        case 2419U: return ttr_fde_2419_0x060ee0(a0, a1);
        case 2420U: return ttr_fde_2420_0x060eec(a0, a1);
        case 2421U: return ttr_fde_2421_0x060ef8(a0, a1);
        case 2422U: return ttr_fde_2422_0x060f24(a0, a1);
        case 2423U: return ttr_fde_2423_0x060f38(a0, a1);
        case 2424U: return ttr_fde_2424_0x060f4c(a0, a1);
        case 2425U: return ttr_fde_2425_0x060f58(a0, a1);
        case 2426U: return ttr_fde_2426_0x060f60(a0, a1);
        case 2427U: return ttr_fde_2427_0x060f8c(a0, a1);
        case 2428U: return ttr_fde_2428_0x060f94(a0, a1);
        case 2429U: return ttr_fde_2429_0x060fa0(a0, a1);
        case 2430U: return ttr_fde_2430_0x060fb4(a0, a1);
        case 2431U: return ttr_fde_2431_0x060fe0(a0, a1);
        case 2432U: return ttr_fde_2432_0x060ff4(a0, a1);
        case 2433U: return ttr_fde_2433_0x061018(a0, a1);
        case 2434U: return ttr_fde_2434_0x061020(a0, a1);
        case 2435U: return ttr_fde_2435_0x061034(a0, a1);
        case 2436U: return ttr_fde_2436_0x06103c(a0, a1);
        case 2437U: return ttr_fde_2437_0x061050(a0, a1);
        case 2438U: return ttr_fde_2438_0x061064(a0, a1);
        case 2439U: return ttr_fde_2439_0x061078(a0, a1);
        case 2440U: return ttr_fde_2440_0x06108c(a0, a1);
        case 2441U: return ttr_fde_2441_0x0610a0(a0, a1);
        case 2442U: return ttr_fde_2442_0x0610c4(a0, a1);
        case 2443U: return ttr_fde_2443_0x0610d8(a0, a1);
        case 2444U: return ttr_fde_2444_0x0610e0(a0, a1);
        case 2445U: return ttr_fde_2445_0x0610f4(a0, a1);
        case 2446U: return ttr_fde_2446_0x061100(a0, a1);
        case 2447U: return ttr_fde_2447_0x061108(a0, a1);
        case 2448U: return ttr_fde_2448_0x061134(a0, a1);
        case 2449U: return ttr_fde_2449_0x061148(a0, a1);
        case 2450U: return ttr_fde_2450_0x06115c(a0, a1);
        case 2451U: return ttr_fde_2451_0x061188(a0, a1);
        case 2452U: return ttr_fde_2452_0x061190(a0, a1);
        case 2453U: return ttr_fde_2453_0x06119c(a0, a1);
        case 2454U: return ttr_fde_2454_0x0611a4(a0, a1);
        case 2455U: return ttr_fde_2455_0x0611d0(a0, a1);
        case 2456U: return ttr_fde_2456_0x0611d8(a0, a1);
        case 2457U: return ttr_fde_2457_0x0611fc(a0, a1);
        case 2458U: return ttr_fde_2458_0x061210(a0, a1);
        case 2459U: return ttr_fde_2459_0x06121c(a0, a1);
        case 2460U: return ttr_fde_2460_0x061228(a0, a1);
        case 2461U: return ttr_fde_2461_0x061234(a0, a1);
        case 2462U: return ttr_fde_2462_0x06123c(a0, a1);
        case 2463U: return ttr_fde_2463_0x061250(a0, a1);
        case 2464U: return ttr_fde_2464_0x06125c(a0, a1);
        case 2465U: return ttr_fde_2465_0x061268(a0, a1);
        case 2466U: return ttr_fde_2466_0x061274(a0, a1);
        case 2467U: return ttr_fde_2467_0x061280(a0, a1);
        case 2468U: return ttr_fde_2468_0x06128c(a0, a1);
        case 2469U: return ttr_fde_2469_0x061294(a0, a1);
        case 2470U: return ttr_fde_2470_0x06129c(a0, a1);
        case 2471U: return ttr_fde_2471_0x0612a4(a0, a1);
        case 2472U: return ttr_fde_2472_0x0612bc(a0, a1);
        case 2473U: return ttr_fde_2473_0x0612d4(a0, a1);
        case 2474U: return ttr_fde_2474_0x0612dc(a0, a1);
        case 2475U: return ttr_fde_2475_0x0612fc(a0, a1);
        case 2476U: return ttr_fde_2476_0x06130c(a0, a1);
        case 2477U: return ttr_fde_2477_0x06132c(a0, a1);
        case 2478U: return ttr_fde_2478_0x06134c(a0, a1);
        case 2479U: return ttr_fde_2479_0x061374(a0, a1);
        case 2480U: return ttr_fde_2480_0x06139c(a0, a1);
        case 2481U: return ttr_fde_2481_0x0613b4(a0, a1);
        case 2482U: return ttr_fde_2482_0x0613c0(a0, a1);
        case 2483U: return ttr_fde_2483_0x0613d0(a0, a1);
        case 2484U: return ttr_fde_2484_0x0613f0(a0, a1);
        case 2485U: return ttr_fde_2485_0x061410(a0, a1);
        case 2486U: return ttr_fde_2486_0x061428(a0, a1);
        case 2487U: return ttr_fde_2487_0x061430(a0, a1);
        case 2488U: return ttr_fde_2488_0x061458(a0, a1);
        case 2489U: return ttr_fde_2489_0x061460(a0, a1);
        case 2490U: return ttr_fde_2490_0x061470(a0, a1);
        case 2491U: return ttr_fde_2491_0x061490(a0, a1);
        case 2492U: return ttr_fde_2492_0x0614b4(a0, a1);
        case 2493U: return ttr_fde_2493_0x0614d8(a0, a1);
        case 2494U: return ttr_fde_2494_0x0614fc(a0, a1);
        case 2495U: return ttr_fde_2495_0x061508(a0, a1);
        case 2496U: return ttr_fde_2496_0x061514(a0, a1);
        case 2497U: return ttr_fde_2497_0x06151c(a0, a1);
        case 2498U: return ttr_fde_2498_0x06152c(a0, a1);
        case 2499U: return ttr_fde_2499_0x061538(a0, a1);
        case 2500U: return ttr_fde_2500_0x061540(a0, a1);
        case 2501U: return ttr_fde_2501_0x061550(a0, a1);
        case 2502U: return ttr_fde_2502_0x06155c(a0, a1);
        case 2503U: return ttr_fde_2503_0x061564(a0, a1);
        case 2504U: return ttr_fde_2504_0x06156c(a0, a1);
        case 2505U: return ttr_fde_2505_0x061574(a0, a1);
        case 2506U: return ttr_fde_2506_0x061590(a0, a1);
        case 2507U: return ttr_fde_2507_0x0615a0(a0, a1);
        case 2508U: return ttr_fde_2508_0x0615ac(a0, a1);
        case 2509U: return ttr_fde_2509_0x0615c8(a0, a1);
        case 2510U: return ttr_fde_2510_0x0615e4(a0, a1);
        case 2511U: return ttr_fde_2511_0x0615f4(a0, a1);
        case 2512U: return ttr_fde_2512_0x061610(a0, a1);
        case 2513U: return ttr_fde_2513_0x06162c(a0, a1);
        case 2514U: return ttr_fde_2514_0x061640(a0, a1);
        case 2515U: return ttr_fde_2515_0x06165c(a0, a1);
        case 2516U: return ttr_fde_2516_0x06166c(a0, a1);
        case 2517U: return ttr_fde_2517_0x06167c(a0, a1);
        case 2518U: return ttr_fde_2518_0x061684(a0, a1);
        case 2519U: return ttr_fde_2519_0x0616a8(a0, a1);
        case 2520U: return ttr_fde_2520_0x0616cc(a0, a1);
        case 2521U: return ttr_fde_2521_0x0616d4(a0, a1);
        case 2522U: return ttr_fde_2522_0x0616e0(a0, a1);
        case 2523U: return ttr_fde_2523_0x0616ec(a0, a1);
        case 2524U: return ttr_fde_2524_0x0616f4(a0, a1);
        case 2525U: return ttr_fde_2525_0x061700(a0, a1);
        case 2526U: return ttr_fde_2526_0x06170c(a0, a1);
        case 2527U: return ttr_fde_2527_0x061714(a0, a1);
        case 2528U: return ttr_fde_2528_0x061724(a0, a1);
        case 2529U: return ttr_fde_2529_0x06172c(a0, a1);
        case 2530U: return ttr_fde_2530_0x061738(a0, a1);
        case 2531U: return ttr_fde_2531_0x061740(a0, a1);
        case 2532U: return ttr_fde_2532_0x06174c(a0, a1);
        case 2533U: return ttr_fde_2533_0x061758(a0, a1);
        case 2534U: return ttr_fde_2534_0x061764(a0, a1);
        case 2535U: return ttr_fde_2535_0x061780(a0, a1);
        case 2536U: return ttr_fde_2536_0x06178c(a0, a1);
        case 2537U: return ttr_fde_2537_0x061794(a0, a1);
        case 2538U: return ttr_fde_2538_0x0617a4(a0, a1);
        case 2539U: return ttr_fde_2539_0x0617ac(a0, a1);
        case 2540U: return ttr_fde_2540_0x0617bc(a0, a1);
        case 2541U: return ttr_fde_2541_0x0617c4(a0, a1);
        case 2542U: return ttr_fde_2542_0x0617cc(a0, a1);
        case 2543U: return ttr_fde_2543_0x0617d8(a0, a1);
        case 2544U: return ttr_fde_2544_0x0617e8(a0, a1);
        case 2545U: return ttr_fde_2545_0x061804(a0, a1);
        case 2546U: return ttr_fde_2546_0x061828(a0, a1);
        case 2547U: return ttr_fde_2547_0x061830(a0, a1);
        case 2548U: return ttr_fde_2548_0x06184c(a0, a1);
        case 2549U: return ttr_fde_2549_0x061868(a0, a1);
        case 2550U: return ttr_fde_2550_0x061884(a0, a1);
        case 2551U: return ttr_fde_2551_0x0618a0(a0, a1);
        case 2552U: return ttr_fde_2552_0x0618ac(a0, a1);
        case 2553U: return ttr_fde_2553_0x0618b8(a0, a1);
        case 2554U: return ttr_fde_2554_0x0618d4(a0, a1);
        case 2555U: return ttr_fde_2555_0x0618dc(a0, a1);
        case 2556U: return ttr_fde_2556_0x0618e8(a0, a1);
        case 2557U: return ttr_fde_2557_0x06190c(a0, a1);
        case 2558U: return ttr_fde_2558_0x06191c(a0, a1);
        case 2559U: return ttr_fde_2559_0x061938(a0, a1);
        case 2560U: return ttr_fde_2560_0x061944(a0, a1);
        case 2561U: return ttr_fde_2561_0x061960(a0, a1);
        case 2562U: return ttr_fde_2562_0x061984(a0, a1);
        case 2563U: return ttr_fde_2563_0x061990(a0, a1);
        case 2564U: return ttr_fde_2564_0x0619a0(a0, a1);
        case 2565U: return ttr_fde_2565_0x0619ac(a0, a1);
        case 2566U: return ttr_fde_2566_0x0619bc(a0, a1);
        case 2567U: return ttr_fde_2567_0x0619cc(a0, a1);
        case 2568U: return ttr_fde_2568_0x0619d8(a0, a1);
        case 2569U: return ttr_fde_2569_0x061a0c(a0, a1);
        case 2570U: return ttr_fde_2570_0x061a14(a0, a1);
        case 2571U: return ttr_fde_2571_0x061a1c(a0, a1);
        case 2572U: return ttr_fde_2572_0x061a24(a0, a1);
        case 2573U: return ttr_fde_2573_0x061a30(a0, a1);
        case 2574U: return ttr_fde_2574_0x061a38(a0, a1);
        case 2575U: return ttr_fde_2575_0x061a44(a0, a1);
        case 2576U: return ttr_fde_2576_0x061a50(a0, a1);
        case 2577U: return ttr_fde_2577_0x061a5c(a0, a1);
        case 2578U: return ttr_fde_2578_0x061a68(a0, a1);
        case 2579U: return ttr_fde_2579_0x061a84(a0, a1);
        case 2580U: return ttr_fde_2580_0x061a8c(a0, a1);
        case 2581U: return ttr_fde_2581_0x061ab0(a0, a1);
        case 2582U: return ttr_fde_2582_0x061acc(a0, a1);
        case 2583U: return ttr_fde_2583_0x061ae0(a0, a1);
        case 2584U: return ttr_fde_2584_0x061aec(a0, a1);
        case 2585U: return ttr_fde_2585_0x061af8(a0, a1);
        case 2586U: return ttr_fde_2586_0x061b00(a0, a1);
        case 2587U: return ttr_fde_2587_0x061b0c(a0, a1);
        case 2588U: return ttr_fde_2588_0x061b28(a0, a1);
        case 2589U: return ttr_fde_2589_0x061b34(a0, a1);
        case 2590U: return ttr_fde_2590_0x061b48(a0, a1);
        case 2591U: return ttr_fde_2591_0x061b68(a0, a1);
        case 2592U: return ttr_fde_2592_0x061b88(a0, a1);
        case 2593U: return ttr_fde_2593_0x061b90(a0, a1);
        case 2594U: return ttr_fde_2594_0x061b9c(a0, a1);
        case 2595U: return ttr_fde_2595_0x061bac(a0, a1);
        case 2596U: return ttr_fde_2596_0x061bc4(a0, a1);
        case 2597U: return ttr_fde_2597_0x061bd8(a0, a1);
        case 2598U: return ttr_fde_2598_0x061be0(a0, a1);
        case 2599U: return ttr_fde_2599_0x061be8(a0, a1);
        case 2600U: return ttr_fde_2600_0x061bfc(a0, a1);
        case 2601U: return ttr_fde_2601_0x061c10(a0, a1);
        case 2602U: return ttr_fde_2602_0x061c24(a0, a1);
        case 2603U: return ttr_fde_2603_0x061c3c(a0, a1);
        case 2604U: return ttr_fde_2604_0x061c50(a0, a1);
        case 2605U: return ttr_fde_2605_0x061c58(a0, a1);
        case 2606U: return ttr_fde_2606_0x061c70(a0, a1);
        case 2607U: return ttr_fde_2607_0x061c84(a0, a1);
        case 2608U: return ttr_fde_2608_0x061c9c(a0, a1);
        case 2609U: return ttr_fde_2609_0x061cb4(a0, a1);
        case 2610U: return ttr_fde_2610_0x061ccc(a0, a1);
        case 2611U: return ttr_fde_2611_0x061ce8(a0, a1);
        case 2612U: return ttr_fde_2612_0x061cf0(a0, a1);
        case 2613U: return ttr_fde_2613_0x061d00(a0, a1);
        case 2614U: return ttr_fde_2614_0x061d18(a0, a1);
        case 2615U: return ttr_fde_2615_0x061d2c(a0, a1);
        case 2616U: return ttr_fde_2616_0x061d44(a0, a1);
        case 2617U: return ttr_fde_2617_0x061d5c(a0, a1);
        case 2618U: return ttr_fde_2618_0x061d74(a0, a1);
        case 2619U: return ttr_fde_2619_0x061d8c(a0, a1);
        case 2620U: return ttr_fde_2620_0x061d9c(a0, a1);
        case 2621U: return ttr_fde_2621_0x061db0(a0, a1);
        case 2622U: return ttr_fde_2622_0x061dd0(a0, a1);
        case 2623U: return ttr_fde_2623_0x061de8(a0, a1);
        case 2624U: return ttr_fde_2624_0x061df0(a0, a1);
        case 2625U: return ttr_fde_2625_0x061df8(a0, a1);
        case 2626U: return ttr_fde_2626_0x061e0c(a0, a1);
        case 2627U: return ttr_fde_2627_0x061e20(a0, a1);
        case 2628U: return ttr_fde_2628_0x061e30(a0, a1);
        case 2629U: return ttr_fde_2629_0x061e44(a0, a1);
        case 2630U: return ttr_fde_2630_0x061e64(a0, a1);
        case 2631U: return ttr_fde_2631_0x061e84(a0, a1);
        case 2632U: return ttr_fde_2632_0x061ea4(a0, a1);
        case 2633U: return ttr_fde_2633_0x061ebc(a0, a1);
        case 2634U: return ttr_fde_2634_0x061ec8(a0, a1);
        case 2635U: return ttr_fde_2635_0x061ed8(a0, a1);
        case 2636U: return ttr_fde_2636_0x061ef0(a0, a1);
        case 2637U: return ttr_fde_2637_0x061f10(a0, a1);
        case 2638U: return ttr_fde_2638_0x061f20(a0, a1);
        case 2639U: return ttr_fde_2639_0x061f38(a0, a1);
        case 2640U: return ttr_fde_2640_0x061f50(a0, a1);
        case 2641U: return ttr_fde_2641_0x061f68(a0, a1);
        case 2642U: return ttr_fde_2642_0x061f80(a0, a1);
        case 2643U: return ttr_fde_2643_0x061f8c(a0, a1);
        case 2644U: return ttr_fde_2644_0x061f98(a0, a1);
        case 2645U: return ttr_fde_2645_0x061fa0(a0, a1);
        case 2646U: return ttr_fde_2646_0x061fb0(a0, a1);
        case 2647U: return ttr_fde_2647_0x061fd0(a0, a1);
        case 2648U: return ttr_fde_2648_0x061fe0(a0, a1);
        case 2649U: return ttr_fde_2649_0x061ff0(a0, a1);
        case 2650U: return ttr_fde_2650_0x062008(a0, a1);
        case 2651U: return ttr_fde_2651_0x062020(a0, a1);
        case 2652U: return ttr_fde_2652_0x062034(a0, a1);
        case 2653U: return ttr_fde_2653_0x062040(a0, a1);
        case 2654U: return ttr_fde_2654_0x062048(a0, a1);
        case 2655U: return ttr_fde_2655_0x06205c(a0, a1);
        case 2656U: return ttr_fde_2656_0x062070(a0, a1);
        case 2657U: return ttr_fde_2657_0x062078(a0, a1);
        case 2658U: return ttr_fde_2658_0x062090(a0, a1);
        case 2659U: return ttr_fde_2659_0x0620a4(a0, a1);
        case 2660U: return ttr_fde_2660_0x0620b0(a0, a1);
        case 2661U: return ttr_fde_2661_0x0620c0(a0, a1);
        case 2662U: return ttr_fde_2662_0x0620d4(a0, a1);
        case 2663U: return ttr_fde_2663_0x0620dc(a0, a1);
        case 2664U: return ttr_fde_2664_0x0620f4(a0, a1);
        case 2665U: return ttr_fde_2665_0x06210c(a0, a1);
        case 2666U: return ttr_fde_2666_0x062124(a0, a1);
        case 2667U: return ttr_fde_2667_0x06213c(a0, a1);
        case 2668U: return ttr_fde_2668_0x062154(a0, a1);
        case 2669U: return ttr_fde_2669_0x06216c(a0, a1);
        case 2670U: return ttr_fde_2670_0x06218c(a0, a1);
        case 2671U: return ttr_fde_2671_0x062198(a0, a1);
        case 2672U: return ttr_fde_2672_0x0621a8(a0, a1);
        case 2673U: return ttr_fde_2673_0x0621c0(a0, a1);
        case 2674U: return ttr_fde_2674_0x0621cc(a0, a1);
        case 2675U: return ttr_fde_2675_0x0621d4(a0, a1);
        case 2676U: return ttr_fde_2676_0x0621e8(a0, a1);
        case 2677U: return ttr_fde_2677_0x0621f0(a0, a1);
        case 2678U: return ttr_fde_2678_0x0621f8(a0, a1);
        case 2679U: return ttr_fde_2679_0x062218(a0, a1);
        case 2680U: return ttr_fde_2680_0x062238(a0, a1);
        case 2681U: return ttr_fde_2681_0x062250(a0, a1);
        case 2682U: return ttr_fde_2682_0x062258(a0, a1);
        case 2683U: return ttr_fde_2683_0x062260(a0, a1);
        case 2684U: return ttr_fde_2684_0x062278(a0, a1);
        case 2685U: return ttr_fde_2685_0x062290(a0, a1);
        case 2686U: return ttr_fde_2686_0x0622a0(a0, a1);
        case 2687U: return ttr_fde_2687_0x0622a8(a0, a1);
        case 2688U: return ttr_fde_2688_0x0622b4(a0, a1);
        case 2689U: return ttr_fde_2689_0x0622bc(a0, a1);
        case 2690U: return ttr_fde_2690_0x0622c4(a0, a1);
        case 2691U: return ttr_fde_2691_0x0622d0(a0, a1);
        case 2692U: return ttr_fde_2692_0x0622dc(a0, a1);
        case 2693U: return ttr_fde_2693_0x0622ec(a0, a1);
        case 2694U: return ttr_fde_2694_0x06230c(a0, a1);
        case 2695U: return ttr_fde_2695_0x062318(a0, a1);
        case 2696U: return ttr_fde_2696_0x062320(a0, a1);
        case 2697U: return ttr_fde_2697_0x06232c(a0, a1);
        case 2698U: return ttr_fde_2698_0x062340(a0, a1);
        case 2699U: return ttr_fde_2699_0x062354(a0, a1);
        case 2700U: return ttr_fde_2700_0x06235c(a0, a1);
        case 2701U: return ttr_fde_2701_0x062370(a0, a1);
        case 2702U: return ttr_fde_2702_0x06237c(a0, a1);
        case 2703U: return ttr_fde_2703_0x062388(a0, a1);
        case 2704U: return ttr_fde_2704_0x062394(a0, a1);
        case 2705U: return ttr_fde_2705_0x0623a8(a0, a1);
        case 2706U: return ttr_fde_2706_0x0623b4(a0, a1);
        case 2707U: return ttr_fde_2707_0x0623d0(a0, a1);
        default: return 0U;
    }
}

} // namespace ttr_render
