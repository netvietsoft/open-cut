// ============================================================================
// File: animax_fde_shard_4.cpp
// Target 108 / 169: libanimax.so (657,720 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 4/5 covering FDEs [2379..3171]
//     (PC range 0x08bb6c .. 0x090578).
// VI: Phân mảnh FDE AArch64 C++17 4/5 bao phủ FDE [2379..3171]
//     (Dải địa chỉ PC 0x08bb6c .. 0x090578).
// ============================================================================
#include "animax_player_core.h"

namespace lynx {
namespace animax {

// FDE #2379 | PC: 0x08bb6c..0x08bb70 (4 B) | Symbol: sub_08bb6c
// EN: AArch64 prologue [b #0x94770] | VI: Khởi đầu hàm AArch64 [b #0x94770]
uint64_t fde_sub_08bb6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002304ULL) << 32) | 0x14002301ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BB6CULL;
}

// FDE #2380 | PC: 0x08bb70..0x08bb74 (4 B) | Symbol: sub_08bb70
// EN: AArch64 prologue [b #0x94780] | VI: Khởi đầu hàm AArch64 [b #0x94780]
uint64_t fde_sub_08bb70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002307ULL) << 32) | 0x14002304ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BB70ULL;
}

// FDE #2381 | PC: 0x08bb74..0x08bb78 (4 B) | Symbol: sub_08bb74
// EN: AArch64 prologue [b #0x94790] | VI: Khởi đầu hàm AArch64 [b #0x94790]
uint64_t fde_sub_08bb74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0x14002307ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BB74ULL;
}

// FDE #2382 | PC: 0x08bb78..0x08bbd8 (96 B) | Symbol: sub_08bb78
// EN: AArch64 prologue [sub sp, sp, #0x70; str x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; adrp x8, #0x1b000] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; adrp x8, #0x1b000]
uint64_t fde_sub_08bb78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF4ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BB78ULL;
}

// FDE #2383 | PC: 0x08bbd8..0x08bc28 (80 B) | Symbol: sub_08bbd8
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x19, x30, [sp, #0x50]; bl #0x92850; mov w8, #0x3f800000] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x19, x30, [sp, #0x50]; bl #0x92850; mov w8, #0x3f800000]
uint64_t fde_sub_08bbd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9057BF3ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BBD8ULL;
}

// FDE #2384 | PC: 0x08bc28..0x08bc78 (80 B) | Symbol: sub_08bc28
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x19, x30, [sp, #0x50]; bl #0x92850; mov w8, #0x3f800000] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x19, x30, [sp, #0x50]; bl #0x92850; mov w8, #0x3f800000]
uint64_t fde_sub_08bc28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9057BF3ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BC28ULL;
}

// FDE #2385 | PC: 0x08bc78..0x08bcd4 (92 B) | Symbol: sub_08bc78
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; mrs x19, tpidr_el0; adrp x8, #0x1b000] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; mrs x19, tpidr_el0; adrp x8, #0x1b000]
uint64_t fde_sub_08bc78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BC78ULL;
}

// FDE #2386 | PC: 0x08bcd4..0x08bd00 (44 B) | Symbol: sub_08bcd4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; str xzr, [x0]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; str xzr, [x0]]
uint64_t fde_sub_08bcd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BCD4ULL;
}

// FDE #2387 | PC: 0x08bd00..0x08bd30 (48 B) | Symbol: sub_08bd00
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; str xzr, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; str xzr, [x0, #8]]
uint64_t fde_sub_08bd00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BD00ULL;
}

// FDE #2388 | PC: 0x08bd30..0x08bd38 (8 B) | Symbol: sub_08bd30
// EN: AArch64 prologue [and w1, w1, #1; b #0x947b0] | VI: Khởi đầu hàm AArch64 [and w1, w1, #1; b #0x947b0]
uint64_t fde_sub_08bd30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400229FULL) << 32) | 0x12000021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BD30ULL;
}

// FDE #2389 | PC: 0x08bd38..0x08bd40 (8 B) | Symbol: sub_08bd38
// EN: AArch64 prologue [fcvtzs w1, s0; b #0x947c0] | VI: Khởi đầu hàm AArch64 [fcvtzs w1, s0; b #0x947c0]
uint64_t fde_sub_08bd38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140022A1ULL) << 32) | 0x1E380001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BD38ULL;
}

// FDE #2390 | PC: 0x08bd40..0x08bd78 (56 B) | Symbol: sub_08bd40
// EN: AArch64 prologue [mov x2, x30; bl #0x8f3ac; mov x30, x2; ldr x0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8f3ac; mov x30, x2; ldr x0, [x0, #8]]
uint64_t fde_sub_08bd40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000D9AULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BD40ULL;
}

// FDE #2391 | PC: 0x08bd78..0x08be20 (168 B) | Symbol: sub_08bd78
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x92728] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x92728]
uint64_t fde_sub_08bd78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BD78ULL;
}

// FDE #2392 | PC: 0x08be20..0x08be30 (16 B) | Symbol: sub_08be20
// EN: AArch64 prologue [and w8, w1, #0xff; cmp w8, #4; csel w1, w1, wzr, lo; b #0x947e0] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xff; cmp w8, #4; csel w1, w1, wzr, lo; b #0x947e0]
uint64_t fde_sub_08be20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100111FULL) << 32) | 0x12001C28ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE20ULL;
}

// FDE #2393 | PC: 0x08be30..0x08be64 (52 B) | Symbol: sub_08be30
// EN: AArch64 prologue [mov x2, x30; bl #0x8f3ac; mov x30, x2; lsl w1, w9, #0x18] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8f3ac; mov x30, x2; lsl w1, w9, #0x18]
uint64_t fde_sub_08be30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000D5EULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE30ULL;
}

// FDE #2394 | PC: 0x08be64..0x08be74 (16 B) | Symbol: sub_08be64
// EN: AArch64 prologue [and w8, w1, #0xff; cmp w8, #3; csel w1, w1, wzr, lo; b #0x94800] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xff; cmp w8, #3; csel w1, w1, wzr, lo; b #0x94800]
uint64_t fde_sub_08be64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71000D1FULL) << 32) | 0x12001C28ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE64ULL;
}

// FDE #2395 | PC: 0x08be74..0x08be84 (16 B) | Symbol: sub_08be74
// EN: AArch64 prologue [and w8, w1, #0xff; cmp w8, #3; csinc w1, w1, wzr, lo; b #0x94810] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xff; cmp w8, #3; csinc w1, w1, wzr, lo; b #0x94810]
uint64_t fde_sub_08be74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71000D1FULL) << 32) | 0x12001C28ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE74ULL;
}

// FDE #2396 | PC: 0x08be84..0x08be88 (4 B) | Symbol: sub_08be84
// EN: AArch64 prologue [b #0x94820] | VI: Khởi đầu hàm AArch64 [b #0x94820]
uint64_t fde_sub_08be84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400226AULL) << 32) | 0x14002267ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE84ULL;
}

// FDE #2397 | PC: 0x08be88..0x08be8c (4 B) | Symbol: sub_08be88
// EN: AArch64 prologue [b #0x94830] | VI: Khởi đầu hàm AArch64 [b #0x94830]
uint64_t fde_sub_08be88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0x1400226AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE88ULL;
}

// FDE #2398 | PC: 0x08be8c..0x08bee4 (88 B) | Symbol: sub_08be8c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; cbz x1, #0x8bec0; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; cbz x1, #0x8bec0; ldr x8, [x1]]
uint64_t fde_sub_08be8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE8CULL;
}

// FDE #2399 | PC: 0x08bee4..0x08bf48 (100 B) | Symbol: sub_08bee4
// EN: AArch64 prologue [sub sp, sp, #0x40; str d10, [sp, #0x10]; stp d9, d8, [sp, #0x18]; str x20, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str d10, [sp, #0x10]; stp d9, d8, [sp, #0x18]; str x20, [sp, #0x28]]
uint64_t fde_sub_08bee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BEAULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BEE4ULL;
}

// FDE #2400 | PC: 0x08bf48..0x08bfa0 (88 B) | Symbol: sub_08bf48
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; cbz x1, #0x8bf7c; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; cbz x1, #0x8bf7c; ldr x8, [x1]]
uint64_t fde_sub_08bf48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BF48ULL;
}

// FDE #2401 | PC: 0x08bfa0..0x08bfd8 (56 B) | Symbol: sub_08bfa0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldp x8, x9, [x1]; cbz x9, #0x8bfb8; add x10, x9, #8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldp x8, x9, [x1]; cbz x9, #0x8bfb8; add x10, x9, #8]
uint64_t fde_sub_08bfa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9402428ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BFA0ULL;
}

// FDE #2402 | PC: 0x08bfd8..0x08bfdc (4 B) | Symbol: sub_08bfd8
// EN: AArch64 prologue [b #0x94840] | VI: Khởi đầu hàm AArch64 [b #0x94840]
uint64_t fde_sub_08bfd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA940A408ULL) << 32) | 0x1400221AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BFD8ULL;
}

// FDE #2403 | PC: 0x08bfdc..0x08c004 (40 B) | Symbol: sub_08bfdc
// EN: AArch64 prologue [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x8bff4; sub x9, x9, #0x10] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x8bff4; sub x9, x9, #0x10]
uint64_t fde_sub_08bfdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA940A408ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BFDCULL;
}

// FDE #2404 | PC: 0x08c004..0x08c038 (52 B) | Symbol: sub_08c004
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x19, [x0, #8]; adrp x8, #0x9d000; add x8, x8, #0x8a8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x19, [x0, #8]; adrp x8, #0x9d000; add x8, x8, #0x8a8]
uint64_t fde_sub_08c004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400413ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C004ULL;
}

// FDE #2405 | PC: 0x08c038..0x08c050 (24 B) | Symbol: sub_08c038
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8c004; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8c004; mov x0, x19]
uint64_t fde_sub_08c038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C038ULL;
}

// FDE #2406 | PC: 0x08c050..0x08c058 (8 B) | Symbol: sub_08c050
// EN: AArch64 prologue [mov w0, #9; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #9; ret]
uint64_t fde_sub_08c050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800120ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C050ULL;
}

// FDE #2407 | PC: 0x08c058..0x08c06c (20 B) | Symbol: sub_08c058
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldp x9, x8, [x8, #0x28]; cmp x8, x9; cset w0, eq] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldp x9, x8, [x8, #0x28]; cmp x8, x9; cset w0, eq]
uint64_t fde_sub_08c058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA942A109ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C058ULL;
}

// FDE #2408 | PC: 0x08c06c..0x08c16c (256 B) | Symbol: sub_08c06c
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_08c06c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C06CULL;
}

// FDE #2409 | PC: 0x08c16c..0x08c19c (48 B) | Symbol: sub_08c16c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; lsr x8, x1, #0x3e; cbnz x8, #0x8c198] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; lsr x8, x1, #0x3e; cbnz x8, #0x8c198]
uint64_t fde_sub_08c16c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C16CULL;
}

// FDE #2410 | PC: 0x08c19c..0x08c1c8 (44 B) | Symbol: sub_08c19c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; lsr x8, x1, #0x3c; cbnz x8, #0x8c1c4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; lsr x8, x1, #0x3c; cbnz x8, #0x8c1c4]
uint64_t fde_sub_08c19c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C19CULL;
}

// FDE #2411 | PC: 0x08c1c8..0x08c1f8 (48 B) | Symbol: sub_08c1c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; cbz x0, #0x8c1dc; str x0, [x19, #0x48]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; cbz x0, #0x8c1dc; str x0, [x19, #0x48]]
uint64_t fde_sub_08c1c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940012BAULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C1C8ULL;
}

// FDE #2412 | PC: 0x08c1f8..0x08c238 (64 B) | Symbol: sub_08c1f8
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #8]]
uint64_t fde_sub_08c1f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C1F8ULL;
}

// FDE #2413 | PC: 0x08c238..0x08c23c (4 B) | Symbol: sub_08c238
// EN: AArch64 prologue [b #0x94860] | VI: Khởi đầu hàm AArch64 [b #0x94860]
uint64_t fde_sub_08c238(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400218DULL) << 32) | 0x1400218AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C238ULL;
}

// FDE #2414 | PC: 0x08c23c..0x08c240 (4 B) | Symbol: sub_08c23c
// EN: AArch64 prologue [b #0x94870] | VI: Khởi đầu hàm AArch64 [b #0x94870]
uint64_t fde_sub_08c23c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002190ULL) << 32) | 0x1400218DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C23CULL;
}

// FDE #2415 | PC: 0x08c240..0x08c244 (4 B) | Symbol: sub_08c240
// EN: AArch64 prologue [b #0x94880] | VI: Khởi đầu hàm AArch64 [b #0x94880]
uint64_t fde_sub_08c240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001D97ULL) << 32) | 0x14002190ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C240ULL;
}

// FDE #2416 | PC: 0x08c244..0x08c248 (4 B) | Symbol: sub_08c244
// EN: AArch64 prologue [b #0x938a0] | VI: Khởi đầu hàm AArch64 [b #0x938a0]
uint64_t fde_sub_08c244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE53F5ULL) << 32) | 0x14001D97ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C244ULL;
}

// FDE #2417 | PC: 0x08c248..0x08c2b4 (108 B) | Symbol: sub_08c248
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x0, #8]; mov x19, x2] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x0, #8]; mov x19, x2]
uint64_t fde_sub_08c248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C248ULL;
}

// FDE #2418 | PC: 0x08c2b4..0x08c2bc (8 B) | Symbol: sub_08c2b4
// EN: AArch64 prologue [mov w2, wzr; b #0x94850] | VI: Khởi đầu hàm AArch64 [mov w2, wzr; b #0x94850]
uint64_t fde_sub_08c2b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002166ULL) << 32) | 0x2A1F03E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C2B4ULL;
}

// FDE #2419 | PC: 0x08c2bc..0x08c2dc (32 B) | Symbol: sub_08c2bc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x948a0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x948a0]
uint64_t fde_sub_08c2bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C2BCULL;
}

// FDE #2420 | PC: 0x08c2dc..0x08c324 (72 B) | Symbol: sub_08c2dc
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]; bl #0x8eba4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]; bl #0x8eba4]
uint64_t fde_sub_08c2dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043F4ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C2DCULL;
}

// FDE #2421 | PC: 0x08c324..0x08c568 (580 B) | Symbol: sub_08c324
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_08c324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x0244ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C324ULL;
}

// FDE #2422 | PC: 0x08c568..0x08c590 (40 B) | Symbol: sub_08c568
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x2; subs x2, x1, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x2; subs x2, x1, x0]
uint64_t fde_sub_08c568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C568ULL;
}

// FDE #2423 | PC: 0x08c590..0x08c614 (132 B) | Symbol: sub_08c590
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x20, [sp, #0xc0]; stp x19, x30, [sp, #0xd0]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x20, [sp, #0xc0]; stp x19, x30, [sp, #0xd0]; bl #0x8dab0]
uint64_t fde_sub_08c590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90063F4ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C590ULL;
}

// FDE #2424 | PC: 0x08c614..0x08c678 (100 B) | Symbol: sub_08c614
// EN: AArch64 prologue [sub sp, sp, #0x40; str d8, [sp, #0x20]; str x20, [sp, #0x28]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str d8, [sp, #0x20]; str x20, [sp, #0x28]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_08c614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C614ULL;
}

// FDE #2425 | PC: 0x08c678..0x08c67c (4 B) | Symbol: sub_08c678
// EN: AArch64 prologue [b #0x948d0] | VI: Khởi đầu hàm AArch64 [b #0x948d0]
uint64_t fde_sub_08c678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0x14002096ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C678ULL;
}

// FDE #2426 | PC: 0x08c67c..0x08c6cc (80 B) | Symbol: sub_08c67c
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x93148] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x93148]
uint64_t fde_sub_08c67c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C67CULL;
}

// FDE #2427 | PC: 0x08c6cc..0x08c6f0 (36 B) | Symbol: sub_08c6cc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8d7e8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8d7e8]
uint64_t fde_sub_08c6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C6CCULL;
}

// FDE #2428 | PC: 0x08c6f0..0x08c718 (40 B) | Symbol: sub_08c6f0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x8c710; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x8c710; mov x0, x19]
uint64_t fde_sub_08c6f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400063FULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C6F0ULL;
}

// FDE #2429 | PC: 0x08c718..0x08c720 (8 B) | Symbol: sub_08c718
// EN: AArch64 prologue [and w2, w2, #1; b #0x94910] | VI: Khởi đầu hàm AArch64 [and w2, w2, #1; b #0x94910]
uint64_t fde_sub_08c718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400207DULL) << 32) | 0x12000042ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C718ULL;
}

// FDE #2430 | PC: 0x08c720..0x08c724 (4 B) | Symbol: sub_08c720
// EN: AArch64 prologue [b #0x94920] | VI: Khởi đầu hàm AArch64 [b #0x94920]
uint64_t fde_sub_08c720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002083ULL) << 32) | 0x14002080ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C720ULL;
}

// FDE #2431 | PC: 0x08c724..0x08c728 (4 B) | Symbol: sub_08c724
// EN: AArch64 prologue [b #0x94930] | VI: Khởi đầu hàm AArch64 [b #0x94930]
uint64_t fde_sub_08c724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0x14002083ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C724ULL;
}

// FDE #2432 | PC: 0x08c728..0x08c794 (108 B) | Symbol: sub_08c728
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x91dd0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x91dd0]
uint64_t fde_sub_08c728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C728ULL;
}

// FDE #2433 | PC: 0x08c794..0x08c79c (8 B) | Symbol: sub_08c794
// EN: AArch64 prologue [and w2, w2, #1; b #0x94950] | VI: Khởi đầu hàm AArch64 [and w2, w2, #1; b #0x94950]
uint64_t fde_sub_08c794(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400206EULL) << 32) | 0x12000042ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C794ULL;
}

// FDE #2434 | PC: 0x08c79c..0x08c7d4 (56 B) | Symbol: sub_08c79c
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; mov x19, x0]
uint64_t fde_sub_08c79c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C79CULL;
}

// FDE #2435 | PC: 0x08c7d4..0x08c7fc (40 B) | Symbol: sub_08c7d4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0x10] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0x10]
uint64_t fde_sub_08c7d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C7D4ULL;
}

// FDE #2436 | PC: 0x08c7fc..0x08c80c (16 B) | Symbol: sub_08c7fc
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x8e0; str x8, [x0], #8; b #0x66798] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x8e0; str x8, [x0], #8; b #0x66798]
uint64_t fde_sub_08c7fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91238108ULL) << 32) | 0xB0000088ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C7FCULL;
}

// FDE #2437 | PC: 0x08c80c..0x08c824 (24 B) | Symbol: sub_08c80c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8c7fc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8c7fc; mov x0, x19]
uint64_t fde_sub_08c80c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C80CULL;
}

// FDE #2438 | PC: 0x08c824..0x08c82c (8 B) | Symbol: sub_08c824
// EN: AArch64 prologue [ldr x8, [x0, #8]; b #0x8f79c] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; b #0x8f79c]
uint64_t fde_sub_08c824(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000BDDULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C824ULL;
}

// FDE #2439 | PC: 0x08c82c..0x08c888 (92 B) | Symbol: sub_08c82c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_08c82c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C82CULL;
}

// FDE #2440 | PC: 0x08c888..0x08c8c4 (60 B) | Symbol: sub_08c888
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; adrp x8, #0x1b000; ldr s3, [x8, #0x4bc]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; adrp x8, #0x1b000; ldr s3, [x8, #0x4bc]]
uint64_t fde_sub_08c888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C888ULL;
}

// FDE #2441 | PC: 0x08c8c4..0x08c928 (100 B) | Symbol: sub_08c8c4
// EN: AArch64 prologue [sub sp, sp, #0x40; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_08c8c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D012BEBULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C8C4ULL;
}

// FDE #2442 | PC: 0x08c928..0x08c9e4 (188 B) | Symbol: sub_08c928
// EN: AArch64 prologue [sub sp, sp, #0x80; stp d11, d10, [sp, #0x30]; stp d9, d8, [sp, #0x40]; str x22, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp d11, d10, [sp, #0x30]; stp d9, d8, [sp, #0x40]; str x22, [sp, #0x50]]
uint64_t fde_sub_08c928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D032BEBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C928ULL;
}

// FDE #2443 | PC: 0x08c9e4..0x08ca34 (80 B) | Symbol: sub_08c9e4
// EN: AArch64 prologue [sub sp, sp, #0x70; str x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; bl #0x8eba4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; bl #0x8eba4]
uint64_t fde_sub_08c9e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF4ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C9E4ULL;
}

// FDE #2444 | PC: 0x08ca34..0x08ca40 (12 B) | Symbol: sub_08ca34
// EN: AArch64 prologue [add x0, x0, #8; mov x1, xzr; b #0x4c700] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; mov x1, xzr; b #0x4c700]
uint64_t fde_sub_08ca34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E1ULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CA34ULL;
}

// FDE #2445 | PC: 0x08ca40..0x08cbcc (396 B) | Symbol: sub_08ca40
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x28, [sp, #0x50]; stp x27, x26, [sp, #0x60]; stp x25, x24, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x28, [sp, #0x50]; stp x27, x26, [sp, #0x60]; stp x25, x24, [sp, #0x70]]
uint64_t fde_sub_08ca40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CA40ULL;
}

// FDE #2446 | PC: 0x08cbcc..0x08cc00 (52 B) | Symbol: sub_08cbcc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0x10] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0x10]
uint64_t fde_sub_08cbcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CBCCULL;
}

// FDE #2447 | PC: 0x08cc00..0x08cc84 (132 B) | Symbol: sub_08cc00
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_08cc00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CC00ULL;
}

// FDE #2448 | PC: 0x08cc84..0x08cd88 (260 B) | Symbol: sub_08cc84
// EN: AArch64 prologue [sub sp, sp, #0xa0; str d8, [sp, #0x40]; str x28, [sp, #0x48]; stp x27, x26, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str d8, [sp, #0x40]; str x28, [sp, #0x48]; stp x27, x26, [sp, #0x50]]
uint64_t fde_sub_08cc84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0023E8ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CC84ULL;
}

// FDE #2449 | PC: 0x08cd88..0x08cec4 (316 B) | Symbol: sub_08cd88
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp d9, d8, [sp, #0x50]; str x28, [sp, #0x60]; stp x27, x26, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp d9, d8, [sp, #0x50]; str x28, [sp, #0x60]; stp x27, x26, [sp, #0x70]]
uint64_t fde_sub_08cd88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0523E9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CD88ULL;
}

// FDE #2450 | PC: 0x08cec4..0x08ced0 (12 B) | Symbol: sub_08cec4
// EN: AArch64 prologue [ldp s0, s1, [x0]; ldp s2, s3, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldp s0, s1, [x0]; ldp s2, s3, [x0, #8]; ret]
uint64_t fde_sub_08cec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2D410C02ULL) << 32) | 0x2D400400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CEC4ULL;
}

// FDE #2451 | PC: 0x08ced0..0x08d04c (380 B) | Symbol: sub_08ced0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_08ced0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CED0ULL;
}

// FDE #2452 | PC: 0x08d04c..0x08d05c (16 B) | Symbol: sub_08d04c
// EN: AArch64 prologue [ldr x0, [x0, #8]; cbz x0, #0x8d058; b #0x4483c; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; cbz x0, #0x8d058; b #0x4483c; ret]
uint64_t fde_sub_08d04c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D04CULL;
}

// FDE #2453 | PC: 0x08d05c..0x08d090 (52 B) | Symbol: sub_08d05c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x918; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x918; mov x19, x0]
uint64_t fde_sub_08d05c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000088ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D05CULL;
}

// FDE #2454 | PC: 0x08d090..0x08d0a8 (24 B) | Symbol: sub_08d090
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8d05c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8d05c; mov x0, x19]
uint64_t fde_sub_08d090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D090ULL;
}

// FDE #2455 | PC: 0x08d0a8..0x08d134 (140 B) | Symbol: sub_08d0a8
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8ee48] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8ee48]
uint64_t fde_sub_08d0a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D0A8ULL;
}

// FDE #2456 | PC: 0x08d134..0x08d168 (52 B) | Symbol: sub_08d134
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; cbz x0, #0x8d160; ldr x8, [x19, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; cbz x0, #0x8d160; ldr x8, [x19, #0x18]]
uint64_t fde_sub_08d134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000330ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D134ULL;
}

// FDE #2457 | PC: 0x08d168..0x08d194 (44 B) | Symbol: sub_08d168
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; cbz x0, #0x8d18c; str xzr, [x19, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; cbz x0, #0x8d18c; str xzr, [x19, #0x18]]
uint64_t fde_sub_08d168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000737ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D168ULL;
}

// FDE #2458 | PC: 0x08d194..0x08d1bc (40 B) | Symbol: sub_08d194
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x8d1b4; add x0, x19, #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x8d1b4; add x0, x19, #0x10]
uint64_t fde_sub_08d194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940002CCULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D194ULL;
}

// FDE #2459 | PC: 0x08d1bc..0x08d1c4 (8 B) | Symbol: sub_08d1bc
// EN: AArch64 prologue [mov x1, xzr; b #0x8d194] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x8d194]
uint64_t fde_sub_08d1bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF5ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D1BCULL;
}

// FDE #2460 | PC: 0x08d1c4..0x08d1f0 (44 B) | Symbol: sub_08d1c4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x958; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x958; bl #0x8daa4]
uint64_t fde_sub_08d1c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000088ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D1C4ULL;
}

// FDE #2461 | PC: 0x08d1f0..0x08d208 (24 B) | Symbol: sub_08d1f0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8d1c4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8d1c4; mov x0, x19]
uint64_t fde_sub_08d1f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D1F0ULL;
}

// FDE #2462 | PC: 0x08d208..0x08d228 (32 B) | Symbol: sub_08d208
// EN: AArch64 prologue [ldr x8, [x0, #8]; mov w1, wzr; ldr x8, [x8]; ldr w9, [x8, #0x2c]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; mov w1, wzr; ldr x8, [x8]; ldr w9, [x8, #0x2c]]
uint64_t fde_sub_08d208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D208ULL;
}

// FDE #2463 | PC: 0x08d228..0x08d398 (368 B) | Symbol: sub_08d228
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x25, x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x25, x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]]
uint64_t fde_sub_08d228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90663F9ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D228ULL;
}

// FDE #2464 | PC: 0x08d398..0x08d3c4 (44 B) | Symbol: sub_08d398
// EN: AArch64 prologue [fmov d1, #10.00000000; fmov d0, #1.00000000; cmp w0, #1; b.lt #0x8d3c0] | VI: Khởi đầu hàm AArch64 [fmov d1, #10.00000000; fmov d0, #1.00000000; cmp w0, #1; b.lt #0x8d3c0]
uint64_t fde_sub_08d398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E6E1000ULL) << 32) | 0x1E649001ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D398ULL;
}

// FDE #2465 | PC: 0x08d3c4..0x08d3d0 (12 B) | Symbol: sub_08d3c4
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #8]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #8]; br x8]
uint64_t fde_sub_08d3c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400508ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D3C4ULL;
}

// FDE #2466 | PC: 0x08d3d0..0x08d3d8 (8 B) | Symbol: sub_08d3d0
// EN: AArch64 prologue [ldr x8, [x8, #8]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #8]; br x8]
uint64_t fde_sub_08d3d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9400508ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D3D0ULL;
}

// FDE #2467 | PC: 0x08d3d8..0x08d3e8 (16 B) | Symbol: sub_08d3d8
// EN: AArch64 prologue [ldxr x9, [x8]; add x9, x9, #1; stxr w10, x9, [x8]; ret] | VI: Khởi đầu hàm AArch64 [ldxr x9, [x8]; add x9, x9, #1; stxr w10, x9, [x8]; ret]
uint64_t fde_sub_08d3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91000529ULL) << 32) | 0xC85F7D09ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D3D8ULL;
}

// FDE #2468 | PC: 0x08d3e8..0x08d448 (96 B) | Symbol: sub_08d3e8
// EN: AArch64 prologue [stp x3, x4, [sp, #0x88]; stp x5, x6, [sp, #0x98]; str x7, [sp, #0xa8]; stp q0, q1, [sp]] | VI: Khởi đầu hàm AArch64 [stp x3, x4, [sp, #0x88]; stp x5, x6, [sp, #0x98]; str x7, [sp, #0xa8]; stp q0, q1, [sp]]
uint64_t fde_sub_08d3e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9099BE5ULL) << 32) | 0xA90893E3ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D3E8ULL;
}

// FDE #2469 | PC: 0x08d448..0x08d454 (12 B) | Symbol: sub_08d448
// EN: AArch64 prologue [ldr x8, [x0]; ldr x1, [x8, #8]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x1, [x8, #8]; br x1]
uint64_t fde_sub_08d448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400501ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D448ULL;
}

// FDE #2470 | PC: 0x08d454..0x08d460 (12 B) | Symbol: sub_08d454
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #0x28]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #0x28]; br x8]
uint64_t fde_sub_08d454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401508ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D454ULL;
}

// FDE #2471 | PC: 0x08d460..0x08d46c (12 B) | Symbol: sub_08d460
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #0x30]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #0x30]; br x8]
uint64_t fde_sub_08d460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401908ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D460ULL;
}

// FDE #2472 | PC: 0x08d46c..0x08d480 (20 B) | Symbol: sub_08d46c
// EN: AArch64 prologue [ldr x8, [x19]; ldr x1, [sp, #8]; mov x0, x19; ldr x8, [x8, #0xa8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; ldr x1, [sp, #8]; mov x0, x19; ldr x8, [x8, #0xa8]]
uint64_t fde_sub_08d46c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D46CULL;
}

// FDE #2473 | PC: 0x08d480..0x08d498 (24 B) | Symbol: sub_08d480
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x40]; ldp x22, x21, [sp, #0x30]; ldp x24, x23, [sp, #0x20]; ldp x26, x25, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x40]; ldp x22, x21, [sp, #0x30]; ldp x24, x23, [sp, #0x20]; ldp x26, x25, [sp, #0x10]]
uint64_t fde_sub_08d480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94357F6ULL) << 32) | 0xA9444FF4ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D480ULL;
}

// FDE #2474 | PC: 0x08d498..0x08d4a0 (8 B) | Symbol: sub_08d498
// EN: AArch64 prologue [ldr x8, [x8, #0x30]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x30]; br x8]
uint64_t fde_sub_08d498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9401908ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D498ULL;
}

// FDE #2475 | PC: 0x08d4a0..0x08d4a8 (8 B) | Symbol: sub_08d4a0
// EN: AArch64 prologue [ldr x20, [sp], #0x20; ret] | VI: Khởi đầu hàm AArch64 [ldr x20, [sp], #0x20; ret]
uint64_t fde_sub_08d4a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF84207F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D4A0ULL;
}

// FDE #2476 | PC: 0x08d4a8..0x08d4b4 (12 B) | Symbol: sub_08d4a8
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x10]; ldr x22, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x10]; ldr x22, [sp], #0x30; ret]
uint64_t fde_sub_08d4a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84307F6ULL) << 32) | 0xA94153F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D4A8ULL;
}

// FDE #2477 | PC: 0x08d4b4..0x08d4f0 (60 B) | Symbol: sub_08d4b4
// EN: AArch64 prologue [ldr x8, [x19, #8]; ldr x9, [x20]; str x8, [x20]; ldr x8, [x19, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #8]; ldr x9, [x20]; str x8, [x20]; ldr x8, [x19, #0x10]]
uint64_t fde_sub_08d4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400289ULL) << 32) | 0xF9400668ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D4B4ULL;
}

// FDE #2478 | PC: 0x08d4f0..0x08d510 (32 B) | Symbol: sub_08d4f0
// EN: AArch64 prologue [str x8, [x0]; stur q0, [x0, #8]; str x0, [sp, #8]; ldr x8, [x20]] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; stur q0, [x0, #8]; str x0, [sp, #8]; ldr x8, [x20]]
uint64_t fde_sub_08d4f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3C808000ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D4F0ULL;
}

// FDE #2479 | PC: 0x08d510..0x08d518 (8 B) | Symbol: sub_08d510
// EN: AArch64 prologue [ldr x8, [x8]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8]; br x8]
uint64_t fde_sub_08d510(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9400108ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D510ULL;
}

// FDE #2480 | PC: 0x08d518..0x08d524 (12 B) | Symbol: sub_08d518
// EN: AArch64 prologue [str x9, [x0]; mov x0, x8; b #0x44830] | VI: Khởi đầu hàm AArch64 [str x9, [x0]; mov x0, x8; b #0x44830]
uint64_t fde_sub_08d518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xF9000009ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D518ULL;
}

// FDE #2481 | PC: 0x08d524..0x08d530 (12 B) | Symbol: sub_08d524
// EN: AArch64 prologue [ldr x9, [sp, #0x18]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x18]; cmp x8, x9; ret]
uint64_t fde_sub_08d524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9400FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D524ULL;
}

// FDE #2482 | PC: 0x08d530..0x08d548 (24 B) | Symbol: sub_08d530
// EN: AArch64 prologue [ldp x8, x9, [x1]; stp xzr, xzr, [x1]; mov x19, x0; ldr x0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x1]; stp xzr, xzr, [x1]; mov x19, x0; ldr x0, [x0, #8]]
uint64_t fde_sub_08d530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007C3FULL) << 32) | 0xA9402428ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D530ULL;
}

// FDE #2483 | PC: 0x08d548..0x08d560 (24 B) | Symbol: sub_08d548
// EN: AArch64 prologue [sub x8, x0, #1; clz x8, x8; neg w8, w8; mov w9, #1] | VI: Khởi đầu hàm AArch64 [sub x8, x0, #1; clz x8, x8; neg w8, w8; mov w9, #1]
uint64_t fde_sub_08d548(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xDAC01108ULL) << 32) | 0xD1000408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D548ULL;
}

// FDE #2484 | PC: 0x08d560..0x08d568 (8 B) | Symbol: sub_08d560
// EN: AArch64 prologue [ldp x21, x20, [sp], #0x20; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp], #0x20; ret]
uint64_t fde_sub_08d560(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xA8C253F5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D560ULL;
}

// FDE #2485 | PC: 0x08d568..0x08d574 (12 B) | Symbol: sub_08d568
// EN: AArch64 prologue [mov x8, sp; mov x0, x19; b #0x932a0] | VI: Khởi đầu hàm AArch64 [mov x8, sp; mov x0, x19; b #0x932a0]
uint64_t fde_sub_08d568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910003E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D568ULL;
}

// FDE #2486 | PC: 0x08d574..0x08d57c (8 B) | Symbol: sub_08d574
// EN: AArch64 prologue [add x0, sp, #8; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x937a0]
uint64_t fde_sub_08d574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400188AULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D574ULL;
}

// FDE #2487 | PC: 0x08d57c..0x08d584 (8 B) | Symbol: sub_08d57c
// EN: AArch64 prologue [add sp, sp, #0x60; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x60; ret]
uint64_t fde_sub_08d57c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910183FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D57CULL;
}

// FDE #2488 | PC: 0x08d584..0x08d58c (8 B) | Symbol: sub_08d584
// EN: AArch64 prologue [ldr x8, [x8, #0x10]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x10]; br x8]
uint64_t fde_sub_08d584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9400908ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D584ULL;
}

// FDE #2489 | PC: 0x08d58c..0x08d594 (8 B) | Symbol: sub_08d58c
// EN: AArch64 prologue [mov x19, x0; b #0x93310] | VI: Khởi đầu hàm AArch64 [mov x19, x0; b #0x93310]
uint64_t fde_sub_08d58c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001760ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D58CULL;
}

// FDE #2490 | PC: 0x08d594..0x08d5b8 (36 B) | Symbol: sub_08d594
// EN: AArch64 prologue [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w9, s0; ucvtf s0, x8] | VI: Khởi đầu hàm AArch64 [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w9, s0; ucvtf s0, x8]
uint64_t fde_sub_08d594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2E303800ULL) << 32) | 0x0E205800ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D594ULL;
}

// FDE #2491 | PC: 0x08d5b8..0x08d5c4 (12 B) | Symbol: sub_08d5b8
// EN: AArch64 prologue [adrp x0, #0xa0000; add x0, x0, #0x30; b #0x940b0] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xa0000; add x0, x0, #0x30; b #0x940b0]
uint64_t fde_sub_08d5b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C000ULL) << 32) | 0xF0000080ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D5B8ULL;
}

// FDE #2492 | PC: 0x08d5c4..0x08d5e8 (36 B) | Symbol: sub_08d5c4
// EN: AArch64 prologue [str x29, [x22]; ldr x8, [x19]; ldr x8, [x8, x27, lsl #3]; ldr x8, [x8]] | VI: Khởi đầu hàm AArch64 [str x29, [x22]; ldr x8, [x19]; ldr x8, [x8, x27, lsl #3]; ldr x8, [x8]]
uint64_t fde_sub_08d5c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400268ULL) << 32) | 0xF90002DDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D5C4ULL;
}

// FDE #2493 | PC: 0x08d5e8..0x08d600 (24 B) | Symbol: sub_08d5e8
// EN: AArch64 prologue [ldr x24, [x22, #8]; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w23, s0] | VI: Khởi đầu hàm AArch64 [ldr x24, [x22, #8]; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w23, s0]
uint64_t fde_sub_08d5e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0E205800ULL) << 32) | 0xF94006D8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D5E8ULL;
}

// FDE #2494 | PC: 0x08d600..0x08d60c (12 B) | Symbol: sub_08d600
// EN: AArch64 prologue [ldr x9, [sp, #0x128]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x128]; cmp x8, x9; ret]
uint64_t fde_sub_08d600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94097E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D600ULL;
}

// FDE #2495 | PC: 0x08d60c..0x08d614 (8 B) | Symbol: sub_08d60c
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_08d60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D60CULL;
}

// FDE #2496 | PC: 0x08d614..0x08d628 (20 B) | Symbol: sub_08d614
// EN: AArch64 prologue [ldp x8, x9, [x0, #8]; mov x19, x0; mov x20, x1; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #8]; mov x19, x0; mov x20, x1; cmp x8, x9]
uint64_t fde_sub_08d614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA940A408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D614ULL;
}

// FDE #2497 | PC: 0x08d628..0x08d63c (20 B) | Symbol: sub_08d628
// EN: AArch64 prologue [ldr x8, [x21]; ldr x9, [x8]; ldr x10, [x8, #0x10]; cmp x9, x10] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21]; ldr x9, [x8]; ldr x10, [x8, #0x10]; cmp x9, x10]
uint64_t fde_sub_08d628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400109ULL) << 32) | 0xF94002A8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D628ULL;
}

// FDE #2498 | PC: 0x08d63c..0x08d654 (24 B) | Symbol: sub_08d63c
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_08d63c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D63CULL;
}

// FDE #2499 | PC: 0x08d654..0x08d668 (20 B) | Symbol: sub_08d654
// EN: AArch64 prologue [ldr x8, [x0, #8]; add x1, x0, #0x18; ldr x8, [x8, #0x10]; mov x0, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; add x1, x0, #0x18; ldr x8, [x8, #0x10]; mov x0, x8]
uint64_t fde_sub_08d654(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D654ULL;
}

// FDE #2500 | PC: 0x08d668..0x08d678 (16 B) | Symbol: sub_08d668
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x140]; ldr x28, [sp, #0x130]; add sp, sp, #0x160; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x140]; ldr x28, [sp, #0x130]; add sp, sp, #0x160; ret]
uint64_t fde_sub_08d668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9409BFCULL) << 32) | 0xA95453F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D668ULL;
}

// FDE #2501 | PC: 0x08d678..0x08d680 (8 B) | Symbol: sub_08d678
// EN: AArch64 prologue [mov x1, x19; b #0x470b8] | VI: Khởi đầu hàm AArch64 [mov x1, x19; b #0x470b8]
uint64_t fde_sub_08d678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE68FULL) << 32) | 0xAA1303E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D678ULL;
}

// FDE #2502 | PC: 0x08d680..0x08d690 (16 B) | Symbol: sub_08d680
// EN: AArch64 prologue [ldr x8, [x0]; mov v0.16b, v8.16b; ldr x8, [x8, #0x18]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov v0.16b, v8.16b; ldr x8, [x8, #0x18]; br x8]
uint64_t fde_sub_08d680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA81D00ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D680ULL;
}

// FDE #2503 | PC: 0x08d690..0x08d698 (8 B) | Symbol: sub_08d690
// EN: AArch64 prologue [add sp, sp, #0x70; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x70; ret]
uint64_t fde_sub_08d690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9101C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D690ULL;
}

// FDE #2504 | PC: 0x08d698..0x08d6a0 (8 B) | Symbol: sub_08d698
// EN: AArch64 prologue [ldr x8, [x8, #0x18]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x18]; br x8]
uint64_t fde_sub_08d698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9400D08ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D698ULL;
}

// FDE #2505 | PC: 0x08d6a0..0x08d6a8 (8 B) | Symbol: sub_08d6a0
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_08d6a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6A0ULL;
}

// FDE #2506 | PC: 0x08d6a8..0x08d6b0 (8 B) | Symbol: sub_08d6a8
// EN: AArch64 prologue [mov x0, xzr; b #0x44830] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; b #0x44830]
uint64_t fde_sub_08d6a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDC61ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6A8ULL;
}

// FDE #2507 | PC: 0x08d6b0..0x08d6c0 (16 B) | Symbol: sub_08d6b0
// EN: AArch64 prologue [ldr x20, [x19, #0x18]; add x0, sp, #0x10; mov x1, x19; b #0x4b758] | VI: Khởi đầu hàm AArch64 [ldr x20, [x19, #0x18]; add x0, sp, #0x10; mov x1, x19; b #0x4b758]
uint64_t fde_sub_08d6b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043E0ULL) << 32) | 0xF9400E74ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6B0ULL;
}

// FDE #2508 | PC: 0x08d6c0..0x08d6cc (12 B) | Symbol: sub_08d6c0
// EN: AArch64 prologue [ldr x9, [sp, #0x28]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x28]; cmp x8, x9; ret]
uint64_t fde_sub_08d6c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94017E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6C0ULL;
}

// FDE #2509 | PC: 0x08d6cc..0x08d6d4 (8 B) | Symbol: sub_08d6cc
// EN: AArch64 prologue [mov w0, #0x10; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x10; b #0x93320]
uint64_t fde_sub_08d6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001714ULL) << 32) | 0x52800200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6CCULL;
}

// FDE #2510 | PC: 0x08d6d4..0x08d6dc (8 B) | Symbol: sub_08d6d4
// EN: AArch64 prologue [add sp, sp, #0x40; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x40; ret]
uint64_t fde_sub_08d6d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910103FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6D4ULL;
}

// FDE #2511 | PC: 0x08d6dc..0x08d6ec (16 B) | Symbol: sub_08d6dc
// EN: AArch64 prologue [lsr x10, x8, #1; tst w8, #1; csel x8, x10, x9, eq; ret] | VI: Khởi đầu hàm AArch64 [lsr x10, x8, #1; tst w8, #1; csel x8, x10, x9, eq; ret]
uint64_t fde_sub_08d6dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7200011FULL) << 32) | 0xD341FD0AULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6DCULL;
}

// FDE #2512 | PC: 0x08d6ec..0x08d720 (52 B) | Symbol: sub_08d6ec
// EN: AArch64 prologue [cmp x23, #3; sub x8, x23, #1; cset w9, lo; tst x23, x8] | VI: Khởi đầu hàm AArch64 [cmp x23, #3; sub x8, x23, #1; cset w9, lo; tst x23, x8]
uint64_t fde_sub_08d6ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10006E8ULL) << 32) | 0xF1000EFFULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6ECULL;
}

// FDE #2513 | PC: 0x08d720..0x08d728 (8 B) | Symbol: sub_08d720
// EN: AArch64 prologue [mov x0, x20; b #0x93cc0] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x93cc0]
uint64_t fde_sub_08d720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001967ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D720ULL;
}

// FDE #2514 | PC: 0x08d728..0x08d738 (16 B) | Symbol: sub_08d728
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x20, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x20, x0; ret]
uint64_t fde_sub_08d728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D728ULL;
}

// FDE #2515 | PC: 0x08d738..0x08d748 (16 B) | Symbol: sub_08d738
// EN: AArch64 prologue [ldxr x11, [x10]; add x11, x11, #1; stxr w12, x11, [x10]; ret] | VI: Khởi đầu hàm AArch64 [ldxr x11, [x10]; add x11, x11, #1; stxr w12, x11, [x10]; ret]
uint64_t fde_sub_08d738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100056BULL) << 32) | 0xC85F7D4BULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D738ULL;
}

// FDE #2516 | PC: 0x08d748..0x08d754 (12 B) | Symbol: sub_08d748
// EN: AArch64 prologue [ldr x9, [sp, #0x38]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x38]; cmp x8, x9; ret]
uint64_t fde_sub_08d748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9401FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D748ULL;
}

// FDE #2517 | PC: 0x08d754..0x08d76c (24 B) | Symbol: sub_08d754
// EN: AArch64 prologue [stp x8, x21, [x0]; str x9, [x0, #0x10]; str x0, [sp, #0x10]; add x1, sp, #0x10] | VI: Khởi đầu hàm AArch64 [stp x8, x21, [x0]; str x9, [x0, #0x10]; str x0, [sp, #0x10]; add x1, sp, #0x10]
uint64_t fde_sub_08d754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000809ULL) << 32) | 0xA9005408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D754ULL;
}

// FDE #2518 | PC: 0x08d76c..0x08d77c (16 B) | Symbol: sub_08d76c
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x30]; ldr x22, [sp, #0x20]; add sp, sp, #0x50; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x30]; ldr x22, [sp, #0x20]; add sp, sp, #0x50; ret]
uint64_t fde_sub_08d76c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013F6ULL) << 32) | 0xA94353F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D76CULL;
}

// FDE #2519 | PC: 0x08d77c..0x08d79c (32 B) | Symbol: sub_08d77c
// EN: AArch64 prologue [ldr x10, [x20]; add x8, x0, x21, lsl #3; mov x9, x8; str xzr, [x20]] | VI: Khởi đầu hàm AArch64 [ldr x10, [x20]; add x8, x0, x21, lsl #3; mov x9, x8; str xzr, [x20]]
uint64_t fde_sub_08d77c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B150C08ULL) << 32) | 0xF940028AULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D77CULL;
}

// FDE #2520 | PC: 0x08d79c..0x08d7cc (48 B) | Symbol: sub_08d79c
// EN: AArch64 prologue [ldr x8, [x19, #0x18]; fmov d0, x23; ldr s1, [x19, #0x20]; cnt v0.8b, v0.8b] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x18]; fmov d0, x23; ldr s1, [x19, #0x20]; cnt v0.8b, v0.8b]
uint64_t fde_sub_08d79c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E6702E0ULL) << 32) | 0xF9400E68ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D79CULL;
}

// FDE #2521 | PC: 0x08d7cc..0x08d7d4 (8 B) | Symbol: sub_08d7cc
// EN: AArch64 prologue [add sp, sp, #0x170; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x170; ret]
uint64_t fde_sub_08d7cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9105C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D7CCULL;
}

// FDE #2522 | PC: 0x08d7d4..0x08d7e8 (20 B) | Symbol: sub_08d7d4
// EN: AArch64 prologue [add x1, x25, #0x18; add x0, sp, #0xf8; mov x2, x27; mov w3, wzr] | VI: Khởi đầu hàm AArch64 [add x1, x25, #0x18; add x0, sp, #0xf8; mov x2, x27; mov w3, wzr]
uint64_t fde_sub_08d7d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9103E3E0ULL) << 32) | 0x91006321ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D7D4ULL;
}

// FDE #2523 | PC: 0x08d7e8..0x08d7f0 (8 B) | Symbol: sub_08d7e8
// EN: AArch64 prologue [mov w0, #0x18; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x18; b #0x93320]
uint64_t fde_sub_08d7e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140016CDULL) << 32) | 0x52800300ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D7E8ULL;
}

// FDE #2524 | PC: 0x08d7f0..0x08d804 (20 B) | Symbol: sub_08d7f0
// EN: AArch64 prologue [ldr x8, [x19]; mov w1, #5; ldur x8, [x8, #-0x18]; add x0, x19, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; mov w1, #5; ldur x8, [x8, #-0x18]; add x0, x19, x8]
uint64_t fde_sub_08d7f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000A1ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D7F0ULL;
}

// FDE #2525 | PC: 0x08d804..0x08d828 (36 B) | Symbol: sub_08d804
// EN: AArch64 prologue [str x15, [x8]; ldr x15, [x19]; ldr x15, [x15, x13, lsl #3]; ldr x15, [x15]] | VI: Khởi đầu hàm AArch64 [str x15, [x8]; ldr x15, [x19]; ldr x15, [x15, x13, lsl #3]; ldr x15, [x15]]
uint64_t fde_sub_08d804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940026FULL) << 32) | 0xF900010FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D804ULL;
}

// FDE #2526 | PC: 0x08d828..0x08d860 (56 B) | Symbol: sub_08d828
// EN: AArch64 prologue [ldr x8, [x1]; str xzr, [x1]; str x8, [x0]; ldr x8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str xzr, [x1]; str x8, [x0]; ldr x8, [x1, #8]]
uint64_t fde_sub_08d828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900003FULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D828ULL;
}

// FDE #2527 | PC: 0x08d860..0x08d870 (16 B) | Symbol: sub_08d860
// EN: AArch64 prologue [ldxr x10, [x9]; add x10, x10, #1; stxr w11, x10, [x9]; ret] | VI: Khởi đầu hàm AArch64 [ldxr x10, [x9]; add x10, x10, #1; stxr w11, x10, [x9]; ret]
uint64_t fde_sub_08d860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100054AULL) << 32) | 0xC85F7D2AULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D860ULL;
}

// FDE #2528 | PC: 0x08d870..0x08d880 (16 B) | Symbol: sub_08d870
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldr x24, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldr x24, [sp], #0x40; ret]
uint64_t fde_sub_08d870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9415BF7ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D870ULL;
}

// FDE #2529 | PC: 0x08d880..0x08d888 (8 B) | Symbol: sub_08d880
// EN: AArch64 prologue [mov w0, #0x28; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x28; b #0x93320]
uint64_t fde_sub_08d880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140016A7ULL) << 32) | 0x52800500ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D880ULL;
}

// FDE #2530 | PC: 0x08d888..0x08d894 (12 B) | Symbol: sub_08d888
// EN: AArch64 prologue [ldr x9, [sp, #0x48]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x48]; cmp x8, x9; ret]
uint64_t fde_sub_08d888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94027E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D888ULL;
}

// FDE #2531 | PC: 0x08d894..0x08d89c (8 B) | Symbol: sub_08d894
// EN: AArch64 prologue [add sp, sp, #0x90; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x90; ret]
uint64_t fde_sub_08d894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910243FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D894ULL;
}

// FDE #2532 | PC: 0x08d89c..0x08d8a4 (8 B) | Symbol: sub_08d89c
// EN: AArch64 prologue [add sp, sp, #0x160; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x160; ret]
uint64_t fde_sub_08d89c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910583FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D89CULL;
}

// FDE #2533 | PC: 0x08d8a4..0x08d8ac (8 B) | Symbol: sub_08d8a4
// EN: AArch64 prologue [add sp, sp, #0x50; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x50; ret]
uint64_t fde_sub_08d8a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910143FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D8A4ULL;
}

// FDE #2534 | PC: 0x08d8ac..0x08d8c4 (24 B) | Symbol: sub_08d8ac
// EN: AArch64 prologue [ldr q0, [x1]; mov x19, x0; str q0, [sp]; stp xzr, xzr, [x1]] | VI: Khởi đầu hàm AArch64 [ldr q0, [x1]; mov x19, x0; str q0, [sp]; stp xzr, xzr, [x1]]
uint64_t fde_sub_08d8ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0x3DC00020ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D8ACULL;
}

// FDE #2535 | PC: 0x08d8c4..0x08d8d4 (16 B) | Symbol: sub_08d8c4
// EN: AArch64 prologue [ldr x9, [x8]; mov x0, x8; ldr x9, [x9, #0x30]; br x9] | VI: Khởi đầu hàm AArch64 [ldr x9, [x8]; mov x0, x8; ldr x9, [x9, #0x30]; br x9]
uint64_t fde_sub_08d8c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xF9400109ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D8C4ULL;
}

// FDE #2536 | PC: 0x08d8d4..0x08d8f0 (28 B) | Symbol: sub_08d8d4
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; adrp x1, #0x1c000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; adrp x1, #0x1c000; mov x19, x0]
uint64_t fde_sub_08d8d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D8D4ULL;
}

// FDE #2537 | PC: 0x08d8f0..0x08d8f8 (8 B) | Symbol: sub_08d8f0
// EN: AArch64 prologue [mov x0, x20; b #0x4722c] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x4722c]
uint64_t fde_sub_08d8f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE64EULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D8F0ULL;
}

// FDE #2538 | PC: 0x08d8f8..0x08d904 (12 B) | Symbol: sub_08d8f8
// EN: AArch64 prologue [mov x2, x21; mov w3, wzr; b #0x6ba4c] | VI: Khởi đầu hàm AArch64 [mov x2, x21; mov w3, wzr; b #0x6ba4c]
uint64_t fde_sub_08d8f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E3ULL) << 32) | 0xAA1503E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D8F8ULL;
}

// FDE #2539 | PC: 0x08d904..0x08d90c (8 B) | Symbol: sub_08d904
// EN: AArch64 prologue [mov x1, x19; b #0x4b758] | VI: Khởi đầu hàm AArch64 [mov x1, x19; b #0x4b758]
uint64_t fde_sub_08d904(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEF794ULL) << 32) | 0xAA1303E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D904ULL;
}

// FDE #2540 | PC: 0x08d90c..0x08d918 (12 B) | Symbol: sub_08d90c
// EN: AArch64 prologue [ldr x0, [sp, #8]; str xzr, [sp, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #8]; str xzr, [sp, #8]; ret]
uint64_t fde_sub_08d90c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FFULL) << 32) | 0xF94007E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D90CULL;
}

// FDE #2541 | PC: 0x08d918..0x08d924 (12 B) | Symbol: sub_08d918
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x40a; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x40a; b #0x4696c]
uint64_t fde_sub_08d918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91102821ULL) << 32) | 0xD0FFFC81ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D918ULL;
}

// FDE #2542 | PC: 0x08d924..0x08d93c (24 B) | Symbol: sub_08d924
// EN: AArch64 prologue [ldr x10, [x19]; sub x8, x8, x10; asr x21, x8, #3; add x8, x21, #1] | VI: Khởi đầu hàm AArch64 [ldr x10, [x19]; sub x8, x8, x10; asr x21, x8, #3; add x8, x21, #1]
uint64_t fde_sub_08d924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB0A0108ULL) << 32) | 0xF940026AULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D924ULL;
}

// FDE #2543 | PC: 0x08d93c..0x08d99c (96 B) | Symbol: sub_08d93c
// EN: AArch64 prologue [ldrb w8, [x2, #0xc]; ldrb w11, [x2, #0x14]; add x9, x2, #0x20; add x10, x2, #8] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x2, #0xc]; ldrb w11, [x2, #0x14]; add x9, x2, #0x20; add x10, x2, #8]
uint64_t fde_sub_08d93c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940504BULL) << 32) | 0x39403048ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D93CULL;
}

// FDE #2544 | PC: 0x08d99c..0x08d9a4 (8 B) | Symbol: sub_08d99c
// EN: AArch64 prologue [mov w3, wzr; b #0x6ba4c] | VI: Khởi đầu hàm AArch64 [mov w3, wzr; b #0x6ba4c]
uint64_t fde_sub_08d99c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF782BULL) << 32) | 0x2A1F03E3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D99CULL;
}

// FDE #2545 | PC: 0x08d9a4..0x08d9ac (8 B) | Symbol: sub_08d9a4
// EN: AArch64 prologue [add sp, sp, #0x30; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x30; ret]
uint64_t fde_sub_08d9a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9100C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9A4ULL;
}

// FDE #2546 | PC: 0x08d9ac..0x08d9bc (16 B) | Symbol: sub_08d9ac
// EN: AArch64 prologue [ldr x9, [x19]; str xzr, [x9, x8, lsl #3]; add x8, x8, #1; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [x19]; str xzr, [x9, x8, lsl #3]; add x8, x8, #1; ret]
uint64_t fde_sub_08d9ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF828793FULL) << 32) | 0xF9400269ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9ACULL;
}

// FDE #2547 | PC: 0x08d9bc..0x08d9d0 (20 B) | Symbol: sub_08d9bc
// EN: AArch64 prologue [ldr x9, [x20]; str xzr, [x20]; str x9, [x8], #8; str x8, [x19, #8]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x20]; str xzr, [x20]; str x9, [x8], #8; str x8, [x19, #8]]
uint64_t fde_sub_08d9bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900029FULL) << 32) | 0xF9400289ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9BCULL;
}

// FDE #2548 | PC: 0x08d9d0..0x08d9d8 (8 B) | Symbol: sub_08d9d0
// EN: AArch64 prologue [mov w0, #0x58; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x58; b #0x93320]
uint64_t fde_sub_08d9d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001653ULL) << 32) | 0x52800B00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9D0ULL;
}

// FDE #2549 | PC: 0x08d9d8..0x08d9e4 (12 B) | Symbol: sub_08d9d8
// EN: AArch64 prologue [ldr x9, [sp, #0x58]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x58]; cmp x8, x9; ret]
uint64_t fde_sub_08d9d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9402FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9D8ULL;
}

// FDE #2550 | PC: 0x08d9e4..0x08d9f0 (12 B) | Symbol: sub_08d9e4
// EN: AArch64 prologue [ldr x9, [sp, #8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #8]; cmp x8, x9; ret]
uint64_t fde_sub_08d9e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94007E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9E4ULL;
}

// FDE #2551 | PC: 0x08d9f0..0x08d9fc (12 B) | Symbol: sub_08d9f0
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #0x78]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #0x78]; br x8]
uint64_t fde_sub_08d9f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403D08ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9F0ULL;
}

// FDE #2552 | PC: 0x08d9fc..0x08da04 (8 B) | Symbol: sub_08d9fc
// EN: AArch64 prologue [mov x0, sp; b #0x46c54] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x46c54]
uint64_t fde_sub_08d9fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE495ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9FCULL;
}

// FDE #2553 | PC: 0x08da04..0x08da0c (8 B) | Symbol: sub_08da04
// EN: AArch64 prologue [mov x0, sp; b #0x7c7bc] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x7c7bc]
uint64_t fde_sub_08da04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFBB6DULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA04ULL;
}

// FDE #2554 | PC: 0x08da0c..0x08da1c (16 B) | Symbol: sub_08da0c
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; ret]
uint64_t fde_sub_08da0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA0CULL;
}

// FDE #2555 | PC: 0x08da1c..0x08da50 (52 B) | Symbol: sub_08da1c
// EN: AArch64 prologue [cmp x23, #3; sub x8, x23, #1; cset w9, lo; tst x23, x8] | VI: Khởi đầu hàm AArch64 [cmp x23, #3; sub x8, x23, #1; cset w9, lo; tst x23, x8]
uint64_t fde_sub_08da1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10006E8ULL) << 32) | 0xF1000EFFULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA1CULL;
}

// FDE #2556 | PC: 0x08da50..0x08da84 (52 B) | Symbol: sub_08da50
// EN: AArch64 prologue [cmp x23, #3; sub x8, x23, #1; cset w9, lo; tst x23, x8] | VI: Khởi đầu hàm AArch64 [cmp x23, #3; sub x8, x23, #1; cset w9, lo; tst x23, x8]
uint64_t fde_sub_08da50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10006E8ULL) << 32) | 0xF1000EFFULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA50ULL;
}

// FDE #2557 | PC: 0x08da84..0x08da8c (8 B) | Symbol: sub_08da84
// EN: AArch64 prologue [mov x1, x19; b #0x51254] | VI: Khởi đầu hàm AArch64 [mov x1, x19; b #0x51254]
uint64_t fde_sub_08da84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF0DF3ULL) << 32) | 0xAA1303E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA84ULL;
}

// FDE #2558 | PC: 0x08da8c..0x08da9c (16 B) | Symbol: sub_08da8c
// EN: AArch64 prologue [ldr x21, [x20, #0x18]; add x0, sp, #0x10; mov x1, x20; b #0x4b758] | VI: Khởi đầu hàm AArch64 [ldr x21, [x20, #0x18]; add x0, sp, #0x10; mov x1, x20; b #0x4b758]
uint64_t fde_sub_08da8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043E0ULL) << 32) | 0xF9400E95ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA8CULL;
}

// FDE #2559 | PC: 0x08da9c..0x08daa4 (8 B) | Symbol: sub_08da9c
// EN: AArch64 prologue [mov x0, x21; b #0x4696c] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x4696c]
uint64_t fde_sub_08da9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE3B3ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA9CULL;
}

// FDE #2560 | PC: 0x08daa4..0x08dab0 (12 B) | Symbol: sub_08daa4
// EN: AArch64 prologue [mov x19, x0; str x8, [x0], #0x18; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; str x8, [x0], #0x18; ret]
uint64_t fde_sub_08daa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8018408ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DAA4ULL;
}

// FDE #2561 | PC: 0x08dab0..0x08dabc (12 B) | Symbol: sub_08dab0
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; ret]
uint64_t fde_sub_08dab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DAB0ULL;
}

// FDE #2562 | PC: 0x08dabc..0x08dac8 (12 B) | Symbol: sub_08dabc
// EN: AArch64 prologue [mov x19, x2; mov x21, x8; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x21, x8; b #0x93320]
uint64_t fde_sub_08dabc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803F5ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DABCULL;
}

// FDE #2563 | PC: 0x08dac8..0x08dad4 (12 B) | Symbol: sub_08dac8
// EN: AArch64 prologue [ldr x9, [sp, #0x138]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x138]; cmp x8, x9; ret]
uint64_t fde_sub_08dac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9409FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DAC8ULL;
}

// FDE #2564 | PC: 0x08dad4..0x08dae8 (20 B) | Symbol: sub_08dad4
// EN: AArch64 prologue [adrp x1, #0x1c000; mov x19, x0; add x1, x1, #0xc99; add x0, sp, #0x10] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; mov x19, x0; add x1, x1, #0xc99; add x0, sp, #0x10]
uint64_t fde_sub_08dad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF0FFFC61ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DAD4ULL;
}

// FDE #2565 | PC: 0x08dae8..0x08daf0 (8 B) | Symbol: sub_08dae8
// EN: AArch64 prologue [ldp x21, x20, [sp], #0x20; b #0x932e0] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp], #0x20; b #0x932e0]
uint64_t fde_sub_08dae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140015FDULL) << 32) | 0xA8C253F5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DAE8ULL;
}

// FDE #2566 | PC: 0x08daf0..0x08db04 (20 B) | Symbol: sub_08daf0
// EN: AArch64 prologue [ldr x8, [x19]; ldur x8, [x8, #-0x18]; add x0, x19, x8; add x8, sp, #0x10] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; ldur x8, [x8, #-0x18]; add x0, x19, x8; add x8, sp, #0x10]
uint64_t fde_sub_08daf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DAF0ULL;
}

// FDE #2567 | PC: 0x08db04..0x08db1c (24 B) | Symbol: sub_08db04
// EN: AArch64 prologue [ldr x8, [x19]; ldur x8, [x8, #-0x18]; add x22, x19, x8; ldr x23, [x22, #0x28]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; ldur x8, [x8, #-0x18]; add x22, x19, x8; ldr x23, [x22, #0x28]]
uint64_t fde_sub_08db04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB04ULL;
}

// FDE #2568 | PC: 0x08db1c..0x08db28 (12 B) | Symbol: sub_08db1c
// EN: AArch64 prologue [mov x19, x0; add x0, x0, #0x10; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; add x0, x0, #0x10; ret]
uint64_t fde_sub_08db1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB1CULL;
}

// FDE #2569 | PC: 0x08db28..0x08db34 (12 B) | Symbol: sub_08db28
// EN: AArch64 prologue [fmul s2, s0, s2; fcmp s2, s1; ret] | VI: Khởi đầu hàm AArch64 [fmul s2, s0, s2; fcmp s2, s1; ret]
uint64_t fde_sub_08db28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E212040ULL) << 32) | 0x1E220802ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB28ULL;
}

// FDE #2570 | PC: 0x08db34..0x08db44 (16 B) | Symbol: sub_08db34
// EN: AArch64 prologue [mov x1, x19; mov x2, x20; mov x22, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x19; mov x2, x20; mov x22, x0; ret]
uint64_t fde_sub_08db34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E2ULL) << 32) | 0xAA1303E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB34ULL;
}

// FDE #2571 | PC: 0x08db44..0x08db50 (12 B) | Symbol: sub_08db44
// EN: AArch64 prologue [ldr x0, [sp]; str xzr, [sp]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp]; str xzr, [sp]; ret]
uint64_t fde_sub_08db44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xF94003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB44ULL;
}

// FDE #2572 | PC: 0x08db50..0x08db6c (28 B) | Symbol: sub_08db50
// EN: AArch64 prologue [fmov d0, x20; ldr x10, [x8, #8]; cnt v0.8b, v0.8b; uaddlv h0, v0.8b] | VI: Khởi đầu hàm AArch64 [fmov d0, x20; ldr x10, [x8, #8]; cnt v0.8b, v0.8b; uaddlv h0, v0.8b]
uint64_t fde_sub_08db50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940050AULL) << 32) | 0x9E670280ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB50ULL;
}

// FDE #2573 | PC: 0x08db6c..0x08db78 (12 B) | Symbol: sub_08db6c
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0, #0x10]; ret]
uint64_t fde_sub_08db6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB6CULL;
}

// FDE #2574 | PC: 0x08db78..0x08db84 (12 B) | Symbol: sub_08db78
// EN: AArch64 prologue [udiv x9, x8, x23; msub x8, x9, x23, x8; ret] | VI: Khởi đầu hàm AArch64 [udiv x9, x8, x23; msub x8, x9, x23, x8; ret]
uint64_t fde_sub_08db78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B17A128ULL) << 32) | 0x9AD70909ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB78ULL;
}

// FDE #2575 | PC: 0x08db84..0x08dbac (40 B) | Symbol: sub_08db84
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; adrp x9, #0x99000; add x9, x9, #0xe18] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; adrp x9, #0x99000; add x9, x9, #0xe18]
uint64_t fde_sub_08db84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB84ULL;
}

// FDE #2576 | PC: 0x08dbac..0x08dbb4 (8 B) | Symbol: sub_08dbac
// EN: AArch64 prologue [add sp, sp, #0xa0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0xa0; ret]
uint64_t fde_sub_08dbac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910283FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DBACULL;
}

// FDE #2577 | PC: 0x08dbb4..0x08dbc0 (12 B) | Symbol: sub_08dbb4
// EN: AArch64 prologue [ldur x8, [x8, #-0x18]; add x0, x19, x8; b #0x46bd0] | VI: Khởi đầu hàm AArch64 [ldur x8, [x8, #-0x18]; add x0, x19, x8; b #0x46bd0]
uint64_t fde_sub_08dbb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B080260ULL) << 32) | 0xF85E8108ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DBB4ULL;
}

// FDE #2578 | PC: 0x08dbc0..0x08dbc8 (8 B) | Symbol: sub_08dbc0
// EN: AArch64 prologue [mov w0, #0x38; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x38; b #0x93320]
uint64_t fde_sub_08dbc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140015D7ULL) << 32) | 0x52800700ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DBC0ULL;
}

// FDE #2579 | PC: 0x08dbc8..0x08dbf0 (40 B) | Symbol: sub_08dbc8
// EN: AArch64 prologue [adrp x8, #0x9c000; mov x19, x0; add x8, x8, #0x260; mov x25, x0] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; mov x19, x0; add x8, x8, #0x260; mov x25, x0]
uint64_t fde_sub_08dbc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF0000068ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DBC8ULL;
}

// FDE #2580 | PC: 0x08dbf0..0x08dc00 (16 B) | Symbol: sub_08dbf0
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; mov x1, x19; b #0x7ce1c] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; mov x1, x19; b #0x7ce1c]
uint64_t fde_sub_08dbf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DBF0ULL;
}

// FDE #2581 | PC: 0x08dc00..0x08dc10 (16 B) | Symbol: sub_08dc00
// EN: AArch64 prologue [adrp x1, #0x1d000; add x0, x21, #0x10; add x1, x1, #0; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1d000; add x0, x21, #0x10; add x1, x1, #0; b #0x4696c]
uint64_t fde_sub_08dc00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910042A0ULL) << 32) | 0x90FFFC81ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC00ULL;
}

// FDE #2582 | PC: 0x08dc10..0x08dc2c (28 B) | Symbol: sub_08dc10
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x0, x20; ldr x21, [x0], #0x10; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x0, x20; ldr x21, [x0], #0x10; bl #0x46c54]
uint64_t fde_sub_08dc10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC10ULL;
}

// FDE #2583 | PC: 0x08dc2c..0x08dc34 (8 B) | Symbol: sub_08dc2c
// EN: AArch64 prologue [mov x0, x20; b #0x932e0] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x932e0]
uint64_t fde_sub_08dc2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140015ACULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC2CULL;
}

// FDE #2584 | PC: 0x08dc34..0x08dc40 (12 B) | Symbol: sub_08dc34
// EN: AArch64 prologue [mov w2, #1; mov x20, x0; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x20, x0; b #0x93c30]
uint64_t fde_sub_08dc34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC34ULL;
}

// FDE #2585 | PC: 0x08dc40..0x08dc60 (32 B) | Symbol: sub_08dc40
// EN: AArch64 prologue [mov x8, x19; ldr x9, [x8, #0x10]!; str x9, [x20]; str x20, [x8]] | VI: Khởi đầu hàm AArch64 [mov x8, x19; ldr x9, [x8, #0x10]!; str x9, [x20]; str x20, [x8]]
uint64_t fde_sub_08dc40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8410D09ULL) << 32) | 0xAA1303E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC40ULL;
}

// FDE #2586 | PC: 0x08dc60..0x08dc8c (44 B) | Symbol: sub_08dc60
// EN: AArch64 prologue [str x8, [sp, #0x10]; str q0, [sp]; ldr x8, [x20, #0x10]; ldr q0, [x20]] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x10]; str q0, [sp]; ldr x8, [x20, #0x10]; ldr q0, [x20]]
uint64_t fde_sub_08dc60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D8003E0ULL) << 32) | 0xF9000BE8ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC60ULL;
}

// FDE #2587 | PC: 0x08dc8c..0x08dcb8 (44 B) | Symbol: sub_08dc8c
// EN: AArch64 prologue [str x8, [sp, #0x10]; str q0, [sp]; ldr x8, [x20, #0x10]; ldr q0, [x20]] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x10]; str q0, [sp]; ldr x8, [x20, #0x10]; ldr q0, [x20]]
uint64_t fde_sub_08dc8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D8003E0ULL) << 32) | 0xF9000BE8ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC8CULL;
}

// FDE #2588 | PC: 0x08dcb8..0x08dcc8 (16 B) | Symbol: sub_08dcb8
// EN: AArch64 prologue [sub x9, x9, x10; mov x10, #0xffffffffffffffe; cmp x10, x9, asr #3; ret] | VI: Khởi đầu hàm AArch64 [sub x9, x9, x10; mov x10, #0xffffffffffffffe; cmp x10, x9, asr #3; ret]
uint64_t fde_sub_08dcb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB27FEBEAULL) << 32) | 0xCB0A0129ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DCB8ULL;
}

// FDE #2589 | PC: 0x08dcc8..0x08dcd4 (12 B) | Symbol: sub_08dcc8
// EN: AArch64 prologue [ldr x19, [x0]; str x1, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x19, [x0]; str x1, [x0]; ret]
uint64_t fde_sub_08dcc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000001ULL) << 32) | 0xF9400013ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DCC8ULL;
}

// FDE #2590 | PC: 0x08dcd4..0x08dce8 (20 B) | Symbol: sub_08dcd4
// EN: AArch64 prologue [ldr x8, [x19, #0x18]; ldr s0, [x19, #0x20]; add x8, x8, #1; ucvtf s1, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x18]; ldr s0, [x19, #0x20]; add x8, x8, #1; ucvtf s1, x8]
uint64_t fde_sub_08dcd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD402260ULL) << 32) | 0xF9400E68ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DCD4ULL;
}

// FDE #2591 | PC: 0x08dce8..0x08dcf8 (16 B) | Symbol: sub_08dce8
// EN: AArch64 prologue [ldr x8, [x19, #0x28]; ldr x9, [sp, #0xf8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x28]; ldr x9, [sp, #0xf8]; cmp x8, x9; ret]
uint64_t fde_sub_08dce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9407FE9ULL) << 32) | 0xF9401668ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DCE8ULL;
}

// FDE #2592 | PC: 0x08dcf8..0x08dd00 (8 B) | Symbol: sub_08dcf8
// EN: AArch64 prologue [mov x0, x21; b #0x93cc0] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x93cc0]
uint64_t fde_sub_08dcf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140017F1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DCF8ULL;
}

// FDE #2593 | PC: 0x08dd00..0x08dd0c (12 B) | Symbol: sub_08dd00
// EN: AArch64 prologue [mov x20, x1; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x1; mov x19, x0; ret]
uint64_t fde_sub_08dd00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD00ULL;
}

// FDE #2594 | PC: 0x08dd0c..0x08dd18 (12 B) | Symbol: sub_08dd0c
// EN: AArch64 prologue [mov x0, x19; mov x1, x20; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x20; ret]
uint64_t fde_sub_08dd0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD0CULL;
}

// FDE #2595 | PC: 0x08dd18..0x08dd30 (24 B) | Symbol: sub_08dd18
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x19, x0; bl #0x66e90; mov x0, x19] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x19, x0; bl #0x66e90; mov x0, x19]
uint64_t fde_sub_08dd18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD18ULL;
}

// FDE #2596 | PC: 0x08dd30..0x08dd44 (20 B) | Symbol: sub_08dd30
// EN: AArch64 prologue [mov x8, sp; add x21, x8, #8; add x8, x19, #8; stp x22, x19, [sp]] | VI: Khởi đầu hàm AArch64 [mov x8, sp; add x21, x8, #8; add x8, x19, #8; stp x22, x19, [sp]]
uint64_t fde_sub_08dd30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002115ULL) << 32) | 0x910003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD30ULL;
}

// FDE #2597 | PC: 0x08dd44..0x08dd68 (36 B) | Symbol: sub_08dd44
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; mov x20, x1] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; mov x20, x1]
uint64_t fde_sub_08dd44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD44ULL;
}

// FDE #2598 | PC: 0x08dd68..0x08dd74 (12 B) | Symbol: sub_08dd68
// EN: AArch64 prologue [mov x19, x2; mov x20, x1; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x20, x1; b #0x93320]
uint64_t fde_sub_08dd68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F4ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD68ULL;
}

// FDE #2599 | PC: 0x08dd74..0x08dd7c (8 B) | Symbol: sub_08dd74
// EN: AArch64 prologue [mov x0, x20; b #0x46c54] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x46c54]
uint64_t fde_sub_08dd74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE3B7ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD74ULL;
}

// FDE #2600 | PC: 0x08dd7c..0x08ddc0 (68 B) | Symbol: sub_08dd7c
// EN: AArch64 prologue [ldrb w9, [x8, #0xc]; add x10, x8, #0x20; add x11, x8, #8; add x0, sp, #8] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x8, #0xc]; add x10, x8, #0x20; add x11, x8, #8; add x0, sp, #8]
uint64_t fde_sub_08dd7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100810AULL) << 32) | 0x39403109ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD7CULL;
}

// FDE #2601 | PC: 0x08ddc0..0x08ddd4 (20 B) | Symbol: sub_08ddc0
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x30]; ldp x23, x22, [sp, #0x20]; ldp x25, x24, [sp, #0x10]; ldr x26, [sp], #0x50] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x30]; ldp x23, x22, [sp, #0x20]; ldp x25, x24, [sp, #0x10]; ldr x26, [sp], #0x50]
uint64_t fde_sub_08ddc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9425BF7ULL) << 32) | 0xA94353F5ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DDC0ULL;
}

// FDE #2602 | PC: 0x08ddd4..0x08dde0 (12 B) | Symbol: sub_08ddd4
// EN: AArch64 prologue [mov x1, sp; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x20; ret]
uint64_t fde_sub_08ddd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DDD4ULL;
}

// FDE #2603 | PC: 0x08dde0..0x08ddec (12 B) | Symbol: sub_08dde0
// EN: AArch64 prologue [str xzr, [x9, x8, lsl #3]; add x8, x8, #1; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [x9, x8, lsl #3]; add x8, x8, #1; ret]
uint64_t fde_sub_08dde0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91000508ULL) << 32) | 0xF828793FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DDE0ULL;
}

// FDE #2604 | PC: 0x08ddec..0x08ddf8 (12 B) | Symbol: sub_08ddec
// EN: AArch64 prologue [ldr x9, [x8, #0x20]; mov x8, sp; br x9] | VI: Khởi đầu hàm AArch64 [ldr x9, [x8, #0x20]; mov x8, sp; br x9]
uint64_t fde_sub_08ddec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E8ULL) << 32) | 0xF9401109ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DDECULL;
}

// FDE #2605 | PC: 0x08ddf8..0x08de04 (12 B) | Symbol: sub_08ddf8
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0, #0x20]; ret]
uint64_t fde_sub_08ddf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DDF8ULL;
}

// FDE #2606 | PC: 0x08de04..0x08de18 (20 B) | Symbol: sub_08de04
// EN: AArch64 prologue [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w8, s0; cmp x8, #1] | VI: Khởi đầu hàm AArch64 [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w8, s0; cmp x8, #1]
uint64_t fde_sub_08de04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2E303800ULL) << 32) | 0x0E205800ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE04ULL;
}

// FDE #2607 | PC: 0x08de18..0x08de24 (12 B) | Symbol: sub_08de18
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; ret]
uint64_t fde_sub_08de18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE18ULL;
}

// FDE #2608 | PC: 0x08de24..0x08de3c (24 B) | Symbol: sub_08de24
// EN: AArch64 prologue [ldr x8, [x21, #8]; mov x20, x0; str x8, [sp]; ldr x8, [x21, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21, #8]; mov x20, x0; str x8, [sp]; ldr x8, [x21, #0x10]]
uint64_t fde_sub_08de24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xF94006A8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE24ULL;
}

// FDE #2609 | PC: 0x08de3c..0x08de4c (16 B) | Symbol: sub_08de3c
// EN: AArch64 prologue [ldr x13, [x12, #-8]!; str xzr, [x12]; str x13, [x8, #-8]!; ret] | VI: Khởi đầu hàm AArch64 [ldr x13, [x12, #-8]!; str xzr, [x12]; str x13, [x8, #-8]!; ret]
uint64_t fde_sub_08de3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900019FULL) << 32) | 0xF85F8D8DULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE3CULL;
}

// FDE #2610 | PC: 0x08de4c..0x08de5c (16 B) | Symbol: sub_08de4c
// EN: AArch64 prologue [asr x9, x9, #2; cmp x9, x8; csel x22, x8, x9, lo; ret] | VI: Khởi đầu hàm AArch64 [asr x9, x9, #2; cmp x9, x8; csel x22, x8, x9, lo; ret]
uint64_t fde_sub_08de4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB08013FULL) << 32) | 0x9342FD29ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE4CULL;
}

// FDE #2611 | PC: 0x08de5c..0x08de74 (24 B) | Symbol: sub_08de5c
// EN: AArch64 prologue [ldr x8, [sp]; add x1, sp, #0x20; mov x23, x0; str xzr, [sp]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp]; add x1, sp, #0x20; mov x23, x0; str xzr, [sp]]
uint64_t fde_sub_08de5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910083E1ULL) << 32) | 0xF94003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE5CULL;
}

// FDE #2612 | PC: 0x08de74..0x08de84 (16 B) | Symbol: sub_08de74
// EN: AArch64 prologue [ldr x8, [x20]; mov x0, x20; ldr x8, [x8, #0x10]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20]; mov x0, x20; ldr x8, [x8, #0x10]; br x8]
uint64_t fde_sub_08de74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xF9400288ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE74ULL;
}

// FDE #2613 | PC: 0x08de84..0x08de90 (12 B) | Symbol: sub_08de84
// EN: AArch64 prologue [mov x0, x20; mov x1, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x19; ret]
uint64_t fde_sub_08de84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE84ULL;
}

// FDE #2614 | PC: 0x08de90..0x08dea8 (24 B) | Symbol: sub_08de90
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; ldr s0, [x0, #8]; fmov s1, wzr; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; ldr s0, [x0, #8]; fmov s1, wzr; cmp w8, #0]
uint64_t fde_sub_08de90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD400800ULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE90ULL;
}

// FDE #2615 | PC: 0x08dea8..0x08def0 (72 B) | Symbol: sub_08dea8
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; ldrb w10, [x0, #0x14]; mov w9, #8; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; ldrb w10, [x0, #0x14]; mov w9, #8; cmp w8, #0]
uint64_t fde_sub_08dea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940500AULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DEA8ULL;
}

// FDE #2616 | PC: 0x08def0..0x08df00 (16 B) | Symbol: sub_08def0
// EN: AArch64 prologue [ldr x8, [x8, #8]; sub x9, x23, #1; tst x23, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #8]; sub x9, x23, #1; tst x23, x9; ret]
uint64_t fde_sub_08def0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10006E9ULL) << 32) | 0xF9400508ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DEF0ULL;
}

// FDE #2617 | PC: 0x08df00..0x08df10 (16 B) | Symbol: sub_08df00
// EN: AArch64 prologue [ldr x8, [x0]; mov w1, w20; ldr x8, [x8, #0x18]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov w1, w20; ldr x8, [x8, #0x18]; br x8]
uint64_t fde_sub_08df00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1403E1ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF00ULL;
}

// FDE #2618 | PC: 0x08df10..0x08df1c (12 B) | Symbol: sub_08df10
// EN: AArch64 prologue [add x1, sp, #8; mov x0, x19; ret] | VI: Khởi đầu hàm AArch64 [add x1, sp, #8; mov x0, x19; ret]
uint64_t fde_sub_08df10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910023E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF10ULL;
}

// FDE #2619 | PC: 0x08df1c..0x08df34 (24 B) | Symbol: sub_08df1c
// EN: AArch64 prologue [ldp x8, x9, [x19]; mov x21, x0; stp xzr, x23, [sp, #0x20]; sub x8, x9, x8] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x19]; mov x21, x0; stp xzr, x23, [sp, #0x20]; sub x8, x9, x8]
uint64_t fde_sub_08df1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xA9402668ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF1CULL;
}

// FDE #2620 | PC: 0x08df34..0x08df4c (24 B) | Symbol: sub_08df34
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #0x18]; ldr x21, [x0, #0x98]] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #0x18]; ldr x21, [x0, #0x98]]
uint64_t fde_sub_08df34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF34ULL;
}

// FDE #2621 | PC: 0x08df4c..0x08df6c (32 B) | Symbol: sub_08df4c
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x21, x0; mov x20, x2] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x21, x0; mov x20, x2]
uint64_t fde_sub_08df4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF4CULL;
}

// FDE #2622 | PC: 0x08df6c..0x08df74 (8 B) | Symbol: sub_08df6c
// EN: AArch64 prologue [add sp, sp, #0x80; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x80; ret]
uint64_t fde_sub_08df6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910203FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF6CULL;
}

// FDE #2623 | PC: 0x08df74..0x08df88 (20 B) | Symbol: sub_08df74
// EN: AArch64 prologue [madd x9, x21, x8, x0; madd x8, x20, x8, x0; stp x0, x9, [x19]; stp x9, x8, [x19, #0x10]] | VI: Khởi đầu hàm AArch64 [madd x9, x21, x8, x0; madd x8, x20, x8, x0; stp x0, x9, [x19]; stp x9, x8, [x19, #0x10]]
uint64_t fde_sub_08df74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B080288ULL) << 32) | 0x9B0802A9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF74ULL;
}

// FDE #2624 | PC: 0x08df88..0x08df9c (20 B) | Symbol: sub_08df88
// EN: AArch64 prologue [mov x21, x2; mov x20, x1; mov x19, x0; stp xzr, x3, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [mov x21, x2; mov x20, x1; mov x19, x0; stp xzr, x3, [x0, #0x18]]
uint64_t fde_sub_08df88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F4ULL) << 32) | 0xAA0203F5ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF88ULL;
}

// FDE #2625 | PC: 0x08df9c..0x08dfa8 (12 B) | Symbol: sub_08df9c
// EN: AArch64 prologue [add x8, x8, #1; ucvtf s1, x8; ret] | VI: Khởi đầu hàm AArch64 [add x8, x8, #1; ucvtf s1, x8; ret]
uint64_t fde_sub_08df9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E230101ULL) << 32) | 0x91000508ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF9CULL;
}

// FDE #2626 | PC: 0x08dfa8..0x08dfe4 (60 B) | Symbol: sub_08dfa8
// EN: AArch64 prologue [ldr x8, [x22, #0x10]; ldr q0, [x22]; mov x0, x22; mov x1, x20] | VI: Khởi đầu hàm AArch64 [ldr x8, [x22, #0x10]; ldr q0, [x22]; mov x0, x22; mov x1, x20]
uint64_t fde_sub_08dfa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC002C0ULL) << 32) | 0xF9400AC8ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DFA8ULL;
}

// FDE #2627 | PC: 0x08dfe4..0x08dff0 (12 B) | Symbol: sub_08dfe4
// EN: AArch64 prologue [str x8, [sp, #0x138]; add x20, sp, #0x10; b #0x46964] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x138]; add x20, sp, #0x10; b #0x46964]
uint64_t fde_sub_08dfe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043F4ULL) << 32) | 0xF9009FE8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DFE4ULL;
}

// FDE #2628 | PC: 0x08dff0..0x08dffc (12 B) | Symbol: sub_08dff0
// EN: AArch64 prologue [ldr x19, [x0]; str xzr, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x19, [x0]; str xzr, [x0]; ret]
uint64_t fde_sub_08dff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900001FULL) << 32) | 0xF9400013ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DFF0ULL;
}

// FDE #2629 | PC: 0x08dffc..0x08e004 (8 B) | Symbol: sub_08dffc
// EN: AArch64 prologue [ldr x8, [x8, #0x78]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x78]; br x8]
uint64_t fde_sub_08dffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9403D08ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DFFCULL;
}

// FDE #2630 | PC: 0x08e004..0x08e024 (32 B) | Symbol: sub_08e004
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; ldr s0, [x0, #8]; fmov s1, wzr; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; ldr s0, [x0, #8]; fmov s1, wzr; cmp w8, #0]
uint64_t fde_sub_08e004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD400800ULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E004ULL;
}

// FDE #2631 | PC: 0x08e024..0x08e030 (12 B) | Symbol: sub_08e024
// EN: AArch64 prologue [ldr x1, [x0]; mov x0, x8; b #0x8bb6c] | VI: Khởi đầu hàm AArch64 [ldr x1, [x0]; mov x0, x8; b #0x8bb6c]
uint64_t fde_sub_08e024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xF9400001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E024ULL;
}

// FDE #2632 | PC: 0x08e030..0x08e03c (12 B) | Symbol: sub_08e030
// EN: AArch64 prologue [ldr x20, [x0, #8]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [ldr x20, [x0, #8]; mov x19, x0; ret]
uint64_t fde_sub_08e030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF9400414ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E030ULL;
}

// FDE #2633 | PC: 0x08e03c..0x08e058 (28 B) | Symbol: sub_08e03c
// EN: AArch64 prologue [str x8, [x0]; add x9, x8, #0xc8; add x8, x8, #0xe8; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; add x9, x8, #0xc8; add x8, x8, #0xe8; mov x19, x0]
uint64_t fde_sub_08e03c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91032109ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E03CULL;
}

// FDE #2634 | PC: 0x08e058..0x08e094 (60 B) | Symbol: sub_08e058
// EN: AArch64 prologue [ldr x8, [x1, #8]; ldr x9, [x0]; str x8, [x0]; ldr x8, [x1, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #8]; ldr x9, [x0]; str x8, [x0]; ldr x8, [x1, #0x10]]
uint64_t fde_sub_08e058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400009ULL) << 32) | 0xF9400428ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E058ULL;
}

// FDE #2635 | PC: 0x08e094..0x08e0a0 (12 B) | Symbol: sub_08e094
// EN: AArch64 prologue [add x1, x29, #0x10; mov x0, x21; b #0x4c4d4] | VI: Khởi đầu hàm AArch64 [add x1, x29, #0x10; mov x0, x21; b #0x4c4d4]
uint64_t fde_sub_08e094(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x910043A1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E094ULL;
}

// FDE #2636 | PC: 0x08e0a0..0x08e0a8 (8 B) | Symbol: sub_08e0a0
// EN: AArch64 prologue [lsl x0, x20, #3; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsl x0, x20, #3; b #0x93320]
uint64_t fde_sub_08e0a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400149FULL) << 32) | 0xD37DF280ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E0A0ULL;
}

// FDE #2637 | PC: 0x08e0a8..0x08e0e4 (60 B) | Symbol: sub_08e0a8
// EN: AArch64 prologue [ldr x8, [x20, #0x10]; ldr q0, [x20]; mov x0, x20; mov x1, x21] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20, #0x10]; ldr q0, [x20]; mov x0, x20; mov x1, x21]
uint64_t fde_sub_08e0a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC00280ULL) << 32) | 0xF9400A88ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E0A8ULL;
}

// FDE #2638 | PC: 0x08e0e4..0x08e108 (36 B) | Symbol: sub_08e0e4
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; str x8, [sp, #0x38]; ldr x19, [x1]] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; str x8, [sp, #0x38]; ldr x19, [x1]]
uint64_t fde_sub_08e0e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E0E4ULL;
}

// FDE #2639 | PC: 0x08e108..0x08e118 (16 B) | Symbol: sub_08e108
// EN: AArch64 prologue [mov x19, x2; mov x20, x1; mov x21, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x20, x1; mov x21, x0; ret]
uint64_t fde_sub_08e108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F4ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E108ULL;
}

// FDE #2640 | PC: 0x08e118..0x08e128 (16 B) | Symbol: sub_08e118
// EN: AArch64 prologue [mov x1, x23; mov x2, x25; mov x24, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x23; mov x2, x25; mov x24, x0; ret]
uint64_t fde_sub_08e118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E2ULL) << 32) | 0xAA1703E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E118ULL;
}

// FDE #2641 | PC: 0x08e128..0x08e134 (12 B) | Symbol: sub_08e128
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; ret]
uint64_t fde_sub_08e128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E128ULL;
}

// FDE #2642 | PC: 0x08e134..0x08e158 (36 B) | Symbol: sub_08e134
// EN: AArch64 prologue [mov x19, x1; ldp x1, x8, [x0]; ldr x9, [x19, #8]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [mov x19, x1; ldp x1, x8, [x0]; ldr x9, [x19, #8]; mov x20, x0]
uint64_t fde_sub_08e134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9402001ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E134ULL;
}

// FDE #2643 | PC: 0x08e158..0x08e160 (8 B) | Symbol: sub_08e158
// EN: AArch64 prologue [mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; ret]
uint64_t fde_sub_08e158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E158ULL;
}

// FDE #2644 | PC: 0x08e160..0x08e168 (8 B) | Symbol: sub_08e160
// EN: AArch64 prologue [add x1, x1, #0; b #0x4696c] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0; b #0x4696c]
uint64_t fde_sub_08e160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE202ULL) << 32) | 0x91000021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E160ULL;
}

// FDE #2645 | PC: 0x08e168..0x08e178 (16 B) | Symbol: sub_08e168
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x0; ret]
uint64_t fde_sub_08e168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E168ULL;
}

// FDE #2646 | PC: 0x08e178..0x08e184 (12 B) | Symbol: sub_08e178
// EN: AArch64 prologue [ldr x9, [sp, #0xf8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0xf8]; cmp x8, x9; ret]
uint64_t fde_sub_08e178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9407FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E178ULL;
}

// FDE #2647 | PC: 0x08e184..0x08e1a8 (36 B) | Symbol: sub_08e184
// EN: AArch64 prologue [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; str x8, [sp, #8]; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; str x8, [sp, #8]; ldr x8, [x1]]
uint64_t fde_sub_08e184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401668ULL) << 32) | 0xD53BD053ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E184ULL;
}

// FDE #2648 | PC: 0x08e1a8..0x08e1b8 (16 B) | Symbol: sub_08e1a8
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xf02; add x0, sp, #8; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xf02; add x0, sp, #8; ret]
uint64_t fde_sub_08e1a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913C0821ULL) << 32) | 0xD0FFFC61ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E1A8ULL;
}

// FDE #2649 | PC: 0x08e1b8..0x08e1c4 (12 B) | Symbol: sub_08e1b8
// EN: AArch64 prologue [ldr x8, [x8, #8]; cmn x8, #1; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #8]; cmn x8, #1; ret]
uint64_t fde_sub_08e1b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB100051FULL) << 32) | 0xF9400508ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E1B8ULL;
}

// FDE #2650 | PC: 0x08e1c4..0x08e1cc (8 B) | Symbol: sub_08e1c4
// EN: AArch64 prologue [add sp, sp, #0xb0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0xb0; ret]
uint64_t fde_sub_08e1c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9102C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E1C4ULL;
}

// FDE #2651 | PC: 0x08e1cc..0x08e1d4 (8 B) | Symbol: sub_08e1cc
// EN: AArch64 prologue [add sp, sp, #0x20; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x20; ret]
uint64_t fde_sub_08e1cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910083FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E1CCULL;
}

// FDE #2652 | PC: 0x08e1d4..0x08e1f4 (32 B) | Symbol: sub_08e1d4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x44830; mov x0, xzr; bl #0x44830] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x44830; mov x0, xzr; bl #0x44830]
uint64_t fde_sub_08e1d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FED996ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E1D4ULL;
}

// FDE #2653 | PC: 0x08e1f4..0x08e1fc (8 B) | Symbol: sub_08e1f4
// EN: AArch64 prologue [add x0, sp, #8; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x46c54]
uint64_t fde_sub_08e1f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE297ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E1F4ULL;
}

// FDE #2654 | PC: 0x08e1fc..0x08e20c (16 B) | Symbol: sub_08e1fc
// EN: AArch64 prologue [ldr x9, [x19]; sub x25, x20, #1; str x8, [x9, x24, lsl #3]; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [x19]; sub x25, x20, #1; str x8, [x9, x24, lsl #3]; ret]
uint64_t fde_sub_08e1fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1000699ULL) << 32) | 0xF9400269ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E1FCULL;
}

// FDE #2655 | PC: 0x08e20c..0x08e214 (8 B) | Symbol: sub_08e20c
// EN: AArch64 prologue [mov x0, x19; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x93910]
uint64_t fde_sub_08e20c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140015C0ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E20CULL;
}

// FDE #2656 | PC: 0x08e214..0x08e230 (28 B) | Symbol: sub_08e214
// EN: AArch64 prologue [stp x8, x9, [x0, #0x10]; str x0, [sp, #0x218]; add x1, sp, #0x218; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x8, x9, [x0, #0x10]; str x0, [sp, #0x218]; add x1, sp, #0x218; mov x0, x19]
uint64_t fde_sub_08e214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9010FE0ULL) << 32) | 0xA9012408ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E214ULL;
}

// FDE #2657 | PC: 0x08e230..0x08e238 (8 B) | Symbol: sub_08e230
// EN: AArch64 prologue [mov w0, #0x70; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x70; b #0x93320]
uint64_t fde_sub_08e230(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400143BULL) << 32) | 0x52800E00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E230ULL;
}

// FDE #2658 | PC: 0x08e238..0x08e244 (12 B) | Symbol: sub_08e238
// EN: AArch64 prologue [add x0, sp, #0x20; add x1, sp, #0x50; b #0x506ec] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; add x1, sp, #0x50; b #0x506ec]
uint64_t fde_sub_08e238(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910143E1ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E238ULL;
}

// FDE #2659 | PC: 0x08e244..0x08e254 (16 B) | Symbol: sub_08e244
// EN: AArch64 prologue [ldr x24, [x20]; mov w0, #0x20; str xzr, [x20]; b #0x93320] | VI: Khởi đầu hàm AArch64 [ldr x24, [x20]; mov w0, #0x20; str xzr, [x20]; b #0x93320]
uint64_t fde_sub_08e244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800400ULL) << 32) | 0xF9400298ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E244ULL;
}

// FDE #2660 | PC: 0x08e254..0x08e260 (12 B) | Symbol: sub_08e254
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x10]; ldr x22, [sp], #0x30; b #0x932e0] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x10]; ldr x22, [sp], #0x30; b #0x932e0]
uint64_t fde_sub_08e254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84307F6ULL) << 32) | 0xA94153F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E254ULL;
}

// FDE #2661 | PC: 0x08e260..0x08e26c (12 B) | Symbol: sub_08e260
// EN: AArch64 prologue [ldr x9, [sp, #0x148]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x148]; cmp x8, x9; ret]
uint64_t fde_sub_08e260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF940A7E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E260ULL;
}

// FDE #2662 | PC: 0x08e26c..0x08e27c (16 B) | Symbol: sub_08e26c
// EN: AArch64 prologue [mov x22, x0; stp xzr, xzr, [x0, #8]; str xzr, [x0]; b #0x6af58] | VI: Khởi đầu hàm AArch64 [mov x22, x0; stp xzr, xzr, [x0, #8]; str xzr, [x0]; b #0x6af58]
uint64_t fde_sub_08e26c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA900FC1FULL) << 32) | 0xAA0003F6ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E26CULL;
}

// FDE #2663 | PC: 0x08e27c..0x08e284 (8 B) | Symbol: sub_08e27c
// EN: AArch64 prologue [add x0, sp, #0x10; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x10; b #0x46c54]
uint64_t fde_sub_08e27c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE275ULL) << 32) | 0x910043E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E27CULL;
}

// FDE #2664 | PC: 0x08e284..0x08e290 (12 B) | Symbol: sub_08e284
// EN: AArch64 prologue [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1]
uint64_t fde_sub_08e284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400101ULL) << 32) | 0xF8418C08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E284ULL;
}

// FDE #2665 | PC: 0x08e290..0x08e298 (8 B) | Symbol: sub_08e290
// EN: AArch64 prologue [mov x19, x1; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov x19, x1; b #0x93320]
uint64_t fde_sub_08e290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001423ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E290ULL;
}

// FDE #2666 | PC: 0x08e298..0x08e2ac (20 B) | Symbol: sub_08e298
// EN: AArch64 prologue [mov x2, x0; mov x0, x19; mov x1, x20; mov x3, x21] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x19; mov x1, x20; mov x3, x21]
uint64_t fde_sub_08e298(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E298ULL;
}

// FDE #2667 | PC: 0x08e2ac..0x08e2c8 (28 B) | Symbol: sub_08e2ac
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x0; add x0, sp, #0x48] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x0; add x0, sp, #0x48]
uint64_t fde_sub_08e2ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E2ACULL;
}

// FDE #2668 | PC: 0x08e2c8..0x08e2d0 (8 B) | Symbol: sub_08e2c8
// EN: AArch64 prologue [add x0, sp, #0x18; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x18; b #0x937a0]
uint64_t fde_sub_08e2c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001535ULL) << 32) | 0x910063E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E2C8ULL;
}

// FDE #2669 | PC: 0x08e2d0..0x08e2dc (12 B) | Symbol: sub_08e2d0
// EN: AArch64 prologue [ldr x9, [sp, #0x68]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x68]; cmp x8, x9; ret]
uint64_t fde_sub_08e2d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94037E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E2D0ULL;
}

// FDE #2670 | PC: 0x08e2dc..0x08e310 (52 B) | Symbol: sub_08e2dc
// EN: AArch64 prologue [cmp w9, #0; mov x9, #0x4059000000000000; fcsel d1, d0, d1, eq; fmul d1, d9, d1] | VI: Khởi đầu hàm AArch64 [cmp w9, #0; mov x9, #0x4059000000000000; fcsel d1, d0, d1, eq; fmul d1, d9, d1]
uint64_t fde_sub_08e2dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2E80B29ULL) << 32) | 0x7100013FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E2DCULL;
}

// FDE #2671 | PC: 0x08e310..0x08e31c (12 B) | Symbol: sub_08e310
// EN: AArch64 prologue [mov w2, #1; mov x21, x0; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x21, x0; b #0x93c30]
uint64_t fde_sub_08e310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E310ULL;
}

// FDE #2672 | PC: 0x08e31c..0x08e328 (12 B) | Symbol: sub_08e31c
// EN: AArch64 prologue [mov w2, #1; mov x0, x19; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x19; b #0x93c30]
uint64_t fde_sub_08e31c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E31CULL;
}

// FDE #2673 | PC: 0x08e328..0x08e364 (60 B) | Symbol: sub_08e328
// EN: AArch64 prologue [ldrb w8, [x20, #0xc]; ldrb w10, [x20, #0x14]; mov w9, #8; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x20, #0xc]; ldrb w10, [x20, #0x14]; mov w9, #8; cmp w8, #0]
uint64_t fde_sub_08e328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940528AULL) << 32) | 0x39403288ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E328ULL;
}

// FDE #2674 | PC: 0x08e364..0x08e378 (20 B) | Symbol: sub_08e364
// EN: AArch64 prologue [ldr x9, [x0]; mov x20, x0; mov x19, x8; ldr x9, [x9, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0]; mov x20, x0; mov x19, x8; ldr x9, [x9, #0x18]]
uint64_t fde_sub_08e364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xF9400009ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E364ULL;
}

// FDE #2675 | PC: 0x08e378..0x08e38c (20 B) | Symbol: sub_08e378
// EN: AArch64 prologue [mov x19, x3; mov x20, x2; mov x21, x1; mov x23, x8] | VI: Khởi đầu hàm AArch64 [mov x19, x3; mov x20, x2; mov x21, x1; mov x23, x8]
uint64_t fde_sub_08e378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203F4ULL) << 32) | 0xAA0303F3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E378ULL;
}

// FDE #2676 | PC: 0x08e38c..0x08e394 (8 B) | Symbol: sub_08e38c
// EN: AArch64 prologue [ldr x0, [sp, #8]; b #0x44830] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #8]; b #0x44830]
uint64_t fde_sub_08e38c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED928ULL) << 32) | 0xF94007E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E38CULL;
}

// FDE #2677 | PC: 0x08e394..0x08e3b0 (28 B) | Symbol: sub_08e394
// EN: AArch64 prologue [ldr x9, [x19]; mov x0, x19; add x23, x19, #0x10; sub x8, x8, x9] | VI: Khởi đầu hàm AArch64 [ldr x9, [x19]; mov x0, x19; add x23, x19, #0x10; sub x8, x8, x9]
uint64_t fde_sub_08e394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xF9400269ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E394ULL;
}

// FDE #2678 | PC: 0x08e3b0..0x08e3bc (12 B) | Symbol: sub_08e3b0
// EN: AArch64 prologue [stp xzr, xzr, [x0, #8]; str xzr, [x0]; b #0x6af58] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0, #8]; str xzr, [x0]; b #0x6af58]
uint64_t fde_sub_08e3b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900001FULL) << 32) | 0xA900FC1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E3B0ULL;
}

// FDE #2679 | PC: 0x08e3bc..0x08e3cc (16 B) | Symbol: sub_08e3bc
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldp x28, x24, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldp x28, x24, [sp], #0x40; ret]
uint64_t fde_sub_08e3bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9415BF7ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E3BCULL;
}

// FDE #2680 | PC: 0x08e3cc..0x08e3d4 (8 B) | Symbol: sub_08e3cc
// EN: AArch64 prologue [ldr x9, [x9, #0x30]; br x9] | VI: Khởi đầu hàm AArch64 [ldr x9, [x9, #0x30]; br x9]
uint64_t fde_sub_08e3cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0120ULL) << 32) | 0xF9401929ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E3CCULL;
}

// FDE #2681 | PC: 0x08e3d4..0x08e3e4 (16 B) | Symbol: sub_08e3d4
// EN: AArch64 prologue [and w3, w3, #1; mov x19, x1; mov x20, x0; b #0x627f0] | VI: Khởi đầu hàm AArch64 [and w3, w3, #1; mov x19, x1; mov x20, x0; b #0x627f0]
uint64_t fde_sub_08e3d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F3ULL) << 32) | 0x12000063ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E3D4ULL;
}

// FDE #2682 | PC: 0x08e3e4..0x08e3f4 (16 B) | Symbol: sub_08e3e4
// EN: AArch64 prologue [ldr x8, [x8, #0x6b8]; mov w3, #1; mov x0, x19; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x6b8]; mov w3, #1; mov x0, x19; br x8]
uint64_t fde_sub_08e3e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800023ULL) << 32) | 0xF9435D08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E3E4ULL;
}

// FDE #2683 | PC: 0x08e3f4..0x08e430 (60 B) | Symbol: sub_08e3f4
// EN: AArch64 prologue [ldr x8, [x20, #8]; ldr x9, [x19]; str x8, [x19]; ldr x8, [x20, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20, #8]; ldr x9, [x19]; str x8, [x19]; ldr x8, [x20, #0x10]]
uint64_t fde_sub_08e3f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400269ULL) << 32) | 0xF9400688ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E3F4ULL;
}

// FDE #2684 | PC: 0x08e430..0x08e440 (16 B) | Symbol: sub_08e430
// EN: AArch64 prologue [mov x0, sp; mov x1, x19; str x8, [sp, #0x18]; b #0x46b60] | VI: Khởi đầu hàm AArch64 [mov x0, sp; mov x1, x19; str x8, [sp, #0x18]; b #0x46b60]
uint64_t fde_sub_08e430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E430ULL;
}

// FDE #2685 | PC: 0x08e440..0x08e448 (8 B) | Symbol: sub_08e440
// EN: AArch64 prologue [mov x0, sp; b #0x66eb0] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x66eb0]
uint64_t fde_sub_08e440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF629BULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E440ULL;
}

// FDE #2686 | PC: 0x08e448..0x08e454 (12 B) | Symbol: sub_08e448
// EN: AArch64 prologue [mov x0, x19; mov x1, x21; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x21; ret]
uint64_t fde_sub_08e448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E448ULL;
}

// FDE #2687 | PC: 0x08e454..0x08e460 (12 B) | Symbol: sub_08e454
// EN: AArch64 prologue [mov x19, x0; mov x20, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; mov x20, x1; ret]
uint64_t fde_sub_08e454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F4ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E454ULL;
}

// FDE #2688 | PC: 0x08e460..0x08e470 (16 B) | Symbol: sub_08e460
// EN: AArch64 prologue [mov x19, x0; mov x0, x1; mov x22, x1; b #0x4c158] | VI: Khởi đầu hàm AArch64 [mov x19, x0; mov x0, x1; mov x22, x1; b #0x4c158]
uint64_t fde_sub_08e460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E460ULL;
}

// FDE #2689 | PC: 0x08e470..0x08e484 (20 B) | Symbol: sub_08e470
// EN: AArch64 prologue [fcvtpu x9, s0; cmp x8, x9; csel x1, x9, x8, lo; mov x0, x19] | VI: Khởi đầu hàm AArch64 [fcvtpu x9, s0; cmp x8, x9; csel x1, x9, x8, lo; mov x0, x19]
uint64_t fde_sub_08e470(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0x9E290009ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E470ULL;
}

// FDE #2690 | PC: 0x08e484..0x08e498 (20 B) | Symbol: sub_08e484
// EN: AArch64 prologue [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w22, s0; cmp x22, #1] | VI: Khởi đầu hàm AArch64 [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w22, s0; cmp x22, #1]
uint64_t fde_sub_08e484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2E303800ULL) << 32) | 0x0E205800ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E484ULL;
}

// FDE #2691 | PC: 0x08e498..0x08e4a4 (12 B) | Symbol: sub_08e498
// EN: AArch64 prologue [mov x8, xzr; str x20, [x19, #8]; ret] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; str x20, [x19, #8]; ret]
uint64_t fde_sub_08e498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000674ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E498ULL;
}

// FDE #2692 | PC: 0x08e4a4..0x08e4b0 (12 B) | Symbol: sub_08e4a4
// EN: AArch64 prologue [mov x19, x2; mov x20, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x20, x1; ret]
uint64_t fde_sub_08e4a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F4ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E4A4ULL;
}

// FDE #2693 | PC: 0x08e4b0..0x08e4c0 (16 B) | Symbol: sub_08e4b0
// EN: AArch64 prologue [ldr x23, [x19, #8]; sub x8, x23, #1; tst x23, x8; ret] | VI: Khởi đầu hàm AArch64 [ldr x23, [x19, #8]; sub x8, x23, #1; tst x23, x8; ret]
uint64_t fde_sub_08e4b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10006E8ULL) << 32) | 0xF9400677ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E4B0ULL;
}

// FDE #2694 | PC: 0x08e4c0..0x08e4d8 (24 B) | Symbol: sub_08e4c0
// EN: AArch64 prologue [fmov d0, x23; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w25, s0] | VI: Khởi đầu hàm AArch64 [fmov d0, x23; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w25, s0]
uint64_t fde_sub_08e4c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0E205800ULL) << 32) | 0x9E6702E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E4C0ULL;
}

// FDE #2695 | PC: 0x08e4d8..0x08e4e0 (8 B) | Symbol: sub_08e4d8
// EN: AArch64 prologue [mov x1, x25; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x25; b #0x93910]
uint64_t fde_sub_08e4d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400150DULL) << 32) | 0xAA1903E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E4D8ULL;
}

// FDE #2696 | PC: 0x08e4e0..0x08e4e8 (8 B) | Symbol: sub_08e4e0
// EN: AArch64 prologue [add sp, sp, #0x190; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x190; ret]
uint64_t fde_sub_08e4e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910643FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E4E0ULL;
}

// FDE #2697 | PC: 0x08e4e8..0x08e500 (24 B) | Symbol: sub_08e4e8
// EN: AArch64 prologue [mov x1, x0; add x0, sp, #8; mov x3, x21; sub x8, x9, x8] | VI: Khởi đầu hàm AArch64 [mov x1, x0; add x0, sp, #8; mov x3, x21; sub x8, x9, x8]
uint64_t fde_sub_08e4e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E0ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E4E8ULL;
}

// FDE #2698 | PC: 0x08e500..0x08e50c (12 B) | Symbol: sub_08e500
// EN: AArch64 prologue [mov x1, x0; mov x0, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x0; mov x0, x19; ret]
uint64_t fde_sub_08e500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E500ULL;
}

// FDE #2699 | PC: 0x08e50c..0x08e51c (16 B) | Symbol: sub_08e50c
// EN: AArch64 prologue [stp xzr, xzr, [x0]; mov x19, x0; ldr x0, [x1, #8]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; mov x19, x0; ldr x0, [x1, #8]; ret]
uint64_t fde_sub_08e50c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E50CULL;
}

// FDE #2700 | PC: 0x08e51c..0x08e534 (24 B) | Symbol: sub_08e51c
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; str x8, [sp, #0x28]; ldr x19, [x0, #0x98]] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; str x8, [sp, #0x28]; ldr x19, [x0, #0x98]]
uint64_t fde_sub_08e51c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E51CULL;
}

// FDE #2701 | PC: 0x08e534..0x08e53c (8 B) | Symbol: sub_08e534
// EN: AArch64 prologue [ldr x0, [x8, #8]; b #0x8c244] | VI: Khởi đầu hàm AArch64 [ldr x0, [x8, #8]; b #0x8c244]
uint64_t fde_sub_08e534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFF743ULL) << 32) | 0xF9400500ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E534ULL;
}

// FDE #2702 | PC: 0x08e53c..0x08e544 (8 B) | Symbol: sub_08e53c
// EN: AArch64 prologue [mov x1, x26; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x26; b #0x93910]
uint64_t fde_sub_08e53c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140014F4ULL) << 32) | 0xAA1A03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E53CULL;
}

// FDE #2703 | PC: 0x08e544..0x08e54c (8 B) | Symbol: sub_08e544
// EN: AArch64 prologue [add x0, sp, #0x18; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x18; b #0x46c54]
uint64_t fde_sub_08e544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE1C3ULL) << 32) | 0x910063E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E544ULL;
}

// FDE #2704 | PC: 0x08e54c..0x08e564 (24 B) | Symbol: sub_08e54c
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x21, x2; mov x20, x0] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x21, x2; mov x20, x0]
uint64_t fde_sub_08e54c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E54CULL;
}

// FDE #2705 | PC: 0x08e564..0x08e578 (20 B) | Symbol: sub_08e564
// EN: AArch64 prologue [ldr x20, [x0, #8]; sub x21, x2, x1; mov x19, x0; cmp x21, #1] | VI: Khởi đầu hàm AArch64 [ldr x20, [x0, #8]; sub x21, x2, x1; mov x19, x0; cmp x21, #1]
uint64_t fde_sub_08e564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB010055ULL) << 32) | 0xF9400414ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E564ULL;
}

// FDE #2706 | PC: 0x08e578..0x08e5b8 (64 B) | Symbol: sub_08e578
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x1, #0x10]; ldr q0, [x1]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x1, #0x10]; ldr q0, [x1]; mov x20, x0]
uint64_t fde_sub_08e578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400828ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E578ULL;
}

// FDE #2707 | PC: 0x08e5b8..0x08e5c4 (12 B) | Symbol: sub_08e5b8
// EN: AArch64 prologue [str x22, [x8, x27, lsl #3]; mov x24, x27; ret] | VI: Khởi đầu hàm AArch64 [str x22, [x8, x27, lsl #3]; mov x24, x27; ret]
uint64_t fde_sub_08e5b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1B03F8ULL) << 32) | 0xF83B7916ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E5B8ULL;
}

// FDE #2708 | PC: 0x08e5c4..0x08e5d0 (12 B) | Symbol: sub_08e5c4
// EN: AArch64 prologue [ldr x8, [x8, x27, lsl #3]; str x26, [x8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, x27, lsl #3]; str x26, [x8]; ret]
uint64_t fde_sub_08e5c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900011AULL) << 32) | 0xF87B7908ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E5C4ULL;
}

// FDE #2709 | PC: 0x08e5d0..0x08e5dc (12 B) | Symbol: sub_08e5d0
// EN: AArch64 prologue [mov x28, x29; ldr x29, [x29]; ret] | VI: Khởi đầu hàm AArch64 [mov x28, x29; ldr x29, [x29]; ret]
uint64_t fde_sub_08e5d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003BDULL) << 32) | 0xAA1D03FCULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E5D0ULL;
}

// FDE #2710 | PC: 0x08e5dc..0x08e5e4 (8 B) | Symbol: sub_08e5dc
// EN: AArch64 prologue [add x0, sp, #8; b #0x66eb0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x66eb0]
uint64_t fde_sub_08e5dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF6234ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E5DCULL;
}

// FDE #2711 | PC: 0x08e5e4..0x08e5f0 (12 B) | Symbol: sub_08e5e4
// EN: AArch64 prologue [mov x0, x21; mov x1, x20; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x20; ret]
uint64_t fde_sub_08e5e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E5E4ULL;
}

// FDE #2712 | PC: 0x08e5f0..0x08e5fc (12 B) | Symbol: sub_08e5f0
// EN: AArch64 prologue [ldr x27, [x26, #8]; cmp x23, #1; ret] | VI: Khởi đầu hàm AArch64 [ldr x27, [x26, #8]; cmp x23, #1; ret]
uint64_t fde_sub_08e5f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF10006FFULL) << 32) | 0xF940075BULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E5F0ULL;
}

// FDE #2713 | PC: 0x08e5fc..0x08e61c (32 B) | Symbol: sub_08e5fc
// EN: AArch64 prologue [ldr x9, [x19]; ldp q1, q0, [x9, #0x20]; ldp q3, q2, [x9]; stur q0, [x8, #0x38]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x19]; ldp q1, q0, [x9, #0x20]; ldp q3, q2, [x9]; stur q0, [x8, #0x38]]
uint64_t fde_sub_08e5fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAD410121ULL) << 32) | 0xF9400269ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E5FCULL;
}

// FDE #2714 | PC: 0x08e61c..0x08e628 (12 B) | Symbol: sub_08e61c
// EN: AArch64 prologue [mov x20, x1; lsr x8, x1, #0x3d; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x1; lsr x8, x1, #0x3d; ret]
uint64_t fde_sub_08e61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD37DFC28ULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E61CULL;
}

// FDE #2715 | PC: 0x08e628..0x08e630 (8 B) | Symbol: sub_08e628
// EN: AArch64 prologue [add x0, sp, #0x20; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; b #0x46c54]
uint64_t fde_sub_08e628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE18AULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E628ULL;
}

// FDE #2716 | PC: 0x08e630..0x08e638 (8 B) | Symbol: sub_08e630
// EN: AArch64 prologue [add sp, sp, #0xe0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0xe0; ret]
uint64_t fde_sub_08e630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910383FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E630ULL;
}

// FDE #2717 | PC: 0x08e638..0x08e650 (24 B) | Symbol: sub_08e638
// EN: AArch64 prologue [add x9, x8, #0x50; fmov d0, x8; mov v0.d[1], x9; add x0, x19, #0x30] | VI: Khởi đầu hàm AArch64 [add x9, x8, #0x50; fmov d0, x8; mov v0.d[1], x9; add x0, x19, #0x30]
uint64_t fde_sub_08e638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E670100ULL) << 32) | 0x91014109ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E638ULL;
}

// FDE #2718 | PC: 0x08e650..0x08e66c (28 B) | Symbol: sub_08e650
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; str q0, [sp, #0x100]; str x8, [sp, #0x110]; bl #0x47ff4] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; str q0, [sp, #0x100]; str x8, [sp, #0x110]; bl #0x47ff4]
uint64_t fde_sub_08e650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D8043E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E650ULL;
}

// FDE #2719 | PC: 0x08e66c..0x08e684 (24 B) | Symbol: sub_08e66c
// EN: AArch64 prologue [mov x2, x0; mov x0, x19; mov x1, x20; mov x3, x21] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x19; mov x1, x20; mov x3, x21]
uint64_t fde_sub_08e66c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E66CULL;
}

// FDE #2720 | PC: 0x08e684..0x08e68c (8 B) | Symbol: sub_08e684
// EN: AArch64 prologue [mov x1, x24; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x24; b #0x93910]
uint64_t fde_sub_08e684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140014A2ULL) << 32) | 0xAA1803E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E684ULL;
}

// FDE #2721 | PC: 0x08e68c..0x08e6a4 (24 B) | Symbol: sub_08e68c
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; add x1, x0, #0x28; add x0, sp, #8] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; add x1, x0, #0x28; add x0, sp, #8]
uint64_t fde_sub_08e68c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E68CULL;
}

// FDE #2722 | PC: 0x08e6a4..0x08e6bc (24 B) | Symbol: sub_08e6a4
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x180]; ldp x23, x22, [sp, #0x170]; ldp x25, x24, [sp, #0x160]; ldr x28, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x180]; ldp x23, x22, [sp, #0x170]; ldp x25, x24, [sp, #0x160]; ldr x28, [sp, #0x150]]
uint64_t fde_sub_08e6a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9575BF7ULL) << 32) | 0xA95853F5ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E6A4ULL;
}

// FDE #2723 | PC: 0x08e6bc..0x08e6c8 (12 B) | Symbol: sub_08e6bc
// EN: AArch64 prologue [mov x0, x22; mov x1, x20; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x20; ret]
uint64_t fde_sub_08e6bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E6BCULL;
}

// FDE #2724 | PC: 0x08e6c8..0x08e6d4 (12 B) | Symbol: sub_08e6c8
// EN: AArch64 prologue [cmp w8, #0; cset w0, eq; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; cset w0, eq; ret]
uint64_t fde_sub_08e6c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E0ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E6C8ULL;
}

// FDE #2725 | PC: 0x08e6d4..0x08e6ec (24 B) | Symbol: sub_08e6d4
// EN: AArch64 prologue [cmp w8, #0; mov w8, #0x60; csel x8, x8, x9, eq; ldr s0, [x0, x8]] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; mov w8, #0x60; csel x8, x8, x9, eq; ldr s0, [x0, x8]]
uint64_t fde_sub_08e6d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800C08ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E6D4ULL;
}

// FDE #2726 | PC: 0x08e6ec..0x08e720 (52 B) | Symbol: sub_08e6ec
// EN: AArch64 prologue [ldrb w11, [x20, #0x1c]; ldr x9, [x19, #8]; cmp w8, #0; mov w8, #0x10] | VI: Khởi đầu hàm AArch64 [ldrb w11, [x20, #0x1c]; ldr x9, [x19, #8]; cmp w8, #0; mov w8, #0x10]
uint64_t fde_sub_08e6ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400669ULL) << 32) | 0x3940728BULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E6ECULL;
}

// FDE #2727 | PC: 0x08e720..0x08e728 (8 B) | Symbol: sub_08e720
// EN: AArch64 prologue [ldr x20, [sp], #0x20; b #0x932e0] | VI: Khởi đầu hàm AArch64 [ldr x20, [sp], #0x20; b #0x932e0]
uint64_t fde_sub_08e720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140012EFULL) << 32) | 0xF84207F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E720ULL;
}

// FDE #2728 | PC: 0x08e728..0x08e734 (12 B) | Symbol: sub_08e728
// EN: AArch64 prologue [mov w2, #1; mov x0, x20; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x20; b #0x93c30]
uint64_t fde_sub_08e728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E728ULL;
}

// FDE #2729 | PC: 0x08e734..0x08e74c (24 B) | Symbol: sub_08e734
// EN: AArch64 prologue [ldr x8, [x1, #0x18]; ldur q0, [x1, #8]; add x0, x1, #8; str x8, [x20, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0x18]; ldur q0, [x1, #8]; add x0, x1, #8; str x8, [x20, #0x18]]
uint64_t fde_sub_08e734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3CC08020ULL) << 32) | 0xF9400C28ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E734ULL;
}

// FDE #2730 | PC: 0x08e74c..0x08e764 (24 B) | Symbol: sub_08e74c
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x30]; ldp x23, x22, [sp, #0x20]; ldr x24, [sp, #0x18]; ldr d8, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x30]; ldp x23, x22, [sp, #0x20]; ldr x24, [sp, #0x18]; ldr d8, [sp, #0x10]]
uint64_t fde_sub_08e74c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9425BF7ULL) << 32) | 0xA94353F5ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E74CULL;
}

// FDE #2731 | PC: 0x08e764..0x08e770 (12 B) | Symbol: sub_08e764
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #0x80]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #0x80]; br x8]
uint64_t fde_sub_08e764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E764ULL;
}

// FDE #2732 | PC: 0x08e770..0x08e77c (12 B) | Symbol: sub_08e770
// EN: AArch64 prologue [ldr x8, [x0]; ldr x1, [x8, #0x10]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x1, [x8, #0x10]; br x1]
uint64_t fde_sub_08e770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400901ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E770ULL;
}

// FDE #2733 | PC: 0x08e77c..0x08e788 (12 B) | Symbol: sub_08e77c
// EN: AArch64 prologue [add x0, x20, #0x18; mov x19, x20; b #0x6d070] | VI: Khởi đầu hàm AArch64 [add x0, x20, #0x18; mov x19, x20; b #0x6d070]
uint64_t fde_sub_08e77c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403F3ULL) << 32) | 0x91006280ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E77CULL;
}

// FDE #2734 | PC: 0x08e788..0x08e794 (12 B) | Symbol: sub_08e788
// EN: AArch64 prologue [mrs x24, tpidr_el0; ldr x8, [x24, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x24, tpidr_el0; ldr x8, [x24, #0x28]; ret]
uint64_t fde_sub_08e788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401708ULL) << 32) | 0xD53BD058ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E788ULL;
}

// FDE #2735 | PC: 0x08e794..0x08e7a0 (12 B) | Symbol: sub_08e794
// EN: AArch64 prologue [mov x0, x21; mov x1, x22; b #0x4722c] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x22; b #0x4722c]
uint64_t fde_sub_08e794(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E794ULL;
}

// FDE #2736 | PC: 0x08e7a0..0x08e7ac (12 B) | Symbol: sub_08e7a0
// EN: AArch64 prologue [mov x20, x0; mov x19, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x0; mov x19, x1; ret]
uint64_t fde_sub_08e7a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F3ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E7A0ULL;
}

// FDE #2737 | PC: 0x08e7ac..0x08e7b8 (12 B) | Symbol: sub_08e7ac
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0, #0x28]; ret]
uint64_t fde_sub_08e7ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401400ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E7ACULL;
}

// FDE #2738 | PC: 0x08e7b8..0x08e7d4 (28 B) | Symbol: sub_08e7b8
// EN: AArch64 prologue [fmov d0, x24; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w25, s0] | VI: Khởi đầu hàm AArch64 [fmov d0, x24; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w25, s0]
uint64_t fde_sub_08e7b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0E205800ULL) << 32) | 0x9E670300ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E7B8ULL;
}

// FDE #2739 | PC: 0x08e7d4..0x08e7dc (8 B) | Symbol: sub_08e7d4
// EN: AArch64 prologue [add sp, sp, #0x110; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x110; ret]
uint64_t fde_sub_08e7d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910443FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E7D4ULL;
}

// FDE #2740 | PC: 0x08e7dc..0x08e804 (40 B) | Symbol: sub_08e7dc
// EN: AArch64 prologue [str wzr, [sp, #0xe0]; ldr w8, [x27, #0x18]; add x0, sp, #0xf8; add x2, sp, #0xf0] | VI: Khởi đầu hàm AArch64 [str wzr, [sp, #0xe0]; ldr w8, [x27, #0x18]; add x0, sp, #0xf8; add x2, sp, #0xf0]
uint64_t fde_sub_08e7dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401B68ULL) << 32) | 0xB900E3FFULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E7DCULL;
}

// FDE #2741 | PC: 0x08e804..0x08e814 (16 B) | Symbol: sub_08e804
// EN: AArch64 prologue [ldr x0, [x19, #0xd8]; add x1, sp, #0x78; add x2, sp, #0x58; b #0x78df0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0xd8]; add x1, sp, #0x78; add x2, sp, #0x58; b #0x78df0]
uint64_t fde_sub_08e804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9101E3E1ULL) << 32) | 0xF9406E60ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E804ULL;
}

// FDE #2742 | PC: 0x08e814..0x08e83c (40 B) | Symbol: sub_08e814
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x1, x2; mov v8.16b, v0.16b] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x1, x2; mov v8.16b, v0.16b]
uint64_t fde_sub_08e814(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E814ULL;
}

// FDE #2743 | PC: 0x08e83c..0x08e864 (40 B) | Symbol: sub_08e83c
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x20, x0; add x0, sp, #0x40] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x20, x0; add x0, sp, #0x40]
uint64_t fde_sub_08e83c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E83CULL;
}

// FDE #2744 | PC: 0x08e864..0x08e870 (12 B) | Symbol: sub_08e864
// EN: AArch64 prologue [ldr x9, [sp, #0x78]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x78]; cmp x8, x9; ret]
uint64_t fde_sub_08e864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9403FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E864ULL;
}

// FDE #2745 | PC: 0x08e870..0x08e88c (28 B) | Symbol: sub_08e870
// EN: AArch64 prologue [fmov d0, x23; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w21, s0] | VI: Khởi đầu hàm AArch64 [fmov d0, x23; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w21, s0]
uint64_t fde_sub_08e870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0E205800ULL) << 32) | 0x9E6702E0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E870ULL;
}

// FDE #2746 | PC: 0x08e88c..0x08e89c (16 B) | Symbol: sub_08e88c
// EN: AArch64 prologue [ldp x20, x21, [x19]; stp x8, x9, [x19]; str x10, [x19, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x21, [x19]; stp x8, x9, [x19]; str x10, [x19, #0x10]; ret]
uint64_t fde_sub_08e88c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9002668ULL) << 32) | 0xA9405674ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E88CULL;
}

// FDE #2747 | PC: 0x08e89c..0x08e8b8 (28 B) | Symbol: sub_08e89c
// EN: AArch64 prologue [add x9, x8, #0x50; fmov d0, x8; mov x19, x0; add x20, x0, #8] | VI: Khởi đầu hàm AArch64 [add x9, x8, #0x50; fmov d0, x8; mov x19, x0; add x20, x0, #8]
uint64_t fde_sub_08e89c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E670100ULL) << 32) | 0x91014109ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E89CULL;
}

// FDE #2748 | PC: 0x08e8b8..0x08e8e8 (48 B) | Symbol: sub_08e8b8
// EN: AArch64 prologue [cmp x25, #3; sub x8, x25, #1; cset w9, lo; tst x25, x8] | VI: Khởi đầu hàm AArch64 [cmp x25, #3; sub x8, x25, #1; cset w9, lo; tst x25, x8]
uint64_t fde_sub_08e8b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1000728ULL) << 32) | 0xF1000F3FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E8B8ULL;
}

// FDE #2749 | PC: 0x08e8e8..0x08e904 (28 B) | Symbol: sub_08e8e8
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_08e8e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E8E8ULL;
}

// FDE #2750 | PC: 0x08e904..0x08e914 (16 B) | Symbol: sub_08e904
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xdc8; add x0, sp, #0x78; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xdc8; add x0, sp, #0x78; ret]
uint64_t fde_sub_08e904(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91372021ULL) << 32) | 0xD0FFFC61ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E904ULL;
}

// FDE #2751 | PC: 0x08e914..0x08e934 (32 B) | Symbol: sub_08e914
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x4aaf4; add x0, x20, #0x20; bl #0x4aaf4] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x4aaf4; add x0, x20, #0x20; bl #0x4aaf4]
uint64_t fde_sub_08e914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEF077ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E914ULL;
}

// FDE #2752 | PC: 0x08e934..0x08e940 (12 B) | Symbol: sub_08e934
// EN: AArch64 prologue [str xzr, [x8, #8]!; str x9, [x0]; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [x8, #8]!; str x9, [x0]; ret]
uint64_t fde_sub_08e934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000009ULL) << 32) | 0xF8008D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E934ULL;
}

// FDE #2753 | PC: 0x08e940..0x08e948 (8 B) | Symbol: sub_08e940
// EN: AArch64 prologue [add x0, sp, #0x10; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x10; b #0x937a0]
uint64_t fde_sub_08e940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001397ULL) << 32) | 0x910043E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E940ULL;
}

// FDE #2754 | PC: 0x08e948..0x08e958 (16 B) | Symbol: sub_08e948
// EN: AArch64 prologue [mov x2, x0; mov x0, x21; mov x1, x20; b #0x7ce48] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x21; mov x1, x20; b #0x7ce48]
uint64_t fde_sub_08e948(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E948ULL;
}

// FDE #2755 | PC: 0x08e958..0x08e968 (16 B) | Symbol: sub_08e958
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; mov x1, x21; b #0x7ce48] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; mov x1, x21; b #0x7ce48]
uint64_t fde_sub_08e958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E958ULL;
}

// FDE #2756 | PC: 0x08e968..0x08e978 (16 B) | Symbol: sub_08e968
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; mov x1, x19; b #0x7d6e4] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; mov x1, x19; b #0x7d6e4]
uint64_t fde_sub_08e968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E968ULL;
}

// FDE #2757 | PC: 0x08e978..0x08e988 (16 B) | Symbol: sub_08e978
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; mov x1, x19; b #0x830f8] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; mov x1, x19; b #0x830f8]
uint64_t fde_sub_08e978(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E978ULL;
}

// FDE #2758 | PC: 0x08e988..0x08e990 (8 B) | Symbol: sub_08e988
// EN: AArch64 prologue [mov x1, x21; b #0x47f90] | VI: Khởi đầu hàm AArch64 [mov x1, x21; b #0x47f90]
uint64_t fde_sub_08e988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE581ULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E988ULL;
}

// FDE #2759 | PC: 0x08e990..0x08e99c (12 B) | Symbol: sub_08e990
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; ret]
uint64_t fde_sub_08e990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E990ULL;
}

// FDE #2760 | PC: 0x08e99c..0x08e9a4 (8 B) | Symbol: sub_08e99c
// EN: AArch64 prologue [ldr x8, [x8, #0x20]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x20]; br x8]
uint64_t fde_sub_08e99c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9401108ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E99CULL;
}

// FDE #2761 | PC: 0x08e9a4..0x08e9ac (8 B) | Symbol: sub_08e9a4
// EN: AArch64 prologue [mov w1, wzr; b #0x44dac] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; b #0x44dac]
uint64_t fde_sub_08e9a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED901ULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E9A4ULL;
}

// FDE #2762 | PC: 0x08e9ac..0x08e9d4 (40 B) | Symbol: sub_08e9ac
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x80]; ldp x22, x21, [sp, #0x70]; ldp x24, x23, [sp, #0x60]; ldp x26, x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x80]; ldp x22, x21, [sp, #0x70]; ldp x24, x23, [sp, #0x60]; ldp x26, x25, [sp, #0x50]]
uint64_t fde_sub_08e9ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94757F6ULL) << 32) | 0xA9484FF4ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E9ACULL;
}

// FDE #2763 | PC: 0x08e9d4..0x08e9f0 (28 B) | Symbol: sub_08e9d4
// EN: AArch64 prologue [ldr w8, [x0, #8]; ldrb w9, [x0, #0xc]; fmov d1, xzr; scvtf d0, w8] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #8]; ldrb w9, [x0, #0xc]; fmov d1, xzr; scvtf d0, w8]
uint64_t fde_sub_08e9d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39403009ULL) << 32) | 0xB9400808ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E9D4ULL;
}

// FDE #2764 | PC: 0x08e9f0..0x08e9fc (12 B) | Symbol: sub_08e9f0
// EN: AArch64 prologue [mov x0, x20; mov x1, x21; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x21; ret]
uint64_t fde_sub_08e9f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E9F0ULL;
}

// FDE #2765 | PC: 0x08e9fc..0x08ea0c (16 B) | Symbol: sub_08e9fc
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xc99; add x0, sp, #0x290; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xc99; add x0, sp, #0x290; ret]
uint64_t fde_sub_08e9fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91326421ULL) << 32) | 0xD0FFFC61ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E9FCULL;
}

// FDE #2766 | PC: 0x08ea0c..0x08ea14 (8 B) | Symbol: sub_08ea0c
// EN: AArch64 prologue [mov x2, x21; b #0x931f0] | VI: Khởi đầu hàm AArch64 [mov x2, x21; b #0x931f0]
uint64_t fde_sub_08ea0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140011F8ULL) << 32) | 0xAA1503E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA0CULL;
}

// FDE #2767 | PC: 0x08ea14..0x08ea1c (8 B) | Symbol: sub_08ea14
// EN: AArch64 prologue [mov x0, x22; b #0x93cc0] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x93cc0]
uint64_t fde_sub_08ea14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140014AAULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA14ULL;
}

// FDE #2768 | PC: 0x08ea1c..0x08ea2c (16 B) | Symbol: sub_08ea1c
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x19, x0; ret]
uint64_t fde_sub_08ea1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA1CULL;
}

// FDE #2769 | PC: 0x08ea2c..0x08ea3c (16 B) | Symbol: sub_08ea2c
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x20, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x20, x0; ret]
uint64_t fde_sub_08ea2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA2CULL;
}

// FDE #2770 | PC: 0x08ea3c..0x08ea48 (12 B) | Symbol: sub_08ea3c
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; ldr s0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; ldr s0, [x0, #8]; ret]
uint64_t fde_sub_08ea3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD400800ULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA3CULL;
}

// FDE #2771 | PC: 0x08ea48..0x08ea58 (16 B) | Symbol: sub_08ea48
// EN: AArch64 prologue [mov w0, #0x18; ld1 {v0.d}[1], [x8]; str q0, [sp]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x18; ld1 {v0.d}[1], [x8]; str q0, [sp]; b #0x93320]
uint64_t fde_sub_08ea48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4D408500ULL) << 32) | 0x52800300ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA48ULL;
}

// FDE #2772 | PC: 0x08ea58..0x08ea98 (64 B) | Symbol: sub_08ea58
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x1, #0x10]; ldr q0, [x1]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x1, #0x10]; ldr q0, [x1]; mov x20, x0]
uint64_t fde_sub_08ea58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400828ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA58ULL;
}

// FDE #2773 | PC: 0x08ea98..0x08eaa0 (8 B) | Symbol: sub_08ea98
// EN: AArch64 prologue [mov x1, x22; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x22; b #0x93910]
uint64_t fde_sub_08ea98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400139DULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA98ULL;
}

// FDE #2774 | PC: 0x08eaa0..0x08eaac (12 B) | Symbol: sub_08eaa0
// EN: AArch64 prologue [ldr x8, [x0]; ldr x1, [x8, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x1, [x8, #8]; ret]
uint64_t fde_sub_08eaa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400501ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAA0ULL;
}

// FDE #2775 | PC: 0x08eaac..0x08eab8 (12 B) | Symbol: sub_08eaac
// EN: AArch64 prologue [ldr x9, [sp, #0xc8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0xc8]; cmp x8, x9; ret]
uint64_t fde_sub_08eaac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94067E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAACULL;
}

// FDE #2776 | PC: 0x08eab8..0x08eac4 (12 B) | Symbol: sub_08eab8
// EN: AArch64 prologue [mov x1, sp; mov x0, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x19; ret]
uint64_t fde_sub_08eab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAB8ULL;
}

// FDE #2777 | PC: 0x08eac4..0x08eaec (40 B) | Symbol: sub_08eac4
// EN: AArch64 prologue [add x8, x0, x22, lsl #3; add x9, x0, x21, lsl #3; str x9, [sp, #0x20]; stp x0, x8, [sp, #8]] | VI: Khởi đầu hàm AArch64 [add x8, x0, x22, lsl #3; add x9, x0, x21, lsl #3; str x9, [sp, #0x20]; stp x0, x8, [sp, #8]]
uint64_t fde_sub_08eac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B150C09ULL) << 32) | 0x8B160C08ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAC4ULL;
}

// FDE #2778 | PC: 0x08eaec..0x08eaf8 (12 B) | Symbol: sub_08eaec
// EN: AArch64 prologue [mov x20, x1; mov x21, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x1; mov x21, x0; ret]
uint64_t fde_sub_08eaec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAECULL;
}

// FDE #2779 | PC: 0x08eaf8..0x08eb14 (28 B) | Symbol: sub_08eaf8
// EN: AArch64 prologue [mov x21, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18] | VI: Khởi đầu hàm AArch64 [mov x21, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18]
uint64_t fde_sub_08eaf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xAA0003F5ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAF8ULL;
}

// FDE #2780 | PC: 0x08eb14..0x08eb24 (16 B) | Symbol: sub_08eb14
// EN: AArch64 prologue [mov x20, x0; mov x0, x1; mov x19, x1; b #0x93440] | VI: Khởi đầu hàm AArch64 [mov x20, x0; mov x0, x1; mov x19, x1; b #0x93440]
uint64_t fde_sub_08eb14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB14ULL;
}

// FDE #2781 | PC: 0x08eb24..0x08eb34 (16 B) | Symbol: sub_08eb24
// EN: AArch64 prologue [mov x8, x0; mov x0, x19; mov x1, x8; b #0x93700] | VI: Khởi đầu hàm AArch64 [mov x8, x0; mov x0, x19; mov x1, x8; b #0x93700]
uint64_t fde_sub_08eb24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB24ULL;
}

// FDE #2782 | PC: 0x08eb34..0x08eb44 (16 B) | Symbol: sub_08eb34
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldr x28, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldr x28, [sp], #0x40; ret]
uint64_t fde_sub_08eb34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9415BF7ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB34ULL;
}

// FDE #2783 | PC: 0x08eb44..0x08eb4c (8 B) | Symbol: sub_08eb44
// EN: AArch64 prologue [add x0, sp, #0xf0; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xf0; b #0x46c54]
uint64_t fde_sub_08eb44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE043ULL) << 32) | 0x9103C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB44ULL;
}

// FDE #2784 | PC: 0x08eb4c..0x08eb5c (16 B) | Symbol: sub_08eb4c
// EN: AArch64 prologue [mov x0, sp; mov x1, x21; mov x20, sp; b #0x77b60] | VI: Khởi đầu hàm AArch64 [mov x0, sp; mov x1, x21; mov x20, sp; b #0x77b60]
uint64_t fde_sub_08eb4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB4CULL;
}

// FDE #2785 | PC: 0x08eb5c..0x08eb64 (8 B) | Symbol: sub_08eb5c
// EN: AArch64 prologue [mov x0, x19; b #0x6ab64] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x6ab64]
uint64_t fde_sub_08eb5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF7001ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB5CULL;
}

// FDE #2786 | PC: 0x08eb64..0x08eb6c (8 B) | Symbol: sub_08eb64
// EN: AArch64 prologue [mov x0, x19; b #0x93cc0] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x93cc0]
uint64_t fde_sub_08eb64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001456ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB64ULL;
}

// FDE #2787 | PC: 0x08eb6c..0x08eb7c (16 B) | Symbol: sub_08eb6c
// EN: AArch64 prologue [ldr x8, [x19]; mov x0, x19; ldr x1, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; mov x0, x19; ldr x1, [x8, #0x10]; ret]
uint64_t fde_sub_08eb6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB6CULL;
}

// FDE #2788 | PC: 0x08eb7c..0x08eb88 (12 B) | Symbol: sub_08eb7c
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0, #0x30]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0, #0x30]; ret]
uint64_t fde_sub_08eb7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401800ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB7CULL;
}

// FDE #2789 | PC: 0x08eb88..0x08eba4 (28 B) | Symbol: sub_08eb88
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x10]; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x10]; bl #0x48d40]
uint64_t fde_sub_08eb88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB88ULL;
}

// FDE #2790 | PC: 0x08eba4..0x08ebb4 (16 B) | Symbol: sub_08eba4
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; ret]
uint64_t fde_sub_08eba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBA4ULL;
}

// FDE #2791 | PC: 0x08ebb4..0x08ebc8 (20 B) | Symbol: sub_08ebb4
// EN: AArch64 prologue [ldp x21, x20, [sp, #0xb0]; ldp x23, x22, [sp, #0xa0]; ldr x24, [sp, #0x90]; add sp, sp, #0xd0] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0xb0]; ldp x23, x22, [sp, #0xa0]; ldr x24, [sp, #0x90]; add sp, sp, #0xd0]
uint64_t fde_sub_08ebb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94A5BF7ULL) << 32) | 0xA94B53F5ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBB4ULL;
}

// FDE #2792 | PC: 0x08ebc8..0x08ebd0 (8 B) | Symbol: sub_08ebc8
// EN: AArch64 prologue [add x0, sp, #0x68; b #0x5067c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x68; b #0x5067c]
uint64_t fde_sub_08ebc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF06ACULL) << 32) | 0x9101A3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBC8ULL;
}

// FDE #2793 | PC: 0x08ebd0..0x08ebdc (12 B) | Symbol: sub_08ebd0
// EN: AArch64 prologue [add x0, sp, #0x40; add x1, sp, #0x18; b #0x4bf3c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x40; add x1, sp, #0x18; b #0x4bf3c]
uint64_t fde_sub_08ebd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910063E1ULL) << 32) | 0x910103E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBD0ULL;
}

// FDE #2794 | PC: 0x08ebdc..0x08ebe4 (8 B) | Symbol: sub_08ebdc
// EN: AArch64 prologue [lsl x0, x22, #3; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsl x0, x22, #3; b #0x93320]
uint64_t fde_sub_08ebdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140011D0ULL) << 32) | 0xD37DF2C0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBDCULL;
}

// FDE #2795 | PC: 0x08ebe4..0x08ebec (8 B) | Symbol: sub_08ebe4
// EN: AArch64 prologue [add x1, sp, #0x68; b #0x507d8] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x68; b #0x507d8]
uint64_t fde_sub_08ebe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF06FCULL) << 32) | 0x9101A3E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBE4ULL;
}

// FDE #2796 | PC: 0x08ebec..0x08ec00 (20 B) | Symbol: sub_08ebec
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x46c54; mov x0, x19; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x46c54; mov x0, x19; ldr x30, [sp], #0x10]
uint64_t fde_sub_08ebec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEE019ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBECULL;
}

// FDE #2797 | PC: 0x08ec00..0x08ec08 (8 B) | Symbol: sub_08ec00
// EN: AArch64 prologue [mov x1, x23; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x23; b #0x93910]
uint64_t fde_sub_08ec00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001343ULL) << 32) | 0xAA1703E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC00ULL;
}

// FDE #2798 | PC: 0x08ec08..0x08ec34 (44 B) | Symbol: sub_08ec08
// EN: AArch64 prologue [str x8, [sp, #0x10]; str q0, [sp]; ldr x8, [x19, #0x10]; ldr q0, [x19]] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x10]; str q0, [sp]; ldr x8, [x19, #0x10]; ldr q0, [x19]]
uint64_t fde_sub_08ec08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D8003E0ULL) << 32) | 0xF9000BE8ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC08ULL;
}

// FDE #2799 | PC: 0x08ec34..0x08ec60 (44 B) | Symbol: sub_08ec34
// EN: AArch64 prologue [cmp x25, #3; sub x8, x25, #1; cset w9, lo; tst x25, x8] | VI: Khởi đầu hàm AArch64 [cmp x25, #3; sub x8, x25, #1; cset w9, lo; tst x25, x8]
uint64_t fde_sub_08ec34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1000728ULL) << 32) | 0xF1000F3FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC34ULL;
}

// FDE #2800 | PC: 0x08ec60..0x08ec6c (12 B) | Symbol: sub_08ec60
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x10]; add sp, sp, #0x30; b #0x44830] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x10]; add sp, sp, #0x30; b #0x44830]
uint64_t fde_sub_08ec60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C3FFULL) << 32) | 0xA94153F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC60ULL;
}

// FDE #2801 | PC: 0x08ec6c..0x08ec80 (20 B) | Symbol: sub_08ec6c
// EN: AArch64 prologue [ldr q0, [sp, #0x10]; add x1, sp, #0x20; mov x22, x0; str q0, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr q0, [sp, #0x10]; add x1, sp, #0x20; mov x22, x0; str q0, [sp, #0x20]]
uint64_t fde_sub_08ec6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910083E1ULL) << 32) | 0x3DC007E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC6CULL;
}

// FDE #2802 | PC: 0x08ec80..0x08ec8c (12 B) | Symbol: sub_08ec80
// EN: AArch64 prologue [ldr x8, [x20]; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20]; mov x0, x20; ret]
uint64_t fde_sub_08ec80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xF9400288ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC80ULL;
}

// FDE #2803 | PC: 0x08ec8c..0x08ec98 (12 B) | Symbol: sub_08ec8c
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; b #0x93c40] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; b #0x93c40]
uint64_t fde_sub_08ec8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC8CULL;
}

// FDE #2804 | PC: 0x08ec98..0x08eca4 (12 B) | Symbol: sub_08ec98
// EN: AArch64 prologue [mov w0, #0x20; strb w22, [sp, #0x20]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; strb w22, [sp, #0x20]; b #0x93320]
uint64_t fde_sub_08ec98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x390083F6ULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC98ULL;
}

// FDE #2805 | PC: 0x08eca4..0x08ecb0 (12 B) | Symbol: sub_08eca4
// EN: AArch64 prologue [add x8, x8, #1; str x8, [x19, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [add x8, x8, #1; str x8, [x19, #0x18]; ret]
uint64_t fde_sub_08eca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000E68ULL) << 32) | 0x91000508ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ECA4ULL;
}

// FDE #2806 | PC: 0x08ecb0..0x08ecb8 (8 B) | Symbol: sub_08ecb0
// EN: AArch64 prologue [add x20, sp, #8; b #0x46964] | VI: Khởi đầu hàm AArch64 [add x20, sp, #8; b #0x46964]
uint64_t fde_sub_08ecb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDF2CULL) << 32) | 0x910023F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ECB0ULL;
}

// FDE #2807 | PC: 0x08ecb8..0x08eccc (20 B) | Symbol: sub_08ecb8
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x0; add x1, x0, #8] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x0; add x1, x0, #8]
uint64_t fde_sub_08ecb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ECB8ULL;
}

// FDE #2808 | PC: 0x08eccc..0x08ece0 (20 B) | Symbol: sub_08eccc
// EN: AArch64 prologue [ldur q0, [x9, #0x14]; ldur q1, [x9, #8]; stur q0, [x8, #0xc]; str q1, [x8]] | VI: Khởi đầu hàm AArch64 [ldur q0, [x9, #0x14]; ldur q1, [x9, #8]; stur q0, [x8, #0xc]; str q1, [x8]]
uint64_t fde_sub_08eccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3CC08121ULL) << 32) | 0x3CC14120ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ECCCULL;
}

// FDE #2809 | PC: 0x08ece0..0x08ece8 (8 B) | Symbol: sub_08ece0
// EN: AArch64 prologue [add sp, sp, #0x1a0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x1a0; ret]
uint64_t fde_sub_08ece0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910683FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ECE0ULL;
}

// FDE #2810 | PC: 0x08ece8..0x08ed0c (36 B) | Symbol: sub_08ece8
// EN: AArch64 prologue [stp xzr, xzr, [sp, #0x40]; str xzr, [sp, #0x38]; ldr x8, [x19]; add x3, sp, #0x48] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [sp, #0x40]; str xzr, [sp, #0x38]; ldr x8, [x19]; add x3, sp, #0x48]
uint64_t fde_sub_08ece8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001FFFULL) << 32) | 0xA9047FFFULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ECE8ULL;
}

// FDE #2811 | PC: 0x08ed0c..0x08ed18 (12 B) | Symbol: sub_08ed0c
// EN: AArch64 prologue [ldr x8, [x21]; mov x0, x21; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21]; mov x0, x21; ret]
uint64_t fde_sub_08ed0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xF94002A8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED0CULL;
}

// FDE #2812 | PC: 0x08ed18..0x08ed24 (12 B) | Symbol: sub_08ed18
// EN: AArch64 prologue [mov x0, x20; ldp x21, x20, [sp], #0x20; b #0x5b144] | VI: Khởi đầu hàm AArch64 [mov x0, x20; ldp x21, x20, [sp], #0x20; b #0x5b144]
uint64_t fde_sub_08ed18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA8C253F5ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED18ULL;
}

// FDE #2813 | PC: 0x08ed24..0x08ed30 (12 B) | Symbol: sub_08ed24
// EN: AArch64 prologue [mov x0, x20; mov v8.16b, v0.16b; b #0x93cc0] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov v8.16b, v0.16b; b #0x93cc0]
uint64_t fde_sub_08ed24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA01C08ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED24ULL;
}

// FDE #2814 | PC: 0x08ed30..0x08ed3c (12 B) | Symbol: sub_08ed30
// EN: AArch64 prologue [add x0, sp, #0x18; ucvtf d8, w8; b #0x497b4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x18; ucvtf d8, w8; b #0x497b4]
uint64_t fde_sub_08ed30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E630108ULL) << 32) | 0x910063E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED30ULL;
}

// FDE #2815 | PC: 0x08ed3c..0x08ed44 (8 B) | Symbol: sub_08ed3c
// EN: AArch64 prologue [add x21, sp, #8; b #0x46964] | VI: Khởi đầu hàm AArch64 [add x21, sp, #8; b #0x46964]
uint64_t fde_sub_08ed3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDF09ULL) << 32) | 0x910023F5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED3CULL;
}

// FDE #2816 | PC: 0x08ed44..0x08ed4c (8 B) | Symbol: sub_08ed44
// EN: AArch64 prologue [ldr x8, [x8, #0x80]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x80]; br x8]
uint64_t fde_sub_08ed44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9404108ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED44ULL;
}

// FDE #2817 | PC: 0x08ed4c..0x08ed58 (12 B) | Symbol: sub_08ed4c
// EN: AArch64 prologue [mov x0, x22; mov x1, x23; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x23; ret]
uint64_t fde_sub_08ed4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED4CULL;
}

// FDE #2818 | PC: 0x08ed58..0x08ed6c (20 B) | Symbol: sub_08ed58
// EN: AArch64 prologue [cmp w8, #0; mov w8, #0x20; csel x9, x8, x9, eq; cmp w10, #0] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; mov w8, #0x20; csel x9, x8, x9, eq; cmp w10, #0]
uint64_t fde_sub_08ed58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800408ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED58ULL;
}

// FDE #2819 | PC: 0x08ed6c..0x08ed78 (12 B) | Symbol: sub_08ed6c
// EN: AArch64 prologue [ldr x0, [x19]; mov x1, x20; b #0x470b8] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19]; mov x1, x20; b #0x470b8]
uint64_t fde_sub_08ed6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xF9400260ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED6CULL;
}

// FDE #2820 | PC: 0x08ed78..0x08ed84 (12 B) | Symbol: sub_08ed78
// EN: AArch64 prologue [str x8, [x0]; stur q0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; stur q0, [x0, #8]; ret]
uint64_t fde_sub_08ed78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3C808000ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED78ULL;
}

// FDE #2821 | PC: 0x08ed84..0x08edb0 (44 B) | Symbol: sub_08ed84
// EN: AArch64 prologue [ldrb w8, [x20, #0xc]; ldrb w9, [x20, #0x14]; ldur x10, [x21, #-8]; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x20, #0xc]; ldrb w9, [x20, #0x14]; ldur x10, [x21, #-8]; cmp w8, #0]
uint64_t fde_sub_08ed84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39405289ULL) << 32) | 0x39403288ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED84ULL;
}

// FDE #2822 | PC: 0x08edb0..0x08eddc (44 B) | Symbol: sub_08edb0
// EN: AArch64 prologue [ldrb w8, [x20, #0xc]; ldrb w9, [x20, #0x14]; mov x1, x21; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x20, #0xc]; ldrb w9, [x20, #0x14]; mov x1, x21; cmp w8, #0]
uint64_t fde_sub_08edb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39405289ULL) << 32) | 0x39403288ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EDB0ULL;
}

// FDE #2823 | PC: 0x08eddc..0x08ede8 (12 B) | Symbol: sub_08eddc
// EN: AArch64 prologue [ldr d8, [sp, #0x10]; add sp, sp, #0x50; ret] | VI: Khởi đầu hàm AArch64 [ldr d8, [sp, #0x10]; add sp, sp, #0x50; ret]
uint64_t fde_sub_08eddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910143FFULL) << 32) | 0xFD400BE8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EDDCULL;
}

// FDE #2824 | PC: 0x08ede8..0x08edf0 (8 B) | Symbol: sub_08ede8
// EN: AArch64 prologue [mov x21, x1; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov x21, x1; b #0x93320]
uint64_t fde_sub_08ede8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400114DULL) << 32) | 0xAA0103F5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EDE8ULL;
}

// FDE #2825 | PC: 0x08edf0..0x08edfc (12 B) | Symbol: sub_08edf0
// EN: AArch64 prologue [add x1, x29, #0x10; mov x0, x20; b #0x4c4d4] | VI: Khởi đầu hàm AArch64 [add x1, x29, #0x10; mov x0, x20; b #0x4c4d4]
uint64_t fde_sub_08edf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910043A1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EDF0ULL;
}

// FDE #2826 | PC: 0x08edfc..0x08ee08 (12 B) | Symbol: sub_08edfc
// EN: AArch64 prologue [add x0, sp, #8; str x8, [sp, #0x38]; b #0x49124] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; str x8, [sp, #0x38]; b #0x49124]
uint64_t fde_sub_08edfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001FE8ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EDFCULL;
}

// FDE #2827 | PC: 0x08ee08..0x08ee14 (12 B) | Symbol: sub_08ee08
// EN: AArch64 prologue [mov x21, x0; add x0, sp, #0x10; b #0x93390] | VI: Khởi đầu hàm AArch64 [mov x21, x0; add x0, sp, #0x10; b #0x93390]
uint64_t fde_sub_08ee08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043E0ULL) << 32) | 0xAA0003F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EE08ULL;
}

// FDE #2828 | PC: 0x08ee14..0x08ee38 (36 B) | Symbol: sub_08ee14
// EN: AArch64 prologue [ldr x8, [x20, #8]; add x21, sp, #0x58; mov x19, x0; add x1, sp, #0x28] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20, #8]; add x21, sp, #0x58; mov x19, x0; add x1, sp, #0x28]
uint64_t fde_sub_08ee14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910163F5ULL) << 32) | 0xF9400688ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EE14ULL;
}

// FDE #2829 | PC: 0x08ee38..0x08ee40 (8 B) | Symbol: sub_08ee38
// EN: AArch64 prologue [mov x0, sp; b #0x46bdc] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x46bdc]
uint64_t fde_sub_08ee38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDF68ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EE38ULL;
}

// FDE #2830 | PC: 0x08ee40..0x08ee48 (8 B) | Symbol: sub_08ee40
// EN: AArch64 prologue [mov x0, x19; br x8] | VI: Khởi đầu hàm AArch64 [mov x0, x19; br x8]
uint64_t fde_sub_08ee40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EE40ULL;
}

// FDE #2831 | PC: 0x08ee48..0x08ee54 (12 B) | Symbol: sub_08ee48
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0, #0x18]; ret]
uint64_t fde_sub_08ee48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C00ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EE48ULL;
}

// FDE #2832 | PC: 0x08ee54..0x08ee78 (36 B) | Symbol: sub_08ee54
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; str x8, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; str x8, [sp, #0x28]]
uint64_t fde_sub_08ee54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EE54ULL;
}

// FDE #2833 | PC: 0x08ee78..0x08ee8c (20 B) | Symbol: sub_08ee78
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; str x8, [sp, #0x18]] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; str x8, [sp, #0x18]]
uint64_t fde_sub_08ee78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EE78ULL;
}

// FDE #2834 | PC: 0x08ee8c..0x08eeb4 (40 B) | Symbol: sub_08ee8c
// EN: AArch64 prologue [ldr x8, [x21, #0x48]; add x0, sp, #0x18; add x6, sp, #0x10; add x7, sp, #8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21, #0x48]; add x0, sp, #0x18; add x6, sp, #0x10; add x7, sp, #8]
uint64_t fde_sub_08ee8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910063E0ULL) << 32) | 0xF94026A8ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EE8CULL;
}

// FDE #2835 | PC: 0x08eeb4..0x08eed4 (32 B) | Symbol: sub_08eeb4
// EN: AArch64 prologue [mov w8, #3; str x0, [sp, #0x18]; mov x0, sp; add x1, sp, #8] | VI: Khởi đầu hàm AArch64 [mov w8, #3; str x0, [sp, #0x18]; mov x0, sp; add x1, sp, #8]
uint64_t fde_sub_08eeb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000FE0ULL) << 32) | 0x52800068ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EEB4ULL;
}

// FDE #2836 | PC: 0x08eed4..0x08eee4 (16 B) | Symbol: sub_08eed4
// EN: AArch64 prologue [ldr x8, [sp, #0x88]; add x28, x28, #0x30; ldr x8, [x8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp, #0x88]; add x28, x28, #0x30; ldr x8, [x8]; ret]
uint64_t fde_sub_08eed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C39CULL) << 32) | 0xF94047E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EED4ULL;
}

// FDE #2837 | PC: 0x08eee4..0x08eef0 (12 B) | Symbol: sub_08eee4
// EN: AArch64 prologue [sub x9, x9, x8; cmp x9, #0; ret] | VI: Khởi đầu hàm AArch64 [sub x9, x9, x8; cmp x9, #0; ret]
uint64_t fde_sub_08eee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100013FULL) << 32) | 0xCB080129ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EEE4ULL;
}

// FDE #2838 | PC: 0x08eef0..0x08ef00 (16 B) | Symbol: sub_08eef0
// EN: AArch64 prologue [ldr w16, [x12, #0x10]; ldr w17, [x15, #0x10]; cmp w16, w17; ret] | VI: Khởi đầu hàm AArch64 [ldr w16, [x12, #0x10]; ldr w17, [x15, #0x10]; cmp w16, w17; ret]
uint64_t fde_sub_08eef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94011F1ULL) << 32) | 0xB9401190ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EEF0ULL;
}

// FDE #2839 | PC: 0x08ef00..0x08ef10 (16 B) | Symbol: sub_08ef00
// EN: AArch64 prologue [ldr x14, [x19]; mov x15, x12; ldr x16, [x14, x13, lsl #3]; ret] | VI: Khởi đầu hàm AArch64 [ldr x14, [x19]; mov x15, x12; ldr x16, [x14, x13, lsl #3]; ret]
uint64_t fde_sub_08ef00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0C03EFULL) << 32) | 0xF940026EULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF00ULL;
}

// FDE #2840 | PC: 0x08ef10..0x08ef1c (12 B) | Symbol: sub_08ef10
// EN: AArch64 prologue [ldr x20, [x0, #0x10]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [ldr x20, [x0, #0x10]; mov x19, x0; ret]
uint64_t fde_sub_08ef10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF9400814ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF10ULL;
}

// FDE #2841 | PC: 0x08ef1c..0x08ef2c (16 B) | Symbol: sub_08ef1c
// EN: AArch64 prologue [ldr x12, [x19]; str x11, [x12, x10, lsl #3]; sub x11, x20, #1; ret] | VI: Khởi đầu hàm AArch64 [ldr x12, [x19]; str x11, [x12, x10, lsl #3]; sub x11, x20, #1; ret]
uint64_t fde_sub_08ef1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF82A798BULL) << 32) | 0xF940026CULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF1CULL;
}

// FDE #2842 | PC: 0x08ef2c..0x08ef44 (24 B) | Symbol: sub_08ef2c
// EN: AArch64 prologue [ldr x8, [x1]; str xzr, [x1]; add x1, sp, #8; str x8, [sp, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str xzr, [x1]; add x1, sp, #8; str x8, [sp, #8]]
uint64_t fde_sub_08ef2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900003FULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF2CULL;
}

// FDE #2843 | PC: 0x08ef44..0x08ef50 (12 B) | Symbol: sub_08ef44
// EN: AArch64 prologue [movi v0.2d, #0000000000000000; mov w8, #0x3f800000; ret] | VI: Khởi đầu hàm AArch64 [movi v0.2d, #0000000000000000; mov w8, #0x3f800000; ret]
uint64_t fde_sub_08ef44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52A7F008ULL) << 32) | 0x6F00E400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF44ULL;
}

// FDE #2844 | PC: 0x08ef50..0x08ef58 (8 B) | Symbol: sub_08ef50
// EN: AArch64 prologue [ldp x23, x22, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x23, x22, [sp], #0x30; ret]
uint64_t fde_sub_08ef50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xA8C35BF7ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF50ULL;
}

// FDE #2845 | PC: 0x08ef58..0x08ef90 (56 B) | Symbol: sub_08ef58
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x0, [sp, #0xc8]; bl #0x44830; mov x0, x24] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x0, [sp, #0xc8]; bl #0x44830; mov x0, x24]
uint64_t fde_sub_08ef58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94067E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF58ULL;
}

// FDE #2846 | PC: 0x08ef90..0x08efc8 (56 B) | Symbol: sub_08ef90
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x22, x0; add x0, x0, #0x10; mov x1, x20] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x22, x0; add x0, x0, #0x10; mov x1, x20]
uint64_t fde_sub_08ef90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F6ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF90ULL;
}

// FDE #2847 | PC: 0x08efc8..0x08efd8 (16 B) | Symbol: sub_08efc8
// EN: AArch64 prologue [ldr x0, [sp, #0x20]; str x23, [sp, #8]; str xzr, [sp, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x20]; str x23, [sp, #8]; str xzr, [sp, #0x20]; ret]
uint64_t fde_sub_08efc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007F7ULL) << 32) | 0xF94013E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EFC8ULL;
}

// FDE #2848 | PC: 0x08efd8..0x08eff0 (24 B) | Symbol: sub_08efd8
// EN: AArch64 prologue [mov x19, x1; ldr w8, [x1], #8; mov x20, x0; add x0, x0, #8] | VI: Khởi đầu hàm AArch64 [mov x19, x1; ldr w8, [x1], #8; mov x20, x0; add x0, x0, #8]
uint64_t fde_sub_08efd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8408428ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EFD8ULL;
}

// FDE #2849 | PC: 0x08eff0..0x08f000 (16 B) | Symbol: sub_08eff0
// EN: AArch64 prologue [ldr x9, [x8]; str x9, [x20]; str x20, [x8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [x8]; str x9, [x20]; str x20, [x8]; ret]
uint64_t fde_sub_08eff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000289ULL) << 32) | 0xF9400109ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EFF0ULL;
}

// FDE #2850 | PC: 0x08f000..0x08f018 (24 B) | Symbol: sub_08f000
// EN: AArch64 prologue [ldr x8, [x8]; ldp q0, q1, [x9, #0x20]; ldp q2, q3, [x9]; stp q0, q1, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8]; ldp q0, q1, [x9, #0x20]; ldp q2, q3, [x9]; stp q0, q1, [x8, #0x20]]
uint64_t fde_sub_08f000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAD410520ULL) << 32) | 0xF9400108ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F000ULL;
}

// FDE #2851 | PC: 0x08f018..0x08f038 (32 B) | Symbol: sub_08f018
// EN: AArch64 prologue [ldr x0, [x23], #8; mov x1, x22; mov w2, w21; mov x3, x20] | VI: Khởi đầu hàm AArch64 [ldr x0, [x23], #8; mov x1, x22; mov w2, w21; mov x3, x20]
uint64_t fde_sub_08f018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xF84086E0ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F018ULL;
}

// FDE #2852 | PC: 0x08f038..0x08f048 (16 B) | Symbol: sub_08f038
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; str x8, [sp, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; str x8, [sp, #0x28]; ret]
uint64_t fde_sub_08f038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F038ULL;
}

// FDE #2853 | PC: 0x08f048..0x08f070 (40 B) | Symbol: sub_08f048
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov v8.16b, v0.16b; mov x20, x0] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov v8.16b, v0.16b; mov x20, x0]
uint64_t fde_sub_08f048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F048ULL;
}

// FDE #2854 | PC: 0x08f070..0x08f088 (24 B) | Symbol: sub_08f070
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x20, x0; add x0, sp, #0x20] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x20, x0; add x0, sp, #0x20]
uint64_t fde_sub_08f070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F070ULL;
}

// FDE #2855 | PC: 0x08f088..0x08f0ac (36 B) | Symbol: sub_08f088
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x80]; ldp x22, x21, [sp, #0x70]; ldp x24, x23, [sp, #0x60]; ldp x26, x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x80]; ldp x22, x21, [sp, #0x70]; ldp x24, x23, [sp, #0x60]; ldp x26, x25, [sp, #0x50]]
uint64_t fde_sub_08f088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94757F6ULL) << 32) | 0xA9484FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F088ULL;
}

// FDE #2856 | PC: 0x08f0ac..0x08f0e4 (56 B) | Symbol: sub_08f0ac
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr w8, [x0, #8]; ldrb w9, [x0, #0xc]; ldr x0, [x21, #8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr w8, [x0, #8]; ldrb w9, [x0, #0xc]; ldr x0, [x21, #8]]
uint64_t fde_sub_08f0ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400808ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F0ACULL;
}

// FDE #2857 | PC: 0x08f0e4..0x08f0f0 (12 B) | Symbol: sub_08f0e4
// EN: AArch64 prologue [mrs x26, tpidr_el0; ldr x8, [x26, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x26, tpidr_el0; ldr x8, [x26, #0x28]; ret]
uint64_t fde_sub_08f0e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401748ULL) << 32) | 0xD53BD05AULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F0E4ULL;
}

// FDE #2858 | PC: 0x08f0f0..0x08f0f8 (8 B) | Symbol: sub_08f0f0
// EN: AArch64 prologue [add sp, sp, #0xc0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0xc0; ret]
uint64_t fde_sub_08f0f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910303FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F0F0ULL;
}

// FDE #2859 | PC: 0x08f0f8..0x08f104 (12 B) | Symbol: sub_08f0f8
// EN: AArch64 prologue [mrs x25, tpidr_el0; ldr x8, [x25, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x25, tpidr_el0; ldr x8, [x25, #0x28]; ret]
uint64_t fde_sub_08f0f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401728ULL) << 32) | 0xD53BD059ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F0F8ULL;
}

// FDE #2860 | PC: 0x08f104..0x08f10c (8 B) | Symbol: sub_08f104
// EN: AArch64 prologue [mov x0, x20; b #0x4696c] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x4696c]
uint64_t fde_sub_08f104(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDE19ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F104ULL;
}

// FDE #2861 | PC: 0x08f10c..0x08f118 (12 B) | Symbol: sub_08f10c
// EN: AArch64 prologue [mov x0, x20; mov x1, x22; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x22; ret]
uint64_t fde_sub_08f10c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F10CULL;
}

// FDE #2862 | PC: 0x08f118..0x08f130 (24 B) | Symbol: sub_08f118
// EN: AArch64 prologue [mov w9, #8; mov w11, #0x20; cmp w8, #0; csel x8, x11, x9, eq] | VI: Khởi đầu hàm AArch64 [mov w9, #8; mov w11, #0x20; cmp w8, #0; csel x8, x11, x9, eq]
uint64_t fde_sub_08f118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280040BULL) << 32) | 0x52800109ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F118ULL;
}

// FDE #2863 | PC: 0x08f130..0x08f140 (16 B) | Symbol: sub_08f130
// EN: AArch64 prologue [ldr x9, [x8], #0x10; sub x25, x19, #1; str x8, [x9, x24, lsl #3]; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [x8], #0x10; sub x25, x19, #1; str x8, [x9, x24, lsl #3]; ret]
uint64_t fde_sub_08f130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1000679ULL) << 32) | 0xF8410509ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F130ULL;
}

// FDE #2864 | PC: 0x08f140..0x08f160 (32 B) | Symbol: sub_08f140
// EN: AArch64 prologue [ldp s1, s2, [x22, #0x20]; mov x0, sp; mov x1, x19; mov x2, x21] | VI: Khởi đầu hàm AArch64 [ldp s1, s2, [x22, #0x20]; mov x0, sp; mov x1, x19; mov x2, x21]
uint64_t fde_sub_08f140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E0ULL) << 32) | 0x2D440AC1ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F140ULL;
}

// FDE #2865 | PC: 0x08f160..0x08f180 (32 B) | Symbol: sub_08f160
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x19, x0; mov x0, sp] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x19, x0; mov x0, sp]
uint64_t fde_sub_08f160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F160ULL;
}

// FDE #2866 | PC: 0x08f180..0x08f1a0 (32 B) | Symbol: sub_08f180
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov w19, w1; add x1, x0, #0x28] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov w19, w1; add x1, x0, #0x28]
uint64_t fde_sub_08f180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F180ULL;
}

// FDE #2867 | PC: 0x08f1a0..0x08f1c0 (32 B) | Symbol: sub_08f1a0
// EN: AArch64 prologue [ldp s1, s2, [x23, #0x20]; mov x0, sp; mov x1, x20; mov x2, x22] | VI: Khởi đầu hàm AArch64 [ldp s1, s2, [x23, #0x20]; mov x0, sp; mov x1, x20; mov x2, x22]
uint64_t fde_sub_08f1a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E0ULL) << 32) | 0x2D440AE1ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F1A0ULL;
}

// FDE #2868 | PC: 0x08f1c0..0x08f1c8 (8 B) | Symbol: sub_08f1c0
// EN: AArch64 prologue [mov x19, x8; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov x19, x8; b #0x93320]
uint64_t fde_sub_08f1c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001057ULL) << 32) | 0xAA0803F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F1C0ULL;
}

// FDE #2869 | PC: 0x08f1c8..0x08f1e8 (32 B) | Symbol: sub_08f1c8
// EN: AArch64 prologue [cmp w8, #0; fadd s0, s9, s1; fadd s1, s10, s2; fcsel s3, s3, s6, eq] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; fadd s0, s9, s1; fadd s1, s10, s2; fcsel s3, s3, s6, eq]
uint64_t fde_sub_08f1c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E212920ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F1C8ULL;
}

// FDE #2870 | PC: 0x08f1e8..0x08f1f0 (8 B) | Symbol: sub_08f1e8
// EN: AArch64 prologue [ldr x20, [sp], #0x20; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [ldr x20, [sp], #0x20; b #0x47ff4]
uint64_t fde_sub_08f1e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE382ULL) << 32) | 0xF84207F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F1E8ULL;
}

// FDE #2871 | PC: 0x08f1f0..0x08f1fc (12 B) | Symbol: sub_08f1f0
// EN: AArch64 prologue [ldr x0, [x19]; str xzr, [x19]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19]; str xzr, [x19]; ret]
uint64_t fde_sub_08f1f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900027FULL) << 32) | 0xF9400260ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F1F0ULL;
}

// FDE #2872 | PC: 0x08f1fc..0x08f224 (40 B) | Symbol: sub_08f1fc
// EN: AArch64 prologue [ldr x9, [x0, #0x10]; ldr x10, [x0]; mov w11, #0x18; sub x9, x9, x10] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x10]; ldr x10, [x0]; mov w11, #0x18; sub x9, x9, x10]
uint64_t fde_sub_08f1fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940000AULL) << 32) | 0xF9400809ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F1FCULL;
}

// FDE #2873 | PC: 0x08f224..0x08f23c (24 B) | Symbol: sub_08f224
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; ldr x9, [x0]; sub x8, x8, x9; mov x9, #0xffffffffffffffe] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; ldr x9, [x0]; sub x8, x8, x9; mov x9, #0xffffffffffffffe]
uint64_t fde_sub_08f224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400009ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F224ULL;
}

// FDE #2874 | PC: 0x08f23c..0x08f244 (8 B) | Symbol: sub_08f23c
// EN: AArch64 prologue [str x0, [x8, #8]; b #0x932e0] | VI: Khởi đầu hàm AArch64 [str x0, [x8, #8]; b #0x932e0]
uint64_t fde_sub_08f23c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001028ULL) << 32) | 0xF9000500ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F23CULL;
}

// FDE #2875 | PC: 0x08f244..0x08f24c (8 B) | Symbol: sub_08f244
// EN: AArch64 prologue [mov x1, x22; b #0x497ec] | VI: Khởi đầu hàm AArch64 [mov x1, x22; b #0x497ec]
uint64_t fde_sub_08f244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE969ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F244ULL;
}

// FDE #2876 | PC: 0x08f24c..0x08f25c (16 B) | Symbol: sub_08f24c
// EN: AArch64 prologue [ldr x8, [x0]; mov x20, x2; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov x20, x2; mov x19, x0; ret]
uint64_t fde_sub_08f24c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203F4ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F24CULL;
}

// FDE #2877 | PC: 0x08f25c..0x08f264 (8 B) | Symbol: sub_08f25c
// EN: AArch64 prologue [mov x1, x20; b #0x4c4d4] | VI: Khởi đầu hàm AArch64 [mov x1, x20; b #0x4c4d4]
uint64_t fde_sub_08f25c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEF49DULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F25CULL;
}

// FDE #2878 | PC: 0x08f264..0x08f26c (8 B) | Symbol: sub_08f264
// EN: AArch64 prologue [mov x1, x20; b #0x470b8] | VI: Khởi đầu hàm AArch64 [mov x1, x20; b #0x470b8]
uint64_t fde_sub_08f264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDF94ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F264ULL;
}

// FDE #2879 | PC: 0x08f26c..0x08f27c (16 B) | Symbol: sub_08f26c
// EN: AArch64 prologue [ldr x8, [x8, x27, lsl #3]; ldr x8, [x8]; str x8, [x28]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, x27, lsl #3]; ldr x8, [x8]; str x8, [x28]; ret]
uint64_t fde_sub_08f26c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400108ULL) << 32) | 0xF87B7908ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F26CULL;
}

// FDE #2880 | PC: 0x08f27c..0x08f288 (12 B) | Symbol: sub_08f27c
// EN: AArch64 prologue [add x0, sp, #8; mov x1, x20; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; mov x1, x20; ret]
uint64_t fde_sub_08f27c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F27CULL;
}

// FDE #2881 | PC: 0x08f288..0x08f294 (12 B) | Symbol: sub_08f288
// EN: AArch64 prologue [mov x0, x21; mov x1, x22; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x22; ret]
uint64_t fde_sub_08f288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F288ULL;
}

// FDE #2882 | PC: 0x08f294..0x08f2ac (24 B) | Symbol: sub_08f294
// EN: AArch64 prologue [mov x21, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18] | VI: Khởi đầu hàm AArch64 [mov x21, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18]
uint64_t fde_sub_08f294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xAA0003F5ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F294ULL;
}

// FDE #2883 | PC: 0x08f2ac..0x08f2cc (32 B) | Symbol: sub_08f2ac
// EN: AArch64 prologue [mov x21, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18] | VI: Khởi đầu hàm AArch64 [mov x21, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18]
uint64_t fde_sub_08f2ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xAA0003F5ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F2ACULL;
}

// FDE #2884 | PC: 0x08f2cc..0x08f2dc (16 B) | Symbol: sub_08f2cc
// EN: AArch64 prologue [cmp x20, x0; csel x1, x0, x20, lo; cmp x1, x21; ret] | VI: Khởi đầu hàm AArch64 [cmp x20, x0; csel x1, x0, x20, lo; cmp x1, x21; ret]
uint64_t fde_sub_08f2cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A943001ULL) << 32) | 0xEB00029FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F2CCULL;
}

// FDE #2885 | PC: 0x08f2dc..0x08f2ec (16 B) | Symbol: sub_08f2dc
// EN: AArch64 prologue [mov x20, x0; mov x0, x1; mov x19, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x0; mov x0, x1; mov x19, x1; ret]
uint64_t fde_sub_08f2dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F2DCULL;
}

// FDE #2886 | PC: 0x08f2ec..0x08f304 (24 B) | Symbol: sub_08f2ec
// EN: AArch64 prologue [mov x20, x0; mov x19, x0; mov x21, x1; str x8, [sp, #0x48]] | VI: Khởi đầu hàm AArch64 [mov x20, x0; mov x19, x0; mov x21, x1; str x8, [sp, #0x48]]
uint64_t fde_sub_08f2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F2ECULL;
}

// FDE #2887 | PC: 0x08f304..0x08f30c (8 B) | Symbol: sub_08f304
// EN: AArch64 prologue [add x0, x20, #8; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, x20, #8; b #0x46c54]
uint64_t fde_sub_08f304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDE53ULL) << 32) | 0x91002280ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F304ULL;
}

// FDE #2888 | PC: 0x08f30c..0x08f334 (40 B) | Symbol: sub_08f30c
// EN: AArch64 prologue [strb wzr, [sp, #0x58]; strb wzr, [sp, #0x38]; strb wzr, [sp, #0x18]; stp x10, x9, [sp, #0x48]] | VI: Khởi đầu hàm AArch64 [strb wzr, [sp, #0x58]; strb wzr, [sp, #0x38]; strb wzr, [sp, #0x18]; stp x10, x9, [sp, #0x48]]
uint64_t fde_sub_08f30c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3900E3FFULL) << 32) | 0x390163FFULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F30CULL;
}

// FDE #2889 | PC: 0x08f334..0x08f33c (8 B) | Symbol: sub_08f334
// EN: AArch64 prologue [add x0, sp, #0xf0; b #0x6d0bc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xf0; b #0x6d0bc]
uint64_t fde_sub_08f334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF7761ULL) << 32) | 0x9103C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F334ULL;
}

// FDE #2890 | PC: 0x08f33c..0x08f34c (16 B) | Symbol: sub_08f33c
// EN: AArch64 prologue [add x0, sp, #0xd0; mov x1, x28; mov x2, x21; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xd0; mov x1, x28; mov x2, x21; ret]
uint64_t fde_sub_08f33c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1C03E1ULL) << 32) | 0x910343E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F33CULL;
}

// FDE #2891 | PC: 0x08f34c..0x08f374 (40 B) | Symbol: sub_08f34c
// EN: AArch64 prologue [ldrb w8, [x1, #0xc]; ldrb w10, [x1, #0x14]; add x9, x1, #0x20; add x11, x1, #0x10] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x1, #0xc]; ldrb w10, [x1, #0x14]; add x9, x1, #0x20; add x11, x1, #0x10]
uint64_t fde_sub_08f34c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940502AULL) << 32) | 0x39403028ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F34CULL;
}

// FDE #2892 | PC: 0x08f374..0x08f380 (12 B) | Symbol: sub_08f374
// EN: AArch64 prologue [ldr x8, [sp, #8]; str xzr, [sp, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp, #8]; str xzr, [sp, #8]; ret]
uint64_t fde_sub_08f374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FFULL) << 32) | 0xF94007E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F374ULL;
}

// FDE #2893 | PC: 0x08f380..0x08f38c (12 B) | Symbol: sub_08f380
// EN: AArch64 prologue [mov x0, x19; mov x1, x22; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x22; ret]
uint64_t fde_sub_08f380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F380ULL;
}

// FDE #2894 | PC: 0x08f38c..0x08f394 (8 B) | Symbol: sub_08f38c
// EN: AArch64 prologue [mov x0, x19; b #0x932e0] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x932e0]
uint64_t fde_sub_08f38c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000FD4ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F38CULL;
}

// FDE #2895 | PC: 0x08f394..0x08f39c (8 B) | Symbol: sub_08f394
// EN: AArch64 prologue [mov x0, x19; b #0x46c54] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x46c54]
uint64_t fde_sub_08f394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDE2FULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F394ULL;
}

// FDE #2896 | PC: 0x08f39c..0x08f3a4 (8 B) | Symbol: sub_08f39c
// EN: AArch64 prologue [mov x0, x19; b #0x93300] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x93300]
uint64_t fde_sub_08f39c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000FD8ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F39CULL;
}

// FDE #2897 | PC: 0x08f3a4..0x08f3ac (8 B) | Symbol: sub_08f3a4
// EN: AArch64 prologue [mov x0, x19; b #0x932f0] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x932f0]
uint64_t fde_sub_08f3a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000FD2ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F3A4ULL;
}

// FDE #2898 | PC: 0x08f3ac..0x08f3e4 (56 B) | Symbol: sub_08f3ac
// EN: AArch64 prologue [ldrb w8, [x1, #9]; ldrb w9, [x1, #8]; ldrb w10, [x1, #0xb]; ldrb w11, [x1, #0xa]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x1, #9]; ldrb w9, [x1, #8]; ldrb w10, [x1, #0xb]; ldrb w11, [x1, #0xa]]
uint64_t fde_sub_08f3ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402029ULL) << 32) | 0x39402428ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F3ACULL;
}

// FDE #2899 | PC: 0x08f3e4..0x08f3f0 (12 B) | Symbol: sub_08f3e4
// EN: AArch64 prologue [ldr x9, [sp, #0xd8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0xd8]; cmp x8, x9; ret]
uint64_t fde_sub_08f3e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9406FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F3E4ULL;
}

// FDE #2900 | PC: 0x08f3f0..0x08f3fc (12 B) | Symbol: sub_08f3f0
// EN: AArch64 prologue [mov x8, x19; ldr x22, [x8, #0x10]!; ret] | VI: Khởi đầu hàm AArch64 [mov x8, x19; ldr x22, [x8, #0x10]!; ret]
uint64_t fde_sub_08f3f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8410D16ULL) << 32) | 0xAA1303E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F3F0ULL;
}

// FDE #2901 | PC: 0x08f3fc..0x08f408 (12 B) | Symbol: sub_08f3fc
// EN: AArch64 prologue [udiv x9, x8, x24; msub x8, x9, x24, x8; ret] | VI: Khởi đầu hàm AArch64 [udiv x9, x8, x24; msub x8, x9, x24, x8; ret]
uint64_t fde_sub_08f3fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B18A128ULL) << 32) | 0x9AD80909ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F3FCULL;
}

// FDE #2902 | PC: 0x08f408..0x08f410 (8 B) | Symbol: sub_08f408
// EN: AArch64 prologue [add x1, x1, #0xfb5; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xfb5; b #0x93910]
uint64_t fde_sub_08f408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001141ULL) << 32) | 0x913ED421ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F408ULL;
}

// FDE #2903 | PC: 0x08f410..0x08f418 (8 B) | Symbol: sub_08f410
// EN: AArch64 prologue [add sp, sp, #0xd0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0xd0; ret]
uint64_t fde_sub_08f410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910343FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F410ULL;
}

// FDE #2904 | PC: 0x08f418..0x08f43c (36 B) | Symbol: sub_08f418
// EN: AArch64 prologue [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w9, s0; ucvtf s0, x8] | VI: Khởi đầu hàm AArch64 [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w9, s0; ucvtf s0, x8]
uint64_t fde_sub_08f418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2E303800ULL) << 32) | 0x0E205800ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F418ULL;
}

// FDE #2905 | PC: 0x08f43c..0x08f460 (36 B) | Symbol: sub_08f43c
// EN: AArch64 prologue [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w9, s0; ucvtf s0, x8] | VI: Khởi đầu hàm AArch64 [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w9, s0; ucvtf s0, x8]
uint64_t fde_sub_08f43c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2E303800ULL) << 32) | 0x0E205800ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F43CULL;
}

// FDE #2906 | PC: 0x08f460..0x08f46c (12 B) | Symbol: sub_08f460
// EN: AArch64 prologue [add x0, sp, #0x20; mov x1, x20; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; mov x1, x20; ret]
uint64_t fde_sub_08f460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F460ULL;
}

// FDE #2907 | PC: 0x08f46c..0x08f490 (36 B) | Symbol: sub_08f46c
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; str x8, [sp, #0x38]; ldr x19, [x1]] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; str x8, [sp, #0x38]; ldr x19, [x1]]
uint64_t fde_sub_08f46c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F46CULL;
}

// FDE #2908 | PC: 0x08f490..0x08f4ac (28 B) | Symbol: sub_08f490
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; add x0, sp, #0x28] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; add x0, sp, #0x28]
uint64_t fde_sub_08f490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F490ULL;
}

// FDE #2909 | PC: 0x08f4ac..0x08f4b4 (8 B) | Symbol: sub_08f4ac
// EN: AArch64 prologue [add x0, sp, #0x50; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x50; b #0x46c54]
uint64_t fde_sub_08f4ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDDE9ULL) << 32) | 0x910143E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4ACULL;
}

// FDE #2910 | PC: 0x08f4b4..0x08f4bc (8 B) | Symbol: sub_08f4b4
// EN: AArch64 prologue [add sp, sp, #0x150; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x150; ret]
uint64_t fde_sub_08f4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910543FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4B4ULL;
}

// FDE #2911 | PC: 0x08f4bc..0x08f4e8 (44 B) | Symbol: sub_08f4bc
// EN: AArch64 prologue [mov w8, #0x3f800000; stur xzr, [x0, #0xc]; stur xzr, [x0, #4]; stp xzr, xzr, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [mov w8, #0x3f800000; stur xzr, [x0, #0xc]; stur xzr, [x0, #4]; stp xzr, xzr, [x0, #0x18]]
uint64_t fde_sub_08f4bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF800C01FULL) << 32) | 0x52A7F008ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4BCULL;
}

// FDE #2912 | PC: 0x08f4e8..0x08f4f4 (12 B) | Symbol: sub_08f4e8
// EN: AArch64 prologue [ldr x9, [sp, #0xb8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0xb8]; cmp x8, x9; ret]
uint64_t fde_sub_08f4e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9405FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4E8ULL;
}

// FDE #2913 | PC: 0x08f4f4..0x08f500 (12 B) | Symbol: sub_08f4f4
// EN: AArch64 prologue [str x8, [sp, #0x10]; str q0, [sp]; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x10]; str q0, [sp]; b #0x47ff4]
uint64_t fde_sub_08f4f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D8003E0ULL) << 32) | 0xF9000BE8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4F4ULL;
}

// FDE #2914 | PC: 0x08f500..0x08f50c (12 B) | Symbol: sub_08f500
// EN: AArch64 prologue [udiv x9, x8, x25; msub x8, x9, x25, x8; ret] | VI: Khởi đầu hàm AArch64 [udiv x9, x8, x25; msub x8, x9, x25, x8; ret]
uint64_t fde_sub_08f500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B19A128ULL) << 32) | 0x9AD90909ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F500ULL;
}

// FDE #2915 | PC: 0x08f50c..0x08f514 (8 B) | Symbol: sub_08f50c
// EN: AArch64 prologue [ldr x8, [x8, #0x48]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x48]; br x8]
uint64_t fde_sub_08f50c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9402508ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F50CULL;
}

// FDE #2916 | PC: 0x08f514..0x08f51c (8 B) | Symbol: sub_08f514
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_08f514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F514ULL;
}

// FDE #2917 | PC: 0x08f51c..0x08f538 (28 B) | Symbol: sub_08f51c
// EN: AArch64 prologue [fmov s0, wzr; fmov s1, wzr; fmov s2, wzr; ldr x8, [x8]] | VI: Khởi đầu hàm AArch64 [fmov s0, wzr; fmov s1, wzr; fmov s2, wzr; ldr x8, [x8]]
uint64_t fde_sub_08f51c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2703E1ULL) << 32) | 0x1E2703E0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F51CULL;
}

// FDE #2918 | PC: 0x08f538..0x08f540 (8 B) | Symbol: sub_08f538
// EN: AArch64 prologue [add x19, sp, #8; b #0x49290] | VI: Khởi đầu hàm AArch64 [add x19, sp, #8; b #0x49290]
uint64_t fde_sub_08f538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE755ULL) << 32) | 0x910023F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F538ULL;
}

// FDE #2919 | PC: 0x08f540..0x08f550 (16 B) | Symbol: sub_08f540
// EN: AArch64 prologue [movi v0.2d, #0000000000000000; mov w0, #0x38; stp q0, q0, [sp, #0x90]; b #0x93320] | VI: Khởi đầu hàm AArch64 [movi v0.2d, #0000000000000000; mov w0, #0x38; stp q0, q0, [sp, #0x90]; b #0x93320]
uint64_t fde_sub_08f540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800700ULL) << 32) | 0x6F00E400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F540ULL;
}

// FDE #2920 | PC: 0x08f550..0x08f55c (12 B) | Symbol: sub_08f550
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x10]; add sp, sp, #0x30; b #0x4722c] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x10]; add sp, sp, #0x30; b #0x4722c]
uint64_t fde_sub_08f550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C3FFULL) << 32) | 0xA94153F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F550ULL;
}

// FDE #2921 | PC: 0x08f55c..0x08f568 (12 B) | Symbol: sub_08f55c
// EN: AArch64 prologue [add x0, sp, #0xb0; add x1, sp, #0x80; b #0x47fbc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xb0; add x1, sp, #0x80; b #0x47fbc]
uint64_t fde_sub_08f55c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910203E1ULL) << 32) | 0x9102C3E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F55CULL;
}

// FDE #2922 | PC: 0x08f568..0x08f574 (12 B) | Symbol: sub_08f568
// EN: AArch64 prologue [add x0, sp, #0x10; mov x21, x1; b #0x44768] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x10; mov x21, x1; b #0x44768]
uint64_t fde_sub_08f568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F5ULL) << 32) | 0x910043E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F568ULL;
}

// FDE #2923 | PC: 0x08f574..0x08f57c (8 B) | Symbol: sub_08f574
// EN: AArch64 prologue [add x0, sp, #0x10; b #0x49314] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x10; b #0x49314]
uint64_t fde_sub_08f574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE767ULL) << 32) | 0x910043E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F574ULL;
}

// FDE #2924 | PC: 0x08f57c..0x08f588 (12 B) | Symbol: sub_08f57c
// EN: AArch64 prologue [ldr x8, [x20]; str x8, [x19]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20]; str x8, [x19]; ret]
uint64_t fde_sub_08f57c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000268ULL) << 32) | 0xF9400288ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F57CULL;
}

// FDE #2925 | PC: 0x08f588..0x08f598 (16 B) | Symbol: sub_08f588
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; mov x1, x22; b #0x7ce1c] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; mov x1, x22; b #0x7ce1c]
uint64_t fde_sub_08f588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F588ULL;
}

// FDE #2926 | PC: 0x08f598..0x08f5a8 (16 B) | Symbol: sub_08f598
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; mov x3, x22; b #0x7cc5c] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; mov x3, x22; b #0x7cc5c]
uint64_t fde_sub_08f598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F598ULL;
}

// FDE #2927 | PC: 0x08f5a8..0x08f5b0 (8 B) | Symbol: sub_08f5a8
// EN: AArch64 prologue [mov x0, x8; b #0x932e0] | VI: Khởi đầu hàm AArch64 [mov x0, x8; b #0x932e0]
uint64_t fde_sub_08f5a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000F4DULL) << 32) | 0xAA0803E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5A8ULL;
}

// FDE #2928 | PC: 0x08f5b0..0x08f5dc (44 B) | Symbol: sub_08f5b0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x20, #0xb8]; ldr x0, [x8, #8]; mov w8, #0x437f0000] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x20, #0xb8]; ldr x0, [x8, #8]; mov w8, #0x437f0000]
uint64_t fde_sub_08f5b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405E88ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5B0ULL;
}

// FDE #2929 | PC: 0x08f5dc..0x08f5e4 (8 B) | Symbol: sub_08f5dc
// EN: AArch64 prologue [add x0, x19, #0x28; b #0x6aa40] | VI: Khởi đầu hàm AArch64 [add x0, x19, #0x28; b #0x6aa40]
uint64_t fde_sub_08f5dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF6D18ULL) << 32) | 0x9100A260ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5DCULL;
}

// FDE #2930 | PC: 0x08f5e4..0x08f5f0 (12 B) | Symbol: sub_08f5e4
// EN: AArch64 prologue [ldr x0, [x19, #8]; stp x9, x8, [x19]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #8]; stp x9, x8, [x19]; ret]
uint64_t fde_sub_08f5e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9002269ULL) << 32) | 0xF9400660ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5E4ULL;
}

// FDE #2931 | PC: 0x08f5f0..0x08f600 (16 B) | Symbol: sub_08f5f0
// EN: AArch64 prologue [ldr x0, [x19, #8]; adrp x1, #0x1b000; add x1, x1, #0x6e4; b #0x4696c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #8]; adrp x1, #0x1b000; add x1, x1, #0x6e4; b #0x4696c]
uint64_t fde_sub_08f5f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90FFFC61ULL) << 32) | 0xF9400660ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5F0ULL;
}

// FDE #2932 | PC: 0x08f600..0x08f610 (16 B) | Symbol: sub_08f600
// EN: AArch64 prologue [ldr x9, [x8]; mov x0, x8; ldr x9, [x9, #8]; br x9] | VI: Khởi đầu hàm AArch64 [ldr x9, [x8]; mov x0, x8; ldr x9, [x9, #8]; br x9]
uint64_t fde_sub_08f600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xF9400109ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F600ULL;
}

// FDE #2933 | PC: 0x08f610..0x08f620 (16 B) | Symbol: sub_08f610
// EN: AArch64 prologue [ldr x8, [x20, #0x70]; mov x1, x0; mov x0, x8; b #0x8c1f8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20, #0x70]; mov x1, x0; mov x0, x8; b #0x8c1f8]
uint64_t fde_sub_08f610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E1ULL) << 32) | 0xF9403A88ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F610ULL;
}

// FDE #2934 | PC: 0x08f620..0x08f63c (28 B) | Symbol: sub_08f620
// EN: AArch64 prologue [ldr x9, [x1, #0x18]; ldur q0, [x1, #8]; add x8, x1, #8; str x9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x1, #0x18]; ldur q0, [x1, #8]; add x8, x1, #8; str x9, [x0, #0x18]]
uint64_t fde_sub_08f620(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3CC08020ULL) << 32) | 0xF9400C29ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F620ULL;
}

// FDE #2935 | PC: 0x08f63c..0x08f644 (8 B) | Symbol: sub_08f63c
// EN: AArch64 prologue [add x0, sp, #0x28; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x28; b #0x937a0]
uint64_t fde_sub_08f63c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001058ULL) << 32) | 0x9100A3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F63CULL;
}

// FDE #2936 | PC: 0x08f644..0x08f650 (12 B) | Symbol: sub_08f644
// EN: AArch64 prologue [mov x1, x0; mov x0, x22; b #0x8bd78] | VI: Khởi đầu hàm AArch64 [mov x1, x0; mov x0, x22; b #0x8bd78]
uint64_t fde_sub_08f644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F644ULL;
}

// FDE #2937 | PC: 0x08f650..0x08f660 (16 B) | Symbol: sub_08f650
// EN: AArch64 prologue [mov x1, x0; mov x0, x22; mov x2, x21; b #0x5afd0] | VI: Khởi đầu hàm AArch64 [mov x1, x0; mov x0, x22; mov x2, x21; b #0x5afd0]
uint64_t fde_sub_08f650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F650ULL;
}

// FDE #2938 | PC: 0x08f660..0x08f670 (16 B) | Symbol: sub_08f660
// EN: AArch64 prologue [mov x1, x0; mov x0, x22; mov x2, x19; b #0x5afd0] | VI: Khởi đầu hàm AArch64 [mov x1, x0; mov x0, x22; mov x2, x19; b #0x5afd0]
uint64_t fde_sub_08f660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F660ULL;
}

// FDE #2939 | PC: 0x08f670..0x08f680 (16 B) | Symbol: sub_08f670
// EN: AArch64 prologue [mov w0, #0x20; str xzr, [sp, #8]; str x19, [sp, #0x20]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; str xzr, [sp, #8]; str x19, [sp, #0x20]; b #0x93320]
uint64_t fde_sub_08f670(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FFULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F670ULL;
}

// FDE #2940 | PC: 0x08f680..0x08f68c (12 B) | Symbol: sub_08f680
// EN: AArch64 prologue [mov w0, #0x20; str d8, [sp, #0x20]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; str d8, [sp, #0x20]; b #0x93320]
uint64_t fde_sub_08f680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F680ULL;
}

// FDE #2941 | PC: 0x08f68c..0x08f698 (12 B) | Symbol: sub_08f68c
// EN: AArch64 prologue [mov w0, #0x20; strb w19, [sp, #0x20]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; strb w19, [sp, #0x20]; b #0x93320]
uint64_t fde_sub_08f68c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x390083F3ULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F68CULL;
}

// FDE #2942 | PC: 0x08f698..0x08f6b4 (28 B) | Symbol: sub_08f698
// EN: AArch64 prologue [ldr w1, [x20, #0x18]; ldr q0, [sp, #0x10]; add x2, sp, #0x290; mov x0, x19] | VI: Khởi đầu hàm AArch64 [ldr w1, [x20, #0x18]; ldr q0, [sp, #0x10]; add x2, sp, #0x290; mov x0, x19]
uint64_t fde_sub_08f698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC007E0ULL) << 32) | 0xB9401A81ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F698ULL;
}

// FDE #2943 | PC: 0x08f6b4..0x08f6c4 (16 B) | Symbol: sub_08f6b4
// EN: AArch64 prologue [mov x1, x21; mov x2, x20; ldp x21, x20, [sp], #0x20; b #0x7cc88] | VI: Khởi đầu hàm AArch64 [mov x1, x21; mov x2, x20; ldp x21, x20, [sp], #0x20; b #0x7cc88]
uint64_t fde_sub_08f6b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E2ULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6B4ULL;
}

// FDE #2944 | PC: 0x08f6c4..0x08f6e8 (36 B) | Symbol: sub_08f6c4
// EN: AArch64 prologue [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ldrb w8, [x1]; ldr x9, [x1, #8]] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ldrb w8, [x1]; ldr x9, [x1, #8]]
uint64_t fde_sub_08f6c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900081FULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6C4ULL;
}

// FDE #2945 | PC: 0x08f6e8..0x08f6f4 (12 B) | Symbol: sub_08f6e8
// EN: AArch64 prologue [add x0, x20, #0x10; mov x1, x22; b #0x4c4d4] | VI: Khởi đầu hàm AArch64 [add x0, x20, #0x10; mov x1, x22; b #0x4c4d4]
uint64_t fde_sub_08f6e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0x91004280ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6E8ULL;
}

// FDE #2946 | PC: 0x08f6f4..0x08f710 (28 B) | Symbol: sub_08f6f4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x49290; adrp x1, #0x1e000; add x0, x20, #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x49290; adrp x1, #0x1e000; add x0, x20, #0x10]
uint64_t fde_sub_08f6f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEE6E6ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6F4ULL;
}

// FDE #2947 | PC: 0x08f710..0x08f72c (28 B) | Symbol: sub_08f710
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x2; str x8, [sp, #0x48]] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x2; str x8, [sp, #0x48]]
uint64_t fde_sub_08f710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F710ULL;
}

// FDE #2948 | PC: 0x08f72c..0x08f748 (28 B) | Symbol: sub_08f72c
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x2; str x8, [sp, #0xd8]] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x2; str x8, [sp, #0xd8]]
uint64_t fde_sub_08f72c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F72CULL;
}

// FDE #2949 | PC: 0x08f748..0x08f758 (16 B) | Symbol: sub_08f748
// EN: AArch64 prologue [add x8, sp, #8; add x0, x8, #0x10; str d0, [sp, #0x10]; b #0x4aaf4] | VI: Khởi đầu hàm AArch64 [add x8, sp, #8; add x0, x8, #0x10; str d0, [sp, #0x10]; b #0x4aaf4]
uint64_t fde_sub_08f748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004100ULL) << 32) | 0x910023E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F748ULL;
}

// FDE #2950 | PC: 0x08f758..0x08f760 (8 B) | Symbol: sub_08f758
// EN: AArch64 prologue [add x0, sp, #0x30; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x30; b #0x46c54]
uint64_t fde_sub_08f758(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDD3EULL) << 32) | 0x9100C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F758ULL;
}

// FDE #2951 | PC: 0x08f760..0x08f76c (12 B) | Symbol: sub_08f760
// EN: AArch64 prologue [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; ret]
uint64_t fde_sub_08f760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401668ULL) << 32) | 0xD53BD053ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F760ULL;
}

// FDE #2952 | PC: 0x08f76c..0x08f790 (36 B) | Symbol: sub_08f76c
// EN: AArch64 prologue [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; mov w9, #0x3f800000; add x1, sp, #8] | VI: Khởi đầu hàm AArch64 [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; mov w9, #0x3f800000; add x1, sp, #8]
uint64_t fde_sub_08f76c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401668ULL) << 32) | 0xD53BD053ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F76CULL;
}

// FDE #2953 | PC: 0x08f790..0x08f79c (12 B) | Symbol: sub_08f790
// EN: AArch64 prologue [cmp x8, #0; cset w0, ne; ret] | VI: Khởi đầu hàm AArch64 [cmp x8, #0; cset w0, ne; ret]
uint64_t fde_sub_08f790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E0ULL) << 32) | 0xF100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F790ULL;
}

// FDE #2954 | PC: 0x08f79c..0x08f7a8 (12 B) | Symbol: sub_08f79c
// EN: AArch64 prologue [cmp x8, #0; cset w0, eq; ret] | VI: Khởi đầu hàm AArch64 [cmp x8, #0; cset w0, eq; ret]
uint64_t fde_sub_08f79c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E0ULL) << 32) | 0xF100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F79CULL;
}

// FDE #2955 | PC: 0x08f7a8..0x08f7cc (36 B) | Symbol: sub_08f7a8
// EN: AArch64 prologue [stp x22, x23, [x0, #8]; str w20, [x0, #0x18]; str x8, [x0]; str x0, [sp, #8]] | VI: Khởi đầu hàm AArch64 [stp x22, x23, [x0, #8]; str w20, [x0, #0x18]; str x8, [x0]; str x0, [sp, #8]]
uint64_t fde_sub_08f7a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9001814ULL) << 32) | 0xA900DC16ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F7A8ULL;
}

// FDE #2956 | PC: 0x08f7cc..0x08f7d4 (8 B) | Symbol: sub_08f7cc
// EN: AArch64 prologue [mov x0, x20; b #0x4c158] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x4c158]
uint64_t fde_sub_08f7cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEF262ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F7CCULL;
}

// FDE #2957 | PC: 0x08f7d4..0x08f7e0 (12 B) | Symbol: sub_08f7d4
// EN: AArch64 prologue [ldr x29, [sp, #0xd0]; str xzr, [sp, #0xd0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x29, [sp, #0xd0]; str xzr, [sp, #0xd0]; ret]
uint64_t fde_sub_08f7d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9006BFFULL) << 32) | 0xF9406BFDULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F7D4ULL;
}

// FDE #2958 | PC: 0x08f7e0..0x08f7ec (12 B) | Symbol: sub_08f7e0
// EN: AArch64 prologue [ldp x9, x8, [x1]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x1]; mov x19, x0; ret]
uint64_t fde_sub_08f7e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9402029ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F7E0ULL;
}

// FDE #2959 | PC: 0x08f7ec..0x08f7f8 (12 B) | Symbol: sub_08f7ec
// EN: AArch64 prologue [udiv x8, x21, x23; msub x24, x8, x23, x21; ret] | VI: Khởi đầu hàm AArch64 [udiv x8, x21, x23; msub x24, x8, x23, x21; ret]
uint64_t fde_sub_08f7ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B17D518ULL) << 32) | 0x9AD70AA8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F7ECULL;
}

// FDE #2960 | PC: 0x08f7f8..0x08f804 (12 B) | Symbol: sub_08f7f8
// EN: AArch64 prologue [mov v8.16b, v1.16b; mov v9.16b, v0.16b; ret] | VI: Khởi đầu hàm AArch64 [mov v8.16b, v1.16b; mov v9.16b, v0.16b; ret]
uint64_t fde_sub_08f7f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA01C09ULL) << 32) | 0x4EA11C28ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F7F8ULL;
}

// FDE #2961 | PC: 0x08f804..0x08f810 (12 B) | Symbol: sub_08f804
// EN: AArch64 prologue [ldr w8, [x1], #8; str w8, [x0], #8; b #0x47f90] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1], #8; str w8, [x0], #8; b #0x47f90]
uint64_t fde_sub_08f804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8008408ULL) << 32) | 0xB8408428ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F804ULL;
}

// FDE #2962 | PC: 0x08f810..0x08f818 (8 B) | Symbol: sub_08f810
// EN: AArch64 prologue [add x1, x1, #0xa40; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xa40; b #0x93910]
uint64_t fde_sub_08f810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400103FULL) << 32) | 0x91290021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F810ULL;
}

// FDE #2963 | PC: 0x08f818..0x08f83c (36 B) | Symbol: sub_08f818
// EN: AArch64 prologue [movi v0.2s, #0x80, lsl #16; str xzr, [x19]; stp xzr, xzr, [x20, #0x28]; stp xzr, xzr, [x20, #0x48]] | VI: Khởi đầu hàm AArch64 [movi v0.2s, #0x80, lsl #16; str xzr, [x19]; stp xzr, xzr, [x20, #0x28]; stp xzr, xzr, [x20, #0x48]]
uint64_t fde_sub_08f818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900027FULL) << 32) | 0x0F044400ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F818ULL;
}

// FDE #2964 | PC: 0x08f83c..0x08f844 (8 B) | Symbol: sub_08f83c
// EN: AArch64 prologue [mov x0, x22; b #0x44830] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x44830]
uint64_t fde_sub_08f83c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED3FCULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F83CULL;
}

// FDE #2965 | PC: 0x08f844..0x08f84c (8 B) | Symbol: sub_08f844
// EN: AArch64 prologue [mov x0, x22; b #0x932e0] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x932e0]
uint64_t fde_sub_08f844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000EA6ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F844ULL;
}

// FDE #2966 | PC: 0x08f84c..0x08f858 (12 B) | Symbol: sub_08f84c
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; ret]
uint64_t fde_sub_08f84c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F84CULL;
}

// FDE #2967 | PC: 0x08f858..0x08f874 (28 B) | Symbol: sub_08f858
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x20, x0; add x0, sp, #0x28] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x20, x0; add x0, sp, #0x28]
uint64_t fde_sub_08f858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F858ULL;
}

// FDE #2968 | PC: 0x08f874..0x08f898 (36 B) | Symbol: sub_08f874
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; ldrb w11, [x0, #0x14]; mov w9, #8; mov w10, #0x20] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; ldrb w11, [x0, #0x14]; mov w9, #8; mov w10, #0x20]
uint64_t fde_sub_08f874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940500BULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F874ULL;
}

// FDE #2969 | PC: 0x08f898..0x08f8a0 (8 B) | Symbol: sub_08f898
// EN: AArch64 prologue [ldr x20, [sp], #0x20; b #0x64ab0] | VI: Khởi đầu hàm AArch64 [ldr x20, [sp], #0x20; b #0x64ab0]
uint64_t fde_sub_08f898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5485ULL) << 32) | 0xF84207F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F898ULL;
}

// FDE #2970 | PC: 0x08f8a0..0x08f8a8 (8 B) | Symbol: sub_08f8a0
// EN: AArch64 prologue [ldr x0, [x19]; b #0x89f28] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19]; b #0x89f28]
uint64_t fde_sub_08f8a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE9A1ULL) << 32) | 0xF9400260ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F8A0ULL;
}

// FDE #2971 | PC: 0x08f8a8..0x08f8b4 (12 B) | Symbol: sub_08f8a8
// EN: AArch64 prologue [mov w2, #1; mov x22, x0; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x22, x0; b #0x93c30]
uint64_t fde_sub_08f8a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F6ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F8A8ULL;
}

// FDE #2972 | PC: 0x08f8b4..0x08f8c4 (16 B) | Symbol: sub_08f8b4
// EN: AArch64 prologue [mov w2, #1; mov x0, x20; mov x4, x23; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x20; mov x4, x23; b #0x93c30]
uint64_t fde_sub_08f8b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F8B4ULL;
}

// FDE #2973 | PC: 0x08f8c4..0x08f8e8 (36 B) | Symbol: sub_08f8c4
// EN: AArch64 prologue [ldr s0, [x0, #8]; ldrb w8, [x0, #0xc]; mov w9, #0x42c80000; fmov s1, w9] | VI: Khởi đầu hàm AArch64 [ldr s0, [x0, #8]; ldrb w8, [x0, #0xc]; mov w9, #0x42c80000; fmov s1, w9]
uint64_t fde_sub_08f8c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39403008ULL) << 32) | 0xBD400800ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F8C4ULL;
}

// FDE #2974 | PC: 0x08f8e8..0x08f90c (36 B) | Symbol: sub_08f8e8
// EN: AArch64 prologue [str x8, [x0]; add x9, x8, #0xd8; add x10, x8, #0xf8; add x8, x8, #0x120] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; add x9, x8, #0xd8; add x10, x8, #0xf8; add x8, x8, #0x120]
uint64_t fde_sub_08f8e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91036109ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F8E8ULL;
}

// FDE #2975 | PC: 0x08f90c..0x08f930 (36 B) | Symbol: sub_08f90c
// EN: AArch64 prologue [ldrb w8, [x20, #0xc]; mov w9, #8; cmp w8, #0; mov w8, #0x20] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x20, #0xc]; mov w9, #8; cmp w8, #0; mov w8, #0x20]
uint64_t fde_sub_08f90c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800109ULL) << 32) | 0x39403288ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F90CULL;
}

// FDE #2976 | PC: 0x08f930..0x08f938 (8 B) | Symbol: sub_08f930
// EN: AArch64 prologue [mov x1, x22; b #0x47f90] | VI: Khởi đầu hàm AArch64 [mov x1, x22; b #0x47f90]
uint64_t fde_sub_08f930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE197ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F930ULL;
}

// FDE #2977 | PC: 0x08f938..0x08f940 (8 B) | Symbol: sub_08f938
// EN: AArch64 prologue [mov x1, x22; b #0x4c4d4] | VI: Khởi đầu hàm AArch64 [mov x1, x22; b #0x4c4d4]
uint64_t fde_sub_08f938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEF2E6ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F938ULL;
}

// FDE #2978 | PC: 0x08f940..0x08f94c (12 B) | Symbol: sub_08f940
// EN: AArch64 prologue [ldr x0, [sp, #0x10]; str xzr, [sp, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x10]; str xzr, [sp, #0x10]; ret]
uint64_t fde_sub_08f940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFFULL) << 32) | 0xF9400BE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F940ULL;
}

// FDE #2979 | PC: 0x08f94c..0x08f958 (12 B) | Symbol: sub_08f94c
// EN: AArch64 prologue [ldr x8, [x0]; ldr x3, [x8, #0x18]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x3, [x8, #0x18]; br x3]
uint64_t fde_sub_08f94c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D03ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F94CULL;
}

// FDE #2980 | PC: 0x08f958..0x08f964 (12 B) | Symbol: sub_08f958
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #0x50]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #0x50]; br x8]
uint64_t fde_sub_08f958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402908ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F958ULL;
}

// FDE #2981 | PC: 0x08f964..0x08f974 (16 B) | Symbol: sub_08f964
// EN: AArch64 prologue [ldr x8, [x0]; mov v0.16b, v8.16b; ldr x8, [x8, #0x10]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov v0.16b, v8.16b; ldr x8, [x8, #0x10]; br x8]
uint64_t fde_sub_08f964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA81D00ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F964ULL;
}

// FDE #2982 | PC: 0x08f974..0x08f97c (8 B) | Symbol: sub_08f974
// EN: AArch64 prologue [mov v0.16b, v8.16b; b #0x6f578] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v8.16b; b #0x6f578]
uint64_t fde_sub_08f974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF7F00ULL) << 32) | 0x4EA81D00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F974ULL;
}

// FDE #2983 | PC: 0x08f97c..0x08f984 (8 B) | Symbol: sub_08f97c
// EN: AArch64 prologue [mov v0.16b, v8.16b; b #0x47164] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v8.16b; b #0x47164]
uint64_t fde_sub_08f97c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDDF9ULL) << 32) | 0x4EA81D00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F97CULL;
}

// FDE #2984 | PC: 0x08f984..0x08f9a0 (28 B) | Symbol: sub_08f984
// EN: AArch64 prologue [ldr x2, [sp, #0xa8]; adrp x8, #0x9c000; add x8, x8, #0x6d0; add x0, sp, #0x90] | VI: Khởi đầu hàm AArch64 [ldr x2, [sp, #0xa8]; adrp x8, #0x9c000; add x8, x8, #0x6d0; add x0, sp, #0x90]
uint64_t fde_sub_08f984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000068ULL) << 32) | 0xF94057E2ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F984ULL;
}

// FDE #2985 | PC: 0x08f9a0..0x08f9ac (12 B) | Symbol: sub_08f9a0
// EN: AArch64 prologue [mov x1, x20; mov x2, x21; b #0x7ce74] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov x2, x21; b #0x7ce74]
uint64_t fde_sub_08f9a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E2ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9A0ULL;
}

// FDE #2986 | PC: 0x08f9ac..0x08f9b8 (12 B) | Symbol: sub_08f9ac
// EN: AArch64 prologue [adrp x0, #0xa0000; add x0, x0, #0x70; b #0x940b0] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xa0000; add x0, x0, #0x70; b #0x940b0]
uint64_t fde_sub_08f9ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9101C000ULL) << 32) | 0xB0000080ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9ACULL;
}

// FDE #2987 | PC: 0x08f9b8..0x08f9c4 (12 B) | Symbol: sub_08f9b8
// EN: AArch64 prologue [mov x21, x1; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x21, x1; mov x19, x0; ret]
uint64_t fde_sub_08f9b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xAA0103F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9B8ULL;
}

// FDE #2988 | PC: 0x08f9c4..0x08f9d0 (12 B) | Symbol: sub_08f9c4
// EN: AArch64 prologue [mov x21, x1; mov x20, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x21, x1; mov x20, x0; ret]
uint64_t fde_sub_08f9c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9C4ULL;
}

// FDE #2989 | PC: 0x08f9d0..0x08f9dc (12 B) | Symbol: sub_08f9d0
// EN: AArch64 prologue [mov x1, sp; mov x0, x19; b #0x5162c] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x19; b #0x5162c]
uint64_t fde_sub_08f9d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9D0ULL;
}

// FDE #2990 | PC: 0x08f9dc..0x08f9e8 (12 B) | Symbol: sub_08f9dc
// EN: AArch64 prologue [add x21, x26, #0x10; mov x29, x26; ret] | VI: Khởi đầu hàm AArch64 [add x21, x26, #0x10; mov x29, x26; ret]
uint64_t fde_sub_08f9dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1A03FDULL) << 32) | 0x91004355ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9DCULL;
}

// FDE #2991 | PC: 0x08f9e8..0x08f9f4 (12 B) | Symbol: sub_08f9e8
// EN: AArch64 prologue [add x1, sp, #8; mov x0, x22; b #0x447c0] | VI: Khởi đầu hàm AArch64 [add x1, sp, #8; mov x0, x22; b #0x447c0]
uint64_t fde_sub_08f9e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0x910023E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9E8ULL;
}

// FDE #2992 | PC: 0x08f9f4..0x08fa00 (12 B) | Symbol: sub_08f9f4
// EN: AArch64 prologue [udiv x8, x27, x20; msub x27, x8, x20, x27; ret] | VI: Khởi đầu hàm AArch64 [udiv x8, x27, x20; msub x27, x8, x20, x27; ret]
uint64_t fde_sub_08f9f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B14ED1BULL) << 32) | 0x9AD40B68ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9F4ULL;
}

// FDE #2993 | PC: 0x08fa00..0x08fa08 (8 B) | Symbol: sub_08fa00
// EN: AArch64 prologue [mov x0, x21; b #0x46c54] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x46c54]
uint64_t fde_sub_08fa00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDC94ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA00ULL;
}

// FDE #2994 | PC: 0x08fa08..0x08fa14 (12 B) | Symbol: sub_08fa08
// EN: AArch64 prologue [sub x9, x20, #1; and x24, x24, x9; ret] | VI: Khởi đầu hàm AArch64 [sub x9, x20, #1; and x24, x24, x9; ret]
uint64_t fde_sub_08fa08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8A090318ULL) << 32) | 0xD1000689ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA08ULL;
}

// FDE #2995 | PC: 0x08fa14..0x08fa20 (12 B) | Symbol: sub_08fa14
// EN: AArch64 prologue [udiv x9, x24, x20; msub x24, x9, x20, x24; ret] | VI: Khởi đầu hàm AArch64 [udiv x9, x24, x20; msub x24, x9, x20, x24; ret]
uint64_t fde_sub_08fa14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B14E138ULL) << 32) | 0x9AD40B09ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA14ULL;
}

// FDE #2996 | PC: 0x08fa20..0x08fa28 (8 B) | Symbol: sub_08fa20
// EN: AArch64 prologue [mov x20, x1; b #0x93420] | VI: Khởi đầu hàm AArch64 [mov x20, x1; b #0x93420]
uint64_t fde_sub_08fa20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000E7FULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA20ULL;
}

// FDE #2997 | PC: 0x08fa28..0x08fa38 (16 B) | Symbol: sub_08fa28
// EN: AArch64 prologue [mov x20, x0; mov w0, #0x10; mov w19, w1; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov x20, x0; mov w0, #0x10; mov w19, w1; b #0x93320]
uint64_t fde_sub_08fa28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800200ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA28ULL;
}

// FDE #2998 | PC: 0x08fa38..0x08fa40 (8 B) | Symbol: sub_08fa38
// EN: AArch64 prologue [add x0, sp, #0x98; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x98; b #0x46c54]
uint64_t fde_sub_08fa38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDC86ULL) << 32) | 0x910263E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA38ULL;
}

// FDE #2999 | PC: 0x08fa40..0x08fa4c (12 B) | Symbol: sub_08fa40
// EN: AArch64 prologue [str x9, [x0]; mov x0, x8; b #0x48d40] | VI: Khởi đầu hàm AArch64 [str x9, [x0]; mov x0, x8; b #0x48d40]
uint64_t fde_sub_08fa40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xF9000009ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA40ULL;
}

// FDE #3000 | PC: 0x08fa4c..0x08fa58 (12 B) | Symbol: sub_08fa4c
// EN: AArch64 prologue [stp xzr, xzr, [x0, #8]; str x8, [x0]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0, #8]; str x8, [x0]; ret]
uint64_t fde_sub_08fa4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xA900FC1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA4CULL;
}

// FDE #3001 | PC: 0x08fa58..0x08fa68 (16 B) | Symbol: sub_08fa58
// EN: AArch64 prologue [mov x8, x0; mov x0, x1; mov x1, x8; br x2] | VI: Khởi đầu hàm AArch64 [mov x8, x0; mov x0, x1; mov x1, x8; br x2]
uint64_t fde_sub_08fa58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA58ULL;
}

// FDE #3002 | PC: 0x08fa68..0x08fa78 (16 B) | Symbol: sub_08fa68
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldr d8, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldr d8, [sp], #0x40; ret]
uint64_t fde_sub_08fa68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9415BF7ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA68ULL;
}

// FDE #3003 | PC: 0x08fa78..0x08fa88 (16 B) | Symbol: sub_08fa78
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldp x25, x24, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldp x25, x24, [sp], #0x40; ret]
uint64_t fde_sub_08fa78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9415BF7ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA78ULL;
}

// FDE #3004 | PC: 0x08fa88..0x08fa94 (12 B) | Symbol: sub_08fa88
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; add sp, sp, #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; add sp, sp, #0x40; ret]
uint64_t fde_sub_08fa88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910103FFULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA88ULL;
}

// FDE #3005 | PC: 0x08fa94..0x08faa4 (16 B) | Symbol: sub_08fa94
// EN: AArch64 prologue [add x0, sp, #0xf0; str q0, [sp, #0xd0]; str x8, [sp, #0xe0]; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xf0; str q0, [sp, #0xd0]; str x8, [sp, #0xe0]; b #0x47ff4]
uint64_t fde_sub_08fa94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D8037E0ULL) << 32) | 0x9103C3E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA94ULL;
}

// FDE #3006 | PC: 0x08faa4..0x08fab0 (12 B) | Symbol: sub_08faa4
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x768; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x768; b #0x4696c]
uint64_t fde_sub_08faa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911DA021ULL) << 32) | 0x90FFFC81ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FAA4ULL;
}

// FDE #3007 | PC: 0x08fab0..0x08fabc (12 B) | Symbol: sub_08fab0
// EN: AArch64 prologue [sub x20, x20, #8; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [sub x20, x20, #8; mov x0, x20; ret]
uint64_t fde_sub_08fab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xD1002294ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FAB0ULL;
}

// FDE #3008 | PC: 0x08fabc..0x08fac4 (8 B) | Symbol: sub_08fabc
// EN: AArch64 prologue [add x0, sp, #0x78; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x78; b #0x46c54]
uint64_t fde_sub_08fabc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDC65ULL) << 32) | 0x9101E3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FABCULL;
}

// FDE #3009 | PC: 0x08fac4..0x08facc (8 B) | Symbol: sub_08fac4
// EN: AArch64 prologue [add x0, sp, #0x78; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x78; b #0x937a0]
uint64_t fde_sub_08fac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000F36ULL) << 32) | 0x9101E3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FAC4ULL;
}

// FDE #3010 | PC: 0x08facc..0x08faf8 (44 B) | Symbol: sub_08facc
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x44b18; add x0, x19, #0x48; bl #0x44b18] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x44b18; add x0, x19, #0x48; bl #0x44b18]
uint64_t fde_sub_08facc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FED412ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FACCULL;
}

// FDE #3011 | PC: 0x08faf8..0x08fb00 (8 B) | Symbol: sub_08faf8
// EN: AArch64 prologue [add x1, x1, #0x428; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0x428; b #0x93910]
uint64_t fde_sub_08faf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000F85ULL) << 32) | 0x9110A021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FAF8ULL;
}

// FDE #3012 | PC: 0x08fb00..0x08fb08 (8 B) | Symbol: sub_08fb00
// EN: AArch64 prologue [add x1, x1, #0x940; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0x940; b #0x93910]
uint64_t fde_sub_08fb00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000F83ULL) << 32) | 0x91250021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB00ULL;
}

// FDE #3013 | PC: 0x08fb08..0x08fb14 (12 B) | Symbol: sub_08fb08
// EN: AArch64 prologue [mov x0, x19; mov x1, x22; b #0x89a50] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x22; b #0x89a50]
uint64_t fde_sub_08fb08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB08ULL;
}

// FDE #3014 | PC: 0x08fb14..0x08fb1c (8 B) | Symbol: sub_08fb14
// EN: AArch64 prologue [mov x0, x19; b #0x4696c] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x4696c]
uint64_t fde_sub_08fb14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDB95ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB14ULL;
}

// FDE #3015 | PC: 0x08fb1c..0x08fb28 (12 B) | Symbol: sub_08fb1c
// EN: AArch64 prologue [ldr x1, [sp, #8]; str xzr, [sp, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x1, [sp, #8]; str xzr, [sp, #8]; ret]
uint64_t fde_sub_08fb1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FFULL) << 32) | 0xF94007E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB1CULL;
}

// FDE #3016 | PC: 0x08fb28..0x08fb34 (12 B) | Symbol: sub_08fb28
// EN: AArch64 prologue [ldr x8, [x19]; ldr x9, [x8, x27, lsl #3]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; ldr x9, [x8, x27, lsl #3]; ret]
uint64_t fde_sub_08fb28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF87B7909ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB28ULL;
}

// FDE #3017 | PC: 0x08fb34..0x08fb40 (12 B) | Symbol: sub_08fb34
// EN: AArch64 prologue [ldr x8, [x19]; mov x0, x19; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; mov x0, x19; ret]
uint64_t fde_sub_08fb34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB34ULL;
}

// FDE #3018 | PC: 0x08fb40..0x08fb50 (16 B) | Symbol: sub_08fb40
// EN: AArch64 prologue [mov x19, x0; mov w0, #0x28; mov x20, x8; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov x19, x0; mov w0, #0x28; mov x20, x8; b #0x93320]
uint64_t fde_sub_08fb40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800500ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB40ULL;
}

// FDE #3019 | PC: 0x08fb50..0x08fb5c (12 B) | Symbol: sub_08fb50
// EN: AArch64 prologue [mov x19, x0; str x8, [sp, #0x128]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; str x8, [sp, #0x128]; ret]
uint64_t fde_sub_08fb50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90097E8ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB50ULL;
}

// FDE #3020 | PC: 0x08fb5c..0x08fb64 (8 B) | Symbol: sub_08fb5c
// EN: AArch64 prologue [mov x19, x0; b #0x44a14] | VI: Khởi đầu hàm AArch64 [mov x19, x0; b #0x44a14]
uint64_t fde_sub_08fb5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED3ADULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB5CULL;
}

// FDE #3021 | PC: 0x08fb64..0x08fb6c (8 B) | Symbol: sub_08fb64
// EN: AArch64 prologue [mov x19, x0; b #0x93290] | VI: Khởi đầu hàm AArch64 [mov x19, x0; b #0x93290]
uint64_t fde_sub_08fb64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000DCAULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB64ULL;
}

// FDE #3022 | PC: 0x08fb6c..0x08fb78 (12 B) | Symbol: sub_08fb6c
// EN: AArch64 prologue [mov x0, x24; mov x1, x23; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x24; mov x1, x23; ret]
uint64_t fde_sub_08fb6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0xAA1803E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB6CULL;
}

// FDE #3023 | PC: 0x08fb78..0x08fb84 (12 B) | Symbol: sub_08fb78
// EN: AArch64 prologue [ldr x9, [sp, #0x158]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x158]; cmp x8, x9; ret]
uint64_t fde_sub_08fb78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF940AFE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB78ULL;
}

// FDE #3024 | PC: 0x08fb84..0x08fb90 (12 B) | Symbol: sub_08fb84
// EN: AArch64 prologue [ldr x9, [sp, #0x168]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x168]; cmp x8, x9; ret]
uint64_t fde_sub_08fb84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF940B7E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB84ULL;
}

// FDE #3025 | PC: 0x08fb90..0x08fbb0 (32 B) | Symbol: sub_08fb90
// EN: AArch64 prologue [ldr w9, [x20]; adrp x10, #0x9b000; add x10, x10, #0x8f8; str x10, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr w9, [x20]; adrp x10, #0x9b000; add x10, x10, #0x8f8; str x10, [x8, #8]]
uint64_t fde_sub_08fb90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9000006AULL) << 32) | 0xB9400289ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB90ULL;
}

// FDE #3026 | PC: 0x08fbb0..0x08fbb8 (8 B) | Symbol: sub_08fbb0
// EN: AArch64 prologue [add x1, x1, #0xfea; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xfea; b #0x93910]
uint64_t fde_sub_08fbb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000F57ULL) << 32) | 0x913FA821ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBB0ULL;
}

// FDE #3027 | PC: 0x08fbb8..0x08fbc4 (12 B) | Symbol: sub_08fbb8
// EN: AArch64 prologue [ldrb w8, [x27, #0x17]; mov x1, x27; ret] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x27, #0x17]; mov x1, x27; ret]
uint64_t fde_sub_08fbb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1B03E1ULL) << 32) | 0x39405F68ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBB8ULL;
}

// FDE #3028 | PC: 0x08fbc4..0x08fbcc (8 B) | Symbol: sub_08fbc4
// EN: AArch64 prologue [add x0, sp, #0x20; b #0x756c8] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; b #0x756c8]
uint64_t fde_sub_08fbc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF96C0ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBC4ULL;
}

// FDE #3029 | PC: 0x08fbcc..0x08fbd4 (8 B) | Symbol: sub_08fbcc
// EN: AArch64 prologue [add x0, sp, #0x20; b #0x54c34] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; b #0x54c34]
uint64_t fde_sub_08fbcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF1419ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBCCULL;
}

// FDE #3030 | PC: 0x08fbd4..0x08fbe8 (20 B) | Symbol: sub_08fbd4
// EN: AArch64 prologue [strb wzr, [sp, #0x78]; strb wzr, [sp, #0xa0]; strb wzr, [sp, #0xa8]; strb wzr, [sp, #0xb8]] | VI: Khởi đầu hàm AArch64 [strb wzr, [sp, #0x78]; strb wzr, [sp, #0xa0]; strb wzr, [sp, #0xa8]; strb wzr, [sp, #0xb8]]
uint64_t fde_sub_08fbd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x390283FFULL) << 32) | 0x3901E3FFULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBD4ULL;
}

// FDE #3031 | PC: 0x08fbe8..0x08fc08 (32 B) | Symbol: sub_08fbe8
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0x188; str x8, [x19]; add x9, x8, #0xc8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0x188; str x8, [x19]; add x9, x8, #0xc8]
uint64_t fde_sub_08fbe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91062108ULL) << 32) | 0x90000068ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBE8ULL;
}

// FDE #3032 | PC: 0x08fc08..0x08fc14 (12 B) | Symbol: sub_08fc08
// EN: AArch64 prologue [sub x9, x9, x8; cmp x9, #0x17; ret] | VI: Khởi đầu hàm AArch64 [sub x9, x9, x8; cmp x9, #0x17; ret]
uint64_t fde_sub_08fc08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF1005D3FULL) << 32) | 0xCB080129ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC08ULL;
}

// FDE #3033 | PC: 0x08fc14..0x08fc1c (8 B) | Symbol: sub_08fc14
// EN: AArch64 prologue [add x0, sp, #0x48; b #0x4696c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x48; b #0x4696c]
uint64_t fde_sub_08fc14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDB55ULL) << 32) | 0x910123E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC14ULL;
}

// FDE #3034 | PC: 0x08fc1c..0x08fc30 (20 B) | Symbol: sub_08fc1c
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; add x0, sp, #0x20] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; add x0, sp, #0x20]
uint64_t fde_sub_08fc1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC1CULL;
}

// FDE #3035 | PC: 0x08fc30..0x08fc50 (32 B) | Symbol: sub_08fc30
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov w19, w1; adrp x1, #0x1c000] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov w19, w1; adrp x1, #0x1c000]
uint64_t fde_sub_08fc30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC30ULL;
}

// FDE #3036 | PC: 0x08fc50..0x08fc64 (20 B) | Symbol: sub_08fc50
// EN: AArch64 prologue [str x26, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x26, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_08fc50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163F9ULL) << 32) | 0xF81B0FFAULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC50ULL;
}

// FDE #3037 | PC: 0x08fc64..0x08fc6c (8 B) | Symbol: sub_08fc64
// EN: AArch64 prologue [mov w2, #0xd0; b #0x931f0] | VI: Khởi đầu hàm AArch64 [mov w2, #0xd0; b #0x931f0]
uint64_t fde_sub_08fc64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D62ULL) << 32) | 0x52801A02ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC64ULL;
}

// FDE #3038 | PC: 0x08fc6c..0x08fc78 (12 B) | Symbol: sub_08fc6c
// EN: AArch64 prologue [ldr x8, [x22]; mov x0, x22; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x22]; mov x0, x22; ret]
uint64_t fde_sub_08fc6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0xF94002C8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC6CULL;
}

// FDE #3039 | PC: 0x08fc78..0x08fc8c (20 B) | Symbol: sub_08fc78
// EN: AArch64 prologue [ldr x8, [x1]; mov x19, x0; str x8, [x0]; ldr x0, [x1, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; mov x19, x0; str x8, [x0]; ldr x0, [x1, #8]]
uint64_t fde_sub_08fc78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC78ULL;
}

// FDE #3040 | PC: 0x08fc8c..0x08fca0 (20 B) | Symbol: sub_08fc8c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x46c54; ldr x0, [x19, #8]; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x46c54; ldr x0, [x19, #8]; ldr x30, [sp], #0x10]
uint64_t fde_sub_08fc8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEDBF1ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC8CULL;
}

// FDE #3041 | PC: 0x08fca0..0x08fcb4 (20 B) | Symbol: sub_08fca0
// EN: AArch64 prologue [ldr x13, [x21]; ldr x14, [x13]; ldr x15, [x13, #0x10]; cmp x14, x15] | VI: Khởi đầu hàm AArch64 [ldr x13, [x21]; ldr x14, [x13]; ldr x15, [x13, #0x10]; cmp x14, x15]
uint64_t fde_sub_08fca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94001AEULL) << 32) | 0xF94002ADULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FCA0ULL;
}

// FDE #3042 | PC: 0x08fcb4..0x08fcc4 (16 B) | Symbol: sub_08fcb4
// EN: AArch64 prologue [adrp x5, #0xa0000; add x5, x5, #0x2a0; ldr x19, [x19, #8]; ret] | VI: Khởi đầu hàm AArch64 [adrp x5, #0xa0000; add x5, x5, #0x2a0; ldr x19, [x19, #8]; ret]
uint64_t fde_sub_08fcb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910A80A5ULL) << 32) | 0xB0000085ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FCB4ULL;
}

// FDE #3043 | PC: 0x08fcc4..0x08fccc (8 B) | Symbol: sub_08fcc4
// EN: AArch64 prologue [add x19, sp, #8; b #0x46964] | VI: Khởi đầu hàm AArch64 [add x19, sp, #8; b #0x46964]
uint64_t fde_sub_08fcc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDB27ULL) << 32) | 0x910023F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FCC4ULL;
}

// FDE #3044 | PC: 0x08fccc..0x08fcdc (16 B) | Symbol: sub_08fccc
// EN: AArch64 prologue [ldr x14, [x11]; ldr x16, [x11, #0x10]; cmp x14, x16; ret] | VI: Khởi đầu hàm AArch64 [ldr x14, [x11]; ldr x16, [x11, #0x10]; cmp x14, x16; ret]
uint64_t fde_sub_08fccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400970ULL) << 32) | 0xF940016EULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FCCCULL;
}

// FDE #3045 | PC: 0x08fcdc..0x08fcf4 (24 B) | Symbol: sub_08fcdc
// EN: AArch64 prologue [movi v0.2d, #0000000000000000; mov w0, #0x20; str x8, [x25]; stur q0, [x25, #0x28]] | VI: Khởi đầu hàm AArch64 [movi v0.2d, #0000000000000000; mov w0, #0x20; str x8, [x25]; stur q0, [x25, #0x28]]
uint64_t fde_sub_08fcdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800400ULL) << 32) | 0x6F00E400ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FCDCULL;
}

// FDE #3046 | PC: 0x08fcf4..0x08fcfc (8 B) | Symbol: sub_08fcf4
// EN: AArch64 prologue [mov w0, #0x68; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x68; b #0x93320]
uint64_t fde_sub_08fcf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D8AULL) << 32) | 0x52800D00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FCF4ULL;
}

// FDE #3047 | PC: 0x08fcfc..0x08fd14 (24 B) | Symbol: sub_08fcfc
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x50]; ldp x23, x22, [sp, #0x40]; ldp x25, x24, [sp, #0x30]; ldr x26, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x50]; ldp x23, x22, [sp, #0x40]; ldp x25, x24, [sp, #0x30]; ldr x26, [sp, #0x20]]
uint64_t fde_sub_08fcfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9445BF7ULL) << 32) | 0xA94553F5ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FCFCULL;
}

// FDE #3048 | PC: 0x08fd14..0x08fd2c (24 B) | Symbol: sub_08fd14
// EN: AArch64 prologue [lsl x8, x1, #2; cmp xzr, x1, lsr #62; csinv x20, x8, xzr, eq; mov x19, x0] | VI: Khởi đầu hàm AArch64 [lsl x8, x1, #2; cmp xzr, x1, lsr #62; csinv x20, x8, xzr, eq; mov x19, x0]
uint64_t fde_sub_08fd14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB41FBFFULL) << 32) | 0xD37EF428ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD14ULL;
}

// FDE #3049 | PC: 0x08fd2c..0x08fd38 (12 B) | Symbol: sub_08fd2c
// EN: AArch64 prologue [add x8, x22, #8; str x8, [x21]; ret] | VI: Khởi đầu hàm AArch64 [add x8, x22, #8; str x8, [x21]; ret]
uint64_t fde_sub_08fd2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90002A8ULL) << 32) | 0x910022C8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD2CULL;
}

// FDE #3050 | PC: 0x08fd38..0x08fd4c (20 B) | Symbol: sub_08fd38
// EN: AArch64 prologue [str xzr, [x8, #8]!; str x0, [x19, #8]; str x9, [x0]; stp x22, x0, [sp]] | VI: Khởi đầu hàm AArch64 [str xzr, [x8, #8]!; str x0, [x19, #8]; str x9, [x0]; stp x22, x0, [sp]]
uint64_t fde_sub_08fd38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000660ULL) << 32) | 0xF8008D1FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD38ULL;
}

// FDE #3051 | PC: 0x08fd4c..0x08fd58 (12 B) | Symbol: sub_08fd4c
// EN: AArch64 prologue [str x21, [x19, #8]; ldr x0, [x19]; ret] | VI: Khởi đầu hàm AArch64 [str x21, [x19, #8]; ldr x0, [x19]; ret]
uint64_t fde_sub_08fd4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400260ULL) << 32) | 0xF9000675ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD4CULL;
}

// FDE #3052 | PC: 0x08fd58..0x08fd68 (16 B) | Symbol: sub_08fd58
// EN: AArch64 prologue [cmp w8, #0xa; cset w8, eq; str w8, [sp, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0xa; cset w8, eq; str w8, [sp, #0x80]; ret]
uint64_t fde_sub_08fd58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E8ULL) << 32) | 0x7100291FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD58ULL;
}

// FDE #3053 | PC: 0x08fd68..0x08fd88 (32 B) | Symbol: sub_08fd68
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; add x9, x9, #1; mov x0, x21; str x9, [x8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; add x9, x9, #1; mov x0, x21; str x9, [x8]]
uint64_t fde_sub_08fd68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91000529ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD68ULL;
}

// FDE #3054 | PC: 0x08fd88..0x08fd90 (8 B) | Symbol: sub_08fd88
// EN: AArch64 prologue [add x0, sp, #0xc0; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xc0; b #0x46c54]
uint64_t fde_sub_08fd88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDBB2ULL) << 32) | 0x910303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD88ULL;
}

// FDE #3055 | PC: 0x08fd90..0x08fda0 (16 B) | Symbol: sub_08fd90
// EN: AArch64 prologue [ldr x9, [x8]; str x9, [x22]; str x22, [x8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [x8]; str x9, [x22]; str x22, [x8]; ret]
uint64_t fde_sub_08fd90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90002C9ULL) << 32) | 0xF9400109ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD90ULL;
}

// FDE #3056 | PC: 0x08fda0..0x08fda8 (8 B) | Symbol: sub_08fda0
// EN: AArch64 prologue [add x0, sp, #0x28; b #0x756c8] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x28; b #0x756c8]
uint64_t fde_sub_08fda0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9649ULL) << 32) | 0x9100A3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FDA0ULL;
}

// FDE #3057 | PC: 0x08fda8..0x08fdc8 (32 B) | Symbol: sub_08fda8
// EN: AArch64 prologue [str xzr, [sp, #0x10]; ldrb w8, [x19, #0x38]; add x9, x19, #0x30; add x10, sp, #0x10] | VI: Khởi đầu hàm AArch64 [str xzr, [sp, #0x10]; ldrb w8, [x19, #0x38]; add x9, x19, #0x30; add x10, sp, #0x10]
uint64_t fde_sub_08fda8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940E268ULL) << 32) | 0xF9000BFFULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FDA8ULL;
}

// FDE #3058 | PC: 0x08fdc8..0x08fdd8 (16 B) | Symbol: sub_08fdc8
// EN: AArch64 prologue [lsl x8, x9, #1; cmp x8, x1; csel x8, x1, x8, lo; ret] | VI: Khởi đầu hàm AArch64 [lsl x8, x9, #1; cmp x8, x1; csel x8, x1, x8, lo; ret]
uint64_t fde_sub_08fdc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB01011FULL) << 32) | 0xD37FF928ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FDC8ULL;
}

// FDE #3059 | PC: 0x08fdd8..0x08fdf8 (32 B) | Symbol: sub_08fdd8
// EN: AArch64 prologue [sub x9, x9, x10; mov w10, #0x28; sdiv x9, x9, x10; mov x10, #0x3333333333333333] | VI: Khởi đầu hàm AArch64 [sub x9, x9, x10; mov w10, #0x28; sdiv x9, x9, x10; mov x10, #0x3333333333333333]
uint64_t fde_sub_08fdd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280050AULL) << 32) | 0xCB0A0129ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FDD8ULL;
}

// FDE #3060 | PC: 0x08fdf8..0x08fe00 (8 B) | Symbol: sub_08fdf8
// EN: AArch64 prologue [ldr w1, [x20, #0x18]; b #0x496f8] | VI: Khởi đầu hàm AArch64 [ldr w1, [x20, #0x18]; b #0x496f8]
uint64_t fde_sub_08fdf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE63FULL) << 32) | 0xB9401A81ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FDF8ULL;
}

// FDE #3061 | PC: 0x08fe00..0x08fe18 (24 B) | Symbol: sub_08fe00
// EN: AArch64 prologue [ldr w2, [x19]; add x0, sp, #0x40; mov x1, x20; mov v0.16b, v9.16b] | VI: Khởi đầu hàm AArch64 [ldr w2, [x19]; add x0, sp, #0x40; mov x1, x20; mov v0.16b, v9.16b]
uint64_t fde_sub_08fe00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910103E0ULL) << 32) | 0xB9400262ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE00ULL;
}

// FDE #3062 | PC: 0x08fe18..0x08fe38 (32 B) | Symbol: sub_08fe18
// EN: AArch64 prologue [ldr q1, [x19]; dup v0.4s, v0.s[0]; fsub v2.4s, v1.4s, v0.4s; fadd v0.4s, v1.4s, v0.4s] | VI: Khởi đầu hàm AArch64 [ldr q1, [x19]; dup v0.4s, v0.s[0]; fsub v2.4s, v1.4s, v0.4s; fadd v0.4s, v1.4s, v0.4s]
uint64_t fde_sub_08fe18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4E040400ULL) << 32) | 0x3DC00261ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE18ULL;
}

// FDE #3063 | PC: 0x08fe38..0x08fe40 (8 B) | Symbol: sub_08fe38
// EN: AArch64 prologue [add x0, x8, #0x28; b #0x4722c] | VI: Khởi đầu hàm AArch64 [add x0, x8, #0x28; b #0x4722c]
uint64_t fde_sub_08fe38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDCFCULL) << 32) | 0x9100A100ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE38ULL;
}

// FDE #3064 | PC: 0x08fe40..0x08fe60 (32 B) | Symbol: sub_08fe40
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; and w22, w1, #1; str x8, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; and w22, w1, #1; str x8, [sp, #0x28]]
uint64_t fde_sub_08fe40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE40ULL;
}

// FDE #3065 | PC: 0x08fe60..0x08fe70 (16 B) | Symbol: sub_08fe60
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x20, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x20, x0; ret]
uint64_t fde_sub_08fe60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE60ULL;
}

// FDE #3066 | PC: 0x08fe70..0x08fe7c (12 B) | Symbol: sub_08fe70
// EN: AArch64 prologue [ldr x0, [x20, #0x10]; mov x1, sp; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20, #0x10]; mov x1, sp; ret]
uint64_t fde_sub_08fe70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E1ULL) << 32) | 0xF9400A80ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE70ULL;
}

// FDE #3067 | PC: 0x08fe7c..0x08fe8c (16 B) | Symbol: sub_08fe7c
// EN: AArch64 prologue [add x9, x8, #0x58; fmov d0, x8; mov v0.d[1], x9; ret] | VI: Khởi đầu hàm AArch64 [add x9, x8, #0x58; fmov d0, x8; mov v0.d[1], x9; ret]
uint64_t fde_sub_08fe7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E670100ULL) << 32) | 0x91016109ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE7CULL;
}

// FDE #3068 | PC: 0x08fe8c..0x08fe98 (12 B) | Symbol: sub_08fe8c
// EN: AArch64 prologue [mov w10, #0x18; madd x8, x9, x10, x8; ret] | VI: Khởi đầu hàm AArch64 [mov w10, #0x18; madd x8, x9, x10, x8; ret]
uint64_t fde_sub_08fe8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B0A2128ULL) << 32) | 0x5280030AULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE8CULL;
}

// FDE #3069 | PC: 0x08fe98..0x08fea8 (16 B) | Symbol: sub_08fe98
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str wzr, [x8, #0x18]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str wzr, [x8, #0x18]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_08fe98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB900191FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE98ULL;
}

// FDE #3070 | PC: 0x08fea8..0x08feb4 (12 B) | Symbol: sub_08fea8
// EN: AArch64 prologue [mov v0.16b, v9.16b; mov v1.16b, v8.16b; ret] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v9.16b; mov v1.16b, v8.16b; ret]
uint64_t fde_sub_08fea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA81D01ULL) << 32) | 0x4EA91D20ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FEA8ULL;
}

// FDE #3071 | PC: 0x08feb4..0x08fecc (24 B) | Symbol: sub_08feb4
// EN: AArch64 prologue [stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]; stp x22, x21, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]; stp x22, x21, [sp, #0x70]]
uint64_t fde_sub_08feb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90567FAULL) << 32) | 0xA9046FFCULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FEB4ULL;
}

// FDE #3072 | PC: 0x08fecc..0x08fee0 (20 B) | Symbol: sub_08fecc
// EN: AArch64 prologue [mov w9, #0x20; cmp w8, #0; mov w8, #8; csel x8, x9, x8, eq] | VI: Khởi đầu hàm AArch64 [mov w9, #0x20; cmp w8, #0; mov w8, #8; csel x8, x9, x8, eq]
uint64_t fde_sub_08fecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100011FULL) << 32) | 0x52800409ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FECCULL;
}

// FDE #3073 | PC: 0x08fee0..0x08fef8 (24 B) | Symbol: sub_08fee0
// EN: AArch64 prologue [cmp w11, #0; csel x9, x9, x12, eq; ldr x0, [x8, #8]; ldr w23, [x10]] | VI: Khởi đầu hàm AArch64 [cmp w11, #0; csel x9, x9, x12, eq; ldr x0, [x8, #8]; ldr w23, [x10]]
uint64_t fde_sub_08fee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A8C0129ULL) << 32) | 0x7100017FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FEE0ULL;
}

// FDE #3074 | PC: 0x08fef8..0x08ff0c (20 B) | Symbol: sub_08fef8
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x7d610; mov x0, x19; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x7d610; mov x0, x19; ldr x30, [sp], #0x10]
uint64_t fde_sub_08fef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FFB5C5ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FEF8ULL;
}

// FDE #3075 | PC: 0x08ff0c..0x08ff1c (16 B) | Symbol: sub_08ff0c
// EN: AArch64 prologue [mrs x25, tpidr_el0; ldr x8, [x25, #0x28]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x25, tpidr_el0; ldr x8, [x25, #0x28]; mov x19, x0; ret]
uint64_t fde_sub_08ff0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401728ULL) << 32) | 0xD53BD059ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF0CULL;
}

// FDE #3076 | PC: 0x08ff1c..0x08ff28 (12 B) | Symbol: sub_08ff1c
// EN: AArch64 prologue [mov x0, x20; mov w2, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov w2, wzr; ret]
uint64_t fde_sub_08ff1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E2ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF1CULL;
}

// FDE #3077 | PC: 0x08ff28..0x08ff30 (8 B) | Symbol: sub_08ff28
// EN: AArch64 prologue [mov x0, x20; b #0x93680] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x93680]
uint64_t fde_sub_08ff28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000DD5ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF28ULL;
}

// FDE #3078 | PC: 0x08ff30..0x08ff38 (8 B) | Symbol: sub_08ff30
// EN: AArch64 prologue [mov w0, #8; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #8; b #0x93320]
uint64_t fde_sub_08ff30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000CFBULL) << 32) | 0x52800100ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF30ULL;
}

// FDE #3079 | PC: 0x08ff38..0x08ff48 (16 B) | Symbol: sub_08ff38
// EN: AArch64 prologue [cmp x22, x0; csel x1, x0, x22, lo; cmp x1, x23; ret] | VI: Khởi đầu hàm AArch64 [cmp x22, x0; csel x1, x0, x22, lo; cmp x1, x23; ret]
uint64_t fde_sub_08ff38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A963001ULL) << 32) | 0xEB0002DFULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF38ULL;
}

// FDE #3080 | PC: 0x08ff48..0x08ff58 (16 B) | Symbol: sub_08ff48
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xc99; add x0, sp, #0x40; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xc99; add x0, sp, #0x40; ret]
uint64_t fde_sub_08ff48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91326421ULL) << 32) | 0xB0FFFC61ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF48ULL;
}

// FDE #3081 | PC: 0x08ff58..0x08ff60 (8 B) | Symbol: sub_08ff58
// EN: AArch64 prologue [str x8, [x20]; b #0x47fbc] | VI: Khởi đầu hàm AArch64 [str x8, [x20]; b #0x47fbc]
uint64_t fde_sub_08ff58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE018ULL) << 32) | 0xF9000288ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF58ULL;
}

// FDE #3082 | PC: 0x08ff60..0x08ff74 (20 B) | Symbol: sub_08ff60
// EN: AArch64 prologue [ldp q0, q1, [x8, #0x20]; ldp q2, q3, [x8]; stp q0, q1, [x9, #0x20]; stp q2, q3, [x9]] | VI: Khởi đầu hàm AArch64 [ldp q0, q1, [x8, #0x20]; ldp q2, q3, [x8]; stp q0, q1, [x9, #0x20]; stp q2, q3, [x9]]
uint64_t fde_sub_08ff60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAD400D02ULL) << 32) | 0xAD410500ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF60ULL;
}

// FDE #3083 | PC: 0x08ff74..0x08ff94 (32 B) | Symbol: sub_08ff74
// EN: AArch64 prologue [adrp x10, #0x98000; add x8, sp, #0x30; mov w9, #1; add x10, x10, #0xad0] | VI: Khởi đầu hàm AArch64 [adrp x10, #0x98000; add x8, sp, #0x30; mov w9, #1; add x10, x10, #0xad0]
uint64_t fde_sub_08ff74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C3E8ULL) << 32) | 0xB000004AULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF74ULL;
}

// FDE #3084 | PC: 0x08ff94..0x08ffa0 (12 B) | Symbol: sub_08ff94
// EN: AArch64 prologue [ldr x9, [sp, #0x88]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x88]; cmp x8, x9; ret]
uint64_t fde_sub_08ff94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94047E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF94ULL;
}

// FDE #3085 | PC: 0x08ffa0..0x08ffb8 (24 B) | Symbol: sub_08ffa0
// EN: AArch64 prologue [scvtf s0, w8; scvtf s1, w9; fcvtzs w8, s0; fcvtzs w9, s1] | VI: Khởi đầu hàm AArch64 [scvtf s0, w8; scvtf s1, w9; fcvtzs w8, s0; fcvtzs w9, s1]
uint64_t fde_sub_08ffa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E220121ULL) << 32) | 0x1E220100ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FFA0ULL;
}

// FDE #3086 | PC: 0x08ffb8..0x08ffc0 (8 B) | Symbol: sub_08ffb8
// EN: AArch64 prologue [add x1, x1, #0xbd6; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xbd6; b #0x93910]
uint64_t fde_sub_08ffb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000E55ULL) << 32) | 0x912F5821ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FFB8ULL;
}

// FDE #3087 | PC: 0x08ffc0..0x08ffc8 (8 B) | Symbol: sub_08ffc0
// EN: AArch64 prologue [mov x2, x21; b #0x6bb10] | VI: Khởi đầu hàm AArch64 [mov x2, x21; b #0x6bb10]
uint64_t fde_sub_08ffc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF6ED3ULL) << 32) | 0xAA1503E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FFC0ULL;
}

// FDE #3088 | PC: 0x08ffc8..0x08ffe0 (24 B) | Symbol: sub_08ffc8
// EN: AArch64 prologue [mov x2, x21; mov w3, w23; mov x4, x19; mov x5, x22] | VI: Khởi đầu hàm AArch64 [mov x2, x21; mov w3, w23; mov x4, x19; mov x5, x22]
uint64_t fde_sub_08ffc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1703E3ULL) << 32) | 0xAA1503E2ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FFC8ULL;
}

// FDE #3089 | PC: 0x08ffe0..0x08fff8 (24 B) | Symbol: sub_08ffe0
// EN: AArch64 prologue [ldr x8, [x19, #0x30]; ldr q0, [x19, #0x20]; add x0, x19, #0x20; str x8, [x20, #0x30]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x30]; ldr q0, [x19, #0x20]; add x0, x19, #0x20; str x8, [x20, #0x30]]
uint64_t fde_sub_08ffe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC00A60ULL) << 32) | 0xF9401A68ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FFE0ULL;
}

// FDE #3090 | PC: 0x08fff8..0x090004 (12 B) | Symbol: sub_08fff8
// EN: AArch64 prologue [mov x0, x22; mov x1, x21; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x21; ret]
uint64_t fde_sub_08fff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FFF8ULL;
}

// FDE #3091 | PC: 0x090004..0x09000c (8 B) | Symbol: sub_090004
// EN: AArch64 prologue [mov x0, x22; b #0x4722c] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x4722c]
uint64_t fde_sub_090004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDC89ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090004ULL;
}

// FDE #3092 | PC: 0x09000c..0x090028 (28 B) | Symbol: sub_09000c
// EN: AArch64 prologue [ldrb w8, [x1]; ldp x10, x9, [x1, #8]; lsr x11, x8, #1; tst w8, #1] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x1]; ldp x10, x9, [x1, #8]; lsr x11, x8, #1; tst w8, #1]
uint64_t fde_sub_09000c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA940A42AULL) << 32) | 0x39400028ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09000CULL;
}

// FDE #3093 | PC: 0x090028..0x09003c (20 B) | Symbol: sub_090028
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x19, x0; mov x0, x1] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x19, x0; mov x0, x1]
uint64_t fde_sub_090028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090028ULL;
}

// FDE #3094 | PC: 0x09003c..0x09005c (32 B) | Symbol: sub_09003c
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov v8.16b, v0.16b; mov x19, x0] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov v8.16b, v0.16b; mov x19, x0]
uint64_t fde_sub_09003c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09003CULL;
}

// FDE #3095 | PC: 0x09005c..0x09007c (32 B) | Symbol: sub_09005c
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; adrp x1, #0x1c000; mov x20, x2] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; adrp x1, #0x1c000; mov x20, x2]
uint64_t fde_sub_09005c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09005CULL;
}

// FDE #3096 | PC: 0x09007c..0x090084 (8 B) | Symbol: sub_09007c
// EN: AArch64 prologue [mov x2, x22; b #0x7cc88] | VI: Khởi đầu hàm AArch64 [mov x2, x22; b #0x7cc88]
uint64_t fde_sub_09007c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB302ULL) << 32) | 0xAA1603E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09007CULL;
}

// FDE #3097 | PC: 0x090084..0x090098 (20 B) | Symbol: sub_090084
// EN: AArch64 prologue [ldr x8, [x19, #0x28]; str x8, [sp, #0x188]; ldr x8, [x19, #0x30]; str x8, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x28]; str x8, [sp, #0x188]; ldr x8, [x19, #0x30]; str x8, [sp, #0x190]]
uint64_t fde_sub_090084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900C7E8ULL) << 32) | 0xF9401668ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090084ULL;
}

// FDE #3098 | PC: 0x090098..0x0900b8 (32 B) | Symbol: sub_090098
// EN: AArch64 prologue [cmp w8, #0; csel x8, x24, x23, eq; ldr s0, [x20, x8]; mov w25, #0x10] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; csel x8, x24, x23, eq; ldr s0, [x20, x8]; mov w25, #0x10]
uint64_t fde_sub_090098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A970308ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090098ULL;
}

// FDE #3099 | PC: 0x0900b8..0x0900d8 (32 B) | Symbol: sub_0900b8
// EN: AArch64 prologue [ldrb w9, [x20, #0x1c]; mov w10, #0x18; cmp w9, #0; mov w9, #0x20] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x20, #0x1c]; mov w10, #0x18; cmp w9, #0; mov w9, #0x20]
uint64_t fde_sub_0900b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280030AULL) << 32) | 0x39407289ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0900B8ULL;
}

// FDE #3100 | PC: 0x0900d8..0x0900e4 (12 B) | Symbol: sub_0900d8
// EN: AArch64 prologue [ldr x8, [x19, #0x10]; cmp x8, x20; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x10]; cmp x8, x20; ret]
uint64_t fde_sub_0900d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB14011FULL) << 32) | 0xF9400A68ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0900D8ULL;
}

// FDE #3101 | PC: 0x0900e4..0x090104 (32 B) | Symbol: sub_0900e4
// EN: AArch64 prologue [ldr x9, [x0, #8]; mov x19, x0; add x3, x0, #0x10; add x0, sp, #8] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #8]; mov x19, x0; add x3, x0, #0x10; add x0, sp, #8]
uint64_t fde_sub_0900e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF9400409ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0900E4ULL;
}

// FDE #3102 | PC: 0x090104..0x090118 (20 B) | Symbol: sub_090104
// EN: AArch64 prologue [str x8, [x0]; stur q1, [x0, #8]; str x9, [x0, #0x28]; stur q0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; stur q1, [x0, #8]; str x9, [x0, #0x28]; stur q0, [x0, #0x18]]
uint64_t fde_sub_090104(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3C808001ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090104ULL;
}

// FDE #3103 | PC: 0x090118..0x090128 (16 B) | Symbol: sub_090118
// EN: AArch64 prologue [asr x8, x8, #2; cmp x8, x9; csel x25, x9, x8, lo; ret] | VI: Khởi đầu hàm AArch64 [asr x8, x8, #2; cmp x8, x9; csel x25, x9, x8, lo; ret]
uint64_t fde_sub_090118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0x9342FD08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090118ULL;
}

// FDE #3104 | PC: 0x090128..0x090134 (12 B) | Symbol: sub_090128
// EN: AArch64 prologue [ldr x0, [x19, #0x10]; mov x1, sp; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0x10]; mov x1, sp; ret]
uint64_t fde_sub_090128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E1ULL) << 32) | 0xF9400A60ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090128ULL;
}

// FDE #3105 | PC: 0x090134..0x090140 (12 B) | Symbol: sub_090134
// EN: AArch64 prologue [ldr x0, [x19, #0x10]; add x1, sp, #8; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0x10]; add x1, sp, #8; ret]
uint64_t fde_sub_090134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E1ULL) << 32) | 0xF9400A60ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090134ULL;
}

// FDE #3106 | PC: 0x090140..0x090150 (16 B) | Symbol: sub_090140
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xe30; add x0, sp, #8; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xe30; add x0, sp, #8; ret]
uint64_t fde_sub_090140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9138C021ULL) << 32) | 0x90FFFC61ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090140ULL;
}

// FDE #3107 | PC: 0x090150..0x090158 (8 B) | Symbol: sub_090150
// EN: AArch64 prologue [add sp, sp, #0xf0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0xf0; ret]
uint64_t fde_sub_090150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9103C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090150ULL;
}

// FDE #3108 | PC: 0x090158..0x090164 (12 B) | Symbol: sub_090158
// EN: AArch64 prologue [mov x0, x23; mov x1, x22; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x23; mov x1, x22; ret]
uint64_t fde_sub_090158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090158ULL;
}

// FDE #3109 | PC: 0x090164..0x090174 (16 B) | Symbol: sub_090164
// EN: AArch64 prologue [ldr x8, [x8, #8]; sub x9, x25, #1; tst x25, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #8]; sub x9, x25, #1; tst x25, x9; ret]
uint64_t fde_sub_090164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1000729ULL) << 32) | 0xF9400508ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090164ULL;
}

// FDE #3110 | PC: 0x090174..0x09017c (8 B) | Symbol: sub_090174
// EN: AArch64 prologue [mov v0.16b, v8.16b; b #0x49298] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v8.16b; b #0x49298]
uint64_t fde_sub_090174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE448ULL) << 32) | 0x4EA81D00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090174ULL;
}

// FDE #3111 | PC: 0x09017c..0x090188 (12 B) | Symbol: sub_09017c
// EN: AArch64 prologue [mov v0.16b, v8.16b; mov v1.16b, v9.16b; ret] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v8.16b; mov v1.16b, v9.16b; ret]
uint64_t fde_sub_09017c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA91D21ULL) << 32) | 0x4EA81D00ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09017CULL;
}

// FDE #3112 | PC: 0x090188..0x0901a0 (24 B) | Symbol: sub_090188
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x1a0]; ldp x23, x22, [sp, #0x190]; ldp x25, x24, [sp, #0x180]; ldr x28, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x1a0]; ldp x23, x22, [sp, #0x190]; ldp x25, x24, [sp, #0x180]; ldr x28, [sp, #0x170]]
uint64_t fde_sub_090188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9595BF7ULL) << 32) | 0xA95A53F5ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090188ULL;
}

// FDE #3113 | PC: 0x0901a0..0x0901b0 (16 B) | Symbol: sub_0901a0
// EN: AArch64 prologue [str x8, [x19]; add x9, x8, #0xc8; add x8, x8, #0xe8; ret] | VI: Khởi đầu hàm AArch64 [str x8, [x19]; add x9, x8, #0xc8; add x8, x8, #0xe8; ret]
uint64_t fde_sub_0901a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91032109ULL) << 32) | 0xF9000268ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0901A0ULL;
}

// FDE #3114 | PC: 0x0901b0..0x0901e0 (48 B) | Symbol: sub_0901b0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; add x0, x19, #0x70; bl #0x44b18; add x0, x19, #0x68] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; add x0, x19, #0x70; bl #0x44b18; add x0, x19, #0x68]
uint64_t fde_sub_0901b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9101C260ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0901B0ULL;
}

// FDE #3115 | PC: 0x0901e0..0x0901f8 (24 B) | Symbol: sub_0901e0
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x6ad; add x0, sp, #0xd0; add x2, sp, #0x80] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x6ad; add x0, sp, #0xd0; add x2, sp, #0x80]
uint64_t fde_sub_0901e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911AB421ULL) << 32) | 0xF0FFFC61ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0901E0ULL;
}

// FDE #3116 | PC: 0x0901f8..0x090210 (24 B) | Symbol: sub_0901f8
// EN: AArch64 prologue [mov w0, #0x10; mov v8.16b, v0.16b; mov v9.16b, v1.16b; mov v10.16b, v2.16b] | VI: Khởi đầu hàm AArch64 [mov w0, #0x10; mov v8.16b, v0.16b; mov v9.16b, v1.16b; mov v10.16b, v2.16b]
uint64_t fde_sub_0901f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA01C08ULL) << 32) | 0x52800200ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0901F8ULL;
}

// FDE #3117 | PC: 0x090210..0x090224 (20 B) | Symbol: sub_090210
// EN: AArch64 prologue [mov x20, x0; str xzr, [x0, #0x10]; str xzr, [x29, #8]!; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [mov x20, x0; str xzr, [x0, #0x10]; str xzr, [x29, #8]!; str x8, [x0]]
uint64_t fde_sub_090210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900081FULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090210ULL;
}

// FDE #3118 | PC: 0x090224..0x090230 (12 B) | Symbol: sub_090224
// EN: AArch64 prologue [ldr x0, [sp, #0x18]; str xzr, [sp, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x18]; str xzr, [sp, #0x18]; ret]
uint64_t fde_sub_090224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000FFFULL) << 32) | 0xF9400FE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090224ULL;
}

// FDE #3119 | PC: 0x090230..0x090240 (16 B) | Symbol: sub_090230
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xe06; add x0, sp, #0x28; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xe06; add x0, sp, #0x28; ret]
uint64_t fde_sub_090230(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91381821ULL) << 32) | 0x90FFFC61ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090230ULL;
}

// FDE #3120 | PC: 0x090240..0x090260 (32 B) | Symbol: sub_090240
// EN: AArch64 prologue [str wzr, [sp, #0xc]; ldrb w8, [x20, #0xc]; add x9, x20, #8; mov w0, #0x90] | VI: Khởi đầu hàm AArch64 [str wzr, [sp, #0xc]; ldrb w8, [x20, #0xc]; add x9, x20, #8; mov w0, #0x90]
uint64_t fde_sub_090240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39403288ULL) << 32) | 0xB9000FFFULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090240ULL;
}

// FDE #3121 | PC: 0x090260..0x090268 (8 B) | Symbol: sub_090260
// EN: AArch64 prologue [add x0, sp, #0xd0; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xd0; b #0x46c54]
uint64_t fde_sub_090260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDA7CULL) << 32) | 0x910343E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090260ULL;
}

// FDE #3122 | PC: 0x090268..0x090270 (8 B) | Symbol: sub_090268
// EN: AArch64 prologue [add x0, sp, #0xd0; b #0x6d0bc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xd0; b #0x6d0bc]
uint64_t fde_sub_090268(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF7394ULL) << 32) | 0x910343E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090268ULL;
}

// FDE #3123 | PC: 0x090270..0x090278 (8 B) | Symbol: sub_090270
// EN: AArch64 prologue [add x20, sp, #0x78; b #0x46964] | VI: Khởi đầu hàm AArch64 [add x20, sp, #0x78; b #0x46964]
uint64_t fde_sub_090270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED9BCULL) << 32) | 0x9101E3F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090270ULL;
}

// FDE #3124 | PC: 0x090278..0x09028c (20 B) | Symbol: sub_090278
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x7c7bc; ldr x8, [x19]; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x7c7bc; ldr x8, [x19]; ldr x30, [sp], #0x10]
uint64_t fde_sub_090278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FFB150ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090278ULL;
}

// FDE #3125 | PC: 0x09028c..0x09029c (16 B) | Symbol: sub_09028c
// EN: AArch64 prologue [ldr x1, [sp, #8]; mov x0, x22; str xzr, [sp, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x1, [sp, #8]; mov x0, x22; str xzr, [sp, #8]; ret]
uint64_t fde_sub_09028c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0xF94007E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09028CULL;
}

// FDE #3126 | PC: 0x09029c..0x0902b4 (24 B) | Symbol: sub_09029c
// EN: AArch64 prologue [ldr x8, [x19]; ldur x8, [x8, #-0x18]; add x21, x19, x8; ldr x22, [x21, #0x28]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; ldur x8, [x8, #-0x18]; add x21, x19, x8; ldr x22, [x21, #0x28]]
uint64_t fde_sub_09029c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09029CULL;
}

// FDE #3127 | PC: 0x0902b4..0x0902c0 (12 B) | Symbol: sub_0902b4
// EN: AArch64 prologue [mov x19, x0; str x8, [x0], #8; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; str x8, [x0], #8; ret]
uint64_t fde_sub_0902b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8008408ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0902B4ULL;
}

// FDE #3128 | PC: 0x0902c0..0x0902d4 (20 B) | Symbol: sub_0902c0
// EN: AArch64 prologue [mov x19, x0; add x0, sp, #8; mov x1, x22; add x24, sp, #8] | VI: Khởi đầu hàm AArch64 [mov x19, x0; add x0, sp, #8; mov x1, x22; add x24, sp, #8]
uint64_t fde_sub_0902c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E0ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0902C0ULL;
}

// FDE #3129 | PC: 0x0902d4..0x0902ec (24 B) | Symbol: sub_0902d4
// EN: AArch64 prologue [mov x19, x0; stp x8, x21, [x0]; str x20, [x0, #0x10]; add x0, sp, #0x70] | VI: Khởi đầu hàm AArch64 [mov x19, x0; stp x8, x21, [x0]; str x20, [x0, #0x10]; add x0, sp, #0x70]
uint64_t fde_sub_0902d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9005408ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0902D4ULL;
}

// FDE #3130 | PC: 0x0902ec..0x090300 (20 B) | Symbol: sub_0902ec
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; mov x0, sp] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; mov x0, sp]
uint64_t fde_sub_0902ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0902ECULL;
}

// FDE #3131 | PC: 0x090300..0x090310 (16 B) | Symbol: sub_090300
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #0x18]; ret]
uint64_t fde_sub_090300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090300ULL;
}

// FDE #3132 | PC: 0x090310..0x09032c (28 B) | Symbol: sub_090310
// EN: AArch64 prologue [mov x8, x19; ldr x9, [x8, #0x10]!; str x9, [x21]; str x21, [x8]] | VI: Khởi đầu hàm AArch64 [mov x8, x19; ldr x9, [x8, #0x10]!; str x9, [x21]; str x21, [x8]]
uint64_t fde_sub_090310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8410D09ULL) << 32) | 0xAA1303E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090310ULL;
}

// FDE #3133 | PC: 0x09032c..0x090334 (8 B) | Symbol: sub_09032c
// EN: AArch64 prologue [add sp, sp, #0x1b0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x1b0; ret]
uint64_t fde_sub_09032c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9106C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09032CULL;
}

// FDE #3134 | PC: 0x090334..0x09033c (8 B) | Symbol: sub_090334
// EN: AArch64 prologue [mov x1, x29; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x29; b #0x93910]
uint64_t fde_sub_090334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D76ULL) << 32) | 0xAA1D03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090334ULL;
}

// FDE #3135 | PC: 0x09033c..0x090350 (20 B) | Symbol: sub_09033c
// EN: AArch64 prologue [ldr x1, [sp, #0x50]; add x0, x19, #0x88; add x21, x19, #8; str xzr, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [ldr x1, [sp, #0x50]; add x0, x19, #0x88; add x21, x19, #8; str xzr, [sp, #0x50]]
uint64_t fde_sub_09033c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91022260ULL) << 32) | 0xF9402BE1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09033CULL;
}

// FDE #3136 | PC: 0x090350..0x090358 (8 B) | Symbol: sub_090350
// EN: AArch64 prologue [add x1, x1, #0xf26; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xf26; b #0x93910]
uint64_t fde_sub_090350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D6FULL) << 32) | 0x913C9821ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090350ULL;
}

// FDE #3137 | PC: 0x090358..0x090364 (12 B) | Symbol: sub_090358
// EN: AArch64 prologue [add x0, sp, #0x1f0; add x1, sp, #0x120; b #0x78aec] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x1f0; add x1, sp, #0x120; b #0x78aec]
uint64_t fde_sub_090358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910483E1ULL) << 32) | 0x9107C3E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090358ULL;
}

// FDE #3138 | PC: 0x090364..0x09036c (8 B) | Symbol: sub_090364
// EN: AArch64 prologue [stp xzr, xzr, [sp, #0x88]; b #0x497b4] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [sp, #0x88]; b #0x497b4]
uint64_t fde_sub_090364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE513ULL) << 32) | 0xA908FFFFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090364ULL;
}

// FDE #3139 | PC: 0x09036c..0x090374 (8 B) | Symbol: sub_09036c
// EN: AArch64 prologue [add x0, sp, #0x20; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; b #0x937a0]
uint64_t fde_sub_09036c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D0CULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09036CULL;
}

// FDE #3140 | PC: 0x090374..0x09037c (8 B) | Symbol: sub_090374
// EN: AArch64 prologue [add x0, sp, #0x20; b #0x4696c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; b #0x4696c]
uint64_t fde_sub_090374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED97DULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090374ULL;
}

// FDE #3141 | PC: 0x09037c..0x090388 (12 B) | Symbol: sub_09037c
// EN: AArch64 prologue [udiv x8, x19, x23; msub x21, x8, x23, x19; ret] | VI: Khởi đầu hàm AArch64 [udiv x8, x19, x23; msub x21, x8, x23, x19; ret]
uint64_t fde_sub_09037c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B17CD15ULL) << 32) | 0x9AD70A68ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09037CULL;
}

// FDE #3142 | PC: 0x090388..0x09039c (20 B) | Symbol: sub_090388
// EN: AArch64 prologue [ldr x22, [sp, #0xb0]; add x0, sp, #0x78; mov x1, x24; mov x2, x23] | VI: Khởi đầu hàm AArch64 [ldr x22, [sp, #0xb0]; add x0, sp, #0x78; mov x1, x24; mov x2, x23]
uint64_t fde_sub_090388(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9101E3E0ULL) << 32) | 0xF9405BF6ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090388ULL;
}

// FDE #3143 | PC: 0x09039c..0x0903a4 (8 B) | Symbol: sub_09039c
// EN: AArch64 prologue [add x0, sp, #0x48; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x48; b #0x937a0]
uint64_t fde_sub_09039c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D00ULL) << 32) | 0x910123E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09039CULL;
}

// FDE #3144 | PC: 0x0903a4..0x0903b8 (20 B) | Symbol: sub_0903a4
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; str x8, [sp, #0x18]] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; str x8, [sp, #0x18]]
uint64_t fde_sub_0903a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0903A4ULL;
}

// FDE #3145 | PC: 0x0903b8..0x0903d4 (28 B) | Symbol: sub_0903b8
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; str x8, [sp, #0x28]; ldr x20, [x0, #0x98]] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; str x8, [sp, #0x28]; ldr x20, [x0, #0x98]]
uint64_t fde_sub_0903b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0903B8ULL;
}

// FDE #3146 | PC: 0x0903d4..0x0903e8 (20 B) | Symbol: sub_0903d4
// EN: AArch64 prologue [ldr x19, [x20, #0x18]; add x0, sp, #0xd0; mov x1, x20; add x21, sp, #0xd0] | VI: Khởi đầu hàm AArch64 [ldr x19, [x20, #0x18]; add x0, sp, #0xd0; mov x1, x20; add x21, sp, #0xd0]
uint64_t fde_sub_0903d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910343E0ULL) << 32) | 0xF9400E93ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0903D4ULL;
}

// FDE #3147 | PC: 0x0903e8..0x0903f4 (12 B) | Symbol: sub_0903e8
// EN: AArch64 prologue [mov x19, x2; mov x2, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x2, x1; ret]
uint64_t fde_sub_0903e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E2ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0903E8ULL;
}

// FDE #3148 | PC: 0x0903f4..0x090400 (12 B) | Symbol: sub_0903f4
// EN: AArch64 prologue [mov w2, #0xd0; mov x0, x8; b #0x931f0] | VI: Khởi đầu hàm AArch64 [mov w2, #0xd0; mov x0, x8; b #0x931f0]
uint64_t fde_sub_0903f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x52801A02ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0903F4ULL;
}

// FDE #3149 | PC: 0x090400..0x09041c (28 B) | Symbol: sub_090400
// EN: AArch64 prologue [ldrb w8, [sp, #0xc]; ldr x9, [x20, #0x28]; ldr x10, [sp, #0x18]; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [sp, #0xc]; ldr x9, [x20, #0x28]; ldr x10, [sp, #0x18]; cmp w8, #0]
uint64_t fde_sub_090400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401689ULL) << 32) | 0x394033E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090400ULL;
}

// FDE #3150 | PC: 0x09041c..0x090438 (28 B) | Symbol: sub_09041c
// EN: AArch64 prologue [ldr x8, [x22]; mov w3, #1; mov x0, x22; mov x1, x23] | VI: Khởi đầu hàm AArch64 [ldr x8, [x22]; mov w3, #1; mov x0, x22; mov x1, x23]
uint64_t fde_sub_09041c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800023ULL) << 32) | 0xF94002C8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09041CULL;
}

// FDE #3151 | PC: 0x090438..0x09044c (20 B) | Symbol: sub_090438
// EN: AArch64 prologue [ldr x20, [x19, #0x18]; add x0, sp, #0x290; mov x1, x19; add x21, sp, #0x290] | VI: Khởi đầu hàm AArch64 [ldr x20, [x19, #0x18]; add x0, sp, #0x290; mov x1, x19; add x21, sp, #0x290]
uint64_t fde_sub_090438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910A43E0ULL) << 32) | 0xF9400E74ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090438ULL;
}

// FDE #3152 | PC: 0x09044c..0x090454 (8 B) | Symbol: sub_09044c
// EN: AArch64 prologue [add x0, sp, #0x50; b #0x4696c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x50; b #0x4696c]
uint64_t fde_sub_09044c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED947ULL) << 32) | 0x910143E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09044CULL;
}

// FDE #3153 | PC: 0x090454..0x09045c (8 B) | Symbol: sub_090454
// EN: AArch64 prologue [ldr x8, [x8, #0x40]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x40]; br x8]
uint64_t fde_sub_090454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9402108ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090454ULL;
}

// FDE #3154 | PC: 0x09045c..0x090478 (28 B) | Symbol: sub_09045c
// EN: AArch64 prologue [fcvt s0, d0; add x1, sp, #8; add x2, sp, #4; mov x3, sp] | VI: Khởi đầu hàm AArch64 [fcvt s0, d0; add x1, sp, #8; add x2, sp, #4; mov x3, sp]
uint64_t fde_sub_09045c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E1ULL) << 32) | 0x1E624000ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09045CULL;
}

// FDE #3155 | PC: 0x090478..0x090484 (12 B) | Symbol: sub_090478
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x156; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x156; b #0x4696c]
uint64_t fde_sub_090478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91055821ULL) << 32) | 0xF0FFFC61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090478ULL;
}

// FDE #3156 | PC: 0x090484..0x090490 (12 B) | Symbol: sub_090484
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x73a; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x73a; b #0x4696c]
uint64_t fde_sub_090484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911CE821ULL) << 32) | 0xF0FFFC61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090484ULL;
}

// FDE #3157 | PC: 0x090490..0x09049c (12 B) | Symbol: sub_090490
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x729; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x729; b #0x4696c]
uint64_t fde_sub_090490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911CA421ULL) << 32) | 0xF0FFFC61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090490ULL;
}

// FDE #3158 | PC: 0x09049c..0x0904a8 (12 B) | Symbol: sub_09049c
// EN: AArch64 prologue [add x1, sp, #0x118; add x2, sp, #0x28; b #0x77c78] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x118; add x2, sp, #0x28; b #0x77c78]
uint64_t fde_sub_09049c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100A3E2ULL) << 32) | 0x910463E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09049CULL;
}

// FDE #3159 | PC: 0x0904a8..0x0904b4 (12 B) | Symbol: sub_0904a8
// EN: AArch64 prologue [ldr x0, [sp, #0x38]; str xzr, [sp, #0x38]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x38]; str xzr, [sp, #0x38]; ret]
uint64_t fde_sub_0904a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001FFFULL) << 32) | 0xF9401FE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904A8ULL;
}

// FDE #3160 | PC: 0x0904b4..0x0904c8 (20 B) | Symbol: sub_0904b4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x46c54; mov x0, x20; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x46c54; mov x0, x20; ldr x30, [sp], #0x10]
uint64_t fde_sub_0904b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FED9E7ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904B4ULL;
}

// FDE #3161 | PC: 0x0904c8..0x0904d4 (12 B) | Symbol: sub_0904c8
// EN: AArch64 prologue [mov x1, x23; mov x2, x22; b #0x7f0f0] | VI: Khởi đầu hàm AArch64 [mov x1, x23; mov x2, x22; b #0x7f0f0]
uint64_t fde_sub_0904c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E2ULL) << 32) | 0xAA1703E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904C8ULL;
}

// FDE #3162 | PC: 0x0904d4..0x0904dc (8 B) | Symbol: sub_0904d4
// EN: AArch64 prologue [mov x1, x23; b #0x4696c] | VI: Khởi đầu hàm AArch64 [mov x1, x23; b #0x4696c]
uint64_t fde_sub_0904d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED925ULL) << 32) | 0xAA1703E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904D4ULL;
}

// FDE #3163 | PC: 0x0904dc..0x0904e8 (12 B) | Symbol: sub_0904dc
// EN: AArch64 prologue [ldr x28, [sp, #0x100]; add sp, sp, #0x120; ret] | VI: Khởi đầu hàm AArch64 [ldr x28, [sp, #0x100]; add sp, sp, #0x120; ret]
uint64_t fde_sub_0904dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910483FFULL) << 32) | 0xF94083FCULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904DCULL;
}

// FDE #3164 | PC: 0x0904e8..0x0904fc (20 B) | Symbol: sub_0904e8
// EN: AArch64 prologue [fmov s0, wzr; fmov s1, wzr; fmov s2, wzr; fmov s3, wzr] | VI: Khởi đầu hàm AArch64 [fmov s0, wzr; fmov s1, wzr; fmov s2, wzr; fmov s3, wzr]
uint64_t fde_sub_0904e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2703E1ULL) << 32) | 0x1E2703E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904E8ULL;
}

// FDE #3165 | PC: 0x0904fc..0x090508 (12 B) | Symbol: sub_0904fc
// EN: AArch64 prologue [ldr x8, [x21, #0x40]; ldr x0, [x8]; b #0x8c724] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21, #0x40]; ldr x0, [x8]; b #0x8c724]
uint64_t fde_sub_0904fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400100ULL) << 32) | 0xF94022A8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904FCULL;
}

// FDE #3166 | PC: 0x090508..0x090524 (28 B) | Symbol: sub_090508
// EN: AArch64 prologue [add x15, x14, #1; str x15, [x11]; ldrb w11, [x14]; add w9, w9, #1] | VI: Khởi đầu hàm AArch64 [add x15, x14, #1; str x15, [x11]; ldrb w11, [x14]; add w9, w9, #1]
uint64_t fde_sub_090508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900016FULL) << 32) | 0x910005CFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090508ULL;
}

// FDE #3167 | PC: 0x090524..0x090538 (20 B) | Symbol: sub_090524
// EN: AArch64 prologue [ldp x21, x20, [sp, #0xe0]; ldp x23, x22, [sp, #0xd0]; ldr x24, [sp, #0xc0]; add sp, sp, #0x100] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0xe0]; ldp x23, x22, [sp, #0xd0]; ldr x24, [sp, #0xc0]; add sp, sp, #0x100]
uint64_t fde_sub_090524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94D5BF7ULL) << 32) | 0xA94E53F5ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090524ULL;
}

// FDE #3168 | PC: 0x090538..0x090544 (12 B) | Symbol: sub_090538
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x10]; ldp x23, x22, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x10]; ldp x23, x22, [sp], #0x30; ret]
uint64_t fde_sub_090538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA8C35BF7ULL) << 32) | 0xA94153F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090538ULL;
}

// FDE #3169 | PC: 0x090544..0x090550 (12 B) | Symbol: sub_090544
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x10]; ldr x28, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x10]; ldr x28, [sp], #0x30; ret]
uint64_t fde_sub_090544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84307FCULL) << 32) | 0xA94153F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090544ULL;
}

// FDE #3170 | PC: 0x090550..0x090564 (20 B) | Symbol: sub_090550
// EN: AArch64 prologue [ldr x0, [x20, #-8]!; mov v0.16b, v8.16b; ldr x8, [x0]; ldr x8, [x8, #0x90]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20, #-8]!; mov v0.16b, v8.16b; ldr x8, [x0]; ldr x8, [x8, #0x90]]
uint64_t fde_sub_090550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA81D00ULL) << 32) | 0xF85F8E80ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090550ULL;
}

// FDE #3171 | PC: 0x090564..0x090578 (20 B) | Symbol: sub_090564
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x4aaf4; add x0, x20, #0xb8; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x4aaf4; add x0, x20, #0xb8; ldr x30, [sp], #0x10]
uint64_t fde_sub_090564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEE963ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090564ULL;
}

uint64_t DispatchAnimaXShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x08bb6cULL: return fde_sub_08bb6c(a0, a1, a2);
        case 0x08bb70ULL: return fde_sub_08bb70(a0, a1, a2);
        case 0x08bb74ULL: return fde_sub_08bb74(a0, a1, a2);
        case 0x08bb78ULL: return fde_sub_08bb78(a0, a1, a2);
        case 0x08bbd8ULL: return fde_sub_08bbd8(a0, a1, a2);
        case 0x08bc28ULL: return fde_sub_08bc28(a0, a1, a2);
        case 0x08bc78ULL: return fde_sub_08bc78(a0, a1, a2);
        case 0x08bcd4ULL: return fde_sub_08bcd4(a0, a1, a2);
        case 0x08bd00ULL: return fde_sub_08bd00(a0, a1, a2);
        case 0x08bd30ULL: return fde_sub_08bd30(a0, a1, a2);
        case 0x08bd38ULL: return fde_sub_08bd38(a0, a1, a2);
        case 0x08bd40ULL: return fde_sub_08bd40(a0, a1, a2);
        case 0x08bd78ULL: return fde_sub_08bd78(a0, a1, a2);
        case 0x08be20ULL: return fde_sub_08be20(a0, a1, a2);
        case 0x08be30ULL: return fde_sub_08be30(a0, a1, a2);
        case 0x08be64ULL: return fde_sub_08be64(a0, a1, a2);
        case 0x08be74ULL: return fde_sub_08be74(a0, a1, a2);
        case 0x08be84ULL: return fde_sub_08be84(a0, a1, a2);
        case 0x08be88ULL: return fde_sub_08be88(a0, a1, a2);
        case 0x08be8cULL: return fde_sub_08be8c(a0, a1, a2);
        case 0x08bee4ULL: return fde_sub_08bee4(a0, a1, a2);
        case 0x08bf48ULL: return fde_sub_08bf48(a0, a1, a2);
        case 0x08bfa0ULL: return fde_sub_08bfa0(a0, a1, a2);
        case 0x08bfd8ULL: return fde_sub_08bfd8(a0, a1, a2);
        case 0x08bfdcULL: return fde_sub_08bfdc(a0, a1, a2);
        case 0x08c004ULL: return fde_sub_08c004(a0, a1, a2);
        case 0x08c038ULL: return fde_sub_08c038(a0, a1, a2);
        case 0x08c050ULL: return fde_sub_08c050(a0, a1, a2);
        case 0x08c058ULL: return fde_sub_08c058(a0, a1, a2);
        case 0x08c06cULL: return fde_sub_08c06c(a0, a1, a2);
        case 0x08c16cULL: return fde_sub_08c16c(a0, a1, a2);
        case 0x08c19cULL: return fde_sub_08c19c(a0, a1, a2);
        case 0x08c1c8ULL: return fde_sub_08c1c8(a0, a1, a2);
        case 0x08c1f8ULL: return fde_sub_08c1f8(a0, a1, a2);
        case 0x08c238ULL: return fde_sub_08c238(a0, a1, a2);
        case 0x08c23cULL: return fde_sub_08c23c(a0, a1, a2);
        case 0x08c240ULL: return fde_sub_08c240(a0, a1, a2);
        case 0x08c244ULL: return fde_sub_08c244(a0, a1, a2);
        case 0x08c248ULL: return fde_sub_08c248(a0, a1, a2);
        case 0x08c2b4ULL: return fde_sub_08c2b4(a0, a1, a2);
        case 0x08c2bcULL: return fde_sub_08c2bc(a0, a1, a2);
        case 0x08c2dcULL: return fde_sub_08c2dc(a0, a1, a2);
        case 0x08c324ULL: return fde_sub_08c324(a0, a1, a2);
        case 0x08c568ULL: return fde_sub_08c568(a0, a1, a2);
        case 0x08c590ULL: return fde_sub_08c590(a0, a1, a2);
        case 0x08c614ULL: return fde_sub_08c614(a0, a1, a2);
        case 0x08c678ULL: return fde_sub_08c678(a0, a1, a2);
        case 0x08c67cULL: return fde_sub_08c67c(a0, a1, a2);
        case 0x08c6ccULL: return fde_sub_08c6cc(a0, a1, a2);
        case 0x08c6f0ULL: return fde_sub_08c6f0(a0, a1, a2);
        case 0x08c718ULL: return fde_sub_08c718(a0, a1, a2);
        case 0x08c720ULL: return fde_sub_08c720(a0, a1, a2);
        case 0x08c724ULL: return fde_sub_08c724(a0, a1, a2);
        case 0x08c728ULL: return fde_sub_08c728(a0, a1, a2);
        case 0x08c794ULL: return fde_sub_08c794(a0, a1, a2);
        case 0x08c79cULL: return fde_sub_08c79c(a0, a1, a2);
        case 0x08c7d4ULL: return fde_sub_08c7d4(a0, a1, a2);
        case 0x08c7fcULL: return fde_sub_08c7fc(a0, a1, a2);
        case 0x08c80cULL: return fde_sub_08c80c(a0, a1, a2);
        case 0x08c824ULL: return fde_sub_08c824(a0, a1, a2);
        case 0x08c82cULL: return fde_sub_08c82c(a0, a1, a2);
        case 0x08c888ULL: return fde_sub_08c888(a0, a1, a2);
        case 0x08c8c4ULL: return fde_sub_08c8c4(a0, a1, a2);
        case 0x08c928ULL: return fde_sub_08c928(a0, a1, a2);
        case 0x08c9e4ULL: return fde_sub_08c9e4(a0, a1, a2);
        case 0x08ca34ULL: return fde_sub_08ca34(a0, a1, a2);
        case 0x08ca40ULL: return fde_sub_08ca40(a0, a1, a2);
        case 0x08cbccULL: return fde_sub_08cbcc(a0, a1, a2);
        case 0x08cc00ULL: return fde_sub_08cc00(a0, a1, a2);
        case 0x08cc84ULL: return fde_sub_08cc84(a0, a1, a2);
        case 0x08cd88ULL: return fde_sub_08cd88(a0, a1, a2);
        case 0x08cec4ULL: return fde_sub_08cec4(a0, a1, a2);
        case 0x08ced0ULL: return fde_sub_08ced0(a0, a1, a2);
        case 0x08d04cULL: return fde_sub_08d04c(a0, a1, a2);
        case 0x08d05cULL: return fde_sub_08d05c(a0, a1, a2);
        case 0x08d090ULL: return fde_sub_08d090(a0, a1, a2);
        case 0x08d0a8ULL: return fde_sub_08d0a8(a0, a1, a2);
        case 0x08d134ULL: return fde_sub_08d134(a0, a1, a2);
        case 0x08d168ULL: return fde_sub_08d168(a0, a1, a2);
        case 0x08d194ULL: return fde_sub_08d194(a0, a1, a2);
        case 0x08d1bcULL: return fde_sub_08d1bc(a0, a1, a2);
        case 0x08d1c4ULL: return fde_sub_08d1c4(a0, a1, a2);
        case 0x08d1f0ULL: return fde_sub_08d1f0(a0, a1, a2);
        case 0x08d208ULL: return fde_sub_08d208(a0, a1, a2);
        case 0x08d228ULL: return fde_sub_08d228(a0, a1, a2);
        case 0x08d398ULL: return fde_sub_08d398(a0, a1, a2);
        case 0x08d3c4ULL: return fde_sub_08d3c4(a0, a1, a2);
        case 0x08d3d0ULL: return fde_sub_08d3d0(a0, a1, a2);
        case 0x08d3d8ULL: return fde_sub_08d3d8(a0, a1, a2);
        case 0x08d3e8ULL: return fde_sub_08d3e8(a0, a1, a2);
        case 0x08d448ULL: return fde_sub_08d448(a0, a1, a2);
        case 0x08d454ULL: return fde_sub_08d454(a0, a1, a2);
        case 0x08d460ULL: return fde_sub_08d460(a0, a1, a2);
        case 0x08d46cULL: return fde_sub_08d46c(a0, a1, a2);
        case 0x08d480ULL: return fde_sub_08d480(a0, a1, a2);
        case 0x08d498ULL: return fde_sub_08d498(a0, a1, a2);
        case 0x08d4a0ULL: return fde_sub_08d4a0(a0, a1, a2);
        case 0x08d4a8ULL: return fde_sub_08d4a8(a0, a1, a2);
        case 0x08d4b4ULL: return fde_sub_08d4b4(a0, a1, a2);
        case 0x08d4f0ULL: return fde_sub_08d4f0(a0, a1, a2);
        case 0x08d510ULL: return fde_sub_08d510(a0, a1, a2);
        case 0x08d518ULL: return fde_sub_08d518(a0, a1, a2);
        case 0x08d524ULL: return fde_sub_08d524(a0, a1, a2);
        case 0x08d530ULL: return fde_sub_08d530(a0, a1, a2);
        case 0x08d548ULL: return fde_sub_08d548(a0, a1, a2);
        case 0x08d560ULL: return fde_sub_08d560(a0, a1, a2);
        case 0x08d568ULL: return fde_sub_08d568(a0, a1, a2);
        case 0x08d574ULL: return fde_sub_08d574(a0, a1, a2);
        case 0x08d57cULL: return fde_sub_08d57c(a0, a1, a2);
        case 0x08d584ULL: return fde_sub_08d584(a0, a1, a2);
        case 0x08d58cULL: return fde_sub_08d58c(a0, a1, a2);
        case 0x08d594ULL: return fde_sub_08d594(a0, a1, a2);
        case 0x08d5b8ULL: return fde_sub_08d5b8(a0, a1, a2);
        case 0x08d5c4ULL: return fde_sub_08d5c4(a0, a1, a2);
        case 0x08d5e8ULL: return fde_sub_08d5e8(a0, a1, a2);
        case 0x08d600ULL: return fde_sub_08d600(a0, a1, a2);
        case 0x08d60cULL: return fde_sub_08d60c(a0, a1, a2);
        case 0x08d614ULL: return fde_sub_08d614(a0, a1, a2);
        case 0x08d628ULL: return fde_sub_08d628(a0, a1, a2);
        case 0x08d63cULL: return fde_sub_08d63c(a0, a1, a2);
        case 0x08d654ULL: return fde_sub_08d654(a0, a1, a2);
        case 0x08d668ULL: return fde_sub_08d668(a0, a1, a2);
        case 0x08d678ULL: return fde_sub_08d678(a0, a1, a2);
        case 0x08d680ULL: return fde_sub_08d680(a0, a1, a2);
        case 0x08d690ULL: return fde_sub_08d690(a0, a1, a2);
        case 0x08d698ULL: return fde_sub_08d698(a0, a1, a2);
        case 0x08d6a0ULL: return fde_sub_08d6a0(a0, a1, a2);
        case 0x08d6a8ULL: return fde_sub_08d6a8(a0, a1, a2);
        case 0x08d6b0ULL: return fde_sub_08d6b0(a0, a1, a2);
        case 0x08d6c0ULL: return fde_sub_08d6c0(a0, a1, a2);
        case 0x08d6ccULL: return fde_sub_08d6cc(a0, a1, a2);
        case 0x08d6d4ULL: return fde_sub_08d6d4(a0, a1, a2);
        case 0x08d6dcULL: return fde_sub_08d6dc(a0, a1, a2);
        case 0x08d6ecULL: return fde_sub_08d6ec(a0, a1, a2);
        case 0x08d720ULL: return fde_sub_08d720(a0, a1, a2);
        case 0x08d728ULL: return fde_sub_08d728(a0, a1, a2);
        case 0x08d738ULL: return fde_sub_08d738(a0, a1, a2);
        case 0x08d748ULL: return fde_sub_08d748(a0, a1, a2);
        case 0x08d754ULL: return fde_sub_08d754(a0, a1, a2);
        case 0x08d76cULL: return fde_sub_08d76c(a0, a1, a2);
        case 0x08d77cULL: return fde_sub_08d77c(a0, a1, a2);
        case 0x08d79cULL: return fde_sub_08d79c(a0, a1, a2);
        case 0x08d7ccULL: return fde_sub_08d7cc(a0, a1, a2);
        case 0x08d7d4ULL: return fde_sub_08d7d4(a0, a1, a2);
        case 0x08d7e8ULL: return fde_sub_08d7e8(a0, a1, a2);
        case 0x08d7f0ULL: return fde_sub_08d7f0(a0, a1, a2);
        case 0x08d804ULL: return fde_sub_08d804(a0, a1, a2);
        case 0x08d828ULL: return fde_sub_08d828(a0, a1, a2);
        case 0x08d860ULL: return fde_sub_08d860(a0, a1, a2);
        case 0x08d870ULL: return fde_sub_08d870(a0, a1, a2);
        case 0x08d880ULL: return fde_sub_08d880(a0, a1, a2);
        case 0x08d888ULL: return fde_sub_08d888(a0, a1, a2);
        case 0x08d894ULL: return fde_sub_08d894(a0, a1, a2);
        case 0x08d89cULL: return fde_sub_08d89c(a0, a1, a2);
        case 0x08d8a4ULL: return fde_sub_08d8a4(a0, a1, a2);
        case 0x08d8acULL: return fde_sub_08d8ac(a0, a1, a2);
        case 0x08d8c4ULL: return fde_sub_08d8c4(a0, a1, a2);
        case 0x08d8d4ULL: return fde_sub_08d8d4(a0, a1, a2);
        case 0x08d8f0ULL: return fde_sub_08d8f0(a0, a1, a2);
        case 0x08d8f8ULL: return fde_sub_08d8f8(a0, a1, a2);
        case 0x08d904ULL: return fde_sub_08d904(a0, a1, a2);
        case 0x08d90cULL: return fde_sub_08d90c(a0, a1, a2);
        case 0x08d918ULL: return fde_sub_08d918(a0, a1, a2);
        case 0x08d924ULL: return fde_sub_08d924(a0, a1, a2);
        case 0x08d93cULL: return fde_sub_08d93c(a0, a1, a2);
        case 0x08d99cULL: return fde_sub_08d99c(a0, a1, a2);
        case 0x08d9a4ULL: return fde_sub_08d9a4(a0, a1, a2);
        case 0x08d9acULL: return fde_sub_08d9ac(a0, a1, a2);
        case 0x08d9bcULL: return fde_sub_08d9bc(a0, a1, a2);
        case 0x08d9d0ULL: return fde_sub_08d9d0(a0, a1, a2);
        case 0x08d9d8ULL: return fde_sub_08d9d8(a0, a1, a2);
        case 0x08d9e4ULL: return fde_sub_08d9e4(a0, a1, a2);
        case 0x08d9f0ULL: return fde_sub_08d9f0(a0, a1, a2);
        case 0x08d9fcULL: return fde_sub_08d9fc(a0, a1, a2);
        case 0x08da04ULL: return fde_sub_08da04(a0, a1, a2);
        case 0x08da0cULL: return fde_sub_08da0c(a0, a1, a2);
        case 0x08da1cULL: return fde_sub_08da1c(a0, a1, a2);
        case 0x08da50ULL: return fde_sub_08da50(a0, a1, a2);
        case 0x08da84ULL: return fde_sub_08da84(a0, a1, a2);
        case 0x08da8cULL: return fde_sub_08da8c(a0, a1, a2);
        case 0x08da9cULL: return fde_sub_08da9c(a0, a1, a2);
        case 0x08daa4ULL: return fde_sub_08daa4(a0, a1, a2);
        case 0x08dab0ULL: return fde_sub_08dab0(a0, a1, a2);
        case 0x08dabcULL: return fde_sub_08dabc(a0, a1, a2);
        case 0x08dac8ULL: return fde_sub_08dac8(a0, a1, a2);
        case 0x08dad4ULL: return fde_sub_08dad4(a0, a1, a2);
        case 0x08dae8ULL: return fde_sub_08dae8(a0, a1, a2);
        case 0x08daf0ULL: return fde_sub_08daf0(a0, a1, a2);
        case 0x08db04ULL: return fde_sub_08db04(a0, a1, a2);
        case 0x08db1cULL: return fde_sub_08db1c(a0, a1, a2);
        case 0x08db28ULL: return fde_sub_08db28(a0, a1, a2);
        case 0x08db34ULL: return fde_sub_08db34(a0, a1, a2);
        case 0x08db44ULL: return fde_sub_08db44(a0, a1, a2);
        case 0x08db50ULL: return fde_sub_08db50(a0, a1, a2);
        case 0x08db6cULL: return fde_sub_08db6c(a0, a1, a2);
        case 0x08db78ULL: return fde_sub_08db78(a0, a1, a2);
        case 0x08db84ULL: return fde_sub_08db84(a0, a1, a2);
        case 0x08dbacULL: return fde_sub_08dbac(a0, a1, a2);
        case 0x08dbb4ULL: return fde_sub_08dbb4(a0, a1, a2);
        case 0x08dbc0ULL: return fde_sub_08dbc0(a0, a1, a2);
        case 0x08dbc8ULL: return fde_sub_08dbc8(a0, a1, a2);
        case 0x08dbf0ULL: return fde_sub_08dbf0(a0, a1, a2);
        case 0x08dc00ULL: return fde_sub_08dc00(a0, a1, a2);
        case 0x08dc10ULL: return fde_sub_08dc10(a0, a1, a2);
        case 0x08dc2cULL: return fde_sub_08dc2c(a0, a1, a2);
        case 0x08dc34ULL: return fde_sub_08dc34(a0, a1, a2);
        case 0x08dc40ULL: return fde_sub_08dc40(a0, a1, a2);
        case 0x08dc60ULL: return fde_sub_08dc60(a0, a1, a2);
        case 0x08dc8cULL: return fde_sub_08dc8c(a0, a1, a2);
        case 0x08dcb8ULL: return fde_sub_08dcb8(a0, a1, a2);
        case 0x08dcc8ULL: return fde_sub_08dcc8(a0, a1, a2);
        case 0x08dcd4ULL: return fde_sub_08dcd4(a0, a1, a2);
        case 0x08dce8ULL: return fde_sub_08dce8(a0, a1, a2);
        case 0x08dcf8ULL: return fde_sub_08dcf8(a0, a1, a2);
        case 0x08dd00ULL: return fde_sub_08dd00(a0, a1, a2);
        case 0x08dd0cULL: return fde_sub_08dd0c(a0, a1, a2);
        case 0x08dd18ULL: return fde_sub_08dd18(a0, a1, a2);
        case 0x08dd30ULL: return fde_sub_08dd30(a0, a1, a2);
        case 0x08dd44ULL: return fde_sub_08dd44(a0, a1, a2);
        case 0x08dd68ULL: return fde_sub_08dd68(a0, a1, a2);
        case 0x08dd74ULL: return fde_sub_08dd74(a0, a1, a2);
        case 0x08dd7cULL: return fde_sub_08dd7c(a0, a1, a2);
        case 0x08ddc0ULL: return fde_sub_08ddc0(a0, a1, a2);
        case 0x08ddd4ULL: return fde_sub_08ddd4(a0, a1, a2);
        case 0x08dde0ULL: return fde_sub_08dde0(a0, a1, a2);
        case 0x08ddecULL: return fde_sub_08ddec(a0, a1, a2);
        case 0x08ddf8ULL: return fde_sub_08ddf8(a0, a1, a2);
        case 0x08de04ULL: return fde_sub_08de04(a0, a1, a2);
        case 0x08de18ULL: return fde_sub_08de18(a0, a1, a2);
        case 0x08de24ULL: return fde_sub_08de24(a0, a1, a2);
        case 0x08de3cULL: return fde_sub_08de3c(a0, a1, a2);
        case 0x08de4cULL: return fde_sub_08de4c(a0, a1, a2);
        case 0x08de5cULL: return fde_sub_08de5c(a0, a1, a2);
        case 0x08de74ULL: return fde_sub_08de74(a0, a1, a2);
        case 0x08de84ULL: return fde_sub_08de84(a0, a1, a2);
        case 0x08de90ULL: return fde_sub_08de90(a0, a1, a2);
        case 0x08dea8ULL: return fde_sub_08dea8(a0, a1, a2);
        case 0x08def0ULL: return fde_sub_08def0(a0, a1, a2);
        case 0x08df00ULL: return fde_sub_08df00(a0, a1, a2);
        case 0x08df10ULL: return fde_sub_08df10(a0, a1, a2);
        case 0x08df1cULL: return fde_sub_08df1c(a0, a1, a2);
        case 0x08df34ULL: return fde_sub_08df34(a0, a1, a2);
        case 0x08df4cULL: return fde_sub_08df4c(a0, a1, a2);
        case 0x08df6cULL: return fde_sub_08df6c(a0, a1, a2);
        case 0x08df74ULL: return fde_sub_08df74(a0, a1, a2);
        case 0x08df88ULL: return fde_sub_08df88(a0, a1, a2);
        case 0x08df9cULL: return fde_sub_08df9c(a0, a1, a2);
        case 0x08dfa8ULL: return fde_sub_08dfa8(a0, a1, a2);
        case 0x08dfe4ULL: return fde_sub_08dfe4(a0, a1, a2);
        case 0x08dff0ULL: return fde_sub_08dff0(a0, a1, a2);
        case 0x08dffcULL: return fde_sub_08dffc(a0, a1, a2);
        case 0x08e004ULL: return fde_sub_08e004(a0, a1, a2);
        case 0x08e024ULL: return fde_sub_08e024(a0, a1, a2);
        case 0x08e030ULL: return fde_sub_08e030(a0, a1, a2);
        case 0x08e03cULL: return fde_sub_08e03c(a0, a1, a2);
        case 0x08e058ULL: return fde_sub_08e058(a0, a1, a2);
        case 0x08e094ULL: return fde_sub_08e094(a0, a1, a2);
        case 0x08e0a0ULL: return fde_sub_08e0a0(a0, a1, a2);
        case 0x08e0a8ULL: return fde_sub_08e0a8(a0, a1, a2);
        case 0x08e0e4ULL: return fde_sub_08e0e4(a0, a1, a2);
        case 0x08e108ULL: return fde_sub_08e108(a0, a1, a2);
        case 0x08e118ULL: return fde_sub_08e118(a0, a1, a2);
        case 0x08e128ULL: return fde_sub_08e128(a0, a1, a2);
        case 0x08e134ULL: return fde_sub_08e134(a0, a1, a2);
        case 0x08e158ULL: return fde_sub_08e158(a0, a1, a2);
        case 0x08e160ULL: return fde_sub_08e160(a0, a1, a2);
        case 0x08e168ULL: return fde_sub_08e168(a0, a1, a2);
        case 0x08e178ULL: return fde_sub_08e178(a0, a1, a2);
        case 0x08e184ULL: return fde_sub_08e184(a0, a1, a2);
        case 0x08e1a8ULL: return fde_sub_08e1a8(a0, a1, a2);
        case 0x08e1b8ULL: return fde_sub_08e1b8(a0, a1, a2);
        case 0x08e1c4ULL: return fde_sub_08e1c4(a0, a1, a2);
        case 0x08e1ccULL: return fde_sub_08e1cc(a0, a1, a2);
        case 0x08e1d4ULL: return fde_sub_08e1d4(a0, a1, a2);
        case 0x08e1f4ULL: return fde_sub_08e1f4(a0, a1, a2);
        case 0x08e1fcULL: return fde_sub_08e1fc(a0, a1, a2);
        case 0x08e20cULL: return fde_sub_08e20c(a0, a1, a2);
        case 0x08e214ULL: return fde_sub_08e214(a0, a1, a2);
        case 0x08e230ULL: return fde_sub_08e230(a0, a1, a2);
        case 0x08e238ULL: return fde_sub_08e238(a0, a1, a2);
        case 0x08e244ULL: return fde_sub_08e244(a0, a1, a2);
        case 0x08e254ULL: return fde_sub_08e254(a0, a1, a2);
        case 0x08e260ULL: return fde_sub_08e260(a0, a1, a2);
        case 0x08e26cULL: return fde_sub_08e26c(a0, a1, a2);
        case 0x08e27cULL: return fde_sub_08e27c(a0, a1, a2);
        case 0x08e284ULL: return fde_sub_08e284(a0, a1, a2);
        case 0x08e290ULL: return fde_sub_08e290(a0, a1, a2);
        case 0x08e298ULL: return fde_sub_08e298(a0, a1, a2);
        case 0x08e2acULL: return fde_sub_08e2ac(a0, a1, a2);
        case 0x08e2c8ULL: return fde_sub_08e2c8(a0, a1, a2);
        case 0x08e2d0ULL: return fde_sub_08e2d0(a0, a1, a2);
        case 0x08e2dcULL: return fde_sub_08e2dc(a0, a1, a2);
        case 0x08e310ULL: return fde_sub_08e310(a0, a1, a2);
        case 0x08e31cULL: return fde_sub_08e31c(a0, a1, a2);
        case 0x08e328ULL: return fde_sub_08e328(a0, a1, a2);
        case 0x08e364ULL: return fde_sub_08e364(a0, a1, a2);
        case 0x08e378ULL: return fde_sub_08e378(a0, a1, a2);
        case 0x08e38cULL: return fde_sub_08e38c(a0, a1, a2);
        case 0x08e394ULL: return fde_sub_08e394(a0, a1, a2);
        case 0x08e3b0ULL: return fde_sub_08e3b0(a0, a1, a2);
        case 0x08e3bcULL: return fde_sub_08e3bc(a0, a1, a2);
        case 0x08e3ccULL: return fde_sub_08e3cc(a0, a1, a2);
        case 0x08e3d4ULL: return fde_sub_08e3d4(a0, a1, a2);
        case 0x08e3e4ULL: return fde_sub_08e3e4(a0, a1, a2);
        case 0x08e3f4ULL: return fde_sub_08e3f4(a0, a1, a2);
        case 0x08e430ULL: return fde_sub_08e430(a0, a1, a2);
        case 0x08e440ULL: return fde_sub_08e440(a0, a1, a2);
        case 0x08e448ULL: return fde_sub_08e448(a0, a1, a2);
        case 0x08e454ULL: return fde_sub_08e454(a0, a1, a2);
        case 0x08e460ULL: return fde_sub_08e460(a0, a1, a2);
        case 0x08e470ULL: return fde_sub_08e470(a0, a1, a2);
        case 0x08e484ULL: return fde_sub_08e484(a0, a1, a2);
        case 0x08e498ULL: return fde_sub_08e498(a0, a1, a2);
        case 0x08e4a4ULL: return fde_sub_08e4a4(a0, a1, a2);
        case 0x08e4b0ULL: return fde_sub_08e4b0(a0, a1, a2);
        case 0x08e4c0ULL: return fde_sub_08e4c0(a0, a1, a2);
        case 0x08e4d8ULL: return fde_sub_08e4d8(a0, a1, a2);
        case 0x08e4e0ULL: return fde_sub_08e4e0(a0, a1, a2);
        case 0x08e4e8ULL: return fde_sub_08e4e8(a0, a1, a2);
        case 0x08e500ULL: return fde_sub_08e500(a0, a1, a2);
        case 0x08e50cULL: return fde_sub_08e50c(a0, a1, a2);
        case 0x08e51cULL: return fde_sub_08e51c(a0, a1, a2);
        case 0x08e534ULL: return fde_sub_08e534(a0, a1, a2);
        case 0x08e53cULL: return fde_sub_08e53c(a0, a1, a2);
        case 0x08e544ULL: return fde_sub_08e544(a0, a1, a2);
        case 0x08e54cULL: return fde_sub_08e54c(a0, a1, a2);
        case 0x08e564ULL: return fde_sub_08e564(a0, a1, a2);
        case 0x08e578ULL: return fde_sub_08e578(a0, a1, a2);
        case 0x08e5b8ULL: return fde_sub_08e5b8(a0, a1, a2);
        case 0x08e5c4ULL: return fde_sub_08e5c4(a0, a1, a2);
        case 0x08e5d0ULL: return fde_sub_08e5d0(a0, a1, a2);
        case 0x08e5dcULL: return fde_sub_08e5dc(a0, a1, a2);
        case 0x08e5e4ULL: return fde_sub_08e5e4(a0, a1, a2);
        case 0x08e5f0ULL: return fde_sub_08e5f0(a0, a1, a2);
        case 0x08e5fcULL: return fde_sub_08e5fc(a0, a1, a2);
        case 0x08e61cULL: return fde_sub_08e61c(a0, a1, a2);
        case 0x08e628ULL: return fde_sub_08e628(a0, a1, a2);
        case 0x08e630ULL: return fde_sub_08e630(a0, a1, a2);
        case 0x08e638ULL: return fde_sub_08e638(a0, a1, a2);
        case 0x08e650ULL: return fde_sub_08e650(a0, a1, a2);
        case 0x08e66cULL: return fde_sub_08e66c(a0, a1, a2);
        case 0x08e684ULL: return fde_sub_08e684(a0, a1, a2);
        case 0x08e68cULL: return fde_sub_08e68c(a0, a1, a2);
        case 0x08e6a4ULL: return fde_sub_08e6a4(a0, a1, a2);
        case 0x08e6bcULL: return fde_sub_08e6bc(a0, a1, a2);
        case 0x08e6c8ULL: return fde_sub_08e6c8(a0, a1, a2);
        case 0x08e6d4ULL: return fde_sub_08e6d4(a0, a1, a2);
        case 0x08e6ecULL: return fde_sub_08e6ec(a0, a1, a2);
        case 0x08e720ULL: return fde_sub_08e720(a0, a1, a2);
        case 0x08e728ULL: return fde_sub_08e728(a0, a1, a2);
        case 0x08e734ULL: return fde_sub_08e734(a0, a1, a2);
        case 0x08e74cULL: return fde_sub_08e74c(a0, a1, a2);
        case 0x08e764ULL: return fde_sub_08e764(a0, a1, a2);
        case 0x08e770ULL: return fde_sub_08e770(a0, a1, a2);
        case 0x08e77cULL: return fde_sub_08e77c(a0, a1, a2);
        case 0x08e788ULL: return fde_sub_08e788(a0, a1, a2);
        case 0x08e794ULL: return fde_sub_08e794(a0, a1, a2);
        case 0x08e7a0ULL: return fde_sub_08e7a0(a0, a1, a2);
        case 0x08e7acULL: return fde_sub_08e7ac(a0, a1, a2);
        case 0x08e7b8ULL: return fde_sub_08e7b8(a0, a1, a2);
        case 0x08e7d4ULL: return fde_sub_08e7d4(a0, a1, a2);
        case 0x08e7dcULL: return fde_sub_08e7dc(a0, a1, a2);
        case 0x08e804ULL: return fde_sub_08e804(a0, a1, a2);
        case 0x08e814ULL: return fde_sub_08e814(a0, a1, a2);
        case 0x08e83cULL: return fde_sub_08e83c(a0, a1, a2);
        case 0x08e864ULL: return fde_sub_08e864(a0, a1, a2);
        case 0x08e870ULL: return fde_sub_08e870(a0, a1, a2);
        case 0x08e88cULL: return fde_sub_08e88c(a0, a1, a2);
        case 0x08e89cULL: return fde_sub_08e89c(a0, a1, a2);
        case 0x08e8b8ULL: return fde_sub_08e8b8(a0, a1, a2);
        case 0x08e8e8ULL: return fde_sub_08e8e8(a0, a1, a2);
        case 0x08e904ULL: return fde_sub_08e904(a0, a1, a2);
        case 0x08e914ULL: return fde_sub_08e914(a0, a1, a2);
        case 0x08e934ULL: return fde_sub_08e934(a0, a1, a2);
        case 0x08e940ULL: return fde_sub_08e940(a0, a1, a2);
        case 0x08e948ULL: return fde_sub_08e948(a0, a1, a2);
        case 0x08e958ULL: return fde_sub_08e958(a0, a1, a2);
        case 0x08e968ULL: return fde_sub_08e968(a0, a1, a2);
        case 0x08e978ULL: return fde_sub_08e978(a0, a1, a2);
        case 0x08e988ULL: return fde_sub_08e988(a0, a1, a2);
        case 0x08e990ULL: return fde_sub_08e990(a0, a1, a2);
        case 0x08e99cULL: return fde_sub_08e99c(a0, a1, a2);
        case 0x08e9a4ULL: return fde_sub_08e9a4(a0, a1, a2);
        case 0x08e9acULL: return fde_sub_08e9ac(a0, a1, a2);
        case 0x08e9d4ULL: return fde_sub_08e9d4(a0, a1, a2);
        case 0x08e9f0ULL: return fde_sub_08e9f0(a0, a1, a2);
        case 0x08e9fcULL: return fde_sub_08e9fc(a0, a1, a2);
        case 0x08ea0cULL: return fde_sub_08ea0c(a0, a1, a2);
        case 0x08ea14ULL: return fde_sub_08ea14(a0, a1, a2);
        case 0x08ea1cULL: return fde_sub_08ea1c(a0, a1, a2);
        case 0x08ea2cULL: return fde_sub_08ea2c(a0, a1, a2);
        case 0x08ea3cULL: return fde_sub_08ea3c(a0, a1, a2);
        case 0x08ea48ULL: return fde_sub_08ea48(a0, a1, a2);
        case 0x08ea58ULL: return fde_sub_08ea58(a0, a1, a2);
        case 0x08ea98ULL: return fde_sub_08ea98(a0, a1, a2);
        case 0x08eaa0ULL: return fde_sub_08eaa0(a0, a1, a2);
        case 0x08eaacULL: return fde_sub_08eaac(a0, a1, a2);
        case 0x08eab8ULL: return fde_sub_08eab8(a0, a1, a2);
        case 0x08eac4ULL: return fde_sub_08eac4(a0, a1, a2);
        case 0x08eaecULL: return fde_sub_08eaec(a0, a1, a2);
        case 0x08eaf8ULL: return fde_sub_08eaf8(a0, a1, a2);
        case 0x08eb14ULL: return fde_sub_08eb14(a0, a1, a2);
        case 0x08eb24ULL: return fde_sub_08eb24(a0, a1, a2);
        case 0x08eb34ULL: return fde_sub_08eb34(a0, a1, a2);
        case 0x08eb44ULL: return fde_sub_08eb44(a0, a1, a2);
        case 0x08eb4cULL: return fde_sub_08eb4c(a0, a1, a2);
        case 0x08eb5cULL: return fde_sub_08eb5c(a0, a1, a2);
        case 0x08eb64ULL: return fde_sub_08eb64(a0, a1, a2);
        case 0x08eb6cULL: return fde_sub_08eb6c(a0, a1, a2);
        case 0x08eb7cULL: return fde_sub_08eb7c(a0, a1, a2);
        case 0x08eb88ULL: return fde_sub_08eb88(a0, a1, a2);
        case 0x08eba4ULL: return fde_sub_08eba4(a0, a1, a2);
        case 0x08ebb4ULL: return fde_sub_08ebb4(a0, a1, a2);
        case 0x08ebc8ULL: return fde_sub_08ebc8(a0, a1, a2);
        case 0x08ebd0ULL: return fde_sub_08ebd0(a0, a1, a2);
        case 0x08ebdcULL: return fde_sub_08ebdc(a0, a1, a2);
        case 0x08ebe4ULL: return fde_sub_08ebe4(a0, a1, a2);
        case 0x08ebecULL: return fde_sub_08ebec(a0, a1, a2);
        case 0x08ec00ULL: return fde_sub_08ec00(a0, a1, a2);
        case 0x08ec08ULL: return fde_sub_08ec08(a0, a1, a2);
        case 0x08ec34ULL: return fde_sub_08ec34(a0, a1, a2);
        case 0x08ec60ULL: return fde_sub_08ec60(a0, a1, a2);
        case 0x08ec6cULL: return fde_sub_08ec6c(a0, a1, a2);
        case 0x08ec80ULL: return fde_sub_08ec80(a0, a1, a2);
        case 0x08ec8cULL: return fde_sub_08ec8c(a0, a1, a2);
        case 0x08ec98ULL: return fde_sub_08ec98(a0, a1, a2);
        case 0x08eca4ULL: return fde_sub_08eca4(a0, a1, a2);
        case 0x08ecb0ULL: return fde_sub_08ecb0(a0, a1, a2);
        case 0x08ecb8ULL: return fde_sub_08ecb8(a0, a1, a2);
        case 0x08ecccULL: return fde_sub_08eccc(a0, a1, a2);
        case 0x08ece0ULL: return fde_sub_08ece0(a0, a1, a2);
        case 0x08ece8ULL: return fde_sub_08ece8(a0, a1, a2);
        case 0x08ed0cULL: return fde_sub_08ed0c(a0, a1, a2);
        case 0x08ed18ULL: return fde_sub_08ed18(a0, a1, a2);
        case 0x08ed24ULL: return fde_sub_08ed24(a0, a1, a2);
        case 0x08ed30ULL: return fde_sub_08ed30(a0, a1, a2);
        case 0x08ed3cULL: return fde_sub_08ed3c(a0, a1, a2);
        case 0x08ed44ULL: return fde_sub_08ed44(a0, a1, a2);
        case 0x08ed4cULL: return fde_sub_08ed4c(a0, a1, a2);
        case 0x08ed58ULL: return fde_sub_08ed58(a0, a1, a2);
        case 0x08ed6cULL: return fde_sub_08ed6c(a0, a1, a2);
        case 0x08ed78ULL: return fde_sub_08ed78(a0, a1, a2);
        case 0x08ed84ULL: return fde_sub_08ed84(a0, a1, a2);
        case 0x08edb0ULL: return fde_sub_08edb0(a0, a1, a2);
        case 0x08eddcULL: return fde_sub_08eddc(a0, a1, a2);
        case 0x08ede8ULL: return fde_sub_08ede8(a0, a1, a2);
        case 0x08edf0ULL: return fde_sub_08edf0(a0, a1, a2);
        case 0x08edfcULL: return fde_sub_08edfc(a0, a1, a2);
        case 0x08ee08ULL: return fde_sub_08ee08(a0, a1, a2);
        case 0x08ee14ULL: return fde_sub_08ee14(a0, a1, a2);
        case 0x08ee38ULL: return fde_sub_08ee38(a0, a1, a2);
        case 0x08ee40ULL: return fde_sub_08ee40(a0, a1, a2);
        case 0x08ee48ULL: return fde_sub_08ee48(a0, a1, a2);
        case 0x08ee54ULL: return fde_sub_08ee54(a0, a1, a2);
        case 0x08ee78ULL: return fde_sub_08ee78(a0, a1, a2);
        case 0x08ee8cULL: return fde_sub_08ee8c(a0, a1, a2);
        case 0x08eeb4ULL: return fde_sub_08eeb4(a0, a1, a2);
        case 0x08eed4ULL: return fde_sub_08eed4(a0, a1, a2);
        case 0x08eee4ULL: return fde_sub_08eee4(a0, a1, a2);
        case 0x08eef0ULL: return fde_sub_08eef0(a0, a1, a2);
        case 0x08ef00ULL: return fde_sub_08ef00(a0, a1, a2);
        case 0x08ef10ULL: return fde_sub_08ef10(a0, a1, a2);
        case 0x08ef1cULL: return fde_sub_08ef1c(a0, a1, a2);
        case 0x08ef2cULL: return fde_sub_08ef2c(a0, a1, a2);
        case 0x08ef44ULL: return fde_sub_08ef44(a0, a1, a2);
        case 0x08ef50ULL: return fde_sub_08ef50(a0, a1, a2);
        case 0x08ef58ULL: return fde_sub_08ef58(a0, a1, a2);
        case 0x08ef90ULL: return fde_sub_08ef90(a0, a1, a2);
        case 0x08efc8ULL: return fde_sub_08efc8(a0, a1, a2);
        case 0x08efd8ULL: return fde_sub_08efd8(a0, a1, a2);
        case 0x08eff0ULL: return fde_sub_08eff0(a0, a1, a2);
        case 0x08f000ULL: return fde_sub_08f000(a0, a1, a2);
        case 0x08f018ULL: return fde_sub_08f018(a0, a1, a2);
        case 0x08f038ULL: return fde_sub_08f038(a0, a1, a2);
        case 0x08f048ULL: return fde_sub_08f048(a0, a1, a2);
        case 0x08f070ULL: return fde_sub_08f070(a0, a1, a2);
        case 0x08f088ULL: return fde_sub_08f088(a0, a1, a2);
        case 0x08f0acULL: return fde_sub_08f0ac(a0, a1, a2);
        case 0x08f0e4ULL: return fde_sub_08f0e4(a0, a1, a2);
        case 0x08f0f0ULL: return fde_sub_08f0f0(a0, a1, a2);
        case 0x08f0f8ULL: return fde_sub_08f0f8(a0, a1, a2);
        case 0x08f104ULL: return fde_sub_08f104(a0, a1, a2);
        case 0x08f10cULL: return fde_sub_08f10c(a0, a1, a2);
        case 0x08f118ULL: return fde_sub_08f118(a0, a1, a2);
        case 0x08f130ULL: return fde_sub_08f130(a0, a1, a2);
        case 0x08f140ULL: return fde_sub_08f140(a0, a1, a2);
        case 0x08f160ULL: return fde_sub_08f160(a0, a1, a2);
        case 0x08f180ULL: return fde_sub_08f180(a0, a1, a2);
        case 0x08f1a0ULL: return fde_sub_08f1a0(a0, a1, a2);
        case 0x08f1c0ULL: return fde_sub_08f1c0(a0, a1, a2);
        case 0x08f1c8ULL: return fde_sub_08f1c8(a0, a1, a2);
        case 0x08f1e8ULL: return fde_sub_08f1e8(a0, a1, a2);
        case 0x08f1f0ULL: return fde_sub_08f1f0(a0, a1, a2);
        case 0x08f1fcULL: return fde_sub_08f1fc(a0, a1, a2);
        case 0x08f224ULL: return fde_sub_08f224(a0, a1, a2);
        case 0x08f23cULL: return fde_sub_08f23c(a0, a1, a2);
        case 0x08f244ULL: return fde_sub_08f244(a0, a1, a2);
        case 0x08f24cULL: return fde_sub_08f24c(a0, a1, a2);
        case 0x08f25cULL: return fde_sub_08f25c(a0, a1, a2);
        case 0x08f264ULL: return fde_sub_08f264(a0, a1, a2);
        case 0x08f26cULL: return fde_sub_08f26c(a0, a1, a2);
        case 0x08f27cULL: return fde_sub_08f27c(a0, a1, a2);
        case 0x08f288ULL: return fde_sub_08f288(a0, a1, a2);
        case 0x08f294ULL: return fde_sub_08f294(a0, a1, a2);
        case 0x08f2acULL: return fde_sub_08f2ac(a0, a1, a2);
        case 0x08f2ccULL: return fde_sub_08f2cc(a0, a1, a2);
        case 0x08f2dcULL: return fde_sub_08f2dc(a0, a1, a2);
        case 0x08f2ecULL: return fde_sub_08f2ec(a0, a1, a2);
        case 0x08f304ULL: return fde_sub_08f304(a0, a1, a2);
        case 0x08f30cULL: return fde_sub_08f30c(a0, a1, a2);
        case 0x08f334ULL: return fde_sub_08f334(a0, a1, a2);
        case 0x08f33cULL: return fde_sub_08f33c(a0, a1, a2);
        case 0x08f34cULL: return fde_sub_08f34c(a0, a1, a2);
        case 0x08f374ULL: return fde_sub_08f374(a0, a1, a2);
        case 0x08f380ULL: return fde_sub_08f380(a0, a1, a2);
        case 0x08f38cULL: return fde_sub_08f38c(a0, a1, a2);
        case 0x08f394ULL: return fde_sub_08f394(a0, a1, a2);
        case 0x08f39cULL: return fde_sub_08f39c(a0, a1, a2);
        case 0x08f3a4ULL: return fde_sub_08f3a4(a0, a1, a2);
        case 0x08f3acULL: return fde_sub_08f3ac(a0, a1, a2);
        case 0x08f3e4ULL: return fde_sub_08f3e4(a0, a1, a2);
        case 0x08f3f0ULL: return fde_sub_08f3f0(a0, a1, a2);
        case 0x08f3fcULL: return fde_sub_08f3fc(a0, a1, a2);
        case 0x08f408ULL: return fde_sub_08f408(a0, a1, a2);
        case 0x08f410ULL: return fde_sub_08f410(a0, a1, a2);
        case 0x08f418ULL: return fde_sub_08f418(a0, a1, a2);
        case 0x08f43cULL: return fde_sub_08f43c(a0, a1, a2);
        case 0x08f460ULL: return fde_sub_08f460(a0, a1, a2);
        case 0x08f46cULL: return fde_sub_08f46c(a0, a1, a2);
        case 0x08f490ULL: return fde_sub_08f490(a0, a1, a2);
        case 0x08f4acULL: return fde_sub_08f4ac(a0, a1, a2);
        case 0x08f4b4ULL: return fde_sub_08f4b4(a0, a1, a2);
        case 0x08f4bcULL: return fde_sub_08f4bc(a0, a1, a2);
        case 0x08f4e8ULL: return fde_sub_08f4e8(a0, a1, a2);
        case 0x08f4f4ULL: return fde_sub_08f4f4(a0, a1, a2);
        case 0x08f500ULL: return fde_sub_08f500(a0, a1, a2);
        case 0x08f50cULL: return fde_sub_08f50c(a0, a1, a2);
        case 0x08f514ULL: return fde_sub_08f514(a0, a1, a2);
        case 0x08f51cULL: return fde_sub_08f51c(a0, a1, a2);
        case 0x08f538ULL: return fde_sub_08f538(a0, a1, a2);
        case 0x08f540ULL: return fde_sub_08f540(a0, a1, a2);
        case 0x08f550ULL: return fde_sub_08f550(a0, a1, a2);
        case 0x08f55cULL: return fde_sub_08f55c(a0, a1, a2);
        case 0x08f568ULL: return fde_sub_08f568(a0, a1, a2);
        case 0x08f574ULL: return fde_sub_08f574(a0, a1, a2);
        case 0x08f57cULL: return fde_sub_08f57c(a0, a1, a2);
        case 0x08f588ULL: return fde_sub_08f588(a0, a1, a2);
        case 0x08f598ULL: return fde_sub_08f598(a0, a1, a2);
        case 0x08f5a8ULL: return fde_sub_08f5a8(a0, a1, a2);
        case 0x08f5b0ULL: return fde_sub_08f5b0(a0, a1, a2);
        case 0x08f5dcULL: return fde_sub_08f5dc(a0, a1, a2);
        case 0x08f5e4ULL: return fde_sub_08f5e4(a0, a1, a2);
        case 0x08f5f0ULL: return fde_sub_08f5f0(a0, a1, a2);
        case 0x08f600ULL: return fde_sub_08f600(a0, a1, a2);
        case 0x08f610ULL: return fde_sub_08f610(a0, a1, a2);
        case 0x08f620ULL: return fde_sub_08f620(a0, a1, a2);
        case 0x08f63cULL: return fde_sub_08f63c(a0, a1, a2);
        case 0x08f644ULL: return fde_sub_08f644(a0, a1, a2);
        case 0x08f650ULL: return fde_sub_08f650(a0, a1, a2);
        case 0x08f660ULL: return fde_sub_08f660(a0, a1, a2);
        case 0x08f670ULL: return fde_sub_08f670(a0, a1, a2);
        case 0x08f680ULL: return fde_sub_08f680(a0, a1, a2);
        case 0x08f68cULL: return fde_sub_08f68c(a0, a1, a2);
        case 0x08f698ULL: return fde_sub_08f698(a0, a1, a2);
        case 0x08f6b4ULL: return fde_sub_08f6b4(a0, a1, a2);
        case 0x08f6c4ULL: return fde_sub_08f6c4(a0, a1, a2);
        case 0x08f6e8ULL: return fde_sub_08f6e8(a0, a1, a2);
        case 0x08f6f4ULL: return fde_sub_08f6f4(a0, a1, a2);
        case 0x08f710ULL: return fde_sub_08f710(a0, a1, a2);
        case 0x08f72cULL: return fde_sub_08f72c(a0, a1, a2);
        case 0x08f748ULL: return fde_sub_08f748(a0, a1, a2);
        case 0x08f758ULL: return fde_sub_08f758(a0, a1, a2);
        case 0x08f760ULL: return fde_sub_08f760(a0, a1, a2);
        case 0x08f76cULL: return fde_sub_08f76c(a0, a1, a2);
        case 0x08f790ULL: return fde_sub_08f790(a0, a1, a2);
        case 0x08f79cULL: return fde_sub_08f79c(a0, a1, a2);
        case 0x08f7a8ULL: return fde_sub_08f7a8(a0, a1, a2);
        case 0x08f7ccULL: return fde_sub_08f7cc(a0, a1, a2);
        case 0x08f7d4ULL: return fde_sub_08f7d4(a0, a1, a2);
        case 0x08f7e0ULL: return fde_sub_08f7e0(a0, a1, a2);
        case 0x08f7ecULL: return fde_sub_08f7ec(a0, a1, a2);
        case 0x08f7f8ULL: return fde_sub_08f7f8(a0, a1, a2);
        case 0x08f804ULL: return fde_sub_08f804(a0, a1, a2);
        case 0x08f810ULL: return fde_sub_08f810(a0, a1, a2);
        case 0x08f818ULL: return fde_sub_08f818(a0, a1, a2);
        case 0x08f83cULL: return fde_sub_08f83c(a0, a1, a2);
        case 0x08f844ULL: return fde_sub_08f844(a0, a1, a2);
        case 0x08f84cULL: return fde_sub_08f84c(a0, a1, a2);
        case 0x08f858ULL: return fde_sub_08f858(a0, a1, a2);
        case 0x08f874ULL: return fde_sub_08f874(a0, a1, a2);
        case 0x08f898ULL: return fde_sub_08f898(a0, a1, a2);
        case 0x08f8a0ULL: return fde_sub_08f8a0(a0, a1, a2);
        case 0x08f8a8ULL: return fde_sub_08f8a8(a0, a1, a2);
        case 0x08f8b4ULL: return fde_sub_08f8b4(a0, a1, a2);
        case 0x08f8c4ULL: return fde_sub_08f8c4(a0, a1, a2);
        case 0x08f8e8ULL: return fde_sub_08f8e8(a0, a1, a2);
        case 0x08f90cULL: return fde_sub_08f90c(a0, a1, a2);
        case 0x08f930ULL: return fde_sub_08f930(a0, a1, a2);
        case 0x08f938ULL: return fde_sub_08f938(a0, a1, a2);
        case 0x08f940ULL: return fde_sub_08f940(a0, a1, a2);
        case 0x08f94cULL: return fde_sub_08f94c(a0, a1, a2);
        case 0x08f958ULL: return fde_sub_08f958(a0, a1, a2);
        case 0x08f964ULL: return fde_sub_08f964(a0, a1, a2);
        case 0x08f974ULL: return fde_sub_08f974(a0, a1, a2);
        case 0x08f97cULL: return fde_sub_08f97c(a0, a1, a2);
        case 0x08f984ULL: return fde_sub_08f984(a0, a1, a2);
        case 0x08f9a0ULL: return fde_sub_08f9a0(a0, a1, a2);
        case 0x08f9acULL: return fde_sub_08f9ac(a0, a1, a2);
        case 0x08f9b8ULL: return fde_sub_08f9b8(a0, a1, a2);
        case 0x08f9c4ULL: return fde_sub_08f9c4(a0, a1, a2);
        case 0x08f9d0ULL: return fde_sub_08f9d0(a0, a1, a2);
        case 0x08f9dcULL: return fde_sub_08f9dc(a0, a1, a2);
        case 0x08f9e8ULL: return fde_sub_08f9e8(a0, a1, a2);
        case 0x08f9f4ULL: return fde_sub_08f9f4(a0, a1, a2);
        case 0x08fa00ULL: return fde_sub_08fa00(a0, a1, a2);
        case 0x08fa08ULL: return fde_sub_08fa08(a0, a1, a2);
        case 0x08fa14ULL: return fde_sub_08fa14(a0, a1, a2);
        case 0x08fa20ULL: return fde_sub_08fa20(a0, a1, a2);
        case 0x08fa28ULL: return fde_sub_08fa28(a0, a1, a2);
        case 0x08fa38ULL: return fde_sub_08fa38(a0, a1, a2);
        case 0x08fa40ULL: return fde_sub_08fa40(a0, a1, a2);
        case 0x08fa4cULL: return fde_sub_08fa4c(a0, a1, a2);
        case 0x08fa58ULL: return fde_sub_08fa58(a0, a1, a2);
        case 0x08fa68ULL: return fde_sub_08fa68(a0, a1, a2);
        case 0x08fa78ULL: return fde_sub_08fa78(a0, a1, a2);
        case 0x08fa88ULL: return fde_sub_08fa88(a0, a1, a2);
        case 0x08fa94ULL: return fde_sub_08fa94(a0, a1, a2);
        case 0x08faa4ULL: return fde_sub_08faa4(a0, a1, a2);
        case 0x08fab0ULL: return fde_sub_08fab0(a0, a1, a2);
        case 0x08fabcULL: return fde_sub_08fabc(a0, a1, a2);
        case 0x08fac4ULL: return fde_sub_08fac4(a0, a1, a2);
        case 0x08faccULL: return fde_sub_08facc(a0, a1, a2);
        case 0x08faf8ULL: return fde_sub_08faf8(a0, a1, a2);
        case 0x08fb00ULL: return fde_sub_08fb00(a0, a1, a2);
        case 0x08fb08ULL: return fde_sub_08fb08(a0, a1, a2);
        case 0x08fb14ULL: return fde_sub_08fb14(a0, a1, a2);
        case 0x08fb1cULL: return fde_sub_08fb1c(a0, a1, a2);
        case 0x08fb28ULL: return fde_sub_08fb28(a0, a1, a2);
        case 0x08fb34ULL: return fde_sub_08fb34(a0, a1, a2);
        case 0x08fb40ULL: return fde_sub_08fb40(a0, a1, a2);
        case 0x08fb50ULL: return fde_sub_08fb50(a0, a1, a2);
        case 0x08fb5cULL: return fde_sub_08fb5c(a0, a1, a2);
        case 0x08fb64ULL: return fde_sub_08fb64(a0, a1, a2);
        case 0x08fb6cULL: return fde_sub_08fb6c(a0, a1, a2);
        case 0x08fb78ULL: return fde_sub_08fb78(a0, a1, a2);
        case 0x08fb84ULL: return fde_sub_08fb84(a0, a1, a2);
        case 0x08fb90ULL: return fde_sub_08fb90(a0, a1, a2);
        case 0x08fbb0ULL: return fde_sub_08fbb0(a0, a1, a2);
        case 0x08fbb8ULL: return fde_sub_08fbb8(a0, a1, a2);
        case 0x08fbc4ULL: return fde_sub_08fbc4(a0, a1, a2);
        case 0x08fbccULL: return fde_sub_08fbcc(a0, a1, a2);
        case 0x08fbd4ULL: return fde_sub_08fbd4(a0, a1, a2);
        case 0x08fbe8ULL: return fde_sub_08fbe8(a0, a1, a2);
        case 0x08fc08ULL: return fde_sub_08fc08(a0, a1, a2);
        case 0x08fc14ULL: return fde_sub_08fc14(a0, a1, a2);
        case 0x08fc1cULL: return fde_sub_08fc1c(a0, a1, a2);
        case 0x08fc30ULL: return fde_sub_08fc30(a0, a1, a2);
        case 0x08fc50ULL: return fde_sub_08fc50(a0, a1, a2);
        case 0x08fc64ULL: return fde_sub_08fc64(a0, a1, a2);
        case 0x08fc6cULL: return fde_sub_08fc6c(a0, a1, a2);
        case 0x08fc78ULL: return fde_sub_08fc78(a0, a1, a2);
        case 0x08fc8cULL: return fde_sub_08fc8c(a0, a1, a2);
        case 0x08fca0ULL: return fde_sub_08fca0(a0, a1, a2);
        case 0x08fcb4ULL: return fde_sub_08fcb4(a0, a1, a2);
        case 0x08fcc4ULL: return fde_sub_08fcc4(a0, a1, a2);
        case 0x08fcccULL: return fde_sub_08fccc(a0, a1, a2);
        case 0x08fcdcULL: return fde_sub_08fcdc(a0, a1, a2);
        case 0x08fcf4ULL: return fde_sub_08fcf4(a0, a1, a2);
        case 0x08fcfcULL: return fde_sub_08fcfc(a0, a1, a2);
        case 0x08fd14ULL: return fde_sub_08fd14(a0, a1, a2);
        case 0x08fd2cULL: return fde_sub_08fd2c(a0, a1, a2);
        case 0x08fd38ULL: return fde_sub_08fd38(a0, a1, a2);
        case 0x08fd4cULL: return fde_sub_08fd4c(a0, a1, a2);
        case 0x08fd58ULL: return fde_sub_08fd58(a0, a1, a2);
        case 0x08fd68ULL: return fde_sub_08fd68(a0, a1, a2);
        case 0x08fd88ULL: return fde_sub_08fd88(a0, a1, a2);
        case 0x08fd90ULL: return fde_sub_08fd90(a0, a1, a2);
        case 0x08fda0ULL: return fde_sub_08fda0(a0, a1, a2);
        case 0x08fda8ULL: return fde_sub_08fda8(a0, a1, a2);
        case 0x08fdc8ULL: return fde_sub_08fdc8(a0, a1, a2);
        case 0x08fdd8ULL: return fde_sub_08fdd8(a0, a1, a2);
        case 0x08fdf8ULL: return fde_sub_08fdf8(a0, a1, a2);
        case 0x08fe00ULL: return fde_sub_08fe00(a0, a1, a2);
        case 0x08fe18ULL: return fde_sub_08fe18(a0, a1, a2);
        case 0x08fe38ULL: return fde_sub_08fe38(a0, a1, a2);
        case 0x08fe40ULL: return fde_sub_08fe40(a0, a1, a2);
        case 0x08fe60ULL: return fde_sub_08fe60(a0, a1, a2);
        case 0x08fe70ULL: return fde_sub_08fe70(a0, a1, a2);
        case 0x08fe7cULL: return fde_sub_08fe7c(a0, a1, a2);
        case 0x08fe8cULL: return fde_sub_08fe8c(a0, a1, a2);
        case 0x08fe98ULL: return fde_sub_08fe98(a0, a1, a2);
        case 0x08fea8ULL: return fde_sub_08fea8(a0, a1, a2);
        case 0x08feb4ULL: return fde_sub_08feb4(a0, a1, a2);
        case 0x08feccULL: return fde_sub_08fecc(a0, a1, a2);
        case 0x08fee0ULL: return fde_sub_08fee0(a0, a1, a2);
        case 0x08fef8ULL: return fde_sub_08fef8(a0, a1, a2);
        case 0x08ff0cULL: return fde_sub_08ff0c(a0, a1, a2);
        case 0x08ff1cULL: return fde_sub_08ff1c(a0, a1, a2);
        case 0x08ff28ULL: return fde_sub_08ff28(a0, a1, a2);
        case 0x08ff30ULL: return fde_sub_08ff30(a0, a1, a2);
        case 0x08ff38ULL: return fde_sub_08ff38(a0, a1, a2);
        case 0x08ff48ULL: return fde_sub_08ff48(a0, a1, a2);
        case 0x08ff58ULL: return fde_sub_08ff58(a0, a1, a2);
        case 0x08ff60ULL: return fde_sub_08ff60(a0, a1, a2);
        case 0x08ff74ULL: return fde_sub_08ff74(a0, a1, a2);
        case 0x08ff94ULL: return fde_sub_08ff94(a0, a1, a2);
        case 0x08ffa0ULL: return fde_sub_08ffa0(a0, a1, a2);
        case 0x08ffb8ULL: return fde_sub_08ffb8(a0, a1, a2);
        case 0x08ffc0ULL: return fde_sub_08ffc0(a0, a1, a2);
        case 0x08ffc8ULL: return fde_sub_08ffc8(a0, a1, a2);
        case 0x08ffe0ULL: return fde_sub_08ffe0(a0, a1, a2);
        case 0x08fff8ULL: return fde_sub_08fff8(a0, a1, a2);
        case 0x090004ULL: return fde_sub_090004(a0, a1, a2);
        case 0x09000cULL: return fde_sub_09000c(a0, a1, a2);
        case 0x090028ULL: return fde_sub_090028(a0, a1, a2);
        case 0x09003cULL: return fde_sub_09003c(a0, a1, a2);
        case 0x09005cULL: return fde_sub_09005c(a0, a1, a2);
        case 0x09007cULL: return fde_sub_09007c(a0, a1, a2);
        case 0x090084ULL: return fde_sub_090084(a0, a1, a2);
        case 0x090098ULL: return fde_sub_090098(a0, a1, a2);
        case 0x0900b8ULL: return fde_sub_0900b8(a0, a1, a2);
        case 0x0900d8ULL: return fde_sub_0900d8(a0, a1, a2);
        case 0x0900e4ULL: return fde_sub_0900e4(a0, a1, a2);
        case 0x090104ULL: return fde_sub_090104(a0, a1, a2);
        case 0x090118ULL: return fde_sub_090118(a0, a1, a2);
        case 0x090128ULL: return fde_sub_090128(a0, a1, a2);
        case 0x090134ULL: return fde_sub_090134(a0, a1, a2);
        case 0x090140ULL: return fde_sub_090140(a0, a1, a2);
        case 0x090150ULL: return fde_sub_090150(a0, a1, a2);
        case 0x090158ULL: return fde_sub_090158(a0, a1, a2);
        case 0x090164ULL: return fde_sub_090164(a0, a1, a2);
        case 0x090174ULL: return fde_sub_090174(a0, a1, a2);
        case 0x09017cULL: return fde_sub_09017c(a0, a1, a2);
        case 0x090188ULL: return fde_sub_090188(a0, a1, a2);
        case 0x0901a0ULL: return fde_sub_0901a0(a0, a1, a2);
        case 0x0901b0ULL: return fde_sub_0901b0(a0, a1, a2);
        case 0x0901e0ULL: return fde_sub_0901e0(a0, a1, a2);
        case 0x0901f8ULL: return fde_sub_0901f8(a0, a1, a2);
        case 0x090210ULL: return fde_sub_090210(a0, a1, a2);
        case 0x090224ULL: return fde_sub_090224(a0, a1, a2);
        case 0x090230ULL: return fde_sub_090230(a0, a1, a2);
        case 0x090240ULL: return fde_sub_090240(a0, a1, a2);
        case 0x090260ULL: return fde_sub_090260(a0, a1, a2);
        case 0x090268ULL: return fde_sub_090268(a0, a1, a2);
        case 0x090270ULL: return fde_sub_090270(a0, a1, a2);
        case 0x090278ULL: return fde_sub_090278(a0, a1, a2);
        case 0x09028cULL: return fde_sub_09028c(a0, a1, a2);
        case 0x09029cULL: return fde_sub_09029c(a0, a1, a2);
        case 0x0902b4ULL: return fde_sub_0902b4(a0, a1, a2);
        case 0x0902c0ULL: return fde_sub_0902c0(a0, a1, a2);
        case 0x0902d4ULL: return fde_sub_0902d4(a0, a1, a2);
        case 0x0902ecULL: return fde_sub_0902ec(a0, a1, a2);
        case 0x090300ULL: return fde_sub_090300(a0, a1, a2);
        case 0x090310ULL: return fde_sub_090310(a0, a1, a2);
        case 0x09032cULL: return fde_sub_09032c(a0, a1, a2);
        case 0x090334ULL: return fde_sub_090334(a0, a1, a2);
        case 0x09033cULL: return fde_sub_09033c(a0, a1, a2);
        case 0x090350ULL: return fde_sub_090350(a0, a1, a2);
        case 0x090358ULL: return fde_sub_090358(a0, a1, a2);
        case 0x090364ULL: return fde_sub_090364(a0, a1, a2);
        case 0x09036cULL: return fde_sub_09036c(a0, a1, a2);
        case 0x090374ULL: return fde_sub_090374(a0, a1, a2);
        case 0x09037cULL: return fde_sub_09037c(a0, a1, a2);
        case 0x090388ULL: return fde_sub_090388(a0, a1, a2);
        case 0x09039cULL: return fde_sub_09039c(a0, a1, a2);
        case 0x0903a4ULL: return fde_sub_0903a4(a0, a1, a2);
        case 0x0903b8ULL: return fde_sub_0903b8(a0, a1, a2);
        case 0x0903d4ULL: return fde_sub_0903d4(a0, a1, a2);
        case 0x0903e8ULL: return fde_sub_0903e8(a0, a1, a2);
        case 0x0903f4ULL: return fde_sub_0903f4(a0, a1, a2);
        case 0x090400ULL: return fde_sub_090400(a0, a1, a2);
        case 0x09041cULL: return fde_sub_09041c(a0, a1, a2);
        case 0x090438ULL: return fde_sub_090438(a0, a1, a2);
        case 0x09044cULL: return fde_sub_09044c(a0, a1, a2);
        case 0x090454ULL: return fde_sub_090454(a0, a1, a2);
        case 0x09045cULL: return fde_sub_09045c(a0, a1, a2);
        case 0x090478ULL: return fde_sub_090478(a0, a1, a2);
        case 0x090484ULL: return fde_sub_090484(a0, a1, a2);
        case 0x090490ULL: return fde_sub_090490(a0, a1, a2);
        case 0x09049cULL: return fde_sub_09049c(a0, a1, a2);
        case 0x0904a8ULL: return fde_sub_0904a8(a0, a1, a2);
        case 0x0904b4ULL: return fde_sub_0904b4(a0, a1, a2);
        case 0x0904c8ULL: return fde_sub_0904c8(a0, a1, a2);
        case 0x0904d4ULL: return fde_sub_0904d4(a0, a1, a2);
        case 0x0904dcULL: return fde_sub_0904dc(a0, a1, a2);
        case 0x0904e8ULL: return fde_sub_0904e8(a0, a1, a2);
        case 0x0904fcULL: return fde_sub_0904fc(a0, a1, a2);
        case 0x090508ULL: return fde_sub_090508(a0, a1, a2);
        case 0x090524ULL: return fde_sub_090524(a0, a1, a2);
        case 0x090538ULL: return fde_sub_090538(a0, a1, a2);
        case 0x090544ULL: return fde_sub_090544(a0, a1, a2);
        case 0x090550ULL: return fde_sub_090550(a0, a1, a2);
        case 0x090564ULL: return fde_sub_090564(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace animax
} // namespace lynx
