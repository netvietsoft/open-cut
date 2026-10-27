// ============================================================================
// File: rex_fde_shard_2.cpp
// Target 109 / 169: librex.so (690,264 bytes)
// EN: Clean-room C++17 AArch64 Function Shard 2/5 covering [320..639]
//     (PC range 0x010fbc .. 0x020c60).
// VI: Phân mảnh hàm AArch64 C++17 2/5 bao phủ [320..639]
//     (Dải địa chỉ PC 0x010fbc .. 0x020c60).
// ============================================================================
#include "rex_date_format.h"

namespace bytedance {
namespace rex {

// Func #0320 | PC: 0x010fbc..0x010ffc (64 B) | Symbol: sub_010fbc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_010fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x9401DDF1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010FBCULL;
}

// Func #0321 | PC: 0x010fcc..0x01100c (64 B) | Symbol: sub_010fcc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_010fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x9401DDEDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010FCCULL;
}

// Func #0322 | PC: 0x010fdc..0x01101c (64 B) | Symbol: sub_010fdc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_010fdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401DDE9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010FDCULL;
}

// Func #0323 | PC: 0x010fec..0x01102c (64 B) | Symbol: sub_010fec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_010fec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401DDE5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010FECULL;
}

// Func #0324 | PC: 0x010ffc..0x01103c (64 B) | Symbol: sub_010ffc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_010ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401DDE1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010FFCULL;
}

// Func #0325 | PC: 0x01100c..0x01104c (64 B) | Symbol: sub_01100c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01100c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401DDDDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01100CULL;
}

// Func #0326 | PC: 0x01101c..0x01105c (64 B) | Symbol: sub_01101c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01101c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401DDD9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01101CULL;
}

// Func #0327 | PC: 0x01102c..0x01106c (64 B) | Symbol: sub_01102c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01102c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401DDD5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01102CULL;
}

// Func #0328 | PC: 0x01103c..0x01107c (64 B) | Symbol: sub_01103c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01103c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401DDD1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01103CULL;
}

// Func #0329 | PC: 0x01104c..0x01108c (64 B) | Symbol: sub_01104c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01104c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401DDCDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01104CULL;
}

// Func #0330 | PC: 0x01105c..0x01109c (64 B) | Symbol: sub_01105c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01105c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401DDC9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01105CULL;
}

// Func #0331 | PC: 0x01106c..0x0110ac (64 B) | Symbol: sub_01106c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01106c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401DDC5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01106CULL;
}

// Func #0332 | PC: 0x01107c..0x0110bc (64 B) | Symbol: sub_01107c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01107c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401DDC1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01107CULL;
}

// Func #0333 | PC: 0x01108c..0x0110cc (64 B) | Symbol: sub_01108c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01108c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401DDBDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01108CULL;
}

// Func #0334 | PC: 0x01109c..0x0110dc (64 B) | Symbol: sub_01109c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_01109c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401DDB9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01109CULL;
}

// Func #0335 | PC: 0x0110b0..0x0110f0 (64 B) | Symbol: sub_0110b0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_0110b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401DDB4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0110B0ULL;
}

// Func #0336 | PC: 0x0110c0..0x011100 (64 B) | Symbol: sub_0110c0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0110c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401DDB0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0110C0ULL;
}

// Func #0337 | PC: 0x0110d0..0x011110 (64 B) | Symbol: sub_0110d0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0110d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401DDACULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0110D0ULL;
}

// Func #0338 | PC: 0x0110e0..0x011120 (64 B) | Symbol: sub_0110e0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0110e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401DDA8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0110E0ULL;
}

// Func #0339 | PC: 0x0110f0..0x011130 (64 B) | Symbol: sub_0110f0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_0110f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401DDA4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0110F0ULL;
}

// Func #0340 | PC: 0x011100..0x011140 (64 B) | Symbol: sub_011100
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x8c9; stur q0, [x9, #0xff]] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x8c9; stur q0, [x9, #0xff]]
uint64_t fde_sub_011100(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x9401DDA0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x011100ULL;
}

// Func #0341 | PC: 0x012324..0x012364 (64 B) | Symbol: sub_012324
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_012324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911523E0ULL) << 32) | 0x9401DBF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012324ULL;
}

// Func #0342 | PC: 0x01232c..0x01236c (64 B) | Symbol: sub_01232c
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x12340; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x12340; subs x19, x19, #0x30]
uint64_t fde_sub_01232c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401D450ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01232CULL;
}

// Func #0343 | PC: 0x01235c..0x01239c (64 B) | Symbol: sub_01235c
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x12338; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x12338; add x8, x21, x19]
uint64_t fde_sub_01235c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFBDDDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01235CULL;
}

// Func #0344 | PC: 0x012370..0x0123b0 (64 B) | Symbol: sub_012370
// EN: AArch64 prologue [bl #0x1ad0; b #0x12338; adrp x0, #0xb7000; add x0, x0, #0x870] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x12338; adrp x0, #0xb7000; add x0, x0, #0x870]
uint64_t fde_sub_012370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFBDD8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012370ULL;
}

// Func #0345 | PC: 0x012380..0x0123c0 (64 B) | Symbol: sub_012380
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_012380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063F3ULL) << 32) | 0x97FFBDDCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012380ULL;
}

// Func #0346 | PC: 0x0123bc..0x0123fc (64 B) | Symbol: sub_0123bc
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0123bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFBE01ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0123BCULL;
}

// Func #0347 | PC: 0x0123c0..0x0141c0 (7680 B) | Symbol: rex_locale_init_ctor_08
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0123c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0123C0ULL;
}

// Func #0348 | PC: 0x0123dc..0x01241c (64 B) | Symbol: sub_0123dc
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_0123dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13143FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0123DCULL;
}

// Func #0349 | PC: 0x0123e0..0x012420 (64 B) | Symbol: sub_0123e0
// EN: AArch64 prologue [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_0123e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0123E0ULL;
}

// Func #0350 | PC: 0x012408..0x012448 (64 B) | Symbol: sub_012408
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x1423c; mov w14, #0x616a; add x25, sp, #0x548] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x1423c; mov w14, #0x616a; add x25, sp, #0x548]
uint64_t fde_sub_012408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F180ULL) << 32) | 0x97FFBDFEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012408ULL;
}

// Func #0351 | PC: 0x012c2c..0x012c6c (64 B) | Symbol: sub_012c2c
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0xabc; ldur q0, [x9, #0xb]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0xabc; ldur q0, [x9, #0xb]]
uint64_t fde_sub_012c2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000429ULL) << 32) | 0x97FFBBDDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012C2CULL;
}

// Func #0352 | PC: 0x012cec..0x012d2c (64 B) | Symbol: sub_012cec
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xd30]; adrp x16, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xd30]; adrp x16, #0x99000]
uint64_t fde_sub_012cec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000429ULL) << 32) | 0x97FFBBADULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012CECULL;
}

// Func #0353 | PC: 0x013160..0x0131a0 (64 B) | Symbol: sub_013160
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; ldr x9, [sp, #0x38]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; ldr x9, [sp, #0x38]]
uint64_t fde_sub_013160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000428ULL) << 32) | 0x97FFBA90ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013160ULL;
}

// Func #0354 | PC: 0x0132d0..0x013310 (64 B) | Symbol: sub_0132d0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0132d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401D52CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0132D0ULL;
}

// Func #0355 | PC: 0x0132e0..0x013320 (64 B) | Symbol: sub_0132e0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0132e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401D528ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0132E0ULL;
}

// Func #0356 | PC: 0x0132f0..0x013330 (64 B) | Symbol: sub_0132f0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0132f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401D524ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0132F0ULL;
}

// Func #0357 | PC: 0x013300..0x013340 (64 B) | Symbol: sub_013300
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x9401D520ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013300ULL;
}

// Func #0358 | PC: 0x013310..0x013350 (64 B) | Symbol: sub_013310
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x9401D51CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013310ULL;
}

// Func #0359 | PC: 0x013320..0x013360 (64 B) | Symbol: sub_013320
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401D518ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013320ULL;
}

// Func #0360 | PC: 0x013330..0x013370 (64 B) | Symbol: sub_013330
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401D514ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013330ULL;
}

// Func #0361 | PC: 0x013340..0x013380 (64 B) | Symbol: sub_013340
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401D510ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013340ULL;
}

// Func #0362 | PC: 0x013350..0x013390 (64 B) | Symbol: sub_013350
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401D50CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013350ULL;
}

// Func #0363 | PC: 0x013360..0x0133a0 (64 B) | Symbol: sub_013360
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401D508ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013360ULL;
}

// Func #0364 | PC: 0x013370..0x0133b0 (64 B) | Symbol: sub_013370
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401D504ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013370ULL;
}

// Func #0365 | PC: 0x013380..0x0133c0 (64 B) | Symbol: sub_013380
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401D500ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013380ULL;
}

// Func #0366 | PC: 0x013390..0x0133d0 (64 B) | Symbol: sub_013390
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401D4FCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013390ULL;
}

// Func #0367 | PC: 0x0133a0..0x0133e0 (64 B) | Symbol: sub_0133a0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0133a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401D4F8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0133A0ULL;
}

// Func #0368 | PC: 0x0133b0..0x0133f0 (64 B) | Symbol: sub_0133b0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0133b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401D4F4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0133B0ULL;
}

// Func #0369 | PC: 0x0133c0..0x013400 (64 B) | Symbol: sub_0133c0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0133c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401D4F0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0133C0ULL;
}

// Func #0370 | PC: 0x0133d0..0x013410 (64 B) | Symbol: sub_0133d0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0133d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401D4ECULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0133D0ULL;
}

// Func #0371 | PC: 0x0133e0..0x013420 (64 B) | Symbol: sub_0133e0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_0133e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401D4E8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0133E0ULL;
}

// Func #0372 | PC: 0x0133f0..0x013430 (64 B) | Symbol: sub_0133f0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_0133f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401D4E4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0133F0ULL;
}

// Func #0373 | PC: 0x013400..0x013440 (64 B) | Symbol: sub_013400
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401D4E0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013400ULL;
}

// Func #0374 | PC: 0x013410..0x013450 (64 B) | Symbol: sub_013410
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401D4DCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013410ULL;
}

// Func #0375 | PC: 0x013420..0x013460 (64 B) | Symbol: sub_013420
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_013420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401D4D8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013420ULL;
}

// Func #0376 | PC: 0x013430..0x013470 (64 B) | Symbol: sub_013430
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_013430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401D4D4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013430ULL;
}

// Func #0377 | PC: 0x013440..0x013480 (64 B) | Symbol: sub_013440
// EN: AArch64 prologue [bl #0x88780; add x8, x23, #0x508; movi v0.2d, #0000000000000000; mov w9, #0x2069] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x8, x23, #0x508; movi v0.2d, #0000000000000000; mov w9, #0x2069]
uint64_t fde_sub_013440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911422E8ULL) << 32) | 0x9401D4D0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x013440ULL;
}

// Func #0378 | PC: 0x0141d8..0x014218 (64 B) | Symbol: sub_0141d8
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_0141d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911523E0ULL) << 32) | 0x9401D447ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0141D8ULL;
}

// Func #0379 | PC: 0x0141e0..0x014220 (64 B) | Symbol: sub_0141e0
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x141f4; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x141f4; subs x19, x19, #0x30]
uint64_t fde_sub_0141e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401CCA3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0141E0ULL;
}

// Func #0380 | PC: 0x014210..0x014250 (64 B) | Symbol: sub_014210
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x21, #-0x30]; tbz w8, #0, #0x141ec; add x8, x20, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x21, #-0x30]; tbz w8, #0, #0x141ec; add x8, x20, x19]
uint64_t fde_sub_014210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D02A8ULL) << 32) | 0x97FFB630ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014210ULL;
}

// Func #0381 | PC: 0x014224..0x014264 (64 B) | Symbol: sub_014224
// EN: AArch64 prologue [bl #0x1ad0; b #0x141ec; adrp x0, #0xb8000; add x0, x0, #0xf70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x141ec; adrp x0, #0xb8000; add x0, x0, #0xf70]
uint64_t fde_sub_014224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFB62BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014224ULL;
}

// Func #0382 | PC: 0x014234..0x014274 (64 B) | Symbol: sub_014234
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_014234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063F3ULL) << 32) | 0x97FFB62FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014234ULL;
}

// Func #0383 | PC: 0x014270..0x0142b0 (64 B) | Symbol: sub_014270
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_014270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFB654ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014270ULL;
}

// Func #0384 | PC: 0x014274..0x016074 (7680 B) | Symbol: rex_locale_init_ctor_09
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_014274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014274ULL;
}

// Func #0385 | PC: 0x014290..0x0142d0 (64 B) | Symbol: sub_014290
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_014290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD131C3FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014290ULL;
}

// Func #0386 | PC: 0x014294..0x0142d4 (64 B) | Symbol: sub_014294
// EN: AArch64 prologue [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_014294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD131C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014294ULL;
}

// Func #0387 | PC: 0x0142bc..0x0142fc (64 B) | Symbol: sub_0142bc
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x16110; movi v1.2d, #0000000000000000; mov w17, #0x614a] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x16110; movi v1.2d, #0000000000000000; mov w17, #0x614a]
uint64_t fde_sub_0142bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F280ULL) << 32) | 0x97FFB651ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0142BCULL;
}

// Func #0388 | PC: 0x014aec..0x014b2c (64 B) | Symbol: sub_014aec
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0xcda; ldur q0, [x9, #0xc]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0xcda; ldur q0, [x9, #0xc]]
uint64_t fde_sub_014aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000429ULL) << 32) | 0x97FFB42DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014AECULL;
}

// Func #0389 | PC: 0x014ba8..0x014be8 (64 B) | Symbol: sub_014ba8
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; add x10, x26, #0x180] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; add x10, x26, #0x180]
uint64_t fde_sub_014ba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000409ULL) << 32) | 0x97FFB3FEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014BA8ULL;
}

// Func #0390 | PC: 0x01502c..0x01506c (64 B) | Symbol: sub_01502c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x18]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x18]]
uint64_t fde_sub_01502c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000408ULL) << 32) | 0x97FFB2DDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01502CULL;
}

// Func #0391 | PC: 0x01519c..0x0151dc (64 B) | Symbol: sub_01519c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01519c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401CD79ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01519CULL;
}

// Func #0392 | PC: 0x0151ac..0x0151ec (64 B) | Symbol: sub_0151ac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0151ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401CD75ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0151ACULL;
}

// Func #0393 | PC: 0x0151bc..0x0151fc (64 B) | Symbol: sub_0151bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0151bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401CD71ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0151BCULL;
}

// Func #0394 | PC: 0x0151cc..0x01520c (64 B) | Symbol: sub_0151cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0151cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x9401CD6DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0151CCULL;
}

// Func #0395 | PC: 0x0151dc..0x01521c (64 B) | Symbol: sub_0151dc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0151dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x9401CD69ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0151DCULL;
}

// Func #0396 | PC: 0x0151ec..0x01522c (64 B) | Symbol: sub_0151ec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0151ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401CD65ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0151ECULL;
}

// Func #0397 | PC: 0x0151fc..0x01523c (64 B) | Symbol: sub_0151fc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0151fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401CD61ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0151FCULL;
}

// Func #0398 | PC: 0x01520c..0x01524c (64 B) | Symbol: sub_01520c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01520c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401CD5DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01520CULL;
}

// Func #0399 | PC: 0x01521c..0x01525c (64 B) | Symbol: sub_01521c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01521c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401CD59ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01521CULL;
}

// Func #0400 | PC: 0x01522c..0x01526c (64 B) | Symbol: sub_01522c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01522c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401CD55ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01522CULL;
}

// Func #0401 | PC: 0x01523c..0x01527c (64 B) | Symbol: sub_01523c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01523c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401CD51ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01523CULL;
}

// Func #0402 | PC: 0x01524c..0x01528c (64 B) | Symbol: sub_01524c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01524c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401CD4DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01524CULL;
}

// Func #0403 | PC: 0x01525c..0x01529c (64 B) | Symbol: sub_01525c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01525c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401CD49ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01525CULL;
}

// Func #0404 | PC: 0x01526c..0x0152ac (64 B) | Symbol: sub_01526c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01526c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401CD45ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01526CULL;
}

// Func #0405 | PC: 0x01527c..0x0152bc (64 B) | Symbol: sub_01527c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01527c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401CD41ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01527CULL;
}

// Func #0406 | PC: 0x01528c..0x0152cc (64 B) | Symbol: sub_01528c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01528c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401CD3DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01528CULL;
}

// Func #0407 | PC: 0x01529c..0x0152dc (64 B) | Symbol: sub_01529c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01529c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401CD39ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01529CULL;
}

// Func #0408 | PC: 0x0152ac..0x0152ec (64 B) | Symbol: sub_0152ac
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_0152ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401CD35ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0152ACULL;
}

// Func #0409 | PC: 0x0152bc..0x0152fc (64 B) | Symbol: sub_0152bc
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_0152bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401CD31ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0152BCULL;
}

// Func #0410 | PC: 0x0152cc..0x01530c (64 B) | Symbol: sub_0152cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0152cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401CD2DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0152CCULL;
}

// Func #0411 | PC: 0x0152dc..0x01531c (64 B) | Symbol: sub_0152dc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0152dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401CD29ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0152DCULL;
}

// Func #0412 | PC: 0x0152ec..0x01532c (64 B) | Symbol: sub_0152ec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0152ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401CD25ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0152ECULL;
}

// Func #0413 | PC: 0x0152fc..0x01533c (64 B) | Symbol: sub_0152fc
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_0152fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401CD21ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0152FCULL;
}

// Func #0414 | PC: 0x01530c..0x01534c (64 B) | Symbol: sub_01530c
// EN: AArch64 prologue [bl #0x88780; add x8, x25, #0x508; movi v0.2d, #0000000000000000; strb wzr, [sp, #0x9e0]] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x8, x25, #0x508; movi v0.2d, #0000000000000000; strb wzr, [sp, #0x9e0]]
uint64_t fde_sub_01530c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91142328ULL) << 32) | 0x9401CD1DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01530CULL;
}

// Func #0415 | PC: 0x0160ac..0x0160ec (64 B) | Symbol: sub_0160ac
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x568; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x568; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_0160ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115A3E0ULL) << 32) | 0x9401CC92ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0160ACULL;
}

// Func #0416 | PC: 0x0160b4..0x0160f4 (64 B) | Symbol: sub_0160b4
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x160c8; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x160c8; subs x19, x19, #0x30]
uint64_t fde_sub_0160b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401C4EEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0160B4ULL;
}

// Func #0417 | PC: 0x0160e4..0x016124 (64 B) | Symbol: sub_0160e4
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x160c0; add x8, x26, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x160c0; add x8, x26, x19]
uint64_t fde_sub_0160e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFAE7BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0160E4ULL;
}

// Func #0418 | PC: 0x0160f8..0x016138 (64 B) | Symbol: sub_0160f8
// EN: AArch64 prologue [bl #0x1ad0; b #0x160c0; adrp x0, #0xba000; add x0, x0, #0x670] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x160c0; adrp x0, #0xba000; add x0, x0, #0x670]
uint64_t fde_sub_0160f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFAE76ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0160F8ULL;
}

// Func #0419 | PC: 0x016108..0x016148 (64 B) | Symbol: sub_016108
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xe0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xe0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_016108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94073F3ULL) << 32) | 0x97FFAE7AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016108ULL;
}

// Func #0420 | PC: 0x016144..0x016184 (64 B) | Symbol: sub_016144
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_016144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFAE9FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016144ULL;
}

// Func #0421 | PC: 0x016148..0x017f48 (7680 B) | Symbol: rex_locale_init_ctor_10
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_016148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016148ULL;
}

// Func #0422 | PC: 0x016164..0x0161a4 (64 B) | Symbol: sub_016164
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc90; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc90; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_016164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13243FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016164ULL;
}

// Func #0423 | PC: 0x016168..0x0161a8 (64 B) | Symbol: sub_016168
// EN: AArch64 prologue [sub sp, sp, #0xc90; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc90; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_016168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13243FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016168ULL;
}

// Func #0424 | PC: 0x016190..0x0161d0 (64 B) | Symbol: sub_016190
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x181cc; adrp x15, #0x99000; add x15, x15, #0xebe] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x181cc; adrp x15, #0x99000; add x15, x15, #0xebe]
uint64_t fde_sub_016190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340101C0ULL) << 32) | 0x97FFAE9CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016190ULL;
}

// Func #0425 | PC: 0x016b28..0x016b68 (64 B) | Symbol: sub_016b28
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x76; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x76; adrp x8, #0x97000]
uint64_t fde_sub_016b28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000429ULL) << 32) | 0x97FFAC1EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016B28ULL;
}

// Func #0426 | PC: 0x016be8..0x016c28 (64 B) | Symbol: sub_016be8
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x9a000]
uint64_t fde_sub_016be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000409ULL) << 32) | 0x97FFABEEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016BE8ULL;
}

// Func #0427 | PC: 0x017048..0x017088 (64 B) | Symbol: sub_017048
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; ldr x9, [sp, #0x18]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; ldr x9, [sp, #0x18]]
uint64_t fde_sub_017048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000408ULL) << 32) | 0x97FFAAD6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017048ULL;
}

// Func #0428 | PC: 0x0171c0..0x017200 (64 B) | Symbol: sub_0171c0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0171c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401C570ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0171C0ULL;
}

// Func #0429 | PC: 0x0171d0..0x017210 (64 B) | Symbol: sub_0171d0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0171d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401C56CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0171D0ULL;
}

// Func #0430 | PC: 0x0171e0..0x017220 (64 B) | Symbol: sub_0171e0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0171e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401C568ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0171E0ULL;
}

// Func #0431 | PC: 0x0171f0..0x017230 (64 B) | Symbol: sub_0171f0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0171f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401C564ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0171F0ULL;
}

// Func #0432 | PC: 0x017200..0x017240 (64 B) | Symbol: sub_017200
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x9401C560ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017200ULL;
}

// Func #0433 | PC: 0x017210..0x017250 (64 B) | Symbol: sub_017210
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401C55CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017210ULL;
}

// Func #0434 | PC: 0x017220..0x017260 (64 B) | Symbol: sub_017220
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401C558ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017220ULL;
}

// Func #0435 | PC: 0x017230..0x017270 (64 B) | Symbol: sub_017230
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017230(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401C554ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017230ULL;
}

// Func #0436 | PC: 0x017240..0x017280 (64 B) | Symbol: sub_017240
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401C550ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017240ULL;
}

// Func #0437 | PC: 0x017250..0x017290 (64 B) | Symbol: sub_017250
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017250(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401C54CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017250ULL;
}

// Func #0438 | PC: 0x017260..0x0172a0 (64 B) | Symbol: sub_017260
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401C548ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017260ULL;
}

// Func #0439 | PC: 0x017270..0x0172b0 (64 B) | Symbol: sub_017270
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401C544ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017270ULL;
}

// Func #0440 | PC: 0x017280..0x0172c0 (64 B) | Symbol: sub_017280
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401C540ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017280ULL;
}

// Func #0441 | PC: 0x017290..0x0172d0 (64 B) | Symbol: sub_017290
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401C53CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017290ULL;
}

// Func #0442 | PC: 0x0172a0..0x0172e0 (64 B) | Symbol: sub_0172a0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0172a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401C538ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0172A0ULL;
}

// Func #0443 | PC: 0x0172b0..0x0172f0 (64 B) | Symbol: sub_0172b0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0172b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401C534ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0172B0ULL;
}

// Func #0444 | PC: 0x0172c0..0x017300 (64 B) | Symbol: sub_0172c0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0172c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401C530ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0172C0ULL;
}

// Func #0445 | PC: 0x0172d0..0x017310 (64 B) | Symbol: sub_0172d0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_0172d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401C52CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0172D0ULL;
}

// Func #0446 | PC: 0x0172e0..0x017320 (64 B) | Symbol: sub_0172e0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_0172e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401C528ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0172E0ULL;
}

// Func #0447 | PC: 0x0172f0..0x017330 (64 B) | Symbol: sub_0172f0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0172f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401C524ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0172F0ULL;
}

// Func #0448 | PC: 0x017300..0x017340 (64 B) | Symbol: sub_017300
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401C520ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017300ULL;
}

// Func #0449 | PC: 0x017310..0x017350 (64 B) | Symbol: sub_017310
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_017310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x9401C51CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017310ULL;
}

// Func #0450 | PC: 0x017320..0x017360 (64 B) | Symbol: sub_017320
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_017320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401C518ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017320ULL;
}

// Func #0451 | PC: 0x017330..0x017370 (64 B) | Symbol: sub_017330
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x909; stur q0, [x9, #0xff]] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x909; stur q0, [x9, #0xff]]
uint64_t fde_sub_017330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x9401C514ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017330ULL;
}

// Func #0452 | PC: 0x01784c..0x01788c (64 B) | Symbol: sub_01784c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q2, [x8, #0xcd0]; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q2, [x8, #0xcd0]; adrp x8, #0x9a000]
uint64_t fde_sub_01784c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000408ULL) << 32) | 0x97FFA8D5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01784CULL;
}

// Func #0453 | PC: 0x0178b0..0x0178f0 (64 B) | Symbol: sub_0178b0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9a000; add x8, x8, #0x167] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9a000; add x8, x8, #0x167]
uint64_t fde_sub_0178b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFA8BCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0178B0ULL;
}

// Func #0454 | PC: 0x0178ec..0x01792c (64 B) | Symbol: sub_0178ec
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xa0]; adrp x8, #0x9a000; add x8, x8, #0x181] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xa0]; adrp x8, #0x9a000; add x8, x8, #0x181]
uint64_t fde_sub_0178ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC02BE0ULL) << 32) | 0x97FFA8ADULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0178ECULL;
}

// Func #0455 | PC: 0x017938..0x017978 (64 B) | Symbol: sub_017938
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x19d; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x19d; adrp x8, #0x97000]
uint64_t fde_sub_017938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000409ULL) << 32) | 0x97FFA89AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017938ULL;
}

// Func #0456 | PC: 0x017978..0x0179b8 (64 B) | Symbol: sub_017978
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; adrp x8, #0x9a000]
uint64_t fde_sub_017978(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000408ULL) << 32) | 0x97FFA88AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017978ULL;
}

// Func #0457 | PC: 0x0179d0..0x017a10 (64 B) | Symbol: sub_0179d0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [sp, #0x1250]; strb wzr, [x0, #0x1a]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [sp, #0x1250]; strb wzr, [x0, #0x1a]]
uint64_t fde_sub_0179d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFA874ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0179D0ULL;
}

// Func #0458 | PC: 0x017a04..0x017a44 (64 B) | Symbol: sub_017a04
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x9a000; add x8, x8, #0x1d6] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x9a000; add x8, x8, #0x1d6]
uint64_t fde_sub_017a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFA867ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017A04ULL;
}

// Func #0459 | PC: 0x017a54..0x017a94 (64 B) | Symbol: sub_017a54
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x1310]; adrp x9, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x1310]; adrp x9, #0x9a000]
uint64_t fde_sub_017a54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFA853ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017A54ULL;
}

// Func #0460 | PC: 0x017af4..0x017b34 (64 B) | Symbol: sub_017af4
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9a000; add x8, x8, #0x206] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9a000; add x8, x8, #0x206]
uint64_t fde_sub_017af4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFA82BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017AF4ULL;
}

// Func #0461 | PC: 0x017b48..0x017b88 (64 B) | Symbol: sub_017b48
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [sp, #0x1490]; strb wzr, [x0, #0x1a]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [sp, #0x1490]; strb wzr, [x0, #0x1a]]
uint64_t fde_sub_017b48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFA816ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017B48ULL;
}

// Func #0462 | PC: 0x017b7c..0x017bbc (64 B) | Symbol: sub_017b7c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9a000; add x8, x8, #0x221] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9a000; add x8, x8, #0x221]
uint64_t fde_sub_017b7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFA809ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017B7CULL;
}

// Func #0463 | PC: 0x017bd0..0x017c10 (64 B) | Symbol: sub_017bd0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1550]; adrp x9, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1550]; adrp x9, #0x9a000]
uint64_t fde_sub_017bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFA7F4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017BD0ULL;
}

// Func #0464 | PC: 0x018168..0x0181a8 (64 B) | Symbol: sub_018168
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x588; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x588; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_018168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911623E0ULL) << 32) | 0x9401C463ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018168ULL;
}

// Func #0465 | PC: 0x018170..0x0181b0 (64 B) | Symbol: sub_018170
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x18184; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x18184; subs x19, x19, #0x30]
uint64_t fde_sub_018170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401BCBFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018170ULL;
}

// Func #0466 | PC: 0x0181a0..0x0181e0 (64 B) | Symbol: sub_0181a0
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x1817c; add x8, x25, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x1817c; add x8, x25, x19]
uint64_t fde_sub_0181a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFA64CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0181A0ULL;
}

// Func #0467 | PC: 0x0181b4..0x0181f4 (64 B) | Symbol: sub_0181b4
// EN: AArch64 prologue [bl #0x1ad0; b #0x1817c; adrp x0, #0xbb000; add x0, x0, #0xd70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x1817c; adrp x0, #0xbb000; add x0, x0, #0xd70]
uint64_t fde_sub_0181b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFA647ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0181B4ULL;
}

// Func #0468 | PC: 0x0181c4..0x018204 (64 B) | Symbol: sub_0181c4
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xc8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xc8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_0181c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94067F3ULL) << 32) | 0x97FFA64BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0181C4ULL;
}

// Func #0469 | PC: 0x018200..0x018240 (64 B) | Symbol: sub_018200
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_018200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFA670ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018200ULL;
}

// Func #0470 | PC: 0x018204..0x01a004 (7680 B) | Symbol: rex_locale_init_ctor_11
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_018204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018204ULL;
}

// Func #0471 | PC: 0x018220..0x018260 (64 B) | Symbol: sub_018220
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_018220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018220ULL;
}

// Func #0472 | PC: 0x018224..0x018264 (64 B) | Symbol: sub_018224
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_018224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018224ULL;
}

// Func #0473 | PC: 0x01824c..0x01828c (64 B) | Symbol: sub_01824c
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x19fdc; mov x17, #0x6546; movi v1.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x19fdc; mov x17, #0x6546; movi v1.2d, #0000000000000000]
uint64_t fde_sub_01824c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400EC60ULL) << 32) | 0x97FFA66DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01824CULL;
}

// Func #0474 | PC: 0x018ac8..0x018b08 (64 B) | Symbol: sub_018ac8
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x358; ldur q0, [x9, #0xc]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x358; ldur q0, [x9, #0xc]]
uint64_t fde_sub_018ac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000409ULL) << 32) | 0x97FFA436ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018AC8ULL;
}

// Func #0475 | PC: 0x018b8c..0x018bcc (64 B) | Symbol: sub_018b8c
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x9a000]
uint64_t fde_sub_018b8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00003E9ULL) << 32) | 0x97FFA405ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018B8CULL;
}

// Func #0476 | PC: 0x018ff8..0x019038 (64 B) | Symbol: sub_018ff8
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; ldr x9, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; ldr x9, [sp, #0x20]]
uint64_t fde_sub_018ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00003E8ULL) << 32) | 0x97FFA2EAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018FF8ULL;
}

// Func #0477 | PC: 0x01916c..0x0191ac (64 B) | Symbol: sub_01916c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01916c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401BD85ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01916CULL;
}

// Func #0478 | PC: 0x01917c..0x0191bc (64 B) | Symbol: sub_01917c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01917c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401BD81ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01917CULL;
}

// Func #0479 | PC: 0x01918c..0x0191cc (64 B) | Symbol: sub_01918c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01918c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401BD7DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01918CULL;
}

// Func #0480 | PC: 0x01919c..0x0191dc (64 B) | Symbol: sub_01919c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01919c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401BD79ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01919CULL;
}

// Func #0481 | PC: 0x0191ac..0x0191ec (64 B) | Symbol: sub_0191ac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0191ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401BD75ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0191ACULL;
}

// Func #0482 | PC: 0x0191bc..0x0191fc (64 B) | Symbol: sub_0191bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0191bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401BD71ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0191BCULL;
}

// Func #0483 | PC: 0x0191cc..0x01920c (64 B) | Symbol: sub_0191cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0191cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401BD6DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0191CCULL;
}

// Func #0484 | PC: 0x0191dc..0x01921c (64 B) | Symbol: sub_0191dc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0191dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401BD69ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0191DCULL;
}

// Func #0485 | PC: 0x0191ec..0x01922c (64 B) | Symbol: sub_0191ec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0191ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401BD65ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0191ECULL;
}

// Func #0486 | PC: 0x0191fc..0x01923c (64 B) | Symbol: sub_0191fc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0191fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401BD61ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0191FCULL;
}

// Func #0487 | PC: 0x01920c..0x01924c (64 B) | Symbol: sub_01920c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01920c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401BD5DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01920CULL;
}

// Func #0488 | PC: 0x01921c..0x01925c (64 B) | Symbol: sub_01921c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01921c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401BD59ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01921CULL;
}

// Func #0489 | PC: 0x01922c..0x01926c (64 B) | Symbol: sub_01922c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01922c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401BD55ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01922CULL;
}

// Func #0490 | PC: 0x01923c..0x01927c (64 B) | Symbol: sub_01923c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01923c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401BD51ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01923CULL;
}

// Func #0491 | PC: 0x01924c..0x01928c (64 B) | Symbol: sub_01924c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01924c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401BD4DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01924CULL;
}

// Func #0492 | PC: 0x01925c..0x01929c (64 B) | Symbol: sub_01925c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_01925c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401BD49ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01925CULL;
}

// Func #0493 | PC: 0x01926c..0x0192ac (64 B) | Symbol: sub_01926c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01926c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401BD45ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01926CULL;
}

// Func #0494 | PC: 0x01927c..0x0192bc (64 B) | Symbol: sub_01927c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_01927c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401BD41ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01927CULL;
}

// Func #0495 | PC: 0x01928c..0x0192cc (64 B) | Symbol: sub_01928c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_01928c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401BD3DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01928CULL;
}

// Func #0496 | PC: 0x01929c..0x0192dc (64 B) | Symbol: sub_01929c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01929c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401BD39ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01929CULL;
}

// Func #0497 | PC: 0x0192ac..0x0192ec (64 B) | Symbol: sub_0192ac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0192ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401BD35ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0192ACULL;
}

// Func #0498 | PC: 0x0192bc..0x0192fc (64 B) | Symbol: sub_0192bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0192bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x9401BD31ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0192BCULL;
}

// Func #0499 | PC: 0x0192cc..0x01930c (64 B) | Symbol: sub_0192cc
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_0192cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401BD2DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0192CCULL;
}

// Func #0500 | PC: 0x0192dc..0x01931c (64 B) | Symbol: sub_0192dc
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x8, sp, #0x8b9; add x13, sp, #0x538] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x8, sp, #0x8b9; add x13, sp, #0x538]
uint64_t fde_sub_0192dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x9401BD29ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0192DCULL;
}

// Func #0501 | PC: 0x019f78..0x019fb8 (64 B) | Symbol: sub_019f78
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_019f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x9401BCDFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x019F78ULL;
}

// Func #0502 | PC: 0x019f80..0x019fc0 (64 B) | Symbol: sub_019f80
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x19f94; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x19f94; subs x19, x19, #0x30]
uint64_t fde_sub_019f80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401B53BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x019F80ULL;
}

// Func #0503 | PC: 0x019fb0..0x019ff0 (64 B) | Symbol: sub_019fb0
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x19f8c; add x8, x26, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x19f8c; add x8, x26, x19]
uint64_t fde_sub_019fb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF9EC8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x019FB0ULL;
}

// Func #0504 | PC: 0x019fc4..0x01a004 (64 B) | Symbol: sub_019fc4
// EN: AArch64 prologue [bl #0x1ad0; b #0x19f8c; adrp x0, #0xbd000; add x0, x0, #0x470] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x19f8c; adrp x0, #0xbd000; add x0, x0, #0x470]
uint64_t fde_sub_019fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF9EC3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x019FC4ULL;
}

// Func #0505 | PC: 0x019fd4..0x01a014 (64 B) | Symbol: sub_019fd4
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_019fd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FF9EC7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x019FD4ULL;
}

// Func #0506 | PC: 0x01a010..0x01a050 (64 B) | Symbol: sub_01a010
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_01a010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF9EECULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01A010ULL;
}

// Func #0507 | PC: 0x01a014..0x01be14 (7680 B) | Symbol: rex_locale_init_ctor_12
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_01a014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01A014ULL;
}

// Func #0508 | PC: 0x01a030..0x01a070 (64 B) | Symbol: sub_01a030
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_01a030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01A030ULL;
}

// Func #0509 | PC: 0x01a034..0x01a074 (64 B) | Symbol: sub_01a034
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_01a034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01A034ULL;
}

// Func #0510 | PC: 0x01a05c..0x01a09c (64 B) | Symbol: sub_01a05c
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x1bed8; mov x16, #0x6546; movi v1.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x1bed8; mov x16, #0x6546; movi v1.2d, #0000000000000000]
uint64_t fde_sub_01a05c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F3C0ULL) << 32) | 0x97FF9EE9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01A05CULL;
}

// Func #0511 | PC: 0x01a8e8..0x01a928 (64 B) | Symbol: sub_01a8e8
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; add x9, x9, #0xea8; ldur q0, [x9, #0xb]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; add x9, x9, #0xea8; ldur q0, [x9, #0xb]]
uint64_t fde_sub_01a8e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003E9ULL) << 32) | 0x97FF9CAEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01A8E8ULL;
}

// Func #0512 | PC: 0x01a9b0..0x01a9f0 (64 B) | Symbol: sub_01a9b0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xcb0]; adrp x16, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xcb0]; adrp x16, #0x9a000]
uint64_t fde_sub_01a9b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003E9ULL) << 32) | 0x97FF9C7CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01A9B0ULL;
}

// Func #0513 | PC: 0x01ae14..0x01ae54 (64 B) | Symbol: sub_01ae14
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; ldr x9, [sp, #0x38]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; ldr x9, [sp, #0x38]]
uint64_t fde_sub_01ae14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003E8ULL) << 32) | 0x97FF9B63ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AE14ULL;
}

// Func #0514 | PC: 0x01af88..0x01afc8 (64 B) | Symbol: sub_01af88
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01af88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401B5FEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AF88ULL;
}

// Func #0515 | PC: 0x01af98..0x01afd8 (64 B) | Symbol: sub_01af98
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01af98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401B5FAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AF98ULL;
}

// Func #0516 | PC: 0x01afa8..0x01afe8 (64 B) | Symbol: sub_01afa8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01afa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401B5F6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AFA8ULL;
}

// Func #0517 | PC: 0x01afb8..0x01aff8 (64 B) | Symbol: sub_01afb8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01afb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401B5F2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AFB8ULL;
}

// Func #0518 | PC: 0x01afc8..0x01b008 (64 B) | Symbol: sub_01afc8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01afc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x9401B5EEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AFC8ULL;
}

// Func #0519 | PC: 0x01afd8..0x01b018 (64 B) | Symbol: sub_01afd8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01afd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401B5EAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AFD8ULL;
}

// Func #0520 | PC: 0x01afe8..0x01b028 (64 B) | Symbol: sub_01afe8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01afe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401B5E6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AFE8ULL;
}

// Func #0521 | PC: 0x01aff8..0x01b038 (64 B) | Symbol: sub_01aff8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01aff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401B5E2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01AFF8ULL;
}

// Func #0522 | PC: 0x01b008..0x01b048 (64 B) | Symbol: sub_01b008
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x9401B5DEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B008ULL;
}

// Func #0523 | PC: 0x01b018..0x01b058 (64 B) | Symbol: sub_01b018
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401B5DAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B018ULL;
}

// Func #0524 | PC: 0x01b028..0x01b068 (64 B) | Symbol: sub_01b028
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401B5D6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B028ULL;
}

// Func #0525 | PC: 0x01b038..0x01b078 (64 B) | Symbol: sub_01b038
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401B5D2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B038ULL;
}

// Func #0526 | PC: 0x01b048..0x01b088 (64 B) | Symbol: sub_01b048
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401B5CEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B048ULL;
}

// Func #0527 | PC: 0x01b058..0x01b098 (64 B) | Symbol: sub_01b058
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401B5CAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B058ULL;
}

// Func #0528 | PC: 0x01b068..0x01b0a8 (64 B) | Symbol: sub_01b068
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401B5C6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B068ULL;
}

// Func #0529 | PC: 0x01b078..0x01b0b8 (64 B) | Symbol: sub_01b078
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401B5C2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B078ULL;
}

// Func #0530 | PC: 0x01b088..0x01b0c8 (64 B) | Symbol: sub_01b088
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401B5BEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B088ULL;
}

// Func #0531 | PC: 0x01b098..0x01b0d8 (64 B) | Symbol: sub_01b098
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_01b098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401B5BAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B098ULL;
}

// Func #0532 | PC: 0x01b0a8..0x01b0e8 (64 B) | Symbol: sub_01b0a8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_01b0a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401B5B6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B0A8ULL;
}

// Func #0533 | PC: 0x01b0b8..0x01b0f8 (64 B) | Symbol: sub_01b0b8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b0b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401B5B2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B0B8ULL;
}

// Func #0534 | PC: 0x01b0c8..0x01b108 (64 B) | Symbol: sub_01b0c8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b0c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401B5AEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B0C8ULL;
}

// Func #0535 | PC: 0x01b0d8..0x01b118 (64 B) | Symbol: sub_01b0d8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01b0d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401B5AAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B0D8ULL;
}

// Func #0536 | PC: 0x01b0e8..0x01b128 (64 B) | Symbol: sub_01b0e8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_01b0e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401B5A6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B0E8ULL;
}

// Func #0537 | PC: 0x01b0f8..0x01b138 (64 B) | Symbol: sub_01b0f8
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x8b9; add x8, x25, #0x478] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x8b9; add x8, x25, #0x478]
uint64_t fde_sub_01b0f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x9401B5A2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01B0F8ULL;
}

// Func #0538 | PC: 0x01be74..0x01beb4 (64 B) | Symbol: sub_01be74
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_01be74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x9401B520ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BE74ULL;
}

// Func #0539 | PC: 0x01be7c..0x01bebc (64 B) | Symbol: sub_01be7c
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x1be90; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x1be90; subs x19, x19, #0x30]
uint64_t fde_sub_01be7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401AD7CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BE7CULL;
}

// Func #0540 | PC: 0x01beac..0x01beec (64 B) | Symbol: sub_01beac
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x1be88; add x8, x27, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x1be88; add x8, x27, x19]
uint64_t fde_sub_01beac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF9709ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BEACULL;
}

// Func #0541 | PC: 0x01bec0..0x01bf00 (64 B) | Symbol: sub_01bec0
// EN: AArch64 prologue [bl #0x1ad0; b #0x1be88; adrp x0, #0xbe000; add x0, x0, #0xb70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x1be88; adrp x0, #0xbe000; add x0, x0, #0xb70]
uint64_t fde_sub_01bec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF9704ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BEC0ULL;
}

// Func #0542 | PC: 0x01bed0..0x01bf10 (64 B) | Symbol: sub_01bed0
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_01bed0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FF9708ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BED0ULL;
}

// Func #0543 | PC: 0x01bf0c..0x01bf4c (64 B) | Symbol: sub_01bf0c
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_01bf0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF972DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BF0CULL;
}

// Func #0544 | PC: 0x01bf10..0x01dd10 (7680 B) | Symbol: rex_locale_init_ctor_13
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_01bf10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BF10ULL;
}

// Func #0545 | PC: 0x01bf2c..0x01bf6c (64 B) | Symbol: sub_01bf2c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc30; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc30; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_01bf2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD130C3FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BF2CULL;
}

// Func #0546 | PC: 0x01bf30..0x01bf70 (64 B) | Symbol: sub_01bf30
// EN: AArch64 prologue [sub sp, sp, #0xc30; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc30; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_01bf30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD130C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BF30ULL;
}

// Func #0547 | PC: 0x01bf58..0x01bf98 (64 B) | Symbol: sub_01bf58
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x1dcc8; movi v1.2d, #0000000000000000; add x24, sp, #0x439] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x1dcc8; movi v1.2d, #0000000000000000; add x24, sp, #0x439]
uint64_t fde_sub_01bf58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400EB60ULL) << 32) | 0x97FF972AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01BF58ULL;
}

// Func #0548 | PC: 0x01c750..0x01c790 (64 B) | Symbol: sub_01c750
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x9a000; add x8, x8, #0x5f3; ldur q0, [x8, #0xb]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x9a000; add x8, x8, #0x5f3; ldur q0, [x8, #0xb]]
uint64_t fde_sub_01c750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00003E8ULL) << 32) | 0x97FF9514ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01C750ULL;
}

// Func #0549 | PC: 0x01c7ac..0x01c7ec (64 B) | Symbol: sub_01c7ac
// EN: AArch64 prologue [bl #0x1ba0; adrp x10, #0x9a000; add x10, x10, #0x5c8; ldp q0, q1, [x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x10, #0x9a000; add x10, x10, #0x5c8; ldp q0, q1, [x10]]
uint64_t fde_sub_01c7ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00003EAULL) << 32) | 0x97FF94FDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01C7ACULL;
}

// Func #0550 | PC: 0x01c864..0x01c8a4 (64 B) | Symbol: sub_01c864
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xce0]; adrp x16, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xce0]; adrp x16, #0x9a000]
uint64_t fde_sub_01c864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00003C9ULL) << 32) | 0x97FF94CFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01C864ULL;
}

// Func #0551 | PC: 0x01cdf4..0x01ce34 (64 B) | Symbol: sub_01cdf4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01cdf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401AE63ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CDF4ULL;
}

// Func #0552 | PC: 0x01ce04..0x01ce44 (64 B) | Symbol: sub_01ce04
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401AE5FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE04ULL;
}

// Func #0553 | PC: 0x01ce14..0x01ce54 (64 B) | Symbol: sub_01ce14
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401AE5BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE14ULL;
}

// Func #0554 | PC: 0x01ce24..0x01ce64 (64 B) | Symbol: sub_01ce24
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401AE57ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE24ULL;
}

// Func #0555 | PC: 0x01ce34..0x01ce74 (64 B) | Symbol: sub_01ce34
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401AE53ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE34ULL;
}

// Func #0556 | PC: 0x01ce44..0x01ce84 (64 B) | Symbol: sub_01ce44
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401AE4FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE44ULL;
}

// Func #0557 | PC: 0x01ce54..0x01ce94 (64 B) | Symbol: sub_01ce54
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401AE4BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE54ULL;
}

// Func #0558 | PC: 0x01ce64..0x01cea4 (64 B) | Symbol: sub_01ce64
// EN: AArch64 prologue [bl #0x88780; mov x0, x20; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x20; mov x1, x26; mov x2, x26]
uint64_t fde_sub_01ce64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x9401AE47ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE64ULL;
}

// Func #0559 | PC: 0x01ce74..0x01ceb4 (64 B) | Symbol: sub_01ce74
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401AE43ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE74ULL;
}

// Func #0560 | PC: 0x01ce84..0x01cec4 (64 B) | Symbol: sub_01ce84
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401AE3FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE84ULL;
}

// Func #0561 | PC: 0x01ce94..0x01ced4 (64 B) | Symbol: sub_01ce94
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ce94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401AE3BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE94ULL;
}

// Func #0562 | PC: 0x01cea4..0x01cee4 (64 B) | Symbol: sub_01cea4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01cea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401AE37ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEA4ULL;
}

// Func #0563 | PC: 0x01ceb4..0x01cef4 (64 B) | Symbol: sub_01ceb4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ceb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401AE33ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEB4ULL;
}

// Func #0564 | PC: 0x01cec4..0x01cf04 (64 B) | Symbol: sub_01cec4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01cec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401AE2FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEC4ULL;
}

// Func #0565 | PC: 0x01ced4..0x01cf14 (64 B) | Symbol: sub_01ced4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01ced4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401AE2BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CED4ULL;
}

// Func #0566 | PC: 0x01cee4..0x01cf24 (64 B) | Symbol: sub_01cee4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01cee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401AE27ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEE4ULL;
}

// Func #0567 | PC: 0x01cef4..0x01cf34 (64 B) | Symbol: sub_01cef4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x20; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x20; mov x2, x1]
uint64_t fde_sub_01cef4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x9401AE23ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEF4ULL;
}

// Func #0568 | PC: 0x01cf04..0x01cf44 (64 B) | Symbol: sub_01cf04
// EN: AArch64 prologue [bl #0x88780; mov x0, x20; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x20; mov x1, x24; mov x2, x24]
uint64_t fde_sub_01cf04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x9401AE1FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF04ULL;
}

// Func #0569 | PC: 0x01cf14..0x01cf54 (64 B) | Symbol: sub_01cf14
// EN: AArch64 prologue [bl #0x88780; mov x0, x20; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x20; mov x1, x21; mov x2, x21]
uint64_t fde_sub_01cf14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x9401AE1BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF14ULL;
}

// Func #0570 | PC: 0x01cf28..0x01cf68 (64 B) | Symbol: sub_01cf28
// EN: AArch64 prologue [bl #0x88780; mov x0, x20; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x20; mov x1, x27; mov x2, x27]
uint64_t fde_sub_01cf28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x9401AE16ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF28ULL;
}

// Func #0571 | PC: 0x01cf38..0x01cf78 (64 B) | Symbol: sub_01cf38
// EN: AArch64 prologue [bl #0x88780; mov x0, x20; mov x1, x19; mov x2, x19] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x20; mov x1, x19; mov x2, x19]
uint64_t fde_sub_01cf38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x9401AE12ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF38ULL;
}

// Func #0572 | PC: 0x01cf48..0x01cf88 (64 B) | Symbol: sub_01cf48
// EN: AArch64 prologue [bl #0x88780; mov x0, x20; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x20; mov x1, x25; mov x2, x25]
uint64_t fde_sub_01cf48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x9401AE0EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF48ULL;
}

// Func #0573 | PC: 0x01cf58..0x01cf98 (64 B) | Symbol: sub_01cf58
// EN: AArch64 prologue [bl #0x88780; mov x0, x20; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x20; mov x1, x28; mov x2, x28]
uint64_t fde_sub_01cf58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x9401AE0AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF58ULL;
}

// Func #0574 | PC: 0x01cf68..0x01cfa8 (64 B) | Symbol: sub_01cf68
// EN: AArch64 prologue [bl #0x88780; add x10, sp, #0x528; add x8, x10, #0x508; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x10, sp, #0x528; add x8, x10, #0x508; movi v0.2d, #0000000000000000]
uint64_t fde_sub_01cf68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114A3EAULL) << 32) | 0x9401AE06ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF68ULL;
}

// Func #0575 | PC: 0x01dc64..0x01dca4 (64 B) | Symbol: sub_01dc64
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x528; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x528; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_01dc64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114A3E0ULL) << 32) | 0x9401ADA4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DC64ULL;
}

// Func #0576 | PC: 0x01dc6c..0x01dcac (64 B) | Symbol: sub_01dc6c
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x1dc80; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x1dc80; subs x19, x19, #0x30]
uint64_t fde_sub_01dc6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401A600ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DC6CULL;
}

// Func #0577 | PC: 0x01dc9c..0x01dcdc (64 B) | Symbol: sub_01dc9c
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x1dc78; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x1dc78; add x8, x21, x19]
uint64_t fde_sub_01dc9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF8F8DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DC9CULL;
}

// Func #0578 | PC: 0x01dcb0..0x01dcf0 (64 B) | Symbol: sub_01dcb0
// EN: AArch64 prologue [bl #0x1ad0; b #0x1dc78; adrp x0, #0xc0000; add x0, x0, #0x270] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x1dc78; adrp x0, #0xc0000; add x0, x0, #0x270]
uint64_t fde_sub_01dcb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF8F88ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DCB0ULL;
}

// Func #0579 | PC: 0x01dcc0..0x01dd00 (64 B) | Symbol: sub_01dcc0
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xa0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xa0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_01dcc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053F3ULL) << 32) | 0x97FF8F8CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DCC0ULL;
}

// Func #0580 | PC: 0x01dcfc..0x01dd3c (64 B) | Symbol: sub_01dcfc
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_01dcfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF8FB1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DCFCULL;
}

// Func #0581 | PC: 0x01dd00..0x01fb00 (7680 B) | Symbol: rex_locale_init_ctor_14
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_01dd00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DD00ULL;
}

// Func #0582 | PC: 0x01dd1c..0x01dd5c (64 B) | Symbol: sub_01dd1c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_01dd1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13183FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DD1CULL;
}

// Func #0583 | PC: 0x01dd20..0x01dd60 (64 B) | Symbol: sub_01dd20
// EN: AArch64 prologue [sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_01dd20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DD20ULL;
}

// Func #0584 | PC: 0x01dd48..0x01dd88 (64 B) | Symbol: sub_01dd48
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x1fc08; adrp x15, #0x9a000; add x15, x15, #0x52c] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x1fc08; adrp x15, #0x9a000; add x15, x15, #0x52c]
uint64_t fde_sub_01dd48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F5E0ULL) << 32) | 0x97FF8FAEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DD48ULL;
}

// Func #0585 | PC: 0x01e55c..0x01e59c (64 B) | Symbol: sub_01e55c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x9a000; add x8, x8, #0x747; ldur q0, [x8, #0xc]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x9a000; add x8, x8, #0x747; ldur q0, [x8, #0xc]]
uint64_t fde_sub_01e55c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900003E8ULL) << 32) | 0x97FF8D91ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E55CULL;
}

// Func #0586 | PC: 0x01e5c0..0x01e600 (64 B) | Symbol: sub_01e5c0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x71b; ldp q0, q1, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x71b; ldp q0, q1, [x9]]
uint64_t fde_sub_01e5c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900003E9ULL) << 32) | 0x97FF8D78ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E5C0ULL;
}

// Func #0587 | PC: 0x01e67c..0x01e6bc (64 B) | Symbol: sub_01e67c
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x741; ldp q0, q1, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x741; ldp q0, q1, [x9]]
uint64_t fde_sub_01e67c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900003E9ULL) << 32) | 0x97FF8D49ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E67CULL;
}

// Func #0588 | PC: 0x01e6e4..0x01e724 (64 B) | Symbol: sub_01e6e4
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xcb0]; str x0, [sp, #0x280]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xcb0]; str x0, [sp, #0x280]]
uint64_t fde_sub_01e6e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003C9ULL) << 32) | 0x97FF8D2FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E6E4ULL;
}

// Func #0589 | PC: 0x01eaec..0x01eb2c (64 B) | Symbol: sub_01eaec
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; ldr x9, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; ldr x9, [sp, #0x20]]
uint64_t fde_sub_01eaec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003C8ULL) << 32) | 0x97FF8C2DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EAECULL;
}

// Func #0590 | PC: 0x01ec64..0x01eca4 (64 B) | Symbol: sub_01ec64
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ec64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401A6C7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EC64ULL;
}

// Func #0591 | PC: 0x01ec74..0x01ecb4 (64 B) | Symbol: sub_01ec74
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ec74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401A6C3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EC74ULL;
}

// Func #0592 | PC: 0x01ec84..0x01ecc4 (64 B) | Symbol: sub_01ec84
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ec84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401A6BFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EC84ULL;
}

// Func #0593 | PC: 0x01ec94..0x01ecd4 (64 B) | Symbol: sub_01ec94
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ec94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401A6BBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EC94ULL;
}

// Func #0594 | PC: 0x01eca4..0x01ece4 (64 B) | Symbol: sub_01eca4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01eca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401A6B7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ECA4ULL;
}

// Func #0595 | PC: 0x01ecb4..0x01ecf4 (64 B) | Symbol: sub_01ecb4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ecb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401A6B3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ECB4ULL;
}

// Func #0596 | PC: 0x01ecc4..0x01ed04 (64 B) | Symbol: sub_01ecc4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ecc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401A6AFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ECC4ULL;
}

// Func #0597 | PC: 0x01ecd4..0x01ed14 (64 B) | Symbol: sub_01ecd4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ecd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401A6ABULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ECD4ULL;
}

// Func #0598 | PC: 0x01ece4..0x01ed24 (64 B) | Symbol: sub_01ece4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ece4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401A6A7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ECE4ULL;
}

// Func #0599 | PC: 0x01ecf4..0x01ed34 (64 B) | Symbol: sub_01ecf4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ecf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401A6A3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ECF4ULL;
}

// Func #0600 | PC: 0x01ed04..0x01ed44 (64 B) | Symbol: sub_01ed04
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ed04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401A69FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED04ULL;
}

// Func #0601 | PC: 0x01ed14..0x01ed54 (64 B) | Symbol: sub_01ed14
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ed14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401A69BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED14ULL;
}

// Func #0602 | PC: 0x01ed24..0x01ed64 (64 B) | Symbol: sub_01ed24
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_01ed24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401A697ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED24ULL;
}

// Func #0603 | PC: 0x01ed34..0x01ed74 (64 B) | Symbol: sub_01ed34
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ed34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401A693ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED34ULL;
}

// Func #0604 | PC: 0x01ed44..0x01ed84 (64 B) | Symbol: sub_01ed44
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ed44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401A68FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED44ULL;
}

// Func #0605 | PC: 0x01ed54..0x01ed94 (64 B) | Symbol: sub_01ed54
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_01ed54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401A68BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED54ULL;
}

// Func #0606 | PC: 0x01ed64..0x01eda4 (64 B) | Symbol: sub_01ed64
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ed64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401A687ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED64ULL;
}

// Func #0607 | PC: 0x01ed74..0x01edb4 (64 B) | Symbol: sub_01ed74
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_01ed74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401A683ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED74ULL;
}

// Func #0608 | PC: 0x01ed84..0x01edc4 (64 B) | Symbol: sub_01ed84
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_01ed84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401A67FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED84ULL;
}

// Func #0609 | PC: 0x01ed94..0x01edd4 (64 B) | Symbol: sub_01ed94
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01ed94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401A67BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01ED94ULL;
}

// Func #0610 | PC: 0x01eda4..0x01ede4 (64 B) | Symbol: sub_01eda4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01eda4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401A677ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EDA4ULL;
}

// Func #0611 | PC: 0x01edb4..0x01edf4 (64 B) | Symbol: sub_01edb4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_01edb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401A673ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EDB4ULL;
}

// Func #0612 | PC: 0x01edc4..0x01ee04 (64 B) | Symbol: sub_01edc4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_01edc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401A66FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EDC4ULL;
}

// Func #0613 | PC: 0x01edd4..0x01ee14 (64 B) | Symbol: sub_01edd4
// EN: AArch64 prologue [bl #0x88780; add x15, sp, #0x558; mov w10, #0xaf80; mov w11, #0x2e61] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x15, sp, #0x558; mov w10, #0xaf80; mov w11, #0x2e61]
uint64_t fde_sub_01edd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911563EFULL) << 32) | 0x9401A66BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EDD4ULL;
}

// Func #0614 | PC: 0x01fa0c..0x01fa4c (64 B) | Symbol: sub_01fa0c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x9a000; add x8, x8, #0x7f3; ldur q2, [x8, #9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x9a000; add x8, x8, #0x7f3; ldur q2, [x8, #9]]
uint64_t fde_sub_01fa0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00003C8ULL) << 32) | 0x97FF8865ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FA0CULL;
}

// Func #0615 | PC: 0x01fa40..0x01fa80 (64 B) | Symbol: sub_01fa40
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; add x8, sp, #1, lsl #12; add x8, x8, #0xa49] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; add x8, sp, #1, lsl #12; add x8, x8, #0xa49]
uint64_t fde_sub_01fa40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FF8858ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FA40ULL;
}

// Func #0616 | PC: 0x01fad0..0x01fb10 (64 B) | Symbol: sub_01fad0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0xa0000; add x9, x9, #0xa8c; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0xa0000; add x9, x9, #0xa8c; adrp x8, #0x97000]
uint64_t fde_sub_01fad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000409ULL) << 32) | 0x97FF8834ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FAD0ULL;
}

// Func #0617 | PC: 0x01fb0c..0x01fb4c (64 B) | Symbol: sub_01fb0c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x90]; add x8, sp, #1, lsl #12; add x8, x8, #0xad9] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x90]; add x8, sp, #1, lsl #12; add x8, x8, #0xad9]
uint64_t fde_sub_01fb0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC027E0ULL) << 32) | 0x97FF8825ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FB0CULL;
}

// Func #0618 | PC: 0x01fba4..0x01fbe4 (64 B) | Symbol: sub_01fba4
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x558; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x558; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_01fba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911563E0ULL) << 32) | 0x9401A5D4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FBA4ULL;
}

// Func #0619 | PC: 0x01fbac..0x01fbec (64 B) | Symbol: sub_01fbac
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x1fbc0; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x1fbc0; subs x19, x19, #0x30]
uint64_t fde_sub_01fbac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94019E30ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FBACULL;
}

// Func #0620 | PC: 0x01fbdc..0x01fc1c (64 B) | Symbol: sub_01fbdc
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x1fbb8; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x1fbb8; add x8, x21, x19]
uint64_t fde_sub_01fbdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF87BDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FBDCULL;
}

// Func #0621 | PC: 0x01fbf0..0x01fc30 (64 B) | Symbol: sub_01fbf0
// EN: AArch64 prologue [bl #0x1ad0; b #0x1fbb8; adrp x0, #0xc1000; add x0, x0, #0x970] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x1fbb8; adrp x0, #0xc1000; add x0, x0, #0x970]
uint64_t fde_sub_01fbf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF87B8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FBF0ULL;
}

// Func #0622 | PC: 0x01fc00..0x01fc40 (64 B) | Symbol: sub_01fc00
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_01fc00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405FF3ULL) << 32) | 0x97FF87BCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FC00ULL;
}

// Func #0623 | PC: 0x01fc3c..0x01fc7c (64 B) | Symbol: sub_01fc3c
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_01fc3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF87E1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FC3CULL;
}

// Func #0624 | PC: 0x01fc40..0x021a40 (7680 B) | Symbol: rex_locale_init_ctor_15
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_01fc40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FC40ULL;
}

// Func #0625 | PC: 0x01fc5c..0x01fc9c (64 B) | Symbol: sub_01fc5c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_01fc5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13183FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FC5CULL;
}

// Func #0626 | PC: 0x01fc60..0x01fca0 (64 B) | Symbol: sub_01fc60
// EN: AArch64 prologue [sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_01fc60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FC60ULL;
}

// Func #0627 | PC: 0x01fc88..0x01fcc8 (64 B) | Symbol: sub_01fc88
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x21ad8; mov x5, #0x6576; movi v1.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x21ad8; mov x5, #0x6576; movi v1.2d, #0000000000000000]
uint64_t fde_sub_01fc88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F260ULL) << 32) | 0x97FF87DEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FC88ULL;
}

// Func #0628 | PC: 0x0204fc..0x02053c (64 B) | Symbol: sub_0204fc
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x8af; ldur q0, [x9, #0xb]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x8af; ldur q0, [x9, #0xb]]
uint64_t fde_sub_0204fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00003C9ULL) << 32) | 0x97FF85A9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0204FCULL;
}

// Func #0629 | PC: 0x0205bc..0x0205fc (64 B) | Symbol: sub_0205bc
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x9a000]
uint64_t fde_sub_0205bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00003A9ULL) << 32) | 0x97FF8579ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0205BCULL;
}

// Func #0630 | PC: 0x020a38..0x020a78 (64 B) | Symbol: sub_020a38
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x10]]
uint64_t fde_sub_020a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00003A8ULL) << 32) | 0x97FF845AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020A38ULL;
}

// Func #0631 | PC: 0x020ba0..0x020be0 (64 B) | Symbol: sub_020ba0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94019EF8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020BA0ULL;
}

// Func #0632 | PC: 0x020bb0..0x020bf0 (64 B) | Symbol: sub_020bb0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020bb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94019EF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020BB0ULL;
}

// Func #0633 | PC: 0x020bc0..0x020c00 (64 B) | Symbol: sub_020bc0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020bc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94019EF0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020BC0ULL;
}

// Func #0634 | PC: 0x020bd0..0x020c10 (64 B) | Symbol: sub_020bd0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94019EECULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020BD0ULL;
}

// Func #0635 | PC: 0x020be0..0x020c20 (64 B) | Symbol: sub_020be0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020be0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x94019EE8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020BE0ULL;
}

// Func #0636 | PC: 0x020bf0..0x020c30 (64 B) | Symbol: sub_020bf0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020bf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94019EE4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020BF0ULL;
}

// Func #0637 | PC: 0x020c00..0x020c40 (64 B) | Symbol: sub_020c00
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94019EE0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C00ULL;
}

// Func #0638 | PC: 0x020c10..0x020c50 (64 B) | Symbol: sub_020c10
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94019EDCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C10ULL;
}

// Func #0639 | PC: 0x020c20..0x020c60 (64 B) | Symbol: sub_020c20
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94019ED8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C20ULL;
}

uint64_t DispatchRexShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x010fbcULL: return fde_sub_010fbc(a0, a1, a2);
        case 0x010fccULL: return fde_sub_010fcc(a0, a1, a2);
        case 0x010fdcULL: return fde_sub_010fdc(a0, a1, a2);
        case 0x010fecULL: return fde_sub_010fec(a0, a1, a2);
        case 0x010ffcULL: return fde_sub_010ffc(a0, a1, a2);
        case 0x01100cULL: return fde_sub_01100c(a0, a1, a2);
        case 0x01101cULL: return fde_sub_01101c(a0, a1, a2);
        case 0x01102cULL: return fde_sub_01102c(a0, a1, a2);
        case 0x01103cULL: return fde_sub_01103c(a0, a1, a2);
        case 0x01104cULL: return fde_sub_01104c(a0, a1, a2);
        case 0x01105cULL: return fde_sub_01105c(a0, a1, a2);
        case 0x01106cULL: return fde_sub_01106c(a0, a1, a2);
        case 0x01107cULL: return fde_sub_01107c(a0, a1, a2);
        case 0x01108cULL: return fde_sub_01108c(a0, a1, a2);
        case 0x01109cULL: return fde_sub_01109c(a0, a1, a2);
        case 0x0110b0ULL: return fde_sub_0110b0(a0, a1, a2);
        case 0x0110c0ULL: return fde_sub_0110c0(a0, a1, a2);
        case 0x0110d0ULL: return fde_sub_0110d0(a0, a1, a2);
        case 0x0110e0ULL: return fde_sub_0110e0(a0, a1, a2);
        case 0x0110f0ULL: return fde_sub_0110f0(a0, a1, a2);
        case 0x011100ULL: return fde_sub_011100(a0, a1, a2);
        case 0x012324ULL: return fde_sub_012324(a0, a1, a2);
        case 0x01232cULL: return fde_sub_01232c(a0, a1, a2);
        case 0x01235cULL: return fde_sub_01235c(a0, a1, a2);
        case 0x012370ULL: return fde_sub_012370(a0, a1, a2);
        case 0x012380ULL: return fde_sub_012380(a0, a1, a2);
        case 0x0123bcULL: return fde_sub_0123bc(a0, a1, a2);
        case 0x0123c0ULL: return fde_sub_0123c0(a0, a1, a2);
        case 0x0123dcULL: return fde_sub_0123dc(a0, a1, a2);
        case 0x0123e0ULL: return fde_sub_0123e0(a0, a1, a2);
        case 0x012408ULL: return fde_sub_012408(a0, a1, a2);
        case 0x012c2cULL: return fde_sub_012c2c(a0, a1, a2);
        case 0x012cecULL: return fde_sub_012cec(a0, a1, a2);
        case 0x013160ULL: return fde_sub_013160(a0, a1, a2);
        case 0x0132d0ULL: return fde_sub_0132d0(a0, a1, a2);
        case 0x0132e0ULL: return fde_sub_0132e0(a0, a1, a2);
        case 0x0132f0ULL: return fde_sub_0132f0(a0, a1, a2);
        case 0x013300ULL: return fde_sub_013300(a0, a1, a2);
        case 0x013310ULL: return fde_sub_013310(a0, a1, a2);
        case 0x013320ULL: return fde_sub_013320(a0, a1, a2);
        case 0x013330ULL: return fde_sub_013330(a0, a1, a2);
        case 0x013340ULL: return fde_sub_013340(a0, a1, a2);
        case 0x013350ULL: return fde_sub_013350(a0, a1, a2);
        case 0x013360ULL: return fde_sub_013360(a0, a1, a2);
        case 0x013370ULL: return fde_sub_013370(a0, a1, a2);
        case 0x013380ULL: return fde_sub_013380(a0, a1, a2);
        case 0x013390ULL: return fde_sub_013390(a0, a1, a2);
        case 0x0133a0ULL: return fde_sub_0133a0(a0, a1, a2);
        case 0x0133b0ULL: return fde_sub_0133b0(a0, a1, a2);
        case 0x0133c0ULL: return fde_sub_0133c0(a0, a1, a2);
        case 0x0133d0ULL: return fde_sub_0133d0(a0, a1, a2);
        case 0x0133e0ULL: return fde_sub_0133e0(a0, a1, a2);
        case 0x0133f0ULL: return fde_sub_0133f0(a0, a1, a2);
        case 0x013400ULL: return fde_sub_013400(a0, a1, a2);
        case 0x013410ULL: return fde_sub_013410(a0, a1, a2);
        case 0x013420ULL: return fde_sub_013420(a0, a1, a2);
        case 0x013430ULL: return fde_sub_013430(a0, a1, a2);
        case 0x013440ULL: return fde_sub_013440(a0, a1, a2);
        case 0x0141d8ULL: return fde_sub_0141d8(a0, a1, a2);
        case 0x0141e0ULL: return fde_sub_0141e0(a0, a1, a2);
        case 0x014210ULL: return fde_sub_014210(a0, a1, a2);
        case 0x014224ULL: return fde_sub_014224(a0, a1, a2);
        case 0x014234ULL: return fde_sub_014234(a0, a1, a2);
        case 0x014270ULL: return fde_sub_014270(a0, a1, a2);
        case 0x014274ULL: return fde_sub_014274(a0, a1, a2);
        case 0x014290ULL: return fde_sub_014290(a0, a1, a2);
        case 0x014294ULL: return fde_sub_014294(a0, a1, a2);
        case 0x0142bcULL: return fde_sub_0142bc(a0, a1, a2);
        case 0x014aecULL: return fde_sub_014aec(a0, a1, a2);
        case 0x014ba8ULL: return fde_sub_014ba8(a0, a1, a2);
        case 0x01502cULL: return fde_sub_01502c(a0, a1, a2);
        case 0x01519cULL: return fde_sub_01519c(a0, a1, a2);
        case 0x0151acULL: return fde_sub_0151ac(a0, a1, a2);
        case 0x0151bcULL: return fde_sub_0151bc(a0, a1, a2);
        case 0x0151ccULL: return fde_sub_0151cc(a0, a1, a2);
        case 0x0151dcULL: return fde_sub_0151dc(a0, a1, a2);
        case 0x0151ecULL: return fde_sub_0151ec(a0, a1, a2);
        case 0x0151fcULL: return fde_sub_0151fc(a0, a1, a2);
        case 0x01520cULL: return fde_sub_01520c(a0, a1, a2);
        case 0x01521cULL: return fde_sub_01521c(a0, a1, a2);
        case 0x01522cULL: return fde_sub_01522c(a0, a1, a2);
        case 0x01523cULL: return fde_sub_01523c(a0, a1, a2);
        case 0x01524cULL: return fde_sub_01524c(a0, a1, a2);
        case 0x01525cULL: return fde_sub_01525c(a0, a1, a2);
        case 0x01526cULL: return fde_sub_01526c(a0, a1, a2);
        case 0x01527cULL: return fde_sub_01527c(a0, a1, a2);
        case 0x01528cULL: return fde_sub_01528c(a0, a1, a2);
        case 0x01529cULL: return fde_sub_01529c(a0, a1, a2);
        case 0x0152acULL: return fde_sub_0152ac(a0, a1, a2);
        case 0x0152bcULL: return fde_sub_0152bc(a0, a1, a2);
        case 0x0152ccULL: return fde_sub_0152cc(a0, a1, a2);
        case 0x0152dcULL: return fde_sub_0152dc(a0, a1, a2);
        case 0x0152ecULL: return fde_sub_0152ec(a0, a1, a2);
        case 0x0152fcULL: return fde_sub_0152fc(a0, a1, a2);
        case 0x01530cULL: return fde_sub_01530c(a0, a1, a2);
        case 0x0160acULL: return fde_sub_0160ac(a0, a1, a2);
        case 0x0160b4ULL: return fde_sub_0160b4(a0, a1, a2);
        case 0x0160e4ULL: return fde_sub_0160e4(a0, a1, a2);
        case 0x0160f8ULL: return fde_sub_0160f8(a0, a1, a2);
        case 0x016108ULL: return fde_sub_016108(a0, a1, a2);
        case 0x016144ULL: return fde_sub_016144(a0, a1, a2);
        case 0x016148ULL: return fde_sub_016148(a0, a1, a2);
        case 0x016164ULL: return fde_sub_016164(a0, a1, a2);
        case 0x016168ULL: return fde_sub_016168(a0, a1, a2);
        case 0x016190ULL: return fde_sub_016190(a0, a1, a2);
        case 0x016b28ULL: return fde_sub_016b28(a0, a1, a2);
        case 0x016be8ULL: return fde_sub_016be8(a0, a1, a2);
        case 0x017048ULL: return fde_sub_017048(a0, a1, a2);
        case 0x0171c0ULL: return fde_sub_0171c0(a0, a1, a2);
        case 0x0171d0ULL: return fde_sub_0171d0(a0, a1, a2);
        case 0x0171e0ULL: return fde_sub_0171e0(a0, a1, a2);
        case 0x0171f0ULL: return fde_sub_0171f0(a0, a1, a2);
        case 0x017200ULL: return fde_sub_017200(a0, a1, a2);
        case 0x017210ULL: return fde_sub_017210(a0, a1, a2);
        case 0x017220ULL: return fde_sub_017220(a0, a1, a2);
        case 0x017230ULL: return fde_sub_017230(a0, a1, a2);
        case 0x017240ULL: return fde_sub_017240(a0, a1, a2);
        case 0x017250ULL: return fde_sub_017250(a0, a1, a2);
        case 0x017260ULL: return fde_sub_017260(a0, a1, a2);
        case 0x017270ULL: return fde_sub_017270(a0, a1, a2);
        case 0x017280ULL: return fde_sub_017280(a0, a1, a2);
        case 0x017290ULL: return fde_sub_017290(a0, a1, a2);
        case 0x0172a0ULL: return fde_sub_0172a0(a0, a1, a2);
        case 0x0172b0ULL: return fde_sub_0172b0(a0, a1, a2);
        case 0x0172c0ULL: return fde_sub_0172c0(a0, a1, a2);
        case 0x0172d0ULL: return fde_sub_0172d0(a0, a1, a2);
        case 0x0172e0ULL: return fde_sub_0172e0(a0, a1, a2);
        case 0x0172f0ULL: return fde_sub_0172f0(a0, a1, a2);
        case 0x017300ULL: return fde_sub_017300(a0, a1, a2);
        case 0x017310ULL: return fde_sub_017310(a0, a1, a2);
        case 0x017320ULL: return fde_sub_017320(a0, a1, a2);
        case 0x017330ULL: return fde_sub_017330(a0, a1, a2);
        case 0x01784cULL: return fde_sub_01784c(a0, a1, a2);
        case 0x0178b0ULL: return fde_sub_0178b0(a0, a1, a2);
        case 0x0178ecULL: return fde_sub_0178ec(a0, a1, a2);
        case 0x017938ULL: return fde_sub_017938(a0, a1, a2);
        case 0x017978ULL: return fde_sub_017978(a0, a1, a2);
        case 0x0179d0ULL: return fde_sub_0179d0(a0, a1, a2);
        case 0x017a04ULL: return fde_sub_017a04(a0, a1, a2);
        case 0x017a54ULL: return fde_sub_017a54(a0, a1, a2);
        case 0x017af4ULL: return fde_sub_017af4(a0, a1, a2);
        case 0x017b48ULL: return fde_sub_017b48(a0, a1, a2);
        case 0x017b7cULL: return fde_sub_017b7c(a0, a1, a2);
        case 0x017bd0ULL: return fde_sub_017bd0(a0, a1, a2);
        case 0x018168ULL: return fde_sub_018168(a0, a1, a2);
        case 0x018170ULL: return fde_sub_018170(a0, a1, a2);
        case 0x0181a0ULL: return fde_sub_0181a0(a0, a1, a2);
        case 0x0181b4ULL: return fde_sub_0181b4(a0, a1, a2);
        case 0x0181c4ULL: return fde_sub_0181c4(a0, a1, a2);
        case 0x018200ULL: return fde_sub_018200(a0, a1, a2);
        case 0x018204ULL: return fde_sub_018204(a0, a1, a2);
        case 0x018220ULL: return fde_sub_018220(a0, a1, a2);
        case 0x018224ULL: return fde_sub_018224(a0, a1, a2);
        case 0x01824cULL: return fde_sub_01824c(a0, a1, a2);
        case 0x018ac8ULL: return fde_sub_018ac8(a0, a1, a2);
        case 0x018b8cULL: return fde_sub_018b8c(a0, a1, a2);
        case 0x018ff8ULL: return fde_sub_018ff8(a0, a1, a2);
        case 0x01916cULL: return fde_sub_01916c(a0, a1, a2);
        case 0x01917cULL: return fde_sub_01917c(a0, a1, a2);
        case 0x01918cULL: return fde_sub_01918c(a0, a1, a2);
        case 0x01919cULL: return fde_sub_01919c(a0, a1, a2);
        case 0x0191acULL: return fde_sub_0191ac(a0, a1, a2);
        case 0x0191bcULL: return fde_sub_0191bc(a0, a1, a2);
        case 0x0191ccULL: return fde_sub_0191cc(a0, a1, a2);
        case 0x0191dcULL: return fde_sub_0191dc(a0, a1, a2);
        case 0x0191ecULL: return fde_sub_0191ec(a0, a1, a2);
        case 0x0191fcULL: return fde_sub_0191fc(a0, a1, a2);
        case 0x01920cULL: return fde_sub_01920c(a0, a1, a2);
        case 0x01921cULL: return fde_sub_01921c(a0, a1, a2);
        case 0x01922cULL: return fde_sub_01922c(a0, a1, a2);
        case 0x01923cULL: return fde_sub_01923c(a0, a1, a2);
        case 0x01924cULL: return fde_sub_01924c(a0, a1, a2);
        case 0x01925cULL: return fde_sub_01925c(a0, a1, a2);
        case 0x01926cULL: return fde_sub_01926c(a0, a1, a2);
        case 0x01927cULL: return fde_sub_01927c(a0, a1, a2);
        case 0x01928cULL: return fde_sub_01928c(a0, a1, a2);
        case 0x01929cULL: return fde_sub_01929c(a0, a1, a2);
        case 0x0192acULL: return fde_sub_0192ac(a0, a1, a2);
        case 0x0192bcULL: return fde_sub_0192bc(a0, a1, a2);
        case 0x0192ccULL: return fde_sub_0192cc(a0, a1, a2);
        case 0x0192dcULL: return fde_sub_0192dc(a0, a1, a2);
        case 0x019f78ULL: return fde_sub_019f78(a0, a1, a2);
        case 0x019f80ULL: return fde_sub_019f80(a0, a1, a2);
        case 0x019fb0ULL: return fde_sub_019fb0(a0, a1, a2);
        case 0x019fc4ULL: return fde_sub_019fc4(a0, a1, a2);
        case 0x019fd4ULL: return fde_sub_019fd4(a0, a1, a2);
        case 0x01a010ULL: return fde_sub_01a010(a0, a1, a2);
        case 0x01a014ULL: return fde_sub_01a014(a0, a1, a2);
        case 0x01a030ULL: return fde_sub_01a030(a0, a1, a2);
        case 0x01a034ULL: return fde_sub_01a034(a0, a1, a2);
        case 0x01a05cULL: return fde_sub_01a05c(a0, a1, a2);
        case 0x01a8e8ULL: return fde_sub_01a8e8(a0, a1, a2);
        case 0x01a9b0ULL: return fde_sub_01a9b0(a0, a1, a2);
        case 0x01ae14ULL: return fde_sub_01ae14(a0, a1, a2);
        case 0x01af88ULL: return fde_sub_01af88(a0, a1, a2);
        case 0x01af98ULL: return fde_sub_01af98(a0, a1, a2);
        case 0x01afa8ULL: return fde_sub_01afa8(a0, a1, a2);
        case 0x01afb8ULL: return fde_sub_01afb8(a0, a1, a2);
        case 0x01afc8ULL: return fde_sub_01afc8(a0, a1, a2);
        case 0x01afd8ULL: return fde_sub_01afd8(a0, a1, a2);
        case 0x01afe8ULL: return fde_sub_01afe8(a0, a1, a2);
        case 0x01aff8ULL: return fde_sub_01aff8(a0, a1, a2);
        case 0x01b008ULL: return fde_sub_01b008(a0, a1, a2);
        case 0x01b018ULL: return fde_sub_01b018(a0, a1, a2);
        case 0x01b028ULL: return fde_sub_01b028(a0, a1, a2);
        case 0x01b038ULL: return fde_sub_01b038(a0, a1, a2);
        case 0x01b048ULL: return fde_sub_01b048(a0, a1, a2);
        case 0x01b058ULL: return fde_sub_01b058(a0, a1, a2);
        case 0x01b068ULL: return fde_sub_01b068(a0, a1, a2);
        case 0x01b078ULL: return fde_sub_01b078(a0, a1, a2);
        case 0x01b088ULL: return fde_sub_01b088(a0, a1, a2);
        case 0x01b098ULL: return fde_sub_01b098(a0, a1, a2);
        case 0x01b0a8ULL: return fde_sub_01b0a8(a0, a1, a2);
        case 0x01b0b8ULL: return fde_sub_01b0b8(a0, a1, a2);
        case 0x01b0c8ULL: return fde_sub_01b0c8(a0, a1, a2);
        case 0x01b0d8ULL: return fde_sub_01b0d8(a0, a1, a2);
        case 0x01b0e8ULL: return fde_sub_01b0e8(a0, a1, a2);
        case 0x01b0f8ULL: return fde_sub_01b0f8(a0, a1, a2);
        case 0x01be74ULL: return fde_sub_01be74(a0, a1, a2);
        case 0x01be7cULL: return fde_sub_01be7c(a0, a1, a2);
        case 0x01beacULL: return fde_sub_01beac(a0, a1, a2);
        case 0x01bec0ULL: return fde_sub_01bec0(a0, a1, a2);
        case 0x01bed0ULL: return fde_sub_01bed0(a0, a1, a2);
        case 0x01bf0cULL: return fde_sub_01bf0c(a0, a1, a2);
        case 0x01bf10ULL: return fde_sub_01bf10(a0, a1, a2);
        case 0x01bf2cULL: return fde_sub_01bf2c(a0, a1, a2);
        case 0x01bf30ULL: return fde_sub_01bf30(a0, a1, a2);
        case 0x01bf58ULL: return fde_sub_01bf58(a0, a1, a2);
        case 0x01c750ULL: return fde_sub_01c750(a0, a1, a2);
        case 0x01c7acULL: return fde_sub_01c7ac(a0, a1, a2);
        case 0x01c864ULL: return fde_sub_01c864(a0, a1, a2);
        case 0x01cdf4ULL: return fde_sub_01cdf4(a0, a1, a2);
        case 0x01ce04ULL: return fde_sub_01ce04(a0, a1, a2);
        case 0x01ce14ULL: return fde_sub_01ce14(a0, a1, a2);
        case 0x01ce24ULL: return fde_sub_01ce24(a0, a1, a2);
        case 0x01ce34ULL: return fde_sub_01ce34(a0, a1, a2);
        case 0x01ce44ULL: return fde_sub_01ce44(a0, a1, a2);
        case 0x01ce54ULL: return fde_sub_01ce54(a0, a1, a2);
        case 0x01ce64ULL: return fde_sub_01ce64(a0, a1, a2);
        case 0x01ce74ULL: return fde_sub_01ce74(a0, a1, a2);
        case 0x01ce84ULL: return fde_sub_01ce84(a0, a1, a2);
        case 0x01ce94ULL: return fde_sub_01ce94(a0, a1, a2);
        case 0x01cea4ULL: return fde_sub_01cea4(a0, a1, a2);
        case 0x01ceb4ULL: return fde_sub_01ceb4(a0, a1, a2);
        case 0x01cec4ULL: return fde_sub_01cec4(a0, a1, a2);
        case 0x01ced4ULL: return fde_sub_01ced4(a0, a1, a2);
        case 0x01cee4ULL: return fde_sub_01cee4(a0, a1, a2);
        case 0x01cef4ULL: return fde_sub_01cef4(a0, a1, a2);
        case 0x01cf04ULL: return fde_sub_01cf04(a0, a1, a2);
        case 0x01cf14ULL: return fde_sub_01cf14(a0, a1, a2);
        case 0x01cf28ULL: return fde_sub_01cf28(a0, a1, a2);
        case 0x01cf38ULL: return fde_sub_01cf38(a0, a1, a2);
        case 0x01cf48ULL: return fde_sub_01cf48(a0, a1, a2);
        case 0x01cf58ULL: return fde_sub_01cf58(a0, a1, a2);
        case 0x01cf68ULL: return fde_sub_01cf68(a0, a1, a2);
        case 0x01dc64ULL: return fde_sub_01dc64(a0, a1, a2);
        case 0x01dc6cULL: return fde_sub_01dc6c(a0, a1, a2);
        case 0x01dc9cULL: return fde_sub_01dc9c(a0, a1, a2);
        case 0x01dcb0ULL: return fde_sub_01dcb0(a0, a1, a2);
        case 0x01dcc0ULL: return fde_sub_01dcc0(a0, a1, a2);
        case 0x01dcfcULL: return fde_sub_01dcfc(a0, a1, a2);
        case 0x01dd00ULL: return fde_sub_01dd00(a0, a1, a2);
        case 0x01dd1cULL: return fde_sub_01dd1c(a0, a1, a2);
        case 0x01dd20ULL: return fde_sub_01dd20(a0, a1, a2);
        case 0x01dd48ULL: return fde_sub_01dd48(a0, a1, a2);
        case 0x01e55cULL: return fde_sub_01e55c(a0, a1, a2);
        case 0x01e5c0ULL: return fde_sub_01e5c0(a0, a1, a2);
        case 0x01e67cULL: return fde_sub_01e67c(a0, a1, a2);
        case 0x01e6e4ULL: return fde_sub_01e6e4(a0, a1, a2);
        case 0x01eaecULL: return fde_sub_01eaec(a0, a1, a2);
        case 0x01ec64ULL: return fde_sub_01ec64(a0, a1, a2);
        case 0x01ec74ULL: return fde_sub_01ec74(a0, a1, a2);
        case 0x01ec84ULL: return fde_sub_01ec84(a0, a1, a2);
        case 0x01ec94ULL: return fde_sub_01ec94(a0, a1, a2);
        case 0x01eca4ULL: return fde_sub_01eca4(a0, a1, a2);
        case 0x01ecb4ULL: return fde_sub_01ecb4(a0, a1, a2);
        case 0x01ecc4ULL: return fde_sub_01ecc4(a0, a1, a2);
        case 0x01ecd4ULL: return fde_sub_01ecd4(a0, a1, a2);
        case 0x01ece4ULL: return fde_sub_01ece4(a0, a1, a2);
        case 0x01ecf4ULL: return fde_sub_01ecf4(a0, a1, a2);
        case 0x01ed04ULL: return fde_sub_01ed04(a0, a1, a2);
        case 0x01ed14ULL: return fde_sub_01ed14(a0, a1, a2);
        case 0x01ed24ULL: return fde_sub_01ed24(a0, a1, a2);
        case 0x01ed34ULL: return fde_sub_01ed34(a0, a1, a2);
        case 0x01ed44ULL: return fde_sub_01ed44(a0, a1, a2);
        case 0x01ed54ULL: return fde_sub_01ed54(a0, a1, a2);
        case 0x01ed64ULL: return fde_sub_01ed64(a0, a1, a2);
        case 0x01ed74ULL: return fde_sub_01ed74(a0, a1, a2);
        case 0x01ed84ULL: return fde_sub_01ed84(a0, a1, a2);
        case 0x01ed94ULL: return fde_sub_01ed94(a0, a1, a2);
        case 0x01eda4ULL: return fde_sub_01eda4(a0, a1, a2);
        case 0x01edb4ULL: return fde_sub_01edb4(a0, a1, a2);
        case 0x01edc4ULL: return fde_sub_01edc4(a0, a1, a2);
        case 0x01edd4ULL: return fde_sub_01edd4(a0, a1, a2);
        case 0x01fa0cULL: return fde_sub_01fa0c(a0, a1, a2);
        case 0x01fa40ULL: return fde_sub_01fa40(a0, a1, a2);
        case 0x01fad0ULL: return fde_sub_01fad0(a0, a1, a2);
        case 0x01fb0cULL: return fde_sub_01fb0c(a0, a1, a2);
        case 0x01fba4ULL: return fde_sub_01fba4(a0, a1, a2);
        case 0x01fbacULL: return fde_sub_01fbac(a0, a1, a2);
        case 0x01fbdcULL: return fde_sub_01fbdc(a0, a1, a2);
        case 0x01fbf0ULL: return fde_sub_01fbf0(a0, a1, a2);
        case 0x01fc00ULL: return fde_sub_01fc00(a0, a1, a2);
        case 0x01fc3cULL: return fde_sub_01fc3c(a0, a1, a2);
        case 0x01fc40ULL: return fde_sub_01fc40(a0, a1, a2);
        case 0x01fc5cULL: return fde_sub_01fc5c(a0, a1, a2);
        case 0x01fc60ULL: return fde_sub_01fc60(a0, a1, a2);
        case 0x01fc88ULL: return fde_sub_01fc88(a0, a1, a2);
        case 0x0204fcULL: return fde_sub_0204fc(a0, a1, a2);
        case 0x0205bcULL: return fde_sub_0205bc(a0, a1, a2);
        case 0x020a38ULL: return fde_sub_020a38(a0, a1, a2);
        case 0x020ba0ULL: return fde_sub_020ba0(a0, a1, a2);
        case 0x020bb0ULL: return fde_sub_020bb0(a0, a1, a2);
        case 0x020bc0ULL: return fde_sub_020bc0(a0, a1, a2);
        case 0x020bd0ULL: return fde_sub_020bd0(a0, a1, a2);
        case 0x020be0ULL: return fde_sub_020be0(a0, a1, a2);
        case 0x020bf0ULL: return fde_sub_020bf0(a0, a1, a2);
        case 0x020c00ULL: return fde_sub_020c00(a0, a1, a2);
        case 0x020c10ULL: return fde_sub_020c10(a0, a1, a2);
        case 0x020c20ULL: return fde_sub_020c20(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace rex
} // namespace bytedance
