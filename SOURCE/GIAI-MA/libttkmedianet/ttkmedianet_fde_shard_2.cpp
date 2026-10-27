// ============================================================================
// File: ttkmedianet_fde_shard_2.cpp
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 2/5 covering FDEs [329..657]
//     (PC range 0x02c844 .. 0x041adc).
// VI: Phân mảnh FDE AArch64 C++17 2/5 bao phủ các FDE [329..657]
//     (Dải địa chỉ PC 0x02c844 .. 0x041adc).
// ============================================================================
#include "ttkmedianet_core.h"

namespace TTKMediaNet {

// FDE #0329 | PC: 0x02c844..0x02c894 (80 B) | Symbol: sub_02c844
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_02c844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C844ULL;
}

// FDE #0330 | PC: 0x02c894..0x02c904 (112 B) | Symbol: sub_02c894
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9b000]
uint64_t fde_sub_02c894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C894ULL;
}

// FDE #0331 | PC: 0x02c904..0x02c97c (120 B) | Symbol: sub_02c904
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9b000]
uint64_t fde_sub_02c904(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C904ULL;
}

// FDE #0332 | PC: 0x02c97c..0x02c9f0 (116 B) | Symbol: sub_02c97c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_02c97c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C97CULL;
}

// FDE #0333 | PC: 0x02c9f0..0x02ca6c (124 B) | Symbol: sub_02c9f0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_02c9f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C9F0ULL;
}

// FDE #0334 | PC: 0x02ca6c..0x02cae8 (124 B) | Symbol: sub_02ca6c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_02ca6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CA6CULL;
}

// FDE #0335 | PC: 0x02cae8..0x02cb6c (132 B) | Symbol: sub_02cae8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_02cae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CAE8ULL;
}

// FDE #0336 | PC: 0x02cb6c..0x02cc3c (208 B) | Symbol: sub_02cb6c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02cb6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CB6CULL;
}

// FDE #0337 | PC: 0x02cc3c..0x02cd74 (312 B) | Symbol: sub_02cc3c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02cc3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC3CULL;
}

// FDE #0338 | PC: 0x02cd74..0x02d4f4 (1920 B) | Symbol: sub_02cd74
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_02cd74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0780ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CD74ULL;
}

// FDE #0339 | PC: 0x02d4f4..0x02d600 (268 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE3putEc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_02d4f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D4F4ULL;
}

// FDE #0340 | PC: 0x02d600..0x02d638 (56 B) | Symbol: sub_02d600
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_02d600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D600ULL;
}

// FDE #0341 | PC: 0x02d638..0x02d67c (68 B) | Symbol: sub_02d638
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_02d638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D638ULL;
}

// FDE #0342 | PC: 0x02d67c..0x02d6c0 (68 B) | Symbol: sub_02d67c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_02d67c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D67CULL;
}

// FDE #0343 | PC: 0x02d6c0..0x02d710 (80 B) | Symbol: sub_02d6c0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_02d6c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D6C0ULL;
}

// FDE #0344 | PC: 0x02d710..0x02d8c4 (436 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEx
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_02d710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D710ULL;
}

// FDE #0345 | PC: 0x02d8c4..0x02d9e8 (292 B) | Symbol: sub_02d8c4
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_02d8c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D8C4ULL;
}

// FDE #0346 | PC: 0x02d9e8..0x02dae8 (256 B) | Symbol: sub_02d9e8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x60]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x60]]
uint64_t fde_sub_02d9e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D9E8ULL;
}

// FDE #0347 | PC: 0x02dae8..0x02db0c (36 B) | Symbol: sub_02dae8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_02dae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DAE8ULL;
}

// FDE #0348 | PC: 0x02db0c..0x02db2c (32 B) | Symbol: sub_02db0c
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; cbz w8, #0x2db28; ldr x0, [x0, #0x38]; cbz x0, #0x2db28] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; cbz w8, #0x2db28; ldr x0, [x0, #0x38]; cbz x0, #0x2db28]
uint64_t fde_sub_02db0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000C8ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DB0CULL;
}

// FDE #0349 | PC: 0x02db2c..0x02db4c (32 B) | Symbol: sub_02db2c
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; cbz w8, #0x2db48; ldr x0, [x0, #0x38]; cbz x0, #0x2db48] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; cbz w8, #0x2db48; ldr x0, [x0, #0x38]; cbz x0, #0x2db48]
uint64_t fde_sub_02db2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000C8ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DB2CULL;
}

// FDE #0350 | PC: 0x02db4c..0x02db6c (32 B) | Symbol: sub_02db4c
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; cbz w8, #0x2db68; ldr x0, [x0, #0x38]; cbz x0, #0x2db68] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; cbz w8, #0x2db68; ldr x0, [x0, #0x38]; cbz x0, #0x2db68]
uint64_t fde_sub_02db4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000C8ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DB4CULL;
}

// FDE #0351 | PC: 0x02db6c..0x02dbf8 (140 B) | Symbol: sub_02db6c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02db6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DB6CULL;
}

// FDE #0352 | PC: 0x02dbf8..0x02dd7c (388 B) | Symbol: sub_02dbf8
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_02dbf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DBF8ULL;
}

// FDE #0353 | PC: 0x02dd7c..0x02ef00 (4484 B) | Symbol: sub_02dd7c
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]]
uint64_t fde_sub_02dd7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9106FFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x1184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DD7CULL;
}

// FDE #0354 | PC: 0x02ef00..0x02efec (236 B) | Symbol: sub_02ef00
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_02ef00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EF00ULL;
}

// FDE #0355 | PC: 0x02efec..0x02f050 (100 B) | Symbol: sub_02efec
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_02efec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EFECULL;
}

// FDE #0356 | PC: 0x02f050..0x02f0c4 (116 B) | Symbol: sub_02f050
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]]
uint64_t fde_sub_02f050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F050ULL;
}

// FDE #0357 | PC: 0x02f0c4..0x02f0e8 (36 B) | Symbol: sub_02f0c4
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x2b0; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x2b0; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_02f0c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910AC108ULL) << 32) | 0xF0000348ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F0C4ULL;
}

// FDE #0358 | PC: 0x02f0e8..0x02f140 (88 B) | Symbol: sub_02f0e8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_02f0e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F0E8ULL;
}

// FDE #0359 | PC: 0x02f140..0x02f1a8 (104 B) | Symbol: sub_02f140
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]]
uint64_t fde_sub_02f140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F140ULL;
}

// FDE #0360 | PC: 0x02f1a8..0x02f224 (124 B) | Symbol: sub_02f1a8
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_02f1a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F1A8ULL;
}

// FDE #0361 | PC: 0x02f224..0x02f54c (808 B) | Symbol: sub_02f224
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_02f224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0328ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F224ULL;
}

// FDE #0362 | PC: 0x02f54c..0x02f5d0 (132 B) | Symbol: _ZN11TTKMediaNet11NetworkTaskC1ENSt6__ndk18weak_ptrINS0_8DelegateEEE
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x2f0; add x9, x8, #0x88; fmov d1, x8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x2f0; add x9, x8, #0x88; fmov d1, x8]
uint64_t fde_sub_02f54c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910BC108ULL) << 32) | 0xF0000348ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F54CULL;
}

// FDE #0363 | PC: 0x02f5d0..0x02f664 (148 B) | Symbol: _ZN11TTKMediaNet11NetworkTaskD2Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_02f5d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F5D0ULL;
}

// FDE #0364 | PC: 0x02f664..0x02f700 (156 B) | Symbol: _ZN11TTKMediaNet11NetworkTaskD0Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_02f664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F664ULL;
}

// FDE #0365 | PC: 0x02f700..0x02fc08 (1288 B) | Symbol: _ZN11TTKMediaNet11NetworkTask4OpenERNS_14RequestContextERNS_15StrategyContextEPNS_15TTKMediaNetTask8DelegateE
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_02f700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0508ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F700ULL;
}

// FDE #0366 | PC: 0x02fc08..0x03005c (1108 B) | Symbol: _ZN11TTKMediaNet11NetworkTask4ReadEPvi
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_02fc08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0454ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02FC08ULL;
}

// FDE #0367 | PC: 0x03005c..0x030458 (1020 B) | Symbol: _ZN11TTKMediaNet11NetworkTask5WriteEPvi
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]]
uint64_t fde_sub_03005c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9085FF8ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x03FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03005CULL;
}

// FDE #0368 | PC: 0x030458..0x030854 (1020 B) | Symbol: _ZN11TTKMediaNet11NetworkTask5CloseEv
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]]
uint64_t fde_sub_030458(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9085FF8ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x03FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030458ULL;
}

// FDE #0369 | PC: 0x030854..0x030c00 (940 B) | Symbol: _ZN11TTKMediaNet11NetworkTask6CancelEv
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]]
uint64_t fde_sub_030854(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9085FF8ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x03ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030854ULL;
}

// FDE #0370 | PC: 0x030c00..0x031054 (1108 B) | Symbol: _ZN11TTKMediaNet11NetworkTask14SetStringValueEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]]
uint64_t fde_sub_030c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C6FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0454ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030C00ULL;
}

// FDE #0371 | PC: 0x031054..0x0312b8 (612 B) | Symbol: _ZN11TTKMediaNet11NetworkTask13SetInt64ValueEil
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_031054(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0264ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031054ULL;
}

// FDE #0372 | PC: 0x0312b8..0x0312c0 (8 B) | Symbol: _ZN11TTKMediaNet11NetworkTask14GetStringValueEiRNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0312b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0312B8ULL;
}

// FDE #0373 | PC: 0x0312c0..0x0312c8 (8 B) | Symbol: _ZN11TTKMediaNet11NetworkTask13GetInt64ValueEiRl
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0312c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0312C0ULL;
}

// FDE #0374 | PC: 0x0312c8..0x031330 (104 B) | Symbol: _ZN11TTKMediaNet11NetworkTask17OnResponseStartedERNS_15ResponseContextE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0312c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0312C8ULL;
}

// FDE #0375 | PC: 0x031330..0x0313b0 (128 B) | Symbol: _ZN11TTKMediaNet11NetworkTask15OnReadCompletedEi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_031330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031330ULL;
}

// FDE #0376 | PC: 0x0313b0..0x031418 (104 B) | Symbol: _ZN11TTKMediaNet11NetworkTask16OnWriteCompletedEi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0313b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0313B0ULL;
}

// FDE #0377 | PC: 0x031418..0x03155c (324 B) | Symbol: _ZN11TTKMediaNet11NetworkTask9OnMessageEilRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_031418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031418ULL;
}

// FDE #0378 | PC: 0x03155c..0x0315f4 (152 B) | Symbol: sub_03155c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_03155c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03155CULL;
}

// FDE #0379 | PC: 0x0315f4..0x0315fc (8 B) | Symbol: sub_0315f4
// EN: AArch64 prologue [sub x0, x0, #8; b #0xf1c0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0xf1c0]
uint64_t fde_sub_0315f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF76F2ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0315F4ULL;
}

// FDE #0380 | PC: 0x0315fc..0x031664 (104 B) | Symbol: sub_0315fc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0315fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0315FCULL;
}

// FDE #0381 | PC: 0x031664..0x0316e4 (128 B) | Symbol: sub_031664
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_031664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031664ULL;
}

// FDE #0382 | PC: 0x0316e4..0x03174c (104 B) | Symbol: sub_0316e4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0316e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0316E4ULL;
}

// FDE #0383 | PC: 0x03174c..0x031754 (8 B) | Symbol: sub_03174c
// EN: AArch64 prologue [sub x0, x0, #8; b #0xfa90] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0xfa90]
uint64_t fde_sub_03174c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF78D0ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03174CULL;
}

// FDE #0384 | PC: 0x031754..0x031758 (4 B) | Symbol: sub_031754
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_031754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000348ULL) << 32) | 0x17FF7503ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031754ULL;
}

// FDE #0385 | PC: 0x031758..0x031778 (32 B) | Symbol: sub_031758
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x3b8; str x8, [x1]; ldur q0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x3b8; str x8, [x1]; ldur q0, [x0, #0x18]]
uint64_t fde_sub_031758(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910EE108ULL) << 32) | 0xB0000348ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031758ULL;
}

// FDE #0386 | PC: 0x031778..0x03177c (4 B) | Symbol: sub_031778
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_031778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF74F9ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031778ULL;
}

// FDE #0387 | PC: 0x03177c..0x031780 (4 B) | Symbol: sub_03177c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03177c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400801ULL) << 32) | 0x17FF74F9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03177CULL;
}

// FDE #0388 | PC: 0x031780..0x0317c0 (64 B) | Symbol: sub_031780
// EN: AArch64 prologue [ldr w1, [x0, #8]; ldp x2, x8, [x0, #0x10]; mov w9, #0x8a88; movk w9, #1, lsl #16] | VI: Khởi đầu hàm AArch64 [ldr w1, [x0, #8]; ldp x2, x8, [x0, #0x10]; mov w9, #0x8a88; movk w9, #1, lsl #16]
uint64_t fde_sub_031780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9412002ULL) << 32) | 0xB9400801ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031780ULL;
}

// FDE #0389 | PC: 0x0317c0..0x0317e0 (32 B) | Symbol: sub_0317c0
// EN: AArch64 prologue [ldrb w8, [x0, #0x10]; adrp x9, #0x9a000; add x9, x9, #0x3f8; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x10]; adrp x9, #0x9a000; add x9, x9, #0x3f8; str x9, [x0]]
uint64_t fde_sub_0317c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000349ULL) << 32) | 0x39404008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0317C0ULL;
}

// FDE #0390 | PC: 0x0317e0..0x03181c (60 B) | Symbol: sub_0317e0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]]
uint64_t fde_sub_0317e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0317E0ULL;
}

// FDE #0391 | PC: 0x03181c..0x0318f4 (216 B) | Symbol: sub_03181c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03181c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03181CULL;
}

// FDE #0392 | PC: 0x0318f4..0x031908 (20 B) | Symbol: sub_0318f4
// EN: AArch64 prologue [ldrb w8, [x0, #0x10]; tbnz w8, #0, #0x31900; ret; ldr x0, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x10]; tbnz w8, #0, #0x31900; ret; ldr x0, [x0, #0x20]]
uint64_t fde_sub_0318f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000048ULL) << 32) | 0x39404008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0318F4ULL;
}

// FDE #0393 | PC: 0x031908..0x031938 (48 B) | Symbol: sub_031908
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]]
uint64_t fde_sub_031908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031908ULL;
}

// FDE #0394 | PC: 0x031938..0x031a20 (232 B) | Symbol: sub_031938
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_031938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031938ULL;
}

// FDE #0395 | PC: 0x031a20..0x031c30 (528 B) | Symbol: _ZN11TTKMediaNet11NetworkTask16TCSetStringValueEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_031a20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031A20ULL;
}

// FDE #0396 | PC: 0x031c30..0x031d2c (252 B) | Symbol: sub_031c30
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_031c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031C30ULL;
}

// FDE #0397 | PC: 0x031d2c..0x031ddc (176 B) | Symbol: sub_031d2c
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_031d2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031D2CULL;
}

// FDE #0398 | PC: 0x031ddc..0x031ec0 (228 B) | Symbol: _ZN11TTKMediaNet11NetworkTask8TCCancelEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x38]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x38]]
uint64_t fde_sub_031ddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031DDCULL;
}

// FDE #0399 | PC: 0x031ec0..0x031fc4 (260 B) | Symbol: sub_031ec0
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_031ec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031EC0ULL;
}

// FDE #0400 | PC: 0x031fc4..0x0320d0 (268 B) | Symbol: sub_031fc4
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_031fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031FC4ULL;
}

// FDE #0401 | PC: 0x0320d0..0x032144 (116 B) | Symbol: sub_0320d0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_0320d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0320D0ULL;
}

// FDE #0402 | PC: 0x032144..0x03223c (248 B) | Symbol: sub_032144
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_032144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032144ULL;
}

// FDE #0403 | PC: 0x03223c..0x03233c (256 B) | Symbol: sub_03223c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03223c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03223CULL;
}

// FDE #0404 | PC: 0x03233c..0x03241c (224 B) | Symbol: sub_03233c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_03233c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03233CULL;
}

// FDE #0405 | PC: 0x03241c..0x032468 (76 B) | Symbol: _ZNSt6__ndk117__assoc_sub_stateD2Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_03241c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03241CULL;
}

// FDE #0406 | PC: 0x032468..0x0324bc (84 B) | Symbol: sub_032468
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_032468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032468ULL;
}

// FDE #0407 | PC: 0x0324bc..0x0324d0 (20 B) | Symbol: sub_0324bc
// EN: AArch64 prologue [cbz x0, #0x324cc; ldr x8, [x0]; ldr x1, [x8, #8]; br x1] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x324cc; ldr x8, [x0]; ldr x1, [x8, #8]; br x1]
uint64_t fde_sub_0324bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0324BCULL;
}

// FDE #0408 | PC: 0x0324d0..0x0324d4 (4 B) | Symbol: sub_0324d0
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0324d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF71A3ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0324D0ULL;
}

// FDE #0409 | PC: 0x0324d4..0x0324d8 (4 B) | Symbol: sub_0324d4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0324d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000348ULL) << 32) | 0x17FF71A3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0324D4ULL;
}

// FDE #0410 | PC: 0x0324d8..0x0324f0 (24 B) | Symbol: sub_0324d8
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x438; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x438; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_0324d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9110E108ULL) << 32) | 0x90000348ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0324D8ULL;
}

// FDE #0411 | PC: 0x0324f0..0x0324f4 (4 B) | Symbol: sub_0324f0
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0324f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF719BULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0324F0ULL;
}

// FDE #0412 | PC: 0x0324f4..0x0324f8 (4 B) | Symbol: sub_0324f4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0324f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0x17FF719BULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0324F4ULL;
}

// FDE #0413 | PC: 0x0324f8..0x032500 (8 B) | Symbol: sub_0324f8
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0xfbc0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0xfbc0]
uint64_t fde_sub_0324f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF75B1ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0324F8ULL;
}

// FDE #0414 | PC: 0x032500..0x032504 (4 B) | Symbol: sub_032500
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_032500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000348ULL) << 32) | 0x17FF7198ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032500ULL;
}

// FDE #0415 | PC: 0x032504..0x03251c (24 B) | Symbol: sub_032504
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x4e8; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x4e8; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_032504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9113A108ULL) << 32) | 0x90000348ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032504ULL;
}

// FDE #0416 | PC: 0x03251c..0x032520 (4 B) | Symbol: sub_03251c
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03251c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF7190ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03251CULL;
}

// FDE #0417 | PC: 0x032520..0x032524 (4 B) | Symbol: sub_032520
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_032520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FF7190ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032520ULL;
}

// FDE #0418 | PC: 0x032524..0x0325c4 (160 B) | Symbol: sub_032524
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #8]]
uint64_t fde_sub_032524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032524ULL;
}

// FDE #0419 | PC: 0x0325c4..0x0325c8 (4 B) | Symbol: sub_0325c4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0325c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000348ULL) << 32) | 0x17FF7167ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0325C4ULL;
}

// FDE #0420 | PC: 0x0325c8..0x0325e8 (32 B) | Symbol: sub_0325c8
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x528; str x8, [x1]; ldur q0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x528; str x8, [x1]; ldur q0, [x0, #0x18]]
uint64_t fde_sub_0325c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114A108ULL) << 32) | 0x90000348ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0325C8ULL;
}

// FDE #0421 | PC: 0x0325e8..0x0325ec (4 B) | Symbol: sub_0325e8
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0325e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF715DULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0325E8ULL;
}

// FDE #0422 | PC: 0x0325ec..0x0325f0 (4 B) | Symbol: sub_0325ec
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0325ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C09ULL) << 32) | 0x17FF715DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0325ECULL;
}

// FDE #0423 | PC: 0x0325f0..0x032650 (96 B) | Symbol: sub_0325f0
// EN: AArch64 prologue [ldr x9, [x0, #0x18]; mov x8, x0; mov w0, #0x6da4; movk w0, #0xfffe, lsl #16] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x18]; mov x8, x0; mov w0, #0x6da4; movk w0, #0xfffe, lsl #16]
uint64_t fde_sub_0325f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xF9400C09ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0325F0ULL;
}

// FDE #0424 | PC: 0x032650..0x032654 (4 B) | Symbol: sub_032650
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_032650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000348ULL) << 32) | 0x17FF7144ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032650ULL;
}

// FDE #0425 | PC: 0x032654..0x032674 (32 B) | Symbol: sub_032654
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x568; str x8, [x1]; ldur q0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x568; str x8, [x1]; ldur q0, [x0, #0x18]]
uint64_t fde_sub_032654(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115A108ULL) << 32) | 0x90000348ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032654ULL;
}

// FDE #0426 | PC: 0x032674..0x032678 (4 B) | Symbol: sub_032674
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_032674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF713AULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032674ULL;
}

// FDE #0427 | PC: 0x032678..0x03267c (4 B) | Symbol: sub_032678
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_032678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x17FF713AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032678ULL;
}

// FDE #0428 | PC: 0x03267c..0x0327a0 (292 B) | Symbol: sub_03267c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_03267c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03267CULL;
}

// FDE #0429 | PC: 0x0327a0..0x032830 (144 B) | Symbol: sub_0327a0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0327a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0327A0ULL;
}

// FDE #0430 | PC: 0x032830..0x0328cc (156 B) | Symbol: sub_032830
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_032830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032830ULL;
}

// FDE #0431 | PC: 0x0328cc..0x0329a8 (220 B) | Symbol: sub_0328cc
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x5a8; str x8, [x1]; ldur q0, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x5a8; str x8, [x1]; ldur q0, [x0, #0x28]]
uint64_t fde_sub_0328cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9116A108ULL) << 32) | 0x90000348ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0328CCULL;
}

// FDE #0432 | PC: 0x0329a8..0x032a2c (132 B) | Symbol: sub_0329a8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0329a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0329A8ULL;
}

// FDE #0433 | PC: 0x032a2c..0x032abc (144 B) | Symbol: sub_032a2c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_032a2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032A2CULL;
}

// FDE #0434 | PC: 0x032abc..0x032c8c (464 B) | Symbol: sub_032abc
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x22, x21, [sp, #0xc0]; stp x20, x19, [sp, #0xd0]; stp x29, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x22, x21, [sp, #0xc0]; stp x20, x19, [sp, #0xd0]; stp x29, x30, [sp, #0xe0]]
uint64_t fde_sub_032abc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C57F6ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032ABCULL;
}

// FDE #0435 | PC: 0x032c8c..0x032ea4 (536 B) | Symbol: _ZN11TTKMediaNet11NetworkTask9StartTaskERNS_14RequestContextERNS_15StrategyContextE
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]; stp x22, x21, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]; stp x22, x21, [sp, #0xe0]]
uint64_t fde_sub_032c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C67FCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032C8CULL;
}

// FDE #0436 | PC: 0x032ea4..0x032ec8 (36 B) | Symbol: sub_032ea4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_032ea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032EA4ULL;
}

// FDE #0437 | PC: 0x032ec8..0x032ee0 (24 B) | Symbol: sub_032ec8
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; cbz x0, #0x32edc; ldr x8, [x0]; ldr x1, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; cbz x0, #0x32edc; ldr x8, [x0]; ldr x1, [x8, #8]]
uint64_t fde_sub_032ec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000080ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032EC8ULL;
}

// FDE #0438 | PC: 0x032ee0..0x032ee4 (4 B) | Symbol: sub_032ee0
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_032ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x17FF6F20ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032EE0ULL;
}

// FDE #0439 | PC: 0x032ee4..0x033004 (288 B) | Symbol: _ZN11TTKMediaNet11NetworkTask6TCReadEPvi
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_032ee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032EE4ULL;
}

// FDE #0440 | PC: 0x033004..0x033058 (84 B) | Symbol: _ZN11TTKMediaNet11NetworkTask7TCWriteEPvi
// EN: AArch64 prologue [ldrb w9, [x0, #0x38]; mov x8, x0; mov w0, #0x6da4; movk w0, #0xfffe, lsl #16] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x38]; mov x8, x0; mov w0, #0x6da4; movk w0, #0xfffe, lsl #16]
uint64_t fde_sub_033004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0x3940E009ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033004ULL;
}

// FDE #0441 | PC: 0x033058..0x033088 (48 B) | Symbol: _ZN11TTKMediaNet11NetworkTask13ResetDelegateEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x20, x0, #0x10] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x20, x0, #0x10]
uint64_t fde_sub_033058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033058ULL;
}

// FDE #0442 | PC: 0x033088..0x033128 (160 B) | Symbol: _ZN11TTKMediaNet11NetworkTask7TCCloseEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x38]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x38]]
uint64_t fde_sub_033088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033088ULL;
}

// FDE #0443 | PC: 0x033128..0x0331a0 (120 B) | Symbol: _ZN11TTKMediaNet11NetworkTask15NotifySucceededEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x38]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x38]]
uint64_t fde_sub_033128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033128ULL;
}

// FDE #0444 | PC: 0x0331a0..0x03322c (140 B) | Symbol: _ZN11TTKMediaNet11NetworkTask12NotifyFailedEi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0331a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0331A0ULL;
}

// FDE #0445 | PC: 0x03322c..0x0332b0 (132 B) | Symbol: _ZN11TTKMediaNet11NetworkTask13NotifyMessageEilRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03322c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03322CULL;
}

// FDE #0446 | PC: 0x0332b0..0x0332e0 (48 B) | Symbol: _ZN11TTKMediaNet11NetworkTask31InternalKeyConvertToExternalKeyEi
// EN: AArch64 prologue [mov w8, #0x445d; movk w8, #0xfff2, lsl #16; add w8, w1, w8; cmp w8, #3] | VI: Khởi đầu hàm AArch64 [mov w8, #0x445d; movk w8, #0xfff2, lsl #16; add w8, w1, w8; cmp w8, #3]
uint64_t fde_sub_0332b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72BFFE48ULL) << 32) | 0x52888BA8ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0332B0ULL;
}

// FDE #0447 | PC: 0x0332e0..0x033398 (184 B) | Symbol: _ZN11TTKMediaNet11NetworkTask6TCOpenENS_14RequestContextENS_15StrategyContextE
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; str w2, [sp, #8]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; str w2, [sp, #8]]
uint64_t fde_sub_0332e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0332E0ULL;
}

// FDE #0448 | PC: 0x033398..0x0333ec (84 B) | Symbol: _ZN11TTKMediaNet11NetworkTask14TCReadInternalEPvi
// EN: AArch64 prologue [ldrb w9, [x0, #0x38]; mov x8, x0; mov w0, #0x6da4; movk w0, #0xfffe, lsl #16] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x38]; mov x8, x0; mov w0, #0x6da4; movk w0, #0xfffe, lsl #16]
uint64_t fde_sub_033398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0x3940E009ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033398ULL;
}

// FDE #0449 | PC: 0x0333ec..0x033464 (120 B) | Symbol: _ZN11TTKMediaNet11NetworkTask14NotifyCanceledEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x38]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x38]]
uint64_t fde_sub_0333ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0333ECULL;
}

// FDE #0450 | PC: 0x033464..0x0334a0 (60 B) | Symbol: _ZN11TTKMediaNet11NetworkTask15TCSetInt64ValueEil
// EN: AArch64 prologue [mov w8, #0x8a88; movk w8, #1, lsl #16; cmp w1, w8; b.ne #0x3347c] | VI: Khởi đầu hàm AArch64 [mov w8, #0x8a88; movk w8, #1, lsl #16; cmp w1, w8; b.ne #0x3347c]
uint64_t fde_sub_033464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A00028ULL) << 32) | 0x52915108ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033464ULL;
}

// FDE #0451 | PC: 0x0334a0..0x0338e8 (1096 B) | Symbol: _ZN11TTKMediaNet11NetworkTask9NotifyLogEv
// EN: AArch64 prologue [sub sp, sp, #0x1a0; stp x28, x23, [sp, #0x160]; stp x22, x21, [sp, #0x170]; stp x20, x19, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; stp x28, x23, [sp, #0x160]; stp x22, x21, [sp, #0x170]; stp x20, x19, [sp, #0x180]]
uint64_t fde_sub_0334a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9165FFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0448ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0334A0ULL;
}

// FDE #0452 | PC: 0x0338e8..0x0338ec (4 B) | Symbol: CreateNetworkMgr
// EN: AArch64 prologue [b #0xebd0] | VI: Khởi đầu hàm AArch64 [b #0xebd0]
uint64_t fde_sub_0338e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x17FF6CBAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0338E8ULL;
}

// FDE #0453 | PC: 0x0338ec..0x033b90 (676 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr4InitEv
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0338ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x02A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0338ECULL;
}

// FDE #0454 | PC: 0x033b90..0x033be8 (88 B) | Symbol: sub_033b90
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]]
uint64_t fde_sub_033b90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033B90ULL;
}

// FDE #0455 | PC: 0x033be8..0x033c0c (36 B) | Symbol: sub_033be8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_033be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033BE8ULL;
}

// FDE #0456 | PC: 0x033c0c..0x033c24 (24 B) | Symbol: sub_033c0c
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; cbz x0, #0x33c20; ldr x8, [x0]; ldr x1, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; cbz x0, #0x33c20; ldr x8, [x0]; ldr x1, [x8, #8]]
uint64_t fde_sub_033c0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000080ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033C0CULL;
}

// FDE #0457 | PC: 0x033c24..0x033c28 (4 B) | Symbol: sub_033c24
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_033c24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FF6BCFULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033C24ULL;
}

// FDE #0458 | PC: 0x033c28..0x033ca8 (128 B) | Symbol: _ZN11TTKMediaNet10NetworkMgrD2Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x58]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x58]]
uint64_t fde_sub_033c28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033C28ULL;
}

// FDE #0459 | PC: 0x033ca8..0x033d24 (124 B) | Symbol: _ZN11TTKMediaNet10NetworkMgrD0Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x58]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x58]]
uint64_t fde_sub_033ca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033CA8ULL;
}

// FDE #0460 | PC: 0x033d24..0x033fa8 (644 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr15StartNetworkMgrEPNS_14TTKMediaNetMgr8DelegateE
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_033d24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033D24ULL;
}

// FDE #0461 | PC: 0x033fa8..0x034228 (640 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr14StopNetworkMgrEv
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_033fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0280ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033FA8ULL;
}

// FDE #0462 | PC: 0x034228..0x0346f4 (1228 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr10CreateTaskEv
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]]
uint64_t fde_sub_034228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043FBULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x04CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034228ULL;
}

// FDE #0463 | PC: 0x0346f4..0x034aa8 (948 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr11DestroyTaskEPNS_15TTKMediaNetTaskE
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]]
uint64_t fde_sub_0346f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9085FF8ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x03B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0346F4ULL;
}

// FDE #0464 | PC: 0x034aa8..0x034db8 (784 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr15StartPreConnectERNS_17PreConnectContextE
// EN: AArch64 prologue [sub sp, sp, #0x130; stp x28, x27, [sp, #0xd0]; stp x26, x25, [sp, #0xe0]; stp x24, x23, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; stp x28, x27, [sp, #0xd0]; stp x26, x25, [sp, #0xe0]; stp x24, x23, [sp, #0xf0]]
uint64_t fde_sub_034aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D6FFCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x0310ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034AA8ULL;
}

// FDE #0465 | PC: 0x034db8..0x0353fc (1604 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr15IsHostConnectedENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEti
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]]
uint64_t fde_sub_034db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E6FFCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x0644ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034DB8ULL;
}

// FDE #0466 | PC: 0x0353fc..0x0355cc (464 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr13SetAltSvcInfoENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_0353fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0353FCULL;
}

// FDE #0467 | PC: 0x0355cc..0x0356e0 (276 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr15IsHostSupportedENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEi
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_0355cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0355CCULL;
}

// FDE #0468 | PC: 0x0356e0..0x035b38 (1112 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr14SetStringValueEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]]
uint64_t fde_sub_0356e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C6FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0458ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0356E0ULL;
}

// FDE #0469 | PC: 0x035b38..0x035da0 (616 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr13SetInt64ValueEil
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_035b38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035B38ULL;
}

// FDE #0470 | PC: 0x035da0..0x035da8 (8 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr14GetStringValueEiRNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_035da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035DA0ULL;
}

// FDE #0471 | PC: 0x035da8..0x035e80 (216 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr13GetInt64ValueEiRl
// EN: AArch64 prologue [mov w8, #0x86a0; movk w8, #1, lsl #16; cmp w1, w8; b.ne #0x35e78] | VI: Khởi đầu hàm AArch64 [mov w8, #0x86a0; movk w8, #1, lsl #16; cmp w1, w8; b.ne #0x35e78]
uint64_t fde_sub_035da8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A00028ULL) << 32) | 0x5290D408ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035DA8ULL;
}

// FDE #0472 | PC: 0x035e80..0x035fa4 (292 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr5OnLogEiRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_035e80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035E80ULL;
}

// FDE #0473 | PC: 0x035fa4..0x036024 (128 B) | Symbol: sub_035fa4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x50]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x50]]
uint64_t fde_sub_035fa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035FA4ULL;
}

// FDE #0474 | PC: 0x036024..0x0360a0 (124 B) | Symbol: sub_036024
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_036024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036024ULL;
}

// FDE #0475 | PC: 0x0360a0..0x0360a8 (8 B) | Symbol: sub_0360a0
// EN: AArch64 prologue [sub x0, x0, #8; b #0xf740] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0xf740]
uint64_t fde_sub_0360a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF65A7ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0360A0ULL;
}

// FDE #0476 | PC: 0x0360a8..0x0360ac (4 B) | Symbol: sub_0360a8
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0360a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000328ULL) << 32) | 0x17FF62AEULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0360A8ULL;
}

// FDE #0477 | PC: 0x0360ac..0x0360cc (32 B) | Symbol: sub_0360ac
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x708; str x8, [x1]; ldur q0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x708; str x8, [x1]; ldur q0, [x0, #0x18]]
uint64_t fde_sub_0360ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911C2108ULL) << 32) | 0x90000328ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0360ACULL;
}

// FDE #0478 | PC: 0x0360cc..0x0360d0 (4 B) | Symbol: sub_0360cc
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0360cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF62A4ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0360CCULL;
}

// FDE #0479 | PC: 0x0360d0..0x0360d4 (4 B) | Symbol: sub_0360d0
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0360d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400801ULL) << 32) | 0x17FF62A4ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0360D0ULL;
}

// FDE #0480 | PC: 0x0360d4..0x0360e0 (12 B) | Symbol: sub_0360d4
// EN: AArch64 prologue [ldr w1, [x0, #8]; ldr x2, [x0, #0x10]; b #0xed50] | VI: Khởi đầu hàm AArch64 [ldr w1, [x0, #8]; ldr x2, [x0, #0x10]; b #0xed50]
uint64_t fde_sub_0360d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400802ULL) << 32) | 0xB9400801ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0360D4ULL;
}

// FDE #0481 | PC: 0x0360e0..0x0361cc (236 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr15TCSetInt64ValueEil
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0360e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0360E0ULL;
}

// FDE #0482 | PC: 0x0361cc..0x0361ec (32 B) | Symbol: sub_0361cc
// EN: AArch64 prologue [ldrb w8, [x0, #0x10]; adrp x9, #0x9a000; add x9, x9, #0x748; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x10]; adrp x9, #0x9a000; add x9, x9, #0x748; str x9, [x0]]
uint64_t fde_sub_0361cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000329ULL) << 32) | 0x39404008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0361CCULL;
}

// FDE #0483 | PC: 0x0361ec..0x036228 (60 B) | Symbol: sub_0361ec
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]]
uint64_t fde_sub_0361ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0361ECULL;
}

// FDE #0484 | PC: 0x036228..0x036300 (216 B) | Symbol: sub_036228
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_036228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036228ULL;
}

// FDE #0485 | PC: 0x036300..0x036314 (20 B) | Symbol: sub_036300
// EN: AArch64 prologue [ldrb w8, [x0, #0x10]; tbnz w8, #0, #0x3630c; ret; ldr x0, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x10]; tbnz w8, #0, #0x3630c; ret; ldr x0, [x0, #0x20]]
uint64_t fde_sub_036300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000048ULL) << 32) | 0x39404008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036300ULL;
}

// FDE #0486 | PC: 0x036314..0x036344 (48 B) | Symbol: sub_036314
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]]
uint64_t fde_sub_036314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036314ULL;
}

// FDE #0487 | PC: 0x036344..0x036454 (272 B) | Symbol: sub_036344
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_036344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036344ULL;
}

// FDE #0488 | PC: 0x036454..0x0366d0 (636 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr16TCSetStringValueEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_036454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x027CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036454ULL;
}

// FDE #0489 | PC: 0x0366d0..0x0368e4 (532 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr17TCIsHostSupportedENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEi
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0366d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0214ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0366D0ULL;
}

// FDE #0490 | PC: 0x0368e4..0x036afc (536 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr15TCSetAltSvcInfoENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0368e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0368E4ULL;
}

// FDE #0491 | PC: 0x036afc..0x036f38 (1084 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr17TCIsHostConnectedENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEti
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_036afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x043CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036AFCULL;
}

// FDE #0492 | PC: 0x036f38..0x03703c (260 B) | Symbol: sub_036f38
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_036f38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036F38ULL;
}

// FDE #0493 | PC: 0x03703c..0x037148 (268 B) | Symbol: sub_03703c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03703c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03703CULL;
}

// FDE #0494 | PC: 0x037148..0x0371bc (116 B) | Symbol: sub_037148
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_037148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037148ULL;
}

// FDE #0495 | PC: 0x0371bc..0x0372b4 (248 B) | Symbol: sub_0371bc
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0371bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0371BCULL;
}

// FDE #0496 | PC: 0x0372b4..0x0373b4 (256 B) | Symbol: sub_0372b4
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0372b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0372B4ULL;
}

// FDE #0497 | PC: 0x0373b4..0x03749c (232 B) | Symbol: sub_0373b4
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0373b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0373B4ULL;
}

// FDE #0498 | PC: 0x03749c..0x0374f0 (84 B) | Symbol: sub_03749c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_03749c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03749CULL;
}

// FDE #0499 | PC: 0x0374f0..0x037504 (20 B) | Symbol: sub_0374f0
// EN: AArch64 prologue [cbz x0, #0x37500; ldr x8, [x0]; ldr x1, [x8, #8]; br x1] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x37500; ldr x8, [x0]; ldr x1, [x8, #8]; br x1]
uint64_t fde_sub_0374f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0374F0ULL;
}

// FDE #0500 | PC: 0x037504..0x037524 (32 B) | Symbol: sub_037504
// EN: AArch64 prologue [ldrb w8, [x0, #8]; adrp x9, #0x9a000; add x9, x9, #0x788; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #8]; adrp x9, #0x9a000; add x9, x9, #0x788; str x9, [x0]]
uint64_t fde_sub_037504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000309ULL) << 32) | 0x39402008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037504ULL;
}

// FDE #0501 | PC: 0x037524..0x037560 (60 B) | Symbol: sub_037524
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #8]]
uint64_t fde_sub_037524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037524ULL;
}

// FDE #0502 | PC: 0x037560..0x037590 (48 B) | Symbol: sub_037560
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x788; str x8, [x1]; ldr x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x788; str x8, [x1]; ldr x8, [x0, #0x18]]
uint64_t fde_sub_037560(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911E2108ULL) << 32) | 0xF0000308ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037560ULL;
}

// FDE #0503 | PC: 0x037590..0x0375a4 (20 B) | Symbol: sub_037590
// EN: AArch64 prologue [ldrb w8, [x0, #8]; tbnz w8, #0, #0x3759c; ret; ldr x0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #8]; tbnz w8, #0, #0x3759c; ret; ldr x0, [x0, #0x18]]
uint64_t fde_sub_037590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000048ULL) << 32) | 0x39402008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037590ULL;
}

// FDE #0504 | PC: 0x0375a4..0x0375d4 (48 B) | Symbol: sub_0375a4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #8]]
uint64_t fde_sub_0375a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0375A4ULL;
}

// FDE #0505 | PC: 0x0375d4..0x0376c8 (244 B) | Symbol: sub_0375d4
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_0375d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0375D4ULL;
}

// FDE #0506 | PC: 0x0376c8..0x037810 (328 B) | Symbol: sub_0376c8
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0376c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0376C8ULL;
}

// FDE #0507 | PC: 0x037810..0x037860 (80 B) | Symbol: sub_037810
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]]
uint64_t fde_sub_037810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037810ULL;
}

// FDE #0508 | PC: 0x037860..0x0378c4 (100 B) | Symbol: sub_037860
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]]
uint64_t fde_sub_037860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037860ULL;
}

// FDE #0509 | PC: 0x0378c4..0x037914 (80 B) | Symbol: sub_0378c4
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x838; str x8, [x1]; ldr x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x838; str x8, [x1]; ldr x8, [x0, #0x18]]
uint64_t fde_sub_0378c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9120E108ULL) << 32) | 0xF0000308ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0378C4ULL;
}

// FDE #0510 | PC: 0x037914..0x037958 (68 B) | Symbol: sub_037914
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]]
uint64_t fde_sub_037914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037914ULL;
}

// FDE #0511 | PC: 0x037958..0x0379b0 (88 B) | Symbol: sub_037958
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]]
uint64_t fde_sub_037958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037958ULL;
}

// FDE #0512 | PC: 0x0379b0..0x037a44 (148 B) | Symbol: sub_0379b0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50]
uint64_t fde_sub_0379b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9044FF4ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0379B0ULL;
}

// FDE #0513 | PC: 0x037a44..0x037b38 (244 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr17TCStartPreConnectENS_17PreConnectContextE
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_037a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037A44ULL;
}

// FDE #0514 | PC: 0x037b38..0x037d8c (596 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr13TCDestroyTaskEPNS_11NetworkTaskE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x0, #0x20] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x0, #0x20]
uint64_t fde_sub_037b38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0254ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037B38ULL;
}

// FDE #0515 | PC: 0x037d8c..0x037d90 (4 B) | Symbol: sub_037d8c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_037d8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000308ULL) << 32) | 0x17FF5B75ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037D8CULL;
}

// FDE #0516 | PC: 0x037d90..0x037db0 (32 B) | Symbol: sub_037d90
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x878; str x8, [x1]; ldr x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x878; str x8, [x1]; ldr x8, [x0, #0x18]]
uint64_t fde_sub_037d90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9121E108ULL) << 32) | 0xF0000308ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037D90ULL;
}

// FDE #0517 | PC: 0x037db0..0x037db4 (4 B) | Symbol: sub_037db0
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_037db0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5B6BULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037DB0ULL;
}

// FDE #0518 | PC: 0x037db4..0x037db8 (4 B) | Symbol: sub_037db4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_037db4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9408001ULL) << 32) | 0x17FF5B6BULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037DB4ULL;
}

// FDE #0519 | PC: 0x037db8..0x037dc0 (8 B) | Symbol: sub_037db8
// EN: AArch64 prologue [ldp x1, x0, [x0, #8]; b #0xf6e0] | VI: Khởi đầu hàm AArch64 [ldp x1, x0, [x0, #8]; b #0xf6e0]
uint64_t fde_sub_037db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5E49ULL) << 32) | 0xA9408001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037DB8ULL;
}

// FDE #0520 | PC: 0x037dc0..0x0381fc (1084 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr12TCCreateTaskEv
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_037dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x043CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037DC0ULL;
}

// FDE #0521 | PC: 0x0381fc..0x03842c (560 B) | Symbol: sub_0381fc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0381fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0381FCULL;
}

// FDE #0522 | PC: 0x03842c..0x038530 (260 B) | Symbol: sub_03842c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03842c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03842CULL;
}

// FDE #0523 | PC: 0x038530..0x03863c (268 B) | Symbol: sub_038530
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_038530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038530ULL;
}

// FDE #0524 | PC: 0x03863c..0x0386b0 (116 B) | Symbol: sub_03863c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_03863c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03863CULL;
}

// FDE #0525 | PC: 0x0386b0..0x0387a8 (248 B) | Symbol: sub_0386b0
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0386b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0386B0ULL;
}

// FDE #0526 | PC: 0x0387a8..0x0388a8 (256 B) | Symbol: sub_0387a8
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0387a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0387A8ULL;
}

// FDE #0527 | PC: 0x0388a8..0x03898c (228 B) | Symbol: sub_0388a8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0388a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0388A8ULL;
}

// FDE #0528 | PC: 0x03898c..0x0389e0 (84 B) | Symbol: sub_03898c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_03898c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03898CULL;
}

// FDE #0529 | PC: 0x0389e0..0x0389f4 (20 B) | Symbol: sub_0389e0
// EN: AArch64 prologue [cbz x0, #0x389f0; ldr x8, [x0]; ldr x1, [x8, #8]; br x1] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x389f0; ldr x8, [x0]; ldr x1, [x8, #8]; br x1]
uint64_t fde_sub_0389e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0389E0ULL;
}

// FDE #0530 | PC: 0x0389f4..0x0389f8 (4 B) | Symbol: sub_0389f4
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0389f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF585AULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0389F4ULL;
}

// FDE #0531 | PC: 0x0389f8..0x0389fc (4 B) | Symbol: sub_0389f8
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0389f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000308ULL) << 32) | 0x17FF585AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0389F8ULL;
}

// FDE #0532 | PC: 0x0389fc..0x038a14 (24 B) | Symbol: sub_0389fc
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x8b8; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x8b8; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_0389fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9122E108ULL) << 32) | 0xD0000308ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0389FCULL;
}

// FDE #0533 | PC: 0x038a14..0x038a18 (4 B) | Symbol: sub_038a14
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_038a14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5852ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038A14ULL;
}

// FDE #0534 | PC: 0x038a18..0x038a1c (4 B) | Symbol: sub_038a18
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_038a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0x17FF5852ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038A18ULL;
}

// FDE #0535 | PC: 0x038a1c..0x038a24 (8 B) | Symbol: sub_038a1c
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0xf0f0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0xf0f0]
uint64_t fde_sub_038a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF59B4ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038A1CULL;
}

// FDE #0536 | PC: 0x038a24..0x038a28 (4 B) | Symbol: sub_038a24
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_038a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000308ULL) << 32) | 0x17FF584FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038A24ULL;
}

// FDE #0537 | PC: 0x038a28..0x038a40 (24 B) | Symbol: sub_038a28
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x968; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x968; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_038a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9125A108ULL) << 32) | 0xD0000308ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038A28ULL;
}

// FDE #0538 | PC: 0x038a40..0x038a44 (4 B) | Symbol: sub_038a40
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_038a40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5847ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038A40ULL;
}

// FDE #0539 | PC: 0x038a44..0x038a48 (4 B) | Symbol: sub_038a44
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_038a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0x17FF5847ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038A44ULL;
}

// FDE #0540 | PC: 0x038a48..0x038ac0 (120 B) | Symbol: sub_038a48
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_038a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038A48ULL;
}

// FDE #0541 | PC: 0x038ac0..0x038ac4 (4 B) | Symbol: sub_038ac0
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_038ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000308ULL) << 32) | 0x17FF5828ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038AC0ULL;
}

// FDE #0542 | PC: 0x038ac4..0x038adc (24 B) | Symbol: sub_038ac4
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x9a8; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x9a8; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_038ac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9126A108ULL) << 32) | 0xD0000308ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038AC4ULL;
}

// FDE #0543 | PC: 0x038adc..0x038ae0 (4 B) | Symbol: sub_038adc
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_038adc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5820ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038ADCULL;
}

// FDE #0544 | PC: 0x038ae0..0x038ae4 (4 B) | Symbol: sub_038ae0
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_038ae0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0x17FF5820ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038AE0ULL;
}

// FDE #0545 | PC: 0x038ae4..0x038aec (8 B) | Symbol: sub_038ae4
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0xfb00] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0xfb00]
uint64_t fde_sub_038ae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5C06ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038AE4ULL;
}

// FDE #0546 | PC: 0x038aec..0x03a990 (7844 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr17TCStartNetworkMgrEv
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_038aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1EA4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038AECULL;
}

// FDE #0547 | PC: 0x03a990..0x03ab7c (492 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr10CertVerifyEPvPKcs
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03a990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03A990ULL;
}

// FDE #0548 | PC: 0x03ab7c..0x03ab80 (4 B) | Symbol: sub_03ab7c
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03ab7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4FF8ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AB7CULL;
}

// FDE #0549 | PC: 0x03ab80..0x03ab84 (4 B) | Symbol: sub_03ab80
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03ab80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FF4FF8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AB80ULL;
}

// FDE #0550 | PC: 0x03ab84..0x03abbc (56 B) | Symbol: sub_03ab84
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_03ab84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AB84ULL;
}

// FDE #0551 | PC: 0x03abbc..0x03abd4 (24 B) | Symbol: sub_03abbc
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x9e8; str x8, [x1]; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x9e8; str x8, [x1]; ldr x8, [x0, #8]]
uint64_t fde_sub_03abbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9127A108ULL) << 32) | 0x90000308ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ABBCULL;
}

// FDE #0552 | PC: 0x03abd4..0x03abd8 (4 B) | Symbol: sub_03abd4
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03abd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4FE2ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ABD4ULL;
}

// FDE #0553 | PC: 0x03abd8..0x03abdc (4 B) | Symbol: sub_03abd8
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03abd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400404ULL) << 32) | 0x17FF4FE2ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ABD8ULL;
}

// FDE #0554 | PC: 0x03abdc..0x03abf0 (20 B) | Symbol: sub_03abdc
// EN: AArch64 prologue [ldr x4, [x0, #8]; ldr x0, [x1]; ldr x1, [x2]; ldrh w2, [x3]] | VI: Khởi đầu hàm AArch64 [ldr x4, [x0, #8]; ldr x0, [x1]; ldr x1, [x2]; ldrh w2, [x3]]
uint64_t fde_sub_03abdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400020ULL) << 32) | 0xF9400404ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ABDCULL;
}

// FDE #0555 | PC: 0x03abf0..0x03ac48 (88 B) | Symbol: sub_03abf0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]]
uint64_t fde_sub_03abf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ABF0ULL;
}

// FDE #0556 | PC: 0x03ac48..0x03ac6c (36 B) | Symbol: sub_03ac48
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_03ac48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AC48ULL;
}

// FDE #0557 | PC: 0x03ac6c..0x03ac7c (16 B) | Symbol: sub_03ac6c
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; cbz x0, #0x3ac78; b #0xeb60; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; cbz x0, #0x3ac78; b #0xeb60; ret]
uint64_t fde_sub_03ac6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AC6CULL;
}

// FDE #0558 | PC: 0x03ac7c..0x03ac80 (4 B) | Symbol: sub_03ac7c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03ac7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FF4FB9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AC7CULL;
}

// FDE #0559 | PC: 0x03ac80..0x03ac98 (24 B) | Symbol: DestroyNetworkMgr
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xf290; mov w0, #1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xf290; mov w0, #1]
uint64_t fde_sub_03ac80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AC80ULL;
}

// FDE #0560 | PC: 0x03ac98..0x03aee8 (592 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr7DelInitEPNS_14TTKMediaNetMgrE
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_03ac98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0250ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AC98ULL;
}

// FDE #0561 | PC: 0x03aee8..0x03aeec (4 B) | Symbol: sub_03aee8
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03aee8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000308ULL) << 32) | 0x17FF4F1EULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AEE8ULL;
}

// FDE #0562 | PC: 0x03aeec..0x03af04 (24 B) | Symbol: sub_03aeec
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0xa68; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0xa68; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_03aeec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9129A108ULL) << 32) | 0x90000308ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AEECULL;
}

// FDE #0563 | PC: 0x03af04..0x03af08 (4 B) | Symbol: sub_03af04
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03af04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4F16ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AF04ULL;
}

// FDE #0564 | PC: 0x03af08..0x03af0c (4 B) | Symbol: sub_03af08
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03af08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0x17FF4F16ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AF08ULL;
}

// FDE #0565 | PC: 0x03af0c..0x03af14 (8 B) | Symbol: sub_03af0c
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0xed60] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0xed60]
uint64_t fde_sub_03af0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4F94ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AF0CULL;
}

// FDE #0566 | PC: 0x03af14..0x03b058 (324 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr9TCDelInitEPNS_14TTKMediaNetMgrE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9d000]
uint64_t fde_sub_03af14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AF14ULL;
}

// FDE #0567 | PC: 0x03b058..0x03b0c0 (104 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr13GetNetworkMgrEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000]
uint64_t fde_sub_03b058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B058ULL;
}

// FDE #0568 | PC: 0x03b0c0..0x03b170 (176 B) | Symbol: _ZN11TTKMediaNet10NetworkMgrC2Ev
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03b0c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B0C0ULL;
}

// FDE #0569 | PC: 0x03b170..0x03b1dc (108 B) | Symbol: _ZN11TTKMediaNet10NetworkMgr16TCStopNetworkMgrEv
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03b170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B170ULL;
}

// FDE #0570 | PC: 0x03b1dc..0x03b59c (960 B) | Symbol: sub_03b1dc
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03b1dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x03C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B1DCULL;
}

// FDE #0571 | PC: 0x03b59c..0x03b5f4 (88 B) | Symbol: sub_03b59c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]]
uint64_t fde_sub_03b59c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B59CULL;
}

// FDE #0572 | PC: 0x03b5f4..0x03b618 (36 B) | Symbol: sub_03b5f4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_03b5f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B5F4ULL;
}

// FDE #0573 | PC: 0x03b618..0x03b90c (756 B) | Symbol: sub_03b618
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03b618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x02F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B618ULL;
}

// FDE #0574 | PC: 0x03b90c..0x03b910 (4 B) | Symbol: sub_03b90c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03b90c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0x17FF4C95ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B90CULL;
}

// FDE #0575 | PC: 0x03b910..0x03b9b8 (168 B) | Symbol: sub_03b910
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03b910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B910ULL;
}

// FDE #0576 | PC: 0x03b9b8..0x03ba68 (176 B) | Symbol: sub_03b9b8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03b9b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B9B8ULL;
}

// FDE #0577 | PC: 0x03ba68..0x03ba74 (12 B) | Symbol: sub_03ba68
// EN: AArch64 prologue [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1]
uint64_t fde_sub_03ba68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400101ULL) << 32) | 0xF8418C08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BA68ULL;
}

// FDE #0578 | PC: 0x03ba74..0x03ba78 (4 B) | Symbol: sub_03ba74
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03ba74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FF4C3BULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BA74ULL;
}

// FDE #0579 | PC: 0x03ba78..0x03baf4 (124 B) | Symbol: sub_03ba78
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]]
uint64_t fde_sub_03ba78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BA78ULL;
}

// FDE #0580 | PC: 0x03baf4..0x03bb6c (120 B) | Symbol: sub_03baf4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]]
uint64_t fde_sub_03baf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BAF4ULL;
}

// FDE #0581 | PC: 0x03bb6c..0x03bbd0 (100 B) | Symbol: sub_03bb6c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]]
uint64_t fde_sub_03bb6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BB6CULL;
}

// FDE #0582 | PC: 0x03bbd0..0x03bbd4 (4 B) | Symbol: sub_03bbd0
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03bbd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FF4BE4ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BBD0ULL;
}

// FDE #0583 | PC: 0x03bbd4..0x03bc70 (156 B) | Symbol: sub_03bbd4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x30]]
uint64_t fde_sub_03bbd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BBD4ULL;
}

// FDE #0584 | PC: 0x03bc70..0x03bd14 (164 B) | Symbol: sub_03bc70
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x30]]
uint64_t fde_sub_03bc70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BC70ULL;
}

// FDE #0585 | PC: 0x03bd14..0x03bda8 (148 B) | Symbol: sub_03bd14
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x30]]
uint64_t fde_sub_03bd14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BD14ULL;
}

// FDE #0586 | PC: 0x03bda8..0x03bdac (4 B) | Symbol: sub_03bda8
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03bda8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002E8ULL) << 32) | 0x17FF4B6EULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BDA8ULL;
}

// FDE #0587 | PC: 0x03bdac..0x03bdbc (16 B) | Symbol: sub_03bdac
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0xaa8; str x8, [x0]; b #0xeef0] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0xaa8; str x8, [x0]; b #0xeef0]
uint64_t fde_sub_03bdac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912AA108ULL) << 32) | 0xF00002E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BDACULL;
}

// FDE #0588 | PC: 0x03bdbc..0x03bdec (48 B) | Symbol: sub_03bdbc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_03bdbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BDBCULL;
}

// FDE #0589 | PC: 0x03bdec..0x03bdf0 (4 B) | Symbol: sub_03bdec
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03bdec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4B5CULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BDECULL;
}

// FDE #0590 | PC: 0x03bdf0..0x03bdf4 (4 B) | Symbol: sub_03bdf0
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03bdf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0x17FF4B5CULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BDF0ULL;
}

// FDE #0591 | PC: 0x03bdf4..0x03bf9c (424 B) | Symbol: sub_03bdf4
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03bdf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BDF4ULL;
}

// FDE #0592 | PC: 0x03bf9c..0x03bfc0 (36 B) | Symbol: sub_03bf9c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_03bf9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BF9CULL;
}

// FDE #0593 | PC: 0x03bfc0..0x03c68c (1740 B) | Symbol: sub_03bfc0
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_03bfc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x06CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BFC0ULL;
}

// FDE #0594 | PC: 0x03c68c..0x03c690 (4 B) | Symbol: sub_03c68c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03c68c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FF4935ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C68CULL;
}

// FDE #0595 | PC: 0x03c690..0x03c6b4 (36 B) | Symbol: sub_03c690
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_03c690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C690ULL;
}

// FDE #0596 | PC: 0x03c6b4..0x03c7d4 (288 B) | Symbol: sub_03c6b4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_03c6b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C6B4ULL;
}

// FDE #0597 | PC: 0x03c7d4..0x03c7d8 (4 B) | Symbol: sub_03c7d4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_03c7d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0x17FF48E3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C7D4ULL;
}

// FDE #0598 | PC: 0x03c7d8..0x03cadc (772 B) | Symbol: sub_03c7d8
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_03c7d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0304ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C7D8ULL;
}

// FDE #0599 | PC: 0x03cadc..0x03cca8 (460 B) | Symbol: sub_03cadc
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_03cadc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CADCULL;
}

// FDE #0600 | PC: 0x03cca8..0x03cf3c (660 B) | Symbol: sub_03cca8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03cca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0294ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CCA8ULL;
}

// FDE #0601 | PC: 0x03cf3c..0x03cf48 (12 B) | Symbol: sub_03cf3c
// EN: AArch64 prologue [ldr w8, [x2]; str w8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x2]; str w8, [x1]; ret]
uint64_t fde_sub_03cf3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9000028ULL) << 32) | 0xB9400048ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CF3CULL;
}

// FDE #0602 | PC: 0x03cf48..0x03cf54 (12 B) | Symbol: sub_03cf48
// EN: AArch64 prologue [ldr x8, [x2]; str x8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2]; str x8, [x1]; ret]
uint64_t fde_sub_03cf48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000028ULL) << 32) | 0xF9400048ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CF48ULL;
}

// FDE #0603 | PC: 0x03cf54..0x03cf60 (12 B) | Symbol: sub_03cf54
// EN: AArch64 prologue [ldr x8, [x2]; str x8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2]; str x8, [x1]; ret]
uint64_t fde_sub_03cf54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000028ULL) << 32) | 0xF9400048ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CF54ULL;
}

// FDE #0604 | PC: 0x03cf60..0x03d014 (180 B) | Symbol: sub_03cf60
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03cf60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CF60ULL;
}

// FDE #0605 | PC: 0x03d014..0x03d020 (12 B) | Symbol: sub_03d014
// EN: AArch64 prologue [ldr q0, [x2]; str q0, [x1]; ret] | VI: Khởi đầu hàm AArch64 [ldr q0, [x2]; str q0, [x1]; ret]
uint64_t fde_sub_03d014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D800020ULL) << 32) | 0x3DC00040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D014ULL;
}

// FDE #0606 | PC: 0x03d020..0x03d128 (264 B) | Symbol: sub_03d020
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03d020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D020ULL;
}

// FDE #0607 | PC: 0x03d128..0x03d358 (560 B) | Symbol: sub_03d128
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_03d128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D128ULL;
}

// FDE #0608 | PC: 0x03d358..0x03d400 (168 B) | Symbol: sub_03d358
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03d358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D358ULL;
}

// FDE #0609 | PC: 0x03d400..0x03d4a8 (168 B) | Symbol: sub_03d400
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03d400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D400ULL;
}

// FDE #0610 | PC: 0x03d4a8..0x03d550 (168 B) | Symbol: sub_03d4a8
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03d4a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D4A8ULL;
}

// FDE #0611 | PC: 0x03d550..0x03d6b0 (352 B) | Symbol: sub_03d550
// EN: AArch64 prologue [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_03d550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF9ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D550ULL;
}

// FDE #0612 | PC: 0x03d6b0..0x03d760 (176 B) | Symbol: sub_03d6b0
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03d6b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D6B0ULL;
}

// FDE #0613 | PC: 0x03d760..0x03d764 (4 B) | Symbol: sub_03d760
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03d760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D760ULL;
}

// FDE #0614 | PC: 0x03d764..0x03d768 (4 B) | Symbol: sub_03d764
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03d764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D764ULL;
}

// FDE #0615 | PC: 0x03d768..0x03d76c (4 B) | Symbol: sub_03d768
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03d768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400028ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D768ULL;
}

// FDE #0616 | PC: 0x03d76c..0x03d780 (20 B) | Symbol: sub_03d76c
// EN: AArch64 prologue [ldrb w8, [x1]; tbnz w8, #0, #0x3d778; ret; ldr x0, [x1, #0x10]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x1]; tbnz w8, #0, #0x3d778; ret; ldr x0, [x1, #0x10]]
uint64_t fde_sub_03d76c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000048ULL) << 32) | 0x39400028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D76CULL;
}

// FDE #0617 | PC: 0x03d780..0x03d784 (4 B) | Symbol: sub_03d780
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_03d780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D780ULL;
}

// FDE #0618 | PC: 0x03d784..0x03d8a0 (284 B) | Symbol: sub_03d784
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x9, [x0, #8]; cbz x9, #0x3d870] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x9, [x0, #8]; cbz x9, #0x3d870]
uint64_t fde_sub_03d784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D784ULL;
}

// FDE #0619 | PC: 0x03d8a0..0x03dc60 (960 B) | Symbol: sub_03d8a0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_03d8a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x03C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D8A0ULL;
}

// FDE #0620 | PC: 0x03dc60..0x03e018 (952 B) | Symbol: sub_03dc60
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_03dc60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x03B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03DC60ULL;
}

// FDE #0621 | PC: 0x03e018..0x03e54c (1332 B) | Symbol: sub_03e018
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_03e018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90367FAULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0534ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E018ULL;
}

// FDE #0622 | PC: 0x03e54c..0x03efc4 (2680 B) | Symbol: sub_03e54c
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_03e54c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0A78ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E54CULL;
}

// FDE #0623 | PC: 0x03efc4..0x03efd0 (12 B) | Symbol: sub_03efc4
// EN: AArch64 prologue [ldr x0, [x0, #0x30]; mov w1, #4; b #0x76a48] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x30]; mov w1, #4; b #0x76a48]
uint64_t fde_sub_03efc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800081ULL) << 32) | 0xF9401800ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03EFC4ULL;
}

// FDE #0624 | PC: 0x03efd0..0x03f044 (116 B) | Symbol: sub_03efd0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_03efd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03EFD0ULL;
}

// FDE #0625 | PC: 0x03f044..0x03f18c (328 B) | Symbol: sub_03f044
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03f044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F044ULL;
}

// FDE #0626 | PC: 0x03f18c..0x03f24c (192 B) | Symbol: sub_03f18c
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_03f18c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F18CULL;
}

// FDE #0627 | PC: 0x03f24c..0x03f544 (760 B) | Symbol: sub_03f24c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03f24c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x02F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F24CULL;
}

// FDE #0628 | PC: 0x03f544..0x03f604 (192 B) | Symbol: sub_03f544
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_03f544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F544ULL;
}

// FDE #0629 | PC: 0x03f604..0x03f734 (304 B) | Symbol: sub_03f604
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_03f604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F604ULL;
}

// FDE #0630 | PC: 0x03f734..0x03f91c (488 B) | Symbol: sub_03f734
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03f734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F734ULL;
}

// FDE #0631 | PC: 0x03f91c..0x03fa48 (300 B) | Symbol: sub_03f91c
// EN: AArch64 prologue [ldr x9, [x0, #8]; cbz x9, #0x3fa24; ldr x8, [x1]; mov x10, #0x2d69] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #8]; cbz x9, #0x3fa24; ldr x8, [x1]; mov x10, #0x2d69]
uint64_t fde_sub_03f91c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000829ULL) << 32) | 0xF9400409ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F91CULL;
}

// FDE #0632 | PC: 0x03fa48..0x03fb70 (296 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03fa48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03FA48ULL;
}

// FDE #0633 | PC: 0x03fb70..0x04091c (3500 B) | Symbol: sub_03fb70
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]]
uint64_t fde_sub_03fb70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C6FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0DACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03FB70ULL;
}

// FDE #0634 | PC: 0x04091c..0x0409dc (192 B) | Symbol: sub_04091c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_04091c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04091CULL;
}

// FDE #0635 | PC: 0x0409dc..0x040bac (464 B) | Symbol: sub_0409dc
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_0409dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90857F6ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0409DCULL;
}

// FDE #0636 | PC: 0x040bac..0x040bfc (80 B) | Symbol: sub_040bac
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #0x10] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #0x10]
uint64_t fde_sub_040bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040BACULL;
}

// FDE #0637 | PC: 0x040bfc..0x040c20 (36 B) | Symbol: sub_040bfc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_040bfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040BFCULL;
}

// FDE #0638 | PC: 0x040c20..0x040c38 (24 B) | Symbol: sub_040c20
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; cbz x0, #0x40c34; ldr x8, [x0]; ldr x1, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; cbz x0, #0x40c34; ldr x8, [x0]; ldr x1, [x8, #8]]
uint64_t fde_sub_040c20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000080ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040C20ULL;
}

// FDE #0639 | PC: 0x040c38..0x040c3c (4 B) | Symbol: sub_040c38
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_040c38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002C8ULL) << 32) | 0x17FF37CAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040C38ULL;
}

// FDE #0640 | PC: 0x040c3c..0x040c4c (16 B) | Symbol: sub_040c3c
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0xca8; str x8, [x0]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0xca8; str x8, [x0]; ret]
uint64_t fde_sub_040c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9132A108ULL) << 32) | 0xD00002C8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040C3CULL;
}

// FDE #0641 | PC: 0x040c4c..0x040c50 (4 B) | Symbol: sub_040c4c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_040c4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD105C3FFULL) << 32) | 0x17FF37C5ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040C4CULL;
}

// FDE #0642 | PC: 0x040c50..0x041040 (1008 B) | Symbol: sub_040c50
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]; stp x22, x21, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]; stp x22, x21, [sp, #0x140]]
uint64_t fde_sub_040c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91267FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x03F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040C50ULL;
}

// FDE #0643 | PC: 0x041040..0x041048 (8 B) | Symbol: sub_041040
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_041040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041040ULL;
}

// FDE #0644 | PC: 0x041048..0x041320 (728 B) | Symbol: sub_041048
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_041048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x02D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041048ULL;
}

// FDE #0645 | PC: 0x041320..0x04137c (92 B) | Symbol: sub_041320
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]]
uint64_t fde_sub_041320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041320ULL;
}

// FDE #0646 | PC: 0x04137c..0x0415ac (560 B) | Symbol: sub_04137c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_04137c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04137CULL;
}

// FDE #0647 | PC: 0x0415ac..0x0415fc (80 B) | Symbol: sub_0415ac
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20; adrp x11, #0x9b000] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20; adrp x11, #0x9b000]
uint64_t fde_sub_0415ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BFDULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0415ACULL;
}

// FDE #0648 | PC: 0x0415fc..0x041608 (12 B) | Symbol: sub_0415fc
// EN: AArch64 prologue [cbz x0, #0x41604; ldr x0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x41604; ldr x0, [x0]; ret]
uint64_t fde_sub_0415fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0415FCULL;
}

// FDE #0649 | PC: 0x041608..0x04160c (4 B) | Symbol: sub_041608
// EN: AArch64 prologue [b #0x4fa94] | VI: Khởi đầu hàm AArch64 [b #0x4fa94]
uint64_t fde_sub_041608(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x14003923ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041608ULL;
}

// FDE #0650 | PC: 0x04160c..0x041694 (136 B) | Symbol: sub_04160c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x2, #0x41680] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x2, #0x41680]
uint64_t fde_sub_04160c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04160CULL;
}

// FDE #0651 | PC: 0x041694..0x0416b8 (36 B) | Symbol: sub_041694
// EN: AArch64 prologue [cbz x1, #0x416b0; cmp w0, #0; mov w8, #0xc8; mov w9, #0xd0] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x416b0; cmp w0, #0; mov w8, #0xc8; mov w9, #0xd0]
uint64_t fde_sub_041694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100001FULL) << 32) | 0xB40000E1ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041694ULL;
}

// FDE #0652 | PC: 0x0416b8..0x041900 (584 B) | Symbol: sub_0416b8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0416b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0248ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0416B8ULL;
}

// FDE #0653 | PC: 0x041900..0x041974 (116 B) | Symbol: sub_041900
// EN: AArch64 prologue [cmp x1, #4; mov x8, x0; b.hs #0x41934; adrp x9, #0x7c000] | VI: Khởi đầu hàm AArch64 [cmp x1, #4; mov x8, x0; b.hs #0x41934; adrp x9, #0x7c000]
uint64_t fde_sub_041900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xF100103FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041900ULL;
}

// FDE #0654 | PC: 0x041974..0x041998 (36 B) | Symbol: sub_041974
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; tbz w8, #6, #0x41988; ldr x8, [x0, #0xb8]; cmp x8, x1] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; tbz w8, #6, #0x41988; ldr x8, [x0, #0xb8]; cmp x8, x1]
uint64_t fde_sub_041974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x36300088ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041974ULL;
}

// FDE #0655 | PC: 0x041998..0x041a2c (148 B) | Symbol: sub_041998
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x2] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x2]
uint64_t fde_sub_041998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041998ULL;
}

// FDE #0656 | PC: 0x041a2c..0x041a34 (8 B) | Symbol: sub_041a2c
// EN: AArch64 prologue [ldr x0, [x0, #0xc0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0xc0]; ret]
uint64_t fde_sub_041a2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9406000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041A2CULL;
}

// FDE #0657 | PC: 0x041a34..0x041adc (168 B) | Symbol: sub_041a34
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_041a34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041A34ULL;
}

uint64_t DispatchTtkMediaNetShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x02c844ULL: return fde_sub_02c844(a0, a1, a2);
        case 0x02c894ULL: return fde_sub_02c894(a0, a1, a2);
        case 0x02c904ULL: return fde_sub_02c904(a0, a1, a2);
        case 0x02c97cULL: return fde_sub_02c97c(a0, a1, a2);
        case 0x02c9f0ULL: return fde_sub_02c9f0(a0, a1, a2);
        case 0x02ca6cULL: return fde_sub_02ca6c(a0, a1, a2);
        case 0x02cae8ULL: return fde_sub_02cae8(a0, a1, a2);
        case 0x02cb6cULL: return fde_sub_02cb6c(a0, a1, a2);
        case 0x02cc3cULL: return fde_sub_02cc3c(a0, a1, a2);
        case 0x02cd74ULL: return fde_sub_02cd74(a0, a1, a2);
        case 0x02d4f4ULL: return fde_sub_02d4f4(a0, a1, a2);
        case 0x02d600ULL: return fde_sub_02d600(a0, a1, a2);
        case 0x02d638ULL: return fde_sub_02d638(a0, a1, a2);
        case 0x02d67cULL: return fde_sub_02d67c(a0, a1, a2);
        case 0x02d6c0ULL: return fde_sub_02d6c0(a0, a1, a2);
        case 0x02d710ULL: return fde_sub_02d710(a0, a1, a2);
        case 0x02d8c4ULL: return fde_sub_02d8c4(a0, a1, a2);
        case 0x02d9e8ULL: return fde_sub_02d9e8(a0, a1, a2);
        case 0x02dae8ULL: return fde_sub_02dae8(a0, a1, a2);
        case 0x02db0cULL: return fde_sub_02db0c(a0, a1, a2);
        case 0x02db2cULL: return fde_sub_02db2c(a0, a1, a2);
        case 0x02db4cULL: return fde_sub_02db4c(a0, a1, a2);
        case 0x02db6cULL: return fde_sub_02db6c(a0, a1, a2);
        case 0x02dbf8ULL: return fde_sub_02dbf8(a0, a1, a2);
        case 0x02dd7cULL: return fde_sub_02dd7c(a0, a1, a2);
        case 0x02ef00ULL: return fde_sub_02ef00(a0, a1, a2);
        case 0x02efecULL: return fde_sub_02efec(a0, a1, a2);
        case 0x02f050ULL: return fde_sub_02f050(a0, a1, a2);
        case 0x02f0c4ULL: return fde_sub_02f0c4(a0, a1, a2);
        case 0x02f0e8ULL: return fde_sub_02f0e8(a0, a1, a2);
        case 0x02f140ULL: return fde_sub_02f140(a0, a1, a2);
        case 0x02f1a8ULL: return fde_sub_02f1a8(a0, a1, a2);
        case 0x02f224ULL: return fde_sub_02f224(a0, a1, a2);
        case 0x02f54cULL: return fde_sub_02f54c(a0, a1, a2);
        case 0x02f5d0ULL: return fde_sub_02f5d0(a0, a1, a2);
        case 0x02f664ULL: return fde_sub_02f664(a0, a1, a2);
        case 0x02f700ULL: return fde_sub_02f700(a0, a1, a2);
        case 0x02fc08ULL: return fde_sub_02fc08(a0, a1, a2);
        case 0x03005cULL: return fde_sub_03005c(a0, a1, a2);
        case 0x030458ULL: return fde_sub_030458(a0, a1, a2);
        case 0x030854ULL: return fde_sub_030854(a0, a1, a2);
        case 0x030c00ULL: return fde_sub_030c00(a0, a1, a2);
        case 0x031054ULL: return fde_sub_031054(a0, a1, a2);
        case 0x0312b8ULL: return fde_sub_0312b8(a0, a1, a2);
        case 0x0312c0ULL: return fde_sub_0312c0(a0, a1, a2);
        case 0x0312c8ULL: return fde_sub_0312c8(a0, a1, a2);
        case 0x031330ULL: return fde_sub_031330(a0, a1, a2);
        case 0x0313b0ULL: return fde_sub_0313b0(a0, a1, a2);
        case 0x031418ULL: return fde_sub_031418(a0, a1, a2);
        case 0x03155cULL: return fde_sub_03155c(a0, a1, a2);
        case 0x0315f4ULL: return fde_sub_0315f4(a0, a1, a2);
        case 0x0315fcULL: return fde_sub_0315fc(a0, a1, a2);
        case 0x031664ULL: return fde_sub_031664(a0, a1, a2);
        case 0x0316e4ULL: return fde_sub_0316e4(a0, a1, a2);
        case 0x03174cULL: return fde_sub_03174c(a0, a1, a2);
        case 0x031754ULL: return fde_sub_031754(a0, a1, a2);
        case 0x031758ULL: return fde_sub_031758(a0, a1, a2);
        case 0x031778ULL: return fde_sub_031778(a0, a1, a2);
        case 0x03177cULL: return fde_sub_03177c(a0, a1, a2);
        case 0x031780ULL: return fde_sub_031780(a0, a1, a2);
        case 0x0317c0ULL: return fde_sub_0317c0(a0, a1, a2);
        case 0x0317e0ULL: return fde_sub_0317e0(a0, a1, a2);
        case 0x03181cULL: return fde_sub_03181c(a0, a1, a2);
        case 0x0318f4ULL: return fde_sub_0318f4(a0, a1, a2);
        case 0x031908ULL: return fde_sub_031908(a0, a1, a2);
        case 0x031938ULL: return fde_sub_031938(a0, a1, a2);
        case 0x031a20ULL: return fde_sub_031a20(a0, a1, a2);
        case 0x031c30ULL: return fde_sub_031c30(a0, a1, a2);
        case 0x031d2cULL: return fde_sub_031d2c(a0, a1, a2);
        case 0x031ddcULL: return fde_sub_031ddc(a0, a1, a2);
        case 0x031ec0ULL: return fde_sub_031ec0(a0, a1, a2);
        case 0x031fc4ULL: return fde_sub_031fc4(a0, a1, a2);
        case 0x0320d0ULL: return fde_sub_0320d0(a0, a1, a2);
        case 0x032144ULL: return fde_sub_032144(a0, a1, a2);
        case 0x03223cULL: return fde_sub_03223c(a0, a1, a2);
        case 0x03233cULL: return fde_sub_03233c(a0, a1, a2);
        case 0x03241cULL: return fde_sub_03241c(a0, a1, a2);
        case 0x032468ULL: return fde_sub_032468(a0, a1, a2);
        case 0x0324bcULL: return fde_sub_0324bc(a0, a1, a2);
        case 0x0324d0ULL: return fde_sub_0324d0(a0, a1, a2);
        case 0x0324d4ULL: return fde_sub_0324d4(a0, a1, a2);
        case 0x0324d8ULL: return fde_sub_0324d8(a0, a1, a2);
        case 0x0324f0ULL: return fde_sub_0324f0(a0, a1, a2);
        case 0x0324f4ULL: return fde_sub_0324f4(a0, a1, a2);
        case 0x0324f8ULL: return fde_sub_0324f8(a0, a1, a2);
        case 0x032500ULL: return fde_sub_032500(a0, a1, a2);
        case 0x032504ULL: return fde_sub_032504(a0, a1, a2);
        case 0x03251cULL: return fde_sub_03251c(a0, a1, a2);
        case 0x032520ULL: return fde_sub_032520(a0, a1, a2);
        case 0x032524ULL: return fde_sub_032524(a0, a1, a2);
        case 0x0325c4ULL: return fde_sub_0325c4(a0, a1, a2);
        case 0x0325c8ULL: return fde_sub_0325c8(a0, a1, a2);
        case 0x0325e8ULL: return fde_sub_0325e8(a0, a1, a2);
        case 0x0325ecULL: return fde_sub_0325ec(a0, a1, a2);
        case 0x0325f0ULL: return fde_sub_0325f0(a0, a1, a2);
        case 0x032650ULL: return fde_sub_032650(a0, a1, a2);
        case 0x032654ULL: return fde_sub_032654(a0, a1, a2);
        case 0x032674ULL: return fde_sub_032674(a0, a1, a2);
        case 0x032678ULL: return fde_sub_032678(a0, a1, a2);
        case 0x03267cULL: return fde_sub_03267c(a0, a1, a2);
        case 0x0327a0ULL: return fde_sub_0327a0(a0, a1, a2);
        case 0x032830ULL: return fde_sub_032830(a0, a1, a2);
        case 0x0328ccULL: return fde_sub_0328cc(a0, a1, a2);
        case 0x0329a8ULL: return fde_sub_0329a8(a0, a1, a2);
        case 0x032a2cULL: return fde_sub_032a2c(a0, a1, a2);
        case 0x032abcULL: return fde_sub_032abc(a0, a1, a2);
        case 0x032c8cULL: return fde_sub_032c8c(a0, a1, a2);
        case 0x032ea4ULL: return fde_sub_032ea4(a0, a1, a2);
        case 0x032ec8ULL: return fde_sub_032ec8(a0, a1, a2);
        case 0x032ee0ULL: return fde_sub_032ee0(a0, a1, a2);
        case 0x032ee4ULL: return fde_sub_032ee4(a0, a1, a2);
        case 0x033004ULL: return fde_sub_033004(a0, a1, a2);
        case 0x033058ULL: return fde_sub_033058(a0, a1, a2);
        case 0x033088ULL: return fde_sub_033088(a0, a1, a2);
        case 0x033128ULL: return fde_sub_033128(a0, a1, a2);
        case 0x0331a0ULL: return fde_sub_0331a0(a0, a1, a2);
        case 0x03322cULL: return fde_sub_03322c(a0, a1, a2);
        case 0x0332b0ULL: return fde_sub_0332b0(a0, a1, a2);
        case 0x0332e0ULL: return fde_sub_0332e0(a0, a1, a2);
        case 0x033398ULL: return fde_sub_033398(a0, a1, a2);
        case 0x0333ecULL: return fde_sub_0333ec(a0, a1, a2);
        case 0x033464ULL: return fde_sub_033464(a0, a1, a2);
        case 0x0334a0ULL: return fde_sub_0334a0(a0, a1, a2);
        case 0x0338e8ULL: return fde_sub_0338e8(a0, a1, a2);
        case 0x0338ecULL: return fde_sub_0338ec(a0, a1, a2);
        case 0x033b90ULL: return fde_sub_033b90(a0, a1, a2);
        case 0x033be8ULL: return fde_sub_033be8(a0, a1, a2);
        case 0x033c0cULL: return fde_sub_033c0c(a0, a1, a2);
        case 0x033c24ULL: return fde_sub_033c24(a0, a1, a2);
        case 0x033c28ULL: return fde_sub_033c28(a0, a1, a2);
        case 0x033ca8ULL: return fde_sub_033ca8(a0, a1, a2);
        case 0x033d24ULL: return fde_sub_033d24(a0, a1, a2);
        case 0x033fa8ULL: return fde_sub_033fa8(a0, a1, a2);
        case 0x034228ULL: return fde_sub_034228(a0, a1, a2);
        case 0x0346f4ULL: return fde_sub_0346f4(a0, a1, a2);
        case 0x034aa8ULL: return fde_sub_034aa8(a0, a1, a2);
        case 0x034db8ULL: return fde_sub_034db8(a0, a1, a2);
        case 0x0353fcULL: return fde_sub_0353fc(a0, a1, a2);
        case 0x0355ccULL: return fde_sub_0355cc(a0, a1, a2);
        case 0x0356e0ULL: return fde_sub_0356e0(a0, a1, a2);
        case 0x035b38ULL: return fde_sub_035b38(a0, a1, a2);
        case 0x035da0ULL: return fde_sub_035da0(a0, a1, a2);
        case 0x035da8ULL: return fde_sub_035da8(a0, a1, a2);
        case 0x035e80ULL: return fde_sub_035e80(a0, a1, a2);
        case 0x035fa4ULL: return fde_sub_035fa4(a0, a1, a2);
        case 0x036024ULL: return fde_sub_036024(a0, a1, a2);
        case 0x0360a0ULL: return fde_sub_0360a0(a0, a1, a2);
        case 0x0360a8ULL: return fde_sub_0360a8(a0, a1, a2);
        case 0x0360acULL: return fde_sub_0360ac(a0, a1, a2);
        case 0x0360ccULL: return fde_sub_0360cc(a0, a1, a2);
        case 0x0360d0ULL: return fde_sub_0360d0(a0, a1, a2);
        case 0x0360d4ULL: return fde_sub_0360d4(a0, a1, a2);
        case 0x0360e0ULL: return fde_sub_0360e0(a0, a1, a2);
        case 0x0361ccULL: return fde_sub_0361cc(a0, a1, a2);
        case 0x0361ecULL: return fde_sub_0361ec(a0, a1, a2);
        case 0x036228ULL: return fde_sub_036228(a0, a1, a2);
        case 0x036300ULL: return fde_sub_036300(a0, a1, a2);
        case 0x036314ULL: return fde_sub_036314(a0, a1, a2);
        case 0x036344ULL: return fde_sub_036344(a0, a1, a2);
        case 0x036454ULL: return fde_sub_036454(a0, a1, a2);
        case 0x0366d0ULL: return fde_sub_0366d0(a0, a1, a2);
        case 0x0368e4ULL: return fde_sub_0368e4(a0, a1, a2);
        case 0x036afcULL: return fde_sub_036afc(a0, a1, a2);
        case 0x036f38ULL: return fde_sub_036f38(a0, a1, a2);
        case 0x03703cULL: return fde_sub_03703c(a0, a1, a2);
        case 0x037148ULL: return fde_sub_037148(a0, a1, a2);
        case 0x0371bcULL: return fde_sub_0371bc(a0, a1, a2);
        case 0x0372b4ULL: return fde_sub_0372b4(a0, a1, a2);
        case 0x0373b4ULL: return fde_sub_0373b4(a0, a1, a2);
        case 0x03749cULL: return fde_sub_03749c(a0, a1, a2);
        case 0x0374f0ULL: return fde_sub_0374f0(a0, a1, a2);
        case 0x037504ULL: return fde_sub_037504(a0, a1, a2);
        case 0x037524ULL: return fde_sub_037524(a0, a1, a2);
        case 0x037560ULL: return fde_sub_037560(a0, a1, a2);
        case 0x037590ULL: return fde_sub_037590(a0, a1, a2);
        case 0x0375a4ULL: return fde_sub_0375a4(a0, a1, a2);
        case 0x0375d4ULL: return fde_sub_0375d4(a0, a1, a2);
        case 0x0376c8ULL: return fde_sub_0376c8(a0, a1, a2);
        case 0x037810ULL: return fde_sub_037810(a0, a1, a2);
        case 0x037860ULL: return fde_sub_037860(a0, a1, a2);
        case 0x0378c4ULL: return fde_sub_0378c4(a0, a1, a2);
        case 0x037914ULL: return fde_sub_037914(a0, a1, a2);
        case 0x037958ULL: return fde_sub_037958(a0, a1, a2);
        case 0x0379b0ULL: return fde_sub_0379b0(a0, a1, a2);
        case 0x037a44ULL: return fde_sub_037a44(a0, a1, a2);
        case 0x037b38ULL: return fde_sub_037b38(a0, a1, a2);
        case 0x037d8cULL: return fde_sub_037d8c(a0, a1, a2);
        case 0x037d90ULL: return fde_sub_037d90(a0, a1, a2);
        case 0x037db0ULL: return fde_sub_037db0(a0, a1, a2);
        case 0x037db4ULL: return fde_sub_037db4(a0, a1, a2);
        case 0x037db8ULL: return fde_sub_037db8(a0, a1, a2);
        case 0x037dc0ULL: return fde_sub_037dc0(a0, a1, a2);
        case 0x0381fcULL: return fde_sub_0381fc(a0, a1, a2);
        case 0x03842cULL: return fde_sub_03842c(a0, a1, a2);
        case 0x038530ULL: return fde_sub_038530(a0, a1, a2);
        case 0x03863cULL: return fde_sub_03863c(a0, a1, a2);
        case 0x0386b0ULL: return fde_sub_0386b0(a0, a1, a2);
        case 0x0387a8ULL: return fde_sub_0387a8(a0, a1, a2);
        case 0x0388a8ULL: return fde_sub_0388a8(a0, a1, a2);
        case 0x03898cULL: return fde_sub_03898c(a0, a1, a2);
        case 0x0389e0ULL: return fde_sub_0389e0(a0, a1, a2);
        case 0x0389f4ULL: return fde_sub_0389f4(a0, a1, a2);
        case 0x0389f8ULL: return fde_sub_0389f8(a0, a1, a2);
        case 0x0389fcULL: return fde_sub_0389fc(a0, a1, a2);
        case 0x038a14ULL: return fde_sub_038a14(a0, a1, a2);
        case 0x038a18ULL: return fde_sub_038a18(a0, a1, a2);
        case 0x038a1cULL: return fde_sub_038a1c(a0, a1, a2);
        case 0x038a24ULL: return fde_sub_038a24(a0, a1, a2);
        case 0x038a28ULL: return fde_sub_038a28(a0, a1, a2);
        case 0x038a40ULL: return fde_sub_038a40(a0, a1, a2);
        case 0x038a44ULL: return fde_sub_038a44(a0, a1, a2);
        case 0x038a48ULL: return fde_sub_038a48(a0, a1, a2);
        case 0x038ac0ULL: return fde_sub_038ac0(a0, a1, a2);
        case 0x038ac4ULL: return fde_sub_038ac4(a0, a1, a2);
        case 0x038adcULL: return fde_sub_038adc(a0, a1, a2);
        case 0x038ae0ULL: return fde_sub_038ae0(a0, a1, a2);
        case 0x038ae4ULL: return fde_sub_038ae4(a0, a1, a2);
        case 0x038aecULL: return fde_sub_038aec(a0, a1, a2);
        case 0x03a990ULL: return fde_sub_03a990(a0, a1, a2);
        case 0x03ab7cULL: return fde_sub_03ab7c(a0, a1, a2);
        case 0x03ab80ULL: return fde_sub_03ab80(a0, a1, a2);
        case 0x03ab84ULL: return fde_sub_03ab84(a0, a1, a2);
        case 0x03abbcULL: return fde_sub_03abbc(a0, a1, a2);
        case 0x03abd4ULL: return fde_sub_03abd4(a0, a1, a2);
        case 0x03abd8ULL: return fde_sub_03abd8(a0, a1, a2);
        case 0x03abdcULL: return fde_sub_03abdc(a0, a1, a2);
        case 0x03abf0ULL: return fde_sub_03abf0(a0, a1, a2);
        case 0x03ac48ULL: return fde_sub_03ac48(a0, a1, a2);
        case 0x03ac6cULL: return fde_sub_03ac6c(a0, a1, a2);
        case 0x03ac7cULL: return fde_sub_03ac7c(a0, a1, a2);
        case 0x03ac80ULL: return fde_sub_03ac80(a0, a1, a2);
        case 0x03ac98ULL: return fde_sub_03ac98(a0, a1, a2);
        case 0x03aee8ULL: return fde_sub_03aee8(a0, a1, a2);
        case 0x03aeecULL: return fde_sub_03aeec(a0, a1, a2);
        case 0x03af04ULL: return fde_sub_03af04(a0, a1, a2);
        case 0x03af08ULL: return fde_sub_03af08(a0, a1, a2);
        case 0x03af0cULL: return fde_sub_03af0c(a0, a1, a2);
        case 0x03af14ULL: return fde_sub_03af14(a0, a1, a2);
        case 0x03b058ULL: return fde_sub_03b058(a0, a1, a2);
        case 0x03b0c0ULL: return fde_sub_03b0c0(a0, a1, a2);
        case 0x03b170ULL: return fde_sub_03b170(a0, a1, a2);
        case 0x03b1dcULL: return fde_sub_03b1dc(a0, a1, a2);
        case 0x03b59cULL: return fde_sub_03b59c(a0, a1, a2);
        case 0x03b5f4ULL: return fde_sub_03b5f4(a0, a1, a2);
        case 0x03b618ULL: return fde_sub_03b618(a0, a1, a2);
        case 0x03b90cULL: return fde_sub_03b90c(a0, a1, a2);
        case 0x03b910ULL: return fde_sub_03b910(a0, a1, a2);
        case 0x03b9b8ULL: return fde_sub_03b9b8(a0, a1, a2);
        case 0x03ba68ULL: return fde_sub_03ba68(a0, a1, a2);
        case 0x03ba74ULL: return fde_sub_03ba74(a0, a1, a2);
        case 0x03ba78ULL: return fde_sub_03ba78(a0, a1, a2);
        case 0x03baf4ULL: return fde_sub_03baf4(a0, a1, a2);
        case 0x03bb6cULL: return fde_sub_03bb6c(a0, a1, a2);
        case 0x03bbd0ULL: return fde_sub_03bbd0(a0, a1, a2);
        case 0x03bbd4ULL: return fde_sub_03bbd4(a0, a1, a2);
        case 0x03bc70ULL: return fde_sub_03bc70(a0, a1, a2);
        case 0x03bd14ULL: return fde_sub_03bd14(a0, a1, a2);
        case 0x03bda8ULL: return fde_sub_03bda8(a0, a1, a2);
        case 0x03bdacULL: return fde_sub_03bdac(a0, a1, a2);
        case 0x03bdbcULL: return fde_sub_03bdbc(a0, a1, a2);
        case 0x03bdecULL: return fde_sub_03bdec(a0, a1, a2);
        case 0x03bdf0ULL: return fde_sub_03bdf0(a0, a1, a2);
        case 0x03bdf4ULL: return fde_sub_03bdf4(a0, a1, a2);
        case 0x03bf9cULL: return fde_sub_03bf9c(a0, a1, a2);
        case 0x03bfc0ULL: return fde_sub_03bfc0(a0, a1, a2);
        case 0x03c68cULL: return fde_sub_03c68c(a0, a1, a2);
        case 0x03c690ULL: return fde_sub_03c690(a0, a1, a2);
        case 0x03c6b4ULL: return fde_sub_03c6b4(a0, a1, a2);
        case 0x03c7d4ULL: return fde_sub_03c7d4(a0, a1, a2);
        case 0x03c7d8ULL: return fde_sub_03c7d8(a0, a1, a2);
        case 0x03cadcULL: return fde_sub_03cadc(a0, a1, a2);
        case 0x03cca8ULL: return fde_sub_03cca8(a0, a1, a2);
        case 0x03cf3cULL: return fde_sub_03cf3c(a0, a1, a2);
        case 0x03cf48ULL: return fde_sub_03cf48(a0, a1, a2);
        case 0x03cf54ULL: return fde_sub_03cf54(a0, a1, a2);
        case 0x03cf60ULL: return fde_sub_03cf60(a0, a1, a2);
        case 0x03d014ULL: return fde_sub_03d014(a0, a1, a2);
        case 0x03d020ULL: return fde_sub_03d020(a0, a1, a2);
        case 0x03d128ULL: return fde_sub_03d128(a0, a1, a2);
        case 0x03d358ULL: return fde_sub_03d358(a0, a1, a2);
        case 0x03d400ULL: return fde_sub_03d400(a0, a1, a2);
        case 0x03d4a8ULL: return fde_sub_03d4a8(a0, a1, a2);
        case 0x03d550ULL: return fde_sub_03d550(a0, a1, a2);
        case 0x03d6b0ULL: return fde_sub_03d6b0(a0, a1, a2);
        case 0x03d760ULL: return fde_sub_03d760(a0, a1, a2);
        case 0x03d764ULL: return fde_sub_03d764(a0, a1, a2);
        case 0x03d768ULL: return fde_sub_03d768(a0, a1, a2);
        case 0x03d76cULL: return fde_sub_03d76c(a0, a1, a2);
        case 0x03d780ULL: return fde_sub_03d780(a0, a1, a2);
        case 0x03d784ULL: return fde_sub_03d784(a0, a1, a2);
        case 0x03d8a0ULL: return fde_sub_03d8a0(a0, a1, a2);
        case 0x03dc60ULL: return fde_sub_03dc60(a0, a1, a2);
        case 0x03e018ULL: return fde_sub_03e018(a0, a1, a2);
        case 0x03e54cULL: return fde_sub_03e54c(a0, a1, a2);
        case 0x03efc4ULL: return fde_sub_03efc4(a0, a1, a2);
        case 0x03efd0ULL: return fde_sub_03efd0(a0, a1, a2);
        case 0x03f044ULL: return fde_sub_03f044(a0, a1, a2);
        case 0x03f18cULL: return fde_sub_03f18c(a0, a1, a2);
        case 0x03f24cULL: return fde_sub_03f24c(a0, a1, a2);
        case 0x03f544ULL: return fde_sub_03f544(a0, a1, a2);
        case 0x03f604ULL: return fde_sub_03f604(a0, a1, a2);
        case 0x03f734ULL: return fde_sub_03f734(a0, a1, a2);
        case 0x03f91cULL: return fde_sub_03f91c(a0, a1, a2);
        case 0x03fa48ULL: return fde_sub_03fa48(a0, a1, a2);
        case 0x03fb70ULL: return fde_sub_03fb70(a0, a1, a2);
        case 0x04091cULL: return fde_sub_04091c(a0, a1, a2);
        case 0x0409dcULL: return fde_sub_0409dc(a0, a1, a2);
        case 0x040bacULL: return fde_sub_040bac(a0, a1, a2);
        case 0x040bfcULL: return fde_sub_040bfc(a0, a1, a2);
        case 0x040c20ULL: return fde_sub_040c20(a0, a1, a2);
        case 0x040c38ULL: return fde_sub_040c38(a0, a1, a2);
        case 0x040c3cULL: return fde_sub_040c3c(a0, a1, a2);
        case 0x040c4cULL: return fde_sub_040c4c(a0, a1, a2);
        case 0x040c50ULL: return fde_sub_040c50(a0, a1, a2);
        case 0x041040ULL: return fde_sub_041040(a0, a1, a2);
        case 0x041048ULL: return fde_sub_041048(a0, a1, a2);
        case 0x041320ULL: return fde_sub_041320(a0, a1, a2);
        case 0x04137cULL: return fde_sub_04137c(a0, a1, a2);
        case 0x0415acULL: return fde_sub_0415ac(a0, a1, a2);
        case 0x0415fcULL: return fde_sub_0415fc(a0, a1, a2);
        case 0x041608ULL: return fde_sub_041608(a0, a1, a2);
        case 0x04160cULL: return fde_sub_04160c(a0, a1, a2);
        case 0x041694ULL: return fde_sub_041694(a0, a1, a2);
        case 0x0416b8ULL: return fde_sub_0416b8(a0, a1, a2);
        case 0x041900ULL: return fde_sub_041900(a0, a1, a2);
        case 0x041974ULL: return fde_sub_041974(a0, a1, a2);
        case 0x041998ULL: return fde_sub_041998(a0, a1, a2);
        case 0x041a2cULL: return fde_sub_041a2c(a0, a1, a2);
        case 0x041a34ULL: return fde_sub_041a34(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace TTKMediaNet
