// ============================================================================
// File: bytebench_fde_shard_4.cpp
// Target 107 / 169: libbytebench.so (641,376 bytes)
// EN: Clean-room C++17 AArch64 Function Shard 4/5 covering [960..1279]
//     (PC range 0x05af90 .. 0x06b39c).
// VI: Phân mảnh hàm AArch64 C++17 4/5 bao phủ [960..1279]
//     (Dải địa chỉ PC 0x05af90 .. 0x06b39c).
// ============================================================================
#include "bytebench_core.h"

namespace bytebench {

// Func #0960 | PC: 0x05af90..0x05afd0 (64 B) | Symbol: sub_05af90
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05af90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AF90ULL;
}

// Func #0961 | PC: 0x05b008..0x05b048 (64 B) | Symbol: sub_05b008
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05b008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B008ULL;
}

// Func #0962 | PC: 0x05b06c..0x05b0ac (64 B) | Symbol: sub_05b06c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05b06c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B06CULL;
}

// Func #0963 | PC: 0x05b0b4..0x05b0f4 (64 B) | Symbol: sub_05b0b4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05b0b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B0B4ULL;
}

// Func #0964 | PC: 0x05b11c..0x05b15c (64 B) | Symbol: sub_05b11c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05b11c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B11CULL;
}

// Func #0965 | PC: 0x05b194..0x05b1d4 (64 B) | Symbol: sub_05b194
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05b194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B194ULL;
}

// Func #0966 | PC: 0x05b204..0x05b244 (64 B) | Symbol: sub_05b204
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05b204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B204ULL;
}

// Func #0967 | PC: 0x05b26c..0x05b2ac (64 B) | Symbol: sub_05b26c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05b26c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B26CULL;
}

// Func #0968 | PC: 0x05b2ec..0x05b32c (64 B) | Symbol: sub_05b2ec
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05b2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B2ECULL;
}

// Func #0969 | PC: 0x05b36c..0x05b3ac (64 B) | Symbol: sub_05b36c
// EN: AArch64 prologue [sub sp, sp, #0xd0; str x23, [sp, #0x90]; stp x22, x21, [sp, #0xa0]; stp x20, x19, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str x23, [sp, #0x90]; stp x22, x21, [sp, #0xa0]; stp x20, x19, [sp, #0xb0]]
uint64_t fde_sub_05b36c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF7ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B36CULL;
}

// Func #0970 | PC: 0x05b478..0x05b4b8 (64 B) | Symbol: sub_05b478
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz x1, #0x5b4a0; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz x1, #0x5b4a0; ldr x8, [x1]]
uint64_t fde_sub_05b478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B478ULL;
}

// Func #0971 | PC: 0x05b4a4..0x05b4e4 (64 B) | Symbol: sub_05b4a4
// EN: AArch64 prologue [sub sp, sp, #0x100; str d8, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]; stp x22, x21, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; str d8, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]; stp x22, x21, [sp, #0xd0]]
uint64_t fde_sub_05b4a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD005BE8ULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B4A4ULL;
}

// Func #0972 | PC: 0x05b724..0x05b764 (64 B) | Symbol: sub_05b724
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_05b724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035FF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B724ULL;
}

// Func #0973 | PC: 0x05b900..0x05b940 (64 B) | Symbol: sub_05b900
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7d734] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7d734]
uint64_t fde_sub_05b900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B900ULL;
}

// Func #0974 | PC: 0x05b924..0x05b964 (64 B) | Symbol: sub_05b924
// EN: AArch64 prologue [sub sp, sp, #0xd0; str x23, [sp, #0x90]; stp x22, x21, [sp, #0xa0]; stp x20, x19, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str x23, [sp, #0x90]; stp x22, x21, [sp, #0xa0]; stp x20, x19, [sp, #0xb0]]
uint64_t fde_sub_05b924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF7ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B924ULL;
}

// Func #0975 | PC: 0x05bc10..0x05bc50 (64 B) | Symbol: sub_05bc10
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]]
uint64_t fde_sub_05bc10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9096FFCULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BC10ULL;
}

// Func #0976 | PC: 0x05bde4..0x05be24 (64 B) | Symbol: sub_05bde4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05bde4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BDE4ULL;
}

// Func #0977 | PC: 0x05be14..0x05be54 (64 B) | Symbol: sub_05be14
// EN: AArch64 prologue [sub sp, sp, #0x510; bl #0x7b21c; mov x26, x1; mov x20, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x510; bl #0x7b21c; mov x26, x1; mov x20, x0]
uint64_t fde_sub_05be14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007D01ULL) << 32) | 0xD11443FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BE14ULL;
}

// Func #0978 | PC: 0x05c8ac..0x05c8ec (64 B) | Symbol: sub_05c8ac
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x78e5c] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x78e5c]
uint64_t fde_sub_05c8ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C8ACULL;
}

// Func #0979 | PC: 0x05c90c..0x05c94c (64 B) | Symbol: sub_05c90c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7d450] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7d450]
uint64_t fde_sub_05c90c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C90CULL;
}

// Func #0980 | PC: 0x05c950..0x05c990 (64 B) | Symbol: sub_05c950
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9c000]
uint64_t fde_sub_05c950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C950ULL;
}

// Func #0981 | PC: 0x05c974..0x05c9b4 (64 B) | Symbol: sub_05c974
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05c974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C974ULL;
}

// Func #0982 | PC: 0x05c998..0x05c9d8 (64 B) | Symbol: sub_05c998
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05c998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C998ULL;
}

// Func #0983 | PC: 0x05ca00..0x05ca40 (64 B) | Symbol: sub_05ca00
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05ca00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CA00ULL;
}

// Func #0984 | PC: 0x05ca28..0x05ca68 (64 B) | Symbol: sub_05ca28
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9c000]
uint64_t fde_sub_05ca28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CA28ULL;
}

// Func #0985 | PC: 0x05ca4c..0x05ca8c (64 B) | Symbol: sub_05ca4c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05ca4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CA4CULL;
}

// Func #0986 | PC: 0x05ca68..0x05caa8 (64 B) | Symbol: sub_05ca68
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]]
uint64_t fde_sub_05ca68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90967FAULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CA68ULL;
}

// Func #0987 | PC: 0x05cc68..0x05cca8 (64 B) | Symbol: sub_05cc68
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05cc68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CC68ULL;
}

// Func #0988 | PC: 0x05cc84..0x05ccc4 (64 B) | Symbol: sub_05cc84
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05cc84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CC84ULL;
}

// Func #0989 | PC: 0x05cd1c..0x05cd5c (64 B) | Symbol: sub_05cd1c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05cd1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CD1CULL;
}

// Func #0990 | PC: 0x05cd38..0x05cd78 (64 B) | Symbol: sub_05cd38
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05cd38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CD38ULL;
}

// Func #0991 | PC: 0x05cd80..0x05cdc0 (64 B) | Symbol: sub_05cd80
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9c000]
uint64_t fde_sub_05cd80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CD80ULL;
}

// Func #0992 | PC: 0x05cda4..0x05cde4 (64 B) | Symbol: sub_05cda4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05cda4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CDA4ULL;
}

// Func #0993 | PC: 0x05cdc0..0x05ce00 (64 B) | Symbol: sub_05cdc0
// EN: AArch64 prologue [sub sp, sp, #0x160; str d8, [sp, #0xf0]; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str d8, [sp, #0xf0]; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]]
uint64_t fde_sub_05cdc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD007BE8ULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CDC0ULL;
}

// Func #0994 | PC: 0x05d2a4..0x05d2e4 (64 B) | Symbol: sub_05d2a4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x233b0; str x19, [sp, #-0x20]!] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x233b0; str x19, [sp, #-0x20]!]
uint64_t fde_sub_05d2a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D2A4ULL;
}

// Func #0995 | PC: 0x05d2b0..0x05d2f0 (64 B) | Symbol: sub_05d2b0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c8a0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c8a0]
uint64_t fde_sub_05d2b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D2B0ULL;
}

// Func #0996 | PC: 0x05d2ec..0x05d32c (64 B) | Symbol: sub_05d2ec
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D2ECULL;
}

// Func #0997 | PC: 0x05d35c..0x05d39c (64 B) | Symbol: sub_05d35c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d35c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D35CULL;
}

// Func #0998 | PC: 0x05d3e0..0x05d420 (64 B) | Symbol: sub_05d3e0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d3e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D3E0ULL;
}

// Func #0999 | PC: 0x05d424..0x05d464 (64 B) | Symbol: sub_05d424
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7eba4] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7eba4]
uint64_t fde_sub_05d424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D424ULL;
}

// Func #1000 | PC: 0x05d594..0x05d5d4 (64 B) | Symbol: sub_05d594
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9c000]
uint64_t fde_sub_05d594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D594ULL;
}

// Func #1001 | PC: 0x05d5b8..0x05d5f8 (64 B) | Symbol: sub_05d5b8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05d5b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D5B8ULL;
}

// Func #1002 | PC: 0x05d5dc..0x05d61c (64 B) | Symbol: sub_05d5dc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d5dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D5DCULL;
}

// Func #1003 | PC: 0x05d648..0x05d688 (64 B) | Symbol: sub_05d648
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05d648(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D648ULL;
}

// Func #1004 | PC: 0x05d698..0x05d6d8 (64 B) | Symbol: sub_05d698
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7a058] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7a058]
uint64_t fde_sub_05d698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D698ULL;
}

// Func #1005 | PC: 0x05d6cc..0x05d70c (64 B) | Symbol: sub_05d6cc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05d6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D6CCULL;
}

// Func #1006 | PC: 0x05d6e8..0x05d728 (64 B) | Symbol: sub_05d6e8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05d6e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D6E8ULL;
}

// Func #1007 | PC: 0x05d740..0x05d780 (64 B) | Symbol: sub_05d740
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c6b0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c6b0]
uint64_t fde_sub_05d740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D740ULL;
}

// Func #1008 | PC: 0x05d75c..0x05d79c (64 B) | Symbol: sub_05d75c
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_05d75c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90757F6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D75CULL;
}

// Func #1009 | PC: 0x05d904..0x05d944 (64 B) | Symbol: sub_05d904
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79058] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79058]
uint64_t fde_sub_05d904(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D904ULL;
}

// Func #1010 | PC: 0x05d930..0x05d970 (64 B) | Symbol: sub_05d930
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9c000]
uint64_t fde_sub_05d930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D930ULL;
}

// Func #1011 | PC: 0x05d95c..0x05d99c (64 B) | Symbol: sub_05d95c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x0, x1; bl #0x2c750] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x0, x1; bl #0x2c750]
uint64_t fde_sub_05d95c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D95CULL;
}

// Func #1012 | PC: 0x05d994..0x05d9d4 (64 B) | Symbol: sub_05d994
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05d994(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D994ULL;
}

// Func #1013 | PC: 0x05d9e4..0x05da24 (64 B) | Symbol: sub_05d9e4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05d9e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D9E4ULL;
}

// Func #1014 | PC: 0x05da38..0x05da78 (64 B) | Symbol: sub_05da38
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05da38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DA38ULL;
}

// Func #1015 | PC: 0x05da64..0x05daa4 (64 B) | Symbol: sub_05da64
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c948] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c948]
uint64_t fde_sub_05da64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DA64ULL;
}

// Func #1016 | PC: 0x05daa0..0x05dae0 (64 B) | Symbol: sub_05daa0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05daa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DAA0ULL;
}

// Func #1017 | PC: 0x05dadc..0x05db1c (64 B) | Symbol: sub_05dadc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05dadc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DADCULL;
}

// Func #1018 | PC: 0x05db08..0x05db48 (64 B) | Symbol: sub_05db08
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c948] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c948]
uint64_t fde_sub_05db08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB08ULL;
}

// Func #1019 | PC: 0x05db44..0x05db84 (64 B) | Symbol: sub_05db44
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05db44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB44ULL;
}

// Func #1020 | PC: 0x05db98..0x05dbd8 (64 B) | Symbol: sub_05db98
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05db98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB98ULL;
}

// Func #1021 | PC: 0x05dbc4..0x05dc04 (64 B) | Symbol: sub_05dbc4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x0, x1; mov x1, x2] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x0, x1; mov x1, x2]
uint64_t fde_sub_05dbc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DBC4ULL;
}

// Func #1022 | PC: 0x05dc14..0x05dc54 (64 B) | Symbol: sub_05dc14
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05dc14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DC14ULL;
}

// Func #1023 | PC: 0x05dc30..0x05dc70 (64 B) | Symbol: sub_05dc30
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05dc30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DC30ULL;
}

// Func #1024 | PC: 0x05dc88..0x05dcc8 (64 B) | Symbol: sub_05dc88
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c6b0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c6b0]
uint64_t fde_sub_05dc88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DC88ULL;
}

// Func #1025 | PC: 0x05dcd8..0x05dd18 (64 B) | Symbol: sub_05dcd8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05dcd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DCD8ULL;
}

// Func #1026 | PC: 0x05dcf4..0x05dd34 (64 B) | Symbol: sub_05dcf4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05dcf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DCF4ULL;
}

// Func #1027 | PC: 0x05dd44..0x05dd84 (64 B) | Symbol: sub_05dd44
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_05dd44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DD44ULL;
}

// Func #1028 | PC: 0x05de0c..0x05de4c (64 B) | Symbol: sub_05de0c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05de0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DE0CULL;
}

// Func #1029 | PC: 0x05de68..0x05dea8 (64 B) | Symbol: sub_05de68
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05de68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DE68ULL;
}

// Func #1030 | PC: 0x05dec4..0x05df04 (64 B) | Symbol: sub_05dec4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05dec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DEC4ULL;
}

// Func #1031 | PC: 0x05df20..0x05df60 (64 B) | Symbol: sub_05df20
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05df20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DF20ULL;
}

// Func #1032 | PC: 0x05df7c..0x05dfbc (64 B) | Symbol: sub_05df7c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05df7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DF7CULL;
}

// Func #1033 | PC: 0x05dfd8..0x05e018 (64 B) | Symbol: sub_05dfd8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_05dfd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DFD8ULL;
}

// Func #1034 | PC: 0x05e034..0x05e074 (64 B) | Symbol: sub_05e034
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05e034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E034ULL;
}

// Func #1035 | PC: 0x05e174..0x05e1b4 (64 B) | Symbol: sub_05e174
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7a3e0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7a3e0]
uint64_t fde_sub_05e174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E174ULL;
}

// Func #1036 | PC: 0x05e1ec..0x05e22c (64 B) | Symbol: sub_05e1ec
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]; stp x22, x21, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]; stp x22, x21, [sp, #0x140]]
uint64_t fde_sub_05e1ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91267FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E1ECULL;
}

// Func #1037 | PC: 0x05e744..0x05e784 (64 B) | Symbol: sub_05e744
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05e744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E744ULL;
}

// Func #1038 | PC: 0x05e768..0x05e7a8 (64 B) | Symbol: sub_05e768
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05e768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E768ULL;
}

// Func #1039 | PC: 0x05e7f8..0x05e838 (64 B) | Symbol: sub_05e7f8
// EN: AArch64 prologue [sub sp, sp, #0x2f0; bl #0x7b9bc; stur x8, [x29, #-0x68]; cbz x1, #0x5ea3c] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x2f0; bl #0x7b9bc; stur x8, [x29, #-0x68]; cbz x1, #0x5ea3c]
uint64_t fde_sub_05e7f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007470ULL) << 32) | 0xD10BC3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E7F8ULL;
}

// Func #1040 | PC: 0x05ee90..0x05eed0 (64 B) | Symbol: sub_05ee90
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05ee90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EE90ULL;
}

// Func #1041 | PC: 0x05eec8..0x05ef08 (64 B) | Symbol: sub_05eec8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05eec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EEC8ULL;
}

// Func #1042 | PC: 0x05ef18..0x05ef58 (64 B) | Symbol: sub_05ef18
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7aa88] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7aa88]
uint64_t fde_sub_05ef18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EF18ULL;
}

// Func #1043 | PC: 0x05ef58..0x05ef98 (64 B) | Symbol: sub_05ef58
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w9, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w9, [x0]]
uint64_t fde_sub_05ef58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EF58ULL;
}

// Func #1044 | PC: 0x05efcc..0x05f00c (64 B) | Symbol: sub_05efcc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w9, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w9, [x0]]
uint64_t fde_sub_05efcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFCCULL;
}

// Func #1045 | PC: 0x05f054..0x05f094 (64 B) | Symbol: sub_05f054
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05f054(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F054ULL;
}

// Func #1046 | PC: 0x05f0bc..0x05f0fc (64 B) | Symbol: sub_05f0bc
// EN: AArch64 prologue [sub sp, sp, #0x270; mrs x25, tpidr_el0; ldr x8, [x25, #0x28]; bl #0x79528] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x270; mrs x25, tpidr_el0; ldr x8, [x25, #0x28]; bl #0x79528]
uint64_t fde_sub_05f0bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD059ULL) << 32) | 0xD109C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F0BCULL;
}

// Func #1047 | PC: 0x05f4e0..0x05f520 (64 B) | Symbol: sub_05f4e0
// EN: AArch64 prologue [sub sp, sp, #0x1a0; stp x28, x23, [sp, #0x160]; stp x22, x21, [sp, #0x170]; stp x20, x19, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; stp x28, x23, [sp, #0x160]; stp x22, x21, [sp, #0x170]; stp x20, x19, [sp, #0x180]]
uint64_t fde_sub_05f4e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9165FFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F4E0ULL;
}

// Func #1048 | PC: 0x05f864..0x05f8a4 (64 B) | Symbol: sub_05f864
// EN: AArch64 prologue [sub sp, sp, #0x3d0; mrs x23, tpidr_el0; ldr x9, [x23, #0x28]; sub w8, w2, #1] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x3d0; mrs x23, tpidr_el0; ldr x9, [x23, #0x28]; sub w8, w2, #1]
uint64_t fde_sub_05f864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD057ULL) << 32) | 0xD10F43FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F864ULL;
}

// Func #1049 | PC: 0x05fed0..0x05ff10 (64 B) | Symbol: sub_05fed0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05fed0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FED0ULL;
}

// Func #1050 | PC: 0x05ff74..0x05ffb4 (64 B) | Symbol: sub_05ff74
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05ff74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FF74ULL;
}

// Func #1051 | PC: 0x05ffbc..0x05fffc (64 B) | Symbol: sub_05ffbc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79298] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79298]
uint64_t fde_sub_05ffbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FFBCULL;
}

// Func #1052 | PC: 0x05ffec..0x06002c (64 B) | Symbol: sub_05ffec
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05ffec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FFECULL;
}

// Func #1053 | PC: 0x060048..0x060088 (64 B) | Symbol: sub_060048
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_060048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060048ULL;
}

// Func #1054 | PC: 0x0600a4..0x0600e4 (64 B) | Symbol: sub_0600a4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0600a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0600A4ULL;
}

// Func #1055 | PC: 0x060100..0x060140 (64 B) | Symbol: sub_060100
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_060100(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060100ULL;
}

// Func #1056 | PC: 0x06015c..0x06019c (64 B) | Symbol: sub_06015c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06015c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06015CULL;
}

// Func #1057 | PC: 0x0601b8..0x0601f8 (64 B) | Symbol: sub_0601b8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x78450; adrp x8, #0x9d000]
uint64_t fde_sub_0601b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0601B8ULL;
}

// Func #1058 | PC: 0x0601e4..0x060224 (64 B) | Symbol: sub_0601e4
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0601e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0601E4ULL;
}

// Func #1059 | PC: 0x060260..0x0602a0 (64 B) | Symbol: sub_060260
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_060260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060260ULL;
}

// Func #1060 | PC: 0x0602bc..0x0602fc (64 B) | Symbol: sub_0602bc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0602bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0602BCULL;
}

// Func #1061 | PC: 0x060324..0x060364 (64 B) | Symbol: sub_060324
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_060324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060324ULL;
}

// Func #1062 | PC: 0x060380..0x0603c0 (64 B) | Symbol: sub_060380
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_060380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060380ULL;
}

// Func #1063 | PC: 0x0603d4..0x060414 (64 B) | Symbol: sub_0603d4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0603d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603D4ULL;
}

// Func #1064 | PC: 0x06040c..0x06044c (64 B) | Symbol: sub_06040c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0, #8]; bl #0x23740] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0, #8]; bl #0x23740]
uint64_t fde_sub_06040c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06040CULL;
}

// Func #1065 | PC: 0x060448..0x060488 (64 B) | Symbol: sub_060448
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_060448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060448ULL;
}

// Func #1066 | PC: 0x06048c..0x0604cc (64 B) | Symbol: sub_06048c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_06048c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06048CULL;
}

// Func #1067 | PC: 0x0604cc..0x06050c (64 B) | Symbol: sub_0604cc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7eb6c] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7eb6c]
uint64_t fde_sub_0604cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0604CCULL;
}

// Func #1068 | PC: 0x060508..0x060548 (64 B) | Symbol: sub_060508
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c6b0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c6b0]
uint64_t fde_sub_060508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060508ULL;
}

// Func #1069 | PC: 0x060528..0x060568 (64 B) | Symbol: sub_060528
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w9, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w9, [x0]]
uint64_t fde_sub_060528(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060528ULL;
}

// Func #1070 | PC: 0x060598..0x0605d8 (64 B) | Symbol: sub_060598
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7ed08] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7ed08]
uint64_t fde_sub_060598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060598ULL;
}

// Func #1071 | PC: 0x0605c0..0x060600 (64 B) | Symbol: sub_0605c0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, #0x4924; movk x8, #0x2492, lsl #16] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, #0x4924; movk x8, #0x2492, lsl #16]
uint64_t fde_sub_0605c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0605C0ULL;
}

// Func #1072 | PC: 0x06061c..0x06065c (64 B) | Symbol: sub_06061c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06061c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06061CULL;
}

// Func #1073 | PC: 0x060654..0x060694 (64 B) | Symbol: sub_060654
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_060654(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060654ULL;
}

// Func #1074 | PC: 0x0606a4..0x0606e4 (64 B) | Symbol: sub_0606a4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7aa88] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7aa88]
uint64_t fde_sub_0606a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0606A4ULL;
}

// Func #1075 | PC: 0x0606e4..0x060724 (64 B) | Symbol: sub_0606e4
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]; stp x20, x19, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]; stp x20, x19, [sp, #0xc0]]
uint64_t fde_sub_0606e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90053F7ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0606E4ULL;
}

// Func #1076 | PC: 0x060880..0x0608c0 (64 B) | Symbol: sub_060880
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_060880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90557F6ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060880ULL;
}

// Func #1077 | PC: 0x060920..0x060960 (64 B) | Symbol: sub_060920
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]; add x29, sp, #0x80] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]; add x29, sp, #0x80]
uint64_t fde_sub_060920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9074FF4ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060920ULL;
}

// Func #1078 | PC: 0x060994..0x0609d4 (64 B) | Symbol: sub_060994
// EN: AArch64 prologue [str x28, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_060994(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060994ULL;
}

// Func #1079 | PC: 0x0609b0..0x0609f0 (64 B) | Symbol: sub_0609b0
// EN: AArch64 prologue [sub sp, sp, #0x1a0; mrs x26, tpidr_el0; ldr x8, [x26, #0x28]; bl #0x7bcc8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; mrs x26, tpidr_el0; ldr x8, [x26, #0x28]; bl #0x7bcc8]
uint64_t fde_sub_0609b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD05AULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0609B0ULL;
}

// Func #1080 | PC: 0x060ba8..0x060be8 (64 B) | Symbol: sub_060ba8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c6b0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c6b0]
uint64_t fde_sub_060ba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BA8ULL;
}

// Func #1081 | PC: 0x060bd0..0x060c10 (64 B) | Symbol: sub_060bd0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w9, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w9, [x0]]
uint64_t fde_sub_060bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BD0ULL;
}

// Func #1082 | PC: 0x060c3c..0x060c7c (64 B) | Symbol: sub_060c3c
// EN: AArch64 prologue [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_060c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060C3CULL;
}

// Func #1083 | PC: 0x060c54..0x060c94 (64 B) | Symbol: sub_060c54
// EN: AArch64 prologue [sub sp, sp, #0x1c0; mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; bl #0x79528] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; bl #0x79528]
uint64_t fde_sub_060c54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD056ULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060C54ULL;
}

// Func #1084 | PC: 0x060e4c..0x060e8c (64 B) | Symbol: sub_060e4c
// EN: AArch64 prologue [sub sp, sp, #0x1b0; str x28, [sp, #0x170]; stp x22, x21, [sp, #0x180]; stp x20, x19, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; str x28, [sp, #0x170]; stp x22, x21, [sp, #0x180]; stp x20, x19, [sp, #0x190]]
uint64_t fde_sub_060e4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900BBFCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060E4CULL;
}

// Func #1085 | PC: 0x061040..0x061080 (64 B) | Symbol: sub_061040
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz x1, #0x61064; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz x1, #0x61064; ldr x8, [x1]]
uint64_t fde_sub_061040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061040ULL;
}

// Func #1086 | PC: 0x061068..0x0611f0 (392 B) | Symbol: Java_com_benchmark_strategy_nativePort_BXDataProviderPort_native_1getDeviceFeature
// EN: AArch64 prologue [cbz x3, #0x61140; mov x0, x30; bl #0x7ba1c; mov x30, x0] | VI: Khởi đầu hàm AArch64 [cbz x3, #0x61140; mov x0, x30; bl #0x7ba1c; mov x30, x0]
uint64_t fde_sub_061068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E0ULL) << 32) | 0xB40006C3ULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061068ULL;
}

// Func #1087 | PC: 0x061200..0x061240 (64 B) | Symbol: sub_061200
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_061200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061200ULL;
}

// Func #1088 | PC: 0x06121c..0x06124c (48 B) | Symbol: Java_com_benchmark_runtime_nativePort_BXStrategyManagePort_native_1createBenchStrategy
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06121c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06121CULL;
}

// Func #1089 | PC: 0x06124c..0x061264 (24 B) | Symbol: Java_com_benchmark_runtime_nativePort_BXStrategyManagePort_native_1releaseByteBenchStrategy
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7e89c] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7e89c]
uint64_t fde_sub_06124c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06124CULL;
}

// Func #1090 | PC: 0x061264..0x06167c (1048 B) | Symbol: Java_com_benchmark_runtime_nativePort_ByteBenchContextPort_native_1init
// EN: AArch64 prologue [mov x0, x30; bl #0x784e0; mov x30, x0; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x0, x30; bl #0x784e0; mov x30, x0; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_061264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005C9EULL) << 32) | 0xAA1E03E0ULL;
    const uint64_t kPcRange = 0x0418ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061264ULL;
}

// Func #1091 | PC: 0x061278..0x0612b8 (64 B) | Symbol: sub_061278
// EN: AArch64 prologue [sub sp, sp, #0x1f0; mrs x28, tpidr_el0; ldr x8, [x28, #0x28]; add x0, sp, #0x98] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1f0; mrs x28, tpidr_el0; ldr x8, [x28, #0x28]; add x0, sp, #0x98]
uint64_t fde_sub_061278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD05CULL) << 32) | 0xD107C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061278ULL;
}

// Func #1092 | PC: 0x06167c..0x0616bc (64 B) | Symbol: sub_06167c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06167c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06167CULL;
}

// Func #1093 | PC: 0x061748..0x061770 (40 B) | Symbol: Java_com_benchmark_runtime_nativePort_ByteBenchContextPort_native_1initAsync
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x86000; adrp x1, #0x86000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x86000; adrp x1, #0x86000]
uint64_t fde_sub_061748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061748ULL;
}

// Func #1094 | PC: 0x061770..0x0619d8 (616 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1init
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]]
uint64_t fde_sub_061770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E6FFCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061770ULL;
}

// Func #1095 | PC: 0x0619d8..0x061a18 (64 B) | Symbol: sub_0619d8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldp x8, x9, [x0]; mov w10, #0x18] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldp x8, x9, [x0]; mov w10, #0x18]
uint64_t fde_sub_0619d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0619D8ULL;
}

// Func #1096 | PC: 0x061a0c..0x061aa4 (152 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1openRepo
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]; stp x29, x30, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]; stp x29, x30, [sp, #0xb0]]
uint64_t fde_sub_061a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF5ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061A0CULL;
}

// Func #1097 | PC: 0x061aa4..0x061b58 (180 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1contains
// EN: AArch64 prologue [mov x1, x30; bl #0x797cc; mov x30, x1; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x797cc; mov x30, x1; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_061aa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005F49ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061AA4ULL;
}

// Func #1098 | PC: 0x061b58..0x061c80 (296 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainIntStrategy
// EN: AArch64 prologue [mov x1, x30; bl #0x79b00; mov x30, x1; stp x29, x30, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x79b00; mov x30, x1; stp x29, x30, [sp, #0xd0]]
uint64_t fde_sub_061b58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005FE9ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061B58ULL;
}

// Func #1099 | PC: 0x061c80..0x061e04 (388 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainFloatStrategy
// EN: AArch64 prologue [sub sp, sp, #0xe0; str d8, [sp, #0x70]; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str d8, [sp, #0x70]; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]]
uint64_t fde_sub_061c80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD003BE8ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061C80ULL;
}

// Func #1100 | PC: 0x061e04..0x061f48 (324 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainLongStrategy
// EN: AArch64 prologue [mov x1, x30; bl #0x79b00; mov x30, x1; stp x29, x30, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x79b00; mov x30, x1; stp x29, x30, [sp, #0xd0]]
uint64_t fde_sub_061e04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005F3EULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061E04ULL;
}

// Func #1101 | PC: 0x061f48..0x06208c (324 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainBoolStrategy
// EN: AArch64 prologue [mov x1, x30; bl #0x79b00; mov x30, x1; stp x29, x30, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x79b00; mov x30, x1; stp x29, x30, [sp, #0xd0]]
uint64_t fde_sub_061f48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005EEDULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061F48ULL;
}

// Func #1102 | PC: 0x06208c..0x062234 (424 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainStrStrategy
// EN: AArch64 prologue [mov x1, x30; bl #0x7d664; mov x30, x1; stp x29, x30, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x7d664; mov x30, x1; stp x29, x30, [sp, #0x100]]
uint64_t fde_sub_06208c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006D75ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06208CULL;
}

// Func #1103 | PC: 0x062234..0x062338 (260 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainStaticIntStrategy
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_062234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062234ULL;
}

// Func #1104 | PC: 0x062338..0x06244c (276 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainStaticFloatStrategy
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x20]; str x25, [sp, #0x28]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x20]; str x25, [sp, #0x28]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_062338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062338ULL;
}

// Func #1105 | PC: 0x06244c..0x062584 (312 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainStaticLongStrategy
// EN: AArch64 prologue [sub sp, sp, #0xa0; mov x1, x30; bl #0x7b8a8; mov x30, x1] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; mov x1, x30; bl #0x7b8a8; mov x30, x1]
uint64_t fde_sub_06244c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E1ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06244CULL;
}

// Func #1106 | PC: 0x062584..0x0626d4 (336 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainStaticBoolStrategy
// EN: AArch64 prologue [sub sp, sp, #0x90; mov x1, x30; bl #0x79624; mov x30, x1] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; mov x1, x30; bl #0x79624; mov x30, x1]
uint64_t fde_sub_062584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E1ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062584ULL;
}

// Func #1107 | PC: 0x0626d4..0x0628d8 (516 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1obtainStaticStrStrategy
// EN: AArch64 prologue [sub sp, sp, #0x100; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]; stp x22, x21, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]; stp x22, x21, [sp, #0xd0]]
uint64_t fde_sub_0626d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90B67FAULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0626D4ULL;
}

// Func #1108 | PC: 0x0628d8..0x062918 (64 B) | Symbol: sub_0628d8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0628d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0628D8ULL;
}

// Func #1109 | PC: 0x0629e4..0x062a24 (64 B) | Symbol: sub_0629e4
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; mov x3, x30; bl #0x78eb0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; mov x3, x30; bl #0x78eb0]
uint64_t fde_sub_0629e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0629E4ULL;
}

// Func #1110 | PC: 0x062e3c..0x062e7c (64 B) | Symbol: sub_062e3c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; subs x8, x0, #1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; subs x8, x0, #1]
uint64_t fde_sub_062e3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062E3CULL;
}

// Func #1111 | PC: 0x062efc..0x062f3c (64 B) | Symbol: sub_062efc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x62f78] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x62f78]
uint64_t fde_sub_062efc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062EFCULL;
}

// Func #1112 | PC: 0x063068..0x063204 (412 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1registerIntStrategy
// EN: AArch64 prologue [mov x6, x30; bl #0x793f4; mov x30, x6; stp x29, x30, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x793f4; mov x30, x6; stp x29, x30, [sp, #0x120]]
uint64_t fde_sub_063068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940058E2ULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063068ULL;
}

// Func #1113 | PC: 0x063204..0x063244 (64 B) | Symbol: sub_063204
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x78888] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x78888]
uint64_t fde_sub_063204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063204ULL;
}

// Func #1114 | PC: 0x063228..0x063268 (64 B) | Symbol: sub_063228
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063228ULL;
}

// Func #1115 | PC: 0x063244..0x063284 (64 B) | Symbol: sub_063244
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063244ULL;
}

// Func #1116 | PC: 0x06328c..0x0632cc (64 B) | Symbol: sub_06328c
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06328c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06328CULL;
}

// Func #1117 | PC: 0x063318..0x063358 (64 B) | Symbol: sub_063318
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110]
uint64_t fde_sub_063318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9104FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063318ULL;
}

// Func #1118 | PC: 0x063350..0x063390 (64 B) | Symbol: sub_063350
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000]
uint64_t fde_sub_063350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063350ULL;
}

// Func #1119 | PC: 0x063374..0x0633b4 (64 B) | Symbol: sub_063374
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063374ULL;
}

// Func #1120 | PC: 0x063398..0x0633d8 (64 B) | Symbol: sub_063398
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7a058] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7a058]
uint64_t fde_sub_063398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063398ULL;
}

// Func #1121 | PC: 0x0633b8..0x0635d0 (536 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1registerFloatStrategy
// EN: AArch64 prologue [sub sp, sp, #0x140; str d8, [sp, #0xd0]; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; str d8, [sp, #0xd0]; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]]
uint64_t fde_sub_0633b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD006BE8ULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0633B8ULL;
}

// Func #1122 | PC: 0x0635dc..0x06361c (64 B) | Symbol: sub_0635dc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0635dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0635DCULL;
}

// Func #1123 | PC: 0x0635f8..0x063638 (64 B) | Symbol: sub_0635f8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0635f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0635F8ULL;
}

// Func #1124 | PC: 0x063640..0x063680 (64 B) | Symbol: sub_063640
// EN: AArch64 prologue [sub sp, sp, #0x40; str d8, [sp, #0x10]; str x21, [sp, #0x18]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str d8, [sp, #0x10]; str x21, [sp, #0x18]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_063640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063640ULL;
}

// Func #1125 | PC: 0x0636f0..0x063730 (64 B) | Symbol: sub_0636f0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000]
uint64_t fde_sub_0636f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0636F0ULL;
}

// Func #1126 | PC: 0x063714..0x063754 (64 B) | Symbol: sub_063714
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063714(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063714ULL;
}

// Func #1127 | PC: 0x063730..0x0638cc (412 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1registerLongStrategy
// EN: AArch64 prologue [mov x6, x30; bl #0x793f4; mov x30, x6; stp x29, x30, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x793f4; mov x30, x6; stp x29, x30, [sp, #0x120]]
uint64_t fde_sub_063730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005730ULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063730ULL;
}

// Func #1128 | PC: 0x0638d8..0x063918 (64 B) | Symbol: sub_0638d8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0638d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0638D8ULL;
}

// Func #1129 | PC: 0x0638f4..0x063934 (64 B) | Symbol: sub_0638f4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0638f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0638F4ULL;
}

// Func #1130 | PC: 0x06393c..0x06397c (64 B) | Symbol: sub_06393c
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06393c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06393CULL;
}

// Func #1131 | PC: 0x0639e0..0x063a20 (64 B) | Symbol: sub_0639e0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9d000]
uint64_t fde_sub_0639e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0639E0ULL;
}

// Func #1132 | PC: 0x063a04..0x063a44 (64 B) | Symbol: sub_063a04
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A04ULL;
}

// Func #1133 | PC: 0x063a20..0x063bc8 (424 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1registerBoolStrategy
// EN: AArch64 prologue [mov x6, x30; bl #0x793f4; mov x30, x6; stp x29, x30, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x793f4; mov x30, x6; stp x29, x30, [sp, #0x120]]
uint64_t fde_sub_063a20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005674ULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A20ULL;
}

// Func #1134 | PC: 0x063bd4..0x063c14 (64 B) | Symbol: sub_063bd4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063bd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063BD4ULL;
}

// Func #1135 | PC: 0x063bf0..0x063c30 (64 B) | Symbol: sub_063bf0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063bf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063BF0ULL;
}

// Func #1136 | PC: 0x063c38..0x063c78 (64 B) | Symbol: sub_063c38
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_063c38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063C38ULL;
}

// Func #1137 | PC: 0x063cc4..0x063d04 (64 B) | Symbol: sub_063cc4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9e000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9e000]
uint64_t fde_sub_063cc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063CC4ULL;
}

// Func #1138 | PC: 0x063ce8..0x063d28 (64 B) | Symbol: sub_063ce8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063ce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063CE8ULL;
}

// Func #1139 | PC: 0x063d04..0x063f80 (636 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1registerStrStrategy
// EN: AArch64 prologue [mov x6, x30; bl #0x7a16c; mov x30, x6; stp x29, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x7a16c; mov x30, x6; stp x29, x30, [sp, #0x160]]
uint64_t fde_sub_063d04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005919ULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x027CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063D04ULL;
}

// Func #1140 | PC: 0x063f8c..0x063fcc (64 B) | Symbol: sub_063f8c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063f8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063F8CULL;
}

// Func #1141 | PC: 0x063fa8..0x063fe8 (64 B) | Symbol: sub_063fa8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063FA8ULL;
}

// Func #1142 | PC: 0x063ff0..0x064030 (64 B) | Symbol: sub_063ff0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_063ff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063FF0ULL;
}

// Func #1143 | PC: 0x0640d0..0x064110 (64 B) | Symbol: sub_0640d0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9e000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9e000]
uint64_t fde_sub_0640d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0640D0ULL;
}

// Func #1144 | PC: 0x0640f4..0x064134 (64 B) | Symbol: sub_0640f4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0640f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0640F4ULL;
}

// Func #1145 | PC: 0x064118..0x064158 (64 B) | Symbol: sub_064118
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_064118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064118ULL;
}

// Func #1146 | PC: 0x064140..0x0643ac (620 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1unregisterStrategy
// EN: AArch64 prologue [mov x1, x30; bl #0x7915c; mov x30, x1; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x7915c; mov x30, x1; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_064140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005406ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x026CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064140ULL;
}

// Func #1147 | PC: 0x0643ac..0x0644b8 (268 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1clearStrategyCache
// EN: AArch64 prologue [mov x1, x30; bl #0x7a374; mov x30, x1; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x7a374; mov x30, x1; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_0643ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940057F1ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0643ACULL;
}

// Func #1148 | PC: 0x0644b8..0x064708 (592 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1getDeviceAllFeatureForServer
// EN: AArch64 prologue [mov x1, x30; bl #0x7915c; mov x30, x1; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x7915c; mov x30, x1; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_0644b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005328ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0250ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0644B8ULL;
}

// Func #1149 | PC: 0x064708..0x0648bc (436 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1getAllChildrenSpaceID
// EN: AArch64 prologue [sub sp, sp, #0xd0; str x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]; stp x22, x21, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]; stp x22, x21, [sp, #0xa0]]
uint64_t fde_sub_064708(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043F9ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064708ULL;
}

// Func #1150 | PC: 0x0648bc..0x064cbc (1024 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1getOneSpaceStrategyList
// EN: AArch64 prologue [sub sp, sp, #0x1d0; str d8, [sp, #0x160]; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1d0; str d8, [sp, #0x160]; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]]
uint64_t fde_sub_0648bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00B3E8ULL) << 32) | 0xD10743FFULL;
    const uint64_t kPcRange = 0x0400ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0648BCULL;
}

// Func #1151 | PC: 0x064cbc..0x065098 (988 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1getOneSpaceKeyList
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x27, [sp, #0xf0]; stp x26, x25, [sp, #0x100]; stp x24, x23, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x27, [sp, #0xf0]; stp x26, x25, [sp, #0x100]; stp x24, x23, [sp, #0x110]]
uint64_t fde_sub_064cbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F6FFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x03DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064CBCULL;
}

// Func #1152 | PC: 0x065098..0x065254 (444 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchStrategyPort_native_1registerBXStrategyInfoCallback
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]]
uint64_t fde_sub_065098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF9ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x01BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065098ULL;
}

// Func #1153 | PC: 0x065254..0x065294 (64 B) | Symbol: sub_065254
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_065254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065254ULL;
}

// Func #1154 | PC: 0x06528c..0x0652cc (64 B) | Symbol: sub_06528c
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_06528c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06528CULL;
}

// Func #1155 | PC: 0x065350..0x0653c0 (112 B) | Symbol: Java_com_benchmark_port_nativePort_BSModuleInvoker_nativeSetJsWorker
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x281cc] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x281cc]
uint64_t fde_sub_065350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065350ULL;
}

// Func #1156 | PC: 0x0653c0..0x06552c (364 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchFeatureCenterPort_native_1setEventSource
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]; stp x22, x21, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]; stp x22, x21, [sp, #0xf0]]
uint64_t fde_sub_0653c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9006BFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0653C0ULL;
}

// Func #1157 | PC: 0x06552c..0x0655f8 (204 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchFeatureCenterPort_native_1updateStrFeatureValue
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_06552c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9045FF8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06552CULL;
}

// Func #1158 | PC: 0x0655f8..0x06568c (148 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchFeatureCenterPort_native_1updateNumberFeatureValue
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_0655f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0655F8ULL;
}

// Func #1159 | PC: 0x06568c..0x065858 (460 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchFeatureCenterPort_native_1registerComponent
// EN: AArch64 prologue [mov x3, x30; bl #0x7ce8c; mov x30, x3; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x7ce8c; mov x30, x3; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_06568c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005DFFULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06568CULL;
}

// Func #1160 | PC: 0x065868..0x0658a8 (64 B) | Symbol: sub_065868
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_065868(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065868ULL;
}

// Func #1161 | PC: 0x065884..0x0658c4 (64 B) | Symbol: sub_065884
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79b94] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79b94]
uint64_t fde_sub_065884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065884ULL;
}

// Func #1162 | PC: 0x0658f4..0x065934 (64 B) | Symbol: sub_0658f4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c65c] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c65c]
uint64_t fde_sub_0658f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0658F4ULL;
}

// Func #1163 | PC: 0x06590c..0x06594c (64 B) | Symbol: sub_06590c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_06590c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06590CULL;
}

// Func #1164 | PC: 0x0659e8..0x065a28 (64 B) | Symbol: sub_0659e8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0659e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0659E8ULL;
}

// Func #1165 | PC: 0x065a04..0x065a44 (64 B) | Symbol: sub_065a04
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79b94] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79b94]
uint64_t fde_sub_065a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A04ULL;
}

// Func #1166 | PC: 0x065a70..0x065ab0 (64 B) | Symbol: sub_065a70
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_065a70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90457F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A70ULL;
}

// Func #1167 | PC: 0x065b6c..0x065bac (64 B) | Symbol: sub_065b6c
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110]
uint64_t fde_sub_065b6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9104FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065B6CULL;
}

// Func #1168 | PC: 0x065bac..0x065bec (64 B) | Symbol: sub_065bac
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_065bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065BACULL;
}

// Func #1169 | PC: 0x065bc8..0x065c08 (64 B) | Symbol: sub_065bc8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79b94] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79b94]
uint64_t fde_sub_065bc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065BC8ULL;
}

// Func #1170 | PC: 0x065c34..0x065c74 (64 B) | Symbol: sub_065c34
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x40]; str x21, [sp, #0x48]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x40]; str x21, [sp, #0x48]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_065c34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0023E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065C34ULL;
}

// Func #1171 | PC: 0x065d04..0x065d44 (64 B) | Symbol: sub_065d04
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9e000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9e000]
uint64_t fde_sub_065d04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065D04ULL;
}

// Func #1172 | PC: 0x065d28..0x065d68 (64 B) | Symbol: sub_065d28
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_065d28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065D28ULL;
}

// Func #1173 | PC: 0x065d4c..0x065d8c (64 B) | Symbol: sub_065d4c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_065d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065D4CULL;
}

// Func #1174 | PC: 0x065d84..0x065e50 (204 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchFeatureCenterPort_native_1registerFeaturePool
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_065d84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9045FF8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065D84ULL;
}

// Func #1175 | PC: 0x065e50..0x065f44 (244 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchFeatureCenterPort_native_1unregisterFeaturePool
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]]
uint64_t fde_sub_065e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075FF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065E50ULL;
}

// Func #1176 | PC: 0x065f44..0x065fc8 (132 B) | Symbol: Java_com_benchmark_strategy_nativePort_ByteBenchFeatureCenterPort_native_1unregisterFeaturePoolAll
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_065f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F44ULL;
}

// Func #1177 | PC: 0x065fc8..0x066008 (64 B) | Symbol: sub_065fc8
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_065fc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065FC8ULL;
}

// Func #1178 | PC: 0x066028..0x066068 (64 B) | Symbol: sub_066028
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0xa0000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0xa0000]
uint64_t fde_sub_066028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066028ULL;
}

// Func #1179 | PC: 0x066108..0x066158 (80 B) | Symbol: BX_ExceptionCheck__catchAll
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_066108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066108ULL;
}

// Func #1180 | PC: 0x066158..0x066198 (64 B) | Symbol: sub_066158
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_066158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066158ULL;
}

// Func #1181 | PC: 0x066204..0x0663a0 (412 B) | Symbol: JNI_OnLoad
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_066204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066204ULL;
}

// Func #1182 | PC: 0x0663a4..0x0663e4 (64 B) | Symbol: sub_0663a4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x19, #0xa0000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x19, #0xa0000]
uint64_t fde_sub_0663a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0663A4ULL;
}

// Func #1183 | PC: 0x0663e0..0x06642c (76 B) | Symbol: BX_FindClass
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x66420] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x66420]
uint64_t fde_sub_0663e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0663E0ULL;
}

// Func #1184 | PC: 0x06642c..0x066438 (12 B) | Symbol: JNI_OnUnload
// EN: AArch64 prologue [adrp x8, #0xa0000; ldr w0, [x8, #0x65c]; b #0x23aa0] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xa0000; ldr w0, [x8, #0x65c]; b #0x23aa0]
uint64_t fde_sub_06642c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9465D00ULL) << 32) | 0xD00001C8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06642CULL;
}

// Func #1185 | PC: 0x06644c..0x06648c (64 B) | Symbol: sub_06644c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79298] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79298]
uint64_t fde_sub_06644c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06644CULL;
}

// Func #1186 | PC: 0x066474..0x06649c (40 B) | Symbol: _ZN9bytebench11CJClassBaseC2ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7db38] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7db38]
uint64_t fde_sub_066474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066474ULL;
}

// Func #1187 | PC: 0x06649c..0x0664bc (32 B) | Symbol: _ZN9bytebench11CJClassBaseD2Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7db38] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7db38]
uint64_t fde_sub_06649c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06649CULL;
}

// Func #1188 | PC: 0x0664bc..0x0664c0 (4 B) | Symbol: _ZN9bytebench11CJClassBaseD0Ev
// EN: AArch64 prologue [brk #1] | VI: Khởi đầu hàm AArch64 [brk #1]
uint64_t fde_sub_0664bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD4200020ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0664BCULL;
}

// Func #1189 | PC: 0x0664c0..0x066584 (196 B) | Symbol: _ZN9bytebench11CJClassBase4initEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0664c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0664C0ULL;
}

// Func #1190 | PC: 0x066584..0x06662c (168 B) | Symbol: _ZN9bytebench11CJClassBase4initEP7_JNIEnvP8_jobject
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_066584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066584ULL;
}

// Func #1191 | PC: 0x06662c..0x066694 (104 B) | Symbol: _ZN9bytebench11CJClassBase7releaseEv
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06662c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06662CULL;
}

// Func #1192 | PC: 0x066694..0x0666d4 (64 B) | Symbol: sub_066694
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_066694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066694ULL;
}

// Func #1193 | PC: 0x066704..0x0667bc (184 B) | Symbol: _ZN9bytebench11CJClassBase13registerClassERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEP7_JNIEnvRP7_jclass
// EN: AArch64 prologue [mov x3, x30; bl #0x797cc; mov x30, x3; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x797cc; mov x30, x3; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_066704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004C31ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066704ULL;
}

// Func #1194 | PC: 0x0667bc..0x0667d4 (24 B) | Symbol: _ZN9bytebench11CJClassBase8getClassERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x66694; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x66694; ldr x0, [x0]]
uint64_t fde_sub_0667bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0667BCULL;
}

// Func #1195 | PC: 0x0667d4..0x0667e8 (20 B) | Symbol: _ZN16CJniRegistrationC2ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE
// EN: AArch64 prologue [ldrb w8, [x1]; ldr x9, [x1, #0x10]; tst w8, #1; csinc x0, x9, x1, ne] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x1]; ldr x9, [x1, #0x10]; tst w8, #1; csinc x0, x9, x1, ne]
uint64_t fde_sub_0667d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400829ULL) << 32) | 0x39400028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0667D4ULL;
}

// Func #1196 | PC: 0x0667e8..0x066804 (28 B) | Symbol: _ZN9bytebench5CTime3nowEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x23ac0; mov w8, #0x3e8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x23ac0; mov w8, #0x3e8]
uint64_t fde_sub_0667e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0667E8ULL;
}

// Func #1197 | PC: 0x066804..0x066828 (36 B) | Symbol: _ZN9bytebench5CTime13updateWithNowEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c654] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c654]
uint64_t fde_sub_066804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066804ULL;
}

// Func #1198 | PC: 0x066828..0x066850 (40 B) | Symbol: _ZN9bytebench5CTime6elapseEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c654] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c654]
uint64_t fde_sub_066828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066828ULL;
}

// Func #1199 | PC: 0x066850..0x066880 (48 B) | Symbol: _ZN9bytebench5CTime8elapseMSEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c654] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c654]
uint64_t fde_sub_066850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066850ULL;
}

// Func #1200 | PC: 0x066880..0x0668b0 (48 B) | Symbol: _ZN9bytebench5CTime7elapseSEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c654] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7c654]
uint64_t fde_sub_066880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066880ULL;
}

// Func #1201 | PC: 0x0668b0..0x0668bc (12 B) | Symbol: _ZN9bytebench6CUtils4flipEt
// EN: AArch64 prologue [rev w8, w0; lsr w0, w8, #0x10; ret] | VI: Khởi đầu hàm AArch64 [rev w8, w0; lsr w0, w8, #0x10; ret]
uint64_t fde_sub_0668b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53107D00ULL) << 32) | 0x5AC00808ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0668B0ULL;
}

// Func #1202 | PC: 0x0668bc..0x0668c4 (8 B) | Symbol: _ZN9bytebench6CUtils4flipEj
// EN: AArch64 prologue [rev w0, w0; ret] | VI: Khởi đầu hàm AArch64 [rev w0, w0; ret]
uint64_t fde_sub_0668bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5AC00800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0668BCULL;
}

// Func #1203 | PC: 0x0668c4..0x066944 (128 B) | Symbol: _ZN9bytebench6CUtils14writeData2FileEPKcPKvj
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0668c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0668C4ULL;
}

// Func #1204 | PC: 0x066944..0x066b58 (532 B) | Symbol: _ZN9bytebench6CUtils13writeBMP2FileEPKcPKviii
// EN: AArch64 prologue [mov x5, x30; bl #0x78c68; mov x30, x5; stp x29, x30, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x78c68; mov x30, x5; stp x29, x30, [sp, #0xc0]]
uint64_t fde_sub_066944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940048C8ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x0214ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066944ULL;
}

// Func #1205 | PC: 0x066b58..0x066bb8 (96 B) | Symbol: _ZN9bytebench6CUtils11strSafeCopyERPcS1_
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_066b58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066B58ULL;
}

// Func #1206 | PC: 0x066bb8..0x066c14 (92 B) | Symbol: _ZN9bytebench6CUtils10NV12ToI420EPhS1_S1_S1_S1_ii
// EN: AArch64 prologue [mul w9, w6, w5; mov x8, xzr; sxtw x9, w9; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [mul w9, w6, w5; mov x8, xzr; sxtw x9, w9; cmp x8, x9]
uint64_t fde_sub_066bb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0x1B057CC9ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066BB8ULL;
}

// Func #1207 | PC: 0x066c14..0x066d00 (236 B) | Symbol: _ZN9bytebench6CUtils20video_calculate_psnrEPNS_24VideoI420MemoryInterfaceES2_Pd
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x60]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x60]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_066c14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0x6DBA23E9ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066C14ULL;
}

// Func #1208 | PC: 0x066d00..0x066d80 (128 B) | Symbol: _ZN9bytebench6CUtils13CalcFramePsnrEPhS1_ii
// EN: AArch64 prologue [fmov d0, xzr; cbz x0, #0x66d7c; cbz x1, #0x66d7c; cmp w2, #1] | VI: Khởi đầu hàm AArch64 [fmov d0, xzr; cbz x0, #0x66d7c; cbz x1, #0x66d7c; cmp w2, #1]
uint64_t fde_sub_066d00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40003C0ULL) << 32) | 0x9E6703E0ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066D00ULL;
}

// Func #1209 | PC: 0x066d18..0x066d58 (64 B) | Symbol: sub_066d18
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mul w8, w3, w2; mov x9, xzr] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mul w8, w3, w2; mov x9, xzr]
uint64_t fde_sub_066d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066D18ULL;
}

// Func #1210 | PC: 0x066d80..0x066d94 (20 B) | Symbol: _ZN9bytebench6CUtils11annexToAVCCEPai
// EN: AArch64 prologue [sub w8, w1, #4; strh wzr, [x0]; strb wzr, [x0, #2]; strb w8, [x0, #3]] | VI: Khởi đầu hàm AArch64 [sub w8, w1, #4; strh wzr, [x0]; strb wzr, [x0, #2]; strb w8, [x0, #3]]
uint64_t fde_sub_066d80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7900001FULL) << 32) | 0x51001028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066D80ULL;
}

// Func #1211 | PC: 0x066d94..0x066e0c (120 B) | Symbol: _ZN9bytebench6CUtils12getOSVersionEv
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]; add x29, sp, #0x80] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]; add x29, sp, #0x80]
uint64_t fde_sub_066d94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9074FF4ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066D94ULL;
}

// Func #1212 | PC: 0x066e0c..0x066eec (224 B) | Symbol: _ZN9bytebench6CUtils15converTojStringEP7_JNIEnvNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_066e0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066E0CULL;
}

// Func #1213 | PC: 0x066eec..0x066f10 (36 B) | Symbol: _ZN9bytebench6CUtils12isSpecialSarEii
// EN: AArch64 prologue [cmp w0, #0; cset w8, gt; cmp w1, #0; cset w9, gt] | VI: Khởi đầu hàm AArch64 [cmp w0, #0; cset w8, gt; cmp w1, #0; cset w9, gt]
uint64_t fde_sub_066eec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9FD7E8ULL) << 32) | 0x7100001FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066EECULL;
}

// Func #1214 | PC: 0x066f10..0x066fcc (188 B) | Symbol: _ZN9bytebench6CUtils9isInRangeEfRNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_066f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90457F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066F10ULL;
}

// Func #1215 | PC: 0x066fcc..0x06700c (64 B) | Symbol: sub_066fcc
// EN: AArch64 prologue [sub sp, sp, #0xa0; mov x3, x30; bl #0x7b8a8; mov x30, x3] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; mov x3, x30; bl #0x7b8a8; mov x30, x3]
uint64_t fde_sub_066fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066FCCULL;
}

// Func #1216 | PC: 0x0670ec..0x06712c (64 B) | Symbol: sub_0670ec
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0670ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0670ECULL;
}

// Func #1217 | PC: 0x0671a8..0x0671e8 (64 B) | Symbol: sub_0671a8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0671a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0671A8ULL;
}

// Func #1218 | PC: 0x067254..0x067294 (64 B) | Symbol: sub_067254
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]; tbnz w8, #0, #0x6726c] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]; tbnz w8, #0, #0x6726c]
uint64_t fde_sub_067254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067254ULL;
}

// Func #1219 | PC: 0x067334..0x0673c4 (144 B) | Symbol: _ZN9bytebench12BXSimpleJson6putIntERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEi
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_067334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90757F6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067334ULL;
}

// Func #1220 | PC: 0x0673c4..0x067460 (156 B) | Symbol: _ZN9bytebench12BXSimpleJson9putDoubleERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEd
// EN: AArch64 prologue [sub sp, sp, #0xa0; str d8, [sp, #0x70]; str x21, [sp, #0x78]; stp x20, x19, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str d8, [sp, #0x70]; str x21, [sp, #0x78]; stp x20, x19, [sp, #0x80]]
uint64_t fde_sub_0673c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD003BE8ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0673C4ULL;
}

// Func #1221 | PC: 0x067460..0x0674fc (156 B) | Symbol: _ZN9bytebench12BXSimpleJson8putFloatERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEf
// EN: AArch64 prologue [sub sp, sp, #0xa0; str d8, [sp, #0x70]; str x21, [sp, #0x78]; stp x20, x19, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str d8, [sp, #0x70]; str x21, [sp, #0x78]; stp x20, x19, [sp, #0x80]]
uint64_t fde_sub_067460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD003BE8ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067460ULL;
}

// Func #1222 | PC: 0x0674fc..0x067590 (148 B) | Symbol: _ZN9bytebench12BXSimpleJson8putInt64ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEl
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_0674fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90757F6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0674FCULL;
}

// Func #1223 | PC: 0x067590..0x067624 (148 B) | Symbol: _ZN9bytebench12BXSimpleJson9putUInt64ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEm
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_067590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90757F6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067590ULL;
}

// Func #1224 | PC: 0x067624..0x06768c (104 B) | Symbol: _ZN9bytebench12BXSimpleJson8toStringEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_067624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9024FF4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067624ULL;
}

// Func #1225 | PC: 0x06768c..0x067734 (168 B) | Symbol: _ZN9bytebench12BXSimpleJson9putStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]]
uint64_t fde_sub_06768c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF7ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06768CULL;
}

// Func #1226 | PC: 0x067734..0x06773c (8 B) | Symbol: _ZN9bytebench12BXSimpleJson7putBoolERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEb
// EN: AArch64 prologue [and w2, w2, #1; b #0x23b50] | VI: Khởi đầu hàm AArch64 [and w2, w2, #1; b #0x23b50]
uint64_t fde_sub_067734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEF106ULL) << 32) | 0x12000042ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067734ULL;
}

// Func #1227 | PC: 0x06773c..0x067794 (88 B) | Symbol: _ZN9bytebench12BXAppLogUtil10reportJsonEPKcS2_
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_06773c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06773CULL;
}

// Func #1228 | PC: 0x067794..0x0677d4 (64 B) | Symbol: sub_067794
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_067794(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9024FF4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067794ULL;
}

// Func #1229 | PC: 0x0677e0..0x067820 (64 B) | Symbol: sub_0677e0
// EN: AArch64 prologue [sub sp, sp, #0x150; str x28, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; str x28, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]]
uint64_t fde_sub_0677e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9008BFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0677E0ULL;
}

// Func #1230 | PC: 0x067830..0x067870 (64 B) | Symbol: sub_067830
// EN: AArch64 prologue [sub sp, sp, #0x1a0; str x28, [sp, #0x160]; stp x22, x21, [sp, #0x170]; stp x20, x19, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; str x28, [sp, #0x160]; stp x22, x21, [sp, #0x170]; stp x20, x19, [sp, #0x180]]
uint64_t fde_sub_067830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900B3FCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067830ULL;
}

// Func #1231 | PC: 0x067958..0x067998 (64 B) | Symbol: sub_067958
// EN: AArch64 prologue [sub sp, sp, #0x150; str x28, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; str x28, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]]
uint64_t fde_sub_067958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9008BFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067958ULL;
}

// Func #1232 | PC: 0x0679a8..0x0679e8 (64 B) | Symbol: sub_0679a8
// EN: AArch64 prologue [sub sp, sp, #0x150; str x28, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; str x28, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]]
uint64_t fde_sub_0679a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9008BFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0679A8ULL;
}

// Func #1233 | PC: 0x067a1c..0x067a5c (64 B) | Symbol: sub_067a1c
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x0, sp] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x0, sp]
uint64_t fde_sub_067a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067A1CULL;
}

// Func #1234 | PC: 0x067a60..0x067aa0 (64 B) | Symbol: sub_067a60
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_067a60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067A60ULL;
}

// Func #1235 | PC: 0x067ab4..0x067af4 (64 B) | Symbol: sub_067ab4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x23ba0; mov w8, #0x4240] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x23ba0; mov w8, #0x4240]
uint64_t fde_sub_067ab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067AB4ULL;
}

// Func #1236 | PC: 0x067ad4..0x067ba0 (204 B) | Symbol: _ZN9bytebench10CFileUtils14openFileCompatEPKc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_067ad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067AD4ULL;
}

// Func #1237 | PC: 0x067ba0..0x067bc8 (40 B) | Symbol: _ZN9bytebench10CFileUtils19closeFileDescriptorERPNS_15CFileDescriptorE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79298] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x79298]
uint64_t fde_sub_067ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067BA0ULL;
}

// Func #1238 | PC: 0x067bc8..0x067bcc (4 B) | Symbol: _ZN9bytebench10CFileUtils10deleteFileEPKc
// EN: AArch64 prologue [b #0x23bf0] | VI: Khởi đầu hàm AArch64 [b #0x23bf0]
uint64_t fde_sub_067bc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81C0FF7ULL) << 32) | 0x17FEF00AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067BC8ULL;
}

// Func #1239 | PC: 0x067bcc..0x067ca4 (216 B) | Symbol: _ZN9bytebench10CFileUtils9deleteDirEPKc
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_067bcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067BCCULL;
}

// Func #1240 | PC: 0x067ca4..0x067cc4 (32 B) | Symbol: _ZN9bytebench10CFileUtils10isDirExistEPKc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x23c00; cbz x0, #0x67cbc] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x23c00; cbz x0, #0x67cbc]
uint64_t fde_sub_067ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067CA4ULL;
}

// Func #1241 | PC: 0x067cc4..0x067d00 (60 B) | Symbol: _ZN9bytebench10CFileUtils9createDirEPKc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_067cc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067CC4ULL;
}

// Func #1242 | PC: 0x067d00..0x067d1c (28 B) | Symbol: _ZN9bytebench10CFileUtils11isFileExistEPKc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w1, #4; bl #0x23c40] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w1, #4; bl #0x23c40]
uint64_t fde_sub_067d00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067D00ULL;
}

// Func #1243 | PC: 0x067d1c..0x067d5c (64 B) | Symbol: sub_067d1c
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50]
uint64_t fde_sub_067d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9044FF4ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067D1CULL;
}

// Func #1244 | PC: 0x067e10..0x067e50 (64 B) | Symbol: sub_067e10
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_067e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067E10ULL;
}

// Func #1245 | PC: 0x067e70..0x067eb0 (64 B) | Symbol: sub_067e70
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]]
uint64_t fde_sub_067e70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043F7ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067E70ULL;
}

// Func #1246 | PC: 0x068010..0x068788 (1912 B) | Symbol: _ZN9bytebench7CPUInfo12getExtraInfoEv
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]]
uint64_t fde_sub_068010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9106FFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0778ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068010ULL;
}

// Func #1247 | PC: 0x068788..0x068970 (488 B) | Symbol: _ZN9bytebench7CPUInfo23SortCpuidByMaxFrequencyERNSt6__ndk16vectorIiNS1_9allocatorIiEEEEPi
// EN: AArch64 prologue [mov x2, x30; bl #0x7a374; mov x30, x2; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x7a374; mov x30, x2; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_068788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940046FAULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068788ULL;
}

// Func #1248 | PC: 0x068970..0x0689b0 (64 B) | Symbol: sub_068970
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; lsr x8, x1, #0x3e; cbnz x8, #0x689a0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; lsr x8, x1, #0x3e; cbnz x8, #0x689a0]
uint64_t fde_sub_068970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068970ULL;
}

// Func #1249 | PC: 0x0689b4..0x0689f4 (64 B) | Symbol: sub_0689b4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x233b0; ldp x8, x9, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x233b0; ldp x8, x9, [x0, #8]]
uint64_t fde_sub_0689b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0689B4ULL;
}

// Func #1250 | PC: 0x0689e8..0x068ac4 (220 B) | Symbol: _ZN9bytebench7CPUInfo18BXSetSchedAffinityERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x19, [sp, #0x90]; stp x29, x30, [sp, #0xa0]; add x29, sp, #0xa0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x19, [sp, #0x90]; stp x29, x30, [sp, #0xa0]; add x29, sp, #0xa0]
uint64_t fde_sub_0689e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF3ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0689E8ULL;
}

// Func #1251 | PC: 0x068ac4..0x068b7c (184 B) | Symbol: Java_com_benchmark_device_BXDeviceInfo_nativeGetCpuModelName
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_068ac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9024FF4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068AC4ULL;
}

// Func #1252 | PC: 0x068b7c..0x068bc4 (72 B) | Symbol: Java_com_benchmark_device_BXDeviceInfo_nativeGetGLExtensions
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_068b7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068B7CULL;
}

// Func #1253 | PC: 0x068bc4..0x068c04 (64 B) | Symbol: sub_068bc4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0xa0000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0xa0000]
uint64_t fde_sub_068bc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068BC4ULL;
}

// Func #1254 | PC: 0x068c34..0x068c74 (64 B) | Symbol: sub_068c34
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_068c34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068C34ULL;
}

// Func #1255 | PC: 0x068c58..0x068c98 (64 B) | Symbol: sub_068c58
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0]]
uint64_t fde_sub_068c58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068C58ULL;
}

// Func #1256 | PC: 0x068c84..0x068cd8 (84 B) | Symbol: Java_com_benchmark_device_BXDeviceInfo_nativeGetGLRenderer
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_068c84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068C84ULL;
}

// Func #1257 | PC: 0x068cd8..0x068d2c (84 B) | Symbol: Java_com_benchmark_device_BXDeviceInfo_nativeGetGLVendor
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_068cd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068CD8ULL;
}

// Func #1258 | PC: 0x068d2c..0x068d80 (84 B) | Symbol: Java_com_benchmark_device_BXDeviceInfo_nativeGetGLVersion
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_068d2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068D2CULL;
}

// Func #1259 | PC: 0x068d80..0x068e18 (152 B) | Symbol: Java_com_benchmark_device_BXDeviceInfo_nativeGPUInfoInit
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_068d80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068D80ULL;
}

// Func #1260 | PC: 0x068e18..0x068e34 (28 B) | Symbol: Java_com_benchmark_device_BXDeviceInfo_nativeGPUInfoRelease
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x68bc4; add x0, x0, #8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x68bc4; add x0, x0, #8]
uint64_t fde_sub_068e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068E18ULL;
}

// Func #1261 | PC: 0x068e34..0x068e74 (64 B) | Symbol: sub_068e34
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x19, [sp, #0x130]; stp x29, x30, [sp, #0x140]; add x29, sp, #0x140] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x19, [sp, #0x130]; stp x29, x30, [sp, #0x140]; add x29, sp, #0x140]
uint64_t fde_sub_068e34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9134FFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068E34ULL;
}

// Func #1262 | PC: 0x069008..0x069048 (64 B) | Symbol: sub_069008
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110]
uint64_t fde_sub_069008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9104FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069008ULL;
}

// Func #1263 | PC: 0x069084..0x0690c4 (64 B) | Symbol: sub_069084
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_069084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069084ULL;
}

// Func #1264 | PC: 0x0690fc..0x06913c (64 B) | Symbol: sub_0690fc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_0690fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0690FCULL;
}

// Func #1265 | PC: 0x0691ac..0x0691ec (64 B) | Symbol: sub_0691ac
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x1, [x0, #0x18]; cbz x1, #0x691d4] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x1, [x0, #0x18]; cbz x1, #0x691d4]
uint64_t fde_sub_0691ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0691ACULL;
}

// Func #1266 | PC: 0x06a554..0x06a594 (64 B) | Symbol: sub_06a554
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06a554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A554ULL;
}

// Func #1267 | PC: 0x06a584..0x06a5c4 (64 B) | Symbol: sub_06a584
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06a584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A584ULL;
}

// Func #1268 | PC: 0x06a5cc..0x06a60c (64 B) | Symbol: sub_06a5cc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06a5cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A5CCULL;
}

// Func #1269 | PC: 0x06a650..0x06a690 (64 B) | Symbol: sub_06a650
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7edac] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7edac]
uint64_t fde_sub_06a650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A650ULL;
}

// Func #1270 | PC: 0x06a7bc..0x06a7cc (16 B) | Symbol: _ZN9bytebench15CFileDescriptorC2Ev
// EN: AArch64 prologue [mov w8, #-1; str w8, [x0]; str xzr, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #-1; str w8, [x0]; str xzr, [x0, #8]; ret]
uint64_t fde_sub_06a7bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9000008ULL) << 32) | 0x12800008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7BCULL;
}

// Func #1271 | PC: 0x06a7cc..0x06aec0 (1780 B) | Symbol: _ZN9bytebench15CFileDescriptor5getFdERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [mov x2, x30; bl #0x78c84; mov x30, x2; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x78c84; mov x30, x2; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_06a7cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400392DULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x06F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7CCULL;
}

// Func #1272 | PC: 0x06aec0..0x06af00 (64 B) | Symbol: sub_06aec0
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110]
uint64_t fde_sub_06aec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9104FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AEC0ULL;
}

// Func #1273 | PC: 0x06aef0..0x06af30 (64 B) | Symbol: sub_06aef0
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110]
uint64_t fde_sub_06aef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9104FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AEF0ULL;
}

// Func #1274 | PC: 0x06af20..0x06af78 (88 B) | Symbol: _ZN9bytebench15CFileDescriptor9getFdPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7d744] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x7d744]
uint64_t fde_sub_06af20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF20ULL;
}

// Func #1275 | PC: 0x06af78..0x06afb8 (64 B) | Symbol: sub_06af78
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_06af78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF78ULL;
}

// Func #1276 | PC: 0x06afc4..0x06b084 (192 B) | Symbol: _ZN9bytebench15CFileDescriptor7closeFdEv
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06afc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AFC4ULL;
}

// Func #1277 | PC: 0x06b084..0x06b248 (452 B) | Symbol: _Z10BXFFReduceR11STERational
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06b084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B084ULL;
}

// Func #1278 | PC: 0x06b248..0x06b2a0 (88 B) | Symbol: _ZN9bytebench12CShareMemoryC2ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06b248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B248ULL;
}

// Func #1279 | PC: 0x06b2a0..0x06b39c (252 B) | Symbol: _ZN9bytebench12CShareMemory15openShareMemoryEi
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_06b2a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90857F6ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B2A0ULL;
}

uint64_t DispatchByteBenchShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x05af90ULL: return fde_sub_05af90(a0, a1, a2);
        case 0x05b008ULL: return fde_sub_05b008(a0, a1, a2);
        case 0x05b06cULL: return fde_sub_05b06c(a0, a1, a2);
        case 0x05b0b4ULL: return fde_sub_05b0b4(a0, a1, a2);
        case 0x05b11cULL: return fde_sub_05b11c(a0, a1, a2);
        case 0x05b194ULL: return fde_sub_05b194(a0, a1, a2);
        case 0x05b204ULL: return fde_sub_05b204(a0, a1, a2);
        case 0x05b26cULL: return fde_sub_05b26c(a0, a1, a2);
        case 0x05b2ecULL: return fde_sub_05b2ec(a0, a1, a2);
        case 0x05b36cULL: return fde_sub_05b36c(a0, a1, a2);
        case 0x05b478ULL: return fde_sub_05b478(a0, a1, a2);
        case 0x05b4a4ULL: return fde_sub_05b4a4(a0, a1, a2);
        case 0x05b724ULL: return fde_sub_05b724(a0, a1, a2);
        case 0x05b900ULL: return fde_sub_05b900(a0, a1, a2);
        case 0x05b924ULL: return fde_sub_05b924(a0, a1, a2);
        case 0x05bc10ULL: return fde_sub_05bc10(a0, a1, a2);
        case 0x05bde4ULL: return fde_sub_05bde4(a0, a1, a2);
        case 0x05be14ULL: return fde_sub_05be14(a0, a1, a2);
        case 0x05c8acULL: return fde_sub_05c8ac(a0, a1, a2);
        case 0x05c90cULL: return fde_sub_05c90c(a0, a1, a2);
        case 0x05c950ULL: return fde_sub_05c950(a0, a1, a2);
        case 0x05c974ULL: return fde_sub_05c974(a0, a1, a2);
        case 0x05c998ULL: return fde_sub_05c998(a0, a1, a2);
        case 0x05ca00ULL: return fde_sub_05ca00(a0, a1, a2);
        case 0x05ca28ULL: return fde_sub_05ca28(a0, a1, a2);
        case 0x05ca4cULL: return fde_sub_05ca4c(a0, a1, a2);
        case 0x05ca68ULL: return fde_sub_05ca68(a0, a1, a2);
        case 0x05cc68ULL: return fde_sub_05cc68(a0, a1, a2);
        case 0x05cc84ULL: return fde_sub_05cc84(a0, a1, a2);
        case 0x05cd1cULL: return fde_sub_05cd1c(a0, a1, a2);
        case 0x05cd38ULL: return fde_sub_05cd38(a0, a1, a2);
        case 0x05cd80ULL: return fde_sub_05cd80(a0, a1, a2);
        case 0x05cda4ULL: return fde_sub_05cda4(a0, a1, a2);
        case 0x05cdc0ULL: return fde_sub_05cdc0(a0, a1, a2);
        case 0x05d2a4ULL: return fde_sub_05d2a4(a0, a1, a2);
        case 0x05d2b0ULL: return fde_sub_05d2b0(a0, a1, a2);
        case 0x05d2ecULL: return fde_sub_05d2ec(a0, a1, a2);
        case 0x05d35cULL: return fde_sub_05d35c(a0, a1, a2);
        case 0x05d3e0ULL: return fde_sub_05d3e0(a0, a1, a2);
        case 0x05d424ULL: return fde_sub_05d424(a0, a1, a2);
        case 0x05d594ULL: return fde_sub_05d594(a0, a1, a2);
        case 0x05d5b8ULL: return fde_sub_05d5b8(a0, a1, a2);
        case 0x05d5dcULL: return fde_sub_05d5dc(a0, a1, a2);
        case 0x05d648ULL: return fde_sub_05d648(a0, a1, a2);
        case 0x05d698ULL: return fde_sub_05d698(a0, a1, a2);
        case 0x05d6ccULL: return fde_sub_05d6cc(a0, a1, a2);
        case 0x05d6e8ULL: return fde_sub_05d6e8(a0, a1, a2);
        case 0x05d740ULL: return fde_sub_05d740(a0, a1, a2);
        case 0x05d75cULL: return fde_sub_05d75c(a0, a1, a2);
        case 0x05d904ULL: return fde_sub_05d904(a0, a1, a2);
        case 0x05d930ULL: return fde_sub_05d930(a0, a1, a2);
        case 0x05d95cULL: return fde_sub_05d95c(a0, a1, a2);
        case 0x05d994ULL: return fde_sub_05d994(a0, a1, a2);
        case 0x05d9e4ULL: return fde_sub_05d9e4(a0, a1, a2);
        case 0x05da38ULL: return fde_sub_05da38(a0, a1, a2);
        case 0x05da64ULL: return fde_sub_05da64(a0, a1, a2);
        case 0x05daa0ULL: return fde_sub_05daa0(a0, a1, a2);
        case 0x05dadcULL: return fde_sub_05dadc(a0, a1, a2);
        case 0x05db08ULL: return fde_sub_05db08(a0, a1, a2);
        case 0x05db44ULL: return fde_sub_05db44(a0, a1, a2);
        case 0x05db98ULL: return fde_sub_05db98(a0, a1, a2);
        case 0x05dbc4ULL: return fde_sub_05dbc4(a0, a1, a2);
        case 0x05dc14ULL: return fde_sub_05dc14(a0, a1, a2);
        case 0x05dc30ULL: return fde_sub_05dc30(a0, a1, a2);
        case 0x05dc88ULL: return fde_sub_05dc88(a0, a1, a2);
        case 0x05dcd8ULL: return fde_sub_05dcd8(a0, a1, a2);
        case 0x05dcf4ULL: return fde_sub_05dcf4(a0, a1, a2);
        case 0x05dd44ULL: return fde_sub_05dd44(a0, a1, a2);
        case 0x05de0cULL: return fde_sub_05de0c(a0, a1, a2);
        case 0x05de68ULL: return fde_sub_05de68(a0, a1, a2);
        case 0x05dec4ULL: return fde_sub_05dec4(a0, a1, a2);
        case 0x05df20ULL: return fde_sub_05df20(a0, a1, a2);
        case 0x05df7cULL: return fde_sub_05df7c(a0, a1, a2);
        case 0x05dfd8ULL: return fde_sub_05dfd8(a0, a1, a2);
        case 0x05e034ULL: return fde_sub_05e034(a0, a1, a2);
        case 0x05e174ULL: return fde_sub_05e174(a0, a1, a2);
        case 0x05e1ecULL: return fde_sub_05e1ec(a0, a1, a2);
        case 0x05e744ULL: return fde_sub_05e744(a0, a1, a2);
        case 0x05e768ULL: return fde_sub_05e768(a0, a1, a2);
        case 0x05e7f8ULL: return fde_sub_05e7f8(a0, a1, a2);
        case 0x05ee90ULL: return fde_sub_05ee90(a0, a1, a2);
        case 0x05eec8ULL: return fde_sub_05eec8(a0, a1, a2);
        case 0x05ef18ULL: return fde_sub_05ef18(a0, a1, a2);
        case 0x05ef58ULL: return fde_sub_05ef58(a0, a1, a2);
        case 0x05efccULL: return fde_sub_05efcc(a0, a1, a2);
        case 0x05f054ULL: return fde_sub_05f054(a0, a1, a2);
        case 0x05f0bcULL: return fde_sub_05f0bc(a0, a1, a2);
        case 0x05f4e0ULL: return fde_sub_05f4e0(a0, a1, a2);
        case 0x05f864ULL: return fde_sub_05f864(a0, a1, a2);
        case 0x05fed0ULL: return fde_sub_05fed0(a0, a1, a2);
        case 0x05ff74ULL: return fde_sub_05ff74(a0, a1, a2);
        case 0x05ffbcULL: return fde_sub_05ffbc(a0, a1, a2);
        case 0x05ffecULL: return fde_sub_05ffec(a0, a1, a2);
        case 0x060048ULL: return fde_sub_060048(a0, a1, a2);
        case 0x0600a4ULL: return fde_sub_0600a4(a0, a1, a2);
        case 0x060100ULL: return fde_sub_060100(a0, a1, a2);
        case 0x06015cULL: return fde_sub_06015c(a0, a1, a2);
        case 0x0601b8ULL: return fde_sub_0601b8(a0, a1, a2);
        case 0x0601e4ULL: return fde_sub_0601e4(a0, a1, a2);
        case 0x060260ULL: return fde_sub_060260(a0, a1, a2);
        case 0x0602bcULL: return fde_sub_0602bc(a0, a1, a2);
        case 0x060324ULL: return fde_sub_060324(a0, a1, a2);
        case 0x060380ULL: return fde_sub_060380(a0, a1, a2);
        case 0x0603d4ULL: return fde_sub_0603d4(a0, a1, a2);
        case 0x06040cULL: return fde_sub_06040c(a0, a1, a2);
        case 0x060448ULL: return fde_sub_060448(a0, a1, a2);
        case 0x06048cULL: return fde_sub_06048c(a0, a1, a2);
        case 0x0604ccULL: return fde_sub_0604cc(a0, a1, a2);
        case 0x060508ULL: return fde_sub_060508(a0, a1, a2);
        case 0x060528ULL: return fde_sub_060528(a0, a1, a2);
        case 0x060598ULL: return fde_sub_060598(a0, a1, a2);
        case 0x0605c0ULL: return fde_sub_0605c0(a0, a1, a2);
        case 0x06061cULL: return fde_sub_06061c(a0, a1, a2);
        case 0x060654ULL: return fde_sub_060654(a0, a1, a2);
        case 0x0606a4ULL: return fde_sub_0606a4(a0, a1, a2);
        case 0x0606e4ULL: return fde_sub_0606e4(a0, a1, a2);
        case 0x060880ULL: return fde_sub_060880(a0, a1, a2);
        case 0x060920ULL: return fde_sub_060920(a0, a1, a2);
        case 0x060994ULL: return fde_sub_060994(a0, a1, a2);
        case 0x0609b0ULL: return fde_sub_0609b0(a0, a1, a2);
        case 0x060ba8ULL: return fde_sub_060ba8(a0, a1, a2);
        case 0x060bd0ULL: return fde_sub_060bd0(a0, a1, a2);
        case 0x060c3cULL: return fde_sub_060c3c(a0, a1, a2);
        case 0x060c54ULL: return fde_sub_060c54(a0, a1, a2);
        case 0x060e4cULL: return fde_sub_060e4c(a0, a1, a2);
        case 0x061040ULL: return fde_sub_061040(a0, a1, a2);
        case 0x061068ULL: return fde_sub_061068(a0, a1, a2);
        case 0x061200ULL: return fde_sub_061200(a0, a1, a2);
        case 0x06121cULL: return fde_sub_06121c(a0, a1, a2);
        case 0x06124cULL: return fde_sub_06124c(a0, a1, a2);
        case 0x061264ULL: return fde_sub_061264(a0, a1, a2);
        case 0x061278ULL: return fde_sub_061278(a0, a1, a2);
        case 0x06167cULL: return fde_sub_06167c(a0, a1, a2);
        case 0x061748ULL: return fde_sub_061748(a0, a1, a2);
        case 0x061770ULL: return fde_sub_061770(a0, a1, a2);
        case 0x0619d8ULL: return fde_sub_0619d8(a0, a1, a2);
        case 0x061a0cULL: return fde_sub_061a0c(a0, a1, a2);
        case 0x061aa4ULL: return fde_sub_061aa4(a0, a1, a2);
        case 0x061b58ULL: return fde_sub_061b58(a0, a1, a2);
        case 0x061c80ULL: return fde_sub_061c80(a0, a1, a2);
        case 0x061e04ULL: return fde_sub_061e04(a0, a1, a2);
        case 0x061f48ULL: return fde_sub_061f48(a0, a1, a2);
        case 0x06208cULL: return fde_sub_06208c(a0, a1, a2);
        case 0x062234ULL: return fde_sub_062234(a0, a1, a2);
        case 0x062338ULL: return fde_sub_062338(a0, a1, a2);
        case 0x06244cULL: return fde_sub_06244c(a0, a1, a2);
        case 0x062584ULL: return fde_sub_062584(a0, a1, a2);
        case 0x0626d4ULL: return fde_sub_0626d4(a0, a1, a2);
        case 0x0628d8ULL: return fde_sub_0628d8(a0, a1, a2);
        case 0x0629e4ULL: return fde_sub_0629e4(a0, a1, a2);
        case 0x062e3cULL: return fde_sub_062e3c(a0, a1, a2);
        case 0x062efcULL: return fde_sub_062efc(a0, a1, a2);
        case 0x063068ULL: return fde_sub_063068(a0, a1, a2);
        case 0x063204ULL: return fde_sub_063204(a0, a1, a2);
        case 0x063228ULL: return fde_sub_063228(a0, a1, a2);
        case 0x063244ULL: return fde_sub_063244(a0, a1, a2);
        case 0x06328cULL: return fde_sub_06328c(a0, a1, a2);
        case 0x063318ULL: return fde_sub_063318(a0, a1, a2);
        case 0x063350ULL: return fde_sub_063350(a0, a1, a2);
        case 0x063374ULL: return fde_sub_063374(a0, a1, a2);
        case 0x063398ULL: return fde_sub_063398(a0, a1, a2);
        case 0x0633b8ULL: return fde_sub_0633b8(a0, a1, a2);
        case 0x0635dcULL: return fde_sub_0635dc(a0, a1, a2);
        case 0x0635f8ULL: return fde_sub_0635f8(a0, a1, a2);
        case 0x063640ULL: return fde_sub_063640(a0, a1, a2);
        case 0x0636f0ULL: return fde_sub_0636f0(a0, a1, a2);
        case 0x063714ULL: return fde_sub_063714(a0, a1, a2);
        case 0x063730ULL: return fde_sub_063730(a0, a1, a2);
        case 0x0638d8ULL: return fde_sub_0638d8(a0, a1, a2);
        case 0x0638f4ULL: return fde_sub_0638f4(a0, a1, a2);
        case 0x06393cULL: return fde_sub_06393c(a0, a1, a2);
        case 0x0639e0ULL: return fde_sub_0639e0(a0, a1, a2);
        case 0x063a04ULL: return fde_sub_063a04(a0, a1, a2);
        case 0x063a20ULL: return fde_sub_063a20(a0, a1, a2);
        case 0x063bd4ULL: return fde_sub_063bd4(a0, a1, a2);
        case 0x063bf0ULL: return fde_sub_063bf0(a0, a1, a2);
        case 0x063c38ULL: return fde_sub_063c38(a0, a1, a2);
        case 0x063cc4ULL: return fde_sub_063cc4(a0, a1, a2);
        case 0x063ce8ULL: return fde_sub_063ce8(a0, a1, a2);
        case 0x063d04ULL: return fde_sub_063d04(a0, a1, a2);
        case 0x063f8cULL: return fde_sub_063f8c(a0, a1, a2);
        case 0x063fa8ULL: return fde_sub_063fa8(a0, a1, a2);
        case 0x063ff0ULL: return fde_sub_063ff0(a0, a1, a2);
        case 0x0640d0ULL: return fde_sub_0640d0(a0, a1, a2);
        case 0x0640f4ULL: return fde_sub_0640f4(a0, a1, a2);
        case 0x064118ULL: return fde_sub_064118(a0, a1, a2);
        case 0x064140ULL: return fde_sub_064140(a0, a1, a2);
        case 0x0643acULL: return fde_sub_0643ac(a0, a1, a2);
        case 0x0644b8ULL: return fde_sub_0644b8(a0, a1, a2);
        case 0x064708ULL: return fde_sub_064708(a0, a1, a2);
        case 0x0648bcULL: return fde_sub_0648bc(a0, a1, a2);
        case 0x064cbcULL: return fde_sub_064cbc(a0, a1, a2);
        case 0x065098ULL: return fde_sub_065098(a0, a1, a2);
        case 0x065254ULL: return fde_sub_065254(a0, a1, a2);
        case 0x06528cULL: return fde_sub_06528c(a0, a1, a2);
        case 0x065350ULL: return fde_sub_065350(a0, a1, a2);
        case 0x0653c0ULL: return fde_sub_0653c0(a0, a1, a2);
        case 0x06552cULL: return fde_sub_06552c(a0, a1, a2);
        case 0x0655f8ULL: return fde_sub_0655f8(a0, a1, a2);
        case 0x06568cULL: return fde_sub_06568c(a0, a1, a2);
        case 0x065868ULL: return fde_sub_065868(a0, a1, a2);
        case 0x065884ULL: return fde_sub_065884(a0, a1, a2);
        case 0x0658f4ULL: return fde_sub_0658f4(a0, a1, a2);
        case 0x06590cULL: return fde_sub_06590c(a0, a1, a2);
        case 0x0659e8ULL: return fde_sub_0659e8(a0, a1, a2);
        case 0x065a04ULL: return fde_sub_065a04(a0, a1, a2);
        case 0x065a70ULL: return fde_sub_065a70(a0, a1, a2);
        case 0x065b6cULL: return fde_sub_065b6c(a0, a1, a2);
        case 0x065bacULL: return fde_sub_065bac(a0, a1, a2);
        case 0x065bc8ULL: return fde_sub_065bc8(a0, a1, a2);
        case 0x065c34ULL: return fde_sub_065c34(a0, a1, a2);
        case 0x065d04ULL: return fde_sub_065d04(a0, a1, a2);
        case 0x065d28ULL: return fde_sub_065d28(a0, a1, a2);
        case 0x065d4cULL: return fde_sub_065d4c(a0, a1, a2);
        case 0x065d84ULL: return fde_sub_065d84(a0, a1, a2);
        case 0x065e50ULL: return fde_sub_065e50(a0, a1, a2);
        case 0x065f44ULL: return fde_sub_065f44(a0, a1, a2);
        case 0x065fc8ULL: return fde_sub_065fc8(a0, a1, a2);
        case 0x066028ULL: return fde_sub_066028(a0, a1, a2);
        case 0x066108ULL: return fde_sub_066108(a0, a1, a2);
        case 0x066158ULL: return fde_sub_066158(a0, a1, a2);
        case 0x066204ULL: return fde_sub_066204(a0, a1, a2);
        case 0x0663a4ULL: return fde_sub_0663a4(a0, a1, a2);
        case 0x0663e0ULL: return fde_sub_0663e0(a0, a1, a2);
        case 0x06642cULL: return fde_sub_06642c(a0, a1, a2);
        case 0x06644cULL: return fde_sub_06644c(a0, a1, a2);
        case 0x066474ULL: return fde_sub_066474(a0, a1, a2);
        case 0x06649cULL: return fde_sub_06649c(a0, a1, a2);
        case 0x0664bcULL: return fde_sub_0664bc(a0, a1, a2);
        case 0x0664c0ULL: return fde_sub_0664c0(a0, a1, a2);
        case 0x066584ULL: return fde_sub_066584(a0, a1, a2);
        case 0x06662cULL: return fde_sub_06662c(a0, a1, a2);
        case 0x066694ULL: return fde_sub_066694(a0, a1, a2);
        case 0x066704ULL: return fde_sub_066704(a0, a1, a2);
        case 0x0667bcULL: return fde_sub_0667bc(a0, a1, a2);
        case 0x0667d4ULL: return fde_sub_0667d4(a0, a1, a2);
        case 0x0667e8ULL: return fde_sub_0667e8(a0, a1, a2);
        case 0x066804ULL: return fde_sub_066804(a0, a1, a2);
        case 0x066828ULL: return fde_sub_066828(a0, a1, a2);
        case 0x066850ULL: return fde_sub_066850(a0, a1, a2);
        case 0x066880ULL: return fde_sub_066880(a0, a1, a2);
        case 0x0668b0ULL: return fde_sub_0668b0(a0, a1, a2);
        case 0x0668bcULL: return fde_sub_0668bc(a0, a1, a2);
        case 0x0668c4ULL: return fde_sub_0668c4(a0, a1, a2);
        case 0x066944ULL: return fde_sub_066944(a0, a1, a2);
        case 0x066b58ULL: return fde_sub_066b58(a0, a1, a2);
        case 0x066bb8ULL: return fde_sub_066bb8(a0, a1, a2);
        case 0x066c14ULL: return fde_sub_066c14(a0, a1, a2);
        case 0x066d00ULL: return fde_sub_066d00(a0, a1, a2);
        case 0x066d18ULL: return fde_sub_066d18(a0, a1, a2);
        case 0x066d80ULL: return fde_sub_066d80(a0, a1, a2);
        case 0x066d94ULL: return fde_sub_066d94(a0, a1, a2);
        case 0x066e0cULL: return fde_sub_066e0c(a0, a1, a2);
        case 0x066eecULL: return fde_sub_066eec(a0, a1, a2);
        case 0x066f10ULL: return fde_sub_066f10(a0, a1, a2);
        case 0x066fccULL: return fde_sub_066fcc(a0, a1, a2);
        case 0x0670ecULL: return fde_sub_0670ec(a0, a1, a2);
        case 0x0671a8ULL: return fde_sub_0671a8(a0, a1, a2);
        case 0x067254ULL: return fde_sub_067254(a0, a1, a2);
        case 0x067334ULL: return fde_sub_067334(a0, a1, a2);
        case 0x0673c4ULL: return fde_sub_0673c4(a0, a1, a2);
        case 0x067460ULL: return fde_sub_067460(a0, a1, a2);
        case 0x0674fcULL: return fde_sub_0674fc(a0, a1, a2);
        case 0x067590ULL: return fde_sub_067590(a0, a1, a2);
        case 0x067624ULL: return fde_sub_067624(a0, a1, a2);
        case 0x06768cULL: return fde_sub_06768c(a0, a1, a2);
        case 0x067734ULL: return fde_sub_067734(a0, a1, a2);
        case 0x06773cULL: return fde_sub_06773c(a0, a1, a2);
        case 0x067794ULL: return fde_sub_067794(a0, a1, a2);
        case 0x0677e0ULL: return fde_sub_0677e0(a0, a1, a2);
        case 0x067830ULL: return fde_sub_067830(a0, a1, a2);
        case 0x067958ULL: return fde_sub_067958(a0, a1, a2);
        case 0x0679a8ULL: return fde_sub_0679a8(a0, a1, a2);
        case 0x067a1cULL: return fde_sub_067a1c(a0, a1, a2);
        case 0x067a60ULL: return fde_sub_067a60(a0, a1, a2);
        case 0x067ab4ULL: return fde_sub_067ab4(a0, a1, a2);
        case 0x067ad4ULL: return fde_sub_067ad4(a0, a1, a2);
        case 0x067ba0ULL: return fde_sub_067ba0(a0, a1, a2);
        case 0x067bc8ULL: return fde_sub_067bc8(a0, a1, a2);
        case 0x067bccULL: return fde_sub_067bcc(a0, a1, a2);
        case 0x067ca4ULL: return fde_sub_067ca4(a0, a1, a2);
        case 0x067cc4ULL: return fde_sub_067cc4(a0, a1, a2);
        case 0x067d00ULL: return fde_sub_067d00(a0, a1, a2);
        case 0x067d1cULL: return fde_sub_067d1c(a0, a1, a2);
        case 0x067e10ULL: return fde_sub_067e10(a0, a1, a2);
        case 0x067e70ULL: return fde_sub_067e70(a0, a1, a2);
        case 0x068010ULL: return fde_sub_068010(a0, a1, a2);
        case 0x068788ULL: return fde_sub_068788(a0, a1, a2);
        case 0x068970ULL: return fde_sub_068970(a0, a1, a2);
        case 0x0689b4ULL: return fde_sub_0689b4(a0, a1, a2);
        case 0x0689e8ULL: return fde_sub_0689e8(a0, a1, a2);
        case 0x068ac4ULL: return fde_sub_068ac4(a0, a1, a2);
        case 0x068b7cULL: return fde_sub_068b7c(a0, a1, a2);
        case 0x068bc4ULL: return fde_sub_068bc4(a0, a1, a2);
        case 0x068c34ULL: return fde_sub_068c34(a0, a1, a2);
        case 0x068c58ULL: return fde_sub_068c58(a0, a1, a2);
        case 0x068c84ULL: return fde_sub_068c84(a0, a1, a2);
        case 0x068cd8ULL: return fde_sub_068cd8(a0, a1, a2);
        case 0x068d2cULL: return fde_sub_068d2c(a0, a1, a2);
        case 0x068d80ULL: return fde_sub_068d80(a0, a1, a2);
        case 0x068e18ULL: return fde_sub_068e18(a0, a1, a2);
        case 0x068e34ULL: return fde_sub_068e34(a0, a1, a2);
        case 0x069008ULL: return fde_sub_069008(a0, a1, a2);
        case 0x069084ULL: return fde_sub_069084(a0, a1, a2);
        case 0x0690fcULL: return fde_sub_0690fc(a0, a1, a2);
        case 0x0691acULL: return fde_sub_0691ac(a0, a1, a2);
        case 0x06a554ULL: return fde_sub_06a554(a0, a1, a2);
        case 0x06a584ULL: return fde_sub_06a584(a0, a1, a2);
        case 0x06a5ccULL: return fde_sub_06a5cc(a0, a1, a2);
        case 0x06a650ULL: return fde_sub_06a650(a0, a1, a2);
        case 0x06a7bcULL: return fde_sub_06a7bc(a0, a1, a2);
        case 0x06a7ccULL: return fde_sub_06a7cc(a0, a1, a2);
        case 0x06aec0ULL: return fde_sub_06aec0(a0, a1, a2);
        case 0x06aef0ULL: return fde_sub_06aef0(a0, a1, a2);
        case 0x06af20ULL: return fde_sub_06af20(a0, a1, a2);
        case 0x06af78ULL: return fde_sub_06af78(a0, a1, a2);
        case 0x06afc4ULL: return fde_sub_06afc4(a0, a1, a2);
        case 0x06b084ULL: return fde_sub_06b084(a0, a1, a2);
        case 0x06b248ULL: return fde_sub_06b248(a0, a1, a2);
        case 0x06b2a0ULL: return fde_sub_06b2a0(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace bytebench
