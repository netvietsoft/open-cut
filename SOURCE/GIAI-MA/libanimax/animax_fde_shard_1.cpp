// ============================================================================
// File: animax_fde_shard_1.cpp
// Target 108 / 169: libanimax.so (657,720 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 1/5 covering FDEs [0..792]
//     (PC range 0x04403c .. 0x057a34).
// VI: Phân mảnh FDE AArch64 C++17 1/5 bao phủ FDE [0..792]
//     (Dải địa chỉ PC 0x04403c .. 0x057a34).
// ============================================================================
#include "animax_player_core.h"

namespace lynx {
namespace animax {

// FDE #0000 | PC: 0x04403c..0x04407c (64 B) | Symbol: sub_04403c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; adrp x1, #0x44000; mov x29, sp; str x19, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; adrp x1, #0x44000; mov x29, sp; str x19, [sp, #0x10]]
uint64_t fde_sub_04403c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000001ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04403CULL;
}

// FDE #0001 | PC: 0x04407c..0x0440fc (128 B) | Symbol: sub_04407c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; mov x1, x0; mov x29, sp; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; mov x1, x0; mov x29, sp; ldr x0, [x0]]
uint64_t fde_sub_04407c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E1ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04407CULL;
}

// FDE #0002 | PC: 0x0440fc..0x044194 (152 B) | Symbol: sub_0440fc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; mov x29, sp; stp x19, x20, [sp, #0x10]; ldr x20, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; mov x29, sp; stp x19, x20, [sp, #0x10]; ldr x20, [x0, #8]]
uint64_t fde_sub_0440fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0440FCULL;
}

// FDE #0003 | PC: 0x044194..0x0441b4 (32 B) | Symbol: sub_044194
// EN: AArch64 prologue [adrp x0, #0xa0000; add x1, x0, #0x90; ldr w2, [x1, #4]; cbz w2, #0x441b0] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xa0000; add x1, x0, #0x90; ldr w2, [x1, #4]; cbz w2, #0x441b0]
uint64_t fde_sub_044194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91024001ULL) << 32) | 0x900002E0ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044194ULL;
}

// FDE #0004 | PC: 0x0441b4..0x04430c (344 B) | Symbol: __emutls_get_address
// EN: AArch64 prologue [adrp x1, #0x9d000; stp x29, x30, [sp, #-0x40]!; mov x29, sp; ldr x1, [x1, #0xbe8]] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x9d000; stp x29, x30, [sp, #-0x40]!; mov x29, sp; ldr x1, [x1, #0xbe8]]
uint64_t fde_sub_0441b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xB00002C1ULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0441B4ULL;
}

// FDE #0005 | PC: 0x04430c..0x044348 (60 B) | Symbol: __emutls_register_common
// EN: AArch64 prologue [ldr x4, [x0]; cmp x4, x1; b.hs #0x44320; str x1, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x4, [x0]; cmp x4, x1; b.hs #0x44320; str x1, [x0]]
uint64_t fde_sub_04430c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB01009FULL) << 32) | 0xF9400004ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04430CULL;
}

// FDE #0006 | PC: 0x044348..0x044768 (1056 B) | Symbol: JNI_OnLoad
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x90300] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x90300]
uint64_t fde_sub_044348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0420ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044348ULL;
}

// FDE #0007 | PC: 0x044768..0x04479c (52 B) | Symbol: sub_044768
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4c718; mov x8, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4c718; mov x8, x0]
uint64_t fde_sub_044768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044768ULL;
}

// FDE #0008 | PC: 0x04479c..0x0447c0 (36 B) | Symbol: sub_04479c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fa28; mov w1, w19] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fa28; mov w1, w19]
uint64_t fde_sub_04479c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04479CULL;
}

// FDE #0009 | PC: 0x0447c0..0x044830 (112 B) | Symbol: sub_0447c0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0447c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0447C0ULL;
}

// FDE #0010 | PC: 0x044830..0x04483c (12 B) | Symbol: sub_044830
// EN: AArch64 prologue [cbz x0, #0x44838; b #0x4483c; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x44838; b #0x4483c; ret]
uint64_t fde_sub_044830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000002ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044830ULL;
}

// FDE #0011 | PC: 0x04483c..0x04487c (64 B) | Symbol: sub_04483c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x8, x0, #8; ldaxr x9, [x8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x8, x0, #8; ldaxr x9, [x8]]
uint64_t fde_sub_04483c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04483CULL;
}

// FDE #0012 | PC: 0x04487c..0x0448ac (48 B) | Symbol: sub_04487c
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c]
uint64_t fde_sub_04487c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04487CULL;
}

// FDE #0013 | PC: 0x0448ac..0x0448b0 (4 B) | Symbol: sub_0448ac
// EN: AArch64 prologue [b #0x44a14] | VI: Khởi đầu hàm AArch64 [b #0x44a14]
uint64_t fde_sub_0448ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0x1400005AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0448ACULL;
}

// FDE #0014 | PC: 0x0448b0..0x0448c4 (20 B) | Symbol: sub_0448b0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8fb5c; mov x0, x19; ldp x19, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8fb5c; mov x0, x19; ldp x19, x30, [sp], #0x10]
uint64_t fde_sub_0448b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012CAAULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0448B0ULL;
}

// FDE #0015 | PC: 0x0448c4..0x0449a8 (228 B) | Symbol: sub_0448c4
// EN: AArch64 prologue [mov x2, x30; bl #0x91aac; mov x30, x2; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x91aac; mov x30, x2; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_0448c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94013479ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0448C4ULL;
}

// FDE #0016 | PC: 0x0449a8..0x0449ec (68 B) | Symbol: sub_0449a8
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0xd0; ldarb w8, [x8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0xd0; ldarb w8, [x8]]
uint64_t fde_sub_0449a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002E8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0449A8ULL;
}

// FDE #0017 | PC: 0x0449ec..0x0449fc (16 B) | Symbol: sub_0449ec
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x46e54; ldr x30, [sp], #0x10; ret] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x46e54; ldr x30, [sp], #0x10; ret]
uint64_t fde_sub_0449ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000919ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0449ECULL;
}

// FDE #0018 | PC: 0x0449fc..0x044a00 (4 B) | Symbol: _ZN4lynx6animax21TextContentDataSourceD1Ev
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0449fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14013A38ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0449FCULL;
}

// FDE #0019 | PC: 0x044a00..0x044a04 (4 B) | Symbol: sub_044a00
// EN: AArch64 prologue [b #0x932e0] | VI: Khởi đầu hàm AArch64 [b #0x932e0]
uint64_t fde_sub_044a00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14012327ULL) << 32) | 0x14013A38ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044A00ULL;
}

// FDE #0020 | PC: 0x044a04..0x044a08 (4 B) | Symbol: sub_044a04
// EN: AArch64 prologue [b #0x8d6a0] | VI: Khởi đầu hàm AArch64 [b #0x8d6a0]
uint64_t fde_sub_044a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14012301ULL) << 32) | 0x14012327ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044A04ULL;
}

// FDE #0021 | PC: 0x044a08..0x044a0c (4 B) | Symbol: sub_044a08
// EN: AArch64 prologue [b #0x8d60c] | VI: Khởi đầu hàm AArch64 [b #0x8d60c]
uint64_t fde_sub_044a08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900011FULL) << 32) | 0x14012301ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044A08ULL;
}

// FDE #0022 | PC: 0x044a0c..0x044a14 (8 B) | Symbol: sub_044a0c
// EN: AArch64 prologue [str xzr, [x8]; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [x8]; ret]
uint64_t fde_sub_044a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF900011FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044A0CULL;
}

// FDE #0023 | PC: 0x044a14..0x044a54 (64 B) | Symbol: sub_044a14
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x38]; adrp x8, #0x98000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x38]; adrp x8, #0x98000]
uint64_t fde_sub_044a14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044A14ULL;
}

// FDE #0024 | PC: 0x044a54..0x044a68 (20 B) | Symbol: sub_044a54
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0]; cbz x0, #0x44a64; b #0x8f23c] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0]; cbz x0, #0x44a64; b #0x8f23c]
uint64_t fde_sub_044a54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044A54ULL;
}

// FDE #0025 | PC: 0x044a68..0x044a98 (48 B) | Symbol: sub_044a68
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; lsr x8, x1, #0x3d; cbnz x8, #0x44a94; bl #0x8f224] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; lsr x8, x1, #0x3d; cbnz x8, #0x44a94; bl #0x8f224]
uint64_t fde_sub_044a68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD37DFC28ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044A68ULL;
}

// FDE #0026 | PC: 0x044a98..0x044aac (20 B) | Symbol: sub_044a98
// EN: AArch64 prologue [lsr x8, x0, #0x3d; cbnz x8, #0x44aa4; b #0x91984; str x30, [sp, #-0x10]!] | VI: Khởi đầu hàm AArch64 [lsr x8, x0, #0x3d; cbnz x8, #0x44aa4; b #0x91984; str x30, [sp, #-0x10]!]
uint64_t fde_sub_044a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB5000048ULL) << 32) | 0xD37DFC08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044A98ULL;
}

// FDE #0027 | PC: 0x044aac..0x044adc (48 B) | Symbol: sub_044aac
// EN: AArch64 prologue [ldp x8, x9, [x0]; cmp x8, x9; b.eq #0x44ad8; ldr x10, [x1, #8]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0]; cmp x8, x9; b.eq #0x44ad8; ldr x10, [x1, #8]]
uint64_t fde_sub_044aac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA9402408ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044AACULL;
}

// FDE #0028 | PC: 0x044adc..0x044b18 (60 B) | Symbol: sub_044adc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8]
uint64_t fde_sub_044adc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044ADCULL;
}

// FDE #0029 | PC: 0x044b18..0x044b30 (24 B) | Symbol: sub_044b18
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0]; str xzr, [x8]; cbz x0, #0x44b2c] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0]; str xzr, [x8]; cbz x0, #0x44b2c]
uint64_t fde_sub_044b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044B18ULL;
}

// FDE #0030 | PC: 0x044b30..0x044b50 (32 B) | Symbol: sub_044b30
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xa0; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xa0; bl #0x8daa4]
uint64_t fde_sub_044b30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044B30ULL;
}

// FDE #0031 | PC: 0x044b50..0x044b68 (24 B) | Symbol: sub_044b50
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x44b30; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x44b30; mov x0, x19]
uint64_t fde_sub_044b50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044B50ULL;
}

// FDE #0032 | PC: 0x044b68..0x044b70 (8 B) | Symbol: sub_044b68
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x44b70] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x44b70]
uint64_t fde_sub_044b68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044B68ULL;
}

// FDE #0033 | PC: 0x044b70..0x044b98 (40 B) | Symbol: sub_044b70
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x1, [x0]; cbz x1, #0x44b90; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x1, [x0]; cbz x1, #0x44b90; mov x19, x0]
uint64_t fde_sub_044b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400001ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044B70ULL;
}

// FDE #0034 | PC: 0x044b98..0x044bc8 (48 B) | Symbol: sub_044b98
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454]
uint64_t fde_sub_044b98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044B98ULL;
}

// FDE #0035 | PC: 0x044bc8..0x044c10 (72 B) | Symbol: sub_044bc8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; mov w0, #0x18] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; mov w0, #0x18]
uint64_t fde_sub_044bc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044BC8ULL;
}

// FDE #0036 | PC: 0x044c10..0x044c18 (8 B) | Symbol: sub_044c10
// EN: AArch64 prologue [mov w0, #0xb; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xb; ret]
uint64_t fde_sub_044c10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800160ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044C10ULL;
}

// FDE #0037 | PC: 0x044c18..0x044c2c (20 B) | Symbol: sub_044c18
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; cbz w8, #0x44c28; ldrb w8, [x0, #0x14]; b #0x8e6c8] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; cbz w8, #0x44c28; ldrb w8, [x0, #0x14]; b #0x8e6c8]
uint64_t fde_sub_044c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000068ULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044C18ULL;
}

// FDE #0038 | PC: 0x044c2c..0x044cac (128 B) | Symbol: sub_044c2c
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e364] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e364]
uint64_t fde_sub_044c2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044C2CULL;
}

// FDE #0039 | PC: 0x044cac..0x044dac (256 B) | Symbol: sub_044cac
// EN: AArch64 prologue [mov x2, x30; bl #0x91aac; mov x30, x2; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x91aac; mov x30, x2; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_044cac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401337FULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044CACULL;
}

// FDE #0040 | PC: 0x044dac..0x044de0 (52 B) | Symbol: sub_044dac
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fa28; scvtf s0, w19] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fa28; scvtf s0, w19]
uint64_t fde_sub_044dac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044DACULL;
}

// FDE #0041 | PC: 0x044de0..0x044e0c (44 B) | Symbol: sub_044de0
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c]
uint64_t fde_sub_044de0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044DE0ULL;
}

// FDE #0042 | PC: 0x044e0c..0x044ee4 (216 B) | Symbol: sub_044e0c
// EN: AArch64 prologue [sub sp, sp, #0x50; str d8, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str d8, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_044e0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044E0CULL;
}

// FDE #0043 | PC: 0x044ee4..0x044f14 (48 B) | Symbol: sub_044ee4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fa28; str w19, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fa28; str w19, [x0, #8]]
uint64_t fde_sub_044ee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044EE4ULL;
}

// FDE #0044 | PC: 0x044f14..0x044f40 (44 B) | Symbol: sub_044f14
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c]
uint64_t fde_sub_044f14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044F14ULL;
}

// FDE #0045 | PC: 0x044f40..0x045010 (208 B) | Symbol: sub_044f40
// EN: AArch64 prologue [sub sp, sp, #0x50; str d8, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str d8, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_044f40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044F40ULL;
}

// FDE #0046 | PC: 0x045010..0x045048 (56 B) | Symbol: sub_045010
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c]
uint64_t fde_sub_045010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045010ULL;
}

// FDE #0047 | PC: 0x045048..0x045064 (28 B) | Symbol: sub_045048
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; cbz w8, #0x45060; ldrb w8, [x0, #0x14]; cbz w8, #0x45060] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; cbz w8, #0x45060; ldrb w8, [x0, #0x14]; cbz w8, #0x45060]
uint64_t fde_sub_045048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000A8ULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045048ULL;
}

// FDE #0048 | PC: 0x045064..0x04509c (56 B) | Symbol: sub_045064
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb40; ldur q0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb40; ldur q0, [x19, #8]]
uint64_t fde_sub_045064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045064ULL;
}

// FDE #0049 | PC: 0x04509c..0x0450a8 (12 B) | Symbol: sub_04509c
// EN: AArch64 prologue [mov v1.16b, v0.16b; mov v2.16b, v0.16b; b #0x450ac] | VI: Khởi đầu hàm AArch64 [mov v1.16b, v0.16b; mov v2.16b, v0.16b; b #0x450ac]
uint64_t fde_sub_04509c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA01C02ULL) << 32) | 0x4EA01C01ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04509CULL;
}

// FDE #0050 | PC: 0x0450a8..0x0450ac (4 B) | Symbol: sub_0450a8
// EN: AArch64 prologue [b #0x450ac] | VI: Khởi đầu hàm AArch64 [b #0x450ac]
uint64_t fde_sub_0450a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0450A8ULL;
}

// FDE #0051 | PC: 0x0450ac..0x0451fc (336 B) | Symbol: sub_0450ac
// EN: AArch64 prologue [sub sp, sp, #0x60; str d10, [sp, #0x10]; stp d9, d8, [sp, #0x18]; str x24, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d10, [sp, #0x10]; stp d9, d8, [sp, #0x18]; str x24, [sp, #0x28]]
uint64_t fde_sub_0450ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BEAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0450ACULL;
}

// FDE #0052 | PC: 0x0451fc..0x045224 (40 B) | Symbol: sub_0451fc
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; cbz w8, #0x45208; strb wzr, [x0, #0xc]; ldrb w8, [x0, #0x14]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; cbz w8, #0x45208; strb wzr, [x0, #0xc]; ldrb w8, [x0, #0x14]]
uint64_t fde_sub_0451fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0451FCULL;
}

// FDE #0053 | PC: 0x045224..0x045260 (60 B) | Symbol: sub_045224
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c]
uint64_t fde_sub_045224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045224ULL;
}

// FDE #0054 | PC: 0x045260..0x045264 (4 B) | Symbol: sub_045260
// EN: AArch64 prologue [b #0x92964] | VI: Khởi đầu hàm AArch64 [b #0x92964]
uint64_t fde_sub_045260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF4ULL) << 32) | 0x140135C1ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045260ULL;
}

// FDE #0055 | PC: 0x045264..0x045298 (52 B) | Symbol: sub_045264
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb40; ldur q0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb40; ldur q0, [x19, #8]]
uint64_t fde_sub_045264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045264ULL;
}

// FDE #0056 | PC: 0x045298..0x0453ac (276 B) | Symbol: sub_045298
// EN: AArch64 prologue [mov x2, x30; bl #0x91aac; mov x30, x2; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x91aac; mov x30, x2; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_045298(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94013204ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045298ULL;
}

// FDE #0057 | PC: 0x0453ac..0x045444 (152 B) | Symbol: sub_0453ac
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr q0, [x1]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr q0, [x1]]
uint64_t fde_sub_0453ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0453ACULL;
}

// FDE #0058 | PC: 0x045444..0x045468 (36 B) | Symbol: sub_045444
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8ff30] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8ff30]
uint64_t fde_sub_045444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045444ULL;
}

// FDE #0059 | PC: 0x045468..0x045490 (40 B) | Symbol: sub_045468
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x45488; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x45488; mov x0, x19]
uint64_t fde_sub_045468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012217ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045468ULL;
}

// FDE #0060 | PC: 0x045490..0x045498 (8 B) | Symbol: sub_045490
// EN: AArch64 prologue [mov x1, xzr; b #0x45468] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x45468]
uint64_t fde_sub_045490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF5ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045490ULL;
}

// FDE #0061 | PC: 0x045498..0x0454d0 (56 B) | Symbol: sub_045498
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; mov x19, x0]
uint64_t fde_sub_045498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045498ULL;
}

// FDE #0062 | PC: 0x0454d0..0x0454e8 (24 B) | Symbol: sub_0454d0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x45498; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x45498; mov x0, x19]
uint64_t fde_sub_0454d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0454D0ULL;
}

// FDE #0063 | PC: 0x0454e8..0x045a20 (1336 B) | Symbol: sub_0454e8
// EN: AArch64 prologue [sub sp, sp, #0xc0; str d10, [sp, #0x60]; stp d9, d8, [sp, #0x70]; stp x25, x24, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str d10, [sp, #0x60]; stp d9, d8, [sp, #0x70]; stp x25, x24, [sp, #0x80]]
uint64_t fde_sub_0454e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0033EAULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0538ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0454E8ULL;
}

// FDE #0064 | PC: 0x045a20..0x045a28 (8 B) | Symbol: sub_045a20
// EN: AArch64 prologue [str xzr, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [x0, #0x78]; ret]
uint64_t fde_sub_045a20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9003C1FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045A20ULL;
}

// FDE #0065 | PC: 0x045a28..0x045ae0 (184 B) | Symbol: sub_045a28
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr q0, [x1]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr q0, [x1]]
uint64_t fde_sub_045a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045A28ULL;
}

// FDE #0066 | PC: 0x045ae0..0x045b04 (36 B) | Symbol: sub_045ae0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x360; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x360; mov x19, x0]
uint64_t fde_sub_045ae0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000288ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045AE0ULL;
}

// FDE #0067 | PC: 0x045b04..0x045b1c (24 B) | Symbol: sub_045b04
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x45ae0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x45ae0; mov x0, x19]
uint64_t fde_sub_045b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045B04ULL;
}

// FDE #0068 | PC: 0x045b1c..0x045c18 (252 B) | Symbol: sub_045b1c
// EN: AArch64 prologue [sub sp, sp, #0x180; str d8, [sp, #0x130]; stp x28, x24, [sp, #0x140]; stp x23, x22, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; str d8, [sp, #0x130]; stp x28, x24, [sp, #0x140]; stp x23, x22, [sp, #0x150]]
uint64_t fde_sub_045b1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD009BE8ULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045B1CULL;
}

// FDE #0069 | PC: 0x045c18..0x045c40 (40 B) | Symbol: sub_045c18
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; mov x19, x0; add x8, x8, #0x968] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; mov x19, x0; add x8, x8, #0x968]
uint64_t fde_sub_045c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045C18ULL;
}

// FDE #0070 | PC: 0x045c40..0x045c58 (24 B) | Symbol: sub_045c40
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0]; str xzr, [x8]; cbz x0, #0x45c54] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0]; str xzr, [x8]; cbz x0, #0x45c54]
uint64_t fde_sub_045c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045C40ULL;
}

// FDE #0071 | PC: 0x045c58..0x045e58 (512 B) | Symbol: sub_045c58
// EN: AArch64 prologue [sub sp, sp, #0x80; str d8, [sp, #0x30]; str x26, [sp, #0x38]; stp x25, x24, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str d8, [sp, #0x30]; str x26, [sp, #0x38]; stp x25, x24, [sp, #0x40]]
uint64_t fde_sub_045c58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045C58ULL;
}

// FDE #0072 | PC: 0x045e58..0x045e80 (40 B) | Symbol: sub_045e58
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x45e78; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x45e78; mov x0, x19]
uint64_t fde_sub_045e58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011F9BULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045E58ULL;
}

// FDE #0073 | PC: 0x045e80..0x045e88 (8 B) | Symbol: sub_045e80
// EN: AArch64 prologue [mov x1, xzr; b #0x45e58] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x45e58]
uint64_t fde_sub_045e80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF5ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045E80ULL;
}

// FDE #0074 | PC: 0x045e88..0x045ea0 (24 B) | Symbol: sub_045e88
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x8c7fc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x8c7fc; mov x0, x19]
uint64_t fde_sub_045e88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011F24ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045E88ULL;
}

// FDE #0075 | PC: 0x045ea0..0x045f80 (224 B) | Symbol: sub_045ea0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; cmp x1, x0; cset w9, eq; mov x8, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; cmp x1, x0; cset w9, eq; mov x8, x0]
uint64_t fde_sub_045ea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB00003FULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045EA0ULL;
}

// FDE #0076 | PC: 0x045f80..0x045fbc (60 B) | Symbol: sub_045f80
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x9, [x8]; str x9, [x0, #8]; cbz x9, #0x45f94] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x9, [x8]; str x9, [x0, #8]; cbz x9, #0x45f94]
uint64_t fde_sub_045f80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400109ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045F80ULL;
}

// FDE #0077 | PC: 0x045fbc..0x045ff8 (60 B) | Symbol: sub_045fbc
// EN: AArch64 prologue [ldr x8, [x0]; ldr x9, [x8, #8]; str x9, [x0]; cbz x9, #0x45fd0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x9, [x8, #8]; str x9, [x0]; cbz x9, #0x45fd0]
uint64_t fde_sub_045fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400509ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045FBCULL;
}

// FDE #0078 | PC: 0x045ff8..0x046028 (48 B) | Symbol: sub_045ff8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x60]; adrp x8, #0x98000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x60]; adrp x8, #0x98000]
uint64_t fde_sub_045ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045FF8ULL;
}

// FDE #0079 | PC: 0x046028..0x046058 (48 B) | Symbol: sub_046028
// EN: AArch64 prologue [cbz x0, #0x46054; stp x19, x30, [sp, #-0x10]!; bl #0x930c8; bl #0x46028] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x46054; stp x19, x30, [sp, #-0x10]!; bl #0x930c8; bl #0x46028]
uint64_t fde_sub_046028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000160ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046028ULL;
}

// FDE #0080 | PC: 0x046058..0x046070 (24 B) | Symbol: sub_046058
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x45ff8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x45ff8; mov x0, x19]
uint64_t fde_sub_046058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046058ULL;
}

// FDE #0081 | PC: 0x046070..0x0460bc (76 B) | Symbol: sub_046070
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; add x8, x8, #0x400] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; add x8, x8, #0x400]
uint64_t fde_sub_046070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046070ULL;
}

// FDE #0082 | PC: 0x0460bc..0x0460d4 (24 B) | Symbol: sub_0460bc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x46070; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x46070; mov x0, x19]
uint64_t fde_sub_0460bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0460BCULL;
}

// FDE #0083 | PC: 0x0460d4..0x0460f0 (28 B) | Symbol: sub_0460d4
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; mov w9, #1; strb w9, [x0, #0x40]; ldr x9, [x8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; mov w9, #1; strb w9, [x0, #0x40]; ldr x9, [x8]]
uint64_t fde_sub_0460d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800029ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0460D4ULL;
}

// FDE #0084 | PC: 0x0460f0..0x046160 (112 B) | Symbol: sub_0460f0
// EN: AArch64 prologue [and w8, w1, #0xffff; sub w8, w8, #0xdb; cmp w8, #4; b.hi #0x4612c] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xffff; sub w8, w8, #0xdb; cmp w8, #4; b.hi #0x4612c]
uint64_t fde_sub_0460f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51036D08ULL) << 32) | 0x12003C28ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0460F0ULL;
}

// FDE #0085 | PC: 0x046160..0x046168 (8 B) | Symbol: sub_046160
// EN: AArch64 prologue [sub x0, x0, #8; b #0x46070] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x46070]
uint64_t fde_sub_046160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFC3ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046160ULL;
}

// FDE #0086 | PC: 0x046168..0x046170 (8 B) | Symbol: sub_046168
// EN: AArch64 prologue [sub x0, x0, #8; b #0x460bc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x460bc]
uint64_t fde_sub_046168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFD4ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046168ULL;
}

// FDE #0087 | PC: 0x046170..0x046214 (164 B) | Symbol: sub_046170
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov x0, x1] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov x0, x1]
uint64_t fde_sub_046170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046170ULL;
}

// FDE #0088 | PC: 0x046214..0x0463d8 (452 B) | Symbol: sub_046214
// EN: AArch64 prologue [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_046214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046214ULL;
}

// FDE #0089 | PC: 0x0463d8..0x0463e0 (8 B) | Symbol: sub_0463d8
// EN: AArch64 prologue [sub x0, x0, #8; b #0x460f0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x460f0]
uint64_t fde_sub_0463d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF45ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0463D8ULL;
}

// FDE #0090 | PC: 0x0463e0..0x04647c (156 B) | Symbol: sub_0463e0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0463e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0463E0ULL;
}

// FDE #0091 | PC: 0x04647c..0x046514 (152 B) | Symbol: sub_04647c
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_04647c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04647CULL;
}

// FDE #0092 | PC: 0x046514..0x04652c (24 B) | Symbol: sub_046514
// EN: AArch64 prologue [fmov s1, #1.00000000; fcmp s0, #0.0; fmin s0, s0, s1; fmov s1, wzr] | VI: Khởi đầu hàm AArch64 [fmov s1, #1.00000000; fcmp s0, #0.0; fmin s0, s0, s1; fmov s1, wzr]
uint64_t fde_sub_046514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E202008ULL) << 32) | 0x1E2E1001ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046514ULL;
}

// FDE #0093 | PC: 0x04652c..0x046544 (24 B) | Symbol: sub_04652c
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0]; str x1, [x8]; cbz x0, #0x46540] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0]; str x1, [x8]; cbz x0, #0x46540]
uint64_t fde_sub_04652c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04652CULL;
}

// FDE #0094 | PC: 0x046544..0x046560 (28 B) | Symbol: sub_046544
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fd14; bl #0x914a8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fd14; bl #0x914a8]
uint64_t fde_sub_046544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046544ULL;
}

// FDE #0095 | PC: 0x046560..0x046588 (40 B) | Symbol: sub_046560
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x490; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x490; mov x19, x0]
uint64_t fde_sub_046560(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000288ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046560ULL;
}

// FDE #0096 | PC: 0x046588..0x0465a0 (24 B) | Symbol: sub_046588
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x46560; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x46560; mov x0, x19]
uint64_t fde_sub_046588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046588ULL;
}

// FDE #0097 | PC: 0x0465a0..0x04662c (140 B) | Symbol: sub_0465a0
// EN: AArch64 prologue [fcmp s0, #0.0; fmov s1, wzr; b.ls #0x46624; fmov s1, #1.00000000] | VI: Khởi đầu hàm AArch64 [fcmp s0, #0.0; fmov s1, wzr; b.ls #0x46624; fmov s1, #1.00000000]
uint64_t fde_sub_0465a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2703E1ULL) << 32) | 0x1E202008ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0465A0ULL;
}

// FDE #0098 | PC: 0x04662c..0x046650 (36 B) | Symbol: sub_04662c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x0, #8]; ldr x8, [x8]; ldr x0, [x8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x0, #8]; ldr x8, [x8]; ldr x0, [x8]]
uint64_t fde_sub_04662c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04662CULL;
}

// FDE #0099 | PC: 0x046650..0x04665c (12 B) | Symbol: sub_046650
// EN: AArch64 prologue [cbz w1, #0x46658; b #0x8e158; b #0x91a58] | VI: Khởi đầu hàm AArch64 [cbz w1, #0x46658; b #0x8e158; b #0x91a58]
uint64_t fde_sub_046650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14011EC1ULL) << 32) | 0x34000041ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046650ULL;
}

// FDE #0100 | PC: 0x04665c..0x046660 (4 B) | Symbol: sub_04665c
// EN: AArch64 prologue [b #0x91a58] | VI: Khởi đầu hàm AArch64 [b #0x91a58]
uint64_t fde_sub_04665c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14012CFAULL) << 32) | 0x14012CFFULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04665CULL;
}

// FDE #0101 | PC: 0x046660..0x046664 (4 B) | Symbol: sub_046660
// EN: AArch64 prologue [b #0x91a48] | VI: Khởi đầu hàm AArch64 [b #0x91a48]
uint64_t fde_sub_046660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0x14012CFAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046660ULL;
}

// FDE #0102 | PC: 0x046664..0x046674 (16 B) | Symbol: sub_046664
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8]; ldr x0, [x8]; b #0x675f8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8]; ldr x0, [x8]; b #0x675f8]
uint64_t fde_sub_046664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400108ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046664ULL;
}

// FDE #0103 | PC: 0x046674..0x046694 (32 B) | Symbol: sub_046674
// EN: AArch64 prologue [ldr s1, [x0, #0x18]; fcmp s1, s0; b.ne #0x46684; b #0x8d60c] | VI: Khởi đầu hàm AArch64 [ldr s1, [x0, #0x18]; fcmp s1, s0; b.ne #0x46684; b #0x8d60c]
uint64_t fde_sub_046674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E202020ULL) << 32) | 0xBD401801ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046674ULL;
}

// FDE #0104 | PC: 0x046694..0x046734 (160 B) | Symbol: sub_046694
// EN: AArch64 prologue [str d8, [sp, #-0x30]!; str x22, [sp, #8]; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x30]!; str x22, [sp, #8]; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]]
uint64_t fde_sub_046694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007F6ULL) << 32) | 0xFC1D0FE8ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046694ULL;
}

// FDE #0105 | PC: 0x046734..0x046744 (16 B) | Symbol: sub_046734
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0x4b8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0x4b8; b #0x8d518]
uint64_t fde_sub_046734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000289ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046734ULL;
}

// FDE #0106 | PC: 0x046744..0x04675c (24 B) | Symbol: sub_046744
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x46734; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x46734; mov x0, x19]
uint64_t fde_sub_046744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046744ULL;
}

// FDE #0107 | PC: 0x04675c..0x0467a8 (76 B) | Symbol: sub_04675c
// EN: AArch64 prologue [str d8, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ee48; mov v8.16b, v0.16b] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ee48; mov v8.16b, v0.16b]
uint64_t fde_sub_04675c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xFC1E0FE8ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04675CULL;
}

// FDE #0108 | PC: 0x0467a8..0x0467d0 (40 B) | Symbol: sub_0467a8
// EN: AArch64 prologue [tbnz w1, #0x1f, #0x467cc; ldr x9, [x0, #8]; ldp x8, x10, [x9]; sxtw x9, w1] | VI: Khởi đầu hàm AArch64 [tbnz w1, #0x1f, #0x467cc; ldr x9, [x0, #8]; ldp x8, x10, [x9]; sxtw x9, w1]
uint64_t fde_sub_0467a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400409ULL) << 32) | 0x37F80121ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0467A8ULL;
}

// FDE #0109 | PC: 0x0467d0..0x0467e4 (20 B) | Symbol: sub_0467d0
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldp x9, x8, [x8]; sub x8, x8, x9; lsr x0, x8, #3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldp x9, x8, [x8]; sub x8, x8, x9; lsr x0, x8, #3]
uint64_t fde_sub_0467d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9402109ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0467D0ULL;
}

// FDE #0110 | PC: 0x0467e4..0x0467e8 (4 B) | Symbol: _ZNK4lynx6animax18LayerStaticRequest10GetKeyPathEv
// EN: AArch64 prologue [b #0x91108] | VI: Khởi đầu hàm AArch64 [b #0x91108]
uint64_t fde_sub_0467e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0x14012A49ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0467E4ULL;
}

// FDE #0111 | PC: 0x0467e8..0x0467f8 (16 B) | Symbol: sub_0467e8
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #8]; ldur x0, [x8, #-8]; b #0x675f8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #8]; ldur x0, [x8, #-8]; b #0x675f8]
uint64_t fde_sub_0467e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400508ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0467E8ULL;
}

// FDE #0112 | PC: 0x0467f8..0x04682c (52 B) | Symbol: sub_0467f8
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x18]; cmp x8, x9; b.eq #0x46814; mov w8, wzr] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x18]; cmp x8, x9; b.eq #0x46814; mov w8, wzr]
uint64_t fde_sub_0467f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA941A009ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0467F8ULL;
}

// FDE #0113 | PC: 0x04682c..0x046964 (312 B) | Symbol: sub_04682c
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_04682c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04682CULL;
}

// FDE #0114 | PC: 0x046964..0x04696c (8 B) | Symbol: sub_046964
// EN: AArch64 prologue [mov w3, #2; b #0x93340] | VI: Khởi đầu hàm AArch64 [mov w3, #2; b #0x93340]
uint64_t fde_sub_046964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14013276ULL) << 32) | 0x52800043ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046964ULL;
}

// FDE #0115 | PC: 0x04696c..0x046990 (36 B) | Symbol: sub_04696c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8eb14; mov x1, x19] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8eb14; mov x1, x19]
uint64_t fde_sub_04696c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04696CULL;
}

// FDE #0116 | PC: 0x046990..0x0469a0 (16 B) | Symbol: sub_046990
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0x568; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0x568; b #0x8d518]
uint64_t fde_sub_046990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000289ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046990ULL;
}

// FDE #0117 | PC: 0x0469a0..0x0469b8 (24 B) | Symbol: sub_0469a0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x46990; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x46990; mov x0, x19]
uint64_t fde_sub_0469a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0469A0ULL;
}

// FDE #0118 | PC: 0x0469b8..0x046b60 (424 B) | Symbol: sub_0469b8
// EN: AArch64 prologue [sub sp, sp, #0x90; str x28, [sp, #0x30]; stp x27, x26, [sp, #0x40]; stp x25, x24, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x28, [sp, #0x30]; stp x27, x26, [sp, #0x40]; stp x25, x24, [sp, #0x50]]
uint64_t fde_sub_0469b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0469B8ULL;
}

// FDE #0119 | PC: 0x046b60..0x046ba0 (64 B) | Symbol: sub_046b60
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; strb wzr, [x0]; str x1, [x0, #8]; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; strb wzr, [x0]; str x1, [x0, #8]; ldr x8, [x1]]
uint64_t fde_sub_046b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3900001FULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046B60ULL;
}

// FDE #0120 | PC: 0x046ba0..0x046bd0 (48 B) | Symbol: sub_046ba0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x90]; cmn w0, #1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x90]; cmn w0, #1]
uint64_t fde_sub_046ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046BA0ULL;
}

// FDE #0121 | PC: 0x046bd0..0x046bdc (12 B) | Symbol: sub_046bd0
// EN: AArch64 prologue [ldr w8, [x0, #0x20]; orr w1, w8, w1; b #0x93350] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x20]; orr w1, w8, w1; b #0x93350]
uint64_t fde_sub_046bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A010101ULL) << 32) | 0xB9402008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046BD0ULL;
}

// FDE #0122 | PC: 0x046bdc..0x046c54 (120 B) | Symbol: sub_046bdc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0, #8]; ldr x9, [x8]; ldur x9, [x9, #-0x18]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0, #8]; ldr x9, [x8]; ldur x9, [x9, #-0x18]]
uint64_t fde_sub_046bdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046BDCULL;
}

// FDE #0123 | PC: 0x046c54..0x046c68 (20 B) | Symbol: sub_046c54
// EN: AArch64 prologue [ldrb w8, [x0]; tbnz w8, #0, #0x46c60; ret; ldr x0, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0]; tbnz w8, #0, #0x46c60; ret; ldr x0, [x0, #0x10]]
uint64_t fde_sub_046c54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000048ULL) << 32) | 0x39400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046C54ULL;
}

// FDE #0124 | PC: 0x046c68..0x046c80 (24 B) | Symbol: sub_046c68
// EN: AArch64 prologue [cbz x1, #0x46c7c; mov x8, x1; mov w1, w2; mov x2, x8] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x46c7c; mov x8, x1; mov w1, w2; mov x2, x8]
uint64_t fde_sub_046c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E8ULL) << 32) | 0xB40000A1ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046C68ULL;
}

// FDE #0125 | PC: 0x046c80..0x046cf4 (116 B) | Symbol: sub_046c80
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mrs x20, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mrs x20, tpidr_el0]
uint64_t fde_sub_046c80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046C80ULL;
}

// FDE #0126 | PC: 0x046cf4..0x046d58 (100 B) | Symbol: sub_046cf4
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; ldr x8, [x0]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; ldr x8, [x0]; mov x19, x0]
uint64_t fde_sub_046cf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046CF4ULL;
}

// FDE #0127 | PC: 0x046d58..0x046d70 (24 B) | Symbol: sub_046d58
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; cbz x0, #0x46d6c; ldr x8, [x0]; ldr x1, [x8, #0x28]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; cbz x0, #0x46d6c; ldr x8, [x0]; ldr x1, [x8, #0x28]]
uint64_t fde_sub_046d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000080ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046D58ULL;
}

// FDE #0128 | PC: 0x046d70..0x046e10 (160 B) | Symbol: sub_046d70
// EN: AArch64 prologue [str d8, [sp, #-0x20]!; str x20, [sp, #8]; stp x19, x30, [sp, #0x10]; ldr x8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x20]!; str x20, [sp, #8]; stp x19, x30, [sp, #0x10]; ldr x8, [x0, #0x10]]
uint64_t fde_sub_046d70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007F4ULL) << 32) | 0xFC1E0FE8ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046D70ULL;
}

// FDE #0129 | PC: 0x046e10..0x046e54 (68 B) | Symbol: sub_046e10
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0xd8; ldarb w8, [x8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0xd8; ldarb w8, [x8]]
uint64_t fde_sub_046e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002C8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046E10ULL;
}

// FDE #0130 | PC: 0x046e54..0x046f08 (180 B) | Symbol: sub_046e54
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_046e54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0x6DBD23E9ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046E54ULL;
}

// FDE #0131 | PC: 0x046f08..0x046f8c (132 B) | Symbol: sub_046f08
// EN: AArch64 prologue [stp d11, d10, [sp, #-0x40]!; stp d9, d8, [sp, #0x10]; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d11, d10, [sp, #-0x40]!; stp d9, d8, [sp, #0x10]; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_046f08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0x6DBC2BEBULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046F08ULL;
}

// FDE #0132 | PC: 0x046f8c..0x046fc0 (52 B) | Symbol: sub_046f8c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr s0, [x0, #0x40]; fmov s1, #-1.00000000; fcmp s0, s1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr s0, [x0, #0x40]; fmov s1, #-1.00000000; fcmp s0, s1]
uint64_t fde_sub_046f8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD404000ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046F8CULL;
}

// FDE #0133 | PC: 0x046fc0..0x046ff4 (52 B) | Symbol: sub_046fc0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr s0, [x0, #0x44]; fmov s1, #-1.00000000; fcmp s0, s1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr s0, [x0, #0x44]; fmov s1, #-1.00000000; fcmp s0, s1]
uint64_t fde_sub_046fc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD404400ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046FC0ULL;
}

// FDE #0134 | PC: 0x046ff4..0x04702c (56 B) | Symbol: sub_046ff4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x0]; mov w1, wzr; bl #0x8e99c] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x0]; mov w1, wzr; bl #0x8e99c]
uint64_t fde_sub_046ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046FF4ULL;
}

// FDE #0135 | PC: 0x04702c..0x0470b8 (140 B) | Symbol: sub_04702c
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x20, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x20, tpidr_el0]
uint64_t fde_sub_04702c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91353FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04702CULL;
}

// FDE #0136 | PC: 0x0470b8..0x0470d4 (28 B) | Symbol: sub_0470b8
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; str x1, [sp, #8]; add x0, x0, #0x18; add x1, sp, #8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; str x1, [sp, #8]; add x0, x0, #0x18; add x1, sp, #8]
uint64_t fde_sub_0470b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007E1ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0470B8ULL;
}

// FDE #0137 | PC: 0x0470d4..0x047164 (144 B) | Symbol: sub_0470d4
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0470d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0470D4ULL;
}

// FDE #0138 | PC: 0x047164..0x04722c (200 B) | Symbol: sub_047164
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp d11, d10, [sp, #0x40]; stp d9, d8, [sp, #0x50]; str x24, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp d11, d10, [sp, #0x40]; stp d9, d8, [sp, #0x50]; str x24, [sp, #0x60]]
uint64_t fde_sub_047164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D042BEBULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047164ULL;
}

// FDE #0139 | PC: 0x04722c..0x0472f0 (196 B) | Symbol: sub_04722c
// EN: AArch64 prologue [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_04722c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012288ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04722CULL;
}

// FDE #0140 | PC: 0x0472f0..0x0477fc (1292 B) | Symbol: sub_0472f0
// EN: AArch64 prologue [sub sp, sp, #0x1e0; str d8, [sp, #0x170]; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; str d8, [sp, #0x170]; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]]
uint64_t fde_sub_0472f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00BBE8ULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x050CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0472F0ULL;
}

// FDE #0141 | PC: 0x0477fc..0x04796c (368 B) | Symbol: sub_0477fc
// EN: AArch64 prologue [sub sp, sp, #0x80; str x26, [sp, #0x30]; stp x25, x24, [sp, #0x40]; stp x23, x22, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x26, [sp, #0x30]; stp x25, x24, [sp, #0x40]; stp x23, x22, [sp, #0x50]]
uint64_t fde_sub_0477fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BFAULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0477FCULL;
}

// FDE #0142 | PC: 0x04796c..0x047b64 (504 B) | Symbol: sub_04796c
// EN: AArch64 prologue [sub sp, sp, #0x70; mov x3, x30; bl #0x90cd8; mov x30, x3] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; mov x3, x30; bl #0x90cd8; mov x30, x3]
uint64_t fde_sub_04796c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04796CULL;
}

// FDE #0143 | PC: 0x047b64..0x047b84 (32 B) | Symbol: sub_047b64
// EN: AArch64 prologue [ldr x8, [x0, #0x38]; adrp x9, #0x9b000; add x9, x9, #0x9a0; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x38]; adrp x9, #0x9b000; add x9, x9, #0x9a0; str x9, [x0]]
uint64_t fde_sub_047b64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002A9ULL) << 32) | 0xF9401C08ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047B64ULL;
}

// FDE #0144 | PC: 0x047b84..0x047bc8 (68 B) | Symbol: sub_047b84
// EN: AArch64 prologue [ldrb w8, [x1, #0xc]; ldrb w10, [x1, #0x14]; add x9, x0, #0x20; add x11, x1, #0x18] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x1, #0xc]; ldrb w10, [x1, #0x14]; add x9, x0, #0x20; add x11, x1, #0x18]
uint64_t fde_sub_047b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940502AULL) << 32) | 0x39403028ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047B84ULL;
}

// FDE #0145 | PC: 0x047bc8..0x047c0c (68 B) | Symbol: sub_047bc8
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; cbz w8, #0x47c08; ldr s3, [x0, #8]; fcmp s3, s0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; cbz w8, #0x47c08; ldr s3, [x0, #8]; fcmp s3, s0]
uint64_t fde_sub_047bc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340001E8ULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047BC8ULL;
}

// FDE #0146 | PC: 0x047c0c..0x047c4c (64 B) | Symbol: sub_047c0c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; mov x19, x0]
uint64_t fde_sub_047c0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047C0CULL;
}

// FDE #0147 | PC: 0x047c4c..0x047c64 (24 B) | Symbol: sub_047c4c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x47c0c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x47c0c; mov x0, x19]
uint64_t fde_sub_047c4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047C4CULL;
}

// FDE #0148 | PC: 0x047c64..0x047ce0 (124 B) | Symbol: sub_047c64
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr q0, [x3]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr q0, [x3]]
uint64_t fde_sub_047c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047C64ULL;
}

// FDE #0149 | PC: 0x047ce0..0x047d20 (64 B) | Symbol: sub_047ce0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; mov x19, x0]
uint64_t fde_sub_047ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047CE0ULL;
}

// FDE #0150 | PC: 0x047d20..0x047d38 (24 B) | Symbol: sub_047d20
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x47ce0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x47ce0; mov x0, x19]
uint64_t fde_sub_047d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047D20ULL;
}

// FDE #0151 | PC: 0x047d38..0x047df8 (192 B) | Symbol: sub_047d38
// EN: AArch64 prologue [str d8, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_047d38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xFC1D0FE8ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047D38ULL;
}

// FDE #0152 | PC: 0x047df8..0x047dfc (4 B) | Symbol: sub_047df8
// EN: AArch64 prologue [b #0x92cfc] | VI: Khởi đầu hàm AArch64 [b #0x92cfc]
uint64_t fde_sub_047df8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3941F009ULL) << 32) | 0x14012BC1ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047DF8ULL;
}

// FDE #0153 | PC: 0x047dfc..0x047e4c (80 B) | Symbol: sub_047dfc
// EN: AArch64 prologue [ldrb w9, [x0, #0x7c]; ldrb w12, [x0, #0x84]; add x10, x0, #0x90; add x11, x0, #0x78] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x7c]; ldrb w12, [x0, #0x84]; add x10, x0, #0x90; add x11, x0, #0x78]
uint64_t fde_sub_047dfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3942100CULL) << 32) | 0x3941F009ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047DFCULL;
}

// FDE #0154 | PC: 0x047e4c..0x047f90 (324 B) | Symbol: sub_047e4c
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x30]; str x22, [sp, #0x38]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x30]; str x22, [sp, #0x38]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_047e4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047E4CULL;
}

// FDE #0155 | PC: 0x047f90..0x047fbc (44 B) | Symbol: sub_047f90
// EN: AArch64 prologue [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ldrb w8, [x1]; tbnz w8, #0, #0x47fb4] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ldrb w8, [x1]; tbnz w8, #0, #0x47fb4]
uint64_t fde_sub_047f90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900081FULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047F90ULL;
}

// FDE #0156 | PC: 0x047fbc..0x047ff4 (56 B) | Symbol: sub_047fbc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dd00; bl #0x48010] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dd00; bl #0x48010]
uint64_t fde_sub_047fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047FBCULL;
}

// FDE #0157 | PC: 0x047ff4..0x048010 (28 B) | Symbol: sub_047ff4
// EN: AArch64 prologue [mov x8, xzr; cmp x8, #0x18; b.eq #0x4800c; str xzr, [x0, x8]] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; cmp x8, #0x18; b.eq #0x4800c; str xzr, [x0, x8]]
uint64_t fde_sub_047ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100611FULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047FF4ULL;
}

// FDE #0158 | PC: 0x048010..0x048030 (32 B) | Symbol: sub_048010
// EN: AArch64 prologue [ldrb w8, [x0]; tbnz w8, #0, #0x48020; strh wzr, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0]; tbnz w8, #0, #0x48020; strh wzr, [x0]; ret]
uint64_t fde_sub_048010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000068ULL) << 32) | 0x39400008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048010ULL;
}

// FDE #0159 | PC: 0x048030..0x04808c (92 B) | Symbol: sub_048030
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; cmn x2, #0x10] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; cmn x2, #0x10]
uint64_t fde_sub_048030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048030ULL;
}

// FDE #0160 | PC: 0x04808c..0x048098 (12 B) | Symbol: sub_04808c
// EN: AArch64 prologue [cbz x2, #0x48094; b #0x931f0; ret] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x48094; b #0x931f0; ret]
uint64_t fde_sub_04808c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14012C58ULL) << 32) | 0xB4000042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04808CULL;
}

// FDE #0161 | PC: 0x048098..0x0480bc (36 B) | Symbol: sub_048098
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8e230] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8e230]
uint64_t fde_sub_048098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048098ULL;
}

// FDE #0162 | PC: 0x0480bc..0x0480e8 (44 B) | Symbol: sub_0480bc
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8d8ac; bl #0x8e38c]
uint64_t fde_sub_0480bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0480BCULL;
}

// FDE #0163 | PC: 0x0480e8..0x048118 (48 B) | Symbol: sub_0480e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x48]; adrp x8, #0x98000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x48]; adrp x8, #0x98000]
uint64_t fde_sub_0480e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0480E8ULL;
}

// FDE #0164 | PC: 0x048118..0x048130 (24 B) | Symbol: sub_048118
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x480e8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x480e8; mov x0, x19]
uint64_t fde_sub_048118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048118ULL;
}

// FDE #0165 | PC: 0x048130..0x048150 (32 B) | Symbol: sub_048130
// EN: AArch64 prologue [cbz x0, #0x4814c; stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x44b70] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4814c; stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x44b70]
uint64_t fde_sub_048130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB40000E0ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048130ULL;
}

// FDE #0166 | PC: 0x048150..0x048164 (20 B) | Symbol: sub_048150
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8d58c; mov x0, x19; ldp x19, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8d58c; mov x0, x19; ldp x19, x30, [sp], #0x10]
uint64_t fde_sub_048150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401150EULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048150ULL;
}

// FDE #0167 | PC: 0x048164..0x04816c (8 B) | Symbol: sub_048164
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; b #0x48130] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; b #0x48130]
uint64_t fde_sub_048164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF2ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048164ULL;
}

// FDE #0168 | PC: 0x04816c..0x048190 (36 B) | Symbol: sub_04816c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8ff30] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8ff30]
uint64_t fde_sub_04816c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04816CULL;
}

// FDE #0169 | PC: 0x048190..0x0481b8 (40 B) | Symbol: sub_048190
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x481b0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x481b0; mov x0, x19]
uint64_t fde_sub_048190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940116CDULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048190ULL;
}

// FDE #0170 | PC: 0x0481b8..0x0481c0 (8 B) | Symbol: sub_0481b8
// EN: AArch64 prologue [mov x1, xzr; b #0x48190] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x48190]
uint64_t fde_sub_0481b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF5ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0481B8ULL;
}

// FDE #0171 | PC: 0x0481c0..0x048258 (152 B) | Symbol: sub_0481c0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x90]; adrp x8, #0x98000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x90]; adrp x8, #0x98000]
uint64_t fde_sub_0481c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0481C0ULL;
}

// FDE #0172 | PC: 0x048258..0x048270 (24 B) | Symbol: sub_048258
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x481c0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x481c0; mov x0, x19]
uint64_t fde_sub_048258(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048258ULL;
}

// FDE #0173 | PC: 0x048270..0x0484a8 (568 B) | Symbol: sub_048270
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_048270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0238ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048270ULL;
}

// FDE #0174 | PC: 0x0484a8..0x048588 (224 B) | Symbol: sub_0484a8
// EN: AArch64 prologue [mov x3, x30; bl #0x90b54; mov x30, x3; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x90b54; mov x30, x3; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0484a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940121AAULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0484A8ULL;
}

// FDE #0175 | PC: 0x048588..0x048624 (156 B) | Symbol: sub_048588
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_048588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048588ULL;
}

// FDE #0176 | PC: 0x048624..0x0486b4 (144 B) | Symbol: sub_048624
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x0, #0x50]; add x20, x1, #0x28] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x0, #0x50]; add x20, x1, #0x28]
uint64_t fde_sub_048624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048624ULL;
}

// FDE #0177 | PC: 0x0486b4..0x048774 (192 B) | Symbol: sub_0486b4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; ldr x0, [x0, #0x50]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; ldr x0, [x0, #0x50]]
uint64_t fde_sub_0486b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0486B4ULL;
}

// FDE #0178 | PC: 0x048774..0x0488d0 (348 B) | Symbol: sub_048774
// EN: AArch64 prologue [str d10, [sp, #-0x40]!; stp d9, d8, [sp, #8]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [str d10, [sp, #-0x40]!; stp d9, d8, [sp, #8]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]]
uint64_t fde_sub_048774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D00A3E9ULL) << 32) | 0xFC1C0FEAULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048774ULL;
}

// FDE #0179 | PC: 0x0488d0..0x048d20 (1104 B) | Symbol: sub_0488d0
// EN: AArch64 prologue [str d12, [sp, #-0x60]!; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; stp x23, x22, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d12, [sp, #-0x60]!; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; stp x23, x22, [sp, #0x30]]
uint64_t fde_sub_0488d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D012BEBULL) << 32) | 0xFC1A0FECULL;
    const uint64_t kPcRange = 0x0450ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0488D0ULL;
}

// FDE #0180 | PC: 0x048d20..0x048d40 (32 B) | Symbol: sub_048d20
// EN: AArch64 prologue [mov x8, xzr; cmp x8, #0x24; b.eq #0x48d3c; ldr x9, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; cmp x8, #0x24; b.eq #0x48d3c; ldr x9, [x0, #0x28]]
uint64_t fde_sub_048d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100911FULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048D20ULL;
}

// FDE #0181 | PC: 0x048d40..0x048d4c (12 B) | Symbol: sub_048d40
// EN: AArch64 prologue [cbz x0, #0x48d48; b #0x932d0; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x48d48; b #0x932d0; ret]
uint64_t fde_sub_048d40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14012963ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048D40ULL;
}

// FDE #0182 | PC: 0x048d4c..0x048d74 (40 B) | Symbol: sub_048d4c
// EN: AArch64 prologue [cbz x0, #0x48d70; stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; bl #0x44830] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x48d70; stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; bl #0x44830]
uint64_t fde_sub_048d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000120ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048D4CULL;
}

// FDE #0183 | PC: 0x048d74..0x048d7c (8 B) | Symbol: sub_048d74
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; b #0x48d4c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; b #0x48d4c]
uint64_t fde_sub_048d74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF5ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048D74ULL;
}

// FDE #0184 | PC: 0x048d7c..0x048d8c (16 B) | Symbol: sub_048d7c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; strb wzr, [x0, #0x38]; mov x0, x8; b #0x4948c] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; strb wzr, [x0, #0x38]; mov x0, x8; b #0x4948c]
uint64_t fde_sub_048d7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3900E01FULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048D7CULL;
}

// FDE #0185 | PC: 0x048d8c..0x048da0 (20 B) | Symbol: sub_048d8c
// EN: AArch64 prologue [ldp d1, d2, [x0, #0x58]; mov w1, wzr; fsub d1, d2, d1; fmul d0, d1, d0] | VI: Khởi đầu hàm AArch64 [ldp d1, d2, [x0, #0x58]; mov w1, wzr; fsub d1, d2, d1; fmul d0, d1, d0]
uint64_t fde_sub_048d8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0x6D458801ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048D8CULL;
}

// FDE #0186 | PC: 0x048da0..0x048da4 (4 B) | Symbol: sub_048da0
// EN: AArch64 prologue [b #0x494e8] | VI: Khởi đầu hàm AArch64 [b #0x494e8]
uint64_t fde_sub_048da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0x140001D2ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048DA0ULL;
}

// FDE #0187 | PC: 0x048da4..0x048db4 (16 B) | Symbol: sub_048da4
// EN: AArch64 prologue [mov x3, x30; bl #0x9000c; mov x30, x3; b #0x469b8] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x9000c; mov x30, x3; b #0x469b8]
uint64_t fde_sub_048da4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011C99ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048DA4ULL;
}

// FDE #0188 | PC: 0x048db4..0x048de4 (48 B) | Symbol: sub_048db4
// EN: AArch64 prologue [cbz x0, #0x48de0; stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x48de0; stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x48d40]
uint64_t fde_sub_048db4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000160ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048DB4ULL;
}

// FDE #0189 | PC: 0x048de4..0x048dec (8 B) | Symbol: sub_048de4
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; b #0x48db4] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; b #0x48db4]
uint64_t fde_sub_048de4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF3ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048DE4ULL;
}

// FDE #0190 | PC: 0x048dec..0x048e74 (136 B) | Symbol: sub_048dec
// EN: AArch64 prologue [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_048dec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048DECULL;
}

// FDE #0191 | PC: 0x048e74..0x048e8c (24 B) | Symbol: sub_048e74
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0x798; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0x798; str x9, [x0]]
uint64_t fde_sub_048e74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000289ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048E74ULL;
}

// FDE #0192 | PC: 0x048e8c..0x048ea4 (24 B) | Symbol: sub_048e8c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x48e74; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x48e74; mov x0, x19]
uint64_t fde_sub_048e8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048E8CULL;
}

// FDE #0193 | PC: 0x048ea4..0x049124 (640 B) | Symbol: sub_048ea4
// EN: AArch64 prologue [sub sp, sp, #0x60; stp d9, d8, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp d9, d8, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]]
uint64_t fde_sub_048ea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0280ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048EA4ULL;
}

// FDE #0194 | PC: 0x049124..0x049154 (48 B) | Symbol: sub_049124
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e50c; cbz x0, #0x49148] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e50c; cbz x0, #0x49148]
uint64_t fde_sub_049124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049124ULL;
}

// FDE #0195 | PC: 0x049154..0x049198 (68 B) | Symbol: sub_049154
// EN: AArch64 prologue [ldrb w8, [x0, #0x34]; cbz w8, #0x49164; ldrb w8, [x0, #0x78]; tbnz w8, #0, #0x49174] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x34]; cbz w8, #0x49164; ldrb w8, [x0, #0x78]; tbnz w8, #0, #0x49174]
uint64_t fde_sub_049154(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000068ULL) << 32) | 0x3940D008ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049154ULL;
}

// FDE #0196 | PC: 0x049198..0x049290 (248 B) | Symbol: sub_049198
// EN: AArch64 prologue [sub sp, sp, #0x170; stp d9, d8, [sp, #0x130]; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp d9, d8, [sp, #0x130]; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_049198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D1323E9ULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049198ULL;
}

// FDE #0197 | PC: 0x049290..0x049298 (8 B) | Symbol: sub_049290
// EN: AArch64 prologue [mov w3, #4; b #0x93340] | VI: Khởi đầu hàm AArch64 [mov w3, #4; b #0x93340]
uint64_t fde_sub_049290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1401282BULL) << 32) | 0x52800083ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049290ULL;
}

// FDE #0198 | PC: 0x049298..0x049314 (124 B) | Symbol: sub_049298
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_049298(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049298ULL;
}

// FDE #0199 | PC: 0x049314..0x04932c (24 B) | Symbol: sub_049314
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; adrp x1, #0x9d000; ldr x1, [x1, #0xbf8]; bl #0x93380] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; adrp x1, #0x9d000; ldr x1, [x1, #0xbf8]; bl #0x93380]
uint64_t fde_sub_049314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002A1ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049314ULL;
}

// FDE #0200 | PC: 0x04932c..0x049350 (36 B) | Symbol: sub_04932c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x49350; ldrb w8, [x19, #0x98]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x49350; ldrb w8, [x19, #0x98]]
uint64_t fde_sub_04932c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04932CULL;
}

// FDE #0201 | PC: 0x049350..0x049430 (224 B) | Symbol: sub_049350
// EN: AArch64 prologue [sub sp, sp, #0x60; stp d9, d8, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp d9, d8, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_049350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0223E9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049350ULL;
}

// FDE #0202 | PC: 0x049430..0x049454 (36 B) | Symbol: sub_049430
// EN: AArch64 prologue [ldr d1, [x0, #0x80]; ldr d0, [x0, #0x40]; fcmp d1, d0; b.mi #0x4944c] | VI: Khởi đầu hàm AArch64 [ldr d1, [x0, #0x80]; ldr d0, [x0, #0x40]; fcmp d1, d0; b.mi #0x4944c]
uint64_t fde_sub_049430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD402000ULL) << 32) | 0xFD404001ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049430ULL;
}

// FDE #0203 | PC: 0x049454..0x049464 (16 B) | Symbol: sub_049454
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0x7c0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0x7c0; b #0x8d518]
uint64_t fde_sub_049454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000269ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049454ULL;
}

// FDE #0204 | PC: 0x049464..0x04947c (24 B) | Symbol: sub_049464
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x49454; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x49454; mov x0, x19]
uint64_t fde_sub_049464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049464ULL;
}

// FDE #0205 | PC: 0x04947c..0x04948c (16 B) | Symbol: sub_04947c
// EN: AArch64 prologue [ldr x0, [x0, #8]; cbz x0, #0x49488; b #0x90a38; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; cbz x0, #0x49488; b #0x90a38; ret]
uint64_t fde_sub_04947c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04947CULL;
}

// FDE #0206 | PC: 0x04948c..0x0494e8 (92 B) | Symbol: sub_04948c
// EN: AArch64 prologue [sub sp, sp, #0x20; str x30, [sp, #0x10]; ldrb w8, [x0, #0x98]; mov x9, #-0x4010000000000000] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; str x30, [sp, #0x10]; ldrb w8, [x0, #0x98]; mov x9, #-0x4010000000000000]
uint64_t fde_sub_04948c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFEULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04948CULL;
}

// FDE #0207 | PC: 0x0494e8..0x049680 (408 B) | Symbol: sub_0494e8
// EN: AArch64 prologue [sub sp, sp, #0x1a0; str d10, [sp, #0x140]; stp d9, d8, [sp, #0x148]; str x28, [sp, #0x158]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; str d10, [sp, #0x140]; stp d9, d8, [sp, #0x148]; str x28, [sp, #0x158]]
uint64_t fde_sub_0494e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00A3EAULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0494E8ULL;
}

// FDE #0208 | PC: 0x049680..0x0496f0 (112 B) | Symbol: sub_049680
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_049680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049680ULL;
}

// FDE #0209 | PC: 0x0496f0..0x0496f8 (8 B) | Symbol: sub_0496f0
// EN: AArch64 prologue [mov w3, #3; b #0x93340] | VI: Khởi đầu hàm AArch64 [mov w3, #3; b #0x93340]
uint64_t fde_sub_0496f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14012713ULL) << 32) | 0x52800063ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496F0ULL;
}

// FDE #0210 | PC: 0x0496f8..0x0497b4 (188 B) | Symbol: sub_0496f8
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_0496f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90263F9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496F8ULL;
}

// FDE #0211 | PC: 0x0497b4..0x0497ec (56 B) | Symbol: sub_0497b4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; stp xzr, xzr, [x0]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; stp xzr, xzr, [x0]]
uint64_t fde_sub_0497b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497B4ULL;
}

// FDE #0212 | PC: 0x0497ec..0x049848 (92 B) | Symbol: sub_0497ec
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92f04; bl #0x49848] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92f04; bl #0x49848]
uint64_t fde_sub_0497ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497ECULL;
}

// FDE #0213 | PC: 0x049848..0x049864 (28 B) | Symbol: sub_049848
// EN: AArch64 prologue [ldrb w8, [x0]; tbnz w8, #0, #0x4985c; add x0, x0, #1; lsr x1, x8, #1] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0]; tbnz w8, #0, #0x4985c; add x0, x0, #1; lsr x1, x8, #1]
uint64_t fde_sub_049848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000088ULL) << 32) | 0x39400008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049848ULL;
}

// FDE #0214 | PC: 0x049864..0x049870 (12 B) | Symbol: sub_049864
// EN: AArch64 prologue [cbz x2, #0x4986c; b #0x93450; b #0x8d6a0] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x4986c; b #0x93450; b #0x8d6a0]
uint64_t fde_sub_049864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140126FAULL) << 32) | 0xB4000042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049864ULL;
}

// FDE #0215 | PC: 0x049870..0x049898 (40 B) | Symbol: sub_049870
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; cbz x8, #0x49890; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; cbz x8, #0x49890; mov x19, x0]
uint64_t fde_sub_049870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049870ULL;
}

// FDE #0216 | PC: 0x049898..0x0498a0 (8 B) | Symbol: sub_049898
// EN: AArch64 prologue [ldr x1, [x0]; b #0x498a0] | VI: Khởi đầu hàm AArch64 [ldr x1, [x0]; b #0x498a0]
uint64_t fde_sub_049898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xF9400001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049898ULL;
}

// FDE #0217 | PC: 0x0498a0..0x0498d0 (48 B) | Symbol: sub_0498a0
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454]
uint64_t fde_sub_0498a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0498A0ULL;
}

// FDE #0218 | PC: 0x0498d0..0x049920 (80 B) | Symbol: sub_0498d0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldrb w8, [x0]; tbnz w8, #0, #0x498e8; add x19, x0, #1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldrb w8, [x0]; tbnz w8, #0, #0x498e8; add x19, x0, #1]
uint64_t fde_sub_0498d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400008ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0498D0ULL;
}

// FDE #0219 | PC: 0x049920..0x049950 (48 B) | Symbol: sub_049920
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x8f6c4; b.lo #0x4994c; ldr x10, [x1, #0x10]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x8f6c4; b.lo #0x4994c; ldr x10, [x1, #0x10]]
uint64_t fde_sub_049920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011768ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049920ULL;
}

// FDE #0220 | PC: 0x049950..0x0499f0 (160 B) | Symbol: sub_049950
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_049950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049950ULL;
}

// FDE #0221 | PC: 0x0499f0..0x049e30 (1088 B) | Symbol: sub_0499f0
// EN: AArch64 prologue [mov x2, x30; bl #0x913b8; mov x30, x2; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x913b8; mov x30, x2; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_0499f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011E71ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0440ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0499F0ULL;
}

// FDE #0222 | PC: 0x049e30..0x049ef0 (192 B) | Symbol: sub_049e30
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_049e30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049E30ULL;
}

// FDE #0223 | PC: 0x049ef0..0x049f64 (116 B) | Symbol: sub_049ef0
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_049ef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049EF0ULL;
}

// FDE #0224 | PC: 0x049f64..0x04a01c (184 B) | Symbol: sub_049f64
// EN: AArch64 prologue [mov x5, x30; bl #0x90b54; mov x30, x5; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x90b54; mov x30, x5; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_049f64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011AFBULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049F64ULL;
}

// FDE #0225 | PC: 0x04a01c..0x04a17c (352 B) | Symbol: sub_04a01c
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_04a01c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90263F9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A01CULL;
}

// FDE #0226 | PC: 0x04a17c..0x04a1ac (48 B) | Symbol: sub_04a17c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x8, #-0x5555555555555556; movk x8, #0xaaa, lsl #48; cmp x1, x8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x8, #-0x5555555555555556; movk x8, #0xaaa, lsl #48; cmp x1, x8]
uint64_t fde_sub_04a17c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB201F3E8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A17CULL;
}

// FDE #0227 | PC: 0x04a1ac..0x04a1dc (48 B) | Symbol: sub_04a1ac
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x4a1c8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x4a1c8]
uint64_t fde_sub_04a1ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A1ACULL;
}

// FDE #0228 | PC: 0x04a1dc..0x04a234 (88 B) | Symbol: sub_04a1dc
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]]
uint64_t fde_sub_04a1dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A1DCULL;
}

// FDE #0229 | PC: 0x04a234..0x04a270 (60 B) | Symbol: sub_04a234
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8]
uint64_t fde_sub_04a234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A234ULL;
}

// FDE #0230 | PC: 0x04a270..0x04a290 (32 B) | Symbol: sub_04a270
// EN: AArch64 prologue [mov x8, #-0x5555555555555556; movk x8, #0xaaab; movk x8, #0xaaa, lsl #48; cmp x0, x8] | VI: Khởi đầu hàm AArch64 [mov x8, #-0x5555555555555556; movk x8, #0xaaab; movk x8, #0xaaa, lsl #48; cmp x0, x8]
uint64_t fde_sub_04a270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF2955568ULL) << 32) | 0xB201F3E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A270ULL;
}

// FDE #0231 | PC: 0x04a290..0x04a2a8 (24 B) | Symbol: sub_04a290
// EN: AArch64 prologue [cbz x1, #0x4a2a4; mov x8, x1; and w1, w2, #0xff; mov x2, x8] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x4a2a4; mov x8, x1; and w1, w2, #0xff; mov x2, x8]
uint64_t fde_sub_04a290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E8ULL) << 32) | 0xB40000A1ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A290ULL;
}

// FDE #0232 | PC: 0x04a2a8..0x04a380 (216 B) | Symbol: sub_04a2a8
// EN: AArch64 prologue [str x28, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub sp, sp, #0x540] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub sp, sp, #0x540]
uint64_t fde_sub_04a2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FFCULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A2A8ULL;
}

// FDE #0233 | PC: 0x04a380..0x04a3dc (92 B) | Symbol: sub_04a380
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x1, x0; mov x19, x0; ldr w0, [x1, #4]!] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x1, x0; mov x19, x0; ldr w0, [x1, #4]!]
uint64_t fde_sub_04a380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E1ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A380ULL;
}

// FDE #0234 | PC: 0x04a3dc..0x04a5c4 (488 B) | Symbol: _ZN4lynx6animax20ScopedGLResetRestoreC1Ej
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov w8, w1; mov w10, #-0x80c8; str w1, [x0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov w8, w1; mov w10, #-0x80c8; str w1, [x0]]
uint64_t fde_sub_04a3dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0103E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A3DCULL;
}

// FDE #0235 | PC: 0x04a5c4..0x04a8a0 (732 B) | Symbol: _ZN4lynx6animax20ScopedGLResetRestoreD1Ev
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x20, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x20, tpidr_el0]
uint64_t fde_sub_04a5c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91353FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x02DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A5C4ULL;
}

// FDE #0236 | PC: 0x04a8a0..0x04a8dc (60 B) | Symbol: _ZN4lynx6animax10LogMessageC2EPKciNS0_14AnimaXLogLevelE
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; str x1, [x0]] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; str x1, [x0]]
uint64_t fde_sub_04a8a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A8A0ULL;
}

// FDE #0237 | PC: 0x04a8dc..0x04a950 (116 B) | Symbol: sub_04a8dc
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; add x8, x8, #0x978] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x98000; add x8, x8, #0x978]
uint64_t fde_sub_04a8dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A8DCULL;
}

// FDE #0238 | PC: 0x04a950..0x04aa0c (188 B) | Symbol: _ZN4lynx6animax10LogMessage4InitEPKci
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_04a950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A950ULL;
}

// FDE #0239 | PC: 0x04aa0c..0x04aa5c (80 B) | Symbol: sub_04aa0c
// EN: AArch64 prologue [ldr w8, [x1, #0x60]; tbnz w8, #4, #0x4aa1c; tbnz w8, #3, #0x4aa44; b #0x926b8] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x60]; tbnz w8, #4, #0x4aa1c; tbnz w8, #3, #0x4aa44; b #0x926b8]
uint64_t fde_sub_04aa0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37200068ULL) << 32) | 0xB9406028ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AA0CULL;
}

// FDE #0240 | PC: 0x04aa5c..0x04aacc (112 B) | Symbol: sub_04aa5c
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub x23, x2, x1] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub x23, x2, x1]
uint64_t fde_sub_04aa5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AA5CULL;
}

// FDE #0241 | PC: 0x04aacc..0x04aaf4 (40 B) | Symbol: sub_04aacc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x8f0; bl #0x902b4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x8f0; bl #0x902b4]
uint64_t fde_sub_04aacc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000268ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AACCULL;
}

// FDE #0242 | PC: 0x04aaf4..0x04aaf8 (4 B) | Symbol: sub_04aaf4
// EN: AArch64 prologue [b #0x926b8] | VI: Khởi đầu hàm AArch64 [b #0x926b8]
uint64_t fde_sub_04aaf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0x14011EF1ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AAF4ULL;
}

// FDE #0243 | PC: 0x04aaf8..0x04ab18 (32 B) | Symbol: sub_04aaf8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x870; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x870; mov x19, x0]
uint64_t fde_sub_04aaf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000268ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AAF8ULL;
}

// FDE #0244 | PC: 0x04ab18..0x04ab30 (24 B) | Symbol: sub_04ab18
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4aaf8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4aaf8; mov x0, x19]
uint64_t fde_sub_04ab18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AB18ULL;
}

// FDE #0245 | PC: 0x04ab30..0x04ac20 (240 B) | Symbol: sub_04ab30
// EN: AArch64 prologue [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x4ab48] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x4ab48]
uint64_t fde_sub_04ab30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401809ULL) << 32) | 0xF9402C08ULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AB30ULL;
}

// FDE #0246 | PC: 0x04ac20..0x04ac34 (20 B) | Symbol: sub_04ac20
// EN: AArch64 prologue [ldr x8, [x0]; mov x1, x2; mov w2, wzr; ldr x4, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov x1, x2; mov w2, wzr; ldr x4, [x8, #0x20]]
uint64_t fde_sub_04ac20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E1ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AC20ULL;
}

// FDE #0247 | PC: 0x04ac34..0x04ac38 (4 B) | Symbol: sub_04ac34
// EN: AArch64 prologue [b #0x8e158] | VI: Khởi đầu hàm AArch64 [b #0x8e158]
uint64_t fde_sub_04ac34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81C0FF8ULL) << 32) | 0x14010D49ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AC34ULL;
}

// FDE #0248 | PC: 0x04ac38..0x04accc (148 B) | Symbol: sub_04ac38
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_04ac38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AC38ULL;
}

// FDE #0249 | PC: 0x04accc..0x04ad18 (76 B) | Symbol: sub_04accc
// EN: AArch64 prologue [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x4ace4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x4ace4]
uint64_t fde_sub_04accc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401809ULL) << 32) | 0xF9402C08ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ACCCULL;
}

// FDE #0250 | PC: 0x04ad18..0x04ad44 (44 B) | Symbol: sub_04ad18
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; mov x19, x0; bl #0x8f50c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; mov x19, x0; bl #0x8f50c]
uint64_t fde_sub_04ad18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AD18ULL;
}

// FDE #0251 | PC: 0x04ad44..0x04adb0 (108 B) | Symbol: sub_04ad44
// EN: AArch64 prologue [ldr x9, [x0, #0x58]; ldr x10, [x0, #0x30]; mov x8, x0; mov w0, w1] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x58]; ldr x10, [x0, #0x30]; mov x8, x0; mov w0, w1]
uint64_t fde_sub_04ad44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940180AULL) << 32) | 0xF9402C09ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AD44ULL;
}

// FDE #0252 | PC: 0x04adb0..0x04ae44 (148 B) | Symbol: sub_04adb0
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e108] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e108]
uint64_t fde_sub_04adb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ADB0ULL;
}

// FDE #0253 | PC: 0x04ae44..0x04af8c (328 B) | Symbol: sub_04ae44
// EN: AArch64 prologue [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_04ae44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011382ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AE44ULL;
}

// FDE #0254 | PC: 0x04af8c..0x04b010 (132 B) | Symbol: sub_04af8c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0]; mov x20, x0]
uint64_t fde_sub_04af8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AF8CULL;
}

// FDE #0255 | PC: 0x04b010..0x04b0e8 (216 B) | Symbol: sub_04b010
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0]]
uint64_t fde_sub_04b010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B010ULL;
}

// FDE #0256 | PC: 0x04b0e8..0x04b11c (52 B) | Symbol: sub_04b0e8
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x30]; cmp x9, x8; b.eq #0x4b10c; add x10, x9, #1] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x30]; cmp x9, x8; b.eq #0x4b10c; add x10, x9, #1]
uint64_t fde_sub_04b0e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB08013FULL) << 32) | 0xA9432009ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B0E8ULL;
}

// FDE #0257 | PC: 0x04b11c..0x04b1f0 (212 B) | Symbol: sub_04b11c
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_04b11c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B11CULL;
}

// FDE #0258 | PC: 0x04b1f0..0x04b200 (16 B) | Symbol: sub_04b1f0
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0x8f0; str x8, [x0], #8; b #0x93390] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0x8f0; str x8, [x0], #8; b #0x93390]
uint64_t fde_sub_04b1f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9123C108ULL) << 32) | 0xB0000268ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B1F0ULL;
}

// FDE #0259 | PC: 0x04b200..0x04b218 (24 B) | Symbol: sub_04b200
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4b1f0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4b1f0; mov x0, x19]
uint64_t fde_sub_04b200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B200ULL;
}

// FDE #0260 | PC: 0x04b218..0x04b21c (4 B) | Symbol: sub_04b218
// EN: AArch64 prologue [b #0x92218] | VI: Khởi đầu hàm AArch64 [b #0x92218]
uint64_t fde_sub_04b218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140110BEULL) << 32) | 0x14011C00ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B218ULL;
}

// FDE #0261 | PC: 0x04b21c..0x04b220 (4 B) | Symbol: sub_04b21c
// EN: AArch64 prologue [b #0x8f514] | VI: Khởi đầu hàm AArch64 [b #0x8f514]
uint64_t fde_sub_04b21c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0x140110BEULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B21CULL;
}

// FDE #0262 | PC: 0x04b220..0x04b240 (32 B) | Symbol: sub_04b220
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93660; mov w8, #-1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93660; mov w8, #-1]
uint64_t fde_sub_04b220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B220ULL;
}

// FDE #0263 | PC: 0x04b240..0x04b248 (8 B) | Symbol: sub_04b240
// EN: AArch64 prologue [add x0, x0, #8; b #0x93670] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0x93670]
uint64_t fde_sub_04b240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1401210BULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B240ULL;
}

// FDE #0264 | PC: 0x04b248..0x04b264 (28 B) | Symbol: sub_04b248
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #8; bl #0x93670] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #8; bl #0x93670]
uint64_t fde_sub_04b248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B248ULL;
}

// FDE #0265 | PC: 0x04b264..0x04b278 (20 B) | Symbol: sub_04b264
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #8]
uint64_t fde_sub_04b264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B264ULL;
}

// FDE #0266 | PC: 0x04b278..0x04b288 (16 B) | Symbol: sub_04b278
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x4b248] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x4b248]
uint64_t fde_sub_04b278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B278ULL;
}

// FDE #0267 | PC: 0x04b288..0x04b2b0 (40 B) | Symbol: sub_04b288
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x828; bl #0x902b4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0x828; bl #0x902b4]
uint64_t fde_sub_04b288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000268ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B288ULL;
}

// FDE #0268 | PC: 0x04b2b0..0x04b2c8 (24 B) | Symbol: sub_04b2b0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4b288; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4b288; mov x0, x19]
uint64_t fde_sub_04b2b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B2B0ULL;
}

// FDE #0269 | PC: 0x04b2c8..0x04b2d8 (16 B) | Symbol: sub_04b2c8
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x4b288] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x4b288]
uint64_t fde_sub_04b2c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B2C8ULL;
}

// FDE #0270 | PC: 0x04b2d8..0x04b2e8 (16 B) | Symbol: sub_04b2d8
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x4b2b0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x4b2b0]
uint64_t fde_sub_04b2d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B2D8ULL;
}

// FDE #0271 | PC: 0x04b2e8..0x04b3d0 (232 B) | Symbol: _ZN4lynx6animax10LogMessageD1Ev
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_04b2e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B2E8ULL;
}

// FDE #0272 | PC: 0x04b3d0..0x04b4d8 (264 B) | Symbol: sub_04b3d0
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x24, [sp, #0x80]; stp x23, x22, [sp, #0x90]; stp x21, x20, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x24, [sp, #0x80]; stp x23, x22, [sp, #0x90]; stp x21, x20, [sp, #0xa0]]
uint64_t fde_sub_04b3d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043F8ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B3D0ULL;
}

// FDE #0273 | PC: 0x04b4d8..0x04b524 (76 B) | Symbol: sub_04b4d8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]; bl #0x902ec] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]; bl #0x902ec]
uint64_t fde_sub_04b4d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF4ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B4D8ULL;
}

// FDE #0274 | PC: 0x04b524..0x04b558 (52 B) | Symbol: sub_04b524
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ef10; cbz x20, #0x4b540] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ef10; cbz x20, #0x4b540]
uint64_t fde_sub_04b524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B524ULL;
}

// FDE #0275 | PC: 0x04b558..0x04b758 (512 B) | Symbol: sub_04b558
// EN: AArch64 prologue [str x28, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_04b558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FFCULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B558ULL;
}

// FDE #0276 | PC: 0x04b758..0x04b780 (40 B) | Symbol: sub_04b758
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8fc78; cbz x0, #0x4b778; bl #0x93420] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8fc78; cbz x0, #0x4b778; bl #0x93420]
uint64_t fde_sub_04b758(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011147ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B758ULL;
}

// FDE #0277 | PC: 0x04b780..0x04b798 (24 B) | Symbol: sub_04b780
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4b798; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4b798; ldr x0, [x19, #8]]
uint64_t fde_sub_04b780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940108E6ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B780ULL;
}

// FDE #0278 | PC: 0x04b798..0x04b7b4 (28 B) | Symbol: sub_04b798
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; cbz x0, #0x4b7a8; bl #0x8d3c4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; cbz x0, #0x4b7a8; bl #0x8d3c4]
uint64_t fde_sub_04b798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940108F4ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B798ULL;
}

// FDE #0279 | PC: 0x04b7b4..0x04b7c4 (16 B) | Symbol: sub_04b7b4
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0x9c0; str x8, [x0], #8; b #0x4b780] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0x9c0; str x8, [x0], #8; b #0x4b780]
uint64_t fde_sub_04b7b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91270108ULL) << 32) | 0xB0000268ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B7B4ULL;
}

// FDE #0280 | PC: 0x04b7c4..0x04b7dc (24 B) | Symbol: sub_04b7c4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4b7b4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4b7b4; mov x0, x19]
uint64_t fde_sub_04b7c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B7C4ULL;
}

// FDE #0281 | PC: 0x04b7dc..0x04b7ec (16 B) | Symbol: sub_04b7dc
// EN: AArch64 prologue [ldr x8, [x0, #8]; add x1, x0, #0x18; mov x0, x8; b #0x4b558] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; add x1, x0, #0x18; mov x0, x8; b #0x4b558]
uint64_t fde_sub_04b7dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B7DCULL;
}

// FDE #0282 | PC: 0x04b7ec..0x04b7f4 (8 B) | Symbol: sub_04b7ec
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x931b0] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x931b0]
uint64_t fde_sub_04b7ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011E70ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B7ECULL;
}

// FDE #0283 | PC: 0x04b7f4..0x04b840 (76 B) | Symbol: sub_04b7f4
// EN: AArch64 prologue [mov x2, x30; bl #0x8d828; mov x30, x2; cbz x10, #0x4b83c] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d828; mov x30, x2; cbz x10, #0x4b83c]
uint64_t fde_sub_04b7f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401080CULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B7F4ULL;
}

// FDE #0284 | PC: 0x04b840..0x04ba18 (472 B) | Symbol: sub_04b840
// EN: AArch64 prologue [stp x28, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub sp, sp, #0x6a0] | VI: Khởi đầu hàm AArch64 [stp x28, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub sp, sp, #0x6a0]
uint64_t fde_sub_04b840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BFCULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B840ULL;
}

// FDE #0285 | PC: 0x04ba18..0x04ba60 (72 B) | Symbol: sub_04ba18
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1]; bl #0x8e7a0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1]; bl #0x8e7a0]
uint64_t fde_sub_04ba18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BA18ULL;
}

// FDE #0286 | PC: 0x04ba60..0x04ba78 (24 B) | Symbol: sub_04ba60
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4ba78; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4ba78; ldr x0, [x19, #8]]
uint64_t fde_sub_04ba60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401082EULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BA60ULL;
}

// FDE #0287 | PC: 0x04ba78..0x04baa0 (40 B) | Symbol: sub_04ba78
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x108]; cbz x0, #0x4ba8c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x108]; cbz x0, #0x4ba8c]
uint64_t fde_sub_04ba78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BA78ULL;
}

// FDE #0288 | PC: 0x04baa0..0x04bab0 (16 B) | Symbol: sub_04baa0
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0x9e8; str x8, [x0], #8; b #0x4ba60] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0x9e8; str x8, [x0], #8; b #0x4ba60]
uint64_t fde_sub_04baa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9127A108ULL) << 32) | 0xB0000268ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BAA0ULL;
}

// FDE #0289 | PC: 0x04bab0..0x04bac8 (24 B) | Symbol: sub_04bab0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4baa0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4baa0; mov x0, x19]
uint64_t fde_sub_04bab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BAB0ULL;
}

// FDE #0290 | PC: 0x04bac8..0x04bad8 (16 B) | Symbol: sub_04bac8
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x4b840] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x4b840]
uint64_t fde_sub_04bac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940106E2ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BAC8ULL;
}

// FDE #0291 | PC: 0x04bad8..0x04be8c (948 B) | Symbol: sub_04bad8
// EN: AArch64 prologue [sub sp, sp, #0x1b0; str d8, [sp, #0x140]; stp x28, x27, [sp, #0x150]; stp x26, x25, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; str d8, [sp, #0x140]; stp x28, x27, [sp, #0x150]; stp x26, x25, [sp, #0x160]]
uint64_t fde_sub_04bad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00A3E8ULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x03B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BAD8ULL;
}

// FDE #0292 | PC: 0x04be8c..0x04becc (64 B) | Symbol: sub_04be8c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w2, #0xd0; bl #0x8e128] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w2, #0xd0; bl #0x8e128]
uint64_t fde_sub_04be8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BE8CULL;
}

// FDE #0293 | PC: 0x04becc..0x04bee4 (24 B) | Symbol: sub_04becc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4bee4; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4bee4; ldr x0, [x19, #8]]
uint64_t fde_sub_04becc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010713ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BECCULL;
}

// FDE #0294 | PC: 0x04bee4..0x04bf04 (32 B) | Symbol: sub_04bee4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x1c8]; cbz x0, #0x4bef8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x1c8]; cbz x0, #0x4bef8]
uint64_t fde_sub_04bee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BEE4ULL;
}

// FDE #0295 | PC: 0x04bf04..0x04bf14 (16 B) | Symbol: sub_04bf04
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0xa10; str x8, [x0], #8; b #0x4becc] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0xa10; str x8, [x0], #8; b #0x4becc]
uint64_t fde_sub_04bf04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91284108ULL) << 32) | 0xB0000268ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BF04ULL;
}

// FDE #0296 | PC: 0x04bf14..0x04bf2c (24 B) | Symbol: sub_04bf14
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4bf04; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4bf04; mov x0, x19]
uint64_t fde_sub_04bf14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BF14ULL;
}

// FDE #0297 | PC: 0x04bf2c..0x04bf3c (16 B) | Symbol: sub_04bf2c
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x4bad8] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x4bad8]
uint64_t fde_sub_04bf2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940105C9ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BF2CULL;
}

// FDE #0298 | PC: 0x04bf3c..0x04c158 (540 B) | Symbol: sub_04bf3c
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x27, x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x27, x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]]
uint64_t fde_sub_04bf3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x021CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BF3CULL;
}

// FDE #0299 | PC: 0x04c158..0x04c4d4 (892 B) | Symbol: sub_04c158
// EN: AArch64 prologue [str x28, [sp, #-0x60]!; mov x1, x30; bl #0x91e38; mov x30, x1] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x60]!; mov x1, x30; bl #0x91e38; mov x30, x1]
uint64_t fde_sub_04c158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E1ULL) << 32) | 0xF81A0FFCULL;
    const uint64_t kPcRange = 0x037CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C158ULL;
}

// FDE #0300 | PC: 0x04c4d4..0x04c568 (148 B) | Symbol: sub_04c4d4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldrb w9, [x0]; ldr x11, [x0, #8]; ldrb w10, [x1]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldrb w9, [x0]; ldr x11, [x0, #8]; ldrb w10, [x1]]
uint64_t fde_sub_04c4d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C4D4ULL;
}

// FDE #0301 | PC: 0x04c568..0x04c5ec (132 B) | Symbol: sub_04c568
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91c40; b.ne #0x4c580] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91c40; b.ne #0x4c580]
uint64_t fde_sub_04c568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C568ULL;
}

// FDE #0302 | PC: 0x04c5ec..0x04c61c (48 B) | Symbol: sub_04c5ec
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x4c614; ldrb w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x4c614; ldrb w8, [x0, #0x10]]
uint64_t fde_sub_04c5ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010680ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C5ECULL;
}

// FDE #0303 | PC: 0x04c61c..0x04c700 (228 B) | Symbol: sub_04c61c
// EN: AArch64 prologue [mov x2, x30; bl #0x8d63c; mov x30, x2; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d63c; mov x30, x2; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_04c61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010407ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C61CULL;
}

// FDE #0304 | PC: 0x04c700..0x04c718 (24 B) | Symbol: sub_04c700
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0]; str x1, [x8]; cbz x0, #0x4c714] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0]; str x1, [x8]; cbz x0, #0x4c714]
uint64_t fde_sub_04c700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C700ULL;
}

// FDE #0305 | PC: 0x04c718..0x04c720 (8 B) | Symbol: sub_04c718
// EN: AArch64 prologue [mov w0, #0x30; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x30; b #0x93320]
uint64_t fde_sub_04c718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14011B01ULL) << 32) | 0x52800600ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C718ULL;
}

// FDE #0306 | PC: 0x04c720..0x04c750 (48 B) | Symbol: sub_04c720
// EN: AArch64 prologue [mov x9, #0x2d69; movk x9, #0xeb38, lsl #16; movk x9, #0xea08, lsl #32; eor x8, x1, x0] | VI: Khởi đầu hàm AArch64 [mov x9, #0x2d69; movk x9, #0xeb38, lsl #16; movk x9, #0xea08, lsl #32; eor x8, x1, x0]
uint64_t fde_sub_04c720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF2BD6709ULL) << 32) | 0xD285AD29ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C720ULL;
}

// FDE #0307 | PC: 0x04c750..0x04c784 (52 B) | Symbol: sub_04c750
// EN: AArch64 prologue [ldp x8, x11, [x0]; ldp x9, x10, [x0, #0x10]; add x8, x8, x1; add x9, x9, x11] | VI: Khởi đầu hàm AArch64 [ldp x8, x11, [x0]; ldp x9, x10, [x0, #0x10]; add x8, x8, x1; add x9, x9, x11]
uint64_t fde_sub_04c750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9412809ULL) << 32) | 0xA9402C08ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C750ULL;
}

// FDE #0308 | PC: 0x04c784..0x04c7e0 (92 B) | Symbol: sub_04c784
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x98000] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x98000]
uint64_t fde_sub_04c784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C784ULL;
}

// FDE #0309 | PC: 0x04c7e0..0x04c7f8 (24 B) | Symbol: sub_04c7e0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8d530; bl #0x44830; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8d530; bl #0x44830; mov x0, x19]
uint64_t fde_sub_04c7e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010353ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C7E0ULL;
}

// FDE #0310 | PC: 0x04c7f8..0x04c82c (52 B) | Symbol: sub_04c7f8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; adrp x8, #0x98000; add x8, x8, #0xa38] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; adrp x8, #0x98000; add x8, x8, #0xa38]
uint64_t fde_sub_04c7f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401112EULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C7F8ULL;
}

// FDE #0311 | PC: 0x04c82c..0x04c844 (24 B) | Symbol: sub_04c82c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4c7f8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4c7f8; mov x0, x19]
uint64_t fde_sub_04c82c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C82CULL;
}

// FDE #0312 | PC: 0x04c844..0x04c84c (8 B) | Symbol: _ZN4lynx6animax18PlayerEventTrackerC1Ev
// EN: AArch64 prologue [str xzr, [x0]; b #0x93690] | VI: Khởi đầu hàm AArch64 [str xzr, [x0]; b #0x93690]
uint64_t fde_sub_04c844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14011B92ULL) << 32) | 0xF900001FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C844ULL;
}

// FDE #0313 | PC: 0x04c84c..0x04c868 (28 B) | Symbol: _ZN4lynx6animax18PlayerEventTracker5ResetEv
// EN: AArch64 prologue [mov x8, xzr; cmp x8, #8; b.eq #0x4c864; strb wzr, [x0, x8]] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; cmp x8, #8; b.eq #0x4c864; strb wzr, [x0, x8]]
uint64_t fde_sub_04c84c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100211FULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C84CULL;
}

// FDE #0314 | PC: 0x04c868..0x04c874 (12 B) | Symbol: _ZN4lynx6animax18PlayerEventTracker9MarkEventENS1_18AnimationEventTypeE
// EN: AArch64 prologue [mov w8, #1; strb w8, [x0, w1, sxtw]; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #1; strb w8, [x0, w1, sxtw]; ret]
uint64_t fde_sub_04c868(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3821C808ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C868ULL;
}

// FDE #0315 | PC: 0x04c874..0x04c87c (8 B) | Symbol: _ZN4lynx6animax18PlayerEventTracker13GetEventValueENS1_18AnimationEventTypeE
// EN: AArch64 prologue [ldrb w0, [x0, w1, sxtw]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, w1, sxtw]; ret]
uint64_t fde_sub_04c874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3861C800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C874ULL;
}

// FDE #0316 | PC: 0x04c87c..0x04c9c8 (332 B) | Symbol: _ZN4lynx6animax18PlayerEventTracker13GetEventNamesEv
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x21, x20, [sp, #0xd0]; stp x19, x30, [sp, #0xe0]; mrs x8, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x21, x20, [sp, #0xd0]; stp x19, x30, [sp, #0xe0]; mrs x8, tpidr_el0]
uint64_t fde_sub_04c87c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D53F5ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C87CULL;
}

// FDE #0317 | PC: 0x04c9c8..0x04c9e4 (28 B) | Symbol: sub_04c9c8
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92c3c; add x8, x20, w19, uxtb #3] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92c3c; add x8, x20, w19, uxtb #3]
uint64_t fde_sub_04c9c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C9C8ULL;
}

// FDE #0318 | PC: 0x04c9e4..0x04c9fc (24 B) | Symbol: sub_04c9e4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x936a0; mov w8, #0x3e8; sdiv x0, x0, x8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x936a0; mov w8, #0x3e8; sdiv x0, x0, x8]
uint64_t fde_sub_04c9e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011B2EULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C9E4ULL;
}

// FDE #0319 | PC: 0x04c9fc..0x04ca14 (24 B) | Symbol: sub_04c9fc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4c9e4; stp x0, xzr, [x19, #0xf0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4c9e4; stp x0, xzr, [x19, #0xf0]]
uint64_t fde_sub_04c9fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C9FCULL;
}

// FDE #0320 | PC: 0x04ca14..0x04cba4 (400 B) | Symbol: sub_04ca14
// EN: AArch64 prologue [str d8, [sp, #-0x20]!; str x20, [sp, #8]; stp x19, x30, [sp, #0x10]; and w8, w1, #0xff] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x20]!; str x20, [sp, #8]; stp x19, x30, [sp, #0x10]; and w8, w1, #0xff]
uint64_t fde_sub_04ca14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007F4ULL) << 32) | 0xFC1E0FE8ULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CA14ULL;
}

// FDE #0321 | PC: 0x04cba4..0x04cbbc (24 B) | Symbol: sub_04cba4
// EN: AArch64 prologue [ldr x8, [x0, #0x120]; adrp x9, #0x98000; add x9, x9, #0xa58; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x120]; adrp x9, #0x98000; add x9, x9, #0xa58; str x9, [x0]]
uint64_t fde_sub_04cba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000269ULL) << 32) | 0xF9409008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CBA4ULL;
}

// FDE #0322 | PC: 0x04cbbc..0x04cbd4 (24 B) | Symbol: sub_04cbbc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4cba4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4cba4; mov x0, x19]
uint64_t fde_sub_04cbbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CBBCULL;
}

// FDE #0323 | PC: 0x04cbd4..0x04cc14 (64 B) | Symbol: sub_04cbd4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x1]; mov x19, x0; cbz x8, #0x4cbf4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x1]; mov x19, x0; cbz x8, #0x4cbf4]
uint64_t fde_sub_04cbd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400028ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CBD4ULL;
}

// FDE #0324 | PC: 0x04cc14..0x04cc24 (16 B) | Symbol: sub_04cc14
// EN: AArch64 prologue [cbz x0, #0x4cc20; add x0, x0, #8; b #0x4cc24; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4cc20; add x0, x0, #8; b #0x4cc24; ret]
uint64_t fde_sub_04cc14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CC14ULL;
}

// FDE #0325 | PC: 0x04cc24..0x04cc4c (40 B) | Symbol: sub_04cc24
// EN: AArch64 prologue [ldxr w8, [x0]; subs w8, w8, #1; stlxr w9, w8, [x0]; cbnz w9, #0x4cc24] | VI: Khởi đầu hàm AArch64 [ldxr w8, [x0]; subs w8, w8, #1; stlxr w9, w8, [x0]; cbnz w9, #0x4cc24]
uint64_t fde_sub_04cc24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71000508ULL) << 32) | 0x885F7C08ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CC24ULL;
}

// FDE #0326 | PC: 0x04cc4c..0x04cd64 (280 B) | Symbol: sub_04cc4c
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_04cc4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CC4CULL;
}

// FDE #0327 | PC: 0x04cd64..0x04ceec (392 B) | Symbol: sub_04cd64
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_04cd64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900A3FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CD64ULL;
}

// FDE #0328 | PC: 0x04ceec..0x04cf70 (132 B) | Symbol: sub_04ceec
// EN: AArch64 prologue [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_04ceec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010F19ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CEECULL;
}

// FDE #0329 | PC: 0x04cf70..0x04d180 (528 B) | Symbol: sub_04cf70
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x23, x22, [sp, #0x90]; stp x21, x20, [sp, #0xa0]; stp x19, x30, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x23, x22, [sp, #0x90]; stp x21, x20, [sp, #0xa0]; stp x19, x30, [sp, #0xb0]]
uint64_t fde_sub_04cf70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9095BF7ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CF70ULL;
}

// FDE #0330 | PC: 0x04d180..0x04d2a4 (292 B) | Symbol: sub_04d180
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0xa0000] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0xa0000]
uint64_t fde_sub_04d180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D180ULL;
}

// FDE #0331 | PC: 0x04d2a4..0x04d2c4 (32 B) | Symbol: sub_04d2a4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; str x0, [sp, #8]; add x0, sp, #8; mov x1, #-1] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; str x0, [sp, #8]; add x0, sp, #8; mov x1, #-1]
uint64_t fde_sub_04d2a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D2A4ULL;
}

// FDE #0332 | PC: 0x04d2c4..0x04d2f8 (52 B) | Symbol: sub_04d2c4
// EN: AArch64 prologue [tbnz x1, #0x3f, #0x4d2f0; subs x1, x1, #1; b.lt #0x4d2f4; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [tbnz x1, #0x3f, #0x4d2f0; subs x1, x1, #1; b.lt #0x4d2f4; ldr x8, [x0]]
uint64_t fde_sub_04d2c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF1000421ULL) << 32) | 0xB7F80161ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D2C4ULL;
}

// FDE #0333 | PC: 0x04d2f8..0x04d33c (68 B) | Symbol: sub_04d2f8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; mov x0, x1] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; mov x0, x1]
uint64_t fde_sub_04d2f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D2F8ULL;
}

// FDE #0334 | PC: 0x04d33c..0x04d36c (48 B) | Symbol: sub_04d33c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w19, w2; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w19, w2; mov x20, x0]
uint64_t fde_sub_04d33c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D33CULL;
}

// FDE #0335 | PC: 0x04d36c..0x04d384 (24 B) | Symbol: sub_04d36c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x44830; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x44830; mov x0, x19]
uint64_t fde_sub_04d36c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401050FULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D36CULL;
}

// FDE #0336 | PC: 0x04d384..0x04d3ac (40 B) | Symbol: sub_04d384
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x4d3a4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x4d3a4; mov x0, x19]
uint64_t fde_sub_04d384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401031AULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D384ULL;
}

// FDE #0337 | PC: 0x04d3ac..0x04d3f8 (76 B) | Symbol: sub_04d3ac
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0xa0000; mov x21, x2] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0xa0000; mov x21, x2]
uint64_t fde_sub_04d3ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D3ACULL;
}

// FDE #0338 | PC: 0x04d3f8..0x04d480 (136 B) | Symbol: sub_04d3f8
// EN: AArch64 prologue [adrp x8, #0xa0000; add x8, x8, #0x7b8; ldp x9, x10, [x8]; sub x9, x9, x10] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xa0000; add x8, x8, #0x7b8; ldp x9, x10, [x8]; sub x9, x9, x10]
uint64_t fde_sub_04d3f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911EE108ULL) << 32) | 0xF0000288ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D3F8ULL;
}

// FDE #0339 | PC: 0x04d480..0x04d4c0 (64 B) | Symbol: sub_04d480
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8]
uint64_t fde_sub_04d480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D480ULL;
}

// FDE #0340 | PC: 0x04d4c0..0x04d5a0 (224 B) | Symbol: sub_04d4c0
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0]]
uint64_t fde_sub_04d4c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D4C0ULL;
}

// FDE #0341 | PC: 0x04d5a0..0x04d5ac (12 B) | Symbol: sub_04d5a0
// EN: AArch64 prologue [cbz x2, #0x4d5a8; b #0x93700; ret] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x4d5a8; b #0x93700; ret]
uint64_t fde_sub_04d5a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14011857ULL) << 32) | 0xB4000042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D5A0ULL;
}

// FDE #0342 | PC: 0x04d5ac..0x04d6cc (288 B) | Symbol: sub_04d5ac
// EN: AArch64 prologue [str x28, [sp, #-0x60]!; mov x8, x30; bl #0x91e38; mov x30, x8] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x60]!; mov x8, x30; bl #0x91e38; mov x30, x8]
uint64_t fde_sub_04d5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E8ULL) << 32) | 0xF81A0FFCULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D5ACULL;
}

// FDE #0343 | PC: 0x04d6cc..0x04d744 (120 B) | Symbol: sub_04d6cc
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x21, #0xa0000] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x21, #0xa0000]
uint64_t fde_sub_04d6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D6CCULL;
}

// FDE #0344 | PC: 0x04d744..0x04d764 (32 B) | Symbol: sub_04d744
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; str x0, [sp, #8]; add x0, sp, #8; mov w1, #1] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; str x0, [sp, #8]; add x0, sp, #8; mov w1, #1]
uint64_t fde_sub_04d744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D744ULL;
}

// FDE #0345 | PC: 0x04d764..0x04d7f0 (140 B) | Symbol: sub_04d764
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x0, #0x20]; cbz x8, #0x4d77c] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x0, #0x20]; cbz x8, #0x4d77c]
uint64_t fde_sub_04d764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D764ULL;
}

// FDE #0346 | PC: 0x04d7f0..0x04d844 (84 B) | Symbol: sub_04d7f0
// EN: AArch64 prologue [adrp x9, #0xa0000; add x9, x9, #0x7b8; ldp x8, x9, [x9]; mov w10, #0x28] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xa0000; add x9, x9, #0x7b8; ldp x8, x9, [x9]; mov w10, #0x28]
uint64_t fde_sub_04d7f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911EE129ULL) << 32) | 0xF0000289ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D7F0ULL;
}

// FDE #0347 | PC: 0x04d844..0x04d90c (200 B) | Symbol: sub_04d844
// EN: AArch64 prologue [sub sp, sp, #0x80; str x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]; bl #0x91df8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]; bl #0x91df8]
uint64_t fde_sub_04d844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F4ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D844ULL;
}

// FDE #0348 | PC: 0x04d90c..0x04d97c (112 B) | Symbol: sub_04d90c
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8dab0]
uint64_t fde_sub_04d90c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D90CULL;
}

// FDE #0349 | PC: 0x04d97c..0x04d994 (24 B) | Symbol: sub_04d97c
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0]; str xzr, [x8]; cbz x0, #0x4d990] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0]; str xzr, [x8]; cbz x0, #0x4d990]
uint64_t fde_sub_04d97c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D97CULL;
}

// FDE #0350 | PC: 0x04d994..0x04d9b4 (32 B) | Symbol: sub_04d994
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xad0; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xad0; bl #0x8daa4]
uint64_t fde_sub_04d994(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000248ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D994ULL;
}

// FDE #0351 | PC: 0x04d9b4..0x04d9cc (24 B) | Symbol: sub_04d9b4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4d994; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4d994; mov x0, x19]
uint64_t fde_sub_04d9b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D9B4ULL;
}

// FDE #0352 | PC: 0x04d9cc..0x04d9d4 (8 B) | Symbol: sub_04d9cc
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x4cc4c] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x4cc4c]
uint64_t fde_sub_04d9cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFC9FULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D9CCULL;
}

// FDE #0353 | PC: 0x04d9d4..0x04da9c (200 B) | Symbol: sub_04d9d4
// EN: AArch64 prologue [sub sp, sp, #0x80; str x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]; bl #0x91df8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]; bl #0x91df8]
uint64_t fde_sub_04d9d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F4ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D9D4ULL;
}

// FDE #0354 | PC: 0x04da9c..0x04db0c (112 B) | Symbol: sub_04da9c
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8dab0]
uint64_t fde_sub_04da9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DA9CULL;
}

// FDE #0355 | PC: 0x04db0c..0x04db54 (72 B) | Symbol: sub_04db0c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x140; ldarb w8, [x8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x140; ldarb w8, [x8]]
uint64_t fde_sub_04db0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000288ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DB0CULL;
}

// FDE #0356 | PC: 0x04db54..0x04dbc0 (108 B) | Symbol: sub_04db54
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; bl #0x8f760] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; bl #0x8f760]
uint64_t fde_sub_04db54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91353FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DB54ULL;
}

// FDE #0357 | PC: 0x04dbc0..0x04dc78 (184 B) | Symbol: sub_04dbc0
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x24, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x24, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_04dbc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91363FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DBC0ULL;
}

// FDE #0358 | PC: 0x04dc78..0x04de80 (520 B) | Symbol: _ZN4lynx6animax9ColorUtil13ParseHexColorERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0xa0; mov x1, x30; bl #0x8feb4; mov x30, x1] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; mov x1, x30; bl #0x8feb4; mov x30, x1]
uint64_t fde_sub_04dc78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E1ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DC78ULL;
}

// FDE #0359 | PC: 0x04de80..0x04de98 (24 B) | Symbol: sub_04de80
// EN: AArch64 prologue [ldrb w8, [x0]; tbnz w8, #0, #0x4de90; lsr x8, x8, #1; b #0x4de94] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0]; tbnz w8, #0, #0x4de90; lsr x8, x8, #1; b #0x4de94]
uint64_t fde_sub_04de80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000068ULL) << 32) | 0x39400008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DE80ULL;
}

// FDE #0360 | PC: 0x04de98..0x04df24 (140 B) | Symbol: sub_04de98
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0]]
uint64_t fde_sub_04de98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DE98ULL;
}

// FDE #0361 | PC: 0x04df24..0x04df90 (108 B) | Symbol: sub_04df24
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e108] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e108]
uint64_t fde_sub_04df24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DF24ULL;
}

// FDE #0362 | PC: 0x04df90..0x04dfec (92 B) | Symbol: sub_04df90
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; cmn x3, #0x10] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; cmn x3, #0x10]
uint64_t fde_sub_04df90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DF90ULL;
}

// FDE #0363 | PC: 0x04dfec..0x04e084 (152 B) | Symbol: sub_04dfec
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x92814] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x92814]
uint64_t fde_sub_04dfec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DFECULL;
}

// FDE #0364 | PC: 0x04e084..0x04e150 (204 B) | Symbol: sub_04e084
// EN: AArch64 prologue [sub sp, sp, #0x170; stp d9, d8, [sp, #0x130]; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp d9, d8, [sp, #0x130]; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_04e084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D1323E9ULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E084ULL;
}

// FDE #0365 | PC: 0x04e150..0x04e270 (288 B) | Symbol: sub_04e150
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_04e150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9135BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E150ULL;
}

// FDE #0366 | PC: 0x04e270..0x04e300 (144 B) | Symbol: sub_04e270
// EN: AArch64 prologue [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_04e270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010A38ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E270ULL;
}

// FDE #0367 | PC: 0x04e300..0x04e31c (28 B) | Symbol: sub_04e300
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x924d8; bl #0x4e31c] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x924d8; bl #0x4e31c]
uint64_t fde_sub_04e300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E300ULL;
}

// FDE #0368 | PC: 0x04e31c..0x04e340 (36 B) | Symbol: sub_04e31c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8eb14; mov x1, x19] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8eb14; mov x1, x19]
uint64_t fde_sub_04e31c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E31CULL;
}

// FDE #0369 | PC: 0x04e340..0x04e3f8 (184 B) | Symbol: sub_04e340
// EN: AArch64 prologue [sub sp, sp, #0x160; str d8, [sp, #0x130]; str x28, [sp, #0x138]; stp x21, x20, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str d8, [sp, #0x130]; str x28, [sp, #0x138]; stp x21, x20, [sp, #0x140]]
uint64_t fde_sub_04e340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD009BE8ULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E340ULL;
}

// FDE #0370 | PC: 0x04e3f8..0x04e424 (44 B) | Symbol: sub_04e3f8
// EN: AArch64 prologue [sdiv w8, w0, w1; eor w9, w1, w0; cmp w9, #0; mul w9, w8, w1] | VI: Khởi đầu hàm AArch64 [sdiv w8, w0, w1; eor w9, w1, w0; cmp w9, #0; mul w9, w8, w1]
uint64_t fde_sub_04e3f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4A000029ULL) << 32) | 0x1AC10C08ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E3F8ULL;
}

// FDE #0371 | PC: 0x04e424..0x04e53c (280 B) | Symbol: sub_04e424
// EN: AArch64 prologue [cbz x2, #0x4e538; ldrb w8, [x0, #9]; ldrb w9, [x0, #8]; ldrb w10, [x1, #9]] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x4e538; ldrb w8, [x0, #9]; ldrb w9, [x0, #8]; ldrb w10, [x1, #9]]
uint64_t fde_sub_04e424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402408ULL) << 32) | 0xB40008A2ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E424ULL;
}

// FDE #0372 | PC: 0x04e53c..0x04e5d0 (148 B) | Symbol: sub_04e53c
// EN: AArch64 prologue [lsr w8, w1, #0x18; adrp x9, #0x1b000; sub w8, w8, w0, lsr #24; and w10, w1, #0xff] | VI: Khởi đầu hàm AArch64 [lsr w8, w1, #0x18; adrp x9, #0x1b000; sub w8, w8, w0, lsr #24; and w10, w1, #0xff]
uint64_t fde_sub_04e53c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0FFFE69ULL) << 32) | 0x53187C28ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E53CULL;
}

// FDE #0373 | PC: 0x04e5d0..0x04e5fc (44 B) | Symbol: sub_04e5d0
// EN: AArch64 prologue [cmp x1, x3; b.hs #0x4e5dc; b #0x8d6a0; str x30, [sp, #-0x10]!] | VI: Khởi đầu hàm AArch64 [cmp x1, x3; b.hs #0x4e5dc; b #0x8d6a0; str x30, [sp, #-0x10]!]
uint64_t fde_sub_04e5d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000042ULL) << 32) | 0xEB03003FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E5D0ULL;
}

// FDE #0374 | PC: 0x04e5fc..0x04e684 (136 B) | Symbol: sub_04e5fc
// EN: AArch64 prologue [and w8, w0, #0xff; sub w9, w8, #1; cmp w9, #7; b.hi #0x4e638] | VI: Khởi đầu hàm AArch64 [and w8, w0, #0xff; sub w9, w8, #1; cmp w9, #7; b.hi #0x4e638]
uint64_t fde_sub_04e5fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000509ULL) << 32) | 0x12001C08ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E5FCULL;
}

// FDE #0375 | PC: 0x04e684..0x04e76c (232 B) | Symbol: sub_04e684
// EN: AArch64 prologue [sub sp, sp, #0x70; str x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]]
uint64_t fde_sub_04e684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E684ULL;
}

// FDE #0376 | PC: 0x04e76c..0x04e8dc (368 B) | Symbol: sub_04e76c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_04e76c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E76CULL;
}

// FDE #0377 | PC: 0x04e8dc..0x04e8fc (32 B) | Symbol: sub_04e8dc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xb28; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xb28; bl #0x8daa4]
uint64_t fde_sub_04e8dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000248ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E8DCULL;
}

// FDE #0378 | PC: 0x04e8fc..0x04e914 (24 B) | Symbol: sub_04e8fc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4e8dc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4e8dc; mov x0, x19]
uint64_t fde_sub_04e8fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E8FCULL;
}

// FDE #0379 | PC: 0x04e914..0x04e91c (8 B) | Symbol: sub_04e914
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x4e91c] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x4e91c]
uint64_t fde_sub_04e914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E914ULL;
}

// FDE #0380 | PC: 0x04e91c..0x04e944 (40 B) | Symbol: sub_04e91c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x4cc14] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x4cc14]
uint64_t fde_sub_04e91c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E91CULL;
}

// FDE #0381 | PC: 0x04e944..0x04e964 (32 B) | Symbol: sub_04e944
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xb98; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xb98; bl #0x8daa4]
uint64_t fde_sub_04e944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000248ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E944ULL;
}

// FDE #0382 | PC: 0x04e964..0x04e97c (24 B) | Symbol: sub_04e964
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4e944; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4e944; mov x0, x19]
uint64_t fde_sub_04e964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E964ULL;
}

// FDE #0383 | PC: 0x04e97c..0x04e980 (4 B) | Symbol: sub_04e97c
// EN: AArch64 prologue [b #0x8e284] | VI: Khởi đầu hàm AArch64 [b #0x8e284]
uint64_t fde_sub_04e97c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0x1400FE42ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E97CULL;
}

// FDE #0384 | PC: 0x04e980..0x04e9d8 (88 B) | Symbol: sub_04e980
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0xd8]; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0xd8]; adrp x8, #0x9c000]
uint64_t fde_sub_04e980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E980ULL;
}

// FDE #0385 | PC: 0x04e9d8..0x04ea00 (40 B) | Symbol: sub_04e9d8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x58; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x58; bl #0x46c54]
uint64_t fde_sub_04e9d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E9D8ULL;
}

// FDE #0386 | PC: 0x04ea00..0x04ea24 (36 B) | Symbol: sub_04ea00
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; bl #0x4ea24; bl #0x8f1f0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; bl #0x4ea24; bl #0x8f1f0]
uint64_t fde_sub_04ea00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400FC5AULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EA00ULL;
}

// FDE #0387 | PC: 0x04ea24..0x04ea54 (48 B) | Symbol: sub_04ea24
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cbz x19, #0x4ea4c] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cbz x19, #0x4ea4c]
uint64_t fde_sub_04ea24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EA24ULL;
}

// FDE #0388 | PC: 0x04ea54..0x04ea6c (24 B) | Symbol: sub_04ea54
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x18; bl #0x8ebec] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x18; bl #0x8ebec]
uint64_t fde_sub_04ea54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EA54ULL;
}

// FDE #0389 | PC: 0x04ea6c..0x04ea84 (24 B) | Symbol: sub_04ea6c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xb60; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xb60; str x9, [x0]]
uint64_t fde_sub_04ea6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000249ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EA6CULL;
}

// FDE #0390 | PC: 0x04ea84..0x04ea9c (24 B) | Symbol: sub_04ea84
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4ea6c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4ea6c; mov x0, x19]
uint64_t fde_sub_04ea84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EA84ULL;
}

// FDE #0391 | PC: 0x04ea9c..0x04eaa4 (8 B) | Symbol: sub_04ea9c
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0x92cf0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0x92cf0]
uint64_t fde_sub_04ea9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14011094ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EA9CULL;
}

// FDE #0392 | PC: 0x04eaa4..0x04eab4 (16 B) | Symbol: sub_04eaa4
// EN: AArch64 prologue [ldr x0, [x0, #8]; ldr x9, [x0]; ldr x1, [x9, #0x28]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; ldr x9, [x0]; ldr x1, [x9, #0x28]; br x1]
uint64_t fde_sub_04eaa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400009ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EAA4ULL;
}

// FDE #0393 | PC: 0x04eab4..0x04eac8 (20 B) | Symbol: sub_04eab4
// EN: AArch64 prologue [movi v0.2d, #0000000000000000; mov w9, #0x3f800000; stp q0, q0, [x8]; str w9, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [movi v0.2d, #0000000000000000; mov w9, #0x3f800000; stp q0, q0, [x8]; str w9, [x8, #0x20]]
uint64_t fde_sub_04eab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52A7F009ULL) << 32) | 0x6F00E400ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EAB4ULL;
}

// FDE #0394 | PC: 0x04eac8..0x04f8d4 (3596 B) | Symbol: sub_04eac8
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]]
uint64_t fde_sub_04eac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9106FFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0E0CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EAC8ULL;
}

// FDE #0395 | PC: 0x04f8d4..0x04f98c (184 B) | Symbol: sub_04f8d4
// EN: AArch64 prologue [sub sp, sp, #0xe0; str d8, [sp, #0xb0]; str x22, [sp, #0xb8]; stp x21, x20, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str d8, [sp, #0xb0]; str x22, [sp, #0xb8]; stp x21, x20, [sp, #0xc0]]
uint64_t fde_sub_04f8d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD005BE8ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F8D4ULL;
}

// FDE #0396 | PC: 0x04f98c..0x04fa3c (176 B) | Symbol: sub_04f98c
// EN: AArch64 prologue [sub sp, sp, #0xe0; str d8, [sp, #0xb0]; str x22, [sp, #0xb8]; stp x21, x20, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str d8, [sp, #0xb0]; str x22, [sp, #0xb8]; stp x21, x20, [sp, #0xc0]]
uint64_t fde_sub_04f98c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD005BE8ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F98CULL;
}

// FDE #0397 | PC: 0x04fa3c..0x04fa7c (64 B) | Symbol: sub_04fa3c
// EN: AArch64 prologue [sub sp, sp, #0x20; ldr q0, [x1]; str q0, [sp]; stp xzr, xzr, [x1]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; ldr q0, [x1]; str q0, [sp]; stp xzr, xzr, [x1]]
uint64_t fde_sub_04fa3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC00020ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FA3CULL;
}

// FDE #0398 | PC: 0x04fa7c..0x04fb48 (204 B) | Symbol: sub_04fa7c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614]
uint64_t fde_sub_04fa7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FA7CULL;
}

// FDE #0399 | PC: 0x04fb48..0x04fb7c (52 B) | Symbol: sub_04fb48
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x20, x21, [x0]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x20, x21, [x0]; mov x19, x0]
uint64_t fde_sub_04fb48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FB48ULL;
}

// FDE #0400 | PC: 0x04fb7c..0x04fb84 (8 B) | Symbol: sub_04fb7c
// EN: AArch64 prologue [add x0, x0, #0x28; b #0x4fb84] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x28; b #0x4fb84]
uint64_t fde_sub_04fb7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x9100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FB7CULL;
}

// FDE #0401 | PC: 0x04fb84..0x04fd44 (448 B) | Symbol: sub_04fb84
// EN: AArch64 prologue [sub sp, sp, #0x70; str x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]]
uint64_t fde_sub_04fb84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FB84ULL;
}

// FDE #0402 | PC: 0x04fd44..0x04fdc8 (132 B) | Symbol: sub_04fd44
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91c40; b.ne #0x4fd5c] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91c40; b.ne #0x4fd5c]
uint64_t fde_sub_04fd44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FD44ULL;
}

// FDE #0403 | PC: 0x04fdc8..0x04fe9c (212 B) | Symbol: sub_04fdc8
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cbz x1, #0x4fe20] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cbz x1, #0x4fe20]
uint64_t fde_sub_04fdc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FDC8ULL;
}

// FDE #0404 | PC: 0x04fe9c..0x04fea4 (8 B) | Symbol: sub_04fe9c
// EN: AArch64 prologue [add x0, x0, #0x28; b #0x4fea4] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x28; b #0x4fea4]
uint64_t fde_sub_04fe9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x9100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FE9CULL;
}

// FDE #0405 | PC: 0x04fea4..0x050078 (468 B) | Symbol: sub_04fea4
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_04fea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x01D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FEA4ULL;
}

// FDE #0406 | PC: 0x050078..0x0500c0 (72 B) | Symbol: sub_050078
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; tbz w2, #0, #0x50098; ldr x1, [x1, #0x10]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; tbz w2, #0, #0x50098; ldr x1, [x1, #0x10]]
uint64_t fde_sub_050078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050078ULL;
}

// FDE #0407 | PC: 0x0500c0..0x0500ec (44 B) | Symbol: sub_0500c0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; cbz x19, #0x500e4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; cbz x19, #0x500e4]
uint64_t fde_sub_0500c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0500C0ULL;
}

// FDE #0408 | PC: 0x0500ec..0x05018c (160 B) | Symbol: sub_0500ec
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr w21, [x0, #0x50]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr w21, [x0, #0x50]]
uint64_t fde_sub_0500ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0500ECULL;
}

// FDE #0409 | PC: 0x05018c..0x050238 (172 B) | Symbol: sub_05018c
// EN: AArch64 prologue [ldr x8, [x0, #8]; cbz x8, #0x50230; fmov d0, x8; cnt v0.8b, v0.8b] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; cbz x8, #0x50230; fmov d0, x8; cnt v0.8b, v0.8b]
uint64_t fde_sub_05018c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000508ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05018CULL;
}

// FDE #0410 | PC: 0x050238..0x0502b0 (120 B) | Symbol: sub_050238
// EN: AArch64 prologue [sub sp, sp, #0x30; str d8, [sp, #0x10]; str x20, [sp, #0x18]; stp x19, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str d8, [sp, #0x10]; str x20, [sp, #0x18]; stp x19, x30, [sp, #0x20]]
uint64_t fde_sub_050238(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050238ULL;
}

// FDE #0411 | PC: 0x0502b0..0x050630 (896 B) | Symbol: sub_0502b0
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x24, [sp, #0xa0]; stp x23, x22, [sp, #0xb0]; stp x21, x20, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x24, [sp, #0xa0]; stp x23, x22, [sp, #0xb0]; stp x21, x20, [sp, #0xc0]]
uint64_t fde_sub_0502b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90053F8ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0380ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0502B0ULL;
}

// FDE #0412 | PC: 0x050630..0x050660 (48 B) | Symbol: sub_050630
// EN: AArch64 prologue [cbz x0, #0x5065c; stp x19, x30, [sp, #-0x10]!; bl #0x930c8; bl #0x50630] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5065c; stp x19, x30, [sp, #-0x10]!; bl #0x930c8; bl #0x50630]
uint64_t fde_sub_050630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000160ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050630ULL;
}

// FDE #0413 | PC: 0x050660..0x05067c (28 B) | Symbol: sub_050660
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x18; bl #0x5067c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x18; bl #0x5067c]
uint64_t fde_sub_050660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050660ULL;
}

// FDE #0414 | PC: 0x05067c..0x050698 (28 B) | Symbol: sub_05067c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930dc; bl #0x50698; add x0, x19, #0x20] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930dc; bl #0x50698; add x0, x19, #0x20]
uint64_t fde_sub_05067c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010A97ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05067CULL;
}

// FDE #0415 | PC: 0x050698..0x0506a0 (8 B) | Symbol: sub_050698
// EN: AArch64 prologue [mov x1, xzr; b #0x506c4] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x506c4]
uint64_t fde_sub_050698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400000AULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050698ULL;
}

// FDE #0416 | PC: 0x0506a0..0x0506c4 (36 B) | Symbol: sub_0506a0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x506bc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x506bc; mov x0, x19]
uint64_t fde_sub_0506a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F589ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0506A0ULL;
}

// FDE #0417 | PC: 0x0506c4..0x0506ec (40 B) | Symbol: sub_0506c4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x506e4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x506e4; mov x0, x19]
uint64_t fde_sub_0506c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F580ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0506C4ULL;
}

// FDE #0418 | PC: 0x0506ec..0x0507d8 (236 B) | Symbol: sub_0506ec
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0]
uint64_t fde_sub_0506ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0506ECULL;
}

// FDE #0419 | PC: 0x0507d8..0x05081c (68 B) | Symbol: sub_0507d8
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldur q0, [x1, #9]; ldr q1, [x1]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldur q0, [x1, #9]; ldr q1, [x1]]
uint64_t fde_sub_0507d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0507D8ULL;
}

// FDE #0420 | PC: 0x05081c..0x050860 (68 B) | Symbol: sub_05081c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w8, #3; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w8, #3; mov x20, x0]
uint64_t fde_sub_05081c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05081CULL;
}

// FDE #0421 | PC: 0x050860..0x05088c (44 B) | Symbol: sub_050860
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x19, x30, [sp, #0x30]; bl #0x90988; b.hs #0x50884] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x19, x30, [sp, #0x30]; bl #0x90988; b.hs #0x50884]
uint64_t fde_sub_050860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9037BF3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050860ULL;
}

// FDE #0422 | PC: 0x05088c..0x050914 (136 B) | Symbol: sub_05088c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_05088c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05088CULL;
}

// FDE #0423 | PC: 0x050914..0x0509bc (168 B) | Symbol: sub_050914
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_050914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050914ULL;
}

// FDE #0424 | PC: 0x0509bc..0x0509cc (16 B) | Symbol: sub_0509bc
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0xbd0; str x8, [x0], #0x10; b #0x46c54] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0xbd0; str x8, [x0], #0x10; b #0x46c54]
uint64_t fde_sub_0509bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912F4108ULL) << 32) | 0x90000248ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0509BCULL;
}

// FDE #0425 | PC: 0x0509cc..0x0509e4 (24 B) | Symbol: sub_0509cc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x509bc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x509bc; mov x0, x19]
uint64_t fde_sub_0509cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0509CCULL;
}

// FDE #0426 | PC: 0x0509e4..0x050a78 (148 B) | Symbol: sub_0509e4
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_0509e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0509E4ULL;
}

// FDE #0427 | PC: 0x050a78..0x050ac0 (72 B) | Symbol: sub_050a78
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; movi v0.2d, #0000000000000000; stp q0, q0, [x0]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; movi v0.2d, #0000000000000000; stp q0, q0, [x0]]
uint64_t fde_sub_050a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050A78ULL;
}

// FDE #0428 | PC: 0x050ac0..0x050ad0 (16 B) | Symbol: sub_050ac0
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0xbf0; str x8, [x0], #8; b #0x4b524] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0xbf0; str x8, [x0], #8; b #0x4b524]
uint64_t fde_sub_050ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912FC108ULL) << 32) | 0x90000248ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050AC0ULL;
}

// FDE #0429 | PC: 0x050ad0..0x050ae8 (24 B) | Symbol: sub_050ad0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x50ac0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x50ac0; mov x0, x19]
uint64_t fde_sub_050ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050AD0ULL;
}

// FDE #0430 | PC: 0x050ae8..0x050c5c (372 B) | Symbol: sub_050ae8
// EN: AArch64 prologue [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_050ae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400FC59ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050AE8ULL;
}

// FDE #0431 | PC: 0x050c5c..0x050d7c (288 B) | Symbol: sub_050c5c
// EN: AArch64 prologue [sub sp, sp, #0x1a0; str x28, [sp, #0x160]; stp x23, x22, [sp, #0x170]; stp x21, x20, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; str x28, [sp, #0x160]; stp x23, x22, [sp, #0x170]; stp x21, x20, [sp, #0x180]]
uint64_t fde_sub_050c5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900B3FCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050C5CULL;
}

// FDE #0432 | PC: 0x050d7c..0x050df8 (124 B) | Symbol: sub_050d7c
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_050d7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0x6DBD23E9ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050D7CULL;
}

// FDE #0433 | PC: 0x050df8..0x0511f0 (1016 B) | Symbol: sub_050df8
// EN: AArch64 prologue [sub sp, sp, #0x1f0; str x28, [sp, #0x1a0]; stp x25, x24, [sp, #0x1b0]; stp x23, x22, [sp, #0x1c0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1f0; str x28, [sp, #0x1a0]; stp x25, x24, [sp, #0x1b0]; stp x23, x22, [sp, #0x1c0]]
uint64_t fde_sub_050df8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900D3FCULL) << 32) | 0xD107C3FFULL;
    const uint64_t kPcRange = 0x03F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050DF8ULL;
}

// FDE #0434 | PC: 0x0511f0..0x05120c (28 B) | Symbol: sub_0511f0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x924d8; bl #0x512d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x924d8; bl #0x512d8]
uint64_t fde_sub_0511f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0511F0ULL;
}

// FDE #0435 | PC: 0x05120c..0x051254 (72 B) | Symbol: sub_05120c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x1]; ldp x10, x9, [x1, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x1]; ldp x10, x9, [x1, #8]]
uint64_t fde_sub_05120c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05120CULL;
}

// FDE #0436 | PC: 0x051254..0x0512d8 (132 B) | Symbol: sub_051254
// EN: AArch64 prologue [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_051254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400FE3FULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051254ULL;
}

// FDE #0437 | PC: 0x0512d8..0x0512e8 (16 B) | Symbol: sub_0512d8
// EN: AArch64 prologue [mov x3, x30; bl #0x9000c; mov x30, x3; b #0x4dfec] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x9000c; mov x30, x3; b #0x4dfec]
uint64_t fde_sub_0512d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400FB4CULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0512D8ULL;
}

// FDE #0438 | PC: 0x0512e8..0x051308 (32 B) | Symbol: sub_0512e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xc10; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xc10; bl #0x8daa4]
uint64_t fde_sub_0512e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000228ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0512E8ULL;
}

// FDE #0439 | PC: 0x051308..0x051320 (24 B) | Symbol: sub_051308
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x512e8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x512e8; mov x0, x19]
uint64_t fde_sub_051308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051308ULL;
}

// FDE #0440 | PC: 0x051320..0x051328 (8 B) | Symbol: sub_051320
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x51328] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x51328]
uint64_t fde_sub_051320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051320ULL;
}

// FDE #0441 | PC: 0x051328..0x051348 (32 B) | Symbol: sub_051328
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930dc; bl #0x51348; add x0, x19, #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930dc; bl #0x51348; add x0, x19, #0x10]
uint64_t fde_sub_051328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401076CULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051328ULL;
}

// FDE #0442 | PC: 0x051348..0x051380 (56 B) | Symbol: sub_051348
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8db6c; cbz x0, #0x51368] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8db6c; cbz x0, #0x51368]
uint64_t fde_sub_051348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051348ULL;
}

// FDE #0443 | PC: 0x051380..0x0513a8 (40 B) | Symbol: sub_051380
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; cbz x8, #0x513a0; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; cbz x8, #0x513a0; mov x19, x0]
uint64_t fde_sub_051380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051380ULL;
}

// FDE #0444 | PC: 0x0513a8..0x051460 (184 B) | Symbol: sub_0513a8
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_0513a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9135BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0513A8ULL;
}

// FDE #0445 | PC: 0x051460..0x05149c (60 B) | Symbol: sub_051460
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x1]; ldr x9, [x0, #0x10]; str x8, [sp, #8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x1]; ldr x9, [x0, #0x10]; str x8, [sp, #8]]
uint64_t fde_sub_051460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400028ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051460ULL;
}

// FDE #0446 | PC: 0x05149c..0x0514a8 (12 B) | Symbol: sub_05149c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; add x0, x8, #0x10; b #0x4fb48] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; add x0, x8, #0x10; b #0x4fb48]
uint64_t fde_sub_05149c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004100ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05149CULL;
}

// FDE #0447 | PC: 0x0514a8..0x0514b0 (8 B) | Symbol: sub_0514a8
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; b #0x50914] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; b #0x50914]
uint64_t fde_sub_0514a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFD1AULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0514A8ULL;
}

// FDE #0448 | PC: 0x0514b0..0x0514b8 (8 B) | Symbol: sub_0514b0
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; b #0x50c5c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; b #0x50c5c]
uint64_t fde_sub_0514b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFDEAULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0514B0ULL;
}

// FDE #0449 | PC: 0x0514b8..0x0514c8 (16 B) | Symbol: sub_0514b8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; ldr d0, [x0, #0xb8]; mov x0, x8; b #0x50238] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; ldr d0, [x0, #0xb8]; mov x0, x8; b #0x50238]
uint64_t fde_sub_0514b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD405C00ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0514B8ULL;
}

// FDE #0450 | PC: 0x0514c8..0x0514e0 (24 B) | Symbol: sub_0514c8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; ldr d2, [x0, #0xb8]; fcvt s1, d0; mov x0, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; ldr d2, [x0, #0xb8]; fcvt s1, d0; mov x0, x8]
uint64_t fde_sub_0514c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD405C02ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0514C8ULL;
}

// FDE #0451 | PC: 0x0514e0..0x0514e8 (8 B) | Symbol: sub_0514e0
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; b #0x509e4] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; b #0x509e4]
uint64_t fde_sub_0514e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFD40ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0514E0ULL;
}

// FDE #0452 | PC: 0x0514e8..0x051580 (152 B) | Symbol: sub_0514e8
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_0514e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0514E8ULL;
}

// FDE #0453 | PC: 0x051580..0x051584 (4 B) | Symbol: sub_051580
// EN: AArch64 prologue [b #0x48da0] | VI: Khởi đầu hàm AArch64 [b #0x48da0]
uint64_t fde_sub_051580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0x17FFDE08ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051580ULL;
}

// FDE #0454 | PC: 0x051584..0x0515a8 (36 B) | Symbol: sub_051584
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #0x10]; and w9, w1, #1; strb w9, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #0x10]; and w9, w1, #1; strb w9, [x8, #0x20]]
uint64_t fde_sub_051584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051584ULL;
}

// FDE #0455 | PC: 0x0515a8..0x0515c8 (32 B) | Symbol: sub_0515a8
// EN: AArch64 prologue [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x10]; str w1, [x0, #0x24]; cmp w9, #0] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x10]; str w1, [x0, #0x24]; cmp w9, #0]
uint64_t fde_sub_0515a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39408009ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0515A8ULL;
}

// FDE #0456 | PC: 0x0515c8..0x05162c (100 B) | Symbol: sub_0515c8
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8dab0]
uint64_t fde_sub_0515c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0515C8ULL;
}

// FDE #0457 | PC: 0x05162c..0x0516f4 (200 B) | Symbol: sub_05162c
// EN: AArch64 prologue [sub sp, sp, #0x80; str x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]]
uint64_t fde_sub_05162c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF6ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05162CULL;
}

// FDE #0458 | PC: 0x0516f4..0x0516f8 (4 B) | Symbol: sub_0516f4
// EN: AArch64 prologue [b #0x907bc] | VI: Khởi đầu hàm AArch64 [b #0x907bc]
uint64_t fde_sub_0516f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10583FFULL) << 32) | 0x1400FC32ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0516F4ULL;
}

// FDE #0459 | PC: 0x0516f8..0x051794 (156 B) | Symbol: sub_0516f8
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_0516f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0516F8ULL;
}

// FDE #0460 | PC: 0x051794..0x0517e0 (76 B) | Symbol: sub_051794
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8dab0]
uint64_t fde_sub_051794(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051794ULL;
}

// FDE #0461 | PC: 0x0517e0..0x051858 (120 B) | Symbol: sub_0517e0
// EN: AArch64 prologue [sub sp, sp, #0x40; str d8, [sp, #0x20]; str x20, [sp, #0x28]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str d8, [sp, #0x20]; str x20, [sp, #0x28]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0517e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0517E0ULL;
}

// FDE #0462 | PC: 0x051858..0x051b80 (808 B) | Symbol: sub_051858
// EN: AArch64 prologue [sub sp, sp, #0x1c0; str x28, [sp, #0x170]; stp x25, x24, [sp, #0x180]; stp x23, x22, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; str x28, [sp, #0x170]; stp x25, x24, [sp, #0x180]; stp x23, x22, [sp, #0x190]]
uint64_t fde_sub_051858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900BBFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x0328ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051858ULL;
}

// FDE #0463 | PC: 0x051b80..0x051c68 (232 B) | Symbol: sub_051b80
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_051b80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9145BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B80ULL;
}

// FDE #0464 | PC: 0x051c68..0x051c84 (28 B) | Symbol: sub_051c68
// EN: AArch64 prologue [cmp x0, x1; b.eq #0x51c80; str x30, [sp, #-0x10]!; bl #0x9000c] | VI: Khởi đầu hàm AArch64 [cmp x0, x1; b.eq #0x51c80; str x30, [sp, #-0x10]!; bl #0x9000c]
uint64_t fde_sub_051c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540000A0ULL) << 32) | 0xEB01001FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051C68ULL;
}

// FDE #0465 | PC: 0x051c84..0x051d20 (156 B) | Symbol: sub_051c84
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92814; tbnz w8, #0, #0x51c9c] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92814; tbnz w8, #0, #0x51c9c]
uint64_t fde_sub_051c84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051C84ULL;
}

// FDE #0466 | PC: 0x051d20..0x051d70 (80 B) | Symbol: sub_051d20
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8dab0]
uint64_t fde_sub_051d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051D20ULL;
}

// FDE #0467 | PC: 0x051d70..0x051d84 (20 B) | Symbol: sub_051d70
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; ldr d1, [x0, #0x30]; str d0, [x0, #0x28]; mov x0, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; ldr d1, [x0, #0x30]; str d0, [x0, #0x28]; mov x0, x8]
uint64_t fde_sub_051d70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD401801ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051D70ULL;
}

// FDE #0468 | PC: 0x051d84..0x051da4 (32 B) | Symbol: sub_051d84
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; ldr d1, [x0, #0x28]; mov v2.16b, v0.16b; str d0, [x0, #0x30]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; ldr d1, [x0, #0x28]; mov v2.16b, v0.16b; str d0, [x0, #0x30]]
uint64_t fde_sub_051d84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD401401ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051D84ULL;
}

// FDE #0469 | PC: 0x051da4..0x051db8 (20 B) | Symbol: sub_051da4
// EN: AArch64 prologue [ldr x8, [x0, #0x20]; fcvt d0, s0; str d0, [x0, #0x48]; ldr x0, [x8, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x20]; fcvt d0, s0; str d0, [x0, #0x48]; ldr x0, [x8, #0x10]]
uint64_t fde_sub_051da4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E22C000ULL) << 32) | 0xF9401008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051DA4ULL;
}

// FDE #0470 | PC: 0x051db8..0x051df4 (60 B) | Symbol: sub_051db8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldrb w8, [x0, #0x41]; mov x19, x0; cbz w8, #0x51dd4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldrb w8, [x0, #0x41]; mov x19, x0; cbz w8, #0x51dd4]
uint64_t fde_sub_051db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39410408ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051DB8ULL;
}

// FDE #0471 | PC: 0x051df4..0x051efc (264 B) | Symbol: sub_051df4
// EN: AArch64 prologue [sub sp, sp, #0x80; str x24, [sp, #0x40]; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x24, [sp, #0x40]; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]]
uint64_t fde_sub_051df4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051DF4ULL;
}

// FDE #0472 | PC: 0x051efc..0x051f34 (56 B) | Symbol: sub_051efc
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; mov x1, x0; ldr x19, [x1], #8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; mov x1, x0; ldr x19, [x1], #8]
uint64_t fde_sub_051efc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051EFCULL;
}

// FDE #0473 | PC: 0x051f34..0x051f44 (16 B) | Symbol: sub_051f34
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; adrp x9, #0x98000; add x9, x9, #0xca8; b #0x8fa40] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; adrp x9, #0x98000; add x9, x9, #0xca8; b #0x8fa40]
uint64_t fde_sub_051f34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000229ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051F34ULL;
}

// FDE #0474 | PC: 0x051f44..0x051f5c (24 B) | Symbol: sub_051f44
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x51f34; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x51f34; mov x0, x19]
uint64_t fde_sub_051f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051F44ULL;
}

// FDE #0475 | PC: 0x051f5c..0x051f64 (8 B) | Symbol: sub_051f5c
// EN: AArch64 prologue [add x0, x0, #8; b #0x51efc] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0x51efc]
uint64_t fde_sub_051f5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFE7ULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051F5CULL;
}

// FDE #0476 | PC: 0x051f64..0x05207c (280 B) | Symbol: sub_051f64
// EN: AArch64 prologue [sub sp, sp, #0x90; stp d9, d8, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp d9, d8, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]]
uint64_t fde_sub_051f64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0523E9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051F64ULL;
}

// FDE #0477 | PC: 0x05207c..0x0520d8 (92 B) | Symbol: sub_05207c
// EN: AArch64 prologue [sub sp, sp, #0x40; stp d9, d8, [sp, #0x10]; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp d9, d8, [sp, #0x10]; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05207c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05207CULL;
}

// FDE #0478 | PC: 0x0520d8..0x0520e8 (16 B) | Symbol: sub_0520d8
// EN: AArch64 prologue [ldr x8, [x0, #0x28]; adrp x9, #0x98000; add x9, x9, #0xcd0; b #0x8fa40] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x28]; adrp x9, #0x98000; add x9, x9, #0xcd0; b #0x8fa40]
uint64_t fde_sub_0520d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9401408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0520D8ULL;
}

// FDE #0479 | PC: 0x0520e8..0x052100 (24 B) | Symbol: sub_0520e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x520d8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x520d8; mov x0, x19]
uint64_t fde_sub_0520e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0520E8ULL;
}

// FDE #0480 | PC: 0x052100..0x052108 (8 B) | Symbol: sub_052100
// EN: AArch64 prologue [add x0, x0, #8; b #0x5207c] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0x5207c]
uint64_t fde_sub_052100(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFDEULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052100ULL;
}

// FDE #0481 | PC: 0x052108..0x052164 (92 B) | Symbol: sub_052108
// EN: AArch64 prologue [str d8, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x20]]
uint64_t fde_sub_052108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xFC1D0FE8ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052108ULL;
}

// FDE #0482 | PC: 0x052164..0x05216c (8 B) | Symbol: sub_052164
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; b #0x4fe9c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; b #0x4fe9c]
uint64_t fde_sub_052164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFF74DULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052164ULL;
}

// FDE #0483 | PC: 0x05216c..0x0521e0 (116 B) | Symbol: sub_05216c
// EN: AArch64 prologue [sub sp, sp, #0x40; str d8, [sp, #0x10]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str d8, [sp, #0x10]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]]
uint64_t fde_sub_05216c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05216CULL;
}

// FDE #0484 | PC: 0x0521e0..0x0521ec (12 B) | Symbol: sub_0521e0
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x50c5c] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x50c5c]
uint64_t fde_sub_0521e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0521E0ULL;
}

// FDE #0485 | PC: 0x0521ec..0x052204 (24 B) | Symbol: sub_0521ec
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; str w1, [x0, #0xc0]; mov w9, #-1; mov w1, #2] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; str w1, [x0, #0xc0]; mov w9, #-1; mov w1, #2]
uint64_t fde_sub_0521ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB900C001ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0521ECULL;
}

// FDE #0486 | PC: 0x052204..0x052244 (64 B) | Symbol: sub_052204
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldrb w8, [x0, #0x40]; mov x19, x0; cbnz w8, #0x52228] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldrb w8, [x0, #0x40]; mov x19, x0; cbnz w8, #0x52228]
uint64_t fde_sub_052204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39410008ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052204ULL;
}

// FDE #0487 | PC: 0x052244..0x052314 (208 B) | Symbol: sub_052244
// EN: AArch64 prologue [sub sp, sp, #0x40; stp d9, d8, [sp, #0x10]; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp d9, d8, [sp, #0x10]; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_052244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052244ULL;
}

// FDE #0488 | PC: 0x052314..0x052400 (236 B) | Symbol: sub_052314
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_052314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9145BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052314ULL;
}

// FDE #0489 | PC: 0x052400..0x0524e0 (224 B) | Symbol: sub_052400
// EN: AArch64 prologue [sub sp, sp, #0x180; str x28, [sp, #0x140]; stp x23, x22, [sp, #0x150]; stp x21, x20, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; str x28, [sp, #0x140]; stp x23, x22, [sp, #0x150]; stp x21, x20, [sp, #0x160]]
uint64_t fde_sub_052400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900A3FCULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052400ULL;
}

// FDE #0490 | PC: 0x0524e0..0x052518 (56 B) | Symbol: sub_0524e0
// EN: AArch64 prologue [and w8, w1, #0xff; cmp w8, #0xb; b.hi #0x52514; mov w8, #0x87f] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xff; cmp w8, #0xb; b.hi #0x52514; mov w8, #0x87f]
uint64_t fde_sub_0524e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71002D1FULL) << 32) | 0x12001C28ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0524E0ULL;
}

// FDE #0491 | PC: 0x052518..0x052584 (108 B) | Symbol: sub_052518
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x19, #0xa0000; add x19, x19, #0x5e8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x19, #0xa0000; add x19, x19, #0x5e8]
uint64_t fde_sub_052518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052518ULL;
}

// FDE #0492 | PC: 0x052584..0x0525bc (56 B) | Symbol: sub_052584
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x19, #0xa0000; add x19, x19, #0xe8; adrp x1, #0x1d000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x19, #0xa0000; add x19, x19, #0xe8; adrp x1, #0x1d000]
uint64_t fde_sub_052584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000273ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052584ULL;
}

// FDE #0493 | PC: 0x0525bc..0x0525d4 (24 B) | Symbol: sub_0525bc
// EN: AArch64 prologue [ldp x9, x10, [x1]; stp xzr, xzr, [x1]; ldr x8, [x0, #0x30]; stp x9, x10, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [ldp x9, x10, [x1]; stp xzr, xzr, [x1]; ldr x8, [x0, #0x30]; stp x9, x10, [x0, #0x28]]
uint64_t fde_sub_0525bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007C3FULL) << 32) | 0xA9402829ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0525BCULL;
}

// FDE #0494 | PC: 0x0525d4..0x05267c (168 B) | Symbol: sub_0525d4
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8e68c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8e68c]
uint64_t fde_sub_0525d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90453F5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0525D4ULL;
}

// FDE #0495 | PC: 0x05267c..0x05268c (16 B) | Symbol: sub_05267c
// EN: AArch64 prologue [cbz x0, #0x52688; mov w1, #1; b #0x514b8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x52688; mov w1, #1; b #0x514b8; ret]
uint64_t fde_sub_05267c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800021ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05267CULL;
}

// FDE #0496 | PC: 0x05268c..0x05269c (16 B) | Symbol: sub_05268c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xd20; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xd20; b #0x8d518]
uint64_t fde_sub_05268c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05268CULL;
}

// FDE #0497 | PC: 0x05269c..0x0526b4 (24 B) | Symbol: sub_05269c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5268c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5268c; mov x0, x19]
uint64_t fde_sub_05269c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05269CULL;
}

// FDE #0498 | PC: 0x0526b4..0x0526c0 (12 B) | Symbol: sub_0526b4
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x5267c] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x5267c]
uint64_t fde_sub_0526b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0526B4ULL;
}

// FDE #0499 | PC: 0x0526c0..0x0527a4 (228 B) | Symbol: sub_0526c0
// EN: AArch64 prologue [sub sp, sp, #0x90; stp d9, d8, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp d9, d8, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]]
uint64_t fde_sub_0526c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0623E9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0526C0ULL;
}

// FDE #0500 | PC: 0x0527a4..0x0527b8 (20 B) | Symbol: sub_0527a4
// EN: AArch64 prologue [cbz x0, #0x527b4; ldp d0, d1, [x1]; ldrb w1, [x1, #0x10]; b #0x52244] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x527b4; ldp d0, d1, [x1]; ldrb w1, [x1, #0x10]; b #0x52244]
uint64_t fde_sub_0527a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D400420ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527A4ULL;
}

// FDE #0501 | PC: 0x0527b8..0x0527c8 (16 B) | Symbol: sub_0527b8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xd48; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xd48; b #0x8d518]
uint64_t fde_sub_0527b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527B8ULL;
}

// FDE #0502 | PC: 0x0527c8..0x0527e0 (24 B) | Symbol: sub_0527c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x527b8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x527b8; mov x0, x19]
uint64_t fde_sub_0527c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527C8ULL;
}

// FDE #0503 | PC: 0x0527e0..0x0527f0 (16 B) | Symbol: sub_0527e0
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x527a4] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x527a4]
uint64_t fde_sub_0527e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EB9CULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527E0ULL;
}

// FDE #0504 | PC: 0x0527f0..0x0528b8 (200 B) | Symbol: sub_0527f0
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_0527f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527F0ULL;
}

// FDE #0505 | PC: 0x0528b8..0x0528c8 (16 B) | Symbol: sub_0528b8
// EN: AArch64 prologue [cbz x0, #0x528c4; ldr w1, [x1]; b #0x521ec; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x528c4; ldr w1, [x1]; b #0x521ec; ret]
uint64_t fde_sub_0528b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400021ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0528B8ULL;
}

// FDE #0506 | PC: 0x0528c8..0x0528d8 (16 B) | Symbol: sub_0528c8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xd70; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xd70; b #0x8d518]
uint64_t fde_sub_0528c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0528C8ULL;
}

// FDE #0507 | PC: 0x0528d8..0x0528f0 (24 B) | Symbol: sub_0528d8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x528c8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x528c8; mov x0, x19]
uint64_t fde_sub_0528d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0528D8ULL;
}

// FDE #0508 | PC: 0x0528f0..0x052900 (16 B) | Symbol: sub_0528f0
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x528b8] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x528b8]
uint64_t fde_sub_0528f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EB58ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0528F0ULL;
}

// FDE #0509 | PC: 0x052900..0x0529a8 (168 B) | Symbol: sub_052900
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8e68c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8e68c]
uint64_t fde_sub_052900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90453F5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052900ULL;
}

// FDE #0510 | PC: 0x0529a8..0x0529b4 (12 B) | Symbol: sub_0529a8
// EN: AArch64 prologue [cbz x0, #0x529b0; b #0x52204; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x529b0; b #0x52204; ret]
uint64_t fde_sub_0529a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE16ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0529A8ULL;
}

// FDE #0511 | PC: 0x0529b4..0x0529c4 (16 B) | Symbol: sub_0529b4
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xd98; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xd98; b #0x8d518]
uint64_t fde_sub_0529b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0529B4ULL;
}

// FDE #0512 | PC: 0x0529c4..0x0529dc (24 B) | Symbol: sub_0529c4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x529b4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x529b4; mov x0, x19]
uint64_t fde_sub_0529c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0529C4ULL;
}

// FDE #0513 | PC: 0x0529dc..0x0529e8 (12 B) | Symbol: sub_0529dc
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x529a8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x529a8]
uint64_t fde_sub_0529dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0529DCULL;
}

// FDE #0514 | PC: 0x0529e8..0x052a90 (168 B) | Symbol: sub_0529e8
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8e68c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8e68c]
uint64_t fde_sub_0529e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90453F5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0529E8ULL;
}

// FDE #0515 | PC: 0x052a90..0x052aa0 (16 B) | Symbol: sub_052a90
// EN: AArch64 prologue [cbz x0, #0x52a9c; mov w1, #3; b #0x514b8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x52a9c; mov w1, #3; b #0x514b8; ret]
uint64_t fde_sub_052a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800061ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052A90ULL;
}

// FDE #0516 | PC: 0x052aa0..0x052ab0 (16 B) | Symbol: sub_052aa0
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xdc0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xdc0; b #0x8d518]
uint64_t fde_sub_052aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052AA0ULL;
}

// FDE #0517 | PC: 0x052ab0..0x052ac8 (24 B) | Symbol: sub_052ab0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52aa0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52aa0; mov x0, x19]
uint64_t fde_sub_052ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052AB0ULL;
}

// FDE #0518 | PC: 0x052ac8..0x052ad4 (12 B) | Symbol: sub_052ac8
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x52a90] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x52a90]
uint64_t fde_sub_052ac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052AC8ULL;
}

// FDE #0519 | PC: 0x052ad4..0x052ba8 (212 B) | Symbol: sub_052ad4
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]]
uint64_t fde_sub_052ad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075BF7ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052AD4ULL;
}

// FDE #0520 | PC: 0x052ba8..0x052bb4 (12 B) | Symbol: sub_052ba8
// EN: AArch64 prologue [cbz x0, #0x52bb0; b #0x929d0; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x52bb0; b #0x929d0; ret]
uint64_t fde_sub_052ba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400FF89ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BA8ULL;
}

// FDE #0521 | PC: 0x052bb4..0x052bb8 (4 B) | Symbol: sub_052bb4
// EN: AArch64 prologue [b #0x8f804] | VI: Khởi đầu hàm AArch64 [b #0x8f804]
uint64_t fde_sub_052bb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0x1400F314ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BB4ULL;
}

// FDE #0522 | PC: 0x052bb8..0x052bd0 (24 B) | Symbol: sub_052bb8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x18; bl #0x8fc8c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x18; bl #0x8fc8c]
uint64_t fde_sub_052bb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BB8ULL;
}

// FDE #0523 | PC: 0x052bd0..0x052be0 (16 B) | Symbol: sub_052bd0
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0xde8; str x8, [x0], #8; b #0x52bb8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0xde8; str x8, [x0], #8; b #0x52bb8]
uint64_t fde_sub_052bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9137A108ULL) << 32) | 0xD0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BD0ULL;
}

// FDE #0524 | PC: 0x052be0..0x052bf8 (24 B) | Symbol: sub_052be0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52bd0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52bd0; mov x0, x19]
uint64_t fde_sub_052be0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BE0ULL;
}

// FDE #0525 | PC: 0x052bf8..0x052c08 (16 B) | Symbol: sub_052bf8
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x52ba8] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x52ba8]
uint64_t fde_sub_052bf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EA96ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BF8ULL;
}

// FDE #0526 | PC: 0x052c08..0x052cdc (212 B) | Symbol: sub_052c08
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]]
uint64_t fde_sub_052c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075BF7ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052C08ULL;
}

// FDE #0527 | PC: 0x052cdc..0x052cf0 (20 B) | Symbol: sub_052cdc
// EN: AArch64 prologue [cbz x0, #0x52cec; mov x2, x1; ldr w1, [x2], #8; b #0x514a8] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x52cec; mov x2, x1; ldr w1, [x2], #8; b #0x514a8]
uint64_t fde_sub_052cdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E2ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052CDCULL;
}

// FDE #0528 | PC: 0x052cf0..0x052d00 (16 B) | Symbol: sub_052cf0
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0xe10; str x8, [x0], #8; b #0x52bb8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0xe10; str x8, [x0], #8; b #0x52bb8]
uint64_t fde_sub_052cf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91384108ULL) << 32) | 0xD0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052CF0ULL;
}

// FDE #0529 | PC: 0x052d00..0x052d18 (24 B) | Symbol: sub_052d00
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52cf0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52cf0; mov x0, x19]
uint64_t fde_sub_052d00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052D00ULL;
}

// FDE #0530 | PC: 0x052d18..0x052d28 (16 B) | Symbol: sub_052d18
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x52cdc] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x52cdc]
uint64_t fde_sub_052d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EA4EULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052D18ULL;
}

// FDE #0531 | PC: 0x052d28..0x052d30 (8 B) | Symbol: sub_052d28
// EN: AArch64 prologue [sub x0, x0, #0x18; b #0x52c08] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x18; b #0x52c08]
uint64_t fde_sub_052d28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFB7ULL) << 32) | 0xD1006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052D28ULL;
}

// FDE #0532 | PC: 0x052d30..0x052d34 (4 B) | Symbol: sub_052d30
// EN: AArch64 prologue [b #0x90a38] | VI: Khởi đầu hàm AArch64 [b #0x90a38]
uint64_t fde_sub_052d30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8C08ULL) << 32) | 0x1400F742ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052D30ULL;
}

// FDE #0533 | PC: 0x052d34..0x052d40 (12 B) | Symbol: sub_052d34
// EN: AArch64 prologue [ldr x8, [x0, #-0x18]!; ldr x3, [x8, #0x38]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #-0x18]!; ldr x3, [x8, #0x38]; br x3]
uint64_t fde_sub_052d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401D03ULL) << 32) | 0xF85E8C08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052D34ULL;
}

// FDE #0534 | PC: 0x052d40..0x052e08 (200 B) | Symbol: sub_052d40
// EN: AArch64 prologue [sub sp, sp, #0x80; str d8, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str d8, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]]
uint64_t fde_sub_052d40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD002BE8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052D40ULL;
}

// FDE #0535 | PC: 0x052e08..0x052e20 (24 B) | Symbol: sub_052e08
// EN: AArch64 prologue [cbz x0, #0x52e1c; ldr s0, [x1]; ldr w1, [x1, #4]; fcvt d0, s0] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x52e1c; ldr s0, [x1]; ldr w1, [x1, #4]; fcvt d0, s0]
uint64_t fde_sub_052e08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD400020ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E08ULL;
}

// FDE #0536 | PC: 0x052e20..0x052e30 (16 B) | Symbol: sub_052e20
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xe38; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x98000; add x9, x9, #0xe38; b #0x8d518]
uint64_t fde_sub_052e20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E20ULL;
}

// FDE #0537 | PC: 0x052e30..0x052e48 (24 B) | Symbol: sub_052e30
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52e20; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52e20; mov x0, x19]
uint64_t fde_sub_052e30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E30ULL;
}

// FDE #0538 | PC: 0x052e48..0x052e58 (16 B) | Symbol: sub_052e48
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x52e08] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x52e08]
uint64_t fde_sub_052e48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EA02ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E48ULL;
}

// FDE #0539 | PC: 0x052e58..0x052e60 (8 B) | Symbol: sub_052e58
// EN: AArch64 prologue [sub x0, x0, #0x20; b #0x52d40] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x20; b #0x52d40]
uint64_t fde_sub_052e58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFB9ULL) << 32) | 0xD1008000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E58ULL;
}

// FDE #0540 | PC: 0x052e60..0x052e9c (60 B) | Symbol: sub_052e60
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; mov x19, x0; add x8, x8, #0xe60] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; mov x19, x0; add x8, x8, #0xe60]
uint64_t fde_sub_052e60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000228ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E60ULL;
}

// FDE #0541 | PC: 0x052e9c..0x052eb4 (24 B) | Symbol: sub_052e9c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52e60; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x52e60; mov x0, x19]
uint64_t fde_sub_052e9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E9CULL;
}

// FDE #0542 | PC: 0x052eb4..0x052ebc (8 B) | Symbol: sub_052eb4
// EN: AArch64 prologue [sub x0, x0, #0x18; b #0x52e60] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x18; b #0x52e60]
uint64_t fde_sub_052eb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFEAULL) << 32) | 0xD1006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052EB4ULL;
}

// FDE #0543 | PC: 0x052ebc..0x052ec4 (8 B) | Symbol: sub_052ebc
// EN: AArch64 prologue [sub x0, x0, #0x18; b #0x52e9c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x18; b #0x52e9c]
uint64_t fde_sub_052ebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF7ULL) << 32) | 0xD1006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052EBCULL;
}

// FDE #0544 | PC: 0x052ec4..0x052ecc (8 B) | Symbol: sub_052ec4
// EN: AArch64 prologue [sub x0, x0, #0x20; b #0x52e60] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x20; b #0x52e60]
uint64_t fde_sub_052ec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFE6ULL) << 32) | 0xD1008000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052EC4ULL;
}

// FDE #0545 | PC: 0x052ecc..0x052ed4 (8 B) | Symbol: sub_052ecc
// EN: AArch64 prologue [sub x0, x0, #0x20; b #0x52e9c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x20; b #0x52e9c]
uint64_t fde_sub_052ecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF3ULL) << 32) | 0xD1008000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052ECCULL;
}

// FDE #0546 | PC: 0x052ed4..0x0531ec (792 B) | Symbol: _ZN4lynx6animax12AnimaXPlayerC2ERNS0_19AnimaXPlayerBuilderE
// EN: AArch64 prologue [mov x2, x30; bl #0x91c18; mov x30, x2; stp x29, x30, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x91c18; mov x30, x2; stp x29, x30, [sp, #0x1b0]]
uint64_t fde_sub_052ed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400FB50ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0318ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052ED4ULL;
}

// FDE #0547 | PC: 0x0531ec..0x0531f4 (8 B) | Symbol: sub_0531ec
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; b #0x932e0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; b #0x932e0]
uint64_t fde_sub_0531ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1401003CULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0531ECULL;
}

// FDE #0548 | PC: 0x0531f4..0x053874 (1664 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer4InitERNS0_19AnimaXPlayerBuilderE
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x26, [sp, #0x100]; stp x25, x24, [sp, #0x110]; stp x23, x22, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x26, [sp, #0x100]; stp x25, x24, [sp, #0x110]; stp x23, x22, [sp, #0x120]]
uint64_t fde_sub_0531f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9106BFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0680ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0531F4ULL;
}

// FDE #0549 | PC: 0x053874..0x05389c (40 B) | Symbol: sub_053874
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x53894; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x53894; mov x0, x19]
uint64_t fde_sub_053874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E9DEULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053874ULL;
}

// FDE #0550 | PC: 0x05389c..0x0538f4 (88 B) | Symbol: sub_05389c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x10]]
uint64_t fde_sub_05389c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05389CULL;
}

// FDE #0551 | PC: 0x0538f4..0x05390c (24 B) | Symbol: sub_0538f4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x51380; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x51380; ldr x0, [x19, #8]]
uint64_t fde_sub_0538f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E889ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0538F4ULL;
}

// FDE #0552 | PC: 0x05390c..0x053970 (100 B) | Symbol: sub_05390c
// EN: AArch64 prologue [cbz x0, #0x5396c; sub sp, sp, #0x40; stp x19, x30, [sp, #0x30]; ldp x8, x19, [x1]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5396c; sub sp, sp, #0x40; stp x19, x30, [sp, #0x30]; ldp x8, x19, [x1]]
uint64_t fde_sub_05390c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xB4000300ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05390CULL;
}

// FDE #0553 | PC: 0x053970..0x053988 (24 B) | Symbol: sub_053970
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x53988; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x53988; ldr x0, [x19, #8]]
uint64_t fde_sub_053970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E86AULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053970ULL;
}

// FDE #0554 | PC: 0x053988..0x0539a4 (28 B) | Symbol: sub_053988
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x44830] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x44830]
uint64_t fde_sub_053988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053988ULL;
}

// FDE #0555 | PC: 0x0539a4..0x0539c4 (32 B) | Symbol: sub_0539a4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xfa8; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xfa8; bl #0x8daa4]
uint64_t fde_sub_0539a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000228ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0539A4ULL;
}

// FDE #0556 | PC: 0x0539c4..0x0539dc (24 B) | Symbol: sub_0539c4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x539a4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x539a4; mov x0, x19]
uint64_t fde_sub_0539c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0539C4ULL;
}

// FDE #0557 | PC: 0x0539dc..0x0539ec (16 B) | Symbol: sub_0539dc
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0xf80; str x8, [x0], #8; b #0x53970] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0xf80; str x8, [x0], #8; b #0x53970]
uint64_t fde_sub_0539dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913E0108ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0539DCULL;
}

// FDE #0558 | PC: 0x0539ec..0x053a04 (24 B) | Symbol: sub_0539ec
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x539dc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x539dc; mov x0, x19]
uint64_t fde_sub_0539ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0539ECULL;
}

// FDE #0559 | PC: 0x053a04..0x053a14 (16 B) | Symbol: sub_053a04
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x5390c] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x5390c]
uint64_t fde_sub_053a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E713ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A04ULL;
}

// FDE #0560 | PC: 0x053a14..0x053a24 (16 B) | Symbol: sub_053a14
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0xf58; str x8, [x0], #8; b #0x538f4] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0xf58; str x8, [x0], #8; b #0x538f4]
uint64_t fde_sub_053a14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913D6108ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A14ULL;
}

// FDE #0561 | PC: 0x053a24..0x053a3c (24 B) | Symbol: sub_053a24
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53a14; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53a14; mov x0, x19]
uint64_t fde_sub_053a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A24ULL;
}

// FDE #0562 | PC: 0x053a3c..0x053a4c (16 B) | Symbol: sub_053a3c
// EN: AArch64 prologue [ldr x8, [x0, #8]; add x1, x0, #0x18; mov x0, x8; b #0x5389c] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; add x1, x0, #0x18; mov x0, x8; b #0x5389c]
uint64_t fde_sub_053a3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A3CULL;
}

// FDE #0563 | PC: 0x053a4c..0x053a6c (32 B) | Symbol: sub_053a4c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xfe0; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x98000; add x8, x8, #0xfe0; bl #0x8daa4]
uint64_t fde_sub_053a4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000228ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A4CULL;
}

// FDE #0564 | PC: 0x053a6c..0x053a84 (24 B) | Symbol: sub_053a6c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53a4c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53a4c; mov x0, x19]
uint64_t fde_sub_053a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A6CULL;
}

// FDE #0565 | PC: 0x053a84..0x053a8c (8 B) | Symbol: sub_053a84
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x53a8c] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x53a8c]
uint64_t fde_sub_053a84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A84ULL;
}

// FDE #0566 | PC: 0x053a8c..0x053ab0 (36 B) | Symbol: sub_053a8c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x4cc14] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x4cc14]
uint64_t fde_sub_053a8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A8CULL;
}

// FDE #0567 | PC: 0x053ab0..0x053ad0 (32 B) | Symbol: sub_053ab0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0x18; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0x18; bl #0x8daa4]
uint64_t fde_sub_053ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000228ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053AB0ULL;
}

// FDE #0568 | PC: 0x053ad0..0x053ae8 (24 B) | Symbol: sub_053ad0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53ab0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53ab0; mov x0, x19]
uint64_t fde_sub_053ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053AD0ULL;
}

// FDE #0569 | PC: 0x053ae8..0x053b9c (180 B) | Symbol: _ZN4lynx6animax12AnimaXPlayerD1Ev
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_053ae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053AE8ULL;
}

// FDE #0570 | PC: 0x053b9c..0x053bf8 (92 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer21GetEventTrackingArrayEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34]
uint64_t fde_sub_053b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053B9CULL;
}

// FDE #0571 | PC: 0x053bf8..0x053c18 (32 B) | Symbol: sub_053bf8
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x53c14; ldr x8, [x8, #0x30]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x53c14; ldr x8, [x8, #0x30]]
uint64_t fde_sub_053bf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053BF8ULL;
}

// FDE #0572 | PC: 0x053c18..0x053c30 (24 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer13GetEventNamesEv
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x937c0; adrp x0, #0xa0000; add x0, x0, #0x808] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x937c0; adrp x0, #0xa0000; add x0, x0, #0x808]
uint64_t fde_sub_053c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400FEE9ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053C18ULL;
}

// FDE #0573 | PC: 0x053c30..0x053d48 (280 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer7DestroyEv
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_053c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9145BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053C30ULL;
}

// FDE #0574 | PC: 0x053d48..0x053d54 (12 B) | Symbol: sub_053d48
// EN: AArch64 prologue [cbz x0, #0x53d50; b #0x5149c; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x53d50; b #0x5149c; ret]
uint64_t fde_sub_053d48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFF5D4ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053D48ULL;
}

// FDE #0575 | PC: 0x053d54..0x053d60 (12 B) | Symbol: sub_053d54
// EN: AArch64 prologue [cbz x0, #0x53d5c; b #0x5a1fc; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x53d5c; b #0x5a1fc; ret]
uint64_t fde_sub_053d54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001929ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053D54ULL;
}

// FDE #0576 | PC: 0x053d60..0x053d70 (16 B) | Symbol: sub_053d60
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xa0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xa0; b #0x8d518]
uint64_t fde_sub_053d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053D60ULL;
}

// FDE #0577 | PC: 0x053d70..0x053d88 (24 B) | Symbol: sub_053d70
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53d60; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53d60; mov x0, x19]
uint64_t fde_sub_053d70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053D70ULL;
}

// FDE #0578 | PC: 0x053d88..0x053d94 (12 B) | Symbol: sub_053d88
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x53d54] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x53d54]
uint64_t fde_sub_053d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053D88ULL;
}

// FDE #0579 | PC: 0x053d94..0x053da4 (16 B) | Symbol: sub_053d94
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x78; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x78; b #0x8d518]
uint64_t fde_sub_053d94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053D94ULL;
}

// FDE #0580 | PC: 0x053da4..0x053dbc (24 B) | Symbol: sub_053da4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53d94; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53d94; mov x0, x19]
uint64_t fde_sub_053da4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053DA4ULL;
}

// FDE #0581 | PC: 0x053dbc..0x053dc8 (12 B) | Symbol: sub_053dbc
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x53d48] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x53d48]
uint64_t fde_sub_053dbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053DBCULL;
}

// FDE #0582 | PC: 0x053dc8..0x053edc (276 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer6ReloadEv
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_053dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9145BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053DC8ULL;
}

// FDE #0583 | PC: 0x053edc..0x053ee8 (12 B) | Symbol: sub_053edc
// EN: AArch64 prologue [cbz x0, #0x53ee4; b #0x5a294; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x53ee4; b #0x5a294; ret]
uint64_t fde_sub_053edc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140018EDULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053EDCULL;
}

// FDE #0584 | PC: 0x053ee8..0x053ef4 (12 B) | Symbol: sub_053ee8
// EN: AArch64 prologue [cbz x0, #0x53ef0; b #0x51db8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x53ef0; b #0x51db8; ret]
uint64_t fde_sub_053ee8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFF7B3ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053EE8ULL;
}

// FDE #0585 | PC: 0x053ef4..0x053f04 (16 B) | Symbol: sub_053ef4
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xf0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xf0; b #0x8d518]
uint64_t fde_sub_053ef4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053EF4ULL;
}

// FDE #0586 | PC: 0x053f04..0x053f1c (24 B) | Symbol: sub_053f04
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53ef4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53ef4; mov x0, x19]
uint64_t fde_sub_053f04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F04ULL;
}

// FDE #0587 | PC: 0x053f1c..0x053f28 (12 B) | Symbol: sub_053f1c
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x53ee8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x53ee8]
uint64_t fde_sub_053f1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F1CULL;
}

// FDE #0588 | PC: 0x053f28..0x053f38 (16 B) | Symbol: sub_053f28
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xc8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xc8; b #0x8d518]
uint64_t fde_sub_053f28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F28ULL;
}

// FDE #0589 | PC: 0x053f38..0x053f50 (24 B) | Symbol: sub_053f38
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53f28; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x53f28; mov x0, x19]
uint64_t fde_sub_053f38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F38ULL;
}

// FDE #0590 | PC: 0x053f50..0x053f5c (12 B) | Symbol: sub_053f50
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x53edc] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x53edc]
uint64_t fde_sub_053f50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F50ULL;
}

// FDE #0591 | PC: 0x053f5c..0x054014 (184 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer13CreateSurfaceENS_4base15MoveOnlyClosureINSt6__ndk110unique_ptrINS0_13AnimaXSurfaceENS4_14default_deleteIS6_EEEEJEEE
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_053f5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F5CULL;
}

// FDE #0592 | PC: 0x054014..0x054044 (48 B) | Symbol: sub_054014
// EN: AArch64 prologue [cbz x0, #0x54040; sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x9276c] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x54040; sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x9276c]
uint64_t fde_sub_054014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xB4000160ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054014ULL;
}

// FDE #0593 | PC: 0x054044..0x054060 (28 B) | Symbol: sub_054044
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; cbz x0, #0x54054; bl #0x8d3c4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; cbz x0, #0x54054; bl #0x8d3c4]
uint64_t fde_sub_054044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E6C9ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054044ULL;
}

// FDE #0594 | PC: 0x054060..0x054070 (16 B) | Symbol: sub_054060
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x118; str x8, [x0], #8; b #0x54044] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x118; str x8, [x0], #8; b #0x54044]
uint64_t fde_sub_054060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91046108ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054060ULL;
}

// FDE #0595 | PC: 0x054070..0x054088 (24 B) | Symbol: sub_054070
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54060; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54060; mov x0, x19]
uint64_t fde_sub_054070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054070ULL;
}

// FDE #0596 | PC: 0x054088..0x054098 (16 B) | Symbol: sub_054088
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54014] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54014]
uint64_t fde_sub_054088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E572ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054088ULL;
}

// FDE #0597 | PC: 0x054098..0x054150 (184 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer13UpdateSurfaceENS_4base15MoveOnlyClosureINSt6__ndk110unique_ptrINS0_13AnimaXSurfaceENS4_14default_deleteIS6_EEEEJS9_EEE
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_054098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054098ULL;
}

// FDE #0598 | PC: 0x054150..0x054180 (48 B) | Symbol: sub_054150
// EN: AArch64 prologue [cbz x0, #0x5417c; sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x9276c] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5417c; sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x9276c]
uint64_t fde_sub_054150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xB4000160ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054150ULL;
}

// FDE #0599 | PC: 0x054180..0x054190 (16 B) | Symbol: sub_054180
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x140; str x8, [x0], #8; b #0x54044] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x140; str x8, [x0], #8; b #0x54044]
uint64_t fde_sub_054180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91050108ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054180ULL;
}

// FDE #0600 | PC: 0x054190..0x0541a8 (24 B) | Symbol: sub_054190
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54180; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54180; mov x0, x19]
uint64_t fde_sub_054190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054190ULL;
}

// FDE #0601 | PC: 0x0541a8..0x0541b8 (16 B) | Symbol: sub_0541a8
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54150] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54150]
uint64_t fde_sub_0541a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E52AULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0541A8ULL;
}

// FDE #0602 | PC: 0x0541b8..0x054220 (104 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer7SetJsonEPKc
// EN: AArch64 prologue [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8eba4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8eba4]
uint64_t fde_sub_0541b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F4ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0541B8ULL;
}

// FDE #0603 | PC: 0x054220..0x054438 (536 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer7SetJsonENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x1b0; stp x28, x24, [sp, #0x170]; stp x23, x22, [sp, #0x180]; stp x21, x20, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; stp x28, x24, [sp, #0x170]; stp x23, x22, [sp, #0x180]; stp x21, x20, [sp, #0x190]]
uint64_t fde_sub_054220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91763FCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054220ULL;
}

// FDE #0604 | PC: 0x054438..0x054474 (60 B) | Symbol: sub_054438
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x90300] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x90300]
uint64_t fde_sub_054438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054438ULL;
}

// FDE #0605 | PC: 0x054474..0x05450c (152 B) | Symbol: sub_054474
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]]
uint64_t fde_sub_054474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054474ULL;
}

// FDE #0606 | PC: 0x05450c..0x05454c (64 B) | Symbol: sub_05450c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1, #0x10]; ldr q0, [x1]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1, #0x10]; ldr q0, [x1]]
uint64_t fde_sub_05450c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05450CULL;
}

// FDE #0607 | PC: 0x05454c..0x054564 (24 B) | Symbol: sub_05454c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x54564; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x54564; ldr x0, [x19, #8]]
uint64_t fde_sub_05454c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E573ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05454CULL;
}

// FDE #0608 | PC: 0x054564..0x05457c (24 B) | Symbol: sub_054564
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x48d40; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x48d40; mov x0, x19]
uint64_t fde_sub_054564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E891ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054564ULL;
}

// FDE #0609 | PC: 0x05457c..0x05458c (16 B) | Symbol: sub_05457c
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x190; str x8, [x0], #8; b #0x5454c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x190; str x8, [x0], #8; b #0x5454c]
uint64_t fde_sub_05457c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91064108ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05457CULL;
}

// FDE #0610 | PC: 0x05458c..0x0545a4 (24 B) | Symbol: sub_05458c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5457c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5457c; mov x0, x19]
uint64_t fde_sub_05458c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05458CULL;
}

// FDE #0611 | PC: 0x0545a4..0x0545b4 (16 B) | Symbol: sub_0545a4
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54474] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54474]
uint64_t fde_sub_0545a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E42BULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0545A4ULL;
}

// FDE #0612 | PC: 0x0545b4..0x0545c4 (16 B) | Symbol: sub_0545b4
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x1b8; b #0x8fa40] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x1b8; b #0x8fa40]
uint64_t fde_sub_0545b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0545B4ULL;
}

// FDE #0613 | PC: 0x0545c4..0x0545dc (24 B) | Symbol: sub_0545c4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x545b4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x545b4; mov x0, x19]
uint64_t fde_sub_0545c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0545C4ULL;
}

// FDE #0614 | PC: 0x0545dc..0x0547d0 (500 B) | Symbol: sub_0545dc
// EN: AArch64 prologue [str x28, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0545dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FFCULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0545DCULL;
}

// FDE #0615 | PC: 0x0547d0..0x0547dc (12 B) | Symbol: sub_0547d0
// EN: AArch64 prologue [ldr w8, [x1]; str w8, [x0]; b #0x8f620] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1]; str w8, [x0]; b #0x8f620]
uint64_t fde_sub_0547d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9000008ULL) << 32) | 0xB9400028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0547D0ULL;
}

// FDE #0616 | PC: 0x0547dc..0x054a0c (560 B) | Symbol: sub_0547dc
// EN: AArch64 prologue [mov x2, x30; bl #0x8e8e8; mov x30, x2; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8e8e8; mov x30, x2; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_0547dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E842ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0547DCULL;
}

// FDE #0617 | PC: 0x054a0c..0x054a48 (60 B) | Symbol: sub_054a0c
// EN: AArch64 prologue [cbz x0, #0x54a44; sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x54a44; sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_054a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0xB40001C0ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054A0CULL;
}

// FDE #0618 | PC: 0x054a48..0x054a5c (20 B) | Symbol: sub_054a48
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x93100; ldr x0, [x19, #8]; ldp x19, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x93100; ldr x0, [x19, #8]; ldp x19, x30, [sp], #0x10]
uint64_t fde_sub_054a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F9ADULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054A48ULL;
}

// FDE #0619 | PC: 0x054a5c..0x054c34 (472 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer17UpdateCompositionEiNSt6__ndk110shared_ptrINS0_16CompositionModelEEE
// EN: AArch64 prologue [sub sp, sp, #0x1b0; str x28, [sp, #0x160]; stp x25, x24, [sp, #0x170]; stp x23, x22, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; str x28, [sp, #0x160]; stp x25, x24, [sp, #0x170]; stp x23, x22, [sp, #0x180]]
uint64_t fde_sub_054a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900B3FCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054A5CULL;
}

// FDE #0620 | PC: 0x054c34..0x054c4c (24 B) | Symbol: sub_054c34
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x54c4c; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x54c4c; ldr x0, [x19, #8]]
uint64_t fde_sub_054c34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E3B9ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054C34ULL;
}

// FDE #0621 | PC: 0x054c4c..0x054c8c (64 B) | Symbol: sub_054c4c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x54c84] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x54c84]
uint64_t fde_sub_054c4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054C4CULL;
}

// FDE #0622 | PC: 0x054c8c..0x054ca0 (20 B) | Symbol: sub_054c8c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930dc; bl #0x91050; ldp x19, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930dc; bl #0x91050; ldp x19, x30, [sp], #0x10]
uint64_t fde_sub_054c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F913ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054C8CULL;
}

// FDE #0623 | PC: 0x054ca0..0x054cb0 (16 B) | Symbol: sub_054ca0
// EN: AArch64 prologue [cbz x0, #0x54cac; mov w1, #8; b #0x514b8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x54cac; mov w1, #8; b #0x514b8; ret]
uint64_t fde_sub_054ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800101ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054CA0ULL;
}

// FDE #0624 | PC: 0x054cb0..0x054cf8 (72 B) | Symbol: sub_054cb0
// EN: AArch64 prologue [cbz x0, #0x54cf4; sub sp, sp, #0x20; ldr x9, [x1, #8]; mov x8, x1] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x54cf4; sub sp, sp, #0x20; ldr x9, [x1, #8]; mov x8, x1]
uint64_t fde_sub_054cb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xB4000220ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054CB0ULL;
}

// FDE #0625 | PC: 0x054cf8..0x054d10 (24 B) | Symbol: sub_054cf8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; bl #0x44830; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; bl #0x44830; ldr x0, [x19, #8]]
uint64_t fde_sub_054cf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E43FULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054CF8ULL;
}

// FDE #0626 | PC: 0x054d10..0x054d20 (16 B) | Symbol: sub_054d10
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x230; str x8, [x0], #8; b #0x54cf8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x230; str x8, [x0], #8; b #0x54cf8]
uint64_t fde_sub_054d10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9108C108ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D10ULL;
}

// FDE #0627 | PC: 0x054d20..0x054d38 (24 B) | Symbol: sub_054d20
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54d10; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54d10; mov x0, x19]
uint64_t fde_sub_054d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D20ULL;
}

// FDE #0628 | PC: 0x054d38..0x054d48 (16 B) | Symbol: sub_054d38
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54cb0] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54cb0]
uint64_t fde_sub_054d38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E246ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D38ULL;
}

// FDE #0629 | PC: 0x054d48..0x054d58 (16 B) | Symbol: sub_054d48
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x208; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x208; b #0x8d518]
uint64_t fde_sub_054d48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D48ULL;
}

// FDE #0630 | PC: 0x054d58..0x054d70 (24 B) | Symbol: sub_054d58
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54d48; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54d48; mov x0, x19]
uint64_t fde_sub_054d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D58ULL;
}

// FDE #0631 | PC: 0x054d70..0x054d7c (12 B) | Symbol: sub_054d70
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x54ca0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x54ca0]
uint64_t fde_sub_054d70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D70ULL;
}

// FDE #0632 | PC: 0x054d7c..0x054d8c (16 B) | Symbol: sub_054d7c
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x1e0; str x8, [x0], #8; b #0x54a48] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x1e0; str x8, [x0], #8; b #0x54a48]
uint64_t fde_sub_054d7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91078108ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D7CULL;
}

// FDE #0633 | PC: 0x054d8c..0x054da4 (24 B) | Symbol: sub_054d8c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54d7c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54d7c; mov x0, x19]
uint64_t fde_sub_054d8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D8CULL;
}

// FDE #0634 | PC: 0x054da4..0x054db4 (16 B) | Symbol: sub_054da4
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54a0c] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x54a0c]
uint64_t fde_sub_054da4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E22BULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054DA4ULL;
}

// FDE #0635 | PC: 0x054db4..0x054dc4 (16 B) | Symbol: sub_054db4
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x168; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x168; b #0x8d518]
uint64_t fde_sub_054db4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054DB4ULL;
}

// FDE #0636 | PC: 0x054dc4..0x054ddc (24 B) | Symbol: sub_054dc4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54db4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x54db4; mov x0, x19]
uint64_t fde_sub_054dc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054DC4ULL;
}

// FDE #0637 | PC: 0x054ddc..0x054de8 (12 B) | Symbol: sub_054ddc
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x54438] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x54438]
uint64_t fde_sub_054ddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054DDCULL;
}

// FDE #0638 | PC: 0x054de8..0x054f54 (364 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer14SetCompositionENSt6__ndk110shared_ptrINS0_16CompositionModelEEE
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x24, [sp, #0x150]; stp x23, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x24, [sp, #0x150]; stp x23, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]]
uint64_t fde_sub_054de8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91563FCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054DE8ULL;
}

// FDE #0639 | PC: 0x054f54..0x0551d8 (644 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer6SetSrcERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x1c0; str x28, [sp, #0x170]; stp x25, x24, [sp, #0x180]; stp x23, x22, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; str x28, [sp, #0x170]; stp x25, x24, [sp, #0x180]; stp x23, x22, [sp, #0x190]]
uint64_t fde_sub_054f54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900BBFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054F54ULL;
}

// FDE #0640 | PC: 0x0551d8..0x0551e4 (12 B) | Symbol: sub_0551d8
// EN: AArch64 prologue [cbz x0, #0x551e0; b #0x51b80; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x551e0; b #0x51b80; ret]
uint64_t fde_sub_0551d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFF269ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0551D8ULL;
}

// FDE #0641 | PC: 0x0551e4..0x0551fc (24 B) | Symbol: sub_0551e4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x10; bl #0x8fc8c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x10; bl #0x8fc8c]
uint64_t fde_sub_0551e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0551E4ULL;
}

// FDE #0642 | PC: 0x0551fc..0x055294 (152 B) | Symbol: sub_0551fc
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]]
uint64_t fde_sub_0551fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0551FCULL;
}

// FDE #0643 | PC: 0x055294..0x0552c8 (52 B) | Symbol: sub_055294
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8efd8; bl #0x47f90] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8efd8; bl #0x47f90]
uint64_t fde_sub_055294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055294ULL;
}

// FDE #0644 | PC: 0x0552c8..0x0552e0 (24 B) | Symbol: sub_0552c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x552e0; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x552e0; ldr x0, [x19, #8]]
uint64_t fde_sub_0552c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E214ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0552C8ULL;
}

// FDE #0645 | PC: 0x0552e0..0x0552f8 (24 B) | Symbol: sub_0552e0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; bl #0x48d40; add x0, x19, #8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; bl #0x48d40; add x0, x19, #8]
uint64_t fde_sub_0552e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E626ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0552E0ULL;
}

// FDE #0646 | PC: 0x0552f8..0x055308 (16 B) | Symbol: sub_0552f8
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x280; str x8, [x0], #8; b #0x552c8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x280; str x8, [x0], #8; b #0x552c8]
uint64_t fde_sub_0552f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910A0108ULL) << 32) | 0x90000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0552F8ULL;
}

// FDE #0647 | PC: 0x055308..0x055320 (24 B) | Symbol: sub_055308
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x552f8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x552f8; mov x0, x19]
uint64_t fde_sub_055308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055308ULL;
}

// FDE #0648 | PC: 0x055320..0x055330 (16 B) | Symbol: sub_055320
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x551fc] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x551fc]
uint64_t fde_sub_055320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E0CCULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055320ULL;
}

// FDE #0649 | PC: 0x055330..0x055340 (16 B) | Symbol: sub_055330
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x2a8; b #0x8fa40] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x2a8; b #0x8fa40]
uint64_t fde_sub_055330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000229ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055330ULL;
}

// FDE #0650 | PC: 0x055340..0x055358 (24 B) | Symbol: sub_055340
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x55330; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x55330; mov x0, x19]
uint64_t fde_sub_055340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055340ULL;
}

// FDE #0651 | PC: 0x055358..0x05554c (500 B) | Symbol: sub_055358
// EN: AArch64 prologue [str x28, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_055358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FFCULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055358ULL;
}

// FDE #0652 | PC: 0x05554c..0x05555c (16 B) | Symbol: sub_05554c
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x258; str x8, [x0], #8; b #0x551e4] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x258; str x8, [x0], #8; b #0x551e4]
uint64_t fde_sub_05554c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91096108ULL) << 32) | 0x90000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05554CULL;
}

// FDE #0653 | PC: 0x05555c..0x055574 (24 B) | Symbol: sub_05555c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5554c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5554c; mov x0, x19]
uint64_t fde_sub_05555c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05555CULL;
}

// FDE #0654 | PC: 0x055574..0x055584 (16 B) | Symbol: sub_055574
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x551d8] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x551d8]
uint64_t fde_sub_055574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E037ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055574ULL;
}

// FDE #0655 | PC: 0x055584..0x055670 (236 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer14SetImageFolderENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x90; str x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]]
uint64_t fde_sub_055584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F6ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055584ULL;
}

// FDE #0656 | PC: 0x055670..0x0556e0 (112 B) | Symbol: sub_055670
// EN: AArch64 prologue [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8dab0]
uint64_t fde_sub_055670(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F4ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055670ULL;
}

// FDE #0657 | PC: 0x0556e0..0x0556f0 (16 B) | Symbol: sub_0556e0
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x2d0; str x8, [x0], #8; b #0x551e4] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x2d0; str x8, [x0], #8; b #0x551e4]
uint64_t fde_sub_0556e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910B4108ULL) << 32) | 0x90000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0556E0ULL;
}

// FDE #0658 | PC: 0x0556f0..0x055708 (24 B) | Symbol: sub_0556f0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x556e0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x556e0; mov x0, x19]
uint64_t fde_sub_0556f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0556F0ULL;
}

// FDE #0659 | PC: 0x055708..0x055718 (16 B) | Symbol: sub_055708
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x55670] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x55670]
uint64_t fde_sub_055708(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DFD2ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055708ULL;
}

// FDE #0660 | PC: 0x055718..0x0557e4 (204 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer14SetSrcPolyfillENSt6__ndk113unordered_mapINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEES9_NS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_S9_EEEEEE
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]]
uint64_t fde_sub_055718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055718ULL;
}

// FDE #0661 | PC: 0x0557e4..0x0558f8 (276 B) | Symbol: sub_0557e4
// EN: AArch64 prologue [sub sp, sp, #0x90; str x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]]
uint64_t fde_sub_0557e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F6ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0557E4ULL;
}

// FDE #0662 | PC: 0x0558f8..0x055910 (24 B) | Symbol: sub_0558f8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4ea00; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4ea00; ldr x0, [x19, #8]]
uint64_t fde_sub_0558f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E088ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0558F8ULL;
}

// FDE #0663 | PC: 0x055910..0x055920 (16 B) | Symbol: sub_055910
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x2f8; str x8, [x0], #8; b #0x558f8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x2f8; str x8, [x0], #8; b #0x558f8]
uint64_t fde_sub_055910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910BE108ULL) << 32) | 0x90000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055910ULL;
}

// FDE #0664 | PC: 0x055920..0x055938 (24 B) | Symbol: sub_055920
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x55910; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x55910; mov x0, x19]
uint64_t fde_sub_055920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055920ULL;
}

// FDE #0665 | PC: 0x055938..0x055948 (16 B) | Symbol: sub_055938
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x557e4] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x557e4]
uint64_t fde_sub_055938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DF46ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055938ULL;
}

// FDE #0666 | PC: 0x055948..0x055b74 (556 B) | Symbol: sub_055948
// EN: AArch64 prologue [mov x2, x30; bl #0x8e8e8; mov x30, x2; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8e8e8; mov x30, x2; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_055948(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E3E7ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x022CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055948ULL;
}

// FDE #0667 | PC: 0x055b74..0x055ba4 (48 B) | Symbol: sub_055b74
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x55b9c; ldrb w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x55b9c; ldrb w8, [x0, #0x10]]
uint64_t fde_sub_055b74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E11EULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055B74ULL;
}

// FDE #0668 | PC: 0x055ba4..0x055bac (8 B) | Symbol: sub_055ba4
// EN: AArch64 prologue [mov w0, #0x40; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x40; b #0x93320]
uint64_t fde_sub_055ba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400F5DEULL) << 32) | 0x52800800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055BA4ULL;
}

// FDE #0669 | PC: 0x055bac..0x055c98 (236 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer22LoadAssetsWithCallbackENS_4base15MoveOnlyClosureIvJEEE
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]]
uint64_t fde_sub_055bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F8ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055BACULL;
}

// FDE #0670 | PC: 0x055c98..0x055e28 (400 B) | Symbol: sub_055c98
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_055c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055C98ULL;
}

// FDE #0671 | PC: 0x055e28..0x055e38 (16 B) | Symbol: sub_055e28
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x320; str x8, [x0], #8; b #0x4b780] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x320; str x8, [x0], #8; b #0x4b780]
uint64_t fde_sub_055e28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910C8108ULL) << 32) | 0x90000228ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055E28ULL;
}

// FDE #0672 | PC: 0x055e38..0x055e50 (24 B) | Symbol: sub_055e38
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x55e28; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x55e28; mov x0, x19]
uint64_t fde_sub_055e38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055E38ULL;
}

// FDE #0673 | PC: 0x055e50..0x055e60 (16 B) | Symbol: sub_055e50
// EN: AArch64 prologue [ldr x8, [x0, #8]; add x1, x0, #0x18; mov x0, x8; b #0x55c98] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; add x1, x0, #0x18; mov x0, x8; b #0x55c98]
uint64_t fde_sub_055e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055E50ULL;
}

// FDE #0674 | PC: 0x055e60..0x055f9c (316 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer21LoadCompositionAssetsENSt6__ndk110shared_ptrINS0_16CompositionModelEEENS_4base15MoveOnlyClosureIvJEEE
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x26, [sp, #0x90]; stp x25, x24, [sp, #0xa0]; stp x23, x22, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x26, [sp, #0x90]; stp x25, x24, [sp, #0xa0]; stp x23, x22, [sp, #0xb0]]
uint64_t fde_sub_055e60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BFAULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055E60ULL;
}

// FDE #0675 | PC: 0x055f9c..0x05602c (144 B) | Symbol: sub_055f9c
// EN: AArch64 prologue [cbz x0, #0x56028; sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x56028; sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]]
uint64_t fde_sub_055f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0xB4000460ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055F9CULL;
}

// FDE #0676 | PC: 0x05602c..0x056044 (24 B) | Symbol: sub_05602c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4b780; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4b780; ldr x0, [x19, #8]]
uint64_t fde_sub_05602c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DEBBULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05602CULL;
}

// FDE #0677 | PC: 0x056044..0x056054 (16 B) | Symbol: sub_056044
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x370; str x8, [x0], #8; b #0x5602c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x370; str x8, [x0], #8; b #0x5602c]
uint64_t fde_sub_056044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910DC108ULL) << 32) | 0xF0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056044ULL;
}

// FDE #0678 | PC: 0x056054..0x05606c (24 B) | Symbol: sub_056054
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56044; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56044; mov x0, x19]
uint64_t fde_sub_056054(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056054ULL;
}

// FDE #0679 | PC: 0x05606c..0x05607c (16 B) | Symbol: sub_05606c
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x55f9c] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x55f9c]
uint64_t fde_sub_05606c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DD79ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05606CULL;
}

// FDE #0680 | PC: 0x05607c..0x05608c (16 B) | Symbol: sub_05607c
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x398; str x8, [x0], #8; b #0x4b798] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x398; str x8, [x0], #8; b #0x4b798]
uint64_t fde_sub_05607c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910E6108ULL) << 32) | 0xF0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05607CULL;
}

// FDE #0681 | PC: 0x05608c..0x0560a4 (24 B) | Symbol: sub_05608c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5607c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5607c; mov x0, x19]
uint64_t fde_sub_05608c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05608CULL;
}

// FDE #0682 | PC: 0x0560a4..0x056224 (384 B) | Symbol: sub_0560a4
// EN: AArch64 prologue [sub sp, sp, #0x1d0; str x28, [sp, #0x190]; stp x23, x22, [sp, #0x1a0]; stp x21, x20, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1d0; str x28, [sp, #0x190]; stp x23, x22, [sp, #0x1a0]; stp x21, x20, [sp, #0x1b0]]
uint64_t fde_sub_0560a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900CBFCULL) << 32) | 0xD10743FFULL;
    const uint64_t kPcRange = 0x0180ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0560A4ULL;
}

// FDE #0683 | PC: 0x056224..0x056234 (16 B) | Symbol: sub_056224
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x348; str x8, [x0], #8; b #0x54044] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x348; str x8, [x0], #8; b #0x54044]
uint64_t fde_sub_056224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910D2108ULL) << 32) | 0xF0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056224ULL;
}

// FDE #0684 | PC: 0x056234..0x05624c (24 B) | Symbol: sub_056234
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56224; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56224; mov x0, x19]
uint64_t fde_sub_056234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056234ULL;
}

// FDE #0685 | PC: 0x05624c..0x056264 (24 B) | Symbol: sub_05624c
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56260; ldr x0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56260; ldr x0, [x0, #0x18]]
uint64_t fde_sub_05624c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05624CULL;
}

// FDE #0686 | PC: 0x056264..0x0562e4 (128 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer7SetLoopEb
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_056264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056264ULL;
}

// FDE #0687 | PC: 0x0562e4..0x0562f8 (20 B) | Symbol: sub_0562e4
// EN: AArch64 prologue [cbz x0, #0x562f4; ldrb w1, [x1]; ldr x0, [x0, #0x20]; b #0x51584] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x562f4; ldrb w1, [x1]; ldr x0, [x0, #0x20]; b #0x51584]
uint64_t fde_sub_0562e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400021ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0562E4ULL;
}

// FDE #0688 | PC: 0x0562f8..0x056308 (16 B) | Symbol: sub_0562f8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x3c0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x3c0; b #0x8d518]
uint64_t fde_sub_0562f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0562F8ULL;
}

// FDE #0689 | PC: 0x056308..0x056320 (24 B) | Symbol: sub_056308
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x562f8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x562f8; mov x0, x19]
uint64_t fde_sub_056308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056308ULL;
}

// FDE #0690 | PC: 0x056320..0x056330 (16 B) | Symbol: sub_056320
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x562e4] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x562e4]
uint64_t fde_sub_056320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DCCCULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056320ULL;
}

// FDE #0691 | PC: 0x056330..0x0563cc (156 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer12SetLoopCountEi
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_056330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056330ULL;
}

// FDE #0692 | PC: 0x0563cc..0x0563e0 (20 B) | Symbol: sub_0563cc
// EN: AArch64 prologue [cbz x0, #0x563dc; ldr w1, [x1]; ldr x0, [x0, #0x20]; b #0x515a8] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x563dc; ldr w1, [x1]; ldr x0, [x0, #0x20]; b #0x515a8]
uint64_t fde_sub_0563cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400021ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0563CCULL;
}

// FDE #0693 | PC: 0x0563e0..0x0563f0 (16 B) | Symbol: sub_0563e0
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x3e8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x3e8; b #0x8d518]
uint64_t fde_sub_0563e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0563E0ULL;
}

// FDE #0694 | PC: 0x0563f0..0x056408 (24 B) | Symbol: sub_0563f0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x563e0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x563e0; mov x0, x19]
uint64_t fde_sub_0563f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0563F0ULL;
}

// FDE #0695 | PC: 0x056408..0x056418 (16 B) | Symbol: sub_056408
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x563cc] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x563cc]
uint64_t fde_sub_056408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DC92ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056408ULL;
}

// FDE #0696 | PC: 0x056418..0x0564a8 (144 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer14SetAutoReverseEb
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_056418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056418ULL;
}

// FDE #0697 | PC: 0x0564a8..0x0564b8 (16 B) | Symbol: sub_0564a8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x410; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x410; b #0x8d518]
uint64_t fde_sub_0564a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0564A8ULL;
}

// FDE #0698 | PC: 0x0564b8..0x0564d0 (24 B) | Symbol: sub_0564b8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x564a8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x564a8; mov x0, x19]
uint64_t fde_sub_0564b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0564B8ULL;
}

// FDE #0699 | PC: 0x0564d0..0x0564f0 (32 B) | Symbol: sub_0564d0
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x564ec; ldr x8, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x564ec; ldr x8, [x8, #0x20]]
uint64_t fde_sub_0564d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0564D0ULL;
}

// FDE #0700 | PC: 0x0564f0..0x0565a8 (184 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer8SetSpeedEd
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0564f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0564F0ULL;
}

// FDE #0701 | PC: 0x0565a8..0x0565b8 (16 B) | Symbol: sub_0565a8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x438; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x438; b #0x8d518]
uint64_t fde_sub_0565a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0565A8ULL;
}

// FDE #0702 | PC: 0x0565b8..0x0565d0 (24 B) | Symbol: sub_0565b8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x565a8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x565a8; mov x0, x19]
uint64_t fde_sub_0565b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0565B8ULL;
}

// FDE #0703 | PC: 0x0565d0..0x0565f8 (40 B) | Symbol: sub_0565d0
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x565f4; ldr x9, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x565f4; ldr x9, [x8, #0x20]]
uint64_t fde_sub_0565d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0565D0ULL;
}

// FDE #0704 | PC: 0x0565f8..0x056764 (364 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer19SetFpsEventIntervalEl
// EN: AArch64 prologue [sub sp, sp, #0x1a0; str x28, [sp, #0x150]; stp x25, x24, [sp, #0x160]; stp x23, x22, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; str x28, [sp, #0x150]; stp x25, x24, [sp, #0x160]; stp x23, x22, [sp, #0x170]]
uint64_t fde_sub_0565f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900ABFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0565F8ULL;
}

// FDE #0705 | PC: 0x056764..0x056774 (16 B) | Symbol: sub_056764
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x460; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x460; b #0x8d518]
uint64_t fde_sub_056764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056764ULL;
}

// FDE #0706 | PC: 0x056774..0x05678c (24 B) | Symbol: sub_056774
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56764; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56764; mov x0, x19]
uint64_t fde_sub_056774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056774ULL;
}

// FDE #0707 | PC: 0x05678c..0x0567a4 (24 B) | Symbol: sub_05678c
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x567a0; ldr x9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x567a0; ldr x9, [x0, #0x18]]
uint64_t fde_sub_05678c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05678CULL;
}

// FDE #0708 | PC: 0x0567a4..0x05685c (184 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer11SetProgressEd
// EN: AArch64 prologue [sub sp, sp, #0x170; str d8, [sp, #0x140]; str x28, [sp, #0x148]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str d8, [sp, #0x140]; str x28, [sp, #0x148]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_0567a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00A3E8ULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0567A4ULL;
}

// FDE #0709 | PC: 0x05685c..0x056870 (20 B) | Symbol: sub_05685c
// EN: AArch64 prologue [cbz x0, #0x5686c; ldr d0, [x1]; fcvt s0, d0; b #0x51da4] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5686c; ldr d0, [x1]; fcvt s0, d0; b #0x51da4]
uint64_t fde_sub_05685c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD400020ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05685CULL;
}

// FDE #0710 | PC: 0x056870..0x056880 (16 B) | Symbol: sub_056870
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x488; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x488; b #0x8d518]
uint64_t fde_sub_056870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056870ULL;
}

// FDE #0711 | PC: 0x056880..0x056898 (24 B) | Symbol: sub_056880
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56870; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56870; mov x0, x19]
uint64_t fde_sub_056880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056880ULL;
}

// FDE #0712 | PC: 0x056898..0x0568a8 (16 B) | Symbol: sub_056898
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x5685c] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x5685c]
uint64_t fde_sub_056898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DB6EULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056898ULL;
}

// FDE #0713 | PC: 0x0568a8..0x056928 (128 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer11SetAutoplayEb
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0568a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0568A8ULL;
}

// FDE #0714 | PC: 0x056928..0x056940 (24 B) | Symbol: sub_056928
// EN: AArch64 prologue [cbz x0, #0x5693c; ldrb w8, [x1]; ldr x9, [x0, #0x20]; strb w8, [x0, #0x41]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5693c; ldrb w8, [x1]; ldr x9, [x0, #0x20]; strb w8, [x0, #0x41]]
uint64_t fde_sub_056928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400028ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056928ULL;
}

// FDE #0715 | PC: 0x056940..0x056950 (16 B) | Symbol: sub_056940
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x4b0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x4b0; b #0x8d518]
uint64_t fde_sub_056940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056940ULL;
}

// FDE #0716 | PC: 0x056950..0x056968 (24 B) | Symbol: sub_056950
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56940; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56940; mov x0, x19]
uint64_t fde_sub_056950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056950ULL;
}

// FDE #0717 | PC: 0x056968..0x056978 (16 B) | Symbol: sub_056968
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x56928] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x56928]
uint64_t fde_sub_056968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DB3AULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056968ULL;
}

// FDE #0718 | PC: 0x056978..0x056ad8 (352 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer18SetDynamicResourceEb
// EN: AArch64 prologue [sub sp, sp, #0x190; str x28, [sp, #0x150]; stp x23, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; str x28, [sp, #0x150]; stp x23, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]]
uint64_t fde_sub_056978(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900ABFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056978ULL;
}

// FDE #0719 | PC: 0x056ad8..0x056af0 (24 B) | Symbol: sub_056ad8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x500; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x500; str x9, [x0]]
uint64_t fde_sub_056ad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056AD8ULL;
}

// FDE #0720 | PC: 0x056af0..0x056b08 (24 B) | Symbol: sub_056af0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56ad8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56ad8; mov x0, x19]
uint64_t fde_sub_056af0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056AF0ULL;
}

// FDE #0721 | PC: 0x056b08..0x056b24 (28 B) | Symbol: sub_056b08
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56b20; ldrb w9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56b20; ldrb w9, [x0, #0x18]]
uint64_t fde_sub_056b08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B08ULL;
}

// FDE #0722 | PC: 0x056b24..0x056b34 (16 B) | Symbol: sub_056b24
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x4d8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x4d8; b #0x8d518]
uint64_t fde_sub_056b24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B24ULL;
}

// FDE #0723 | PC: 0x056b34..0x056b4c (24 B) | Symbol: sub_056b34
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56b24; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56b24; mov x0, x19]
uint64_t fde_sub_056b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B34ULL;
}

// FDE #0724 | PC: 0x056b4c..0x056b64 (24 B) | Symbol: sub_056b4c
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56b60; ldrb w9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56b60; ldrb w9, [x0, #0x18]]
uint64_t fde_sub_056b4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B4CULL;
}

// FDE #0725 | PC: 0x056b64..0x056bb4 (80 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer28EnableDynamicResourceFeatureEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34]
uint64_t fde_sub_056b64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B64ULL;
}

// FDE #0726 | PC: 0x056bb4..0x056be0 (44 B) | Symbol: sub_056bb4
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56bdc; ldrb w9, [x8, #0x41]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56bdc; ldrb w9, [x8, #0x41]]
uint64_t fde_sub_056bb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056BB4ULL;
}

// FDE #0727 | PC: 0x056be0..0x056c7c (156 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer13SetStartFrameEd
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_056be0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0023E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056BE0ULL;
}

// FDE #0728 | PC: 0x056c7c..0x056c90 (20 B) | Symbol: sub_056c7c
// EN: AArch64 prologue [cbz x0, #0x56c8c; ldr d0, [x1]; ldr x0, [x0, #0x20]; b #0x51d70] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x56c8c; ldr d0, [x1]; ldr x0, [x0, #0x20]; b #0x51d70]
uint64_t fde_sub_056c7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD400020ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056C7CULL;
}

// FDE #0729 | PC: 0x056c90..0x056ca0 (16 B) | Symbol: sub_056c90
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x550; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x550; b #0x8d518]
uint64_t fde_sub_056c90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056C90ULL;
}

// FDE #0730 | PC: 0x056ca0..0x056cb8 (24 B) | Symbol: sub_056ca0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56c90; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56c90; mov x0, x19]
uint64_t fde_sub_056ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CA0ULL;
}

// FDE #0731 | PC: 0x056cb8..0x056cc8 (16 B) | Symbol: sub_056cb8
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x56c7c] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x56c7c]
uint64_t fde_sub_056cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DA66ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CB8ULL;
}

// FDE #0732 | PC: 0x056cc8..0x056d64 (156 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer11SetEndFrameEd
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_056cc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0023E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CC8ULL;
}

// FDE #0733 | PC: 0x056d64..0x056d78 (20 B) | Symbol: sub_056d64
// EN: AArch64 prologue [cbz x0, #0x56d74; ldr d0, [x1]; ldr x0, [x0, #0x20]; b #0x51d84] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x56d74; ldr d0, [x1]; ldr x0, [x0, #0x20]; b #0x51d84]
uint64_t fde_sub_056d64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD400020ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056D64ULL;
}

// FDE #0734 | PC: 0x056d78..0x056d88 (16 B) | Symbol: sub_056d78
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x578; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x578; b #0x8d518]
uint64_t fde_sub_056d78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056D78ULL;
}

// FDE #0735 | PC: 0x056d88..0x056da0 (24 B) | Symbol: sub_056d88
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56d78; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56d78; mov x0, x19]
uint64_t fde_sub_056d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056D88ULL;
}

// FDE #0736 | PC: 0x056da0..0x056db0 (16 B) | Symbol: sub_056da0
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x56d64] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x56d64]
uint64_t fde_sub_056da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DA2CULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056DA0ULL;
}

// FDE #0737 | PC: 0x056db0..0x056e38 (136 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer16SetKeepLastFrameEb
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_056db0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056DB0ULL;
}

// FDE #0738 | PC: 0x056e38..0x056e48 (16 B) | Symbol: sub_056e38
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x5a0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x5a0; b #0x8d518]
uint64_t fde_sub_056e38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056E38ULL;
}

// FDE #0739 | PC: 0x056e48..0x056e60 (24 B) | Symbol: sub_056e48
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56e38; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56e38; mov x0, x19]
uint64_t fde_sub_056e48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056E48ULL;
}

// FDE #0740 | PC: 0x056e60..0x056e78 (24 B) | Symbol: sub_056e60
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56e74; ldrb w9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56e74; ldrb w9, [x0, #0x18]]
uint64_t fde_sub_056e60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056E60ULL;
}

// FDE #0741 | PC: 0x056e78..0x056f18 (160 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer12SetObjectFitENS0_9ObjectFitE
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_056e78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056E78ULL;
}

// FDE #0742 | PC: 0x056f18..0x056fb8 (160 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer17SetObjectPositionENS0_14ObjectPositionE
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_056f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F18ULL;
}

// FDE #0743 | PC: 0x056fb8..0x056fc8 (16 B) | Symbol: sub_056fb8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x5c8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x5c8; b #0x8d518]
uint64_t fde_sub_056fb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FB8ULL;
}

// FDE #0744 | PC: 0x056fc8..0x056fe0 (24 B) | Symbol: sub_056fc8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56fb8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x56fb8; mov x0, x19]
uint64_t fde_sub_056fc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FC8ULL;
}

// FDE #0745 | PC: 0x056fe0..0x056ff8 (24 B) | Symbol: sub_056fe0
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56ff4; ldrb w9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x56ff4; ldrb w9, [x0, #0x18]]
uint64_t fde_sub_056fe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FE0ULL;
}

// FDE #0746 | PC: 0x056ff8..0x0570b8 (192 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer15SetMaxFrameRateEd
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_056ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FF8ULL;
}

// FDE #0747 | PC: 0x0570b8..0x0570c8 (16 B) | Symbol: sub_0570b8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x5f0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x5f0; b #0x8d518]
uint64_t fde_sub_0570b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0570B8ULL;
}

// FDE #0748 | PC: 0x0570c8..0x0570e0 (24 B) | Symbol: sub_0570c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x570b8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x570b8; mov x0, x19]
uint64_t fde_sub_0570c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0570C8ULL;
}

// FDE #0749 | PC: 0x0570e0..0x057110 (48 B) | Symbol: sub_0570e0
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x5710c; ldr x8, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x5710c; ldr x8, [x8, #0x20]]
uint64_t fde_sub_0570e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0570E0ULL;
}

// FDE #0750 | PC: 0x057110..0x057228 (280 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer11PlaySegmentEdd
// EN: AArch64 prologue [sub sp, sp, #0x190; stp d9, d8, [sp, #0x150]; str x28, [sp, #0x160]; stp x21, x20, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp d9, d8, [sp, #0x150]; str x28, [sp, #0x160]; stp x21, x20, [sp, #0x170]]
uint64_t fde_sub_057110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D1523E9ULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057110ULL;
}

// FDE #0751 | PC: 0x057228..0x057238 (16 B) | Symbol: sub_057228
// EN: AArch64 prologue [cbz x0, #0x57234; ldp d0, d1, [x1]; b #0x51f64; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57234; ldp d0, d1, [x1]; b #0x51f64; ret]
uint64_t fde_sub_057228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D400420ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057228ULL;
}

// FDE #0752 | PC: 0x057238..0x057248 (16 B) | Symbol: sub_057238
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x618; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x618; b #0x8d518]
uint64_t fde_sub_057238(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057238ULL;
}

// FDE #0753 | PC: 0x057248..0x057260 (24 B) | Symbol: sub_057248
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57238; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57238; mov x0, x19]
uint64_t fde_sub_057248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057248ULL;
}

// FDE #0754 | PC: 0x057260..0x057270 (16 B) | Symbol: sub_057260
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57228] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57228]
uint64_t fde_sub_057260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D8FCULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057260ULL;
}

// FDE #0755 | PC: 0x057270..0x0572c4 (84 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer8GetWidthEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x91de0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x91de0]
uint64_t fde_sub_057270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057270ULL;
}

// FDE #0756 | PC: 0x0572c4..0x0572e4 (32 B) | Symbol: sub_0572c4
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x572e0; ldr s0, [x8, #0x78]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x572e0; ldr s0, [x8, #0x78]]
uint64_t fde_sub_0572c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0572C4ULL;
}

// FDE #0757 | PC: 0x0572e4..0x057338 (84 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer9GetHeightEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x91de0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x91de0]
uint64_t fde_sub_0572e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0572E4ULL;
}

// FDE #0758 | PC: 0x057338..0x057358 (32 B) | Symbol: sub_057338
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x57354; ldr s0, [x8, #0x7c]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x57354; ldr s0, [x8, #0x7c]]
uint64_t fde_sub_057338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057338ULL;
}

// FDE #0759 | PC: 0x057358..0x0573ac (84 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer13GetDurationMsEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34]
uint64_t fde_sub_057358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057358ULL;
}

// FDE #0760 | PC: 0x0573ac..0x0573d0 (36 B) | Symbol: sub_0573ac
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x90a44; ldr x0, [x8, #0x10]; cbz x0, #0x573c8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x90a44; ldr x0, [x8, #0x10]; cbz x0, #0x573c8]
uint64_t fde_sub_0573ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E5A5ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0573ACULL;
}

// FDE #0761 | PC: 0x0573d0..0x057470 (160 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer4PlayEv
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_0573d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900A3FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0573D0ULL;
}

// FDE #0762 | PC: 0x057470..0x05747c (12 B) | Symbol: sub_057470
// EN: AArch64 prologue [cbz x0, #0x57478; b #0x51df4; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57478; b #0x51df4; ret]
uint64_t fde_sub_057470(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFEA60ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057470ULL;
}

// FDE #0763 | PC: 0x05747c..0x05748c (16 B) | Symbol: sub_05747c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x6b8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x6b8; b #0x8d518]
uint64_t fde_sub_05747c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05747CULL;
}

// FDE #0764 | PC: 0x05748c..0x0574a4 (24 B) | Symbol: sub_05748c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5747c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5747c; mov x0, x19]
uint64_t fde_sub_05748c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05748CULL;
}

// FDE #0765 | PC: 0x0574a4..0x0574b0 (12 B) | Symbol: sub_0574a4
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x57470] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x57470]
uint64_t fde_sub_0574a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0574A4ULL;
}

// FDE #0766 | PC: 0x0574b0..0x057550 (160 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer5PauseEv
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_0574b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900A3FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0574B0ULL;
}

// FDE #0767 | PC: 0x057550..0x05755c (12 B) | Symbol: sub_057550
// EN: AArch64 prologue [cbz x0, #0x57558; b #0x515c8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57558; b #0x515c8; ret]
uint64_t fde_sub_057550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE81DULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057550ULL;
}

// FDE #0768 | PC: 0x05755c..0x05756c (16 B) | Symbol: sub_05755c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x6e0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x6e0; b #0x8d518]
uint64_t fde_sub_05755c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05755CULL;
}

// FDE #0769 | PC: 0x05756c..0x057584 (24 B) | Symbol: sub_05756c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5755c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5755c; mov x0, x19]
uint64_t fde_sub_05756c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05756CULL;
}

// FDE #0770 | PC: 0x057584..0x057590 (12 B) | Symbol: sub_057584
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x57550] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x57550]
uint64_t fde_sub_057584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057584ULL;
}

// FDE #0771 | PC: 0x057590..0x057630 (160 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer6ResumeEv
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_057590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900A3FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057590ULL;
}

// FDE #0772 | PC: 0x057630..0x05763c (12 B) | Symbol: sub_057630
// EN: AArch64 prologue [cbz x0, #0x57638; b #0x516f8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57638; b #0x516f8; ret]
uint64_t fde_sub_057630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE831ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057630ULL;
}

// FDE #0773 | PC: 0x05763c..0x05764c (16 B) | Symbol: sub_05763c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x708; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x708; b #0x8d518]
uint64_t fde_sub_05763c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05763CULL;
}

// FDE #0774 | PC: 0x05764c..0x057664 (24 B) | Symbol: sub_05764c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5763c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5763c; mov x0, x19]
uint64_t fde_sub_05764c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05764CULL;
}

// FDE #0775 | PC: 0x057664..0x057670 (12 B) | Symbol: sub_057664
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x57630] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x57630]
uint64_t fde_sub_057664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057664ULL;
}

// FDE #0776 | PC: 0x057670..0x057710 (160 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer4StopEv
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_057670(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900A3FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057670ULL;
}

// FDE #0777 | PC: 0x057710..0x05771c (12 B) | Symbol: sub_057710
// EN: AArch64 prologue [cbz x0, #0x57718; b #0x51794; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57718; b #0x51794; ret]
uint64_t fde_sub_057710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE820ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057710ULL;
}

// FDE #0778 | PC: 0x05771c..0x05772c (16 B) | Symbol: sub_05771c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x730; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x730; b #0x8d518]
uint64_t fde_sub_05771c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05771CULL;
}

// FDE #0779 | PC: 0x05772c..0x057744 (24 B) | Symbol: sub_05772c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5771c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5771c; mov x0, x19]
uint64_t fde_sub_05772c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05772CULL;
}

// FDE #0780 | PC: 0x057744..0x057750 (12 B) | Symbol: sub_057744
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x57710] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x57710]
uint64_t fde_sub_057744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057744ULL;
}

// FDE #0781 | PC: 0x057750..0x057810 (192 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer4SeekEd
// EN: AArch64 prologue [sub sp, sp, #0x170; str d8, [sp, #0x140]; str x28, [sp, #0x148]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str d8, [sp, #0x140]; str x28, [sp, #0x148]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_057750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00A3E8ULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057750ULL;
}

// FDE #0782 | PC: 0x057810..0x057820 (16 B) | Symbol: sub_057810
// EN: AArch64 prologue [cbz x0, #0x5781c; ldr d0, [x1]; b #0x517e0; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5781c; ldr d0, [x1]; b #0x517e0; ret]
uint64_t fde_sub_057810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD400020ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057810ULL;
}

// FDE #0783 | PC: 0x057820..0x057830 (16 B) | Symbol: sub_057820
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x758; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x758; b #0x8d518]
uint64_t fde_sub_057820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057820ULL;
}

// FDE #0784 | PC: 0x057830..0x057848 (24 B) | Symbol: sub_057830
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57820; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57820; mov x0, x19]
uint64_t fde_sub_057830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057830ULL;
}

// FDE #0785 | PC: 0x057848..0x057858 (16 B) | Symbol: sub_057848
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57810] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57810]
uint64_t fde_sub_057848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D782ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057848ULL;
}

// FDE #0786 | PC: 0x057858..0x0578a8 (80 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer11IsAnimatingEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34]
uint64_t fde_sub_057858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057858ULL;
}

// FDE #0787 | PC: 0x0578a8..0x0578d4 (44 B) | Symbol: sub_0578a8
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x578d0; ldr x8, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x578d0; ldr x8, [x8, #0x20]]
uint64_t fde_sub_0578a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0578A8ULL;
}

// FDE #0788 | PC: 0x0578d4..0x0579f0 (284 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer20SubscribeUpdateEventEi
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0578d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0578D4ULL;
}

// FDE #0789 | PC: 0x0579f0..0x0579fc (12 B) | Symbol: sub_0579f0
// EN: AArch64 prologue [cbz x0, #0x579f8; b #0x5a02c; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x579f8; b #0x5a02c; ret]
uint64_t fde_sub_0579f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400098EULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0579F0ULL;
}

// FDE #0790 | PC: 0x0579fc..0x057a0c (16 B) | Symbol: sub_0579fc
// EN: AArch64 prologue [cbz x0, #0x57a08; ldr w1, [x1]; b #0x52108; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57a08; ldr w1, [x1]; b #0x52108; ret]
uint64_t fde_sub_0579fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400021ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0579FCULL;
}

// FDE #0791 | PC: 0x057a0c..0x057a1c (16 B) | Symbol: sub_057a0c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x7d0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x7d0; b #0x8d518]
uint64_t fde_sub_057a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057A0CULL;
}

// FDE #0792 | PC: 0x057a1c..0x057a34 (24 B) | Symbol: sub_057a1c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57a0c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57a0c; mov x0, x19]
uint64_t fde_sub_057a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057A1CULL;
}

uint64_t DispatchAnimaXShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x04403cULL: return fde_sub_04403c(a0, a1, a2);
        case 0x04407cULL: return fde_sub_04407c(a0, a1, a2);
        case 0x0440fcULL: return fde_sub_0440fc(a0, a1, a2);
        case 0x044194ULL: return fde_sub_044194(a0, a1, a2);
        case 0x0441b4ULL: return fde_sub_0441b4(a0, a1, a2);
        case 0x04430cULL: return fde_sub_04430c(a0, a1, a2);
        case 0x044348ULL: return fde_sub_044348(a0, a1, a2);
        case 0x044768ULL: return fde_sub_044768(a0, a1, a2);
        case 0x04479cULL: return fde_sub_04479c(a0, a1, a2);
        case 0x0447c0ULL: return fde_sub_0447c0(a0, a1, a2);
        case 0x044830ULL: return fde_sub_044830(a0, a1, a2);
        case 0x04483cULL: return fde_sub_04483c(a0, a1, a2);
        case 0x04487cULL: return fde_sub_04487c(a0, a1, a2);
        case 0x0448acULL: return fde_sub_0448ac(a0, a1, a2);
        case 0x0448b0ULL: return fde_sub_0448b0(a0, a1, a2);
        case 0x0448c4ULL: return fde_sub_0448c4(a0, a1, a2);
        case 0x0449a8ULL: return fde_sub_0449a8(a0, a1, a2);
        case 0x0449ecULL: return fde_sub_0449ec(a0, a1, a2);
        case 0x0449fcULL: return fde_sub_0449fc(a0, a1, a2);
        case 0x044a00ULL: return fde_sub_044a00(a0, a1, a2);
        case 0x044a04ULL: return fde_sub_044a04(a0, a1, a2);
        case 0x044a08ULL: return fde_sub_044a08(a0, a1, a2);
        case 0x044a0cULL: return fde_sub_044a0c(a0, a1, a2);
        case 0x044a14ULL: return fde_sub_044a14(a0, a1, a2);
        case 0x044a54ULL: return fde_sub_044a54(a0, a1, a2);
        case 0x044a68ULL: return fde_sub_044a68(a0, a1, a2);
        case 0x044a98ULL: return fde_sub_044a98(a0, a1, a2);
        case 0x044aacULL: return fde_sub_044aac(a0, a1, a2);
        case 0x044adcULL: return fde_sub_044adc(a0, a1, a2);
        case 0x044b18ULL: return fde_sub_044b18(a0, a1, a2);
        case 0x044b30ULL: return fde_sub_044b30(a0, a1, a2);
        case 0x044b50ULL: return fde_sub_044b50(a0, a1, a2);
        case 0x044b68ULL: return fde_sub_044b68(a0, a1, a2);
        case 0x044b70ULL: return fde_sub_044b70(a0, a1, a2);
        case 0x044b98ULL: return fde_sub_044b98(a0, a1, a2);
        case 0x044bc8ULL: return fde_sub_044bc8(a0, a1, a2);
        case 0x044c10ULL: return fde_sub_044c10(a0, a1, a2);
        case 0x044c18ULL: return fde_sub_044c18(a0, a1, a2);
        case 0x044c2cULL: return fde_sub_044c2c(a0, a1, a2);
        case 0x044cacULL: return fde_sub_044cac(a0, a1, a2);
        case 0x044dacULL: return fde_sub_044dac(a0, a1, a2);
        case 0x044de0ULL: return fde_sub_044de0(a0, a1, a2);
        case 0x044e0cULL: return fde_sub_044e0c(a0, a1, a2);
        case 0x044ee4ULL: return fde_sub_044ee4(a0, a1, a2);
        case 0x044f14ULL: return fde_sub_044f14(a0, a1, a2);
        case 0x044f40ULL: return fde_sub_044f40(a0, a1, a2);
        case 0x045010ULL: return fde_sub_045010(a0, a1, a2);
        case 0x045048ULL: return fde_sub_045048(a0, a1, a2);
        case 0x045064ULL: return fde_sub_045064(a0, a1, a2);
        case 0x04509cULL: return fde_sub_04509c(a0, a1, a2);
        case 0x0450a8ULL: return fde_sub_0450a8(a0, a1, a2);
        case 0x0450acULL: return fde_sub_0450ac(a0, a1, a2);
        case 0x0451fcULL: return fde_sub_0451fc(a0, a1, a2);
        case 0x045224ULL: return fde_sub_045224(a0, a1, a2);
        case 0x045260ULL: return fde_sub_045260(a0, a1, a2);
        case 0x045264ULL: return fde_sub_045264(a0, a1, a2);
        case 0x045298ULL: return fde_sub_045298(a0, a1, a2);
        case 0x0453acULL: return fde_sub_0453ac(a0, a1, a2);
        case 0x045444ULL: return fde_sub_045444(a0, a1, a2);
        case 0x045468ULL: return fde_sub_045468(a0, a1, a2);
        case 0x045490ULL: return fde_sub_045490(a0, a1, a2);
        case 0x045498ULL: return fde_sub_045498(a0, a1, a2);
        case 0x0454d0ULL: return fde_sub_0454d0(a0, a1, a2);
        case 0x0454e8ULL: return fde_sub_0454e8(a0, a1, a2);
        case 0x045a20ULL: return fde_sub_045a20(a0, a1, a2);
        case 0x045a28ULL: return fde_sub_045a28(a0, a1, a2);
        case 0x045ae0ULL: return fde_sub_045ae0(a0, a1, a2);
        case 0x045b04ULL: return fde_sub_045b04(a0, a1, a2);
        case 0x045b1cULL: return fde_sub_045b1c(a0, a1, a2);
        case 0x045c18ULL: return fde_sub_045c18(a0, a1, a2);
        case 0x045c40ULL: return fde_sub_045c40(a0, a1, a2);
        case 0x045c58ULL: return fde_sub_045c58(a0, a1, a2);
        case 0x045e58ULL: return fde_sub_045e58(a0, a1, a2);
        case 0x045e80ULL: return fde_sub_045e80(a0, a1, a2);
        case 0x045e88ULL: return fde_sub_045e88(a0, a1, a2);
        case 0x045ea0ULL: return fde_sub_045ea0(a0, a1, a2);
        case 0x045f80ULL: return fde_sub_045f80(a0, a1, a2);
        case 0x045fbcULL: return fde_sub_045fbc(a0, a1, a2);
        case 0x045ff8ULL: return fde_sub_045ff8(a0, a1, a2);
        case 0x046028ULL: return fde_sub_046028(a0, a1, a2);
        case 0x046058ULL: return fde_sub_046058(a0, a1, a2);
        case 0x046070ULL: return fde_sub_046070(a0, a1, a2);
        case 0x0460bcULL: return fde_sub_0460bc(a0, a1, a2);
        case 0x0460d4ULL: return fde_sub_0460d4(a0, a1, a2);
        case 0x0460f0ULL: return fde_sub_0460f0(a0, a1, a2);
        case 0x046160ULL: return fde_sub_046160(a0, a1, a2);
        case 0x046168ULL: return fde_sub_046168(a0, a1, a2);
        case 0x046170ULL: return fde_sub_046170(a0, a1, a2);
        case 0x046214ULL: return fde_sub_046214(a0, a1, a2);
        case 0x0463d8ULL: return fde_sub_0463d8(a0, a1, a2);
        case 0x0463e0ULL: return fde_sub_0463e0(a0, a1, a2);
        case 0x04647cULL: return fde_sub_04647c(a0, a1, a2);
        case 0x046514ULL: return fde_sub_046514(a0, a1, a2);
        case 0x04652cULL: return fde_sub_04652c(a0, a1, a2);
        case 0x046544ULL: return fde_sub_046544(a0, a1, a2);
        case 0x046560ULL: return fde_sub_046560(a0, a1, a2);
        case 0x046588ULL: return fde_sub_046588(a0, a1, a2);
        case 0x0465a0ULL: return fde_sub_0465a0(a0, a1, a2);
        case 0x04662cULL: return fde_sub_04662c(a0, a1, a2);
        case 0x046650ULL: return fde_sub_046650(a0, a1, a2);
        case 0x04665cULL: return fde_sub_04665c(a0, a1, a2);
        case 0x046660ULL: return fde_sub_046660(a0, a1, a2);
        case 0x046664ULL: return fde_sub_046664(a0, a1, a2);
        case 0x046674ULL: return fde_sub_046674(a0, a1, a2);
        case 0x046694ULL: return fde_sub_046694(a0, a1, a2);
        case 0x046734ULL: return fde_sub_046734(a0, a1, a2);
        case 0x046744ULL: return fde_sub_046744(a0, a1, a2);
        case 0x04675cULL: return fde_sub_04675c(a0, a1, a2);
        case 0x0467a8ULL: return fde_sub_0467a8(a0, a1, a2);
        case 0x0467d0ULL: return fde_sub_0467d0(a0, a1, a2);
        case 0x0467e4ULL: return fde_sub_0467e4(a0, a1, a2);
        case 0x0467e8ULL: return fde_sub_0467e8(a0, a1, a2);
        case 0x0467f8ULL: return fde_sub_0467f8(a0, a1, a2);
        case 0x04682cULL: return fde_sub_04682c(a0, a1, a2);
        case 0x046964ULL: return fde_sub_046964(a0, a1, a2);
        case 0x04696cULL: return fde_sub_04696c(a0, a1, a2);
        case 0x046990ULL: return fde_sub_046990(a0, a1, a2);
        case 0x0469a0ULL: return fde_sub_0469a0(a0, a1, a2);
        case 0x0469b8ULL: return fde_sub_0469b8(a0, a1, a2);
        case 0x046b60ULL: return fde_sub_046b60(a0, a1, a2);
        case 0x046ba0ULL: return fde_sub_046ba0(a0, a1, a2);
        case 0x046bd0ULL: return fde_sub_046bd0(a0, a1, a2);
        case 0x046bdcULL: return fde_sub_046bdc(a0, a1, a2);
        case 0x046c54ULL: return fde_sub_046c54(a0, a1, a2);
        case 0x046c68ULL: return fde_sub_046c68(a0, a1, a2);
        case 0x046c80ULL: return fde_sub_046c80(a0, a1, a2);
        case 0x046cf4ULL: return fde_sub_046cf4(a0, a1, a2);
        case 0x046d58ULL: return fde_sub_046d58(a0, a1, a2);
        case 0x046d70ULL: return fde_sub_046d70(a0, a1, a2);
        case 0x046e10ULL: return fde_sub_046e10(a0, a1, a2);
        case 0x046e54ULL: return fde_sub_046e54(a0, a1, a2);
        case 0x046f08ULL: return fde_sub_046f08(a0, a1, a2);
        case 0x046f8cULL: return fde_sub_046f8c(a0, a1, a2);
        case 0x046fc0ULL: return fde_sub_046fc0(a0, a1, a2);
        case 0x046ff4ULL: return fde_sub_046ff4(a0, a1, a2);
        case 0x04702cULL: return fde_sub_04702c(a0, a1, a2);
        case 0x0470b8ULL: return fde_sub_0470b8(a0, a1, a2);
        case 0x0470d4ULL: return fde_sub_0470d4(a0, a1, a2);
        case 0x047164ULL: return fde_sub_047164(a0, a1, a2);
        case 0x04722cULL: return fde_sub_04722c(a0, a1, a2);
        case 0x0472f0ULL: return fde_sub_0472f0(a0, a1, a2);
        case 0x0477fcULL: return fde_sub_0477fc(a0, a1, a2);
        case 0x04796cULL: return fde_sub_04796c(a0, a1, a2);
        case 0x047b64ULL: return fde_sub_047b64(a0, a1, a2);
        case 0x047b84ULL: return fde_sub_047b84(a0, a1, a2);
        case 0x047bc8ULL: return fde_sub_047bc8(a0, a1, a2);
        case 0x047c0cULL: return fde_sub_047c0c(a0, a1, a2);
        case 0x047c4cULL: return fde_sub_047c4c(a0, a1, a2);
        case 0x047c64ULL: return fde_sub_047c64(a0, a1, a2);
        case 0x047ce0ULL: return fde_sub_047ce0(a0, a1, a2);
        case 0x047d20ULL: return fde_sub_047d20(a0, a1, a2);
        case 0x047d38ULL: return fde_sub_047d38(a0, a1, a2);
        case 0x047df8ULL: return fde_sub_047df8(a0, a1, a2);
        case 0x047dfcULL: return fde_sub_047dfc(a0, a1, a2);
        case 0x047e4cULL: return fde_sub_047e4c(a0, a1, a2);
        case 0x047f90ULL: return fde_sub_047f90(a0, a1, a2);
        case 0x047fbcULL: return fde_sub_047fbc(a0, a1, a2);
        case 0x047ff4ULL: return fde_sub_047ff4(a0, a1, a2);
        case 0x048010ULL: return fde_sub_048010(a0, a1, a2);
        case 0x048030ULL: return fde_sub_048030(a0, a1, a2);
        case 0x04808cULL: return fde_sub_04808c(a0, a1, a2);
        case 0x048098ULL: return fde_sub_048098(a0, a1, a2);
        case 0x0480bcULL: return fde_sub_0480bc(a0, a1, a2);
        case 0x0480e8ULL: return fde_sub_0480e8(a0, a1, a2);
        case 0x048118ULL: return fde_sub_048118(a0, a1, a2);
        case 0x048130ULL: return fde_sub_048130(a0, a1, a2);
        case 0x048150ULL: return fde_sub_048150(a0, a1, a2);
        case 0x048164ULL: return fde_sub_048164(a0, a1, a2);
        case 0x04816cULL: return fde_sub_04816c(a0, a1, a2);
        case 0x048190ULL: return fde_sub_048190(a0, a1, a2);
        case 0x0481b8ULL: return fde_sub_0481b8(a0, a1, a2);
        case 0x0481c0ULL: return fde_sub_0481c0(a0, a1, a2);
        case 0x048258ULL: return fde_sub_048258(a0, a1, a2);
        case 0x048270ULL: return fde_sub_048270(a0, a1, a2);
        case 0x0484a8ULL: return fde_sub_0484a8(a0, a1, a2);
        case 0x048588ULL: return fde_sub_048588(a0, a1, a2);
        case 0x048624ULL: return fde_sub_048624(a0, a1, a2);
        case 0x0486b4ULL: return fde_sub_0486b4(a0, a1, a2);
        case 0x048774ULL: return fde_sub_048774(a0, a1, a2);
        case 0x0488d0ULL: return fde_sub_0488d0(a0, a1, a2);
        case 0x048d20ULL: return fde_sub_048d20(a0, a1, a2);
        case 0x048d40ULL: return fde_sub_048d40(a0, a1, a2);
        case 0x048d4cULL: return fde_sub_048d4c(a0, a1, a2);
        case 0x048d74ULL: return fde_sub_048d74(a0, a1, a2);
        case 0x048d7cULL: return fde_sub_048d7c(a0, a1, a2);
        case 0x048d8cULL: return fde_sub_048d8c(a0, a1, a2);
        case 0x048da0ULL: return fde_sub_048da0(a0, a1, a2);
        case 0x048da4ULL: return fde_sub_048da4(a0, a1, a2);
        case 0x048db4ULL: return fde_sub_048db4(a0, a1, a2);
        case 0x048de4ULL: return fde_sub_048de4(a0, a1, a2);
        case 0x048decULL: return fde_sub_048dec(a0, a1, a2);
        case 0x048e74ULL: return fde_sub_048e74(a0, a1, a2);
        case 0x048e8cULL: return fde_sub_048e8c(a0, a1, a2);
        case 0x048ea4ULL: return fde_sub_048ea4(a0, a1, a2);
        case 0x049124ULL: return fde_sub_049124(a0, a1, a2);
        case 0x049154ULL: return fde_sub_049154(a0, a1, a2);
        case 0x049198ULL: return fde_sub_049198(a0, a1, a2);
        case 0x049290ULL: return fde_sub_049290(a0, a1, a2);
        case 0x049298ULL: return fde_sub_049298(a0, a1, a2);
        case 0x049314ULL: return fde_sub_049314(a0, a1, a2);
        case 0x04932cULL: return fde_sub_04932c(a0, a1, a2);
        case 0x049350ULL: return fde_sub_049350(a0, a1, a2);
        case 0x049430ULL: return fde_sub_049430(a0, a1, a2);
        case 0x049454ULL: return fde_sub_049454(a0, a1, a2);
        case 0x049464ULL: return fde_sub_049464(a0, a1, a2);
        case 0x04947cULL: return fde_sub_04947c(a0, a1, a2);
        case 0x04948cULL: return fde_sub_04948c(a0, a1, a2);
        case 0x0494e8ULL: return fde_sub_0494e8(a0, a1, a2);
        case 0x049680ULL: return fde_sub_049680(a0, a1, a2);
        case 0x0496f0ULL: return fde_sub_0496f0(a0, a1, a2);
        case 0x0496f8ULL: return fde_sub_0496f8(a0, a1, a2);
        case 0x0497b4ULL: return fde_sub_0497b4(a0, a1, a2);
        case 0x0497ecULL: return fde_sub_0497ec(a0, a1, a2);
        case 0x049848ULL: return fde_sub_049848(a0, a1, a2);
        case 0x049864ULL: return fde_sub_049864(a0, a1, a2);
        case 0x049870ULL: return fde_sub_049870(a0, a1, a2);
        case 0x049898ULL: return fde_sub_049898(a0, a1, a2);
        case 0x0498a0ULL: return fde_sub_0498a0(a0, a1, a2);
        case 0x0498d0ULL: return fde_sub_0498d0(a0, a1, a2);
        case 0x049920ULL: return fde_sub_049920(a0, a1, a2);
        case 0x049950ULL: return fde_sub_049950(a0, a1, a2);
        case 0x0499f0ULL: return fde_sub_0499f0(a0, a1, a2);
        case 0x049e30ULL: return fde_sub_049e30(a0, a1, a2);
        case 0x049ef0ULL: return fde_sub_049ef0(a0, a1, a2);
        case 0x049f64ULL: return fde_sub_049f64(a0, a1, a2);
        case 0x04a01cULL: return fde_sub_04a01c(a0, a1, a2);
        case 0x04a17cULL: return fde_sub_04a17c(a0, a1, a2);
        case 0x04a1acULL: return fde_sub_04a1ac(a0, a1, a2);
        case 0x04a1dcULL: return fde_sub_04a1dc(a0, a1, a2);
        case 0x04a234ULL: return fde_sub_04a234(a0, a1, a2);
        case 0x04a270ULL: return fde_sub_04a270(a0, a1, a2);
        case 0x04a290ULL: return fde_sub_04a290(a0, a1, a2);
        case 0x04a2a8ULL: return fde_sub_04a2a8(a0, a1, a2);
        case 0x04a380ULL: return fde_sub_04a380(a0, a1, a2);
        case 0x04a3dcULL: return fde_sub_04a3dc(a0, a1, a2);
        case 0x04a5c4ULL: return fde_sub_04a5c4(a0, a1, a2);
        case 0x04a8a0ULL: return fde_sub_04a8a0(a0, a1, a2);
        case 0x04a8dcULL: return fde_sub_04a8dc(a0, a1, a2);
        case 0x04a950ULL: return fde_sub_04a950(a0, a1, a2);
        case 0x04aa0cULL: return fde_sub_04aa0c(a0, a1, a2);
        case 0x04aa5cULL: return fde_sub_04aa5c(a0, a1, a2);
        case 0x04aaccULL: return fde_sub_04aacc(a0, a1, a2);
        case 0x04aaf4ULL: return fde_sub_04aaf4(a0, a1, a2);
        case 0x04aaf8ULL: return fde_sub_04aaf8(a0, a1, a2);
        case 0x04ab18ULL: return fde_sub_04ab18(a0, a1, a2);
        case 0x04ab30ULL: return fde_sub_04ab30(a0, a1, a2);
        case 0x04ac20ULL: return fde_sub_04ac20(a0, a1, a2);
        case 0x04ac34ULL: return fde_sub_04ac34(a0, a1, a2);
        case 0x04ac38ULL: return fde_sub_04ac38(a0, a1, a2);
        case 0x04acccULL: return fde_sub_04accc(a0, a1, a2);
        case 0x04ad18ULL: return fde_sub_04ad18(a0, a1, a2);
        case 0x04ad44ULL: return fde_sub_04ad44(a0, a1, a2);
        case 0x04adb0ULL: return fde_sub_04adb0(a0, a1, a2);
        case 0x04ae44ULL: return fde_sub_04ae44(a0, a1, a2);
        case 0x04af8cULL: return fde_sub_04af8c(a0, a1, a2);
        case 0x04b010ULL: return fde_sub_04b010(a0, a1, a2);
        case 0x04b0e8ULL: return fde_sub_04b0e8(a0, a1, a2);
        case 0x04b11cULL: return fde_sub_04b11c(a0, a1, a2);
        case 0x04b1f0ULL: return fde_sub_04b1f0(a0, a1, a2);
        case 0x04b200ULL: return fde_sub_04b200(a0, a1, a2);
        case 0x04b218ULL: return fde_sub_04b218(a0, a1, a2);
        case 0x04b21cULL: return fde_sub_04b21c(a0, a1, a2);
        case 0x04b220ULL: return fde_sub_04b220(a0, a1, a2);
        case 0x04b240ULL: return fde_sub_04b240(a0, a1, a2);
        case 0x04b248ULL: return fde_sub_04b248(a0, a1, a2);
        case 0x04b264ULL: return fde_sub_04b264(a0, a1, a2);
        case 0x04b278ULL: return fde_sub_04b278(a0, a1, a2);
        case 0x04b288ULL: return fde_sub_04b288(a0, a1, a2);
        case 0x04b2b0ULL: return fde_sub_04b2b0(a0, a1, a2);
        case 0x04b2c8ULL: return fde_sub_04b2c8(a0, a1, a2);
        case 0x04b2d8ULL: return fde_sub_04b2d8(a0, a1, a2);
        case 0x04b2e8ULL: return fde_sub_04b2e8(a0, a1, a2);
        case 0x04b3d0ULL: return fde_sub_04b3d0(a0, a1, a2);
        case 0x04b4d8ULL: return fde_sub_04b4d8(a0, a1, a2);
        case 0x04b524ULL: return fde_sub_04b524(a0, a1, a2);
        case 0x04b558ULL: return fde_sub_04b558(a0, a1, a2);
        case 0x04b758ULL: return fde_sub_04b758(a0, a1, a2);
        case 0x04b780ULL: return fde_sub_04b780(a0, a1, a2);
        case 0x04b798ULL: return fde_sub_04b798(a0, a1, a2);
        case 0x04b7b4ULL: return fde_sub_04b7b4(a0, a1, a2);
        case 0x04b7c4ULL: return fde_sub_04b7c4(a0, a1, a2);
        case 0x04b7dcULL: return fde_sub_04b7dc(a0, a1, a2);
        case 0x04b7ecULL: return fde_sub_04b7ec(a0, a1, a2);
        case 0x04b7f4ULL: return fde_sub_04b7f4(a0, a1, a2);
        case 0x04b840ULL: return fde_sub_04b840(a0, a1, a2);
        case 0x04ba18ULL: return fde_sub_04ba18(a0, a1, a2);
        case 0x04ba60ULL: return fde_sub_04ba60(a0, a1, a2);
        case 0x04ba78ULL: return fde_sub_04ba78(a0, a1, a2);
        case 0x04baa0ULL: return fde_sub_04baa0(a0, a1, a2);
        case 0x04bab0ULL: return fde_sub_04bab0(a0, a1, a2);
        case 0x04bac8ULL: return fde_sub_04bac8(a0, a1, a2);
        case 0x04bad8ULL: return fde_sub_04bad8(a0, a1, a2);
        case 0x04be8cULL: return fde_sub_04be8c(a0, a1, a2);
        case 0x04beccULL: return fde_sub_04becc(a0, a1, a2);
        case 0x04bee4ULL: return fde_sub_04bee4(a0, a1, a2);
        case 0x04bf04ULL: return fde_sub_04bf04(a0, a1, a2);
        case 0x04bf14ULL: return fde_sub_04bf14(a0, a1, a2);
        case 0x04bf2cULL: return fde_sub_04bf2c(a0, a1, a2);
        case 0x04bf3cULL: return fde_sub_04bf3c(a0, a1, a2);
        case 0x04c158ULL: return fde_sub_04c158(a0, a1, a2);
        case 0x04c4d4ULL: return fde_sub_04c4d4(a0, a1, a2);
        case 0x04c568ULL: return fde_sub_04c568(a0, a1, a2);
        case 0x04c5ecULL: return fde_sub_04c5ec(a0, a1, a2);
        case 0x04c61cULL: return fde_sub_04c61c(a0, a1, a2);
        case 0x04c700ULL: return fde_sub_04c700(a0, a1, a2);
        case 0x04c718ULL: return fde_sub_04c718(a0, a1, a2);
        case 0x04c720ULL: return fde_sub_04c720(a0, a1, a2);
        case 0x04c750ULL: return fde_sub_04c750(a0, a1, a2);
        case 0x04c784ULL: return fde_sub_04c784(a0, a1, a2);
        case 0x04c7e0ULL: return fde_sub_04c7e0(a0, a1, a2);
        case 0x04c7f8ULL: return fde_sub_04c7f8(a0, a1, a2);
        case 0x04c82cULL: return fde_sub_04c82c(a0, a1, a2);
        case 0x04c844ULL: return fde_sub_04c844(a0, a1, a2);
        case 0x04c84cULL: return fde_sub_04c84c(a0, a1, a2);
        case 0x04c868ULL: return fde_sub_04c868(a0, a1, a2);
        case 0x04c874ULL: return fde_sub_04c874(a0, a1, a2);
        case 0x04c87cULL: return fde_sub_04c87c(a0, a1, a2);
        case 0x04c9c8ULL: return fde_sub_04c9c8(a0, a1, a2);
        case 0x04c9e4ULL: return fde_sub_04c9e4(a0, a1, a2);
        case 0x04c9fcULL: return fde_sub_04c9fc(a0, a1, a2);
        case 0x04ca14ULL: return fde_sub_04ca14(a0, a1, a2);
        case 0x04cba4ULL: return fde_sub_04cba4(a0, a1, a2);
        case 0x04cbbcULL: return fde_sub_04cbbc(a0, a1, a2);
        case 0x04cbd4ULL: return fde_sub_04cbd4(a0, a1, a2);
        case 0x04cc14ULL: return fde_sub_04cc14(a0, a1, a2);
        case 0x04cc24ULL: return fde_sub_04cc24(a0, a1, a2);
        case 0x04cc4cULL: return fde_sub_04cc4c(a0, a1, a2);
        case 0x04cd64ULL: return fde_sub_04cd64(a0, a1, a2);
        case 0x04ceecULL: return fde_sub_04ceec(a0, a1, a2);
        case 0x04cf70ULL: return fde_sub_04cf70(a0, a1, a2);
        case 0x04d180ULL: return fde_sub_04d180(a0, a1, a2);
        case 0x04d2a4ULL: return fde_sub_04d2a4(a0, a1, a2);
        case 0x04d2c4ULL: return fde_sub_04d2c4(a0, a1, a2);
        case 0x04d2f8ULL: return fde_sub_04d2f8(a0, a1, a2);
        case 0x04d33cULL: return fde_sub_04d33c(a0, a1, a2);
        case 0x04d36cULL: return fde_sub_04d36c(a0, a1, a2);
        case 0x04d384ULL: return fde_sub_04d384(a0, a1, a2);
        case 0x04d3acULL: return fde_sub_04d3ac(a0, a1, a2);
        case 0x04d3f8ULL: return fde_sub_04d3f8(a0, a1, a2);
        case 0x04d480ULL: return fde_sub_04d480(a0, a1, a2);
        case 0x04d4c0ULL: return fde_sub_04d4c0(a0, a1, a2);
        case 0x04d5a0ULL: return fde_sub_04d5a0(a0, a1, a2);
        case 0x04d5acULL: return fde_sub_04d5ac(a0, a1, a2);
        case 0x04d6ccULL: return fde_sub_04d6cc(a0, a1, a2);
        case 0x04d744ULL: return fde_sub_04d744(a0, a1, a2);
        case 0x04d764ULL: return fde_sub_04d764(a0, a1, a2);
        case 0x04d7f0ULL: return fde_sub_04d7f0(a0, a1, a2);
        case 0x04d844ULL: return fde_sub_04d844(a0, a1, a2);
        case 0x04d90cULL: return fde_sub_04d90c(a0, a1, a2);
        case 0x04d97cULL: return fde_sub_04d97c(a0, a1, a2);
        case 0x04d994ULL: return fde_sub_04d994(a0, a1, a2);
        case 0x04d9b4ULL: return fde_sub_04d9b4(a0, a1, a2);
        case 0x04d9ccULL: return fde_sub_04d9cc(a0, a1, a2);
        case 0x04d9d4ULL: return fde_sub_04d9d4(a0, a1, a2);
        case 0x04da9cULL: return fde_sub_04da9c(a0, a1, a2);
        case 0x04db0cULL: return fde_sub_04db0c(a0, a1, a2);
        case 0x04db54ULL: return fde_sub_04db54(a0, a1, a2);
        case 0x04dbc0ULL: return fde_sub_04dbc0(a0, a1, a2);
        case 0x04dc78ULL: return fde_sub_04dc78(a0, a1, a2);
        case 0x04de80ULL: return fde_sub_04de80(a0, a1, a2);
        case 0x04de98ULL: return fde_sub_04de98(a0, a1, a2);
        case 0x04df24ULL: return fde_sub_04df24(a0, a1, a2);
        case 0x04df90ULL: return fde_sub_04df90(a0, a1, a2);
        case 0x04dfecULL: return fde_sub_04dfec(a0, a1, a2);
        case 0x04e084ULL: return fde_sub_04e084(a0, a1, a2);
        case 0x04e150ULL: return fde_sub_04e150(a0, a1, a2);
        case 0x04e270ULL: return fde_sub_04e270(a0, a1, a2);
        case 0x04e300ULL: return fde_sub_04e300(a0, a1, a2);
        case 0x04e31cULL: return fde_sub_04e31c(a0, a1, a2);
        case 0x04e340ULL: return fde_sub_04e340(a0, a1, a2);
        case 0x04e3f8ULL: return fde_sub_04e3f8(a0, a1, a2);
        case 0x04e424ULL: return fde_sub_04e424(a0, a1, a2);
        case 0x04e53cULL: return fde_sub_04e53c(a0, a1, a2);
        case 0x04e5d0ULL: return fde_sub_04e5d0(a0, a1, a2);
        case 0x04e5fcULL: return fde_sub_04e5fc(a0, a1, a2);
        case 0x04e684ULL: return fde_sub_04e684(a0, a1, a2);
        case 0x04e76cULL: return fde_sub_04e76c(a0, a1, a2);
        case 0x04e8dcULL: return fde_sub_04e8dc(a0, a1, a2);
        case 0x04e8fcULL: return fde_sub_04e8fc(a0, a1, a2);
        case 0x04e914ULL: return fde_sub_04e914(a0, a1, a2);
        case 0x04e91cULL: return fde_sub_04e91c(a0, a1, a2);
        case 0x04e944ULL: return fde_sub_04e944(a0, a1, a2);
        case 0x04e964ULL: return fde_sub_04e964(a0, a1, a2);
        case 0x04e97cULL: return fde_sub_04e97c(a0, a1, a2);
        case 0x04e980ULL: return fde_sub_04e980(a0, a1, a2);
        case 0x04e9d8ULL: return fde_sub_04e9d8(a0, a1, a2);
        case 0x04ea00ULL: return fde_sub_04ea00(a0, a1, a2);
        case 0x04ea24ULL: return fde_sub_04ea24(a0, a1, a2);
        case 0x04ea54ULL: return fde_sub_04ea54(a0, a1, a2);
        case 0x04ea6cULL: return fde_sub_04ea6c(a0, a1, a2);
        case 0x04ea84ULL: return fde_sub_04ea84(a0, a1, a2);
        case 0x04ea9cULL: return fde_sub_04ea9c(a0, a1, a2);
        case 0x04eaa4ULL: return fde_sub_04eaa4(a0, a1, a2);
        case 0x04eab4ULL: return fde_sub_04eab4(a0, a1, a2);
        case 0x04eac8ULL: return fde_sub_04eac8(a0, a1, a2);
        case 0x04f8d4ULL: return fde_sub_04f8d4(a0, a1, a2);
        case 0x04f98cULL: return fde_sub_04f98c(a0, a1, a2);
        case 0x04fa3cULL: return fde_sub_04fa3c(a0, a1, a2);
        case 0x04fa7cULL: return fde_sub_04fa7c(a0, a1, a2);
        case 0x04fb48ULL: return fde_sub_04fb48(a0, a1, a2);
        case 0x04fb7cULL: return fde_sub_04fb7c(a0, a1, a2);
        case 0x04fb84ULL: return fde_sub_04fb84(a0, a1, a2);
        case 0x04fd44ULL: return fde_sub_04fd44(a0, a1, a2);
        case 0x04fdc8ULL: return fde_sub_04fdc8(a0, a1, a2);
        case 0x04fe9cULL: return fde_sub_04fe9c(a0, a1, a2);
        case 0x04fea4ULL: return fde_sub_04fea4(a0, a1, a2);
        case 0x050078ULL: return fde_sub_050078(a0, a1, a2);
        case 0x0500c0ULL: return fde_sub_0500c0(a0, a1, a2);
        case 0x0500ecULL: return fde_sub_0500ec(a0, a1, a2);
        case 0x05018cULL: return fde_sub_05018c(a0, a1, a2);
        case 0x050238ULL: return fde_sub_050238(a0, a1, a2);
        case 0x0502b0ULL: return fde_sub_0502b0(a0, a1, a2);
        case 0x050630ULL: return fde_sub_050630(a0, a1, a2);
        case 0x050660ULL: return fde_sub_050660(a0, a1, a2);
        case 0x05067cULL: return fde_sub_05067c(a0, a1, a2);
        case 0x050698ULL: return fde_sub_050698(a0, a1, a2);
        case 0x0506a0ULL: return fde_sub_0506a0(a0, a1, a2);
        case 0x0506c4ULL: return fde_sub_0506c4(a0, a1, a2);
        case 0x0506ecULL: return fde_sub_0506ec(a0, a1, a2);
        case 0x0507d8ULL: return fde_sub_0507d8(a0, a1, a2);
        case 0x05081cULL: return fde_sub_05081c(a0, a1, a2);
        case 0x050860ULL: return fde_sub_050860(a0, a1, a2);
        case 0x05088cULL: return fde_sub_05088c(a0, a1, a2);
        case 0x050914ULL: return fde_sub_050914(a0, a1, a2);
        case 0x0509bcULL: return fde_sub_0509bc(a0, a1, a2);
        case 0x0509ccULL: return fde_sub_0509cc(a0, a1, a2);
        case 0x0509e4ULL: return fde_sub_0509e4(a0, a1, a2);
        case 0x050a78ULL: return fde_sub_050a78(a0, a1, a2);
        case 0x050ac0ULL: return fde_sub_050ac0(a0, a1, a2);
        case 0x050ad0ULL: return fde_sub_050ad0(a0, a1, a2);
        case 0x050ae8ULL: return fde_sub_050ae8(a0, a1, a2);
        case 0x050c5cULL: return fde_sub_050c5c(a0, a1, a2);
        case 0x050d7cULL: return fde_sub_050d7c(a0, a1, a2);
        case 0x050df8ULL: return fde_sub_050df8(a0, a1, a2);
        case 0x0511f0ULL: return fde_sub_0511f0(a0, a1, a2);
        case 0x05120cULL: return fde_sub_05120c(a0, a1, a2);
        case 0x051254ULL: return fde_sub_051254(a0, a1, a2);
        case 0x0512d8ULL: return fde_sub_0512d8(a0, a1, a2);
        case 0x0512e8ULL: return fde_sub_0512e8(a0, a1, a2);
        case 0x051308ULL: return fde_sub_051308(a0, a1, a2);
        case 0x051320ULL: return fde_sub_051320(a0, a1, a2);
        case 0x051328ULL: return fde_sub_051328(a0, a1, a2);
        case 0x051348ULL: return fde_sub_051348(a0, a1, a2);
        case 0x051380ULL: return fde_sub_051380(a0, a1, a2);
        case 0x0513a8ULL: return fde_sub_0513a8(a0, a1, a2);
        case 0x051460ULL: return fde_sub_051460(a0, a1, a2);
        case 0x05149cULL: return fde_sub_05149c(a0, a1, a2);
        case 0x0514a8ULL: return fde_sub_0514a8(a0, a1, a2);
        case 0x0514b0ULL: return fde_sub_0514b0(a0, a1, a2);
        case 0x0514b8ULL: return fde_sub_0514b8(a0, a1, a2);
        case 0x0514c8ULL: return fde_sub_0514c8(a0, a1, a2);
        case 0x0514e0ULL: return fde_sub_0514e0(a0, a1, a2);
        case 0x0514e8ULL: return fde_sub_0514e8(a0, a1, a2);
        case 0x051580ULL: return fde_sub_051580(a0, a1, a2);
        case 0x051584ULL: return fde_sub_051584(a0, a1, a2);
        case 0x0515a8ULL: return fde_sub_0515a8(a0, a1, a2);
        case 0x0515c8ULL: return fde_sub_0515c8(a0, a1, a2);
        case 0x05162cULL: return fde_sub_05162c(a0, a1, a2);
        case 0x0516f4ULL: return fde_sub_0516f4(a0, a1, a2);
        case 0x0516f8ULL: return fde_sub_0516f8(a0, a1, a2);
        case 0x051794ULL: return fde_sub_051794(a0, a1, a2);
        case 0x0517e0ULL: return fde_sub_0517e0(a0, a1, a2);
        case 0x051858ULL: return fde_sub_051858(a0, a1, a2);
        case 0x051b80ULL: return fde_sub_051b80(a0, a1, a2);
        case 0x051c68ULL: return fde_sub_051c68(a0, a1, a2);
        case 0x051c84ULL: return fde_sub_051c84(a0, a1, a2);
        case 0x051d20ULL: return fde_sub_051d20(a0, a1, a2);
        case 0x051d70ULL: return fde_sub_051d70(a0, a1, a2);
        case 0x051d84ULL: return fde_sub_051d84(a0, a1, a2);
        case 0x051da4ULL: return fde_sub_051da4(a0, a1, a2);
        case 0x051db8ULL: return fde_sub_051db8(a0, a1, a2);
        case 0x051df4ULL: return fde_sub_051df4(a0, a1, a2);
        case 0x051efcULL: return fde_sub_051efc(a0, a1, a2);
        case 0x051f34ULL: return fde_sub_051f34(a0, a1, a2);
        case 0x051f44ULL: return fde_sub_051f44(a0, a1, a2);
        case 0x051f5cULL: return fde_sub_051f5c(a0, a1, a2);
        case 0x051f64ULL: return fde_sub_051f64(a0, a1, a2);
        case 0x05207cULL: return fde_sub_05207c(a0, a1, a2);
        case 0x0520d8ULL: return fde_sub_0520d8(a0, a1, a2);
        case 0x0520e8ULL: return fde_sub_0520e8(a0, a1, a2);
        case 0x052100ULL: return fde_sub_052100(a0, a1, a2);
        case 0x052108ULL: return fde_sub_052108(a0, a1, a2);
        case 0x052164ULL: return fde_sub_052164(a0, a1, a2);
        case 0x05216cULL: return fde_sub_05216c(a0, a1, a2);
        case 0x0521e0ULL: return fde_sub_0521e0(a0, a1, a2);
        case 0x0521ecULL: return fde_sub_0521ec(a0, a1, a2);
        case 0x052204ULL: return fde_sub_052204(a0, a1, a2);
        case 0x052244ULL: return fde_sub_052244(a0, a1, a2);
        case 0x052314ULL: return fde_sub_052314(a0, a1, a2);
        case 0x052400ULL: return fde_sub_052400(a0, a1, a2);
        case 0x0524e0ULL: return fde_sub_0524e0(a0, a1, a2);
        case 0x052518ULL: return fde_sub_052518(a0, a1, a2);
        case 0x052584ULL: return fde_sub_052584(a0, a1, a2);
        case 0x0525bcULL: return fde_sub_0525bc(a0, a1, a2);
        case 0x0525d4ULL: return fde_sub_0525d4(a0, a1, a2);
        case 0x05267cULL: return fde_sub_05267c(a0, a1, a2);
        case 0x05268cULL: return fde_sub_05268c(a0, a1, a2);
        case 0x05269cULL: return fde_sub_05269c(a0, a1, a2);
        case 0x0526b4ULL: return fde_sub_0526b4(a0, a1, a2);
        case 0x0526c0ULL: return fde_sub_0526c0(a0, a1, a2);
        case 0x0527a4ULL: return fde_sub_0527a4(a0, a1, a2);
        case 0x0527b8ULL: return fde_sub_0527b8(a0, a1, a2);
        case 0x0527c8ULL: return fde_sub_0527c8(a0, a1, a2);
        case 0x0527e0ULL: return fde_sub_0527e0(a0, a1, a2);
        case 0x0527f0ULL: return fde_sub_0527f0(a0, a1, a2);
        case 0x0528b8ULL: return fde_sub_0528b8(a0, a1, a2);
        case 0x0528c8ULL: return fde_sub_0528c8(a0, a1, a2);
        case 0x0528d8ULL: return fde_sub_0528d8(a0, a1, a2);
        case 0x0528f0ULL: return fde_sub_0528f0(a0, a1, a2);
        case 0x052900ULL: return fde_sub_052900(a0, a1, a2);
        case 0x0529a8ULL: return fde_sub_0529a8(a0, a1, a2);
        case 0x0529b4ULL: return fde_sub_0529b4(a0, a1, a2);
        case 0x0529c4ULL: return fde_sub_0529c4(a0, a1, a2);
        case 0x0529dcULL: return fde_sub_0529dc(a0, a1, a2);
        case 0x0529e8ULL: return fde_sub_0529e8(a0, a1, a2);
        case 0x052a90ULL: return fde_sub_052a90(a0, a1, a2);
        case 0x052aa0ULL: return fde_sub_052aa0(a0, a1, a2);
        case 0x052ab0ULL: return fde_sub_052ab0(a0, a1, a2);
        case 0x052ac8ULL: return fde_sub_052ac8(a0, a1, a2);
        case 0x052ad4ULL: return fde_sub_052ad4(a0, a1, a2);
        case 0x052ba8ULL: return fde_sub_052ba8(a0, a1, a2);
        case 0x052bb4ULL: return fde_sub_052bb4(a0, a1, a2);
        case 0x052bb8ULL: return fde_sub_052bb8(a0, a1, a2);
        case 0x052bd0ULL: return fde_sub_052bd0(a0, a1, a2);
        case 0x052be0ULL: return fde_sub_052be0(a0, a1, a2);
        case 0x052bf8ULL: return fde_sub_052bf8(a0, a1, a2);
        case 0x052c08ULL: return fde_sub_052c08(a0, a1, a2);
        case 0x052cdcULL: return fde_sub_052cdc(a0, a1, a2);
        case 0x052cf0ULL: return fde_sub_052cf0(a0, a1, a2);
        case 0x052d00ULL: return fde_sub_052d00(a0, a1, a2);
        case 0x052d18ULL: return fde_sub_052d18(a0, a1, a2);
        case 0x052d28ULL: return fde_sub_052d28(a0, a1, a2);
        case 0x052d30ULL: return fde_sub_052d30(a0, a1, a2);
        case 0x052d34ULL: return fde_sub_052d34(a0, a1, a2);
        case 0x052d40ULL: return fde_sub_052d40(a0, a1, a2);
        case 0x052e08ULL: return fde_sub_052e08(a0, a1, a2);
        case 0x052e20ULL: return fde_sub_052e20(a0, a1, a2);
        case 0x052e30ULL: return fde_sub_052e30(a0, a1, a2);
        case 0x052e48ULL: return fde_sub_052e48(a0, a1, a2);
        case 0x052e58ULL: return fde_sub_052e58(a0, a1, a2);
        case 0x052e60ULL: return fde_sub_052e60(a0, a1, a2);
        case 0x052e9cULL: return fde_sub_052e9c(a0, a1, a2);
        case 0x052eb4ULL: return fde_sub_052eb4(a0, a1, a2);
        case 0x052ebcULL: return fde_sub_052ebc(a0, a1, a2);
        case 0x052ec4ULL: return fde_sub_052ec4(a0, a1, a2);
        case 0x052eccULL: return fde_sub_052ecc(a0, a1, a2);
        case 0x052ed4ULL: return fde_sub_052ed4(a0, a1, a2);
        case 0x0531ecULL: return fde_sub_0531ec(a0, a1, a2);
        case 0x0531f4ULL: return fde_sub_0531f4(a0, a1, a2);
        case 0x053874ULL: return fde_sub_053874(a0, a1, a2);
        case 0x05389cULL: return fde_sub_05389c(a0, a1, a2);
        case 0x0538f4ULL: return fde_sub_0538f4(a0, a1, a2);
        case 0x05390cULL: return fde_sub_05390c(a0, a1, a2);
        case 0x053970ULL: return fde_sub_053970(a0, a1, a2);
        case 0x053988ULL: return fde_sub_053988(a0, a1, a2);
        case 0x0539a4ULL: return fde_sub_0539a4(a0, a1, a2);
        case 0x0539c4ULL: return fde_sub_0539c4(a0, a1, a2);
        case 0x0539dcULL: return fde_sub_0539dc(a0, a1, a2);
        case 0x0539ecULL: return fde_sub_0539ec(a0, a1, a2);
        case 0x053a04ULL: return fde_sub_053a04(a0, a1, a2);
        case 0x053a14ULL: return fde_sub_053a14(a0, a1, a2);
        case 0x053a24ULL: return fde_sub_053a24(a0, a1, a2);
        case 0x053a3cULL: return fde_sub_053a3c(a0, a1, a2);
        case 0x053a4cULL: return fde_sub_053a4c(a0, a1, a2);
        case 0x053a6cULL: return fde_sub_053a6c(a0, a1, a2);
        case 0x053a84ULL: return fde_sub_053a84(a0, a1, a2);
        case 0x053a8cULL: return fde_sub_053a8c(a0, a1, a2);
        case 0x053ab0ULL: return fde_sub_053ab0(a0, a1, a2);
        case 0x053ad0ULL: return fde_sub_053ad0(a0, a1, a2);
        case 0x053ae8ULL: return fde_sub_053ae8(a0, a1, a2);
        case 0x053b9cULL: return fde_sub_053b9c(a0, a1, a2);
        case 0x053bf8ULL: return fde_sub_053bf8(a0, a1, a2);
        case 0x053c18ULL: return fde_sub_053c18(a0, a1, a2);
        case 0x053c30ULL: return fde_sub_053c30(a0, a1, a2);
        case 0x053d48ULL: return fde_sub_053d48(a0, a1, a2);
        case 0x053d54ULL: return fde_sub_053d54(a0, a1, a2);
        case 0x053d60ULL: return fde_sub_053d60(a0, a1, a2);
        case 0x053d70ULL: return fde_sub_053d70(a0, a1, a2);
        case 0x053d88ULL: return fde_sub_053d88(a0, a1, a2);
        case 0x053d94ULL: return fde_sub_053d94(a0, a1, a2);
        case 0x053da4ULL: return fde_sub_053da4(a0, a1, a2);
        case 0x053dbcULL: return fde_sub_053dbc(a0, a1, a2);
        case 0x053dc8ULL: return fde_sub_053dc8(a0, a1, a2);
        case 0x053edcULL: return fde_sub_053edc(a0, a1, a2);
        case 0x053ee8ULL: return fde_sub_053ee8(a0, a1, a2);
        case 0x053ef4ULL: return fde_sub_053ef4(a0, a1, a2);
        case 0x053f04ULL: return fde_sub_053f04(a0, a1, a2);
        case 0x053f1cULL: return fde_sub_053f1c(a0, a1, a2);
        case 0x053f28ULL: return fde_sub_053f28(a0, a1, a2);
        case 0x053f38ULL: return fde_sub_053f38(a0, a1, a2);
        case 0x053f50ULL: return fde_sub_053f50(a0, a1, a2);
        case 0x053f5cULL: return fde_sub_053f5c(a0, a1, a2);
        case 0x054014ULL: return fde_sub_054014(a0, a1, a2);
        case 0x054044ULL: return fde_sub_054044(a0, a1, a2);
        case 0x054060ULL: return fde_sub_054060(a0, a1, a2);
        case 0x054070ULL: return fde_sub_054070(a0, a1, a2);
        case 0x054088ULL: return fde_sub_054088(a0, a1, a2);
        case 0x054098ULL: return fde_sub_054098(a0, a1, a2);
        case 0x054150ULL: return fde_sub_054150(a0, a1, a2);
        case 0x054180ULL: return fde_sub_054180(a0, a1, a2);
        case 0x054190ULL: return fde_sub_054190(a0, a1, a2);
        case 0x0541a8ULL: return fde_sub_0541a8(a0, a1, a2);
        case 0x0541b8ULL: return fde_sub_0541b8(a0, a1, a2);
        case 0x054220ULL: return fde_sub_054220(a0, a1, a2);
        case 0x054438ULL: return fde_sub_054438(a0, a1, a2);
        case 0x054474ULL: return fde_sub_054474(a0, a1, a2);
        case 0x05450cULL: return fde_sub_05450c(a0, a1, a2);
        case 0x05454cULL: return fde_sub_05454c(a0, a1, a2);
        case 0x054564ULL: return fde_sub_054564(a0, a1, a2);
        case 0x05457cULL: return fde_sub_05457c(a0, a1, a2);
        case 0x05458cULL: return fde_sub_05458c(a0, a1, a2);
        case 0x0545a4ULL: return fde_sub_0545a4(a0, a1, a2);
        case 0x0545b4ULL: return fde_sub_0545b4(a0, a1, a2);
        case 0x0545c4ULL: return fde_sub_0545c4(a0, a1, a2);
        case 0x0545dcULL: return fde_sub_0545dc(a0, a1, a2);
        case 0x0547d0ULL: return fde_sub_0547d0(a0, a1, a2);
        case 0x0547dcULL: return fde_sub_0547dc(a0, a1, a2);
        case 0x054a0cULL: return fde_sub_054a0c(a0, a1, a2);
        case 0x054a48ULL: return fde_sub_054a48(a0, a1, a2);
        case 0x054a5cULL: return fde_sub_054a5c(a0, a1, a2);
        case 0x054c34ULL: return fde_sub_054c34(a0, a1, a2);
        case 0x054c4cULL: return fde_sub_054c4c(a0, a1, a2);
        case 0x054c8cULL: return fde_sub_054c8c(a0, a1, a2);
        case 0x054ca0ULL: return fde_sub_054ca0(a0, a1, a2);
        case 0x054cb0ULL: return fde_sub_054cb0(a0, a1, a2);
        case 0x054cf8ULL: return fde_sub_054cf8(a0, a1, a2);
        case 0x054d10ULL: return fde_sub_054d10(a0, a1, a2);
        case 0x054d20ULL: return fde_sub_054d20(a0, a1, a2);
        case 0x054d38ULL: return fde_sub_054d38(a0, a1, a2);
        case 0x054d48ULL: return fde_sub_054d48(a0, a1, a2);
        case 0x054d58ULL: return fde_sub_054d58(a0, a1, a2);
        case 0x054d70ULL: return fde_sub_054d70(a0, a1, a2);
        case 0x054d7cULL: return fde_sub_054d7c(a0, a1, a2);
        case 0x054d8cULL: return fde_sub_054d8c(a0, a1, a2);
        case 0x054da4ULL: return fde_sub_054da4(a0, a1, a2);
        case 0x054db4ULL: return fde_sub_054db4(a0, a1, a2);
        case 0x054dc4ULL: return fde_sub_054dc4(a0, a1, a2);
        case 0x054ddcULL: return fde_sub_054ddc(a0, a1, a2);
        case 0x054de8ULL: return fde_sub_054de8(a0, a1, a2);
        case 0x054f54ULL: return fde_sub_054f54(a0, a1, a2);
        case 0x0551d8ULL: return fde_sub_0551d8(a0, a1, a2);
        case 0x0551e4ULL: return fde_sub_0551e4(a0, a1, a2);
        case 0x0551fcULL: return fde_sub_0551fc(a0, a1, a2);
        case 0x055294ULL: return fde_sub_055294(a0, a1, a2);
        case 0x0552c8ULL: return fde_sub_0552c8(a0, a1, a2);
        case 0x0552e0ULL: return fde_sub_0552e0(a0, a1, a2);
        case 0x0552f8ULL: return fde_sub_0552f8(a0, a1, a2);
        case 0x055308ULL: return fde_sub_055308(a0, a1, a2);
        case 0x055320ULL: return fde_sub_055320(a0, a1, a2);
        case 0x055330ULL: return fde_sub_055330(a0, a1, a2);
        case 0x055340ULL: return fde_sub_055340(a0, a1, a2);
        case 0x055358ULL: return fde_sub_055358(a0, a1, a2);
        case 0x05554cULL: return fde_sub_05554c(a0, a1, a2);
        case 0x05555cULL: return fde_sub_05555c(a0, a1, a2);
        case 0x055574ULL: return fde_sub_055574(a0, a1, a2);
        case 0x055584ULL: return fde_sub_055584(a0, a1, a2);
        case 0x055670ULL: return fde_sub_055670(a0, a1, a2);
        case 0x0556e0ULL: return fde_sub_0556e0(a0, a1, a2);
        case 0x0556f0ULL: return fde_sub_0556f0(a0, a1, a2);
        case 0x055708ULL: return fde_sub_055708(a0, a1, a2);
        case 0x055718ULL: return fde_sub_055718(a0, a1, a2);
        case 0x0557e4ULL: return fde_sub_0557e4(a0, a1, a2);
        case 0x0558f8ULL: return fde_sub_0558f8(a0, a1, a2);
        case 0x055910ULL: return fde_sub_055910(a0, a1, a2);
        case 0x055920ULL: return fde_sub_055920(a0, a1, a2);
        case 0x055938ULL: return fde_sub_055938(a0, a1, a2);
        case 0x055948ULL: return fde_sub_055948(a0, a1, a2);
        case 0x055b74ULL: return fde_sub_055b74(a0, a1, a2);
        case 0x055ba4ULL: return fde_sub_055ba4(a0, a1, a2);
        case 0x055bacULL: return fde_sub_055bac(a0, a1, a2);
        case 0x055c98ULL: return fde_sub_055c98(a0, a1, a2);
        case 0x055e28ULL: return fde_sub_055e28(a0, a1, a2);
        case 0x055e38ULL: return fde_sub_055e38(a0, a1, a2);
        case 0x055e50ULL: return fde_sub_055e50(a0, a1, a2);
        case 0x055e60ULL: return fde_sub_055e60(a0, a1, a2);
        case 0x055f9cULL: return fde_sub_055f9c(a0, a1, a2);
        case 0x05602cULL: return fde_sub_05602c(a0, a1, a2);
        case 0x056044ULL: return fde_sub_056044(a0, a1, a2);
        case 0x056054ULL: return fde_sub_056054(a0, a1, a2);
        case 0x05606cULL: return fde_sub_05606c(a0, a1, a2);
        case 0x05607cULL: return fde_sub_05607c(a0, a1, a2);
        case 0x05608cULL: return fde_sub_05608c(a0, a1, a2);
        case 0x0560a4ULL: return fde_sub_0560a4(a0, a1, a2);
        case 0x056224ULL: return fde_sub_056224(a0, a1, a2);
        case 0x056234ULL: return fde_sub_056234(a0, a1, a2);
        case 0x05624cULL: return fde_sub_05624c(a0, a1, a2);
        case 0x056264ULL: return fde_sub_056264(a0, a1, a2);
        case 0x0562e4ULL: return fde_sub_0562e4(a0, a1, a2);
        case 0x0562f8ULL: return fde_sub_0562f8(a0, a1, a2);
        case 0x056308ULL: return fde_sub_056308(a0, a1, a2);
        case 0x056320ULL: return fde_sub_056320(a0, a1, a2);
        case 0x056330ULL: return fde_sub_056330(a0, a1, a2);
        case 0x0563ccULL: return fde_sub_0563cc(a0, a1, a2);
        case 0x0563e0ULL: return fde_sub_0563e0(a0, a1, a2);
        case 0x0563f0ULL: return fde_sub_0563f0(a0, a1, a2);
        case 0x056408ULL: return fde_sub_056408(a0, a1, a2);
        case 0x056418ULL: return fde_sub_056418(a0, a1, a2);
        case 0x0564a8ULL: return fde_sub_0564a8(a0, a1, a2);
        case 0x0564b8ULL: return fde_sub_0564b8(a0, a1, a2);
        case 0x0564d0ULL: return fde_sub_0564d0(a0, a1, a2);
        case 0x0564f0ULL: return fde_sub_0564f0(a0, a1, a2);
        case 0x0565a8ULL: return fde_sub_0565a8(a0, a1, a2);
        case 0x0565b8ULL: return fde_sub_0565b8(a0, a1, a2);
        case 0x0565d0ULL: return fde_sub_0565d0(a0, a1, a2);
        case 0x0565f8ULL: return fde_sub_0565f8(a0, a1, a2);
        case 0x056764ULL: return fde_sub_056764(a0, a1, a2);
        case 0x056774ULL: return fde_sub_056774(a0, a1, a2);
        case 0x05678cULL: return fde_sub_05678c(a0, a1, a2);
        case 0x0567a4ULL: return fde_sub_0567a4(a0, a1, a2);
        case 0x05685cULL: return fde_sub_05685c(a0, a1, a2);
        case 0x056870ULL: return fde_sub_056870(a0, a1, a2);
        case 0x056880ULL: return fde_sub_056880(a0, a1, a2);
        case 0x056898ULL: return fde_sub_056898(a0, a1, a2);
        case 0x0568a8ULL: return fde_sub_0568a8(a0, a1, a2);
        case 0x056928ULL: return fde_sub_056928(a0, a1, a2);
        case 0x056940ULL: return fde_sub_056940(a0, a1, a2);
        case 0x056950ULL: return fde_sub_056950(a0, a1, a2);
        case 0x056968ULL: return fde_sub_056968(a0, a1, a2);
        case 0x056978ULL: return fde_sub_056978(a0, a1, a2);
        case 0x056ad8ULL: return fde_sub_056ad8(a0, a1, a2);
        case 0x056af0ULL: return fde_sub_056af0(a0, a1, a2);
        case 0x056b08ULL: return fde_sub_056b08(a0, a1, a2);
        case 0x056b24ULL: return fde_sub_056b24(a0, a1, a2);
        case 0x056b34ULL: return fde_sub_056b34(a0, a1, a2);
        case 0x056b4cULL: return fde_sub_056b4c(a0, a1, a2);
        case 0x056b64ULL: return fde_sub_056b64(a0, a1, a2);
        case 0x056bb4ULL: return fde_sub_056bb4(a0, a1, a2);
        case 0x056be0ULL: return fde_sub_056be0(a0, a1, a2);
        case 0x056c7cULL: return fde_sub_056c7c(a0, a1, a2);
        case 0x056c90ULL: return fde_sub_056c90(a0, a1, a2);
        case 0x056ca0ULL: return fde_sub_056ca0(a0, a1, a2);
        case 0x056cb8ULL: return fde_sub_056cb8(a0, a1, a2);
        case 0x056cc8ULL: return fde_sub_056cc8(a0, a1, a2);
        case 0x056d64ULL: return fde_sub_056d64(a0, a1, a2);
        case 0x056d78ULL: return fde_sub_056d78(a0, a1, a2);
        case 0x056d88ULL: return fde_sub_056d88(a0, a1, a2);
        case 0x056da0ULL: return fde_sub_056da0(a0, a1, a2);
        case 0x056db0ULL: return fde_sub_056db0(a0, a1, a2);
        case 0x056e38ULL: return fde_sub_056e38(a0, a1, a2);
        case 0x056e48ULL: return fde_sub_056e48(a0, a1, a2);
        case 0x056e60ULL: return fde_sub_056e60(a0, a1, a2);
        case 0x056e78ULL: return fde_sub_056e78(a0, a1, a2);
        case 0x056f18ULL: return fde_sub_056f18(a0, a1, a2);
        case 0x056fb8ULL: return fde_sub_056fb8(a0, a1, a2);
        case 0x056fc8ULL: return fde_sub_056fc8(a0, a1, a2);
        case 0x056fe0ULL: return fde_sub_056fe0(a0, a1, a2);
        case 0x056ff8ULL: return fde_sub_056ff8(a0, a1, a2);
        case 0x0570b8ULL: return fde_sub_0570b8(a0, a1, a2);
        case 0x0570c8ULL: return fde_sub_0570c8(a0, a1, a2);
        case 0x0570e0ULL: return fde_sub_0570e0(a0, a1, a2);
        case 0x057110ULL: return fde_sub_057110(a0, a1, a2);
        case 0x057228ULL: return fde_sub_057228(a0, a1, a2);
        case 0x057238ULL: return fde_sub_057238(a0, a1, a2);
        case 0x057248ULL: return fde_sub_057248(a0, a1, a2);
        case 0x057260ULL: return fde_sub_057260(a0, a1, a2);
        case 0x057270ULL: return fde_sub_057270(a0, a1, a2);
        case 0x0572c4ULL: return fde_sub_0572c4(a0, a1, a2);
        case 0x0572e4ULL: return fde_sub_0572e4(a0, a1, a2);
        case 0x057338ULL: return fde_sub_057338(a0, a1, a2);
        case 0x057358ULL: return fde_sub_057358(a0, a1, a2);
        case 0x0573acULL: return fde_sub_0573ac(a0, a1, a2);
        case 0x0573d0ULL: return fde_sub_0573d0(a0, a1, a2);
        case 0x057470ULL: return fde_sub_057470(a0, a1, a2);
        case 0x05747cULL: return fde_sub_05747c(a0, a1, a2);
        case 0x05748cULL: return fde_sub_05748c(a0, a1, a2);
        case 0x0574a4ULL: return fde_sub_0574a4(a0, a1, a2);
        case 0x0574b0ULL: return fde_sub_0574b0(a0, a1, a2);
        case 0x057550ULL: return fde_sub_057550(a0, a1, a2);
        case 0x05755cULL: return fde_sub_05755c(a0, a1, a2);
        case 0x05756cULL: return fde_sub_05756c(a0, a1, a2);
        case 0x057584ULL: return fde_sub_057584(a0, a1, a2);
        case 0x057590ULL: return fde_sub_057590(a0, a1, a2);
        case 0x057630ULL: return fde_sub_057630(a0, a1, a2);
        case 0x05763cULL: return fde_sub_05763c(a0, a1, a2);
        case 0x05764cULL: return fde_sub_05764c(a0, a1, a2);
        case 0x057664ULL: return fde_sub_057664(a0, a1, a2);
        case 0x057670ULL: return fde_sub_057670(a0, a1, a2);
        case 0x057710ULL: return fde_sub_057710(a0, a1, a2);
        case 0x05771cULL: return fde_sub_05771c(a0, a1, a2);
        case 0x05772cULL: return fde_sub_05772c(a0, a1, a2);
        case 0x057744ULL: return fde_sub_057744(a0, a1, a2);
        case 0x057750ULL: return fde_sub_057750(a0, a1, a2);
        case 0x057810ULL: return fde_sub_057810(a0, a1, a2);
        case 0x057820ULL: return fde_sub_057820(a0, a1, a2);
        case 0x057830ULL: return fde_sub_057830(a0, a1, a2);
        case 0x057848ULL: return fde_sub_057848(a0, a1, a2);
        case 0x057858ULL: return fde_sub_057858(a0, a1, a2);
        case 0x0578a8ULL: return fde_sub_0578a8(a0, a1, a2);
        case 0x0578d4ULL: return fde_sub_0578d4(a0, a1, a2);
        case 0x0579f0ULL: return fde_sub_0579f0(a0, a1, a2);
        case 0x0579fcULL: return fde_sub_0579fc(a0, a1, a2);
        case 0x057a0cULL: return fde_sub_057a0c(a0, a1, a2);
        case 0x057a1cULL: return fde_sub_057a1c(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace animax
} // namespace lynx
