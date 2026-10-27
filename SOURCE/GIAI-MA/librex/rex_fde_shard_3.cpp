// ============================================================================
// File: rex_fde_shard_3.cpp
// Target 109 / 169: librex.so (690,264 bytes)
// EN: Clean-room C++17 AArch64 Function Shard 3/5 covering [640..959]
//     (PC range 0x020c30 .. 0x030294).
// VI: Phân mảnh hàm AArch64 C++17 3/5 bao phủ [640..959]
//     (Dải địa chỉ PC 0x020c30 .. 0x030294).
// ============================================================================
#include "rex_date_format.h"

namespace bytedance {
namespace rex {

// Func #0640 | PC: 0x020c30..0x020c70 (64 B) | Symbol: sub_020c30
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94019ED4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C30ULL;
}

// Func #0641 | PC: 0x020c40..0x020c80 (64 B) | Symbol: sub_020c40
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94019ED0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C40ULL;
}

// Func #0642 | PC: 0x020c50..0x020c90 (64 B) | Symbol: sub_020c50
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94019ECCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C50ULL;
}

// Func #0643 | PC: 0x020c60..0x020ca0 (64 B) | Symbol: sub_020c60
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94019EC8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C60ULL;
}

// Func #0644 | PC: 0x020c70..0x020cb0 (64 B) | Symbol: sub_020c70
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94019EC4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C70ULL;
}

// Func #0645 | PC: 0x020c80..0x020cc0 (64 B) | Symbol: sub_020c80
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94019EC0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C80ULL;
}

// Func #0646 | PC: 0x020c90..0x020cd0 (64 B) | Symbol: sub_020c90
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020c90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94019EBCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020C90ULL;
}

// Func #0647 | PC: 0x020ca0..0x020ce0 (64 B) | Symbol: sub_020ca0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94019EB8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020CA0ULL;
}

// Func #0648 | PC: 0x020cb0..0x020cf0 (64 B) | Symbol: sub_020cb0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_020cb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94019EB4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020CB0ULL;
}

// Func #0649 | PC: 0x020cc0..0x020d00 (64 B) | Symbol: sub_020cc0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_020cc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94019EB0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020CC0ULL;
}

// Func #0650 | PC: 0x020cd0..0x020d10 (64 B) | Symbol: sub_020cd0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020cd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94019EACULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020CD0ULL;
}

// Func #0651 | PC: 0x020ce0..0x020d20 (64 B) | Symbol: sub_020ce0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94019EA8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020CE0ULL;
}

// Func #0652 | PC: 0x020cf0..0x020d30 (64 B) | Symbol: sub_020cf0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_020cf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x94019EA4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020CF0ULL;
}

// Func #0653 | PC: 0x020d00..0x020d40 (64 B) | Symbol: sub_020d00
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_020d00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94019EA0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020D00ULL;
}

// Func #0654 | PC: 0x020d10..0x020d50 (64 B) | Symbol: sub_020d10
// EN: AArch64 prologue [bl #0x88780; add x8, x26, #0x508; movi v0.2d, #0000000000000000; strb wzr, [sp, #0x9d0]] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x8, x26, #0x508; movi v0.2d, #0000000000000000; strb wzr, [sp, #0x9d0]]
uint64_t fde_sub_020d10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91142348ULL) << 32) | 0x94019E9CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020D10ULL;
}

// Func #0655 | PC: 0x021a74..0x021ab4 (64 B) | Symbol: sub_021a74
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x558; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x558; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_021a74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911563E0ULL) << 32) | 0x94019E20ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021A74ULL;
}

// Func #0656 | PC: 0x021a7c..0x021abc (64 B) | Symbol: sub_021a7c
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x21a90; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x21a90; subs x19, x19, #0x30]
uint64_t fde_sub_021a7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401967CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021A7CULL;
}

// Func #0657 | PC: 0x021aac..0x021aec (64 B) | Symbol: sub_021aac
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x21a88; add x8, x27, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x21a88; add x8, x27, x19]
uint64_t fde_sub_021aac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF8009ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021AACULL;
}

// Func #0658 | PC: 0x021ac0..0x021b00 (64 B) | Symbol: sub_021ac0
// EN: AArch64 prologue [bl #0x1ad0; b #0x21a88; adrp x0, #0xc3000; add x0, x0, #0x70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x21a88; adrp x0, #0xc3000; add x0, x0, #0x70]
uint64_t fde_sub_021ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF8004ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021AC0ULL;
}

// Func #0659 | PC: 0x021ad0..0x021b10 (64 B) | Symbol: sub_021ad0
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xd0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xd0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_021ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9406BF3ULL) << 32) | 0x97FF8008ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021AD0ULL;
}

// Func #0660 | PC: 0x021b0c..0x021b4c (64 B) | Symbol: sub_021b0c
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_021b0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF802DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021B0CULL;
}

// Func #0661 | PC: 0x021b10..0x023910 (7680 B) | Symbol: rex_locale_init_ctor_16
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_021b10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021B10ULL;
}

// Func #0662 | PC: 0x021b2c..0x021b6c (64 B) | Symbol: sub_021b2c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_021b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13143FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021B2CULL;
}

// Func #0663 | PC: 0x021b30..0x021b70 (64 B) | Symbol: sub_021b30
// EN: AArch64 prologue [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_021b30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021B30ULL;
}

// Func #0664 | PC: 0x021b58..0x021b98 (64 B) | Symbol: sub_021b58
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x238c8; adrp x17, #0x9a000; adrp x0, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x238c8; adrp x17, #0x9a000; adrp x0, #0x9a000]
uint64_t fde_sub_021b58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400EB60ULL) << 32) | 0x97FF802AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021B58ULL;
}

// Func #0665 | PC: 0x0223f4..0x022434 (64 B) | Symbol: sub_0223f4
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; adrp x11, #0x9a000; ldr q0, [x8, #0xc90]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; adrp x11, #0x9a000; ldr q0, [x8, #0xc90]]
uint64_t fde_sub_0223f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003A8ULL) << 32) | 0x97FF7DEBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0223F4ULL;
}

// Func #0666 | PC: 0x022a3c..0x022a7c (64 B) | Symbol: sub_022a3c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022a3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94019751ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022A3CULL;
}

// Func #0667 | PC: 0x022a4c..0x022a8c (64 B) | Symbol: sub_022a4c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022a4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401974DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022A4CULL;
}

// Func #0668 | PC: 0x022a5c..0x022a9c (64 B) | Symbol: sub_022a5c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94019749ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022A5CULL;
}

// Func #0669 | PC: 0x022a6c..0x022aac (64 B) | Symbol: sub_022a6c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94019745ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022A6CULL;
}

// Func #0670 | PC: 0x022a7c..0x022abc (64 B) | Symbol: sub_022a7c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022a7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94019741ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022A7CULL;
}

// Func #0671 | PC: 0x022a8c..0x022acc (64 B) | Symbol: sub_022a8c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022a8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401973DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022A8CULL;
}

// Func #0672 | PC: 0x022a9c..0x022adc (64 B) | Symbol: sub_022a9c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022a9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94019739ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022A9CULL;
}

// Func #0673 | PC: 0x022aac..0x022aec (64 B) | Symbol: sub_022aac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022aac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94019735ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022AACULL;
}

// Func #0674 | PC: 0x022abc..0x022afc (64 B) | Symbol: sub_022abc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022abc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94019731ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022ABCULL;
}

// Func #0675 | PC: 0x022acc..0x022b0c (64 B) | Symbol: sub_022acc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022acc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401972DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022ACCULL;
}

// Func #0676 | PC: 0x022adc..0x022b1c (64 B) | Symbol: sub_022adc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022adc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94019729ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022ADCULL;
}

// Func #0677 | PC: 0x022aec..0x022b2c (64 B) | Symbol: sub_022aec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94019725ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022AECULL;
}

// Func #0678 | PC: 0x022afc..0x022b3c (64 B) | Symbol: sub_022afc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94019721ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022AFCULL;
}

// Func #0679 | PC: 0x022b0c..0x022b4c (64 B) | Symbol: sub_022b0c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022b0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401971DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B0CULL;
}

// Func #0680 | PC: 0x022b1c..0x022b5c (64 B) | Symbol: sub_022b1c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022b1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94019719ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B1CULL;
}

// Func #0681 | PC: 0x022b2c..0x022b6c (64 B) | Symbol: sub_022b2c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94019715ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B2CULL;
}

// Func #0682 | PC: 0x022b3c..0x022b7c (64 B) | Symbol: sub_022b3c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022b3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94019711ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B3CULL;
}

// Func #0683 | PC: 0x022b4c..0x022b8c (64 B) | Symbol: sub_022b4c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_022b4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401970DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B4CULL;
}

// Func #0684 | PC: 0x022b5c..0x022b9c (64 B) | Symbol: sub_022b5c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_022b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94019709ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B5CULL;
}

// Func #0685 | PC: 0x022b6c..0x022bac (64 B) | Symbol: sub_022b6c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_022b6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94019705ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B6CULL;
}

// Func #0686 | PC: 0x022b7c..0x022bbc (64 B) | Symbol: sub_022b7c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_022b7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94019701ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B7CULL;
}

// Func #0687 | PC: 0x022b8c..0x022bcc (64 B) | Symbol: sub_022b8c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_022b8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940196FDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B8CULL;
}

// Func #0688 | PC: 0x022b9c..0x022bdc (64 B) | Symbol: sub_022b9c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_022b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940196F9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022B9CULL;
}

// Func #0689 | PC: 0x022bac..0x022bec (64 B) | Symbol: sub_022bac
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x949; strb wzr, [sp, #0x9c0]] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x949; strb wzr, [sp, #0x9c0]]
uint64_t fde_sub_022bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x940196F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022BACULL;
}

// Func #0690 | PC: 0x023864..0x0238a4 (64 B) | Symbol: sub_023864
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_023864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911523E0ULL) << 32) | 0x940196A4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023864ULL;
}

// Func #0691 | PC: 0x02386c..0x0238ac (64 B) | Symbol: sub_02386c
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x23880; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x23880; subs x19, x19, #0x30]
uint64_t fde_sub_02386c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94018F00ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02386CULL;
}

// Func #0692 | PC: 0x02389c..0x0238dc (64 B) | Symbol: sub_02389c
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x23878; add x8, x27, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x23878; add x8, x27, x19]
uint64_t fde_sub_02389c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF788DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02389CULL;
}

// Func #0693 | PC: 0x0238b0..0x0238f0 (64 B) | Symbol: sub_0238b0
// EN: AArch64 prologue [bl #0x1ad0; b #0x23878; adrp x0, #0xc4000; add x0, x0, #0x770] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x23878; adrp x0, #0xc4000; add x0, x0, #0x770]
uint64_t fde_sub_0238b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF7888ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0238B0ULL;
}

// Func #0694 | PC: 0x0238c0..0x023900 (64 B) | Symbol: sub_0238c0
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_0238c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063F3ULL) << 32) | 0x97FF788CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0238C0ULL;
}

// Func #0695 | PC: 0x0238fc..0x02393c (64 B) | Symbol: sub_0238fc
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0238fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF78B1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0238FCULL;
}

// Func #0696 | PC: 0x023900..0x025700 (7680 B) | Symbol: rex_locale_init_ctor_17
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_023900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023900ULL;
}

// Func #0697 | PC: 0x02391c..0x02395c (64 B) | Symbol: sub_02391c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_02391c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13183FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02391CULL;
}

// Func #0698 | PC: 0x023920..0x023960 (64 B) | Symbol: sub_023920
// EN: AArch64 prologue [sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_023920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023920ULL;
}

// Func #0699 | PC: 0x023948..0x023988 (64 B) | Symbol: sub_023948
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x258a4; movi v1.2d, #0000000000000000; mov w10, #0x6966] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x258a4; movi v1.2d, #0000000000000000; mov w10, #0x6966]
uint64_t fde_sub_023948(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400FAC0ULL) << 32) | 0x97FF78AEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023948ULL;
}

// Func #0700 | PC: 0x0241dc..0x02421c (64 B) | Symbol: sub_0241dc
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x358; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0x358; adrp x8, #0x97000]
uint64_t fde_sub_0241dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00003A9ULL) << 32) | 0x97FF7671ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0241DCULL;
}

// Func #0701 | PC: 0x0242a4..0x0242e4 (64 B) | Symbol: sub_0242a4
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x99000]
uint64_t fde_sub_0242a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000389ULL) << 32) | 0x97FF763FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0242A4ULL;
}

// Func #0702 | PC: 0x024714..0x024754 (64 B) | Symbol: sub_024714
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; ldr x9, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; ldr x9, [sp, #0x20]]
uint64_t fde_sub_024714(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000388ULL) << 32) | 0x97FF7523ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024714ULL;
}

// Func #0703 | PC: 0x02488c..0x0248cc (64 B) | Symbol: sub_02488c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02488c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94018FBDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02488CULL;
}

// Func #0704 | PC: 0x02489c..0x0248dc (64 B) | Symbol: sub_02489c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02489c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94018FB9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02489CULL;
}

// Func #0705 | PC: 0x0248ac..0x0248ec (64 B) | Symbol: sub_0248ac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0248ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94018FB5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0248ACULL;
}

// Func #0706 | PC: 0x0248bc..0x0248fc (64 B) | Symbol: sub_0248bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0248bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94018FB1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0248BCULL;
}

// Func #0707 | PC: 0x0248cc..0x02490c (64 B) | Symbol: sub_0248cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0248cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x94018FADULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0248CCULL;
}

// Func #0708 | PC: 0x0248dc..0x02491c (64 B) | Symbol: sub_0248dc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0248dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94018FA9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0248DCULL;
}

// Func #0709 | PC: 0x0248ec..0x02492c (64 B) | Symbol: sub_0248ec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0248ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94018FA5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0248ECULL;
}

// Func #0710 | PC: 0x0248fc..0x02493c (64 B) | Symbol: sub_0248fc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0248fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94018FA1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0248FCULL;
}

// Func #0711 | PC: 0x02490c..0x02494c (64 B) | Symbol: sub_02490c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02490c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94018F9DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02490CULL;
}

// Func #0712 | PC: 0x02491c..0x02495c (64 B) | Symbol: sub_02491c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02491c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94018F99ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02491CULL;
}

// Func #0713 | PC: 0x02492c..0x02496c (64 B) | Symbol: sub_02492c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02492c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94018F95ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02492CULL;
}

// Func #0714 | PC: 0x02493c..0x02497c (64 B) | Symbol: sub_02493c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02493c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94018F91ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02493CULL;
}

// Func #0715 | PC: 0x02494c..0x02498c (64 B) | Symbol: sub_02494c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02494c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94018F8DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02494CULL;
}

// Func #0716 | PC: 0x02495c..0x02499c (64 B) | Symbol: sub_02495c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02495c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94018F89ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02495CULL;
}

// Func #0717 | PC: 0x02496c..0x0249ac (64 B) | Symbol: sub_02496c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02496c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94018F85ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02496CULL;
}

// Func #0718 | PC: 0x02497c..0x0249bc (64 B) | Symbol: sub_02497c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02497c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94018F81ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02497CULL;
}

// Func #0719 | PC: 0x02498c..0x0249cc (64 B) | Symbol: sub_02498c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02498c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94018F7DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02498CULL;
}

// Func #0720 | PC: 0x02499c..0x0249dc (64 B) | Symbol: sub_02499c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_02499c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94018F79ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02499CULL;
}

// Func #0721 | PC: 0x0249ac..0x0249ec (64 B) | Symbol: sub_0249ac
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_0249ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94018F75ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0249ACULL;
}

// Func #0722 | PC: 0x0249bc..0x0249fc (64 B) | Symbol: sub_0249bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0249bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94018F71ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0249BCULL;
}

// Func #0723 | PC: 0x0249cc..0x024a0c (64 B) | Symbol: sub_0249cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0249cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94018F6DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0249CCULL;
}

// Func #0724 | PC: 0x0249dc..0x024a1c (64 B) | Symbol: sub_0249dc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0249dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x94018F69ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0249DCULL;
}

// Func #0725 | PC: 0x0249ec..0x024a2c (64 B) | Symbol: sub_0249ec
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_0249ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94018F65ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0249ECULL;
}

// Func #0726 | PC: 0x0249fc..0x024a3c (64 B) | Symbol: sub_0249fc
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x8d9; add x8, x25, #0x478] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x8d9; add x8, x25, #0x478]
uint64_t fde_sub_0249fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x94018F61ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0249FCULL;
}

// Func #0727 | PC: 0x025014..0x025054 (64 B) | Symbol: sub_025014
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; adrp x8, #0x9a000]
uint64_t fde_sub_025014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000388ULL) << 32) | 0x97FF72E3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025014ULL;
}

// Func #0728 | PC: 0x025064..0x0250a4 (64 B) | Symbol: sub_025064
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xb0]; adrp x8, #0x9a000; add x9, sp, #1, lsl #12] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xb0]; adrp x8, #0x9a000; add x9, sp, #1, lsl #12]
uint64_t fde_sub_025064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC02FE0ULL) << 32) | 0x97FF72CFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025064ULL;
}

// Func #0729 | PC: 0x0250f8..0x025138 (64 B) | Symbol: sub_0250f8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xa0]; add x8, sp, #1, lsl #12; movi v1.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xa0]; add x8, sp, #1, lsl #12; movi v1.2d, #0000000000000000]
uint64_t fde_sub_0250f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC02BE0ULL) << 32) | 0x97FF72AAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0250F8ULL;
}

// Func #0730 | PC: 0x025840..0x025880 (64 B) | Symbol: sub_025840
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x558; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x558; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_025840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911563E0ULL) << 32) | 0x94018EADULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025840ULL;
}

// Func #0731 | PC: 0x025848..0x025888 (64 B) | Symbol: sub_025848
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x2585c; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x2585c; subs x19, x19, #0x30]
uint64_t fde_sub_025848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94018709ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025848ULL;
}

// Func #0732 | PC: 0x025878..0x0258b8 (64 B) | Symbol: sub_025878
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x25854; add x8, x26, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x25854; add x8, x26, x19]
uint64_t fde_sub_025878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF7096ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025878ULL;
}

// Func #0733 | PC: 0x02588c..0x0258cc (64 B) | Symbol: sub_02588c
// EN: AArch64 prologue [bl #0x1ad0; b #0x25854; adrp x0, #0xc5000; add x0, x0, #0xe70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x25854; adrp x0, #0xc5000; add x0, x0, #0xe70]
uint64_t fde_sub_02588c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF7091ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02588CULL;
}

// Func #0734 | PC: 0x02589c..0x0258dc (64 B) | Symbol: sub_02589c
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xd0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xd0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_02589c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9406BF3ULL) << 32) | 0x97FF7095ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02589CULL;
}

// Func #0735 | PC: 0x0258d8..0x025918 (64 B) | Symbol: sub_0258d8
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0258d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF70BAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0258D8ULL;
}

// Func #0736 | PC: 0x0258dc..0x0276dc (7680 B) | Symbol: rex_locale_init_ctor_18
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0258dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0258DCULL;
}

// Func #0737 | PC: 0x0258f8..0x025938 (64 B) | Symbol: sub_0258f8
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_0258f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13143FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0258F8ULL;
}

// Func #0738 | PC: 0x0258fc..0x02593c (64 B) | Symbol: sub_0258fc
// EN: AArch64 prologue [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_0258fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0258FCULL;
}

// Func #0739 | PC: 0x025924..0x025964 (64 B) | Symbol: sub_025924
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x276e4; mov x6, #0xc366; movk x6, #0x76a9, lsl #16] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x276e4; mov x6, #0xc366; movk x6, #0x76a9, lsl #16]
uint64_t fde_sub_025924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400EDE0ULL) << 32) | 0x97FF70B7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025924ULL;
}

// Func #0740 | PC: 0x0261ac..0x0261ec (64 B) | Symbol: sub_0261ac
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0xedc; ldur q0, [x9, #0xb]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9a000; add x9, x9, #0xedc; ldur q0, [x9, #0xb]]
uint64_t fde_sub_0261ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900003A9ULL) << 32) | 0x97FF6E7DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0261ACULL;
}

// Func #0741 | PC: 0x02626c..0x0262ac (64 B) | Symbol: sub_02626c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; adrp x16, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; adrp x16, #0x9a000]
uint64_t fde_sub_02626c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000388ULL) << 32) | 0x97FF6E4DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02626CULL;
}

// Func #0742 | PC: 0x02681c..0x02685c (64 B) | Symbol: sub_02681c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02681c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x940187D9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02681CULL;
}

// Func #0743 | PC: 0x02682c..0x02686c (64 B) | Symbol: sub_02682c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02682c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x940187D5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02682CULL;
}

// Func #0744 | PC: 0x02683c..0x02687c (64 B) | Symbol: sub_02683c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02683c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x940187D1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02683CULL;
}

// Func #0745 | PC: 0x02684c..0x02688c (64 B) | Symbol: sub_02684c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02684c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x940187CDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02684CULL;
}

// Func #0746 | PC: 0x02685c..0x02689c (64 B) | Symbol: sub_02685c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02685c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x940187C9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02685CULL;
}

// Func #0747 | PC: 0x02686c..0x0268ac (64 B) | Symbol: sub_02686c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02686c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x940187C5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02686CULL;
}

// Func #0748 | PC: 0x02687c..0x0268bc (64 B) | Symbol: sub_02687c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02687c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x940187C1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02687CULL;
}

// Func #0749 | PC: 0x02688c..0x0268cc (64 B) | Symbol: sub_02688c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02688c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x940187BDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02688CULL;
}

// Func #0750 | PC: 0x02689c..0x0268dc (64 B) | Symbol: sub_02689c
// EN: AArch64 prologue [bl #0x88780; mov x0, x21; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x21; mov x1, x27; mov x2, x27]
uint64_t fde_sub_02689c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x940187B9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02689CULL;
}

// Func #0751 | PC: 0x0268ac..0x0268ec (64 B) | Symbol: sub_0268ac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_0268ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x940187B5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0268ACULL;
}

// Func #0752 | PC: 0x0268bc..0x0268fc (64 B) | Symbol: sub_0268bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_0268bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x940187B1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0268BCULL;
}

// Func #0753 | PC: 0x0268cc..0x02690c (64 B) | Symbol: sub_0268cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_0268cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x940187ADULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0268CCULL;
}

// Func #0754 | PC: 0x0268dc..0x02691c (64 B) | Symbol: sub_0268dc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_0268dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x940187A9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0268DCULL;
}

// Func #0755 | PC: 0x0268ec..0x02692c (64 B) | Symbol: sub_0268ec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_0268ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x940187A5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0268ECULL;
}

// Func #0756 | PC: 0x0268fc..0x02693c (64 B) | Symbol: sub_0268fc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_0268fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x940187A1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0268FCULL;
}

// Func #0757 | PC: 0x02690c..0x02694c (64 B) | Symbol: sub_02690c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02690c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401879DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02690CULL;
}

// Func #0758 | PC: 0x02691c..0x02695c (64 B) | Symbol: sub_02691c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02691c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94018799ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02691CULL;
}

// Func #0759 | PC: 0x02692c..0x02696c (64 B) | Symbol: sub_02692c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x21; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x21; mov x2, x1]
uint64_t fde_sub_02692c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94018795ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02692CULL;
}

// Func #0760 | PC: 0x02693c..0x02697c (64 B) | Symbol: sub_02693c
// EN: AArch64 prologue [bl #0x88780; mov x0, x21; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x21; mov x1, x28; mov x2, x28]
uint64_t fde_sub_02693c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x94018791ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02693CULL;
}

// Func #0761 | PC: 0x02694c..0x02698c (64 B) | Symbol: sub_02694c
// EN: AArch64 prologue [bl #0x88780; mov x0, x21; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x21; mov x1, x26; mov x2, x26]
uint64_t fde_sub_02694c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x9401878DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02694CULL;
}

// Func #0762 | PC: 0x026960..0x0269a0 (64 B) | Symbol: sub_026960
// EN: AArch64 prologue [bl #0x88780; mov x0, x21; mov x1, x19; mov x2, x19] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x21; mov x1, x19; mov x2, x19]
uint64_t fde_sub_026960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x94018788ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026960ULL;
}

// Func #0763 | PC: 0x026970..0x0269b0 (64 B) | Symbol: sub_026970
// EN: AArch64 prologue [bl #0x88780; mov x0, x21; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x21; mov x1, x20; mov x2, x20]
uint64_t fde_sub_026970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x94018784ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026970ULL;
}

// Func #0764 | PC: 0x026980..0x0269c0 (64 B) | Symbol: sub_026980
// EN: AArch64 prologue [bl #0x88780; mov x0, x21; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x21; mov x1, x23; mov x2, x23]
uint64_t fde_sub_026980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x94018780ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026980ULL;
}

// Func #0765 | PC: 0x026990..0x0269d0 (64 B) | Symbol: sub_026990
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x949; strb wzr, [sp, #0x9c0]] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x949; strb wzr, [sp, #0x9c0]]
uint64_t fde_sub_026990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x9401877CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026990ULL;
}

// Func #0766 | PC: 0x027680..0x0276c0 (64 B) | Symbol: sub_027680
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_027680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911523E0ULL) << 32) | 0x9401871DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027680ULL;
}

// Func #0767 | PC: 0x027688..0x0276c8 (64 B) | Symbol: sub_027688
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x2769c; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x2769c; subs x19, x19, #0x30]
uint64_t fde_sub_027688(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94017F79ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027688ULL;
}

// Func #0768 | PC: 0x0276b8..0x0276f8 (64 B) | Symbol: sub_0276b8
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x27694; add x8, x26, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x27694; add x8, x26, x19]
uint64_t fde_sub_0276b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF6906ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0276B8ULL;
}

// Func #0769 | PC: 0x0276cc..0x02770c (64 B) | Symbol: sub_0276cc
// EN: AArch64 prologue [bl #0x1ad0; b #0x27694; adrp x0, #0xc7000; add x0, x0, #0x570] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x27694; adrp x0, #0xc7000; add x0, x0, #0x570]
uint64_t fde_sub_0276cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF6901ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0276CCULL;
}

// Func #0770 | PC: 0x0276dc..0x02771c (64 B) | Symbol: sub_0276dc
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_0276dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063F3ULL) << 32) | 0x97FF6905ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0276DCULL;
}

// Func #0771 | PC: 0x027718..0x027758 (64 B) | Symbol: sub_027718
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_027718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF692AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027718ULL;
}

// Func #0772 | PC: 0x02771c..0x02951c (7680 B) | Symbol: rex_locale_init_ctor_19
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_02771c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02771CULL;
}

// Func #0773 | PC: 0x027738..0x027778 (64 B) | Symbol: sub_027738
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_027738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD131C3FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027738ULL;
}

// Func #0774 | PC: 0x02773c..0x02777c (64 B) | Symbol: sub_02773c
// EN: AArch64 prologue [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_02773c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD131C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02773CULL;
}

// Func #0775 | PC: 0x027764..0x0277a4 (64 B) | Symbol: sub_027764
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x2950c; mov x7, #0xc366; movk x7, #0x76a9, lsl #16] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x2950c; mov x7, #0xc366; movk x7, #0x76a9, lsl #16]
uint64_t fde_sub_027764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400ED20ULL) << 32) | 0x97FF6927ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027764ULL;
}

// Func #0776 | PC: 0x027f94..0x027fd4 (64 B) | Symbol: sub_027f94
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9b000; add x9, x9, #0xe; ldur q0, [x9, #0xf]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9b000; add x9, x9, #0xe; ldur q0, [x9, #0xf]]
uint64_t fde_sub_027f94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900003A9ULL) << 32) | 0x97FF6703ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027F94ULL;
}

// Func #0777 | PC: 0x028050..0x028090 (64 B) | Symbol: sub_028050
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcd0]; adrp x14, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcd0]; adrp x14, #0x9b000]
uint64_t fde_sub_028050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000368ULL) << 32) | 0x97FF66D4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028050ULL;
}

// Func #0778 | PC: 0x0283f4..0x028434 (64 B) | Symbol: sub_0283f4
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9b000; add x9, x9, #0x80; ldr q0, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9b000; add x9, x9, #0x80; ldr q0, [x9]]
uint64_t fde_sub_0283f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000389ULL) << 32) | 0x97FF65EBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0283F4ULL;
}

// Func #0779 | PC: 0x0284b8..0x0284f8 (64 B) | Symbol: sub_0284b8
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc50]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc50]; adrp x8, #0x9b000]
uint64_t fde_sub_0284b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000368ULL) << 32) | 0x97FF65BAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0284B8ULL;
}

// Func #0780 | PC: 0x028520..0x028560 (64 B) | Symbol: sub_028520
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9b000; adrp x8, #0x97000; add x9, x9, #0x99] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9b000; adrp x8, #0x97000; add x9, x9, #0x99]
uint64_t fde_sub_028520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000389ULL) << 32) | 0x97FF65A0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028520ULL;
}

// Func #0781 | PC: 0x0285dc..0x02861c (64 B) | Symbol: sub_0285dc
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp]; adrp x8, #0x9b000; add x8, x8, #0xb1] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp]; adrp x8, #0x9b000; add x8, x8, #0xb1]
uint64_t fde_sub_0285dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC003E0ULL) << 32) | 0x97FF6571ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0285DCULL;
}

// Func #0782 | PC: 0x028630..0x028670 (64 B) | Symbol: sub_028630
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x94018054ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028630ULL;
}

// Func #0783 | PC: 0x028640..0x028680 (64 B) | Symbol: sub_028640
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94057E1ULL) << 32) | 0x94018050ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028640ULL;
}

// Func #0784 | PC: 0x028650..0x028690 (64 B) | Symbol: sub_028650
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xb0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xb0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BE1ULL) << 32) | 0x9401804CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028650ULL;
}

// Func #0785 | PC: 0x028660..0x0286a0 (64 B) | Symbol: sub_028660
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xb8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xb8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405FE1ULL) << 32) | 0x94018048ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028660ULL;
}

// Func #0786 | PC: 0x028670..0x0286b0 (64 B) | Symbol: sub_028670
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xc0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xc0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028670(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063E1ULL) << 32) | 0x94018044ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028670ULL;
}

// Func #0787 | PC: 0x028680..0x0286c0 (64 B) | Symbol: sub_028680
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94018040ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028680ULL;
}

// Func #0788 | PC: 0x028690..0x0286d0 (64 B) | Symbol: sub_028690
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x9401803CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028690ULL;
}

// Func #0789 | PC: 0x0286a0..0x0286e0 (64 B) | Symbol: sub_0286a0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0286a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94018038ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286A0ULL;
}

// Func #0790 | PC: 0x0286b0..0x0286f0 (64 B) | Symbol: sub_0286b0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0286b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94018034ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286B0ULL;
}

// Func #0791 | PC: 0x0286c0..0x028700 (64 B) | Symbol: sub_0286c0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0286c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94018030ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286C0ULL;
}

// Func #0792 | PC: 0x0286d0..0x028710 (64 B) | Symbol: sub_0286d0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0286d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401802CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286D0ULL;
}

// Func #0793 | PC: 0x0286e0..0x028720 (64 B) | Symbol: sub_0286e0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0286e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94018028ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286E0ULL;
}

// Func #0794 | PC: 0x0286f0..0x028730 (64 B) | Symbol: sub_0286f0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0286f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94018024ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286F0ULL;
}

// Func #0795 | PC: 0x028700..0x028740 (64 B) | Symbol: sub_028700
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94018020ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028700ULL;
}

// Func #0796 | PC: 0x028710..0x028750 (64 B) | Symbol: sub_028710
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401801CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028710ULL;
}

// Func #0797 | PC: 0x028720..0x028760 (64 B) | Symbol: sub_028720
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94018018ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028720ULL;
}

// Func #0798 | PC: 0x028730..0x028770 (64 B) | Symbol: sub_028730
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94018014ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028730ULL;
}

// Func #0799 | PC: 0x028740..0x028780 (64 B) | Symbol: sub_028740
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94018010ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028740ULL;
}

// Func #0800 | PC: 0x028750..0x028790 (64 B) | Symbol: sub_028750
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_028750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401800CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028750ULL;
}

// Func #0801 | PC: 0x028760..0x0287a0 (64 B) | Symbol: sub_028760
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94018008ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028760ULL;
}

// Func #0802 | PC: 0x028770..0x0287b0 (64 B) | Symbol: sub_028770
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94018004ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028770ULL;
}

// Func #0803 | PC: 0x028780..0x0287c0 (64 B) | Symbol: sub_028780
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_028780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94018000ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028780ULL;
}

// Func #0804 | PC: 0x028790..0x0287d0 (64 B) | Symbol: sub_028790
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_028790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94017FFCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028790ULL;
}

// Func #0805 | PC: 0x0287a0..0x0287e0 (64 B) | Symbol: sub_0287a0
// EN: AArch64 prologue [bl #0x88780; mov w10, #0x2e61; add x9, x25, #0x478; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov w10, #0x2e61; add x9, x25, #0x478; movi v0.2d, #0000000000000000]
uint64_t fde_sub_0287a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5285CC2AULL) << 32) | 0x94017FF8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0287A0ULL;
}

// Func #0806 | PC: 0x0294a8..0x0294e8 (64 B) | Symbol: sub_0294a8
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x568; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x568; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_0294a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115A3E0ULL) << 32) | 0x94017F93ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0294A8ULL;
}

// Func #0807 | PC: 0x0294b0..0x0294f0 (64 B) | Symbol: sub_0294b0
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x294c4; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x294c4; subs x19, x19, #0x30]
uint64_t fde_sub_0294b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x940177EFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0294B0ULL;
}

// Func #0808 | PC: 0x0294e0..0x029520 (64 B) | Symbol: sub_0294e0
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x294bc; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x294bc; add x8, x21, x19]
uint64_t fde_sub_0294e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF617CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0294E0ULL;
}

// Func #0809 | PC: 0x0294f4..0x029534 (64 B) | Symbol: sub_0294f4
// EN: AArch64 prologue [bl #0x1ad0; b #0x294bc; adrp x0, #0xc8000; add x0, x0, #0xc70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x294bc; adrp x0, #0xc8000; add x0, x0, #0xc70]
uint64_t fde_sub_0294f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF6177ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0294F4ULL;
}

// Func #0810 | PC: 0x029504..0x029544 (64 B) | Symbol: sub_029504
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xe0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xe0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_029504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94073F3ULL) << 32) | 0x97FF617BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029504ULL;
}

// Func #0811 | PC: 0x029540..0x029580 (64 B) | Symbol: sub_029540
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_029540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF61A0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029540ULL;
}

// Func #0812 | PC: 0x029544..0x02b344 (7680 B) | Symbol: rex_locale_init_ctor_20
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_029544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029544ULL;
}

// Func #0813 | PC: 0x029560..0x0295a0 (64 B) | Symbol: sub_029560
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_029560(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13143FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029560ULL;
}

// Func #0814 | PC: 0x029564..0x0295a4 (64 B) | Symbol: sub_029564
// EN: AArch64 prologue [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_029564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029564ULL;
}

// Func #0815 | PC: 0x02958c..0x0295cc (64 B) | Symbol: sub_02958c
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x2ba64; movi v1.2d, #0000000000000000; mov w2, #0xa1c3] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x2ba64; movi v1.2d, #0000000000000000; mov w2, #0xa1c3]
uint64_t fde_sub_02958c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340126A0ULL) << 32) | 0x97FF619DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02958CULL;
}

// Func #0816 | PC: 0x029e20..0x029e60 (64 B) | Symbol: sub_029e20
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc90]; str x0, [sp, #0x1e0]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc90]; str x0, [sp, #0x1e0]]
uint64_t fde_sub_029e20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000369ULL) << 32) | 0x97FF5F60ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029E20ULL;
}

// Func #0817 | PC: 0x02a31c..0x02a35c (64 B) | Symbol: sub_02a31c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x50]]
uint64_t fde_sub_02a31c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000368ULL) << 32) | 0x97FF5E21ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A31CULL;
}

// Func #0818 | PC: 0x02a494..0x02a4d4 (64 B) | Symbol: sub_02a494
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x940178BBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A494ULL;
}

// Func #0819 | PC: 0x02a4a4..0x02a4e4 (64 B) | Symbol: sub_02a4a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a4a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x940178B7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A4A4ULL;
}

// Func #0820 | PC: 0x02a4b4..0x02a4f4 (64 B) | Symbol: sub_02a4b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x940178B3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A4B4ULL;
}

// Func #0821 | PC: 0x02a4c4..0x02a504 (64 B) | Symbol: sub_02a4c4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a4c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x940178AFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A4C4ULL;
}

// Func #0822 | PC: 0x02a4d4..0x02a514 (64 B) | Symbol: sub_02a4d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a4d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x940178ABULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A4D4ULL;
}

// Func #0823 | PC: 0x02a4e4..0x02a524 (64 B) | Symbol: sub_02a4e4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a4e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x940178A7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A4E4ULL;
}

// Func #0824 | PC: 0x02a4f4..0x02a534 (64 B) | Symbol: sub_02a4f4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a4f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x940178A3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A4F4ULL;
}

// Func #0825 | PC: 0x02a504..0x02a544 (64 B) | Symbol: sub_02a504
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401789FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A504ULL;
}

// Func #0826 | PC: 0x02a514..0x02a554 (64 B) | Symbol: sub_02a514
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401789BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A514ULL;
}

// Func #0827 | PC: 0x02a524..0x02a564 (64 B) | Symbol: sub_02a524
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94017897ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A524ULL;
}

// Func #0828 | PC: 0x02a534..0x02a574 (64 B) | Symbol: sub_02a534
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94017893ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A534ULL;
}

// Func #0829 | PC: 0x02a544..0x02a584 (64 B) | Symbol: sub_02a544
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401788FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A544ULL;
}

// Func #0830 | PC: 0x02a554..0x02a594 (64 B) | Symbol: sub_02a554
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401788BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A554ULL;
}

// Func #0831 | PC: 0x02a564..0x02a5a4 (64 B) | Symbol: sub_02a564
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94017887ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A564ULL;
}

// Func #0832 | PC: 0x02a574..0x02a5b4 (64 B) | Symbol: sub_02a574
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94017883ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A574ULL;
}

// Func #0833 | PC: 0x02a584..0x02a5c4 (64 B) | Symbol: sub_02a584
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_02a584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401787FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A584ULL;
}

// Func #0834 | PC: 0x02a594..0x02a5d4 (64 B) | Symbol: sub_02a594
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401787BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A594ULL;
}

// Func #0835 | PC: 0x02a5a4..0x02a5e4 (64 B) | Symbol: sub_02a5a4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_02a5a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94017877ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A5A4ULL;
}

// Func #0836 | PC: 0x02a5b8..0x02a5f8 (64 B) | Symbol: sub_02a5b8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_02a5b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94017872ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A5B8ULL;
}

// Func #0837 | PC: 0x02a5c8..0x02a608 (64 B) | Symbol: sub_02a5c8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a5c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401786EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A5C8ULL;
}

// Func #0838 | PC: 0x02a5d8..0x02a618 (64 B) | Symbol: sub_02a5d8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a5d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401786AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A5D8ULL;
}

// Func #0839 | PC: 0x02a5e8..0x02a628 (64 B) | Symbol: sub_02a5e8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02a5e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94017866ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A5E8ULL;
}

// Func #0840 | PC: 0x02a5f8..0x02a638 (64 B) | Symbol: sub_02a5f8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_02a5f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94017862ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A5F8ULL;
}

// Func #0841 | PC: 0x02a608..0x02a648 (64 B) | Symbol: sub_02a608
// EN: AArch64 prologue [bl #0x88780; mov w10, #0x2e69; movi v0.2d, #0000000000000000; add x8, sp, #0x8c9] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov w10, #0x2e69; movi v0.2d, #0000000000000000; add x8, sp, #0x8c9]
uint64_t fde_sub_02a608(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5285CD2AULL) << 32) | 0x9401785EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A608ULL;
}

// Func #0842 | PC: 0x02ba00..0x02ba40 (64 B) | Symbol: sub_02ba00
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_02ba00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911523E0ULL) << 32) | 0x9401763DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA00ULL;
}

// Func #0843 | PC: 0x02ba08..0x02ba48 (64 B) | Symbol: sub_02ba08
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x2ba1c; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x2ba1c; subs x19, x19, #0x30]
uint64_t fde_sub_02ba08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94016E99ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA08ULL;
}

// Func #0844 | PC: 0x02ba38..0x02ba78 (64 B) | Symbol: sub_02ba38
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x2ba14; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x2ba14; add x8, x21, x19]
uint64_t fde_sub_02ba38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF5826ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA38ULL;
}

// Func #0845 | PC: 0x02ba4c..0x02ba8c (64 B) | Symbol: sub_02ba4c
// EN: AArch64 prologue [bl #0x1ad0; b #0x2ba14; adrp x0, #0xca000; add x0, x0, #0x370] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x2ba14; adrp x0, #0xca000; add x0, x0, #0x370]
uint64_t fde_sub_02ba4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF5821ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA4CULL;
}

// Func #0846 | PC: 0x02ba5c..0x02ba9c (64 B) | Symbol: sub_02ba5c
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_02ba5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063F3ULL) << 32) | 0x97FF5825ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA5CULL;
}

// Func #0847 | PC: 0x02ba98..0x02bad8 (64 B) | Symbol: sub_02ba98
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_02ba98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF584AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA98ULL;
}

// Func #0848 | PC: 0x02ba9c..0x02d89c (7680 B) | Symbol: rex_locale_init_ctor_21
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_02ba9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA9CULL;
}

// Func #0849 | PC: 0x02bab8..0x02baf8 (64 B) | Symbol: sub_02bab8
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xca0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xca0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_02bab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13283FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BAB8ULL;
}

// Func #0850 | PC: 0x02babc..0x02bafc (64 B) | Symbol: sub_02babc
// EN: AArch64 prologue [sub sp, sp, #0xca0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xca0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_02babc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13283FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BABCULL;
}

// Func #0851 | PC: 0x02bae4..0x02bb24 (64 B) | Symbol: sub_02bae4
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x2dbf8; str x19, [sp, #0xb8]; add x19, sp, #0x598] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x2dbf8; str x19, [sp, #0xb8]; add x19, sp, #0x598]
uint64_t fde_sub_02bae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34010880ULL) << 32) | 0x97FF5847ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BAE4ULL;
}

// Func #0852 | PC: 0x02bb48..0x02bb88 (64 B) | Symbol: sub_02bb48
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9b000; add x9, x9, #0x484; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9b000; add x9, x9, #0x484; adrp x8, #0x97000]
uint64_t fde_sub_02bb48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000389ULL) << 32) | 0x97FF5816ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BB48ULL;
}

// Func #0853 | PC: 0x02bb88..0x02bbc8 (64 B) | Symbol: sub_02bb88
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; add x8, sp, #0x4c9; str x0, [sp, #0x5d8]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; add x8, sp, #0x4c9; str x0, [sp, #0x5d8]]
uint64_t fde_sub_02bb88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF5806ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BB88ULL;
}

// Func #0854 | PC: 0x02bcd4..0x02bd14 (64 B) | Symbol: sub_02bcd4
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9b000; add x8, x8, #0x510] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9b000; add x8, x8, #0x510]
uint64_t fde_sub_02bcd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF57B3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BCD4ULL;
}

// Func #0855 | PC: 0x02bd68..0x02bda8 (64 B) | Symbol: sub_02bd68
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x9b000; add x8, x8, #0x558; ldr q0, [x8]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x9b000; add x8, x8, #0x558; ldr q0, [x8]]
uint64_t fde_sub_02bd68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000388ULL) << 32) | 0x97FF578EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BD68ULL;
}

// Func #0856 | PC: 0x02c078..0x02c0b8 (64 B) | Symbol: sub_02c078
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; add x8, sp, #0x769; str x0, [sp, #0x878]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; add x8, sp, #0x769; str x0, [sp, #0x878]]
uint64_t fde_sub_02c078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF56CAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C078ULL;
}

// Func #0857 | PC: 0x02c508..0x02c548 (64 B) | Symbol: sub_02c508
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; ldr x27, [sp, #0xe0]; str x0, [sp, #0x230]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; ldr x27, [sp, #0xe0]; str x0, [sp, #0x230]]
uint64_t fde_sub_02c508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF55A6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C508ULL;
}

// Func #0858 | PC: 0x02c5c8..0x02c608 (64 B) | Symbol: sub_02c5c8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x15, #0x9b000; add x15, x15, #0x6b1] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x15, #0x9b000; add x15, x15, #0x6b1]
uint64_t fde_sub_02c5c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF5576ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C5C8ULL;
}

// Func #0859 | PC: 0x02ca34..0x02ca74 (64 B) | Symbol: sub_02ca34
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x10, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x10, [sp, #0xe0]]
uint64_t fde_sub_02ca34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000348ULL) << 32) | 0x97FF545BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CA34ULL;
}

// Func #0860 | PC: 0x02cb98..0x02cbd8 (64 B) | Symbol: sub_02cb98
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cb98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94016EFAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CB98ULL;
}

// Func #0861 | PC: 0x02cba8..0x02cbe8 (64 B) | Symbol: sub_02cba8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94016EF6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CBA8ULL;
}

// Func #0862 | PC: 0x02cbb8..0x02cbf8 (64 B) | Symbol: sub_02cbb8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cbb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94016EF2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CBB8ULL;
}

// Func #0863 | PC: 0x02cbc8..0x02cc08 (64 B) | Symbol: sub_02cbc8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xc0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xc0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cbc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063E1ULL) << 32) | 0x94016EEEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CBC8ULL;
}

// Func #0864 | PC: 0x02cbd8..0x02cc18 (64 B) | Symbol: sub_02cbd8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xd0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xd0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cbd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9406BE1ULL) << 32) | 0x94016EEAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CBD8ULL;
}

// Func #0865 | PC: 0x02cbe8..0x02cc28 (64 B) | Symbol: sub_02cbe8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_02cbe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94016EE6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CBE8ULL;
}

// Func #0866 | PC: 0x02cbf8..0x02cc38 (64 B) | Symbol: sub_02cbf8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cbf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94016EE2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CBF8ULL;
}

// Func #0867 | PC: 0x02cc08..0x02cc48 (64 B) | Symbol: sub_02cc08
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94016EDEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC08ULL;
}

// Func #0868 | PC: 0x02cc18..0x02cc58 (64 B) | Symbol: sub_02cc18
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94016EDAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC18ULL;
}

// Func #0869 | PC: 0x02cc28..0x02cc68 (64 B) | Symbol: sub_02cc28
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94016ED6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC28ULL;
}

// Func #0870 | PC: 0x02cc38..0x02cc78 (64 B) | Symbol: sub_02cc38
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94016ED2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC38ULL;
}

// Func #0871 | PC: 0x02cc48..0x02cc88 (64 B) | Symbol: sub_02cc48
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94016ECEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC48ULL;
}

// Func #0872 | PC: 0x02cc58..0x02cc98 (64 B) | Symbol: sub_02cc58
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94016ECAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC58ULL;
}

// Func #0873 | PC: 0x02cc68..0x02cca8 (64 B) | Symbol: sub_02cc68
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94016EC6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC68ULL;
}

// Func #0874 | PC: 0x02cc78..0x02ccb8 (64 B) | Symbol: sub_02cc78
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94016EC2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC78ULL;
}

// Func #0875 | PC: 0x02cc88..0x02ccc8 (64 B) | Symbol: sub_02cc88
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_02cc88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94016EBEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC88ULL;
}

// Func #0876 | PC: 0x02cc98..0x02ccd8 (64 B) | Symbol: sub_02cc98
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cc98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94016EBAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CC98ULL;
}

// Func #0877 | PC: 0x02cca8..0x02cce8 (64 B) | Symbol: sub_02cca8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_02cca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94016EB6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CCA8ULL;
}

// Func #0878 | PC: 0x02ccb8..0x02ccf8 (64 B) | Symbol: sub_02ccb8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_02ccb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94016EB2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CCB8ULL;
}

// Func #0879 | PC: 0x02ccc8..0x02cd08 (64 B) | Symbol: sub_02ccc8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ccc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94016EAEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CCC8ULL;
}

// Func #0880 | PC: 0x02ccd8..0x02cd18 (64 B) | Symbol: sub_02ccd8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ccd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94016EAAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CCD8ULL;
}

// Func #0881 | PC: 0x02cce8..0x02cd28 (64 B) | Symbol: sub_02cce8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xe0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xe0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02cce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94073E1ULL) << 32) | 0x94016EA6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CCE8ULL;
}

// Func #0882 | PC: 0x02ccf8..0x02cd38 (64 B) | Symbol: sub_02ccf8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_02ccf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94016EA2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CCF8ULL;
}

// Func #0883 | PC: 0x02cd08..0x02cd48 (64 B) | Symbol: sub_02cd08
// EN: AArch64 prologue [bl #0x88780; add x11, sp, #0x598; movi v0.2d, #0000000000000000; add x9, sp, #0x919] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x11, sp, #0x598; movi v0.2d, #0000000000000000; add x9, sp, #0x919]
uint64_t fde_sub_02cd08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911663EBULL) << 32) | 0x94016E9EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CD08ULL;
}

// Func #0884 | PC: 0x02ce1c..0x02ce5c (64 B) | Symbol: sub_02ce1c
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9b000; add x9, x9, #0x6e1; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9b000; add x9, x9, #0x6e1; adrp x8, #0x97000]
uint64_t fde_sub_02ce1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000369ULL) << 32) | 0x97FF5361ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CE1CULL;
}

// Func #0885 | PC: 0x02ce58..0x02ce98 (64 B) | Symbol: sub_02ce58
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; add x8, sp, #0x9d9; str x0, [sp, #0xae8]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; add x8, sp, #0x9d9; str x0, [sp, #0xae8]]
uint64_t fde_sub_02ce58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF5352ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CE58ULL;
}

// Func #0886 | PC: 0x02d1f8..0x02d238 (64 B) | Symbol: sub_02d1f8
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd10]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd10]; adrp x8, #0x9b000]
uint64_t fde_sub_02d1f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000348ULL) << 32) | 0x97FF526AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D1F8ULL;
}

// Func #0887 | PC: 0x02d264..0x02d2a4 (64 B) | Symbol: sub_02d264
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x10e0]; strh w21, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x10e0]; strh w21, [x0, #0x20]]
uint64_t fde_sub_02d264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FF524FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D264ULL;
}

// Func #0888 | PC: 0x02d29c..0x02d2dc (64 B) | Symbol: sub_02d29c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd50]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd50]; adrp x8, #0x9b000]
uint64_t fde_sub_02d29c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000348ULL) << 32) | 0x97FF5241ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D29CULL;
}

// Func #0889 | PC: 0x02d2fc..0x02d33c (64 B) | Symbol: sub_02d2fc
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x11a0]; stur x22, [x0, #0x1d]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x11a0]; stur x22, [x0, #0x1d]]
uint64_t fde_sub_02d2fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF5229ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D2FCULL;
}

// Func #0890 | PC: 0x02d334..0x02d374 (64 B) | Symbol: sub_02d334
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x8, #0x9b000; add x8, x8, #0x7ac] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x8, #0x9b000; add x8, x8, #0x7ac]
uint64_t fde_sub_02d334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FF521BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D334ULL;
}

// Func #0891 | PC: 0x02d384..0x02d3c4 (64 B) | Symbol: sub_02d384
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; str x0, [sp, #0x1260]; strb wzr, [x0, #0x1d]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; str x0, [sp, #0x1260]; strb wzr, [x0, #0x1d]]
uint64_t fde_sub_02d384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FF5207ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D384ULL;
}

// Func #0892 | PC: 0x02d3b8..0x02d3f8 (64 B) | Symbol: sub_02d3b8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x9b000; add x8, x8, #0x7ca] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x9b000; add x8, x8, #0x7ca]
uint64_t fde_sub_02d3b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FF51FAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D3B8ULL;
}

// Func #0893 | PC: 0x02d408..0x02d448 (64 B) | Symbol: sub_02d408
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x1320]; strh w21, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x1320]; strh w21, [x0, #0x20]]
uint64_t fde_sub_02d408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FF51E6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D408ULL;
}

// Func #0894 | PC: 0x02d440..0x02d480 (64 B) | Symbol: sub_02d440
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x9b000; add x8, x8, #0x7ed] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x9b000; add x8, x8, #0x7ed]
uint64_t fde_sub_02d440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FF51D8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D440ULL;
}

// Func #0895 | PC: 0x02d490..0x02d4d0 (64 B) | Symbol: sub_02d490
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x13e0]; strh w21, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x13e0]; strh w21, [x0, #0x20]]
uint64_t fde_sub_02d490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FF51C4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D490ULL;
}

// Func #0896 | PC: 0x02d4c8..0x02d508 (64 B) | Symbol: sub_02d4c8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9b000; add x8, x8, #0x810] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9b000; add x8, x8, #0x810]
uint64_t fde_sub_02d4c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF51B6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D4C8ULL;
}

// Func #0897 | PC: 0x02d518..0x02d558 (64 B) | Symbol: sub_02d518
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x14a0]; stur x21, [x0, #0x1d]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x14a0]; stur x21, [x0, #0x1d]]
uint64_t fde_sub_02d518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF51A2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D518ULL;
}

// Func #0898 | PC: 0x02d550..0x02d590 (64 B) | Symbol: sub_02d550
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9b000; add x8, x8, #0x836] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9b000; add x8, x8, #0x836]
uint64_t fde_sub_02d550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF5194ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D550ULL;
}

// Func #0899 | PC: 0x02d5a0..0x02d5e0 (64 B) | Symbol: sub_02d5a0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1560]; stur x21, [x0, #0x1d]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1560]; stur x21, [x0, #0x1d]]
uint64_t fde_sub_02d5a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF5180ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D5A0ULL;
}

// Func #0900 | PC: 0x02d5dc..0x02d61c (64 B) | Symbol: sub_02d5dc
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9b000; add x8, x8, #0x85c] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9b000; add x8, x8, #0x85c]
uint64_t fde_sub_02d5dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF5171ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D5DCULL;
}

// Func #0901 | PC: 0x02d62c..0x02d66c (64 B) | Symbol: sub_02d62c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x21, #0xb0]; str x22, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x21, #0xb0]; str x22, [x0, #0x10]]
uint64_t fde_sub_02d62c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF515DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D62CULL;
}

// Func #0902 | PC: 0x02d65c..0x02d69c (64 B) | Symbol: sub_02d65c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9b000; add x8, x8, #0x875] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9b000; add x8, x8, #0x875]
uint64_t fde_sub_02d65c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF5151ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D65CULL;
}

// Func #0903 | PC: 0x02d6ac..0x02d6ec (64 B) | Symbol: sub_02d6ac
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [x21, #0x170]; adrp x11, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [x21, #0x170]; adrp x11, #0x9b000]
uint64_t fde_sub_02d6ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF513DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D6ACULL;
}

// Func #0904 | PC: 0x02d750..0x02d790 (64 B) | Symbol: sub_02d750
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9b000; add x8, x8, #0x8a6] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9b000; add x8, x8, #0x8a6]
uint64_t fde_sub_02d750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF5114ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D750ULL;
}

// Func #0905 | PC: 0x02d7a0..0x02d7e0 (64 B) | Symbol: sub_02d7a0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x21, #0x2f0]; str x22, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x21, #0x2f0]; str x22, [x0, #0x10]]
uint64_t fde_sub_02d7a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF5100ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D7A0ULL;
}

// Func #0906 | PC: 0x02d7d0..0x02d810 (64 B) | Symbol: sub_02d7d0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9b000; add x8, x8, #0x8bf] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9b000; add x8, x8, #0x8bf]
uint64_t fde_sub_02d7d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF50F4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D7D0ULL;
}

// Func #0907 | PC: 0x02d820..0x02d860 (64 B) | Symbol: sub_02d820
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x21, #0x3b0]; str x22, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x21, #0x3b0]; str x22, [x0, #0x10]]
uint64_t fde_sub_02d820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FF50E0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D820ULL;
}

// Func #0908 | PC: 0x02d850..0x02d890 (64 B) | Symbol: sub_02d850
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9b000; add x8, x8, #0x8d8] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9b000; add x8, x8, #0x8d8]
uint64_t fde_sub_02d850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF50D4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D850ULL;
}

// Func #0909 | PC: 0x02d8a0..0x02d8e0 (64 B) | Symbol: sub_02d8a0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [x21, #0x470]; strb wzr, [x0, #0x1b]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [x21, #0x470]; strb wzr, [x0, #0x1b]]
uint64_t fde_sub_02d8a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF50C0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D8A0ULL;
}

// Func #0910 | PC: 0x02d8d4..0x02d914 (64 B) | Symbol: sub_02d8d4
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9b000; add x8, x8, #0x8f4] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9b000; add x8, x8, #0x8f4]
uint64_t fde_sub_02d8d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF50B3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D8D4ULL;
}

// Func #0911 | PC: 0x02d924..0x02d964 (64 B) | Symbol: sub_02d924
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [x21, #0x530]; mov w13, #0x16] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [x21, #0x530]; mov w13, #0x16]
uint64_t fde_sub_02d924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF509FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D924ULL;
}

// Func #0912 | PC: 0x02db94..0x02dbd4 (64 B) | Symbol: sub_02db94
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x598; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x598; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_02db94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911663E0ULL) << 32) | 0x94016DD8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DB94ULL;
}

// Func #0913 | PC: 0x02db9c..0x02dbdc (64 B) | Symbol: sub_02db9c
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x2dbb0; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x2dbb0; subs x19, x19, #0x30]
uint64_t fde_sub_02db9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94016634ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DB9CULL;
}

// Func #0914 | PC: 0x02dbcc..0x02dc0c (64 B) | Symbol: sub_02dbcc
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x2dba8; add x8, x28, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x2dba8; add x8, x28, x19]
uint64_t fde_sub_02dbcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF4FC1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DBCCULL;
}

// Func #0915 | PC: 0x02dbe0..0x02dc20 (64 B) | Symbol: sub_02dbe0
// EN: AArch64 prologue [bl #0x1ad0; b #0x2dba8; adrp x0, #0xcb000; add x0, x0, #0xa70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x2dba8; adrp x0, #0xcb000; add x0, x0, #0xa70]
uint64_t fde_sub_02dbe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF4FBCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DBE0ULL;
}

// Func #0916 | PC: 0x02dbf0..0x02dc30 (64 B) | Symbol: sub_02dbf0
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_02dbf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405FF3ULL) << 32) | 0x97FF4FC0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DBF0ULL;
}

// Func #0917 | PC: 0x02dc2c..0x02dc6c (64 B) | Symbol: sub_02dc2c
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_02dc2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF4FE5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DC2CULL;
}

// Func #0918 | PC: 0x02dc30..0x02fa30 (7680 B) | Symbol: rex_locale_init_ctor_22
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_02dc30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DC30ULL;
}

// Func #0919 | PC: 0x02dc4c..0x02dc8c (64 B) | Symbol: sub_02dc4c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_02dc4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13183FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DC4CULL;
}

// Func #0920 | PC: 0x02dc50..0x02dc90 (64 B) | Symbol: sub_02dc50
// EN: AArch64 prologue [sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc60; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_02dc50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DC50ULL;
}

// Func #0921 | PC: 0x02dc78..0x02dcb8 (64 B) | Symbol: sub_02dc78
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x3026c; movi v4.2d, #0000000000000000; adrp x0, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x3026c; movi v4.2d, #0000000000000000; adrp x0, #0x9b000]
uint64_t fde_sub_02dc78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34012F80ULL) << 32) | 0x97FF4FE2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DC78ULL;
}

// Func #0922 | PC: 0x02e530..0x02e570 (64 B) | Symbol: sub_02e530
// EN: AArch64 prologue [bl #0x1ba0; adrp x10, #0x9b000; add x10, x10, #0xa5f; ldp q0, q1, [x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x10, #0x9b000; add x10, x10, #0xa5f; ldp q0, q1, [x10]]
uint64_t fde_sub_02e530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB000036AULL) << 32) | 0x97FF4D9CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02E530ULL;
}

// Func #0923 | PC: 0x02e5f0..0x02e630 (64 B) | Symbol: sub_02e5f0
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; adrp x8, #0x9b000]
uint64_t fde_sub_02e5f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000348ULL) << 32) | 0x97FF4D6CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02E5F0ULL;
}

// Func #0924 | PC: 0x02e9c4..0x02ea04 (64 B) | Symbol: sub_02e9c4
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; adrp x9, #0x9b000; add x9, x9, #0xaf8] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; adrp x9, #0x9b000; add x9, x9, #0xaf8]
uint64_t fde_sub_02e9c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000348ULL) << 32) | 0x97FF4C77ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02E9C4ULL;
}

// Func #0925 | PC: 0x02ea84..0x02eac4 (64 B) | Symbol: sub_02ea84
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x20]; add x8, x22, #0x3f8; movi v2.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x20]; add x8, x22, #0x3f8; movi v2.2d, #0000000000000000]
uint64_t fde_sub_02ea84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC00BE0ULL) << 32) | 0x97FF4C47ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EA84ULL;
}

// Func #0926 | PC: 0x02ebf0..0x02ec30 (64 B) | Symbol: sub_02ebf0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ebf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x940166E4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EBF0ULL;
}

// Func #0927 | PC: 0x02ec00..0x02ec40 (64 B) | Symbol: sub_02ec00
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x940166E0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC00ULL;
}

// Func #0928 | PC: 0x02ec10..0x02ec50 (64 B) | Symbol: sub_02ec10
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x940166DCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC10ULL;
}

// Func #0929 | PC: 0x02ec20..0x02ec60 (64 B) | Symbol: sub_02ec20
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x940166D8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC20ULL;
}

// Func #0930 | PC: 0x02ec30..0x02ec70 (64 B) | Symbol: sub_02ec30
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94057E1ULL) << 32) | 0x940166D4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC30ULL;
}

// Func #0931 | PC: 0x02ec40..0x02ec80 (64 B) | Symbol: sub_02ec40
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x940166D0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC40ULL;
}

// Func #0932 | PC: 0x02ec50..0x02ec90 (64 B) | Symbol: sub_02ec50
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x940166CCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC50ULL;
}

// Func #0933 | PC: 0x02ec60..0x02eca0 (64 B) | Symbol: sub_02ec60
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x940166C8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC60ULL;
}

// Func #0934 | PC: 0x02ec70..0x02ecb0 (64 B) | Symbol: sub_02ec70
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x940166C4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC70ULL;
}

// Func #0935 | PC: 0x02ec80..0x02ecc0 (64 B) | Symbol: sub_02ec80
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x940166C0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC80ULL;
}

// Func #0936 | PC: 0x02ec90..0x02ecd0 (64 B) | Symbol: sub_02ec90
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ec90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x940166BCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EC90ULL;
}

// Func #0937 | PC: 0x02eca0..0x02ece0 (64 B) | Symbol: sub_02eca0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02eca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x940166B8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ECA0ULL;
}

// Func #0938 | PC: 0x02ecb0..0x02ecf0 (64 B) | Symbol: sub_02ecb0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_02ecb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940166B4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ECB0ULL;
}

// Func #0939 | PC: 0x02ecc0..0x02ed00 (64 B) | Symbol: sub_02ecc0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ecc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x940166B0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ECC0ULL;
}

// Func #0940 | PC: 0x02ecd0..0x02ed10 (64 B) | Symbol: sub_02ecd0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ecd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x940166ACULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ECD0ULL;
}

// Func #0941 | PC: 0x02ece0..0x02ed20 (64 B) | Symbol: sub_02ece0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ece0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x940166A8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ECE0ULL;
}

// Func #0942 | PC: 0x02ecf0..0x02ed30 (64 B) | Symbol: sub_02ecf0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ecf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x940166A4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ECF0ULL;
}

// Func #0943 | PC: 0x02ed00..0x02ed40 (64 B) | Symbol: sub_02ed00
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ed00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x940166A0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ED00ULL;
}

// Func #0944 | PC: 0x02ed10..0x02ed50 (64 B) | Symbol: sub_02ed10
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_02ed10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401669CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ED10ULL;
}

// Func #0945 | PC: 0x02ed20..0x02ed60 (64 B) | Symbol: sub_02ed20
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ed20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94016698ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ED20ULL;
}

// Func #0946 | PC: 0x02ed30..0x02ed70 (64 B) | Symbol: sub_02ed30
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_02ed30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94016694ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ED30ULL;
}

// Func #0947 | PC: 0x02ed40..0x02ed80 (64 B) | Symbol: sub_02ed40
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_02ed40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94016690ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ED40ULL;
}

// Func #0948 | PC: 0x02ed50..0x02ed90 (64 B) | Symbol: sub_02ed50
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_02ed50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401668CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ED50ULL;
}

// Func #0949 | PC: 0x02ed60..0x02eda0 (64 B) | Symbol: sub_02ed60
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x8d9; stur q0, [x9, #0xff]] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x9, sp, #0x8d9; stur q0, [x9, #0xff]]
uint64_t fde_sub_02ed60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x94016688ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ED60ULL;
}

// Func #0950 | PC: 0x02f600..0x02f640 (64 B) | Symbol: sub_02f600
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x8, #0x9b000; add x8, x8, #0xc5e] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x8, #0x9b000; add x8, x8, #0xc5e]
uint64_t fde_sub_02f600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FF4968ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F600ULL;
}

// Func #0951 | PC: 0x02f644..0x02f684 (64 B) | Symbol: sub_02f644
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9b000; adrp x8, #0x97000; add x9, x9, #0xc76] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9b000; adrp x8, #0x97000; add x9, x9, #0xc76]
uint64_t fde_sub_02f644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000369ULL) << 32) | 0x97FF4957ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F644ULL;
}

// Func #0952 | PC: 0x02f6c0..0x02f700 (64 B) | Symbol: sub_02f6c0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x9, #0x9b000; add x9, x9, #0xcb7] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x9, #0x9b000; add x9, x9, #0xcb7]
uint64_t fde_sub_02f6c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FF4938ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02F6C0ULL;
}

// Func #0953 | PC: 0x02fbc4..0x02fc04 (64 B) | Symbol: sub_02fbc4
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x8, #0x9b000; add x8, x8, #0xdeb] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x8, #0x9b000; add x8, x8, #0xdeb]
uint64_t fde_sub_02fbc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FF47F7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02FBC4ULL;
}

// Func #0954 | PC: 0x02fc08..0x02fc48 (64 B) | Symbol: sub_02fc08
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x90]; adrp x8, #0x9b000; add x8, x8, #0xe03] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x90]; adrp x8, #0x9b000; add x8, x8, #0xe03]
uint64_t fde_sub_02fc08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC027E0ULL) << 32) | 0x97FF47E6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02FC08ULL;
}

// Func #0955 | PC: 0x02fc78..0x02fcb8 (64 B) | Symbol: sub_02fc78
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; add x8, x21, #0x648; movi v1.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; add x8, x21, #0x648; movi v1.2d, #0000000000000000]
uint64_t fde_sub_02fc78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FF47CAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02FC78ULL;
}

// Func #0956 | PC: 0x030208..0x030248 (64 B) | Symbol: sub_030208
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x558; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x558; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_030208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911563E0ULL) << 32) | 0x9401643BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030208ULL;
}

// Func #0957 | PC: 0x030210..0x030250 (64 B) | Symbol: sub_030210
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x30224; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x30224; subs x19, x19, #0x30]
uint64_t fde_sub_030210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94015C97ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030210ULL;
}

// Func #0958 | PC: 0x030240..0x030280 (64 B) | Symbol: sub_030240
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3021c; add x8, x23, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3021c; add x8, x23, x19]
uint64_t fde_sub_030240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF4624ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030240ULL;
}

// Func #0959 | PC: 0x030254..0x030294 (64 B) | Symbol: sub_030254
// EN: AArch64 prologue [bl #0x1ad0; b #0x3021c; adrp x0, #0xcd000; add x0, x0, #0x170] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x3021c; adrp x0, #0xcd000; add x0, x0, #0x170]
uint64_t fde_sub_030254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF461FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030254ULL;
}

uint64_t DispatchRexShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x020c30ULL: return fde_sub_020c30(a0, a1, a2);
        case 0x020c40ULL: return fde_sub_020c40(a0, a1, a2);
        case 0x020c50ULL: return fde_sub_020c50(a0, a1, a2);
        case 0x020c60ULL: return fde_sub_020c60(a0, a1, a2);
        case 0x020c70ULL: return fde_sub_020c70(a0, a1, a2);
        case 0x020c80ULL: return fde_sub_020c80(a0, a1, a2);
        case 0x020c90ULL: return fde_sub_020c90(a0, a1, a2);
        case 0x020ca0ULL: return fde_sub_020ca0(a0, a1, a2);
        case 0x020cb0ULL: return fde_sub_020cb0(a0, a1, a2);
        case 0x020cc0ULL: return fde_sub_020cc0(a0, a1, a2);
        case 0x020cd0ULL: return fde_sub_020cd0(a0, a1, a2);
        case 0x020ce0ULL: return fde_sub_020ce0(a0, a1, a2);
        case 0x020cf0ULL: return fde_sub_020cf0(a0, a1, a2);
        case 0x020d00ULL: return fde_sub_020d00(a0, a1, a2);
        case 0x020d10ULL: return fde_sub_020d10(a0, a1, a2);
        case 0x021a74ULL: return fde_sub_021a74(a0, a1, a2);
        case 0x021a7cULL: return fde_sub_021a7c(a0, a1, a2);
        case 0x021aacULL: return fde_sub_021aac(a0, a1, a2);
        case 0x021ac0ULL: return fde_sub_021ac0(a0, a1, a2);
        case 0x021ad0ULL: return fde_sub_021ad0(a0, a1, a2);
        case 0x021b0cULL: return fde_sub_021b0c(a0, a1, a2);
        case 0x021b10ULL: return fde_sub_021b10(a0, a1, a2);
        case 0x021b2cULL: return fde_sub_021b2c(a0, a1, a2);
        case 0x021b30ULL: return fde_sub_021b30(a0, a1, a2);
        case 0x021b58ULL: return fde_sub_021b58(a0, a1, a2);
        case 0x0223f4ULL: return fde_sub_0223f4(a0, a1, a2);
        case 0x022a3cULL: return fde_sub_022a3c(a0, a1, a2);
        case 0x022a4cULL: return fde_sub_022a4c(a0, a1, a2);
        case 0x022a5cULL: return fde_sub_022a5c(a0, a1, a2);
        case 0x022a6cULL: return fde_sub_022a6c(a0, a1, a2);
        case 0x022a7cULL: return fde_sub_022a7c(a0, a1, a2);
        case 0x022a8cULL: return fde_sub_022a8c(a0, a1, a2);
        case 0x022a9cULL: return fde_sub_022a9c(a0, a1, a2);
        case 0x022aacULL: return fde_sub_022aac(a0, a1, a2);
        case 0x022abcULL: return fde_sub_022abc(a0, a1, a2);
        case 0x022accULL: return fde_sub_022acc(a0, a1, a2);
        case 0x022adcULL: return fde_sub_022adc(a0, a1, a2);
        case 0x022aecULL: return fde_sub_022aec(a0, a1, a2);
        case 0x022afcULL: return fde_sub_022afc(a0, a1, a2);
        case 0x022b0cULL: return fde_sub_022b0c(a0, a1, a2);
        case 0x022b1cULL: return fde_sub_022b1c(a0, a1, a2);
        case 0x022b2cULL: return fde_sub_022b2c(a0, a1, a2);
        case 0x022b3cULL: return fde_sub_022b3c(a0, a1, a2);
        case 0x022b4cULL: return fde_sub_022b4c(a0, a1, a2);
        case 0x022b5cULL: return fde_sub_022b5c(a0, a1, a2);
        case 0x022b6cULL: return fde_sub_022b6c(a0, a1, a2);
        case 0x022b7cULL: return fde_sub_022b7c(a0, a1, a2);
        case 0x022b8cULL: return fde_sub_022b8c(a0, a1, a2);
        case 0x022b9cULL: return fde_sub_022b9c(a0, a1, a2);
        case 0x022bacULL: return fde_sub_022bac(a0, a1, a2);
        case 0x023864ULL: return fde_sub_023864(a0, a1, a2);
        case 0x02386cULL: return fde_sub_02386c(a0, a1, a2);
        case 0x02389cULL: return fde_sub_02389c(a0, a1, a2);
        case 0x0238b0ULL: return fde_sub_0238b0(a0, a1, a2);
        case 0x0238c0ULL: return fde_sub_0238c0(a0, a1, a2);
        case 0x0238fcULL: return fde_sub_0238fc(a0, a1, a2);
        case 0x023900ULL: return fde_sub_023900(a0, a1, a2);
        case 0x02391cULL: return fde_sub_02391c(a0, a1, a2);
        case 0x023920ULL: return fde_sub_023920(a0, a1, a2);
        case 0x023948ULL: return fde_sub_023948(a0, a1, a2);
        case 0x0241dcULL: return fde_sub_0241dc(a0, a1, a2);
        case 0x0242a4ULL: return fde_sub_0242a4(a0, a1, a2);
        case 0x024714ULL: return fde_sub_024714(a0, a1, a2);
        case 0x02488cULL: return fde_sub_02488c(a0, a1, a2);
        case 0x02489cULL: return fde_sub_02489c(a0, a1, a2);
        case 0x0248acULL: return fde_sub_0248ac(a0, a1, a2);
        case 0x0248bcULL: return fde_sub_0248bc(a0, a1, a2);
        case 0x0248ccULL: return fde_sub_0248cc(a0, a1, a2);
        case 0x0248dcULL: return fde_sub_0248dc(a0, a1, a2);
        case 0x0248ecULL: return fde_sub_0248ec(a0, a1, a2);
        case 0x0248fcULL: return fde_sub_0248fc(a0, a1, a2);
        case 0x02490cULL: return fde_sub_02490c(a0, a1, a2);
        case 0x02491cULL: return fde_sub_02491c(a0, a1, a2);
        case 0x02492cULL: return fde_sub_02492c(a0, a1, a2);
        case 0x02493cULL: return fde_sub_02493c(a0, a1, a2);
        case 0x02494cULL: return fde_sub_02494c(a0, a1, a2);
        case 0x02495cULL: return fde_sub_02495c(a0, a1, a2);
        case 0x02496cULL: return fde_sub_02496c(a0, a1, a2);
        case 0x02497cULL: return fde_sub_02497c(a0, a1, a2);
        case 0x02498cULL: return fde_sub_02498c(a0, a1, a2);
        case 0x02499cULL: return fde_sub_02499c(a0, a1, a2);
        case 0x0249acULL: return fde_sub_0249ac(a0, a1, a2);
        case 0x0249bcULL: return fde_sub_0249bc(a0, a1, a2);
        case 0x0249ccULL: return fde_sub_0249cc(a0, a1, a2);
        case 0x0249dcULL: return fde_sub_0249dc(a0, a1, a2);
        case 0x0249ecULL: return fde_sub_0249ec(a0, a1, a2);
        case 0x0249fcULL: return fde_sub_0249fc(a0, a1, a2);
        case 0x025014ULL: return fde_sub_025014(a0, a1, a2);
        case 0x025064ULL: return fde_sub_025064(a0, a1, a2);
        case 0x0250f8ULL: return fde_sub_0250f8(a0, a1, a2);
        case 0x025840ULL: return fde_sub_025840(a0, a1, a2);
        case 0x025848ULL: return fde_sub_025848(a0, a1, a2);
        case 0x025878ULL: return fde_sub_025878(a0, a1, a2);
        case 0x02588cULL: return fde_sub_02588c(a0, a1, a2);
        case 0x02589cULL: return fde_sub_02589c(a0, a1, a2);
        case 0x0258d8ULL: return fde_sub_0258d8(a0, a1, a2);
        case 0x0258dcULL: return fde_sub_0258dc(a0, a1, a2);
        case 0x0258f8ULL: return fde_sub_0258f8(a0, a1, a2);
        case 0x0258fcULL: return fde_sub_0258fc(a0, a1, a2);
        case 0x025924ULL: return fde_sub_025924(a0, a1, a2);
        case 0x0261acULL: return fde_sub_0261ac(a0, a1, a2);
        case 0x02626cULL: return fde_sub_02626c(a0, a1, a2);
        case 0x02681cULL: return fde_sub_02681c(a0, a1, a2);
        case 0x02682cULL: return fde_sub_02682c(a0, a1, a2);
        case 0x02683cULL: return fde_sub_02683c(a0, a1, a2);
        case 0x02684cULL: return fde_sub_02684c(a0, a1, a2);
        case 0x02685cULL: return fde_sub_02685c(a0, a1, a2);
        case 0x02686cULL: return fde_sub_02686c(a0, a1, a2);
        case 0x02687cULL: return fde_sub_02687c(a0, a1, a2);
        case 0x02688cULL: return fde_sub_02688c(a0, a1, a2);
        case 0x02689cULL: return fde_sub_02689c(a0, a1, a2);
        case 0x0268acULL: return fde_sub_0268ac(a0, a1, a2);
        case 0x0268bcULL: return fde_sub_0268bc(a0, a1, a2);
        case 0x0268ccULL: return fde_sub_0268cc(a0, a1, a2);
        case 0x0268dcULL: return fde_sub_0268dc(a0, a1, a2);
        case 0x0268ecULL: return fde_sub_0268ec(a0, a1, a2);
        case 0x0268fcULL: return fde_sub_0268fc(a0, a1, a2);
        case 0x02690cULL: return fde_sub_02690c(a0, a1, a2);
        case 0x02691cULL: return fde_sub_02691c(a0, a1, a2);
        case 0x02692cULL: return fde_sub_02692c(a0, a1, a2);
        case 0x02693cULL: return fde_sub_02693c(a0, a1, a2);
        case 0x02694cULL: return fde_sub_02694c(a0, a1, a2);
        case 0x026960ULL: return fde_sub_026960(a0, a1, a2);
        case 0x026970ULL: return fde_sub_026970(a0, a1, a2);
        case 0x026980ULL: return fde_sub_026980(a0, a1, a2);
        case 0x026990ULL: return fde_sub_026990(a0, a1, a2);
        case 0x027680ULL: return fde_sub_027680(a0, a1, a2);
        case 0x027688ULL: return fde_sub_027688(a0, a1, a2);
        case 0x0276b8ULL: return fde_sub_0276b8(a0, a1, a2);
        case 0x0276ccULL: return fde_sub_0276cc(a0, a1, a2);
        case 0x0276dcULL: return fde_sub_0276dc(a0, a1, a2);
        case 0x027718ULL: return fde_sub_027718(a0, a1, a2);
        case 0x02771cULL: return fde_sub_02771c(a0, a1, a2);
        case 0x027738ULL: return fde_sub_027738(a0, a1, a2);
        case 0x02773cULL: return fde_sub_02773c(a0, a1, a2);
        case 0x027764ULL: return fde_sub_027764(a0, a1, a2);
        case 0x027f94ULL: return fde_sub_027f94(a0, a1, a2);
        case 0x028050ULL: return fde_sub_028050(a0, a1, a2);
        case 0x0283f4ULL: return fde_sub_0283f4(a0, a1, a2);
        case 0x0284b8ULL: return fde_sub_0284b8(a0, a1, a2);
        case 0x028520ULL: return fde_sub_028520(a0, a1, a2);
        case 0x0285dcULL: return fde_sub_0285dc(a0, a1, a2);
        case 0x028630ULL: return fde_sub_028630(a0, a1, a2);
        case 0x028640ULL: return fde_sub_028640(a0, a1, a2);
        case 0x028650ULL: return fde_sub_028650(a0, a1, a2);
        case 0x028660ULL: return fde_sub_028660(a0, a1, a2);
        case 0x028670ULL: return fde_sub_028670(a0, a1, a2);
        case 0x028680ULL: return fde_sub_028680(a0, a1, a2);
        case 0x028690ULL: return fde_sub_028690(a0, a1, a2);
        case 0x0286a0ULL: return fde_sub_0286a0(a0, a1, a2);
        case 0x0286b0ULL: return fde_sub_0286b0(a0, a1, a2);
        case 0x0286c0ULL: return fde_sub_0286c0(a0, a1, a2);
        case 0x0286d0ULL: return fde_sub_0286d0(a0, a1, a2);
        case 0x0286e0ULL: return fde_sub_0286e0(a0, a1, a2);
        case 0x0286f0ULL: return fde_sub_0286f0(a0, a1, a2);
        case 0x028700ULL: return fde_sub_028700(a0, a1, a2);
        case 0x028710ULL: return fde_sub_028710(a0, a1, a2);
        case 0x028720ULL: return fde_sub_028720(a0, a1, a2);
        case 0x028730ULL: return fde_sub_028730(a0, a1, a2);
        case 0x028740ULL: return fde_sub_028740(a0, a1, a2);
        case 0x028750ULL: return fde_sub_028750(a0, a1, a2);
        case 0x028760ULL: return fde_sub_028760(a0, a1, a2);
        case 0x028770ULL: return fde_sub_028770(a0, a1, a2);
        case 0x028780ULL: return fde_sub_028780(a0, a1, a2);
        case 0x028790ULL: return fde_sub_028790(a0, a1, a2);
        case 0x0287a0ULL: return fde_sub_0287a0(a0, a1, a2);
        case 0x0294a8ULL: return fde_sub_0294a8(a0, a1, a2);
        case 0x0294b0ULL: return fde_sub_0294b0(a0, a1, a2);
        case 0x0294e0ULL: return fde_sub_0294e0(a0, a1, a2);
        case 0x0294f4ULL: return fde_sub_0294f4(a0, a1, a2);
        case 0x029504ULL: return fde_sub_029504(a0, a1, a2);
        case 0x029540ULL: return fde_sub_029540(a0, a1, a2);
        case 0x029544ULL: return fde_sub_029544(a0, a1, a2);
        case 0x029560ULL: return fde_sub_029560(a0, a1, a2);
        case 0x029564ULL: return fde_sub_029564(a0, a1, a2);
        case 0x02958cULL: return fde_sub_02958c(a0, a1, a2);
        case 0x029e20ULL: return fde_sub_029e20(a0, a1, a2);
        case 0x02a31cULL: return fde_sub_02a31c(a0, a1, a2);
        case 0x02a494ULL: return fde_sub_02a494(a0, a1, a2);
        case 0x02a4a4ULL: return fde_sub_02a4a4(a0, a1, a2);
        case 0x02a4b4ULL: return fde_sub_02a4b4(a0, a1, a2);
        case 0x02a4c4ULL: return fde_sub_02a4c4(a0, a1, a2);
        case 0x02a4d4ULL: return fde_sub_02a4d4(a0, a1, a2);
        case 0x02a4e4ULL: return fde_sub_02a4e4(a0, a1, a2);
        case 0x02a4f4ULL: return fde_sub_02a4f4(a0, a1, a2);
        case 0x02a504ULL: return fde_sub_02a504(a0, a1, a2);
        case 0x02a514ULL: return fde_sub_02a514(a0, a1, a2);
        case 0x02a524ULL: return fde_sub_02a524(a0, a1, a2);
        case 0x02a534ULL: return fde_sub_02a534(a0, a1, a2);
        case 0x02a544ULL: return fde_sub_02a544(a0, a1, a2);
        case 0x02a554ULL: return fde_sub_02a554(a0, a1, a2);
        case 0x02a564ULL: return fde_sub_02a564(a0, a1, a2);
        case 0x02a574ULL: return fde_sub_02a574(a0, a1, a2);
        case 0x02a584ULL: return fde_sub_02a584(a0, a1, a2);
        case 0x02a594ULL: return fde_sub_02a594(a0, a1, a2);
        case 0x02a5a4ULL: return fde_sub_02a5a4(a0, a1, a2);
        case 0x02a5b8ULL: return fde_sub_02a5b8(a0, a1, a2);
        case 0x02a5c8ULL: return fde_sub_02a5c8(a0, a1, a2);
        case 0x02a5d8ULL: return fde_sub_02a5d8(a0, a1, a2);
        case 0x02a5e8ULL: return fde_sub_02a5e8(a0, a1, a2);
        case 0x02a5f8ULL: return fde_sub_02a5f8(a0, a1, a2);
        case 0x02a608ULL: return fde_sub_02a608(a0, a1, a2);
        case 0x02ba00ULL: return fde_sub_02ba00(a0, a1, a2);
        case 0x02ba08ULL: return fde_sub_02ba08(a0, a1, a2);
        case 0x02ba38ULL: return fde_sub_02ba38(a0, a1, a2);
        case 0x02ba4cULL: return fde_sub_02ba4c(a0, a1, a2);
        case 0x02ba5cULL: return fde_sub_02ba5c(a0, a1, a2);
        case 0x02ba98ULL: return fde_sub_02ba98(a0, a1, a2);
        case 0x02ba9cULL: return fde_sub_02ba9c(a0, a1, a2);
        case 0x02bab8ULL: return fde_sub_02bab8(a0, a1, a2);
        case 0x02babcULL: return fde_sub_02babc(a0, a1, a2);
        case 0x02bae4ULL: return fde_sub_02bae4(a0, a1, a2);
        case 0x02bb48ULL: return fde_sub_02bb48(a0, a1, a2);
        case 0x02bb88ULL: return fde_sub_02bb88(a0, a1, a2);
        case 0x02bcd4ULL: return fde_sub_02bcd4(a0, a1, a2);
        case 0x02bd68ULL: return fde_sub_02bd68(a0, a1, a2);
        case 0x02c078ULL: return fde_sub_02c078(a0, a1, a2);
        case 0x02c508ULL: return fde_sub_02c508(a0, a1, a2);
        case 0x02c5c8ULL: return fde_sub_02c5c8(a0, a1, a2);
        case 0x02ca34ULL: return fde_sub_02ca34(a0, a1, a2);
        case 0x02cb98ULL: return fde_sub_02cb98(a0, a1, a2);
        case 0x02cba8ULL: return fde_sub_02cba8(a0, a1, a2);
        case 0x02cbb8ULL: return fde_sub_02cbb8(a0, a1, a2);
        case 0x02cbc8ULL: return fde_sub_02cbc8(a0, a1, a2);
        case 0x02cbd8ULL: return fde_sub_02cbd8(a0, a1, a2);
        case 0x02cbe8ULL: return fde_sub_02cbe8(a0, a1, a2);
        case 0x02cbf8ULL: return fde_sub_02cbf8(a0, a1, a2);
        case 0x02cc08ULL: return fde_sub_02cc08(a0, a1, a2);
        case 0x02cc18ULL: return fde_sub_02cc18(a0, a1, a2);
        case 0x02cc28ULL: return fde_sub_02cc28(a0, a1, a2);
        case 0x02cc38ULL: return fde_sub_02cc38(a0, a1, a2);
        case 0x02cc48ULL: return fde_sub_02cc48(a0, a1, a2);
        case 0x02cc58ULL: return fde_sub_02cc58(a0, a1, a2);
        case 0x02cc68ULL: return fde_sub_02cc68(a0, a1, a2);
        case 0x02cc78ULL: return fde_sub_02cc78(a0, a1, a2);
        case 0x02cc88ULL: return fde_sub_02cc88(a0, a1, a2);
        case 0x02cc98ULL: return fde_sub_02cc98(a0, a1, a2);
        case 0x02cca8ULL: return fde_sub_02cca8(a0, a1, a2);
        case 0x02ccb8ULL: return fde_sub_02ccb8(a0, a1, a2);
        case 0x02ccc8ULL: return fde_sub_02ccc8(a0, a1, a2);
        case 0x02ccd8ULL: return fde_sub_02ccd8(a0, a1, a2);
        case 0x02cce8ULL: return fde_sub_02cce8(a0, a1, a2);
        case 0x02ccf8ULL: return fde_sub_02ccf8(a0, a1, a2);
        case 0x02cd08ULL: return fde_sub_02cd08(a0, a1, a2);
        case 0x02ce1cULL: return fde_sub_02ce1c(a0, a1, a2);
        case 0x02ce58ULL: return fde_sub_02ce58(a0, a1, a2);
        case 0x02d1f8ULL: return fde_sub_02d1f8(a0, a1, a2);
        case 0x02d264ULL: return fde_sub_02d264(a0, a1, a2);
        case 0x02d29cULL: return fde_sub_02d29c(a0, a1, a2);
        case 0x02d2fcULL: return fde_sub_02d2fc(a0, a1, a2);
        case 0x02d334ULL: return fde_sub_02d334(a0, a1, a2);
        case 0x02d384ULL: return fde_sub_02d384(a0, a1, a2);
        case 0x02d3b8ULL: return fde_sub_02d3b8(a0, a1, a2);
        case 0x02d408ULL: return fde_sub_02d408(a0, a1, a2);
        case 0x02d440ULL: return fde_sub_02d440(a0, a1, a2);
        case 0x02d490ULL: return fde_sub_02d490(a0, a1, a2);
        case 0x02d4c8ULL: return fde_sub_02d4c8(a0, a1, a2);
        case 0x02d518ULL: return fde_sub_02d518(a0, a1, a2);
        case 0x02d550ULL: return fde_sub_02d550(a0, a1, a2);
        case 0x02d5a0ULL: return fde_sub_02d5a0(a0, a1, a2);
        case 0x02d5dcULL: return fde_sub_02d5dc(a0, a1, a2);
        case 0x02d62cULL: return fde_sub_02d62c(a0, a1, a2);
        case 0x02d65cULL: return fde_sub_02d65c(a0, a1, a2);
        case 0x02d6acULL: return fde_sub_02d6ac(a0, a1, a2);
        case 0x02d750ULL: return fde_sub_02d750(a0, a1, a2);
        case 0x02d7a0ULL: return fde_sub_02d7a0(a0, a1, a2);
        case 0x02d7d0ULL: return fde_sub_02d7d0(a0, a1, a2);
        case 0x02d820ULL: return fde_sub_02d820(a0, a1, a2);
        case 0x02d850ULL: return fde_sub_02d850(a0, a1, a2);
        case 0x02d8a0ULL: return fde_sub_02d8a0(a0, a1, a2);
        case 0x02d8d4ULL: return fde_sub_02d8d4(a0, a1, a2);
        case 0x02d924ULL: return fde_sub_02d924(a0, a1, a2);
        case 0x02db94ULL: return fde_sub_02db94(a0, a1, a2);
        case 0x02db9cULL: return fde_sub_02db9c(a0, a1, a2);
        case 0x02dbccULL: return fde_sub_02dbcc(a0, a1, a2);
        case 0x02dbe0ULL: return fde_sub_02dbe0(a0, a1, a2);
        case 0x02dbf0ULL: return fde_sub_02dbf0(a0, a1, a2);
        case 0x02dc2cULL: return fde_sub_02dc2c(a0, a1, a2);
        case 0x02dc30ULL: return fde_sub_02dc30(a0, a1, a2);
        case 0x02dc4cULL: return fde_sub_02dc4c(a0, a1, a2);
        case 0x02dc50ULL: return fde_sub_02dc50(a0, a1, a2);
        case 0x02dc78ULL: return fde_sub_02dc78(a0, a1, a2);
        case 0x02e530ULL: return fde_sub_02e530(a0, a1, a2);
        case 0x02e5f0ULL: return fde_sub_02e5f0(a0, a1, a2);
        case 0x02e9c4ULL: return fde_sub_02e9c4(a0, a1, a2);
        case 0x02ea84ULL: return fde_sub_02ea84(a0, a1, a2);
        case 0x02ebf0ULL: return fde_sub_02ebf0(a0, a1, a2);
        case 0x02ec00ULL: return fde_sub_02ec00(a0, a1, a2);
        case 0x02ec10ULL: return fde_sub_02ec10(a0, a1, a2);
        case 0x02ec20ULL: return fde_sub_02ec20(a0, a1, a2);
        case 0x02ec30ULL: return fde_sub_02ec30(a0, a1, a2);
        case 0x02ec40ULL: return fde_sub_02ec40(a0, a1, a2);
        case 0x02ec50ULL: return fde_sub_02ec50(a0, a1, a2);
        case 0x02ec60ULL: return fde_sub_02ec60(a0, a1, a2);
        case 0x02ec70ULL: return fde_sub_02ec70(a0, a1, a2);
        case 0x02ec80ULL: return fde_sub_02ec80(a0, a1, a2);
        case 0x02ec90ULL: return fde_sub_02ec90(a0, a1, a2);
        case 0x02eca0ULL: return fde_sub_02eca0(a0, a1, a2);
        case 0x02ecb0ULL: return fde_sub_02ecb0(a0, a1, a2);
        case 0x02ecc0ULL: return fde_sub_02ecc0(a0, a1, a2);
        case 0x02ecd0ULL: return fde_sub_02ecd0(a0, a1, a2);
        case 0x02ece0ULL: return fde_sub_02ece0(a0, a1, a2);
        case 0x02ecf0ULL: return fde_sub_02ecf0(a0, a1, a2);
        case 0x02ed00ULL: return fde_sub_02ed00(a0, a1, a2);
        case 0x02ed10ULL: return fde_sub_02ed10(a0, a1, a2);
        case 0x02ed20ULL: return fde_sub_02ed20(a0, a1, a2);
        case 0x02ed30ULL: return fde_sub_02ed30(a0, a1, a2);
        case 0x02ed40ULL: return fde_sub_02ed40(a0, a1, a2);
        case 0x02ed50ULL: return fde_sub_02ed50(a0, a1, a2);
        case 0x02ed60ULL: return fde_sub_02ed60(a0, a1, a2);
        case 0x02f600ULL: return fde_sub_02f600(a0, a1, a2);
        case 0x02f644ULL: return fde_sub_02f644(a0, a1, a2);
        case 0x02f6c0ULL: return fde_sub_02f6c0(a0, a1, a2);
        case 0x02fbc4ULL: return fde_sub_02fbc4(a0, a1, a2);
        case 0x02fc08ULL: return fde_sub_02fc08(a0, a1, a2);
        case 0x02fc78ULL: return fde_sub_02fc78(a0, a1, a2);
        case 0x030208ULL: return fde_sub_030208(a0, a1, a2);
        case 0x030210ULL: return fde_sub_030210(a0, a1, a2);
        case 0x030240ULL: return fde_sub_030240(a0, a1, a2);
        case 0x030254ULL: return fde_sub_030254(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace rex
} // namespace bytedance
