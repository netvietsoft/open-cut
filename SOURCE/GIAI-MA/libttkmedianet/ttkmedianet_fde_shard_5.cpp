// ============================================================================
// File: ttkmedianet_fde_shard_5.cpp
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 5/5 covering FDEs [1316..1642]
//     (PC range 0x06c6b4 .. 0x07c780).
// VI: Phân mảnh FDE AArch64 C++17 5/5 bao phủ các FDE [1316..1642]
//     (Dải địa chỉ PC 0x06c6b4 .. 0x07c780).
// ============================================================================
#include "ttkmedianet_core.h"

namespace TTKMediaNet {

// FDE #1316 | PC: 0x06c6b4..0x06c798 (228 B) | Symbol: sub_06c6b4
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06c6b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C6B4ULL;
}

// FDE #1317 | PC: 0x06c798..0x06c7d4 (60 B) | Symbol: sub_06c798
// EN: AArch64 prologue [ldr x8, [x2, #0xac0]; ldr w9, [x2, #4]; orr x8, x8, #0x10000; str x8, [x2, #0xac0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2, #0xac0]; ldr w9, [x2, #4]; orr x8, x8, #0x10000; str x8, [x2, #0xac0]]
uint64_t fde_sub_06c798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400449ULL) << 32) | 0xF9456048ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C798ULL;
}

// FDE #1318 | PC: 0x06c7d4..0x06c89c (200 B) | Symbol: sub_06c7d4
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06c7d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7D4ULL;
}

// FDE #1319 | PC: 0x06c89c..0x06c8b0 (20 B) | Symbol: sub_06c89c
// EN: AArch64 prologue [ldr x8, [x2, #0xac0]; mov x0, x2; and x8, x8, #0xfffffffffbffffff; str x8, [x2, #0xac0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2, #0xac0]; mov x0, x2; and x8, x8, #0xfffffffffbffffff; str x8, [x2, #0xac0]]
uint64_t fde_sub_06c89c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E0ULL) << 32) | 0xF9456048ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C89CULL;
}

// FDE #1320 | PC: 0x06c8b0..0x06c8b8 (8 B) | Symbol: sub_06c8b0
// EN: AArch64 prologue [ldr x0, [x2, #0x710]; b #0x6e6c4] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2, #0x710]; b #0x6e6c4]
uint64_t fde_sub_06c8b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000784ULL) << 32) | 0xF9438840ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C8B0ULL;
}

// FDE #1321 | PC: 0x06c8b8..0x06c8c8 (16 B) | Symbol: sub_06c8b8
// EN: AArch64 prologue [ldr x8, [x2, #0xac0]; orr x8, x8, #0x800000000; str x8, [x2, #0xac0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2, #0xac0]; orr x8, x8, #0x800000000; str x8, [x2, #0xac0]; ret]
uint64_t fde_sub_06c8b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB25D0108ULL) << 32) | 0xF9456048ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C8B8ULL;
}

// FDE #1322 | PC: 0x06c8c8..0x06ca14 (332 B) | Symbol: sub_06c8c8
// EN: AArch64 prologue [str x1, [x0, #0x200]; adrp x16, #0x9b000; adrp x17, #0x9b000; adrp x1, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x1, [x0, #0x200]; adrp x16, #0x9b000; adrp x17, #0x9b000; adrp x1, #0x9b000]
uint64_t fde_sub_06c8c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000170ULL) << 32) | 0xF9010001ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C8C8ULL;
}

// FDE #1323 | PC: 0x06ca14..0x06cafc (232 B) | Symbol: sub_06ca14
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06ca14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CA14ULL;
}

// FDE #1324 | PC: 0x06cafc..0x06cb8c (144 B) | Symbol: sub_06cafc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x6cb6c] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x6cb6c]
uint64_t fde_sub_06cafc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CAFCULL;
}

// FDE #1325 | PC: 0x06cb8c..0x06cbe8 (92 B) | Symbol: sub_06cb8c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06cb8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CB8CULL;
}

// FDE #1326 | PC: 0x06cbe8..0x06cdd8 (496 B) | Symbol: sub_06cbe8
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06cbe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CBE8ULL;
}

// FDE #1327 | PC: 0x06cdd8..0x06cecc (244 B) | Symbol: sub_06cdd8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06cdd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CDD8ULL;
}

// FDE #1328 | PC: 0x06cecc..0x06ced8 (12 B) | Symbol: sub_06cecc
// EN: AArch64 prologue [ldr x8, [x1, #0xc50]; stp x8, x1, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0xc50]; stp x8, x1, [x0]; ret]
uint64_t fde_sub_06cecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9000408ULL) << 32) | 0xF9462828ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CECCULL;
}

// FDE #1329 | PC: 0x06ced8..0x06cf14 (60 B) | Symbol: sub_06ced8
// EN: AArch64 prologue [cmp w2, #4; b.ne #0x6cf0c; ldrh w8, [x1, #0xf2]; mov w9, #0x204] | VI: Khởi đầu hàm AArch64 [cmp w2, #4; b.ne #0x6cf0c; ldrh w8, [x1, #0xf2]; mov w9, #0x204]
uint64_t fde_sub_06ced8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000181ULL) << 32) | 0x7100105FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CED8ULL;
}

// FDE #1330 | PC: 0x06cf14..0x06cf1c (8 B) | Symbol: sub_06cf14
// EN: AArch64 prologue [mov w0, #0x10; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x10; ret]
uint64_t fde_sub_06cf14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CF14ULL;
}

// FDE #1331 | PC: 0x06cf1c..0x06d158 (572 B) | Symbol: sub_06cf1c
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_06cf1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x023CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CF1CULL;
}

// FDE #1332 | PC: 0x06d158..0x06d15c (4 B) | Symbol: sub_06d158
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_06d158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D158ULL;
}

// FDE #1333 | PC: 0x06d15c..0x06d164 (8 B) | Symbol: sub_06d15c
// EN: AArch64 prologue [mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; ret]
uint64_t fde_sub_06d15c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D15CULL;
}

// FDE #1334 | PC: 0x06d164..0x06d19c (56 B) | Symbol: sub_06d164
// EN: AArch64 prologue [cbz w2, #0x6d18c; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w2, [x0, #0x1e8]] | VI: Khởi đầu hàm AArch64 [cbz w2, #0x6d18c; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w2, [x0, #0x1e8]]
uint64_t fde_sub_06d164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x34000142ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D164ULL;
}

// FDE #1335 | PC: 0x06d19c..0x06d370 (468 B) | Symbol: sub_06d19c
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_06d19c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D19CULL;
}

// FDE #1336 | PC: 0x06d370..0x06d374 (4 B) | Symbol: sub_06d370
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_06d370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D370ULL;
}

// FDE #1337 | PC: 0x06d374..0x06d37c (8 B) | Symbol: sub_06d374
// EN: AArch64 prologue [mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; ret]
uint64_t fde_sub_06d374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D374ULL;
}

// FDE #1338 | PC: 0x06d37c..0x06d418 (156 B) | Symbol: sub_06d37c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06d37c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D37CULL;
}

// FDE #1339 | PC: 0x06d418..0x06d544 (300 B) | Symbol: sub_06d418
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06d418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D418ULL;
}

// FDE #1340 | PC: 0x06d544..0x06d5d8 (148 B) | Symbol: sub_06d544
// EN: AArch64 prologue [cmp x2, #0x50; b.eq #0x6d554; cmp x2, #0x30; b.ne #0x6d59c] | VI: Khởi đầu hàm AArch64 [cmp x2, #0x50; b.eq #0x6d554; cmp x2, #0x30; b.ne #0x6d59c]
uint64_t fde_sub_06d544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000060ULL) << 32) | 0xF101405FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D544ULL;
}

// FDE #1341 | PC: 0x06d5d8..0x06d7d0 (504 B) | Symbol: sub_06d5d8
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06d5d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D5D8ULL;
}

// FDE #1342 | PC: 0x06d7d0..0x06d8ac (220 B) | Symbol: sub_06d7d0
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06d7d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D7D0ULL;
}

// FDE #1343 | PC: 0x06d8ac..0x06d924 (120 B) | Symbol: sub_06d8ac
// EN: AArch64 prologue [cbz x0, #0x6d920; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x6d920; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_06d8ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40003A0ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D8ACULL;
}

// FDE #1344 | PC: 0x06d924..0x06d92c (8 B) | Symbol: sub_06d924
// EN: AArch64 prologue [ldr x0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; ret]
uint64_t fde_sub_06d924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D924ULL;
}

// FDE #1345 | PC: 0x06d92c..0x06d934 (8 B) | Symbol: sub_06d92c
// EN: AArch64 prologue [ldr w0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0]; ret]
uint64_t fde_sub_06d92c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D92CULL;
}

// FDE #1346 | PC: 0x06d934..0x06d940 (12 B) | Symbol: sub_06d934
// EN: AArch64 prologue [add x8, x0, #0x48; str x8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [add x8, x0, #0x48; str x8, [x1]; ret]
uint64_t fde_sub_06d934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000028ULL) << 32) | 0x91012008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D934ULL;
}

// FDE #1347 | PC: 0x06d940..0x06d94c (12 B) | Symbol: sub_06d940
// EN: AArch64 prologue [add x8, x0, #0x90; str x8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [add x8, x0, #0x90; str x8, [x1]; ret]
uint64_t fde_sub_06d940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000028ULL) << 32) | 0x91024008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D940ULL;
}

// FDE #1348 | PC: 0x06d94c..0x06d958 (12 B) | Symbol: sub_06d94c
// EN: AArch64 prologue [add x8, x0, #0x10; str x8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [add x8, x0, #0x10; str x8, [x1]; ret]
uint64_t fde_sub_06d94c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000028ULL) << 32) | 0x91004008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D94CULL;
}

// FDE #1349 | PC: 0x06d958..0x06da34 (220 B) | Symbol: sub_06d958
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06d958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D958ULL;
}

// FDE #1350 | PC: 0x06da34..0x06dad8 (164 B) | Symbol: sub_06da34
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_06da34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DA34ULL;
}

// FDE #1351 | PC: 0x06dad8..0x06db8c (180 B) | Symbol: sub_06dad8
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06dad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DAD8ULL;
}

// FDE #1352 | PC: 0x06db8c..0x06dba0 (20 B) | Symbol: sub_06db8c
// EN: AArch64 prologue [ldr x8, [x0, #0xf0]; str x8, [x1]; ldr x8, [x0, #0x100]; str x8, [x2]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0xf0]; str x8, [x1]; ldr x8, [x0, #0x100]; str x8, [x2]]
uint64_t fde_sub_06db8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000028ULL) << 32) | 0xF9407808ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DB8CULL;
}

// FDE #1353 | PC: 0x06dba0..0x06dc6c (204 B) | Symbol: sub_06dba0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06dba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DBA0ULL;
}

// FDE #1354 | PC: 0x06dc6c..0x06dd08 (156 B) | Symbol: sub_06dc6c
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06dc6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DC6CULL;
}

// FDE #1355 | PC: 0x06dd08..0x06de20 (280 B) | Symbol: sub_06dd08
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06dd08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DD08ULL;
}

// FDE #1356 | PC: 0x06de20..0x06dfb4 (404 B) | Symbol: sub_06de20
// EN: AArch64 prologue [stp x28, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06de20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FFCULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DE20ULL;
}

// FDE #1357 | PC: 0x06dfb4..0x06e094 (224 B) | Symbol: sub_06dfb4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06dfb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DFB4ULL;
}

// FDE #1358 | PC: 0x06e094..0x06e0b8 (36 B) | Symbol: sub_06e094
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0, #8]; bl #0xeba0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0, #8]; bl #0xeba0]
uint64_t fde_sub_06e094(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E094ULL;
}

// FDE #1359 | PC: 0x06e0b8..0x06e18c (212 B) | Symbol: sub_06e0b8
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06e0b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E0B8ULL;
}

// FDE #1360 | PC: 0x06e18c..0x06e1e0 (84 B) | Symbol: sub_06e18c
// EN: AArch64 prologue [cbz x0, #0x6e1dc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x6e1dc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_06e18c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000280ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E18CULL;
}

// FDE #1361 | PC: 0x06e1e0..0x06e2f4 (276 B) | Symbol: sub_06e1e0
// EN: AArch64 prologue [sub sp, sp, #0x90; str x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]]
uint64_t fde_sub_06e1e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF7ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E1E0ULL;
}

// FDE #1362 | PC: 0x06e2f4..0x06e3c0 (204 B) | Symbol: sub_06e2f4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06e2f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E2F4ULL;
}

// FDE #1363 | PC: 0x06e3c0..0x06e3dc (28 B) | Symbol: sub_06e3c0
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; str w1, [x0, #0x58]; cbz x8, #0x6e3d4; mov x1, x2] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; str w1, [x0, #0x58]; cbz x8, #0x6e3d4; mov x1, x2]
uint64_t fde_sub_06e3c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9005801ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E3C0ULL;
}

// FDE #1364 | PC: 0x06e3dc..0x06e4b4 (216 B) | Symbol: sub_06e3dc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #8]]
uint64_t fde_sub_06e3dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E3DCULL;
}

// FDE #1365 | PC: 0x06e4b4..0x06e4dc (40 B) | Symbol: sub_06e4b4
// EN: AArch64 prologue [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e4d4; mov w1, w2] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e4d4; mov w1, w2]
uint64_t fde_sub_06e4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D00ULL) << 32) | 0x8B214C08ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E4B4ULL;
}

// FDE #1366 | PC: 0x06e4dc..0x06e524 (72 B) | Symbol: sub_06e4dc
// EN: AArch64 prologue [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e504; ldp x10, x9, [sp, #8]] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e504; ldp x10, x9, [sp, #8]]
uint64_t fde_sub_06e4dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D00ULL) << 32) | 0x8B214C08ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E4DCULL;
}

// FDE #1367 | PC: 0x06e524..0x06e54c (40 B) | Symbol: sub_06e524
// EN: AArch64 prologue [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e544; mov w1, w2] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e544; mov w1, w2]
uint64_t fde_sub_06e524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D00ULL) << 32) | 0x8B214C08ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E524ULL;
}

// FDE #1368 | PC: 0x06e54c..0x06e594 (72 B) | Symbol: sub_06e54c
// EN: AArch64 prologue [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e574; ldp x10, x9, [sp, #8]] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e574; ldp x10, x9, [sp, #8]]
uint64_t fde_sub_06e54c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D00ULL) << 32) | 0x8B214C08ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E54CULL;
}

// FDE #1369 | PC: 0x06e594..0x06e5ac (24 B) | Symbol: sub_06e594
// EN: AArch64 prologue [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e5a8; mov w1, w2] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e5a8; mov w1, w2]
uint64_t fde_sub_06e594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D00ULL) << 32) | 0x8B214C08ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E594ULL;
}

// FDE #1370 | PC: 0x06e5ac..0x06e5f0 (68 B) | Symbol: sub_06e5ac
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x10]; cmp w8, #1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x10]; cmp w8, #1]
uint64_t fde_sub_06e5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E5ACULL;
}

// FDE #1371 | PC: 0x06e5f0..0x06e610 (32 B) | Symbol: sub_06e5f0
// EN: AArch64 prologue [ldrb w8, [x0, #0x50]; cbz w8, #0x6e608; ldr x0, [x0, #0x20]; cbz x0, #0x6e608] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x50]; cbz w8, #0x6e608; ldr x0, [x0, #0x20]; cbz x0, #0x6e608]
uint64_t fde_sub_06e5f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000A8ULL) << 32) | 0x39414008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E5F0ULL;
}

// FDE #1372 | PC: 0x06e610..0x06e628 (24 B) | Symbol: sub_06e610
// EN: AArch64 prologue [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e620; b #0x7374c] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #3; ldr x0, [x8, #0x18]; cbz x0, #0x6e620; b #0x7374c]
uint64_t fde_sub_06e610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D00ULL) << 32) | 0x8B214C08ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E610ULL;
}

// FDE #1373 | PC: 0x06e628..0x06e634 (12 B) | Symbol: sub_06e628
// EN: AArch64 prologue [mov w8, #1; strb w8, [x0, #0x15]; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #1; strb w8, [x0, #0x15]; ret]
uint64_t fde_sub_06e628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39005408ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E628ULL;
}

// FDE #1374 | PC: 0x06e634..0x06e640 (12 B) | Symbol: sub_06e634
// EN: AArch64 prologue [ldr x8, [x0, #0x30]; str w1, [x8, #0x170]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x30]; str w1, [x8, #0x170]; ret]
uint64_t fde_sub_06e634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9017101ULL) << 32) | 0xF9401808ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E634ULL;
}

// FDE #1375 | PC: 0x06e640..0x06e648 (8 B) | Symbol: sub_06e640
// EN: AArch64 prologue [ldrb w0, [x0, #0x5c]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x5c]; ret]
uint64_t fde_sub_06e640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39417000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E640ULL;
}

// FDE #1376 | PC: 0x06e648..0x06e6c4 (124 B) | Symbol: sub_06e648
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06e648(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E648ULL;
}

// FDE #1377 | PC: 0x06e6c4..0x06e6cc (8 B) | Symbol: sub_06e6c4
// EN: AArch64 prologue [ldr x0, [x0, #0x30]; b #0x739d4] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x30]; b #0x739d4]
uint64_t fde_sub_06e6c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140014C3ULL) << 32) | 0xF9401800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E6C4ULL;
}

// FDE #1378 | PC: 0x06e6cc..0x06e7bc (240 B) | Symbol: sub_06e6cc
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_06e6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E6CCULL;
}

// FDE #1379 | PC: 0x06e7bc..0x06e800 (68 B) | Symbol: sub_06e7bc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_06e7bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E7BCULL;
}

// FDE #1380 | PC: 0x06e800..0x06e8ec (236 B) | Symbol: sub_06e800
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_06e800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E800ULL;
}

// FDE #1381 | PC: 0x06e8ec..0x06ead4 (488 B) | Symbol: sub_06e8ec
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06e8ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E8ECULL;
}

// FDE #1382 | PC: 0x06ead4..0x06eb98 (196 B) | Symbol: sub_06ead4
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06ead4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EAD4ULL;
}

// FDE #1383 | PC: 0x06eb98..0x06ec94 (252 B) | Symbol: sub_06eb98
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06eb98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB98ULL;
}

// FDE #1384 | PC: 0x06ec94..0x06eca4 (16 B) | Symbol: sub_06ec94
// EN: AArch64 prologue [cbz x0, #0x6eca0; ldr x0, [x0, #8]; b #0xf410; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x6eca0; ldr x0, [x0, #8]; b #0xf410; ret]
uint64_t fde_sub_06ec94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EC94ULL;
}

// FDE #1385 | PC: 0x06eca4..0x06edfc (344 B) | Symbol: sub_06eca4
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_06eca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ECA4ULL;
}

// FDE #1386 | PC: 0x06edfc..0x06ef64 (360 B) | Symbol: sub_06edfc
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_06edfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EDFCULL;
}

// FDE #1387 | PC: 0x06ef64..0x06efd4 (112 B) | Symbol: sub_06ef64
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06ef64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EF64ULL;
}

// FDE #1388 | PC: 0x06efd4..0x06efdc (8 B) | Symbol: sub_06efd4
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_06efd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EFD4ULL;
}

// FDE #1389 | PC: 0x06efdc..0x06f01c (64 B) | Symbol: sub_06efdc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, wzr] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, wzr]
uint64_t fde_sub_06efdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EFDCULL;
}

// FDE #1390 | PC: 0x06f01c..0x06f058 (60 B) | Symbol: sub_06f01c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #0x3a80] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #0x3a80]
uint64_t fde_sub_06f01c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F01CULL;
}

// FDE #1391 | PC: 0x06f058..0x06f05c (4 B) | Symbol: sub_06f058
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_06f058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F058ULL;
}

// FDE #1392 | PC: 0x06f05c..0x06f064 (8 B) | Symbol: sub_06f05c
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06f05c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F05CULL;
}

// FDE #1393 | PC: 0x06f064..0x06f078 (20 B) | Symbol: sub_06f064
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xea80; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xea80; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_06f064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F064ULL;
}

// FDE #1394 | PC: 0x06f078..0x06f080 (8 B) | Symbol: sub_06f078
// EN: AArch64 prologue [mov w1, #1; b #0xf6a0] | VI: Khởi đầu hàm AArch64 [mov w1, #1; b #0xf6a0]
uint64_t fde_sub_06f078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE8189ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F078ULL;
}

// FDE #1395 | PC: 0x06f080..0x06f130 (176 B) | Symbol: sub_06f080
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06f080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F080ULL;
}

// FDE #1396 | PC: 0x06f130..0x06f134 (4 B) | Symbol: sub_06f130
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_06f130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F130ULL;
}

// FDE #1397 | PC: 0x06f134..0x06f150 (28 B) | Symbol: sub_06f134
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xfa30; cmp w0, #0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xfa30; cmp w0, #0]
uint64_t fde_sub_06f134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F134ULL;
}

// FDE #1398 | PC: 0x06f150..0x06f1f0 (160 B) | Symbol: sub_06f150
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06f150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F150ULL;
}

// FDE #1399 | PC: 0x06f1f0..0x06f1f4 (4 B) | Symbol: sub_06f1f0
// EN: AArch64 prologue [b #0xecb0] | VI: Khởi đầu hàm AArch64 [b #0xecb0]
uint64_t fde_sub_06f1f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FE7EB0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F1F0ULL;
}

// FDE #1400 | PC: 0x06f1f4..0x06f270 (124 B) | Symbol: sub_06f1f4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_06f1f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F1F4ULL;
}

// FDE #1401 | PC: 0x06f270..0x06f2a8 (56 B) | Symbol: sub_06f270
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06f270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F270ULL;
}

// FDE #1402 | PC: 0x06f2a8..0x06f3cc (292 B) | Symbol: sub_06f2a8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06f2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F2A8ULL;
}

// FDE #1403 | PC: 0x06f3cc..0x06f410 (68 B) | Symbol: sub_06f3cc
// EN: AArch64 prologue [cbz x2, #0x6f40c; adrp x8, #0x7e000; add x8, x8, #0x4e6; ldrb w9, [x1]] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x6f40c; adrp x8, #0x7e000; add x8, x8, #0x4e6; ldrb w9, [x1]]
uint64_t fde_sub_06f3cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000068ULL) << 32) | 0xB4000202ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F3CCULL;
}

// FDE #1404 | PC: 0x06f410..0x06f444 (52 B) | Symbol: sub_06f410
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x0, sp] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x0, sp]
uint64_t fde_sub_06f410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F410ULL;
}

// FDE #1405 | PC: 0x06f444..0x06f44c (8 B) | Symbol: sub_06f444
// EN: AArch64 prologue [stp xzr, xzr, [x0]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; ret]
uint64_t fde_sub_06f444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F444ULL;
}

// FDE #1406 | PC: 0x06f44c..0x06f4fc (176 B) | Symbol: sub_06f44c
// EN: AArch64 prologue [strb wzr, [x3]; cbz x1, #0x6f474; ldr x9, [x2, #8]; cbz x9, #0x6f47c] | VI: Khởi đầu hàm AArch64 [strb wzr, [x3]; cbz x1, #0x6f474; ldr x9, [x2, #8]; cbz x9, #0x6f47c]
uint64_t fde_sub_06f44c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000121ULL) << 32) | 0x3900007FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F44CULL;
}

// FDE #1407 | PC: 0x06f4fc..0x06f5b8 (188 B) | Symbol: sub_06f4fc
// EN: AArch64 prologue [cmp x0, x1; b.hs #0x6f5b0; ldrb w8, [x0]; lsr w9, w8, #6] | VI: Khởi đầu hàm AArch64 [cmp x0, x1; b.hs #0x6f5b0; ldrb w8, [x0]; lsr w9, w8, #6]
uint64_t fde_sub_06f4fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000582ULL) << 32) | 0xEB01001FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F4FCULL;
}

// FDE #1408 | PC: 0x06f5b8..0x06f5f0 (56 B) | Symbol: sub_06f5b8
// EN: AArch64 prologue [cmp x0, #0x40; b.hs #0x6f5c8; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [cmp x0, #0x40; b.hs #0x6f5c8; mov w0, #1; ret]
uint64_t fde_sub_06f5b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000062ULL) << 32) | 0xF101001FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F5B8ULL;
}

// FDE #1409 | PC: 0x06f5f0..0x06f6a8 (184 B) | Symbol: sub_06f5f0
// EN: AArch64 prologue [sub sp, sp, #0x10; cmp x1, #0x3f; b.hi #0x6f610; add x8, x0, #1] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x10; cmp x1, #0x3f; b.hi #0x6f610; add x8, x0, #1]
uint64_t fde_sub_06f5f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100FC3FULL) << 32) | 0xD10043FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F5F0ULL;
}

// FDE #1410 | PC: 0x06f6a8..0x06f744 (156 B) | Symbol: sub_06f6a8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06f6a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F6A8ULL;
}

// FDE #1411 | PC: 0x06f744..0x06f770 (44 B) | Symbol: sub_06f744
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06f744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F744ULL;
}

// FDE #1412 | PC: 0x06f770..0x06f7ec (124 B) | Symbol: sub_06f770
// EN: AArch64 prologue [cbz x0, #0x6f7d0; ldr x8, [x0, #0x10]; cmp x8, x1; b.ls #0x6f7d0] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x6f7d0; ldr x8, [x0, #0x10]; cmp x8, x1; b.ls #0x6f7d0]
uint64_t fde_sub_06f770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0xB4000300ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F770ULL;
}

// FDE #1413 | PC: 0x06f7ec..0x06f7f4 (8 B) | Symbol: sub_06f7ec
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; ret]
uint64_t fde_sub_06f7ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F7ECULL;
}

// FDE #1414 | PC: 0x06f7f4..0x06f804 (16 B) | Symbol: sub_06f7f4
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x10]; cmp x9, x8; cset w0, hs; ret] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x10]; cmp x9, x8; cset w0, hs; ret]
uint64_t fde_sub_06f7f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB08013FULL) << 32) | 0xA9412408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F7F4ULL;
}

// FDE #1415 | PC: 0x06f804..0x06f828 (36 B) | Symbol: sub_06f804
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; cbz x8, #0x6f820; ldr x8, [x0, #0x20]; ldp x9, x10, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; cbz x8, #0x6f820; ldr x8, [x0, #0x20]; ldp x9, x10, [x0]]
uint64_t fde_sub_06f804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000C8ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F804ULL;
}

// FDE #1416 | PC: 0x06f828..0x06f860 (56 B) | Symbol: sub_06f828
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x10]; cmp x8, x9; b.hs #0x6f858; ldp x9, x10, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x10]; cmp x8, x9; b.hs #0x6f858; ldp x9, x10, [x0, #0x20]]
uint64_t fde_sub_06f828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA9412009ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F828ULL;
}

// FDE #1417 | PC: 0x06f860..0x06f89c (60 B) | Symbol: sub_06f860
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x10]; cmp x8, x9; b.hs #0x6f894; ldp x9, x10, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x10]; cmp x8, x9; b.hs #0x6f894; ldp x9, x10, [x0, #0x20]]
uint64_t fde_sub_06f860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA9412009ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F860ULL;
}

// FDE #1418 | PC: 0x06f89c..0x06f8cc (48 B) | Symbol: sub_06f89c
// EN: AArch64 prologue [ldr x9, [x0, #0x18]; cbz x9, #0x6f8c4; mov x8, x0; ldp x10, x11, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x18]; cbz x9, #0x6f8c4; mov x8, x0; ldp x10, x11, [x8, #0x20]]
uint64_t fde_sub_06f89c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000129ULL) << 32) | 0xF9400C09ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F89CULL;
}

// FDE #1419 | PC: 0x06f8cc..0x06f8f0 (36 B) | Symbol: sub_06f8cc
// EN: AArch64 prologue [ldr x9, [x0, #0x18]; cbz x9, #0x6f8e8; mov x8, x0; mov w0, wzr] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x18]; cbz x9, #0x6f8e8; mov x8, x0; mov w0, wzr]
uint64_t fde_sub_06f8cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000C9ULL) << 32) | 0xF9400C09ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F8CCULL;
}

// FDE #1420 | PC: 0x06f8f0..0x06f914 (36 B) | Symbol: sub_06f8f0
// EN: AArch64 prologue [ldr x9, [x0, #0x18]; cmp x9, x1; b.ls #0x6f90c; mov x8, x0] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x18]; cmp x9, x1; b.ls #0x6f90c; mov x8, x0]
uint64_t fde_sub_06f8f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB01013FULL) << 32) | 0xF9400C09ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F8F0ULL;
}

// FDE #1421 | PC: 0x06f914..0x06fa1c (264 B) | Symbol: sub_06f914
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06f914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F914ULL;
}

// FDE #1422 | PC: 0x06fa1c..0x06fab4 (152 B) | Symbol: sub_06fa1c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06fa1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FA1CULL;
}

// FDE #1423 | PC: 0x06fab4..0x06fae0 (44 B) | Symbol: sub_06fab4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06fab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FAB4ULL;
}

// FDE #1424 | PC: 0x06fae0..0x06fca4 (452 B) | Symbol: sub_06fae0
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06fae0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FAE0ULL;
}

// FDE #1425 | PC: 0x06fca4..0x06fd64 (192 B) | Symbol: sub_06fca4
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06fca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FCA4ULL;
}

// FDE #1426 | PC: 0x06fd64..0x06fe2c (200 B) | Symbol: sub_06fd64
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06fd64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FD64ULL;
}

// FDE #1427 | PC: 0x06fe2c..0x06fe60 (52 B) | Symbol: sub_06fe2c
// EN: AArch64 prologue [ldr x9, [x0, #0x20]; cmp x9, x1; b.ne #0x6fe48; ldr x9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x20]; cmp x9, x1; b.ne #0x6fe48; ldr x9, [x0, #0x18]]
uint64_t fde_sub_06fe2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB01013FULL) << 32) | 0xF9401009ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FE2CULL;
}

// FDE #1428 | PC: 0x06fe60..0x06ff34 (212 B) | Symbol: sub_06fe60
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06fe60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FE60ULL;
}

// FDE #1429 | PC: 0x06ff34..0x07005c (296 B) | Symbol: sub_06ff34
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06ff34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FF34ULL;
}

// FDE #1430 | PC: 0x07005c..0x0700d8 (124 B) | Symbol: sub_07005c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07005c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07005CULL;
}

// FDE #1431 | PC: 0x0700d8..0x070194 (188 B) | Symbol: sub_0700d8
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0700d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0700D8ULL;
}

// FDE #1432 | PC: 0x070194..0x07025c (200 B) | Symbol: sub_070194
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_070194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070194ULL;
}

// FDE #1433 | PC: 0x07025c..0x0703a0 (324 B) | Symbol: sub_07025c
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_07025c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07025CULL;
}

// FDE #1434 | PC: 0x0703a0..0x070418 (120 B) | Symbol: sub_0703a0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_0703a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0703A0ULL;
}

// FDE #1435 | PC: 0x070418..0x0704a0 (136 B) | Symbol: sub_070418
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_070418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070418ULL;
}

// FDE #1436 | PC: 0x0704a0..0x0704ac (12 B) | Symbol: sub_0704a0
// EN: AArch64 prologue [stp xzr, xzr, [x0, #0x10]; strb wzr, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0, #0x10]; strb wzr, [x0, #0x20]; ret]
uint64_t fde_sub_0704a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3900801FULL) << 32) | 0xA9017C1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0704A0ULL;
}

// FDE #1437 | PC: 0x0704ac..0x0704e0 (52 B) | Symbol: sub_0704ac
// EN: AArch64 prologue [cbz x0, #0x704dc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x704dc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_0704ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000180ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0704ACULL;
}

// FDE #1438 | PC: 0x0704e0..0x0705c4 (228 B) | Symbol: sub_0704e0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0704e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0704E0ULL;
}

// FDE #1439 | PC: 0x0705c4..0x070610 (76 B) | Symbol: sub_0705c4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_0705c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0705C4ULL;
}

// FDE #1440 | PC: 0x070610..0x070628 (24 B) | Symbol: sub_070610
// EN: AArch64 prologue [ldr x8, [x0]; movi v0.2d, #0000000000000000; stp q0, q0, [x0]; strb wzr, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; movi v0.2d, #0000000000000000; stp q0, q0, [x0]; strb wzr, [x0, #0x20]]
uint64_t fde_sub_070610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070610ULL;
}

// FDE #1441 | PC: 0x070628..0x0706bc (148 B) | Symbol: sub_070628
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_070628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070628ULL;
}

// FDE #1442 | PC: 0x0706bc..0x070710 (84 B) | Symbol: sub_0706bc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x9, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x9, [x0]]
uint64_t fde_sub_0706bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0706BCULL;
}

// FDE #1443 | PC: 0x070710..0x0707a0 (144 B) | Symbol: sub_070710
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_070710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070710ULL;
}

// FDE #1444 | PC: 0x0707a0..0x0707f8 (88 B) | Symbol: sub_0707a0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0707a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0707A0ULL;
}

// FDE #1445 | PC: 0x0707f8..0x070800 (8 B) | Symbol: sub_0707f8
// EN: AArch64 prologue [mov w0, #0x60; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x60; ret]
uint64_t fde_sub_0707f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0707F8ULL;
}

// FDE #1446 | PC: 0x070800..0x070808 (8 B) | Symbol: sub_070800
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ret]
uint64_t fde_sub_070800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070800ULL;
}

// FDE #1447 | PC: 0x070808..0x07081c (20 B) | Symbol: sub_070808
// EN: AArch64 prologue [ldr w8, [x0]; str xzr, [x0, #0x48]; stp x8, x8, [x0, #0x10]; str x8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0]; str xzr, [x0, #0x48]; stp x8, x8, [x0, #0x10]; str x8, [x0, #0x28]]
uint64_t fde_sub_070808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900241FULL) << 32) | 0xB9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070808ULL;
}

// FDE #1448 | PC: 0x07081c..0x070830 (20 B) | Symbol: sub_07081c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; ldr x9, [x0, #0x30]; cmp x8, x9; cset w0, lo] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; ldr x9, [x0, #0x30]; cmp x8, x9; cset w0, lo]
uint64_t fde_sub_07081c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401809ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07081CULL;
}

// FDE #1449 | PC: 0x070830..0x070834 (4 B) | Symbol: sub_070830
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_070830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52967008ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070830ULL;
}

// FDE #1450 | PC: 0x070834..0x0708ac (120 B) | Symbol: sub_070834
// EN: AArch64 prologue [mov w8, #0xb380; mov w9, #0x1670; str x8, [x0, #8]; str w9, [x0]] | VI: Khởi đầu hàm AArch64 [mov w8, #0xb380; mov w9, #0x1670; str x8, [x0, #8]; str w9, [x0]]
uint64_t fde_sub_070834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5282CE09ULL) << 32) | 0x52967008ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070834ULL;
}

// FDE #1451 | PC: 0x0708ac..0x070930 (132 B) | Symbol: sub_0708ac
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x58]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x58]]
uint64_t fde_sub_0708ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0708ACULL;
}

// FDE #1452 | PC: 0x070930..0x070aa0 (368 B) | Symbol: sub_070930
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_070930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070930ULL;
}

// FDE #1453 | PC: 0x070aa0..0x070aa8 (8 B) | Symbol: sub_070aa0
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_070aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070AA0ULL;
}

// FDE #1454 | PC: 0x070aa8..0x070ab0 (8 B) | Symbol: sub_070aa8
// EN: AArch64 prologue [mov w0, #0x168; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x168; ret]
uint64_t fde_sub_070aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52802D00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070AA8ULL;
}

// FDE #1455 | PC: 0x070ab0..0x070b10 (96 B) | Symbol: sub_070ab0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w9, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w9, [x0]]
uint64_t fde_sub_070ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070AB0ULL;
}

// FDE #1456 | PC: 0x070b10..0x070b18 (8 B) | Symbol: sub_070b10
// EN: AArch64 prologue [ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_070b10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070B10ULL;
}

// FDE #1457 | PC: 0x070b18..0x070b8c (116 B) | Symbol: sub_070b18
// EN: AArch64 prologue [ldr w8, [x0, #0x100]; cmp w8, #1; b.eq #0x70b30; ldr w9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x100]; cmp w8, #1; b.eq #0x70b30; ldr w9, [x0]]
uint64_t fde_sub_070b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0xB9410008ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070B18ULL;
}

// FDE #1458 | PC: 0x070b8c..0x070b9c (16 B) | Symbol: sub_070b8c
// EN: AArch64 prologue [ldr w8, [x0]; cmp w8, #0; cset w0, eq; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0]; cmp w8, #0; cset w0, eq; ret]
uint64_t fde_sub_070b8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100011FULL) << 32) | 0xB9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070B8CULL;
}

// FDE #1459 | PC: 0x070b9c..0x070bac (16 B) | Symbol: sub_070b9c
// EN: AArch64 prologue [ldr x8, [x0, #0x108]; cmp x8, #0; cset w0, ne; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x108]; cmp x8, #0; cset w0, ne; ret]
uint64_t fde_sub_070b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100011FULL) << 32) | 0xF9408408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070B9CULL;
}

// FDE #1460 | PC: 0x070bac..0x070d84 (472 B) | Symbol: sub_070bac
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_070bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070BACULL;
}

// FDE #1461 | PC: 0x070d84..0x071ad0 (3404 B) | Symbol: sub_070d84
// EN: AArch64 prologue [str d8, [sp, #-0x30]!; str x21, [sp, #8]; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x30]!; str x21, [sp, #8]; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]]
uint64_t fde_sub_070d84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007F5ULL) << 32) | 0xFC1D0FE8ULL;
    const uint64_t kPcRange = 0x0D4CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070D84ULL;
}

// FDE #1462 | PC: 0x071ad0..0x071ce0 (528 B) | Symbol: sub_071ad0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_071ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071AD0ULL;
}

// FDE #1463 | PC: 0x071ce0..0x071d30 (80 B) | Symbol: sub_071ce0
// EN: AArch64 prologue [ldr x9, [x0, #0x10]; mov w8, #0x2710; cbz x9, #0x71cfc; mov w10, #0x7fffffff] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x10]; mov w8, #0x2710; cbz x9, #0x71cfc; mov w10, #0x7fffffff]
uint64_t fde_sub_071ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5284E208ULL) << 32) | 0xF9400809ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071CE0ULL;
}

// FDE #1464 | PC: 0x071d30..0x071d50 (32 B) | Symbol: sub_071d30
// EN: AArch64 prologue [ldrb w8, [x0, #0x161]; cbz w8, #0x71d48; ldrb w8, [x0, #0x138]; cbz w8, #0x71d48] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x161]; cbz w8, #0x71d48; ldrb w8, [x0, #0x138]; cbz w8, #0x71d48]
uint64_t fde_sub_071d30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000A8ULL) << 32) | 0x39458408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D30ULL;
}

// FDE #1465 | PC: 0x071d50..0x071d58 (8 B) | Symbol: sub_071d50
// EN: AArch64 prologue [ldr w0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0]; ret]
uint64_t fde_sub_071d50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D50ULL;
}

// FDE #1466 | PC: 0x071d58..0x071d60 (8 B) | Symbol: sub_071d58
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ret]
uint64_t fde_sub_071d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D58ULL;
}

// FDE #1467 | PC: 0x071d60..0x071d68 (8 B) | Symbol: sub_071d60
// EN: AArch64 prologue [ldrb w0, [x0, #0xee]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0xee]; ret]
uint64_t fde_sub_071d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3943B800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D60ULL;
}

// FDE #1468 | PC: 0x071d68..0x071d70 (8 B) | Symbol: sub_071d68
// EN: AArch64 prologue [ldrb w0, [x0, #0xb8]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0xb8]; ret]
uint64_t fde_sub_071d68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3942E000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D68ULL;
}

// FDE #1469 | PC: 0x071d70..0x071d78 (8 B) | Symbol: sub_071d70
// EN: AArch64 prologue [ldr w0, [x0, #0x100]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x100]; ret]
uint64_t fde_sub_071d70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9410000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D70ULL;
}

// FDE #1470 | PC: 0x071d78..0x071d80 (8 B) | Symbol: sub_071d78
// EN: AArch64 prologue [ldr x0, [x0, #0x108]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x108]; ret]
uint64_t fde_sub_071d78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9408400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D78ULL;
}

// FDE #1471 | PC: 0x071d80..0x071d88 (8 B) | Symbol: sub_071d80
// EN: AArch64 prologue [ldrb w0, [x0, #0x110]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x110]; ret]
uint64_t fde_sub_071d80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39444000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D80ULL;
}

// FDE #1472 | PC: 0x071d88..0x071d90 (8 B) | Symbol: sub_071d88
// EN: AArch64 prologue [ldrb w0, [x0, #0x64]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x64]; ret]
uint64_t fde_sub_071d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39419000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D88ULL;
}

// FDE #1473 | PC: 0x071d90..0x071d98 (8 B) | Symbol: sub_071d90
// EN: AArch64 prologue [ldr s0, [x0, #0x90]; ret] | VI: Khởi đầu hàm AArch64 [ldr s0, [x0, #0x90]; ret]
uint64_t fde_sub_071d90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xBD409000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D90ULL;
}

// FDE #1474 | PC: 0x071d98..0x071da0 (8 B) | Symbol: sub_071d98
// EN: AArch64 prologue [ldr s0, [x0, #0xa0]; ret] | VI: Khởi đầu hàm AArch64 [ldr s0, [x0, #0xa0]; ret]
uint64_t fde_sub_071d98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xBD40A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D98ULL;
}

// FDE #1475 | PC: 0x071da0..0x071e88 (232 B) | Symbol: sub_071da0
// EN: AArch64 prologue [ldr x8, [x0, #8]; cmp x8, x3; b.ls #0x71dc0; mov x8, x0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; cmp x8, x3; b.ls #0x71dc0; mov x8, x0]
uint64_t fde_sub_071da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB03011FULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071DA0ULL;
}

// FDE #1476 | PC: 0x071e88..0x071eb0 (40 B) | Symbol: sub_071e88
// EN: AArch64 prologue [ldr x8, [x0, #0x70]; movi v0.2d, #0000000000000000; stp q0, q0, [x0, #0x60]; stp q0, q0, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x70]; movi v0.2d, #0000000000000000; stp q0, q0, [x0, #0x60]; stp q0, q0, [x0]]
uint64_t fde_sub_071e88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0xF9403808ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071E88ULL;
}

// FDE #1477 | PC: 0x071eb0..0x071f7c (204 B) | Symbol: sub_071eb0
// EN: AArch64 prologue [ldr x8, [x0, #0x48]; cbz x8, #0x71f38; ldr x8, [x1, #0x3e0]; ldr w9, [x1, #0x3d8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x48]; cbz x8, #0x71f38; ldr x8, [x1, #0x3e0]; ldr w9, [x1, #0x3d8]]
uint64_t fde_sub_071eb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000428ULL) << 32) | 0xF9402408ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071EB0ULL;
}

// FDE #1478 | PC: 0x071f7c..0x072048 (204 B) | Symbol: sub_071f7c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_071f7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071F7CULL;
}

// FDE #1479 | PC: 0x072048..0x072160 (280 B) | Symbol: sub_072048
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #0x3a8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #0x3a8]]
uint64_t fde_sub_072048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072048ULL;
}

// FDE #1480 | PC: 0x072160..0x0721b0 (80 B) | Symbol: sub_072160
// EN: AArch64 prologue [ldr w8, [x1, #0x380]; cbz w8, #0x72170; ldr q0, [x1, #0x3f0]; b #0x7217c] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x380]; cbz w8, #0x72170; ldr q0, [x1, #0x3f0]; b #0x7217c]
uint64_t fde_sub_072160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000068ULL) << 32) | 0xB9438028ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072160ULL;
}

// FDE #1481 | PC: 0x0721b0..0x0721bc (12 B) | Symbol: sub_0721b0
// EN: AArch64 prologue [stp xzr, xzr, [x0, #8]; str x1, [x0]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0, #8]; str x1, [x0]; ret]
uint64_t fde_sub_0721b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000001ULL) << 32) | 0xA900FC1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0721B0ULL;
}

// FDE #1482 | PC: 0x0721bc..0x0722b0 (244 B) | Symbol: sub_0721bc
// EN: AArch64 prologue [ldr x8, [x0]; cbnz x8, #0x721cc; mov w8, #8; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; cbnz x8, #0x721cc; mov w8, #8; str x8, [x0]]
uint64_t fde_sub_0721bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB5000068ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0721BCULL;
}

// FDE #1483 | PC: 0x0722b0..0x0722f4 (68 B) | Symbol: sub_0722b0
// EN: AArch64 prologue [mov w8, #-1; lsl w8, w8, w1; mvn w8, w8; sxtw x8, w8] | VI: Khởi đầu hàm AArch64 [mov w8, #-1; lsl w8, w8, w1; mvn w8, w8; sxtw x8, w8]
uint64_t fde_sub_0722b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1AC12108ULL) << 32) | 0x12800008ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0722B0ULL;
}

// FDE #1484 | PC: 0x0722f4..0x07235c (104 B) | Symbol: sub_0722f4
// EN: AArch64 prologue [mov w8, #-1; ldrb w9, [x0]; lsl w10, w8, w2; mvn w8, w10] | VI: Khởi đầu hàm AArch64 [mov w8, #-1; ldrb w9, [x0]; lsl w10, w8, w2; mvn w8, w10]
uint64_t fde_sub_0722f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0x12800008ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0722F4ULL;
}

// FDE #1485 | PC: 0x07235c..0x072398 (60 B) | Symbol: sub_07235c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_07235c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07235CULL;
}

// FDE #1486 | PC: 0x072398..0x0723cc (52 B) | Symbol: sub_072398
// EN: AArch64 prologue [cbz x0, #0x723c8; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x723c8; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_072398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000180ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072398ULL;
}

// FDE #1487 | PC: 0x0723cc..0x072454 (136 B) | Symbol: sub_0723cc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_0723cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0723CCULL;
}

// FDE #1488 | PC: 0x072454..0x0726c4 (624 B) | Symbol: sub_072454
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_072454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0270ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072454ULL;
}

// FDE #1489 | PC: 0x0726c4..0x0727fc (312 B) | Symbol: sub_0726c4
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0726c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0726C4ULL;
}

// FDE #1490 | PC: 0x0727fc..0x072a68 (620 B) | Symbol: sub_0727fc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0727fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x026CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0727FCULL;
}

// FDE #1491 | PC: 0x072a68..0x072bf4 (396 B) | Symbol: sub_072a68
// EN: AArch64 prologue [cbz x0, #0x72bf0; str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x72bf0; str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]]
uint64_t fde_sub_072a68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0xB4000C40ULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072A68ULL;
}

// FDE #1492 | PC: 0x072bf4..0x072ccc (216 B) | Symbol: sub_072bf4
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_072bf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072BF4ULL;
}

// FDE #1493 | PC: 0x072ccc..0x072e14 (328 B) | Symbol: sub_072ccc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_072ccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072CCCULL;
}

// FDE #1494 | PC: 0x072e14..0x072f74 (352 B) | Symbol: sub_072e14
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_072e14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072E14ULL;
}

// FDE #1495 | PC: 0x072f74..0x0730e8 (372 B) | Symbol: sub_072f74
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_072f74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072F74ULL;
}

// FDE #1496 | PC: 0x0730e8..0x07325c (372 B) | Symbol: sub_0730e8
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_0730e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0730E8ULL;
}

// FDE #1497 | PC: 0x07325c..0x073530 (724 B) | Symbol: sub_07325c
// EN: AArch64 prologue [sub sp, sp, #0x130; stp x28, x27, [sp, #0xd0]; stp x26, x25, [sp, #0xe0]; stp x24, x23, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; stp x28, x27, [sp, #0xd0]; stp x26, x25, [sp, #0xe0]; stp x24, x23, [sp, #0xf0]]
uint64_t fde_sub_07325c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D6FFCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x02D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07325CULL;
}

// FDE #1498 | PC: 0x073530..0x0735f0 (192 B) | Symbol: sub_073530
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_073530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073530ULL;
}

// FDE #1499 | PC: 0x0735f0..0x073658 (104 B) | Symbol: sub_0735f0
// EN: AArch64 prologue [ldr w8, [x0, #0x170]; mov w9, #0x38; cmp w1, #0; add x11, x0, #0x148] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x170]; mov w9, #0x38; cmp w1, #0; add x11, x0, #0x148]
uint64_t fde_sub_0735f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800709ULL) << 32) | 0xB9417008ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0735F0ULL;
}

// FDE #1500 | PC: 0x073658..0x07374c (244 B) | Symbol: sub_073658
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_073658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90467FAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073658ULL;
}

// FDE #1501 | PC: 0x07374c..0x073754 (8 B) | Symbol: sub_07374c
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; ret]
uint64_t fde_sub_07374c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07374CULL;
}

// FDE #1502 | PC: 0x073754..0x0739d4 (640 B) | Symbol: sub_073754
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]; stp x22, x21, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]; stp x22, x21, [sp, #0xf0]]
uint64_t fde_sub_073754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D67FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0280ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073754ULL;
}

// FDE #1503 | PC: 0x0739d4..0x073ab8 (228 B) | Symbol: sub_0739d4
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0739d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0739D4ULL;
}

// FDE #1504 | PC: 0x073ab8..0x073b78 (192 B) | Symbol: sub_073ab8
// EN: AArch64 prologue [sub sp, sp, #0x90; str x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_073ab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BFBULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073AB8ULL;
}

// FDE #1505 | PC: 0x073b78..0x073be8 (112 B) | Symbol: sub_073b78
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_073b78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073B78ULL;
}

// FDE #1506 | PC: 0x073be8..0x073c20 (56 B) | Symbol: sub_073be8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x5; mov x5, x4] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x5; mov x5, x4]
uint64_t fde_sub_073be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073BE8ULL;
}

// FDE #1507 | PC: 0x073c20..0x073c5c (60 B) | Symbol: sub_073c20
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_073c20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073C20ULL;
}

// FDE #1508 | PC: 0x073c5c..0x073c68 (12 B) | Symbol: sub_073c5c
// EN: AArch64 prologue [cbz x0, #0x73c64; b #0xfa50; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x73c64; b #0xfa50; ret]
uint64_t fde_sub_073c5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE6F7CULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073C5CULL;
}

// FDE #1509 | PC: 0x073c68..0x073cc0 (88 B) | Symbol: sub_073c68
// EN: AArch64 prologue [cbz x1, #0x73cb8; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x73cb8; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_073c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xB4000281ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073C68ULL;
}

// FDE #1510 | PC: 0x073cc0..0x073d18 (88 B) | Symbol: sub_073cc0
// EN: AArch64 prologue [cbz x1, #0x73d10; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x73d10; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_073cc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xB4000281ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073CC0ULL;
}

// FDE #1511 | PC: 0x073d18..0x073d7c (100 B) | Symbol: sub_073d18
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_073d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073D18ULL;
}

// FDE #1512 | PC: 0x073d7c..0x073d88 (12 B) | Symbol: sub_073d7c
// EN: AArch64 prologue [cbz x0, #0x73d84; b #0xf240; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x73d84; b #0xf240; ret]
uint64_t fde_sub_073d7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE6D30ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073D7CULL;
}

// FDE #1513 | PC: 0x073d88..0x073e90 (264 B) | Symbol: sub_073d88
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_073d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073D88ULL;
}

// FDE #1514 | PC: 0x073e90..0x073f00 (112 B) | Symbol: sub_073e90
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x29, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x29, #0x10]]
uint64_t fde_sub_073e90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073E90ULL;
}

// FDE #1515 | PC: 0x073f00..0x073f98 (152 B) | Symbol: sub_073f00
// EN: AArch64 prologue [cbz x1, #0x73f90; adrp x8, #0x9b000; ldr x8, [x8, #0xe78]; cmp x1, #1] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x73f90; adrp x8, #0x9b000; ldr x8, [x8, #0xe78]; cmp x1, #1]
uint64_t fde_sub_073f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000148ULL) << 32) | 0xB4000481ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F00ULL;
}

// FDE #1516 | PC: 0x073f98..0x074120 (392 B) | Symbol: sub_073f98
// EN: AArch64 prologue [cbz x2, #0x7411c; adrp x8, #0x9b000; ldr x8, [x8, #0xe78]; mov w9, #8] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x7411c; adrp x8, #0x9b000; ldr x8, [x8, #0xe78]; mov w9, #8]
uint64_t fde_sub_073f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000148ULL) << 32) | 0xB4000C22ULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F98ULL;
}

// FDE #1517 | PC: 0x074120..0x074134 (20 B) | Symbol: sub_074120
// EN: AArch64 prologue [mov w8, #0x100; movk w8, #1, lsl #16; str w8, [x0]; strb wzr, [x0, #4]] | VI: Khởi đầu hàm AArch64 [mov w8, #0x100; movk w8, #1, lsl #16; str w8, [x0]; strb wzr, [x0, #4]]
uint64_t fde_sub_074120(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A00028ULL) << 32) | 0x52802008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074120ULL;
}

// FDE #1518 | PC: 0x074134..0x0742b8 (388 B) | Symbol: sub_074134
// EN: AArch64 prologue [adrp x13, #0x9b000; ldr x13, [x13, #0xea8]; add x10, x3, x4; add x11, x1, x2] | VI: Khởi đầu hàm AArch64 [adrp x13, #0x9b000; ldr x13, [x13, #0xea8]; add x10, x3, x4; add x11, x1, x2]
uint64_t fde_sub_074134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94755ADULL) << 32) | 0xF000012DULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074134ULL;
}

// FDE #1519 | PC: 0x0742b8..0x07439c (228 B) | Symbol: sub_0742b8
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x110]; stp x26, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x110]; stp x26, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]]
uint64_t fde_sub_0742b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9008BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0742B8ULL;
}

// FDE #1520 | PC: 0x07439c..0x0743d0 (52 B) | Symbol: sub_07439c
// EN: AArch64 prologue [adrp x9, #0x74000; add x9, x9, #0x3d0; adrp x10, #0x74000; mov w8, #1] | VI: Khởi đầu hàm AArch64 [adrp x9, #0x74000; add x9, x9, #0x3d0; adrp x10, #0x74000; mov w8, #1]
uint64_t fde_sub_07439c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910F4129ULL) << 32) | 0x90000009ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07439CULL;
}

// FDE #1521 | PC: 0x0743d0..0x07441c (76 B) | Symbol: sub_0743d0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x18]; add x8, x8, x6] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x18]; add x8, x8, x6]
uint64_t fde_sub_0743d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0743D0ULL;
}

// FDE #1522 | PC: 0x07441c..0x074468 (76 B) | Symbol: sub_07441c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x18]; sub x8, x6, x8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x18]; sub x8, x6, x8]
uint64_t fde_sub_07441c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07441CULL;
}

// FDE #1523 | PC: 0x074468..0x074488 (32 B) | Symbol: sub_074468
// EN: AArch64 prologue [mov w8, #1; adrp x9, #0x74000; add x9, x9, #0x488; dup v0.2d, x8] | VI: Khởi đầu hàm AArch64 [mov w8, #1; adrp x9, #0x74000; add x9, x9, #0x488; dup v0.2d, x8]
uint64_t fde_sub_074468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000009ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074468ULL;
}

// FDE #1524 | PC: 0x074488..0x0744cc (68 B) | Symbol: sub_074488
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cmp x6, x3; str x6, [x4]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cmp x6, x3; str x6, [x4]]
uint64_t fde_sub_074488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074488ULL;
}

// FDE #1525 | PC: 0x0744cc..0x0746f4 (552 B) | Symbol: sub_0744cc
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0744cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0228ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0744CCULL;
}

// FDE #1526 | PC: 0x0746f4..0x074710 (28 B) | Symbol: sub_0746f4
// EN: AArch64 prologue [cbz x0, #0x74708; adrp x8, #0x9d000; ldr x1, [x8, #0xde0]; cbz x1, #0x7470c] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x74708; adrp x8, #0x9d000; ldr x1, [x8, #0xde0]; cbz x1, #0x7470c]
uint64_t fde_sub_0746f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000148ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0746F4ULL;
}

// FDE #1527 | PC: 0x074710..0x074724 (20 B) | Symbol: sub_074710
// EN: AArch64 prologue [adrp x8, #0x9d000; ldr x1, [x8, #0xdf0]; cbz x1, #0x74720; br x1] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; ldr x1, [x8, #0xdf0]; cbz x1, #0x74720; br x1]
uint64_t fde_sub_074710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF946F901ULL) << 32) | 0xB0000148ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074710ULL;
}

// FDE #1528 | PC: 0x074724..0x074738 (20 B) | Symbol: sub_074724
// EN: AArch64 prologue [adrp x8, #0x9d000; ldr x2, [x8, #0xde8]; cbz x2, #0x74734; br x2] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; ldr x2, [x8, #0xde8]; cbz x2, #0x74734; br x2]
uint64_t fde_sub_074724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF946F502ULL) << 32) | 0xB0000148ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074724ULL;
}

// FDE #1529 | PC: 0x074738..0x074e90 (1880 B) | Symbol: sub_074738
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]]
uint64_t fde_sub_074738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9076FFCULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0758ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074738ULL;
}

// FDE #1530 | PC: 0x074e90..0x074fdc (332 B) | Symbol: sub_074e90
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_074e90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074E90ULL;
}

// FDE #1531 | PC: 0x074fdc..0x07506c (144 B) | Symbol: sub_074fdc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, xzr] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, xzr]
uint64_t fde_sub_074fdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074FDCULL;
}

// FDE #1532 | PC: 0x07506c..0x075074 (8 B) | Symbol: sub_07506c
// EN: AArch64 prologue [mov w1, #1; b #0x751f8] | VI: Khởi đầu hàm AArch64 [mov w1, #1; b #0x751f8]
uint64_t fde_sub_07506c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000062ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07506CULL;
}

// FDE #1533 | PC: 0x075074..0x0751f8 (388 B) | Symbol: sub_075074
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_075074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075074ULL;
}

// FDE #1534 | PC: 0x0751f8..0x0756b4 (1212 B) | Symbol: sub_0751f8
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0751f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x04BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0751F8ULL;
}

// FDE #1535 | PC: 0x0756b4..0x075a58 (932 B) | Symbol: sub_0756b4
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0756b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x03A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0756B4ULL;
}

// FDE #1536 | PC: 0x075a58..0x075b58 (256 B) | Symbol: sub_075a58
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_075a58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075A58ULL;
}

// FDE #1537 | PC: 0x075b58..0x0764c8 (2416 B) | Symbol: sub_075b58
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_075b58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0970ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075B58ULL;
}

// FDE #1538 | PC: 0x0764c8..0x0765a8 (224 B) | Symbol: sub_0764c8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x280]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x280]]
uint64_t fde_sub_0764c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0764C8ULL;
}

// FDE #1539 | PC: 0x0765a8..0x076928 (896 B) | Symbol: sub_0765a8
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0765a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0380ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0765A8ULL;
}

// FDE #1540 | PC: 0x076928..0x076a48 (288 B) | Symbol: sub_076928
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_076928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076928ULL;
}

// FDE #1541 | PC: 0x076a48..0x0771cc (1924 B) | Symbol: sub_076a48
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]]
uint64_t fde_sub_076a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9096FFCULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x0784ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076A48ULL;
}

// FDE #1542 | PC: 0x0771cc..0x0772a4 (216 B) | Symbol: sub_0771cc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0771cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0771CCULL;
}

// FDE #1543 | PC: 0x0772a4..0x0773f0 (332 B) | Symbol: sub_0772a4
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0772a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0772A4ULL;
}

// FDE #1544 | PC: 0x0773f0..0x0774a0 (176 B) | Symbol: sub_0773f0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0773f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0773F0ULL;
}

// FDE #1545 | PC: 0x0774a0..0x077530 (144 B) | Symbol: sub_0774a0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0774a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0774A0ULL;
}

// FDE #1546 | PC: 0x077530..0x07759c (108 B) | Symbol: sub_077530
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_077530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077530ULL;
}

// FDE #1547 | PC: 0x07759c..0x07769c (256 B) | Symbol: sub_07759c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07759c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07759CULL;
}

// FDE #1548 | PC: 0x07769c..0x077798 (252 B) | Symbol: sub_07769c
// EN: AArch64 prologue [ldrsh w8, [x1, #0x10]; cbnz w2, #0x776b0; tbz w8, #6, #0x776b0; mov w0, wzr] | VI: Khởi đầu hàm AArch64 [ldrsh w8, [x1, #0x10]; cbnz w2, #0x776b0; tbz w8, #6, #0x776b0; mov w0, wzr]
uint64_t fde_sub_07769c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x35000082ULL) << 32) | 0x79C02028ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07769CULL;
}

// FDE #1549 | PC: 0x077798..0x07790c (372 B) | Symbol: sub_077798
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_077798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077798ULL;
}

// FDE #1550 | PC: 0x07790c..0x077984 (120 B) | Symbol: sub_07790c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07790c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07790CULL;
}

// FDE #1551 | PC: 0x077984..0x077b88 (516 B) | Symbol: sub_077984
// EN: AArch64 prologue [ldrh w8, [x1, #0x10]; ldr w9, [x0, #0xd0]; mov w10, #1; mov w11, #0x50000000] | VI: Khởi đầu hàm AArch64 [ldrh w8, [x1, #0x10]; ldr w9, [x0, #0xd0]; mov w10, #1; mov w11, #0x50000000]
uint64_t fde_sub_077984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940D009ULL) << 32) | 0x79402028ULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077984ULL;
}

// FDE #1552 | PC: 0x077b88..0x077cc8 (320 B) | Symbol: sub_077b88
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_077b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077B88ULL;
}

// FDE #1553 | PC: 0x077cc8..0x077d4c (132 B) | Symbol: sub_077cc8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0x9d000]
uint64_t fde_sub_077cc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077CC8ULL;
}

// FDE #1554 | PC: 0x077d4c..0x077e8c (320 B) | Symbol: sub_077d4c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_077d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077D4CULL;
}

// FDE #1555 | PC: 0x077e8c..0x078614 (1928 B) | Symbol: sub_077e8c
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_077e8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0788ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077E8CULL;
}

// FDE #1556 | PC: 0x078614..0x07866c (88 B) | Symbol: sub_078614
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_078614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078614ULL;
}

// FDE #1557 | PC: 0x07866c..0x07870c (160 B) | Symbol: sub_07866c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07866c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07866CULL;
}

// FDE #1558 | PC: 0x07870c..0x07877c (112 B) | Symbol: sub_07870c
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07870c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07870CULL;
}

// FDE #1559 | PC: 0x07877c..0x078830 (180 B) | Symbol: sub_07877c
// EN: AArch64 prologue [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07877c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57FCULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07877CULL;
}

// FDE #1560 | PC: 0x078830..0x07883c (12 B) | Symbol: sub_078830
// EN: AArch64 prologue [str wzr, [x0, #8]; str xzr, [x0]; ret] | VI: Khởi đầu hàm AArch64 [str wzr, [x0, #8]; str xzr, [x0]; ret]
uint64_t fde_sub_078830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900001FULL) << 32) | 0xB900081FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078830ULL;
}

// FDE #1561 | PC: 0x07883c..0x078848 (12 B) | Symbol: sub_07883c
// EN: AArch64 prologue [str wzr, [x0, #8]; str xzr, [x0]; ret] | VI: Khởi đầu hàm AArch64 [str wzr, [x0, #8]; str xzr, [x0]; ret]
uint64_t fde_sub_07883c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900001FULL) << 32) | 0xB900081FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07883CULL;
}

// FDE #1562 | PC: 0x078848..0x0788c0 (120 B) | Symbol: sub_078848
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_078848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078848ULL;
}

// FDE #1563 | PC: 0x0788c0..0x078938 (120 B) | Symbol: sub_0788c0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0788c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0788C0ULL;
}

// FDE #1564 | PC: 0x078938..0x078bac (628 B) | Symbol: sub_078938
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_078938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0274ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078938ULL;
}

// FDE #1565 | PC: 0x078bac..0x078cd0 (292 B) | Symbol: sub_078bac
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_078bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078BACULL;
}

// FDE #1566 | PC: 0x078cd0..0x078d5c (140 B) | Symbol: sub_078cd0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_078cd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078CD0ULL;
}

// FDE #1567 | PC: 0x078d5c..0x078ec4 (360 B) | Symbol: sub_078d5c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_078d5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078D5CULL;
}

// FDE #1568 | PC: 0x078ec4..0x078f44 (128 B) | Symbol: sub_078ec4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; tbnz w1, #0x1f, #0x78f38; ldr w8, [x0, #0x140]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; tbnz w1, #0x1f, #0x78f38; ldr w8, [x0, #0x140]]
uint64_t fde_sub_078ec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078EC4ULL;
}

// FDE #1569 | PC: 0x078f44..0x078f9c (88 B) | Symbol: sub_078f44
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; tbnz w1, #0x1f, #0x78f90] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; tbnz w1, #0x1f, #0x78f90]
uint64_t fde_sub_078f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078F44ULL;
}

// FDE #1570 | PC: 0x078f9c..0x078fb4 (24 B) | Symbol: sub_078f9c
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, w1, sxtw #3]; add x9, x8, #0x10; cmp x8, #0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, w1, sxtw #3]; add x9, x8, #0x10; cmp x8, #0]
uint64_t fde_sub_078f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF861D908ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078F9CULL;
}

// FDE #1571 | PC: 0x078fb4..0x079088 (212 B) | Symbol: sub_078fb4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_078fb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078FB4ULL;
}

// FDE #1572 | PC: 0x079088..0x079090 (8 B) | Symbol: sub_079088
// EN: AArch64 prologue [stp xzr, xzr, [x0]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; ret]
uint64_t fde_sub_079088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079088ULL;
}

// FDE #1573 | PC: 0x079090..0x0790f8 (104 B) | Symbol: sub_079090
// EN: AArch64 prologue [ldr w8, [x0, #8]; cmp w8, #1; b.lt #0x790f0; mov x8, xzr] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #8]; cmp w8, #1; b.lt #0x790f0; mov x8, xzr]
uint64_t fde_sub_079090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0xB9400808ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079090ULL;
}

// FDE #1574 | PC: 0x0790f8..0x079124 (44 B) | Symbol: sub_0790f8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0790f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0790F8ULL;
}

// FDE #1575 | PC: 0x079124..0x07921c (248 B) | Symbol: sub_079124
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_079124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079124ULL;
}

// FDE #1576 | PC: 0x07921c..0x079348 (300 B) | Symbol: sub_07921c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_07921c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07921CULL;
}

// FDE #1577 | PC: 0x079348..0x079358 (16 B) | Symbol: sub_079348
// EN: AArch64 prologue [adrp x8, #0x9b000; ldr x8, [x8, #0xdb8]; str x0, [x8]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; ldr x8, [x8, #0xdb8]; str x0, [x8]; ret]
uint64_t fde_sub_079348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF946DD08ULL) << 32) | 0xD0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079348ULL;
}

// FDE #1578 | PC: 0x079358..0x0794b8 (352 B) | Symbol: sub_079358
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_079358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079358ULL;
}

// FDE #1579 | PC: 0x0794b8..0x07962c (372 B) | Symbol: sub_0794b8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_0794b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0794B8ULL;
}

// FDE #1580 | PC: 0x07962c..0x0797e4 (440 B) | Symbol: sub_07962c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07962c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07962CULL;
}

// FDE #1581 | PC: 0x0797e4..0x0797e8 (4 B) | Symbol: sub_0797e4
// EN: AArch64 prologue [b #0xebc0] | VI: Khởi đầu hàm AArch64 [b #0xebc0]
uint64_t fde_sub_0797e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FE54F7ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0797E4ULL;
}

// FDE #1582 | PC: 0x0797e8..0x079860 (120 B) | Symbol: sub_0797e8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #1]
uint64_t fde_sub_0797e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0797E8ULL;
}

// FDE #1583 | PC: 0x079860..0x079868 (8 B) | Symbol: sub_079860
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_079860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079860ULL;
}

// FDE #1584 | PC: 0x079868..0x079930 (200 B) | Symbol: sub_079868
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]; stp x29, x30, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]; stp x29, x30, [sp, #0x140]]
uint64_t fde_sub_079868(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91257FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079868ULL;
}

// FDE #1585 | PC: 0x079930..0x0799b0 (128 B) | Symbol: sub_079930
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_079930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079930ULL;
}

// FDE #1586 | PC: 0x0799b0..0x0799c4 (20 B) | Symbol: sub_0799b0
// EN: AArch64 prologue [adrp x9, #0x82000; and x8, x0, #0xff; add x9, x9, #0xb31; ldrb w0, [x9, x8]] | VI: Khởi đầu hàm AArch64 [adrp x9, #0x82000; and x8, x0, #0xff; add x9, x9, #0xb31; ldrb w0, [x9, x8]]
uint64_t fde_sub_0799b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92401C08ULL) << 32) | 0xB0000049ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0799B0ULL;
}

// FDE #1587 | PC: 0x0799c4..0x079a1c (88 B) | Symbol: sub_0799c4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0799c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0799C4ULL;
}

// FDE #1588 | PC: 0x079a1c..0x079a6c (80 B) | Symbol: sub_079a1c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_079a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079A1CULL;
}

// FDE #1589 | PC: 0x079a6c..0x079aa4 (56 B) | Symbol: sub_079a6c
// EN: AArch64 prologue [ldr w9, [x0]; mov w8, #0x7fffffff; mov w11, #0x4e6d; sdiv w10, w8, w1] | VI: Khởi đầu hàm AArch64 [ldr w9, [x0]; mov w8, #0x7fffffff; mov w11, #0x4e6d; sdiv w10, w8, w1]
uint64_t fde_sub_079a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12B00008ULL) << 32) | 0xB9400009ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079A6CULL;
}

// FDE #1590 | PC: 0x079aa4..0x079c40 (412 B) | Symbol: sub_079aa4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x800] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x800]
uint64_t fde_sub_079aa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079AA4ULL;
}

// FDE #1591 | PC: 0x079c40..0x079cf0 (176 B) | Symbol: sub_079c40
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_079c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079C40ULL;
}

// FDE #1592 | PC: 0x079cf0..0x079cf8 (8 B) | Symbol: sub_079cf0
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_079cf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079CF0ULL;
}

// FDE #1593 | PC: 0x079cf8..0x079d64 (108 B) | Symbol: sub_079cf8
// EN: AArch64 prologue [ldr x8, [x0, #8]; mov w9, #0x4240; movk w9, #0xf, lsl #16; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; mov w9, #0x4240; movk w9, #0xf, lsl #16; cmp x8, x9]
uint64_t fde_sub_079cf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52884809ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079CF8ULL;
}

// FDE #1594 | PC: 0x079d64..0x079df4 (144 B) | Symbol: sub_079d64
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_079d64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079D64ULL;
}

// FDE #1595 | PC: 0x079df4..0x079f80 (396 B) | Symbol: sub_079df4
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_079df4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079DF4ULL;
}

// FDE #1596 | PC: 0x079f80..0x07a00c (140 B) | Symbol: sub_079f80
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0xf0]; stp x20, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0xf0]; stp x20, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]]
uint64_t fde_sub_079f80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9007BFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079F80ULL;
}

// FDE #1597 | PC: 0x07a00c..0x07a140 (308 B) | Symbol: sub_07a00c
// EN: AArch64 prologue [str x28, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_07a00c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FFCULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A00CULL;
}

// FDE #1598 | PC: 0x07a140..0x07a180 (64 B) | Symbol: sub_07a140
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000]
uint64_t fde_sub_07a140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A140ULL;
}

// FDE #1599 | PC: 0x07a180..0x07a2dc (348 B) | Symbol: sub_07a180
// EN: AArch64 prologue [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07a180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57FCULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A180ULL;
}

// FDE #1600 | PC: 0x07a2dc..0x07a368 (140 B) | Symbol: sub_07a2dc
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0xf0]; stp x20, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0xf0]; stp x20, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]]
uint64_t fde_sub_07a2dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9007BFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A2DCULL;
}

// FDE #1601 | PC: 0x07a368..0x07a4c0 (344 B) | Symbol: sub_07a368
// EN: AArch64 prologue [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07a368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57FCULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A368ULL;
}

// FDE #1602 | PC: 0x07a4c0..0x07a53c (124 B) | Symbol: sub_07a4c0
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_07a4c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A4C0ULL;
}

// FDE #1603 | PC: 0x07a53c..0x07a648 (268 B) | Symbol: sub_07a53c
// EN: AArch64 prologue [stp x28, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub sp, sp, #0x530] | VI: Khởi đầu hàm AArch64 [stp x28, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub sp, sp, #0x530]
uint64_t fde_sub_07a53c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FFCULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A53CULL;
}

// FDE #1604 | PC: 0x07a648..0x07a754 (268 B) | Symbol: sub_07a648
// EN: AArch64 prologue [stp x28, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub sp, sp, #0x530] | VI: Khởi đầu hàm AArch64 [stp x28, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub sp, sp, #0x530]
uint64_t fde_sub_07a648(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FFCULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A648ULL;
}

// FDE #1605 | PC: 0x07a754..0x07a870 (284 B) | Symbol: sub_07a754
// EN: AArch64 prologue [stp x28, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub sp, sp, #0x530] | VI: Khởi đầu hàm AArch64 [stp x28, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub sp, sp, #0x530]
uint64_t fde_sub_07a754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FFCULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A754ULL;
}

// FDE #1606 | PC: 0x07a870..0x07a8f4 (132 B) | Symbol: sub_07a870
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07a870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A870ULL;
}

// FDE #1607 | PC: 0x07a8f4..0x07a99c (168 B) | Symbol: sub_07a8f4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_07a8f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A8F4ULL;
}

// FDE #1608 | PC: 0x07a99c..0x07ab34 (408 B) | Symbol: sub_07a99c
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x23, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x23, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]]
uint64_t fde_sub_07a99c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9115FFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A99CULL;
}

// FDE #1609 | PC: 0x07ab34..0x07acb4 (384 B) | Symbol: sub_07ab34
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_07ab34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035FF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0180ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AB34ULL;
}

// FDE #1610 | PC: 0x07acb4..0x07ae18 (356 B) | Symbol: sub_07acb4
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07acb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07ACB4ULL;
}

// FDE #1611 | PC: 0x07ae18..0x07ae7c (100 B) | Symbol: sub_07ae18
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x19, #0x9e000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x19, #0x9e000]
uint64_t fde_sub_07ae18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AE18ULL;
}

// FDE #1612 | PC: 0x07ae7c..0x07aff0 (372 B) | Symbol: sub_07ae7c
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_07ae7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AE7CULL;
}

// FDE #1613 | PC: 0x07aff0..0x07b0f0 (256 B) | Symbol: sub_07aff0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07aff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AFF0ULL;
}

// FDE #1614 | PC: 0x07b0f0..0x07b170 (128 B) | Symbol: sub_07b0f0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07b0f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B0F0ULL;
}

// FDE #1615 | PC: 0x07b170..0x07b1e4 (116 B) | Symbol: sub_07b170
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_07b170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B170ULL;
}

// FDE #1616 | PC: 0x07b1e4..0x07b2a8 (196 B) | Symbol: sub_07b1e4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07b1e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B1E4ULL;
}

// FDE #1617 | PC: 0x07b2a8..0x07b30c (100 B) | Symbol: sub_07b2a8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07b2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B2A8ULL;
}

// FDE #1618 | PC: 0x07b30c..0x07b4cc (448 B) | Symbol: sub_07b30c
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_07b30c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B30CULL;
}

// FDE #1619 | PC: 0x07b4cc..0x07b4f0 (36 B) | Symbol: sub_07b4cc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_07b4cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B4CCULL;
}

// FDE #1620 | PC: 0x07b4f0..0x07b5ac (188 B) | Symbol: sub_07b4f0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_07b4f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B4F0ULL;
}

// FDE #1621 | PC: 0x07b5ac..0x07b608 (92 B) | Symbol: sub_07b5ac
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_07b5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B5ACULL;
}

// FDE #1622 | PC: 0x07b608..0x07b650 (72 B) | Symbol: sub_07b608
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_07b608(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B608ULL;
}

// FDE #1623 | PC: 0x07b650..0x07b774 (292 B) | Symbol: sub_07b650
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_07b650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B650ULL;
}

// FDE #1624 | PC: 0x07b774..0x07b880 (268 B) | Symbol: sub_07b774
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sxth w8, w3] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sxth w8, w3]
uint64_t fde_sub_07b774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B774ULL;
}

// FDE #1625 | PC: 0x07b880..0x07ba6c (492 B) | Symbol: sub_07b880
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_07b880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B880ULL;
}

// FDE #1626 | PC: 0x07ba6c..0x07bab0 (68 B) | Symbol: sub_07ba6c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]]
uint64_t fde_sub_07ba6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BA6CULL;
}

// FDE #1627 | PC: 0x07bab0..0x07bc90 (480 B) | Symbol: sub_07bab0
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_07bab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BAB0ULL;
}

// FDE #1628 | PC: 0x07bc90..0x07bd04 (116 B) | Symbol: sub_07bc90
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sxth w8, w3] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sxth w8, w3]
uint64_t fde_sub_07bc90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BC90ULL;
}

// FDE #1629 | PC: 0x07bd04..0x07bd78 (116 B) | Symbol: sub_07bd04
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sxth w8, w3] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sxth w8, w3]
uint64_t fde_sub_07bd04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BD04ULL;
}

// FDE #1630 | PC: 0x07bd78..0x07c038 (704 B) | Symbol: sub_07bd78
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_07bd78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90367FAULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BD78ULL;
}

// FDE #1631 | PC: 0x07c038..0x07c088 (80 B) | Symbol: sub_07c038
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #8]]
uint64_t fde_sub_07c038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C038ULL;
}

// FDE #1632 | PC: 0x07c088..0x07c498 (1040 B) | Symbol: sub_07c088
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_07c088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0410ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C088ULL;
}

// FDE #1633 | PC: 0x07c498..0x07c560 (200 B) | Symbol: sub_07c498
// EN: AArch64 prologue [sub sp, sp, #0x80; str x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]; add x29, sp, #0x70] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]; add x29, sp, #0x70]
uint64_t fde_sub_07c498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F3ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C498ULL;
}

// FDE #1634 | PC: 0x07c560..0x07c5b8 (88 B) | Symbol: sub_07c560
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w20, w0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w20, w0]
uint64_t fde_sub_07c560(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C560ULL;
}

// FDE #1635 | PC: 0x07c5b8..0x07c5dc (36 B) | Symbol: sub_07c5b8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_07c5b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C5B8ULL;
}

// FDE #1636 | PC: 0x07c5dc..0x07c5f0 (20 B) | Symbol: sub_07c5dc
// EN: AArch64 prologue [tbnz w0, #4, #0x7c5e8; mov x0, x1; b #0xf920; mov x0, x1] | VI: Khởi đầu hàm AArch64 [tbnz w0, #4, #0x7c5e8; mov x0, x1; b #0xf920; mov x0, x1]
uint64_t fde_sub_07c5dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0x37200060ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C5DCULL;
}

// FDE #1637 | PC: 0x07c5f0..0x07c5f8 (8 B) | Symbol: sub_07c5f0
// EN: AArch64 prologue [mov x0, x1; b #0xf300] | VI: Khởi đầu hàm AArch64 [mov x0, x1; b #0xf300]
uint64_t fde_sub_07c5f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE4B43ULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C5F0ULL;
}

// FDE #1638 | PC: 0x07c5f8..0x07c640 (72 B) | Symbol: sub_07c5f8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #0x30] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #0x30]
uint64_t fde_sub_07c5f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C5F8ULL;
}

// FDE #1639 | PC: 0x07c640..0x07c664 (36 B) | Symbol: sub_07c640
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_07c640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C640ULL;
}

// FDE #1640 | PC: 0x07c664..0x07c698 (52 B) | Symbol: sub_07c664
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz w1, #0x7c684; bl #0xf480] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz w1, #0x7c684; bl #0xf480]
uint64_t fde_sub_07c664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C664ULL;
}

// FDE #1641 | PC: 0x07c698..0x07c77c (228 B) | Symbol: sub_07c698
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_07c698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C698ULL;
}

// FDE #1642 | PC: 0x07c77c..0x07c780 (4 B) | Symbol: sub_07c77c
// EN: AArch64 prologue [b #0xf030] | VI: Khởi đầu hàm AArch64 [b #0xf030]
uint64_t fde_sub_07c77c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x00000021ULL) << 32) | 0x17FE4A2DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C77CULL;
}

uint64_t DispatchTtkMediaNetShard5(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x06c6b4ULL: return fde_sub_06c6b4(a0, a1, a2);
        case 0x06c798ULL: return fde_sub_06c798(a0, a1, a2);
        case 0x06c7d4ULL: return fde_sub_06c7d4(a0, a1, a2);
        case 0x06c89cULL: return fde_sub_06c89c(a0, a1, a2);
        case 0x06c8b0ULL: return fde_sub_06c8b0(a0, a1, a2);
        case 0x06c8b8ULL: return fde_sub_06c8b8(a0, a1, a2);
        case 0x06c8c8ULL: return fde_sub_06c8c8(a0, a1, a2);
        case 0x06ca14ULL: return fde_sub_06ca14(a0, a1, a2);
        case 0x06cafcULL: return fde_sub_06cafc(a0, a1, a2);
        case 0x06cb8cULL: return fde_sub_06cb8c(a0, a1, a2);
        case 0x06cbe8ULL: return fde_sub_06cbe8(a0, a1, a2);
        case 0x06cdd8ULL: return fde_sub_06cdd8(a0, a1, a2);
        case 0x06ceccULL: return fde_sub_06cecc(a0, a1, a2);
        case 0x06ced8ULL: return fde_sub_06ced8(a0, a1, a2);
        case 0x06cf14ULL: return fde_sub_06cf14(a0, a1, a2);
        case 0x06cf1cULL: return fde_sub_06cf1c(a0, a1, a2);
        case 0x06d158ULL: return fde_sub_06d158(a0, a1, a2);
        case 0x06d15cULL: return fde_sub_06d15c(a0, a1, a2);
        case 0x06d164ULL: return fde_sub_06d164(a0, a1, a2);
        case 0x06d19cULL: return fde_sub_06d19c(a0, a1, a2);
        case 0x06d370ULL: return fde_sub_06d370(a0, a1, a2);
        case 0x06d374ULL: return fde_sub_06d374(a0, a1, a2);
        case 0x06d37cULL: return fde_sub_06d37c(a0, a1, a2);
        case 0x06d418ULL: return fde_sub_06d418(a0, a1, a2);
        case 0x06d544ULL: return fde_sub_06d544(a0, a1, a2);
        case 0x06d5d8ULL: return fde_sub_06d5d8(a0, a1, a2);
        case 0x06d7d0ULL: return fde_sub_06d7d0(a0, a1, a2);
        case 0x06d8acULL: return fde_sub_06d8ac(a0, a1, a2);
        case 0x06d924ULL: return fde_sub_06d924(a0, a1, a2);
        case 0x06d92cULL: return fde_sub_06d92c(a0, a1, a2);
        case 0x06d934ULL: return fde_sub_06d934(a0, a1, a2);
        case 0x06d940ULL: return fde_sub_06d940(a0, a1, a2);
        case 0x06d94cULL: return fde_sub_06d94c(a0, a1, a2);
        case 0x06d958ULL: return fde_sub_06d958(a0, a1, a2);
        case 0x06da34ULL: return fde_sub_06da34(a0, a1, a2);
        case 0x06dad8ULL: return fde_sub_06dad8(a0, a1, a2);
        case 0x06db8cULL: return fde_sub_06db8c(a0, a1, a2);
        case 0x06dba0ULL: return fde_sub_06dba0(a0, a1, a2);
        case 0x06dc6cULL: return fde_sub_06dc6c(a0, a1, a2);
        case 0x06dd08ULL: return fde_sub_06dd08(a0, a1, a2);
        case 0x06de20ULL: return fde_sub_06de20(a0, a1, a2);
        case 0x06dfb4ULL: return fde_sub_06dfb4(a0, a1, a2);
        case 0x06e094ULL: return fde_sub_06e094(a0, a1, a2);
        case 0x06e0b8ULL: return fde_sub_06e0b8(a0, a1, a2);
        case 0x06e18cULL: return fde_sub_06e18c(a0, a1, a2);
        case 0x06e1e0ULL: return fde_sub_06e1e0(a0, a1, a2);
        case 0x06e2f4ULL: return fde_sub_06e2f4(a0, a1, a2);
        case 0x06e3c0ULL: return fde_sub_06e3c0(a0, a1, a2);
        case 0x06e3dcULL: return fde_sub_06e3dc(a0, a1, a2);
        case 0x06e4b4ULL: return fde_sub_06e4b4(a0, a1, a2);
        case 0x06e4dcULL: return fde_sub_06e4dc(a0, a1, a2);
        case 0x06e524ULL: return fde_sub_06e524(a0, a1, a2);
        case 0x06e54cULL: return fde_sub_06e54c(a0, a1, a2);
        case 0x06e594ULL: return fde_sub_06e594(a0, a1, a2);
        case 0x06e5acULL: return fde_sub_06e5ac(a0, a1, a2);
        case 0x06e5f0ULL: return fde_sub_06e5f0(a0, a1, a2);
        case 0x06e610ULL: return fde_sub_06e610(a0, a1, a2);
        case 0x06e628ULL: return fde_sub_06e628(a0, a1, a2);
        case 0x06e634ULL: return fde_sub_06e634(a0, a1, a2);
        case 0x06e640ULL: return fde_sub_06e640(a0, a1, a2);
        case 0x06e648ULL: return fde_sub_06e648(a0, a1, a2);
        case 0x06e6c4ULL: return fde_sub_06e6c4(a0, a1, a2);
        case 0x06e6ccULL: return fde_sub_06e6cc(a0, a1, a2);
        case 0x06e7bcULL: return fde_sub_06e7bc(a0, a1, a2);
        case 0x06e800ULL: return fde_sub_06e800(a0, a1, a2);
        case 0x06e8ecULL: return fde_sub_06e8ec(a0, a1, a2);
        case 0x06ead4ULL: return fde_sub_06ead4(a0, a1, a2);
        case 0x06eb98ULL: return fde_sub_06eb98(a0, a1, a2);
        case 0x06ec94ULL: return fde_sub_06ec94(a0, a1, a2);
        case 0x06eca4ULL: return fde_sub_06eca4(a0, a1, a2);
        case 0x06edfcULL: return fde_sub_06edfc(a0, a1, a2);
        case 0x06ef64ULL: return fde_sub_06ef64(a0, a1, a2);
        case 0x06efd4ULL: return fde_sub_06efd4(a0, a1, a2);
        case 0x06efdcULL: return fde_sub_06efdc(a0, a1, a2);
        case 0x06f01cULL: return fde_sub_06f01c(a0, a1, a2);
        case 0x06f058ULL: return fde_sub_06f058(a0, a1, a2);
        case 0x06f05cULL: return fde_sub_06f05c(a0, a1, a2);
        case 0x06f064ULL: return fde_sub_06f064(a0, a1, a2);
        case 0x06f078ULL: return fde_sub_06f078(a0, a1, a2);
        case 0x06f080ULL: return fde_sub_06f080(a0, a1, a2);
        case 0x06f130ULL: return fde_sub_06f130(a0, a1, a2);
        case 0x06f134ULL: return fde_sub_06f134(a0, a1, a2);
        case 0x06f150ULL: return fde_sub_06f150(a0, a1, a2);
        case 0x06f1f0ULL: return fde_sub_06f1f0(a0, a1, a2);
        case 0x06f1f4ULL: return fde_sub_06f1f4(a0, a1, a2);
        case 0x06f270ULL: return fde_sub_06f270(a0, a1, a2);
        case 0x06f2a8ULL: return fde_sub_06f2a8(a0, a1, a2);
        case 0x06f3ccULL: return fde_sub_06f3cc(a0, a1, a2);
        case 0x06f410ULL: return fde_sub_06f410(a0, a1, a2);
        case 0x06f444ULL: return fde_sub_06f444(a0, a1, a2);
        case 0x06f44cULL: return fde_sub_06f44c(a0, a1, a2);
        case 0x06f4fcULL: return fde_sub_06f4fc(a0, a1, a2);
        case 0x06f5b8ULL: return fde_sub_06f5b8(a0, a1, a2);
        case 0x06f5f0ULL: return fde_sub_06f5f0(a0, a1, a2);
        case 0x06f6a8ULL: return fde_sub_06f6a8(a0, a1, a2);
        case 0x06f744ULL: return fde_sub_06f744(a0, a1, a2);
        case 0x06f770ULL: return fde_sub_06f770(a0, a1, a2);
        case 0x06f7ecULL: return fde_sub_06f7ec(a0, a1, a2);
        case 0x06f7f4ULL: return fde_sub_06f7f4(a0, a1, a2);
        case 0x06f804ULL: return fde_sub_06f804(a0, a1, a2);
        case 0x06f828ULL: return fde_sub_06f828(a0, a1, a2);
        case 0x06f860ULL: return fde_sub_06f860(a0, a1, a2);
        case 0x06f89cULL: return fde_sub_06f89c(a0, a1, a2);
        case 0x06f8ccULL: return fde_sub_06f8cc(a0, a1, a2);
        case 0x06f8f0ULL: return fde_sub_06f8f0(a0, a1, a2);
        case 0x06f914ULL: return fde_sub_06f914(a0, a1, a2);
        case 0x06fa1cULL: return fde_sub_06fa1c(a0, a1, a2);
        case 0x06fab4ULL: return fde_sub_06fab4(a0, a1, a2);
        case 0x06fae0ULL: return fde_sub_06fae0(a0, a1, a2);
        case 0x06fca4ULL: return fde_sub_06fca4(a0, a1, a2);
        case 0x06fd64ULL: return fde_sub_06fd64(a0, a1, a2);
        case 0x06fe2cULL: return fde_sub_06fe2c(a0, a1, a2);
        case 0x06fe60ULL: return fde_sub_06fe60(a0, a1, a2);
        case 0x06ff34ULL: return fde_sub_06ff34(a0, a1, a2);
        case 0x07005cULL: return fde_sub_07005c(a0, a1, a2);
        case 0x0700d8ULL: return fde_sub_0700d8(a0, a1, a2);
        case 0x070194ULL: return fde_sub_070194(a0, a1, a2);
        case 0x07025cULL: return fde_sub_07025c(a0, a1, a2);
        case 0x0703a0ULL: return fde_sub_0703a0(a0, a1, a2);
        case 0x070418ULL: return fde_sub_070418(a0, a1, a2);
        case 0x0704a0ULL: return fde_sub_0704a0(a0, a1, a2);
        case 0x0704acULL: return fde_sub_0704ac(a0, a1, a2);
        case 0x0704e0ULL: return fde_sub_0704e0(a0, a1, a2);
        case 0x0705c4ULL: return fde_sub_0705c4(a0, a1, a2);
        case 0x070610ULL: return fde_sub_070610(a0, a1, a2);
        case 0x070628ULL: return fde_sub_070628(a0, a1, a2);
        case 0x0706bcULL: return fde_sub_0706bc(a0, a1, a2);
        case 0x070710ULL: return fde_sub_070710(a0, a1, a2);
        case 0x0707a0ULL: return fde_sub_0707a0(a0, a1, a2);
        case 0x0707f8ULL: return fde_sub_0707f8(a0, a1, a2);
        case 0x070800ULL: return fde_sub_070800(a0, a1, a2);
        case 0x070808ULL: return fde_sub_070808(a0, a1, a2);
        case 0x07081cULL: return fde_sub_07081c(a0, a1, a2);
        case 0x070830ULL: return fde_sub_070830(a0, a1, a2);
        case 0x070834ULL: return fde_sub_070834(a0, a1, a2);
        case 0x0708acULL: return fde_sub_0708ac(a0, a1, a2);
        case 0x070930ULL: return fde_sub_070930(a0, a1, a2);
        case 0x070aa0ULL: return fde_sub_070aa0(a0, a1, a2);
        case 0x070aa8ULL: return fde_sub_070aa8(a0, a1, a2);
        case 0x070ab0ULL: return fde_sub_070ab0(a0, a1, a2);
        case 0x070b10ULL: return fde_sub_070b10(a0, a1, a2);
        case 0x070b18ULL: return fde_sub_070b18(a0, a1, a2);
        case 0x070b8cULL: return fde_sub_070b8c(a0, a1, a2);
        case 0x070b9cULL: return fde_sub_070b9c(a0, a1, a2);
        case 0x070bacULL: return fde_sub_070bac(a0, a1, a2);
        case 0x070d84ULL: return fde_sub_070d84(a0, a1, a2);
        case 0x071ad0ULL: return fde_sub_071ad0(a0, a1, a2);
        case 0x071ce0ULL: return fde_sub_071ce0(a0, a1, a2);
        case 0x071d30ULL: return fde_sub_071d30(a0, a1, a2);
        case 0x071d50ULL: return fde_sub_071d50(a0, a1, a2);
        case 0x071d58ULL: return fde_sub_071d58(a0, a1, a2);
        case 0x071d60ULL: return fde_sub_071d60(a0, a1, a2);
        case 0x071d68ULL: return fde_sub_071d68(a0, a1, a2);
        case 0x071d70ULL: return fde_sub_071d70(a0, a1, a2);
        case 0x071d78ULL: return fde_sub_071d78(a0, a1, a2);
        case 0x071d80ULL: return fde_sub_071d80(a0, a1, a2);
        case 0x071d88ULL: return fde_sub_071d88(a0, a1, a2);
        case 0x071d90ULL: return fde_sub_071d90(a0, a1, a2);
        case 0x071d98ULL: return fde_sub_071d98(a0, a1, a2);
        case 0x071da0ULL: return fde_sub_071da0(a0, a1, a2);
        case 0x071e88ULL: return fde_sub_071e88(a0, a1, a2);
        case 0x071eb0ULL: return fde_sub_071eb0(a0, a1, a2);
        case 0x071f7cULL: return fde_sub_071f7c(a0, a1, a2);
        case 0x072048ULL: return fde_sub_072048(a0, a1, a2);
        case 0x072160ULL: return fde_sub_072160(a0, a1, a2);
        case 0x0721b0ULL: return fde_sub_0721b0(a0, a1, a2);
        case 0x0721bcULL: return fde_sub_0721bc(a0, a1, a2);
        case 0x0722b0ULL: return fde_sub_0722b0(a0, a1, a2);
        case 0x0722f4ULL: return fde_sub_0722f4(a0, a1, a2);
        case 0x07235cULL: return fde_sub_07235c(a0, a1, a2);
        case 0x072398ULL: return fde_sub_072398(a0, a1, a2);
        case 0x0723ccULL: return fde_sub_0723cc(a0, a1, a2);
        case 0x072454ULL: return fde_sub_072454(a0, a1, a2);
        case 0x0726c4ULL: return fde_sub_0726c4(a0, a1, a2);
        case 0x0727fcULL: return fde_sub_0727fc(a0, a1, a2);
        case 0x072a68ULL: return fde_sub_072a68(a0, a1, a2);
        case 0x072bf4ULL: return fde_sub_072bf4(a0, a1, a2);
        case 0x072cccULL: return fde_sub_072ccc(a0, a1, a2);
        case 0x072e14ULL: return fde_sub_072e14(a0, a1, a2);
        case 0x072f74ULL: return fde_sub_072f74(a0, a1, a2);
        case 0x0730e8ULL: return fde_sub_0730e8(a0, a1, a2);
        case 0x07325cULL: return fde_sub_07325c(a0, a1, a2);
        case 0x073530ULL: return fde_sub_073530(a0, a1, a2);
        case 0x0735f0ULL: return fde_sub_0735f0(a0, a1, a2);
        case 0x073658ULL: return fde_sub_073658(a0, a1, a2);
        case 0x07374cULL: return fde_sub_07374c(a0, a1, a2);
        case 0x073754ULL: return fde_sub_073754(a0, a1, a2);
        case 0x0739d4ULL: return fde_sub_0739d4(a0, a1, a2);
        case 0x073ab8ULL: return fde_sub_073ab8(a0, a1, a2);
        case 0x073b78ULL: return fde_sub_073b78(a0, a1, a2);
        case 0x073be8ULL: return fde_sub_073be8(a0, a1, a2);
        case 0x073c20ULL: return fde_sub_073c20(a0, a1, a2);
        case 0x073c5cULL: return fde_sub_073c5c(a0, a1, a2);
        case 0x073c68ULL: return fde_sub_073c68(a0, a1, a2);
        case 0x073cc0ULL: return fde_sub_073cc0(a0, a1, a2);
        case 0x073d18ULL: return fde_sub_073d18(a0, a1, a2);
        case 0x073d7cULL: return fde_sub_073d7c(a0, a1, a2);
        case 0x073d88ULL: return fde_sub_073d88(a0, a1, a2);
        case 0x073e90ULL: return fde_sub_073e90(a0, a1, a2);
        case 0x073f00ULL: return fde_sub_073f00(a0, a1, a2);
        case 0x073f98ULL: return fde_sub_073f98(a0, a1, a2);
        case 0x074120ULL: return fde_sub_074120(a0, a1, a2);
        case 0x074134ULL: return fde_sub_074134(a0, a1, a2);
        case 0x0742b8ULL: return fde_sub_0742b8(a0, a1, a2);
        case 0x07439cULL: return fde_sub_07439c(a0, a1, a2);
        case 0x0743d0ULL: return fde_sub_0743d0(a0, a1, a2);
        case 0x07441cULL: return fde_sub_07441c(a0, a1, a2);
        case 0x074468ULL: return fde_sub_074468(a0, a1, a2);
        case 0x074488ULL: return fde_sub_074488(a0, a1, a2);
        case 0x0744ccULL: return fde_sub_0744cc(a0, a1, a2);
        case 0x0746f4ULL: return fde_sub_0746f4(a0, a1, a2);
        case 0x074710ULL: return fde_sub_074710(a0, a1, a2);
        case 0x074724ULL: return fde_sub_074724(a0, a1, a2);
        case 0x074738ULL: return fde_sub_074738(a0, a1, a2);
        case 0x074e90ULL: return fde_sub_074e90(a0, a1, a2);
        case 0x074fdcULL: return fde_sub_074fdc(a0, a1, a2);
        case 0x07506cULL: return fde_sub_07506c(a0, a1, a2);
        case 0x075074ULL: return fde_sub_075074(a0, a1, a2);
        case 0x0751f8ULL: return fde_sub_0751f8(a0, a1, a2);
        case 0x0756b4ULL: return fde_sub_0756b4(a0, a1, a2);
        case 0x075a58ULL: return fde_sub_075a58(a0, a1, a2);
        case 0x075b58ULL: return fde_sub_075b58(a0, a1, a2);
        case 0x0764c8ULL: return fde_sub_0764c8(a0, a1, a2);
        case 0x0765a8ULL: return fde_sub_0765a8(a0, a1, a2);
        case 0x076928ULL: return fde_sub_076928(a0, a1, a2);
        case 0x076a48ULL: return fde_sub_076a48(a0, a1, a2);
        case 0x0771ccULL: return fde_sub_0771cc(a0, a1, a2);
        case 0x0772a4ULL: return fde_sub_0772a4(a0, a1, a2);
        case 0x0773f0ULL: return fde_sub_0773f0(a0, a1, a2);
        case 0x0774a0ULL: return fde_sub_0774a0(a0, a1, a2);
        case 0x077530ULL: return fde_sub_077530(a0, a1, a2);
        case 0x07759cULL: return fde_sub_07759c(a0, a1, a2);
        case 0x07769cULL: return fde_sub_07769c(a0, a1, a2);
        case 0x077798ULL: return fde_sub_077798(a0, a1, a2);
        case 0x07790cULL: return fde_sub_07790c(a0, a1, a2);
        case 0x077984ULL: return fde_sub_077984(a0, a1, a2);
        case 0x077b88ULL: return fde_sub_077b88(a0, a1, a2);
        case 0x077cc8ULL: return fde_sub_077cc8(a0, a1, a2);
        case 0x077d4cULL: return fde_sub_077d4c(a0, a1, a2);
        case 0x077e8cULL: return fde_sub_077e8c(a0, a1, a2);
        case 0x078614ULL: return fde_sub_078614(a0, a1, a2);
        case 0x07866cULL: return fde_sub_07866c(a0, a1, a2);
        case 0x07870cULL: return fde_sub_07870c(a0, a1, a2);
        case 0x07877cULL: return fde_sub_07877c(a0, a1, a2);
        case 0x078830ULL: return fde_sub_078830(a0, a1, a2);
        case 0x07883cULL: return fde_sub_07883c(a0, a1, a2);
        case 0x078848ULL: return fde_sub_078848(a0, a1, a2);
        case 0x0788c0ULL: return fde_sub_0788c0(a0, a1, a2);
        case 0x078938ULL: return fde_sub_078938(a0, a1, a2);
        case 0x078bacULL: return fde_sub_078bac(a0, a1, a2);
        case 0x078cd0ULL: return fde_sub_078cd0(a0, a1, a2);
        case 0x078d5cULL: return fde_sub_078d5c(a0, a1, a2);
        case 0x078ec4ULL: return fde_sub_078ec4(a0, a1, a2);
        case 0x078f44ULL: return fde_sub_078f44(a0, a1, a2);
        case 0x078f9cULL: return fde_sub_078f9c(a0, a1, a2);
        case 0x078fb4ULL: return fde_sub_078fb4(a0, a1, a2);
        case 0x079088ULL: return fde_sub_079088(a0, a1, a2);
        case 0x079090ULL: return fde_sub_079090(a0, a1, a2);
        case 0x0790f8ULL: return fde_sub_0790f8(a0, a1, a2);
        case 0x079124ULL: return fde_sub_079124(a0, a1, a2);
        case 0x07921cULL: return fde_sub_07921c(a0, a1, a2);
        case 0x079348ULL: return fde_sub_079348(a0, a1, a2);
        case 0x079358ULL: return fde_sub_079358(a0, a1, a2);
        case 0x0794b8ULL: return fde_sub_0794b8(a0, a1, a2);
        case 0x07962cULL: return fde_sub_07962c(a0, a1, a2);
        case 0x0797e4ULL: return fde_sub_0797e4(a0, a1, a2);
        case 0x0797e8ULL: return fde_sub_0797e8(a0, a1, a2);
        case 0x079860ULL: return fde_sub_079860(a0, a1, a2);
        case 0x079868ULL: return fde_sub_079868(a0, a1, a2);
        case 0x079930ULL: return fde_sub_079930(a0, a1, a2);
        case 0x0799b0ULL: return fde_sub_0799b0(a0, a1, a2);
        case 0x0799c4ULL: return fde_sub_0799c4(a0, a1, a2);
        case 0x079a1cULL: return fde_sub_079a1c(a0, a1, a2);
        case 0x079a6cULL: return fde_sub_079a6c(a0, a1, a2);
        case 0x079aa4ULL: return fde_sub_079aa4(a0, a1, a2);
        case 0x079c40ULL: return fde_sub_079c40(a0, a1, a2);
        case 0x079cf0ULL: return fde_sub_079cf0(a0, a1, a2);
        case 0x079cf8ULL: return fde_sub_079cf8(a0, a1, a2);
        case 0x079d64ULL: return fde_sub_079d64(a0, a1, a2);
        case 0x079df4ULL: return fde_sub_079df4(a0, a1, a2);
        case 0x079f80ULL: return fde_sub_079f80(a0, a1, a2);
        case 0x07a00cULL: return fde_sub_07a00c(a0, a1, a2);
        case 0x07a140ULL: return fde_sub_07a140(a0, a1, a2);
        case 0x07a180ULL: return fde_sub_07a180(a0, a1, a2);
        case 0x07a2dcULL: return fde_sub_07a2dc(a0, a1, a2);
        case 0x07a368ULL: return fde_sub_07a368(a0, a1, a2);
        case 0x07a4c0ULL: return fde_sub_07a4c0(a0, a1, a2);
        case 0x07a53cULL: return fde_sub_07a53c(a0, a1, a2);
        case 0x07a648ULL: return fde_sub_07a648(a0, a1, a2);
        case 0x07a754ULL: return fde_sub_07a754(a0, a1, a2);
        case 0x07a870ULL: return fde_sub_07a870(a0, a1, a2);
        case 0x07a8f4ULL: return fde_sub_07a8f4(a0, a1, a2);
        case 0x07a99cULL: return fde_sub_07a99c(a0, a1, a2);
        case 0x07ab34ULL: return fde_sub_07ab34(a0, a1, a2);
        case 0x07acb4ULL: return fde_sub_07acb4(a0, a1, a2);
        case 0x07ae18ULL: return fde_sub_07ae18(a0, a1, a2);
        case 0x07ae7cULL: return fde_sub_07ae7c(a0, a1, a2);
        case 0x07aff0ULL: return fde_sub_07aff0(a0, a1, a2);
        case 0x07b0f0ULL: return fde_sub_07b0f0(a0, a1, a2);
        case 0x07b170ULL: return fde_sub_07b170(a0, a1, a2);
        case 0x07b1e4ULL: return fde_sub_07b1e4(a0, a1, a2);
        case 0x07b2a8ULL: return fde_sub_07b2a8(a0, a1, a2);
        case 0x07b30cULL: return fde_sub_07b30c(a0, a1, a2);
        case 0x07b4ccULL: return fde_sub_07b4cc(a0, a1, a2);
        case 0x07b4f0ULL: return fde_sub_07b4f0(a0, a1, a2);
        case 0x07b5acULL: return fde_sub_07b5ac(a0, a1, a2);
        case 0x07b608ULL: return fde_sub_07b608(a0, a1, a2);
        case 0x07b650ULL: return fde_sub_07b650(a0, a1, a2);
        case 0x07b774ULL: return fde_sub_07b774(a0, a1, a2);
        case 0x07b880ULL: return fde_sub_07b880(a0, a1, a2);
        case 0x07ba6cULL: return fde_sub_07ba6c(a0, a1, a2);
        case 0x07bab0ULL: return fde_sub_07bab0(a0, a1, a2);
        case 0x07bc90ULL: return fde_sub_07bc90(a0, a1, a2);
        case 0x07bd04ULL: return fde_sub_07bd04(a0, a1, a2);
        case 0x07bd78ULL: return fde_sub_07bd78(a0, a1, a2);
        case 0x07c038ULL: return fde_sub_07c038(a0, a1, a2);
        case 0x07c088ULL: return fde_sub_07c088(a0, a1, a2);
        case 0x07c498ULL: return fde_sub_07c498(a0, a1, a2);
        case 0x07c560ULL: return fde_sub_07c560(a0, a1, a2);
        case 0x07c5b8ULL: return fde_sub_07c5b8(a0, a1, a2);
        case 0x07c5dcULL: return fde_sub_07c5dc(a0, a1, a2);
        case 0x07c5f0ULL: return fde_sub_07c5f0(a0, a1, a2);
        case 0x07c5f8ULL: return fde_sub_07c5f8(a0, a1, a2);
        case 0x07c640ULL: return fde_sub_07c640(a0, a1, a2);
        case 0x07c664ULL: return fde_sub_07c664(a0, a1, a2);
        case 0x07c698ULL: return fde_sub_07c698(a0, a1, a2);
        case 0x07c77cULL: return fde_sub_07c77c(a0, a1, a2);
        default: return 0ULL;
    }
}

uint64_t DispatchTtkMediaNetShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchTtkMediaNetShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchTtkMediaNetShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchTtkMediaNetShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;

// EN: Unified router across all 1,643 AArch64 FDEs in libttkmedianet.so
// VI: Bộ định tuyến hợp nhất trên toàn bộ 1.643 hàm AArch64 FDE trong libttkmedianet.so
uint64_t ExecuteTtkMediaNetFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept {
    if (fde_pc_begin >= 0x00fd20ULL && fde_pc_begin <= 0x02c800ULL) {
        return DispatchTtkMediaNetShard1(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x02c844ULL && fde_pc_begin <= 0x041a34ULL) {
        return DispatchTtkMediaNetShard2(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x041adcULL && fde_pc_begin <= 0x056af0ULL) {
        return DispatchTtkMediaNetShard3(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x056b00ULL && fde_pc_begin <= 0x06c6a4ULL) {
        return DispatchTtkMediaNetShard4(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x06c6b4ULL && fde_pc_begin <= 0x07c77cULL) {
        return DispatchTtkMediaNetShard5(fde_pc_begin, arg0, arg1, arg2);
    }
    return 0ULL;
}

} // namespace TTKMediaNet
