// ============================================================================
// File: rex_fde_shard_1.cpp
// Target 109 / 169: librex.so (690,264 bytes)
// EN: Clean-room C++17 AArch64 Function Shard 1/5 covering [0..319]
//     (PC range 0x001c10 .. 0x010fec).
// VI: Phân mảnh hàm AArch64 C++17 1/5 bao phủ [0..319]
//     (Dải địa chỉ PC 0x001c10 .. 0x010fec).
// ============================================================================
#include "rex_date_format.h"

namespace bytedance {
namespace rex {

// Func #0000 | PC: 0x001c10..0x003a10 (7680 B) | Symbol: rex_locale_init_ctor_00
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_001c10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x001C10ULL;
}

// Func #0001 | PC: 0x001c2c..0x001c6c (64 B) | Symbol: sub_001c2c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_001c2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x001C2CULL;
}

// Func #0002 | PC: 0x001c30..0x001c70 (64 B) | Symbol: sub_001c30
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_001c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x001C30ULL;
}

// Func #0003 | PC: 0x001c58..0x001c98 (64 B) | Symbol: sub_001c58
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x3a7c; movi v1.2d, #0000000000000000; adrp x0, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x3a7c; movi v1.2d, #0000000000000000; adrp x0, #0x97000]
uint64_t fde_sub_001c58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F100ULL) << 32) | 0x97FFFFEAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x001C58ULL;
}

// Func #0004 | PC: 0x0024cc..0x00250c (64 B) | Symbol: sub_0024cc
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; add x9, x9, #0xea7; ldur q0, [x9, #0xc]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; add x9, x9, #0xea7; ldur q0, [x9, #0xc]]
uint64_t fde_sub_0024cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00004A9ULL) << 32) | 0x97FFFDB5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0024CCULL;
}

// Func #0005 | PC: 0x002594..0x0025d4 (64 B) | Symbol: sub_002594
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x97000]
uint64_t fde_sub_002594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00004A9ULL) << 32) | 0x97FFFD83ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002594ULL;
}

// Func #0006 | PC: 0x0029e4..0x002a24 (64 B) | Symbol: sub_0029e4
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; ldr x9, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; ldr x9, [sp, #0x28]]
uint64_t fde_sub_0029e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00004A8ULL) << 32) | 0x97FFFC6FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0029E4ULL;
}

// Func #0007 | PC: 0x002b58..0x002b98 (64 B) | Symbol: sub_002b58
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002b58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9402170AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002B58ULL;
}

// Func #0008 | PC: 0x002b68..0x002ba8 (64 B) | Symbol: sub_002b68
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002b68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94021706ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002B68ULL;
}

// Func #0009 | PC: 0x002b78..0x002bb8 (64 B) | Symbol: sub_002b78
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002b78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94021702ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002B78ULL;
}

// Func #0010 | PC: 0x002b88..0x002bc8 (64 B) | Symbol: sub_002b88
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x940216FEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002B88ULL;
}

// Func #0011 | PC: 0x002b98..0x002bd8 (64 B) | Symbol: sub_002b98
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002b98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x940216FAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002B98ULL;
}

// Func #0012 | PC: 0x002ba8..0x002be8 (64 B) | Symbol: sub_002ba8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002ba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x940216F6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002BA8ULL;
}

// Func #0013 | PC: 0x002bb8..0x002bf8 (64 B) | Symbol: sub_002bb8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002bb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x940216F2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002BB8ULL;
}

// Func #0014 | PC: 0x002bc8..0x002c08 (64 B) | Symbol: sub_002bc8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002bc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x940216EEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002BC8ULL;
}

// Func #0015 | PC: 0x002bd8..0x002c18 (64 B) | Symbol: sub_002bd8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002bd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x940216EAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002BD8ULL;
}

// Func #0016 | PC: 0x002be8..0x002c28 (64 B) | Symbol: sub_002be8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x940216E6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002BE8ULL;
}

// Func #0017 | PC: 0x002bf8..0x002c38 (64 B) | Symbol: sub_002bf8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002bf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x940216E2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002BF8ULL;
}

// Func #0018 | PC: 0x002c08..0x002c48 (64 B) | Symbol: sub_002c08
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x940216DEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C08ULL;
}

// Func #0019 | PC: 0x002c18..0x002c58 (64 B) | Symbol: sub_002c18
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x940216DAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C18ULL;
}

// Func #0020 | PC: 0x002c28..0x002c68 (64 B) | Symbol: sub_002c28
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002c28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x940216D6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C28ULL;
}

// Func #0021 | PC: 0x002c38..0x002c78 (64 B) | Symbol: sub_002c38
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002c38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x940216D2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C38ULL;
}

// Func #0022 | PC: 0x002c48..0x002c88 (64 B) | Symbol: sub_002c48
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x940216CEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C48ULL;
}

// Func #0023 | PC: 0x002c58..0x002c98 (64 B) | Symbol: sub_002c58
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002c58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x940216CAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C58ULL;
}

// Func #0024 | PC: 0x002c68..0x002ca8 (64 B) | Symbol: sub_002c68
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_002c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940216C6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C68ULL;
}

// Func #0025 | PC: 0x002c78..0x002cb8 (64 B) | Symbol: sub_002c78
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_002c78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940216C2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C78ULL;
}

// Func #0026 | PC: 0x002c88..0x002cc8 (64 B) | Symbol: sub_002c88
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002c88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x940216BEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C88ULL;
}

// Func #0027 | PC: 0x002c98..0x002cd8 (64 B) | Symbol: sub_002c98
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x940216BAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002C98ULL;
}

// Func #0028 | PC: 0x002ca8..0x002ce8 (64 B) | Symbol: sub_002ca8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_002ca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x940216B6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002CA8ULL;
}

// Func #0029 | PC: 0x002cb8..0x002cf8 (64 B) | Symbol: sub_002cb8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_002cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940216B2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002CB8ULL;
}

// Func #0030 | PC: 0x002cc8..0x002d08 (64 B) | Symbol: sub_002cc8
// EN: AArch64 prologue [bl #0x88780; mov w10, #0x6d76; add x9, x24, #0x478; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov w10, #0x6d76; add x9, x24, #0x478; movi v0.2d, #0000000000000000]
uint64_t fde_sub_002cc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528DAECAULL) << 32) | 0x940216AEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x002CC8ULL;
}

// Func #0031 | PC: 0x003a18..0x003a58 (64 B) | Symbol: sub_003a18
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_003a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x94021637ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003A18ULL;
}

// Func #0032 | PC: 0x003a20..0x003a60 (64 B) | Symbol: sub_003a20
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x3a34; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x3a34; subs x19, x19, #0x30]
uint64_t fde_sub_003a20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94020E93ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003A20ULL;
}

// Func #0033 | PC: 0x003a50..0x003a90 (64 B) | Symbol: sub_003a50
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3a2c; add x8, x27, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3a2c; add x8, x27, x19]
uint64_t fde_sub_003a50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFF820ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003A50ULL;
}

// Func #0034 | PC: 0x003a64..0x003aa4 (64 B) | Symbol: sub_003a64
// EN: AArch64 prologue [bl #0x1ad0; b #0x3a2c; adrp x0, #0xad000; add x0, x0, #0x770] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x3a2c; adrp x0, #0xad000; add x0, x0, #0x770]
uint64_t fde_sub_003a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFF81BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003A64ULL;
}

// Func #0035 | PC: 0x003a74..0x003ab4 (64 B) | Symbol: sub_003a74
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_003a74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FFF81FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003A74ULL;
}

// Func #0036 | PC: 0x003ab0..0x003af0 (64 B) | Symbol: sub_003ab0
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_003ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFF844ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003AB0ULL;
}

// Func #0037 | PC: 0x003ab4..0x0058b4 (7680 B) | Symbol: rex_locale_init_ctor_01
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_003ab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003AB4ULL;
}

// Func #0038 | PC: 0x003ad0..0x003b10 (64 B) | Symbol: sub_003ad0
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc80; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc80; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_003ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13203FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003AD0ULL;
}

// Func #0039 | PC: 0x003ad4..0x003b14 (64 B) | Symbol: sub_003ad4
// EN: AArch64 prologue [sub sp, sp, #0xc80; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc80; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_003ad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13203FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003AD4ULL;
}

// Func #0040 | PC: 0x003afc..0x003b3c (64 B) | Symbol: sub_003afc
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x65dc; movi v2.2d, #0000000000000000; add x8, sp, #0x489] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x65dc; movi v2.2d, #0000000000000000; add x8, sp, #0x489]
uint64_t fde_sub_003afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340156E0ULL) << 32) | 0x97FFF841ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x003AFCULL;
}

// Func #0041 | PC: 0x004354..0x004394 (64 B) | Symbol: sub_004354
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x17c; ldp q0, q1, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x17c; ldp q0, q1, [x9]]
uint64_t fde_sub_004354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900004A9ULL) << 32) | 0x97FFF613ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004354ULL;
}

// Func #0042 | PC: 0x004408..0x004448 (64 B) | Symbol: sub_004408
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; add x9, x21, #0x188] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; add x9, x21, #0x188]
uint64_t fde_sub_004408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000488ULL) << 32) | 0x97FFF5E6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004408ULL;
}

// Func #0043 | PC: 0x004534..0x004574 (64 B) | Symbol: sub_004534
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x300]; add x9, sp, #0x219] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x300]; add x9, sp, #0x219]
uint64_t fde_sub_004534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFF59BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004534ULL;
}

// Func #0044 | PC: 0x004874..0x0048b4 (64 B) | Symbol: sub_004874
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; add x9, x21, #0x3f0; ldr q0, [x8, #0xc70]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; add x9, x21, #0x3f0; ldr q0, [x8, #0xc70]]
uint64_t fde_sub_004874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000488ULL) << 32) | 0x97FFF4CBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004874ULL;
}

// Func #0045 | PC: 0x0049e8..0x004a28 (64 B) | Symbol: sub_0049e8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0049e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94020F66ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0049E8ULL;
}

// Func #0046 | PC: 0x0049f8..0x004a38 (64 B) | Symbol: sub_0049f8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0049f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94020F62ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0049F8ULL;
}

// Func #0047 | PC: 0x004a08..0x004a48 (64 B) | Symbol: sub_004a08
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94020F5EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A08ULL;
}

// Func #0048 | PC: 0x004a18..0x004a58 (64 B) | Symbol: sub_004a18
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xc0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xc0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063E1ULL) << 32) | 0x94020F5AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A18ULL;
}

// Func #0049 | PC: 0x004a28..0x004a68 (64 B) | Symbol: sub_004a28
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xd0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xd0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9406BE1ULL) << 32) | 0x94020F56ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A28ULL;
}

// Func #0050 | PC: 0x004a38..0x004a78 (64 B) | Symbol: sub_004a38
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94020F52ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A38ULL;
}

// Func #0051 | PC: 0x004a48..0x004a88 (64 B) | Symbol: sub_004a48
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94020F4EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A48ULL;
}

// Func #0052 | PC: 0x004a58..0x004a98 (64 B) | Symbol: sub_004a58
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94020F4AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A58ULL;
}

// Func #0053 | PC: 0x004a68..0x004aa8 (64 B) | Symbol: sub_004a68
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94020F46ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A68ULL;
}

// Func #0054 | PC: 0x004a78..0x004ab8 (64 B) | Symbol: sub_004a78
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94020F42ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A78ULL;
}

// Func #0055 | PC: 0x004a88..0x004ac8 (64 B) | Symbol: sub_004a88
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94020F3EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A88ULL;
}

// Func #0056 | PC: 0x004a98..0x004ad8 (64 B) | Symbol: sub_004a98
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94020F3AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004A98ULL;
}

// Func #0057 | PC: 0x004aa8..0x004ae8 (64 B) | Symbol: sub_004aa8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_004aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94020F36ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004AA8ULL;
}

// Func #0058 | PC: 0x004ab8..0x004af8 (64 B) | Symbol: sub_004ab8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004ab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94020F32ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004AB8ULL;
}

// Func #0059 | PC: 0x004ac8..0x004b08 (64 B) | Symbol: sub_004ac8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004ac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94020F2EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004AC8ULL;
}

// Func #0060 | PC: 0x004ad8..0x004b18 (64 B) | Symbol: sub_004ad8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_004ad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94020F2AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004AD8ULL;
}

// Func #0061 | PC: 0x004ae8..0x004b28 (64 B) | Symbol: sub_004ae8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004ae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94020F26ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004AE8ULL;
}

// Func #0062 | PC: 0x004af8..0x004b38 (64 B) | Symbol: sub_004af8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_004af8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94020F22ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004AF8ULL;
}

// Func #0063 | PC: 0x004b08..0x004b48 (64 B) | Symbol: sub_004b08
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_004b08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94020F1EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004B08ULL;
}

// Func #0064 | PC: 0x004b18..0x004b58 (64 B) | Symbol: sub_004b18
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_004b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94020F1AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004B18ULL;
}

// Func #0065 | PC: 0x004b28..0x004b68 (64 B) | Symbol: sub_004b28
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004b28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94020F16ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004B28ULL;
}

// Func #0066 | PC: 0x004b38..0x004b78 (64 B) | Symbol: sub_004b38
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_004b38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94020F12ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004B38ULL;
}

// Func #0067 | PC: 0x004b48..0x004b88 (64 B) | Symbol: sub_004b48
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_004b48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94020F0EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004B48ULL;
}

// Func #0068 | PC: 0x004b58..0x004b98 (64 B) | Symbol: sub_004b58
// EN: AArch64 prologue [bl #0x88780; add x12, sp, #0x578; movi v0.2d, #0000000000000000; add x9, sp, #0x8f9] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x12, sp, #0x578; movi v0.2d, #0000000000000000; add x9, sp, #0x8f9]
uint64_t fde_sub_004b58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115E3ECULL) << 32) | 0x94020F0AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x004B58ULL;
}

// Func #0069 | PC: 0x005378..0x0053b8 (64 B) | Symbol: sub_005378
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; adrp x9, #0x98000; add x9, x9, #0x2fd] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; adrp x9, #0x98000; add x9, x9, #0x2fd]
uint64_t fde_sub_005378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000488ULL) << 32) | 0x97FFF20AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005378ULL;
}

// Func #0070 | PC: 0x0055b8..0x0055f8 (64 B) | Symbol: sub_0055b8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x98000; add x9, sp, #1, lsl #12] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x98000; add x9, sp, #1, lsl #12]
uint64_t fde_sub_0055b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFF17AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0055B8ULL;
}

// Func #0071 | PC: 0x005650..0x005690 (64 B) | Symbol: sub_005650
// EN: AArch64 prologue [bl #0x1ba0; ldp q1, q0, [sp, #0xc0]; adrp x8, #0x98000; add x9, sp, #1, lsl #12] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldp q1, q0, [sp, #0xc0]; adrp x8, #0x98000; add x9, sp, #1, lsl #12]
uint64_t fde_sub_005650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAD4603E1ULL) << 32) | 0x97FFF154ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005650ULL;
}

// Func #0072 | PC: 0x0057f0..0x005830 (64 B) | Symbol: sub_0057f0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x98000; add x9, sp, #1, lsl #12] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x98000; add x9, sp, #1, lsl #12]
uint64_t fde_sub_0057f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFF0ECULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0057F0ULL;
}

// Func #0073 | PC: 0x005924..0x005964 (64 B) | Symbol: sub_005924
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q2, [x8, #0xc50]; adrp x8, #0x98000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q2, [x8, #0xc50]; adrp x8, #0x98000]
uint64_t fde_sub_005924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000488ULL) << 32) | 0x97FFF09FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005924ULL;
}

// Func #0074 | PC: 0x005a5c..0x005a9c (64 B) | Symbol: sub_005a5c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x8, #0x98000; add x8, x8, #0x542] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x8, #0x98000; add x8, x8, #0x542]
uint64_t fde_sub_005a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FFF051ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005A5CULL;
}

// Func #0075 | PC: 0x005b80..0x005bc0 (64 B) | Symbol: sub_005b80
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [x28, #0x30]; add x9, x26, #0x568] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [x28, #0x30]; add x9, x26, #0x568]
uint64_t fde_sub_005b80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFF008ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005B80ULL;
}

// Func #0076 | PC: 0x005cac..0x005cec (64 B) | Symbol: sub_005cac
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x60f; ldr q0, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x60f; ldr q0, [x9]]
uint64_t fde_sub_005cac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000489ULL) << 32) | 0x97FFEFBDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005CACULL;
}

// Func #0077 | PC: 0x005dd4..0x005e14 (64 B) | Symbol: sub_005dd4
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0x651; ldur q0, [x8, #0xc]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0x651; ldur q0, [x8, #0xc]]
uint64_t fde_sub_005dd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000488ULL) << 32) | 0x97FFEF73ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005DD4ULL;
}

// Func #0078 | PC: 0x005e08..0x005e48 (64 B) | Symbol: sub_005e08
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0x66e; ldur q0, [x8, #0xa]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0x66e; ldur q0, [x8, #0xa]]
uint64_t fde_sub_005e08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000488ULL) << 32) | 0x97FFEF66ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005E08ULL;
}

// Func #0079 | PC: 0x005e3c..0x005e7c (64 B) | Symbol: sub_005e3c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0x689; ldr x9, [x8, #0x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0x689; ldr x9, [x8, #0x10]]
uint64_t fde_sub_005e3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000488ULL) << 32) | 0x97FFEF59ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005E3CULL;
}

// Func #0080 | PC: 0x005e70..0x005eb0 (64 B) | Symbol: sub_005e70
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [x28, #0x210]; add x8, x26, #0x741] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [x28, #0x210]; add x8, x26, #0x741]
uint64_t fde_sub_005e70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFEF4CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005E70ULL;
}

// Func #0081 | PC: 0x005ef8..0x005f38 (64 B) | Symbol: sub_005ef8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x98000; add x8, x8, #0x6d0] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x98000; add x8, x8, #0x6d0]
uint64_t fde_sub_005ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFEF2AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x005EF8ULL;
}

// Func #0082 | PC: 0x00601c..0x00605c (64 B) | Symbol: sub_00601c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; mov w9, #0x2a; str x0, [x28, #0x330]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; mov w9, #0x2a; str x0, [x28, #0x330]]
uint64_t fde_sub_00601c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FFEEE1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00601CULL;
}

// Func #0083 | PC: 0x006134..0x006174 (64 B) | Symbol: sub_006134
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x79f; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x79f; adrp x8, #0x97000]
uint64_t fde_sub_006134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000489ULL) << 32) | 0x97FFEE9BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006134ULL;
}

// Func #0084 | PC: 0x006170..0x0061b0 (64 B) | Symbol: sub_006170
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; adrp x8, #0x97000; add x9, x9, #0x7d6] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; adrp x8, #0x97000; add x9, x9, #0x7d6]
uint64_t fde_sub_006170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000489ULL) << 32) | 0x97FFEE8CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006170ULL;
}

// Func #0085 | PC: 0x006254..0x006294 (64 B) | Symbol: sub_006254
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0x804; ldur q0, [x8, #0xe]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0x804; ldur q0, [x8, #0xe]]
uint64_t fde_sub_006254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000488ULL) << 32) | 0x97FFEE53ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006254ULL;
}

// Func #0086 | PC: 0x006288..0x0062c8 (64 B) | Symbol: sub_006288
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x98000; add x8, x8, #0x83b] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x98000; add x8, x8, #0x83b]
uint64_t fde_sub_006288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFEE46ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006288ULL;
}

// Func #0087 | PC: 0x006578..0x0065b8 (64 B) | Symbol: sub_006578
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x578; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x578; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_006578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115E3E0ULL) << 32) | 0x94020B5FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006578ULL;
}

// Func #0088 | PC: 0x006580..0x0065c0 (64 B) | Symbol: sub_006580
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x6594; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x6594; subs x19, x19, #0x30]
uint64_t fde_sub_006580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x940203BBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006580ULL;
}

// Func #0089 | PC: 0x0065b0..0x0065f0 (64 B) | Symbol: sub_0065b0
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x658c; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x658c; add x8, x21, x19]
uint64_t fde_sub_0065b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFED48ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0065B0ULL;
}

// Func #0090 | PC: 0x0065c4..0x006604 (64 B) | Symbol: sub_0065c4
// EN: AArch64 prologue [bl #0x1ad0; b #0x658c; adrp x0, #0xae000; add x0, x0, #0xe70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x658c; adrp x0, #0xae000; add x0, x0, #0xe70]
uint64_t fde_sub_0065c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFED43ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0065C4ULL;
}

// Func #0091 | PC: 0x0065d4..0x006614 (64 B) | Symbol: sub_0065d4
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_0065d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405FF3ULL) << 32) | 0x97FFED47ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0065D4ULL;
}

// Func #0092 | PC: 0x006610..0x006650 (64 B) | Symbol: sub_006610
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_006610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFED6CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006610ULL;
}

// Func #0093 | PC: 0x006614..0x008414 (7680 B) | Symbol: rex_locale_init_ctor_02
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_006614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006614ULL;
}

// Func #0094 | PC: 0x006630..0x006670 (64 B) | Symbol: sub_006630
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_006630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006630ULL;
}

// Func #0095 | PC: 0x006634..0x006674 (64 B) | Symbol: sub_006634
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_006634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006634ULL;
}

// Func #0096 | PC: 0x00665c..0x00669c (64 B) | Symbol: sub_00665c
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x8434; add x20, sp, #0x538; movi v1.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x8434; add x20, sp, #0x538; movi v1.2d, #0000000000000000]
uint64_t fde_sub_00665c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400EEA0ULL) << 32) | 0x97FFED69ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00665CULL;
}

// Func #0097 | PC: 0x006eac..0x006eec (64 B) | Symbol: sub_006eac
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x95c; ldur q0, [x9, #0xa]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x95c; ldur q0, [x9, #0xa]]
uint64_t fde_sub_006eac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000489ULL) << 32) | 0x97FFEB3DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006EACULL;
}

// Func #0098 | PC: 0x006f70..0x006fb0 (64 B) | Symbol: sub_006f70
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xcb0]; adrp x16, #0x98000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xcb0]; adrp x16, #0x98000]
uint64_t fde_sub_006f70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000489ULL) << 32) | 0x97FFEB0CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x006F70ULL;
}

// Func #0099 | PC: 0x0073c4..0x007404 (64 B) | Symbol: sub_0073c4
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; ldr x9, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; ldr x9, [sp, #0x20]]
uint64_t fde_sub_0073c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000488ULL) << 32) | 0x97FFE9F7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0073C4ULL;
}

// Func #0100 | PC: 0x007534..0x007574 (64 B) | Symbol: sub_007534
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94020493ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007534ULL;
}

// Func #0101 | PC: 0x007544..0x007584 (64 B) | Symbol: sub_007544
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9402048FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007544ULL;
}

// Func #0102 | PC: 0x007554..0x007594 (64 B) | Symbol: sub_007554
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9402048BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007554ULL;
}

// Func #0103 | PC: 0x007564..0x0075a4 (64 B) | Symbol: sub_007564
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94020487ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007564ULL;
}

// Func #0104 | PC: 0x007574..0x0075b4 (64 B) | Symbol: sub_007574
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94020483ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007574ULL;
}

// Func #0105 | PC: 0x007584..0x0075c4 (64 B) | Symbol: sub_007584
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9402047FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007584ULL;
}

// Func #0106 | PC: 0x007594..0x0075d4 (64 B) | Symbol: sub_007594
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9402047BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007594ULL;
}

// Func #0107 | PC: 0x0075a4..0x0075e4 (64 B) | Symbol: sub_0075a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0075a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94020477ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0075A4ULL;
}

// Func #0108 | PC: 0x0075b4..0x0075f4 (64 B) | Symbol: sub_0075b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0075b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94020473ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0075B4ULL;
}

// Func #0109 | PC: 0x0075c4..0x007604 (64 B) | Symbol: sub_0075c4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0075c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9402046FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0075C4ULL;
}

// Func #0110 | PC: 0x0075d4..0x007614 (64 B) | Symbol: sub_0075d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0075d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9402046BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0075D4ULL;
}

// Func #0111 | PC: 0x0075e4..0x007624 (64 B) | Symbol: sub_0075e4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0075e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94020467ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0075E4ULL;
}

// Func #0112 | PC: 0x0075f4..0x007634 (64 B) | Symbol: sub_0075f4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0075f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94020463ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0075F4ULL;
}

// Func #0113 | PC: 0x007604..0x007644 (64 B) | Symbol: sub_007604
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9402045FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007604ULL;
}

// Func #0114 | PC: 0x007614..0x007654 (64 B) | Symbol: sub_007614
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9402045BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007614ULL;
}

// Func #0115 | PC: 0x007624..0x007664 (64 B) | Symbol: sub_007624
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_007624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94020457ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007624ULL;
}

// Func #0116 | PC: 0x007634..0x007674 (64 B) | Symbol: sub_007634
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94020453ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007634ULL;
}

// Func #0117 | PC: 0x007644..0x007684 (64 B) | Symbol: sub_007644
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_007644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9402044FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007644ULL;
}

// Func #0118 | PC: 0x007654..0x007694 (64 B) | Symbol: sub_007654
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_007654(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9402044BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007654ULL;
}

// Func #0119 | PC: 0x007664..0x0076a4 (64 B) | Symbol: sub_007664
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94020447ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007664ULL;
}

// Func #0120 | PC: 0x007674..0x0076b4 (64 B) | Symbol: sub_007674
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94020443ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007674ULL;
}

// Func #0121 | PC: 0x007684..0x0076c4 (64 B) | Symbol: sub_007684
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_007684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x9402043FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007684ULL;
}

// Func #0122 | PC: 0x007694..0x0076d4 (64 B) | Symbol: sub_007694
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_007694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9402043BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x007694ULL;
}

// Func #0123 | PC: 0x0076a4..0x0076e4 (64 B) | Symbol: sub_0076a4
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x8, sp, #0x8b9; add x13, sp, #0x538] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x8, sp, #0x8b9; add x13, sp, #0x538]
uint64_t fde_sub_0076a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x94020437ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0076A4ULL;
}

// Func #0124 | PC: 0x0083d0..0x008410 (64 B) | Symbol: sub_0083d0
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_0083d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x940203C9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0083D0ULL;
}

// Func #0125 | PC: 0x0083d8..0x008418 (64 B) | Symbol: sub_0083d8
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x83ec; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x83ec; subs x19, x19, #0x30]
uint64_t fde_sub_0083d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401FC25ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0083D8ULL;
}

// Func #0126 | PC: 0x008408..0x008448 (64 B) | Symbol: sub_008408
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x83e4; add x8, x23, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x83e4; add x8, x23, x19]
uint64_t fde_sub_008408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFE5B2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x008408ULL;
}

// Func #0127 | PC: 0x00841c..0x00845c (64 B) | Symbol: sub_00841c
// EN: AArch64 prologue [bl #0x1ad0; b #0x83e4; adrp x0, #0xb0000; add x0, x0, #0x570] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x83e4; adrp x0, #0xb0000; add x0, x0, #0x570]
uint64_t fde_sub_00841c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFE5ADULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00841CULL;
}

// Func #0128 | PC: 0x00842c..0x00846c (64 B) | Symbol: sub_00842c
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_00842c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FFE5B1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00842CULL;
}

// Func #0129 | PC: 0x008468..0x0084a8 (64 B) | Symbol: sub_008468
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_008468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFE5D6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x008468ULL;
}

// Func #0130 | PC: 0x00846c..0x00a26c (7680 B) | Symbol: rex_locale_init_ctor_03
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_00846c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00846CULL;
}

// Func #0131 | PC: 0x008488..0x0084c8 (64 B) | Symbol: sub_008488
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_008488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x008488ULL;
}

// Func #0132 | PC: 0x00848c..0x0084cc (64 B) | Symbol: sub_00848c
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_00848c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00848CULL;
}

// Func #0133 | PC: 0x0084b4..0x0084f4 (64 B) | Symbol: sub_0084b4
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0xa3a4; movi v1.2d, #0000000000000000; adrp x0, #0x98000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0xa3a4; movi v1.2d, #0000000000000000; adrp x0, #0x98000]
uint64_t fde_sub_0084b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F760ULL) << 32) | 0x97FFE5D3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0084B4ULL;
}

// Func #0134 | PC: 0x008d94..0x008dd4 (64 B) | Symbol: sub_008d94
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0xc51; ldp q0, q1, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0xc51; ldp q0, q1, [x9]]
uint64_t fde_sub_008d94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000489ULL) << 32) | 0x97FFE383ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x008D94ULL;
}

// Func #0135 | PC: 0x008e50..0x008e90 (64 B) | Symbol: sub_008e50
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; add x8, x27, #0x188] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; add x8, x27, #0x188]
uint64_t fde_sub_008e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000468ULL) << 32) | 0x97FFE354ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x008E50ULL;
}

// Func #0136 | PC: 0x008f7c..0x008fbc (64 B) | Symbol: sub_008f7c
// EN: AArch64 prologue [bl #0x1ba0; adrp x10, #0x97000; ldr q0, [x10, #0xc70]; str x0, [sp, #0x2c0]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x10, #0x97000; ldr q0, [x10, #0xc70]; str x0, [sp, #0x2c0]]
uint64_t fde_sub_008f7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF000046AULL) << 32) | 0x97FFE309ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x008F7CULL;
}

// Func #0137 | PC: 0x0093d4..0x009414 (64 B) | Symbol: sub_0093d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0093d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401FCEBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0093D4ULL;
}

// Func #0138 | PC: 0x0093e4..0x009424 (64 B) | Symbol: sub_0093e4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0093e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401FCE7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0093E4ULL;
}

// Func #0139 | PC: 0x0093f4..0x009434 (64 B) | Symbol: sub_0093f4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0093f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401FCE3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0093F4ULL;
}

// Func #0140 | PC: 0x009404..0x009444 (64 B) | Symbol: sub_009404
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401FCDFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009404ULL;
}

// Func #0141 | PC: 0x009414..0x009454 (64 B) | Symbol: sub_009414
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401FCDBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009414ULL;
}

// Func #0142 | PC: 0x009424..0x009464 (64 B) | Symbol: sub_009424
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401FCD7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009424ULL;
}

// Func #0143 | PC: 0x009434..0x009474 (64 B) | Symbol: sub_009434
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401FCD3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009434ULL;
}

// Func #0144 | PC: 0x009444..0x009484 (64 B) | Symbol: sub_009444
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401FCCFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009444ULL;
}

// Func #0145 | PC: 0x009454..0x009494 (64 B) | Symbol: sub_009454
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401FCCBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009454ULL;
}

// Func #0146 | PC: 0x009464..0x0094a4 (64 B) | Symbol: sub_009464
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401FCC7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009464ULL;
}

// Func #0147 | PC: 0x009474..0x0094b4 (64 B) | Symbol: sub_009474
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401FCC3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009474ULL;
}

// Func #0148 | PC: 0x009484..0x0094c4 (64 B) | Symbol: sub_009484
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401FCBFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009484ULL;
}

// Func #0149 | PC: 0x009494..0x0094d4 (64 B) | Symbol: sub_009494
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_009494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401FCBBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009494ULL;
}

// Func #0150 | PC: 0x0094a4..0x0094e4 (64 B) | Symbol: sub_0094a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0094a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401FCB7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0094A4ULL;
}

// Func #0151 | PC: 0x0094b4..0x0094f4 (64 B) | Symbol: sub_0094b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0094b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401FCB3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0094B4ULL;
}

// Func #0152 | PC: 0x0094c4..0x009504 (64 B) | Symbol: sub_0094c4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0094c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401FCAFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0094C4ULL;
}

// Func #0153 | PC: 0x0094d4..0x009514 (64 B) | Symbol: sub_0094d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0094d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x9401FCABULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0094D4ULL;
}

// Func #0154 | PC: 0x0094e4..0x009524 (64 B) | Symbol: sub_0094e4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_0094e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401FCA7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0094E4ULL;
}

// Func #0155 | PC: 0x0094f4..0x009534 (64 B) | Symbol: sub_0094f4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_0094f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401FCA3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0094F4ULL;
}

// Func #0156 | PC: 0x009504..0x009544 (64 B) | Symbol: sub_009504
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_009504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401FC9FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009504ULL;
}

// Func #0157 | PC: 0x009514..0x009554 (64 B) | Symbol: sub_009514
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_009514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401FC9BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009514ULL;
}

// Func #0158 | PC: 0x009524..0x009564 (64 B) | Symbol: sub_009524
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_009524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401FC97ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009524ULL;
}

// Func #0159 | PC: 0x009534..0x009574 (64 B) | Symbol: sub_009534
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_009534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401FC93ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009534ULL;
}

// Func #0160 | PC: 0x009544..0x009584 (64 B) | Symbol: sub_009544
// EN: AArch64 prologue [bl #0x88780; movi v1.2d, #0000000000000000; add x9, sp, #0x939; strb wzr, [sp, #0x9b0]] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v1.2d, #0000000000000000; add x9, sp, #0x939; strb wzr, [sp, #0x9b0]]
uint64_t fde_sub_009544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E401ULL) << 32) | 0x9401FC8FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009544ULL;
}

// Func #0161 | PC: 0x009b14..0x009b54 (64 B) | Symbol: sub_009b14
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q1, [x8, #0xcb0]; adrp x8, #0x98000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q1, [x8, #0xcb0]; adrp x8, #0x98000]
uint64_t fde_sub_009b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000468ULL) << 32) | 0x97FFE023ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009B14ULL;
}

// Func #0162 | PC: 0x009b68..0x009ba8 (64 B) | Symbol: sub_009b68
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x80]; str x0, [sp, #0x1200]; adrp x9, #0x98000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x80]; str x0, [sp, #0x1200]; adrp x9, #0x98000]
uint64_t fde_sub_009b68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC023E0ULL) << 32) | 0x97FFE00EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x009B68ULL;
}

// Func #0163 | PC: 0x00a274..0x00a2b4 (64 B) | Symbol: sub_00a274
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0xe45; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0xe45; adrp x8, #0x97000]
uint64_t fde_sub_00a274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000469ULL) << 32) | 0x97FFDE4BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A274ULL;
}

// Func #0164 | PC: 0x00a2b0..0x00a2f0 (64 B) | Symbol: sub_00a2b0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x90]; add x8, sp, #1, lsl #12; add x8, x8, #0xab9] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x90]; add x8, sp, #1, lsl #12; add x8, x8, #0xab9]
uint64_t fde_sub_00a2b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC027E0ULL) << 32) | 0x97FFDE3CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A2B0ULL;
}

// Func #0165 | PC: 0x00a340..0x00a380 (64 B) | Symbol: sub_00a340
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_00a340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x9401FBEDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A340ULL;
}

// Func #0166 | PC: 0x00a348..0x00a388 (64 B) | Symbol: sub_00a348
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0xa35c; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0xa35c; subs x19, x19, #0x30]
uint64_t fde_sub_00a348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401F449ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A348ULL;
}

// Func #0167 | PC: 0x00a378..0x00a3b8 (64 B) | Symbol: sub_00a378
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0xa354; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0xa354; add x8, x21, x19]
uint64_t fde_sub_00a378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFDDD6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A378ULL;
}

// Func #0168 | PC: 0x00a38c..0x00a3cc (64 B) | Symbol: sub_00a38c
// EN: AArch64 prologue [bl #0x1ad0; b #0xa354; adrp x0, #0xb1000; add x0, x0, #0xc70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0xa354; adrp x0, #0xb1000; add x0, x0, #0xc70]
uint64_t fde_sub_00a38c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFDDD1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A38CULL;
}

// Func #0169 | PC: 0x00a39c..0x00a3dc (64 B) | Symbol: sub_00a39c
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_00a39c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FFDDD5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A39CULL;
}

// Func #0170 | PC: 0x00a3d8..0x00a418 (64 B) | Symbol: sub_00a3d8
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_00a3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFDDFAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A3D8ULL;
}

// Func #0171 | PC: 0x00a3dc..0x00c1dc (7680 B) | Symbol: rex_locale_init_ctor_04
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_00a3dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A3DCULL;
}

// Func #0172 | PC: 0x00a3f8..0x00a438 (64 B) | Symbol: sub_00a3f8
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc90; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc90; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_00a3f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13243FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A3F8ULL;
}

// Func #0173 | PC: 0x00a3fc..0x00a43c (64 B) | Symbol: sub_00a3fc
// EN: AArch64 prologue [sub sp, sp, #0xc90; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc90; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_00a3fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13243FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A3FCULL;
}

// Func #0174 | PC: 0x00a424..0x00a464 (64 B) | Symbol: sub_00a424
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0xc530; str x19, [sp, #0xb8]; add x19, sp, #0x588] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0xc530; str x19, [sp, #0xb8]; add x19, sp, #0x588]
uint64_t fde_sub_00a424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34010840ULL) << 32) | 0x97FFDDF7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A424ULL;
}

// Func #0175 | PC: 0x00a488..0x00a4c8 (64 B) | Symbol: sub_00a488
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0xe76; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0xe76; adrp x8, #0x97000]
uint64_t fde_sub_00a488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000469ULL) << 32) | 0x97FFDDC6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A488ULL;
}

// Func #0176 | PC: 0x00a4c8..0x00a508 (64 B) | Symbol: sub_00a4c8
// EN: AArch64 prologue [bl #0x1ba0; adrp x10, #0x98000; add x10, x10, #0xe92; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x10, #0x98000; add x10, x10, #0xe92; adrp x8, #0x97000]
uint64_t fde_sub_00a4c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD000046AULL) << 32) | 0x97FFDDB6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A4C8ULL;
}

// Func #0177 | PC: 0x00a60c..0x00a64c (64 B) | Symbol: sub_00a60c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0xf08; ldur q0, [x8, #0xe]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0xf08; ldur q0, [x8, #0xe]]
uint64_t fde_sub_00a60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000468ULL) << 32) | 0x97FFDD65ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A60CULL;
}

// Func #0178 | PC: 0x00a6a4..0x00a6e4 (64 B) | Symbol: sub_00a6a4
// EN: AArch64 prologue [bl #0x1ba0; adrp x11, #0x97000; adrp x8, #0x98000; add x8, x8, #0xf53] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x11, #0x97000; adrp x8, #0x98000; add x8, x8, #0xf53]
uint64_t fde_sub_00a6a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB000046BULL) << 32) | 0x97FFDD3FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A6A4ULL;
}

// Func #0179 | PC: 0x00a934..0x00a974 (64 B) | Symbol: sub_00a934
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0xffb; ldr q0, [x8]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x98000; add x8, x8, #0xffb; ldr q0, [x8]]
uint64_t fde_sub_00a934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000468ULL) << 32) | 0x97FFDC9BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A934ULL;
}

// Func #0180 | PC: 0x00a998..0x00a9d8 (64 B) | Symbol: sub_00a998
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x99000; add x8, x8, #0x27; ldr q2, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x99000; add x8, x8, #0x27; ldr q2, [sp, #0xa0]]
uint64_t fde_sub_00a998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000468ULL) << 32) | 0x97FFDC82ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A998ULL;
}

// Func #0181 | PC: 0x00a9c8..0x00aa08 (64 B) | Symbol: sub_00a9c8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x10, #0x99000; add x8, sp, #0x759] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x10, #0x99000; add x8, sp, #0x759]
uint64_t fde_sub_00a9c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFDC76ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00A9C8ULL;
}

// Func #0182 | PC: 0x00ab00..0x00ab40 (64 B) | Symbol: sub_00ab00
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; add x8, sp, #0x7e9; str x0, [sp, #0x8f8]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; add x8, sp, #0x7e9; str x0, [sp, #0x8f8]]
uint64_t fde_sub_00ab00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFDC28ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00AB00ULL;
}

// Func #0183 | PC: 0x00ae80..0x00aec0 (64 B) | Symbol: sub_00ae80
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; ldr x26, [sp, #0xd0]; str x0, [sp, #0x220]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; ldr x26, [sp, #0xd0]; str x0, [sp, #0x220]]
uint64_t fde_sub_00ae80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFDB48ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00AE80ULL;
}

// Func #0184 | PC: 0x00af3c..0x00af7c (64 B) | Symbol: sub_00af3c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x15, #0x98000; add x15, x15, #0x98f] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x15, #0x98000; add x15, x15, #0x98f]
uint64_t fde_sub_00af3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFDB19ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00AF3CULL;
}

// Func #0185 | PC: 0x00b39c..0x00b3dc (64 B) | Symbol: sub_00b39c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0xd0]]
uint64_t fde_sub_00b39c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000468ULL) << 32) | 0x97FFDA01ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B39CULL;
}

// Func #0186 | PC: 0x00b508..0x00b548 (64 B) | Symbol: sub_00b508
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401F49EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B508ULL;
}

// Func #0187 | PC: 0x00b518..0x00b558 (64 B) | Symbol: sub_00b518
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401F49AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B518ULL;
}

// Func #0188 | PC: 0x00b528..0x00b568 (64 B) | Symbol: sub_00b528
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b528(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401F496ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B528ULL;
}

// Func #0189 | PC: 0x00b538..0x00b578 (64 B) | Symbol: sub_00b538
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401F492ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B538ULL;
}

// Func #0190 | PC: 0x00b548..0x00b588 (64 B) | Symbol: sub_00b548
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b548(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401F48EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B548ULL;
}

// Func #0191 | PC: 0x00b558..0x00b598 (64 B) | Symbol: sub_00b558
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_00b558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401F48AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B558ULL;
}

// Func #0192 | PC: 0x00b568..0x00b5a8 (64 B) | Symbol: sub_00b568
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401F486ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B568ULL;
}

// Func #0193 | PC: 0x00b578..0x00b5b8 (64 B) | Symbol: sub_00b578
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x9401F482ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B578ULL;
}

// Func #0194 | PC: 0x00b588..0x00b5c8 (64 B) | Symbol: sub_00b588
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401F47EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B588ULL;
}

// Func #0195 | PC: 0x00b598..0x00b5d8 (64 B) | Symbol: sub_00b598
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401F47AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B598ULL;
}

// Func #0196 | PC: 0x00b5a8..0x00b5e8 (64 B) | Symbol: sub_00b5a8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b5a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401F476ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B5A8ULL;
}

// Func #0197 | PC: 0x00b5b8..0x00b5f8 (64 B) | Symbol: sub_00b5b8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b5b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401F472ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B5B8ULL;
}

// Func #0198 | PC: 0x00b5c8..0x00b608 (64 B) | Symbol: sub_00b5c8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b5c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401F46EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B5C8ULL;
}

// Func #0199 | PC: 0x00b5d8..0x00b618 (64 B) | Symbol: sub_00b5d8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b5d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401F46AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B5D8ULL;
}

// Func #0200 | PC: 0x00b5e8..0x00b628 (64 B) | Symbol: sub_00b5e8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b5e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401F466ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B5E8ULL;
}

// Func #0201 | PC: 0x00b5f8..0x00b638 (64 B) | Symbol: sub_00b5f8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_00b5f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401F462ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B5F8ULL;
}

// Func #0202 | PC: 0x00b608..0x00b648 (64 B) | Symbol: sub_00b608
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b608(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401F45EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B608ULL;
}

// Func #0203 | PC: 0x00b618..0x00b658 (64 B) | Symbol: sub_00b618
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_00b618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401F45AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B618ULL;
}

// Func #0204 | PC: 0x00b628..0x00b668 (64 B) | Symbol: sub_00b628
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_00b628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401F456ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B628ULL;
}

// Func #0205 | PC: 0x00b638..0x00b678 (64 B) | Symbol: sub_00b638
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401F452ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B638ULL;
}

// Func #0206 | PC: 0x00b648..0x00b688 (64 B) | Symbol: sub_00b648
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xd0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xd0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b648(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9406BE1ULL) << 32) | 0x9401F44EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B648ULL;
}

// Func #0207 | PC: 0x00b658..0x00b698 (64 B) | Symbol: sub_00b658
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00b658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401F44AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B658ULL;
}

// Func #0208 | PC: 0x00b668..0x00b6a8 (64 B) | Symbol: sub_00b668
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_00b668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401F446ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B668ULL;
}

// Func #0209 | PC: 0x00b678..0x00b6b8 (64 B) | Symbol: sub_00b678
// EN: AArch64 prologue [bl #0x88780; add x11, sp, #0x588; movi v0.2d, #0000000000000000; add x9, sp, #0x909] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x11, sp, #0x588; movi v0.2d, #0000000000000000; add x9, sp, #0x909]
uint64_t fde_sub_00b678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911623EBULL) << 32) | 0x9401F442ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B678ULL;
}

// Func #0210 | PC: 0x00b7c0..0x00b800 (64 B) | Symbol: sub_00b7c0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; add x8, sp, #0x9c9; str x0, [sp, #0xad8]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; add x8, sp, #0x9c9; str x0, [sp, #0xad8]]
uint64_t fde_sub_00b7c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFD8F8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00B7C0ULL;
}

// Func #0211 | PC: 0x00bb7c..0x00bbbc (64 B) | Symbol: sub_00bb7c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcf0]; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcf0]; adrp x8, #0x99000]
uint64_t fde_sub_00bb7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000468ULL) << 32) | 0x97FFD809ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BB7CULL;
}

// Func #0212 | PC: 0x00bbec..0x00bc2c (64 B) | Symbol: sub_00bbec
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x10d0]; adrp x10, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x10d0]; adrp x10, #0x99000]
uint64_t fde_sub_00bbec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFD7EDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BBECULL;
}

// Func #0213 | PC: 0x00bc90..0x00bcd0 (64 B) | Symbol: sub_00bc90
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x99000; add x8, x8, #0x230] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x99000; add x8, x8, #0x230]
uint64_t fde_sub_00bc90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFD7C4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BC90ULL;
}

// Func #0214 | PC: 0x00bce0..0x00bd20 (64 B) | Symbol: sub_00bce0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x1250]; adrp x9, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x1250]; adrp x9, #0x99000]
uint64_t fde_sub_00bce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFD7B0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BCE0ULL;
}

// Func #0215 | PC: 0x00bd84..0x00bdc4 (64 B) | Symbol: sub_00bd84
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc50]; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc50]; adrp x8, #0x99000]
uint64_t fde_sub_00bd84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000468ULL) << 32) | 0x97FFD787ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BD84ULL;
}

// Func #0216 | PC: 0x00bddc..0x00be1c (64 B) | Symbol: sub_00bddc
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x13d0]; strb wzr, [x0, #0x1c]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x13d0]; strb wzr, [x0, #0x1c]]
uint64_t fde_sub_00bddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFD771ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BDDCULL;
}

// Func #0217 | PC: 0x00be10..0x00be50 (64 B) | Symbol: sub_00be10
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x99000; add x8, x8, #0x284] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x99000; add x8, x8, #0x284]
uint64_t fde_sub_00be10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFD764ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BE10ULL;
}

// Func #0218 | PC: 0x00be64..0x00bea4 (64 B) | Symbol: sub_00be64
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x1490]; strb wzr, [x0, #0x1c]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; str x0, [sp, #0x1490]; strb wzr, [x0, #0x1c]]
uint64_t fde_sub_00be64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FFD74FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BE64ULL;
}

// Func #0219 | PC: 0x00be98..0x00bed8 (64 B) | Symbol: sub_00be98
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd00]; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd00]; adrp x8, #0x99000]
uint64_t fde_sub_00be98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000468ULL) << 32) | 0x97FFD742ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BE98ULL;
}

// Func #0220 | PC: 0x00befc..0x00bf3c (64 B) | Symbol: sub_00befc
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x70]; str x0, [sp, #0x1550]; adrp x9, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x70]; str x0, [sp, #0x1550]; adrp x9, #0x99000]
uint64_t fde_sub_00befc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC01FE0ULL) << 32) | 0x97FFD729ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00BEFCULL;
}

// Func #0221 | PC: 0x00c008..0x00c048 (64 B) | Symbol: sub_00c008
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x99000; add x8, x8, #0x2ed] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x99000; add x8, x8, #0x2ed]
uint64_t fde_sub_00c008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFD6E6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C008ULL;
}

// Func #0222 | PC: 0x00c058..0x00c098 (64 B) | Symbol: sub_00c058
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x20, #0x230]; str x21, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x20, #0x230]; str x21, [x0, #0x10]]
uint64_t fde_sub_00c058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFD6D2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C058ULL;
}

// Func #0223 | PC: 0x00c088..0x00c0c8 (64 B) | Symbol: sub_00c088
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd10]; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd10]; adrp x8, #0x99000]
uint64_t fde_sub_00c088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000448ULL) << 32) | 0x97FFD6C6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C088ULL;
}

// Func #0224 | PC: 0x00c0e0..0x00c120 (64 B) | Symbol: sub_00c0e0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x90]; str x0, [x20, #0x2f0]; strh w21, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x90]; str x0, [x20, #0x2f0]; strh w21, [x0, #0x20]]
uint64_t fde_sub_00c0e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC027E0ULL) << 32) | 0x97FFD6B0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C0E0ULL;
}

// Func #0225 | PC: 0x00c118..0x00c158 (64 B) | Symbol: sub_00c118
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x99000; add x8, x8, #0x329] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x99000; add x8, x8, #0x329]
uint64_t fde_sub_00c118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFD6A2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C118ULL;
}

// Func #0226 | PC: 0x00c168..0x00c1a8 (64 B) | Symbol: sub_00c168
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x20, #0x3b0]; adrp x9, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; str x0, [x20, #0x3b0]; adrp x9, #0x99000]
uint64_t fde_sub_00c168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FFD68EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C168ULL;
}

// Func #0227 | PC: 0x00c20c..0x00c24c (64 B) | Symbol: sub_00c20c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x99000; add x8, x8, #0x358] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x99000; add x8, x8, #0x358]
uint64_t fde_sub_00c20c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFD665ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C20CULL;
}

// Func #0228 | PC: 0x00c260..0x00c2a0 (64 B) | Symbol: sub_00c260
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [x20, #0x530]; mov w13, #0x16] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [x20, #0x530]; mov w13, #0x16]
uint64_t fde_sub_00c260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FFD650ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C260ULL;
}

// Func #0229 | PC: 0x00c4cc..0x00c50c (64 B) | Symbol: sub_00c4cc
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x588; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x588; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_00c4cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911623E0ULL) << 32) | 0x9401F38AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C4CCULL;
}

// Func #0230 | PC: 0x00c4d4..0x00c514 (64 B) | Symbol: sub_00c4d4
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0xc4e8; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0xc4e8; subs x19, x19, #0x30]
uint64_t fde_sub_00c4d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401EBE6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C4D4ULL;
}

// Func #0231 | PC: 0x00c504..0x00c544 (64 B) | Symbol: sub_00c504
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0xc4e0; add x8, x27, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0xc4e0; add x8, x27, x19]
uint64_t fde_sub_00c504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFD573ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C504ULL;
}

// Func #0232 | PC: 0x00c518..0x00c558 (64 B) | Symbol: sub_00c518
// EN: AArch64 prologue [bl #0x1ad0; b #0xc4e0; adrp x0, #0xb3000; add x0, x0, #0x370] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0xc4e0; adrp x0, #0xb3000; add x0, x0, #0x370]
uint64_t fde_sub_00c518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFD56EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C518ULL;
}

// Func #0233 | PC: 0x00c528..0x00c568 (64 B) | Symbol: sub_00c528
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_00c528(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405FF3ULL) << 32) | 0x97FFD572ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C528ULL;
}

// Func #0234 | PC: 0x00c564..0x00c5a4 (64 B) | Symbol: sub_00c564
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_00c564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFD597ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C564ULL;
}

// Func #0235 | PC: 0x00c568..0x00e368 (7680 B) | Symbol: rex_locale_init_ctor_05
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_00c568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C568ULL;
}

// Func #0236 | PC: 0x00c584..0x00c5c4 (64 B) | Symbol: sub_00c584
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_00c584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C584ULL;
}

// Func #0237 | PC: 0x00c588..0x00c5c8 (64 B) | Symbol: sub_00c588
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_00c588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C588ULL;
}

// Func #0238 | PC: 0x00c5b0..0x00c5f0 (64 B) | Symbol: sub_00c5b0
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0xe3bc; movi v1.2d, #0000000000000000; add x17, sp, #0x449] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0xe3bc; movi v1.2d, #0000000000000000; add x17, sp, #0x449]
uint64_t fde_sub_00c5b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F040ULL) << 32) | 0x97FFD594ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00C5B0ULL;
}

// Func #0239 | PC: 0x00cd88..0x00cdc8 (64 B) | Symbol: sub_00cd88
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x99000; add x8, x8, #0x433; ldur x9, [x8, #0xf]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x99000; add x8, x8, #0x433; ldur x9, [x8, #0xf]]
uint64_t fde_sub_00cd88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000468ULL) << 32) | 0x97FFD386ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00CD88ULL;
}

// Func #0240 | PC: 0x00cdec..0x00ce2c (64 B) | Symbol: sub_00cdec
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0x40c; ldp q0, q1, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0x40c; ldp q0, q1, [x9]]
uint64_t fde_sub_00cdec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000469ULL) << 32) | 0x97FFD36DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00CDECULL;
}

// Func #0241 | PC: 0x00ceb0..0x00cef0 (64 B) | Symbol: sub_00ceb0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xd30]; adrp x9, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xd30]; adrp x9, #0x99000]
uint64_t fde_sub_00ceb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000449ULL) << 32) | 0x97FFD33CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00CEB0ULL;
}

// Func #0242 | PC: 0x00d25c..0x00d29c (64 B) | Symbol: sub_00d25c
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0x46e; ldur q0, [x9, #0xa]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0x46e; ldur q0, [x9, #0xa]]
uint64_t fde_sub_00d25c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000469ULL) << 32) | 0x97FFD251ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D25CULL;
}

// Func #0243 | PC: 0x00d318..0x00d358 (64 B) | Symbol: sub_00d318
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; add x9, x22, #0x3f8] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; add x9, x22, #0x3f8]
uint64_t fde_sub_00d318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000448ULL) << 32) | 0x97FFD222ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D318ULL;
}

// Func #0244 | PC: 0x00d484..0x00d4c4 (64 B) | Symbol: sub_00d484
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401ECBFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D484ULL;
}

// Func #0245 | PC: 0x00d494..0x00d4d4 (64 B) | Symbol: sub_00d494
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401ECBBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D494ULL;
}

// Func #0246 | PC: 0x00d4a4..0x00d4e4 (64 B) | Symbol: sub_00d4a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d4a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401ECB7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D4A4ULL;
}

// Func #0247 | PC: 0x00d4b4..0x00d4f4 (64 B) | Symbol: sub_00d4b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x9401ECB3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D4B4ULL;
}

// Func #0248 | PC: 0x00d4c4..0x00d504 (64 B) | Symbol: sub_00d4c4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d4c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401ECAFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D4C4ULL;
}

// Func #0249 | PC: 0x00d4d4..0x00d514 (64 B) | Symbol: sub_00d4d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d4d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401ECABULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D4D4ULL;
}

// Func #0250 | PC: 0x00d4e4..0x00d524 (64 B) | Symbol: sub_00d4e4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d4e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401ECA7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D4E4ULL;
}

// Func #0251 | PC: 0x00d4f4..0x00d534 (64 B) | Symbol: sub_00d4f4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d4f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401ECA3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D4F4ULL;
}

// Func #0252 | PC: 0x00d504..0x00d544 (64 B) | Symbol: sub_00d504
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401EC9FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D504ULL;
}

// Func #0253 | PC: 0x00d514..0x00d554 (64 B) | Symbol: sub_00d514
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401EC9BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D514ULL;
}

// Func #0254 | PC: 0x00d524..0x00d564 (64 B) | Symbol: sub_00d524
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401EC97ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D524ULL;
}

// Func #0255 | PC: 0x00d534..0x00d574 (64 B) | Symbol: sub_00d534
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401EC93ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D534ULL;
}

// Func #0256 | PC: 0x00d544..0x00d584 (64 B) | Symbol: sub_00d544
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_00d544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401EC8FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D544ULL;
}

// Func #0257 | PC: 0x00d554..0x00d594 (64 B) | Symbol: sub_00d554
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401EC8BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D554ULL;
}

// Func #0258 | PC: 0x00d564..0x00d5a4 (64 B) | Symbol: sub_00d564
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401EC87ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D564ULL;
}

// Func #0259 | PC: 0x00d574..0x00d5b4 (64 B) | Symbol: sub_00d574
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401EC83ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D574ULL;
}

// Func #0260 | PC: 0x00d584..0x00d5c4 (64 B) | Symbol: sub_00d584
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401EC7FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D584ULL;
}

// Func #0261 | PC: 0x00d594..0x00d5d4 (64 B) | Symbol: sub_00d594
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401EC7BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D594ULL;
}

// Func #0262 | PC: 0x00d5a4..0x00d5e4 (64 B) | Symbol: sub_00d5a4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_00d5a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401EC77ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D5A4ULL;
}

// Func #0263 | PC: 0x00d5b4..0x00d5f4 (64 B) | Symbol: sub_00d5b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d5b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401EC73ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D5B4ULL;
}

// Func #0264 | PC: 0x00d5c4..0x00d604 (64 B) | Symbol: sub_00d5c4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_00d5c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401EC6FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D5C4ULL;
}

// Func #0265 | PC: 0x00d5d4..0x00d614 (64 B) | Symbol: sub_00d5d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00d5d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401EC6BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D5D4ULL;
}

// Func #0266 | PC: 0x00d5e4..0x00d624 (64 B) | Symbol: sub_00d5e4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_00d5e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401EC67ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D5E4ULL;
}

// Func #0267 | PC: 0x00d5f4..0x00d634 (64 B) | Symbol: sub_00d5f4
// EN: AArch64 prologue [bl #0x88780; add x5, sp, #0x538; mov w11, #0x2e61; add x9, x5, #0x478] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x5, sp, #0x538; mov w11, #0x2e61; add x9, x5, #0x478]
uint64_t fde_sub_00d5f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E5ULL) << 32) | 0x9401EC63ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00D5F4ULL;
}

// Func #0268 | PC: 0x00e358..0x00e398 (64 B) | Symbol: sub_00e358
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_00e358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x9401EBE7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E358ULL;
}

// Func #0269 | PC: 0x00e360..0x00e3a0 (64 B) | Symbol: sub_00e360
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0xe374; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0xe374; subs x19, x19, #0x30]
uint64_t fde_sub_00e360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401E443ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E360ULL;
}

// Func #0270 | PC: 0x00e390..0x00e3d0 (64 B) | Symbol: sub_00e390
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0xe36c; add x8, x22, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0xe36c; add x8, x22, x19]
uint64_t fde_sub_00e390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFCDD0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E390ULL;
}

// Func #0271 | PC: 0x00e3a4..0x00e3e4 (64 B) | Symbol: sub_00e3a4
// EN: AArch64 prologue [bl #0x1ad0; b #0xe36c; adrp x0, #0xb4000; add x0, x0, #0xa70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0xe36c; adrp x0, #0xb4000; add x0, x0, #0xa70]
uint64_t fde_sub_00e3a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFCDCBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E3A4ULL;
}

// Func #0272 | PC: 0x00e3b4..0x00e3f4 (64 B) | Symbol: sub_00e3b4
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_00e3b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FFCDCFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E3B4ULL;
}

// Func #0273 | PC: 0x00e3f0..0x00e430 (64 B) | Symbol: sub_00e3f0
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_00e3f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFCDF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E3F0ULL;
}

// Func #0274 | PC: 0x00e3f4..0x0101f4 (7680 B) | Symbol: rex_locale_init_ctor_06
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_00e3f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E3F4ULL;
}

// Func #0275 | PC: 0x00e410..0x00e450 (64 B) | Symbol: sub_00e410
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_00e410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13143FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E410ULL;
}

// Func #0276 | PC: 0x00e414..0x00e454 (64 B) | Symbol: sub_00e414
// EN: AArch64 prologue [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_00e414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E414ULL;
}

// Func #0277 | PC: 0x00e43c..0x00e47c (64 B) | Symbol: sub_00e43c
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x10028; movi v1.2d, #0000000000000000; mov w10, #0x6563] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x10028; movi v1.2d, #0000000000000000; mov w10, #0x6563]
uint64_t fde_sub_00e43c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400DF40ULL) << 32) | 0x97FFCDF1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00E43CULL;
}

// Func #0278 | PC: 0x00ec98..0x00ecd8 (64 B) | Symbol: sub_00ec98
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0x6af; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0x6af; adrp x8, #0x97000]
uint64_t fde_sub_00ec98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000449ULL) << 32) | 0x97FFCBC2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00EC98ULL;
}

// Func #0279 | PC: 0x00ed58..0x00ed98 (64 B) | Symbol: sub_00ed58
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x99000]
uint64_t fde_sub_00ed58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000449ULL) << 32) | 0x97FFCB92ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00ED58ULL;
}

// Func #0280 | PC: 0x00f1d4..0x00f214 (64 B) | Symbol: sub_00f1d4
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x50]; ldr x8, [sp, #0x28]; add x9, x22, #0x3f8] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x50]; ldr x8, [sp, #0x28]; add x9, x22, #0x3f8]
uint64_t fde_sub_00f1d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC017E0ULL) << 32) | 0x97FFCA73ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F1D4ULL;
}

// Func #0281 | PC: 0x00f344..0x00f384 (64 B) | Symbol: sub_00f344
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401E50FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F344ULL;
}

// Func #0282 | PC: 0x00f354..0x00f394 (64 B) | Symbol: sub_00f354
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401E50BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F354ULL;
}

// Func #0283 | PC: 0x00f364..0x00f3a4 (64 B) | Symbol: sub_00f364
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401E507ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F364ULL;
}

// Func #0284 | PC: 0x00f374..0x00f3b4 (64 B) | Symbol: sub_00f374
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x98]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FE1ULL) << 32) | 0x9401E503ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F374ULL;
}

// Func #0285 | PC: 0x00f384..0x00f3c4 (64 B) | Symbol: sub_00f384
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x9401E4FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F384ULL;
}

// Func #0286 | PC: 0x00f394..0x00f3d4 (64 B) | Symbol: sub_00f394
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401E4FBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F394ULL;
}

// Func #0287 | PC: 0x00f3a4..0x00f3e4 (64 B) | Symbol: sub_00f3a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f3a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401E4F7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F3A4ULL;
}

// Func #0288 | PC: 0x00f3b4..0x00f3f4 (64 B) | Symbol: sub_00f3b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f3b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401E4F3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F3B4ULL;
}

// Func #0289 | PC: 0x00f3c4..0x00f404 (64 B) | Symbol: sub_00f3c4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f3c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401E4EFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F3C4ULL;
}

// Func #0290 | PC: 0x00f3d4..0x00f414 (64 B) | Symbol: sub_00f3d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f3d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401E4EBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F3D4ULL;
}

// Func #0291 | PC: 0x00f3e4..0x00f424 (64 B) | Symbol: sub_00f3e4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f3e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401E4E7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F3E4ULL;
}

// Func #0292 | PC: 0x00f3f4..0x00f434 (64 B) | Symbol: sub_00f3f4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f3f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401E4E3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F3F4ULL;
}

// Func #0293 | PC: 0x00f404..0x00f444 (64 B) | Symbol: sub_00f404
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401E4DFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F404ULL;
}

// Func #0294 | PC: 0x00f414..0x00f454 (64 B) | Symbol: sub_00f414
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401E4DBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F414ULL;
}

// Func #0295 | PC: 0x00f424..0x00f464 (64 B) | Symbol: sub_00f424
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401E4D7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F424ULL;
}

// Func #0296 | PC: 0x00f434..0x00f474 (64 B) | Symbol: sub_00f434
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_00f434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401E4D3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F434ULL;
}

// Func #0297 | PC: 0x00f444..0x00f484 (64 B) | Symbol: sub_00f444
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x9401E4CFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F444ULL;
}

// Func #0298 | PC: 0x00f454..0x00f494 (64 B) | Symbol: sub_00f454
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_00f454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401E4CBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F454ULL;
}

// Func #0299 | PC: 0x00f464..0x00f4a4 (64 B) | Symbol: sub_00f464
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_00f464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401E4C7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F464ULL;
}

// Func #0300 | PC: 0x00f474..0x00f4b4 (64 B) | Symbol: sub_00f474
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401E4C3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F474ULL;
}

// Func #0301 | PC: 0x00f484..0x00f4c4 (64 B) | Symbol: sub_00f484
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401E4BFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F484ULL;
}

// Func #0302 | PC: 0x00f494..0x00f4d4 (64 B) | Symbol: sub_00f494
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_00f494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401E4BBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F494ULL;
}

// Func #0303 | PC: 0x00f4a4..0x00f4e4 (64 B) | Symbol: sub_00f4a4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_00f4a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401E4B7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F4A4ULL;
}

// Func #0304 | PC: 0x00f4b4..0x00f4f4 (64 B) | Symbol: sub_00f4b4
// EN: AArch64 prologue [bl #0x88780; movi v0.2d, #0000000000000000; add x8, sp, #0x8c9; add x11, sp, #0x548] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v0.2d, #0000000000000000; add x8, sp, #0x8c9; add x11, sp, #0x548]
uint64_t fde_sub_00f4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x9401E4B3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00F4B4ULL;
}

// Func #0305 | PC: 0x00ffc4..0x010004 (64 B) | Symbol: sub_00ffc4
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x548; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_00ffc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911523E0ULL) << 32) | 0x9401E4CCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00FFC4ULL;
}

// Func #0306 | PC: 0x00ffcc..0x01000c (64 B) | Symbol: sub_00ffcc
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0xffe0; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0xffe0; subs x19, x19, #0x30]
uint64_t fde_sub_00ffcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401DD28ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00FFCCULL;
}

// Func #0307 | PC: 0x00fffc..0x01003c (64 B) | Symbol: sub_00fffc
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0xffd8; add x8, x22, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0xffd8; add x8, x22, x19]
uint64_t fde_sub_00fffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FFC6B5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00FFFCULL;
}

// Func #0308 | PC: 0x010010..0x010050 (64 B) | Symbol: sub_010010
// EN: AArch64 prologue [bl #0x1ad0; b #0xffd8; adrp x0, #0xb6000; add x0, x0, #0x170] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0xffd8; adrp x0, #0xb6000; add x0, x0, #0x170]
uint64_t fde_sub_010010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FFC6B0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010010ULL;
}

// Func #0309 | PC: 0x010020..0x010060 (64 B) | Symbol: sub_010020
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xc0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_010020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063F3ULL) << 32) | 0x97FFC6B4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010020ULL;
}

// Func #0310 | PC: 0x01005c..0x01009c (64 B) | Symbol: sub_01005c
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_01005c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FFC6D9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01005CULL;
}

// Func #0311 | PC: 0x010060..0x011e60 (7680 B) | Symbol: rex_locale_init_ctor_07
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_010060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010060ULL;
}

// Func #0312 | PC: 0x01007c..0x0100bc (64 B) | Symbol: sub_01007c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_01007c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13143FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01007CULL;
}

// Func #0313 | PC: 0x010080..0x0100c0 (64 B) | Symbol: sub_010080
// EN: AArch64 prologue [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc50; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_010080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010080ULL;
}

// Func #0314 | PC: 0x0100a8..0x0100e8 (64 B) | Symbol: sub_0100a8
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x12388; movi v1.2d, #0000000000000000; mov w1, #0x656c] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x12388; movi v1.2d, #0000000000000000; mov w1, #0x656c]
uint64_t fde_sub_0100a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340116E0ULL) << 32) | 0x97FFC6D6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0100A8ULL;
}

// Func #0315 | PC: 0x010920..0x010960 (64 B) | Symbol: sub_010920
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc90]; adrp x11, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc90]; adrp x11, #0x99000]
uint64_t fde_sub_010920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000429ULL) << 32) | 0x97FFC4A0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010920ULL;
}

// Func #0316 | PC: 0x010e1c..0x010e5c (64 B) | Symbol: sub_010e1c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x50]]
uint64_t fde_sub_010e1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000428ULL) << 32) | 0x97FFC361ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010E1CULL;
}

// Func #0317 | PC: 0x010f8c..0x010fcc (64 B) | Symbol: sub_010f8c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_010f8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401DDFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010F8CULL;
}

// Func #0318 | PC: 0x010f9c..0x010fdc (64 B) | Symbol: sub_010f9c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_010f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401DDF9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010F9CULL;
}

// Func #0319 | PC: 0x010fac..0x010fec (64 B) | Symbol: sub_010fac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_010fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401DDF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010FACULL;
}

uint64_t DispatchRexShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x001c10ULL: return fde_sub_001c10(a0, a1, a2);
        case 0x001c2cULL: return fde_sub_001c2c(a0, a1, a2);
        case 0x001c30ULL: return fde_sub_001c30(a0, a1, a2);
        case 0x001c58ULL: return fde_sub_001c58(a0, a1, a2);
        case 0x0024ccULL: return fde_sub_0024cc(a0, a1, a2);
        case 0x002594ULL: return fde_sub_002594(a0, a1, a2);
        case 0x0029e4ULL: return fde_sub_0029e4(a0, a1, a2);
        case 0x002b58ULL: return fde_sub_002b58(a0, a1, a2);
        case 0x002b68ULL: return fde_sub_002b68(a0, a1, a2);
        case 0x002b78ULL: return fde_sub_002b78(a0, a1, a2);
        case 0x002b88ULL: return fde_sub_002b88(a0, a1, a2);
        case 0x002b98ULL: return fde_sub_002b98(a0, a1, a2);
        case 0x002ba8ULL: return fde_sub_002ba8(a0, a1, a2);
        case 0x002bb8ULL: return fde_sub_002bb8(a0, a1, a2);
        case 0x002bc8ULL: return fde_sub_002bc8(a0, a1, a2);
        case 0x002bd8ULL: return fde_sub_002bd8(a0, a1, a2);
        case 0x002be8ULL: return fde_sub_002be8(a0, a1, a2);
        case 0x002bf8ULL: return fde_sub_002bf8(a0, a1, a2);
        case 0x002c08ULL: return fde_sub_002c08(a0, a1, a2);
        case 0x002c18ULL: return fde_sub_002c18(a0, a1, a2);
        case 0x002c28ULL: return fde_sub_002c28(a0, a1, a2);
        case 0x002c38ULL: return fde_sub_002c38(a0, a1, a2);
        case 0x002c48ULL: return fde_sub_002c48(a0, a1, a2);
        case 0x002c58ULL: return fde_sub_002c58(a0, a1, a2);
        case 0x002c68ULL: return fde_sub_002c68(a0, a1, a2);
        case 0x002c78ULL: return fde_sub_002c78(a0, a1, a2);
        case 0x002c88ULL: return fde_sub_002c88(a0, a1, a2);
        case 0x002c98ULL: return fde_sub_002c98(a0, a1, a2);
        case 0x002ca8ULL: return fde_sub_002ca8(a0, a1, a2);
        case 0x002cb8ULL: return fde_sub_002cb8(a0, a1, a2);
        case 0x002cc8ULL: return fde_sub_002cc8(a0, a1, a2);
        case 0x003a18ULL: return fde_sub_003a18(a0, a1, a2);
        case 0x003a20ULL: return fde_sub_003a20(a0, a1, a2);
        case 0x003a50ULL: return fde_sub_003a50(a0, a1, a2);
        case 0x003a64ULL: return fde_sub_003a64(a0, a1, a2);
        case 0x003a74ULL: return fde_sub_003a74(a0, a1, a2);
        case 0x003ab0ULL: return fde_sub_003ab0(a0, a1, a2);
        case 0x003ab4ULL: return fde_sub_003ab4(a0, a1, a2);
        case 0x003ad0ULL: return fde_sub_003ad0(a0, a1, a2);
        case 0x003ad4ULL: return fde_sub_003ad4(a0, a1, a2);
        case 0x003afcULL: return fde_sub_003afc(a0, a1, a2);
        case 0x004354ULL: return fde_sub_004354(a0, a1, a2);
        case 0x004408ULL: return fde_sub_004408(a0, a1, a2);
        case 0x004534ULL: return fde_sub_004534(a0, a1, a2);
        case 0x004874ULL: return fde_sub_004874(a0, a1, a2);
        case 0x0049e8ULL: return fde_sub_0049e8(a0, a1, a2);
        case 0x0049f8ULL: return fde_sub_0049f8(a0, a1, a2);
        case 0x004a08ULL: return fde_sub_004a08(a0, a1, a2);
        case 0x004a18ULL: return fde_sub_004a18(a0, a1, a2);
        case 0x004a28ULL: return fde_sub_004a28(a0, a1, a2);
        case 0x004a38ULL: return fde_sub_004a38(a0, a1, a2);
        case 0x004a48ULL: return fde_sub_004a48(a0, a1, a2);
        case 0x004a58ULL: return fde_sub_004a58(a0, a1, a2);
        case 0x004a68ULL: return fde_sub_004a68(a0, a1, a2);
        case 0x004a78ULL: return fde_sub_004a78(a0, a1, a2);
        case 0x004a88ULL: return fde_sub_004a88(a0, a1, a2);
        case 0x004a98ULL: return fde_sub_004a98(a0, a1, a2);
        case 0x004aa8ULL: return fde_sub_004aa8(a0, a1, a2);
        case 0x004ab8ULL: return fde_sub_004ab8(a0, a1, a2);
        case 0x004ac8ULL: return fde_sub_004ac8(a0, a1, a2);
        case 0x004ad8ULL: return fde_sub_004ad8(a0, a1, a2);
        case 0x004ae8ULL: return fde_sub_004ae8(a0, a1, a2);
        case 0x004af8ULL: return fde_sub_004af8(a0, a1, a2);
        case 0x004b08ULL: return fde_sub_004b08(a0, a1, a2);
        case 0x004b18ULL: return fde_sub_004b18(a0, a1, a2);
        case 0x004b28ULL: return fde_sub_004b28(a0, a1, a2);
        case 0x004b38ULL: return fde_sub_004b38(a0, a1, a2);
        case 0x004b48ULL: return fde_sub_004b48(a0, a1, a2);
        case 0x004b58ULL: return fde_sub_004b58(a0, a1, a2);
        case 0x005378ULL: return fde_sub_005378(a0, a1, a2);
        case 0x0055b8ULL: return fde_sub_0055b8(a0, a1, a2);
        case 0x005650ULL: return fde_sub_005650(a0, a1, a2);
        case 0x0057f0ULL: return fde_sub_0057f0(a0, a1, a2);
        case 0x005924ULL: return fde_sub_005924(a0, a1, a2);
        case 0x005a5cULL: return fde_sub_005a5c(a0, a1, a2);
        case 0x005b80ULL: return fde_sub_005b80(a0, a1, a2);
        case 0x005cacULL: return fde_sub_005cac(a0, a1, a2);
        case 0x005dd4ULL: return fde_sub_005dd4(a0, a1, a2);
        case 0x005e08ULL: return fde_sub_005e08(a0, a1, a2);
        case 0x005e3cULL: return fde_sub_005e3c(a0, a1, a2);
        case 0x005e70ULL: return fde_sub_005e70(a0, a1, a2);
        case 0x005ef8ULL: return fde_sub_005ef8(a0, a1, a2);
        case 0x00601cULL: return fde_sub_00601c(a0, a1, a2);
        case 0x006134ULL: return fde_sub_006134(a0, a1, a2);
        case 0x006170ULL: return fde_sub_006170(a0, a1, a2);
        case 0x006254ULL: return fde_sub_006254(a0, a1, a2);
        case 0x006288ULL: return fde_sub_006288(a0, a1, a2);
        case 0x006578ULL: return fde_sub_006578(a0, a1, a2);
        case 0x006580ULL: return fde_sub_006580(a0, a1, a2);
        case 0x0065b0ULL: return fde_sub_0065b0(a0, a1, a2);
        case 0x0065c4ULL: return fde_sub_0065c4(a0, a1, a2);
        case 0x0065d4ULL: return fde_sub_0065d4(a0, a1, a2);
        case 0x006610ULL: return fde_sub_006610(a0, a1, a2);
        case 0x006614ULL: return fde_sub_006614(a0, a1, a2);
        case 0x006630ULL: return fde_sub_006630(a0, a1, a2);
        case 0x006634ULL: return fde_sub_006634(a0, a1, a2);
        case 0x00665cULL: return fde_sub_00665c(a0, a1, a2);
        case 0x006eacULL: return fde_sub_006eac(a0, a1, a2);
        case 0x006f70ULL: return fde_sub_006f70(a0, a1, a2);
        case 0x0073c4ULL: return fde_sub_0073c4(a0, a1, a2);
        case 0x007534ULL: return fde_sub_007534(a0, a1, a2);
        case 0x007544ULL: return fde_sub_007544(a0, a1, a2);
        case 0x007554ULL: return fde_sub_007554(a0, a1, a2);
        case 0x007564ULL: return fde_sub_007564(a0, a1, a2);
        case 0x007574ULL: return fde_sub_007574(a0, a1, a2);
        case 0x007584ULL: return fde_sub_007584(a0, a1, a2);
        case 0x007594ULL: return fde_sub_007594(a0, a1, a2);
        case 0x0075a4ULL: return fde_sub_0075a4(a0, a1, a2);
        case 0x0075b4ULL: return fde_sub_0075b4(a0, a1, a2);
        case 0x0075c4ULL: return fde_sub_0075c4(a0, a1, a2);
        case 0x0075d4ULL: return fde_sub_0075d4(a0, a1, a2);
        case 0x0075e4ULL: return fde_sub_0075e4(a0, a1, a2);
        case 0x0075f4ULL: return fde_sub_0075f4(a0, a1, a2);
        case 0x007604ULL: return fde_sub_007604(a0, a1, a2);
        case 0x007614ULL: return fde_sub_007614(a0, a1, a2);
        case 0x007624ULL: return fde_sub_007624(a0, a1, a2);
        case 0x007634ULL: return fde_sub_007634(a0, a1, a2);
        case 0x007644ULL: return fde_sub_007644(a0, a1, a2);
        case 0x007654ULL: return fde_sub_007654(a0, a1, a2);
        case 0x007664ULL: return fde_sub_007664(a0, a1, a2);
        case 0x007674ULL: return fde_sub_007674(a0, a1, a2);
        case 0x007684ULL: return fde_sub_007684(a0, a1, a2);
        case 0x007694ULL: return fde_sub_007694(a0, a1, a2);
        case 0x0076a4ULL: return fde_sub_0076a4(a0, a1, a2);
        case 0x0083d0ULL: return fde_sub_0083d0(a0, a1, a2);
        case 0x0083d8ULL: return fde_sub_0083d8(a0, a1, a2);
        case 0x008408ULL: return fde_sub_008408(a0, a1, a2);
        case 0x00841cULL: return fde_sub_00841c(a0, a1, a2);
        case 0x00842cULL: return fde_sub_00842c(a0, a1, a2);
        case 0x008468ULL: return fde_sub_008468(a0, a1, a2);
        case 0x00846cULL: return fde_sub_00846c(a0, a1, a2);
        case 0x008488ULL: return fde_sub_008488(a0, a1, a2);
        case 0x00848cULL: return fde_sub_00848c(a0, a1, a2);
        case 0x0084b4ULL: return fde_sub_0084b4(a0, a1, a2);
        case 0x008d94ULL: return fde_sub_008d94(a0, a1, a2);
        case 0x008e50ULL: return fde_sub_008e50(a0, a1, a2);
        case 0x008f7cULL: return fde_sub_008f7c(a0, a1, a2);
        case 0x0093d4ULL: return fde_sub_0093d4(a0, a1, a2);
        case 0x0093e4ULL: return fde_sub_0093e4(a0, a1, a2);
        case 0x0093f4ULL: return fde_sub_0093f4(a0, a1, a2);
        case 0x009404ULL: return fde_sub_009404(a0, a1, a2);
        case 0x009414ULL: return fde_sub_009414(a0, a1, a2);
        case 0x009424ULL: return fde_sub_009424(a0, a1, a2);
        case 0x009434ULL: return fde_sub_009434(a0, a1, a2);
        case 0x009444ULL: return fde_sub_009444(a0, a1, a2);
        case 0x009454ULL: return fde_sub_009454(a0, a1, a2);
        case 0x009464ULL: return fde_sub_009464(a0, a1, a2);
        case 0x009474ULL: return fde_sub_009474(a0, a1, a2);
        case 0x009484ULL: return fde_sub_009484(a0, a1, a2);
        case 0x009494ULL: return fde_sub_009494(a0, a1, a2);
        case 0x0094a4ULL: return fde_sub_0094a4(a0, a1, a2);
        case 0x0094b4ULL: return fde_sub_0094b4(a0, a1, a2);
        case 0x0094c4ULL: return fde_sub_0094c4(a0, a1, a2);
        case 0x0094d4ULL: return fde_sub_0094d4(a0, a1, a2);
        case 0x0094e4ULL: return fde_sub_0094e4(a0, a1, a2);
        case 0x0094f4ULL: return fde_sub_0094f4(a0, a1, a2);
        case 0x009504ULL: return fde_sub_009504(a0, a1, a2);
        case 0x009514ULL: return fde_sub_009514(a0, a1, a2);
        case 0x009524ULL: return fde_sub_009524(a0, a1, a2);
        case 0x009534ULL: return fde_sub_009534(a0, a1, a2);
        case 0x009544ULL: return fde_sub_009544(a0, a1, a2);
        case 0x009b14ULL: return fde_sub_009b14(a0, a1, a2);
        case 0x009b68ULL: return fde_sub_009b68(a0, a1, a2);
        case 0x00a274ULL: return fde_sub_00a274(a0, a1, a2);
        case 0x00a2b0ULL: return fde_sub_00a2b0(a0, a1, a2);
        case 0x00a340ULL: return fde_sub_00a340(a0, a1, a2);
        case 0x00a348ULL: return fde_sub_00a348(a0, a1, a2);
        case 0x00a378ULL: return fde_sub_00a378(a0, a1, a2);
        case 0x00a38cULL: return fde_sub_00a38c(a0, a1, a2);
        case 0x00a39cULL: return fde_sub_00a39c(a0, a1, a2);
        case 0x00a3d8ULL: return fde_sub_00a3d8(a0, a1, a2);
        case 0x00a3dcULL: return fde_sub_00a3dc(a0, a1, a2);
        case 0x00a3f8ULL: return fde_sub_00a3f8(a0, a1, a2);
        case 0x00a3fcULL: return fde_sub_00a3fc(a0, a1, a2);
        case 0x00a424ULL: return fde_sub_00a424(a0, a1, a2);
        case 0x00a488ULL: return fde_sub_00a488(a0, a1, a2);
        case 0x00a4c8ULL: return fde_sub_00a4c8(a0, a1, a2);
        case 0x00a60cULL: return fde_sub_00a60c(a0, a1, a2);
        case 0x00a6a4ULL: return fde_sub_00a6a4(a0, a1, a2);
        case 0x00a934ULL: return fde_sub_00a934(a0, a1, a2);
        case 0x00a998ULL: return fde_sub_00a998(a0, a1, a2);
        case 0x00a9c8ULL: return fde_sub_00a9c8(a0, a1, a2);
        case 0x00ab00ULL: return fde_sub_00ab00(a0, a1, a2);
        case 0x00ae80ULL: return fde_sub_00ae80(a0, a1, a2);
        case 0x00af3cULL: return fde_sub_00af3c(a0, a1, a2);
        case 0x00b39cULL: return fde_sub_00b39c(a0, a1, a2);
        case 0x00b508ULL: return fde_sub_00b508(a0, a1, a2);
        case 0x00b518ULL: return fde_sub_00b518(a0, a1, a2);
        case 0x00b528ULL: return fde_sub_00b528(a0, a1, a2);
        case 0x00b538ULL: return fde_sub_00b538(a0, a1, a2);
        case 0x00b548ULL: return fde_sub_00b548(a0, a1, a2);
        case 0x00b558ULL: return fde_sub_00b558(a0, a1, a2);
        case 0x00b568ULL: return fde_sub_00b568(a0, a1, a2);
        case 0x00b578ULL: return fde_sub_00b578(a0, a1, a2);
        case 0x00b588ULL: return fde_sub_00b588(a0, a1, a2);
        case 0x00b598ULL: return fde_sub_00b598(a0, a1, a2);
        case 0x00b5a8ULL: return fde_sub_00b5a8(a0, a1, a2);
        case 0x00b5b8ULL: return fde_sub_00b5b8(a0, a1, a2);
        case 0x00b5c8ULL: return fde_sub_00b5c8(a0, a1, a2);
        case 0x00b5d8ULL: return fde_sub_00b5d8(a0, a1, a2);
        case 0x00b5e8ULL: return fde_sub_00b5e8(a0, a1, a2);
        case 0x00b5f8ULL: return fde_sub_00b5f8(a0, a1, a2);
        case 0x00b608ULL: return fde_sub_00b608(a0, a1, a2);
        case 0x00b618ULL: return fde_sub_00b618(a0, a1, a2);
        case 0x00b628ULL: return fde_sub_00b628(a0, a1, a2);
        case 0x00b638ULL: return fde_sub_00b638(a0, a1, a2);
        case 0x00b648ULL: return fde_sub_00b648(a0, a1, a2);
        case 0x00b658ULL: return fde_sub_00b658(a0, a1, a2);
        case 0x00b668ULL: return fde_sub_00b668(a0, a1, a2);
        case 0x00b678ULL: return fde_sub_00b678(a0, a1, a2);
        case 0x00b7c0ULL: return fde_sub_00b7c0(a0, a1, a2);
        case 0x00bb7cULL: return fde_sub_00bb7c(a0, a1, a2);
        case 0x00bbecULL: return fde_sub_00bbec(a0, a1, a2);
        case 0x00bc90ULL: return fde_sub_00bc90(a0, a1, a2);
        case 0x00bce0ULL: return fde_sub_00bce0(a0, a1, a2);
        case 0x00bd84ULL: return fde_sub_00bd84(a0, a1, a2);
        case 0x00bddcULL: return fde_sub_00bddc(a0, a1, a2);
        case 0x00be10ULL: return fde_sub_00be10(a0, a1, a2);
        case 0x00be64ULL: return fde_sub_00be64(a0, a1, a2);
        case 0x00be98ULL: return fde_sub_00be98(a0, a1, a2);
        case 0x00befcULL: return fde_sub_00befc(a0, a1, a2);
        case 0x00c008ULL: return fde_sub_00c008(a0, a1, a2);
        case 0x00c058ULL: return fde_sub_00c058(a0, a1, a2);
        case 0x00c088ULL: return fde_sub_00c088(a0, a1, a2);
        case 0x00c0e0ULL: return fde_sub_00c0e0(a0, a1, a2);
        case 0x00c118ULL: return fde_sub_00c118(a0, a1, a2);
        case 0x00c168ULL: return fde_sub_00c168(a0, a1, a2);
        case 0x00c20cULL: return fde_sub_00c20c(a0, a1, a2);
        case 0x00c260ULL: return fde_sub_00c260(a0, a1, a2);
        case 0x00c4ccULL: return fde_sub_00c4cc(a0, a1, a2);
        case 0x00c4d4ULL: return fde_sub_00c4d4(a0, a1, a2);
        case 0x00c504ULL: return fde_sub_00c504(a0, a1, a2);
        case 0x00c518ULL: return fde_sub_00c518(a0, a1, a2);
        case 0x00c528ULL: return fde_sub_00c528(a0, a1, a2);
        case 0x00c564ULL: return fde_sub_00c564(a0, a1, a2);
        case 0x00c568ULL: return fde_sub_00c568(a0, a1, a2);
        case 0x00c584ULL: return fde_sub_00c584(a0, a1, a2);
        case 0x00c588ULL: return fde_sub_00c588(a0, a1, a2);
        case 0x00c5b0ULL: return fde_sub_00c5b0(a0, a1, a2);
        case 0x00cd88ULL: return fde_sub_00cd88(a0, a1, a2);
        case 0x00cdecULL: return fde_sub_00cdec(a0, a1, a2);
        case 0x00ceb0ULL: return fde_sub_00ceb0(a0, a1, a2);
        case 0x00d25cULL: return fde_sub_00d25c(a0, a1, a2);
        case 0x00d318ULL: return fde_sub_00d318(a0, a1, a2);
        case 0x00d484ULL: return fde_sub_00d484(a0, a1, a2);
        case 0x00d494ULL: return fde_sub_00d494(a0, a1, a2);
        case 0x00d4a4ULL: return fde_sub_00d4a4(a0, a1, a2);
        case 0x00d4b4ULL: return fde_sub_00d4b4(a0, a1, a2);
        case 0x00d4c4ULL: return fde_sub_00d4c4(a0, a1, a2);
        case 0x00d4d4ULL: return fde_sub_00d4d4(a0, a1, a2);
        case 0x00d4e4ULL: return fde_sub_00d4e4(a0, a1, a2);
        case 0x00d4f4ULL: return fde_sub_00d4f4(a0, a1, a2);
        case 0x00d504ULL: return fde_sub_00d504(a0, a1, a2);
        case 0x00d514ULL: return fde_sub_00d514(a0, a1, a2);
        case 0x00d524ULL: return fde_sub_00d524(a0, a1, a2);
        case 0x00d534ULL: return fde_sub_00d534(a0, a1, a2);
        case 0x00d544ULL: return fde_sub_00d544(a0, a1, a2);
        case 0x00d554ULL: return fde_sub_00d554(a0, a1, a2);
        case 0x00d564ULL: return fde_sub_00d564(a0, a1, a2);
        case 0x00d574ULL: return fde_sub_00d574(a0, a1, a2);
        case 0x00d584ULL: return fde_sub_00d584(a0, a1, a2);
        case 0x00d594ULL: return fde_sub_00d594(a0, a1, a2);
        case 0x00d5a4ULL: return fde_sub_00d5a4(a0, a1, a2);
        case 0x00d5b4ULL: return fde_sub_00d5b4(a0, a1, a2);
        case 0x00d5c4ULL: return fde_sub_00d5c4(a0, a1, a2);
        case 0x00d5d4ULL: return fde_sub_00d5d4(a0, a1, a2);
        case 0x00d5e4ULL: return fde_sub_00d5e4(a0, a1, a2);
        case 0x00d5f4ULL: return fde_sub_00d5f4(a0, a1, a2);
        case 0x00e358ULL: return fde_sub_00e358(a0, a1, a2);
        case 0x00e360ULL: return fde_sub_00e360(a0, a1, a2);
        case 0x00e390ULL: return fde_sub_00e390(a0, a1, a2);
        case 0x00e3a4ULL: return fde_sub_00e3a4(a0, a1, a2);
        case 0x00e3b4ULL: return fde_sub_00e3b4(a0, a1, a2);
        case 0x00e3f0ULL: return fde_sub_00e3f0(a0, a1, a2);
        case 0x00e3f4ULL: return fde_sub_00e3f4(a0, a1, a2);
        case 0x00e410ULL: return fde_sub_00e410(a0, a1, a2);
        case 0x00e414ULL: return fde_sub_00e414(a0, a1, a2);
        case 0x00e43cULL: return fde_sub_00e43c(a0, a1, a2);
        case 0x00ec98ULL: return fde_sub_00ec98(a0, a1, a2);
        case 0x00ed58ULL: return fde_sub_00ed58(a0, a1, a2);
        case 0x00f1d4ULL: return fde_sub_00f1d4(a0, a1, a2);
        case 0x00f344ULL: return fde_sub_00f344(a0, a1, a2);
        case 0x00f354ULL: return fde_sub_00f354(a0, a1, a2);
        case 0x00f364ULL: return fde_sub_00f364(a0, a1, a2);
        case 0x00f374ULL: return fde_sub_00f374(a0, a1, a2);
        case 0x00f384ULL: return fde_sub_00f384(a0, a1, a2);
        case 0x00f394ULL: return fde_sub_00f394(a0, a1, a2);
        case 0x00f3a4ULL: return fde_sub_00f3a4(a0, a1, a2);
        case 0x00f3b4ULL: return fde_sub_00f3b4(a0, a1, a2);
        case 0x00f3c4ULL: return fde_sub_00f3c4(a0, a1, a2);
        case 0x00f3d4ULL: return fde_sub_00f3d4(a0, a1, a2);
        case 0x00f3e4ULL: return fde_sub_00f3e4(a0, a1, a2);
        case 0x00f3f4ULL: return fde_sub_00f3f4(a0, a1, a2);
        case 0x00f404ULL: return fde_sub_00f404(a0, a1, a2);
        case 0x00f414ULL: return fde_sub_00f414(a0, a1, a2);
        case 0x00f424ULL: return fde_sub_00f424(a0, a1, a2);
        case 0x00f434ULL: return fde_sub_00f434(a0, a1, a2);
        case 0x00f444ULL: return fde_sub_00f444(a0, a1, a2);
        case 0x00f454ULL: return fde_sub_00f454(a0, a1, a2);
        case 0x00f464ULL: return fde_sub_00f464(a0, a1, a2);
        case 0x00f474ULL: return fde_sub_00f474(a0, a1, a2);
        case 0x00f484ULL: return fde_sub_00f484(a0, a1, a2);
        case 0x00f494ULL: return fde_sub_00f494(a0, a1, a2);
        case 0x00f4a4ULL: return fde_sub_00f4a4(a0, a1, a2);
        case 0x00f4b4ULL: return fde_sub_00f4b4(a0, a1, a2);
        case 0x00ffc4ULL: return fde_sub_00ffc4(a0, a1, a2);
        case 0x00ffccULL: return fde_sub_00ffcc(a0, a1, a2);
        case 0x00fffcULL: return fde_sub_00fffc(a0, a1, a2);
        case 0x010010ULL: return fde_sub_010010(a0, a1, a2);
        case 0x010020ULL: return fde_sub_010020(a0, a1, a2);
        case 0x01005cULL: return fde_sub_01005c(a0, a1, a2);
        case 0x010060ULL: return fde_sub_010060(a0, a1, a2);
        case 0x01007cULL: return fde_sub_01007c(a0, a1, a2);
        case 0x010080ULL: return fde_sub_010080(a0, a1, a2);
        case 0x0100a8ULL: return fde_sub_0100a8(a0, a1, a2);
        case 0x010920ULL: return fde_sub_010920(a0, a1, a2);
        case 0x010e1cULL: return fde_sub_010e1c(a0, a1, a2);
        case 0x010f8cULL: return fde_sub_010f8c(a0, a1, a2);
        case 0x010f9cULL: return fde_sub_010f9c(a0, a1, a2);
        case 0x010facULL: return fde_sub_010fac(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace rex
} // namespace bytedance
